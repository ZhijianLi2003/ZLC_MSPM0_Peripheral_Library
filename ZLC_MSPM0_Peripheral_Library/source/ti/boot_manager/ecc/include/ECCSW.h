/********************************************************************************
 **                                                                            **
 **                      Copyright 2006 -- 2012 (c)  INVIA                     **
 **                                                                            **
 **   All rights reserved. Reproduction in whole or part is prohibited         **
 **      without the written permission of the copyright owner                 **
 **                                                                            **
 ********************************************************************************
 ** File Name:      ECCSW.h
 ** Release:        2.0
 ** Author:         Alexandre Berzati <alexandre.berzati@invia.fr> - INVIA
 **
 ** Description:    Description of the ECC API Library entry points and
 **                 Error codes
 **
 ********************************************************************************
 */

/*
 * Customizations:
 *  - Removed global variables and modified APIs accordingly.
 *  - Modified to use stdint.
 *  - Added ECCSW_validatePublicKeyWeierstrass().
 *  - Added ECCSW_validatePrivateKeyWeierstrass().
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

#ifndef __ECCSW_H_
#define __ECCSW_H_

#include "lowlevelapi.h"
#include "scalarMul.h"

#include <stdint.h>

/******************************************************************************/
/***                               STATUS                                   ***/
/******************************************************************************/

// ECDSA and ECDH status

#define STATUS_ORDER_LARGER_THAN_255_WORDS 0x28
#define STATUS_ORDER_EVEN 0x82
#define STATUS_ORDER_MSW_IS_ZERO 0x23
#define STATUS_ECC_KEY_TOO_LONG 0x25
#define STATUS_ECC_KEY_LENGTH_ZERO 0x52
#define STATUS_ECC_X_LARGER_THAN_PRIME 0x11
#define STATUS_ECC_Y_LARGER_THAN_PRIME 0x12
#define STATUS_ECC_X_ZERO 0x13
#define STATUS_ECC_Y_ZERO 0x14
#define STATUS_ECC_POINT_NOT_ON_CURVE 0x15
#define STATUS_ECC_POINT_ON_CURVE 0x16
#define STATUS_PRIVATE_KEY_ZERO 0x17
#define STATUS_PRIVATE_KEY_LARGER_EQUAL_ORDER 0x18
#define STATUS_PRIVATE_VALID 0x19
#define STATUS_DIGEST_TOO_LONG 0x27
#define STATUS_DIGEST_LENGTH_ZERO 0x72
#define STATUS_ECDSA_SIGN_OK 0x32
#define STATUS_ECDSA_INVALID_SIGNATURE 0x5A
#define STATUS_ECDSA_VALID_SIGNATURE 0xA5
#define STATUS_SIG_P1_TOO_LONG 0x11
#define STATUS_SIG_P1_LENGTH_ZERO 0x12
#define STATUS_SIG_P2_TOO_LONG 0x22
#define STATUS_SIG_P2_LENGTH_ZERO 0x21

#define STATUS_ECDSA_KEYGEN_OK STATUS_SCALAR_MUL_OK
#define STATUS_ECDH_KEYGEN_OK STATUS_SCALAR_MUL_OK
#define STATUS_ECDH_COMMON_KEY_OK STATUS_SCALAR_MUL_OK

/******************************************************************************/
/***                              TYPES                                     ***/
/******************************************************************************/

/******************************************************************************/
/***                        GLOBAL VAIABLES                                 ***/
/******************************************************************************/

/******************************************************************************/
/***                           FUNCTIONS                                    ***/
/******************************************************************************/

uint8_t ECCSW_keyGen(ECC_State *state, uint32_t *eccKeyGen_Random,
    uint32_t *eccKeyGen_Sk, uint32_t *eccKeyGen_Pk_X,
    uint32_t *eccKeyGen_Pk_Y);

/**
 * Create Aliases
 */
#define ECCSW_ECDSAKeyGen ECCSW_keyGen
#define ECCSW_ECDHKeyGen ECCSW_keyGen

uint8_t ECCSW_ECDSASign(ECC_State *state, uint32_t *ecdsaSign_Key,
    uint32_t *ecdsaSign_Digest, uint32_t *ecdsaSign_Random,
    uint32_t *ecdsaSign_Sig_P1, uint32_t *ecdsaSign_Sig_P2);

uint8_t ECCSW_ECDSAVerify(ECC_State *state, uint32_t *ecdsaVerif_Pk_X,
    uint32_t *ecdsaVerif_Pk_Y, uint32_t *ecdsaVerif_Digest,
    uint32_t *ecdsaSig_P1, uint32_t *ecdsaSig_P2);

uint8_t ECCSW_ECDHCommonKey(ECC_State *state, uint32_t *ecdhCommonKey_inScal,
    uint32_t *ecdhCommonKey_inX, uint32_t *ecdhCommonKey_inY,
    uint32_t *ecdhCommonKey_outX, uint32_t *ecdhCommonKey_outY);

uint8_t ECCSW_validatePrivateKeyWeierstrass(
    ECC_State *state, const uint32_t *privateKey);

uint8_t ECCSW_validatePublicKeyWeierstrass(ECC_State *state,
    const uint32_t *curvePointX, const uint32_t *curvePointY);

#endif
