#include QMK_KEYBOARD_H
#include "5x6_track.h"
#define _BASE   0
#define _NAV    1
#define _SYST   2
#define _MOUSE  3  //layer for mouse functions

// Macros
#define TASK    LCTL(LSFT(KC_ESC))
#define TAB_R   LCTL(KC_TAB)
#define TAB_L   LCTL(LSFT(KC_TAB))
#define TAB_RO  LCTL(LSFT(KC_T))
#define CAD     LCTL(LALT(KC_DEL))
#define IAD		LCTL(LALT(KC_INS))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_5x6(
        // left hand                                                            // right hand
            LT(_SYST, KC_ESC),  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,         KC_6,    KC_7,    KC_8,   KC_9,     KC_0,    KC_MINS,
            KC_TAB,   		KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,             KC_Y,    KC_U,    KC_I,   KC_O,     KC_P,    KC_DEL,
            KC_LCTL,   		KC_A,    KC_S,    KC_D,   KC_F,   KC_G,             KC_H,    KC_J,    KC_K,   KC_L,     KC_SCLN, KC_QUOT,
            KC_LSFT,     	KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,             KC_N,    KC_M,    KC_COMM,KC_DOT,   KC_SLSH, KC_RSFT,
                                     KC_APP,  KC_LGUI,                                            MO(_NAV),  TG(_MOUSE),
                                                KC_LALT, LT(_NAV, KC_SPC),          KC_SPC,
                                                KC_BTN3, KC_BTN1,                   KC_WFWD,
                                                SNIPING, DRGSCRL,          KC_BTN1, KC_WBAK),

    [_NAV] = LAYOUT_5x6(
        // left hand                                                                         // right hand
            KC_TILD,   _______,    _______,    _______,   _______,   _______,                _______,   _______,    _______,   _______,    KC_LBRC, KC_RBRC,
            _______,   _______,    _______,    LCTL(LSFT(KC_E)),     _______,   _______,     _______,   KC_HOME,    KC_UP,     KC_END,     _______,  _______,
            _______,   LCTL(KC_A), LCTL(KC_S), _______,   _______,   _______,                KC_PGUP,   KC_LEFT,    KC_DOWN,   KC_RIGHT,   _______,  _______,
            _______,   KC_UNDO,    KC_CUT,     KC_COPY,   KC_PSTE,   _______,                KC_PGDN,   TAB_L,      TAB_R,     _______,    _______,  _______,
                                   _______, _______,                                                                 _______,   _______,
                                                        _______, _______,                         _______,
                                                        _______, _______,                         _______,
                                                        _______, _______,                _______, _______),

    [_SYST] = LAYOUT_5x6(
        // left hand                                                             // right hand
            _______,   KC_F1,     KC_F2,      KC_F3,     KC_F4,     KC_F5,       KC_6,      KC_F7,      KC_F8,     KC_F9,     KC_F10,  	_______,
            _______,   KC_INS,    KC_PAUS,    _______,   IAD,   	   CAD,      _______,   _______,    _______,   _______,   _______,  _______,
            KC_CAPS,   KC_NUM,    KC_SCRL,    _______,   _______,   _______,     _______,   _______,    KC_MSTP,   KC_VOLD,   KC_VOLU,  KC_MUTE,
            _______,   _______,   _______,    _______,   _______,   _______,     _______,   _______,    _______,   _______,   _______,  _______,
                                  _______,    _______,                                                   QK_BOOT,   EE_CLR,
                                                        _______, _______,                        _______,
                                                        _______, _______,                        _______,
                                                        _______, _______,               _______, _______),


    [_MOUSE] = LAYOUT_5x6(
        // left hand                                                              // right hand
            _______,   _______,    _______,    _______,   _______,   _______,     _______,   _______,    _______,   _______,   _______,  _______,
            _______,   _______,    _______,    _______,   _______,   _______,     _______,   _______,    _______,   _______,   _______,  _______,
            _______,   _______,    _______,    _______,   _______,   _______,     _______,   KC_BTN1,    KC_BTN2,   KC_BTN3,   _______,  _______,
            _______,   _______,    _______,    _______,   _______,   _______,     _______,   _______,    _______,   _______,   _______,  _______,
                                   _______, _______,                                                     _______,  _______,
                                                        _______, _______,                     _______,
                                                        _______, _______,                     _______,
                                                        _______, _______,            _______, _______),

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


