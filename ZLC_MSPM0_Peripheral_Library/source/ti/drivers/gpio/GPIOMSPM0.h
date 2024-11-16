/*
 * Copyright (c) 2023, Texas Instruments Incorporated
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
 *  @file       GPIOMSPM0.h
 *
 *  @brief      GPIO driver implementation for MSPM0 devices.
 *
 *  @defgroup   GPIOMSPM0 GPIO driver APIs
 *
 *  # Overview
 *  Refer to @ref ti_drivers_GPIO_Overview for a complete description of the GPIO
 *  driver APIs provided and examples of their use.
 *
 *  The definitions in this file should not be used directly. All GPIO_CFG
 *  macros should be used as-is from GPIO.h.
 *
 *  There are no additional configuration values or platform-specific
 *  functions for GPIOMSPM0.
 ******************************************************************************
 */
/** @addtogroup GPIOMSPM0
 *  @ingroup GPIO
* @{
*/
#ifndef ti_drivers_GPIOMSPM0__include
#define ti_drivers_GPIOMSPM0__include

#include <ti/drivers/GPIO.h>

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */

/* We don't define this value on purpose - any unsupported values will cause a
 * compile-time error. If your compiler tells you that this macro is missing,
 * you are trying to use an unsupported option.
 *
 * See below for which options are unsupported.
 */
#undef GPIOMSPM0_CFG_OPTION_NOT_SUPPORTED

/*!
 * @brief  Medium drive strength is not available on MSPM0 devices.
 */
#define GPIO_CFG_DRVSTR_MED_INTERNAL       (GPIOMSPM0_CFG_OPTION_NOT_SUPPORTED)

/*!
 * @brief  Low value interrupts are not available on MSPM0 devices.
 */
#define GPIO_CFG_INT_LOW_INTERNAL          (GPIOMSPM0_CFG_OPTION_NOT_SUPPORTED)
/*!
 * @brief  High value interrupts are not available on MSPM0 devices.
 */
#define GPIO_CFG_INT_HIGH_INTERNAL         (GPIOMSPM0_CFG_OPTION_NOT_SUPPORTED)

/* clang-format on */

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_GPIOMSPM0__include */
/** @}*/
