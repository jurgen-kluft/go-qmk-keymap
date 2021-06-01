package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"os"
	"strings"
	"unicode"
)

const (
	STATE_HEAD int = iota
	STATE_KEYMAPS
	STATE_KEYMAP
	STATE_TAIL
)

func is_comment_line(line string) bool {
	line = strings.TrimSpace(line)
	return strings.HasPrefix(line, "//") || strings.HasPrefix(line, "*") || strings.HasPrefix(line, "/*") || strings.HasPrefix(line, "*/")
}

func sprint_element(element string, separator string, width int) string {
	// left align the element
	// followed by the seperator
	// padded with space until reaching width

	str := make([]rune, 0, width+1)
	cnt := 0
	for _, c := range element {
		str = append(str, c)
		cnt += 1
	}
	for _, c := range separator {
		str = append(str, c)
		cnt += 1
	}
	for cnt < width {
		str = append(str, ' ')
		cnt += 1
	}
	return string(str)
}

func print_formatted(kb *keyboard_t, layer *layer_t) []string {
	output := make([]string, 0, 8)
	width := make([]int, len(kb.Rows[0]))
	for i := 0; i < len(width); i++ {
		if len(kb.Spacing) > 0 {
			width[i] = kb.Spacing[0]
		} else {
			width[i] = 8
		}
	}
	for _, row := range kb.Rows {
		for ci, ki := range row {
			if ki >= 0 {
				key := layer.Keymap[ki]
				if len(key) > width[ci] {
					width[ci] = len(key)
				}
			} else {
				ki = -ki
				if ki >= 0 && ki < len(kb.Spacing) {
					if kb.Spacing[ki] > width[ci] {
						width[ci] = kb.Spacing[ki]
					}
				}
			}
		}
	}

	for ri, row := range kb.Rows {
		line := ""
		for i, ki := range row {
			last_column := ki == (kb.Numkeys - 1)
			if ki < 0 {
				line = line + sprint_element("", " ", width[i]+2)
			} else {
				if last_column {
					line = line + sprint_element(layer.Keymap[ki], " ", width[i]+2)
				} else {
					line = line + sprint_element(layer.Keymap[ki], ",", width[i]+2)
				}
			}
		}

		// add eol part
		line = line + layer.EOLs[ri]

		output = append(output, line)
	}
	return output
}

const (
	PARSER_WHITESPACE int = iota
	PARSER_ARRAYITEM
)

func parse_layer_id(line string) string {
	// [ID] = LAYOUT(
	id := make([]rune, 0, 16)
	state := 0
	for _, r := range line {
		if state == 0 {
			if r == '[' {
				state = 1
			}
		} else if state == 1 {
			if r == ']' {
				state = 2
			} else {
				id = append(id, r)
			}
		} else if state == 2 {
			break
		}
	}
	idstr := string(id)
	idstr = strings.TrimSpace(idstr)
	return idstr
}

func parse_elements(line string) ([]string, string) {
	keymap := make([]string, 0, 80)

	eol_pos := len(line)
	for cursor, r := range line {
		if r == '/' || r == '\\' {
			eol_pos = cursor
			break
		}
	}

	// snip the end of the line part and remember it
	end_of_line_part := line[eol_pos:]

	// continue with the trimmed line
	line = line[0:eol_pos]

	state := PARSER_WHITESPACE
	open := 0
	elem := make([]rune, 0, 60)
	for _, r := range line {

		if state == PARSER_WHITESPACE {
			if unicode.IsSpace(r) == false {
				state = PARSER_ARRAYITEM
			}
		}

		if state == PARSER_ARRAYITEM {
			if open > 0 {
				if r == '[' || r == '(' {
					open += 1
				} else if r == ']' || r == ')' {
					open -= 1
				}
				elem = append(elem, r)
			} else {
				if r == ',' {
					state = PARSER_WHITESPACE
					elemstr := string(elem)
					elemstr = strings.TrimSpace(elemstr)
					keymap = append(keymap, elemstr)
					elem = elem[:0]
				} else {
					if r == '[' || r == '(' {
						open += 1
					}
					elem = append(elem, r)
				}
			}
		}
	}
	if len(elem) > 0 {
		elemstr := string(elem)
		elemstr = strings.TrimSpace(elemstr)
		if len(elemstr) > 0 {
			keymap = append(keymap, elemstr)
		}
	}
	return keymap, end_of_line_part
}

func parse_viz_layer_names(line string) []string {
	layer_names := make([]string, 0, 4)
	layers_str := make([]rune, 0, 32)
	state := 0
	for _, c := range line {
		if state == 0 {
			if c == '[' {
				state = 1
			}
		} else if state == 1 {
			if c == ']' {
				state = 2
			} else {
				layers_str = append(layers_str, c)
			}
		} else if state == 2 {
			break
		}
	}
	layers := strings.Split(string(layers_str), ",")
	for _, l := range layers {
		layer_name := strings.TrimSpace(l)
		layer_names = append(layer_names, layer_name)
	}
	return layer_names
}

func index_to_viz(index int) string {
	return fmt.Sprintf("_%03d_", index)
}

func print_viz(k *keyboard_t, layer *layer_t) []string {
	keyboardviz := make([]string, 0, 32)
	for _, line := range k.VizBoard {
		keyboardviz = append(keyboardviz, line)
	}

	spacing := "                          "
	for ki, key := range layer.Keymap {
		keysymbol := ""
		if symbol, ok := k.VizSymbols[key]; ok {
			keysymbol = symbol
		} else if len(key) > k.VizWidth {
			keysymbol = key[(len(key) - k.VizWidth):]
		} else if len(key) < k.VizWidth {
			lp := (k.VizWidth - len(key)) / 2
			rp := k.VizWidth - len(key) - lp
			keysymbol = fmt.Sprintf("%s%s%s", spacing[0:lp], key, spacing[0:rp])
		} else {
			keysymbol = key
		}

		marker := index_to_viz(ki)
		for i := 0; i < len(keyboardviz); i++ {
			if strings.Contains(keyboardviz[i], marker) {
				keyboardviz[i] = strings.Replace(keyboardviz[i], marker, keysymbol, 1)
			}
		}
	}

	return keyboardviz
}

func main() { os.Exit(mainReturnWithCode()) }

func isEmit(line string, kb *keyboard_t) bool {
	line = strings.TrimSpace(line)
	for _, emitat := range kb.VizEmits {
		if strings.Compare(line, emitat) == 0 {
			return true
		}
	}
	return false
}

func mainReturnWithCode() int {
	scanner := bufio.NewScanner(os.Stdin)
	lines := make([]string, 0, 4096)
	for scanner.Scan() {
		line := scanner.Text()
		lines = append(lines, line)
	}

	// find the config json lines
	collect_json := false
	json := ""
	for _, line := range lines {
		if strings.Contains(line, "qmk-keyboard-format:json:begin") {
			collect_json = true
		} else if strings.Contains(line, "qmk-keyboard-format:json:end") {
			collect_json = false
		} else {
			if collect_json {
				json = json + line
			}
		}
	}

	if json == "" {
		return -1
	}

	kb, err := UnmarshalKeyboard([]byte(json))
	if kb == nil || err != nil {
		fmt.Printf("error, cannot unmarshall json")
		return -2
	}

	keymaps_begin := "keymaps[]"
	keymaps_end := "};"
	keymap_begin := "LAYOUT("
	keymap_end1 := "),"
	keymap_end2 := ")"

	output := make([]string, 0, 1024)

	layers := make(map[string]*layer_t)

	state := STATE_HEAD
	layer := &layer_t{}
	for _, line := range lines {
		// here we check if the line is a '//' comment and skip processing it
		if is_comment_line(line) {
			if strings.HasPrefix(strings.TrimSpace(line), kb.VizLine) == false {
				output = append(output, line)
			}
		} else {
			if state == STATE_HEAD {
				if strings.Contains(line, keymaps_begin) {
					state = STATE_KEYMAPS
					output = append(output, line)
				} else {
					output = append(output, line)
				}
			} else if state == STATE_KEYMAPS {
				if strings.Contains(line, keymap_begin) {
					layer_name := parse_layer_id(line)
					layer = &layer_t{Name: layer_name, Keymap: make([]string, 0, 104)}
					layers[layer_name] = layer
					state = STATE_KEYMAP
					output = append(output, line)
				} else if strings.Compare(strings.TrimSpace(line), keymaps_end) == 0 {
					state = STATE_TAIL
					output = append(output, line)
				} else {
					output = append(output, line)
				}
			} else if state == STATE_KEYMAP {
				if strings.TrimSpace(line) == keymap_end1 || strings.TrimSpace(line) == keymap_end2 {
					// do we have a parsed keymap, if so write it out here in a formatted form
					//if len(keymap) == keyboard.numkeys {
					formatted := print_formatted(kb, layer)
					for _, l := range formatted {
						output = append(output, l)
					}
					//}
					layer = nil
					state = STATE_KEYMAPS
					output = append(output, line)
				} else {
					// collect the elements from these lines
					elems, eol_part := parse_elements(line)
					layer.Keymap = append(layer.Keymap, elems...)
					layer.EOLs = append(layer.EOLs, eol_part)
				}
			} else if state == STATE_TAIL {
				output = append(output, line)
			}
		}
	}

	if len(kb.VizEmits) > 0 {
		// iterate over all output lines and identify locations where we need to output ascii-art for a layer

		doviz := 0
		output_temp := make([]string, 0, 1024)
		for _, line := range output {
			if isEmit(line, kb) {
				layer_name := parse_layer_id(line)
				if layer, ok := layers[layer_name]; ok {
					layer_viz := print_viz(kb, layer)
					output_temp = append(output_temp, layer_viz...)
				}
				output_temp = append(output_temp, line)
				doviz = 0
			} else if doviz == 0 {
				output_temp = append(output_temp, line)
			}
		}
		output = output_temp
	}

	for _, l := range output {
		fmt.Println(l)
	}

	return 0
}

func UnmarshalKeyboard(data []byte) (*keyboard_t, error) {
	r := &keyboard_t{}
	err := json.Unmarshal(data, &r)
	return r, err
}

func (r *keyboard_t) Marshal() ([]byte, error) {
	return json.Marshal(r)
}

type keyboard_t struct {
	Name       string            `json:"name"`
	Numkeys    int               `json:"numkeys"`
	Rows       [][]int           `json:"rows"`
	Spacing    []int             `json:"spacing"`
	VizWidth   int               `json:"vizcellwidth"`
	VizEmits   []string          `json:"vizemits"`
	VizLine    string            `json:"vizline"`
	VizBoard   []string          `json:"vizboard"`
	VizSymbols map[string]string `json:"vizsymbols"`
}

type layer_t struct {
	Name   string
	Keymap []string
	EOLs   []string
}

// key symbols
// http://xahlee.info/comp/unicode_computing_symbols.html
