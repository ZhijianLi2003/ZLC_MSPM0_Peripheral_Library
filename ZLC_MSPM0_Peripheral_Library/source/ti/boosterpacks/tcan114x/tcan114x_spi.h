/*
 * Copyright (c) 2022, Texas Instruments Incorporated
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
/*
 * tcan114x_SPI.h
 * Description: This file is responsible for abstracting the lower-level
 * microcontroller SPI read and write functions
 *
 * Created on: December 4, 2018
 *     Author: Texas Instruments
 * Updated on: October 20, 2022
 *     Author: Texas Instruments
 */
#ifndef TCAN114X_SPI_H_
#define TCAN114X_SPI_H_

/* ********************************** *
 *  Start of device-specific defines
 * ********************************** */
#include "ti_msp_dl_config.h"
/* ******************************** *
 *  End of device-specific defines
 * ******************************** */

//--------------------------------------------------------------------------
//							Write Functions
//------------------------------------------------------------------------

/* TCAN_WRITE
 * Description: Writes a single 8-bit word to the specified register address from an address pointer, returns the  interrupt register
 */
uint8_t TCAN_WRITE(uint8_t address, uint8_t* data);

//--------------------------------------------------------------------------
//							Read Functions
//--------------------------------------------------------------------------
/* TCAN_READ
 * Description: Reads a single 8-bit word from the specified register address. Data is written to data pointer. Function returns interrupt data
 */
uint8_t TCAN_READ(uint8_t address, uint8_t* data);

//-----------------------------------------------------------------------------------------------

#endif
