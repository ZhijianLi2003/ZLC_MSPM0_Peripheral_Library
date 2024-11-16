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
 *  @file dl_dac12.h
 *  @brief 12-bit DAC Driver Library
 *  @defgroup   DAC12 Digital to Analog Converter (DAC12)
 *
 *  @anchor ti_dl_dl_dac12_Overview
 *  # Overview
 *
 *  The Digital to Analog Converter Driver Library allows full configuration of
 *  the MSPM0 DAC12 module. The DAC module is a 12-bit voltage-output
 *  digital-to-analog converter (DAC).
 *
 *  <hr>
 ******************************************************************************
 */
/** @addtogroup DAC12
 * @{
 */
#ifndef ti_dl_dl_dac12__include
#define ti_dl_dl_dac12__include

#include <stdbool.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/dl_common.h>

#ifdef __MSPM0_HAS_DAC12__

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */

/** @enum DL_DAC12_OUTPUT */
typedef enum {
    /*!  DAC output is disconnected from output pin */
    DL_DAC12_OUTPUT_DISABLED = DAC12_CTL1_OPS_NOC0,
    /*!  DAC output is available on output pin */
    DL_DAC12_OUTPUT_ENABLED = DAC12_CTL1_OPS_OUT0,
} DL_DAC12_OUTPUT;

/** @enum DL_DAC12_REPRESENTATION */
typedef enum {
    /*!  Binary representation */
    DL_DAC12_REPRESENTATION_BINARY = DAC12_CTL0_DFM_BINARY,
    /*!  Two's complement representation */
    DL_DAC12_REPRESENTATION_TWOS_COMPLEMENT = DAC12_CTL0_DFM_TWOS_COMP,
} DL_DAC12_REPRESENTATION;

/** @enum DL_DAC12_RESOLUTION */
typedef enum {
    /*!  12-bit input resolution */
    DL_DAC12_RESOLUTION_12BIT = DAC12_CTL0_RES__12BITS,
    /*!  8-bit input resolution */
    DL_DAC12_RESOLUTION_8BIT = DAC12_CTL0_RES__8BITS,
} DL_DAC12_RESOLUTION;

/** @enum DL_DAC12_AMP */
typedef enum {
    /*!  Output amplifier off with high impedance tristate output */
    DL_DAC12_AMP_OFF_TRISTATE = DAC12_CTL1_AMPHIZ_HIZ,
    /*!  Output amplifier off with output pulled to ground */
    DL_DAC12_AMP_OFF_0V = DAC12_CTL1_AMPHIZ_PULLDOWN,
    /*!  Output amplifier enabled */
    DL_DAC12_AMP_ON = DAC12_CTL1_AMPEN_ENABLE,
} DL_DAC12_AMP;

/** @enum DL_DAC12_VREF_SOURCE */
typedef enum {
    /*! Positive reference is VDDA, negative reference is VeREF- */
    DL_DAC12_VREF_SOURCE_VDDA_VEREFN = (DAC12_CTL1_REFSP_VDDA |
                                        DAC12_CTL1_REFSN_VEREFN) ,
    /*! Positive reference is VeREF+, negative reference is VeREF- */
    DL_DAC12_VREF_SOURCE_VEREFP_VEREFN = (DAC12_CTL1_REFSP_VEREFP |
                                          DAC12_CTL1_REFSN_VEREFN),
    /*! Positive reference is VDDA, negative reference is VSSA */
    DL_DAC12_VREF_SOURCE_VDDA_VSSA = (DAC12_CTL1_REFSP_VDDA |
                                      DAC12_CTL1_REFSN_VSSA),
    /*! Positive reference is VeREF+, negative reference is VSSA */
    DL_DAC12_VREF_SOURCE_VEREFP_VSSA = (DAC12_CTL1_REFSP_VEREFP |
                                        DAC12_CTL1_REFSN_VSSA),
} DL_DAC12_VREF_SOURCE;

/** @enum DL_DAC12_SAMPLETIMER */
typedef enum {
    /*!  DAC sample timer generator is disabled */
    DL_DAC12_SAMPLETIMER_DISABLE = DAC12_CTL3_STIMEN_CLR,
    /*!  DAC sample timer generator is enabled */
    DL_DAC12_SAMPLETIMER_ENABLE = DAC12_CTL3_STIMEN_SET,
} DL_DAC12_SAMPLETIMER;


/** @enum DL_DAC12_SAMPLES_PER_SECOND */
typedef enum {
    /*!  Sample Time Trigger rate of 500 Samples Per Second */
    DL_DAC12_SAMPLES_PER_SECOND_500 = DAC12_CTL3_STIMCONFIG__500SPS,
    /*!  Sample Time Trigger rate of 1,000 Samples Per Second */
    DL_DAC12_SAMPLES_PER_SECOND_1K = DAC12_CTL3_STIMCONFIG__1KSPS,
    /*!  Sample Time Trigger rate of 2,000 Samples Per Second */
    DL_DAC12_SAMPLES_PER_SECOND_2K = DAC12_CTL3_STIMCONFIG__2KSPS,
    /*!  Sample Time Trigger rate of 4,000 Samples Per Second */
    DL_DAC12_SAMPLES_PER_SECOND_4K = DAC12_CTL3_STIMCONFIG__4KSPS,
    /*!  Sample Time Trigger rate of 8,000 Samples Per Second */
    DL_DAC12_SAMPLES_PER_SECOND_8K = DAC12_CTL3_STIMCONFIG__8KSPS,
    /*!  Sample Time Trigger rate of 16,000 Samples Per Second */
    DL_DAC12_SAMPLES_PER_SECOND_16K = DAC12_CTL3_STIMCONFIG__16KSPS,
    /*!  Sample Time Trigger rate of 100,000 Samples Per Second */
    DL_DAC12_SAMPLES_PER_SECOND_100K = DAC12_CTL3_STIMCONFIG__100KSPS,
    /*!  Sample Time Trigger rate of 200,000 Samples Per Second */
    DL_DAC12_SAMPLES_PER_SECOND_200K = DAC12_CTL3_STIMCONFIG__200KSPS,
    /*!  Sample Time Trigger rate of 500,000 Samples Per Second */
    DL_DAC12_SAMPLES_PER_SECOND_500K = DAC12_CTL3_STIMCONFIG__500KSPS,
    /*!  Sample Time Trigger rate of 1,000,000 Samples Per Second */
    DL_DAC12_SAMPLES_PER_SECOND_1M = DAC12_CTL3_STIMCONFIG__1MSPS,
} DL_DAC12_SAMPLES_PER_SECOND;

/** @enum DL_DAC12_FIFO */
typedef enum {
    /*!  DAC FIFO is disabled */
    DL_DAC12_FIFO_DISABLED = DAC12_CTL2_FIFOEN_CLR,
    /*!  DAC FIFO is enabled */
    DL_DAC12_FIFO_ENABLED = DAC12_CTL2_FIFOEN_SET,
} DL_DAC12_FIFO;


/** @enum DL_DAC12_FIFO_THRESHOLD */
typedef enum {
    /*!  DAC FIFO threshold for DMA Trigger Generation where 1/4th of location are empty */
    DL_DAC12_FIFO_THRESHOLD_ONE_QTR_EMPTY = DAC12_CTL2_FIFOTH_LOW,
    /*!  DAC FIFO threshold for DMA Trigger Generation where 2/4th of locations are empty */
    DL_DAC12_FIFO_THRESHOLD_TWO_QTRS_EMPTY = DAC12_CTL2_FIFOTH_MED,
    /*!  DAC FIFO threshold for DMA Trigger Generation where 3/4th of locations are empty */
    DL_DAC12_FIFO_THRESHOLD_THREE_QTRS_EMPTY = DAC12_CTL2_FIFOTH_HIGH,
} DL_DAC12_FIFO_THRESHOLD;

/** @enum DL_DAC12_FIFO_TRIGGER */
typedef enum {
    /*!  DAC FIFO read trigger sourced from the sample time generator */
    DL_DAC12_FIFO_TRIGGER_SAMPLETIMER = DAC12_CTL2_FIFOTRIGSEL_STIM,
    /*!  DAC FIFO read trigger sourced from the hardware trigger 0 event fabric */
    DL_DAC12_FIFO_TRIGGER_HWTRIG0 = DAC12_CTL2_FIFOTRIGSEL_TRIG0,
} DL_DAC12_FIFO_TRIGGER;

/** @enum DL_DAC12_DMA_TRIGGER */
typedef enum {
    /*!  DMA trigger mechanism for DAC is disabled */
    DL_DAC12_DMA_TRIGGER_DISABLED = DAC12_CTL2_DMATRIGEN_CLR,
    /*!  DMA trigger mechanism for DAC is enabled */
    DL_DAC12_DMA_TRIGGER_ENABLED = DAC12_CTL2_DMATRIGEN_SET,
} DL_DAC12_DMA_TRIGGER;

/** @enum DL_DAC12_CALIBRATION */
typedef enum {

    /*! Factory Trim */
    DL_DAC12_CALIBRATION_FACTORY = DAC12_CALCTL_CALSEL_FACTORYTRIM,
    /*! Self Trim (last calibration result) */
    DL_DAC12_CALIBRATION_SELF = DAC12_CALCTL_CALSEL_SELFCALIBRATIONTRIM,

} DL_DAC12_CALIBRATION;

/** @addtogroup DL_DAC12_INTERRUPT
 *  @{
 */

/*!
 *  @brief Interrupt raised when the module ready event has occurred
 */
#define DL_DAC12_INTERRUPT_MODULE_READY             (DAC12_GEN_EVENT_IMASK_MODRDYIFG_SET)

/*!
 *  @brief Interrupt raised when the FIFO is empty
 */
#define DL_DAC12_INTERRUPT_FIFO_EMPTY            (DAC12_GEN_EVENT_IMASK_FIFOEMPTYIFG_SET)

/*!
 *  @brief Interrupt raised when the FIFO is 3/4th empty
 */
#define DL_DAC12_INTERRUPT_FIFO_THREE_QTRS_EMPTY   (DAC12_GEN_EVENT_IMASK_FIFO3B4IFG_SET)

/*!
 *  @brief Interrupt raised when the FIFO is 2/4ths empty
 */
#define DL_DAC12_INTERRUPT_FIFO_TWO_QTRS_EMPTY     (DAC12_GEN_EVENT_IMASK_FIFO1B2IFG_SET)

/*!
 *  @brief Interrupt raised when the FIFO is 1/4th empty
 */
#define DL_DAC12_INTERRUPT_FIFO_ONE_QTR_EMPTY      (DAC12_GEN_EVENT_IMASK_FIFO1B4IFG_SET)

/*!
 *  @brief Interrupt raised when the FIFO is full
 */
#define DL_DAC12_INTERRUPT_FIFO_FULL              (DAC12_GEN_EVENT_IMASK_FIFOFULLIFG_SET)

/*!
 *  @brief Interrupt raised when the FIFO is underrun
 *         (tried to read from an empty FIFO)
 */
#define DL_DAC12_INTERRUPT_FIFO_UNDERRUN          (DAC12_GEN_EVENT_IMASK_FIFOURUNIFG_SET)

/*!
 *  @brief Interrupt raised as an Acknowledgement to the DMA completing a
 *         transfer
 *
 *  During DMA operation only, once the DMA has performed its desired number
 *  of transfers to the FIFO, the DMA will assert a DMA done event. The DMA will
 *  also send a status, which is 0 if there is more data to send. If there is a
 *  nonzero status, and the DMA is done sending information, the DMATrigger will
 *  be disabled and this interrupt will be asserted.
 */
#define DL_DAC12_INTERRUPT_DMA_DONE                (DAC12_GEN_EVENT_IMASK_DMADONEIFG_SET)

/** @}*/

/** @addtogroup DL_DAC12_EVENT
 *  @{
 */

/*!
 *  @brief Event raised when the module ready event has occurred
 */
#define DL_DAC12_EVENT_MODULE_READY             (DAC12_GEN_EVENT_IMASK_MODRDYIFG_SET)

/*!
 *  @brief Event raised when the FIFO is empty
 */
#define DL_DAC12_EVENT_FIFO_EMPTY            (DAC12_GEN_EVENT_IMASK_FIFOEMPTYIFG_SET)

/*!
 *  @brief Event raised when the FIFO is 3/4th empty
 */
#define DL_DAC12_EVENT_FIFO_THREE_QTRS_EMPTY   (DAC12_GEN_EVENT_IMASK_FIFO3B4IFG_SET)

/*!
 *  @brief Event raised when the FIFO is 2/4ths empty
 */
#define DL_DAC12_EVENT_FIFO_TWO_QTRS_EMPTY     (DAC12_GEN_EVENT_IMASK_FIFO1B2IFG_SET)

/*!
 *  @brief Event raised when the FIFO is 1/4th empty
 */
#define DL_DAC12_EVENT_FIFO_ONE_QTR_EMPTY      (DAC12_GEN_EVENT_IMASK_FIFO1B4IFG_SET)

/*!
 *  @brief Event raised when the FIFO is full
 */
#define DL_DAC12_EVENT_FIFO_FULL              (DAC12_GEN_EVENT_IMASK_FIFOFULLIFG_SET)

/*!
 *  @brief Event raised when the FIFO is underrun
 *         (tried to read from an empty FIFO)
 */
#define DL_DAC12_EVENT_FIFO_UNDERRUN          (DAC12_GEN_EVENT_IMASK_FIFOURUNIFG_SET)

/*!
 *  @brief Event raised as an Acknowledgement to the DMA completing a
 *         transfer
 *
 *  During DMA operation only, once the DMA has performed its desired number
 *  of transfers to the FIFO, the DMA will assert a DMA done event. The DMA will
 *  also send a status, which is 0 if there is more data to send. If there is a
 *  nonzero status, and the DMA is done sending information, the DMATrigger will
 *  be disabled and this interrupt will be asserted.
 */
#define DL_DAC12_EVENT_DMA_DONE                (DAC12_GEN_EVENT_IMASK_DMADONEIFG_SET)

/** @}*/

/* clang-format on */

/*! @enum DL_DAC12_IIDX */
typedef enum {
    /*! DAC interrupt index for no interrupt pending */
    DL_DAC12_IIDX_NO_INT = DAC12_CPU_INT_IIDX_STAT_NO_INTR,
    /*! DAC interrupt index when module is ready */
    DL_DAC12_IIDX_MODULE_READY = DAC12_CPU_INT_IIDX_STAT_MODRDYIFG,
    /*! DAC interrupt index when FIFO is full */
    DL_DAC12_IIDX_FIFO_FULL = DAC12_CPU_INT_IIDX_STAT_FIFOFULLIFG,
    /*! DAC interrupt index when FIFO is 1/4 empty */
    DL_DAC12_IIDX_FIFO_1_4_EMPTY = DAC12_CPU_INT_IIDX_STAT_FIFO1B4IFG,
    /*! DAC interrupt index when FIFO is 1/2 empty */
    DL_DAC12_IIDX_FIFO_1_2_EMPTY = DAC12_CPU_INT_IIDX_STAT_FIFO1B2IFG,
    /*! DAC interrupt index when FIFO is 3/4 empty */
    DL_DAC12_IIDX_FIFO_3_4_EMPTY = DAC12_CPU_INT_IIDX_STAT_FIFO3B4IFG,
    /*! DAC interrupt index when FIFO is empty */
    DL_DAC12_IIDX_FIFO_EMPTY = DAC12_CPU_INT_IIDX_STAT_FIFOEMPTYIFG,
    /*! DAC interrupt index if there is FIFO underrun */
    DL_DAC12_IIDX_FIFO_UNDERRUN = DAC12_CPU_INT_IIDX_STAT_FIFOURUNIFG,
    /*! DAC interrupt index for DMA transfer done */
    DL_DAC12_IIDX_DMA_DONE = DAC12_CPU_INT_IIDX_STAT_DMADONEIFG
} DL_DAC12_IIDX;

/*! @enum DL_DAC12_SUBSCRIBER_INDEX */
typedef enum {
    /*! DAC12 Subscriber index 0 */
    DL_DAC12_SUBSCRIBER_INDEX_0 = 0,
} DL_DAC12_SUBSCRIBER_INDEX;

/*! @enum DL_DAC12_EVENT_ROUTE */
typedef enum {
    /*! DAC12 event route 1 */
    DL_DAC12_EVENT_ROUTE_1 = 0,
} DL_DAC12_EVENT_ROUTE;

/**
 *  @brief  Configuration struct for @ref DL_DAC12_init
 */
typedef struct {
    /*! Enables the DAC output on the device OUT pin. One of @ref DL_DAC12_OUTPUT */
    DL_DAC12_OUTPUT outputEnable;

    /*! The bit resolution. One of @ref DL_DAC12_RESOLUTION */
    DL_DAC12_RESOLUTION resolution;

    /*! The input data representation. One of @ref DL_DAC12_REPRESENTATION */
    DL_DAC12_REPRESENTATION representation;

    /*! The voltage reference. One of @ref DL_DAC12_VREF_SOURCE */
    DL_DAC12_VREF_SOURCE voltageReferenceSource;

    /*! Output amplifier setting. One of @ref DL_DAC12_AMP */
    DL_DAC12_AMP amplifierSetting;

    /*! The FIFO enable. One of @ref DL_DAC12_FIFO */
    DL_DAC12_FIFO fifoEnable;

    /*! The Read Fifo Trigger source. One of @ref DL_DAC12_FIFO_TRIGGER */
    DL_DAC12_FIFO_TRIGGER fifoTriggerSource;

    /*! The bit to enable a DMA trigger source to use the DMA instead of
     *  the CPU to input data.
     *  One of @ref DL_DAC12_DMA_TRIGGER
     */
    DL_DAC12_DMA_TRIGGER dmaTriggerEnable;

    /*! The FIFO Threshold at which the DMA Trigger is asserted.
     *  One of @ref DL_DAC12_FIFO_THRESHOLD
     */
    DL_DAC12_FIFO_THRESHOLD dmaTriggerThreshold;

    /*! Enables the sample time generator as the FIFO trigger.
     *  One of @ref DL_DAC12_SAMPLETIMER
     */
    DL_DAC12_SAMPLETIMER sampleTimeGeneratorEnable;

    /*! Rate of the sample time generator. One of @ref
     *  DL_DAC12_SAMPLES_PER_SECOND
     */
    DL_DAC12_SAMPLES_PER_SECOND sampleRate;
} DL_DAC12_Config;

/**
 *  @brief      Initialize the DAC module
 *
 *  Initializes all the common configurable options for the DAC module. Any
 *  other custom configuration can be done after this initialization.
 *  @post DAC is not enabled
 *
 *  @param[in]  dac12   Pointer to the register overlay for the peripheral
 *  @param[in]  config  Configuration for DAC12 peripheral
 */
void DL_DAC12_init(DAC12_Regs *dac12, DL_DAC12_Config *config);

/**
 * @brief Enables power on DAC12 module
 *
 * @param dac12        Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_DAC12_enablePower(DAC12_Regs *dac12)
{
    dac12->GPRCM.PWREN =
        (DAC12_PWREN_KEY_UNLOCK_W | DAC12_PWREN_ENABLE_ENABLE);
}

/**
 * @brief Disables power on dac12 module
 *
 * @param dac12        Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_DAC12_disablePower(DAC12_Regs *dac12)
{
    dac12->GPRCM.PWREN =
        (DAC12_PWREN_KEY_UNLOCK_W | DAC12_PWREN_ENABLE_DISABLE);
}

/**
 * @brief Returns if  power on dac12 module
 *
 * @param dac12        Pointer to the register overlay for the peripheral
 *
 * @return true if power is enabled
 * @return false if power is disabled
 */
__STATIC_INLINE bool DL_DAC12_isPowerEnabled(DAC12_Regs *dac12)
{
    return ((dac12->GPRCM.PWREN & DAC12_PWREN_ENABLE_MASK) ==
            DAC12_PWREN_ENABLE_ENABLE);
}

/**
 * @brief Resets dac12 peripheral
 *
 * @param dac12        Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_DAC12_reset(DAC12_Regs *dac12)
{
    dac12->GPRCM.RSTCTL =
        (DAC12_RSTCTL_KEY_UNLOCK_W | DAC12_RSTCTL_RESETSTKYCLR_CLR |
            DAC12_RSTCTL_RESETASSERT_ASSERT);
}

/**
 * @brief Returns if dac12 peripheral was reset
 *
 * @param dac12        Pointer to the register overlay for the peripheral
 *
 * @return true if peripheral was reset
 * @return false if peripheral wasn't reset
 *
 */
__STATIC_INLINE bool DL_DAC12_isReset(DAC12_Regs *dac12)
{
    return ((dac12->GPRCM.STAT & DAC12_STAT_RESETSTKY_MASK) ==
            DAC12_STAT_RESETSTKY_RESET);
}

/**
 *  @brief      Enables the DAC module
 *
 *  @param[in]  dac12    pointer to the register overlay of the peripheral
 */
__STATIC_INLINE void DL_DAC12_enable(DAC12_Regs *dac12)
{
    dac12->CTL0 |= DAC12_CTL0_ENABLE_SET;
}

/**
 *  @brief      Disables the DAC Module
 *
 *  @param[in]  dac12    pointer to the register overlay of the peripheral
 */
__STATIC_INLINE void DL_DAC12_disable(DAC12_Regs *dac12)
{
    dac12->CTL0 &= ~DAC12_CTL0_ENABLE_MASK;
}

/**
 *  @brief      Checks the enable bit of the DAC
 *
 *  @param[in]  dac12    pointer to the register overlay of the peripheral
 *
 *  @return     Whether the DAC module is enabled
 *
 *  @retval     true    Module enabled
 *  @retval     false   Module disabled
 */
__STATIC_INLINE bool DL_DAC12_isEnabled(DAC12_Regs *dac12)
{
    uint32_t t = (dac12->CTL0 & DAC12_CTL0_ENABLE_MASK);
    return (t == DAC12_CTL0_ENABLE_SET);
}

/**
 *  @brief      Sets all elements of the input data format at once
 *
 *  @param[in]  dac12    pointer to the register overlay of the peripheral
 *  @param[in]  rep      Data Representation. One of
 *                       @ref DL_DAC12_REPRESENTATION
 *  @param[in]  res      Data Resolution. One of @ref DL_DAC12_RESOLUTION
 */
__STATIC_INLINE void DL_DAC12_configDataFormat(
    DAC12_Regs *dac12, DL_DAC12_REPRESENTATION rep, DL_DAC12_RESOLUTION res)
{
    DL_Common_updateReg(&dac12->CTL0, ((uint32_t) rep | (uint32_t) res),
        DAC12_CTL0_RES_MASK | DAC12_CTL0_DFM_MASK);
}

/**
 *  @brief      Gets the currently configured amplifier setting
 *
 *  @param[in]  dac12    pointer to the register overlay of the peripheral
 *
 *  @return     Currently configured amplifier setting
 *
 *  @retval     One of @ref DL_DAC12_AMP
 */
__STATIC_INLINE DL_DAC12_AMP DL_DAC12_getAmplifier(DAC12_Regs *dac12)
{
    uint32_t ampVal =
        (dac12->CTL1 & (DAC12_CTL1_AMPEN_MASK | DAC12_CTL1_AMPHIZ_MASK));

    return (DL_DAC12_AMP)(ampVal);
}

/**
 *  @brief      Sets the DAC and output amplifer setting
 *
 *  @param[in]  dac12    pointer to the register overlay of the peripheral
 *  @param[in]  ampVal   amplifier configuration value. One of @ref DL_DAC12_AMP
 */
__STATIC_INLINE void DL_DAC12_setAmplifier(
    DAC12_Regs *dac12, DL_DAC12_AMP ampVal)
{
    DL_Common_updateReg(&dac12->CTL1, (uint32_t) ampVal,
        (DAC12_CTL1_AMPEN_MASK | DAC12_CTL1_AMPHIZ_MASK));
}

/**
 *  @brief      Gets the currently configured reference voltage source
 *
 *  @param[in]  dac12    pointer to the register overlay of the peripheral
 *
 *  @return     Currently configured reference voltage
 *
 *  @retval     Bitwise OR of @ref DL_DAC12_VREF_SOURCE
 */
__STATIC_INLINE DL_DAC12_VREF_SOURCE DL_DAC12_getReferenceVoltageSource(
    DAC12_Regs *dac12)
{
    uint32_t refsVal =
        (dac12->CTL1 & (DAC12_CTL1_REFSP_MASK | DAC12_CTL1_REFSN_MASK));

    return (DL_DAC12_VREF_SOURCE)(refsVal);
}

/**
 *  @brief      Set the reference voltage source of the DAC
 *
 *  @param[in]  dac12    pointer to the register overlay of the peripheral
 *  @param[in]  refsVal  reference voltage source. Bitwise OR of
 *                       @ref DL_DAC12_VREF_SOURCE
 */
__STATIC_INLINE void DL_DAC12_setReferenceVoltageSource(
    DAC12_Regs *dac12, DL_DAC12_VREF_SOURCE refsVal)
{
    DL_Common_updateReg(&dac12->CTL1, (uint32_t) refsVal,
        (DAC12_CTL1_REFSP_MASK | DAC12_CTL1_REFSN_MASK));
}

/**
 *  @brief      Enables the DAC output by connecting it to the OUT0 pin
 *
 *  @param[in]  dac12    pointer to the register overlay of the peripheral
 */
__STATIC_INLINE void DL_DAC12_enableOutputPin(DAC12_Regs *dac12)
{
    dac12->CTL1 |= DAC12_CTL1_OPS_OUT0;
}

/**
 *  @brief      Disable the DAC output by disconnecting it from the OUT0 pin
 *
 *  @param[in]  dac12    pointer to the register overlay of the peripheral
 */
__STATIC_INLINE void DL_DAC12_disableOutputPin(DAC12_Regs *dac12)
{
    dac12->CTL1 &= ~DAC12_CTL1_OPS_MASK;
}

/**
 *  @brief      Checks to see whether the output is connected
 *
 *  @param[in]  dac12    pointer to the register overlay of the peripheral
 *
 *  @return     Status of output connection
 *
 *  @retval     true  Output is connected
 *  @retval     false Output is not connected
 */
__STATIC_INLINE bool DL_DAC12_isOutputPinEnabled(DAC12_Regs *dac12)
{
    return ((dac12->CTL1 & DAC12_CTL1_OPS_MASK) == DAC12_CTL1_OPS_OUT0);
}

/**
 *  @brief      Enables the FIFO module
 *
 *  Enables the FIFO and the FIFO hardware control state machine
 *
 *  @param[in]  dac12    pointer to the register overlay of the peripheral
 */
__STATIC_INLINE void DL_DAC12_enableFIFO(DAC12_Regs *dac12)
{
    /* Insert value */
    dac12->CTL2 |= DAC12_CTL2_FIFOEN_SET;
}

/**
 *  @brief      Disables the FIFO
 *
 *  @param[in]  dac12    pointer to the register overlay of the peripheral
 *
 *  @sa         DL_DAC12_enableFIFO
 */
__STATIC_INLINE void DL_DAC12_disableFIFO(DAC12_Regs *dac12)
{
    /* Clear out the bit */
    dac12->CTL2 &= ~DAC12_CTL2_FIFOEN_MASK;
}

/**
 *  @brief      Checks whether the FIFO is enabled
 *
 *  @param[in]  dac12    pointer to the register overlay of the peripheral
 *
 *  @return     Current status of the FIFO
 *
 *  @retval     true    FIFO is enabled
 *  @retval     false   FIFO is not enabled
 */
__STATIC_INLINE bool DL_DAC12_isFIFOEnabled(DAC12_Regs *dac12)
{
    uint32_t t = (dac12->CTL2 & DAC12_CTL2_FIFOEN_MASK);
    return (t == DAC12_CTL2_FIFOEN_SET);
}

/**
 *  @brief      Gets the FIFO threshold
 *
 *  @param[in]  dac12    pointer to the register overlay of the peripheral
 *
 *  @return     Currently configured FIFO Threshold
 *
 *  @retval     One of @ref DL_DAC12_FIFO_THRESHOLD
 *
 *  @sa         DL_DAC12_setFIFOThreshold
 */
__STATIC_INLINE DL_DAC12_FIFO_THRESHOLD DL_DAC12_getFIFOThreshold(
    DAC12_Regs *dac12)
{
    uint32_t fifoThreshold = (dac12->CTL2 & DAC12_CTL2_FIFOTH_MASK);

    return (DL_DAC12_FIFO_THRESHOLD)(fifoThreshold);
}

/**
 *  @brief      Sets the FIFO threshold
 *
 *  Determines the FIFO threshold In case of DMA based operation,
 *  DAC generates new DMA trigger when the number of empty locations in FIFO
 *  match the selected FIFO threshold level.
 *  In the case of CPU based operation, the FIFO threshold bits are don't care
 *  and FIFO level is directly indicated through the respective bits in the
 *  RIS register
 *
 *  @param[in]  dac12       pointer to the register overlay of the peripheral
 *  @param[in]  fifoThreshold  Threshold value. One of @ref DL_DAC12_FIFO_THRESHOLD
 */
__STATIC_INLINE void DL_DAC12_setFIFOThreshold(
    DAC12_Regs *dac12, DL_DAC12_FIFO_THRESHOLD fifoThreshold)
{
    DL_Common_updateReg(
        &dac12->CTL2, (uint32_t) fifoThreshold, DAC12_CTL2_FIFOTH_MASK);
}

/**
 *  @brief      Gets the FIFO read trigger source
 *
 *  @param[in]  dac12    pointer to the register overlay of the peripheral
 *
 *  @return     Currently configured trigger source
 *
 *  @retval     One of @ref DL_DAC12_FIFO_TRIGGER
 *
 *  @sa         DL_DAC12_setFIFOTriggerSource
 */
__STATIC_INLINE DL_DAC12_FIFO_TRIGGER DL_DAC12_getFIFOTriggerSource(
    DAC12_Regs *dac12)
{
    uint32_t fifoTrig = (dac12->CTL2 & DAC12_CTL2_FIFOTRIGSEL_MASK);

    return (DL_DAC12_FIFO_TRIGGER)(fifoTrig);
}

/**
 *  @brief      Sets the FIFO read trigger source
 *
 *  Selects the source for FIFO read trigger by the DAC. When the selected FIFO
 *  read trigger is asserted, the data from FIFO (as indicated by read pointer)
 *  is moved into internal DAC data register
 *
 *  @param[in]  dac12       pointer to the register overlay of the peripheral
 *  @param[in]  fifoTrig    Read Trigger Source. One of
 *                          @ref DL_DAC12_FIFO_TRIGGER
 */
__STATIC_INLINE void DL_DAC12_setFIFOTriggerSource(
    DAC12_Regs *dac12, DL_DAC12_FIFO_TRIGGER fifoTrig)
{
    DL_Common_updateReg(
        &dac12->CTL2, (uint32_t) fifoTrig, DAC12_CTL2_FIFOTRIGSEL_MASK);
}

/**
 *  @brief      Enables the DMA trigger generator
 *
 *  When this is and the FIFO are enabled, the DMA trigger is generated based
 *  on the empty FIFO locations qualified by the selected FIFO Threshold
 *  settings. This bit is automatically cleared by hardware when the DMA done
 *  event is asserted with DMA status signal value being nonzero
 *
 *  @param[in]  dac12    pointer to the register overlay of the peripheral
 *
 *  @sa         DL_DAC12_enableFIFO
 *  @sa         DL_DAC12_setFIFOThreshold
 */
__STATIC_INLINE void DL_DAC12_enableDMATrigger(DAC12_Regs *dac12)
{
    /* Insert value */
    dac12->CTL2 |= DAC12_CTL2_DMATRIGEN_SET;
}

/**
 *  @brief      Disables the DMA trigger generator
 *
 *  @param[in]  dac12    pointer to the register overlay of the peripheral
 *
 *  @sa         DL_DAC12_enableDMATriggerGenerator
 */
__STATIC_INLINE void DL_DAC12_disableDMATrigger(DAC12_Regs *dac12)
{
    /* Clear out the bit */
    dac12->CTL2 &= ~DAC12_CTL2_DMATRIGEN_MASK;
}

/**
 *  @brief      Checks whether the DMA trigger generator is enabled
 *
 *  @param[in]  dac12    pointer to the register overlay of the peripheral
 *
 *  @return     Current status of the DMA trigger generator
 *
 *  @retval     true   DMA Trigger enabled
 *  @retval     false  DMA Trigger not enabled
 */
__STATIC_INLINE bool DL_DAC12_isDMATriggerEnabled(DAC12_Regs *dac12)
{
    uint32_t t = (dac12->CTL2 & DAC12_CTL2_DMATRIGEN_MASK);
    return (t == DAC12_CTL2_DMATRIGEN_SET);
}

/**
 *  @brief      Enables the sample time generator
 *
 *  The sample time generator can be selected as the FIFO Trigger @ref
 *  DL_DAC12_setFIFOTriggerSource and control the rate at which the DAC will
 *  consume inputs from the FIFO
 *
 *  @param[in]  dac12    pointer to the register overlay of the peripheral
 */
__STATIC_INLINE void DL_DAC12_enableSampleTimeGenerator(DAC12_Regs *dac12)
{
    /* Insert value */
    dac12->CTL3 |= DAC12_CTL3_STIMEN_SET;
}

/**
 *  @brief      Disables the sample time generator
 *
 *  @param[in]  dac12    pointer to the register overlay of the peripheral
 *
 *  @sa         DL_DAC12_enableSampleTimeGenerator
 */
__STATIC_INLINE void DL_DAC12_disableSampleTimeGenerator(DAC12_Regs *dac12)
{
    /* Clear out the bit */
    dac12->CTL3 &= ~DAC12_CTL3_STIMEN_MASK;
}

/**
 *  @brief      Checks whether the sample time trigger generator is enabled
 *
 *  @param[in]  dac12    pointer to the register overlay of the peripheral
 *
 *  @return     Current status of the sample time generator
 *
 *  @retval     true  Sample time generator is enabled
 *  @retval     false Sample time generator is not enabled
 */
__STATIC_INLINE bool DL_DAC12_isSampleTimeGeneratorEnabled(DAC12_Regs *dac12)
{
    uint32_t t = (dac12->CTL3 & DAC12_CTL3_STIMEN_MASK);
    return (t == DAC12_CTL3_STIMEN_SET);
}

/**
 *  @brief      Gets the sample trigger rate of the sample time generator
 *
 *  @param[in]  dac12    pointer to the register overlay of the peripheral
 *
 *  @return     Currently configured sample rate
 *
 *  @retval     One of @ref DL_DAC12_SAMPLES_PER_SECOND
 */
__STATIC_INLINE DL_DAC12_SAMPLES_PER_SECOND DL_DAC12_getSampleRate(
    DAC12_Regs *dac12)
{
    uint32_t sampleRate = (dac12->CTL3 & DAC12_CTL3_STIMCONFIG_MASK);

    return (DL_DAC12_SAMPLES_PER_SECOND)(sampleRate);
}

/**
 *  @brief      Sets the sample triggering rate of the sample time generator
 *
 *  Sets the sample trigger rate of the sample time generator.
 *  The sample time generator can be selected as the FIFO Trigger @ref
 *  DL_DAC12_setFIFOTriggerSource and control the rate at which the DAC will
 *  consume inputs from the FIFO
 *
 *  @param[in]  dac12       pointer to the register overlay of the peripheral
 *  @param[in]  sampleRate  Desired sample rate. One of
 *                          @ref DL_DAC12_SAMPLES_PER_SECOND
 */
__STATIC_INLINE void DL_DAC12_setSampleRate(
    DAC12_Regs *dac12, DL_DAC12_SAMPLES_PER_SECOND sampleRate)
{
    DL_Common_updateReg(
        &dac12->CTL3, (uint32_t) sampleRate, DAC12_CTL3_STIMCONFIG_MASK);
}

/**
 *  @brief      Checks whether a calibration sequence is currently running
 *
 *  @param[in]  dac12    pointer to the register overlay of the peripheral
 *
 *  @return     Current status of an active calibration sequence
 *
 *  @retval     true  Calibration Sequence is currently running
 *  @retval     false Calibration Sequence is not running
 *
 *  @sa         DL_DAC12_startCalibration
 */
__STATIC_INLINE bool DL_DAC12_isCalibrationRunning(DAC12_Regs *dac12)
{
    uint32_t t = (dac12->CALCTL & DAC12_CALCTL_CALON_MASK);
    return (t == DAC12_CALCTL_CALON_ACTIVE);
}

/**
 *  @brief      Initiates the DAC offset error calibration sequence
 *
 *  Initiates the DAC offset error calibration sequence and
 *  the CALON_ACTIVE bit is automatically reset when the offset error
 *  calibration completes. Upon completion, the correct calibration will be put
 *  into the CALDATA register. This sequence can be started either on the fly
 *  (once the module is ready) or during setup (where this is called directy
 *  after enabling the DAC).
 *
 *  In order for the calibration to be successful, the AMP must already be
 *  configured and the LOCK bit must be cleared for the value to be written
 *  successfully. The output is also tri-stated during calibration.
 *
 *  A negative offset will mean that low input values will have a output of 0.
 *  A positive offset will mean that an input of 0 will result in a non-zero
 *  output.
 *
 *  @param[in]  dac12   pointer to the register overlay of the peripheral
 */
__STATIC_INLINE void DL_DAC12_startCalibration(DAC12_Regs *dac12)
{
    dac12->CALCTL =
        (DAC12_CALCTL_CALON_ACTIVE | DAC12_CALCTL_CALSEL_SELFCALIBRATIONTRIM);
}

/**
 *  @brief      Gets the DAC Calibration offset
 *
 *  Reads of the CALDATA register should only be performed after the
 *  calibration sequence has completed. During calibration, this register is
 *  continuously written to, and inaccurate values could be obtained.
 *
 *  @param[in]  dac12 pointer to the register overlay of the peripheral
 *
 *  @return     Current error calibration offset
 *
 *  @retval     -64 to +63 in two's complement
 */
__STATIC_INLINE uint32_t DL_DAC12_getCalibrationData(DAC12_Regs *dac12)
{
    return (dac12->CALDATA & DAC12_CALDATA_DATA_MASK);
}

/**
 *  @brief      Perform calibration sequence
 *
 *  Enables writes, and then starts the calibration sequence. Should only be
 *  called after the DAC module is enabled. This will only return when the
 *  calibration sequence has completed.
 *
 *  @pre Amplifier settings should be configured. @ref DL_DAC12_setAmplifier
 *  @post Calibration is complete, and CALDATA is locked to prevent writes.
 *
 *  @param[in]  dac12   pointer to the register overlay of the peripheral
 */
void DL_DAC12_performSelfCalibrationBlocking(DAC12_Regs *dac12);

/**
 *  @brief      Outputs an 8-bit data value
 *
 *  Using the CPU to control the DAC, this register can be written to if a
 *  fixed output voltage is desired (ex. DC Generation) with the FIFO disabled,
 *  or it can write with variable output (ex. AC Generation) by enabling the
 *  FIFO and writing to this register. The value will then be written to the
 *  FIFO internally. With FIFO enabled with @ref DL_DAC12_enableFIFO, the
 *  FIFO-specific interrupts will be generated inside the DAC.
 *
 *  The DMA trigger generation mechanism must be kept disabled when CPU is used
 *  to load data into DAC
 *
 *  @param[in]  dac12       pointer to the register overlay of the peripheral
 *  @param[in]  dataValue   value to be written to the bit-field from 0x0 to
 *                          0xFF. It can be either binary or two's complement
 */
__STATIC_INLINE void DL_DAC12_output8(DAC12_Regs *dac12, uint8_t dataValue)
{
    dac12->DATA0 = dataValue;
}

/**
 *  @brief      Outputs a 12-bit Data Value
 *
 *  Using the CPU to control the DAC, this register can be written to if a
 *  fixed output voltage is desired (ex. DC Generation) with the FIFO disabled,
 *  or it can write with variable output (ex. AC Generation) by enabling the
 *  FIFO and writing to this register. The value will then be written to the
 *  FIFO internally. With FIFO enabled with @ref DL_DAC12_enableFIFO, the
 *  FIFO-specific interrupts will be generated inside the DAC.
 *
 *  The DMA trigger generation mechanism must be kept disabled when CPU is used
 *  to load data into DAC
 *
 *  @param[in]  dac12       pointer to the register overlay of the peripheral
 *  @param[in]  dataValue   value to be written to the bit-field from 0x0 to
 *                          0xFFF. It can be either binary or two's complement
 */
__STATIC_INLINE void DL_DAC12_output12(DAC12_Regs *dac12, uint32_t dataValue)
{
    dac12->DATA0 = (dataValue & DAC12_DATA0_DATA_VALUE_MASK);
}

/**
 *  @brief      Fills the DAC fifo with 8-bit data values from the buffer
 *
 *  Writes as many values from the data buffer to the FIFO as possible,
 *  and then exits when either the count is matched or the FIFO is full.
 *
 *  @param[in]  dac12       pointer to the register overlay of the peripheral
 *  @param[in]  buffer      array containing the data values (0x00 - 0xFF) to
 *                          be written
 *  @param[in]  count       length of the buffer, or maximum desired transfer
 *
 *  @return     Count successfully transferred to the FIFO
 *
 *  @retval     0 - max(number of empty fifo slots, count)
 */
uint32_t DL_DAC12_fillFIFO8(
    DAC12_Regs *dac12, uint8_t *buffer, uint32_t count);

/**
 *  @brief      Fills the DAC fifo with 12-bit data values from the buffer
 *
 *  Writes as many values from the data buffer to the FIFO as possible,
 *  and then exits when either the count is matched or the FIFO is full.
 *
 *  @param[in]  dac12       pointer to the register overlay of the peripheral
 *  @param[in]  buffer      array containing the data values (0x00 - 0xFFF) to
 *                          be written
 *  @param[in]  count       length of the buffer, or maximum desired transfer
 *
 *  @return     Count successfully transfered to the FIFO
 *
 *  @retval     0 - max(number of empty fifo slots, count)
 */
uint32_t DL_DAC12_fillFIFO12(
    DAC12_Regs *dac12, uint16_t *buffer, uint32_t count);

/**
 *  @brief      Blocking 8-bit output to the DAC FIFO
 *
 *  Waits until the FIFO is not full, then writes a single value
 *
 *  @param[in]  dac12        pointer to the register overlay of the peripheral
 *  @param[in]  data         data value (0x00 - 0xFF) to be written
 */
void DL_DAC12_outputBlocking8(DAC12_Regs *dac12, uint8_t data);

/**
 *  @brief      Blocking 12-bit output to the DAC FIFO
 *
 *  Waits until the FIFO is not full, then writes a single value
 *
 *  @param[in]  dac12        pointer to the register overlay of the peripheral
 *  @param[in]  data         data value (0x000 - 0xFFF) to be written
 */
void DL_DAC12_outputBlocking12(DAC12_Regs *dac12, uint16_t data);

/**
 *  @brief      Checks the raw interrupt status of one or more interrupts
 *
 *  The raw interrupt status is independent of whether a specific interrupt is
 *  enabled.
 *
 *  @param[in]  dac12         pointer to the register overlay of the peripheral
 *  @param[in]  interruptMask the desired interrupt(s). One or more of
 *                            @ref DL_DAC12_INTERRUPT
 *
 *  @return     currently asserted interrupts (whether enabled or not) bit-wise
 *              AND with the inputted interrupts
 *
 *  @retval     0       no interrupts that were inputted are currently asserted
 *  @retval     not 0   a bit-wise OR of the inputted @ref DL_DAC12_INTERRUPT
 *                      registers that are currently asserted.
 */
__STATIC_INLINE uint32_t DL_DAC12_getInterruptStatus(
    DAC12_Regs *dac12, uint32_t interruptMask)
{
    return (dac12->CPU_INT.RIS & interruptMask);
}

/**
 *  @brief      Clears the interrupt status of one or more interrupts
 *
 *  Accesses the write only interrupt clear (ICLR) register and writes a 1 to
 *  the bits specified. Any bit that has 1 written to it will clear that pending
 *  interrupt if it is currently pending.
 *
 *  @param[in]  dac12         pointer to the register overlay of the peripheral
 *  @param[in]  interruptMask the desired interrupt(s). One or more of
 *                            @ref DL_DAC12_INTERRUPT
 */
__STATIC_INLINE void DL_DAC12_clearInterruptStatus(
    DAC12_Regs *dac12, uint32_t interruptMask)
{
    dac12->CPU_INT.ICLR = interruptMask;
}

/**
 *  @brief      Enables one or more interrupts
 *
 *  Access and write to the IMASK register to enable the interrupts specified.
 *
 *  @param[in]  dac12         pointer to the register overlay of the peripheral
 *  @param[in]  interruptMask the desired interrupt(s). One or more of
 *                            @ref DL_DAC12_INTERRUPT
 */
__STATIC_INLINE void DL_DAC12_enableInterrupt(
    DAC12_Regs *dac12, uint32_t interruptMask)
{
    dac12->CPU_INT.IMASK |= interruptMask;
}

/**
 *  @brief      Disables one or more interrupts
 *
 *  Access and write to the IMASK register to disable the interrupts specified.
 *
 *  @param[in]  dac12         pointer to the register overlay of the peripheral
 *  @param[in]  interruptMask the desired interrupt(s). One or more of
 *                            @ref DL_DAC12_INTERRUPT
 */
__STATIC_INLINE void DL_DAC12_disableInterrupt(
    DAC12_Regs *dac12, uint32_t interruptMask)
{
    dac12->CPU_INT.IMASK &= ~interruptMask;
}

/**
 *  @brief      Gets the highest priority pending interrupt
 *
 *  Accesses and reads the IIDX register to obtain the highest currently
 *  pending interrupt. Interrupts with lower offsets (and smaller values) are
 *  higher priority than interrupts with higher offsets (and larger values).
 *  In order for the interrupt to be pending, it must have been enabled and
 *  asserted. Clearing the interrupt should will un-pend the interrupt.
 *
 *  @param[in]  dac12        pointer to the register overlay of the peripheral
 *
 *  @return     highest priority pending interrupt
 *
 *  @retval     One of @ref DL_DAC12_IIDX
 */
__STATIC_INLINE DL_DAC12_IIDX DL_DAC12_getPendingInterrupt(DAC12_Regs *dac12)
{
    return ((DL_DAC12_IIDX) dac12->CPU_INT.IIDX);
}

/**
 *  @brief      Checks if the DAC FIFO is currently full
 *
 *  Accesses the raw interrupt status (RIS) register in order to get the
 *  current state of the FIFOFull Interrupt flag.
 *
 *  @param[in]  dac12        pointer to the register overlay of the peripheral
 *
 *  @return     status of FIFO full interrupt flag
 *
 *  @retval     true   FIFO is currently full
 *  @retval     false  FIFO is not full
 */
__STATIC_INLINE bool DL_DAC12_isFIFOFull(DAC12_Regs *dac12)
{
    uint32_t t =
        DL_DAC12_getInterruptStatus(dac12, DL_DAC12_INTERRUPT_FIFO_FULL);
    return (t == DL_DAC12_INTERRUPT_FIFO_FULL);
}

/**
 *  @brief Sets the event publisher channel id
 *
 *  @param[in]  dac12 Pointer to the register overlay for the
 *                      peripheral
 *  @param[in]  chanID  Channel ID number. Valid range 0-15. If ChanID == 0
 *                      publisher is disconnected.
 */
__STATIC_INLINE void DL_DAC12_setPublisherChanID(
    DAC12_Regs *dac12, uint8_t chanID)
{
    dac12->FPUB_1 = (chanID & DAC12_FPUB_1_CHANID_MAXIMUM);
}

/**
 *  @brief Gets the event publisher channel id
 *
 *  @param[in]  dac12 Pointer to the register overlay for the
 *                      peripheral
 *  @return     Event publisher channel ID
 *
 */
__STATIC_INLINE uint8_t DL_DAC12_getPublisherChanID(DAC12_Regs *dac12)
{
    return ((uint8_t)((dac12->FPUB_1) & DAC12_FPUB_1_CHANID_MASK));
}

/**
 *  @brief Sets the event subscriber channel id
 *
 *  @param[in]  dac12 Pointer to the register overlay for the
 *                      peripheral
 *  @param[in]  index   Specifies the register event index to be configured
 *  @param[in]  chanID  Channel ID number. Valid range 0-15. If ChanID == 0
 *                      subscriber is disconnected.
 */
__STATIC_INLINE void DL_DAC12_setSubscriberChanID(
    DAC12_Regs *dac12, DL_DAC12_SUBSCRIBER_INDEX index, uint8_t chanID)
{
    volatile uint32_t *pReg = &dac12->FSUB_0;

    *(pReg + (uint32_t) index) = (chanID & DAC12_FSUB_0_CHANID_MAXIMUM);
}

/**
 *  @brief Gets the event subscriber channel id
 *
 *  @param[in]  dac12 Pointer to the register overlay for the peripheral
 *  @param[in]  index  Specifies the register event index to be configured
 *
 *  @return     Event subscriber channel ID
 *
 */
__STATIC_INLINE uint8_t DL_DAC12_getSubscriberChanID(
    DAC12_Regs *dac12, DL_DAC12_SUBSCRIBER_INDEX index)
{
    volatile uint32_t *pReg = &dac12->FSUB_0;

    return ((uint8_t)(*(pReg + (uint32_t) index) & DAC12_FSUB_0_CHANID_MASK));
}

/**
 *  @brief      Enable DAC event
 *
 *  @param[in]  dac12        Pointer to the register overlay for the peripheral
 *  @param[in]  eventMask      Bit mask of interrupts to enable. Bitwise OR of
 *                             @ref DL_DAC12_EVENT.
 */
__STATIC_INLINE void DL_DAC12_enableEvent(
    DAC12_Regs *dac12, uint32_t eventMask)
{
    dac12->GEN_EVENT.IMASK |= (eventMask);
}

/**
 *  @brief      Disable DAC event
 *
 *  @param[in]  dac12        Pointer to the register overlay for the peripheral
 *  @param[in]  eventMask      Bit mask of interrupts to enable. Bitwise OR of
 *                             @ref DL_DAC12_EVENT.
 */
__STATIC_INLINE void DL_DAC12_disableEvent(
    DAC12_Regs *dac12, uint32_t eventMask)
{
    dac12->GEN_EVENT.IMASK &= ~(eventMask);
}

/**
 *  @brief      Check which DAC events are enabled
 *
 *  @param[in]  dac12        Pointer to the register overlay for the peripheral
 *  @param[in]  eventMask      Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_DAC12_EVENT.
 *
 *  @return     Which of the requested DAC interrupts are enabled
 *
 *  @retval     Bitwise OR of @ref DL_DAC12_EVENT values
 */
__STATIC_INLINE uint32_t DL_DAC12_getEnabledEvents(
    DAC12_Regs *dac12, uint32_t eventMask)
{
    return ((dac12->GEN_EVENT.IMASK) & (eventMask));
}

/**
 *  @brief      Check event flag of enabled DAC event
 *
 *  Checks if any of the DAC events that were previously enabled are
 *  pending.
 *
 *  @param[in]  dac12        Pointer to the register overlay for the peripheral
 *  @param[in]  eventMask      Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_DAC12_EVENT.
 *
 *  @return     Which of the requested DAC interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_DAC12_EVENT values
 *
 *  @sa         DL_DAC12_enableInterrupt
 */
__STATIC_INLINE uint32_t DL_DAC12_getEnabledEventStatus(
    DAC12_Regs *dac12, uint32_t eventMask)
{
    return ((dac12->GEN_EVENT.MIS) & eventMask);
}

/**
 *  @brief      Check interrupt flag of any DAC event
 *
 *  Checks if any events are pending. Events do not have to
 *  be previously enabled.
 *
 *  @param[in]  dac12        Pointer to the register overlay for the peripheral
 *  @param[in]  eventMask      Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_DAC12_EVENT.
 *
 *  @return     Which of the requested DAC interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_DAC12_EVENT values
 */
__STATIC_INLINE uint32_t DL_DAC12_getRawEventsStatus(
    DAC12_Regs *dac12, uint32_t eventMask)
{
    return ((dac12->GEN_EVENT.RIS) & eventMask);
}

/**
 *  @brief      Clear pending DAC events
 *
 *  @param[in]  dac12        Pointer to the register overlay for the peripheral
 *  @param[in]  eventMask  Bit mask of interrupts to clear. Bitwise OR of
 *                             @ref DL_DAC12_EVENT.
 */
__STATIC_INLINE void DL_DAC12_clearEventsStatus(
    DAC12_Regs *dac12, uint32_t eventMask)
{
    dac12->GEN_EVENT.ICLR |= (eventMask);
}

#ifdef __cplusplus
}
#endif
#endif /* __MSPM0_HAS_DAC12__ */

#endif /* ti_dl_dl_dac12__include */
/** @}*/
