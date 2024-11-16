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
 *  @file       ADS131M02_Defaults.h
 *  @brief      Default ADS register data
 *
 *  @anchor ADS131M02_Defaults_h
 *  # Overview
 *
 *  Default ADS131M02 register data
 *
 *  <hr>
 ******************************************************************************/
/** @addtogroup ADS131M0x
 * @{
 */

#ifndef _ADS131M02_DEFAULTS_H_
#define _ADS131M02_DEFAULTS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ADS131M0x.h"

/*! @brief Default clock address data   */
#define ADS131M02_CLOCK_ADDRESS_DATA        CLOCK_CH1_EN_ENABLED | CLOCK_CH0_EN_ENABLED | CLOCK_XTAL_DIS_ENABLED | CLOCK_EXTREF_EN_DISABLED | CLOCK_OSR_1024 | CLOCK_PWR_HR
/*! @brief Default mode address data    */
#define ADS131M02_MODE_ADDRESS_DATA         MODE_REG_CRC_EN_DISABLED | MODE_RX_CRC_EN_DISABLED | MODE_CRC_TYPE_16BIT_CCITT | MODE_RESET_RESET_OCCURRED | MODE_WLENGTH_24BIT | MODE_TIMEOUT_ENABLED | MODE_DRDY_SEL_MOST_LAGGING | MODE_DRDY_HiZ_LOGIC_HIGH | MODE_DRDY_FMT_LOGIC_LOW
/*! @brief Default gain1 address data   */
#define ADS131M02_GAIN1_ADDRESS_DATA        GAIN1_PGAGAIN3_1 | GAIN1_PGAGAIN2_1 | GAIN1_PGAGAIN1_1 | GAIN1_PGAGAIN0_32
/*! @brief Default CFG address data     */
#define ADS131M02_CFG_ADDRESS_DATA          CFG_GC_DLY_16 | CFG_GC_EN_DISABLED | CFG_CD_ALLCH_ANY_CHANNEL | CFG_CD_NUM_1 | CFG_CD_LEN_128 | CFG_CD_EN_DISABLED
/*! @brief Default THRSHLD MSB address data   */
#define ADS131M02_THRSHLD_MSB_ADDRESS_DATA  THRSHLD_MSB_DEFAULT
/*! @brief Default THRSHLD LSB address data   */
#define ADS131M02_THRSHLD_LSB_ADDRESS_DATA  THRSHLD_LSB_DCBLOCK_DISABLED
/*! @brief Default CH0_CFG address data   */
#define ADS131M02_CH0_CFG_ADDRESS_DATA      CH0_CFG_DEFAULT
/*! @brief Default CH0 OCAL_MSB address data   */
#define ADS131M02_CH0_OCAL_MSB_ADDRESS_DATA CH0_OCAL_MSB_DEFAULT
/*! @brief Default CH0 OCAL_LSB address data   */
#define ADS131M02_CH0_OCAL_LSB_ADDRESS_DATA CH0_OCAL_LSB_DEFAULT
/*! @brief Default CH0 GCAL_MSB address data   */
#define ADS131M02_CH0_GCAL_MSB_ADDRESS_DATA CH0_GCAL_MSB_DEFAULT
/*! @brief Default CH0 GCAL_LSB address data   */
#define ADS131M02_CH0_GCAL_LSB_ADDRESS_DATA CH0_GCAL_LSB_DEFAULT
/*! @brief Default CH1_CFG address data   */
#define ADS131M02_CH1_CFG_ADDRESS_DATA      CH1_CFG_DEFAULT
/*! @brief Default CH1 OCAL_MSB address data   */
#define ADS131M02_CH1_OCAL_MSB_ADDRESS_DATA CH1_OCAL_MSB_DEFAULT
/*! @brief Default CH1 OCAL_LSB address data   */
#define ADS131M02_CH1_OCAL_LSB_ADDRESS_DATA CH1_OCAL_LSB_DEFAULT
/*! @brief Default CH1 GCAL_MSB address data   */
#define ADS131M02_CH1_GCAL_MSB_ADDRESS_DATA CH1_GCAL_MSB_DEFAULT
/*! @brief Default CH1 GCAL_LSB address data   */
#define ADS131M02_CH1_GCAL_LSB_ADDRESS_DATA CH1_GCAL_LSB_DEFAULT

/*! @brief Defines ADS initial register data */
extern uint16_t ADS131M02_initRegData[NUM_REGISTERS + 1];

#ifdef __cplusplus
}
#endif
#endif /* _ADS131M02_DEFAULTS_H_ */
/** @}*/
