// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "backlight.h"
#include "keymap_extras/keymap_nordic.h"
#include "sv.h"
#include "i3.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _CM 0
#define _I3 1
#define _LW 2
#define _RS 3

#define THUMB_ROW {M(0), KC_RGUI, KC_LGUI, KC_LCTL, KC_LSFT, LT(_LW, KC_BSPC), LT(_RS, KC_SPC), LT(_I3, KC_ESC), KC_LALT, KC_DEL, KC_VOLD, KC_VOLU}
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_CM] = { /* Qwerty */
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   SV_AA  },
  {KC_APP,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    SV_OE,    SV_AE  },
  {KC_BSPC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  THUMB_ROW
},
[_I3] = { /* i3 */
  {KC_TRNS,  I3_WS1,  I3_WS2,  I3_WS3,  I3_WS4,  I3_WS5,  I3_WS6,  I3_WS7,  I3_WS8,  I3_WS9, I3_WS0,  KC_TRNS},
  {KC_TRNS,  KC_TRNS, I3_SPLH, I3_SPLV, I3_FULL, I3_LNCH, KC_TRNS, I3_FLFT, I3_FDWN, I3_FUP, I3_FRGT, KC_TRNS},
  {KC_TRNS,  KC_TRNS, I3_STCK, I3_TABD, I3_DFLT, KC_TRNS, KC_TRNS, I3_GLFT, I3_GDWN, I3_GUP, I3_GRGT, I3_TERM},
  {I3_KILL,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, I3_MENU, KC_TRNS, KC_MNXT, KC_MPLY,KC_TRNS, KC_TRNS}
},
[_RS] = { /* RAISE */
  {KC_TRNS, KC_PERC, NO_CIRC, NO_LESS, NO_LBRC, NO_PLUS, NO_MINS, NO_RBRC, NO_GRTR, NO_EQL,  NO_DLR,  NO_PND},
  {KC_TRNS, KC_HASH, NO_QUO2, NO_LCBR, NO_LPRN, NO_ASTR, NO_SLSH, NO_RPRN, NO_RCBR, NO_APOS, NO_UNDS, NO_EURO},
  {KC_TRNS, SV_BSLS, NO_COLN, KC_EXLM, NO_AMP,  NO_AT,   NO_TILD, SV_PIPE, NO_QUES, NO_SCLN, NO_ACUT, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_MPLY, KC_TRNS, KC_TRNS}
},
[_LW] = { /* LOWER */
  {KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS},
  {KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
}
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            backlight_step();
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
