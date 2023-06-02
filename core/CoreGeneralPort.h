/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef CORE_ECE02CDF_DC7C_4FF3_A0C5_DE8A6C0F1776
#define CORE_ECE02CDF_DC7C_4FF3_A0C5_DE8A6C0F1776

/* ****************************************************************************************
 * Include
 */  
 
//-----------------------------------------------------------------------------------------
#include "lang/package-info.h" 
#include "hal/package-info.h"
#include "./../gpio/package-info.h"
//-----------------------------------------------------------------------------------------
#include "./InputMode.h"
#include "./OutputMode.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace at32f415::core{
  class CoreGeneralPort;
  class Core;
}

/* ****************************************************************************************
 * Class Object
 */  
class at32f415::core::CoreGeneralPort :public lang::Object , 
  public hal::GeneralPort{

  friend Core;
        
  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
  private: 
    gpio::Register& mReg;

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
  private: 
    /**
     *
     */
    CoreGeneralPort(gpio::Register& reg);

    /**
     *
     */
    virtual ~CoreGeneralPort(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */
  public:
    static crm::PeriphClock getPeriphClock(gpio::Register& reg);

  /* **************************************************************************************
   * Public Method <Override> hal::Base
   */
  public:
    
    /**
     * @brief uninitialze hardware.
     * 
     * @return true 
     * @return false 
     */
    virtual bool deinit(void) override;

    /**
     * @brief initialze hardware.
     * 
     * @return true 
     * @return false 
     */
    virtual bool init(void) override;

    /**
     * @brief get hardware initialzed status.
     * 
     * @return true initd
     * @return false not init
     */
    virtual bool isInit(void) override;

  /* **************************************************************************************
   * Public Method <Override>
   */
  public:
  
    /**
     * @brief 
     * 
     * @param port 
     * @return uint32_t 
     */
    virtual uint32_t dir(uint32_t port) override;

    /**
     * @brief 
     * 
     * @param port 
     * @param value 
     */
    virtual void dir(uint32_t port, uint32_t value) override;
    
    /**
     * @brief 
     * 
     * @param port 
     * @param mask 
     */
    virtual void dirClear(uint32_t port, uint32_t mask) override;
    
    /**
     * @brief 
     * 
     * @param port 
     * @param mask 
     */
    virtual void dirSet(uint32_t port, uint32_t mask) override;

    /**
     * @brief 
     * 
     * @param port 
     * @return uint32_t 
     */
    virtual uint32_t pin(uint32_t port) override;

    /**
     * @brief 
     * 
     * @param port 
     * @param value 
     */
    virtual void pin(uint32_t port, uint32_t value) override;
    
    /**
     * @brief 
     * 
     * @param port 
     * @param mask 
     */
    virtual void pinClear(uint32_t port, uint32_t mask) override;

    /**
     * @brief 
     * 
     * @param port 
     * @param mask 
     */
    virtual void pinSet(uint32_t port, uint32_t mask) override;
    
    /**
     * @brief 
     * 
     * @param port 
     * @param mask 
     */
    virtual void pinToggle(uint32_t port, uint32_t mask) override;

  /* **************************************************************************************
   * Public Method <Inline>
   */

  /* **************************************************************************************
   * Public Method
   */
  public:
    
    /**
     * @brief 
     * 
     * @param pin 
     * @param mode 
     * @return true 
     * @return false 
     */
    bool configInput(uint32_t pin, core::InputMode mode);
    
    /**
     * @brief 
     * 
     * @param pin 
     * @param mode 
     * @param opendrain 
     * @param function 
     * @param value 
     * @return true 
     * @return false 
     */
    bool configOutput(uint32_t pin, core::OutputMode mode, 
                      bool opendrain, 
                      bool function, 
                      bool value);

    /**
     * @brief Set the Function object
     * 
     * @param pin 
     * @param enable 
     * @return true 
     * @return false 
     */
    bool setFunction(uint32_t pin, bool opendrain);

    /**
     * @brief Set the Analog object
     * 
     * @param pin 
     * @return true 
     * @return false 
     */
    bool setAnalog(uint32_t pin);

    /**
     * @brief 
     * 
     * @return at32f415::gpio::Register& 
     */
    at32f415::gpio::Register& getRegister(void);

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /* **************************************************************************************
   * Private Method <Static>
   */

  /* **************************************************************************************
   * Private Method <Override>
   */
   
  /* **************************************************************************************
   * Private Method
   */  

};



/* *****************************************************************************************
 * End of file
 */ 


#endif/* CORE_ECE02CDF_DC7C_4FF3_A0C5_DE8A6C0F1776 */