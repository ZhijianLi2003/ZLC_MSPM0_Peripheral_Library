/*
 * Copyright (c) 2022-2023, Texas Instruments Incorporated
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
 *  @file       ADCMSPM0.h
 *  @brief      ADC driver implementation for the ADC peripheral on MSPM0
 *              devices
 *  @defgroup   ADCMSPM0 ADC driver APIs
 *
 *  This ADC driver implementation is designed to operate on a ADC peripheral
 *  for MSPM0 devices.
 *
 *  Refer to ADC.h for a complete description of APIs & example of use.
 *
 ******************************************************************************
 */
/** @addtogroup ADCMSPM0
 *  @ingroup ADC
* @{
*/
/* clang-format off */
#ifndef ti_drivers_adc_ADCMSPM0__include
#define ti_drivers_adc_ADCMSPM0__include

#include <stdint.h>
#include <stdbool.h>


#include <ti/drivers/ADC.h>
#include <ti/driverlib/dl_adc12.h>

#ifdef POWER_MANAGEMENT_MSPM0
#include <ti/drivers/Power.h>
#endif
#include <ti/devices/DeviceFamily.h>

#ifdef __cplusplus
extern "C" {
#endif
/*! An interrupt mask for all ADC CPU interrupts */
#define ADC_ALL_INTERRUPTS_MASK     0xFFFFFFFFUL
/*!
 *  @brief Resolution of ADC-conversion
 *
 *  This sets the resolution of the ADC conversion, and will affect how long
 *  a conversion takes.
 */
typedef enum
{
    /*! ADC resolution 12bit */
    ADCMSPM0_RESOLUTION_12_BIT = DL_ADC12_SAMP_CONV_RES_12_BIT,
    /*! ADC resolution 10bit */
    ADCMSPM0_RESOLUTION_10_BIT = DL_ADC12_SAMP_CONV_RES_10_BIT,
    /*! ADC resolution 8bit */
    ADCMSPM0_RESOLUTION_8_BIT  = DL_ADC12_SAMP_CONV_RES_8_BIT,
} ADCMSPM0_Resolution_Bits;

/*!
 *  @brief  Specifies the source of the ADC reference voltage
 *
 *  The ADC reference voltage will determine the upper limit of the input voltage.
 *
 *  @note   The actual reference values are slightly different for each device.
 *          The function ADCMSPM0_ADCValueToMicrovolts() must be used
 *          to derive actual voltage values. Do not attempt to compare raw
 *          values between devices or derive a voltage from them yourself. The
 *          results of doing so will only be approximately correct.
 *
 *  @warning    Refer to the datasheet to make sure the input voltage to the ADC
 *              never exceeds the specifies limits.
 */
typedef enum
{
    /*! ADC reference voltage VDDA */
    ADCMSPM0_VDDA_REFERENCE      = DL_ADC12_REFERENCE_VOLTAGE_VDDA,
    /*! ADC reference voltage internal */
    ADCMSPM0_INTERNAL_REFERENCE  = DL_ADC12_REFERENCE_VOLTAGE_INTREF,
    /*! ADC reference voltage external */
    ADCMSPM0_EXTERNAL_REFERENCE  = DL_ADC12_REFERENCE_VOLTAGE_EXTREF
} ADCMSPM0_Reference_Source;

/*!
 *  @brief ADC clock-divider
 *
 *  This sets the clock divider value for the ADC sample clock(SAMPCLK) which
 *  can be derived from the SYSOSC/ULPCLK/HFCLK.
 */
typedef enum
{
    /*! Do not divide clock source */
    ADCMSPM0_CLKDIV_1  = DL_ADC12_CLOCK_DIVIDE_1,
    /*! Divide clock source by 2 */
    ADCMSPM0_CLKDIV_2  = DL_ADC12_CLOCK_DIVIDE_2,
    /*! Divide clock source by 4 */
    ADCMSPM0_CLKDIV_4  = DL_ADC12_CLOCK_DIVIDE_4,
    /*! Divide clock source by 8 */
    ADCMSPM0_CLKDIV_8  = DL_ADC12_CLOCK_DIVIDE_8,
    /*! Divide clock source by 16 */
    ADCMSPM0_CLKDIV_16 = DL_ADC12_CLOCK_DIVIDE_16,
    /*! Divide clock source by 24 */
    ADCMSPM0_CLKDIV_24 = DL_ADC12_CLOCK_DIVIDE_24,
    /*! Divide clock source by 32 */
    ADCMSPM0_CLKDIV_32 = DL_ADC12_CLOCK_DIVIDE_32,
    /*! Divide clock source by 48 */
    ADCMSPM0_CLKDIV_48 = DL_ADC12_CLOCK_DIVIDE_48
} ADCMSPM0_Clock_Divider;

/*!
 *  @brief ADC clock source select
 *
 *  This selects the clock source
 */

typedef enum
{
    /*! SYSOSC is the source of ADC sample clock*/
    ADCMSPM0_CLK_SYSOSC = DL_ADC12_CLOCK_SYSOSC,
    /*! ULPCLK is the source of ADC sample clock*/
    ADCMSPM0_CLK_ULPCLK = DL_ADC12_CLOCK_ULPCLK,
    /*! HFCLK is the source of ADC sample clock*/
    ADCMSPM0_CLK_HFCLK  = DL_ADC12_CLOCK_HFCLK,
}ADCMSPM0_Clock_Select;

/*!
 *  @brief ADC clock freq range
 *
 *  This sets the clock freq range for the configured ADC clock
 */
typedef enum
{
    /*! Specifies ADC clock (ADCCLK) frequency range is from 1 MHz to 4 MHz */
    ADCMSPM0_CLK_FREQ_RANGE_1TO4    = DL_ADC12_CLOCK_FREQ_RANGE_1_TO_4,
    /*! Specifies ADC clock (ADCCLK) frequency range is from 4 MHz to 8 MHz */
    ADCMSPM0_CLK_FREQ_RANGE_4TO8    = DL_ADC12_CLOCK_FREQ_RANGE_4_TO_8,
    /*! Specifies ADC clock (ADCCLK) frequency range is from 8 MHz to 16 MHz */
    ADCMSPM0_CLK_FREQ_RANGE_8TO16   = DL_ADC12_CLOCK_FREQ_RANGE_8_TO_16,
    /*! Specifies ADC clock (ADCCLK) frequency range is from 16 MHz to 20 MHz */
    ADCMSPM0_CLK_FREQ_RANGE_16TO20  = DL_ADC12_CLOCK_FREQ_RANGE_16_TO_20,
    /*! Specifies ADC clock (ADCCLK) frequency range is from 20 MHz to 24 MHz */
    ADCMSPM0_CLK_FREQ_RANGE_20TO24  = DL_ADC12_CLOCK_FREQ_RANGE_20_TO_24,
    /*! Specifies ADC clock (ADCCLK) frequency range is from 24 MHz to 32 MHz */
    ADCMSPM0_CLK_FREQ_RANGE_24TO32  = DL_ADC12_CLOCK_FREQ_RANGE_24_TO_32,
    /*! Specifies ADC clock (ADCCLK) frequency range is from 32 MHz to 40 MHz */
    ADCMSPM0_CLK_FREQ_RANGE_32TO40  = DL_ADC12_CLOCK_FREQ_RANGE_32_TO_40,
    /*! Specifies ADC clock (ADCCLK) frequency range is from 40 MHz to 48 MHz */
    ADCMSPM0_CLK_FREQ_RANGE_40TO48  = DL_ADC12_CLOCK_FREQ_RANGE_40_TO_48,
}ADCMSPM0_Freq_Range;

/*!
 *  @brief ADC conversion mode
 *
 *  This sets the ADC conversion mode
 */
typedef enum
{
    /*! Single channel conversion selected */
    ADCMSPM0_SINGLE_CH_SINGLE_CONV          = DL_ADC12_SAMP_MODE_SINGLE,
    /*! Multi channel conversion selected */
    ADCMSPM0_MULTI_CH_SEQUENCE_CONV         = DL_ADC12_SAMP_MODE_SEQUENCE,
}ADCMSPM0_Conversion_Mode;

/*!
 *  @brief ADC Repeat conversion mode
 *
 *  This sets the ADC repeat conversion mode to enable or disable
 */
typedef enum
{
    /*! Enable the repetition of the selected conversion */
    ADCMSPM0_REPEAT_MODE_ENABLED          = DL_ADC12_REPEAT_MODE_ENABLED,
    /*! Disable the repetition of the selected conversion */
    ADCMSPM0_REPEAT_MODE_DISABLED         = DL_ADC12_REPEAT_MODE_DISABLED,
}ADCMSPM0_Repeat_Conversion_Mode;

/*!
 *  @brief ADC sampling mode
 *
 *  This sets the ADC sampling mode
 */
typedef enum
{
    /*! Timer high phase is used as source of the sample signal
    *   Internal ADC sampling timer is used in this mode. It can be
    *   selected/configured from @ref ADCMSPM0_Sample_Timer_Source.
    */
    ADCMSPM0_SAMPLING_MODE_AUTO   = DL_ADC12_SAMPLING_SOURCE_AUTO,
    /*! External or software trigger is used as source of the sample signal */
    ADCMSPM0_SAMPLING_MODE_MANUAL = DL_ADC12_SAMPLING_SOURCE_MANUAL,
} ADCMSPM0_Sampling_Mode;

/*!
 *  @brief ADC sampling trigger source
 *
 *  This sets the ADC sampling trigger source
 */
typedef enum
{
    /*! Conversion is triggered by software. */
    ADCMSPM0_SAMPLING_TRIG_SW    = DL_ADC12_TRIG_SRC_SOFTWARE,
    /*! Conversion is triggered by hardware */
    ADCMSPM0_SAMPLING_TRIG_EVENT = DL_ADC12_TRIG_SRC_EVENT,
} ADCMSPM0_Sampling_Trg;

/*!
 *  @brief ADC conversion data format
 *
 *  This sets the ADC conversion data format
 */
typedef enum
{
    /*! Results are read as binary unsigned, right aligned. */
    ADCMSPM0_CONV_DATA_FORMAT_UNSIGNED    = DL_ADC12_SAMP_CONV_DATA_FORMAT_UNSIGNED,
    /*! Result are read as signed binary (2s complement), left aligned. */
    ADCMSPM0_CONV_DATA_FORMAT_SIGNED      = DL_ADC12_SAMP_CONV_DATA_FORMAT_SIGNED,
} ADCMSPM0_Conv_Data_Format;

/*!
 *  @brief ADC sample timer source
 *
 *  Selects the source of sample timer period between SCOMP0 and
 *  SCOMP1. This selection is valid when ADCMSPM0_SAMPLING_MODE_AUTO is
 *  selected as a sampling mode from @ref ADCMSPM0_Sampling_Mode .
 */
typedef enum
{
    /*! sample adc sample timer source 0 */
    ADCMSPM0_SAMP_TMR_SOURCE_SCOMP0    = DL_ADC12_SAMPLE_TIMER_SOURCE_SCOMP0,
    /*! sample adc sample timer source 1 */
    ADCMSPM0_SAMP_TMR_SOURCE_SCOMP1    = DL_ADC12_SAMPLE_TIMER_SOURCE_SCOMP1,
} ADCMSPM0_Sample_Timer_Source;

/*!
 *  @brief ADC conversion trigger
 *
 *  Selects the source of the trigger to start next conversion
 */
typedef enum
{
    /*! ADC triggers automaticaly to the next memory conversion register */
    ADCMSPM0_NEXT_CONV_AUTO         = DL_ADC12_TRIGGER_MODE_AUTO_NEXT,
    /*! A valid trigger will step to the next memory conversion register */
    ADCMSPM0_NEXT_CONV_WITH_TRIG    = DL_ADC12_TRIGGER_MODE_TRIGGER_NEXT,
} ADCMSPM0_Conv_Trig_Src;

/*!
 *  @brief ADC HW averaging
 *
 *  Hardware Averaging enabled/disabled
 */
typedef enum
{
    /*! HW averaging mode enabled */
    ADCMSPM0_HW_AVG_ENABLED     = DL_ADC12_AVERAGING_MODE_ENABLED,
    /*! HW averaging mode disabled */
    ADCMSPM0_HW_AVG_DISABLED    = DL_ADC12_AVERAGING_MODE_DISABLED,
} ADCMSPM0_HW_Avg;

/*!
 *  @brief Hardware averager numerator.
 *
 *  Selects number of conversions to
 *  accumulate for current MEMCTLx and then it is divided by AVGD
 */
typedef enum
{
    ADCMSPM0_HW_AVG_NUM_ACC_DISABLED = DL_ADC12_HW_AVG_NUM_ACC_DISABLED,
    ADCMSPM0_HW_AVG_NUM_ACC_2        = DL_ADC12_HW_AVG_NUM_ACC_2,
    ADCMSPM0_HW_AVG_NUM_ACC_4        = DL_ADC12_HW_AVG_NUM_ACC_4,
    ADCMSPM0_HW_AVG_NUM_ACC_8        = DL_ADC12_HW_AVG_NUM_ACC_8,
    ADCMSPM0_HW_AVG_NUM_ACC_16       = DL_ADC12_HW_AVG_NUM_ACC_16,
    ADCMSPM0_HW_AVG_NUM_ACC_32       = DL_ADC12_HW_AVG_NUM_ACC_32,
    ADCMSPM0_HW_AVG_NUM_ACC_64       = DL_ADC12_HW_AVG_NUM_ACC_64,
    ADCMSPM0_HW_AVG_NUM_ACC_128      = DL_ADC12_HW_AVG_NUM_ACC_128,
}ADCMSPM0_AVGN;

/*!
 *  @brief Hardware averager denominator.
 *
 *  The number to divide the accumulated value by (this is a shift).
 */
typedef enum
{
    ADCMSPM0_HW_AVG_DEN_DIV_BY_1     = DL_ADC12_HW_AVG_DEN_DIV_BY_1,
    ADCMSPM0_HW_AVG_DEN_DIV_BY_2     = DL_ADC12_HW_AVG_DEN_DIV_BY_2,
    ADCMSPM0_HW_AVG_DEN_DIV_BY_4     = DL_ADC12_HW_AVG_DEN_DIV_BY_4,
    ADCMSPM0_HW_AVG_DEN_DIV_BY_8     = DL_ADC12_HW_AVG_DEN_DIV_BY_8,
    ADCMSPM0_HW_AVG_DEN_DIV_BY_16    = DL_ADC12_HW_AVG_DEN_DIV_BY_16,
    ADCMSPM0_HW_AVG_DEN_DIV_BY_32    = DL_ADC12_HW_AVG_DEN_DIV_BY_32,
    ADCMSPM0_HW_AVG_DEN_DIV_BY_64    = DL_ADC12_HW_AVG_DEN_DIV_BY_64,
    ADCMSPM0_HW_AVG_DEN_DIV_BY_128   = DL_ADC12_HW_AVG_DEN_DIV_BY_128,
}ADCMSPM0_AVGD;

/*!
 *  @brief ADC power down mode
 *
 *  Selects the power down mode
 */
typedef enum
{
    /*! Power down mode auto */
    ADCMSPM0_Pwr_Dn_MODE_AUTO     = DL_ADC12_POWER_DOWN_MODE_AUTO,
    /*! Power down mode manual */
    ADCMSPM0_Pwr_Dn_MODE_MANUAL   = DL_ADC12_POWER_DOWN_MODE_MANUAL,
} ADCMSPM0_Pwr_Dn_Mode;

/*!
 *  @brief Sequence start address
 *
 *  These bits select which MEMCTLx is used
 *  for single conversion or as first MEMCTL for sequence mode
 */
typedef enum
{
    ADCMSPM0_SEQ_START_ADDR_00 = DL_ADC12_SEQ_START_ADDR_00,
    ADCMSPM0_SEQ_START_ADDR_01 = DL_ADC12_SEQ_START_ADDR_01,
    ADCMSPM0_SEQ_START_ADDR_02 = DL_ADC12_SEQ_START_ADDR_02,
    ADCMSPM0_SEQ_START_ADDR_03 = DL_ADC12_SEQ_START_ADDR_03,
    ADCMSPM0_SEQ_START_ADDR_04 = DL_ADC12_SEQ_START_ADDR_04,
    ADCMSPM0_SEQ_START_ADDR_05 = DL_ADC12_SEQ_START_ADDR_05,
    ADCMSPM0_SEQ_START_ADDR_06 = DL_ADC12_SEQ_START_ADDR_06,
    ADCMSPM0_SEQ_START_ADDR_07 = DL_ADC12_SEQ_START_ADDR_07,
    ADCMSPM0_SEQ_START_ADDR_08 = DL_ADC12_SEQ_START_ADDR_08,
    ADCMSPM0_SEQ_START_ADDR_09 = DL_ADC12_SEQ_START_ADDR_09,
    ADCMSPM0_SEQ_START_ADDR_10 = DL_ADC12_SEQ_START_ADDR_10,
    ADCMSPM0_SEQ_START_ADDR_11 = DL_ADC12_SEQ_START_ADDR_11,
}ADCMSPM0_CONV_START_ADDRESS;

/*!
 *  @brief Sequence end address
 *
 *  These bits select which MEMCTLx is the
 *  last one for the sequence mode.
 */
typedef enum
{
    ADCMSPM0_SEQ_END_ADDR_00 = DL_ADC12_SEQ_END_ADDR_00,
    ADCMSPM0_SEQ_END_ADDR_01 = DL_ADC12_SEQ_END_ADDR_01,
    ADCMSPM0_SEQ_END_ADDR_02 = DL_ADC12_SEQ_END_ADDR_02,
    ADCMSPM0_SEQ_END_ADDR_03 = DL_ADC12_SEQ_END_ADDR_03,
    ADCMSPM0_SEQ_END_ADDR_04 = DL_ADC12_SEQ_END_ADDR_04,
    ADCMSPM0_SEQ_END_ADDR_05 = DL_ADC12_SEQ_END_ADDR_05,
    ADCMSPM0_SEQ_END_ADDR_06 = DL_ADC12_SEQ_END_ADDR_06,
    ADCMSPM0_SEQ_END_ADDR_07 = DL_ADC12_SEQ_END_ADDR_07,
    ADCMSPM0_SEQ_END_ADDR_08 = DL_ADC12_SEQ_END_ADDR_08,
    ADCMSPM0_SEQ_END_ADDR_09 = DL_ADC12_SEQ_END_ADDR_09,
    ADCMSPM0_SEQ_END_ADDR_10 = DL_ADC12_SEQ_END_ADDR_10,
    ADCMSPM0_SEQ_END_ADDR_11 = DL_ADC12_SEQ_END_ADDR_11,
}ADCMSPM0_CONV_END_ADDRESS;

/*!
 *  @brief  ADCMSPM0 Hardware attributes
 *  These fields are used by driverlib APIs and therefore must be populated by
 *  driverlib macro definitions.
 *  Currently the Single channel single conversion and the Repeat single channel conversion
 *  are supported. For the other conversion modes, user has to modify or add the needed parameters
 *  to below structure.
 */
typedef struct
{
    /*! Base Address of ADC instance */
    ADC12_Regs *adc;
    /*! DIO that the ADC input is routed to */
    uint8_t adcInputDIO;
    /*! Pincm value for the selected adc input pin */
    uint8_t adcInputPincm;
    /*! ADC input pin function */
    uint32_t adcInputPinMux;
    /*! DIO that the ADC positive reference is routed to */
    uint8_t adcPosRefDIO;
    /*! Pincm value for the selected adc pos ref pin */
    uint8_t adcPosRefPincm;
    /*! ADC positive reference pin function */
    uint32_t adcPosRefPinMux;
    /*! DIO that the ADC negative reference is routed to */
    uint8_t adcNegRefDIO;
    /*! Pincm value for the selected adc neg ref pin */
    uint8_t adcNegRefPincm;
    /*! ADC negative reference pin function */
    uint32_t adcNegRefPinMux;
    /*! Internal ADC channel */
    uint8_t adcChannel;
    /*! Reference voltage in microvolts*/
    uint_fast32_t refVoltage;
    /*! Reference source for the ADC to use */
    ADCMSPM0_Reference_Source refSource;
    /*! Time the ADC spends sampling, in CLK-cycles.*/
    uint16_t samplingDuration;
    /*! Resolution of ADC-conversion. */
    ADCMSPM0_Resolution_Bits resolutionBits;
    /*! ADC clock divider value */
    ADCMSPM0_Clock_Divider adcClkkDivider;
    /*! ADC clock source select */
    ADCMSPM0_Clock_Select adcClkSelect;
    /*! ADC clock freq range */
    ADCMSPM0_Freq_Range adcClkFreqRange;

    /*! Mode for ADC */
    ADCMSPM0_Conversion_Mode conversionMode;
    /*! Conversion Start Address used as an index for MEMCTLx */
    ADCMSPM0_CONV_START_ADDRESS conversionStartAddr;
    /*! Conversion End Address used as an index for MEMCTLx */
    ADCMSPM0_CONV_END_ADDRESS conversionEndAddr;
    /*! Enable repeat mode for the given conversion mode */
    ADCMSPM0_Repeat_Conversion_Mode repeatConversionMode;
    /*! Set the sampling mode to auto or manual */
    ADCMSPM0_Sampling_Mode samplingMode;
    /*! Set the sample trigger source to sw or event */
    ADCMSPM0_Sampling_Trg sampleTrigger;
    /*! Set the conversion data format signed or unsigned */
    ADCMSPM0_Conv_Data_Format conversionDataFormat;
    /*! Set the sample timer source to SCOMP0 or SCOMP1 */
    ADCMSPM0_Sample_Timer_Source sampleTimerSrc;
    /*! Select the adc conversion trigger to auto or with trigger */
    ADCMSPM0_Conv_Trig_Src conversionTrigger;
    /*! Set the hardware averaging enabled/disabled */
    ADCMSPM0_HW_Avg adcHWAveraging;
    /*! Set the hardware averaging denominator */
    ADCMSPM0_AVGD adcHwAvgDenominator;
    /*! Set the hardware averaging numerator */
    ADCMSPM0_AVGN adcHwAvgNumerator;
    /*! MEMCTLx index */
    uint8_t idxMEMCTLx;
} ADCMSPM0_HWAttrs;

/*!
 *  @brief  ADCMSPM0 Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct
{
    /*! Flag if the instance is in use */
    bool isOpen;
    /*! Flag to indicate if thread safety is ensured by the driver */
    bool isProtected;
} ADCMSPM0_Object;

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_adc_ADCMSPM0__include */
/* clang-format on */
/** @}*/
