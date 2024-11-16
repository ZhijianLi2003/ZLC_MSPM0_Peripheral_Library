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
 * tcan114x_wdt.c
 *
 *  Created on: Dec 27, 2018
 *      Author: a0225039
 */

#include "tcan114x_wdt.h"

/*
 * @brief Configures the watchdog registers with the settings from the passed struct
 * @param *WDTConfig is a pointer to a @c TCAN114x_Watchdog_Config struct
 * @returns TCAN114X_STATUS_ENUM if the write was successful or not, based on if TCAN114X_CONFIGURE_VERIFY_WRITES is defined in tcan114x.h
 */
TCAN114X_STATUS_ENUM
TCAN114x_WDT_Config_Write(TCAN114x_Watchdog_Config *WDTConfig)
{
    // Step one is to write the words to the registers
    TCAN_WRITE(REG_TCAN114X_WD_CONFIG_1, &WDTConfig->word_config_1);
#ifdef TCAN114X_CONFIGURE_VERIFY_WRITES
    uint8_t readVerify;
    TCAN_READ(REG_TCAN114X_WD_CONFIG_1, &readVerify);
    if (readVerify != WDTConfig->word_config_1) return TCAN114X_FAIL;
#endif

    // Write the second word to the register
    TCAN_WRITE(REG_TCAN114X_WD_CONFIG_2, &WDTConfig->word_config_2);
#ifdef TCAN114X_CONFIGURE_VERIFY_WRITES
    TCAN_READ(REG_TCAN114X_WD_CONFIG_2, &readVerify);
    if ((readVerify & 0xE0) != (WDTConfig->word_config_2 & 0xE0))
        return TCAN114X_FAIL;
#endif

    // Write the third word to the register
    TCAN_WRITE(REG_TCAN114X_WD_RST_PULSE, &WDTConfig->word_wd_rst_pulse);
#ifdef TCAN114X_CONFIGURE_VERIFY_WRITES
    TCAN_READ(REG_TCAN114X_WD_RST_PULSE, &readVerify);
    if (readVerify != WDTConfig->word_wd_rst_pulse) return TCAN114X_FAIL;
#endif

    return TCAN114X_SUCCESS;
}

/*
 * @brief Reads the current configuration of the watchdog and updates the passed struct
 * @param *WDTConfig is a pointer to a @c TCAN114x_Watchdog_Config struct
 * @returns TCAN114X_STATUS_ENUM if the write was successful or not, based on if TCAN114X_CONFIGURE_VERIFY_WRITES is defined in tcan114x.h
 */
TCAN114X_STATUS_ENUM
TCAN114x_WDT_Config_Read(TCAN114x_Watchdog_Config *WDTConfig)
{
    uint8_t readWDT;
    TCAN_READ(REG_TCAN114X_WD_CONFIG_1, &readWDT);
    WDTConfig->word_config_1 = readWDT;

    TCAN_READ(REG_TCAN114X_WD_CONFIG_2, &readWDT);
    WDTConfig->word_config_2 = readWDT;

    TCAN_READ(REG_TCAN114X_WD_RST_PULSE, &readWDT);
    WDTConfig->word_wd_rst_pulse = readWDT;

    return TCAN114X_SUCCESS;
}

/*
 * @brief Configures the QA watchdog register with the settings from the passed struct
 * @param *QAConfig is a pointer to a @c TCAN114x_Watchdog_QA_Config struct
 * @returns TCAN114X_STATUS_ENUM if the write was successful or not, based on if TCAN114X_CONFIGURE_VERIFY_WRITES is defined in tcan114x.h
 */
TCAN114X_STATUS_ENUM
TCAN114x_WDT_Config_QA_Write(TCAN114x_Watchdog_QA_Config *QAConfig)
{
    TCAN_WRITE(REG_TCAN114X_WD_QA_CONFIG, &QAConfig->word_qa_config);
#ifdef TCAN114X_CONFIGURE_VERIFY_WRITES
    uint8_t readVerify;
    TCAN_READ(REG_TCAN114X_WD_QA_CONFIG, &readVerify);
    if (readVerify != QAConfig->word_qa_config) return TCAN114X_FAIL;
#endif
    return TCAN114X_SUCCESS;
}

/*
 * @brief Reads the current configuration of the QA watchdog and updates the passed struct
 * @param *QAConfig is a pointer to a @c TCAN114x_Watchdog_QA_Config struct
 * @returns TCAN114X_STATUS_ENUM if the write was successful or not, based on if TCAN114X_CONFIGURE_VERIFY_WRITES is defined in tcan114x.h
 */
TCAN114X_STATUS_ENUM
TCAN114x_WDT_Config_QA_Read(TCAN114x_Watchdog_QA_Config *QAConfig)
{
    uint8_t readWDT;
    TCAN_READ(REG_TCAN114X_WD_QA_CONFIG, &readWDT);
    QAConfig->word_qa_config = readWDT;
    return TCAN114X_SUCCESS;
}

/*
 * @briefe Disables the watchdog, it must be re-configured to be enabled
 */
TCAN114X_STATUS_ENUM
TCAN114x_WDT_Disable(void)
{
    uint8_t data;
    TCAN_READ(REG_TCAN114X_WD_CONFIG_1, &data);
    data &= ~REG_BITS_TCAN114X_WD_CONFIG_1_WD_CONFIG_MASK;
    TCAN_WRITE(REG_TCAN114X_WD_CONFIG_1, &data);
#ifdef TCAN114X_CONFIGURE_VERIFY_WRITES
    TCAN_READ(REG_TCAN114X_WD_CONFIG_1, &data);
    if (data & REG_BITS_TCAN114X_WD_CONFIG_1_WD_CONFIG_MASK)
        return TCAN114X_FAIL;
#endif
    return TCAN114X_SUCCESS;
}

/*
 * @brief Writes to the WD timer reset register to perform a reset
 */
void TCAN114x_WDT_Reset(void)
{
    // Write 0xFF to the input reset register to reset the watchdog
    uint8_t data = 0xFF;
    TCAN_WRITE(REG_TCAN114X_WD_INPUT_TRIG, &data);
}

/*
 * @brief Reads the current question from the TCAN114x and writes it to the question pointer
 * @param *question is a pointer where the question will be stored
 */
void TCAN114x_WDT_QA_Read_Question(uint8_t *question)
{
    uint8_t read;
    TCAN_READ(REG_TCAN114X_WD_QA_QUESTION, &read);
    *question = read & 0x0F;
}

/*
 * @brief Writes the supplied answer to the TCAN114x
 * @param *answer is a pointer to the answer that will be written to the TCAN114x
 */
void TCAN114x_WDT_QA_Write_Answer(uint8_t *answer)
{
    TCAN_WRITE(REG_TCAN114X_WD_QA_ANSWER, answer);
}

/*
 * @brief Calculates the 4 answers needed based on the supplied question
 * @param *question is a pointer to the question used to calculate the answers
 * @param answer[] is an array of at least 4 bytes used to store the calculated answers
 */
void TCAN114x_WDT_QA_Calculate_Answer(
    uint8_t *question, uint8_t answer[], uint8_t answerConfig)
{
    // We'll need a way to map the configuration mux to the array of bits.
    wdt_bits bitArray = {0};
    TCAN114X_WDT_QA_Generate_Question_Bit_Array(answerConfig, &bitArray);

    // Now we can generate the answer
    uint8_t i;

    // Gets us the current WD_ANS_CNT value (starts at 3, and goes to 0
    for (i = 0; i < 4; i++) {
        uint8_t wd_cnt = 3 - i;

        uint8_t bitanswer = 0;
        uint8_t temp;

        // Bit 0
        temp = TCAN114X_WDT_QA_Get_Bit(wd_cnt, 1) ^
               TCAN114X_WDT_QA_Get_Bit(*question, bitArray.wd1);
        temp ^= TCAN114X_WDT_QA_Get_Bit(*question, bitArray.wd0);
        bitanswer = temp;

        // Bit 1
        temp = TCAN114X_WDT_QA_Get_Bit(*question, 1) ^
               TCAN114X_WDT_QA_Get_Bit(*question, bitArray.wd3);
        temp += TCAN114X_WDT_QA_Get_Bit(wd_cnt, 1);
        temp += TCAN114X_WDT_QA_Get_Bit(*question, bitArray.wd2);
        bitanswer |= (TCAN114X_WDT_QA_Return_XOR(temp) << 1);

        // Bit 2
        temp = TCAN114X_WDT_QA_Get_Bit(*question, 1) ^
               TCAN114X_WDT_QA_Get_Bit(*question, bitArray.wd5);
        temp += TCAN114X_WDT_QA_Get_Bit(wd_cnt, 1);
        temp += TCAN114X_WDT_QA_Get_Bit(*question, bitArray.wd4);
        bitanswer |= (TCAN114X_WDT_QA_Return_XOR(temp) << 2);

        // Bit 3
        temp = TCAN114X_WDT_QA_Get_Bit(*question, 3) ^
               TCAN114X_WDT_QA_Get_Bit(*question, bitArray.wd7);
        temp += TCAN114X_WDT_QA_Get_Bit(wd_cnt, 1);
        temp += TCAN114X_WDT_QA_Get_Bit(*question, bitArray.wd6);
        bitanswer |= (TCAN114X_WDT_QA_Return_XOR(temp) << 3);

        // Bit 4
        temp = TCAN114X_WDT_QA_Get_Bit(wd_cnt, 0) ^
               TCAN114X_WDT_QA_Get_Bit(*question, bitArray.wd8);
        bitanswer |= (temp << 4);

        // Bit 5
        temp = TCAN114X_WDT_QA_Get_Bit(wd_cnt, 0) ^
               TCAN114X_WDT_QA_Get_Bit(*question, bitArray.wd9);
        bitanswer |= (temp << 5);

        // Bit 6
        temp = TCAN114X_WDT_QA_Get_Bit(wd_cnt, 0) ^
               TCAN114X_WDT_QA_Get_Bit(*question, bitArray.wd10);
        bitanswer |= (temp << 6);

        // Bit 7
        temp = TCAN114X_WDT_QA_Get_Bit(wd_cnt, 0) ^
               TCAN114X_WDT_QA_Get_Bit(*question, bitArray.wd11);
        bitanswer |= (temp << 7);

        answer[i] = bitanswer;
    }
}

uint8_t TCAN114X_WDT_QA_Get_Bit(uint8_t data, uint8_t bit)
{
    if (bit > 3) return 0;
    return ((data >> bit) & 0x01);
}

uint8_t TCAN114X_WDT_QA_Return_XOR(uint8_t data)
{
    if (data % 2) return 1;
    return 0;
}

void TCAN114X_WDT_QA_Generate_Question_Bit_Array(
    uint8_t config, wdt_bits *bitArray)
{
    switch (config) {
        default:
            return;
        case 0x00: {
            bitArray->wd0  = 0;
            bitArray->wd1  = 3;
            bitArray->wd2  = 0;
            bitArray->wd3  = 2;
            bitArray->wd4  = 0;
            bitArray->wd5  = 3;
            bitArray->wd6  = 2;
            bitArray->wd7  = 0;
            bitArray->wd8  = 1;
            bitArray->wd9  = 3;
            bitArray->wd10 = 0;
            bitArray->wd11 = 2;
            break;
        }
        case 0x01: {
            bitArray->wd0  = 1;
            bitArray->wd1  = 2;
            bitArray->wd2  = 1;
            bitArray->wd3  = 1;
            bitArray->wd4  = 3;
            bitArray->wd5  = 2;
            bitArray->wd6  = 1;
            bitArray->wd7  = 3;
            bitArray->wd8  = 0;
            bitArray->wd9  = 2;
            bitArray->wd10 = 3;
            bitArray->wd11 = 1;
            break;
        }
        case 0x02: {
            bitArray->wd0  = 2;
            bitArray->wd1  = 1;
            bitArray->wd2  = 2;
            bitArray->wd3  = 0;
            bitArray->wd4  = 1;
            bitArray->wd5  = 1;
            bitArray->wd6  = 0;
            bitArray->wd7  = 2;
            bitArray->wd8  = 2;
            bitArray->wd9  = 1;
            bitArray->wd10 = 2;
            bitArray->wd11 = 0;
            break;
        }
        case 0x03: {
            bitArray->wd0  = 3;
            bitArray->wd1  = 0;
            bitArray->wd2  = 3;
            bitArray->wd3  = 3;
            bitArray->wd4  = 1;
            bitArray->wd5  = 0;
            bitArray->wd6  = 3;
            bitArray->wd7  = 1;
            bitArray->wd8  = 3;
            bitArray->wd9  = 0;
            bitArray->wd10 = 1;
            bitArray->wd11 = 3;
            break;
        }
    }
}

/*
 * @brief Calculates the next 4 bit question
 * @param *question is a pointer to the question used to calculate the answers
 * @param answer[] is an array of at least 4 bytes used to store the calculated answers
 */
void TCAN114x_WDT_QA_Calculate_Question(uint8_t *question, uint8_t answer[])
{
    uint8_t crc = 0;
    uint8_t i, j;
    uint8_t CRC7_POLY = 0x19;

    for (i = 0; i < 4; i++) {
        crc ^= *question;
        for (j = 0; j < 8; j++) {
            if (crc & 1) crc ^= CRC7_POLY;
            crc >>= 1;
        }
        answer[i] = crc;
    }
}
