/* Copyright 2021 Seth Rider with apologies to Kyle McCreery
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
  _NUMB,
  _WM,
  _DR,
  _DW
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_NUMB] = LAYOUT(
                TO(_NUMB), TO(_WM), TO(_DR), TO(_DW),
		  KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
                  KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_MUTE,  KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        TO(_WM),  KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_BSPC,  KC_P0,   _______, KC_PDOT, KC_PENT,

                  KC_F5,   KC_F6,   KC_F7

    ),
    [_WM] = LAYOUT(
                 _______,  _______, _______, _______,  
                 _______,  _______, _______, _______,  
                 G(KC_5),  G(KC_6), G(KC_7), G(KC_8),
        _______, G(KC_1),  G(KC_2), G(KC_3), G(KC_4),
     G(KC_LBRC), G(KC_H),  G(KC_J), G(KC_K), G(KC_L),
        KC_LSFT, RGB_SAD,  _______, RGB_SAI, _______,

                 _______, _______, _______

    ),
	  [_DR] = LAYOUT(
                  _______, _______, _______, _______,
                  _______, _______, _______, _______,
                  _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,
						   
                  _______, _______, _______

    ),
	  [_DW] = LAYOUT(
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

	static void render_icon(void) {
		static const char PROGMEM icon[] = {
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0x10, 0x08, 0x0c, 
			0x04, 0x12, 0x0a, 0x06, 0x06, 0x0c, 0x18, 0x30, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f, 0x02, 0x04, 0x0c, 0xb4, 0x44, 
			0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x0c, 0xfc, 0xfe, 0x0f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 
			0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x10, 0x10, 0x08, 0x07, 0x08, 0x08, 0x08, 0x0e, 0x19, 0x30, 
			0xe0, 0xc0, 0x20, 0x10, 0x10, 0x08, 0x0e, 0x0f, 0x0f, 0x08, 0x18, 0x38, 0x70, 0xe0, 0xc0, 0x00, 
			0x06, 0x09, 0x10, 0x20, 0x20, 0x20, 0x40, 0xc0, 0xc0, 0xc0, 0xe0, 0xe0, 0x70, 0x38, 0x3c, 0x1e, 
			0x0f, 0x07, 0x1c, 0x20, 0x20, 0x20, 0x40, 0x40, 0x40, 0x60, 0x70, 0x78, 0x3c, 0x3f, 0x1f, 0x0f
		};
		oled_write_raw_P(icon, sizeof(icon));

	}

	void oled_task_user(void) {
		render_icon();
		oled_set_cursor(0,6);

    switch (get_highest_layer(layer_state)) {
        case _NUMB:
            oled_write_ln_P(PSTR("NUMB"), false);
            break;
        case _WM:
            oled_write_ln_P(PSTR("WIN"), false);
            break;
        case _DR:
            oled_write_ln_P(PSTR("DEEB"), false);
            oled_write_ln_P(PSTR("REG"), false);
            break;
        case _DW:
            oled_write_ln_P(PSTR("DEEB"), false);
            oled_write_ln_P(PSTR("WEB"), false);
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
