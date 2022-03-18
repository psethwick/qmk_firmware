#include QMK_KEYBOARD_H

enum planck_layers {
  MAIN,
  NUM,
  /* SYM, */
  NAV,
  MOUSE,
  FUN,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   F  |   P  |   B  |      |      |   J  |   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   G  |      |      |   M  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   D  |   V  |      |      |   K  |   H  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Spc  |Lower |             |Raise | Ent  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
	// colemak dh
/* [_MAIN] = LAYOUT_planck_grid( */
/*    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,  _______, _______, KC_J,    KC_L,   KC_U,    KC_Y,    KC_SCLN, */
/*    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,  _______, _______, KC_M,    KC_N,   KC_E,    KC_I,    KC_O, */
/*    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,  _______, _______, KC_K,    KC_H,   KC_COMM, KC_DOT,  KC_SLSH, */
/*    _______, _______, _______, KC_SPC, KC_ESC, _______, _______, KC_SPC,  KC_ENT, _______, _______, _______ */
/* ), */
#define GUIA LGUI_T(KC_A)
#define ALTS LALT_T(KC_S)
#define CTLD LCTL_T(KC_D)
#define SFTF LSFT_T(KC_F)

#define GUISC RGUI_T(KC_SCLN)
#define ALTL LALT_T(KC_L)
#define CTLK RCTL_T(KC_K)
#define SFTJ RSFT_T(KC_J)

#define LTHM1 LT(NAV, KC_SPC)
#define LTHM2 LT(MOUSE, KC_TAB)
#define RTHM1 LT(NUM, KC_ENT)
#define RTHM2 LT(FUN, KC_BSPC)
#define ALTGX ALGR_T(KC_X)
#define ALTGD ALGR_T(KC_DOT)
#define ____ _______
[MAIN] = LAYOUT_ortho_34_split(
   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,
   GUIA,    ALTS,    CTLD,    SFTF,    KC_G,     KC_H,    SFTJ,   CTLK,    ALTL,   GUISC,
   KC_Z,    ALTGX,    KC_C,   KC_V,    KC_B,     KC_N,    KC_M,   KC_COMM, ALTGD,  KC_SLSH,
                             LTHM1,   LTHM2,     RTHM2,  RTHM1
),
[NAV] = LAYOUT_ortho_34_split(
   ____,    ____,    ____,    ____,    ____,     ____,    ____,    ____,    ____,    ____,
   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, ____,     KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,
   ____,    KC_ALGR, ____,    ____,    ____,     KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                              ____,    ____,     KC_DEL,  KC_BSPC
),
[NUM] = LAYOUT_ortho_34_split(
	KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, ____,    ____,    ____,    ____,    RESET,
    KC_DOT,  KC_4,    KC_5,    KC_6,    KC_EQL,  ____,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, ____,    ____,    ____,    KC_ALGR, ____,
                               KC_0,    KC_ESC,  ____,  ____
),
[FUN] = LAYOUT_ortho_34_split(
    KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, ____,    ____,    ____,    ____,    RESET,
    KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK, ____,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, ____,    ____,    ____,    KC_ALGR, ____,
                               KC_SPC,  KC_TAB,  ____,  ____
),
[MOUSE] = LAYOUT_ortho_34_split(
    RESET,   ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, ____,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, ____,
    ____,    KC_ALGR, ____,    ____,    ____,    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, ____,
                               ____,  ____,      KC_BTN1, KC_BTN2
),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
/* [_NAV] = LAYOUT_planck_grid( */
/*    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     _______, _______, KC_Y,    KC_U,   KC_I,    KC_O,    KC_P, */
/* LGUI_T(KC_A),LALT_T(KC_S),LCTL_T(KC_D),LSFT_T(KC_F),KC_G,_______, _______, KC_H,RSFT_T(KC_J),RCTL_T(KC_K),RALT_T(KC_L),RGUI_T(KC_SCLN), */
/*    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     _______, _______, KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, */
/*    _______, _______, _______, LT(_NAV, KC_SPC), LT(_NUM, KC_ESC),    _______, _______, KC_BSPC,  LT(_RAISE, KC_ENT), _______, _______, _______ */
/*     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC, */
/*     KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE, */
/*     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______, */
/*     _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY */
/* ), */

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
/* [_RAISE] = LAYOUT_planck_grid( */
/*     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, */
/*     KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, */
/*     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______, */
/*     _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY */
/* ), */
/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/* [_SPECIAL] = LAYOUT_planck_grid( */
/*     _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, */
/*     _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, */
/*     _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, */
/*     _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______ */
/* ) */

};

/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*   return update_tri_layer_state(state, _LOWER, _RAISE, _SPECIAL); */
/* } */
