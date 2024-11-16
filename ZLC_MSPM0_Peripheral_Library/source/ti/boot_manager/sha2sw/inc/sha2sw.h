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
#ifndef SHA2SW_H_
#define SHA2SW_H_

/** ============================================================================
 *  @file       sha2sw.h
 *
 *  @brief      SHA2 SW APIs.
 *
 *  @anchor ti_SHA2_SW_LIBRARY_Overview
 *  # Overview #
 *  Provides top-level general purpose SHA2 512//384/256/224 APIs.
 *  SHA2 algorithm is implemented in SW with no HW acceleration.
 *  The implementation is highly optimized for speed and code size.
 *
 *
 *  Availability of SHA2 224 and SHA2 384 depends on build configuration.
 *  See file @sa sha2sw_config.h.
 *
 *  ## Limitations ##
 *  @li A maximum of 512MiB may be hashed by this implementation. (SHA2
 *      standard supports 2 million Terabytes for 224/256)
 *  @li Input data may be 8-bit aligned. However, output digest must be
 *      32-bit aligned.
 *  @li Intermediate values, input data, and final digest value may be
 *      left behind on the stack.
 *
 *  <hr>
 *  @anchor ti_SHA2_SW_LIBRARY_Usage
 *  # Usage #
 *
 *  There are two general ways to execute a SHA2 operation:
 *
 *  - one-step, using #SHA2SW_hashData()
 *  - multi-step, using #SHA2SW_start(), #SHA2SW_addData(), and
 *    #SHA2SW_finalize()
 *
 *  The multi-step approach allows the hash to be extended by adding
 *  more data.
 *
 *  In addition, #SHA2SW_cancel() is provided to cancel a multi-step
 *  operation. The cancel process ensures intermediate data is erased
 *  (set to zero) for security.
 *
 *  All input data is to be in little-endian (LE) format and the resulting
 *  hash values produced by these APIs are in LE format.
 *
 *  @anchor ti_SHA2_SW_LIBRARY_Synopsis
 *  ## Synopsis
 *
 *  The following is a quick overview of one-step hashing.
 *
 *  @anchor ti_SHA2_SW_LIBRARY_Synopsis_Code
 *  @code
 *  // Import SHA2 SW Driver definitions
 *  #include <sha2sw.h>
 *
 *  // Create an object and handle
 *  SHA2SW_Object sha2SWObject;
 *  SHA2SW_Handle sha2SWHandle = &sha2SWObject;
 *
 *  // Allocate space for digest output
 *  uint32_t actualDigest[8]; // If using SHA2 384 or 512, use 16 words.
 *
 *  result = SHA2SW_hashData(sha2SWHandle, SHA2SW_HASH_TYPE_256, message,
 *                           strlen(message), actualDigest);
 *  @endcode
 *
 *  <hr>
 *  @anchor ti_drivers_I2C_Examples
 *  # Examples
 *  @li @ref ti_SHA2_SW_LIBRARY_Example_hashData "Hashing data in one call"
 *  @li @ref ti_SHA2_SW_LIBRARY_Example_addData "Hashing data in multiple calls"
 *    ...
 *    ...
 *  @anchor ti_SHA2_SW_LIBRARY_Example_hashData
 *  ## Hashing data in one call
 *  @code
 *  SHA2SW_Object sha256SWObject;
 *  SHA2SW_Handle sha256SWHandle = &sha256SWObject;
 *  int_fast16_t sha2SWresult;
 *  uint32_t finalDigest[8];
 *  int notsame;
 *
 *  char message[] =
 *          "abcdefghijklmnabcdefghijklmnabcdefghijklmnabcdefghijklmn1234";
 *  uint8_t expectedDigest[] =
 *          { 0x60, 0x06, 0x00, 0x24, 0x13, 0xe4, 0x27, 0x0d,
 *            0x4d, 0xdb, 0x66, 0x93, 0x42, 0xa9, 0xe2, 0xdb,
 *            0x66, 0x5e, 0xc8, 0x70, 0x73, 0xc4, 0x2e, 0xb5,
 *            0x44, 0x99, 0x62, 0xf1, 0x2a, 0xb2, 0xe8, 0x60, };
 *
 *  sha2SWresult = SHA2SW_hashData(sha256SWHandle, SHA2SW_HASH_TYPE_256,
 *                                   message, strlen(message), finalDigest);
 *
 *  if (sha2SWresult != SHA2SW_STATUS_SUCCESS)
 *  {
 *      while(1);
 *  }
 *
 *  // NOTE: If expectedDigest is a secret value, a timing constant comparison
 *  // routine shall be used instead of memcmp.
 *  notsame = memcmp(finalDigest, expectedDigest, sizeof(finalDigest));
 *
 *  if (notsame)
 *  {
 *      while(1);
 *  }
 *  @endcode
 *
 *
 *  @anchor ti_SHA2_SW_LIBRARY_Example_addData
 *  ## Hashing data in multiple calls
 *  @code
 *  SHA2SW_Object sha256SWObject;
 *  SHA2SW_Handle sha256SWHandle = &sha2SWObject;
 *  int_fast16_t sha2SWresult;
 *  uint32_t finalDigest[8];
 *  int notsame;
 *
 *  char message[] =
 *          "abcdefghijklmnabcdefghijklmnabcdefghijklmnabcdefghijklmn1234";
 *  uint8_t expectedDigest[] =
 *          { 0x60, 0x06, 0x00, 0x24, 0x13, 0xe4, 0x27, 0x0d,
 *            0x4d, 0xdb, 0x66, 0x93, 0x42, 0xa9, 0xe2, 0xdb,
 *            0x66, 0x5e, 0xc8, 0x70, 0x73, 0xc4, 0x2e, 0xb5,
 *            0x44, 0x99, 0x62, 0xf1, 0x2a, 0xb2, 0xe8, 0x60, };
 *
 *
 *  sha2SWresult = SHA2SW_start(sha256SWHandle, SHA2SW_HASH_TYPE_256);
 *
 *  if (sha2SWresult == SHA2SW_STATUS_SUCCESS) {
 *      sha2SWresult = SHA2SW_addData(sha256SWHandle, message, 20);
 *  }
 *
 *  if (sha2SWresult == SHA2SW_STATUS_SUCCESS) {
 *      sha2SWresult = SHA2SW_addData(sha256SWHandle, &message[20], strlen(message) - 20);
 *  }
 *
 *  if (sha2SWresult == SHA2SW_STATUS_SUCCESS) {
 *      sha2SWresult = SHA2SW_finalize(sha256SWHandle, finalDigest);
 *  }
 *
 *  if (sha2SWresult != SHA2SW_STATUS_SUCCESS)
 *  {
 *      while(1);
 *  }
 *
 *  // NOTE: If expectedDigest is a secret value, a timing constant comparison
 *  // routine shall be used instead of memcmp.
 *  notsame = memcmp(finalDigest, expectedDigest, sizeof(finalDigest));
 *
 *  if (notsame)
 *  {
 *      while(1);
 *  }
 *  @endcode
 *
 *
 *  <hr>
 *  @anchor ti_SHA2_SW_LIBRARY_configuration
 *  # Configuration
 *
 *  See file @sa sha2sw_config.h for full configuration information.
 *
 *  If #SHA2SW_VALIDATE_INPUTS is not defined then:
 *  @li the caller is responsible for ensuring all inputs are valid, and
 *  @li the module's functions will only return #SHA2SW_STATUS_SUCCESS
 *
 */

#include <stddef.h>
#include <stdint.h>

#include <sha2sw_common.h>
#include <sha2sw_config.h>

/*!
 *  @brief SHA2SW Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct {
    uint32_t bitsProcessed;  // Only 2^32 bits (512 MiBytes) are supported
    union {
        struct {
            int8_t offsetWb;     // Byte offset into Ws, used to load message
            uint8_t numRounds;   // Number of 0-indexed rounds.
            uint8_t digestSize;  // Size of output digest.
            uint8_t reserved1;
        };
        uint32_t quickSettings;  // Combined settings used to make
                                 // initialization more efficient.
    };
    union {                    // Union used to avoid casting
        uint32_t digest32[8];  // Holds intermediate/final digest when
                               // numRounds is SHA2SW_224_OR_256_ROUNDS.
        uint64_t digest64[8];  // Holds intermediate/final digest when
                               // numRounds is SHA2SW_384_OR_512_ROUNDS.
    };
    union {                 // Union used to avoid casting
        uint32_t Ws32[16];  // Message schedule, indexed by (s & 0xF),
                            // where s = 64 - 1 - t, and t is NIST 180-4's
                            // message schedule index. Used when
                            // numRounds is SHA2SW_224_OR_256_ROUNDS.
        uint64_t Ws64[16];  // Message schedule, indexed by (s & 0xF),
                            // where s = 80 -1 - t, and t is NIST 180-4's
                            // message schedule index. Used when
                            // numRounds is SHA2SW_384_OR_512_ROUNDS.
    };

} SHA2SW_Object;

/*!
 *  @brief  A handle to a SHA2SW_Object.
 */
typedef SHA2SW_Object* SHA2SW_Handle;

/*!
 *  @brief  Performs a complete hash operation, producing a final digest
 *          for the data.
 *
 *  This function wraps #SHA2SW_start(), #SHA2SW_addData(), and
 *  #SHA2SW_finalize().
 *
 *  There is no need to call #SHA2SW_start() prior to calling this function.
 *
 *  The total length of data that can be hashed by this implementation
 *  is 512MiB (0x20000000 bytes.)
 *
 *  @param[in]  handle A #SHA2SW_Handle.
 *
 *  @param[in]  hashType The type of hash (256 or 224) to perform.
 *
 *  @param[in]  data data (message) to hash. May point to zero.
 *
 *  @param[in]  length the number of bytes (pointed to by @c data parameter)
 *              to add to the hash.
 *
 *  @param[out]  digest Output location for the final digest. Must be
 *               able to hold the full length of the digest size
 *               and be 32-bit aligned.
 *
 *  @retval #SHA2SW_STATUS_SUCCESS             The hash operation succeeded.
 *  @retval #SHA2SW_STATUS_ERROR               The hash operation failed.
 *  @retval #SHA2SW_STATUS_UNSUPPORTED         Requested Hash Type is unsupported.
 *  @retval #SHA2SW_STATUS_LENGTH_TOO_LARGE    The requested length of data to hash
 *                                             is more than the implementation
 *                                             supports.
 *  @retval #SHA2SW_STATUS_NULL_INPUT          One or more of the pointer inputs is
 *                                             NULL.
 *
 */
int_fast16_t SHA2SW_hashData(SHA2SW_Handle handle, SHA2SW_HashType hashType,
    const void* data, size_t length, uint32_t digest[16]);

/*!
 *  @brief  Initialize a SHA2SW_Handle, preparing for hashing data.
 *
 *  @param[in] handle A #SHA2SW_Handle.
 *
 *  @param[in] hashType The type of hash (256 or 224) to perform.
 *
 *  @retval #SHA2SW_STATUS_SUCCESS             The hash operation succeeded.
 *  @retval #SHA2SW_STATUS_UNSUPPORTED         Requested Hash Type is unsupported.
 *  @retval #SHA2SW_STATUS_NULL_INPUT          One or more of the pointer inputs is
 *                                             NULL.
 *
 *  @sa     #SHA2SW_addData()
 *  @sa     #SHA2SW_finalize()
 */
int_fast16_t SHA2SW_start(SHA2SW_Handle handle, SHA2SW_HashType hashType);

/*!
 *  @brief  Add data to a SHA2 operation.
 *
 *  Adds data to a hash operation. The @c handle must have been
 *  initialized by a call to SHA2SW_start first.
 *
 *  The total length of data that can be hashed by this implementation
 *  is 512MiB (0x20000000 bytes.)
 *
 *  After passing in all data to be hashed, call #SHA2SW_finalize()
 *  to obtain the final digest.
 *
 *  @pre    handle was previously passed to #SHA2SW_start().
 *
 *  @param[in]  handle A #SHA2SW_Handle.
 *
 *  @param[in]  data data (message) to add to the hash. May point to zero.
 *
 *  @param[in]  length the number of bytes (pointed to by @c data parameter)
 *              to add to the hash.
 *
 *  @retval #SHA2SW_STATUS_SUCCESS             The hash operation succeeded.
 *  @retval #SHA2SW_STATUS_LENGTH_TOO_LARGE    The requested length of data to hash
 *                                             is more than the implementation
 *                                             supports.
 *  @retval #SHA2SW_STATUS_NULL_INPUT          One or more of the pointer inputs is
 *                                             NULL.
 *
 *  @sa     #SHA2SW_start()
 *  @sa     #SHA2SW_finalize()
 */
int_fast16_t SHA2SW_addData(
    SHA2SW_Handle handle, const void* data, size_t length);

/*!
 *  @brief  Finalize a SHA2 operation, creating the final digest.
 *
 *  After calling this function, @c handle should not be used again
 *  until it has been reinitialized via a call to #SHA2SW_start().
 *
 *  @pre    handle was previously passed to #SHA2SW_start() and data to
 *          be hashed was passed to #SHA2SW_addData()
 *
 *  @param[in]  handle A #SHA2SW_Handle.
 *
 *  @param[out]  digest Output location for the final digest. Must be
 *               able to hold the full length of the selected digest
 *               size and be 32-bit aligned.
 *
 *  @retval #SHA2SW_STATUS_SUCCESS             The hash operation succeeded.
 *  @retval #SHA2SW_STATUS_NULL_INPUT          One or more of the pointer inputs is
 *                                             NULL.
 *
 *  @sa     #SHA2SW_start()
 *  @sa     #SHA2SW_addData()
 */
int_fast16_t SHA2SW_finalize(SHA2SW_Handle handle, uint32_t digest[16]);

/*!
 *  @brief  Cancels a SHA2 operation by clearing intermediate
 *          data stored in the handle.
 *
 *  @note   The handle will not be ready for a new operation
 *          until after #SHA2SW_start() is called on the handle.
 *
 *  @param[in]  handle A #SHA2SW_Handle.
 *
 *  @sa     #SHA2SW_start()
 */
void SHA2SW_cancel(SHA2SW_Handle handle);

#endif /* SHA2SW_H_ */
