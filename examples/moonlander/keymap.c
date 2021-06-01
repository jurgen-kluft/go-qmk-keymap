#include QMK_KEYBOARD_H
#include "version.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL

#undef LAYOUT
#define LAYOUT LAYOUT_moonlander

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};


enum tap_dance_codes {
  DANCE_0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  //# .-----------------------------------------------.                                             .-----------------------------------------------.
  //# | _____ | _____ | _____ | _____ | _____ | _____ |                                             | TO(1) | TO(2) | _____ | _____ | _____ | _____ |
  //# |-------+-------+-------+-------+-------+-------|                                             |-------+-------+-------+-------+-------+-------|
  //# | TG(9) | G(10) | TG(4) |   Q   |   W   |   E   |                                             |   R   |   T   | GHT)) | EFT)) |   Y   |   U   |
  //# |-------+-------+-------+-------+-------+-------|-------+-------.             .-------+-------|-------+-------+-------+-------+-------+-------|
  //# |   I   |   O   |   P   | _____ | LSFT) |   A   |   S   |   D   |             |   F   |   G   | EFT)) | GHT)) |   H   |   J   |   K   |   L   |
  //# .-------+-------+-------+-------+-------+-------+-------+-------|             |-------+-------.-------+-------+-------+-------+-------+-------.
  //#                         |   ;   |   ⇪   | _____ |   Z   |   X   |             |   C   |   V   |   B   |   N   |   M   |                        
  //#                         .-------+-------+-------+-------+-------.             .-------|-------|-------|-------|-------.                        
  [0] = LAYOUT(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(1),                  TO(2),                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TG(9),          TG(10),         
    TG(4),          KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           LCTL(LGUI(KC_RIGHT)),   LCTL(LGUI(KC_LEFT)),  KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT, 
    OSM(MOD_LSFT),  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           LCTL(LGUI(KC_LEFT)),    LCTL(LGUI(KC_RIGHT)), KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_CAPSLOCK,    
    KC_TRANSPARENT, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                         KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, TG(9),          MO(13),         MO(7),          KC_BSPACE,                                                    KC_BSPACE,      MO(5),          MO(12),         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                                    KC_SPACE,       MO(6),          KC_TRANSPARENT,         KC_TRANSPARENT,       MO(8),          KC_BSPACE                                                                       
  ),
  [1] = LAYOUT(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0),            TO(3),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,    KC_TRANSPARENT, 
    KC_TRANSPARENT, LGUI_T(KC_A),   LALT_T(KC_S),   LCTL_T(KC_D),   LSFT_T(KC_F),   KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, LSFT_T(KC_J),   LCTL_T(KC_K),   LALT_T(KC_L),   LGUI_T(KC_SCOLON), KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MO(6),          KC_TRANSPARENT, KC_TRANSPARENT,                                   KC_TRANSPARENT, KC_TRANSPARENT, MO(8),          KC_TRANSPARENT, KC_TRANSPARENT,    KC_TRANSPARENT, 
                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT                                                                     
  ),
  [2] = LAYOUT(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(3),            TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_J,           KC_C,           KC_Y,           KC_F,           KC_K,           KC_TRANSPARENT,   KC_TRANSPARENT, KC_Z,           KC_L,           KC_COMMA,       KC_U,           KC_Q,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_R,           KC_S,           KC_T,           KC_H,           KC_D,           KC_TRANSPARENT,   KC_TRANSPARENT, KC_M,           KC_N,           KC_A,           KC_I,           KC_O,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_UNDS,        KC_V,           KC_G,           KC_P,           KC_B,                                             KC_X,           KC_W,           KC_DOT,         KC_SCOLON,      KC_AT,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                   KC_BSPACE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_E                                                                            
  ),
  [3] = LAYOUT(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(2),            TO(1),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_J,           KC_C,           KC_Y,           KC_F,           KC_K,           KC_TRANSPARENT,   KC_TRANSPARENT, KC_Z,           KC_L,           KC_COMMA,       KC_U,           KC_Q,           KC_TRANSPARENT, 
    KC_TRANSPARENT, LGUI_T(KC_R),   LALT_T(KC_S),   LCTL_T(KC_T),   LSFT_T(KC_H),   KC_D,           KC_TRANSPARENT,   KC_TRANSPARENT, KC_M,           LSFT_T(KC_N),   LCTL_T(KC_A),   LALT_T(KC_I),   LGUI_T(KC_O),   KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_UNDS,        KC_V,           KC_G,           KC_P,           KC_B,                                             KC_X,           KC_W,           KC_DOT,         KC_SCOLON,      KC_AT,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MO(6),          KC_TRANSPARENT, KC_TRANSPARENT,                                   KC_TRANSPARENT, KC_TRANSPARENT, MO(8),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_E                                                                            
  ),
  [4] = LAYOUT(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, LSFT(KC_Q),     LSFT(KC_W),     LSFT(KC_E),     LSFT(KC_R),     LSFT(KC_T),     KC_TRANSPARENT,   KC_TRANSPARENT, LSFT(KC_Y),     LSFT(KC_U),     LSFT(KC_I),     LSFT(KC_O),     LSFT(KC_P),     KC_TRANSPARENT, 
    KC_TRANSPARENT, LSFT(KC_A),     LSFT(KC_S),     LSFT(KC_D),     LSFT(KC_F),     LSFT(KC_G),     KC_TRANSPARENT,   KC_TRANSPARENT, LSFT(KC_H),     LSFT(KC_J),     LSFT(KC_K),     LSFT(KC_L),     KC_UNDS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, LSFT(KC_Z),     LSFT(KC_X),     LSFT(KC_C),     LSFT(KC_V),     LSFT(KC_B),                                       LSFT(KC_N),     LSFT(KC_M),     LSFT(KC_COMMA), LSFT(KC_DOT),   KC_AT,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT                                                                  
  ),
  [5] = LAYOUT(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          
    KC_NO,          KC_TRANSPARENT, KC_SLASH,       KC_LBRACKET,    KC_RBRACKET,    KC_CIRC,        KC_TRANSPARENT,   KC_TRANSPARENT, KC_DQUO,        KC_LABK,        KC_RABK,        KC_UNDS,        KC_TILD,        KC_NO,          
    KC_TRANSPARENT, KC_HASH,        KC_EQUAL,       KC_LCBR,        KC_RCBR,        KC_ASTR,        KC_TRANSPARENT,   KC_TRANSPARENT, KC_PLUS,        KC_LPRN,        KC_RPRN,        KC_MINUS,       KC_COLN,        KC_NO,          
    KC_TRANSPARENT, KC_DLR,         KC_BSLASH,      KC_PIPE,        KC_AMPR,        KC_GRAVE,                                         KC_QUOTE,       KC_PERC,        KC_EXLM,        KC_QUES,        KC_AT,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MO(6),          KC_TRANSPARENT,                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT                                                                  
  ),
  [6] = LAYOUT(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_ASTR,        KC_PLUS,        KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_MINUS,       KC_SLASH,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_5,           KC_6,           KC_7,           KC_8,           KC_EQUAL,       KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_EQUAL,       KC_9,           KC_TRANSPARENT,                                   KC_TRANSPARENT, KC_0,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT                                                                  
  ),
  //# .-----------------------------------------------.                                             .-----------------------------------------------.
  //# | _____ | _____ | _____ | _____ | _____ | _____ |                                             | _____ | _____ | _____ | _____ | _____ | _____ |
  //# |-------+-------+-------+-------+-------+-------|                                             |-------+-------+-------+-------+-------+-------|
  //# | KC_NO | KC_NO | KC_NO | _____ | KC_W) | SCAPE |                                             |   ⏎   |   ⭾   | _____ | _____ |   ⎀   |   ⇞   |
  //# |-------+-------+-------+-------+-------+-------|-------+-------.             .-------+-------|-------+-------+-------+-------+-------+-------|
  //# |   ⇤   | _____ | _____ | KC_NO | _____ |   ⌘   |   ⎇   | LCTRL |             | SHIFT |   ⌦  | _____ | _____ |   ◁   |   ▽   |   △   |   ▷   |
  //# .-------+-------+-------+-------+-------+-------+-------+-------|             |-------+-------.-------+-------+-------+-------+-------+-------.
  //#                         | _____ | _____ | _____ | _UNDO | C_CUT |             | _COPY | PASTE |   ⌫   |   ⌦  |   ⇟   |                        
  //#                         .-------+-------+-------+-------+-------.             .-------|-------|-------|-------|-------.                        
  [7] = LAYOUT(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          
    KC_NO,          KC_TRANSPARENT, LCTL(KC_W),     KC_ESCAPE,      KC_ENTER,       KC_TAB,         KC_TRANSPARENT,   KC_TRANSPARENT, KC_INSERT,      KC_PGUP,        KC_HOME,        KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          
    KC_TRANSPARENT, KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_LSHIFT,      KC_DELETE,      KC_TRANSPARENT,   KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_PC_UNDO,     KC_PC_CUT,      KC_PC_COPY,     KC_PC_PASTE,    KC_BSPACE,                                        KC_DELETE,      KC_PGDOWN,      KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                   KC_TRANSPARENT, MO(13),         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT                                                                  
  ),
  [8] = LAYOUT(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,   KC_TRANSPARENT, KC_ESCAPE,      KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_LSHIFT,      KC_NO,          KC_NO,            KC_NO,          KC_ENTER,       KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_NO,          
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                            KC_TAB,         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT                                                                  
  ),
  [9] = LAYOUT(
    AU_TOG,         RGB_TOG,        TOGGLE_LAYER_COLOR, RGB_VAD,            RGB_VAI,        RGB_SAD,        RGB_SAI,             RESET,          WEBUSB_PAIR,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,      KC_NO,          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_BRIGHTNESS_UP,   KC_TRANSPARENT, KC_MS_WH_UP,    KC_AUDIO_VOL_UP,     KC_TRANSPARENT, KC_EQUAL,       KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     KC_MEDIA_PREV_TRACK, TD(DANCE_0),    
    KC_TRANSPARENT, KC_LGUI,        KC_LALT,            KC_LCTRL,           KC_LSHIFT,      KC_MS_WH_DOWN,  KC_AUDIO_VOL_DOWN,   KC_TRANSPARENT, KC_MINUS,       KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MEDIA_NEXT_TRACK, MU_TOG,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_BRIGHTNESS_DOWN, KC_TRANSPARENT, KC_TRANSPARENT,                                      KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_BTN3,     KC_MS_WH_RIGHT, KC_TRANSPARENT,      MU_MOD,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT,                                      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT, 
                                                                            KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT                                                                       
  ),
  [10] = LAYOUT(
    TO(5),     KC_1,  KC_2,   KC_3,     KC_4,     KC_5,      KC_TRANSPARENT,   KC_0,           KC_6,           KC_7,           KC_8,      KC_9,           KC_NO,          KC_TRANSPARENT, 
    KC_TAB,    KC_Q,  KC_W,   KC_E,     KC_R,     KC_T,      KC_NO,            KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,      KC_O,           KC_P,           KC_TRANSPARENT, 
    KC_ESCAPE, KC_A,  KC_S,   KC_D,     KC_F,     KC_G,      KC_NO,            KC_NO,          KC_H,           KC_J,           KC_K,      KC_L,           KC_SCOLON,      KC_TRANSPARENT, 
    KC_LSHIFT, KC_Z,  KC_X,   KC_C,     KC_V,     KC_B,                                        KC_N,           KC_M,           KC_COMMA,  KC_DOT,         KC_SLASH,       KC_TRANSPARENT, 
    KC_NO,     KC_NO, MO(11), KC_LCTRL, KC_LALT,  KC_ENTER,                                    KC_TRANSPARENT, KC_LALT,        KC_LSHIFT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                        KC_SPACE, KC_BSPACE, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT                                                             
  ),
  [11] = LAYOUT(
    TO(5),          KC_0,      KC_9,           KC_8,     KC_7,     KC_6,      KC_TRANSPARENT,   KC_0,           KC_6,           KC_7,           KC_8,     KC_9,           KC_NO,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_P,      KC_O,           KC_I,     KC_U,     KC_Y,      KC_NO,            KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,     KC_O,           KC_P,      KC_TRANSPARENT, 
    KC_ESCAPE,      KC_SCOLON, KC_L,           KC_K,     KC_J,     KC_H,      KC_NO,            KC_NO,          KC_H,           KC_J,           KC_K,     KC_L,           KC_SCOLON, KC_TRANSPARENT, 
    KC_LSHIFT,      KC_SLASH,  KC_DOT,         KC_COMMA, KC_M,     KC_N,                                        KC_N,           KC_M,           KC_COMMA, KC_DOT,         KC_SLASH,  KC_RSHIFT,      
    KC_TRANSPARENT, KC_NO,     KC_TRANSPARENT, KC_LCTRL, KC_LALT,  KC_ENTER,                                    KC_TRANSPARENT, KC_LALT,        KC_LCTRL, KC_TRANSPARENT, KC_NO,     KC_NO,          
                                                         KC_SPACE, KC_BSPACE, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT                                                       
  ),
  [12] = LAYOUT(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_LSHIFT,      KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT                                                                  
  ),
  [13] = LAYOUT(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_RSHIFT,      KC_RCTRL,       KC_LALT,        KC_RGUI,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT                                                                  
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,255,6}, {0,0,254}, {78,209,152}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {41,218,228}, {160,208,209}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {43,202,213}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,255,6}, {0,0,254}, {0,222,218}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254}, {0,0,254} },
    [1] = { {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195}, {0,15,195} },
    [2] = { {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241}, {24,82,241} },
    [3] = { {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187}, {28,175,187} },
    [4] = { {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198}, {165,249,198} },
    [5] = { {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218}, {0,222,218} },
    [6] = { {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228}, {129,70,228} },
    [7] = { {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152}, {78,209,152} },
    [8] = { {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228}, {41,218,228} },
    [9] = { {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {0,183,238}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195}, {124,179,195} },
    [10] = { {0,183,238}, {141,255,233}, {141,255,233}, {141,255,233}, {0,0,0}, {141,255,233}, {141,255,233}, {0,183,238}, {141,255,233}, {0,0,0}, {141,255,233}, {0,183,238}, {0,183,238}, {141,255,233}, {154,255,255}, {141,255,233}, {141,255,233}, {0,183,238}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {141,255,233}, {0,0,0}, {141,255,233}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {141,255,233}, {141,255,233}, {0,0,0}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {0,0,0}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {0,0,0}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {0,0,0}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {0,0,0}, {0,0,0}, {88,185,172}, {0,0,0}, {0,0,0}, {0,0,255} },
    [11] = { {0,183,238}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {0,0,0}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {88,185,172}, {0,0,0}, {0,0,0}, {0,0,0} },
    [12] = { {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188}, {22,240,188} },
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      set_layer_color(7);
      break;
    case 8:
      set_layer_color(8);
      break;
    case 9:
      set_layer_color(9);
      break;
    case 10:
      set_layer_color(10);
      break;
    case 11:
      set_layer_color(11);
      break;
    case 12:
      set_layer_color(12);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[1];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: register_code16(KC_MEDIA_STOP); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_PLAY_PAUSE); register_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: unregister_code16(KC_MEDIA_STOP); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
    }
    dance_state[0].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
};

/*
qmk-keyboard-format:json:begin
{
    "name": "moonlander",
    "numkeys": 72,
    "rows": [
        [ -3,  0,  1,  2,  3,  4,  5,  6, -2,  7,  8,  9, 10, 11, 12, 13 ],
        [ -3, 14, 15, 16, 17, 18, 19, 20, -2, 21, 22, 23, 24, 25, 26, 27 ],
        [ -3, 28, 29, 30, 31, 32, 33, 34, -2, 35, 36, 37, 38, 39, 40, 41 ],
        [ -3, 42, 43, 44, 45, 46, 47, -1, -2, -1, 48, 49, 50, 51, 52, 53 ],
        [ -3, 54, 55, 56, 57, 58, 59, -1, -2, -1, 60, 61, 62, 63, 64, 65 ],
        [ -3, -1, -1, -1, -1, 66, 67, 68, -2, 69, 70, 71, -1, -1, -1, -1 ]
    ],
    "spacing": [
        0,
        0,
        0,
        2
    ],
    "vizcellwidth": 5,
    "vizemits": [
        { "line": "[0] = LAYOUT(", "layer": "0" },
        { "line": "[7] = LAYOUT(", "layer": "7" }
    ],
    "vizline": "//#",
    "vizboard": [
        "  //# .-----------------------------------------------.                                             .-----------------------------------------------.",
        "  //# | _000_ | _001_ | _002_ | _003_ | _004_ | _005_ |                                             | _006_ | _007_ | _008_ | _009_ | _010_ | _011_ |",
        "  //# |-------+-------+-------+-------+-------+-------|                                             |-------+-------+-------+-------+-------+-------|",
        "  //# | _012_ | _013_ | _014_ | _015_ | _016_ | _017_ |                                             | _018_ | _019_ | _020_ | _021_ | _022_ | _023_ |",
        "  //# |-------+-------+-------+-------+-------+-------|-------+-------.             .-------+-------|-------+-------+-------+-------+-------+-------|",
        "  //# | _024_ | _025_ | _026_ | _027_ | _028_ | _029_ | _030_ | _031_ |             | _032_ | _033_ | _034_ | _035_ | _036_ | _037_ | _038_ | _039_ |",
        "  //# .-------+-------+-------+-------+-------+-------+-------+-------|             |-------+-------.-------+-------+-------+-------+-------+-------.",
        "  //#                         | _040_ | _041_ | _042_ | _043_ | _044_ |             | _045_ | _046_ | _047_ | _048_ | _049_ |                        ",
        "  //#                         .-------+-------+-------+-------+-------.             .-------|-------|-------|-------|-------.                        "
    ],
    "vizsymbols": {
        "_______": "     ",
        "KC_TRANSPARENT": "_____",
        "KC_TRANS": "     ",
        "KC_0": "  0  " ,
        "KC_1": "  1  " ,
        "KC_2": "  2  " ,
        "KC_3": "  3  " ,
        "KC_4": "  4  " ,
        "KC_5": "  5  " ,
        "KC_6": "  6  " ,
        "KC_7": "  7  " ,
        "KC_8": "  8  " ,
        "KC_9": "  9  " ,
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
        "KC_COMM": "  ,  ",
        "KC_DOT": "  .  ",
        "KC_SCOLON": "  ;  ",
        "KC_SCLN": "  :  ",
        "KC_SLASH": "  \/  ",
        "KC_SLSH": "  \/  ",
        "KC_BSLS": "  \\  ",
        "KC_EXLM": "  !  ",
        "KC_PIPE": "  |  ",
        "KC_QUOT": "  '  ",
        "KC_HASH": "  #  ",
        "KC_AMPR": "  &  ",
        "KC_PERC": "  %  ",
        "KC_AT": "  @  ",
        "KC_DLR": "  $  ",
        "KC_CIRC": "  ^  ",
        "KC_EQL": "  =  ",
        "KC_ASTR": "  *  ",
        "KC_MINS": "  -  ",
        "KC_PLUS": "  +  ",
        "KC_LCBR": "  {  ",
        "KC_RCBR": "  }  ",
        "KC_LPRN": "  (  ",
        "KC_RPRN": "  )  ",
        "KC_GRV": "  `  ",
        "KC_LBRC": "  [  ",
        "KC_RBRC": "  ]  ",
        "KC_TILD": "  ~  ",
        "KC_ESC": "  ⎋  " ,
        "KC_CUT": "  ✄  " ,
        "KC_UNDO": "  ↶  " ,
        "KC_REDO": "  ↷  " ,
        "KC_VOLU": "  🕪  " ,
        "KC_VOLD": "  🕩  " ,
        "KC_MUTE":   "  🕨  " ,
        "KC_TAB": "  ⭾  " ,
        "KC_MENU": "  𝌆  " ,
        "KC_CAPSLOCK": "  ⇪  " ,
        "KC_NUMLK": "  ⇭  " ,
        "KC_SCRLK": "  ⇳  " ,
        "KC_PRSCR": "  ⎙  " ,
        "KC_PAUSE": "  ⎉  " ,
        "KC_BREAK": "  ⎊  " ,
        "KC_ENTER": "  ⏎  " ,
        "KC_BSPACE": "  ⌫  " ,
        "KC_DELETE": "  ⌦ " ,
        "KC_INSERT": "  ⎀  " ,
        "KC_LEFT": "  ◁  " ,
        "KC_RIGHT": "  ▷  " ,
        "KC_UP": "  △  " ,
        "KC_DOWN": "  ▽  " ,
        "KC_HOME": "  ⇤  " ,
        "KC_END": "  ⇥  " ,
        "KC_PGUP": "  ⇞  " ,
        "KC_PGDOWN": "  ⇟  " ,
        "KC_LSFT": "  ⇧  " ,
        "KC_RSFT": "  ⇧  " ,
        "KC_LCTL": "  ^  " ,
        "KC_RCTL": "  ^  " ,
        "KC_LALT": "  ⎇  " ,
        "KC_RALT": "  ⎇  " ,
        "KC_HYPER": "  ✧  " ,
        "KC_LGUI": "  ⌘  " ,
        "KC_RGUI": "  ⌘  "
    }    
}
qmk-keyboard-format:json:end
*/
