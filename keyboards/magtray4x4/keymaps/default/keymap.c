// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

//make custom cycle keycode and function in process_user_record
int current_layer = 0;
int current_display_mode = 0;

enum layers {
    NUM_P,
    ARROW,
    NUM2,
    NUM3
};

enum custom_keycodes {
    KC_00 = SAFE_RANGE,
    LAYER_INC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┐
     * │TOG│
     * ├───┼───┬───┬───┐
     * │ 7 │ 8 │ 9 │ + │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ % │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ = │
     * ├───┼───┼───┼───┤
     * │ 0 │00 │ . │Ent│
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT_ortho_5x4(
        LT(0, KC_NO),
        KC_7,   KC_8,   KC_9,   KC_PPLS,
        KC_4,   KC_5,   KC_6,   KC_PERC,
        KC_1,   KC_2,   KC_3,   KC_EQL,
        KC_0,   KC_00,  KC_DOT, KC_PENT
    ),

    /*
     * ┌───┐
     * │TOG│
     * ├───┼───┬───┬───┐
     * │Hom│ ↑ │PgU│ 3 │
     * ├───┼───┼───┼───┤
     * │ ← │   │ → │ 2 │
     * ├───┼───┼───┤───┤
     * │End│ ↓ │PgD│ 1 │
     * ├───┼───┼───┤───┤
     * │Ins│Spc│Del│Ent│
     * └───┴───┴───┘───┘
     */
    [1] = LAYOUT_ortho_5x4(
        LT(0, KC_NO),
        KC_HOME, KC_UP,   KC_PGUP, KC_3,
        KC_LEFT, XXXXXXX, KC_RGHT, KC_2,
        KC_END,  KC_DOWN, KC_PGDN, KC_1,
        KC_INS,  KC_SPC,  KC_DEL,  KC_PENT
    ),

    /*
     * ┌───┐
     * │TOG│
     * ├───┼───┬───┬───┐
     * │ 7 │ 8 │ 9 │ + │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ % │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ = │
     * ├───┼───┼───┼───┤
     * │ 0 │00 │ . │Ent│
     * └───┴───┴───┴───┘
     */
    [2] = LAYOUT_ortho_5x4(
        LT(0, KC_NO),
        KC_6,   KC_8,   KC_9,   KC_PPLS,
        KC_4,   KC_5,   KC_6,   KC_PERC,
        KC_1,   KC_2,   KC_3,   KC_EQL,
        KC_0,   KC_00,  KC_DOT, KC_PENT
    ),

    /*
     * ┌───┐
     * │TOG│
     * ├───┼───┬───┬───┐
     * │ 7 │ 8 │ 9 │ + │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ % │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ = │
     * ├───┼───┼───┼───┤
     * │ 0 │00 │ . │Ent│
     * └───┴───┴───┴───┘
     */
    [3] = LAYOUT_ortho_5x4(
        LT(0, KC_NO),
        KC_5,   KC_8,   KC_9,   KC_PPLS,
        KC_4,   KC_5,   KC_6,   KC_PERC,
        KC_1,   KC_2,   KC_3,   KC_EQL,
        KC_0,   KC_00,  KC_DOT, KC_PENT
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_00:
                tap_code(KC_0);
                tap_code(KC_0);
                return false;
        case LT(0, KC_NO):
            // on tap
            if (record->tap.count && record->event.pressed) {
                layer_move(++current_layer % 4);
            }
#ifdef OLED_ENABLE
            // on hold
            else if (record->event.pressed) {
                switch(++current_display_mode % 3) {
                    case 0: // clock
                        // call the default function for oled here. the one that is initialized
                        tap_code(KC_0);
                        break;
                    case 1: // layers
                        tap_code(KC_1);
                        break;
                    case 2: // monkey
                        tap_code(KC_2);
                        break;
                }
            }
#endif
            return false;
    }
    
    return true;
}

// when the layer is changed, flash the layer number on the screen
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case 0:
            // flash layer 1 on the screen. write function for this
            break;
        case 1:
            // if display != 2 flash layer on screen,
            // else cycle picture (maybe function?)
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        default: // for any other layers, or the default layer
            
            break;
    }
  return state;
}

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

bool oled_task_user() {
    static const char big1 [] PROGMEM = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xf8, 0xf8, 
        0xf8, 0xf8, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x78, 0x78, 
        0x38, 0x38, 0xf8, 0xf8, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x70, 0x78, 0x38, 0x38, 
        0xf8, 0xf8, 0xf0, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0x70, 0xf8, 0xf8, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x3c, 
        0x3e, 0x3f, 0x3f, 0x3b, 0x39, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x78, 0x7b, 0x73, 0x73, 
        0x7f, 0x7f, 0x3e, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x0f, 0x0f, 0x0d, 0x0c, 0x3f, 0x3f, 
        0x0c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
        0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    
    oled_write_raw_P(big1, sizeof(big1));

    return false;
}
#endif