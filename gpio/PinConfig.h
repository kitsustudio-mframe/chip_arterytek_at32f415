/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_79C67E64_6C39_487F_8D8E_F301F919801A
#define CHIP_79C67E64_6C39_487F_8D8E_F301F919801A

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------
#include "chip_arterytek_at32f415/gpio/DriveMode.h"
#include "chip_arterytek_at32f415/gpio/Mode.h"
#include "chip_arterytek_at32f415/gpio/OutputMode.h"
#include "chip_arterytek_at32f415/gpio/Pins.h"
#include "chip_arterytek_at32f415/gpio/PullMode.h"

/* ****************************************************************************
 * Namespace
 */
namespace chip::gpio {
  struct PinConfig;
}  // namespace chip::gpio

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
struct chip::gpio::PinConfig {
  uint32_t pins;          ///< pins number selection
  OutputMode outputMode;  ///< output type selection
  PullMode pullMode;      ///< pull type selection
  Mode mode;              ///< mode selection
  DriveMode driveMode;    ///< drive strength selection
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_79C67E64_6C39_487F_8D8E_F301F919801A */
