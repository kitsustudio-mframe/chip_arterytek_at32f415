/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_1B5701DC_6FE1_4C03_8AF9_89950AADFBD8
#define CHIP_1B5701DC_6FE1_4C03_8AF9_89950AADFBD8

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::tmr::subordinate {
  enum struct InputSelect : uint8_t;
}  // namespace chip::tmr::subordinate

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::tmr::subordinate::InputSelect : uint8_t {
  IS0 = 0x00,   /*!< subordinate mode input select is0 */
  IS1 = 0x01,   /*!< subordinate mode input select is1 */
  IS2 = 0x02,   /*!< subordinate mode input select is2 */
  IS3 = 0x03,   /*!< subordinate mode input select is3 */
  C1INC = 0x04, /*!< subordinate mode input select c1inc */
  C1DF1 = 0x05, /*!< subordinate mode input select c1df1 */
  C2DF2 = 0x06, /*!< subordinate mode input select c2df2 */
  EXTIN = 0x07  /*!< subordinate mode input select extin */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_1B5701DC_6FE1_4C03_8AF9_89950AADFBD8 */
