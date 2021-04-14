# keymap formatting for .c qmk files

This utility can format a ``keymap.c`` file and particularly the keymap array with LAYOUT's.
Adding configuration local to this file ensures this utility can work with any keyboard layout.

NOTE: The state of this utility is still 'Alpha', things might change and bugs might exist.

## configuration

 Here an example of the configuration that you can add at the bottom of your ```keymap.c``` file.

 The 'spacing' array is used by the negative indices in the 'rows' definition, you can add/remove items to fit your needs.

```c++
/*
qmk-keyboard-format:json:begin
{
    "name": "Kyria",
    "numkeys": 50,
    "rows": [
        [  0,  1,  2,  3,  4,  5, -1, -1, -2, -1, -1,  6,  7,  8,  9, 10, 11 ],
        [ 12, 13, 14, 15, 16, 17, -1, -1, -2, -1, -1, 18, 19, 20, 21, 22, 23 ],
        [ 24, 25, 26, 27, 28, 29, 30, 31, -2, 32, 33, 34, 35, 36, 37, 38, 39 ],
        [ -1, -1, -1, 40, 41, 42, 43, 44, -2, 45, 46, 47, 48, 49, -1, -1, -1 ]
    ],
    "spacing": [
        10,
        10,
        8
    ],
    "vizcellwidth": 5,
    "vizboard": [
        " // ",
        " // .-----------------------------------------------.                                             .-----------------------------------------------.",
        " // | _000_ | _001_ | _002_ | _003_ | _004_ | _005_ |                                             | _006_ | _007_ | _008_ | _009_ | _010_ | _011_ |",
        " // |-------+-------+-------+-------+-------+-------|                                             |-------+-------+-------+-------+-------+-------|",
        " // | _012_ | _013_ | _014_ | _015_ | _016_ | _017_ |                                             | _018_ | _019_ | _020_ | _021_ | _022_ | _023_ |",
        " // |-------+-------+-------+-------+-------+-------|-------+-------.             .-------+-------|-------+-------+-------+-------+-------+-------|",
        " // | _024_ | _025_ | _026_ | _027_ | _028_ | _029_ | _030_ | _031_ |             | _032_ | _033_ | _034_ | _035_ | _036_ | _037_ | _038_ | _039_ |",
        " // .-------+-------+-------+-------+-------+-------+-------+-------|             |-------+-------.-------+-------+-------+-------+-------+-------.",
        " //                         | _040_ | _041_ | _042_ | _043_ | _044_ |             | _045_ | _046_ | _047_ | _048_ | _049_ |                        ",
        " //                         .-------+-------+-------+-------+-------.             .-------|-------|-------|-------|-------.                        ",
        " // "
    ],
    "vizsymbols": {
        "KC_TRANS": "     ",
        "KC_A": "  A  " ,
        "KC_B": "  B  " ,
        "KC_C": "  C  " ,
        "KC_D": "  D  " ,
        "KC_E": "  E  " ,
        "KC_F": "  F  " ,
        "KC_G": "  G  " ,
        "KC_H": "  H  " ,
        "KC_I": "  I  " ,
        "KC_J": "  J  " ,
        "KC_K": "  K  " ,
        "KC_L": "  L  " ,
        "KC_M": "  M  " ,
        "KC_N": "  N  " ,
        "KC_O": "  O  " ,
        "KC_P": "  P  " ,
        "KC_Q": "  Q  " ,
        "KC_R": "  R  " ,
        "KC_S": "  S  " ,
        "KC_T": "  T  " ,
        "KC_U": "  U  " ,
        "KC_V": "  V  " ,
        "KC_W": "  W  " ,
        "KC_X": "  X  " ,
        "KC_Y": "  Y  " ,
        "KC_Z": "  Z  " ,
        "KC_COMMA": "  ,  ",
        "KC_DOT": "  .  ",
        "KC_SCOLON": "  ;  ",
        "KC_SCLN": "  :  ",
        "KC_SLASH": "  /  ",
        "KC_ESC": " ⎋  " ,
        "KC_CUT": " ✄  " ,
        "KC_UNDO": " ↶  " ,
        "KC_REDO": " ↷  " ,
        "KC_VOLU": " 🕪  " ,
        "KC_VOLD": " 🕩  " ,
        "KC_MUTE":   "  🕨" ,
        "KC_TAB": " ⭾  " ,
        "KC_MENU": "  𝌆  " ,
        "KC_CAPSLOCK": "  ⇪  " ,
        "KC_NUMLK": "  ⇭  " ,
        "KC_SCRLK": "  ⇳  " ,
        "KC_PRSCR": "  ⎙  " ,
        "KC_PAUSE": "  ⎉  " ,
        "KC_BREAK": "  ⎊  " ,
        "KC_ENTER": "  ⏎  " ,
        "KC_BSPACE": " ⌫  " ,
        "KC_DELETE": " ⌦ " ,
        "KC_INSERT": " ⎀  " ,
        "KC_LEFT": " ◁  " ,
        "KC_RIGHT": " ▷  " ,
        "KC_UP": " △  " ,
        "KC_DOWN": " ▽  " ,
        "KC_HOME": " ⇤  " ,
        "KC_END": " ⇥  " ,
        "KC_PGUP": " ⇞  " ,
        "KC_PGDOWN": " ⇟  " ,
        "KC_LSFT": "  ⇧  " ,
        "KC_RSFT": "  ⇧  " ,
        "KC_LCTL": "  ^  " ,
        "KC_RCTL": "  ^  " ,
        "KC_LALT": " ⎇  " ,
        "KC_RALT": " ⎇  " ,
        "KC_HYPER": "  ✧  " ,
        "KC_LGUI": " ⌘  " ,
        "KC_RGUI": " ⌘  "
    }
}
qmk-keyboard-format:json:end
*/
```

## Visual Studio Code (vscode)

You can use this formatter by installing an extension called [Custom Local Formatters](https://marketplace.visualstudio.com/items?itemName=jkillian.custom-local-formatters) and by adding a formatter entry for ```.c``` files and pointing to this utility. For Mac this utility needs to be in a directory that is known by your environment, for Windows the root of the workspace will work.



## keymap viz, aka ascii-art

When you put the following 2 lines in your keymap.c file, the tool will insert textual diagram of your layer(s).
You can specify the layers you want to have generated by changing the text within the ```[_BASE, _NAV, _RSTHD]```.

Best unicode monospace font to use is called [FiraCode](https://github.com/tonsky/FiraCode).

```c++
// qmk-keyboard-format:keymapviz:begin[_BASE, _NAV, _RSTHD]
// qmk-keyboard-format:keymapviz:end
```

```c++
// qmk-keyboard-format:keymapviz:begin[_BASE, _NAV, _RSTHD]
  // Layer _BASE
 // 
 // .-----------------------------------------------.                                             .-----------------------------------------------.
 // |       |   Q   |   W   |   E   |   R   |   T   |                                             |   Y   |   U   |   I   |   O   |   P   | STHD) |
 // |-------+-------+-------+-------+-------+-------|                                             |-------+-------+-------+-------+-------+-------|
 // | CAPS) |   A   |   S   |   D   |   F   |   G   |                                             |   H   |   J   |   K   |   L   |   :   |       |
 // |-------+-------+-------+-------+-------+-------|-------+-------.             .-------+-------|-------+-------+-------+-------+-------+-------|
 // |       |   Z   |   X   |   C   |   V   |   B   | _MOD) | CAPS) |             | MOUS) |  ⌫    |   N   |   M   |   ,   |   .   |   /   | STEM) |
 // .-------+-------+-------+-------+-------+-------+-------+-------|             |-------+-------.-------+-------+-------+-------+-------+-------.
 //                         |       |  ⌘    | _NAV) | SPACE |   ⇧   |             |   ⇧   |  ⌫    | _SYM) |   ⌘   |       |                        
 //                         .-------+-------+-------+-------+-------.             .-------|-------|-------|-------|-------.                        
 // 
  // Layer _NAV
 // 
 // .-----------------------------------------------.                                             .-----------------------------------------------.
 // |       |       |       | SCAPE |   ⏎   |  ⭾    |                                             |       |   ⇞   |   ⇤   |   ⭾   |       |       |
 // |-------+-------+-------+-------+-------+-------|                                             |-------+-------+-------+-------+-------+-------|
 // |       |  ⌘    |   ⎇   |   ^   |   ⇧   |  ⌦    |                                             |  ◁    |   ▽   |   △   |   ▷   |       |       |
 // |-------+-------+-------+-------+-------+-------|-------+-------.             .-------+-------|-------+-------+-------+-------+-------+-------|
 // |       |  ↶    |   ✄   | _COPY | PASTE |   ⌫   |       |       |             |       |       |       |   ⇟   |   ⇥   | SPACE |   ⎀   |       |
 // .-------+-------+-------+-------+-------+-------+-------+-------|             |-------+-------.-------+-------+-------+-------+-------+-------.
 //                         |       |       |       |       |       |             |       |       | _FNC) |       |       |                        
 //                         .-------+-------+-------+-------+-------.             .-------|-------|-------|-------|-------.                        
 // 
  // Layer _RSTHD
 // 
 // .-----------------------------------------------.                                             .-----------------------------------------------.
 // |       |   J   |   C   |   Y   |   F   |   K   |                                             |   Z   |   L   |   ,   |   U   |   Q   |       |
 // |-------+-------+-------+-------+-------+-------|                                             |-------+-------+-------+-------+-------+-------|
 // |       |   R   |   S   |   T   |   H   |   D   |                                             |   M   |   N   |   A   |   I   |   O   |   :   |
 // |-------+-------+-------+-------+-------+-------|-------+-------.             .-------+-------|-------+-------+-------+-------+-------+-------|
 // |       |   :   |   V   |   G   |   P   |   B   |       |       |             |       |       |   X   |   W   |   .   |   :   |   /   |       |
 // .-------+-------+-------+-------+-------+-------+-------+-------|             |-------+-------.-------+-------+-------+-------+-------+-------.
 //                         |       |       |       |       |       |             |       |   E   |       |       |       |                        
 //                         .-------+-------+-------+-------+-------.             .-------|-------|-------|-------|-------.                        
 // 
 // qmk-keyboard-format:keymapviz:end
 ```

