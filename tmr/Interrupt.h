/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_5CD8C65D_9F6C_443F_BBDE_F0DEEC68232B
#define CHIP_5CD8C65D_9F6C_443F_BBDE_F0DEEC68232B

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::tmr {
  enum struct Interrupt : uint32_t;
}  // namespace chip::tmr

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::tmr::Interrupt : uint32_t {
  OVF = 0x00000001,     /*!< tmr interrupt overflow */
  C1 = 0x00000002,      /*!< tmr interrupt channel 1 */
  C2 = 0x00000004,      /*!< tmr interrupt channel 2 */
  C3 = 0x00000008,      /*!< tmr interrupt channel 3 */
  C4 = 0x00000010,      /*!< tmr interrupt channel 4 */
  HALL = 0x00000020,    /*!< tmr interrupt hall */
  TRIGGER = 0x00000040, /*!< tmr interrupt trigger */
  BRK = 0x00000080      /*!< tmr interrupt brake */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_5CD8C65D_9F6C_443F_BBDE_F0DEEC68232B */
