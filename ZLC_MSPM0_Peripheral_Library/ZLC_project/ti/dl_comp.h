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
 *  @file       dl_comp.h
 *  @brief      Comparator (COMP)
 *  @defgroup   COMP Comparator (COMP)
 *
 *  @anchor ti_dl_dl_comp_Overview
 *  # Overview
 *
 *  The COMP DriverLib allows full configuration of the MSPM0 comparator module.
 *  The comparator module (COMP) is an analog voltage comparator with general
 *  comparator functionality.
 *
 *  <hr>
 ******************************************************************************/
/** @addtogroup COMP
 * @{
 */
#ifndef ti_dl_m0p_dl_comp__include
#define ti_dl_m0p_dl_comp__include

#include <stdbool.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/dl_common.h>

#ifdef __MSPM0_HAS_COMP__

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */

/** @addtogroup DL_COMP_INTERRUPT
 *  @{
 */
/*!
 * @brief Comparator output ready interrupt
 */
#define DL_COMP_INTERRUPT_OUTPUT_READY               (COMP_CPU_INT_IMASK_OUTRDYIFG_SET)

/*!
 * @brief Rising or falling edge of comparator output (selected by IES bit)
 *        interrupt
 */
#define DL_COMP_INTERRUPT_OUTPUT_EDGE                  (COMP_CPU_INT_IMASK_COMPIFG_SET)

/*!
 * @brief Rising or falling edge of comparator inverted output (selected by
 *        IES bit) interrupt
 */
#define DL_COMP_INTERRUPT_OUTPUT_EDGE_INV           (COMP_CPU_INT_IMASK_COMPINVIFG_SET)

/** @}*/

/** @addtogroup DL_COMP_EVENT
 *  @{
 */
/*!
 * @brief Comparator output ready event
 */
#define DL_COMP_EVENT_OUTPUT_READY               (COMP_GEN_EVENT_IMASK_OUTRDYIFG_SET)

/*!
 * @brief Rising or falling edge of comparator output (selected by IES bit)
 *        event
 */
#define DL_COMP_EVENT_OUTPUT_EDGE                  (COMP_GEN_EVENT_IMASK_COMPIFG_SET)

/*!
 * @brief Rising or falling edge of comparator inverted output (selected by
 *        IES bit) event
 */
#define DL_COMP_EVENT_OUTPUT_EDGE_INV           (COMP_GEN_EVENT_IMASK_COMPINVIFG_SET)

/** @}*/

/* clang-format on */

/*! @enum DL_COMP_IIDX */
typedef enum {
    /*! COMP interrupt index for no interrupt */
    DL_COMP_IIDX_NO_INTERRUPT = COMP_CPU_INT_IIDX_STAT_NO_INTR,
    /*! COMP interrupt index for comparator output ready interrupt */
    DL_COMP_IIDX_OUTPUT_READY = COMP_CPU_INT_IIDX_STAT_OUTRDYIFG,
    /*! COMP interrupt index for rising or falling edge of comparator output
     * (selected by IES bit) interrupt */
    DL_COMP_IIDX_OUTPUT_EDGE = COMP_CPU_INT_IIDX_STAT_COMPIFG,
    /*! COMP interrupt index for rising or falling edge of comparator inverted
     * output (selected by IES bit) interrupt */
    DL_COMP_IIDX_OUTPUT_EDGE_INV = COMP_CPU_INT_IIDX_STAT_COMPINVIFG,
} DL_COMP_IIDX;

/*! @enum DL_COMP_MODE */
typedef enum {
    /*! Comparator is in fast mode */
    DL_COMP_MODE_FAST = COMP_CTL1_MODE_FAST,
    /*! Comparator is in ultra-low power (ULP) mode */
    DL_COMP_MODE_ULP = COMP_CTL1_MODE_ULP,
} DL_COMP_MODE;

/*! @enum DL_COMP_OUTPUT_INT_EDGE */
typedef enum {
    /*! Rising edge sets COMPIFG and falling edge sets COMPINVIFG */
    DL_COMP_OUTPUT_INT_EDGE_RISING = COMP_CTL1_IES_RISING,
    /*! Falling edge sets COMPIFG and rising edge sets COMPINVIFG */
    DL_COMP_OUTPUT_INT_EDGE_FALLING = COMP_CTL1_IES_FALLING,
} DL_COMP_OUTPUT_INT_EDGE;

/*! @enum DL_COMP_HYSTERESIS */
typedef enum {
    /*! No hysteresis */
    DL_COMP_HYSTERESIS_NONE = COMP_CTL1_HYST_NO_HYS,
    /*! Typical hysteresis voltage generated is 10mV */
    DL_COMP_HYSTERESIS_10 = COMP_CTL1_HYST_LOW_HYS,
    /*! Typical hysteresis voltage generated is 20mV */
    DL_COMP_HYSTERESIS_20 = COMP_CTL1_HYST_MED_HYS,
    /*! Typical hysteresis voltage generated is 30mV */
    DL_COMP_HYSTERESIS_30 = COMP_CTL1_HYST_HIGH_HYS,
} DL_COMP_HYSTERESIS;

/*! @enum DL_COMP_POLARITY */
typedef enum {
    /*! Comparator output is non-inverted. When comparator is off, OUT is low */
    DL_COMP_POLARITY_NON_INV = COMP_CTL1_OUTPOL_NON_INV,
    /*! Comparator output is inverted. When comparator is off, OUT is high */
    DL_COMP_POLARITY_INV = COMP_CTL1_OUTPOL_INV,
} DL_COMP_POLARITY;

/*! @enum DL_COMP_FILTER_DELAY */
typedef enum {
    /*! Typical filter delay of 70ns */
    DL_COMP_FILTER_DELAY_70 = COMP_CTL1_FLTDLY_DLY_0,
    /*! Typical filter delay of 500ns */
    DL_COMP_FILTER_DELAY_500 = COMP_CTL1_FLTDLY_DLY_1,
    /*! Typical filter delay of 1200ns */
    DL_COMP_FILTER_DELAY_1200 = COMP_CTL1_FLTDLY_DLY_2,
    /*! Typical filter delay of 2700ns */
    DL_COMP_FILTER_DELAY_2700 = COMP_CTL1_FLTDLY_DLY_3,
} DL_COMP_FILTER_DELAY;

/*! @enum DL_COMP_IPSEL_CHANNEL */
typedef enum {
    /*! IPSEL is channel 0. See the device datasheet for more details. */
    DL_COMP_IPSEL_CHANNEL_0 = COMP_CTL0_IPSEL_CH_0,
    /*! IPSEL is channel 1. See the device datasheet for more details. */
    DL_COMP_IPSEL_CHANNEL_1 = COMP_CTL0_IPSEL_CH_1,
    /*! IPSEL is channel 2. See the device datasheet for more details. */
    DL_COMP_IPSEL_CHANNEL_2 = COMP_CTL0_IPSEL_CH_2,
    /*! IPSEL is channel 3. See the device datasheet for more details. */
    DL_COMP_IPSEL_CHANNEL_3 = COMP_CTL0_IPSEL_CH_3,
    /*! IPSEL is channel 4. See the device datasheet for more details. */
    DL_COMP_IPSEL_CHANNEL_4 = COMP_CTL0_IPSEL_CH_4,
    /*! IPSEL is channel 5. See the device datasheet for more details. */
    DL_COMP_IPSEL_CHANNEL_5 = COMP_CTL0_IPSEL_CH_5,
    /*! IPSEL is channel 6. See the device datasheet for more details. */
    DL_COMP_IPSEL_CHANNEL_6 = COMP_CTL0_IPSEL_CH_6,
    /*! IPSEL is channel 7. See the device datasheet for more details. */
    DL_COMP_IPSEL_CHANNEL_7 = COMP_CTL0_IPSEL_CH_7,
} DL_COMP_IPSEL_CHANNEL;

/*! @enum DL_COMP_IMSEL_CHANNEL */
typedef enum {
    /*! IMSEL is channel 0. See the device datasheet for more details. */
    DL_COMP_IMSEL_CHANNEL_0 = COMP_CTL0_IMSEL_CH_0,
    /*! IMSEL is channel 1. See the device datasheet for more details. */
    DL_COMP_IMSEL_CHANNEL_1 = COMP_CTL0_IMSEL_CH_1,
    /*! IMSEL is channel 2. See the device datasheet for more details. */
    DL_COMP_IMSEL_CHANNEL_2 = COMP_CTL0_IMSEL_CH_2,
    /*! IMSEL is channel 3. See the device datasheet for more details. */
    DL_COMP_IMSEL_CHANNEL_3 = COMP_CTL0_IMSEL_CH_3,
    /*! IMSEL is channel 4. See the device datasheet for more details. */
    DL_COMP_IMSEL_CHANNEL_4 = COMP_CTL0_IMSEL_CH_4,
    /*! IMSEL is channel 5. See the device datasheet for more details. */
    DL_COMP_IMSEL_CHANNEL_5 = COMP_CTL0_IMSEL_CH_5,
    /*! IMSEL is channel 6. See the device datasheet for more details. */
    DL_COMP_IMSEL_CHANNEL_6 = COMP_CTL0_IMSEL_CH_6,
    /*! IMSEL is channel 7. See the device datasheet for more details. */
    DL_COMP_IMSEL_CHANNEL_7 = COMP_CTL0_IMSEL_CH_7,
} DL_COMP_IMSEL_CHANNEL;

/*! @enum DL_COMP_ENABLE_CHANNEL */
typedef enum {
    /*! Channel input disabled for both the positive and negative terminals */
    DL_COMP_ENABLE_CHANNEL_NONE =
        (COMP_CTL0_IPEN_DISABLE | COMP_CTL0_IMEN_DISABLE),
    /*! Channel input enabled for the positive terminal */
    DL_COMP_ENABLE_CHANNEL_POS = COMP_CTL0_IPEN_ENABLE,
    /*! Channel input enabled for the positive terminal */
    DL_COMP_ENABLE_CHANNEL_NEG = COMP_CTL0_IMEN_ENABLE,
    /*! Channel input enabled for both the positive and negative terminals */
    DL_COMP_ENABLE_CHANNEL_POS_NEG =
        (COMP_CTL0_IPEN_ENABLE | COMP_CTL0_IMEN_ENABLE),
} DL_COMP_ENABLE_CHANNEL;

/*! @enum DL_COMP_REF_MODE */
typedef enum {
    /*! ULP_REF bandgap, local reference buffer, and 8-bit COMP inside
     * comparator operate in static mode */
    DL_COMP_REF_MODE_STATIC = COMP_CTL2_REFMODE_STATIC,
    /*! ULP_REF bandgap, local reference buffer, and 8-bit COMP inside
     * comparator operate in sampled mode */
    DL_COMP_REF_MODE_SAMPLED = COMP_CTL2_REFMODE_SAMPLED,
} DL_COMP_REF_MODE;

/*! @enum DL_COMP_REF_SOURCE */
typedef enum {
    /*! Reference voltage generator is disabled (local reference buffer as
     * well as DAC) */
    DL_COMP_REF_SOURCE_NONE = COMP_CTL2_REFSRC_OFF,
    /*! VDDA selected as the reference source to DAC and DAC output applied
     * as reference to comparator */
    DL_COMP_REF_SOURCE_VDDA_DAC = COMP_CTL2_REFSRC_VDDA_DAC,
    /*! VREF selected as the reference source to DAC and DAC output applied
     * as reference to comparator */
    DL_COMP_REF_SOURCE_VREF_DAC = COMP_CTL2_REFSRC_VREF_DAC,
    /*! VREF applied as reference to comparator. For some devices, DAC is
     * switched off. Refer to the device datasheet for more information. */
    DL_COMP_REF_SOURCE_VREF = COMP_CTL2_REFSRC_VREF,
    /*! VDDA is used as comparator reference. For some devices, DAC is
     * switched off. Refer to the device datasheet for more information. */
    DL_COMP_REF_SOURCE_VDDA = COMP_CTL2_REFSRC_VDDA,
    /*! Internal reference selected as the reference source to the DAC and DAC
     * output applied as reference to comparator */
    DL_COMP_REF_SOURCE_INT_VREF_DAC = COMP_CTL2_REFSRC_INTVREF_DAC,
#if (DeviceFamily_PARENT == DeviceFamily_PARENT_MSPM0L122X_L222X)
    /*! Internal VREF used as reference source of comparator */
    DL_COMP_REF_SOURCE_INT_VREF = COMP_CTL2_REFSRC_INTVREF,
#endif
} DL_COMP_REF_SOURCE;

/*! @enum DL_COMP_REF_TERMINAL_SELECT */
typedef enum {
    /*! Reference applied to positive terminal. If EXCH bit is 1, reference
     * applied to negative terminal. */
    DL_COMP_REF_TERMINAL_SELECT_POS = COMP_CTL2_REFSEL_POSITIVE,
    /*! Reference applied to negative terminal. If EXCH bit is 0, reference
     * applied to positive terminal. */
    DL_COMP_REF_TERMINAL_SELECT_NEG = COMP_CTL2_REFSEL_NEGATIVE,
} DL_COMP_REF_TERMINAL_SELECT;

/*! @enum DL_COMP_BLANKING_SOURCE */
typedef enum {
    /*! Disable use of blanking source */
    DL_COMP_BLANKING_SOURCE_DISABLE = COMP_CTL2_BLANKSRC_DISABLE,
    /*! Blanking source 1 */
    DL_COMP_BLANKING_SOURCE_1 = COMP_CTL2_BLANKSRC_BLANKSRC1,
    /*! Blanking source 2 */
    DL_COMP_BLANKING_SOURCE_2 = COMP_CTL2_BLANKSRC_BLANKSRC2,
    /*! Blanking source 3 */
    DL_COMP_BLANKING_SOURCE_3 = COMP_CTL2_BLANKSRC_BLANKSRC3,
    /*! Blanking source 4 */
    DL_COMP_BLANKING_SOURCE_4 = COMP_CTL2_BLANKSRC_BLANKSRC4,
    /*! Blanking source 5 */
    DL_COMP_BLANKING_SOURCE_5 = COMP_CTL2_BLANKSRC_BLANKSRC5,
    /*! Blanking source 6 */
    DL_COMP_BLANKING_SOURCE_6 = COMP_CTL2_BLANKSRC_BLANKSRC6,
} DL_COMP_BLANKING_SOURCE;

/*! @enum DL_COMP_DAC_CONTROL */
typedef enum {
    /*! Comparator output controls selection betwen DACCODE0 and DACCODE1 */
    DL_COMP_DAC_CONTROL_COMP_OUT = COMP_CTL2_DACCTL_COMPOUT_SEL,
    /*! DACSW bit controls selection betwen DACCODE0 and DACCODE1 */
    DL_COMP_DAC_CONTROL_SW = COMP_CTL2_DACCTL_DACSW_SEL,
} DL_COMP_DAC_CONTROL;

/*! @enum DL_COMP_DAC_INPUT */
typedef enum {
    /*! DACCODE0 selected as input for 8-bit COMP when DACCTL bit is 1 */
    DL_COMP_DAC_INPUT_DACCODE0 = COMP_CTL2_DACSW_DACCODE0_SEL,
    /*! DACCODE1 selected as input for 8-bit COMP when DACCTL bit is 1 */
    DL_COMP_DAC_INPUT_DACCODE1 = COMP_CTL2_DACSW_DACCODE1_SEL,
} DL_COMP_DAC_INPUT;

/*! @enum DL_COMP_OUTPUT */
typedef enum {
    /*! Comparator output is high */
    DL_COMP_OUTPUT_HIGH = COMP_STAT_OUT_LOW,
    /*! Comparator output is low */
    DL_COMP_OUTPUT_LOW = COMP_STAT_OUT_HIGH,
} DL_COMP_OUTPUT;

/*! @enum DL_COMP_SUBSCRIBER_INDEX */
typedef enum {
    /*! COMP Subscriber index 0 */
    DL_COMP_SUBSCRIBER_INDEX_0 = 0,
    /*! COMP Subscriber index 1 */
    DL_COMP_SUBSCRIBER_INDEX_1 = 1
} DL_COMP_SUBSCRIBER_INDEX;

/*!
 *  @brief  Configuration struct for @ref DL_COMP_init
 */
typedef struct {
    /*! The operating mode of the comparator */
    DL_COMP_MODE mode;
    /*! The channel inputs to the comparator terminals to enable */
    DL_COMP_ENABLE_CHANNEL channelEnable;
    /*! The channel input for the positive terminal of the comparator */
    DL_COMP_IPSEL_CHANNEL posChannel;
    /*! The channel input for the negative terminal of the comparator */
    DL_COMP_IMSEL_CHANNEL negChannel;
    /*! The polarity of the comparator output */
    DL_COMP_POLARITY polarity;
    /*! The hysteresis of the comparator */
    DL_COMP_HYSTERESIS hysteresis;
} DL_COMP_Config;

/*!
 *  @brief  Configuration struct for @ref DL_COMP_refVoltageInit
 */
typedef struct {
    /*! The operating mode of the reference voltage generator */
    DL_COMP_REF_MODE mode;
    /*! The reference source of the comparator */
    DL_COMP_REF_SOURCE source;
    /*! The terminals the reference voltage is applied to */
    DL_COMP_REF_TERMINAL_SELECT terminalSelect;
    /*! Determines what controls the selection between DACCODE0 and DACCODE1 */
    DL_COMP_DAC_CONTROL controlSelect;
    /*! If DL_COMP_DAC_CONTROL_SW is enabled, selects between DACCODE0
     * and DACCODE1 */
    DL_COMP_DAC_INPUT inputSelect;
} DL_COMP_RefVoltageConfig;

/**
 * @brief      Enables power on the comparator module
 *
 * @param[in]  comp  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_COMP_enablePower(COMP_Regs *comp)
{
    comp->GPRCM.PWREN = (COMP_PWREN_KEY_UNLOCK_W | COMP_PWREN_ENABLE_ENABLE);
}

/**
 * @brief      Disables power on the comparator module
 *
 * @param[in]  comp  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_COMP_disablePower(COMP_Regs *comp)
{
    comp->GPRCM.PWREN = (COMP_PWREN_KEY_UNLOCK_W | COMP_PWREN_ENABLE_DISABLE);
}

/**
 * @brief      Returns if power is on for the comparator module
 *
 * @param[in]  comp  Pointer to the register overlay for the peripheral
 *
 *  @return    The status of the peripheral power
 *
 * @retval     true  If power is enabled
 * @retval     false If power is disabled
 */
__STATIC_INLINE bool DL_COMP_isPowerEnabled(COMP_Regs *comp)
{
    return ((comp->GPRCM.PWREN & COMP_PWREN_ENABLE_MASK) ==
            COMP_PWREN_ENABLE_ENABLE);
}

/**
 * @brief      Resets comparator peripheral
 *
 * @param[in]  comp  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_COMP_reset(COMP_Regs *comp)
{
    comp->GPRCM.RSTCTL =
        (COMP_RSTCTL_KEY_UNLOCK_W | COMP_RSTCTL_RESETSTKYCLR_CLR |
            COMP_RSTCTL_RESETASSERT_ASSERT);
}

/**
 * @brief      Returns if comparator was reset
 *
 * @param[in]  comp  Pointer to the register overlay for the peripheral
 *
 * @return true  If peripheral was reset
 * @return false If peripheral wasn't reset
 *
 */
__STATIC_INLINE bool DL_COMP_isReset(COMP_Regs *comp)
{
    return ((comp->GPRCM.STAT & COMP_GPRCM_STAT_RESETSTKY_MASK) ==
            COMP_GPRCM_STAT_RESETSTKY_RESET);
}

/**
 *  @brief      Initialize the COMP peripheral
 *
 *  Initializes all the common configurable options for the COMP peripheral. Any
 *  other custom configuration can be done after calling this API. The COMP is
 *  not enabled in this API.
 *
 *  @param[in]  comp    Pointer to the register overlay for the peripheral
 *  @param[in]  config  Configuration for COMP peripheral
 */
__STATIC_INLINE void DL_COMP_init(COMP_Regs *comp, DL_COMP_Config *config)
{
    DL_Common_updateReg(&comp->CTL0,
        (uint32_t) config->posChannel | (uint32_t) config->negChannel |
            (uint32_t) config->channelEnable,
        COMP_CTL0_IMSEL_MASK | COMP_CTL0_IPSEL_MASK | COMP_CTL0_IPEN_MASK |
            COMP_CTL0_IMEN_MASK);

    DL_Common_updateReg(&comp->CTL1,
        (uint32_t) config->mode | (uint32_t) config->polarity |
            (uint32_t) config->hysteresis,
        COMP_CTL1_MODE_MASK | COMP_CTL1_HYST_MASK | COMP_CTL1_OUTPOL_MASK);
}

/**
 *  @brief      Initialize the comparator reference voltage generator
 *
 * Initializes all the common configurable options for the comparator
 * reference voltage generator. Any other custom configuration can be done
 * after calling this API.
 *
 *  @param[in]  comp    Pointer to the register overlay for the peripheral
 *  @param[in]  config  Configuration for the reference voltage generator
 */
__STATIC_INLINE void DL_COMP_refVoltageInit(
    COMP_Regs *comp, DL_COMP_RefVoltageConfig *config)
{
    DL_Common_updateReg(&comp->CTL2,
        (uint32_t) config->mode | (uint32_t) config->source |
            (uint32_t) config->terminalSelect |
            (uint32_t) config->controlSelect | (uint32_t) config->inputSelect,
        COMP_CTL2_REFMODE_MASK | COMP_CTL2_REFSRC_MASK |
            COMP_CTL2_REFSEL_MASK | COMP_CTL2_DACCTL_MASK |
            COMP_CTL2_DACSW_MASK);
}

/**
 *  @brief      Enable the comparator peripheral
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_COMP_enable(COMP_Regs *comp)
{
    comp->CTL1 |= COMP_CTL1_ENABLE_ON;
}

/**
 *  @brief      Checks if the comparator peripheral is enabled
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 *
 *  @return     Returns the enabled status of the comparator
 *
 *  @retval     true  The comparator peripheral is enabled
 *  @retval     false The comparator peripheral is disabled

 */
__STATIC_INLINE bool DL_COMP_isEnabled(COMP_Regs *comp)
{
    return ((comp->CTL1 & COMP_CTL1_ENABLE_MASK) == COMP_CTL1_ENABLE_ON);
}

/**
 *  @brief      Disable the comparator peripheral
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_COMP_disable(COMP_Regs *comp)
{
    comp->CTL1 &= ~(COMP_CTL1_ENABLE_MASK);
}

/**
 *  @brief      Set the comparator operating mode
 *
 * The clock control for comparator is managed by SYSCTL, SYSCTL knows if
 * comparator module is enabled and at also knows if it is in ultra-low power
 * mode or fast mode. User needs to ensure the proper bus clock is selected
 * for different comparator operation mode.
 *   - In @ref DL_COMP_MODE_ULP, bus clock can be LFCLK or any of the high
 *     speed clocks.
 *   - In @ref DL_COMP_MODE_FAST, bus clock cannot be LFCLK.
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 *  @param[in]  mode  Mode to set the comparator to.
 *                    One of @ref DL_COMP_MODE.
 */
__STATIC_INLINE void DL_COMP_setCompMode(COMP_Regs *comp, DL_COMP_MODE mode)
{
    DL_Common_updateReg(&comp->CTL1, (uint32_t) mode, COMP_CTL1_MODE_MASK);
}

/**
 *  @brief      Get the mode the comparator is set to
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 *
 *  @return     The mode the comparator is set to
 *
 *  @retval     One of @ref DL_COMP_MODE
 */
__STATIC_INLINE DL_COMP_MODE DL_COMP_getCompMode(COMP_Regs *comp)
{
    uint32_t mode = (comp->CTL1 & COMP_CTL1_MODE_MASK);

    return (DL_COMP_MODE)(mode);
}

/**
 *  @brief      Enable exchange of the comparator inputs, and invert output
 *
 * When enabled, the input signals of comparator positive and negative
 * terminals are exchanged. Additionally, the output signal from the comparator
 * is inverted too. This allows the user to determine or compensate for the
 * comparator input offset voltage.
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_COMP_enableExchangeInputs(COMP_Regs *comp)
{
    comp->CTL1 |= COMP_CTL1_EXCH_EXC;
}

/**
 *  @brief      Checks if the inputs are exchanged and if output is inverted
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 *
 *  @return     Returns if the inputs are exchanged and if output is inverted
 *
 *  @retval     true  The inputs are exchanged and output is inverted
 *  @retval     false The inputs are not exchanged and output is not inverted

 */
__STATIC_INLINE bool DL_COMP_isExchangeInputsEnabled(COMP_Regs *comp)
{
    return ((comp->CTL1 & COMP_CTL1_EXCH_MASK) == COMP_CTL1_EXCH_EXC);
}

/**
 *  @brief      Disable input exchange and invert output
 *
 * The input signals of the comparator positive and negative terminals are not
 * exchanged, and the output signal from the comparator is not inverted.
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_COMP_disableExchangeInputs(COMP_Regs *comp)
{
    comp->CTL1 &= ~(COMP_CTL1_EXCH_MASK);
}

/**
 *  @brief      Enable shorting of the comparator inputs
 *
 * When enabled, shorts the positive and negative input terminals of the
 * comparator.
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_COMP_enableShortInputTerminals(COMP_Regs *comp)
{
    comp->CTL1 |= COMP_CTL1_SHORT_SHT;
}

/**
 *  @brief      Checks if the comparator inputs are shorted
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 *
 *  @return     Returns if the comparator inputs are shorted
 *
 *  @retval     true  The comparator inputs are shorted
 *  @retval     false The comparator inputs are not shorted

 */
__STATIC_INLINE bool DL_COMP_isInputTerminalsShorted(COMP_Regs *comp)
{
    return ((comp->CTL1 & COMP_CTL1_SHORT_MASK) == COMP_CTL1_SHORT_SHT);
}

/**
 *  @brief      Disable shorting the comparator inputs
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_COMP_disableShortInputTerminals(COMP_Regs *comp)
{
    comp->CTL1 &= ~(COMP_CTL1_SHORT_MASK);
}

/**
 *  @brief      Set the interrupt edge for the comparator output
 *
 * The interrupt flags COMPIFG and COMPINVIFG are set either on the rising or
 * falling edge of the comparator output.
 *   - In @ref DL_COMP_OUTPUT_INT_EDGE_RISING, rising edge of the comparator
 *     output sets the COMPIFG and falling edge sets the COMPINVIFG.
 *   - In @ref DL_COMP_OUTPUT_INT_EDGE_FALLING, falling edge of the comparator
 *     output sets the COMPIFG and rising edge sets the COMPINVIFG.
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 *  @param[in]  edge  Interrupt edge for the comparator output.
 *                    One of @ref DL_COMP_OUTPUT_INT_EDGE.
 */
__STATIC_INLINE void DL_COMP_setOutputInterruptEdge(
    COMP_Regs *comp, DL_COMP_OUTPUT_INT_EDGE edge)
{
    DL_Common_updateReg(&comp->CTL1, (uint32_t) edge, COMP_CTL1_IES_MASK);
}

/**
 *  @brief      Get the interrupt edge for the comparator output
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 *
 *  @return     The interrupt edge for the comparator output
 *
 *  @retval     One of @ref DL_COMP_OUTPUT_INT_EDGE
 */
__STATIC_INLINE DL_COMP_OUTPUT_INT_EDGE DL_COMP_getOutputInterruptEdge(
    COMP_Regs *comp)
{
    uint32_t interruptEdge = (comp->CTL1 & COMP_CTL1_IES_MASK);

    return (DL_COMP_OUTPUT_INT_EDGE)(interruptEdge);
}

/**
 *  @brief      Set the hysteresis voltage
 *
 *  @param[in]  comp     Pointer to the register overlay for the peripheral
 *  @param[in]  voltage  Voltage value to set the hysteresis to
 */
__STATIC_INLINE void DL_COMP_setHysteresis(
    COMP_Regs *comp, DL_COMP_HYSTERESIS voltage)
{
    DL_Common_updateReg(&comp->CTL1, (uint32_t) voltage, COMP_CTL1_HYST_MASK);
}

/**
 *  @brief      Get the hysteresis voltage
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 *
 *  @return     The hysteresis voltage
 *
 *  @retval     One of @ref DL_COMP_HYSTERESIS
 */
__STATIC_INLINE DL_COMP_HYSTERESIS DL_COMP_getHysteresis(COMP_Regs *comp)
{
    uint32_t hysteresis = (comp->CTL1 & COMP_CTL1_HYST_MASK);

    return (DL_COMP_HYSTERESIS)(hysteresis);
}

/**
 *  @brief      Set the output polarity
 *
 *  @param[in]  comp      Pointer to the register overlay for the peripheral
 *  @param[in]  polarity  The polarity of the comparator output
 */
__STATIC_INLINE void DL_COMP_setOutputPolarity(
    COMP_Regs *comp, DL_COMP_POLARITY polarity)
{
    DL_Common_updateReg(
        &comp->CTL1, (uint32_t) polarity, COMP_CTL1_OUTPOL_MASK);
}

/**
 *  @brief      Get the output polarity
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 *
 *  @return     The output polarity
 *
 *  @retval     One of @ref DL_COMP_POLARITY
 */
__STATIC_INLINE DL_COMP_POLARITY DL_COMP_getOutputPolarity(COMP_Regs *comp)
{
    uint32_t polarity = (comp->CTL1 & COMP_CTL1_OUTPOL_MASK);

    return (DL_COMP_POLARITY)(polarity);
}

/**
 *  @brief      Enable output filter
 *
 * The output is filtered with an on-chip analog filter. The delay of the
 * filter can be adjusted in four different steps. Refer to the device
 * specific datasheet for the comparator propagation delay with different
 * filter delay settings.
 *
 *  @param[in]  comp   Pointer to the register overlay for the peripheral
 *  @param[in]  delay  Delay of the filter. One of @ref DL_COMP_FILTER_DELAY.
 */
__STATIC_INLINE void DL_COMP_enableOutputFilter(
    COMP_Regs *comp, DL_COMP_FILTER_DELAY delay)
{
    comp->CTL1 |= (COMP_CTL1_FLTEN_ENABLE | (uint32_t) delay);
}

/**
 *  @brief      Checks if output filter is enabled
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 *
 *  @return     Returns if the output is filtered
 *
 *  @retval     true  The output is filtered
 *  @retval     false The output is not filtered
 */
__STATIC_INLINE bool DL_COMP_isOutputFilterEnabled(COMP_Regs *comp)
{
    return ((comp->CTL1 & COMP_CTL1_FLTEN_MASK) == COMP_CTL1_FLTEN_ENABLE);
}

/**
 *  @brief      Disable output filter using on-chip analog filter
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_COMP_disableOutputFilter(COMP_Regs *comp)
{
    comp->CTL1 &= ~(COMP_CTL1_FLTEN_MASK);
}

/**
 *  @brief      Get the output filter delay
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 *
 *  @return     The output filter delay
 *
 *  @retval     One of @ref DL_COMP_FILTER_DELAY
 */
__STATIC_INLINE DL_COMP_FILTER_DELAY DL_COMP_getOutputFilterDelay(
    COMP_Regs *comp)
{
    uint32_t delay = (comp->CTL1 & COMP_CTL1_FLTDLY_MASK);

    return (DL_COMP_FILTER_DELAY)(delay);
}

/**
 *  @brief      Enable the window comparator
 *
 *  @param[in]  comp   Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_COMP_enableWindowComparator(COMP_Regs *comp)
{
    comp->CTL1 |= COMP_CTL1_WINCOMPEN_ON;
}

/**
 *  @brief      Checks if the window comparator is enabled
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 *
 *  @return     Returns if the window comparator is enabled
 *
 *  @retval     true  The window comparator is enabled
 *  @retval     false The window comparator is not enabled
 */
__STATIC_INLINE bool DL_COMP_isWindowComparatorEnabled(COMP_Regs *comp)
{
    return ((comp->CTL1 & COMP_CTL1_WINCOMPEN_MASK) == COMP_CTL1_WINCOMPEN_ON);
}

/**
 *  @brief      Disable the window comparator
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_COMP_disableWindowComparator(COMP_Regs *comp)
{
    comp->CTL1 &= ~(COMP_CTL1_WINCOMPEN_MASK);
}

/**
 *  @brief      Set the enabled channels for the comparator terminals
 *
 * Enables the selected analog input channels for the positive and
 * negative comparator terminals.
 *
 *  @param[in]  comp      Pointer to the register overlay for the peripheral
 *  @param[in]  channels  Input channels to enable
 */
__STATIC_INLINE void DL_COMP_setEnabledInputChannels(
    COMP_Regs *comp, DL_COMP_ENABLE_CHANNEL channels)
{
    DL_Common_updateReg(&comp->CTL0, (uint32_t) channels,
        (COMP_CTL0_IMEN_MASK | COMP_CTL0_IPEN_MASK));
}

/**
 *  @brief      Get the enabled input channels
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 *
 *  @return     The enabled input channels
 *
 *  @retval     One of @ref DL_COMP_ENABLE_CHANNEL
 */
__STATIC_INLINE DL_COMP_ENABLE_CHANNEL DL_COMP_getEnabledInputChannels(
    COMP_Regs *comp)
{
    uint32_t channel =
        (comp->CTL0 & (COMP_CTL0_IMEN_MASK | COMP_CTL0_IPEN_MASK));

    return (DL_COMP_ENABLE_CHANNEL)(channel);
}

/**
 *  @brief      Set the channel input for the positive terminal
 *
 * This API sets the IPSEL control bit to select the channel input for the
 * positive terminal. Please see the device datasheet for more details on each
 * channel input for each comparator instance.
 *
 * Note this API does not enable the positive terminal. Call
 * @ref DL_COMP_setEnabledInputChannels to enable the terminals.
 *
 *  @param[in]  comp   Pointer to the register overlay for the peripheral
 *  @param[in]  input  Channel input for the positive terminal
 */
__STATIC_INLINE void DL_COMP_setPositiveChannelInput(
    COMP_Regs *comp, DL_COMP_IPSEL_CHANNEL input)
{
    DL_Common_updateReg(&comp->CTL0, (uint32_t) input, COMP_CTL0_IPSEL_MASK);
}

/**
 *  @brief      Get the channel input for the positive terminal
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 *
 *  @return     The channel input for the positive terminal
 *
 *  @retval     One of @ref DL_COMP_IPSEL_CHANNEL
 */
__STATIC_INLINE DL_COMP_IPSEL_CHANNEL DL_COMP_getPositiveChannelInput(
    COMP_Regs *comp)
{
    uint32_t channel = (comp->CTL0 & COMP_CTL0_IPSEL_MASK);

    return (DL_COMP_IPSEL_CHANNEL)(channel);
}

/**
 *  @brief      Set the channel input for the negative terminal
 *
 * This API sets the IMSEL control bit to select the channel input for the
 * negative terminal. Please see the device TRM for more details on each
 * channel input for each comparator instance.
 *
 * Note this API does not enable the negative terminal. Call
 * @ref DL_COMP_setEnabledInputChannels to enable the terminals.
 *
 *  @param[in]  comp   Pointer to the register overlay for the peripheral
 *  @param[in]  input  Channel input for the negative terminal
 */
__STATIC_INLINE void DL_COMP_setNegativeChannelInput(
    COMP_Regs *comp, DL_COMP_IMSEL_CHANNEL input)
{
    DL_Common_updateReg(&comp->CTL0, (uint32_t) input, COMP_CTL0_IMSEL_MASK);
}

/**
 *  @brief      Get the channel input for the negative terminal
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 *
 *  @return     The channel input for the negative terminal
 *
 *  @retval     One of @ref DL_COMP_IMSEL_CHANNEL
 */
__STATIC_INLINE DL_COMP_IMSEL_CHANNEL DL_COMP_getNegativeChannelInput(
    COMP_Regs *comp)
{
    uint32_t channel = (comp->CTL0 & COMP_CTL0_IMSEL_MASK);

    return (DL_COMP_IMSEL_CHANNEL)(channel);
}

/**
 *  @brief      Set the mode for the reference voltage
 *
 * This bit requests ULP_REF bandgap operation in static mode or sampled mode.
 * The local reference buffer and 8-bit COMP inside comparator module are also
 * configured accordingly.
 *     - In @ref DL_COMP_REF_MODE_STATIC, operation offers higher accuracy but
 *       consumes higher current.
 *     - In @ref DL_COMP_REF_MODE_SAMPLED, operation consumes lower current but
 *       with relaxed reference voltage accuracy.
 * Comparator requests for reference voltage from ULP_REF only when REFLVL > 0.
 *
 *  @param[in]  comp   Pointer to the register overlay for the peripheral
 *  @param[in]  mode   Mode to set the reference voltage to
 */
__STATIC_INLINE void DL_COMP_setReferenceMode(
    COMP_Regs *comp, DL_COMP_REF_MODE mode)
{
    DL_Common_updateReg(&comp->CTL2, (uint32_t) mode, COMP_CTL2_REFMODE_MASK);
}

/**
 *  @brief      Get the mode for the reference voltage
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 *
 *  @return     The mode of the reference voltage
 *
 *  @retval     One of @ref DL_COMP_REF_MODE
 */
__STATIC_INLINE DL_COMP_REF_MODE DL_COMP_getReferenceMode(COMP_Regs *comp)
{
    uint32_t mode = (comp->CTL2 & COMP_CTL2_REFMODE_MASK);

    return (DL_COMP_REF_MODE)(mode);
}

/**
 *  @brief      Set the reference source for the comparator
 *
 *  @param[in]  comp     Pointer to the register overlay for the peripheral
 *  @param[in]  source   Reference source for the comparator
 */
__STATIC_INLINE void DL_COMP_setReferenceSource(
    COMP_Regs *comp, DL_COMP_REF_SOURCE source)
{
    DL_Common_updateReg(&comp->CTL2, (uint32_t) source, COMP_CTL2_REFSRC_MASK);
}

/**
 *  @brief      Get the reference source for the comparator
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 *
 *  @return     The reference source
 *
 *  @retval     One of @ref DL_COMP_REF_SOURCE
 */
__STATIC_INLINE DL_COMP_REF_SOURCE DL_COMP_getReferenceSource(COMP_Regs *comp)
{
    uint32_t source = (comp->CTL2 & COMP_CTL2_REFSRC_MASK);

    return (DL_COMP_REF_SOURCE)(source);
}

/**
 *  @brief      Set the comparator terminal the reference voltage is applied to
 *
 * The reference voltage generator output can be applied to either the positive
 * terminal or negative terminal of the comparator. When the reference voltage
 * generator output is applied on a comparator terminal using REFSEL bit and
 * the comparator channel (from device pins or from internal analog modules) is
 * also selected on the same terminal using IPSEL/IPEN or IMSEL/IMEN bits, then
 * the comparator channel selection takes precedence.
 *
 *  @param[in]  comp      Pointer to the register overlay for the peripheral
 *  @param[in]  terminal  Terminal the reference voltage is applied to
 */
__STATIC_INLINE void DL_COMP_setReferenceCompTerminal(
    COMP_Regs *comp, DL_COMP_REF_TERMINAL_SELECT terminal)
{
    DL_Common_updateReg(
        &comp->CTL2, (uint32_t) terminal, COMP_CTL2_REFSEL_MASK);
}

/**
 *  @brief      Get the comparator terminal the reference voltage is applied to
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 *
 *  @return     The terminal the reference voltage is applied to
 *
 *  @retval     One of @ref DL_COMP_REF_TERMINAL_SELECT
 */
__STATIC_INLINE DL_COMP_REF_TERMINAL_SELECT DL_COMP_getReferenceCompTerminal(
    COMP_Regs *comp)
{
    uint32_t terminal = (comp->CTL2 & COMP_CTL2_REFSEL_MASK);

    return (DL_COMP_REF_TERMINAL_SELECT)(terminal);
}

/**
 *  @brief      Set the blanking source for the comparator
 *
 *  @param[in]  comp     Pointer to the register overlay for the peripheral
 *  @param[in]  source   Blanking source for the comparator
 */
__STATIC_INLINE void DL_COMP_setBlankingSource(
    COMP_Regs *comp, DL_COMP_BLANKING_SOURCE source)
{
    DL_Common_updateReg(
        &comp->CTL2, (uint32_t) source, COMP_CTL2_BLANKSRC_MASK);
}

/**
 *  @brief      Get the blanking source for the comparator
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 *
 *  @return     The blanking source
 *
 *  @retval     One of @ref DL_COMP_BLANKING_SOURCE
 */
__STATIC_INLINE DL_COMP_BLANKING_SOURCE DL_COMP_getBlankingSource(
    COMP_Regs *comp)
{
    uint32_t source = (comp->CTL2 & COMP_CTL2_BLANKSRC_MASK);

    return (DL_COMP_BLANKING_SOURCE)(source);
}

/**
 *  @brief      Select the source for COMP control
 *
 * The DACCTL bit determines if the comparator output or a software control
 * bit, DACSW, selects between DACCODE0 and DACCODE1 bits as the input to
 * the COMP.
 *
 *  @param[in]  comp     Pointer to the register overlay for the peripheral
 *  @param[in]  control  What controls the inputs to the COMP.
 *                       One of @ref DL_COMP_DAC_CONTROL
 */
__STATIC_INLINE void DL_COMP_setDACControl(
    COMP_Regs *comp, DL_COMP_DAC_CONTROL control)
{
    DL_Common_updateReg(
        &comp->CTL2, (uint32_t) control, COMP_CTL2_DACCTL_MASK);
}

/**
 *  @brief      Get what controls the input to the COMP
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 *
 *  @return     The control input
 *
 *  @retval     One of @ref DL_COMP_DAC_CONTROL
 */
__STATIC_INLINE DL_COMP_DAC_CONTROL DL_COMP_getDACControl(COMP_Regs *comp)
{
    uint32_t control = (comp->CTL2 & COMP_CTL2_DACCTL_MASK);

    return (DL_COMP_DAC_CONTROL)(control);
}

/**
 *  @brief      Set whether DACCODE0 or DACCODE1 is the input to the COMP
 *
 * @pre The DACCTL bit must be set to 1 in order to program the DACSW bit to
 * select between DACCODE0 or DACCODE1.
 *
 * @sa          DL_COMP_setDACControl
 *
 *  @param[in]  comp   Pointer to the register overlay for the peripheral
 *  @param[in]  input  The input to the COMP. One of @ref DL_COMP_DAC_INPUT
 */
__STATIC_INLINE void DL_COMP_setDACInput(
    COMP_Regs *comp, DL_COMP_DAC_INPUT input)
{
    DL_Common_updateReg(&comp->CTL2, (uint32_t) input, COMP_CTL2_DACSW_MASK);
}

/**
 *  @brief      Get whether DACCODE0 or DACCODE1 is the input to the COMP
 *
 * @pre The DACCTL bit must be set to 1 in order to program the DACSW bit to
 * select between DACCODE0 or DACCODE1.
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 *
 *  @return     The input to the COMP
 *
 *  @retval     One of @ref DL_COMP_DAC_INPUT
 */
__STATIC_INLINE DL_COMP_DAC_INPUT DL_COMP_getDACInput(COMP_Regs *comp)
{
    uint32_t input = (comp->CTL2 & COMP_CTL2_DACSW_MASK);

    return (DL_COMP_DAC_INPUT)(input);
}

/**
 *  @brief      Set the 8-bit COMP input code through DACCODE0
 *
 * Sets the first 8-bit COMP code through DACCODE0.  When the COMP code is 0x0
 * the COMP output will be 0 V. When the COMP code is 0xFF the COMP output will
 * be selected reference voltage x 255/256.
 *
 * @pre The DACCTL bit determines what controls the selection between
 * DACCODE0 and DACCODE1.
 * @pre If DACCTL is 1, then the DACSW bit is used to select between DACCODE0
 * or DACCODE1.
 *
 * @sa          DL_COMP_setDACControl
 * @sa          DL_COMP_setDACInput
 *
 *  @param[in]  comp   Pointer to the register overlay for the peripheral
 *  @param[in]  value  Code to set for codeDACCODE0.
 *                     Value between 0x0 - 0xFF.
 */
__STATIC_INLINE void DL_COMP_setDACCode0(COMP_Regs *comp, uint32_t value)
{
    DL_Common_updateReg(&comp->CTL3, value, COMP_CTL3_DACCODE0_MASK);
}

/**
 *  @brief      Get the code value of DACCODE0
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 *
 *  @return     The code value that DACCODE0 is set to
 *
 *  @retval     Value between 0x0 - 0xFF
 */
__STATIC_INLINE uint32_t DL_COMP_getDACCode0(COMP_Regs *comp)
{
    return (comp->CTL3 & COMP_CTL3_DACCODE0_MASK);
}

/**
 *  @brief      Set the 8-bit COMP input code through DACCODE1
 *
 * Sets the second 8-bit COMP code through DACCODE1.  When the COMP code is 0x0
 * the COMP output will be 0 V. When the COMP code is 0xFF the COMP output will
 * be selected reference voltage x 255/256.
 *
 * @pre The DACCTL bit determines what controls the selection between
 * DACCODE0 and DACCODE1.
 * @pre If DACCTL is 1, then the DACSW bit is used to select between DACCODE0
 * or DACCODE1.
 *
 * @sa          DL_COMP_setDACControl
 * @sa          DL_COMP_setDACInput
 *
 *  @param[in]  comp   Pointer to the register overlay for the peripheral
 *  @param[in]  value  Code to set for codeDACCODE1.
 *                     Value between 0x0 - 0xFF.
 */
__STATIC_INLINE void DL_COMP_setDACCode1(COMP_Regs *comp, uint32_t value)
{
    DL_Common_updateReg(&comp->CTL3, (value << COMP_CTL3_DACCODE1_OFS),
        COMP_CTL3_DACCODE1_MASK);
}

/**
 *  @brief      Get the code value of DACCODE1
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 *
 *  @return     The code value that DACCODE1 is set to
 *
 *  @retval     Value between 0x0 - 0xFF
 */
__STATIC_INLINE uint32_t DL_COMP_getDACCode1(COMP_Regs *comp)
{
    return ((comp->CTL3 & COMP_CTL3_DACCODE1_MASK) >> COMP_CTL3_DACCODE1_OFS);
}

/**
 *  @brief      Gets the comparator output
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 *
 *  @return     Returns the output status of the comparator. One of @ref DL_COMP_OUTPUT
 */
__STATIC_INLINE DL_COMP_OUTPUT DL_COMP_getComparatorOutput(COMP_Regs *comp)
{
    uint32_t output = (comp->STAT & COMP_STAT_OUT_MASK);

    return (DL_COMP_OUTPUT)(output);
}

/**
 *  @brief      Enable sampled mode of the comparator
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_COMP_enableSampledMode(COMP_Regs *comp)
{
    comp->CTL2 |= COMP_CTL2_SAMPMODE_ENABLE;
}

/**
 *  @brief      Checks if sampled mode is enabled
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 *
 *  @return     Returns if sampled mode is enabled
 *
 *  @retval     true  Sampled mode is enabled
 *  @retval     false Sampled mode is disabled

 */
__STATIC_INLINE bool DL_COMP_isSampledModeEnabled(COMP_Regs *comp)
{
    return (
        (comp->CTL2 & COMP_CTL2_SAMPMODE_MASK) == COMP_CTL2_SAMPMODE_ENABLE);
}

/**
 *  @brief      Disable sampled mode
 *
 *  @param[in]  comp  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_COMP_disableSampledMode(COMP_Regs *comp)
{
    comp->CTL2 &= ~(COMP_CTL2_SAMPMODE_MASK);
}

/**
 *  @brief Sets the event subscriber channel id
 *
 *  @param[in]  comp Pointer to the register overlay for the
 *                      peripheral
 *  @param[in]  index   Specifies the register event index to be configured
 *  @param[in]  chanID  Channel ID number. Valid range 0-15. If ChanID == 0
 *                      subscriber is disconnected.
 */
__STATIC_INLINE void DL_COMP_setSubscriberChanID(
    COMP_Regs *comp, DL_COMP_SUBSCRIBER_INDEX index, uint8_t chanID)
{
    volatile uint32_t *pReg = &comp->FSUB_0;

    *(pReg + (uint32_t) index) = (chanID & COMP_FSUB_0_CHANID_MAXIMUM);
}

/**
 *  @brief Gets the event subscriber channel id
 *
 *  @param[in]  comp Pointer to the register overlay for the peripheral
 *  @param[in]  index  Specifies the register event index to be configured
 *
 *  @return     Event subscriber channel ID
 *
 */
__STATIC_INLINE uint8_t DL_COMP_getSubscriberChanID(
    COMP_Regs *comp, DL_COMP_SUBSCRIBER_INDEX index)
{
    volatile uint32_t *pReg = &comp->FSUB_0;

    return ((uint8_t)(*(pReg + (uint32_t) index) & COMP_FSUB_0_CHANID_MASK));
}

/**
 *  @brief      Enable COMP interrupts
 *
 *  @param[in]  comp           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to enable. Bitwise OR of
 *                             @ref DL_COMP_INTERRUPT.
 */
__STATIC_INLINE void DL_COMP_enableInterrupt(
    COMP_Regs *comp, uint32_t interruptMask)
{
    comp->CPU_INT.IMASK |= interruptMask;
}

/**
 *  @brief      Disable COMP interrupts
 *
 *  @param[in]  comp           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to disable. Bitwise OR of
 *                             @ref DL_COMP_INTERRUPT.
 */
__STATIC_INLINE void DL_COMP_disableInterrupt(
    COMP_Regs *comp, uint32_t interruptMask)
{
    comp->CPU_INT.IMASK &= ~(interruptMask);
}

/**
 *  @brief      Check which COMP interrupts are enabled
 *
 *  @param[in]  comp           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_COMP_INTERRUPT.
 *
 *  @return     Which of the requested COMP interrupts are enabled
 *
 *  @retval     Bitwise OR of @ref DL_COMP_INTERRUPT values
 */
__STATIC_INLINE uint32_t DL_COMP_getEnabledInterrupts(
    COMP_Regs *comp, uint32_t interruptMask)
{
    return (comp->CPU_INT.IMASK & interruptMask);
}

/**
 *  @brief      Check interrupt flag of enabled COMP interrupts
 *
 *  Checks if any of the COMP interrupts that were previously enabled are
 *  pending.
 *
 *  @param[in]  comp           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_COMP_INTERRUPT.
 *
 *  @return     Which of the requested COMP interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_COMP_INTERRUPT values
 *
 *  @sa         DL_COMP_enableInterrupt
 */
__STATIC_INLINE uint32_t DL_COMP_getEnabledInterruptStatus(
    COMP_Regs *comp, uint32_t interruptMask)
{
    return (comp->CPU_INT.MIS & interruptMask);
}

/**
 *  @brief      Check interrupt flag of any COMP interrupt
 *
 *  Checks if any of the COMP interrupts are pending. Interrupts do not have to
 *  be previously enabled.
 *
 *  @param[in]  comp           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_COMP_INTERRUPT.
 *
 *  @return     Which of the requested COMP interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_COMP_INTERRUPT values
 */
__STATIC_INLINE uint32_t DL_COMP_getRawInterruptStatus(
    COMP_Regs *comp, uint32_t interruptMask)
{
    return (comp->CPU_INT.RIS & interruptMask);
}

/**
 *  @brief      Get highest priority pending COMP interrupt
 *
 *  Checks if any of the COMP interrupts are pending. Interrupts do not have to
 *  be previously enabled.
 *
 *  @param[in]  comp           Pointer to the register overlay for the
 *                             peripheral
 *  @return     The highest priority pending COMP interrupt. One of @ref
 *               DL_COMP_IIDX
 */
__STATIC_INLINE DL_COMP_IIDX DL_COMP_getPendingInterrupt(COMP_Regs *comp)
{
    return (DL_COMP_IIDX)(comp->CPU_INT.IIDX);
}

/**
 *  @brief      Clear pending COMP interrupts
 *
 *  @param[in]  comp           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  interruptMask  Bit mask of interrupts to clear. Bitwise OR of
 *                             @ref DL_COMP_INTERRUPT.
 */
__STATIC_INLINE void DL_COMP_clearInterruptStatus(
    COMP_Regs *comp, uint32_t interruptMask)
{
    comp->CPU_INT.ICLR = interruptMask;
}

/**
 *  @brief Sets the COMP event publisher channel ID
 *
 *  @param[in]  comp           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  chanID         Channel ID number. Valid range 0-15.
 *                             If ChanID == 0, publisher is disconnected.
 */
__STATIC_INLINE void DL_COMP_setPublisherChanID(
    COMP_Regs *comp, uint8_t chanID)
{
    comp->FPUB_1 = (chanID & COMP_FPUB_1_CHANID_MAXIMUM);
}

/**
 *  @brief Gets the event publisher channel ID
 *
 *  @param[in]  comp           Pointer to the register overlay for the
 *                             peripheral
 *  @return     Event publisher channel ID
 *
 */
__STATIC_INLINE uint8_t DL_COMP_getPublisherChanID(COMP_Regs *comp)
{
    return ((uint8_t)((comp->FPUB_1) & COMP_FPUB_1_CHANID_MAXIMUM));
}

/**
 *  @brief      Enable COMP event
 *
 *  @param[in]  comp           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  eventMask      Bit mask of interrupts to enable. Bitwise OR of
 *                             @ref DL_COMP_EVENT.
 */
__STATIC_INLINE void DL_COMP_enableEvent(COMP_Regs *comp, uint32_t eventMask)
{
    comp->GEN_EVENT.IMASK |= (eventMask);
}

/**
 *  @brief      Disable COMP event
 *
 *  @param[in]  comp           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  eventMask      Bit mask of interrupts to enable. Bitwise OR of
 *                             @ref DL_COMP_EVENT.
 */
__STATIC_INLINE void DL_COMP_disableEvent(COMP_Regs *comp, uint32_t eventMask)
{
    comp->GEN_EVENT.IMASK &= ~(eventMask);
}

/**
 *  @brief      Check which COMP events are enabled
 *
 *  @param[in]  comp           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  eventMask      Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_COMP_EVENT.
 *
 *  @return     Which of the requested COMP interrupts are enabled
 *
 *  @retval     Bitwise OR of @ref DL_COMP_EVENT values
 */
__STATIC_INLINE uint32_t DL_COMP_getEnabledEvents(
    COMP_Regs *comp, uint32_t eventMask)
{
    return ((comp->GEN_EVENT.IMASK) & (eventMask));
}

/**
 *  @brief      Check event flag of enabled COMP event
 *
 *  Checks if any of the COMP events that were previously enabled are
 *  pending.
 *
 *  @param[in]  comp           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  eventMask      Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_COMP_EVENT.
 *
 *  @return     Which of the requested COMP interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_COMP_EVENT values
 *
 *  @sa         DL_COMP_enableInterrupt
 */
__STATIC_INLINE uint32_t DL_COMP_getEnabledEventStatus(
    COMP_Regs *comp, uint32_t eventMask)
{
    return ((comp->GEN_EVENT.MIS) & eventMask);
}

/**
 *  @brief      Check interrupt flag of any COMP event
 *
 *  Checks if any events are pending. Events do not have to
 *  be previously enabled.
 *
 *  @param[in]  comp           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  eventMask      Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_COMP_EVENT.
 *
 *  @return     Which of the requested COMP interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_COMP_EVENT values
 */
__STATIC_INLINE uint32_t DL_COMP_getRawEventsStatus(
    COMP_Regs *comp, uint32_t eventMask)
{
    return ((comp->GEN_EVENT.RIS) & eventMask);
}

/**
 *  @brief      Clear pending COMP events
 *
 *  @param[in]  comp           Pointer to the register overlay for the
 *                             peripheral
 *  @param[in]  eventMask      Bit mask of interrupts to clear. Bitwise OR of
 *                             @ref DL_COMP_EVENT.
 */
__STATIC_INLINE void DL_COMP_clearEventsStatus(
    COMP_Regs *comp, uint32_t eventMask)
{
    comp->GEN_EVENT.ICLR |= (eventMask);
}

/* clang-format on */

#ifdef __cplusplus
}
#endif

#endif /* __MSPM0_HAS_COMP__ */

#endif /* ti_dl_m0p_dl_comp__include */
/** @}*/
