/*
* Copyright (c) 2021 Texas Instruments Incorporated
*
* All rights reserved not granted herein.
* Limited License.
*
* Texas Instruments Incorporated grants a world-wide, royalty-free,
* non-exclusive license under copyrights and patents it now or hereafter
* owns or controls to make, have made, use, import, offer to sell and sell ("Utilize")
* this software subject to the terms herein.  With respect to the foregoing patent
* license, such license is granted  solely to the extent that any such patent is necessary
* to Utilize the software alone.  The patent license shall not apply to any combinations which
* include this software, other than combinations with devices manufactured by or for TI (“TI Devices”).
* No hardware patent is licensed hereunder.
*
* Redistributions must preserve existing copyright notices and reproduce this license (including the
* above copyright notice and the disclaimer and (if applicable) source code license limitations below)
* in the documentation and/or other materials provided with the distribution
*
* Redistribution and use in binary form, without modification, are permitted provided that the following
* conditions are met:
*
*   * No reverse engineering, decompilation, or disassembly of this software is permitted with respect to any
*     software provided in binary form.
*   * any redistribution and use are licensed by TI for use only with TI Devices.
*   * Nothing shall obligate TI to provide you with source code for the software licensed and provided to you in object code.
*
* If software source code is provided to you, modification and redistribution of the source code are permitted
* provided that the following conditions are met:
*
*   * any redistribution and use of the source code, including any resulting derivative works, are licensed by
*     TI for use only with TI Devices.
*   * any redistribution and use of any object code compiled from the source code and any resulting derivative
*     works, are licensed by TI for use only with TI Devices.
*
* Neither the name of Texas Instruments Incorporated nor the names of its suppliers may be used to endorse or
* promote products derived from this software without specific prior written permission.
*
* DISCLAIMER.
*
* THIS SOFTWARE IS PROVIDED BY TI AND TI’S LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
* BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL TI AND TI’S LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
* OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef SHA2SW_COMMON_H_
#define SHA2SW_COMMON_H_

/** ============================================================================
 *  @file       sha2sw_common.h
 *
 *  @brief      Definitions common across all SHA2 SW modules.
 *
 *  # Overview #
 *  Provides top-level general purpose SHA2 SW definitions such as
 *  error return codes and enumerations.
 *
 */

#include <stddef.h>
#include <stdint.h>

#include <sha2sw_config.h>

/*!
 *  @brief  Enum for the hash types supported by the library.
 */
typedef enum {
    SHA2SW_HASH_TYPE_256 = 0,
#if SHA2SW_SUPPORT_SHA2_224 == 1
    SHA2SW_HASH_TYPE_224 = 1,
#endif
#if SHA2SW_SUPPORT_SHA2_384 == 1
    SHA2SW_HASH_TYPE_384 = 2,
#endif
    SHA2SW_HASH_TYPE_512 = 3
} SHA2SW_HashType;

/*!
 *  @brief  Number of rounds used in the SHA2 224 and 256 algorithms.
 */
#define SHA2SW_224_OR_256_ROUNDS ((uint8_t) 64u)

/*!
 *  @brief  Number of rounds used in the SHA2 384 and 512 algorithms.
 */
#define SHA2SW_384_OR_512_ROUNDS ((uint8_t) 80u)

/*!
 *  @brief  Number of bytes in the block of the SHA2 224 and 256 algorithms.
 */
#define SHA2SW_224_OR_256_BLOCK_SIZE ((uint8_t) 64u)

/*!
 *  @brief  Number of bytes in the block of the SHA2 384 and 512 algorithms.
 */
#define SHA2SW_384_OR_512_BLOCK_SIZE ((uint8_t) 128u)

/*!
 *  @brief  Number of bytes in the SHA2 224 digest.
 */
#define SHA2SW_224_DIGEST_SIZE ((uint8_t) 28u)

/*!
 *  @brief  Number of bytes in the SHA2 256 digest.
 */
#define SHA2SW_256_DIGEST_SIZE ((uint8_t) 32u)

/*!
 *  @brief  Number of bytes in the SHA2 384 digest.
 */
#define SHA2SW_384_DIGEST_SIZE ((uint8_t) 48u)

/*!
 *  @brief  Number of bytes in the SHA2 512 digest.
 */
#define SHA2SW_512_DIGEST_SIZE ((uint8_t) 64u)

/*!
 *  @brief  The maximum number of bits this implementation
 *          supports in the input message/data.
 */
#define SHA2SW_MAX_MESSAGE_BIT_LENGTH ((uint32_t) 0x20000000u)

/*!
*  @defgroup SHA2SW_StatusCodes SHA2 SW Status codes
*  These macros represent status codes returned by the SHA2 SW module.
*  @{
*/

/*!
 * @brief   Successful status code.
 *
 * Functions return SHA2SW_STATUS_SUCCESS if the function was executed
 * successfully.
 */
#define SHA2SW_STATUS_SUCCESS ((int_fast16_t) 0)

/*!
 * @brief   Generic error status code.
 *
 * Functions return SHA2SW_STATUS_ERROR if the function was not executed
 * successfully and no more specific error is applicable.
 */
#define SHA2SW_STATUS_ERROR ((int_fast16_t) -100)

/*!
 * @brief   Requested operation is not supported.
 *
 * The library (as built) does not support a requested feature.
 */
#define SHA2SW_STATUS_UNSUPPORTED ((int_fast16_t) -102)

/*!
 * @brief   Too many data bytes have been requested to be hashed.
 *
 * The library supports a maximum length of 512MiB to be hashed.
 */
#define SHA2SW_STATUS_LENGTH_TOO_LARGE ((int_fast16_t) -103)

/*!
 * @brief   Input value was NULL.
 *
 * An input pointer was NULL. Operation not performed.
 */
#define SHA2SW_STATUS_NULL_INPUT ((int_fast16_t) -104)

/*! @}*/

#endif /* SHA2SW_COMMON_H_ */
