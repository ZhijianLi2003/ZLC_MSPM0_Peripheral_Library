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
#include "drv8889-q1.h"

/*!
 * @brief KV value(Transimpedance gain) for DRV8889Q1 is 2.2,
this is 72089 in IQ15 format
 */
#define DRV8889Q1_KV_VA_IQ                            (72089)

void DRV8889Q1_init(DRV8889Q1_Instance *handle)
{
    HAL_enablePWMInterrupt(handle->step);

    /* Unlock the SPI registers */
    DRV8889Q1_setSPIRegisterLock(handle, DRV8889Q1_REG_CTRL4_LOCK_UNLOCK);
}

uint16_t DRV8889Q1_createSPIDataWord(
                DRV8889Q1_SPI_CMD wrCmd, DRV8889Q1_REG_ADDR addr, uint8_t data)
{
    uint16_t dataWord = 0;
    /* Bit 14 W0: write = 0 and read = 1 */
    dataWord = ((wrCmd) << DRV8889Q1_SPI_CMD_OFS);

    /* Bit 13-9: address */
    dataWord |= ((addr << DRV8889Q1_SPI_ADDR_OFS) & DRV8889Q1_SPI_ADDR_MASK);

    /* Bit 7-0: data */
    dataWord |= data;
    return  dataWord;
}

void DRV8889Q1_spiWrite(
            DRV8889Q1_Instance *handle, DRV8889Q1_REG_ADDR addr, uint8_t data)
{
    uint16_t dataWord = DRV8889Q1_createSPIDataWord(
                                        DRV8889Q1_SPI_CMD_WRITE, addr, data);
    HAL_transmitSPIData16(handle->spi, handle->spiCS, dataWord);
    while (HAL_isSPIBusy(handle->spi))
    {
        /* This is expected to be empty*/
    };
}

uint8_t DRV8889Q1_spiRead(DRV8889Q1_Instance *handle, DRV8889Q1_REG_ADDR addr)
{
    HAL_SPI_clearRXFifo(handle->spi, handle->spiCS);
    uint16_t dataWord = DRV8889Q1_createSPIDataWord(
                                            DRV8889Q1_SPI_CMD_READ, addr, 0x00);
    HAL_transmitSPIData16(handle->spi, handle->spiCS, dataWord);
    while (HAL_isSPIBusy(handle->spi))
    {
        /* This is expected to be empty*/
    };
    return (uint8_t)(0xFF & HAL_receiveSPIData16(handle->spi, handle->spiCS));
}

void DRV8889Q1_spiUpdateRegister(DRV8889Q1_Instance *handle, 
                        DRV8889Q1_REG_ADDR addr, uint32_t mask, uint8_t data)
{
    uint8_t dataValue;
    dataValue = (uint8_t) DRV8889Q1_spiRead(handle, addr);
    dataValue &= ~(mask);
    dataValue |= data;
    DRV8889Q1_spiWrite(handle, addr, dataValue);
}

void DRV8889Q1_setSPIRegisterLock(
                    DRV8889Q1_Instance *handle, DRV8889Q1_REG_CTRL4_LOCK lock)
{
    DRV8889Q1_spiUpdateRegister(handle,DRV8889Q1_REG_ADDR_CTRL4,
                                        DRV8889Q1_REG_CTRL4_LOCK_MASK, 
                                        (lock << DRV8889Q1_REG_CTRL4_LOCK_OFS));
}

void DRV8889Q1_setDirection(DRV8889Q1_Instance *handle, DRV8889Q1_DIR dir)
{
    if(dir == DRV8889Q1_DIR_FORWARD)
    {
        HAL_setGPIOVal(handle->dir, HAL_GPIO_VALUE_LOW);
    }
    else if(dir == DRV8889Q1_DIR_REVERSE)
    {
        HAL_setGPIOVal(handle->dir, HAL_GPIO_VALUE_HIGH);
    }
    else
    {
        /* This is expected to be empty*/
    }
}

void DRV8889Q1_setStepMode(
                    DRV8889Q1_Instance *handle, DRV8889Q1_STEP stepMode)
{
    DRV8889Q1_spiUpdateRegister(handle,DRV8889Q1_REG_ADDR_CTRL3,
                        DRV8889Q1_REG_CTRL3_MICROSTEP_MODE_MASK,
                        (stepMode << DRV8889Q1_REG_CTRL3_MICROSTEP_MODE_OFS));
}

void DRV8889Q1_setDecayMode(
            DRV8889Q1_Instance *handle, DRV8889Q1_DECAY decayMode)
{
    DRV8889Q1_spiUpdateRegister(handle,DRV8889Q1_REG_ADDR_CTRL2,
                                DRV8889Q1_REG_CTRL2_DECAY_MASK, 
                                (decayMode << DRV8889Q1_REG_CTRL2_DECAY_OFS));
}

void DRV8889Q1_setSpeed(DRV8889Q1_Instance *handle, uint32_t timFreq)
{
    if(timFreq > DRV8889Q1_MAX_SET_FREQ)
    {
        /*
        * Timer frequency entered is above the Firmware limit.
        * If frequency is set higher it can affect the application code
        * execution rate and cause the gui to not function, thus loosing
        * control of motor.
        */
        __BKPT();
        timFreq = DRV8889Q1_MAX_SET_FREQ;
    }
    handle->setFreq = timFreq;
    HAL_setPWMFreq(handle->step, timFreq);
    DRV8889Q1_setStepDuty(handle);
}

void DRV8889Q1_setFSCurr(DRV8889Q1_Instance *handle, _iq15 fsCurr)
{
    _iq15 volt = _IQ15mpy(fsCurr, DRV8889Q1_KV_VA_IQ);
    HAL_setDACVoltage(handle->vref, volt);
}

void DRV8889Q1_setSlewRate(
                    DRV8889Q1_Instance *handle, DRV8889Q1_SLEW_RATE slewRate)
{
    DRV8889Q1_spiUpdateRegister(handle,DRV8889Q1_REG_ADDR_CTRL1,
                            DRV8889Q1_REG_CTRL1_SLEW_RATE_MASK,
                            (slewRate << DRV8889Q1_REG_CTRL1_SLEW_RATE_OFS));
}

void DRV8889Q1_setNSleep(DRV8889Q1_Instance *handle)
{
    HAL_setGPIOVal(handle->nsleep, HAL_GPIO_VALUE_HIGH);
    /* Startup delay for the DRV8889Q1 SPI to be ready */
    HAL_delayMilliSeconds(DRV8889Q1_SPI_READY_DELAY_MS);
}

void DRV8889Q1_clearNSleep(DRV8889Q1_Instance *handle)
{
    HAL_setGPIOVal(handle->nsleep, HAL_GPIO_VALUE_LOW);
}

void DRV8889Q1_enableOutput(DRV8889Q1_Instance *handle)
{
    HAL_setGPIOVal(handle->drvOff, HAL_GPIO_VALUE_LOW);
    DRV8889Q1_spiUpdateRegister(handle, DRV8889Q1_REG_ADDR_CTRL2, 
                                        DRV8889Q1_REG_CTRL2_DIS_OUT_MASK, 
                                        (0 << DRV8889Q1_REG_CTRL2_DIS_OUT_OFS));
}

void DRV8889Q1_disableOutput(DRV8889Q1_Instance *handle)
{
    HAL_setGPIOVal(handle->drvOff, HAL_GPIO_VALUE_HIGH);
    DRV8889Q1_spiUpdateRegister(handle, DRV8889Q1_REG_ADDR_CTRL2, 
                                        DRV8889Q1_REG_CTRL2_DIS_OUT_MASK, 
                                        (1 << DRV8889Q1_REG_CTRL2_DIS_OUT_OFS));
}

void DRV8889Q1_startMotor(DRV8889Q1_Instance *handle)
{
    handle->driveState = DRV8889Q1_DRIVE_PWM;
    DRV8889Q1_setStepDrive(handle, handle->driveState);
    HAL_startPWMCounter(handle->step);
}

void DRV8889Q1_stopMotor(DRV8889Q1_Instance *handle)
{
    HAL_stopPWMCounter(handle->step);
    handle->driveState = DRV8889Q1_DRIVE_DISABLED;
    DRV8889Q1_setStepDrive(handle, handle->driveState);
}

bool DRV8889Q1_isMotorRunning(DRV8889Q1_Instance *handle)
{
    return HAL_isPWMCounterRunning(handle->step);
}

bool DRV8889Q1_isFaultOccurred(DRV8889Q1_Instance *handle)
{
    bool ret = false;
    if(HAL_readGPIOVal(handle->nfault) == HAL_GPIO_VALUE_LOW)
    {
        ret = true;
    }
    return ret;
}

void DRV8889Q1_setControlMode(DRV8889Q1_Instance *handle,
                                         DRV8889Q1_CONTROL_MODE ctrl_mode)
{
    handle->controlMode = ctrl_mode;
}

void DRV8889Q1_checkStep(DRV8889Q1_Instance *handle)
{
    if(handle->controlMode == DRV8889Q1_CONTROL_MODE_STEP)
    {
        handle->stepCount+=1;
        if(handle->stepCount >= handle->setStep)
        {
            handle->stepCount = 0;
            DRV8889Q1_stopMotor(handle);
        }
    }
}

void DRV8889Q1_setStepDuty(DRV8889Q1_Instance *handle)
{
    HA_setPWMDutyCycle(handle->step, DRV8889Q1_STEP_DUTYCYCLE);
}

void DRV8889Q1_setStepDrive(
                        DRV8889Q1_Instance *handle, DRV8889Q1_DRIVE drive)
{
    if (drive == DRV8889Q1_DRIVE_DISABLED)
    {
        HAL_configurePWMPin(handle->step, HAL_PWM_CHANNEL_MODE_FORCED_LOW);
    }
    else if (drive == DRV8889Q1_DRIVE_PWM)
    {
        HAL_configurePWMPin(handle->step, HAL_PWM_CHANNEL_MODE_PWM);
    }
}

void DRV8889Q1_setStep(DRV8889Q1_Instance *handle, uint16_t setSteps)
{
    handle->setStep = setSteps;
}

void DRV8889Q1_setTrqDac(DRV8889Q1_Instance *handle, DRV8889Q1_TRQ_DAC trqDac)
{
    DRV8889Q1_spiUpdateRegister(handle, DRV8889Q1_REG_ADDR_CTRL1, 
                                 DRV8889Q1_REG_CTRL1_TRQ_DAC_MASK, 
                                 (trqDac << DRV8889Q1_REG_CTRL1_TRQ_DAC_OFS));
}

void DRV8889Q1_setToff(DRV8889Q1_Instance *handle, DRV8889Q1_TOFF toff)
{
    DRV8889Q1_spiUpdateRegister(handle, DRV8889Q1_REG_ADDR_CTRL2, 
                                        DRV8889Q1_REG_CTRL2_TOFF_MASK, 
                                        (toff << DRV8889Q1_REG_CTRL2_TOFF_OFS));
}

void DRV8889Q1_clearFaults(DRV8889Q1_Instance *handle)
{
    DRV8889Q1_spiUpdateRegister(handle, DRV8889Q1_REG_ADDR_CTRL4, 
                                        DRV8889Q1_REG_CTRL4_CLR_FLT_MASK, 
                                        (1 << DRV8889Q1_REG_CTRL4_CLR_FLT_OFS));
}

uint8_t DRV8889Q1_getStallThres(DRV8889Q1_Instance *handle)
{
    uint8_t dataSpi = DRV8889Q1_spiRead(handle, DRV8889Q1_REG_ADDR_CTRL6);
    return dataSpi;
}

void DRV8889Q1_setStallThres(DRV8889Q1_Instance *handle, uint8_t stallThres)
{
    DRV8889Q1_spiUpdateRegister(handle, DRV8889Q1_REG_ADDR_CTRL6, 
                            DRV8889Q1_REG_CTRL6_STALL_TH_MASK, 
                            (stallThres << DRV8889Q1_REG_CTRL6_STALL_TH_OFS));
}

uint8_t DRV8889Q1_getTrqCount(DRV8889Q1_Instance *handle)
{
    uint8_t dataSpi = DRV8889Q1_spiRead(handle, DRV8889Q1_REG_ADDR_CTRL7);
    return dataSpi;
}

void DRV8889Q1_enableStallDet(DRV8889Q1_Instance *handle)
{
    DRV8889Q1_spiUpdateRegister(handle, DRV8889Q1_REG_ADDR_CTRL5, 
                                 DRV8889Q1_REG_CTRL5_EN_STL_MASK, 
                                 (1 << DRV8889Q1_REG_CTRL5_EN_STL_OFS));
}

void DRV8889Q1_disableStallDet(DRV8889Q1_Instance *handle)
{
    DRV8889Q1_spiUpdateRegister(handle, DRV8889Q1_REG_ADDR_CTRL5, 
                                        DRV8889Q1_REG_CTRL5_EN_STL_MASK, 
                                        (0 << DRV8889Q1_REG_CTRL5_EN_STL_OFS));
}

void DRV8889Q1_enableOlDet(DRV8889Q1_Instance *handle)
{
    DRV8889Q1_spiUpdateRegister(handle, DRV8889Q1_REG_ADDR_CTRL4, 
                                        DRV8889Q1_REG_CTRL4_EN_OL_MASK, 
                                        (1 << DRV8889Q1_REG_CTRL4_EN_OL_OFS));
}

void DRV8889Q1_disableOlDet(DRV8889Q1_Instance *handle)
{
    DRV8889Q1_spiUpdateRegister(handle, DRV8889Q1_REG_ADDR_CTRL4, 
                                        DRV8889Q1_REG_CTRL4_EN_OL_MASK, 
                                        (0 << DRV8889Q1_REG_CTRL4_EN_OL_OFS));
}

void DRV8889Q1_setLearnStall(DRV8889Q1_Instance *handle)
{
    DRV8889Q1_spiUpdateRegister(handle, DRV8889Q1_REG_ADDR_CTRL5, 
                                        DRV8889Q1_REG_CTRL5_STL_LRN_MASK, 
                                        (1 << DRV8889Q1_REG_CTRL5_STL_LRN_OFS));
}

bool DRV8889Q1_isStallLearnSuccess(DRV8889Q1_Instance *handle)
{
    bool ret = false;
    uint8_t dataSpi = 
                    DRV8889Q1_spiRead(handle, DRV8889Q1_REG_ADDR_DIAG_STATUS_2);
    if(dataSpi & DRV8889Q1_REG_DIAG_STATUS_2_STL_LRN_OK_MASK)
    {
        ret = true;
    }
    return ret;
}

void DRV8889Q1_setVrefRefVoltage(DRV8889Q1_Instance *handle, _iq15 refVoltage)
{
    HAL_setDacRefVoltage(handle->vref, refVoltage);
}
