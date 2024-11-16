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
#ifndef SHA256SW_CORE_H_
#define SHA256SW_CORE_H_

/** ============================================================================
 *  @file       sha256sw_core.h
 *
 *  @brief      Core routines and constants for SHA2 256/224 SW implementation.
 *
 *  @note       Does not include padding routines.
 */

#include <stdint.h>

#include <sha2sw_config.h>
#include <sha2sw_core.h>

#if defined(__IAR_SYSTEMS_ICC__)
#include <intrinsics.h>
#endif

#if SHA2SW_USE_ARMCLE == 1
#include <arm_acle.h>
#endif

/*!
 *
 *  @brief Initial digest value for SHA2 256.
 *
 */
extern const uint32_t SHA256SW_initialDigest256[8];

#if SHA2SW_SUPPORT_SHA2_224 == 1
/*!
 *
 *  @brief Initial digest value for SHA2 224.
 *
 */
extern const uint32_t SHA256SW_initialDigest224[8];
#endif

/*!
 *  @brief   Performs core SHA2 224/256 algorithm on one 512 bit block of data.
 *
 *  @post    object->digest contains updated BE digest resulting from
 *           hashing the block.
 *
 *  @param[in,out]  digest preloaded with previous block's digest (or initial
 *                  digest if call is to process first block) in BE format.
 *                  On function return, digest will hold the updated BE digest.
 *
 *  @param[in] Ws loaded with block in BE format, including padding as
 *             specified by the SHA2 standard. First word of block to be
 *             in Ws[15], last word of block to be in Ws[0].
 */
void SHA256SW_processBlock(uint32_t digest[8], uint32_t Ws[16]);

#endif /* SHA256SW_CORE_H_ */
