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

func print_formatted(k *keyboard_t, keymap []string) {

}

func main() {

	// Kyria layout example:
	//
	// e001, e002, e003, e004, e005, e006, ____, ____, ____, ____, ____, ____, e007, e008, e009, e010, e011, e012
	// e013, e014, e015, e016, e017, e018, ____, ____, ____, ____, ____, ____, e019, e020, e021, e022, e023, e024
	// e025, e026, e027, e028, e029, e030, e031, e032, ____, ____, e033, e034, e035, e036, e037, e038, e039, e040
	// ____, ____, ____, e041, e042, e043, e044, e045, ____, ____, e046, e047, e048, e049, e050, ____, ____, ____
	//

	keyboard := &keyboard_t{name: "Kyria", rows: nil}

	keymaps_begin := "keymaps[]"
	keymaps_end := "};"
	keymap_begin := "LAYOUT("
	keymap_end := ")"

	scanner := bufio.NewScanner(os.Stdin)
	state := STATE_HEAD
	keymap := make([]string, 80)
	for scanner.Scan() {
		line := scanner.Text()
		if state == STATE_HEAD {
			if strings.Contains(line, keymaps_begin) {
				state = STATE_KEYMAPS
				fmt.Println(line)
			} else if strings.Compare(line, keymaps_end) == 0 {
				state = STATE_TAIL
				fmt.Println(line)
			} else {
				fmt.Println(line)
			}
		} else if state == STATE_KEYMAPS {
			if strings.Contains(line, keymap_begin) {
				state = STATE_KEYMAP
				keymap = keymap[:0] // set the array to a length of 0
				fmt.Println(line)
			} else if strings.Compare(line, keymap_end) == 0 {
				// do we have a parsed keymap, if so write it out here in a formatted form
				if len(keymap) == keyboard.numkeys {
					print_formatted(keyboard, keymap)
				}
				state = STATE_KEYMAPS
				fmt.Println(line)
			} else {
				fmt.Println(line)
			}
		} else if state == STATE_KEYMAP {
			// collect the elements from these lines
			keystrs := strings.Split(line, ",")
			for _, key := range keystrs {
				key = strings.Trim(key, " \t")
				keymap = append(keymap, key)
			}
		} else if state == STATE_TAIL {
			fmt.Println(line)
		}
	}

	// HEAD
	// the head can be emitted directly to stdout

	// read until we reach the line that contains:
	//                 "keymaps[][MATRIX_ROWS][MATRIX_COLS]"

	// any line here that is a comment we need to keep it

	// we know that the keymaps end with the line:
	//                 "};"

	// TAIL
	// the rest of the file (tail) can be emitted to stdout
}
