/* Copyright 2015-2021 Jack Humbert
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

#pragma once

#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PLANCK_SOUND)
// #define STARTUP_SONG SONG(NO_SOUND)

#    define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND) }
#endif

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4
#define IGNORE_MOD_TAP_INTERRUPT

#define LAYOUT_ortho_34_split( \
    k00, k01, k02, k03, k04, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k27, k28, k29, k2a, k2b, \
                   k33, k34, k37, k38  \
) \
{ \
    { k00, k01, k02, k03, k04, KC_NO }, \
    { k10, k11, k12, k13, k14, KC_NO }, \
    { k20, k21, k22, k23, k24, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, k07, k08, k09, k0a, k0b }, \
    { KC_NO, k17, k18, k19, k1a, k1b }, \
    { KC_NO, k27, k28, k29, k2a, k2b }, \
    { k37, k38, KC_NO, k33, k34, KC_NO } \
}

