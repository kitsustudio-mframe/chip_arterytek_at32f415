/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_5DFF479A_1086_4BB6_8E1A_0373216AA033
#define CHIP_5DFF479A_1086_4BB6_8E1A_0373216AA033

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::usart {
  enum struct DataBit : uint8_t;
}  // namespace chip::usart

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::usart::DataBit : uint8_t {
  BITS8 = 0x00, /*!< usart data size is 8 bits */
  BITS9 = 0x01  /*!< usart data size is 9 bits */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_5DFF479A_1086_4BB6_8E1A_0373216AA033 */
