/*
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

#ifndef __ECCSW25519_H_
#define __ECCSW25519_H_

#include <stdint.h>
#include "lowlevelapi.h"

/******************************************************************************/
/***                           FUNCTIONS                                    ***/
/******************************************************************************/

//*****************************************************************************
//!
//!  @brief  Computes the public key or shared secret key for X25519
//!
//!  @param state   pointer to ECC state object
//!  @param ecdhCommonKey_inScal   pointer to input scalar (private key)
//!  @param ecdhCommonKey_inX      pointer to input x-coordinate (public key or base point coordinate)
//!  @param ecdhCommonKey_outX     pointer to output x-coordinate (shared secret key or public key)
//!
//!  @retval STATUS_ECDH_COMMON_KEY_OK
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
uint8_t ECCSW_X25519_commonKey(ECC_State *state,
    const uint32_t *ecdhCommonKey_inScal, const uint32_t *ecdhCommonKey_inX,
    uint32_t *ecdhCommonKey_outX);

#endif /* __ECCSW25519_H_ */
