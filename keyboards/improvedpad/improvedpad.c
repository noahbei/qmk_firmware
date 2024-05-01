// Copyright 2023 Noah Beidelman (@noahbei)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "improvedpad.h"
#include "qp.h"
#include "gfx/one.qgf.h"
#include "gfx/two.qgf.h"
#include "gfx/three.qgf.h"
#include "gfx/four.qgf.h"


void board_init(void) {
  SYSCFG->CFGR1 |= SYSCFG_CFGR1_I2C1_DMA_RMP;
}

#ifdef QUANTUM_PAINTER_ENABLE

painter_device_t lcd;
painter_image_handle_t one, two, three, four;
void keyboard_post_init_kb(void) {
    wait_ms(LCD_WAIT_TIME);
    lcd = qp_st7735_make_spi_device(LCD_HEIGHT, LCD_WIDTH, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, 0);
    qp_init(lcd, LCD_ROTATION);
    qp_set_viewport_offsets(lcd, LCD_OFFSET_X, LCD_OFFSET_Y);
    qp_power(lcd, true);

    qp_rect(lcd, 0, 0, LCD_WIDTH, LCD_HEIGHT, 0, 0, 225, true);
    one = qp_load_image_mem(gfx_one);
    qp_drawimage(lcd, 0, 0, one);
    
    keyboard_post_init_user();
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    qp_rect(lcd, 0, 0, LCD_WIDTH, LCD_HEIGHT, 0, 0, 225, true);
    switch (get_highest_layer(state)) {
    case 0:
        one = qp_load_image_mem(gfx_one);
        qp_drawimage(lcd, 0, 0, one);
        break;
    case 1:
        two = qp_load_image_mem(gfx_two);
        qp_drawimage(lcd, LCD_WIDTH / 2 - 1, 0, two);
        break;
    case 2:
        three = qp_load_image_mem(gfx_three);
        qp_drawimage(lcd, 0, LCD_HEIGHT / 2 - 1, three);
        break;
    case 3:
        four = qp_load_image_mem(gfx_four);
        qp_drawimage(lcd, LCD_WIDTH / 2 - 1, LCD_HEIGHT / 2 - 1, four);
        break;
    default: //  for any other layers, or the default layer
        
        break;
    }
    qp_flush(lcd);
    qp_close_image(one);
    qp_close_image(two);
    qp_close_image(three);
    qp_close_image(four);
  return state;
}
#endif