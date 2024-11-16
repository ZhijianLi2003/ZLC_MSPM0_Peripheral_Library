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
#include "drv8411a.h"

/**
 * @brief Array for storing the step frequency multiplication 
 *        factor for each step mode
 */
uint8_t DRV8411A_freqMulFactor[DRV8411A_STEP_MAX] = { 4, 8};

void DRV8411A_enableDrive(DRV8411A_Instance *handle)
{
    handle->driveState = DRV8411A_DRIVE_ENABLED;
    INDEXER_Instance* indexer = &handle->indexer;
    indexer->IaDrive = STEPPER_DRIVE_FORWARD;
    indexer->IbDrive = STEPPER_DRIVE_FORWARD;
    DRV8411A_setPWMDrive(handle->ain1, handle->ain2,
                         indexer->IaDrive, handle->decayMode);
    DRV8411A_setPWMDrive(handle->bin1, handle->bin2,
                         indexer->IbDrive, handle->decayMode);
}

void DRV8411A_disableDrive(DRV8411A_Instance *handle)
{
    INDEXER_Instance* indexer = &handle->indexer; 
    indexer->IaDrive = STEPPER_DRIVE_DISABLE;
    indexer->IbDrive = STEPPER_DRIVE_DISABLE;
    DRV8411A_setPWMDrives(handle);
    handle->driveState = DRV8411A_DRIVE_DISABLED; 
}

void DRV8411A_startMotor(DRV8411A_Instance *handle)
{
    if(handle->controlMode == DRV8411A_CONTROL_MODE_STEP 
                              && handle->setStep == 0)
    {
        return;
    }
    HAL_startTIMCounter(handle->indexerTimer);
}

void DRV8411A_stopMotor(DRV8411A_Instance *handle)
{
    HAL_stopTIMCounter(handle->indexerTimer);
}

bool DRV8411A_isMotorRunning(DRV8411A_Instance *handle)
{
    return HAL_isTIMCounterRunning(handle->indexerTimer);
}

bool DRV8411A_isFaultOccurred(DRV8411A_Instance *handle)
{
    bool ret = false;
    if(HAL_readGPIOVal(handle->nfault) == HAL_GPIO_VALUE_LOW)
    {
        ret = true;
    }
    return ret;
}

void DRV8411A_setDirection(DRV8411A_Instance *handle, DRV8411A_DIR dir)
{
    if(dir == DRV8411A_DIR_FORWARD)
    {
        STEPPER_setIndexerDir(&handle->indexer, STEPPER_DIR_FORWARD);
    }
    else if(dir == DRV8411A_DIR_REVERSE)
    {
        STEPPER_setIndexerDir(&handle->indexer, STEPPER_DIR_REVERSE);
    }
    else
    {
        /* This is expected to be empty*/
    }
}

void DRV8411A_setStepMode(

    DRV8411A_Instance *handle, DRV8411A_STEP stepMode)
{
    if(stepMode == DRV8411A_STEP_FULL_STEP)
    {
        handle->stepMode = stepMode;
        STEPPER_setIndexerIncVal(&handle->indexer, STEPPER_STEP_INC_DEC_FULL_STEP);
        DRV8411A_setSpeed(handle, handle->setFreq);
    }
    if(stepMode == DRV8411A_STEP_HALF_STEP_NC)
    {
        handle->stepMode = stepMode;
        STEPPER_setIndexerIncVal(&handle->indexer, STEPPER_STEP_INC_DEC_HALF_STEP);
        DRV8411A_setSpeed(handle, handle->setFreq);
        STEPPER_setStepType(&handle->indexer, STEPPER_STEP_TYPE_NONCIR);
    }
    else
    {
        STEPPER_setStepType(&handle->indexer, STEPPER_STEP_TYPE_CIR);
    }
}

void DRV8411A_setSpeed(DRV8411A_Instance *handle, uint32_t timFreq)
{
    uint32_t timFreqCal = (timFreq * DRV8411A_freqMulFactor[handle->stepMode]);
    if(timFreqCal > DRV8411A_MAX_SET_FREQ)
    {
        /*
        * Timer frequency entered is above the Firmware limit.
        * If frequency is set higher it can affect the application code
        * execution rate and cause the gui to not function, thus loosing
        * control of motor.
        */
        __BKPT();
        timFreqCal = DRV8411A_MAX_SET_FREQ;
    }
    handle->setFreq = timFreq;
    HAL_setTIMFreq(handle->indexerTimer, timFreqCal);
}
