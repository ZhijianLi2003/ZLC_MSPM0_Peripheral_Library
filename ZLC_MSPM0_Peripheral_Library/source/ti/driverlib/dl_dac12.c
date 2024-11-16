/*
 * Copyright (c) 2020, Texas Instruments Incorporated
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

#include <ti/driverlib/dl_dac12.h>

#ifdef __MSPM0_HAS_DAC12__

void DL_DAC12_init(DAC12_Regs *dac12, DL_DAC12_Config *config)
{
    /* CTL 0 - Input Data Formatting */
    DL_DAC12_configDataFormat(
        dac12, config->representation, config->resolution);

    /* CTL 1 - DAC Module */
    DL_Common_updateReg(&dac12->CTL1,
        (uint32_t) config->outputEnable |
            (uint32_t) config->voltageReferenceSource |
            (uint32_t) config->amplifierSetting,
        DAC12_CTL1_OPS_MASK | DAC12_CTL1_REFSP_MASK | DAC12_CTL1_REFSN_MASK |
            DAC12_CTL1_AMPEN_MASK | DAC12_CTL1_AMPHIZ_MASK);

    /* CTL 2 - FIFO */
    DL_Common_updateReg(&dac12->CTL2,
        ((uint32_t) config->fifoEnable | (uint32_t) config->fifoTriggerSource |
            (uint32_t) config->dmaTriggerEnable |
            (uint32_t) config->dmaTriggerThreshold),
        DAC12_CTL2_DMATRIGEN_MASK | DAC12_CTL2_FIFOTH_MASK |
            DAC12_CTL2_FIFOEN_MASK | DAC12_CTL2_FIFOTRIGSEL_MASK);

    /* CTL3 Register - Sample Time Generator */
    DL_Common_updateReg(&dac12->CTL3,
        ((uint32_t) config->sampleTimeGeneratorEnable |
            (uint32_t) config->sampleRate),
        DAC12_CTL3_STIMCONFIG_MASK | DAC12_CTL3_STIMEN_MASK);
}

void DL_DAC12_outputBlocking8(DAC12_Regs *dac12, uint8_t data)
{
    while (DL_DAC12_isFIFOFull(dac12)) {
        ;
    }

    DL_DAC12_output8(dac12, data);
}

void DL_DAC12_outputBlocking12(DAC12_Regs *dac12, uint16_t data)
{
    while (DL_DAC12_isFIFOFull(dac12)) {
        ;
    }

    DL_DAC12_output12(dac12, data);
}

uint32_t DL_DAC12_fillFIFO8(DAC12_Regs *dac12, uint8_t *buffer, uint32_t count)
{
    uint32_t i;
    for (i = 0; i < count; i++) {
        if (!DL_DAC12_isFIFOFull(dac12)) {
            DL_DAC12_output8(dac12, buffer[i]);
        } else {
            break;
        }
    }

    return i;
}

uint32_t DL_DAC12_fillFIFO12(
    DAC12_Regs *dac12, uint16_t *buffer, uint32_t count)
{
    uint32_t i;
    for (i = 0; i < count; i++) {
        if (!DL_DAC12_isFIFOFull(dac12)) {
            DL_DAC12_output12(dac12, buffer[i]);
        } else {
            break;
        }
    }

    return i;
}

void DL_DAC12_performSelfCalibrationBlocking(DAC12_Regs *dac12)
{
    DL_DAC12_startCalibration(dac12);
    /*
     * Tri-stated during calibration, and CALON will continue to be set
     * Prevents the function from exiting until the calibration is finished.
     */
    while (DL_DAC12_isCalibrationRunning(dac12)) {
        ;
    }
}

#endif /* __MSPM0_HAS_DAC12__ */
