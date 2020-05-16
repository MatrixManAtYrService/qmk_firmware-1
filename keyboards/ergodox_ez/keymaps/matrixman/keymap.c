#include QMK_KEYBOARD_H

// http://www.keyboard-layout-editor.com/#/gists/9be130e4c9b503317619

#define BASE 0 // default layer
#define SYMB_L 1 // symbols (activated by left symbol-layer key)
#define SYMB_R 2 // symbols (activated by right symbol-layer key)
#define NAV 3 // navigation

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Prose layer
 *
 * Layer switch keys:
 * [tap/toggle]
 * (momentary)
 * {toggle}
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |   1  |   2  |   3  |   4  |   5  | Del  |           | BSPC |   6  |   7  |   8  |   9  |   0  | BSPC   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Tab  |   Q  |   W  |   E  |   R  |   T  | Ctrl/|           |Ctrl/ |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------| Esc  |           |  ;   |------+------+------+------+------+--------|
 * |  Ctrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|Alt/  |           |Alt/  |------+------+------+------+------+--------|
 * |  Shift |   Z  |   X  |   C  |   V  |   B  |Tab   |           |Ins   |   N  |   M  |   ,  |   .  | /    | Shift  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Super | Ctrl | Alt  |      | [Nav]|                                       |[Nav] |      | Alt  | Ctrl | Super|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Ctrl | Alt  |       | Alt  | Ctrl |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      | Esc  |[Nav] |       |[Nav] |  Space |      |
 *                                 | Tab  | /    |------|       |------|  /     | Bspc |
 *                                 |      |[Symb]| Shift|       |Shift | [Symb] |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
   LT(NAV,KC_ESC),     KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_DELETE,
        KC_TAB,        KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   CTL_T(KC_ESC),
        KC_LCTRL,      KC_A,    KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,       KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   ALT_T(KC_TAB),
        LGUI_T(KC_UP), KC_LCTL, KC_LALT,KC_NO,  MO(NAV),

                                           KC_LCTRL,  KC_LALT,
                                                      MO(NAV),
                       KC_TAB,    LT(SYMB_L,KC_ESC),  KC_LSFT,
                  // right hand
                  KC_BSPC,       KC_6,   KC_7,   KC_8,   KC_9,   KC_0,      KC_BSPC,
                  CTL_T(KC_SCLN),KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,      KC_BSLS,
                                 KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,   KC_QUOT,
                  ALT_T(KC_INS), KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT,
                                         MO(NAV),KC_NO,  KC_RALT,KC_RCTL,   RGUI_T(KC_ENT),
                  KC_RALT,   KC_RCTRL,
                  MO(NAV),
                  KC_RSFT, LT(SYMB_R,KC_SPACE), KC_BSPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  `   |  ~   |   *  |   &  |   /  |  <   |           |   >  |   \  |   7  |   8  |   9  |   |  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  _   |  ^   |   %  |   $  |   (  |------|           |------|   )  |   4  |   5  |   6  |   -  | Enter  |
 * |--------+------+------+------+------+------|  [   |           |   ]  |------+------+------+------+------+--------|
 * |        |  =   |  #   |   @  |   !  |   {  |      |           |      |   }  |   1  |   2  |   3  |   +  | Enter  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |   "  |      |      |      |      |                                       |   0  |   .  |   .  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |   ?  |   :  |------|       |------|   ;  |  .   |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB_L] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_GRV ,  KC_TILD,  KC_ASTR,  KC_AMPR,  KC_SLSH,  LSFT(KC_COMM),
       KC_TRNS,  KC_UNDS,  KC_CIRC,  KC_PERC,  KC_DLR,   KC_LPRN,
       KC_TRNS,  KC_EQL,   KC_HASH,  KC_AT,    KC_EXLM,  KC_LCBR,  KC_LBRC,
 LSFT(KC_QUOT),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                         KC_TRNS,  KC_TRNS,
                                                   KC_TRNS,
                         LSFT(KC_SLSH),  KC_TRNS,  KC_TRNS,
       // right hand
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
  LSFT(KC_DOT),  KC_BSLS,  KC_7,     KC_8,     KC_9,     KC_PIPE,  KC_TRNS,
                 KC_RPRN,  KC_4,     KC_5,     KC_6,     KC_MINS,  KC_ENT,
       KC_RBRC,  KC_RCBR,  KC_1,     KC_2,     KC_3,     KC_PLUS,  KC_ENT,
                           KC_0,    KC_DOT,  KC_DOT,     KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,
       KC_TRNS,
       KC_TRNS,  KC_SCLN,  KC_DOT
),

[SYMB_R] = LAYOUT_ergodox(  // same as above, but avoids clash between SYMB and ;/:
       // left hand
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_GRV ,  KC_TILD,  KC_ASTR,  KC_AMPR,  KC_SLSH,  LSFT(KC_COMM),
       KC_TRNS,  KC_UNDS,  KC_CIRC,  KC_PERC,  KC_DLR,   KC_LPRN,
       KC_TRNS,  KC_EQL,   KC_HASH,  KC_AT,    KC_EXLM,  KC_LCBR,  KC_LBRC,
 LSFT(KC_QUOT),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                         KC_TRNS,  KC_TRNS,
                                                   KC_TRNS,
                         LSFT(KC_SLSH),  KC_COLN,  KC_TRNS,
       // right hand
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
  LSFT(KC_DOT),  KC_BSLS,  KC_7,     KC_8,     KC_9,     KC_PIPE,  KC_TRNS,
                 KC_RPRN,  KC_4,     KC_5,     KC_6,     KC_MINS,  KC_ENT,
       KC_RBRC,  KC_RCBR,  KC_1,     KC_2,     KC_3,     KC_PLUS,  KC_ENT,
                           KC_0,   KC_DOT,     KC_DOT,   KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,
       KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_DOT
),
/* Keymap 2: Navigation Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |Break |           |PrntSc|  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Click|MsLeft|MsUp  |MsDown|MsRght|------|           |------| Left | Down | Up   | Right|  F11 |   Enter|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |RClick| Btn4 |ScrlDn|ScrlUp| Btn5 |      |           |      | Home | PgDwn| PgUp | End  |  F12 |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Play2|      |      |      |      |                                       |      |      |      |      |Play1 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |Rstp2 |Rcrd2 |------|       |------|Rcrd1 |Rstp1 |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NAV] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,  KC_F1,    KC_F2,          KC_F3,        KC_F4,    KC_F5,  KC_PAUSE,
       KC_TRNS,  KC_F1,    KC_F2,          KC_F3,        KC_F4,    KC_F5,  KC_TRNS,
       KC_TRNS,  KC_BTN1,  KC_MS_L,        KC_MS_U,      KC_MS_D,  KC_MS_R,
       KC_TRNS,  KC_BTN2,  KC_BTN4,        KC_MS_WH_UP,  KC_MS_WH_DOWN,  KC_BTN5,  KC_TRNS,
       DM_PLY2,  KC_TRNS,  KC_TRNS,        KC_TRNS,      KC_TRNS,
                                           KC_TRNS,      KC_TRNS,
                                                         KC_TRNS,
                               DM_RSTP,    DM_REC2,      KC_TRNS,
       // right hand
       KC_PSCREEN,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
       KC_TRNS,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F12,
                    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_F11,   KC_ENT,
       KC_TRNS,     KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_F12,   KC_TRNS,
                              KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  DM_PLY1,
       KC_TRNS,     KC_TRNS,
       KC_TRNS,
       KC_TRNS, DM_REC1, DM_RSTP
),
};
