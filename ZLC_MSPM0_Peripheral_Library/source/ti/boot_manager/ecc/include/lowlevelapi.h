/********************************************************************************
 **                                                                            **
 **                      Copyright 2006 -- 2011 (c)  INVIA                     **
 **                                                                            **
 **   All rights reserved. Reproduction in whole or part is prohibited         **
 **      without the written permission of the copyright owner                 **
 **                                                                            **
 ********************************************************************************
 ** File Name:      lowlevelapi.h
 ** Release:        2.0
 ** Author:         Alexandre Berzati <alexandre.berzati@invia.fr> - INVIA
 **
 ** Description:    Low-level arithmetic routines that simulate the MEXPA
 ** Note:           This header file provides prototypes for both the
 **                 MEXPA-accelerated and the simulated version of the
 **                 low-level API.
 **                 Refer to the User Manual for further details
 **
 ********************************************************************************
 */

/*
 * Customizations:
 *  - Removed global variables and modified APIs accordingly.
 *  - Modified to use stdint.
 *  - Converted to doxygen API doc.
 *
 * Copyright (c) 2021, Texas Instruments Incorporated
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
#ifndef __LOWLEVELAPI_H__
#define __LOWLEVELAPI_H__

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------------------
// Low-level Macro
//-----------------------------------------------------------------------------------------
#define MODSIZE(x) (2 * (x) + 2)
#define OPSIZE(x) ((x) + 1)
#define MONTLOG(x) (32 * (x))

//-----------------------------------------------------------------------------------------
// Low-level types
//-----------------------------------------------------------------------------------------

typedef struct {
    uint8_t win;
    uint8_t MSBMOD;
    const uint32_t *data_p;
    const uint32_t *data_r;
    const uint32_t *data_a;
    const uint32_t *data_b;
    const uint32_t *data_Gx;
    const uint32_t *data_Gy;
    const uint32_t *data_k_mont;
    const uint32_t *data_a_mont;
    const uint32_t *data_b_mont;
    uint32_t *workzone;
    const uint32_t *inScalar;
    const uint32_t *inPointX;
    const uint32_t *inPointY;
    uint32_t *outPointX;
    uint32_t *outPointY;
    uint32_t *SCAL;
    uint32_t *EXPX;
    uint32_t *EXPY;
    uint32_t *EXPZ;
    uint32_t *EXPW;
    uint32_t *ACCX;
    uint32_t *ACCY;
    uint32_t *ACCZ;
    uint32_t *TMP1;
    uint32_t *TMP2;
    uint32_t *TMP3;
    uint32_t *TMP4;
    uint32_t *TMP5;
    uint32_t *TMP6;
    uint32_t *MOD;
    uint32_t LEN;
    uint32_t aux64[2];
} ECC_State;

// //-----------------------------------------------------------------------------------------
// // Functions made available by lowlevelapi
// //-----------------------------------------------------------------------------------------

/** @defgroup modular_operators
 *  @{
 */

//*****************************************************************************
//!
//!  @brief  Montgomery modular multiplication out = in1 * in2 * K mod MOD where K is the
//!      Montgomery factor K = 2^-(32*LEN) mod MOD.
//!
//!  @param out     points anywhere in memory except in1 or in2
//!  @param in1     pointer to multiplicator in operand format
//!  @param in2     pointer to multiplicand in operand format
//!  @param mod     pointer to modulus
//!  @param len     word length of operands
//!
//*****************************************************************************
void mMULT(uint32_t *out, const uint32_t *in1, const uint32_t *in2,
    uint32_t *mod, uint32_t len);

//*****************************************************************************
//!
//!  @brief  Computes out = in1 - in2 mod MOD
//!
//!  @param out     pointer to result to be written in operand format
//!  @param in1     pointer to first operand in operand format
//!  @param in2     pointer to second operand in operand format
//!  @param mod     pointer to modulus
//!  @param len     word length of operands
//!
//!  @pre    A modulus must have been initialized by the mSET routine.
//!
//*****************************************************************************
void mSUB(uint32_t *out, const uint32_t *in1, const uint32_t *in2,
    uint32_t *mod, uint32_t len);

//*****************************************************************************
//!
//!  @brief  Computes out = in1 + in2 mod MOD
//!
//!  @param out     pointer to result to be written in operand format
//!  @param in1     pointer to first operand in operand format
//!  @param in2     pointer to second operand in operand format
//!  @param mod     pointer to modulus
//!  @param len     word length of operands
//!
//!  @pre    A modulus must have been initialized by the mSET routine.
//!
//*****************************************************************************
void mADD(uint32_t *out, const uint32_t *in1, const uint32_t *in2,
    uint32_t *mod, uint32_t len);

//*****************************************************************************
//!
//!  @brief  Computes the scrict modular remainder out = in1 mod MOD < MOD.
//!
//!  @param out     pointer to result to be written in operand format
//!  @param in1     pointer to integer in operand format
//!  @param mod     pointer to modulus
//!  @param len     word length of operands
//!
//!  @pre    A modulus must have been initialized by the mSET routine.
//!
//*****************************************************************************
void mOUT(uint32_t *out, const uint32_t *in1, uint32_t *mod, uint32_t len);

/** @} */ /* end of modular_operators */

//*****************************************************************************
//!
//!  @brief Returns the wordsize of the integer given at address in1 in LV format
//!
//!
//!  @param in1     pointer to integer in LV format [L, LSW, ..., MSW]
//!
//!  @return wordsize of the integer given at address in1
//!
//*****************************************************************************
uint32_t IMPORTLENGTH(const uint32_t *in1);

//*****************************************************************************
//!
//!  @brief Imports the integer in LV format found at address in1 into address out in modulus
//!         format [0, 0, LSW, ..., MSW]. Returns the wordsize of the imported modulus.
//!
//!  @param out     points where the modulus is to be written
//!  @param in1     pointer to integer in LV format [L, LSW, ..., MSW]
//!
//!  @return wordsize of the imported modulus
//!
//*****************************************************************************
uint32_t IMPORTMODULUS(uint32_t *out, const uint32_t *in1);

//*****************************************************************************
//!
//!  @brief Imports the integer in LV format found at address in1 into address out in operand
//!         format [LSW, ..., MSW, 0, ..., 0], making sure that the obtained array has LEN+1
//!         words, thus truncating or right-padding with zeroes as needed. Returns the wordsize
//!         of the imported integer.
//!
//!  @param state   pointer to ECC state object
//!  @param out     points where the operand is to be written
//!  @param in1     pointer to integer in LV format [L, LSW, ..., MSW]
//!
//!  @return wordsize of the imported integer
//!
//*****************************************************************************
uint32_t IMPORTOPERAND(ECC_State *state, uint32_t *out, const uint32_t *in1);

//*****************************************************************************
//!
//!  @brief Exports the integer found at address in1 to address out in LV
//!         format [LEN, LSW, ..., MSW]. Returns LEN.
//!
//!  @param  state   pointer to ECC state object
//!  @param  out     points where the LV format integer is to be written
//!  @param  in1     pointer to integer
//!
//!  @return LEN (wordsize length) from ECC state object
//!
//*****************************************************************************
uint32_t EXPORTOPERAND(ECC_State *state, uint32_t *out, const uint32_t *in1);

//*****************************************************************************
//!
//!  @brief Imports the integer in LV format found at address in1 into address out in raw data
//!         format [LSW, ..., MSW]. Returns the wordsize of the imported integer.
//!
//!
//!  @param out     points where the integer is to be written
//!  @param in1     pointer to integer in LV format [LEN, LSW, ..., MSW]
//!
//!  @return wordsize of the imported integer
//!
//*****************************************************************************
uint32_t IMPORTDATA(uint32_t *out, const uint32_t *in1);

//*****************************************************************************
//!
//!  @brief Writes the 32-bit integer in aux at address out in operand format
//!
//!  @param state     pointer to ECC state object
//!  @param out       points where the integer is to be written
//!  @param inValue   word to copy
//!
//*****************************************************************************
void SETOPERAND(ECC_State *state, uint32_t *out, uint32_t inValue);

//*****************************************************************************
//!
//!  @brief Copies aux words from address in1 to address out.
//!
//!  @param out     points anywhere in memory
//!  @param in1     points anywhere in memory
//!  @param size    number of words to be copied
//!
//*****************************************************************************
void COPY(uint32_t *out, uint32_t *in1, uint32_t size);

//*****************************************************************************
//!
//!  @brief Writes zeroes at adresses out through out + aux - 1.
//!
//!  @param out     points anywhere in memory
//!  @param size    number of zeroes to be written
//!
//*****************************************************************************
void ZERO(uint32_t *out, uint32_t size);

//*****************************************************************************
//!
//!  @brief Writes the 32-bit integer in aux at address out + WordPos
//!
//!  @param state   pointer to ECC state object
//!  @param out     points where the integer is to be written
//!
//*****************************************************************************

void SETWORD(ECC_State *state, uint32_t *out);

//-------------------------------------------------------------------------------
//! Initializing modular computations
//-------------------------------------------------------------------------------

//*****************************************************************************
//!
//!  @brief Initializes the modulus at address in1 for later modular operations. Completes the
//!         modulus with the modulus-specific constant alpha = -1/m mod 2^64.
//!
//!  @param state   pointer to ECC state object
//!  @param in1     pointer to modulus in format [0, 0, LSW(m), ..., MSW(m)]
//!  @param size    indicates the wordsize of the modulus
//!
//!  @note In simulation mode, only al0 = alpha mod 2^32 is computed. The routine uses the
//!        Newton-based inductive formula alpha = alpha * (m[0] * alpha + 2) mod 2^32
//!        repeated 6 times where alpha is previously set to 1.
//*****************************************************************************
void mSET(ECC_State *state, uint32_t *in1, uint32_t size);

//*****************************************************************************
//!
//!  @brief Prepares operation in Integer
//!
//!  @param state   pointer to ECC state object
//!  @param size    indicates the wordsize of the operands
//!
//*****************************************************************************
void zSET(ECC_State *state, uint32_t size);

//*****************************************************************************
//!
//!  @brief Writes c = 1/K mod MOD at on LEN words at address out where K is the Montgomery
//!         factor K = 2^-(32.LEN) mod MOD.
//!
//!  @param state   pointer to ECC state object
//!  @param out     points anywhere in memory
//!
//!  @pre   A modulus must have been initialized by the mSET routine.
//!
//*****************************************************************************
void mINVK(ECC_State *state, uint32_t *out);

//-------------------------------------------------------------------------------
//! Integer operators
//-------------------------------------------------------------------------------

//*****************************************************************************
//!
//!  @brief Computes out = in1 + in2 on LEN words and returns the overflow carry.
//!
//!  @param state   pointer to ECC state object
//!  @param out     pointer to result to be written
//!  @param in1     pointer to first operand
//!  @param in2     pointer to second operand
//!
//!  @return overflow carry
//!
//*****************************************************************************

uint32_t zADD(ECC_State *state, uint32_t *out, uint32_t *in1, uint32_t *in2);

//*****************************************************************************
//!
//!  @brief Computes out = in1 - in2 on LEN words and returns the Borrow.
//!
//!  @param state   pointer to ECC state object
//!  @param out     pointer to result to be written
//!  @param in1     pointer to first operand
//!  @param in2     pointer to second operand
//!
//!  @return borrow
//!
//*****************************************************************************

uint32_t zSUB(ECC_State *state, uint32_t *out, uint32_t *in1, uint32_t *in2);

//*****************************************************************************
//!
//!  @brief Computes out = (in1 mod 2^(32 LEN)) * aux + in2 mod 2^(32 LEN)) and returns the
//!        overflow carry.
//!
//!  @param state   pointer to ECC state object
//!  @param out     pointer to result to be written
//!  @param in1     pointer to first operand
//!  @param in2     pointer to second operand
//!
//!  @return overflow carry
//!
//!  @pre    A modulus must have been initialized by the mSET routine.
//!
//*****************************************************************************

void zMACC32(ECC_State *state, uint32_t *out, uint32_t *in1, uint32_t *in2);

//*****************************************************************************
//!
//!  @brief Computes @(out) = @(in1) - aux on LEN words and returns the overflow carry.
//!
//!  @param state   pointer to ECC state object
//!  @param in1     pointer to first operand
//!  @param out     pointer to result to be written
//!
//!  @return overflow carry
//!
//!  @pre    A modulus must have been initialized by the mSET routine.
//!
//*****************************************************************************
uint32_t zSUB32(ECC_State *state, uint32_t *out, uint32_t *in1);

//*****************************************************************************
//!
//!  @brief Computes @(out) = @(in1) + aux on LEN words and returns the overflow carry.
//!
//!  @param state   pointer to ECC state object with aux value
//!  @param out     pointer to result to be written
//!  @param in1     pointer to first operand
//!
//!  @return overflow carry
//!
//!  @pre    A modulus must have been initialized by the mSET routine.
//!
//*****************************************************************************
uint32_t zADD32(ECC_State *state, uint32_t *out, uint32_t *in1);

//*****************************************************************************
//!
//!  @brief Computes out = (in1 mod 2^(32 LEN)) * aux mod 2^(32(LEN+1)).
//!
//!  @param state   pointer to ECC state object
//!  @param in1     pointer to first operand
//!  @param out     pointer to result to be written
//!
//!  @pre    A modulus must have been initialized by the mSET routine.
//!
//*****************************************************************************
void zMULT32(ECC_State *state, uint32_t *out, uint32_t *in1);

//*****************************************************************************
//!
//!  @brief Compares two buffers in constant time
//!
//!  @param buffer0     pointer to first uint32_t buffer
//!  @param buffer1     pointer to second uint32_t buffer
//!  @param bufferWordLength    Number of 32-bit words of buffer0 and buffer1 to compare
//!
//!  @return true if buffer content is identical and false otherwise
//!
//*****************************************************************************
bool BUFFERSEQUAL(const uint32_t *buffer0, const uint32_t *buffer1,
    uint32_t bufferWordLength);

//*****************************************************************************
//!
//!  @brief Checks if a buffer contains only zeros in constant time
//!
//!  @param buffer      pointer to the uint32_t buffer to check
//!  @param bufferWordLength    Number of 32-bit words of buffer
//!
//!  @return true if the buffer only contains 0x00000000 and false otherwise
//!
//*****************************************************************************
bool ISALLZEROS(const uint32_t *buffer, uint32_t bufferWordLength);

#ifdef __cplusplus
}
#endif

#endif /*__LOWLEVELAPI_H__*/

//==================================================================================== end>
