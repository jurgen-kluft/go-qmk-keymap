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
    "vizemits": [
        { "line": "[_QWERTY] = LAYOUT(", "layer": "_QWERTY" },
        { "line": "[_RAISE] = LAYOUT(", "layer": "_RAISE" }
    ],
    "vizline": "//#",
    "vizboard": [
        "    //#                         ╭───────╮                                                                        ╭───────╮                          ",
        "    //#                 ╭───────╯ _003_ ╰───────╮                                                        ╭───────╯ _008_ ╰───────╮                  ",
        "    //#                 │ _002_ │       │ _004_ ╭───────╮                                        ╭───────╮ _007_ │       │ _009_ │                  ",
        "    //# ╭───────╮───────╯       ╰───────╯       │ _005_ │                                        │ _006_ │       ╰───────╯       ╰───────╭───────╮  ",
        "    //# │ _000_ │ _001_ ╰───────╯ _015_ ╰───────╯       │                                        │       ╰───────╯ _020_ ╰───────╯ _010_ │ _011_ │  ",
        "    //# │       │       │ _014_ │       │ _016_ ╰───────╯                                        ╰───────╯ _019_ │       │ _021_ │       │       │  ",
        "    //# ╰───────╯───────╯       ╰───────╯       │ _017_ │                                        │ _018_ │       ╰───────╯       ╰───────╰───────╯  ",
        "    //# │ _012_ │ _013_ ╰───────╯ _027_ ╰───────╯       │                                        │       ╰───────╯ _036_ ╰───────╯ _022_ │ _023_ │  ",
        "    //# │       │       │ _026_ │       │ _028_ ╰───────╯                                        ╰───────╯ _035_ │       │ _037_ │       │       │  ",
        "    //# ╰───────╯───────╯       ╰───────╯       │ _029_ │ ╭───────╮                    ╭───────╮ │ _034_ │       ╰───────╯       ╰───────╰───────╯  ",
        "    //# │ _024_ │ _025_ ╰───────╯       ╰───────╯       │ │ _030_ ╰───────╮    ╭───────╯ _033_ │ │       ╰───────╯       ╰───────╯ _038_ │ _039_ │  ",
        "    //# │       │       │              ╭───────╮╰───────╯ │       │ _031_ │    │ _032_ │       │ ╰───────╯╭───────╮              │       │       │  ",
        "    //# ╰───────╯───────╯     ╭───────╮│ _041_ ╰───────╮  ╰───────╯       │    │       ╰───────╯  ╭───────╯ _048_ │╭───────╮     ╰───────╰───────╯  ",
        "    //#                       │ _040_ ││       │ _042_ ╰───────╮  ╰───────╯    ╰───────╯  ╭───────╯ _047_ │       ││ _049_ │                        ",
        "    //#                       │       │╰───────╯       │ _043_ ╰───────╮          ╭───────╯ _046_ │       ╰───────╯│       │                        ",
        "    //#                       ╰encodr─╯        ╰───────╯       │ _044_ │          │ _045_ │       ╰───────╯        ╰encodr─╯                        ",
        "    //#                                                ╰───────╯       │          │       ╰───────╯                                                 ",
        "    //#                                                        ╰───────╯          ╰───────╯                                                         "
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

## Commandline

Once you have compiled an executable of this utility (`go build` or `go install`) you can then use it as process.
You need to provide the content of your .c file to the application and write the stdout of the application
to the same or otherwise a new file.
`cat main.c | go-qmk-keymap(.exe) > main.c`
You can also run the program without compile step with this command:
`cat keymap.c | go run main.go > formatted-keymap.c`

## Visual Studio Code (vscode)

You can use this formatter by installing an extension called [Custom Local Formatters](https://marketplace.visualstudio.com/items?itemName=jkillian.custom-local-formatters) and by adding a formatter entry for ```.c``` files and pointing to this utility. For Mac this utility needs to be in a directory that is known by your environment, for Windows the root of the workspace will work.

## keymap viz, aka ascii-art

When you put entries in the `vizemits` array it will emit the keymap using the `vizboard` text. `vizline` is necessary to be able to recognize comment lines generated by this tool. NOTE: `vizboard` should use the same pattern as `vizboard`.
For the best possible unicode formatting I recommend using a unicode monospace font to use that is called [FiraCode](https://github.com/tonsky/FiraCode).

## keymap image

Still researching how to add the feature that will output your selected layers to an image (jpg, png) using meta-data from the user.
Things like the base image, font etc.. should be configurable by the user.
