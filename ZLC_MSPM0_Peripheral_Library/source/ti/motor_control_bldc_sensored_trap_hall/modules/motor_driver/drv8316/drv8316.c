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
#include "drv8316.h"

//*****************************************************************************
// the internal function prototypes
//*****************************************************************************
uint16_t DRV8316_SPICmd(HAL_SPI_CHAN spiChan, HAL_SPI_CS spiCs,
                 DRV8316_SPI spiMode, DRV8316_ADDR regAddr, uint8_t data);

/**
 * @brief initialize the drv8316 module
 * @param[in] drvHandle   The drv instance
 */
void DRV8316_init(DRV8316_Instance *drvHandle)
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
 * @brief spi command to write or read the data
 * @param[in] spiChan  SPI channel
 * @param[in] spiCs    SPI channel select
 * @param[in] spiMode  SPI read or write
 * @param[in] regAddr   register address
 * @param[in] data      data transmitted
 * @return    uint16_t  data received
 */
uint16_t DRV8316_SPICmd(HAL_SPI_CHAN spiChan, HAL_SPI_CS spiCs,
                 DRV8316_SPI spiMode, DRV8316_ADDR regAddr, uint8_t data)
{
    uint16_t ctrlWord = 0;

    /* build the control word with parity   */
    uint16_t calc = (spiMode | regAddr << DRV8316_ADDR_BIT_POSITION | data);
    uint16_t parity = DRV8316_INITIAL_PARITY;
    while(calc)
    {
       parity ^= (calc & DRV8316_PARITY_CHECK);
       calc >>= DRV8316_RIGHT_SHIFT_REGISTER;
    }
    ctrlWord = (spiMode | regAddr << DRV8316_ADDR_BIT_POSITION |
               (parity << DRV8316_PARITY_BIT_POSITION) |
                data);
    HAL_writeSPI16(spiChan, spiCs, ctrlWord);
    return HAL_readSPI16(spiChan, spiCs);
}

/*
 * @brief write data to spi
 * @param[in] drvHandle  The drv instance
 * @param[in] addr        SPI register address
 * @param[in] data        data transmitted
 */
uint16_t DRV8316_SPIWrite(
        DRV8316_Instance *drvHandle, DRV8316_ADDR addr, uint8_t data)
{
    return DRV8316_SPICmd(
        drvHandle->spiChan, drvHandle->spiCs, DRV8316_SPI_WRITE, addr, data);
}

/*
 * @brief write data to spi
 * @param[in] drvHandle  The drv instance
 * @param[in] addr        SPI register address
 */
uint16_t DRV8316_SPIRead(
        DRV8316_Instance *drvHandle, DRV8316_ADDR addr)
{
    return DRV8316_SPICmd(
         drvHandle->spiChan, drvHandle->spiCs, DRV8316_SPI_READ, addr, 0x00);
}

/**
 * @brief    Enable DRV
 * @param[in] drvHandle   The drv instance
 */
void DRV8316_enable(DRV8316_Instance *drvHandle)
{
    /* Reset the drv by applying a pulse on nSleep pin  */
    DRV8316_setnSleep(drvHandle, DRV8316_DRV_NSLEEP_SLEEP);
    DRV8316_setnSleep(drvHandle, DRV8316_DRV_NSLEEP_AWAKE);

    /* Clear the DRV_OFF pin to turn ON DRV */
    DRV8316_setDrvoff(drvHandle, DRV8316_DRVOFF_PIN_LOW);

    DRV8316_unlockRegs(drvHandle);
    DRV8316_clearfaultBit(drvHandle);
}

/**
 * @brief     update the drv registers
 * @param[in] drvHandle   The drv instance
 * @param[in] regAddr The register to be updated
 * @param[in] value   new value of the bits to be updated
 * @param[in] mask    mask for the bit to be updated
 */
void DRV8316_updateCTRLRegs(DRV8316_Instance *drvHandle, DRV8316_ADDR regAddr,
                            uint16_t value, uint16_t mask)
{
    uint16_t temp = DRV8316_SPIRead(drvHandle, regAddr);
    temp = temp & ~mask;
    temp |= (value & mask);
    DRV8316_SPIWrite(drvHandle, regAddr, temp);
}

/**
 * @brief updates the current gain scale factor
 * @param[in] drvHandle   The drv instance
 * @param[in] csa  DRV8316 CSA gain value
 */
void DRV8316_updateCSAScaleFactor(
        DRV8316_Instance *drvHandle, DRV8316_CSAGAIN csa)
{
    _iq20 temp;
    switch(csa)
    {
    case DRV8316_CSAGAIN_0P15VA:
        temp = DRV8316_CSAGAIN_0P15VA_IQ;
        break;
    case DRV8316_CSAGAIN_0P3VA:
        temp = DRV8316_CSAGAIN_0P3VA_IQ;
        break;
    case DRV8316_CSAGAIN_0P6VA:
        temp = DRV8316_CSAGAIN_0P6VA_IQ;
        break;
    case DRV8316_CSAGAIN_1P2VA:
        temp = DRV8316_CSAGAIN_1P2VA_IQ;
        break;
    default:
        /* Expected to be empty */
        break;
    }
    drvHandle->csa_sf = _IQ20div(_IQ20(1), temp);
}

/**
 * @brief Get voltage from adc channel
 * @param[in] chan  The ADC channel name
 * @return     Return  
 */
_iq20 DRV8316_getVoltage(HAL_ADC_CHAN chan)
{
    _iq20 voltage = HAL_getIQ20VoltageFromADC(chan);
    return _IQ20mpy(voltage, DRV8316_VOLTAGE_CONV_CONST);
}

/**
 * @brief Get current from adc channel
 * @param[in] chan The ADC channel name
 * @param[in] drvHandle The drv instance
 * @param[in] vRef voltage reference for current
 * @return     Return  
 */
_iq20 DRV8316_getCurrent(
        HAL_ADC_CHAN chan, DRV8316_Instance *drvHandle, _iq20 vRef)
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
void DRV8316_ADCVRefSel(HAL_ADC_VREF adcRef, HAL_ADC_CHAN chan,
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




