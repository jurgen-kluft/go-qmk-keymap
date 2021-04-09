package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"

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

	for _, row := range k.Rows {
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
		line = line + ","
		output = append(output, line)
	}
	return output
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

	return 0
}
