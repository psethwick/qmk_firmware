/* Copyright 2021 Kyle McCreery
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

// Defines names for use in layer keycodes and the keymap

enum layer_names {
  _ALPHA,
  _SHF,
  _CTL,
  _ALT,
  _SUP
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
		  KC_A,   KC_B,    KC_C,   KC_D,
		  KC_E,   KC_F,    KC_G,   KC_H,
		  KC_I,   KC_J,    KC_K,   KC_L,
        TO(_S),   KC_P4,  KC_,     KC_P6,   _______,
        MO(_FN1), KC_P1,  KC_,     KC_P3,   KC_PENT,
        KC_BSPC,  KC_P0,   _______, KC_PDOT, _______,

                  KC_F5,   KC_F6,   KC_F7

    ),
    [_FN1] = LAYOUT(
                 _______,  _______, _______, _______,
                 _______,  _______, _______, _______,
                 RGB_HUD,  RGB_SPI, RGB_HUI, _______,
        _______, RGB_RMOD, RGB_TOG, RGB_MOD, _______,
        _______, RGB_VAD,  RGB_SPD, RGB_VAI, _______,
        _______, RGB_SAD,  _______, RGB_SAI, _______,

                 _______, _______, _______

    ),
	  [_FN2] = LAYOUT(
                  _______, _______, _______, _______,
                  _______, _______, _______, _______,
                  _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,
						   
                  _______, _______, _______

    ),
	  [_FN3] = LAYOUT(
                  _______, _______, _______, _______,
                  _______, _______, _______, _______,
                  _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,
    
                  _______, _______, _______

    )
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case 0:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        break;
		case 1:
            if (clockwise) {
                tap_code(KC_BRIU);
            } else {
                tap_code(KC_BRID);
            }
        break;
    }
    return true;
}
#endif

#ifdef OLED_DRIVER_ENABLE
	oled_rotation_t oled_init_user(oled_rotation_t rotation) {
		return OLED_ROTATION_270;       // flips the display 270 degrees
	}

	static void render_penis(void) {
		static const char PROGMEM penis[] = {
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0x10, 0x08, 0x0c, 
	0x04, 0x12, 0x0a, 0x06, 0x06, 0x0c, 0x18, 0x30, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f, 0x02, 0x04, 0x0c, 0xb4, 0x44, 
	0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x0c, 0xfc, 0xfe, 0x0f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x10, 0x10, 0x08, 0x07, 0x08, 0x08, 0x08, 0x0e, 0x19, 0x30, 
	0xe0, 0xc0, 0x20, 0x10, 0x10, 0x08, 0x0e, 0x0f, 0x0f, 0x08, 0x18, 0x38, 0x70, 0xe0, 0xc0, 0x00, 
	0x06, 0x09, 0x10, 0x20, 0x20, 0x20, 0x40, 0xc0, 0xc0, 0xc0, 0xe0, 0xe0, 0x70, 0x38, 0x3c, 0x1e, 
	0x0f, 0x07, 0x1c, 0x20, 0x20, 0x20, 0x40, 0x40, 0x40, 0x60, 0x70, 0x78, 0x3c, 0x3f, 0x1f, 0x0f
		};
		oled_write_raw_P(penis, sizeof(penis));

	}

	void oled_task_user(void) {
		render_penis();
		oled_set_cursor(0,6);

		oled_write_ln_P(PSTR("Layer"), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _FN1:
            oled_write_ln_P(PSTR("FN 1"), false);
            break;
        case _FN2:
            oled_write_ln_P(PSTR("FN 2"), false);
            break;
        case _FN3:
            oled_write_ln_P(PSTR("FN 3"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
	oled_write_ln_P(PSTR(""), false);
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_ln_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_ln_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_ln_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
	}
#endif
