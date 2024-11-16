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

//*****************************************************************************
// the includes
//*****************************************************************************
#include "drv8300.h"

//*****************************************************************************
// the internal function prototypes
//*****************************************************************************

/**
 * @brief initialize the drv8300 module
 * @param[in] drvHandle   The drv instance
 */
void DRV8300_init(DRV8300_Instance *drvHandle)
{
    HAL_enableADCInterrupt(drvHandle->Vsen);
    HAL_enableADCInterrupt(drvHandle->VsenA);
    HAL_enableADCInterrupt(drvHandle->VsenB);
    HAL_enableADCInterrupt(drvHandle->VsenC);
    HAL_enableADCInterrupt(drvHandle->IsenA);
    HAL_enableADCInterrupt(drvHandle->IsenB);
    HAL_enableADCInterrupt(drvHandle->IsenC);
}

/**
 * @brief updates the current gain scale factor
 * @param[in] drvHandle   The drv instance
 * @param[in] csa  DRV8300 CSA gain value
 */
void DRV8300_updateCSAScaleFactor(
        DRV8300_Instance *drvHandle, uint16_t csa)
{
    drvHandle->csa_sf = _IQ20div(_IQ20(1), _IQ20(csa));
}

/**
 * @brief Get voltage from adc channel
 * @param[in] chan  The ADC channel name
 * @return     Return  
 */
_iq20 DRV8300_getVoltage(HAL_ADC_CHAN chan)
{
    _iq20 voltage = HAL_getIQ20VoltageFromADC(chan);
    return _IQ20mpy(voltage, DRV8300_VOLTAGE_CONV_CONST);
}

/**
 * @brief Get current from adc channel
 * @param[in] chan The ADC channel name
 * @param[in] drvHandle The drv instance
 * @param[in] vRef voltage reference for current
 * @return     Return  
 */
_iq20 DRV8300_getCurrent(
        HAL_ADC_CHAN chan, DRV8300_Instance *drvHandle, _iq20 vRef)
{
    _iq20 voltage = HAL_getIQ20VoltageFromADC(chan);
    vRef = vRef >> 1;
    return _IQ20mpy((vRef-voltage),drvHandle->csa_sf);
}

/**
 * @brief updates the adc voltage reference
 * @param[in] adcRef  ADC voltage reference
 * @param[in] chan    ADC channel name
 * @param[in] internalVRef  Internal reference voltage
 * @param[in] externalVRef  External reference voltage
 */
void DRV8300_ADCVRefSel(HAL_ADC_VREF adcRef, HAL_ADC_CHAN chan,
                        HAL_ADC_INT_VREF internalVRef, uint16_t externalVRef)
{
    switch(adcRef)
    {
    case HAL_ADC_VREF_VDDA:
        HAL_setADCVRefVDDA(chan);
        break;
    case HAL_ADC_VREF_INTERNAL:
        HAL_setADCVRefInternal(chan, internalVRef);
        break;
    case HAL_ADC_VREF_EXTERNAL:
        HAL_setADCVRefExternal(chan, externalVRef);
        break;
    default:
        /* Expected to be empty */
        break;
    }
}
