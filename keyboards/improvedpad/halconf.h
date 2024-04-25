// Copyright 2023 Noah Beidelman (@noahbei)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#undef HAL_USE_SPI
#define HAL_USE_SPI TRUE

#include_next <halconf.h>