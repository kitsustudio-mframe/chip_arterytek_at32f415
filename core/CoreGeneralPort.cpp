/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */
#include "./CoreGeneralPort.h"

//-----------------------------------------------------------------------------------------
#include "chip.h"
#include "mframe.h"

/* ****************************************************************************************
 * Namespace
 */

/* ****************************************************************************************
 * Using
 */
using namespace chip::core;

using chip::crm::CRM;
using chip::crm::PeriphClock;
using chip::crm::PeriphReset;

/* ****************************************************************************************
 * Macro
 */
#define GET_CTRL_DIR(source, shift) ((source & (0x00000003 << (shift << 2))) ? 1 : 0)
#define GET_BIT(source, bit) ((source & (1 << (bit))) ? 1 : 0)

/* ****************************************************************************************
 * Variable
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 *
 */
CoreGeneralPort::CoreGeneralPort(gpio::Register& reg) : mReg(reg) {
  return;
}

/**
 *
 */
CoreGeneralPort::~CoreGeneralPort(void) {
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */
chip::crm::PeriphClock CoreGeneralPort::getPeriphClock(gpio::Register& reg) {
  switch (reinterpret_cast<uint32_t>(&reg)) {
    case AT32F415::BASE_GPIOA:
      return PeriphClock::GPIOA;

    case AT32F415::BASE_GPIOB:
      return PeriphClock::GPIOB;

    case AT32F415::BASE_GPIOC:
      return PeriphClock::GPIOC;

    case AT32F415::BASE_GPIOD:
      return PeriphClock::GPIOD;

    case AT32F415::BASE_GPIOF:
      return PeriphClock::GPIOF;

    default:
      return PeriphClock::NONE;
  }
}
/* ****************************************************************************************
 * Public Method <Override> mframe::hal::Base
 */

/**
 * uninitialze hardware.
 */
bool CoreGeneralPort::deinit(void) {
  if (!this->isInit())
    return false;

  chip::crm::CRM::periphClockEnable(getPeriphClock(this->mReg), false);
  return true;
}

/**
 * initialze hardware;
 */
bool CoreGeneralPort::init(void) {
  if (this->isInit())
    return false;

  chip::crm::CRM::periphClockEnable(getPeriphClock(this->mReg), true);
  return false;
}

/**
 * get hardware initialzed status.
 *
 * @return false = not init, true = initd
 */
bool CoreGeneralPort::isInit(void) {
  return chip::crm::CRM::getPeriphClockEnable(getPeriphClock(this->mReg));
}

/* ****************************************************************************************
 * Public Method <Override> mframe::hal::GeneralPort
 */

/**
 * dir
 */
uint32_t CoreGeneralPort::dir(uint32_t port) {
  if (port)
    return 0x00000000;

  uint32_t result = 0x00000000;

  for (int i = 0; i < 8; ++i) {
    uint32_t mask = static_cast<uint32_t>(0x00000003 << (i << 2));

    if (this->mReg.cfglr & ~mask)
      result |= (1 << i);

    if (this->mReg.cfghr & ~mask)
      result |= (1 << (8 + i));
  }

  return result;
}

/**
 * dir
 */
void CoreGeneralPort::dir(uint32_t port, uint32_t value) {
  if (port)
    return;

  value &= 0x0000FFFF;

  uint32_t regMaskCONF;

  for (uint32_t i = 0; i < 8; ++i) {
    regMaskCONF = static_cast<uint32_t>(0x00000003 << (i << 2));

    if (this->mReg.cfglr & regMaskCONF) {  // hardware is output
      if (!GET_BIT(value, i))              // value flag is low?
        this->mReg.cfglr &= ~regMaskCONF;  // set input

    } else {                              // hardware is input
      if (GET_BIT(value, i))              // value flag is high?
        this->mReg.cfglr |= regMaskCONF;  // set output 50M
    }

    if (this->mReg.cfghr & regMaskCONF) {  // hardware is output
      if (!GET_BIT(value, 8 + i))          // value flag is low?
        this->mReg.cfghr &= ~regMaskCONF;  // set input

    } else {                              // hardware is input
      if (GET_BIT(value, 8 + i))          // value flag is high?
        this->mReg.cfghr |= regMaskCONF;  // set output 50M
    }
  }

  return;
}

/**
 *
 */
void CoreGeneralPort::dirClear(uint32_t port, uint32_t mask) {
  if (port)
    return;

  this->dir(0, (this->dir(0) & ~mask));

  return;
}

/**
 *
 */
void CoreGeneralPort::dirSet(uint32_t port, uint32_t mask) {
  if (port)
    return;

  this->dir(0, (this->dir(0) | mask));

  return;
}

/**
 *
 * @param port GPIO port.
 */
uint32_t CoreGeneralPort::pin(uint32_t port) {
  if (port)
    return 0x00000000;

  return this->mReg.idt;
}

/**
 *
 * @param port GPIO port.
 * @param value GPIO write value.
 */
void CoreGeneralPort::pin(uint32_t port, uint32_t value) {
  if (port)
    return;

  uint32_t dir = this->dir(0);

  this->mReg.scr = (value & dir);
}

/**
 * setting io output pin to push-pull low at mask.
 *
 * @param port io port.
 * @param mask bit high = active.
 */
void CoreGeneralPort::pinClear(uint32_t port, uint32_t mask) {
  if (port)
    return;

  uint32_t dir = this->dir(0);

  this->mReg.clr = (static_cast<uint32_t>(mask) & dir);
  return;
}

/**
 *
 * @param port GPIO port.
 * @param mask GPIO write value.
 */
void CoreGeneralPort::pinSet(uint32_t port, uint32_t mask) {
  if (port)
    return;

  uint32_t dir = this->dir(0);

  this->mReg.scr = (static_cast<uint32_t>(mask) & dir);
  return;
}

/**
 *
 */
void CoreGeneralPort::pinToggle(uint32_t port, uint32_t mask) {
  if (port)
    return;

  uint32_t dir = this->dir(0);

  this->mReg.odt ^= (static_cast<uint32_t>(mask) & dir);
  return;
}

/* ****************************************************************************************
 * Public Method
 */

/**
 *
 */
bool CoreGeneralPort::configInput(uint32_t pin, InputMode mode) {
  if (pin >= 16)
    return false;

  uint8_t shift = static_cast<uint8_t>((pin & 0x00000007) << 2);
  volatile uint32_t* reg;
  uint32_t ctrl;

  if (pin < 8)  // 0~7pin
    reg = &this->mReg.cfglr;

  else  // 8~15pin
    reg = &this->mReg.cfghr;

  ctrl = ((*reg) & ~static_cast<uint32_t>(0x0000000F << shift));

  switch (mode) {
    case InputMode::OPEN:
      *reg = (ctrl | static_cast<uint32_t>(0x00000004 << shift));
      this->mReg.clr |= (1 << pin);
      return true;

    case InputMode::ANALOG:
      *reg = ctrl;
      this->mReg.clr |= (1 << pin);
      return true;

    case InputMode::PULLDOWN:
      *reg = (ctrl | static_cast<uint32_t>(0x00000008 << shift));
      this->mReg.clr |= (1 << pin);
      return true;

    case InputMode::PULLUP:
      *reg = (ctrl | static_cast<uint32_t>(0x00000008 << shift));
      this->mReg.scr |= (1 << pin);
      return true;
  }

  return false;
}

/**
 *
 */
bool CoreGeneralPort::configOutput(uint32_t pin, OutputMode mode, bool opendrain, bool function, bool value) {
  if (pin >= 16)
    return false;

  uint8_t shift = static_cast<uint8_t>((pin & 0x00000007) << 2);
  volatile uint32_t* reg;
  uint32_t ctrl;

  if (pin < 8)  // 0~7pin
    reg = &this->mReg.cfglr;

  else  // 8~15pin
    reg = &this->mReg.cfghr;

  ctrl = ((*reg) & ~static_cast<uint32_t>(0x0000000F << shift));

  if (opendrain)
    ctrl |= static_cast<uint32_t>(0x00000004 << shift);

  if (function)
    ctrl |= static_cast<uint32_t>(0x00000008 << shift);

  switch (mode) {
    case OutputMode::SPEED_2M:
      *reg = (ctrl | static_cast<uint32_t>(0x00000002 << shift));
      break;

    case OutputMode::SPEED_10M:
      *reg = (ctrl | static_cast<uint32_t>(0x00000001 << shift));
      break;

    case OutputMode::SPEED_50M:
      *reg = (ctrl | static_cast<uint32_t>(0x00000003 << shift));
      break;
  }

  this->mReg.scr |= (1 << pin);

  return false;
}

/**
 * @brief
 *
 * @param pin
 * @param opendrain
 * @return true
 * @return false
 */
bool CoreGeneralPort::setFunction(uint32_t pin, bool opendrain) {
  return this->configOutput(pin, OutputMode::SPEED_50M, opendrain, true, true);
}

/**
 * @brief
 *
 * @param pin
 * @return true
 * @return false
 */
bool CoreGeneralPort::setAnalog(uint32_t pin) {
  return this->configInput(pin, InputMode::ANALOG);
}

/**
 *
 */
chip::gpio::Register& CoreGeneralPort::getRegister(void) {
  return this->mReg;
}

/* ****************************************************************************************
 * Protected Method <Static>
 */

/* ****************************************************************************************
 * Protected Method <Override>
 */

/* ****************************************************************************************
 * Protected Method
 */

/* ****************************************************************************************
 * Private Method
 */

/* ****************************************************************************************
 * End of file
 */
