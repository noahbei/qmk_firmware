// Copyright 2023 Noah Beidelman (@noahbei)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [2] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [3] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    * ┌───┬───┬───┬───┬───┬───┐
    * │ 7 │ 8 │ 9 │ / │Tog│Tog│
    * ├───┼───┼───┼───┼───┴───┘
    * │ 4 │ 5 │ 6 │ * │
    * ├───┼───┼───┼───┤
    * │ 1 │ 2 │ 3 │ - │
    * ├───┼───┼───┼───┤
    * │ 0 │ . │ENT│ + │
    * └───┴───┴───┴───┘
    */
    [0] = LAYOUT(
        KC_7,   KC_8,   KC_9,   KC_PSLS,   KC_BSPC,   TO(1),
        KC_4,   KC_5,   KC_6,   KC_PAST,
        KC_1,   KC_2,   KC_3,   KC_PMNS,
        KC_0,   KC_DOT, KC_ENT, KC_PPLS
    ),

    [1] = LAYOUT(
        KC_7,   KC_8,   KC_9,   KC_PSLS,   KC_BSPC,   TO(2),
        KC_4,   KC_5,   KC_6,   KC_PAST,
        KC_1,   KC_2,   KC_3,   KC_PMNS,
        KC_0,   KC_DOT, KC_ENT, KC_PPLS
    ),

    [2] = LAYOUT(
        KC_7,   KC_8,   KC_9,   KC_PSLS,   KC_BSPC,   TO(3),
        KC_4,   KC_5,   KC_6,   KC_PAST,
        KC_1,   KC_2,   KC_3,   KC_PMNS,
        KC_0,   KC_DOT, KC_ENT, KC_PPLS
    ),

    [3] = LAYOUT(
        KC_7,   KC_8,   KC_9,   KC_PSLS,   KC_BSPC,   TO(0),
        KC_4,   KC_5,   KC_6,   KC_PAST,
        KC_1,   KC_2,   KC_3,   KC_PMNS,
        KC_0,   KC_DOT, KC_ENT, KC_PPLS
    ),
};
