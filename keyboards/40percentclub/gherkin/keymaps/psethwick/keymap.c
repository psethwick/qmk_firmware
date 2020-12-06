#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"
#include "keymap_steno.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_ortho_upsidedown_3x10(
    STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR ,
    STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR ,
    TO(1),   STN_NUM, STN_A,   STN_O,   STN_NUM, STN_E,   STN_U,   STN_NUM, STN_NUM, STN_NUM),

  [1] = LAYOUT_ortho_upsidedown_3x10(
    KC_A,    KC_S,    KC_E,    KC_T,    KC_T,    KC_Y,    KC_N,    KC_I,    KC_O,    KC_P,
//  A        S        D        F        G        H        J        K        L        ;   COMBOS
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    // leaves us bottom for FN / useful keys
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
    //LT(0, KC_TAB),   TO(0),   TO(0),   TO(0),   LCTL_T(KC_SPC),    LCTL_T(KC_SPC),    TO(0),    TO(0),   RSFT_T(KC_ENT),
  ),
};

void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI);
}
