package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"unicode"

	"github.com/jurgen-kluft/go-qmk-keymap/config"
)

const (
	STATE_HEAD int = iota
	STATE_KEYMAPS
	STATE_KEYMAP
	STATE_TAIL
)

func print_formatted(k *config.Keyboard, spacing []int, keymap []string) []string {
	output := make([]string, 0, 8)
	width := make([]int, len(k.Rows[0]))
	for i := 0; i < len(width); i++ {
		if len(spacing) > 0 {
			width[i] = spacing[0]
		} else {
			width[i] = 8
		}
	}
	for _, row := range k.Rows {
		for i, ki := range row {
			if ki >= 0 {
				key := keymap[ki]
				if len(key) > width[i] {
					width[i] = len(key)
				}
			} else {
				ki = -ki
				if ki >= 0 && ki < len(spacing) {
					if spacing[ki] > width[i] {
						width[i] = spacing[ki]
					}
				}
			}
		}
	}
	key_formats := make([]string, len(width))
	for i, w := range width {
		key_formats[i] = fmt.Sprintf("%s%d%s", "%-", w, "s")
	}

	for ri, row := range k.Rows {
		separator := ""
		line := "    "
		for i, ki := range row {
			if ki < 0 {
				line = line + fmt.Sprintf(key_formats[i], " ")
				line = line + "  "
			} else {
				line = line + fmt.Sprint(separator)
				line = line + fmt.Sprintf(key_formats[i], keymap[ki])
				separator = ", "
			}
		}

		// the last row does not need a comma at the end
		if ri < (len(k.Rows) - 1) {
			line = line + ","
		}

		output = append(output, line)
	}
	return output
}

const (
	SKIP_WHITESPACE int = iota
	PARSE_ELEMENT
)

func parse_elements(line string) []string {
	keymap := make([]string, 0, 80)

	state := SKIP_WHITESPACE
	open := 0
	elem := make([]rune, 0, 60)
	for _, r := range line {
		if state == SKIP_WHITESPACE {
			if unicode.IsSpace(r) == false {
				state = PARSE_ELEMENT
				elem = elem[:0]
				elem = append(elem, r)
			}
		} else if state == PARSE_ELEMENT {
			if open > 0 {
				if r == ']' || r == ')' {
					open -= 1
				}
				elem = append(elem, r)
			} else {
				if r == ',' {
					state = SKIP_WHITESPACE
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
		keymap = append(keymap, elemstr)
	}
	return keymap
}

func print_viz(k *config.Keyboard, keymap []string) []string {
	output := make([]string, 0, 5)

	return output
}

func main() { os.Exit(mainReturnWithCode()) }

func mainReturnWithCode() int {
	kbconfig, err := config.Load("go-qmk-keymap.json")
	if err != nil {
		return -1
	}
	keyboard := kbconfig.FindKeyboard("Kyria")
	if keyboard == nil {
		return -2
	}

	keymaps_begin := "keymaps[]"
	keymaps_end := "};"
	keymap_begin := "LAYOUT("
	keymap_end1 := "),"
	keymap_end2 := ")"

	output := make([]string, 0, 1024)

	scanner := bufio.NewScanner(os.Stdin)
	state := STATE_HEAD
	keymap := make([]string, 0, 80)
	for scanner.Scan() {
		line := scanner.Text()
		if state == STATE_HEAD {
			if strings.Contains(line, keymaps_begin) {
				state = STATE_KEYMAPS
				output = append(output, line)
			} else {
				output = append(output, line)
			}
		} else if state == STATE_KEYMAPS {
			if strings.Contains(line, keymap_begin) {
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
				formatted := print_formatted(keyboard, kbconfig.Spacing, keymap)
				for _, l := range formatted {
					output = append(output, l)
				}
				//}
				keymap = make([]string, 0, 80)
				state = STATE_KEYMAPS
				output = append(output, line)
			} else {
				// collect the elements from these lines
				elems := parse_elements(line)
				keymap = append(keymap, elems...)
			}
		} else if state == STATE_TAIL {
			output = append(output, line)
		}
	}

	for _, l := range output {
		fmt.Println(l)
	}

	return 0
}
