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
 *  @file       metrology_setup.h
 *  @brief      initializes the metrology module
 *
 *  @anchor metrology_setup_h
 *  # Overview
 *
 *  API's releated to initialize the metrology module
 *
 *  <hr>
 ******************************************************************************/
/** @addtogroup Metrology
 * @{
 */

#ifndef _METROLOGY_SETUP_H_
#define _METROLOGY_SETUP_H_

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief FIR coefficients to correct specific phase shift angles at 50 Hz
 *        and sampling 2000 times per second. There are 256 steps in this table. 
 */
extern const int32_t phase_shift_fir_coeffs[PHASE_SHIFT_FIR_TABLE_ELEMENTS][2];

/*!
 * @brief Metrology Init
 * @param[in] workingData The metrology data
 */
void Metrology_init(metrologyData *workingData);

/*!
 * @brief Metrology Init nv data
 * @param[in] workingData The metrology data
 */
void Metrology_initNVData(metrologyData *workingData);

/*!
 * @brief Metrology Align with nv data
 * @param[in] workingData The metrology data
 */
void Metrology_alignwithNVData(metrologyData *workingData);

/*!
 * @brief Set phase Correction
 * @param[in] phCorr The phase correction data
 * @param[in] correction correction value
 */
void Metrology_setPhaseCorrection(phaseCorrection *phCorr, int32_t correction);

/*!
 * @brief Metrology Align with calibration data
 * @param[in] workingData The metrology data
 */
void Metrology_alignWithCalibrationData(metrologyData *workingData);


#ifdef __cplusplus
}
#endif
#endif /* _METROLOGY_SETUP_H_ */
/** @}*/
