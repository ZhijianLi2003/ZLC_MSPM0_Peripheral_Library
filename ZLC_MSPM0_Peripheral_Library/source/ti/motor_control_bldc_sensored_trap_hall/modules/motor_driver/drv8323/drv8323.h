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
 *  @file       drv8323.h
 *  @brief      DRV8323_MODULE Module
 *
 *  @anchor drv8323_h
 *  # Overview
 *  
 *  API's releated to DRV8323
 * 
 *  <hr>
 ******************************************************************************/
/** @addtogroup DRV8323_MODULE Motor Driver/DRV8323
 * @{
 */

#ifndef _DRV8323_H_
#define _DRV8323_H_

#include "hal.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! @brief Defines the time to wakeup the drv after reset    */
#define DRV8323_MAXIMUM_WAKEUP_TIME                 (2000)
/*! @brief Defines voltage conversion constant */
#define DRV8323_VOLTAGE_CONV_CONST                  _IQ20(17.433)
/*! @brief Defines CSA reference voltage */
#define DRV8323_CSA_REF_VOLTAGE                     (3300)
/*! @brief Defines CSA gains 5 in IQ20*/
#define DRV8323_CSAGAIN_5_IQ                        _IQ20(5)
/*! @brief Defines CSA gains 10 in IQ20*/
#define DRV8323_CSAGAIN_10_IQ                       _IQ20(10)
/*! @brief Defines CSA gains 20 in IQ20*/
#define DRV8323_CSAGAIN_20_IQ                       _IQ20(20)
/*! @brief Defines CSA gains 40 in IQ20*/
#define DRV8323_CSAGAIN_40_IQ                       _IQ20(40)

/*! @enum DRV8323_CSAGAIN   */
typedef enum
{
    /*! @brief Define DRV8323 CSA GAIN 5 Setting */
    DRV8323_CSAGAIN_5 = 0 << 0,
    /*! @brief Define DRV8323 CSA GAIN 10 Setting */
    DRV8323_CSAGAIN_10 = 1 << 0,
    /*! @brief Define DRV8323 CSA GAIN 20 Setting */
    DRV8323_CSAGAIN_20 = 2 << 0,
    /*! @brief Define DRV8323 CSA GAIN 40 Setting */
    DRV8323_CSAGAIN_40 = 3 << 0
}DRV8323_CSAGAIN ;

/*! @enum DRV8323_DRVOFF_PIN_STAT   */
typedef enum
{
  /*! Define DRVOFF PIN LOW */
  DRV8323_DRVOFF_PIN_LOW = HAL_GPIO_PIN_LOW,
  /*! Define DRVOFF PIN HIGH */
  DRV8323_DRVOFF_PIN_HIGH = HAL_GPIO_PIN_HIGH
}DRV8323_DRVOFF_PIN_STAT ;

/*! @enum DRV8323_DRV_NSLEEP_STAT
 *  @brief Represents NSLEEP Pin State
 */
typedef enum
{
  /*! @brief Define NSLEEP PIN LOW */
  DRV8323_DRV_NSLEEP_SLEEP = HAL_GPIO_PIN_LOW,
  /*! @brief Define NSLEEP PIN HIGH */
  DRV8323_DRV_NSLEEP_AWAKE = HAL_GPIO_PIN_HIGH
}DRV8323_DRV_NSLEEP_STAT;

/*! @brief Defines drv8323 instance  */
typedef struct
{
    /*!
     * HAL output pin connected to the motor driver's nsleep pin.
     */
    HAL_GPIO_OUT     nsleep;
    /*!
     * HAL output pin connected to the motor driver's LED pin
     */
    HAL_GPIO_OUT     led;
    /*!
     * HAL input pin connected to the motor driver's nfault pin.
     */
    HAL_GPIO_IN      nfault;
    /*!
     * Scale factor used to cache values needed to calculate current
     */
    _iq20            csa_sf;
    /*!
     * Scale factor used to cache values needed to calculate current
     */
    _iq20            csaVRef;
    /*!
     * ADc channels used to measure bus voltage
     */
    HAL_ADC_CHAN     Vsen;
    /*!
     * ADc channels used to measure phase A voltage
     */
    HAL_ADC_CHAN     VsenA;
    /*!
     * ADc channels used to measure phase B voltage
     */
    HAL_ADC_CHAN     VsenB;
    /*!
     * ADc channels used to measure phase C voltage
     */
    HAL_ADC_CHAN     VsenC;
    /*!
     * ADc channels used to measure bus current
     */
    HAL_ADC_CHAN     IsenA;
    /*!
     * ADc channels used to measure bus current
     */
    HAL_ADC_CHAN     IsenB;
    /*!
     * ADc channels used to measure bus current
     */
    HAL_ADC_CHAN     IsenC;
    /*!
     * pwm timer to which fault pin is connected
     */
    HAL_FAULT_INPUT  faultIn;

}DRV8323_Instance;

/**
 * @brief set nSleep
 * @param[in] drvHandle   The drv instance
 * @param[in] value nSleep value
 */
__STATIC_INLINE void DRV8323_setnSleep(
        DRV8323_Instance *drvHandle, DRV8323_DRV_NSLEEP_STAT value)
{
  if(value == DRV8323_DRV_NSLEEP_AWAKE)
  {
      HAL_writeGPIOPin(drvHandle->nsleep, HAL_GPIO_PIN_HIGH);
  }
  else if(value == DRV8323_DRV_NSLEEP_SLEEP)
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
  HAL_delayMicroSeconds(DRV8323_MAXIMUM_WAKEUP_TIME);
}

/**
 * @brief  get Current reference in IQ20
 * @param[in] vRef  CSA reference voltage in milli volts
 * @return    _iq20 CSA reference voltage in _iq20 format
 */
__STATIC_INLINE _iq20 DRV8323_getcsaVref(uint16_t vRef)
{
    _iq13 temp = _IQ13div(_IQ13(vRef), _IQ13(1000));
    return _IQ13toIQ20(temp);
}

/**
 * @brief initialize the drv8323 module
 * @param[in] drvHandle The drv8323 instance
 */
void DRV8323_init(DRV8323_Instance *drvHandle);

/**
 * @brief     Enable DRV
 * @param[in] drvHandle The drv8323 instance
 */
void DRV8323_enable(DRV8323_Instance *drvHandle);

/**
 * @brief updates the current gain scale factor
 * @param[in] drvHandle  The drv8323 instance
 * @param[in] csa  drv8323 CSA gain value
 * @param[in] rSense shunt resistance
 */
void DRV8323_updateCSAScaleFactor(DRV8323_Instance *drvHandle,
                             DRV8323_CSAGAIN  csa, uint16_t rSense);

/**
 * @brief Get voltage from adc channel
 * @param[in] chan The ADC channel name
 * @return     Return   
 */
_iq20 DRV8323_getVoltage(HAL_ADC_CHAN  chan);

/**
 * @brief Get current from adc channel
 * @param[in] chan The ADC channel name
 * @param[in] drvHandle The drv instance
 * @param[in] vRef voltage reference for current
 * @return     Return   
 */
_iq20 DRV8323_getCurrent(
        HAL_ADC_CHAN  chan, DRV8323_Instance *drvHandle, _iq20 vRef);

/**
 * @brief updates the adc voltage reference
 * @param[in] adcRef ADC voltage reference
 * @param[in] chan The ADC channel name
 * @param[in] internalVRef  Internal reference voltage
 * @param[in] externalVRef  External reference voltage
 
 */
void DRV8323_ADCVRefSel(HAL_ADC_VREF adcRef, HAL_ADC_CHAN chan,
                        HAL_ADC_INT_VREF internalVRef, uint16_t externalVRef);

#ifdef __cplusplus
}
#endif
#endif /* _DRV8323_H_ */
/** @}*/

