// Copyright 2022 Matthew Dews (@matthew-dews)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "6x7_track.h"
enum custom_layer {
    _QWERTY,
    _LOWER,
    _RAISE,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_6x7(
        KC_ESC , KC_F1   , KC_F2  , KC_F3 , KC_F4 , KC_F5 , KC_F6 ,                         KC_F7 , KC_F8  , KC_F9  , KC_F10, KC_F11, KC_F12   , _______,
        DRGSCRL, KC_GRV  , KC_1   , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7   , KC_8   , KC_9  , KC_0  , KC_LBRC  , KC_RBRC,
        SNIPING, KC_TAB  , KC_Q   , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U   , KC_I   , KC_O  , KC_P  , KC_QUOT  , KC_BACKSLASH,
        KC_BTN3, KC_LSFT , KC_A   , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J   , KC_K   , KC_L  ,KC_SCLN, KC_LSFT  , DRGSCRL,
        KC_BTN1, KC_LCTL , KC_Z   , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M   , KC_COMM, KC_DOT,KC_SLSH, KC_LCTL  , KC_BTN1,
                                    KC_LBRC,KC_RBRC,                                                         KC_PLUS, KC_EQL,
                                                    RAISE , KC_SPC ,                          LOWER,
                                                    KC_TAB, KC_HOME,                          KC_ENTER,
                                                    KC_BSPC, KC_GRV,                 KC_LGUI, KC_LALT
        ),

    [_LOWER] = LAYOUT_6x7(
        KC_ESC , KC_F1  , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6  ,                       KC_F7 , KC_F8  , KC_F9 ,KC_F10 ,KC_F11 ,KC_F12 , _______,
        _______, KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL , _______,
        _______, _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,_______,KC_PLUS, _______,
        _______, _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                        KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,KC_PIPE, _______,
        _______, _______,_______,_______,_______,_______,_______,                        _______, KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS, _______,
                                 _______,KC_PSCR,                                                        _______, KC_P0,
                                                    _______,_______,                           _______,
                                                    _______,_______,                           _______,
                                                    _______,_______,                  QK_BOOT, _______
        ),

    [_RAISE] = LAYOUT_6x7(
        _______,KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 , _______,
        _______,_______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC,_______,KC_NLCK,KC_INS ,KC_SLCK,KC_MUTE, _______,
        _______,_______,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                        KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU, _______,
        _______,_______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,KC_VOLD, _______,
        _______,_______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______, _______,
                                _______,_______,                                                        KC_EQL ,_______,
                                                   _______,_______,                          _______,
                                                   _______,_______,                          _______,
                                                   _______, QK_BOOT,                  _______,_______
        )
};

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (mouse_report.v != 0 || mouse_report.h != 0) {
        print("keymap.c/pointing_device_task_user(): got mouse report with updated v or h\n");
//        mouse_report.h = mouse_report.x;
//        mouse_report.v = mouse_report.y;
//        mouse_report.x = 0;
//        mouse_report.y = 0;
    }
    if (mouse_report.v != 0 || mouse_report.h != 0) {
        print("keymap.c/pointing_device_task_user(): got mouse report with updated v or h\n");
        //        mouse_report.h = mouse_report.x;
        //        mouse_report.v = mouse_report.y;
        //        mouse_report.x = 0;
        //        mouse_report.y = 0;
    }
    return mouse_report;
}

//static void pointing_device_task_charybdis(report_mouse_t* mouse_report) {
//    static int16_t scroll_buffer_x = 0;
//    static int16_t scroll_buffer_y = 0;
//    if (g_charybdis_config.is_dragscroll_enabled) {
//
//        scroll_buffer_x += mouse_report->x;
//
//
////        scroll_buffer_y -= mouse_report->y;
//
//        scroll_buffer_y += mouse_report->y;
//
//        if (scroll_buffer_x != 0 || scroll_buffer_y != 0) {
//            printf("keymap.c:pointing_device_task_charybdis() scroll_buffer_x: %d, scroll_buffer_y: %d\n", scroll_buffer_x, scroll_buffer_y);
//        }
//        mouse_report->x = 0;
//        mouse_report->y = 0;
//        if (abs(scroll_buffer_x) > 2) {
//            mouse_report->h = scroll_buffer_x > 0 ? 1 : -1;
//            scroll_buffer_x = 0;
//            printf("h changed by %d'n", mouse_report->h);
//        }
//        if (abs(scroll_buffer_y) > 2) {
//            mouse_report->v = scroll_buffer_y > 0 ? 1 : -1;
//            scroll_buffer_y = 0;
//            printf("v changed by %d\n", mouse_report->v);
//        }
//
//    }
//
//}
//
//report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {
//    //    print("pointing_device_task_kb");
//    pointing_device_task_charybdis(&mouse_report);
//    mouse_report = pointing_device_task_user(mouse_report);
//    return mouse_report;
//}

//report_mouse_t pointing_device_set_shared_report(report_mouse_t mouse_report) {
//    print("keymap.c/pointing_device_set_shared_report\n");
////    pointing_device_task_charybdis(&mouse_report);
////    mouse_report = pointing_device_task_user(mouse_report);
////    pointing_device_set_shared_report(mouse_report);
//    return mouse_report;
//}

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
    debug_mouse=true;
}
