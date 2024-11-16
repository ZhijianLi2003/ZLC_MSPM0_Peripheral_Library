/*
 * Copyright (c) 2015-2023, Texas Instruments Incorporated
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

#ifndef __TI_MSP_CRYPTO_H__
#define __TI_MSP_CRYPTO_H__

#include <stdint.h>
#include "sha256sw.h"

/*********************************************************************
 * GLOBAL VARIABLES
 */

/*********************************************************************
 * MACROS
 */

/* ECC Window Size.  Determines speed and workzone size of ECC operations.
 Recommended setting is 3. */
/*
 * Measured workspace memory size with the corresponding measured measured workzone usage
 *
 * Window Size: 2 max Workzone 904 (0x388)
 * Window Size: 3 max Workzone size: 1012 (0x3F4)
 * Window Size: 4 max Workzone size: 1228 (0x4CC)
 * Window Size: 5 max Workzone size: 1660 (0x67C)
 *
 * Recommended to add some safety factor for buffer overflow
 * ex: window size 2, use size 960/3C0
 * */
#define SECURE_FW_ECC_WINDOW_SIZE 2
#define ECC_WORKZONE_SIZE 960

/*! Invalid ECC Signature         */
#define SECURE_FW_ECC_STATUS_INVALID_SIGNATURE 0x5A
/*! ECC Signature Successfully Verified  */
#define SECURE_FW_ECC_STATUS_VALID_SIGNATURE 0xA5

#define ECDSA_KEY_LEN 32  //!< Length of the ECDSA security key
#define ECDSA_SHA_TEMPWORKZONE_LEN \
    ECDSA_KEY_LEN *                \
        6  //!< space for six buffers finalHash, reverseHash, pubkeyX, pubKeyY, sign1, sign2

/* Offset value for number of bytes occupied by length field */
#define SECURE_FW_ECC_KEY_OFFSET 4

/* Offset of Key Length field */
#define SECURE_FW_ECC_KEY_LEN_OFFSET 0

/*!
 * ECC key length in bytes for NIST P-256 keys.
 */
#define SECURE_FW_ECC_NIST_P256_KEY_LEN_IN_BYTES 32

/*!
 * ECC Workzone length in bytes for NIST P-256 key and shared secret generation.
 * For use with ECC Window Size 3 only.  Used to store intermediary values in
 * ECC calculations. */
#define BIM_ECC_NIST_P256_WORKZONE_LEN_IN_BYTES 1100

#ifndef SECURE_FW_ECC_NIST_P256_WORKZONE_LEN_IN_BYTES
#define SECURE_FW_ECC_NIST_P256_WORKZONE_LEN_IN_BYTES \
    (BIM_ECC_NIST_P256_WORKZONE_LEN_IN_BYTES)
#endif

/*! Length of Sign */
#define SECURE_FW_SIGN_LEN 32

/* Total buffer size */
#define SECURE_FW_ECC_BUF_TOTAL_LEN(len) ((len) + SECURE_FW_ECC_KEY_OFFSET)

/* Key size in uint32_t blocks */
#define SECURE_FW_ECC_UINT32_BLK_LEN(len) (((len) + 3) / 4)

/* Return Codes for the SHA256 */
#define MSP_CRYPTO_SHA256_STATUS_SUCCESS SHA2SW_STATUS_SUCCESS

#define MSP_CRYPTO_SHA256_STATUS_ERROR SHA2SW_STATUS_ERROR

#define MSP_CRYPTO_SHA256_STATUS_UNSUPPORTED SHA2SW_STATUS_UNSUPPORTED

#define MSP_CRYPTO_SHA256_STATUS_LENGTH_TOO_LARGE SHA2SW_STATUS_LENGTH_TOO_LARGE

#define MSP_CRYPTO_SHA256_STATUS_NULL_INPUT SHA2SW_STATUS_NULL_INPUT


void MSPCrypto_sha256_init(void);

void MSPCrypto_sha256_drop(void);

int MSPCrypto_sha256_update(const void *data, uint32_t data_len);

int MSPCrypto_sha256_finish(uint8_t *output);

void MSPCrypto_ecdsa_p256_init(void);

void MSPCrypto_ecdsa_p256_drop(void);

int MSPCrypto_ecdsa_p256_verify(
    const uint8_t *pk, const uint8_t *hash, const uint8_t *sig);

#endif /* __MSP_CRYPTO_H__ */
