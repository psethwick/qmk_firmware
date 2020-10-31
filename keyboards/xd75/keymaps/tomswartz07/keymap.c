/* Copyright 2017 Wunder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | `~     | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | BKSP   | -      | =      | \      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | Del    | [      | ]      | HOME   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | ESC    | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | ENTER  |        |        | END    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | '      |        |        | PG UP  |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LGUI   | LALT   | LOWER  | BKSP   | ENTER  | SPACE  | RAISE  | LEFT   | DOWN   | UP     | RIGHT  |        |        | PG DN  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_QWERTY] = LAYOUT_ortho_5x15( /* QWERTY */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, KC_MINS, KC_EQL,   KC_BSLS,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,  KC_LBRC, KC_RBRC,  KC_HOME,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  KC_NO,   KC_NO,    KC_END,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT, KC_NO,   KC_NO,    KC_PGUP,
    KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_BSPC, KC_ENT, KC_SPC, RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_RALT, KC_NO,    KC_PGDN
  ),

/* LOWER
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ~      | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | BKSP   |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | ~      |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | DEL    |        |        |        |        |        |        | _      | +      | {      | }      |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |        |        |        | Home   | End    |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        | Vol -  | VOL +  |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_LOWER] = LAYOUT_ortho_5x15( /* LOWER */
    KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    _______, KC_MINS, KC_EQL,   KC_BSLS,
    KC_TILD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_END,  _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, _______, _______, _______, _______
  ),

/* RAISE
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | `~     | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | BKSP   |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | `~     |        |        |        |        |        |        |        |        |        |        | Del    |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | DEL    |        |        |        |        |        |        | -      | =      | [      | ]      | \      |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_RAISE] = LAYOUT_ortho_5x15( /* RAISE */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    _______, KC_MINS, KC_EQL,   KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

/* ADJUST
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        | RGB HD | RGB HI |        |        |        |        |        |        | PR SCR | SCR LK | INSERT |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | PLAY   | NEXT   |        | RGB SD | RGB SI | LEFT   | DOWN   | UP     | RIGHT  |        | RESET  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   |RGB RMD | RGB VD | RGB VI |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | RGB TG | RGB MD |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_ADJUST] = LAYOUT_ortho_5x15( /* ADJUST */
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NLCK, KC_SLSH,
    _______, RESET,   _______, _______, RGB_HUD, RGB_HUI, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_INS,
    KC_MPRV, KC_MPLY, KC_MNXT, _______, RGB_SAD, RGB_SAI, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, RESET,   _______, _______, _______,
    KC_VOLD, KC_MUTE, KC_VOLU, RGB_RMOD,RGB_VAD, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
