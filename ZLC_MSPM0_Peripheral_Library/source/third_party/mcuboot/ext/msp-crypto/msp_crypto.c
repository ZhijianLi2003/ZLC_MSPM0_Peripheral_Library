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

#include "msp-crypto/msp_crypto.h"
#include <stdint.h>
#include "mcuboot_config/mcuboot_logging.h"
#include "string.h"

#include "sha256sw.h"
#include "ECCSW.h"
#include "scalarMul.h"

#define MAXLEN 8   // for NIST-256
#define KEYLEN 32  // in bytes
#define ECDSA_SHA_TEMPWORKSZONE_LEN (6 * KEYLEN)


/* NIST p256 curve parameters, DO NOT EDIT */
const uint32_t NIST256_p[MAXLEN + 1]  = {8ul, 4294967295ul, 4294967295ul,
    4294967295ul, 0ul, 0ul, 0ul, 1ul, 4294967295ul};
const uint32_t NIST256_r[MAXLEN + 1]  = {8ul, 4234356049ul, 4089039554ul,
    2803342980ul, 3169254061ul, 4294967295ul, 4294967295ul, 0ul, 4294967295ul};
const uint32_t NIST256_a[MAXLEN + 1]  = {8ul, 4294967292ul, 4294967295ul,
    4294967295ul, 0ul, 0ul, 0ul, 1ul, 4294967295ul};
const uint32_t NIST256_b[MAXLEN + 1]  = {8ul, 668098635ul, 1003371582ul,
    3428036854ul, 1696401072ul, 1989707452ul, 3018571093ul, 2855965671ul,
    1522939352ul};
const uint32_t NIST256_Gx[MAXLEN + 1] = {8ul, 3633889942ul, 4104206661ul,
    770388896ul, 1996717441ul, 1671708914ul, 4173129445ul, 3777774151ul,
    1796723186ul};
const uint32_t NIST256_Gy[MAXLEN + 1] = {8ul, 935285237ul, 3417718888ul,
    1798397646ul, 734933847ul, 2081398294ul, 2397563722ul, 4263149467ul,
    1340293858ul};

/* SHA256 Objects */
SHA256SW_Object sha256SWObject;
SHA256SW_Handle sha256SWHandle = &sha256SWObject;
int_fast16_t sha2SWresult;
uint32_t finalDigest[8];

/* ECC Workzone declared
 *
 * Size considerations:
 *  Window Size: 2 (currently used and non adjustable)
 *  Maximum workzone size: 904 (0x388)
 *
 */
uint32_t ecc_workzone[ECC_WORKZONE_SIZE / sizeof(uint32_t)];

/* ECC Defines */
uint8_t ret;
uint32_t len;
volatile uint32_t err = 0;
volatile uint8_t j, w;
ECC_State ecc_state;

void copy(uint8_t *to, const uint8_t *from, int len)
{
    for (int i = 0; i < len; i++) {
        to[i] = from[i];
    }
}

/*********************************************************************
 * @fn         reverseOrder
 * @brief      Reverse the byte order and copy to output buffer
 *
 * @param      pBufIn - pointer to input buffer
 * @param      pBufOut - pointer to output buffer
 */
static void reverseOrder(const uint8_t *pBufIn, uint8_t *pBufOut)
{
    uint8_t i            = 0;
    uint32_t sign_length = 32;
    for (i = 0; i < sign_length; i++) {
        pBufOut[i] = pBufIn[sign_length - 1 - i];
    }
}

/*********************************************************************
 * @fn         copyBytes
 * @brief      Copy data between memory locatins
 *
 * @param      pDst - pointer to destination buffer
 * @param      pSrc - pointer to source buffer
 * @param      len  - length of data to be copied
 */
static void copyBytes(uint8_t *pDst, const uint8_t *pSrc, uint32_t len)
{
    uint32_t i;
    for (i = 0; i < len; i++) {
        pDst[i] = pSrc[i];
    }
}

void MSPCrypto_sha256_init(void)
{
    sha2SWresult = SHA256SW_start(sha256SWHandle, SHA2SW_HASH_TYPE_256);
}

void MSPCrypto_sha256_drop(void)
{
    SHA256SW_cancel(sha256SWHandle);
    return;
}

int MSPCrypto_sha256_update(const void *data, uint32_t data_len)
{
    if (sha2SWresult == SHA2SW_STATUS_SUCCESS) {
        sha2SWresult = SHA256SW_addData(sha256SWHandle, data, data_len);
    }
    return sha2SWresult;
}

int MSPCrypto_sha256_finish(uint8_t *output)
{
    if (sha2SWresult == SHA2SW_STATUS_SUCCESS) {
        sha2SWresult = SHA256SW_finalize(sha256SWHandle, (uint32_t *) output);
    }
    return sha2SWresult;
}

void MSPCrypto_ecdsa_p256_init(void)
{
    ecc_state.data_p   = NIST256_p;
    ecc_state.data_r   = NIST256_r;
    ecc_state.data_a   = NIST256_a;
    ecc_state.data_b   = NIST256_b;
    ecc_state.data_Gx  = NIST256_Gx;
    ecc_state.data_Gy  = NIST256_Gy;
    ecc_state.workzone = ecc_workzone;
    ecc_state.win      = SECURE_FW_ECC_WINDOW_SIZE;
}

void MSPCrypto_ecdsa_p256_drop(void)
{
    /* Nothing required to drop */
    return;
}

int MSPCrypto_ecdsa_p256_verify(
    const uint8_t *pk, const uint8_t *hash, const uint8_t *sig)
{
    /* Key comes in pre-processed from DER format with x coordinate, then y. */
    uint32_t publicKeyXBuf[MAXLEN + 1] = {0};
    uint32_t publicKeyYBuf[MAXLEN + 1] = {0};
    uint32_t digest[MAXLEN + 1]        = {0};
    uint32_t sign1[MAXLEN + 1]         = {0};
    uint32_t sign2[MAXLEN + 1]         = {0};
    uint32_t ret;

    /* ECC library expects inputs in uint32_t format, whereas mcuboot provides
     * byte length. Set length accordingly */
    publicKeyXBuf[0] = KEYLEN / 4;
    reverseOrder(pk, (uint8_t *) &publicKeyXBuf[1]);

    publicKeyYBuf[0] = KEYLEN / 4;
    reverseOrder(pk + KEYLEN, (uint8_t *) &publicKeyYBuf[1]);

    digest[0] = KEYLEN / 4;
    reverseOrder(hash, (uint8_t *) &digest[1]);

    sign1[0] = KEYLEN / 4;
    reverseOrder(sig, (uint8_t *) &sign1[1]);

    sign2[0] = KEYLEN / 4;
    reverseOrder(sig + KEYLEN, (uint8_t *) &sign2[1]);

    ret = ECCSW_ECDSAVerify(
        &ecc_state, publicKeyXBuf, publicKeyYBuf, digest, sign1, sign2);

    if (ret != STATUS_ECDSA_VALID_SIGNATURE) {
        MCUBOOT_LOG_ERR("MSPCrypto_ecdsa_p256_verify: fail");
        return -1;
    }

    return 0;
}