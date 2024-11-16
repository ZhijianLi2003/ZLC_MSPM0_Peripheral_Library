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
 *  @file       drv8300.h
 *  @brief      DRV8300_MODULE Module
 *
 *  @anchor drv8300_h
 *  # Overview
 *  
 *  API's releated to DRV8300
 * 
 *  <hr>
 ******************************************************************************/
/** @addtogroup DRV8300_MODULE Motor Driver/DRV8300
 * @{
 */

#ifndef _DRV8300_H_
#define _DRV8300_H_

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

/*! @brief Defines voltage conversion constant */
#define DRV8300_VOLTAGE_CONV_CONST          _IQ20(33.425)

/*! @brief Defines CSA reference voltage */
#define DRV8300_CSA_REF_VOLTAGE             (3300)

//*****************************************************************************
// typedefs
//*****************************************************************************

/*! @brief Defines DRV8300 instance  */
typedef struct
{
    /*!
     * HAL output pin connected to the motor driver's LED pin
     */
    HAL_GPIO_OUT     led;
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

}DRV8300_Instance;

//*****************************************************************************
// the function prototypes
//*****************************************************************************
/**
 * @brief initialize the drv8300 module
 * @param[in] drvHandle   The drv instance
 */
void DRV8300_init(DRV8300_Instance *drvHandle);

/**
 * @brief     Enable DRV
 * @param[in] drvHandle   The drv instance
 */
void DRV8300_enable(DRV8300_Instance *drvHandle);

/**
 * @brief updates the current gain scale factor
 * @param[in] drvHandle  The drv instance
 * @param[in] csa         DRV8300 CSA gain value
 */
void DRV8300_updateCSAScaleFactor(
        DRV8300_Instance *drvHandle, uint16_t csa);

/**
 * @brief Get voltage from adc channel
 * @param[in] chan  The ADC channel name
 * @return     Return  
 */
_iq20 DRV8300_getVoltage(HAL_ADC_CHAN chan);

/**
 * @brief Get current from adc channel
 * @param[in] chan The ADC channel name
 * @param[in] drvHandle The drv instance
 * @param[in] vRef voltage reference for current
 * @return     Return  
 */
_iq20 DRV8300_getCurrent(HAL_ADC_CHAN chan,
        DRV8300_Instance *drvHandle, _iq20 vRef);

/**
 * @brief updates the adc voltage reference
 * @param[in] adcRef  ADC voltage reference
 * @param[in] chan    ADC channel name
 * @param[in] internalVRef  Internal reference voltage
 * @param[in] externalVRef  External reference voltage
 */
void DRV8300_ADCVRefSel(HAL_ADC_VREF adcRef, HAL_ADC_CHAN chan,
                        HAL_ADC_INT_VREF internalVRef, uint16_t externalVRef);

/**
 * @brief  get Current reference in IQ20
 * @param[in] vRef  CSA reference voltage in milli volts
 * @return    _iq20 CSA reference voltage in _iq20 format
 */
__STATIC_INLINE _iq20 DRV8300_getcsaVref(uint16_t vRef)
{
    _iq13 temp = _IQ13div(_IQ13(vRef),_IQ13(1000));
    return _IQ13toIQ20(temp);
}

#ifdef __cplusplus
}
#endif
#endif /* _DRV8300_H_ */
/** @}*/
