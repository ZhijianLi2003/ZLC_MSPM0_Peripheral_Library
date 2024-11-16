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
 *  @file       drv8311.h
 *  @brief      drv8311_MODULE Module
 *
 *  @anchor drv8311_h
 *  # Overview
 *  
 *  API's releated to drv8311
 * 
 *  <hr>
 ******************************************************************************/
/** @addtogroup drv8311_MODULE Motor Driver/drv8311
 * @{
 */

#ifndef _drv8311_H_
#define _drv8311_H_

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
/*! @brief Defines the time to clear the nSLEEP pin to reset faults */
#define drv8311_MAXIMUM_RESET_TIME          (40)

/*! @brief Defines the time to wakeup the drv after reset    */
#define drv8311_MAXIMUM_WAKEUP_TIME         (2000)

/*! @brief Defines voltage conversion constant */
#define drv8311_VOLTAGE_CONV_CONST          _IQ20(8.143)

/*! @brief Defines CSA reference voltage */
#define drv8311_CSA_REF_VOLTAGE             (3000)

/*! @brief Defines CSA gains 0.25 in IQ20 */
#define drv8311_CSAGAIN_0P25VA_IQ           _IQ20(0.25)

/*! @brief Defines CSA gains 0.5 in IQ20 */
#define drv8311_CSAGAIN_0P5VA_IQ            _IQ20(0.5)

/*! @brief Defines CSA gains 1.0 in IQ20 */
#define drv8311_CSAGAIN_1P0VA_IQ            _IQ20(1.0)

/*! @brief Defines CSA gains 2.0 in IQ20 */
#define drv8311_CSAGAIN_2P0VA_IQ            _IQ20(2.0)

//*****************************************************************************
// typedefs
//*****************************************************************************


/*! @enum drv8311_CSAGAIN */
typedef enum
{
    /*! @brief Define drv8311 CSA GAIN 0.25 Setting */
    drv8311_CSAGAIN_0P25VA = 0x00 << 0,
    /*! @brief Define drv8311 CSA GAIN 0.5 Setting */
    drv8311_CSAGAIN_0P5VA = 0x01 << 0,
    /*! @brief Define drv8311 CSA GAIN 1.0 Setting */
    drv8311_CSAGAIN_1P0VA = 0x02 << 0,
    /*! @brief Define drv8311 CSA GAIN 2.0 Setting */
    drv8311_CSAGAIN_2P0VA = 0x03 << 0
}drv8311_CSAGAIN;

/*! @enum drv8311_DRVOFF_PIN_STAT */
typedef enum
{
    /*! @brief Define DRVOFF PIN LOW */
    drv8311_DRVOFF_PIN_LOW = HAL_GPIO_PIN_LOW,
    /*! @brief Define DRVOFF PIN HIGH */
    drv8311_DRVOFF_PIN_HIGH = HAL_GPIO_PIN_HIGH
}drv8311_DRVOFF_PIN_STAT;

/*! @enum  drv8311_DRV_NSLEEP_STAT */
typedef enum
{
    /*! @brief Define NSLEEP PIN LOW */
    drv8311_DRV_NSLEEP_SLEEP = HAL_GPIO_PIN_LOW,
    /*! @brief Define NSLEEP PIN HIGH */
    drv8311_DRV_NSLEEP_AWAKE = HAL_GPIO_PIN_HIGH
}drv8311_DRV_NSLEEP_STAT;

/*! @brief Defines drv8311 instance  */
typedef struct
{
    /*!
     * HAL output pin connected to the motor driver's nsleep pin.
     */
    HAL_GPIO_OUT    nsleep;
    /*!
     * HAL output pin connected to the motor driver's drvoff pin.
     */
    HAL_GPIO_OUT    drvoff;
    /*!
     * HAL input pin connected to the motor driver's nfault pin.
     */
    HAL_GPIO_IN     nfault;
    /*!
     * HAL SPI channel connected to the motor driver's spi pins
     */
    HAL_SPI_CHAN    spiChan;
    /*!
     * HAL SPI CS connected to the motor driver's spi cs pin
     */
    HAL_SPI_CS      spiCs;
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

}drv8311_Instance;

//*****************************************************************************
// the function prototypes
//*****************************************************************************
/**
 * @brief set drvoff
 * @param[in] drvHandle   The drv instance
 * @param[in] value        drvoff value
 */
__STATIC_INLINE void drv8311_setDrvoff(
        drv8311_Instance *drvHandle, drv8311_DRVOFF_PIN_STAT value)
{
  if(value == drv8311_DRVOFF_PIN_HIGH)
  {
      HAL_writeGPIOPin(drvHandle->drvoff, HAL_GPIO_PIN_HIGH);
  }
  else if(value == drv8311_DRVOFF_PIN_LOW)
  {
      HAL_writeGPIOPin(drvHandle->drvoff, HAL_GPIO_PIN_LOW);
  }
  else
  {
      /* This is expected to be empty */
  }
}

/**
 * @brief set nSleep
 * @param[in] drvHandle   The drv instance
 * @param[in] value nSleep value
 */
__STATIC_INLINE void drv8311_setnSleep(
        drv8311_Instance *drvHandle, drv8311_DRV_NSLEEP_STAT value)
{
  if(value == drv8311_DRV_NSLEEP_AWAKE)
  {
      HAL_writeGPIOPin(drvHandle->nsleep, HAL_GPIO_PIN_HIGH);
  }
  else if(value == drv8311_DRV_NSLEEP_SLEEP)
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
  HAL_delayMicroSeconds(drv8311_MAXIMUM_WAKEUP_TIME);
}

/**
 * @brief initialize the drv8311 module
 * @param[in] drvHandle   The drv instance
 */
void drv8311_init(drv8311_Instance *drvHandle);

/**
 * @brief     Enable DRV
 * @param[in] drvHandle   The drv instance
 */
void drv8311_enable(drv8311_Instance *drvHandle);

/**
 * @brief updates the current gain scale factor
 * @param[in] drvHandle  The drv instance
 * @param[in] csa         drv8311 CSA gain value
 */
void drv8311_updateCSAScaleFactor(
        drv8311_Instance *drvHandle, drv8311_CSAGAIN csa);

/**
 * @brief Get voltage from adc channel
 * @param[in] chan  The ADC channel name
 * @return     Return  
 */
_iq20 drv8311_getVoltage(HAL_ADC_CHAN chan);

/**
 * @brief Get current from adc channel
 * @param[in] chan The ADC channel name
 * @param[in] drvHandle The drv instance
 * @param[in] vRef voltage reference for current
 * @return     Return  
 */
_iq20 drv8311_getCurrent(HAL_ADC_CHAN chan,
        drv8311_Instance *drvHandle, _iq20 vRef);

/**
 * @brief updates the adc voltage reference
 * @param[in] adcRef  ADC voltage reference
 * @param[in] chan    ADC channel name
 * @param[in] internalVRef  Internal reference voltage
 * @param[in] externalVRef  External reference voltage
 */
void drv8311_ADCVRefSel(HAL_ADC_VREF adcRef, HAL_ADC_CHAN chan,
                        HAL_ADC_INT_VREF internalVRef, uint16_t externalVRef);

/**
 * @brief  get Current reference in IQ20
 * @param[in] vRef  CSA reference voltage in milli volts
 * @return    _iq20 CSA reference voltage in _iq20 format
 */
__STATIC_INLINE _iq20 drv8311_getcsaVref(uint16_t vRef)
{
    _iq13 temp = _IQ13div(_IQ13(vRef),_IQ13(1000));
    return _IQ13toIQ20(temp);
}

#ifdef __cplusplus
}
#endif
#endif /* _drv8311_H_ */
/** @}*/
