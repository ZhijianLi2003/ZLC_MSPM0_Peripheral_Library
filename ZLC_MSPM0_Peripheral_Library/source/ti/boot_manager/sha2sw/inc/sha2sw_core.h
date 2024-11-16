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
#ifndef SHA2SW_CORE_H_
#define SHA2SW_CORE_H_

/** ============================================================================
 *  @file       sha2sw_core.h
 *
 *  @brief      Core routines and constants common to all SHA 2 variants.
 *
 *  @note       Support for a particular SHA2 algorithm depends on the build
 *              build configuration set in sha2sw_config.h.
 *
 *  @note       Does not include padding routines.
 */

#include <stdint.h>

#include <sha2sw_config.h>

#if defined(__IAR_SYSTEMS_ICC__)
#include <intrinsics.h>
#endif

#if SHA2SW_USE_ARMCLE == 1
#include <arm_acle.h>
#endif

/*** SHA2 Algorithm Macros *******************************/

/*!
 * @brief   Shift right Function - shift x by a
 *
 */
#define SHR(x, a) ((x) >> (a))

/*!
 * @brief   CH function from NIST FIPS 180-4, Eq 4.8.
 *
 * Implementation is refactored for efficiency.
 *
 */
#define CH(x, y, z) (((x) & ((y) ^ (z))) ^ (z))

/*!
 * @brief   MAJ function from NIST FIPS 180-4, Eq 4.9.
 *
 * Implementation is refactored for efficiency.
 *
 */
#define MAJ(x, y, z) ((((y) ^ (z)) & (x)) ^ ((y) & (z)))

#if SHA2SW_USE_ARMCLE == 1
/*!
 * @brief 32 bit reverse function (BE->LE, LE->BE).
 *
 * Implemented using intrinsic from ARM(R) CLE.
 */
#define REV32(in) __rev((in))

#elif defined(__IAR_SYSTEMS_ICC__)
/*!
 * @brief 32 bit reverse function (BE->LE, LE->BE).
 *
 * Implemented using IAR(R) intrinsic.
 */
#define REV32(in) __REV((in))
#else
/*!
 * @brief 32 bit reverse function (BE->LE, LE->BE).
 *
 * Implemented using shifts and bitwise OR
 */
#define REV32(in)                                             \
    ((((in) &0x000000FF) << 24) | (((in) &0x0000FF00) << 8) | \
        (((in) &0x00FF0000) >> 8) | (((in) &0xFF000000) >> 24))
#endif

#endif /* SHA2SW_CORE_H_ */
