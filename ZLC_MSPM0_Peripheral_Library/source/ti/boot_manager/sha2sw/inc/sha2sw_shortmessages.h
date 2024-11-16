/******************************************************************************
*  Copyright (c) 2021 Texas Instruments Incorporated. All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions are met:
*
*  1) Redistributions of source code must retain the above copyright notice,
*     this list of conditions and the following disclaimer.
*
*  2) Redistributions in binary form must reproduce the above copyright notice,
*     this list of conditions and the following disclaimer in the documentation
*     and/or other materials provided with the distribution.
*
*  3) Neither the name of the copyright holder nor the names of its contributors
*     may be used to endorse or promote products derived from this software
*     without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
*  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
*  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
*  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
*  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
*  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
*  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
*  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
*  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
******************************************************************************/
#ifndef SHA2SW_SHORTMESSAGES_H_
#define SHA2SW_SHORTMESSAGES_H_

/** ============================================================================
 *  @file       sha2sw_shortmessages.h
 *
 *  @brief      Provides specialized SHA2 APIs for short message hashes.
 *
 *  These specialized APIs provide reduced code size compared to the
 *  general purpose APIs.
 *
 */

#include <stdint.h>

#include <sha256sw.h>

/*!
 *  @brief  Performs a SHA2 256 hash of 16 bytes.
 *
 *  <em>Resulting hash is in BE format.</em> This saves code size.
 *  However, this is a different hash output format than the
 *  general purpose APIs.
 *
 *  Caller is responsible for ensuring all inputs are valid (no NULL
 *  pointers.)
 *
 *  For security, after the call returns, the caller should clear
 *  all memory used by the data pointed to by @c Ws.
 *  Sensitive data may still also remain on the stack after the function
 *  returns.
 *
 *  @param[out]  digest Output location for the final digest in BE format.
 *               Must be able to hold 16 bytes of output and be 32-bit aligned.
 *
 *  @param[in]   Ws workspace area for generating the hash.
 *               Must be 64 bytes long and be 32-bit aligned.
 *
 *  @param[in]   data data to hash, must be 16 bytes in length and in LE format.
 *
 */
void SHA2SW_hash16Bytes(uint32_t digest[8], uint32_t Ws[16], const void* data);

#endif /* SHA2SW_SHORTMESSAGES_H_ */
