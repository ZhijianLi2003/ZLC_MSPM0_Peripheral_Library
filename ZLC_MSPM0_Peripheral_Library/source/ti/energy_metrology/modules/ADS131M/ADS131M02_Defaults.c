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

#include "ADS131M02_Defaults.h"

uint16_t ADS131M02_initRegData[NUM_REGISTERS + 1] = {ADS_OPCODE_WREG | 0x0041,
                                0x0000,
                                0x0000,
                                ADS131M02_MODE_ADDRESS_DATA,
                                ADS131M02_CLOCK_ADDRESS_DATA,
                                ADS131M02_GAIN1_ADDRESS_DATA,
                                0x0000,
                                ADS131M02_CFG_ADDRESS_DATA,
                                ADS131M02_THRSHLD_MSB_ADDRESS_DATA,
                                ADS131M02_THRSHLD_LSB_ADDRESS_DATA,
                                ADS131M02_CH0_CFG_ADDRESS_DATA,
                                ADS131M02_CH0_OCAL_MSB_ADDRESS_DATA,
                                ADS131M02_CH0_OCAL_LSB_ADDRESS_DATA,
                                ADS131M02_CH0_GCAL_MSB_ADDRESS_DATA,
                                ADS131M02_CH0_GCAL_LSB_ADDRESS_DATA,
                                ADS131M02_CH1_CFG_ADDRESS_DATA,
                                ADS131M02_CH1_OCAL_MSB_ADDRESS_DATA,
                                ADS131M02_CH1_OCAL_LSB_ADDRESS_DATA,
                                ADS131M02_CH1_GCAL_MSB_ADDRESS_DATA,
                                ADS131M02_CH1_GCAL_LSB_ADDRESS_DATA,
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
};
