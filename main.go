package main

import (
	"bufio"
	"fmt"
	"os"
)

// TODO:
// replacements
// custom defines

type keymap_t struct {
	name   string
	keymap []string
}

type keyboard_t struct {
	name string
	rows [][]int
}

func main() {

	// Kyria layout example:
	//
	// e001, e002, e003, e004, e005, e006, ____, ____, ____, ____, ____, ____, e007, e008, e009, e010, e011, e012
	// e013, e014, e015, e016, e017, e018, ____, ____, ____, ____, ____, ____, e019, e020, e021, e022, e023, e024
	// e025, e026, e027, e028, e029, e030, e031, e032, ____, ____, e033, e034, e035, e036, e037, e038, e039, e040
	// ____, ____, ____, e041, e042, e043, e044, e045, ____, ____, e046, e047, e048, e049, e050, ____, ____, ____
	//

	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		fmt.Println(scanner.Text())
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
