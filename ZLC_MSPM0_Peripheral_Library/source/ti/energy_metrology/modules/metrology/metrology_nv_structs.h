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
 *  @file       metrology_nv_structs.h
 *  @brief      Structures in metrology module
 *
 *  @anchor metrology_nv_structs_h
 *  # Overview
 *
 *  Structures in metrology module
 *
 *  <hr>
 ******************************************************************************/
/** @addtogroup Metrology
 * @{
 */

#ifndef METROLOGY_NV_STRUCTS_H_
#define METROLOGY_NV_STRUCTS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "metrology_defines.h"

/*! @brief Defines current sensor calibration data  */
typedef struct
{
    /*! @brief Initial DC currnet estimate  */
    _iq19 IinitialDcEstimate;
    /*! @brief Current AC offset  */
    _iq19 IacOffset;
    /*! @brief Fundamental current AC offset  */
    _iq19 IFAcOffset;
    /*! @brief Active power offset  */
    _iq13 activePowerOffset;
    /*! @brief Reactive power offset  */
    _iq13 reactivePowerOffset;
    /*! @brief Fundamental active power offset  */
    _iq13 FActivePowerOffset;
    /*! @brief Fundamental reactive power offset  */
    _iq13 FReactivePowerOffset;
    /*! @brief Phase offset  */
    int32_t phaseOffset;
    /*! @brief Current scale factor  */
    _iq19 IscaleFactor;
    /*! @brief Power scale factor  */
    _iq10 PscaleFactor;
}currentSensorCalibrationData;

/*! @brief Defines phase calibration data   */
typedef struct
{
    /*! @brief Defines current sensor calibration data  */
    currentSensorCalibrationData current;
    /*! @brief Inital DC voltage estimate  */
    _iq19 VinitialDcEstimate;
    /*! @brief voltage AC offset  */
    _iq19 VacOffset;
    /*! @brief fundamental voltage AC offset  */
    _iq19 VFundamentalAcOffset;
    /*! @brief Voltage scale factor  */
    _iq19 VscaleFactor;
}phaseCalibrationData;

/*! @brief Defines calibration data */
typedef struct
{
    /*! @brief Defines phase calibration data   */
    phaseCalibrationData phases[MAX_PHASES];
    /*! @brief Defines neutral calibration data */
    currentSensorCalibrationData neutral;
    /*! @brief calibration state    */
    int structState;
    /*! @brief initialization flag  */
    uint32_t calibrationInitFlag;
}calibrationData;

/*! @brief Defines calibration parameters   */
typedef struct
{
    /*! @brief Defines calibration data */
    calibrationData calData;
    /*! @brief calibration data */
    int32_t calibrationStatus;
}nvParam;

/*! @brief Defines nv memory*/
typedef struct infoMem
{
    /*! @brief seg_a */
    union
    {
        /*! @brief Defines nv params*/
        nvParam s;
        /*! @brief Defines nv params array*/
        int8_t x[256];
    } seg_a;
}infoMem;

#ifdef __cplusplus
}
#endif
#endif /* METROLOGY_NV_STRUCTS_H_ */
/** @}*/

