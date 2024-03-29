/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_52845632_52CC_45F4_ABCB_4346F1F5CAB0
#define CHIP_52845632_52CC_45F4_ABCB_4346F1F5CAB0

/* ****************************************************************************
 * Include
 */

#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::dma {
  enum struct Channel : uint8_t;
}

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::dma::Channel : uint8_t {
  CHANNEL1 = 0x01,  ///< dma flexible channel1
  CHANNEL2 = 0x02,  ///< dma flexible channel2
  CHANNEL3 = 0x03,  ///< dma flexible channel3
  CHANNEL4 = 0x04,  ///< dma flexible channel4
  CHANNEL5 = 0x05,  ///< dma flexible channel5
  CHANNEL6 = 0x06,  ///< dma flexible channel6
  CHANNEL7 = 0x07   ///< dma flexible channel7
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_52845632_52CC_45F4_ABCB_4346F1F5CAB0 */
