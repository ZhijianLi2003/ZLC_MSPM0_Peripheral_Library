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
 *  @file       dl_gpamp.h
 *  @brief      General Purpose Amplifier (GPAMP)
 *  @defgroup   GPAMP General Purpose Amplifier (GPAMP)
 *
 ******************************************************************************
 */
/** @addtogroup GPAMP
 * @{
 */
#ifndef ti_dl_m0p_dl_gpamp__include
#define ti_dl_m0p_dl_gpamp__include

#include <stdbool.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/dl_common.h>

#ifdef __MSPM0_HAS_GPAMP__

#ifdef __cplusplus
extern "C" {
#endif

/*! @enum DL_GPAMP_NSEL */
typedef enum {
    /*! Inverting input channel is the output pin */
    DL_GPAMP_NSEL_OUTPUT_PIN = SYSCTL_PMUOPAMP_NSEL_SEL0,
    /*! Inverting input channel is the IN- pin */
    DL_GPAMP_NSEL_IN_NEG = SYSCTL_PMUOPAMP_NSEL_SEL1,
    /*! Inverting input channel is  internal GPAMP output */
    DL_GPAMP_NSEL_INTERNAL_OUTPUT = SYSCTL_PMUOPAMP_NSEL_SEL2,
    /*! No channel selected for the inverting input channel */
    DL_GPAMP_NSEL_OPEN = SYSCTL_PMUOPAMP_NSEL_SEL3,
} DL_GPAMP_NSEL;

/*! @enum DL_GPAMP_PSEL */
typedef enum {
    /*! Non-Inverting input channel is disabled */
    DL_GPAMP_PSEL_OPEN = SYSCTL_PMUOPAMP_PCHENABLE_FALSE,
    /*! Non-Inverting input channel is enabled */
    DL_GPAMP_PSEL_IN_POS = SYSCTL_PMUOPAMP_PCHENABLE_TRUE,
} DL_GPAMP_PSEL;

/*! @enum DL_GPAMP_OUTPUT_PIN_STATE */
typedef enum {
    /*! Output pin is disabled */
    DL_GPAMP_OUTPUT_PIN_STATE_DISABLED = SYSCTL_PMUOPAMP_OUTENABLE_FALSE,
    /*! Output pin is enabled */
    DL_GPAMP_OUTPUT_PIN_STATE_ENABLED = SYSCTL_PMUOPAMP_OUTENABLE_TRUE,
} DL_GPAMP_OUTPUT_PIN_STATE;

/*! @enum DL_GPAMP_RRI_MODE */
typedef enum {
    /*! RRI mode is PMOS input pairs mode */
    DL_GPAMP_RRI_MODE_PMOS_INPUT = SYSCTL_PMUOPAMP_RRI_MODE0,
    /*! RRI mode is NMOS input pairs */
    DL_GPAMP_RRI_MODE_NMOS_INPUT = SYSCTL_PMUOPAMP_RRI_MODE1,
    /*! RRI mode is rail to rail*/
    DL_GPAMP_RRI_MODE_RAIL_TO_RAIL = SYSCTL_PMUOPAMP_RRI_MODE2,
    /*! RRI mode is sample channel 0*/
    DL_GPAMP_RRI_MODE_SAMPLE_CHANNEL_0 = SYSCTL_PMUOPAMP_RRI_MODE3,

} DL_GPAMP_RRI_MODE;

/*! @enum DL_GPAMP_CHOPPING_FREQ */
typedef enum {
    /*! Chopping clock frequency is 16KHZ */
    DL_GPAMP_CHOPPING_FREQ_16KHZ = SYSCTL_PMUOPAMP_CHOPCLKFREQ_CLK16KHZ,
    /*! Chopping clock frequency is 8KHZ */
    DL_GPAMP_CHOPPING_FREQ_8KHZ = SYSCTL_PMUOPAMP_CHOPCLKFREQ_CLK8KHZ,
    /*! Chopping clock frequency is 4KHZ */
    DL_GPAMP_CHOPPING_FREQ_4KHZ = SYSCTL_PMUOPAMP_CHOPCLKFREQ_CLK4KHZ,
    /*! Chopping clock frequency is 2KHZ */
    DL_GPAMP_CHOPPING_FREQ_2KHZ = SYSCTL_PMUOPAMP_CHOPCLKFREQ_CLK2KHZ,
} DL_GPAMP_CHOPPING_FREQ;

/*! @enum DL_GPAMP_CHOPPING_MODE */
typedef enum {
    /*! Chopping is disabled */
    DL_GPAMP_CHOPPING_MODE_DISABLED = SYSCTL_PMUOPAMP_CHOPCLKMODE_CHOPDISABLED,
    /*! Chopping mode is standard chop */
    DL_GPAMP_CHOPPING_MODE_STANDARD = SYSCTL_PMUOPAMP_CHOPCLKMODE_REGCHOP,
    /*! Chopping mode is ADC assisted chop */
    DL_GPAMP_CHOPPING_MODE_ADC_ASSISTED =
        SYSCTL_PMUOPAMP_CHOPCLKMODE_ADCASSIST,
} DL_GPAMP_CHOPPING_MODE;

/*!
 *  @brief  Configuration struct for @ref DL_GPAMP_init
 */
typedef struct {
    /*! The chopping mode to set. One of @ref DL_GPAMP_CHOPPING_MODE */
    DL_GPAMP_CHOPPING_MODE choppingMode;
    /*! The chopping frequency to set. One of @ref DL_GPAMP_CHOPPING_FREQ */
    DL_GPAMP_CHOPPING_FREQ choppingFreq;
    /*! The state of the output pin. One of @ref DL_GPAMP_OUTPUT_PIN_STATE. */
    DL_GPAMP_OUTPUT_PIN_STATE outputPinState;
    /*! The non-inverting input channel to set. One of @ref DL_GPAMP_PSEL */
    DL_GPAMP_PSEL pselChannel;
    /*! The inverting input channel to set. One of @ref DL_GPAMP_NSEL */
    DL_GPAMP_NSEL nselChannel;
} DL_GPAMP_Config;

/* clang-format on */

/**
 *  @brief      Enable the GPAMP peripheral
 */
__STATIC_INLINE void DL_GPAMP_enable(void)
{
    SYSCTL->SOCLOCK.PMUOPAMP |= SYSCTL_PMUOPAMP_ENABLE_TRUE;
}

/**
 *  @brief      Checks if the GPAMP peripheral is enabled
 *
 *  @return     Returns the enabled status of the GPAMP
 *
 *  @retval     true  The GPAMP peripheral is enabled
 *  @retval     false The GPAMP peripheral is disabled
 */
__STATIC_INLINE bool DL_GPAMP_isEnabled(void)
{
    return ((SYSCTL->SOCLOCK.PMUOPAMP & SYSCTL_PMUOPAMP_ENABLE_MASK) ==
            SYSCTL_PMUOPAMP_ENABLE_TRUE);
}

/**
 *  @brief      Disable the GPAMP peripheral
 */
__STATIC_INLINE void DL_GPAMP_disable(void)
{
    SYSCTL->SOCLOCK.PMUOPAMP &= ~(SYSCTL_PMUOPAMP_ENABLE_MASK);
}

/**
 *  @brief      Initialize the GPAmp peripheral
 *
 *  Initializes all the common configurable options for the GPAmp peripheral.
 *  Any other custom configuration can be done after calling this API.
 *  The GPAmp is not enabled in this API.
 *
 *  @param[in]  config  Configuration for gpamp peripheral
 */
__STATIC_INLINE void DL_GPAMP_init(DL_GPAMP_Config *config)
{
    DL_Common_updateReg(&SYSCTL->SOCLOCK.PMUOPAMP,
        (uint32_t) config->choppingMode | (uint32_t) config->choppingFreq |
            (uint32_t) config->outputPinState |
            (uint32_t) config->pselChannel | (uint32_t) config->nselChannel,
        SYSCTL_PMUOPAMP_CHOPCLKMODE_MASK | SYSCTL_PMUOPAMP_CHOPCLKFREQ_MASK |
            SYSCTL_PMUOPAMP_OUTENABLE_MASK | SYSCTL_PMUOPAMP_PCHENABLE_MASK |
            SYSCTL_PMUOPAMP_NSEL_MASK);
}

/**
 *  @brief      Enable the non-inverting input channel
 */
__STATIC_INLINE void DL_GPAMP_enableNonInvertingInputChannel(void)
{
    SYSCTL->SOCLOCK.PMUOPAMP |= SYSCTL_PMUOPAMP_PCHENABLE_TRUE;
}

/**
 *  @brief      Checks if the non-inverting input channel is enabled
 *
 *  @return     Returns the enabled status of the GPAMP
 *
 *  @retval     true  The non-inverting input channel is enabled
 *  @retval     false The non-inverting input channel is disabled
 */
__STATIC_INLINE bool DL_GPAMP_isNonInvertingInputChannelEnabled(void)
{
    return ((SYSCTL->SOCLOCK.PMUOPAMP & SYSCTL_PMUOPAMP_PCHENABLE_MASK) ==
            SYSCTL_PMUOPAMP_PCHENABLE_TRUE);
}

/**
 *  @brief      Disable the non-inverting input channel
 */
__STATIC_INLINE void DL_GPAMP_disableNonInvertingInputChannel(void)
{
    SYSCTL->SOCLOCK.PMUOPAMP &= ~(SYSCTL_PMUOPAMP_PCHENABLE_MASK);
}

/**
 *  @brief      Set the inverting input channel
 *
 *  @param[in]  inputChannel  The inverting input channel to set.
 *                            One of @ref DL_GPAMP_NSEL.
 */
__STATIC_INLINE void DL_GPAMP_setInvertingInputChannel(
    DL_GPAMP_NSEL inputChannel)
{
    DL_Common_updateReg(&SYSCTL->SOCLOCK.PMUOPAMP, (uint32_t) inputChannel,
        SYSCTL_PMUOPAMP_NSEL_MASK);
}

/**
 *  @brief      Get the inverting input channel
 *
 *  @return     The current inverting input channel
 *
 *  @retval     One of @ref DL_GPAMP_NSEL
 */
__STATIC_INLINE DL_GPAMP_NSEL DL_GPAMP_getInvertingInputChannel(void)
{
    uint32_t nsel = (SYSCTL->SOCLOCK.PMUOPAMP & SYSCTL_PMUOPAMP_NSEL_MASK);

    return (DL_GPAMP_NSEL)(nsel);
}

/**
 *  @brief      Set the rail-to-rail input (RRI) mode
 *
 *  @param[in]  mode  The RRI mode to set. One of @ref DL_GPAMP_RRI_MODE.
 */
__STATIC_INLINE void DL_GPAMP_setRailToRailInputMode(DL_GPAMP_RRI_MODE mode)
{
    DL_Common_updateReg(
        &SYSCTL->SOCLOCK.PMUOPAMP, (uint32_t) mode, SYSCTL_PMUOPAMP_RRI_MASK);
}

/**
 *  @brief      Get the rail-to-rail input (RRI) mode
 *
 *  @return     The current RRI mode
 *
 *  @retval     One of @ref DL_GPAMP_RRI_MODE
 */
__STATIC_INLINE DL_GPAMP_RRI_MODE DL_GPAMP_getRailToRailInputMode(void)
{
    uint32_t mode = (SYSCTL->SOCLOCK.PMUOPAMP & SYSCTL_PMUOPAMP_RRI_MASK);

    return (DL_GPAMP_RRI_MODE)(mode);
}

/**
 *  @brief      Enable output to pad
 */
__STATIC_INLINE void DL_GPAMP_enableOutputToPad(void)
{
    SYSCTL->SOCLOCK.PMUOPAMP |= SYSCTL_PMUOPAMP_OUTENABLE_TRUE;
}

/**
 *  @brief      Checks if output to pad is enabled
 *
 *  @return     Returns if output to pad is enabled
 *
 *  @retval     true  Output to pad is enabled
 *  @retval     false Output to pad is disabled
 */
__STATIC_INLINE bool DL_GPAMP_isOutputToPadEnabled(void)
{
    return ((SYSCTL->SOCLOCK.PMUOPAMP & SYSCTL_PMUOPAMP_OUTENABLE_MASK) ==
            SYSCTL_PMUOPAMP_OUTENABLE_TRUE);
}

/**
 *  @brief      Disable output to pad
 */
__STATIC_INLINE void DL_GPAMP_disableOutputToPad(void)
{
    SYSCTL->SOCLOCK.PMUOPAMP &= ~(SYSCTL_PMUOPAMP_OUTENABLE_MASK);
}

/**
 *  @brief      Set the chopping clock frequency
 *
 *  @param[in]  frequency  The chopping frequency to set.
 *                         One of @ref DL_GPAMP_CHOPPING_FREQ
 */
__STATIC_INLINE void DL_GPAMP_setChoppingFrequency(
    DL_GPAMP_CHOPPING_FREQ frequency)
{
    DL_Common_updateReg(&SYSCTL->SOCLOCK.PMUOPAMP, (uint32_t) frequency,
        SYSCTL_PMUOPAMP_CHOPCLKFREQ_MASK);
}

/**
 *  @brief      Get the chopping clock frequency
 *
 *  @return     The current chopping frequency
 *
 *  @retval     One of @ref DL_GPAMP_CHOPPING_FREQ
 */
__STATIC_INLINE DL_GPAMP_CHOPPING_FREQ DL_GPAMP_getChoppingFrequency(void)
{
    uint32_t freq =
        (SYSCTL->SOCLOCK.PMUOPAMP & SYSCTL_PMUOPAMP_CHOPCLKFREQ_MASK);

    return (DL_GPAMP_CHOPPING_FREQ)(freq);
}

/**
 *  @brief      Set the chopping mode
 *
 *  @param[in]  mode  The chopping mode to set.
 *                         One of @ref DL_GPAMP_CHOPPING_MODE
 */
__STATIC_INLINE void DL_GPAMP_setChoppingMode(DL_GPAMP_CHOPPING_MODE mode)
{
    DL_Common_updateReg(&SYSCTL->SOCLOCK.PMUOPAMP, (uint32_t) mode,
        SYSCTL_PMUOPAMP_CHOPCLKMODE_MASK);
}

/**
 *  @brief      Get the chopping mode
 *
 *  @return     The current chopping mode
 *
 *  @retval     One of @ref DL_GPAMP_CHOPPING_MODE
 */
__STATIC_INLINE DL_GPAMP_CHOPPING_MODE DL_GPAMP_getChoppingMode(void)
{
    uint32_t mode =
        (SYSCTL->SOCLOCK.PMUOPAMP & SYSCTL_PMUOPAMP_CHOPCLKMODE_MASK);

    return (DL_GPAMP_CHOPPING_MODE)(mode);
}

/* clang-format on */

#ifdef __cplusplus
}
#endif

#endif /* __MSPM0_HAS_GPAMP__ */

#endif /* ti_dl_m0p_dl_gpamp__include */
/** @}*/
