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
 *  @file       dl_opa.h
 *  @brief      Op-Amp (OPA) Driver Library
 *  @defgroup   OPA Op-Amp (OPA)
 *
 *  @anchor ti_dl_dl_opa_Overview
 *  # Overview
 *
 *  The OP-Amp Driver Library allows full configuration of the MSPM0 OPA module.
 *  The OPA is a zero-drift chopper stabilized operational amplifier with a
 *  programmable gain stage.
 *
 *  <hr>

 ******************************************************************************
 */
/** @addtogroup OPA
 * @{
 */
#ifndef ti_dl_dl_opa__include
#define ti_dl_dl_opa__include

#include <stdbool.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/dl_common.h>

#ifdef __MSPM0_HAS_OA__

#ifdef __cplusplus
extern "C" {
#endif

/*! @enum DL_OPA_CHOPPING_MODE */
typedef enum {
    /*! Disable chopping mode */
    DL_OPA_CHOPPING_MODE_DISABLE = OA_CFG_CHOP_OFF,
    /*! Enable standard chopping mode */
    DL_OPA_CHOPPING_MODE_STANDARD = OA_CFG_CHOP_ON,
    /*! Enable ADC assisted chopping mode. Requires OPA output to be
     connected to an ADC input with hardware averaging. */
    DL_OPA_CHOPPING_MODE_ADC_AVERAGING = OA_CFG_CHOP_AVGON,
} DL_OPA_CHOPPING_MODE;

/*! @enum DL_OPA_OUTPUT_PIN_STATE */
typedef enum {

    /*! Output pin is enabled */
    DL_OPA_OUTPUT_PIN_ENABLED = OA_CFG_OUTPIN_ENABLED,
    /*! Outpin pin is disabled */
    DL_OPA_OUTPUT_PIN_DISABLED = OA_CFG_OUTPIN_DISABLED,

} DL_OPA_OUTPUT_PIN_STATE;

/*! @enum DL_OPA_PSEL */
typedef enum {
    /*! Non-inverting input channel is Open */
    DL_OPA_PSEL_OPEN = OA_CFG_PSEL_NC,
    /*!  Non-inverting input is OPAx_IN0+ */
    DL_OPA_PSEL_IN0_POS = OA_CFG_PSEL_EXTPIN0,
    /*!  Non-inverting input is OPAx_IN1+ */
    DL_OPA_PSEL_IN1_POS = OA_CFG_PSEL_EXTPIN1,
    /*!  Non-inverting input is DAC_OUT */
    DL_OPA_PSEL_DAC_OUT = OA_CFG_PSEL_DAC12OUT,
    /*!  Non-inverting input is DAC8.x_OUT */
    DL_OPA_PSEL_DAC8_OUT = OA_CFG_PSEL_DAC8OUT,
    /*!  Non-inverting input is VREF */
    DL_OPA_PSEL_VREF = OA_CFG_PSEL_VREF,
    /*!  Non-inverting input is OPA[x-1]_RTOP */
    DL_OPA_PSEL_RTOP = OA_CFG_PSEL_OANM1RTOP,

    /*!  Non-inverting input is GPAMP OUT*/
    DL_OPA_PSEL_GPAMP_OUT = OA_CFG_PSEL_GPAMP_OUT_INT,
    /*!  Non-inverting input is GND */
    DL_OPA_PSEL_GND = OA_CFG_PSEL_VSS,

} DL_OPA_PSEL;

/*! @enum DL_OPA_NSEL */
typedef enum {
    /*! Inverting input channel is Open */
    DL_OPA_NSEL_OPEN = OA_CFG_NSEL_NC,
    /*! Inverting input channel is OPAx_IN0- */
    DL_OPA_NSEL_IN0_NEG = OA_CFG_NSEL_EXTPIN0,
    /*! Inverting input channel is OPAx_IN1- */
    DL_OPA_NSEL_IN1_NEG = OA_CFG_NSEL_EXTPIN1,
    /*! Inverting input channel is OPA[x-1]_RBOT */
    DL_OPA_NSEL_RBOT = OA_CFG_NSEL_OANP1RBOT,
    /*! Inverting input channel is RTAP */
    DL_OPA_NSEL_RTAP = OA_CFG_NSEL_OANRTAP,
    /*! Inverting input channel is RTOP */
    DL_OPA_NSEL_RTOP = OA_CFG_NSEL_OANRTOP,
    /*! Spare input for inverting channel */
    DL_OPA_NSEL_SPARE = OA_CFG_NSEL_SPARE,
} DL_OPA_NSEL;

/*! @enum DL_OPA_MSEL */
typedef enum {
    /*! M-MUX input channel is Open */
    DL_OPA_MSEL_OPEN = OA_CFG_MSEL_NC,
    /*! M-MUX input channel is OPAx_IN1- */
    DL_OPA_MSEL_IN1_NEG = OA_CFG_MSEL_EXTNPIN1,
    /*! M-MUX input channel is GND */
    DL_OPA_MSEL_GND = OA_CFG_MSEL_VSS,
    /*! M-MUX input channel is DAC_OUT */
    DL_OPA_MSEL_DAC_OUT = OA_CFG_MSEL_DAC12OUT,
    /*! M-MUX input channel is OPA[x-1]_RTOP */
    DL_OPA_MSEL_RTOP = OA_CFG_MSEL_OANM1RTOP,
} DL_OPA_MSEL;

/*! @enum DL_OPA_GBW */
typedef enum {
    /*! High gain bandwidth (GBW). See device specific datasheet for values. */
    DL_OPA_GBW_HIGH = OA_CFGBASE_GBW_HIGHGAIN,
    /*! Low gain bandwidth (GBW). See device specific datasheet for values. */
    DL_OPA_GBW_LOW = OA_CFGBASE_GBW_LOWGAIN,
} DL_OPA_GBW;

/*! @enum DL_OPA_GAIN */
typedef enum {
    /*! Gain value is Not Valid in Non-inverting and inverting PGA modes */
    DL_OPA_GAIN_N0_P1 = (((uint32_t) 0x0) << OA_CFG_GAIN_OFS),
    /*! Gain value is -1x in Inverting PGA mode, and 2x in Non-inverting
    * PGA mode */
    DL_OPA_GAIN_N1_P2 = (((uint32_t) 0x1) << OA_CFG_GAIN_OFS),
    /*! Gain value is -3x in Inverting PGA mode, and 4x in Non-inverting
    * PGA mode */
    DL_OPA_GAIN_N3_P4 = (((uint32_t) 0x2) << OA_CFG_GAIN_OFS),
    /*! Gain value is -7x in Inverting PGA mode, and 8x in Non-inverting
    * PGA mode */
    DL_OPA_GAIN_N7_P8 = (((uint32_t) 0x3) << OA_CFG_GAIN_OFS),
    /*! Gain value is -15x in Inverting PGA mode, and 16x in Non-inverting
    * PGA mode */
    DL_OPA_GAIN_N15_P16 = (((uint32_t) 0x4) << OA_CFG_GAIN_OFS),
    /*! Gain value is -31x in Inverting PGA mode, and 32x in Non-inverting
      * PGA mode */
    DL_OPA_GAIN_N31_P32 = (((uint32_t) 0x5) << OA_CFG_GAIN_OFS),
} DL_OPA_GAIN;

/*!
 *  @brief  Configuration struct for @ref DL_OPA_init
 */
typedef struct {
    /*! The chopping mode to set. One of @ref DL_OPA_CHOPPING_MODE */
    DL_OPA_CHOPPING_MODE choppingMode;
    /*! The state of the output pin. One of @ref DL_OPA_OUTPUT_PIN_STATE. */
    DL_OPA_OUTPUT_PIN_STATE outputPinState;
    /*! The non-inverting input channel to set. One of @ref DL_OPA_PSEL */
    DL_OPA_PSEL pselChannel;
    /*! The inverting input channel to set. One of @ref DL_OPA_NSEL */
    DL_OPA_NSEL nselChannel;
    /*! The M-MUX input channel to set. One of @ref DL_OPA_MSEL */
    DL_OPA_MSEL mselChannel;
    /*! The gain to set. Value between 0-7. */
    DL_OPA_GAIN gain;
} DL_OPA_Config;

/**
 * @brief Enables power on OPA module
 *
 * @param[in]  opa  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_OPA_enablePower(OA_Regs *opa)
{
    opa->GPRCM.PWREN = (OA_PWREN_KEY_UNLOCK_W | OA_PWREN_ENABLE_ENABLE);
}

/**
 * @brief Disables power on OPA module
 *
 * @param[in]  opa  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_OPA_disablePower(OA_Regs *opa)
{
    opa->GPRCM.PWREN = (OA_PWREN_KEY_UNLOCK_W | OA_PWREN_ENABLE_DISABLE);
}

/**
 * @brief Returns if  power on opa module
 *
 * @param[in]  opa  Pointer to the register overlay for the peripheral
 *
 * @return true if power is enabled
 * @return false if power is disabled
 */
__STATIC_INLINE bool DL_OPA_isPowerEnabled(OA_Regs *opa)
{
    return (
        (opa->GPRCM.PWREN & OA_PWREN_ENABLE_MASK) == OA_PWREN_ENABLE_ENABLE);
}

/**
 * @brief Resets OPA peripheral
 *
 * @param[in]  opa  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_OPA_reset(OA_Regs *opa)
{
    opa->GPRCM.RSTCTL = (OA_RSTCTL_KEY_UNLOCK_W | OA_RSTCTL_RESETSTKYCLR_CLR |
                         OA_RSTCTL_RESETASSERT_ASSERT);
}

/**
 * @brief Returns if OPA peripheral was reset
 *
 * @param[in]  opa  Pointer to the register overlay for the peripheral
 *
 * @return true if peripheral was reset
 * @return false if peripheral wasn't reset
 *
 */
__STATIC_INLINE bool DL_OPA_isReset(OA_Regs *opa)
{
    return ((opa->GPRCM.STAT & OA_GPRCM_STAT_RESETSTKY_MASK) ==
            OA_GPRCM_STAT_RESETSTKY_RESET);
}

/**
 *  @brief      Enable the OPA peripheral
 *
 *  @param[in]  opa  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_OPA_enable(OA_Regs *opa)
{
    opa->CTL |= OA_CTL_ENABLE_ON;
}

/**
 *  @brief      Checks if the OPA peripheral is enabled
 *
 *  @param[in]  opa  Pointer to the register overlay for the peripheral
 *
 *  @return     Returns the enabled status of the OPA
 *
 *  @retval     true  The OPA peripheral is enabled
 *  @retval     false The OPA peripheral is disabled

 */
__STATIC_INLINE bool DL_OPA_isEnabled(OA_Regs *opa)
{
    return ((opa->CTL & OA_CTL_ENABLE_MASK) == OA_CTL_ENABLE_ON);
}

/**
 *  @brief      Disable the OPA peripheral
 *
 *  @param[in]  opa  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_OPA_disable(OA_Regs *opa)
{
    opa->CTL &= ~(OA_CTL_ENABLE_MASK);
}

/**
 *  @brief      Initialize the OPA peripheral
 *
 *  Initializes all the common configurable options for the OPA peripheral. Any
 *  other custom configuration can be done after calling this API. The OPA is
 *  not enabled in this API.
 *
 *  @param[in]  opa    Pointer to the register overlay for the peripheral
 *  @param[in]  config  Configuration for OPA peripheral
 */
__STATIC_INLINE void DL_OPA_init(OA_Regs *opa, DL_OPA_Config *config)
{
    DL_Common_updateReg(&opa->CFG,
        (uint32_t) config->choppingMode | (uint32_t) config->outputPinState |
            (uint32_t) config->pselChannel | (uint32_t) config->nselChannel |
            (uint32_t) config->mselChannel | (uint32_t) config->gain,
        OA_CFG_CHOP_MASK | OA_CFG_OUTPIN_MASK | OA_CFG_PSEL_MASK |
            OA_CFG_NSEL_MASK | OA_CFG_MSEL_MASK | OA_CFG_GAIN_MASK);
}

/**
 *  @brief      Set the gain bandwidth (GBW)
 *
 *  @param[in]  opa        Pointer to the register overlay for the peripheral
 *  @param[in]  bandwidth  The gain bandwidth to set. One of @ref DL_OPA_GBW
 *
 *
 *  @pre The OPA must be ready (STAT.RDY == 1) before setting
 *       this configuration.
 *
 */
__STATIC_INLINE void DL_OPA_setGainBandwidth(
    OA_Regs *opa, DL_OPA_GBW bandwidth)
{
    opa->CFGBASE |= ((uint32_t) bandwidth);
}

/**
 *  @brief      Get the gain bandwidth (GBW)
 *
 *  @param[in]  opa   Pointer to the register overlay for the peripheral
 *
 *  @return     The current gain bandwidth
 *
 *  @retval     One of @ref DL_OPA_GBW
 */
__STATIC_INLINE DL_OPA_GBW DL_OPA_getGainBandwidth(OA_Regs *opa)
{
    uint32_t bandwidth = (opa->CFGBASE & OA_CFGBASE_GBW_MASK);

    return (DL_OPA_GBW)(bandwidth);
}

/**
 *  @brief      Enable the rail-to-rail input (RRI)
 *
 *  @param[in]  opa  Pointer to the register overlay for the peripheral
 *
 *
 *  @pre The OPA must be ready (STAT.RDY == 1) before setting
 *       this configuration.
 *
 */
__STATIC_INLINE void DL_OPA_enableRailToRailInput(OA_Regs *opa)
{
    opa->CFGBASE |= OA_CFGBASE_RRI_ON;
}

/**
 *  @brief      Checks if the the rail-to-rail input (RRI) is enabled
 *
 *  @param[in]  opa  Pointer to the register overlay for the peripheral
 *
 *  @return     Returns the rail-to-rail input status of the OPA
 *
 *  @retval     true  The rail-to-rail input is enabled
 *  @retval     false The rail-to-rail input is disabled

 */
__STATIC_INLINE bool DL_OPA_isRailToRailInputEnabled(OA_Regs *opa)
{
    return ((opa->CFGBASE &= OA_CFGBASE_RRI_MASK) == OA_CFGBASE_RRI_ON);
}

/**
 *  @brief      Disable the rail-to-rail input (RRI)
 *
 *  @param[in]  opa  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_OPA_disableRailToRailInput(OA_Regs *opa)
{
    opa->CFGBASE &= ~(OA_CFGBASE_RRI_MASK);
}

/**
 *  @brief      Set and enable the chopping mode
 *
 *  @param[in]  opa     Pointer to the register overlay for the peripheral
 *  @param[in]  mode    The chopping mode to set.
 *                      One of @ref DL_OPA_CHOPPING_MODE
 */
__STATIC_INLINE void DL_OPA_setChoppingMode(
    OA_Regs *opa, DL_OPA_CHOPPING_MODE mode)
{
    DL_Common_updateReg(&opa->CFG, (uint32_t) mode, OA_CFG_CHOP_MASK);
}

/**
 *  @brief      Get the chopping mode
 *
 *  @param[in]  opa     Pointer to the register overlay for the peripheral
 *
 *  @return     The current chopping mode
 *
 *  @retval     One of @ref DL_OPA_CHOPPING_MODE
 */
__STATIC_INLINE DL_OPA_CHOPPING_MODE DL_OPA_getChoppingMode(OA_Regs *opa)
{
    uint32_t mode = (opa->CFG & OA_CFG_CHOP_MASK);

    return (DL_OPA_CHOPPING_MODE)(mode);
}

/**
 *  @brief      Set the state of the output pin
 *
 * When the output pin is enabled, the OPA output goes to the device pin while
 * still maintaining connection to the programmable gain stage and other analog
 * peripherals.
 * When disabled, the OPA output is a purely internal signal and is internally
 * connected to the programmable gain stage and capable of being routed to
 * other on-board analog peripherals.
 *
 *  @param[in]  opa     Pointer to the register overlay for the peripheral
 *  @param[in]  state   The state to set the output pin to
 *                      One of @ref DL_OPA_OUTPUT_PIN_STATE
 */
__STATIC_INLINE void DL_OPA_setOutputPinState(
    OA_Regs *opa, DL_OPA_OUTPUT_PIN_STATE state)
{
    DL_Common_updateReg(&opa->CFG, (uint32_t) state, OA_CFG_OUTPIN_MASK);
}

/**
 *  @brief      Get the state of the output pin
 *
 * When the output pin is enabled, the OPA output goes to the device pin while
 * still maintaining connection to the programmable gain stage and other analog
 * peripherals.
 * When disabled, the OPA output is a purely internal signal and is internally
 * connected to the programmable gain stage and capable of being routed to
 * other on-board analog peripherals.
 *
 *  @param[in]  opa     Pointer to the register overlay for the peripheral
 *
 *  @return     The state of the output pin
 *
 *  @retval     One of @ref DL_OPA_OUTPUT_PIN_STATE
 */
__STATIC_INLINE DL_OPA_OUTPUT_PIN_STATE DL_OPA_getOutputPinState(OA_Regs *opa)
{
    uint32_t state = (opa->CFG & OA_CFG_OUTPIN_MASK);

    return (DL_OPA_OUTPUT_PIN_STATE)(state);
}

/**
 *  @brief      Disable the OPA output signal to be accessed by a device pin
 *
 * When disabled, the OPA output is a purely internal signal and is internally
 * connected to the programmable gain stage and capable of being routed to
 * other on-board analog peripherals.
 *
 *  @param[in]  opa  Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_OPA_disableOutputPin(OA_Regs *opa)
{
    opa->CFG &= ~(OA_CFG_OUTPIN_MASK);
}

/**
 *  @brief      Set the non-inverting input channel
 *
 *  This API sets the PSEL control bit to select the non-inverting input
 *  channel of the amplifier.
 *
 *  @param[in]  opa           Pointer to the register overlay for the peripheral
 *  @param[in]  inputChannel  The non-inverting input channel to set.
 *                            One of @ref DL_OPA_PSEL.
 */
__STATIC_INLINE void DL_OPA_setNonInvertingInputChannel(
    OA_Regs *opa, DL_OPA_PSEL inputChannel)
{
    DL_Common_updateReg(&opa->CFG, (uint32_t) inputChannel, OA_CFG_PSEL_MASK);
}

/**
 *  @brief      Get the non-inverting input channel
 *
 *  @param[in]  opa     Pointer to the register overlay for the peripheral
 *
 *  @return     The current non-inverting input channel
 *
 *  @retval     One of @ref DL_OPA_PSEL
 */
__STATIC_INLINE DL_OPA_PSEL DL_OPA_getNonInvertingInputChannel(OA_Regs *opa)
{
    uint32_t inputChannel = (opa->CFG & OA_CFG_PSEL_MASK);

    return (DL_OPA_PSEL)(inputChannel);
}

/**
 *  @brief      Set the inverting input channel
 *
 *  This API sets the NSEL control bit to select the inverting input
 *  channel of the amplifier.
 *
 *  @param[in]  opa           Pointer to the register overlay for the peripheral
 *  @param[in]  inputChannel  The inverting input channel to set.
 *                            One of @ref DL_OPA_NSEL.
 */
__STATIC_INLINE void DL_OPA_setInvertingInputChannel(
    OA_Regs *opa, DL_OPA_NSEL inputChannel)
{
    DL_Common_updateReg(&opa->CFG, (uint32_t) inputChannel, OA_CFG_NSEL_MASK);
}

/**
 *  @brief      Get the inverting input channel
 *
 *  @param[in]  opa     Pointer to the register overlay for the peripheral
 *
 *  @return     The current inverting input channel
 *
 *  @retval     One of @ref DL_OPA_NSEL
 */
__STATIC_INLINE DL_OPA_NSEL DL_OPA_getInvertingInputChannel(OA_Regs *opa)
{
    uint32_t inputChannel = (opa->CFG & OA_CFG_NSEL_MASK);

    return (DL_OPA_NSEL)(inputChannel);
}

/**
 *  @brief      Set the M-MUX input channel
 *
 *  This API sets the MSEL control bit to select the input channel for M-MUX,
 *  which is connected to the programmable gain stage resistor ladder.
 *
 *  @param[in]  opa           Pointer to the register overlay for the peripheral
 *  @param[in]  inputChannel  The M-MUX input channel to set.
 *                            One of @ref DL_OPA_MSEL.
 */
__STATIC_INLINE void DL_OPA_setMMUXInputChannel(
    OA_Regs *opa, DL_OPA_MSEL inputChannel)
{
    DL_Common_updateReg(&opa->CFG, (uint32_t) inputChannel, OA_CFG_MSEL_MASK);
}

/**
 *  @brief      Get the M-MUX input channel
 *
 *  @param[in]  opa   Pointer to the register overlay for the peripheral
 *
 *  @return     The current M-MUX input channel
 *
 *  @retval     One of @ref DL_OPA_MSEL
 */
__STATIC_INLINE DL_OPA_MSEL DL_OPA_getMMUXInputChannel(OA_Regs *opa)
{
    uint32_t inputChannel = (opa->CFG & OA_CFG_MSEL_MASK);

    return (DL_OPA_MSEL)(inputChannel);
}

/**
 *  @brief      Set the gain for the programmable gain stage
 *
 * The OPA integrates a programmable gain stage in the feedback loop to
 * configure the OPA as a PGA(programmable gain amplifier). The gain stage
 * is a feedback resistance ladder and it supports up to 32x amplification.
 *
 * Refer to the TRM for gain enumeration information.
 *
 *  @param[in]  opa   Pointer to the register overlay for the peripheral
 *  @param[in]  gain  The gain to set. One of @ref DL_OPA_GAIN.
 */
__STATIC_INLINE void DL_OPA_setGain(OA_Regs *opa, DL_OPA_GAIN gain)
{
    DL_Common_updateReg(&opa->CFG, (uint32_t) gain, OA_CFG_GAIN_MASK);
}

/**
 *  @brief      Get the gain from the programmable gain stage
*
 * Refer to the TRM for gain enumeration information.
 *
 *  @param[in]  opa   Pointer to the register overlay for the peripheral
 *
 *  @return     The gain
 *
 *  @retval     The gain. One of @ref DL_OPA_GAIN
 */
__STATIC_INLINE DL_OPA_GAIN DL_OPA_getGain(OA_Regs *opa)
{
    uint32_t gain = (opa->CFG & OA_CFG_GAIN_MASK);

    return (DL_OPA_GAIN)(gain);
}

/**
 *  @brief      Increment gain to the next @ref DL_OPA_GAIN enum value
 *
 * The OPA allows dynamic gain changes. If the gain is already at the maximum
 * setting DL_OPA_GAIN_N31_P32 (CFG.GAIN = 0x5), this function does nothing.
 *
 * Refer to the TRM for more information about changing gain dynamically.
 *
 *  @param[in]  opa   Pointer to the register overlay for the peripheral
 *
 *  @return     The gain at the end of the operation.
 *
 *  @retval     The applied gain. One of @ref DL_OPA_GAIN
 */
DL_OPA_GAIN DL_OPA_increaseGain(OA_Regs *opa);

/**
 *  @brief      Decrement gain to the next @ref DL_OPA_GAIN enum value
 *
 * The OPA allows dynamic gain changes. If the gain is at the minimum setting
 * DL_OPA_GAIN_N1_P2 (CFG.GAIN = 0x1), this function does nothing.
 *
 * Refer to the TRM for more information about changing gain dynamically.
 *
 *  @param[in]  opa   Pointer to the register overlay for the peripheral
 *
 *  @return     The gain at the end of the operation.
 *
 *  @retval     The applied gain. One of @ref DL_OPA_GAIN
 */
DL_OPA_GAIN DL_OPA_decreaseGain(OA_Regs *opa);

/**
 *  @brief      Checks if the OPA is ready
 *
 *  @param[in]  opa  Pointer to the register overlay for the peripheral
 *
 *  @return     The status of the OPA ready bit
 *
 *  @retval     true   The OPA is ready
 *  @retval     false  The OPA is not ready
 *
 */
__STATIC_INLINE bool DL_OPA_isReady(OA_Regs *opa)
{
    return ((opa->STAT & OA_STAT_RDY_MASK) == OA_STAT_RDY_TRUE);
}

#ifdef __cplusplus
}
#endif
#endif /* __MSPM0_HAS_OA__ */

#endif /* ti_dl_dl_opa__include */
/** @}*/
