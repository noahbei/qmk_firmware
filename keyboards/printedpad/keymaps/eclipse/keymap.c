// Copyright 2023 Noah Beidelman (@noahbei)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    numpad = 0,
    gamepad,
    media,
    funct
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┐
     * │Tog│ 
     * ├───┼───┬───┐ 
     * │ 1 │ 2 │ 3 │
     * ├───┼───┼───┤
     * │ 4 │ 5 │ 6 │
     * ├───┼───┼───┤
     * │ 7 │ 8 │ 9 │
     * └───┴───┴───┘
     */
    [numpad] = LAYOUT(
        LT(0, KC_NO),
        KC_7,   KC_8,   KC_9,
        KC_4,   KC_5,   KC_6,
        KC_1,   KC_2,   KC_3
    ),

    [gamepad] = LAYOUT(
        LT(0, KC_NO),
        KC_Y,    KC_X,    KC_A,
        KC_ENT,  KC_UP,   KC_B,
        KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [media] = LAYOUT(
        LT(0, KC_NO),
        KC_NO,   KC_NO,   KC_NO,
        KC_MUTE, KC_VOLU, KC_MPLY,
        KC_MPRV, KC_VOLD, KC_MNXT
    ),

    [funct] = LAYOUT(
        LT(0, KC_NO),
        KC_F1,  KC_F2,  KC_F3,
        KC_F4,  KC_F5,  KC_F6,
        KC_F7,  KC_F8,  KC_F9
    )
};