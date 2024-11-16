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
 *  @file       dl_systick.h
 *  @brief      System Tick Timer (SysTick) Driver Library
 *  @defgroup   SYSTICK M0P System Tick Timer (SysTick)
 *
 *  @anchor ti_dl_m0p_dl_systick_Overview
 *  # Overview
 *
 *  SysTick is a simple timer that is part of the Cortex-M architecture. Its
 *  intended purpose is to provide a periodic interrupt for an RTOS, but it can
 *  be used for other simple timing purposes.
 *
 *  <hr>
 ******************************************************************************
 */
/** @addtogroup SYSTICK
 * @{
 */
#ifndef ti_dl_m0p_dl_systick__include
#define ti_dl_m0p_dl_systick__include

#include <stdbool.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */

/**
 *  @brief Redirects DL_SYSTICK_config to CMSIS standard SysTick_Config
 */
#define DL_SYSTICK_config(x)                                   SysTick_Config(x)

/* clang-format on */

/**
 *  @brief     Initializes the System Tick Timer (SysTick)
 *
 *  Initializes the System Tick Timer by configuring the desired period. Resets
 *  the counter so that, once enabled, the SysTick starts counting from 0. Does
 *  not start the timer or enable the interrupt.
 *
 *  @param[in] period       The period in ticks for the SysTick to fire. Value
 *                          between 0x00000002 - 0x01000000.
 */
__STATIC_INLINE void DL_SYSTICK_init(uint32_t period)
{
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk;
    SysTick->LOAD = period - (uint32_t) 1;
    SysTick->VAL  = 0;
}

/**
 *  @brief     Set the period for the SysTick
 *
 *  Calling this function does not cause the SysTick counter to reload
 *  immediately. If you want to change the period and reset the counter use
 *  the @ref DL_SYSTICK_init function or @ref DL_SYSTICK_resetValue.
 *
 *  @param[in] period  The period in ticks for the SysTick to fire. Value
 *                     between 0x00000002 - 0x01000000.
 */
__STATIC_INLINE void DL_SYSTICK_setPeriod(uint32_t period)
{
    SysTick->LOAD = period - (uint32_t) 1;
}

/**
 *  @brief  Reset the current value of the SysTick
 *
 *  Resets the current value of the SysTick back to 0, essentially resetting
 *  the period.
 */
__STATIC_INLINE void DL_SYSTICK_resetValue(void)
{
    SysTick->VAL = 0;
}

/**
 *  @brief   Get the period for the SysTick
 *
 *  @return  The period in ticks for the SysTick to fire
 *
 *  @retval  Value between 0x00000002 - 0x01000000.
 */
__STATIC_INLINE uint32_t DL_SYSTICK_getPeriod(void)
{
    return (SysTick->LOAD + (uint32_t) 1);
}

/**
 *  @brief   Get the current value of SysTick counter
 *
 *  @return  The current value of the counter in ticks
 *
 *  @retval  Value between 0x00000000 - 0x00FFFFFF.
 */
__STATIC_INLINE uint32_t DL_SYSTICK_getValue(void)
{
    return SysTick->VAL;
}

/**
 *  @brief  Enable the SysTick interrupt
 */
__STATIC_INLINE void DL_SYSTICK_enableInterrupt(void)
{
    SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
}

/**
 *  @brief  Disable the SysTick interrupt
 */
__STATIC_INLINE void DL_SYSTICK_disableInterrupt(void)
{
    SysTick->CTRL &= ~(SysTick_CTRL_TICKINT_Msk);
}

/**
 *  @brief  Enable the SysTick, starts counting once enabled
 *
 *  Once enabled, the SysTick will start counting from whatever value it was
 *  disabled with. To ensure a full period, use @ref DL_SYSTICK_init
 *  or @ref DL_SYSTICK_resetValue before enabling.
 */
__STATIC_INLINE void DL_SYSTICK_enable(void)
{
    SysTick->CTRL |= (SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk);
}

/**
 *  @brief  Disable the SysTick, stops counting once disabled
 */
__STATIC_INLINE void DL_SYSTICK_disable(void)
{
    SysTick->CTRL &= ~(SysTick_CTRL_ENABLE_Msk);
}

/**
 *  @brief   Checks if the SysTick is enabled
 *
 *  @return  Returns the enabled status of the SysTick
 *
 *  @retval  true  The SysTick is enabled and counting
 *  @retval  false The SysTick is disabled and not counting
 */
__STATIC_INLINE bool DL_SYSTICK_isEnabled(void)
{
    return (
        (SysTick->CTRL & SysTick_CTRL_ENABLE_Msk) == SysTick_CTRL_ENABLE_Msk);
}

#ifdef __cplusplus
}
#endif

#endif /* ti_dl_m0p_dl_systick__include */
/** @}*/
