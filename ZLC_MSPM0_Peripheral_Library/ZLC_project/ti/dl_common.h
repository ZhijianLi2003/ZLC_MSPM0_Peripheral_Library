/*
 * Copyright (c) 2020, Texas Instruments Incorporated
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
/*!****************************************************************************
 *  @file       dl_common.h
 *  @brief      DriverLib Common APIs
 *  @defgroup   DLCommon DriverLib Common APIs
 *
 *  @anchor ti_dl_dl_common_Overview
 *  # Overview
 *
 *  APIs used across multiple DriverLib modules
 *
 *  <hr>
 ******************************************************************************/
/** @addtogroup DLCommon
 * @{
 */
#ifndef ti_dl_dl_common__include
#define ti_dl_dl_common__include

#include <ti/devices/msp/msp.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Writes value to specified register - retaining bits unaffected by mask.
 *
 * @param[in] reg     Pointer to the register overlay for the peripheral.
 * @param[in] val     Value to be written to the register.
 * @param[in] mask    Mask defines which bits will be altered.
 */
__STATIC_INLINE void DL_Common_updateReg(
    volatile uint32_t *reg, uint32_t val, uint32_t mask)
{
    uint32_t tmp;

    tmp  = *reg;
    tmp  = tmp & ~mask;
    *reg = tmp | (val & mask);
}

/**
 * @brief   Consumes the number of CPU cycles specified.
 *
 * @param[in] cycles  Floor number of cycles to delay.
 *                    Specifying zero will result in the maximum
 *                    possible delay. Note that guarantees at least
 *                    this number of cycles will be delayed,
 *                    not that exactly this number of cycles will be
 *                    delayed. If a more precise number of cycle delay value
 *                    is needed, GPTimer is recommended.
 *
 *                    Typical variance from this function is 10 cycles or
 *                    less assuming that the function is located in flash and
 *                    that caching is enabled. Disabling caching may result in
 *                    wait-states when fetching from flash.
 *                    Other variance occurs due:
 *                      - Amount of register stacking/unstacking around API entry/exit
 *                      - Value of cycles relative to 4-cycle loop counter
 *                      - Placement of code on a 2- or 4-byte aligned boundary
 */
void DL_Common_delayCycles(uint32_t cycles);

#ifdef __cplusplus
}
#endif

#endif /* ti_dl_dl_common__include */
/** @}*/
