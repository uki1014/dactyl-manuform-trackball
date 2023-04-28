#include QMK_KEYBOARD_H
#include "5x6_l_oled_r_tb.h"
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
            KC_TILD,   _______,    _______,    _______,   _______,   _______,                _______,   _______,    _______,   _______,    KC_LBRC,  KC_RBRC,
            _______,   _______,    _______,    LCTL(LSFT(KC_E)),     _______,   _______,     _______,   KC_HOME,    KC_UP,     KC_END,     _______,  _______,
            _______,   LCTL(KC_A), LCTL(KC_S), _______,   _______,   _______,                KC_PGUP,   KC_LEFT,    KC_DOWN,   KC_RIGHT,   _______,  _______,
            _______,   KC_UNDO,    KC_CUT,     KC_COPY,   KC_PSTE,   _______,                KC_PGDN,   TAB_L,      TAB_R,     _______,    _______,  _______,
                                   _______, _______,                                                                 _______,   _______,
                                                        _______, _______,                         _______,
                                                        _______, _______,                         _______,
                                                        _______, QK_BOOT,                _______, QK_BOOT),

    [_SYST] = LAYOUT_5x6(
        // left hand                                                             // right hand
            _______,   KC_F1,     KC_F2,      KC_F3,     KC_F4,     KC_F5,       KC_6,      KC_F7,      KC_F8,     KC_F9,     KC_F10,  	_______,
            _______,   KC_INS,    KC_PAUS,    _______,   IAD,   	   CAD,      _______,   _______,    _______,   _______,   _______,  _______,
            KC_CAPS,   KC_NUM,    KC_SCRL,    _______,   _______,   _______,     _______,   _______,    _______,   KC_MSTP,   KC_VOLD,  KC_VOLU,
            _______,   _______,   _______,    _______,   _______,   _______,     _______,   _______,    _______,   _______,   _______,  KC_MUTE,
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


//void keyboard_post_init_user(void) {
//    // Customise these values to desired behaviour
//    debug_enable=true;
//    debug_matrix=true;
//    debug_keyboard=true;
//    debug_mouse=true;
//}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)  },
    [_NAV] =  { ENCODER_CCW_CW(RGB_HUD, RGB_HUI)  },
    [_SYST] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)  },
    [_MOUSE] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) },
};
#endif

//#ifdef ENCODER_ENABLE
//bool encoder_update_user(uint8_t index, bool clockwise) {
//    switch(get_highest_layer(layer_state|default_layer_state)) {
//        case _BASE:
//        case _SYST:
//        case _MOUSE:
//            if (index == 0) {
//                if (clockwise) {
//                    tap_code(KC_VOLD);
//                } else {
//                    tap_code(KC_VOLU);
//                }
//            }
//            break;
//        case _NAV:
//            if (index == 0) {
//                if (clockwise) {
//                    tap_code(KC_PGUP);
//                } else {
//                    tap_code(KC_PGDN);
//                }
//            }
//            break;
//    }
//    return false;
//}
//#endif

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return OLED_ROTATION_180;
}

static void render_wylderbuilds(void) {
    static const char PROGMEM wylderbuilds[] = {
        // 'dark wylderbuilds_oled_name', 128x32px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0xc0, 0x40,
        0x40, 0x60, 0x20, 0x20, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x30, 0x20, 0x60,
        0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0x40, 0x40, 0x60, 0x60,
        0x40, 0x40, 0x40, 0x40, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0xc0, 0x40, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xf0,
        0x00, 0x00, 0xc1, 0xc1, 0x01, 0x01, 0xf1, 0x11, 0x01, 0x01, 0x01, 0x31, 0x60, 0xc0, 0x80, 0xc0,
        0xf0, 0x10, 0x00, 0x00, 0x00, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xc0,
        0x00, 0x01, 0x03, 0x9e, 0xf8, 0x00, 0x00, 0x20, 0xe0, 0xf0, 0x10, 0x30, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x20, 0xf0, 0x30, 0xa0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0x98, 0xf0, 0x70,
        0x00, 0x00, 0x00, 0x00, 0xf0, 0x80, 0x00, 0x70, 0xfe, 0x03, 0x00, 0x00, 0xe0, 0xf0, 0x00, 0x00,
        0x00, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x11, 0xf1, 0x11, 0x33, 0x63, 0xc3,
        0x83, 0x01, 0x01, 0xc1, 0xe1, 0x31, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
        0x1f, 0x7c, 0xff, 0x07, 0x7c, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0x80, 0xc0, 0x40, 0x40, 0x00, 0x00, 0x00, 0x7f, 0xff,
        0x60, 0x30, 0x18, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x01, 0x7f, 0xf2, 0x82, 0x02, 0x80, 0x80, 0x00,
        0x00, 0x00, 0x00, 0x7f, 0x0e, 0x1b, 0x70, 0xc0, 0x00, 0x00, 0x00, 0x01, 0xff, 0x81, 0xc1, 0x63,
        0x3e, 0x00, 0x00, 0x00, 0x1f, 0x7f, 0x40, 0x40, 0x7f, 0x00, 0x00, 0x00, 0x7f, 0x7f, 0x00, 0x00,
        0x00, 0x1f, 0xff, 0x80, 0xc0, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xc0, 0x60, 0x30, 0x1f,
        0x07, 0x00, 0x00, 0x01, 0x43, 0x44, 0x7c, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(wylderbuilds, sizeof(wylderbuilds));
}

bool oled_task_user(void) {
    oled_set_cursor(0, 1);
    if (is_keyboard_master()) {
        oled_write_P(PSTR("Layer\n"), false);

        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWRTY\n"), false);
                break;
            case _LOWER:
                oled_write_P(PSTR("LOWER\n"), false);
                break;
            case _RAISE:
                oled_write_P(PSTR("RAISE\n"), false);
                break;
            default:
                // Or use the write_ln shortcut over adding '\n' to the end of your string
                oled_write_ln_P(PSTR("Undefined"), false);
        }
        oled_set_cursor(0, 5);
        oled_write_P(PSTR("WPM: "), false);

        oled_write(get_u8_str(get_current_wpm(), ' '), false);
        // Host Keyboard LED Status

        oled_set_cursor(0, 8);
        led_t led_state = host_keyboard_led_state();

        oled_write_P(led_state.num_lock ? PSTR("NUMLK \n") : PSTR("    \n"), false);
        oled_write_P(led_state.caps_lock ? PSTR("CAPLK \n") : PSTR("    \n"), false);
        oled_write_P(led_state.scroll_lock ? PSTR("SCRLK \n") : PSTR("    \n"), false);
    } else {
        // write WPM to right OLED
        render_wylderbuilds();
    }

    return false;
}
#endif

