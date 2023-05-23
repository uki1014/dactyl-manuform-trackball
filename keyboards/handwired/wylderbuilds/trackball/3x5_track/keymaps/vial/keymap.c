#include QMK_KEYBOARD_H
#include "3x5_track.h"

#define _COLEMAK 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_3x5(
        KC_Q  ,KC_W  , KC_F  , KC_P  , KC_G  ,                      KC_J  , KC_L  , KC_U  , KC_Y  , KC_SCLN,
        KC_A  , KC_R  , KC_S  , KC_T  , KC_D  ,                      KC_H  , KC_N  , KC_E  , KC_I  , KC_O,
        KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                      KC_K  , KC_M  ,KC_COMM,KC_DOT , KC_SLSH,
                                      RAISE, KC_SPC,               LOWER,
                                      KC_TAB, KC_HOME,             KC_ENT,
                                      KC_BSPC, KC_GRV,     KC_DEL, KC_LALT
        ),

    [_LOWER] = LAYOUT_3x5(
        _______,_______,_______,_______,KC_LBRC,                     KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,KC_PLUS,
        KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                     KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,
        _______,_______,_______,_______,_______,                     _______, KC_P1 , KC_P2 , KC_P3 ,KC_EQL,
                                        _______,_______,             _______,
                                        KC_BTN3,KC_BTN1,             _______,
                                        SNIPING,DRGSCRL,     _______,QK_BOOT

        ),

    [_RAISE] = LAYOUT_3x5(
        KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                     KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,
        _______,_______,_______,_______,KC_LBRC,                     KC_RBRC,_______,KC_NLCK,KC_INS ,KC_SLCK,
        KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                     KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,KC_VOLD,
                                        _______,_______,             _______,
                                        _______,_______,             _______,
                                        QK_BOOT,_______,     _______,_______
        )
};

void keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
    debug_mouse=true;
#else
    debug_enable=false;
    debug_matrix=false;
    debug_keyboard=false;
    debug_mouse=false;
#endif
}
