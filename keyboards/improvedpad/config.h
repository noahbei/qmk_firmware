// Copyright 2023 Noah Beidelman (@noahbei)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#pragma once

// SPI pins
// #define SPI_DRIVER SPID1
#define SPI_SCK_PIN A5
#define SPI_MOSI_PIN A7
#define SPI_MISO_PIN A6 // Unused

// LCD Configuration
#define LCD_RST_PIN A2
#define LCD_CS_PIN A4
#define LCD_DC_PIN A1
#define LCD_SPI_DIVISOR 4
#define LCD_WAIT_TIME 150
#define LCD_WIDTH 128
#define LCD_HEIGHT 128
#define LCD_ROTATION QP_ROTATION_0
#define LCD_OFFSET_X 1
#define LCD_OFFSET_Y 26

// Painter Configuration
#define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS true

// Encoder Configuration
#define ENCODERS_PAD_A { B14, B5 }
#define ENCODERS_PAD_B { B13, B4 }
#define ENCODER_RESOLUTION 4
#define ENCODER_MAP_KEY_DELAY 10
#define ENCODER_DEFAULT_POS 0x3
#define ENCODER_DIRECTION_FLIP
