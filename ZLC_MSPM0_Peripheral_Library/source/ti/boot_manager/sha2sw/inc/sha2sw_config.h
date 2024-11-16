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
#ifndef SHA2SW_CONFIG_H_
#define SHA2SW_CONFIG_H_

/** ============================================================================
 *  @file       sha2sw_config.h
 *
 *  @brief      Provides build-time configuration options for the SHA2 SW
 *              module.
 *
 */

/*!
*  @defgroup SHA2SW_ConfigOptions SHA2 SW Configuration Options
*
*  These macros enable various features and build configurations.
*  @{
*/
/*!
 * @brief   Include support for SHA2 224.
 *
 */
#if !defined(SHA2SW_SUPPORT_SHA2_224)
#define SHA2SW_SUPPORT_SHA2_224 (0)
#endif

/*!
 * @brief   Include support for SHA2 384.
 *
 */
#if !defined(SHA2SW_SUPPORT_SHA2_384)
#define SHA2SW_SUPPORT_SHA2_384 (0)
#endif

/*!
 * @brief   If defined, SHA2SW library will check inputs for invalid
 *          conditions. Otherwise, parameters will not be checked.
 *
 *  If #SHA2SW_VALIDATE_INPUTS is not defined then:
 *  @li the caller is responsible for ensuring all inputs are valid, and
 *  @li the module's functions will only return #SHA2SW_STATUS_SUCCESS
 *
 *
 *  Not defining this value will reduce code size.
 */
#if !defined(SHA2SW_VALIDATE_INPUTS)
#define SHA2SW_VALIDATE_INPUTS (0)
#endif

/*!
 * @brief   Use a faster implementation of the message schedule which is
 *          slightly larger in code size.
 *
 * Expected time savings of 2,600 cycles or more per input block. Code
 * size cost for enabling may be as little as 8 bytes.
 */
#if !defined(SHA2SW_FAST_MESSAGE_SCHEDULE)
#define SHA2SW_FAST_MESSAGE_SCHEDULE (1)
#endif

/*!
 * @brief   Use a faster implementation of the working variables a-h which is
 *          slightly larger in code size.
 *
 * Expected time savings of 750 cycles or more per input block. Code
 * size cost for enabling may be as little as 24 bytes.
 */
#if !defined(SHA2SW_FAST_WORKING_VARS)
#define SHA2SW_FAST_WORKING_VARS (1)
#endif

/*!
 * @brief   Use portions of the constants of the 512 algorithm to
 *          support the 256 and 224 algorithms.
 *
 * The initial hash values as well as the round constants (K) of
 * 512/384 are extensions of the values used for 256/224. Thus,
 * const data space can be saved by using the 512/384 constants
 * for the 256/224 algorithm. However, the 256/224 algorithm must
 * spend extra cycles to skip over unneeded constants.
 *
 * Expected savings of at least 288 bytes of const data at the cost
 * of a few bytes of code space and small change in performance.
 */
#if !defined(SHA2SW_USE_512_CONST_FOR_256)
#define SHA2SW_USE_512_CONST_FOR_256 (0)
#endif

/*!
 * @brief   Use Arm(R) C Language Extensions
 *
 * Use ARM(R) CLE to directly access op codes which can improve
 * code size and/or performance.
 */
#if !defined(SHA2SW_USE_ARMCLE)
#define SHA2SW_USE_ARMCLE (1)
#endif

/*! @}*/

#endif /* SHA2SW_CONFIG_H_ */
