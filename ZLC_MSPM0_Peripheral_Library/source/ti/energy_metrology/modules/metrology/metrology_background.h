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
 *  @file       metrology_background.h
 *  @brief      API's related to metrology background process
 *
 *  @anchor metrology_background_h
 *  # Overview
 *
 *  API's related to background process in metrology module
 *
 *  <hr>
 ******************************************************************************/
/** @addtogroup Metrology
 * @{
 */

#ifndef _METROLOGY_BACKGROUND_H_
#define _METROLOGY_BACKGROUND_H_

#ifdef __cplusplus
extern "C" {
#endif

/*! @brief Defines 2 * PI   */
#define PI2  _IQ23(6.28318530718)

/*!
 * @brief Metrology per phase sampling
 * @param[in] workingData The metrology data
 */
void Metrology_perSampleProcessing(metrologyData *workingData);

/*!
 * @brief Metrology per sample energy pulse processing
 * @param[in] workingData The metrology data
 */
void Metrology_perSampleEnergyPulseProcessing(metrologyData *workingData);

/*!
 * @brief dc_filter()
 *          Simple 1st order DC filter
 *              y(n)     = y(n-1) + (x(n) - y(n-1))/2^14
 *              xfilt(n) = x(n) - y(n)
 *   where:
 *    x(n)     = most recent ADC sample
 *    y(n)     = filter tap
 *    xfilt(n) = DC filtered output
 *
 * @param[in,out]   p  pointer to filter tap data
 * @param[in]       x  pointer to input data
 *
 * @return filtered output
 */
__STATIC_INLINE _iq23 metrology_dcFilter(int64_t *p, _iq23 x)
{
    *p += ( (int64_t) (x - ( (int32_t) (*p >> 16) )) ) << 2;
     x -= ( (int32_t) (*p >> 16) );

    return x;
}

#ifdef __cplusplus
}
#endif
#endif /* _METROLOGY_BACKGROUND_H_ */
/** @}*/
