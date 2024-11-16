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
 *  @file       ADS131M08_Defaults.h
 *  @brief      Default ADS131M08 register data
 *
 *  @anchor ADS131M08_Defaults_h
 *  # Overview
 *
 *  Default ADS131M08 register data
 *
 *  <hr>
 ******************************************************************************/
/** @addtogroup ADS131M0x
 * @{
 */

#ifndef _ADS131M08_DEFAULTS_H_
#define _ADS131M08_DEFAULTS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ADS131M0x.h"

/*! @brief Default clock address data   */
#define ADS01_CLOCK_ADDRESS_DATA        CLOCK_CH7_EN_DISABLED | CLOCK_CH6_EN_ENABLED | CLOCK_CH5_EN_ENABLED | CLOCK_CH4_EN_ENABLED | CLOCK_CH3_EN_ENABLED | CLOCK_CH2_EN_ENABLED | CLOCK_CH1_EN_ENABLED | CLOCK_CH0_EN_ENABLED | CLOCK_XTAL_DIS_ENABLED | CLOCK_EXTREF_EN_DISABLED | CLOCK_OSR_512 | CLOCK_PWR_HR
/*! @brief Default mode address data    */
#define ADS01_MODE_ADDRESS_DATA         MODE_REG_CRC_EN_DISABLED | MODE_RX_CRC_EN_DISABLED | MODE_CRC_TYPE_16BIT_CCITT | MODE_RESET_RESET_OCCURRED | MODE_WLENGTH_24BIT | MODE_TIMEOUT_ENABLED | MODE_DRDY_SEL_MOST_LAGGING | MODE_DRDY_HiZ_LOGIC_HIGH | MODE_DRDY_FMT_LOGIC_LOW

#ifdef ROGOSWKI_SUPPORT
/*! @brief Default gain1 address data   */
#define ADS01_GAIN1_ADDRESS_DATA        GAIN1_PGAGAIN3_16 | GAIN1_PGAGAIN2_1 | GAIN1_PGAGAIN1_1 | GAIN1_PGAGAIN0_1
/*! @brief Default gain2 address data   */
#define ADS01_GAIN2_ADDRESS_DATA        GAIN2_PGAGAIN7_1 | GAIN2_PGAGAIN6_16 | GAIN2_PGAGAIN5_16 | GAIN2_PGAGAIN4_16
#else
/*! @brief Default gain1 address data   */
#define ADS01_GAIN1_ADDRESS_DATA        GAIN1_PGAGAIN3_1 | GAIN1_PGAGAIN2_1 | GAIN1_PGAGAIN1_1 | GAIN1_PGAGAIN0_1
/*! @brief Default gain2 address data   */
#define ADS01_GAIN2_ADDRESS_DATA        GAIN2_PGAGAIN7_1 | GAIN2_PGAGAIN6_1 | GAIN2_PGAGAIN5_1 | GAIN2_PGAGAIN4_1
#endif

/*! @brief Default CFG address data     */
#define ADS01_CFG_ADDRESS_DATA          CFG_GC_DLY_16 | CFG_GC_EN_DISABLED | CFG_CD_ALLCH_ANY_CHANNEL | CFG_CD_NUM_1 | CFG_CD_LEN_128 | CFG_CD_EN_DISABLED
/*! @brief Default THRSHLD MSB address data   */
#define ADS01_THRSHLD_MSB_ADDRESS_DATA  THRSHLD_MSB_DEFAULT
/*! @brief Default THRSHLD LSB address data   */
#define ADS01_THRSHLD_LSB_ADDRESS_DATA  THRSHLD_LSB_DCBLOCK_DISABLED
/*! @brief Default CH0_CFG address data   */
#define ADS01_CH0_CFG_ADDRESS_DATA      CH0_CFG_DEFAULT
/*! @brief Default CH0 OCAL_MSB address data   */
#define ADS01_CH0_OCAL_MSB_ADDRESS_DATA CH0_OCAL_MSB_DEFAULT
/*! @brief Default CH0 OCAL_LSB address data   */
#define ADS01_CH0_OCAL_LSB_ADDRESS_DATA CH0_OCAL_LSB_DEFAULT
/*! @brief Default CH0 GCAL_MSB address data   */
#define ADS01_CH0_GCAL_MSB_ADDRESS_DATA CH0_GCAL_MSB_DEFAULT
/*! @brief Default CH0 GCAL_LSB address data   */
#define ADS01_CH0_GCAL_LSB_ADDRESS_DATA CH0_GCAL_LSB_DEFAULT
/*! @brief Default CH1_CFG address data   */
#define ADS01_CH1_CFG_ADDRESS_DATA      CH1_CFG_DEFAULT
/*! @brief Default CH1 OCAL_MSB address data   */
#define ADS01_CH1_OCAL_MSB_ADDRESS_DATA CH1_OCAL_MSB_DEFAULT
/*! @brief Default CH1 OCAL_LSB address data   */
#define ADS01_CH1_OCAL_LSB_ADDRESS_DATA CH1_OCAL_LSB_DEFAULT
/*! @brief Default CH1 GCAL_MSB address data   */
#define ADS01_CH1_GCAL_MSB_ADDRESS_DATA CH1_GCAL_MSB_DEFAULT
/*! @brief Default CH1 GCAL_LSB address data   */
#define ADS01_CH1_GCAL_LSB_ADDRESS_DATA CH1_GCAL_LSB_DEFAULT
/*! @brief Default CH2_CFG address data   */
#define ADS01_CH2_CFG_ADDRESS_DATA      CH2_CFG_DEFAULT
/*! @brief Default CH2 OCAL_MSB address data   */
#define ADS01_CH2_OCAL_MSB_ADDRESS_DATA CH2_OCAL_MSB_DEFAULT
/*! @brief Default CH2 OCAL_LSB address data   */
#define ADS01_CH2_OCAL_LSB_ADDRESS_DATA CH2_OCAL_LSB_DEFAULT
/*! @brief Default CH2 GCAL_MSB address data   */
#define ADS01_CH2_GCAL_MSB_ADDRESS_DATA CH2_GCAL_MSB_DEFAULT
/*! @brief Default CH2 GCAL_LSB address data   */
#define ADS01_CH2_GCAL_LSB_ADDRESS_DATA CH2_GCAL_LSB_DEFAULT
/*! @brief Default CH3_CFG address data   */
#define ADS01_CH3_CFG_ADDRESS_DATA      CH3_CFG_DEFAULT
/*! @brief Default CH3 OCAL_MSB address data   */
#define ADS01_CH3_OCAL_MSB_ADDRESS_DATA CH3_OCAL_MSB_DEFAULT
/*! @brief Default CH3 OCAL_LSB address data   */
#define ADS01_CH3_OCAL_LSB_ADDRESS_DATA CH3_OCAL_LSB_DEFAULT
/*! @brief Default CH3 GCAL_MSB address data   */
#define ADS01_CH3_GCAL_MSB_ADDRESS_DATA CH3_GCAL_MSB_DEFAULT
/*! @brief Default CH3 GCAL_LSB address data   */
#define ADS01_CH3_GCAL_LSB_ADDRESS_DATA CH3_GCAL_LSB_DEFAULT
/*! @brief Default CH4_CFG address data   */
#define ADS01_CH4_CFG_ADDRESS_DATA      CH4_CFG_DEFAULT
/*! @brief Default CH4 OCAL_MSB address data   */
#define ADS01_CH4_OCAL_MSB_ADDRESS_DATA CH4_OCAL_MSB_DEFAULT
/*! @brief Default CH4 OCAL_LSB address data   */
#define ADS01_CH4_OCAL_LSB_ADDRESS_DATA CH4_OCAL_LSB_DEFAULT
/*! @brief Default CH4 GCAL_MSB address data   */
#define ADS01_CH4_GCAL_MSB_ADDRESS_DATA CH4_GCAL_MSB_DEFAULT
/*! @brief Default CH4 GCAL_LSB address data   */
#define ADS01_CH4_GCAL_LSB_ADDRESS_DATA CH4_GCAL_LSB_DEFAULT
/*! @brief Default CH5_CFG address data   */
#define ADS01_CH5_CFG_ADDRESS_DATA      CH5_CFG_DEFAULT
/*! @brief Default CH5 OCAL_MSB address data   */
#define ADS01_CH5_OCAL_MSB_ADDRESS_DATA CH5_OCAL_MSB_DEFAULT
/*! @brief Default CH5 OCAL_LSB address data   */
#define ADS01_CH5_OCAL_LSB_ADDRESS_DATA CH5_OCAL_LSB_DEFAULT
/*! @brief Default CH5 GCAL_MSB address data   */
#define ADS01_CH5_GCAL_MSB_ADDRESS_DATA CH5_GCAL_MSB_DEFAULT
/*! @brief Default CH5 GCAL_LSB address data   */
#define ADS01_CH5_GCAL_LSB_ADDRESS_DATA CH5_GCAL_LSB_DEFAULT
/*! @brief Default CH6_CFG address data   */
#define ADS01_CH6_CFG_ADDRESS_DATA      CH6_CFG_DEFAULT
/*! @brief Default CH6 OCAL_MSB address data   */
#define ADS01_CH6_OCAL_MSB_ADDRESS_DATA CH6_OCAL_MSB_DEFAULT
/*! @brief Default CH6 OCAL_LSB address data   */
#define ADS01_CH6_OCAL_LSB_ADDRESS_DATA CH6_OCAL_LSB_DEFAULT
/*! @brief Default CH6 GCAL_MSB address data   */
#define ADS01_CH6_GCAL_MSB_ADDRESS_DATA CH6_GCAL_MSB_DEFAULT
/*! @brief Default CH6 GCAL_LSB address data   */
#define ADS01_CH6_GCAL_LSB_ADDRESS_DATA CH6_GCAL_LSB_DEFAULT
/*! @brief Default CH7_CFG address data   */
#define ADS01_CH7_CFG_ADDRESS_DATA      CH7_CFG_DEFAULT
/*! @brief Default CH7 OCAL_MSB address data   */
#define ADS01_CH7_OCAL_MSB_ADDRESS_DATA CH7_OCAL_MSB_DEFAULT
/*! @brief Default CH7 OCAL_LSB address data   */
#define ADS01_CH7_OCAL_LSB_ADDRESS_DATA CH7_OCAL_LSB_DEFAULT
/*! @brief Default CH7 GCAL_MSB address data   */
#define ADS01_CH7_GCAL_MSB_ADDRESS_DATA CH7_GCAL_MSB_DEFAULT
/*! @brief Default CH7 GCAL_LSB address data   */
#define ADS01_CH7_GCAL_LSB_ADDRESS_DATA CH7_GCAL_LSB_DEFAULT

/*! @brief ADS13M08 initial data*/
extern uint16_t ADS01_initRegData[NUM_REGISTERS + 1];

#ifdef __cplusplus
}
#endif
#endif /* _ADS131M08_DEFAULTS_H_ */
/** @}*/
