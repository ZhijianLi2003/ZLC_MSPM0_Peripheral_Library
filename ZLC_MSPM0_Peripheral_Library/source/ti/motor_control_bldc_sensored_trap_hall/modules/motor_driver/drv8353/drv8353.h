/*
 * Copyright (c) 2023, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*!****************************************************************************
 *  @file       drv8353.h
 *  @brief      DRV8353_MODULE Module
 *
 *  @anchor drv8353_h
 *  # Overview
 *  
 *  API's releated to DRV8353
 * 
 *  <hr>
 ******************************************************************************/
/** @addtogroup DRV8353_MODULE Motor Driver/DRV8353
 * @{
 */

#ifndef _DRV8353_H_
#define _DRV8353_H_

//*****************************************************************************
// the includes
//*****************************************************************************
#include "hal.h"

#ifdef __cplusplus
extern "C" {
#endif

//*****************************************************************************
//defines
//*****************************************************************************
/*! @brief Defines the address mask  */
#define DRV8353_ADDR_MASK                   (0x7E00)

/*! @brief Defines the data mask     */
#define DRV8353_DATA_MASK                   (0x00FF)

/*! @brief Defines the data transmitted while reading a register */
#define DRV8353_DATA_TRANSMIT_TO_READ       (0x00)

/*! @brief Defines the initial parity of command word */
#define DRV8353_INITIAL_PARITY              (0x00)

/*! @brief Defines the parity checking bit           */
#define DRV8353_PARITY_CHECK                (0x01)

/*! @brief Defines the number of bits right shifted  */
#define DRV8353_RIGHT_SHIFT_REGISTER        (1)

/*! @brief Defines the position of the parity in command word    */
#define DRV8353_PARITY_BIT_POSITION         (8)

/*! @brief Defines the position of the parity in command word    */
#define DRV8353_ADDR_BIT_POSITION           (9)

/*! @brief Defines the position of the parity in command word    */
#define DRV8353_SPICMD_BIT_POSITION         (15)

/*! @brief Defines the claer bit mask */
#define DRV8353_CLEAR_BIT_MASK              (0x01)

/*! @brief Defines the time to clear the nSLEEP pin to reset faults */
#define DRV8353_MAXIMUM_RESET_TIME          (40)

/*! @brief Defines the time to wakeup the drv after reset    */
#define DRV8353_MAXIMUM_WAKEUP_TIME         (2000)

/*! @brief Defines voltage conversion constant */
#define DRV8353_VOLTAGE_CONV_CONST          _IQ20(39.582)

/*! @brief Defines CSA reference voltage */
#define DRV8353_CSA_REF_VOLTAGE             (3300)

//*****************************************************************************
// typedefs
//*****************************************************************************
/*! @enum  DRV8353_DRV_NSLEEP_STAT */
typedef enum
{
    /*! @brief Define NSLEEP PIN LOW */
    DRV8353_DRV_NSLEEP_SLEEP = HAL_GPIO_PIN_LOW,
    /*! @brief Define NSLEEP PIN HIGH */
    DRV8353_DRV_NSLEEP_AWAKE = HAL_GPIO_PIN_HIGH
}DRV8353_DRV_NSLEEP_STAT;

/*! @brief Defines DRV8353 instance  */
typedef struct
{
    /*!
     * HAL output pin connected to the motor driver's nsleep pin.
     */
    HAL_GPIO_OUT    nsleep;
    /*!
     * HAL output pin connected to the motor driver's LED pin
     */
    HAL_GPIO_OUT     led;
    /*!
     * HAL input pin connected to the motor driver's nfault pin.
     */
    HAL_GPIO_IN     nfault;
    /*!
     * Scale factor used to cache values needed to calculate current
     */
    _iq20           csa_sf;
    /*!
     * Scale factor used to cache values needed to calculate current
     */
    _iq20           csaVRef;
    /*!
     * ADc channels used to measure bus voltage
     */
    HAL_ADC_CHAN    Vsen;
    /*!
     * ADc channels used to measure phase A voltage
     */
    HAL_ADC_CHAN    VsenA;
    /*!
     * ADc channels used to measure phase B voltage
     */
    HAL_ADC_CHAN    VsenB;
    /*!
     * ADc channels used to measure phase C voltage
     */
    HAL_ADC_CHAN    VsenC;
    /*!
     * ADc channels used to measure phase A current
     */
    HAL_ADC_CHAN    IsenA;
    /*!
     * ADc channels used to measure phase B current
     */
    HAL_ADC_CHAN    IsenB;
    /*!
     * ADc channels used to measure phase C current
     */
    HAL_ADC_CHAN    IsenC;
    /*!
     * pwm timer to which fault pin is connected
     */
    HAL_FAULT_INPUT faultIn;

}DRV8353_Instance;

//*****************************************************************************
// the function prototypes
//*****************************************************************************
/**
 * @brief set nSleep
 * @param[in] drvHandle   The drv instance
 * @param[in] value nSleep value
 */
__STATIC_INLINE void DRV8353_setnSleep(
        DRV8353_Instance *drvHandle, DRV8353_DRV_NSLEEP_STAT value)
{
  if(value == DRV8353_DRV_NSLEEP_AWAKE)
  {
      HAL_writeGPIOPin(drvHandle->nsleep, HAL_GPIO_PIN_HIGH);
  }
  else if(value == DRV8353_DRV_NSLEEP_SLEEP)
  {
      HAL_writeGPIOPin(drvHandle->nsleep, HAL_GPIO_PIN_LOW);
  }
  else
  {
      /* This is expected to be empty */
  }
    /* tWake - Turnon time = 1ms
     * tSleep - Turnoff time = 1ms
     * So not matter what you set sleep pin to just wait 1 ms
     */
  HAL_delayMicroSeconds(DRV8353_MAXIMUM_WAKEUP_TIME);
}

/**
 * @brief initialize the drv8353 module
 * @param[in] drvHandle   The drv instance
 */
void DRV8353_init(DRV8353_Instance *drvHandle);

/**
 * @brief     Enable DRV
 * @param[in] drvHandle   The drv instance
 */
void DRV8353_enable(DRV8353_Instance *drvHandle);

/**
 * @brief updates the current gain scale factor
 * @param[in] drvHandle  The drv instance
 * @param[in] csa         DRV8353 CSA gain value
 */
void DRV8353_updateCSAScaleFactor(
        DRV8353_Instance *drvHandle, uint16_t csa);

/**
 * @brief Get voltage from adc channel
 * @param[in] chan  The ADC channel name
 * @return     Return  
 */
_iq20 DRV8353_getVoltage(HAL_ADC_CHAN chan);

/**
 * @brief Get current from adc channel
 * @param[in] chan The ADC channel name
 * @param[in] drvHandle The drv instance
 * @param[in] vRef voltage reference for current
 * @return     Return  
 */
_iq20 DRV8353_getCurrent(HAL_ADC_CHAN chan,
        DRV8353_Instance *drvHandle, _iq20 vRef);

/**
 * @brief updates the adc voltage reference
 * @param[in] adcRef  ADC voltage reference
 * @param[in] chan    ADC channel name
 * @param[in] internalVRef  Internal reference voltage
 * @param[in] externalVRef  External reference voltage
 */
void DRV8353_ADCVRefSel(HAL_ADC_VREF adcRef, HAL_ADC_CHAN chan,
                        HAL_ADC_INT_VREF internalVRef, uint16_t externalVRef);

/**
 * @brief  get Current reference in IQ20
 * @param[in] vRef  CSA reference voltage in milli volts
 * @return    _iq20 CSA reference voltage in _iq20 format
 */
__STATIC_INLINE _iq20 DRV8353_getcsaVref(uint16_t vRef)
{
    _iq13 temp = _IQ13div(_IQ13(vRef),_IQ13(1000));
    return _IQ13toIQ20(temp);
}

#ifdef __cplusplus
}
#endif
#endif /* _DRV8353_H_ */
/** @}*/
