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
 *  @file       metrology_foreground.h
 *  @brief      APIs related to Metrology foreground process
 *
 *  @anchor metrology_foreground_h
 *  # Overview
 *
 *  APIs related to Metrology foreground process in metrology module
 *
 *  <hr>
 ******************************************************************************/
/** @addtogroup Metrology
 * @{
 */

#ifndef _METROLOGY_FOREGROUND_H_
#define _METROLOGY_FOREGROUND_H_

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief    Calculate phase parameters
 * @param[in] workingData The metrology instance
 * @param[in] ph          phase number
 */
void Metrology_calculatePhaseReadings(metrologyData *workingData, PHASES ph);

/*!
 * @brief    Calculate three phase parameters
 * @param[in] workingData The metrology instance
 */
void Metrology_calculateThreePhaseParameters(metrologyData *workingData);

/*!
 * @brief    Calculate total parameters
 * @param[in] workingData The metrology instance
 */
void Metrology_calculateTotalParameters(metrologyData *workingData);

/*!
 * @brief    Calculate neutral parameters
 * @param[in] workingData The metrology instance
 */
void Metrology_calculateNeutralReadings(metrologyData *workingData);

/*!
 * @brief    Sag Swell Detection
 * @param[in] workingData The metrology instance
 * @param[in] ph          phase number
 */
void Metrology_sagSwellDetection(metrologyData *workingData, PHASES ph);

#ifdef __cplusplus
}
#endif
#endif /* _METROLOGY_FOREGROUND_H_ */
/** @}*/
