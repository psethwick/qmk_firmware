#include QMK_KEYBOARD_H
#include "keymap_steno.h"

#define L_Z       LT(5, KC_Z)
#define L_X       LT(4, KC_X)
#define L_C       LT(3, KC_C)
#define L_V       LT(2, KC_V)
#define L_N       LT(1, KC_N)
#define L_B       LT(1, KC_B)
#define L_M       LT(2, KC_M)
#define L_COMM    LT(3, KC_COMM)
#define L_DOT     LT(4, KC_DOT)
#define L_SLSH    LT(5, KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_ortho_3x10(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    LGUI_T(KC_A),     ALT_T(KC_S),    LCTL_T(KC_D),    LSFT_T(KC_F),    KC_G,    KC_H,    RSFT_T(KC_J),    RCTL_T(KC_K),    ALGR_T(KC_L),    RGUI_T(KC_SCLN),
    L_Z,     L_X,    L_C,     L_V,     L_B,     L_N,     L_M,      L_COMM,   L_DOT,  L_SLSH
  ),

  [1] = LAYOUT_ortho_3x10(
    KC_BSPC, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC,
    _______, _______, _______, KC_ENT,  KC_SPC,  KC_SPC,  KC_ENT,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [2] = LAYOUT_ortho_3x10(
    _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    KC_TAB,  _______, _______, _______, _______, KC_COMM, KC_DOT,  KC_SLSH, KC_SCLN, KC_QUOT,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

  [3] = LAYOUT_ortho_3x10(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, TO(6)
  ),

  [4] = LAYOUT_ortho_3x10(
    _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    KC_TAB,  _______, _______, _______, _______, KC_LABK, KC_RABK, KC_QUES, KC_COLN, KC_DQUO,
    _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
  ),

  [5] = LAYOUT_ortho_3x10(
    KC_CALC, KC_WHOM, KC_MAIL, KC_MYCM, _______, _______, _______, _______, _______, KC_PSCR,
    _______, _______, _______, _______, _______, _______, _______, _______, BL_DEC,  BL_INC,
    _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______
  ),

  [6] = LAYOUT_ortho_3x10(
    STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR ,
    STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR ,
    TO(0), STN_NUM, STN_A,   STN_O,   STN_NUM, STN_E,   STN_U,   STN_NUM, STN_NUM, STN_NUM),
};

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output
  setPinOutput(D5);
  setPinOutput(B0);
}

void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    writePinLow(D5);
  } else {
    writePinHigh(D5);
  }

  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinLow(B0);
  } else {
    writePinHigh(B0);
  }
}

void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI);
}

    //KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    //KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, KC_GRV,
