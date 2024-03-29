/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_3FA58C3A_7193_49FB_A03E_C051BF650961
#define CHIP_3FA58C3A_7193_49FB_A03E_C051BF650961

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::crm {
  enum struct ReferenceClockPLL : uint8_t;
}  // namespace chip::crm

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::crm::ReferenceClockPLL : uint8_t {
  REF_4M = 0,  /*!< pll reference clock between 3.9 mhz and 5 mhz */
  REF_6M = 1,  /*!< pll reference clock between 5.2 mhz and 6.25 mhz */
  REF_8M = 2,  /*!< pll reference clock between 7.8125 mhz and 8.33 mhz */
  REF_12M = 3, /*!< pll reference clock between 8.33 mhz and 12.5 mhz */
  REF_16M = 4, /*!< pll reference clock between 15.625 mhz and 20.83 mhz */
  REF_25M = 5  /*!< pll reference clock between 20.83 mhz and 31.255 mhz */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_3FA58C3A_7193_49FB_A03E_C051BF650961 */
