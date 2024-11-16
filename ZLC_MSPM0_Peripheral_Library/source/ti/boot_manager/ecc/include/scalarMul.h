/********************************************************************************
 **                                                                            **
 **                      Copyright 2006 -- 2012 (c)  INVIA                     **
 **                                                                            **
 **   All rights reserved. Reproduction in whole or part is prohibited         **
 **      without the written permission of the copyright owner                 **
 **                                                                            **
 ********************************************************************************
 ** File Name:      scalarMul.h
 ** Release:        2.0
 ** Author:         Alexandre Berzati <alexandre.berzati@invia.fr> - INVIA
 **
 ** Description:    Headers of main functions used for elliptic curve
 **                 computations
 **
 ********************************************************************************
 */

/*
 * Customizations:
 *  - Removed global variables and modified APIs accordingly.
 *  - Modified to use stdint.
 *  - Converted to doxygen API doc
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

#ifndef __SCALARMUL_H_
#define __SCALARMUL_H_

#include "lowlevelapi.h"

#include <stdint.h>

/******************************************************************************/
/***                               STATUS                                   ***/
/******************************************************************************/

#define STATUS_MODULUS_EVEN 0xDC
#define STATUS_MODULUS_LARGER_THAN_255_WORDS 0xD2
#define STATUS_MODULUS_LENGTH_ZERO 0x08
#define STATUS_MODULUS_MSW_IS_ZERO 0x30
#define STATUS_SCALAR_TOO_LONG 0x35
#define STATUS_SCALAR_LENGTH_ZERO 0x53
#define STATUS_ORDER_TOO_LONG 0xC6
#define STATUS_ORDER_LENGTH_ZERO 0x6C
#define STATUS_X_COORD_TOO_LONG 0x3C
#define STATUS_X_COORD_LENGTH_ZERO 0xC3
#define STATUS_Y_COORD_TOO_LONG 0x65
#define STATUS_Y_COORD_LENGTH_ZERO 0x56
#define STATUS_A_COEF_TOO_LONG 0x5C
#define STATUS_A_COEF_LENGTH_ZERO 0xC5
#define STATUS_BAD_WINDOW_SIZE 0x66
#define STATUS_FAULT_DETECTION 0x33
#define STATUS_SCALAR_MUL_OK 0x99

/******************************************************************************/
/***                              TYPES                                     ***/
/******************************************************************************/

/******************************************************************************/
/***                        GLOBAL VAIABLES                                 ***/
/******************************************************************************/

#define REF_INVK                                                \
    (state->workzone + MODSIZE(state->LEN) + (state->LEN) + 1 + \
        2 * OPSIZE(state->LEN))
#define REF_INVK2                                               \
    (state->workzone + MODSIZE(state->LEN) + (state->LEN) + 1 + \
        (3 * ((uint8_t) 1 << (state->win - 2)) + 5) * OPSIZE(state->LEN))

/******************************************************************************/
/***                           FUNCTIONS                                    ***/
/******************************************************************************/

//*****************************************************************************
//!
//!  @brief  Complete scalar multiplication sequence (Initialization, core, and finalization)
//!
//!  @param state   pointer to ECC state object
//!
//!  @retval STATUS_SCALAR_MUL_OK
//!  @retval STATUS_MODULUS_EVEN
//!  @retval STATUS_MODULUS_MSW_IS_ZERO
//!  @retval STATUS_MODULUS_LENGTH_ZERO
//!  @retval STATUS_MODULUS_LARGER_THAN_255_WORDS
//!  @retval STATUS_SCALAR_TOO_LONG
//!  @retval STATUS_SCALAR_LENGTH_ZERO
//!  @retval STATUS_ORDER_LENGTH_ZERO
//!  @retval STATUS_ORDER_TOO_LONG
//!  @retval STATUS_BAD_WINDOW_SIZE if window size is not [2-5]
//!  @retval STATUS_Y_COORD_TOO_LONG
//!  @retval STATUS_Y_COORD_LENGTH_ZERO
//!  @retval STATUS_A_COEF_TOO_LONG
//!  @retval STATUS_A_COEF_LENGTH_ZERO
//!
//*****************************************************************************
uint8_t SCALARMUL(ECC_State *state);

//*****************************************************************************
//!
//!  @brief  Initialization for scalar multiplication
//!
//!  @param state   pointer to ECC state object
//!
//!  @retval STATUS_SCALAR_MUL_OK
//!  @retval STATUS_MODULUS_EVEN
//!  @retval STATUS_MODULUS_MSW_IS_ZERO
//!  @retval STATUS_MODULUS_LENGTH_ZERO
//!  @retval STATUS_MODULUS_LARGER_THAN_255_WORDS
//!
//*****************************************************************************
uint8_t SCALARMUL_init(ECC_State *state);

//*****************************************************************************
//!
//!  @brief  Core scalar multiplication
//!
//!  @param state   pointer to ECC state object
//!
//!  @retval STATUS_SCALAR_MUL_OK
//!  @retval STATUS_SCALAR_TOO_LONG
//!  @retval STATUS_SCALAR_LENGTH_ZERO
//!  @retval STATUS_ORDER_LENGTH_ZERO
//!  @retval STATUS_ORDER_TOO_LONG
//!  @retval STATUS_BAD_WINDOW_SIZE if window size is not [2-5]
//!  @retval STATUS_Y_COORD_TOO_LONG
//!  @retval STATUS_Y_COORD_LENGTH_ZERO
//!  @retval STATUS_A_COEF_TOO_LONG
//!  @retval STATUS_A_COEF_LENGTH_ZERO
//!
//*****************************************************************************
uint8_t SCALARMUL_core(ECC_State *state);

//*****************************************************************************
//!
//!  @brief  Finalize scalar multiplication
//!
//!  @param state   pointer to ECC state object
//!
//*****************************************************************************
void SCALARMUL_final(ECC_State *state);

//*****************************************************************************
//!
//!  @brief   Perform a modular inversion of the element at address in in1
//!
//!  @param state   pointer to ECC state object
//!  @param in1     pointer to value to invert
//!
//!  @return pointer to inverted value (same as in1)
//!
//*****************************************************************************
uint32_t *INVERT(ECC_State *state, uint32_t *in1);

//*****************************************************************************
//!
//!  @brief  Perform a modular exponentiation of the element at address in in1 to the
//!          power in aux (32-bit value)
//!
//!  @param state   pointer to ECC state object with aux value
//!  @param out     pointer to output location
//!  @param in1     pointer to address of the value to exponentiate
//!  @param in2     pointer to available memory buffers for exponentiation
//!
//!  @return Pointer to result (either in2 or out)
//!
//*****************************************************************************
uint32_t *SQUAREMULTIPLYWORD(
    ECC_State *state, uint32_t *out, uint32_t *in1, uint32_t *in2);

//*****************************************************************************
//!
//!  @brief  JACADD primitive:
//!    - If aux=0, then perform a Jacobian addition of the exponentiator to the i-th accumulator
//!    - If aux=1, then perform a Jacobian addition of the j-th accumulator to the i-th accumulator
//!    - If aux=2, then perform a Jacobian addition of the point at address in2 to the i-th accumulator
//!
//!  @param state   pointer to ECC state object with aux value
//!  @param in1     pointer to index of the accumulator (i)
//!  @param in2     pointer to index of the accumulator (j) / address of the point to add
//!
//!  @return Pointer to result (either in2 or out)
//!
//*****************************************************************************
void JACADD(ECC_State *state, uint32_t *in1, uint32_t *in2);

//*****************************************************************************
//!
//!  @brief  Saves the point to the output locaiton
//!
//!  @param state   pointer to ECC state object
//!
//*****************************************************************************
void ATOMICPATTERN(ECC_State *state);

//*****************************************************************************
//!
//!  @brief  Extract the bit of given index
//!
//!  @param in1     pointer to input
//!  @param in2     pointer to index of bit
//!
//!  @return The bit of the given index
//!
//*****************************************************************************
uint8_t GETBIT(uint32_t *in1, uint32_t *in2);

//*****************************************************************************
//!
//!  @brief  Extract the digit of given index (LSB) and bit-length from a given input
//!
//!  @param state   pointer to ECC state object
//!  @param in1     pointer to input data
//!  @param in2     pointer to index of digit LSB
//!
//!  @return The digit of given index (LSB) and bit-length from a given input.
//!
//*****************************************************************************
uint8_t GETDIGIT(ECC_State *state, uint32_t *in1, uint32_t *in2);

//*****************************************************************************
//!
//!  @brief  Extract the maximum odd digit with MSB at a given index from a given input
//!
//!  @param state   pointer to ECC state object
//!  @param in1     pointer to input data
//!  @param in2     pointer to index
//!
//!  @return The maximum odd digit with MSB at a given index from a given input.
//!
//*****************************************************************************
uint8_t GETDIGITL2R(ECC_State *state, uint32_t *in1, uint32_t *in2);

//*****************************************************************************
//!
//!  @brief  Saves the point to the output location
//!
//!  @param state   pointer to ECC state object
//!  @param out     pointer location to save the point
//!
//*****************************************************************************
void SAVEPOINT(ECC_State *state, uint32_t *out);

#endif /* __SCALARMUL_H_ */
