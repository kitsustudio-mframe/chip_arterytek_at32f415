/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_87B737EA_46B8_4F82_B389_5E0FF7C0F4D7
#define CHIP_87B737EA_46B8_4F82_B389_5E0FF7C0F4D7

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
  enum struct DividerClockOut : uint8_t;
}  // namespace chip::crm

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::crm::DividerClockOut : uint8_t {
  DIV1 = 0x00,   /*!< clkout div1 */
  DIV2 = 0x08,   /*!< clkout div2 */
  DIV4 = 0x09,   /*!< clkout div4 */
  DIV8 = 0x0A,   /*!< clkout div8 */
  DIV16 = 0x0B,  /*!< clkout div16 */
  DIV64 = 0x0C,  /*!< clkout div64 */
  DIV128 = 0x0D, /*!< clkout div128 */
  DIV256 = 0x0E, /*!< clkout div256 */
  DIV512 = 0x0F  /*!< clkout div512 */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_87B737EA_46B8_4F82_B389_5E0FF7C0F4D7 */
