#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _RAISE  1
#define _LOWER 2
#define _SWE  3
#define SPACE KC_SPACE
#define _BL 4 // Backlight
// #define _ADJUST 3
#define TG_NKRO MAGIC_TOGGLE_NKRO
#define ___ _______


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc~ |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | BSPC |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | ENTR |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |(Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  '"  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI | Alt  |  -_  | TO 1 | Space|Space |Raise | LEFT | DOWN |  UP  | RGHT |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,       KC_I,    KC_O,    KC_P,    KC_LBRC, \
  KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,       KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSPO,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,       KC_COMM, KC_DOT,  KC_QUOT, KC_ENTER, \
  KC_LCTL,  KC_LGUI, KC_LALT, KC_MINUS,MO(_LOWER),KC_BSPC, SPACE,   MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Raise (NUMERICAL)
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |  7   |  8   |  9   |  0   | Back |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   {  |   }  |   [  |   ]  |      |      |      |      |      |      |  =+  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |(Shift|   \  |   |  |   _  |      |      |      |      |      |      |      |   )  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | TO 0 |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
    KC_GRAVE,  KC_1,     KC_2,     KC_3,    KC_4,        KC_5,     KC_6,    KC_7,    KC_8,     KC_9,     KC_0,     KC_CIRC, \
    KC_TILDE, KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,       KC_F9,     KC_BSLS,      KC_TILDE, \
    ___,       KC_BSLS,  KC_PIPE,  KC_UNDS, ___,         ___,      ___,     ___,     KC_LCBR,      KC_RCBR,      KC_INS,      KC_RPRN, \
    ___,       ___,      ___,      ___,     ___,         KC_DEL,      ___,     ___,     ___,      ___,      ___,      ___ \
),

/* Lower (FUNCTION)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  RGB | PScr |  Ins |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Home |  Del |  End |      |      |      | TO 0 | TO 1 | SWE  | Mute | Play |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | PGDN | PGUP |  *   |Raise | Prev | Vol- | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
    KC_F1,    KC_EXLM,    KC_DQUO,    KC_HASH,  ___ , KC_PERC,   KC_AMPR,    KC_SLSH,   KC_LPRN,       KC_RPRN,  KC_EQL,   KC_QUES, \
    ___,      RGB_TOG,  KC_PSCR,  KC_INS,  ___,     ___,      ___,     ___,         ___,         ___,      ___,      RESET, \
    ___,      KC_HOME,  KC_DEL,   KC_END,  ___,     ___,      ___,     ___,         ___,         TO(_SWE), KC_MUTE,  KC_MPLY, \
    ___,      ___,      ___,      ___,     KC_PGDN, KC_PGUP,  KC_ASTR, ___,         KC_MPRV,     KC_VOLD,  KC_VOLU,  KC_MNXT \
),

/* SWE
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_SWE] = LAYOUT_ortho_4x12( \
    TO(_QWERTY), ___,      ___,      ___,     ___,     ___,       ___,     ___,    ___,      ___,      ___,        ___, \
    ___,         ___,      ___,      ___,     ___,     ___,       ___,     ___,    ___,      ___,      RALT(KC_W), ___, \
    ___,         ___,      ___,      ___,     ___,     ___,       ___,     ___,    ___,      ___,      RALT(KC_P), RALT(KC_Q), \
    ___,         ___,      ___,      ___,     ___,     ___,       ___,     ___,    ___,      ___,      ___,        ___ \
)

/* Adjust
 G = git
 M = mail
 * ,-----------------------------------------------------------------------------------.
 * | gAdd |gStash|      | const|      | Clog |      |      | Mstk | Mrad |Mgmail|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | gPush|      |      | if() |      | Clog2|      |      |      |      |Mcity |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | gPull|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Lower |      |      |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */


/* Empty
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Lower |      |      |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
};

// Macro actions for each corresponding ID.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch (id) {
  case 0:
    if (record->event.pressed) {
      register_code(KC_RSFT);
#ifdef BACKLIGHT_ENABLE
      backlight_step();
#endif
    }
    else {
      unregister_code(KC_RSFT);
    }
    break;
  }
  return MACRO_NONE;
};

// Loop
void matrix_scan_user(void) {
  // Empty
};
