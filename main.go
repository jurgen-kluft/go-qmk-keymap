package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// TODO:
// replacements
// custom defines

type keymap_t struct {
	name   string
	keymap []string
}

type keyboard_t struct {
	name    string
	numkeys int
	rows    [][]int
}

const (
	STATE_HEAD int = iota
	STATE_KEYMAPS
	STATE_KEYMAP
	STATE_TAIL
)

func init_kyria_keyboard() *keyboard_t {
	// Kyria layout:
	//
	// e001, e002, e003, e004, e005, e006, ____, ____, ____, ____, ____, e007, e008, e009, e010, e011, e012
	// e013, e014, e015, e016, e017, e018, ____, ____, ____, ____, ____, e019, e020, e021, e022, e023, e024
	// e025, e026, e027, e028, e029, e030, e031, e032, ____, e033, e034, e035, e036, e037, e038, e039, e040
	// ____, ____, ____, e041, e042, e043, e044, e045, ____, e046, e047, e048, e049, e050, ____, ____, ____
	//

	kyria := &keyboard_t{name: "Kyria", numkeys: 50, rows: [][]int{
		{00, 01, 02, 03, 04, 05, -1, -1, -1, -1, -1, 06, 07, +8, +9, 10, 11},
		{12, 13, 14, 15, 16, 17, -1, -1, -1, -1, -1, 18, 19, 20, 21, 22, 23},
		{24, 25, 26, 27, 28, 29, 30, 31, -1, 32, 33, 34, 35, 36, 37, 38, 39},
		{-1, -1, -1, 40, 41, 42, 43, 44, -1, 45, 46, 47, 48, 49, -1, -1, -1},
	}}
	return kyria
}

func print_formatted(k *keyboard_t, keymap []string) []string {
	output := make([]string, 0, 5)
	width := make([]int, len(k.rows[0]))
	for i := 0; i < len(width); i++ {
		width[i] = 3
	}
	for _, row := range k.rows {
		for i, ki := range row {
			if ki >= 0 {
				key := keymap[ki]
				if len(key) > width[i] {
					width[i] = len(key)
				}
			}
		}
	}
	key_formats := make([]string, len(width))
	for i, w := range width {
		key_formats[i] = fmt.Sprintf("%s%d%s", "%-", w, "s")
	}

	for _, row := range k.rows {
		separator := ""
		line := "    "
		for i, ki := range row {
			if ki == -1 {
				line = line + fmt.Sprintf(key_formats[i], " ")
				line = line + "  "
			} else {
				line = line + fmt.Sprint(separator)
				line = line + fmt.Sprintf(key_formats[i], keymap[ki])
				separator = ", "
			}
		}
		line = line + ","
		output = append(output, line)
	}
	return output
}

func main() {
	keyboard := init_kyria_keyboard()

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
				formatted := print_formatted(keyboard, keymap)
				for _, l := range formatted {
					output = append(output, l)
				}
				//}
				keymap = make([]string, 0, 80)
				state = STATE_KEYMAPS
				output = append(output, line)
			} else {
				// collect the elements from these lines
				keystrs := strings.Split(line, ",")
				for _, k := range keystrs {
					key := strings.TrimSpace(k)
					if len(key) > 0 && key != "\n" {
						keymap = append(keymap, key)
					}
				}
			}
		} else if state == STATE_TAIL {
			output = append(output, line)
		}
	}

	for _, l := range output {
		fmt.Println(l)
	}
}
