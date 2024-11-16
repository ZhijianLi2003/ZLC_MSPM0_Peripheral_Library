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
 *  @file       dl_vref.h
 *  @brief      Voltage Reference (VREF) Driver Library
 *  @defgroup   VREF Voltage Reference (VREF)
 *
 *  @anchor ti_dl_dl_vref_Overview
 *  # Overview
 *
 *  The Voltage Reference Driver Library allows full configuration of
 *  the MSPM0 VREF module.
 *  The VREF module contains a configurable voltage reference buffer which
 *  allows users to supply a stable internal reference to on-board analog
 *  peripherals. It also supports bringing in an external reference for
 *  applications where higher accuracy is required.
 *
 *  <hr>
 ******************************************************************************
 */
/** @addtogroup VREF
 * @{
 */
#ifndef ti_dl_dl_m0p_vref__include
#define ti_dl_dl_m0p_vref__include

#include <stdbool.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/dl_common.h>

#ifdef __MSPM0_HAS_VREF__

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */

/** @addtogroup DL_VREF_CTL1_READY
 * @{
 */

/*!
* @brief VREF bit in CTL1 indicating the module is ready is not set
*/
#define DL_VREF_CTL1_READY_NOTRDY    (VREF_CTL1_READY_NOTRDY)

/*!
* @brief VREF bit in CTL1 indicating the module is ready is set
*/
#define DL_VREF_CTL1_READY_RDY    (VREF_CTL1_READY_RDY)


/** @}*/

/** @addtogroup DL_VREF_SH
 * @{
 */

/*!
* @brief Minimum value for VREF sample and hold, if enabled
*/
#define DL_VREF_SH_MIN             (VREF_CTL2_SHCYCLE_MINIMUM)

/*!
* @brief Maximum value for VREF sample and hold, if enabled
*/
#define DL_VREF_SH_MAX             (VREF_CTL2_SHCYCLE_MAXIMUM)

/** @}*/

/** @addtogroup DL_VREF_HOLD
 * @{
 */

/*!
* @brief Minimum value for VREF hold, if enabled
*/
#define DL_VREF_HOLD_MIN             (VREF_CTL2_HCYCLE_MINIMUM)

/*!
* @brief Maximum value for VREF hold, if enabled
*/
#define DL_VREF_HOLD_MAX             (VREF_CTL2_HCYCLE_MAXIMUM)

/** @}*/

/* clang-format on */

/*! @enum DL_VREF_CLOCK */
typedef enum {
    /*! Set VREF clock source as LFCLK  */
    DL_VREF_CLOCK_LFCLK = VREF_CLKSEL_LFCLK_SEL_MASK,
    /*! Set VREF clock source as MFCLK  */
    DL_VREF_CLOCK_MFCLK = VREF_CLKSEL_MFCLK_SEL_MASK,
    /*! Set VREF clock source as BUSCLK  */
    DL_VREF_CLOCK_BUSCLK = VREF_CLKSEL_BUSCLK_SEL_MASK,
} DL_VREF_CLOCK;

/*! @enum DL_VREF_CLOCK_DIVIDE */
typedef enum {
    /*! Clock divide by 1 */
    DL_VREF_CLOCK_DIVIDE_1 = 0,
    /*! Clock divide by 2 */
    DL_VREF_CLOCK_DIVIDE_2 = 1,
    /*! Clock divide by 4 */
    DL_VREF_CLOCK_DIVIDE_4 = 3,
    /*! Clock divide by 6 */
    DL_VREF_CLOCK_DIVIDE_6 = 5,
    /*! Clock divide by 8 */
    DL_VREF_CLOCK_DIVIDE_8 = 7,
} DL_VREF_CLOCK_DIVIDE;

/*! @enum DL_VREF_ENABLE */
typedef enum {
    /*! VREF control set disabled */
    DL_VREF_ENABLE_DISABLE = VREF_CTL0_ENABLE_DISABLE,
    /*! VREF control set enabled */
    DL_VREF_ENABLE_ENABLE = VREF_CTL0_ENABLE_ENABLE,
} DL_VREF_ENABLE;

/*! @enum DL_VREF_BUFCONFIG */
typedef enum {
    /*! Configure VREF output buffer to 2.5V */
    DL_VREF_BUFCONFIG_OUTPUT_2_5V = VREF_CTL0_BUFCONFIG_OUTPUT2P5V,
    /*! Configure VREF output buffer to 1.4V */
    DL_VREF_BUFCONFIG_OUTPUT_1_4V = VREF_CTL0_BUFCONFIG_OUTPUT1P4V,
} DL_VREF_BUFCONFIG;

/*! @enum DL_VREF_SHMODE */
typedef enum {
    /*! Set VREF sample and hold mode to disabled */
    DL_VREF_SHMODE_DISABLE = VREF_CTL0_SHMODE_DISABLE,
    /*! Set VREF sample and hold mode to enabled */
    DL_VREF_SHMODE_ENABLE = VREF_CTL0_SHMODE_ENABLE,
} DL_VREF_SHMODE;

/*!
 *  @brief  Configuration struct for @ref DL_VREF_setClockConfig.
 */
typedef struct {
    /*! Selects VREF module clock source @ref DL_VREF_CLOCK */
    DL_VREF_CLOCK clockSel;
    /*! Selects the divide ratio. One of @ref DL_VREF_CLOCK_DIVIDE */
    DL_VREF_CLOCK_DIVIDE divideRatio;
} DL_VREF_ClockConfig;

/**
 * @brief Configuration struct for @ref DL_VREF_Config.
 */
typedef struct {
    /*! VREF enable setting. Either @ref DL_VREF_ENABLE_DISABLE or @ref DL_VREF_ENABLE_ENABLE */
    DL_VREF_ENABLE vrefEnable;
    /*! VREF buffer configuration setting. Either @ref DL_VREF_BUFCONFIG_OUTPUT_1_4V or @ref DL_VREF_BUFCONFIG_OUTPUT_2_5V */
    DL_VREF_BUFCONFIG bufConfig;
    /*! VREF sample and hold enable configuration setting. Either @ref DL_VREF_SHMODE_DISABLE or @ref DL_VREF_SHMODE_ENABLE */
    DL_VREF_SHMODE shModeEnable;
    /*! Number of cycles to sample and hold for, if sample and hold mode is enabled. Minimum @ref DL_VREF_SH_MAX, maximum @ref DL_VREF_SH_MAX */
    uint32_t shCycleCount;
    /*! Number of cycles to hold for, if sample and hold mode is enabled. Minimum @ref DL_VREF_HOLD_MAX, maximum @ref DL_VREF_HOLD_MIN */
    uint32_t holdCycleCount;
} DL_VREF_Config;

/**
 * @brief Enables power on VREF module
 *
 * @param vref       Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_VREF_enablePower(VREF_Regs *vref)
{
    vref->GPRCM.PWREN = VREF_PWREN_KEY_UNLOCK_W | VREF_PWREN_ENABLE_ENABLE;
}

/**
 * @brief Disable power on VREF module
 *
 * @param vref       Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_VREF_disablePower(VREF_Regs *vref)
{
    vref->GPRCM.PWREN = VREF_PWREN_KEY_UNLOCK_W | VREF_PWREN_ENABLE_DISABLE;
}

/**
 *  @brief      Enables Internal VREF
 *
 *  This function only enables the internal VREF but doesn't configure all
 *  settings. It's recommended to use @ref DL_VREF_configReference to configure
 *  and enable VREF with all parameters.
 *
 *  @param vref       Pointer to the register overlay for the peripheral
 *
 */
__STATIC_INLINE void DL_VREF_enableInternalRef(VREF_Regs *vref)
{
    vref->CTL0 |= VREF_CTL0_ENABLE_ENABLE;
}

/**
 *  @brief      Disables Internal VREF, allows for External VREF
 *
 *  The internal VREF must be disabled when using external VREF input.
 *
 *  @param vref       Pointer to the register overlay for the peripheral
 *
 */
__STATIC_INLINE void DL_VREF_disableInternalRef(VREF_Regs *vref)
{
    vref->CTL0 &= ~VREF_CTL0_ENABLE_MASK;
}

/**
 *  @brief      Checks if the internal VREF is enabled
 *
 *  @param vref       Pointer to the register overlay for the peripheral
 *
 *  @return     Returns the enabled status of the vref peripheral
 *
 *  @retval     true  The internal VREF is enabled
 *  @retval     false The internal VREF is disabled, external VREF can be used
 */
__STATIC_INLINE bool DL_VREF_isEnabled(VREF_Regs *vref)
{
    return ((vref->CTL0 & VREF_CTL0_ENABLE_MASK) == VREF_CTL0_ENABLE_ENABLE);
}

#if (DeviceFamily_PARENT == DeviceFamily_PARENT_MSPM0L122X_L222X)
/**
 *  @brief      Enable VREF buffer as internal reference input for comparator
 *
 * @param vref       Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_VREF_enableInternalRefCOMP(VREF_Regs *vref)
{
    vref->CTL0 |= VREF_CTL0_COMP_VREF_ENABLE_ENABLE;
}

/**
 *  @brief      Checks if VREF buffer for comparator is enabled
 *
 * @param vref       Pointer to the register overlay for the peripheral
 *
 *  @return     Returns if VREF buffer for comparator is enabled
 *
 *  @retval     true  VREF buffer for comparator is enabled
 *  @retval     false VREF buffer for comparator is disabled
 */
__STATIC_INLINE bool DL_VREF_isInternalRefCOMPEnabled(VREF_Regs *vref)
{
    return ((vref->CTL0 & VREF_CTL0_COMP_VREF_ENABLE_MASK) ==
            VREF_CTL0_COMP_VREF_ENABLE_ENABLE);
}

/**
 *  @brief      Disable VREF buffer as internal reference input for comparator
 *
 * @param vref       Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_VREF_disableInternalRefCOMP(VREF_Regs *vref)
{
    vref->CTL0 &= ~(VREF_CTL0_COMP_VREF_ENABLE_MASK);
}
#endif

/**
 * @brief Set the clock select and clock divide fields in VREF
 *
 * @param vref       Pointer to the register overlay for the peripheral
 *
 * @param config     Pointer to the configuration structure
 */
void DL_VREF_setClockConfig(VREF_Regs *vref, DL_VREF_ClockConfig *config);

/**
 * @brief Copy the clock select and clock divide fields in VREF to config
 *
 * @param vref       Pointer to the register overlay for the peripheral
 *
 * @param config     Pointer to the configuration structure
 */
void DL_VREF_getClockConfig(VREF_Regs *vref, DL_VREF_ClockConfig *config);

/**
 * @brief Resets the VREF module
 *
 * @param vref       Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_VREF_reset(VREF_Regs *vref)
{
    vref->GPRCM.RSTCTL =
        VREF_RSTCTL_RESETASSERT_MASK | VREF_RSTCTL_KEY_UNLOCK_W;
}

/**
 * @brief Returns if VREF peripheral was reset
 *
 * @param vref        Pointer to the register overlay for the VREF peripheral
 *
 * @return true if peripheral was reset
 * @return false if peripheral wasn't reset
 *
 */
__STATIC_INLINE bool DL_VREF_isReset(VREF_Regs *vref)
{
    return (vref->GPRCM.STAT & VREF_STAT_RESETSTKY_MASK) ==
           VREF_STAT_RESETSTKY_RESET;
}

/**
 * @brief Returns VREF register status
 *
 * @param vref        Pointer to the register overlay for the VREF peripheral
 *
 * @return VREF status bits set. Either @ref DL_VREF_CTL1_READY_NOTRDY or @ref DL_VREF_CTL1_READY_RDY
 *
 */
__STATIC_INLINE uint32_t DL_VREF_getStatus(VREF_Regs *vref)
{
    return vref->CTL1 & VREF_CTL1_READY_MASK;
}

/**
 * @brief Configure VREF enable, control registers
 *
 * @param vref        Pointer to the register overlay for the VREF peripheral
 *
 * @param config      Pointer to @ref DL_VREF_Config structure to configure the peripheral
 *
 */
void DL_VREF_configReference(VREF_Regs *vref, DL_VREF_Config *config);

#ifdef __cplusplus
}
#endif

#endif /* __MSPM0_HAS_VREF__ */

#endif /* ti_dl_dl_m0p_vref__include */
/** @}*/
