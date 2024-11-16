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
 *  @file       metrology_calibration_defaults.h
 *  @brief      Default calibration parameters
 *
 *  @anchor metrology_calibration_defaults_h
 *  # Overview
 *
 *
 *
 *  <hr>
 ******************************************************************************/
/** @addtogroup Metrology
 * @{
 */

#ifndef _METROLOGY_CALIBRATION_DEFAULTS_H_
#define _METROLOGY_CALIBRATION_DEFAULTS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "string.h"
#include "template.h"

/*! @brief structure to store default calibration parameters    */
extern calibrationData calibrationDefaults;

/*! @brief Defines a flag data to check the availability of data in flash   */
#define CONFIG_INIT_FLAG                                (0xABCD)

/*! @brief Defines the scale factor for voltage at phase A      */
#define DEFAULT_V_RMS_SCALE_FACTOR_A                    _IQ19(PHASE_A_VOLTAGE_SCALE_FACTOR)
/*! @brief Defines the voltage DC estimate in phase A           */
#define DEFAULT_V_DC_ESTIMATE_A                         _IQ19(PHASE_A_VOLTAGE_DC_ESTIMATE)
/*! @brief Defines the voltage AC offset in phase A             */
#define DEFAULT_V_AC_OFFSET_A                           _IQ19(PHASE_A_VOLTAGE_AC_OFFSET)
/*! @brief Defines the fundamental voltage AC offset in phase A */
#define DEFAULT_V_FUNDAMENTAL_OFFSET_A                  _IQ19(PHASE_A_VOLTAGE_FUNDAMENATAL_OFFSET)
/*! @brief Defines the scale factor for voltage at phase B      */
#define DEFAULT_V_RMS_SCALE_FACTOR_B                    _IQ19(PHASE_B_VOLTAGE_SCALE_FACTOR)
/*! @brief Defines the voltage DC estimate in phase B           */
#define DEFAULT_V_DC_ESTIMATE_B                         _IQ19(PHASE_B_VOLTAGE_DC_ESTIMATE)
/*! @brief Defines the voltage AC offset in phase B             */
#define DEFAULT_V_AC_OFFSET_B                           _IQ19(PHASE_B_VOLTAGE_AC_OFFSET)
/*! @brief Defines the fundamental voltage AC offset in phaseB  */
#define DEFAULT_V_FUNDAMENTAL_OFFSET_B                  _IQ19(PHASE_B_VOLTAGE_FUNDAMENATAL_OFFSET)
/*! @brief Defines the scale factor for voltage at phase C      */
#define DEFAULT_V_RMS_SCALE_FACTOR_C                    _IQ19(PHASE_C_VOLTAGE_SCALE_FACTOR)
/*! @brief Defines the voltage DC estimate in phase C           */
#define DEFAULT_V_DC_ESTIMATE_C                         _IQ19(PHASE_C_VOLTAGE_DC_ESTIMATE)
/*! @brief Defines the voltage AC offset in phase B             */
#define DEFAULT_V_AC_OFFSET_C                           _IQ19(PHASE_C_VOLTAGE_AC_OFFSET)
/*! @brief Defines the fundamental voltage AC offset in phase B */
#define DEFAULT_V_FUNDAMENTAL_OFFSET_C                  _IQ19(PHASE_C_VOLTAGE_FUNDAMENATAL_OFFSET)
/*! @brief Defines the scale factor for current at phase A      */
#define DEFAULT_I_RMS_SCALE_FACTOR_A                    _IQ19(PHASE_A_CURRENT_SCALE_FACTOR)
/*! @brief Defines the scale factor for power at phase A        */
#define DEFAULT_P_SCALE_FACTOR_A                        _IQ10(PHASE_A_POWER_SCALE_FACTOR)
/*! @brief Defines the current DC estimate in phase A           */
#define DEFAULT_I_DC_ESTIMATE_A                         _IQ19(PHASE_A_CURRENT_DC_ESTIMATE)
/*! @brief Defines the current AC offset in phase A             */
#define DEFAULT_I_AC_OFFSET_A                           _IQ19(PHASE_A_CURRENT_AC_OFFSET)
/*! @brief Defines the fundamental current AC offset in phase A */
#define DEFAULT_I_FUNDAMENTAL_OFFSET_A                  _IQ19(PHASE_A_CURRENT_FUNDAMENATAL_OFFSET)
/*! @brief Defines the scale factor for current at phase B      */
#define DEFAULT_I_RMS_SCALE_FACTOR_B                    _IQ19(PHASE_B_CURRENT_SCALE_FACTOR)
/*! @brief Defines the scale factor for power at phase B        */
#define DEFAULT_P_SCALE_FACTOR_B                        _IQ10(PHASE_B_POWER_SCALE_FACTOR)
/*! @brief Defines the current DC estimate in phase B           */
#define DEFAULT_I_DC_ESTIMATE_B                         _IQ19(PHASE_B_CURRENT_DC_ESTIMATE)
/*! @brief Defines the current AC offset in phase B             */
#define DEFAULT_I_AC_OFFSET_B                           _IQ19(PHASE_B_CURRENT_AC_OFFSET)
/*! @brief Defines the fundamental current AC offset in phase B */
#define DEFAULT_I_FUNDAMENTAL_OFFSET_B                  _IQ19(PHASE_B_CURRENT_FUNDAMENATAL_OFFSET)
/*! @brief Defines the scale factor for current at phase C      */
#define DEFAULT_I_RMS_SCALE_FACTOR_C                    _IQ19(PHASE_C_CURRENT_SCALE_FACTOR)
/*! @brief Defines the scale factor for power at phase C        */
#define DEFAULT_P_SCALE_FACTOR_C                        _IQ10(PHASE_C_POWER_SCALE_FACTOR)
/*! @brief Defines the current DC estimate in phase C           */
#define DEFAULT_I_DC_ESTIMATE_C                         _IQ19(PHASE_C_CURRENT_DC_ESTIMATE)
/*! @brief Defines the current AC offset in phase C             */
#define DEFAULT_I_AC_OFFSET_C                           _IQ19(PHASE_C_CURRENT_AC_OFFSET)
/*! @brief Defines the fundamental current AC offset in phase C */
#define DEFAULT_I_FUNDAMENTAL_OFFSET_C                  _IQ19(PHASE_C_CURRENT_FUNDAMENATAL_OFFSET)
/*! @brief Defines the scale factor for current at neutral      */
#define DEFAULT_I_RMS_SCALE_FACTOR_NEUTRAL              _IQ19(NEUTRAL_CURRENT_SCALE_FACTOR)
/*! @brief Defines the current DC estimate in neutral           */
#define DEFAULT_I_DC_ESTIMATE_NEUTRAL                   _IQ19(NEUTRAL_CURRENT_DC_ESTIMATE)
/*! @brief Defines the current AC offset in neutral             */
#define DEFAULT_I_AC_OFFSET_NEUTRAL                     _IQ19(NEUTRAl_CURRENT_AC_OFFSET)
/*! @brief Defines the fundamental current AC offset in neutral */
#define DEFAULT_I_FUNDAMENTAL_OFFSET_NEUTRAL            _IQ19(NEUTRAL_CURRENT_FUNDAMENATAL_OFFSET)
/*! @brief Defines active power offset in phase A               */
#define DEFAULT_P_OFFSET_A                              _IQ13(PHASE_A_ACTIVE_POWER_OFFSET)
/*! @brief Defines fundamental active power offset in phase A   */
#define DEFAULT_FUNDAMENTAL_P_OFFSET_A                  _IQ13(PHASE_A_ACTIVE_POWER_FUNDAMENATAL_OFFSET)
/*! @brief Defines reactive power offset in phase A             */
#define DEFAULT_Q_OFFSET_A                              _IQ13(PHASE_A_REACTIVE_POWER_OFFSET)
/*! @brief Defines fundamental reactive power offset in phase A */
#define DEFAULT_FUNDAMENTAL_Q_OFFSET_A                  _IQ13(PHASE_A_REACTIVE_POWER_FUNDAMENATAL_OFFSET)
/*! @brief Defines active power offset in phase B               */
#define DEFAULT_P_OFFSET_B                              _IQ13(PHASE_B_ACTIVE_POWER_OFFSET)
/*! @brief Defines fundamental active power offset in phase B   */
#define DEFAULT_FUNDAMENTAL_P_OFFSET_B                  _IQ13(PHASE_B_ACTIVE_POWER_FUNDAMENATAL_OFFSET)
/*! @brief Defines reactive power offset in phase B             */
#define DEFAULT_Q_OFFSET_B                              _IQ13(PHASE_B_REACTIVE_POWER_OFFSET)
/*! @brief Defines fundamental reactive power offset in phase B */
#define DEFAULT_FUNDAMENTAL_Q_OFFSET_B                  _IQ13(PHASE_B_REACTIVE_POWER_FUNDAMENATAL_OFFSET)
/*! @brief Defines active power offset in phase C               */
#define DEFAULT_P_OFFSET_C                              _IQ13(PHASE_C_ACTIVE_POWER_OFFSET)
/*! @brief Defines fundamental active power offset in phase C   */
#define DEFAULT_FUNDAMENTAL_P_OFFSET_C                  _IQ13(PHASE_C_ACTIVE_POWER_FUNDAMENATAL_OFFSET)
/*! @brief Defines reactive power offset in phase C             */
#define DEFAULT_Q_OFFSET_C                              _IQ13(PHASE_C_REACTIVE_POWER_OFFSET)
/*! @brief Defines fundamental reactive power offset in phase C */
#define DEFAULT_FUNDAMENTAL_Q_OFFSET_C                  _IQ13(PHASE_C_REACTIVE_POWER_FUNDAMENATAL_OFFSET)
/*! @brief Defines the scale factor for power at neutral        */
#define DEFAULT_P_SCALE_FACTOR_NEUTRAL                  _IQ19(NEUTRAL_POWER_SCALE_FACTOR)
/*! @brief Defines active power offset in neutral               */
#define DEFAULT_P_OFFSET_NEUTRAL                        _IQ19(NEUTRAL_ACTIVE_POWER_OFFSET)
/*! @brief Defines reactive power offset in neutral             */
#define DEFAULT_Q_OFFSET_NEUTRAL                        _IQ19(NEUTRAL_REACTIVE_POWER_OFFSET)
/*! @brief Defines fundamental active power offset in neutral   */
#define DEFAULT_FUNDAMENTAL_P_OFFSET_NEUTRAL            _IQ19(NEUTRAL_ACTIVE_POWER_FUNDAMENTAL_OFFSET)
/*! @brief Defines fundamental reactive power offset in neutral */
#define DEFAULT_FUNDAMENTAL_Q_OFFSET_NEUTRAL            _IQ19(NEUTRAL_REACTIVE_POWER_FUNDAMENTAL_OFFSET)

/* Value is phase angle in 1/256th of a sample increments. */

/** @def DEFAULT_BASE_PHASE_A_CORRECTION
    Defines holds the value for phase correction to compensate for delay due to the current
    transformer and/or front-end circuitry at phase A. This can be set to a value that is
    in fairly acceptable range, and it will be fine tuned under phase correction during calibration. */
/*  It is set to 0 (0f * SAMPLE_RATE * PHASE_SHIFT_FIR_TABLE_ELEMENTS) when testing with simulated
 *  data as it doesn't required phase correction, any value between -125us to 125 us is acceptable and
 *  it is fine tuned during calibration, ideally it should be close to zero*/
#define DEFAULT_BASE_PHASE_A_CORRECTION             ((int) 0)//(-2.4e-06f * SAMPLE_RATE * PHASE_SHIFT_FIR_TABLE_ELEMENTS))


/** @def DEFAULT_BASE_PHASE_B_CORRECTION
    Defines holds the value for phase correction to compensate for delay due to the current
    transformer and/or front-end circuitry at phase B. This can be set to a value that is in
    fairly acceptable range, and it will be fine tuned under phase correction during calibration. */
/*  It is set to 0 (0f * SAMPLE_RATE * PHASE_SHIFT_FIR_TABLE_ELEMENTS) when testing with simulated
 *  data as it doesn't required phase correction, any value between -125us to 125 us is acceptable and
 *  it is fine tuned during calibration, ideally it should be close to zero*/
#define DEFAULT_BASE_PHASE_B_CORRECTION             ((int) 0)//(-3.9e-06f * SAMPLE_RATE * PHASE_SHIFT_FIR_TABLE_ELEMENTS))


/** @def DEFAULT_BASE_PHASE_C_CORRECTION
    Defines holds the value for phase correction to compensate for delay due to the current
    transformer and/or front-end circuitry at phase C. This can be set to a value that is in
    fairly acceptable range, and it will be fine tuned under phase correction during calibration. */
/*  It is set to 0 (0f * SAMPLE_RATE * PHASE_SHIFT_FIR_TABLE_ELEMENTS) when testing with simulated
 *  data as it doesn't required phase correction, any value between -125us to 125 us is acceptable and
 *  it is fine tuned during calibration, ideally it should be close to zero*/
#define DEFAULT_BASE_PHASE_C_CORRECTION             ((int) 0)//(1.5e-06f * SAMPLE_RATE * PHASE_SHIFT_FIR_TABLE_ELEMENTS))


/** @def DEFAULT_BASE_NEUTRAL_PHASE_CORRECTION
    Defines holds the value for phase correction to compensate for delay due to the current
    transformer and/or front-end circuitry at neutral. This can be set to a value that is in
    fairly acceptable range, and it will be fine tuned under phase correction during calibration. */
/*  It is set to 0 (0f * SAMPLE_RATE * PHASE_SHIFT_FIR_TABLE_ELEMENTS) when testing with simulated
 *  data as it doesn't required phase correction, any value between -125us to 125 us is acceptable and
 *  it is fine tuned during calibration, ideally it should be close to zero*/
#define DEFAULT_BASE_NEUTRAL_PHASE_CORRECTION       ((int) 0)//(1.5e-06f * SAMPLE_RATE * PHASE_SHIFT_FIR_TABLE_ELEMENTS))


/*! @brief Default calibration data to store in flash   */
calibrationData calibrationDefaults =
{
    {
#if defined(THREE_PHASE_SUPPORT) || defined(TWO_PHASE_SUPPORT) || defined(SPLIT_PHASE_SUPPORT) || defined(SINGLE_PHASE_SUPPORT)
        {
            {
                .IinitialDcEstimate     = DEFAULT_I_DC_ESTIMATE_A,
                .IacOffset              = DEFAULT_I_AC_OFFSET_A,
                .IFAcOffset             = DEFAULT_I_FUNDAMENTAL_OFFSET_A,
                .activePowerOffset      = DEFAULT_P_OFFSET_A,
                .reactivePowerOffset    = DEFAULT_Q_OFFSET_A,
                .FActivePowerOffset     = DEFAULT_FUNDAMENTAL_P_OFFSET_A,
                .FReactivePowerOffset   = DEFAULT_FUNDAMENTAL_Q_OFFSET_A,
                .phaseOffset            = DEFAULT_BASE_PHASE_A_CORRECTION,
                .IscaleFactor           = DEFAULT_I_RMS_SCALE_FACTOR_A,
                .PscaleFactor           = DEFAULT_P_SCALE_FACTOR_A,
            },
            .VinitialDcEstimate     = DEFAULT_V_DC_ESTIMATE_A,
            .VacOffset              = DEFAULT_V_AC_OFFSET_A,
            .VFundamentalAcOffset   = DEFAULT_V_FUNDAMENTAL_OFFSET_A,
            .VscaleFactor           = DEFAULT_V_RMS_SCALE_FACTOR_A,
        },
#endif
#if defined(THREE_PHASE_SUPPORT) || defined(TWO_PHASE_SUPPORT) || defined(SPLIT_PHASE_SUPPORT)
        {
            {
                .IinitialDcEstimate     = DEFAULT_I_DC_ESTIMATE_B,
                .IacOffset              = DEFAULT_I_AC_OFFSET_B,
                .IFAcOffset             = DEFAULT_I_FUNDAMENTAL_OFFSET_B,
                .activePowerOffset      = DEFAULT_P_OFFSET_B,
                .reactivePowerOffset    = DEFAULT_Q_OFFSET_B,
                .FActivePowerOffset     = DEFAULT_FUNDAMENTAL_P_OFFSET_B,
                .FReactivePowerOffset   = DEFAULT_FUNDAMENTAL_Q_OFFSET_B,
                .phaseOffset            = DEFAULT_BASE_PHASE_B_CORRECTION,
                .IscaleFactor           = DEFAULT_I_RMS_SCALE_FACTOR_B,
                .PscaleFactor           = DEFAULT_P_SCALE_FACTOR_B,
            },
            .VinitialDcEstimate     = DEFAULT_V_DC_ESTIMATE_B,
            .VacOffset              = DEFAULT_V_AC_OFFSET_B,
            .VFundamentalAcOffset   = DEFAULT_V_FUNDAMENTAL_OFFSET_B,
            .VscaleFactor           = DEFAULT_V_RMS_SCALE_FACTOR_B,
        },
#endif
#if defined(THREE_PHASE_SUPPORT)
        {
            {
                .IinitialDcEstimate     = DEFAULT_I_DC_ESTIMATE_C,
                .IacOffset              = DEFAULT_I_AC_OFFSET_C,
                .IFAcOffset             = DEFAULT_I_FUNDAMENTAL_OFFSET_C,
                .activePowerOffset      = DEFAULT_P_OFFSET_C,
                .reactivePowerOffset    = DEFAULT_Q_OFFSET_C,
                .FActivePowerOffset     = DEFAULT_FUNDAMENTAL_P_OFFSET_C,
                .FReactivePowerOffset   = DEFAULT_FUNDAMENTAL_Q_OFFSET_C,
                .phaseOffset            = DEFAULT_BASE_PHASE_C_CORRECTION,
                .IscaleFactor           = DEFAULT_I_RMS_SCALE_FACTOR_C,
                .PscaleFactor           = DEFAULT_P_SCALE_FACTOR_C,
            },
            .VinitialDcEstimate     = DEFAULT_V_DC_ESTIMATE_C,
            .VacOffset              = DEFAULT_V_AC_OFFSET_C,
            .VFundamentalAcOffset   = DEFAULT_V_FUNDAMENTAL_OFFSET_C,
            .VscaleFactor           = DEFAULT_V_RMS_SCALE_FACTOR_C,
        },
#endif
    },
    {
        .IinitialDcEstimate     = DEFAULT_I_DC_ESTIMATE_NEUTRAL,
        .IacOffset              = DEFAULT_I_AC_OFFSET_NEUTRAL,
        .IFAcOffset             = DEFAULT_I_FUNDAMENTAL_OFFSET_NEUTRAL,
        .activePowerOffset      = DEFAULT_P_OFFSET_NEUTRAL,
        .reactivePowerOffset    = DEFAULT_Q_OFFSET_NEUTRAL,
        .FActivePowerOffset     = DEFAULT_FUNDAMENTAL_P_OFFSET_NEUTRAL,
        .FReactivePowerOffset   = DEFAULT_FUNDAMENTAL_Q_OFFSET_NEUTRAL,
        .phaseOffset            = DEFAULT_BASE_NEUTRAL_PHASE_CORRECTION,
        .IscaleFactor           = DEFAULT_I_RMS_SCALE_FACTOR_NEUTRAL,
        .PscaleFactor           = DEFAULT_P_SCALE_FACTOR_NEUTRAL,
    },
    .structState = 0x59,
    .calibrationInitFlag = CONFIG_INIT_FLAG
};

#ifdef __cplusplus
}
#endif
#endif /* METROLOGY_CALIBRATION_DEFAULTS_H_ */
/** @}*/
