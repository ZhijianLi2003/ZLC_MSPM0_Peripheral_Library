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

#include "ADS131M08_Defaults.h"

uint16_t ADS01_initRegData[NUM_REGISTERS + 1] = {ADS_OPCODE_WREG | 0x0041,
                                0x0000,
                                0x0000,
                                ADS01_MODE_ADDRESS_DATA,
                                ADS01_CLOCK_ADDRESS_DATA,
                                ADS01_GAIN1_ADDRESS_DATA,
                                ADS01_GAIN2_ADDRESS_DATA,
                                ADS01_CFG_ADDRESS_DATA,
                                ADS01_THRSHLD_MSB_ADDRESS_DATA,
                                ADS01_THRSHLD_LSB_ADDRESS_DATA,
                                ADS01_CH0_CFG_ADDRESS_DATA,
                                ADS01_CH0_OCAL_MSB_ADDRESS_DATA,
                                ADS01_CH0_OCAL_LSB_ADDRESS_DATA,
                                ADS01_CH0_GCAL_MSB_ADDRESS_DATA,
                                ADS01_CH0_GCAL_LSB_ADDRESS_DATA,
                                ADS01_CH1_CFG_ADDRESS_DATA,
                                ADS01_CH1_OCAL_MSB_ADDRESS_DATA,
                                ADS01_CH1_OCAL_LSB_ADDRESS_DATA,
                                ADS01_CH1_GCAL_MSB_ADDRESS_DATA,
                                ADS01_CH1_GCAL_LSB_ADDRESS_DATA,
                                ADS01_CH2_CFG_ADDRESS_DATA,
                                ADS01_CH2_OCAL_MSB_ADDRESS_DATA,
                                ADS01_CH2_OCAL_LSB_ADDRESS_DATA,
                                ADS01_CH2_GCAL_MSB_ADDRESS_DATA,
                                ADS01_CH2_GCAL_LSB_ADDRESS_DATA,
                                ADS01_CH3_CFG_ADDRESS_DATA,
                                ADS01_CH3_OCAL_MSB_ADDRESS_DATA,
                                ADS01_CH3_OCAL_LSB_ADDRESS_DATA,
                                ADS01_CH3_GCAL_MSB_ADDRESS_DATA,
                                ADS01_CH3_GCAL_LSB_ADDRESS_DATA,
                                ADS01_CH4_CFG_ADDRESS_DATA,
                                ADS01_CH4_OCAL_MSB_ADDRESS_DATA,
                                ADS01_CH4_OCAL_LSB_ADDRESS_DATA,
                                ADS01_CH4_GCAL_MSB_ADDRESS_DATA,
                                ADS01_CH4_GCAL_LSB_ADDRESS_DATA,
                                ADS01_CH5_CFG_ADDRESS_DATA,
                                ADS01_CH5_OCAL_MSB_ADDRESS_DATA,
                                ADS01_CH5_OCAL_LSB_ADDRESS_DATA,
                                ADS01_CH5_GCAL_MSB_ADDRESS_DATA,
                                ADS01_CH5_GCAL_LSB_ADDRESS_DATA,
                                ADS01_CH6_CFG_ADDRESS_DATA,
                                ADS01_CH6_OCAL_MSB_ADDRESS_DATA,
                                ADS01_CH6_OCAL_LSB_ADDRESS_DATA,
                                ADS01_CH6_GCAL_MSB_ADDRESS_DATA,
                                ADS01_CH6_GCAL_LSB_ADDRESS_DATA,
                                ADS01_CH7_CFG_ADDRESS_DATA,
                                ADS01_CH7_OCAL_MSB_ADDRESS_DATA,
                                ADS01_CH7_OCAL_LSB_ADDRESS_DATA,
                                ADS01_CH7_GCAL_MSB_ADDRESS_DATA,
                                ADS01_CH7_GCAL_LSB_ADDRESS_DATA,
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
};
