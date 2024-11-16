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
 *  @file       metrology_structs.h
 *  @brief      Structures in metrology module
 *
 *  @anchor metrology_structs_h
 *  # Overview
 *
 *  Structures in metrology module
 *
 *  <hr>
 ******************************************************************************/
/** @addtogroup Metrology
 * @{
 */

#ifndef METROLOGY_STRUCTS_H_
#define METROLOGY_STRUCTS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "metrology_nv_structs.h"

/*! @brief Define Phase Readings    */
typedef struct
{
    /*! @brief The RMS voltage, in volts (IQ19 format) */
    _iq19 RMSVoltage;
    /*! @brief The RMS voltage, in volts (IQ19 format) */
    _iq19 RMSVoltageCycle;
    /*! @brief The RMS current, in amps  (IQ19 format) */
    _iq19 RMSCurrent;
    /*! @brief The active power, in watts (IQ13 format) */
    _iq13 activePower;
    /*! @brief The reactive power, in VAR (IQ13 format) */
    _iq13 reactivePower;
    /*! @brief The apparent power, in VA  (IQ13 format) */
    _iq13 apparentPower;
    /*! @brief The fundamental RMS voltage, in volts (IQ19 format) */
    _iq19 FRMSVoltage;
    /*! @brief The fundamental RMS current, in amps  (IQ19 format) */
    _iq19 FRMSCurrent;
    /*! @brief The fundamental active power, in watts (IQ13 format) */
    _iq13 FActivePower;
    /*! @brief The fundamental reactive power, in VAR (IQ13 format) */
    _iq13 FReactivePower;
    /*! @brief The fundamental reactive power, in VA  (IQ13 format) */
    _iq13 FApparentPower;
    /*! @brief The THD in the voltage waveform in IQ19 format  */
    _iq19 voltageTHD;
    /*! @brief The THD in the current waveform in IQ19 format  */
    _iq19 currentTHD;
    /*! @brief The power factor, in IQ13 format */
    _iq13 powerFactor;
    /*! @brief The angle between voltage and current in IQ15 format
               angle = power fcator angle * 180 /2^15  */
    _iq15 powerFactorAngle;
    /*! @brief The under deviation from the mains nominal voltage in percentage (IQ19 format) */
    _iq19 underdeviation;
    /*! @brief The over deviation from the mains nominal voltage in percentage (IQ19 format) */
    _iq19 overdeviation;
    /*! @brief The mains frequency, in IQ 15 format */
    _iq15 frequency;
    /*! @brief The phase difference between the current phase and the previous one in IQ15 format
        angle = phase_to_phase_ange * 180°/ 2^15  */
    _iq15 phasetoPhaseAngle;
}phaseReadings;

/*! @brief Defines neutral readings */
typedef struct
{
    /*! @brief The RMS current, in steps of 1uA */
    _iq19 RMSCurrent;
}neutralReadings;

/*! @brief Defines Total Power readings */
typedef struct
{
    /*! @brief Total Active Power   */
    _iq13 activePower;
    /*! @brief Total Reactive Power   */
    _iq13 reactivePower;
    /*! @brief Total Apparent Power   */
    _iq13 apparentPower;
    /*! @brief Total Fundamental Active Power   */
    _iq13 fundamentalActivePower;
    /*! @brief Total Fundamental Reactive Power   */
    _iq13 fundamentalReactivePower;
    /*! @brief Total Fundamental Apparent Power   */
    _iq13 fundamentalApparentPower;
}TotalPowerReadings;

/*! @brief Defines energy integrator parameters */
typedef struct
{
    /*! @brief energy accumulated   */
    uint64_t  energy;
    /*! @brief The residual fraction of an energy increment left over after integration */
    _iq13     energyResidual;
}energyIntegrator;

/*! @brief Defines Line Parameters  */
typedef struct
{
    /*! @brief Line to Line RMS Voltage */
    _iq19 LLRMSVoltage_ab;
    /*! @brief Line to Line Fundamental RMS Voltage */
    _iq19 FLLRMSVoltage_ab;
    /*! @brief Line to Line RMS Voltage */
    _iq19 LLRMSVoltage_bc;
    /*! @brief Line to Line Fundamental RMS Voltage */
    _iq19 FLLRMSVoltage_bc;
    /*! @brief Line to Line RMS Voltage */
    _iq19 LLRMSVoltage_ca;
    /*! @brief Line to Line Fundamental RMS Voltage */
    _iq19 FLLRMSVoltage_ca;
}LLReadings;

/*! @brief Defines Phase Correction Parameters  */
typedef struct
{
    /*! @brief Phase correction steps */
    int8_t step;
    /*! @brief Phase correction beta */
    _iq15 firBeta;
    /*! @brief Phase correction gain */
    _iq14 firGain;
}phaseCorrection;

/*! @brief Defines current dot product set  */
typedef struct
{
    /*! @brief Active power product */
    int64_t activePower;
    /*! @brief Reactive power product */
    int64_t reactivePower;
    /*! @brief Fundamental active power product */
    int64_t FActivePower;
    /*! @brief Fundamental reactive power product */
    int64_t FReactivePower;
    /*! @brief Current product */
    int64_t currentSq;
    /*! @brief Samples count */
    uint32_t sampleCount;
}currentDPSet;

/*! @brief Defines voltage dot product set  */
typedef struct
{
    /*! @brief Voltage product  */
    int64_t voltageSq;
    /*! @brief Fundamental voltage product  */
    int64_t fVoltageSq;
    /*! @brief Sample count  */
    uint32_t sampleCount;
    /*! @brief Cycles count  */
    int16_t cycleNumber;
}voltageDPSet;

/*! @brief Defines cycle voltage product set    */
typedef struct
{
    /*! @brief Cycle voltage product  */
    int64_t cycleVoltageSq;
    /*! @brief Sample count  */
    uint32_t cycleSampleCount;
}cyclePhaseDPSet;

/*! @brief Defines neutral dot product set  */
typedef struct
{
    /*! @brief neutral current square   */
    int64_t currentSq;
    /*! @brief neutral current sample count */
    uint32_t sampleCount;
}neutralDPSet;

/*! @brief current parameters   */
typedef struct
{
    /*! @brief current dc estimate  */
    int64_t I_dc_estimate;
    /*! @brief current dc estimate after integration */
    int64_t I_dc_estimate_integral;
    /*! @brief current dc estimate logged  */
    int32_t I_dc_estimate_logged;
    /*! @brief current dot product sets  */
    currentDPSet    dotProd[2];
    /*! @brief phase correction   */
    phaseCorrection phaseCorrection;
    /*! @brief quadrature correction   */
    phaseCorrection quadratureCorrection;
    /*! @brief current history   */
    _iq23 IHistory[2];
    /*! @brief current buffer index   */
    int   currentBufferIndex;
    /*! @brief current end stops   */
    int   currentEndStops;
}currentParams;

/*! @brief Defines mains parameters */
typedef struct
{
    /*! @brief samples in cycle */
    uint32_t cycleSamples;
    /*! @brief cycle period in multiples of 256 */
    uint32_t period;
    /*! @brief cycle period in fraction */
    _iq23 cyclePeriod;
}mainsParams;

/*! @brief Defines Phase parameters */
typedef struct
{
    /*! @brief DC voltage estimate  */
    int64_t V_dc_estimate;
    /*! @brief DC voltage estimate 1 */
    int64_t V_dc_estimate1;
    /*! @brief DC voltage estimate logged */
    int32_t V_dc_estimate_logged;
    /*! @brief Array to store voltage history  */
    _iq23 vHistory[64];
    /*! @brief voltage history array index  */
    int8_t vHistoryIndex;
    /*! @brief Angle of a pure sin wave  */
    uint32_t purePhase;
    /*! @brief Rate of change of angle in pure sin wave per sample  */
    _iq23 purePhaseRate;
    /*! @brief dot product of voltage and pure wave  */
    int32_t crossSum;
    /*! @brief Counts the number of voltage samples missed  */
    int sinceLast;
    /*! @brief Stores the last voltage sample  */
    _iq23 lastVoltageSample;
    /*! @brief DC voltage estimate  */
    int voltageEndStops;
    /*! @brief Struct to store voltage dot product data  */
    voltageDPSet dotProd[2];
    /*! @brief Struct to store cycle voltage dot product data  */
    cyclePhaseDPSet cycleDotProd[2];
    /*! @brief Struct to store current parameters  */
    currentParams current;
    /*! @brief Struct to store frequency calculation params  */
    mainsParams voltagePeriod;
    /*! @brief stores the index of DP set data  */
    uint8_t dpSet;
    /*! @brief stores the index of cycle DP set data  */
    uint8_t cycleDpSet;
    /*! @brief Sag start voltage    */
    _iq19 sagThresholdStart;
    /*! @brief Sag minimum voltage  */
    _iq19 sagMinVoltage;
    /*! @brief Sag stop voltage     */
    _iq19 sagThresholdStop;
    /*! @brief Sag voltage value    */
    _iq19 sagValue;
    /*! @brief Swell start voltage      */
    _iq19 swellThresholdStart;
    /*! @brief Swell stop voltage       */
    _iq19 swellThresholdStop;
    /*! @brief Swell voltage value      */
    _iq19 swellValue;
    /*! @brief Sag swell state          */
    int8_t sagSwellState;
    /*! @brief interruption level       */
    uint64_t interruptionLevel;
    /*! @brief interruption level half  */
    uint64_t interruptionLevelHalf;
    /*! @brief interruption events count*/
    uint16_t interruptionEvents;
    /*! @brief interruption duration    */
    uint32_t interruptionDuration;
    /*! @brief Sag events count         */
    uint16_t sagEvents;
    /*! @brief Sag event duration       */
    uint32_t sagDuration;
    /*! @brief Swell events count       */
    uint16_t swellEvents;
    /*! @brief Swell event duration     */
    uint32_t swellDuration;
    /*!@brief initial cycles skipped    */
    uint8_t cycleSkipCount;
}phaseParams;

/*! @brief Defines neutral Params   */
typedef struct
{
    /*! @brief DC current estimate  */
    int64_t            I_dc_estimate;
    /*! @brief DC current estimate logged */
    int64_t            I_dc_estimate_logged;
    /*! @brief Neutral dot product set    */
    neutralDPSet       dotProd[2];
    /*! @brief Array to store neutral current samples    */
    _iq23              I_History[2];
    /*! @brief Struct to store the phase correction      */
    phaseCorrection    phaseCorrection;
    /*! @brief Stores the number of over range samples   */
    int8_t             currentEndStops;
    /*! @brief Stores the dot product set index    */
    uint8_t            dpSet;
}neutralParams;

/*! @ brief Defines energy pulse params */
typedef struct
{
    /*! @brief Energy integrated per sample */
    uint64_t integrator;
    /*! @brief pulse remaining time */
    uint8_t pulseRemainingTime;
}energyPulse;

/*! @brief Defines Energy Directions    */
typedef struct
{
    /*! @brief Struct to store active energy pulse  */
    energyPulse activeEnergyPulse;
    /*! @brief Struct to store reactive energy pulse  */
    energyPulse reactiveEnergyPulse;
    /*! @brief Struct to store apparent energy pulse  */
    energyPulse apparentEnergyPulse;
    /*! @brief Struct to store fundamental active energy pulse  */
    energyPulse fActiveEnergyPulse;
    /*! @brief Struct to store fundamental reactive energy pulse  */
    energyPulse fReactiveEnergyPulse;
    /*! @brief Struct to store fundamental apparent energy pulse  */
    energyPulse fApparentEnergyPulse;
    /*! @brief Active Energy imported   */
    energyIntegrator activeEnergyImported;
    /*! @brief Active Energy exported   */
    energyIntegrator activeEnergyExported;
    /*! @brief Reactive Energy Quadrant I   */
    energyIntegrator reactiveEnergyQuardrantI;
    /*! @brief Reactive Energy Quadrant II   */
    energyIntegrator reactiveEnergyQuardrantII;
    /*! @brief Reactive Energy Quadrant III  */
    energyIntegrator reactiveEnergyQuardrantIII;
    /*! @brief Reactive Energy Quadrant IV   */
    energyIntegrator reactiveEnergyQuardrantIV;
    /*! @brief Apparent Energy imported   */
    energyIntegrator appparentEnergyImported;
    /*! @brief Apparent Energy exported   */
    energyIntegrator appparentEnergyExported;
    /*! @brief Fundamental Active Energy imported   */
    energyIntegrator fundamentalActiveEnergyImported;
    /*! @brief Fundamental Active Energy exported   */
    energyIntegrator fundamentalActiveEnergyExported;
    /*! @brief Fundamental Reactive Energy Quadrant I   */
    energyIntegrator fundamentalReactiveEnergyQuardrantI;
    /*! @brief Fundamental Reactive Energy Quadrant II   */
    energyIntegrator fundamentalReactiveEnergyQuardrantII;
    /*! @brief Fundamental Reactive Energy Quadrant III  */
    energyIntegrator fundamentalReactiveEnergyQuardrantIII;
    /*! @brief Fundamental Reactive Energy Quadrant IV   */
    energyIntegrator fundamentalReactiveEnergyQuardrantIV;
    /*! @brief Fundamental Apparent Energy imported   */
    energyIntegrator fundamentalAppparentEnergyImported;
    /*! @brief Fundamental Apparent Energy exported   */
    energyIntegrator fundamentalAppparentEnergyExported;
}phaseEnergy;

/*! @brief Defines Phase metrology  */
typedef struct
{
    /*! @brief Phase Readings   */
    phaseReadings  readings;
    /*! @brief Phase Params */
    phaseParams    params;
    /*! @brief Phase Energies */
    phaseEnergy    energy;
    /*! @brief Phase Status */
    volatile uint16_t       status;
    /*! @brief Phase cCycle Status */
    volatile uint16_t       cycleStatus;
}phaseMetrology;

/*! @brief Defines Neutral Metrology    */
typedef struct
{
    /*! @brief Neutral Readings   */
    neutralReadings  readings;
    /*! @brief Neutral Params   */
    neutralParams    params;
    /*! @brief Neutral Status   */
    volatile uint16_t       status;
}neutralMetrology;

/*! @brief Defines Total Parameters */
typedef struct
{
    /*! @brief Total Power Readings   */
    TotalPowerReadings readings;
    /*! @brief Total Energy Readings  */
    phaseEnergy        energy;
    /*! @brief Total Power Factor     */
    _iq13              powerFactor;
    /*! @brief current vector sum     */
    _iq19              currentVectorSum;
}totalParams;

/*! @brief Defines Metrology Data   */
typedef struct
{
    /*! @brief This structure holds all the working data for each phase. */
    phaseMetrology phases[MAX_PHASES];
    /*! @brief This structure holds all the working data for neutral. */
    neutralMetrology neutral;
    /*! @brief This structure holds all total power and energy readings. */
    totalParams totals;
    /*! @brief This structure holds line to line readings. */
    LLReadings LLReadings;
    /*! @brief stores raw voltage data  */
    _iq23 rawVoltageData[MAX_PHASES];
    /*! @brief stores raw current data  */
    _iq23 rawCurrentData[MAX_PHASES];
    /*! @brief stores last raw current data  */
    _iq23 lastRawCurrentData[MAX_PHASES];
    /*! @brief stores current integration data  */
    _iq23 currentIntegrationData[MAX_PHASES];
    /*! @brief stores raw neutral data  */
    _iq23 rawNeutralData;
    /*! @brief Metrology status */
    METROLOGY_STATUS metrologyState;
    /*! @brief Metrology operating mode */
    OPERATING_MODES operatingMode;
    /*! @brief Stores the supported parameters  */
    uint32_t supportedParams;
    /*! @brief GPIO outputs active energy pulse */
    HAL_GPIO_OUT activePulse;
    /*! @brief GPIO outputs reactive energy pulse */
    HAL_GPIO_OUT reactivePulse;
}metrologyData;

#ifdef __cplusplus
}
#endif
#endif /* METROLOGY_STRUCTS_H_ */
/** @}*/
