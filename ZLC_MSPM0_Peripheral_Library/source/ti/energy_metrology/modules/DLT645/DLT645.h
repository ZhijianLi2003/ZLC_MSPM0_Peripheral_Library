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
 *  @file       DLT645.h
 *  @brief      API's releated to DLT645 communication
 *
 *  @anchor dlt645_h
 *  # Overview
 *
 *  API's releated to DLT645 communication
 *
 *  <hr>
 ******************************************************************************/
/** @addtogroup DLT645
 * @{
 */

#ifndef DLT645_H_
#define DLT645_H_

#include "metrology.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! @brief Defines number of preamble bytes */
#define DLT645_PREAMBLE_BYTES                   (4)
/*! @brief Defines number of header bytes   */
#define DLT645_MESSAGE_HEADER_BYTES             (10)
/*! @brief Defines number of trailer bytes  */
#define DLT645_MESSAGE_TRAILER_BYTES            (2)
/*! @brief The starting byte of the message body in a received DLT645 message. */
#define DLT645_MSG_RX_START_BODY                DLT645_MESSAGE_HEADER_BYTES
/*! @brief The starting 16 bit word of the message body in a received DLT645 message. */
#define DLT645_MSG_RX_START_BODY_W              (DLT645_MESSAGE_HEADER_BYTES >> 1)
/*! @brief The maximum DLT645 message body length to allow for when sizing buffers. */
#define MAX_DLT645_MSG_BODY                     (110)
/*! @brief Defines serial meaasage length   */
#define MAX_SERIAL_MESSAGE_LEN  DLT645_PREAMBLE_BYTES + DLT645_MESSAGE_HEADER_BYTES + DLT645_MESSAGE_TRAILER_BYTES + MAX_DLT645_MSG_BODY
/*! Defines Password 1  */
#define SERIAL_CALIBRATION_PASSWORD_1           (0x1234)
/*! Defines Password 2  */
#define SERIAL_CALIBRATION_PASSWORD_2           (0x5678)
/*! Defines Password 3  */
#define SERIAL_CALIBRATION_PASSWORD_3           (0x9ABC)
/*! Defines Password 4  */
#define SERIAL_CALIBRATION_PASSWORD_4           (0xDEF0)
/*! Defines neutral support */
#define DLT645_NEUTRAL_SUPPORT                  (0x01)
/*! Defines phase correction  support */
#define DLT645_PHASE_CORRECTION_SUPPORT         (0x02)
/*! Defines RTC support */
#define DLT645_RTC_SUPPORT                      (0x08)

/*! @brief Serial message union */
typedef union
{
    /*! @brief 8 bit serial message */
    uint8_t uint8[MAX_SERIAL_MESSAGE_LEN];
    /*! @brief 16 bit serial message    */
    uint16_t uint16[(MAX_SERIAL_MESSAGE_LEN) >> 1];
}SerialMsg;

/*! @brief Serial message buffer    */
typedef struct
{
    /*! @brief Serial message   */
    SerialMsg buf;
    /*! @brief pointer to serial message array  */
    uint8_t ptr;
    /*! @brief Length of serial message */
    uint8_t len;
    /*! @brief Serial message timeut    */
    uint8_t timeOut;
}SerialMsgBuf;

/*! @brief DLT645 buffer    */
typedef struct
{
    /*! @brief serial transmit message  */
    SerialMsgBuf txMsg;
    /*! @brief serial receive message   */
    SerialMsgBuf rxMsg;
    /*! @brief transmit status  */
    int8_t txInProgress;
    /*! @brief receive status   */
    int8_t rxPending;
    /*! @brief GPIO out to enable RS485 */
    HAL_GPIO_OUT  RS485EN;
    /*! @brief HAL UART channel used to communicate with GUI. */
    HAL_UART_CHAN  uartChan;
}DLT645Buf;

/*! @enum DLT645_STATUS */
typedef enum
{
    /*! @brief DLT645 password matched  */
    DLT645_STATUS_PASSWORD_OK = 0x01
}DLT645_STATUS;

/*! @enum HOST_CMD */
typedef enum
{
    /*! @brief Command to get meter configuration   */
    HOST_CMD_GET_METER_CONFIGURATION            = 0x56,
    /*! @brief Command to set meter configuration   */
    HOST_CMD_SET_METER_CONSUMPTION              = 0x57,
    /*! @brief Command to set RTC   */
    HOST_CMD_SET_RTC                            = 0x58,
    /*! @brief Command to get RTC   */
    HOST_CMD_GET_RTC                            = 0x59,
    /*! @brief Command to align with calibration factors   */
    HOST_CMD_ALIGN_WITH_CALIBRATION_FACTORS     = 0x5A,
    /*! @brief Command to set password   */
    HOST_CMD_SET_PASSWORD                       = 0x60,
    /*! @brief Command to get readings in phase 1   */
    HOST_CMD_GET_READINGS_PHASE_1               = 0x61,
    /*! @brief Command to get readings in phase 2   */
    HOST_CMD_GET_READINGS_PHASE_2               = 0x62,
    /*! @brief Command to get readings in phase 3   */
    HOST_CMD_GET_READINGS_PHASE_3               = 0x63,
    /*! @brief Command to get readings in neutral   */
    HOST_CMD_GET_READINGS_NEUTRAL               = 0x64,
    /*! @brief Command to get consumption in phase 1   */
    HOST_CMD_GET_CONSUMPTION_PHASE_1            = 0x65,
    /*! @brief Command to get consumption in phase 2   */
    HOST_CMD_GET_CONSUMPTION_PHASE_2            = 0x66,
    /*! @brief Command to get consumption in phase 3   */
    HOST_CMD_GET_CONSUMPTION_PHASE_3            = 0x67,
    /*! @brief Command to get consumption in all phases   */
    HOST_CMD_GET_CONSUMPTION_AGGREGATE          = 0x68,
    /*! @brief Command to get extra readings in phase 1   */
    HOST_CMD_GET_EXTRA_READINGS_PHASE_1         = 0x69,
    /*! @brief Command to get extra readings in phase 2   */
    HOST_CMD_GET_EXTRA_READINGS_PHASE_2         = 0x6A,
    /*! @brief Command to get extra readings in phase 3   */
    HOST_CMD_GET_EXTRA_READINGS_PHASE_3         = 0x6B,
    /*! @brief Command to get extra readings in neutral   */
    HOST_CMD_GET_EXTRA_READINGS_NEUTRAL         = 0x6C,
    /*! @brief Command to get total readings   */
    HOST_CMD_GET_READINGS_AGGREGATE             = 0x6D,
    /*! @brief Command to get total extra readings   */
    HOST_CMD_GET_EXTRA_READINGS_AGGREGATE       = 0x6E,
    /*! @brief Command to sum check   */
    HOST_CMD_SUMCHECK_MEMORY                    = 0x75,
    /*! @brief Command to get raw active power in Phase 1   */
    HOST_CMD_GET_RAW_ACTIVE_POWER_PHASE_1       = 0x91,
    /*! @brief Command to get raw active power in Phase 2   */
    HOST_CMD_GET_RAW_ACTIVE_POWER_PHASE_2       = 0x92,
    /*! @brief Command to get raw active power in Phase 3   */
    HOST_CMD_GET_RAW_ACTIVE_POWER_PHASE_3       = 0x93,
    /*! @brief Command to get raw reactive power in Phase 1   */
    HOST_CMD_GET_RAW_REACTIVE_POWER_PHASE_1     = 0x95,
    /*! @brief Command to get raw reactive power in Phase 2   */
    HOST_CMD_GET_RAW_REACTIVE_POWER_PHASE_2     = 0x96,
    /*! @brief Command to get raw reactive power in Phase 3   */
    HOST_CMD_GET_RAW_REACTIVE_POWER_PHASE_3     = 0x97,
    /*! @brief Command to get raw active power neutral   */
    HOST_CMD_GET_RAW_ACTIVE_POWER_NEUTRAL       = 0x99,
    /*! @brief Command to get raw reactive power neutral   */
    HOST_CMD_GET_RAW_REACTIVE_POWER_NEUTRAL     = 0x9D,
    /*! @brief Command to check RTC error   */
    HOST_CMD_CHECK_RTC_ERROR                    = 0xA0,
    /*! @brief Command to correction in RTC   */
    HOST_CMD_RTC_CORRECTION                     = 0xA1,
    /*! @brief Command to set multirate parameters   */
    HOST_CMD_MULTIRATE_SET_PARAMETERS           = 0xC0,
    /*! @brief Command to get multirate parameters   */
    HOST_CMD_MULTIRATE_GET_PARAMETERS           = 0xC1,
    /*! @brief Command to clear multirate usage    */
    HOST_CMD_MULTIRATE_CLEAR_USAGE              = 0xC2,
    /*! @brief Command to get multirate usage   */
    HOST_CMD_MULTIRATE_GET_USAGE                = 0xC3,
    /*! @brief Command to clear calibration data  */
    HOST_CMD_CLEAR_CALIBRATION_DATA             = 0xD0,
    /*! @brief Command to set calibration data in phase 1   */
    HOST_CMD_SET_CALIBRATION_PHASE_1            = 0xD1,
    /*! @brief Command to set calibration data in phase 2   */
    HOST_CMD_SET_CALIBRATION_PHASE_2            = 0xD2,
    /*! @brief Command to set calibration data in phase 3   */
    HOST_CMD_SET_CALIBRATION_PHASE_3            = 0xD3,
    /*! @brief Command to set calibration data in neutral   */
    HOST_CMD_SET_CALIBRATION_NEUTRAL            = 0xD4,
    /*! @brief Command to set extra calibration data   */
    HOST_CMD_SET_CALIBRATION_EXTRAS             = 0xD5,
    /*! @brief Command to get calibration data in phase 1   */
    HOST_CMD_GET_CALIBRATION_PHASE_1            = 0xD6,
    /*! @brief Command to get calibration data in phase 2   */
    HOST_CMD_GET_CALIBRATION_PHASE_2            = 0xD7,
    /*! @brief Command to get calibration data in phase 3   */
    HOST_CMD_GET_CALIBRATION_PHASE_3            = 0xD8,
    /*! @brief Command to get calibration data in neutral   */
    HOST_CMD_GET_CALIBRATION_NEUTRAL            = 0xD9,
    /*! @brief Command to get extra calibration data   */
    HOST_CMD_GET_CALIBRATION_EXTRAS             = 0xDA
}HOST_CMD;

/*! @enum METER_CONFIG_1 */
typedef enum
{
    /*! @brief Configure active power   */
    METER_CONFIG_1_ACTIVE_POWER                      = 0x01,
    /*! @brief Configure reactive power   */
    METER_CONFIG_1_REACTIVE_POWER                    = 0x02,
    /*! @brief Configure apparent power   */
    METER_CONFIG_1_APPARENT_POWER                    = 0x04,
    /*! @brief Configure rms voltage   */
    METER_CONFIG_1_VRMS                              = 0x08,
    /*! @brief Configure rms current   */
    METER_CONFIG_1_IRMS                              = 0x10,
    /*! @brief Configure power factor   */
    METER_CONFIG_1_POWER_FACTOR                      = 0x20,
    /*! @brief Configure mains frequency   */
    METER_CONFIG_1_MAINS_FREQUENCY                   = 0x40,
    /*! @brief Configure quadrature reactive power   */
    METER_CONFIG_1_QUADRATURE_REACTIVE_POWER         = 0x80
}METER_CONFIG_1;

/*! @enum METER_CONFIG_2 */
typedef enum
{
    /*! @brief Configure fundamental apparent power   */
    METER_CONFIG_2_FUNDAMENTAL_APPARENT_POWER        = 0x01,
    /*! @brief Configure fundamental active power     */
    METER_CONFIG_2_FUNDAMENTAL_ACTIVE_POWER          = 0x02,
    /*! @brief Configure fundamental reactive power   */
    METER_CONFIG_2_FUNDAMENTAL_REACTIVE_POWER        = 0x04,
    /*! @brief Configure fundamental rms voltage  */
    METER_CONFIG_2_FUNDAMENTAL_VRMS                  = 0x08,
    /*! @brief Configure fundamental rms current  */
    METER_CONFIG_2_FUNDAMENTAL_IRMS                  = 0x10,
    /*! @brief Configure voltage THD  */
    METER_CONFIG_2_VOLTAGE_THD                       = 0x20,
    /*! @brief Configure current THD  */
    METER_CONFIG_2_CURRENT_THD                       = 0x40,
    /*! @brief Configure sag swell detection  */
    METER_CONFIG_2_SAG_SWELL                         = 0x80
}METER_CONFIG_2;

/*!
 * @brief DLT645 UART receive DMA init
 * @param[in] dlt645      The DLT645 instance
 */
void DLT645_UARTRxdmaInit(DLT645Buf *dlt645);

/*!
 * @brief DLT645 service
 * @param[in] workingData The metrology instance
 * @param[in] dlt645      The DLT645 instance
 */
void DLT645_service(metrologyData *workingData, DLT645Buf *dlt645);

/*!
 * @brief Read all RX Data to RX buffer
 * @param[in] dlt645 The DLT645 instance
 * @param[in] ch     RX data
 */
void DLT645_rxByte(DLT645Buf *dlt645, uint8_t ch);

/*!
 * @brief Read UART receive byte
 * @param[in] dlt645 The dlt645 instance
 */
void DLT645_UARTRxByte(DLT645Buf *dlt645);

/*!
 * @brief Get UART transmit byte
 * @param[in] dlt645 The dlt645 instance
 * @return UART transmit byte
 */
uint16_t DLT645_UARTTxByte(DLT645Buf *dlt645);

#ifdef __cplusplus
}
#endif
#endif /* DLT645_H_ */
/** @}*/
