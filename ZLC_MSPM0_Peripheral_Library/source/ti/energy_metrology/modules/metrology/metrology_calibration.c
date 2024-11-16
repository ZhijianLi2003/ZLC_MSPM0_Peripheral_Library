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

//*****************************************************************************
// the includes
//*****************************************************************************
#include "metrology_defines.h"
#include "metrology_structs.h"
#include "metrology_calibration_defaults.h"
#include "metrology_calibration.h"

/*! @brief Defines nvParams struct */
__attribute__((section(".memsector01"))) struct infoMem nvParams;

HAL_MEMORY_BLOCK_STARTADDR startAddr = HAL_MEMORY_BLOCK_STARTADDR01;

/*! @brief Defines updated calibration data*/
calibrationData updatedData;

/*!
 * @brief Set default calibration data to flash
 */
void Metrology_setDefaultCalibrationData()
{
    HAL_clearMemoryBlock(startAddr);
    HAL_copyMemoryBlock(&nvParams, &calibrationDefaults, sizeof(calibrationDefaults), startAddr);
    HAL_secureMemoryBlock(startAddr);

    memcpy(&updatedData, &calibrationDefaults, sizeof(calibrationDefaults));
}

/*!
 * @brief Load calibration data from flash
 */
void Metrology_initializeCalibrationData()
{
    memcpy(&updatedData, &nvParams.seg_a.s.calData, sizeof(nvParams.seg_a.s.calData));
    if(updatedData.calibrationInitFlag != CONFIG_INIT_FLAG)
    {
        Metrology_setDefaultCalibrationData();
    }
}

/*!
 * @brief Reads phase voltage dc estimate
 * @param[in] workingData The Metrology instance
 * @param[in] ph          The phase number
 * @return Phase voltage dc estimate
 */
int16_t Metrology_getPhaseInitialVdcEstimate(metrologyData *workingData, PHASES ph)
{
    return calInfo->phases[ph].VinitialDcEstimate;
}

/*!
 * @brief Reads phase current dc estimate
 * @param[in] workingData The Metrology instance
 * @param[in] ph          The phase number
 * @return Phase current dc estimate
 */
int16_t Metrology_getPhaseInitialIdcEstimate(metrologyData *workingData, PHASES ph)
{
    return calInfo->phases[ph].current.IinitialDcEstimate;
}

/*!
 * @brief Reads phase voltage AC offset
 * @param[in] workingData The Metrology instance
 * @param[in] ph          The phase number
 * @return Phase voltage AC offset in milli volts
 */
int32_t Metrology_getPhaseVacOffset(metrologyData *workingData, PHASES ph)
{
    return _IQ9mpyI32int(_IQ19toIQ9(calInfo->phases[ph].VacOffset), 1000);
}

/*!
 * @brief Reads phase current AC offset
 * @param[in] workingData The Metrology instance
 * @param[in] ph          The phase number
 * @return Phase current AC offset in micro amps
 */
int32_t Metrology_getPhaseIacOffset(metrologyData *workingData, PHASES ph)
{
    return _IQ3mpyI32int(_IQ19toIQ3(calInfo->phases[ph].current.IacOffset), 1000000);
}

/*!
 * @brief Reads phase active power offset
 * @param[in] workingData The Metrology instance
 * @param[in] ph          The phase number
 * @return Phase active power offset in milli watts
 */
int32_t Metrology_getPhasePOffset(metrologyData *workingData, PHASES ph)
{
    return _IQ3mpyI32int(_IQ13toIQ3(calInfo->phases[ph].current.activePowerOffset), 1000);
}

/*!
 * @brief Reads phase reactive power offset
 * @param[in] workingData The Metrology instance
 * @param[in] ph          The phase number
 * @return Phase reactive power offset in milli VAR
 */
int32_t Metrology_getPhaseQOffset(metrologyData *workingData, PHASES ph)
{
    return _IQ3mpyI32int(_IQ13toIQ3(calInfo->phases[ph].current.reactivePowerOffset), 1000);
}

/*!
 * @brief Reads phase fundamental active power offset
 * @param[in] workingData The Metrology instance
 * @param[in] ph          The phase number
 * @return Phase fundamental active power offset in milli watts
 */
int32_t Metrology_getPhaseFundPOffset(metrologyData *workingData, PHASES ph)
{
    return _IQ3mpyI32int(_IQ13toIQ3(calInfo->phases[ph].current.FActivePowerOffset), 1000);
}

/*!
 * @brief Reads phase fundamental reactive power offset
 * @param[in] workingData The Metrology instance
 * @param[in] ph          The phase number
 * @return Phase fundamental reactive power offset in milli VAR
 */
int32_t Metrology_getPhaseFundQOffset(metrologyData *workingData, PHASES ph)
{
    return _IQ3mpyI32int(_IQ13toIQ3(calInfo->phases[ph].current.FReactivePowerOffset), 1000);
}

/*!
 * @brief Reads phase fundamental voltage offset
 * @param[in] workingData The Metrology instance
 * @param[in] ph          The phase number
 * @return Phase fundamental voltage offset in milli volts
 */
int32_t Metrology_getPhaseFundVOffset(metrologyData *workingData, PHASES ph)
{
    return _IQ9mpyI32int(_IQ19toIQ9(calInfo->phases[ph].VFundamentalAcOffset), 1000);
}

/*!
 * @brief Reads phase fundamental current offset
 * @param[in] workingData The Metrology instance
 * @param[in] ph          The phase number
 * @return Phase fundamental current offset in micro amps
 */
int32_t Metrology_getPhaseFundIOffset(metrologyData *workingData, PHASES ph)
{
    return _IQ3mpyI32int(_IQ19toIQ3(calInfo->phases[ph].current.IFAcOffset), 1000000);
}

/*!
 * @brief Reads phase correction parameters
 * @param[in] workingData The Metrology instance
 * @param[in] ph          The phase number
 * @return Phase correction parameters
 */
int16_t Metrology_getPhaseCorrectionParameters(metrologyData *workingData, PHASES ph)
{
    return (int16_t)(calInfo->phases[ph].current.phaseOffset << 3);
}

/*!
 * @brief Reads voltage scale factor
 * @param[in] workingData The Metrology instance
 * @param[in] ph          The phase number
 * @return Voltage scale factor
 */
uint32_t Metrology_getPhaseVRMSScaling(metrologyData *workingData, PHASES ph)
{
    float value = _IQ19toF(calInfo->phases[ph].VscaleFactor);
    return (*(uint32_t *) &value);
}

/*!
 * @brief Reads current scale factor
 * @param[in] workingData The Metrology instance
 * @param[in] ph          The phase number
 * @return Current scale factor
 */
uint32_t Metrology_getPhaseIRMSScaling(metrologyData *workingData, PHASES ph)
{
    float value = _IQ19toF(calInfo->phases[ph].current.IscaleFactor);
    return (*(uint32_t *) &value);
}

/*!
 * @brief Reads power scale factor
 * @param[in] workingData The Metrology instance
 * @param[in] ph          The phase number
 * @return Power scale factor
 */
uint32_t Metrology_getPhasePScaling(metrologyData *workingData, PHASES ph)
{
    float value = _IQ10toF( calInfo->phases[ph].current.PscaleFactor);
    return (*(uint32_t *) &value);
}

/*!
 * @brief Reads neutral current dc estimate
 * @param[in] workingData The Metrology instance
 * @return Neutral current dc estimate
 */
int16_t Metrology_getNeutralInitialIdcEstimate(metrologyData *workingData)
{
    return calInfo->neutral.IinitialDcEstimate;
}

/*!
 * @brief Reads neutral current ac offset
 * @param[in] workingData The Metrology instance
 * @return Neutral current ac offset
 */
int32_t Metrology_getNeutralIacOffset(metrologyData *workingData)
{
    return calInfo->neutral.IacOffset;
}

/*!
 * @brief Reads neutral active power offset
 * @param[in] workingData The Metrology instance
 * @return Neutral active power offset
 */
int32_t Metrology_getNeutralPOffset(metrologyData *workingData)
{
    return calInfo->neutral.activePowerOffset;
}

/*!
 * @brief Reads neutral reactive power offset
 * @param[in] workingData The Metrology instance
 * @return Neutral reactive power offset
 */
int32_t Metrology_getNeutralQOffset(metrologyData *workingData)
{
    return calInfo->neutral.reactivePowerOffset;
}

/*!
 * @brief Reads neutral fundamental active power offset
 * @param[in] workingData The Metrology instance
 * @return Neutral fundamental active power offset
 */
int32_t Metrology_getNeutralFundPOffset(metrologyData *workingData)
{
    return calInfo->neutral.FActivePowerOffset;
}

/*!
 * @brief Reads neutral fundamental reactive power offset
 * @param[in] workingData The Metrology instance
 * @return Neutral fundamental reactive power offset
 */
int32_t Metrology_getNeutralFundQOffset(metrologyData *workingData)
{
    return calInfo->neutral.FReactivePowerOffset;
}

/*!
 * @brief Reads neutral fundamental current offset
 * @param[in] workingData The Metrology instance
 * @return Neutral fundamental current offset
 */
int32_t Metrology_getNeutralFundIOffset(metrologyData *workingData)
{
    return calInfo->neutral.IFAcOffset;
}

/*!
 * @brief Reads neutral fundamental voltage offset
 * @param[in] workingData The Metrology instance
 * @return Neutral fundamental voltage offset
 */
int32_t Metrology_getNeutralFundVOffset(metrologyData *workingData)
{
    /* No concept of voltage in Neutral */
    return 0;
}

/*!
 * @brief Reads neutral current scale factor
 * @param[in] workingData The Metrology instance
 * @return Neutral current scale factor
 */
uint32_t Metrology_getNeutralIRMSScaling(metrologyData *workingData)
{
    float value = _IQ19toF(calInfo->neutral.IscaleFactor);
    return (*(uint32_t *) &value);
}

/*!
 * @brief Reads neutral power scale factor
 * @param[in] workingData The Metrology instance
 * @return Neutral power scale factor
 */
uint32_t Metrology_getNeutralPScaling(metrologyData *workingData)
{
    float value = _IQ10toF(calInfo->neutral.PscaleFactor);
    return (*(uint32_t *) &value);
}

/*!
 * @brief Reads neutral correction data
 * @param[in] workingData The Metrology instance
 * @return Neutral correction parameter
 */
int16_t Metrology_getNeutralCorrectionParameters(metrologyData *workingData)
{
    return (int16_t)(calInfo->neutral.phaseOffset << 3);
}

/*!
 * @brief Reads calibration status
 * @param[in] workingData The Metrology instance
 * @return Calibration status
 */
int32_t Metrology_getCalibrationStatus(metrologyData *workingData)
{
    return nvParams.seg_a.s.calibrationStatus;
}

/*!
 * @brief Update calibration data
 * @param[in] workingData The Metrology instance
 * @param[in] status  Calibration status
 */
void Metrology_setCalibrationStatus(metrologyData *workingData, int32_t status)
{
    nvParams.seg_a.s.calibrationStatus = status;
}

/*!
 * @brief Update Phase voltage offset
 * @param[in] workingData The metrology instance
 * @param[in] data        The voltage offset in milli volts
 * @param[in] ph          The phase number
 */
void Metrology_setPhaseVacOffset(metrologyData *workingData, int32_t data, PHASES ph)
{
    updatedData.phases[ph].VacOffset = _IQ19div(_IQ19(data), _IQ19(1000));
}

/*!
 * @brief Update Phase fundamental voltage offset
 * @param[in] workingData The metrology instance
 * @param[in] data        The fundamental voltage offset
 * @param[in] ph          The phase number
 */
void Metrology_setPhaseFundVOffset(metrologyData *workingData, int32_t data, PHASES ph)
{
    updatedData.phases[ph].VFundamentalAcOffset = _IQ19div(_IQ19(data), _IQ19(1000));
}

/*!
 * @brief Update Phase voltage DC estimate
 * @param[in] workingData The metrology instance
 * @param[in] data        The voltage DC estimate
 * @param[in] ph          The phase number
 */
void Metrology_setPhaseVdcEstimate(metrologyData *workingData, int16_t data, PHASES ph)
{
    updatedData.phases[ph].VinitialDcEstimate = data;
}


/*!
 * @brief Update Phase voltage scale factor
 * @param[in] workingData The metrology instance
 * @param[in] data        The voltage scale factor
 * @param[in] ph          The phase number
 */
void Metrology_setPhaseVRMSScaling(metrologyData *workingData, uint32_t data, PHASES ph)
{
    updatedData.phases[ph].VscaleFactor = _IQ19(*(float *) &data);
}

/*!
 * @brief Update Phase current offset
 * @param[in] workingData The metrology instance
 * @param[in] data        The current offset
 * @param[in] ph          The phase number
 */
void Metrology_setPhaseIacOffset(metrologyData *workingData, int32_t data, PHASES ph)
{
    updatedData.phases[ph].current.IacOffset = _IQ10toIQ19(_IQ10div(_IQ10(data), _IQ10(1000000)));
}

/*!
 * @brief Update Phase fundamental current offset
 * @param[in] workingData The metrology instance
 * @param[in] data        The fundamental current offset
 * @param[in] ph          The phase number
 */
void Metrology_setPhaseFundIOffset(metrologyData *workingData, int32_t data, PHASES ph)
{
    updatedData.phases[ph].current.IFAcOffset = _IQ10toIQ19(_IQ10div(_IQ10(data), _IQ10(1000000)));
}

/*!
 * @brief Update Phase current DC estimate
 * @param[in] workingData The metrology instance
 * @param[in] data        The current DC estimate
 * @param[in] ph          The phase number
 */
void Metrology_setPhaseIdcEstimate(metrologyData *workingData, int16_t data, PHASES ph)
{
    updatedData.phases[ph].current.IinitialDcEstimate = data;
}

/*!
 * @brief Update Phase current scale factor
 * @param[in] workingData The metrology instance
 * @param[in] data        The current scale factor
 * @param[in] ph          The phase number
 */
void Metrology_setPhaseIRMSScaling(metrologyData *workingData, uint32_t data, PHASES ph)
{
    updatedData.phases[ph].current.IscaleFactor = _IQ19(*(float *) &data);
}

/*!
 * @brief Update Phase power scale factor
 * @param[in] workingData The metrology instance
 * @param[in] data        The power scale factor
 * @param[in] ph          The phase number
 */
void Metrology_setPhasePScaling(metrologyData *workingData, uint32_t data, PHASES ph)
{
    updatedData.phases[ph].current.PscaleFactor = _IQ10(*(float *) &data);
}

/*!
 * @brief Update Phase fundamental active power offset
 * @param[in] workingData The metrology instance
 * @param[in] data        The fundamental active power offset
 * @param[in] ph          The phase number
 */
void Metrology_setPhaseFundPOffset(metrologyData *workingData, int32_t data, PHASES ph)
{
    updatedData.phases[ph].current.FActivePowerOffset = _IQ13div(_IQ13(data), _IQ13(1000));
}

/*!
 * @brief Update Phase fundamental reactive power offset
 * @param[in] workingData The metrology instance
 * @param[in] data        The fundamental reactive power offset
 * @param[in] ph          The phase number
 */
void Metrology_setPhaseFundQOffset(metrologyData *workingData, int32_t data, PHASES ph)
{
    updatedData.phases[ph].current.FReactivePowerOffset = _IQ13div(_IQ13(data), _IQ13(1000));
}

/*!
 * @brief Update Phase active power offset
 * @param[in] workingData The metrology instance
 * @param[in] data        The active power offset
 * @param[in] ph          The phase number
 */
void Metrology_setPhasePOffset(metrologyData *workingData, int32_t data, PHASES ph)
{
    updatedData.phases[ph].current.activePowerOffset = _IQ13div(_IQ13(data), _IQ13(1000));
}

/*!
 * @brief Update Phase reactive power offset
 * @param[in] workingData The metrology instance
 * @param[in] data        The reactive power offset
 * @param[in] ph          The phase number
 */
void Metrology_setPhaseQOffset(metrologyData *workingData, int32_t data, PHASES ph)
{
    updatedData.phases[ph].current.reactivePowerOffset = _IQ13div(_IQ13(data), _IQ13(1000));
}

/*!
 * @brief Update Phase calibration offset
 * @param[in] workingData The metrology instance
 * @param[in] data        The phase calibration offset
 * @param[in] ph          The phase number
 */
void Metrology_setPhaseOffset(metrologyData *workingData, int16_t data, PHASES ph)
{
    updatedData.phases[ph].current.phaseOffset = (int32_t)(data >> 3);
}

/*!
 * @brief Update Neutral current offset
 * @param[in] workingData The metrology instance
 * @param[in] data        The current offset
 */
void Metrology_setNeutralIacOffset(metrologyData *workingData, int32_t data)
{
    updatedData.neutral.IacOffset = _IQ10toIQ19(_IQ10div(_IQ10(data), _IQ10(1000000)));
}

/*!
 * @brief Update neutral fundamental current offset
 * @param[in] workingData The metrology instance
 * @param[in] data        The fundamental current offset
 */
void Metrology_setNeutralFundIOffset(metrologyData *workingData, int32_t data)
{
    updatedData.neutral.IFAcOffset = _IQ10toIQ19(_IQ10div(_IQ10(data), _IQ10(1000000)));
}

/*!
 * @brief Update neutral current dc estimate
 * @param[in] workingData The metrology instance
 * @param[in] data        The current dc estimate
 */
void Metrology_setNeutralIdcEstimate(metrologyData *workingData, int16_t data)
{
    updatedData.neutral.IinitialDcEstimate = data;
}

/*!
 * @brief Update neutral current scale factor
 * @param[in] workingData The metrology instance
 * @param[in] data        The current scale factor
 */
void Metrology_setNeutralIRMSScaling(metrologyData *workingData, uint32_t data)
{
    updatedData.neutral.IscaleFactor = _IQ19(*(float *) &data);
}

/*!
 * @brief Update neutral power scale factor
 * @param[in] workingData The metrology instance
 * @param[in] data        The power scale factor
 */
void Metrology_setNeutralPScaling(metrologyData *workingData, uint32_t data)
{
    updatedData.neutral.PscaleFactor = _IQ10(*(float *) &data);
}

/*!
 * @brief Update neutral fundamental active power offset
 * @param[in] workingData The metrology instance
 * @param[in] data        The fundamental active power offset
 */
void Metrology_setNeutralFundPOffset(metrologyData *workingData, int32_t data)
{
    updatedData.neutral.FActivePowerOffset = _IQ13div(_IQ13(data), _IQ13(1000));
}

/*!
 * @brief Update neutral fundamental reactive power offset
 * @param[in] workingData The metrology instance
 * @param[in] data        The fundamental reactive power offset
 */
void Metrology_setNeutralFundQOffset(metrologyData *workingData, int32_t data)
{
    updatedData.neutral.FReactivePowerOffset = _IQ13div(_IQ13(data), _IQ13(1000));
}

/*!
 * @brief Update neutral active power offset
 * @param[in] workingData The metrology instance
 * @param[in] data        The active power offset
 */
void Metrology_setNeutralPOffset(metrologyData *workingData, int32_t data)
{
    updatedData.neutral.activePowerOffset = _IQ13div(_IQ13(data), _IQ13(1000));
}

/*!
 * @brief Update neutral reactive power offset
 * @param[in] workingData The metrology instance
 * @param[in] data        The reactive power offset
 */
void Metrology_setNeutralQOffset(metrologyData *workingData, int32_t data)
{
    updatedData.neutral.reactivePowerOffset = _IQ13div(_IQ13(data), _IQ13(1000));
}

/*!
 * @brief Update neutral calibration offset
 * @param[in] workingData The metrology instance
 * @param[in] data        The neutral calibration offset
 */
void Metrology_setNeutralOffset(metrologyData *workingData, int16_t data)
{
    updatedData.neutral.phaseOffset = (int32_t)(data >> 3);
}

/*!
 * @brief Clear calibration data
 * @param[in] workingData The Metrology instance
 */
void Metrology_clearCalibrationData(metrologyData *workingData)
{
    HAL_clearMemoryBlock(startAddr);
    HAL_copyMemoryBlock(&nvParams, &calibrationDefaults, sizeof(calibrationDefaults), startAddr);
    HAL_secureMemoryBlock(startAddr);
}

/*!
 * @brief Update calibration data
 * @param[in] workingData The Metrology instance
 */
void Metrology_updateCalibrationData(metrologyData *workingData)
{
    HAL_clearMemoryBlock(startAddr);
    HAL_copyMemoryBlock(&nvParams, &updatedData, sizeof(updatedData), startAddr);
    HAL_secureMemoryBlock(startAddr);
}





