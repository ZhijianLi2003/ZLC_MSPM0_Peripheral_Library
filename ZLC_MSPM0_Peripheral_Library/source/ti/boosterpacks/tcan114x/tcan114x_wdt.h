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
 * tcan114x_wdt.h
 *
 *  Created on: Dec 27, 2018
 *      Author: a0225039
 */

#ifndef TESTER_SUITE_CAN_TCAN114X_TCAN114X_WDT_H_
#define TESTER_SUITE_CAN_TCAN114X_TCAN114X_WDT_H_

#include "tcan114x.h"
#include "tcan114x_data_structs.h"

typedef struct {
    uint8_t wd0 : 2;
    uint8_t wd1 : 2;
    uint8_t wd2 : 2;
    uint8_t wd3 : 2;
    uint8_t wd4 : 2;
    uint8_t wd5 : 2;
    uint8_t wd6 : 2;
    uint8_t wd7 : 2;
    uint8_t wd8 : 2;
    uint8_t wd9 : 2;
    uint8_t wd10 : 2;
    uint8_t wd11 : 2;
} wdt_bits;

/*
 * Get and Set Methods
 */
TCAN114X_STATUS_ENUM TCAN114x_WDT_Config_Write(
    TCAN114x_Watchdog_Config *WDTConfig);
TCAN114X_STATUS_ENUM TCAN114x_WDT_Config_Read(
    TCAN114x_Watchdog_Config *WDTConfig);
TCAN114X_STATUS_ENUM TCAN114x_WDT_Config_QA_Write(
    TCAN114x_Watchdog_QA_Config *QAConfig);
TCAN114X_STATUS_ENUM TCAN114x_WDT_Config_QA_Read(
    TCAN114x_Watchdog_QA_Config *QAConfig);
TCAN114X_STATUS_ENUM TCAN114x_WDT_Disable(void);

/*
 * Functions
 */
void TCAN114x_WDT_Reset(void);
void TCAN114x_WDT_QA_Read_Question(uint8_t *question);
void TCAN114x_WDT_QA_Write_Answer(uint8_t *answer);
void TCAN114x_WDT_QA_Calculate_Answer(
    uint8_t *question, uint8_t answer[], uint8_t answerConfig);

/*
 * Private Functions
 */
uint8_t TCAN114X_WDT_QA_Get_Bit(uint8_t data, uint8_t bit);
uint8_t TCAN114X_WDT_QA_Return_XOR(uint8_t data);
void TCAN114X_WDT_QA_Generate_Question_Bit_Array(
    uint8_t config, wdt_bits *bitArray);
#endif /* TESTER_SUITE_CAN_TCAN114X_TCAN114X_WDT_H_ */
