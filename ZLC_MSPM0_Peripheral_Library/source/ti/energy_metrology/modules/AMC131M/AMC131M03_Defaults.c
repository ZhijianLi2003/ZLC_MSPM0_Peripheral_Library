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

#include "AMC131M03_Defaults.h"

uint16_t AMC131M03_initRegData[NUM_REGISTERS + 1] = {AMC_OPCODE_WREG | 0x0041,
                                0x0000,
                                0x0000,
                                AMC131M03_MODE_ADDRESS_DATA,
                                AMC131M03_CLOCK_ADDRESS_DATA,
                                AMC131M03_GAIN1_ADDRESS_DATA,
                                0x0000,
                                AMC131M03_CFG_ADDRESS_DATA,
                                0x0000,
                                0x0000,
                                AMC131M03_CH0_CFG_ADDRESS_DATA,
                                AMC131M03_CH0_OCAL_MSB_ADDRESS_DATA,
                                AMC131M03_CH0_OCAL_LSB_ADDRESS_DATA,
                                AMC131M03_CH0_GCAL_MSB_ADDRESS_DATA,
                                AMC131M03_CH0_GCAL_LSB_ADDRESS_DATA,
                                AMC131M03_CH1_CFG_ADDRESS_DATA,
                                AMC131M03_CH1_OCAL_MSB_ADDRESS_DATA,
                                AMC131M03_CH1_OCAL_LSB_ADDRESS_DATA,
                                AMC131M03_CH1_GCAL_MSB_ADDRESS_DATA,
                                AMC131M03_CH1_GCAL_LSB_ADDRESS_DATA,
                                AMC131M03_CH2_CFG_ADDRESS_DATA,
                                AMC131M03_CH2_OCAL_MSB_ADDRESS_DATA,
                                AMC131M03_CH2_OCAL_LSB_ADDRESS_DATA,
                                AMC131M03_CH2_GCAL_MSB_ADDRESS_DATA,
                                AMC131M03_CH2_GCAL_LSB_ADDRESS_DATA,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                AMC131M03_DCD_CTRL_REGISTER,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
                                0x0000,
};

/* single registers write, added temporarily for debug   */

void AMC_initializeRegisters(AMC_Instance *amcHandle)
{
    AMC_writeSingleSPIReg(amcHandle, CLOCK_ADDRESS, AMC131M03_CLOCK_ADDRESS_DATA, 1);
    AMC_writeSingleSPIReg(amcHandle, REGMAP_DCDC_ADDRESS, AMC131M03_DCD_CTRL_REGISTER, 1);// needs to be initialized first
    AMC_writeSingleSPIReg(amcHandle, MODE_ADDRESS, AMC131M03_MODE_ADDRESS_DATA, 1);
    AMC_writeSingleSPIReg(amcHandle, GAIN1_ADDRESS, AMC131M03_GAIN1_ADDRESS_DATA, 1);
    AMC_writeSingleSPIReg(amcHandle, CFG_ADDRESS, AMC131M03_CFG_ADDRESS_DATA, 1);
    AMC_writeSingleSPIReg(amcHandle, THRSHLD_MSB_ADDRESS, AMC131M03_THRSHLD_MSB_ADDRESS_DATA, 1);
    AMC_writeSingleSPIReg(amcHandle, THRSHLD_LSB_ADDRESS, AMC131M03_THRSHLD_LSB_ADDRESS_DATA, 1);
    AMC_writeSingleSPIReg(amcHandle, CH0_CFG_ADDRESS, AMC131M03_CH0_CFG_ADDRESS_DATA, 1);
    AMC_writeSingleSPIReg(amcHandle, CH0_OCAL_MSB_ADDRESS, AMC131M03_CH0_OCAL_MSB_ADDRESS_DATA, 1);
    AMC_writeSingleSPIReg(amcHandle, CH0_OCAL_LSB_ADDRESS, AMC131M03_CH0_OCAL_LSB_ADDRESS_DATA, 1);
    AMC_writeSingleSPIReg(amcHandle, CH0_GCAL_MSB_ADDRESS, AMC131M03_CH0_GCAL_MSB_ADDRESS_DATA, 1);
    AMC_writeSingleSPIReg(amcHandle, CH0_GCAL_LSB_ADDRESS, AMC131M03_CH0_GCAL_LSB_ADDRESS_DATA, 1);
    AMC_writeSingleSPIReg(amcHandle, CH1_CFG_ADDRESS, AMC131M03_CH1_CFG_ADDRESS_DATA, 1);
    AMC_writeSingleSPIReg(amcHandle, CH1_OCAL_MSB_ADDRESS, AMC131M03_CH1_OCAL_MSB_ADDRESS_DATA, 1);
    AMC_writeSingleSPIReg(amcHandle, CH1_OCAL_LSB_ADDRESS, AMC131M03_CH1_OCAL_LSB_ADDRESS_DATA, 1);
    AMC_writeSingleSPIReg(amcHandle, CH1_GCAL_MSB_ADDRESS, AMC131M03_CH1_GCAL_MSB_ADDRESS_DATA, 1);
    AMC_writeSingleSPIReg(amcHandle, CH1_GCAL_LSB_ADDRESS, AMC131M03_CH1_GCAL_LSB_ADDRESS_DATA, 1);
    AMC_writeSingleSPIReg(amcHandle, CH2_CFG_ADDRESS, AMC131M03_CH2_CFG_ADDRESS_DATA, 1);
    AMC_writeSingleSPIReg(amcHandle, CH2_OCAL_MSB_ADDRESS, AMC131M03_CH2_OCAL_MSB_ADDRESS_DATA, 1);
    AMC_writeSingleSPIReg(amcHandle, CH2_OCAL_LSB_ADDRESS, AMC131M03_CH2_OCAL_LSB_ADDRESS_DATA, 1);
    AMC_writeSingleSPIReg(amcHandle, CH2_GCAL_MSB_ADDRESS, AMC131M03_CH2_GCAL_MSB_ADDRESS_DATA, 1);
    AMC_writeSingleSPIReg(amcHandle, CH2_GCAL_LSB_ADDRESS, AMC131M03_CH2_GCAL_LSB_ADDRESS_DATA, 1);
}


































