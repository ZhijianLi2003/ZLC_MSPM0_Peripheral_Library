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
 *  @file       ADS131M0x.h
 *  @brief      ADS131M0x module
 *
 *  @anchor ADS131M0x_h
 *  # Overview
 *
 *  APIs related to ADS131M0x
 *
 *  <hr>
 ******************************************************************************/
/** @addtogroup ADS131M0x
 * @{
 */

#ifndef ADS131M0X_H_
#define ADS131M0X_H_

#include <assert.h>
#include "hal.h"
#include "template.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef ADS_CHANNELCOUNT
#define ADS_CHANNELCOUNT            (8)
#endif

/*! @brief ADS DMA Transfer Done    */
#define ADS_DMA_TRANSFER_DONE       0x01
/*! @brief ADS DMA Ready to transfer    */
#define ADS_DMA_TRANSFER_READY      0x00
/*! @brief ADS DMA waiting for dma interrupt    */
#define ADS_DMA_WAITING             0x01
/*! @brief ADS DMA is in idle state */
#define ADS_DMA_IDLE                0x00
/*! @brief ADS register word length 16 bit    */
#define ADS_REG_WORD_LENGTH_16BIT                       (2)
/*! @brief ADS register word length 24 bit    */
#define ADS_REG_WORD_LENGTH_24BIT                       (3)
/*! @brief ADS register word length 32 bit sign extended   */
#define ADS_REG_WORD_LENGTH_32BIT_SIGN_EXTEND           (4)
/*! @brief ADS register word length 16 bit zero padded   */
#define ADS_REG_WORD_LENGTH_32BIT_ZERO_PADDED           (4)
/*! @brief ADS command word length    */
#define ADS_CMDLENGTH           (1)
/*! @brief ADS CRC word length        */
#define ADS_CRCLENGTH           (1)
/*! @brief ADS data word length       */
#define ADS_WORDLENGTH          ADS_REG_WORD_LENGTH_24BIT
/*! @brief ADS number of registers  */
#define NUM_REGISTERS           (64)
/*! @brief ADS byte length          */
#define ADS_BYTELENGTH          ((ADS_CMDLENGTH + ADS_CRCLENGTH + ADS_CHANNELCOUNT) * ADS_WORDLENGTH)
/*! @brief ADS CRC initial value    */
#define ADS_CRC_INITAL_VALUE    (0xFFFF)
/*! @brief upper byte mask for uint16_t */
#define ADS_UPPER_BYTE_MASK     (0xFF00)
/*! @brief lower byte mask for uint16_t */
#define ADS_LOWER_BYTE_MASK     (0x00FF)

/*! @brief Defines ADS Channel data */
typedef struct
{
    /*! @brief ADS response word    */
    uint16_t response;
    /*! @brief ADS CRC word         */
    uint16_t crc;
    /*! @brief ADS channel0 data    */
    int32_t chan0;
#if (ADS_CHANNELCOUNT > 1)
    /*! @brief ADS channel1 data    */
    int32_t chan1;
#endif
#if (ADS_CHANNELCOUNT > 2)
    /*! @brief ADS channel2 data    */
    int32_t chan2;
#endif
#if (ADS_CHANNELCOUNT > 3)
    /*! @brief ADS channel3 data    */
    int32_t chan3;
#endif
#if (ADS_CHANNELCOUNT > 4)
    /*! @brief ADS channel4 data    */
    int32_t chan4;
#endif
#if (ADS_CHANNELCOUNT > 5)
    /*! @brief ADS channel5 data    */
    int32_t chan5;
#endif
#if (ADS_CHANNELCOUNT > 6)
    /*! @brief ADS channel6 data    */
    int32_t chan6;
#endif
#if (ADS_CHANNELCOUNT > 7)
    /*! @brief ADS channel7 data    */
    int32_t chan7;
#endif
}ADS_channelData;

/*! @enum ADS_CRC_TYPE    */
typedef enum
{
    /*! @brief ADS CRC type CCITT   */
    ADS_CRC_TYPE_CCITT = 0,
    /*! @brief ADS CRC type ANSI    */
    ADS_CRC_TYPE_ANSI
}ADS_CRC_TYPE;

/*! @enum ADS_CRC   */
typedef enum
{
    /*! @brief ADS CRC disable      */
    ADS_CRC_DISABLE = 0,
    /*! @brief ADS CRC enable       */
    ADS_CRC_ENABLE
}ADS_CRC;

/*! @brief ADS_Instance     */
typedef struct
{
    /*! @brief HAL input pin connected to ADS ready pin. */
    HAL_GPIO_IN         ready;
    /*! @brief HAL output pin connected to ADS sync pin. */
    HAL_GPIO_OUT        sync;
    /*! @brief HAL SPI channel used to communicate with ADS. */
    HAL_SPI_CHAN        spiChan;
    /*! @brief HAL SPI CS pin connected to ADS CS pin. */
    HAL_SPI_CS          spiCs;
    /*! @brief Structure to store the sampled data. */
    ADS_channelData     channelData;
    /*! @brief ADS CRC Status */
    ADS_CRC             crcEnable;
    /*! @brief ADS CRC type */
    ADS_CRC_TYPE        crcType;
    /*! @brief array to store the raw adc data received */
    uint8_t             rawdata[ADS_BYTELENGTH];
    /*! @brief Array to store ADS register data */
    uint16_t            ADS_initRegData[NUM_REGISTERS + 1];
    /*! @brief Store DMA status */
    uint8_t             DMAStatus;
    /*!
     * @brief Store DMA wait status
     *        1 when waiting for DMA interrupt
     *        0 otherwise
     */
    uint8_t             DMAWait;
    /*! @brief Store data collection status */
    uint8_t             datacollectionStatus;
    /*! @brief Store crc pass count */
    uint32_t            crcPassCount;
    /*! @brief Store crc pass count */
    uint32_t            crcFailCount;
}ADS_Instance;

/*! @enum ADS_OPCODES   */
typedef enum
{
    /*! @brief opcode to read status register   */
    ADS_OPCODE_NULL     = 0x0000,
    /*! @brief opcode to reset ADS  */
    ADS_OPCODE_RESET    = 0x0011,
    /*! @brief opcode to set ADS in standby mode    */
    ADS_OPCODE_STANDBY  = 0x0022,
    /*! @brief opcode to wakeup the ADS */
    ADS_OPCODE_WAKEUP   = 0x0033,
    /*! @brief opcode to lock ADS   */
    ADS_OPCODE_LOCK     = 0x0555,
    /*! @brief opcode to unlock ADS   */
    ADS_OPCODE_UNLOCK   = 0x0655,
    /*! @brief opcode to read ADS registers  */
    ADS_OPCODE_RREG     = 0xA000,
    /*! @brief opcode to write ADS registers  */
    ADS_OPCODE_WREG     = 0x6000
}ADS_OPCODES;

//****************************************************************************
//
// Register definitions
//
//****************************************************************************

/* NOTE: Whenever possible, macro names (defined below) were derived from
 * datasheet defined names; however, updates to documentation may cause
 * mismatches between names defined here in example code from those shown
 * in the device datasheet.
 */

/* Register 0x00 (ID) definition - READ ONLY
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                    RESERVED[3:0]                  |                    CHANCNT[3:0]                   |                                               REVID[7:0]                                              |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Defines ID register address   */
    #define ID_ADDRESS             ((uint8_t)  0x00)
    /*! @brief Defines ID register defaults   */
    #define ID_DEFAULT             ((uint16_t) 0x2000 | (ADS_CHANNELCOUNT << 8))

    /*! @brief Defines ID register reserved mask   */
    #define ID_RESERVED_MASK       ((uint16_t) 0xF000)

    /*! @brief Defines ID register channel count mask   */
    #define ID_CHANCNT_MASK        ((uint16_t) 0x0F00)
    /*! @brief Defines ID register channel count 4   */
    #define ID_CHANCNT_4CH         ((uint16_t) 0x0004 << 8)
    /*! @brief Defines ID register channel count 6   */
    #define ID_CHANCNT_6CH         ((uint16_t) 0x0006 << 8)
    /*! @brief Defines ID register channel count 8   */
    #define ID_CHANCNT_8CH         ((uint16_t) 0x0008 << 8)

    /*! @brief Defines ID register reserved mask   */
    #define ID_REVID_MASK          ((uint16_t) 0x00FF)
    /*! @brief Defines ID register reserved default   */
    #define ID_REVID_REVA          ((uint16_t) 0x0000 << 0)    /* DEFAULT */ 


/* Register 0x01 (STATUS) definition - READ ONLY
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |    LOCK    |  F_RESYNC  |   REG_MAP  |   CRC_ERR  |  CRC_TYPE  |    RESET   |       WLENGTH[1:0]      |    DRDY7   |    DRDY6   |    DRDY5   |    DRDY4   |    DRDY3   |    DRDY2   |    DRDY1   |    DRDY0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *  NOTE 1: Bits 0 through 7 are hardware controlled. Reading these values multiple times may return different results.
 *  NOTE 2: Bits 7 through 4 are RESERVED on the ADS131M04. These bits will always read 0.
 */

    /*! @brief Defines status register address   */
    #define STATUS_ADDRESS                    ((uint8_t)  0x01)
    /*! @brief Defines status register default value  */
    #define STATUS_DEFAULT                    ((uint16_t) 0x0500)

    /*! @brief Defines status register lock mask   */
    #define STATUS_LOCK_MASK                  ((uint16_t) 0x8000)
    /*! @brief Defines status register unlocked  */
    #define STATUS_LOCK_UNLOCKED              ((uint16_t) 0x0000 << 15)   /* DEFAULT */ 
    /*! @brief Defines status register locked   */
    #define STATUS_LOCK_LOCKED                ((uint16_t) 0x0001 << 15)

    /*! @brief Defines status register resync mask   */
    #define STATUS_F_RESYNC_MASK              ((uint16_t) 0x4000)
    /*! @brief Defines status register resync no fault   */
    #define STATUS_F_RESYNC_NO_FAULT          ((uint16_t) 0x0000 << 14)   /* DEFAULT */ 
    /*! @brief Defines status register resync fault   */
    #define STATUS_F_RESYNC_FAULT             ((uint16_t) 0x0001 << 14)

    /*! @brief Defines status register reg map mask   */
    #define STATUS_REG_MAP_MASK               ((uint16_t) 0x2000)
    /*! @brief Defines status register reg map no CRC change   */
    #define STATUS_REG_MAP_NO_CHANGE_CRC      ((uint16_t) 0x0000 << 13)   /* DEFAULT */ 
    /*! @brief Defines status register reg map CRC change   */
    #define STATUS_REG_MAP_CHANGED_CRC        ((uint16_t) 0x0001 << 13)

    /*! @brief Defines status register CRC error mask   */
    #define STATUS_CRC_ERR_MASK               ((uint16_t) 0x1000)
    /*! @brief Defines status register no CRC error    */
    #define STATUS_CRC_ERR_NO_CRC_ERROR       ((uint16_t) 0x0000 << 12)   /* DEFAULT */ 
    /*! @brief Defines status register CRC error    */
    #define STATUS_CRC_ERR_INPUT_CRC_ERROR    ((uint16_t) 0x0001 << 12)

    /*! @brief Defines status register CRC type mask   */
    #define STATUS_CRC_TYPE_MASK              ((uint16_t) 0x0800)
    /*! @brief Defines status register CRC type 16 bit CCITT   */
    #define STATUS_CRC_TYPE_16BIT_CCITT       ((uint16_t) 0x0000 << 11)   /* DEFAULT */ 
    /*! @brief Defines status register CRC type 16 bit ANSI   */
    #define STATUS_CRC_TYPE_16BIT_ANSI        ((uint16_t) 0x0001 << 11)

    /*! @brief Defines status register reset mask   */
    #define STATUS_RESET_MASK                 ((uint16_t) 0x0400)
    /*! @brief Defines status register no reset    */
    #define STATUS_RESET_NO_RESET             ((uint16_t) 0x0000 << 10)
    /*! @brief Defines status register reset    */
    #define STATUS_RESET_RESET_OCCURRED       ((uint16_t) 0x0001 << 10)   /* DEFAULT */ 

    /*! @brief Defines status register word length mask   */
    #define STATUS_WLENGTH_MASK               ((uint16_t) 0x0300)
    /*! @brief Defines status register word length 16 bit   */
    #define STATUS_WLENGTH_16BIT              ((uint16_t) 0x0000 << 8)
    /*! @brief Defines status register word length 24 bit   */
    #define STATUS_WLENGTH_24BIT              ((uint16_t) 0x0001 << 8)    /* DEFAULT */ 
    /*! @brief Defines status register word length 32 bits   */
    #define STATUS_WLENGTH_32BIT_LSB_ZEROES   ((uint16_t) 0x0002 << 8)
    /*! @brief Defines status register word length 32 bit   */
    #define STATUS_WLENGTH_32BIT_MSB_SIGN_EXT ((uint16_t) 0x0003 << 8)


    /*! @brief Defines status register DRDY7 mask   */
    #define STATUS_DRDY7_MASK                 ((uint16_t) 0x0080)
    /*! @brief Defines status register DRDY7 no new data   */
    #define STATUS_DRDY7_NO_NEW_DATA          ((uint16_t) 0x0000 << 7)
    /*! @brief Defines status register DRDY7 new data   */
    #define STATUS_DRDY7_NEW_DATA             ((uint16_t) 0x0001 << 7)


    /*! @brief Defines status register DRDY6 mask   */
    #define STATUS_DRDY6_MASK                 ((uint16_t) 0x0040)
    /*! @brief Defines status register DRDY6 no new data   */
    #define STATUS_DRDY6_NO_NEW_DATA          ((uint16_t) 0x0000 << 6)
    /*! @brief Defines status register DRDY6 new data   */
    #define STATUS_DRDY6_NEW_DATA             ((uint16_t) 0x0001 << 6)


    /*! @brief Defines status register DRDY5 mask   */
    #define STATUS_DRDY5_MASK                 ((uint16_t) 0x0020)
    /*! @brief Defines status register DRDY5 no new data   */
    #define STATUS_DRDY5_NO_NEW_DATA          ((uint16_t) 0x0000 << 5)
    /*! @brief Defines status register DRDY5 new data   */
    #define STATUS_DRDY5_NEW_DATA             ((uint16_t) 0x0001 << 5)


    /*! @brief Defines status register DRDY4 mask   */
    #define STATUS_DRDY4_MASK                 ((uint16_t) 0x0010)
    /*! @brief Defines status register DRDY4 no new data   */
    #define STATUS_DRDY4_NO_NEW_DATA          ((uint16_t) 0x0000 << 4)
    /*! @brief Defines status register DRDY4 new data   */
    #define STATUS_DRDY4_NEW_DATA             ((uint16_t) 0x0001 << 4)


    /*! @brief Defines status register DRDY3 mask   */
    #define STATUS_DRDY3_MASK                 ((uint16_t) 0x0008)
    /*! @brief Defines status register DRDY3 no new data   */
    #define STATUS_DRDY3_NO_NEW_DATA          ((uint16_t) 0x0000 << 3)
    /*! @brief Defines status register DRDY3 new data   */
    #define STATUS_DRDY3_NEW_DATA             ((uint16_t) 0x0001 << 3)


    /*! @brief Defines status register DRDY2 mask   */
    #define STATUS_DRDY2_MASK                 ((uint16_t) 0x0004)
    /*! @brief Defines status register DRDY2 no new data   */
    #define STATUS_DRDY2_NO_NEW_DATA          ((uint16_t) 0x0000 << 2)
    /*! @brief Defines status register DRDY2 new data   */
    #define STATUS_DRDY2_NEW_DATA             ((uint16_t) 0x0001 << 2)


    /*! @brief Defines status register DRDY1 mask   */
    #define STATUS_DRDY1_MASK                 ((uint16_t) 0x0002)
    /*! @brief Defines status register DRDY1 no new data   */
    #define STATUS_DRDY1_NO_NEW_DATA          ((uint16_t) 0x0000 << 1)
    /*! @brief Defines status register DRDY1 new data   */
    #define STATUS_DRDY1_NEW_DATA             ((uint16_t) 0x0001 << 1)

    /*! @brief Defines status register DRDY0 mask   */
    #define STATUS_DRDY0_MASK                 ((uint16_t) 0x0001)
    /*! @brief Defines status register DRDY0 no new data   */
    #define STATUS_DRDY0_NO_NEW_DATA          ((uint16_t) 0x0000 << 0)
    /*! @brief Defines status register DRDY0 new data   */
    #define STATUS_DRDY0_NEW_DATA             ((uint16_t) 0x0001 << 0)



/* Register 0x02 (MODE) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |      RESERVED0[1:0]     | REG_CRC_EN |  RX_CRC_EN |  CRC_TYPE  |    RESET   |       WLENGTH[1:0]      |             RESERVED1[2:0]           |   TIMEOUT  |       DRDY_SEL[1:0]     |  DRDY_HiZ  |  DRDY_FMT  |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Defines mode register address  */
    #define MODE_ADDRESS                                                    ((uint8_t)  0x02)
    /*! @brief Defines mode register default  */
    #define MODE_DEFAULT                                                    ((uint16_t) 0x0510)

    /*! @brief Defines mode register reserved mask  */
    #define MODE_RESERVED0_MASK                                             ((uint16_t) 0xC000)

    /*! @brief Defines mode register CRC EN mask  */
    #define MODE_REG_CRC_EN_MASK                                            ((uint16_t) 0x2000)
    /*! @brief Defines mode register CRC EN disabled  */
    #define MODE_REG_CRC_EN_DISABLED                                        ((uint16_t) 0x0000 << 13)   /* DEFAULT */ 
    /*! @brief Defines mode register CRC EN enabled  */
    #define MODE_REG_CRC_EN_ENABLED                                         ((uint16_t) 0x0001 << 13)

    /*! @brief Defines mode register RX CRC EN mask  */
    #define MODE_RX_CRC_EN_MASK                                             ((uint16_t) 0x1000)
    /*! @brief Defines mode register RX CRC EN disabled  */
    #define MODE_RX_CRC_EN_DISABLED                                         ((uint16_t) 0x0000 << 12)   /* DEFAULT */ 
    /*! @brief Defines mode register RX CRC EN enabled  */
    #define MODE_RX_CRC_EN_ENABLED                                          ((uint16_t) 0x0001 << 12)

    /*! @brief Defines mode register CRC type mask  */
    #define MODE_CRC_TYPE_MASK                                              ((uint16_t) 0x0800)
    /*! @brief Defines mode register CRC type 16 bit CCITT  */
    #define MODE_CRC_TYPE_16BIT_CCITT                                       ((uint16_t) 0x0000 << 11)   /* DEFAULT */ 
    /*! @brief Defines mode register CRC type 16 bit ANSI  */
    #define MODE_CRC_TYPE_16BIT_ANSI                                        ((uint16_t) 0x0001 << 11)

    /*! @brief Defines mode register reset mask  */
    #define MODE_RESET_MASK                                                 ((uint16_t) 0x0400)
    /*! @brief Defines mode register no reset  */
    #define MODE_RESET_NO_RESET                                             ((uint16_t) 0x0000 << 10)
    /*! @brief Defines mode register reset occured  */
    #define MODE_RESET_RESET_OCCURRED                                       ((uint16_t) 0x0001 << 10)   /* DEFAULT */ 

    /*! @brief Defines mode register word length mask  */
    #define MODE_WLENGTH_MASK                                               ((uint16_t) 0x0300)
    /*! @brief Defines mode register word length 16 bit  */
    #define MODE_WLENGTH_16BIT                                              ((uint16_t) 0x0000 << 8)
    /*! @brief Defines mode register word length 24 bit  */
    #define MODE_WLENGTH_24BIT                                              ((uint16_t) 0x0001 << 8)
    /*! @brief Defines mode register word length 32 bits  */
    #define MODE_WLENGTH_32BIT_LSB_ZEROES                                   ((uint16_t) 0x0002 << 8)
    /*! @brief Defines mode register word length 32 bit  */
    #define MODE_WLENGTH_32BIT_MSB_SIGN_EXT                                 ((uint16_t) 0x0003 << 8)

    /*! @brief Defines mode register reserved mask  */
    #define MODE_RESERVED1_MASK                                             ((uint16_t) 0x00E0)

    /*! @brief Defines mode register timeout mask  */
    #define MODE_TIMEOUT_MASK                                               ((uint16_t) 0x0010)
    /*! @brief Defines mode register timeout disabled  */
    #define MODE_TIMEOUT_DISABLED                                           ((uint16_t) 0x0000 << 4)
    /*! @brief Defines mode register timeout enabled  */
    #define MODE_TIMEOUT_ENABLED                                            ((uint16_t) 0x0001 << 4)    /* DEFAULT */ 

    /*! @brief Defines mode register DRDY_SEL mask  */
    #define MODE_DRDY_SEL_MASK                                              ((uint16_t) 0x000C)
    /*! @brief Defines mode register DRDY_SEL most lagging  */
    #define MODE_DRDY_SEL_MOST_LAGGING                                      ((uint16_t) 0x0000 << 2)    /* DEFAULT */ 
    /*! @brief Defines mode register DRDY_SEL logic OR  */
    #define MODE_DRDY_SEL_LOGIC_OR                                          ((uint16_t) 0x0001 << 2)
    /*! @brief Defines mode register DRDY_SEL most leading  */
    #define MODE_DRDY_SEL_MOST_LEADING                                      ((uint16_t) 0x0002 << 2)    // Alternative value: ((uint16_t) 0x0003 << 2)

    /*! @brief Defines mode register DRDY_HiZ mask  */
    #define MODE_DRDY_HiZ_MASK                                              ((uint16_t) 0x0002)
    /*! @brief Defines mode register DRDY_HiZ logic high  */
    #define MODE_DRDY_HiZ_LOGIC_HIGH                                        ((uint16_t) 0x0000 << 1)    /* DEFAULT */ 
    /*! @brief Defines mode register DRDY_HiZ high impedence  */
    #define MODE_DRDY_HiZ_HIGH_IMPEDANCE                                    ((uint16_t) 0x0001 << 1)

    /*! @brief Defines mode register DRDY_FMT mask  */
    #define MODE_DRDY_FMT_MASK                                              ((uint16_t) 0x0001)
    /*! @brief Defines mode register DRDY_FMT low  */
    #define MODE_DRDY_FMT_LOGIC_LOW                                         ((uint16_t) 0x0000 << 0)    /* DEFAULT */ 
    /*! @brief Defines mode register DRDY_FMT neg pulse fixed width  */
    #define MODE_DRDY_FMT_NEG_PULSE_FIXED_WIDTH                             ((uint16_t) 0x0001 << 0)



/* Register 0x03 (CLOCK) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   CH7_EN   |   CH6_EN   |   CH5_EN   |   CH4_EN   |   CH3_EN   |   CH2_EN   |   CH1_EN   |   CH0_EN   |  XTAL_DIS  |  EXTREF_EN |  RESERVED  |               OSR[2:0]               |         PWR[1:0]        |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *  NOTE 1: Bits 5 through 7 and 12 through 15 are RESERVED on the ADS131M04.
 */

    /*! @brief Defines clock register address  */
    #define CLOCK_ADDRESS                                                   ((uint8_t)  0x03)

    /*! @brief Defines clock register default  */
    #if (ADS_CHANNELCOUNT == 8)
    #define CLOCK_DEFAULT                                                   ((uint16_t) 0xFF0E)
    #endif
    #if (ADS_CHANNELCOUNT == 7)
    #define CLOCK_DEFAULT                                                   ((uint16_t) 0x7F0E)
    #endif
    #if (ADS_CHANNELCOUNT == 6)
    #define CLOCK_DEFAULT                                                   ((uint16_t) 0x3F0E)
    #endif
    #if (ADS_CHANNELCOUNT == 5)
    #define CLOCK_DEFAULT                                                   ((uint16_t) 0x1F0E)
    #endif
    #if (ADS_CHANNELCOUNT == 4)
    #define CLOCK_DEFAULT                                                   ((uint16_t) 0x0F0E)
    #endif
    #if (ADS_CHANNELCOUNT == 3)
    #define CLOCK_DEFAULT                                                   ((uint16_t) 0x070E)
    #endif
    #if (ADS_CHANNELCOUNT == 2)
    #define CLOCK_DEFAULT                                                   ((uint16_t) 0x030E)
    #endif
    #if (ADS_CHANNELCOUNT == 1)
    #define CLOCK_DEFAULT                                                   ((uint16_t) 0x010E)
    #endif


    /*! @brief Defines clock register CH7 EN mask  */
    #define CLOCK_CH7_EN_MASK                                               ((uint16_t) 0x8000)
    /*! @brief Defines clock register CH7 EN Disabled  */
    #define CLOCK_CH7_EN_DISABLED                                           ((uint16_t) 0x0000 << 15)
    /*! @brief Defines clock register CH7 EN enabled  */
    #define CLOCK_CH7_EN_ENABLED                                            ((uint16_t) 0x0001 << 15)


    /*! @brief Defines clock register CH6 EN mask  */
    #define CLOCK_CH6_EN_MASK                                               ((uint16_t) 0x4000)
    /*! @brief Defines clock register CH6 EN Disabled  */
    #define CLOCK_CH6_EN_DISABLED                                           ((uint16_t) 0x0000 << 14)
    /*! @brief Defines clock register CH6 EN enabled  */
    #define CLOCK_CH6_EN_ENABLED                                            ((uint16_t) 0x0001 << 14)


    /*! @brief Defines clock register CH5 EN mask  */
    #define CLOCK_CH5_EN_MASK                                               ((uint16_t) 0x2000)
    /*! @brief Defines clock register CH5 EN Disabled  */
    #define CLOCK_CH5_EN_DISABLED                                           ((uint16_t) 0x0000 << 13)
    /*! @brief Defines clock register CH5 EN enabled  */
    #define CLOCK_CH5_EN_ENABLED                                            ((uint16_t) 0x0001 << 13)


    /*! @brief Defines clock register CH4 EN mask  */
    #define CLOCK_CH4_EN_MASK                                               ((uint16_t) 0x1000)
    /*! @brief Defines clock register CH4 EN Disabled  */
    #define CLOCK_CH4_EN_DISABLED                                           ((uint16_t) 0x0000 << 12)
    /*! @brief Defines clock register CH4 EN enabled  */
    #define CLOCK_CH4_EN_ENABLED                                            ((uint16_t) 0x0001 << 12)


    /*! @brief Defines clock register CH3 EN mask  */
    #define CLOCK_CH3_EN_MASK                                               ((uint16_t) 0x0800)
    /*! @brief Defines clock register CH3 EN Disabled  */
    #define CLOCK_CH3_EN_DISABLED                                           ((uint16_t) 0x0000 << 11)
    /*! @brief Defines clock register CH3 EN enabled  */
    #define CLOCK_CH3_EN_ENABLED                                            ((uint16_t) 0x0001 << 11)


    /*! @brief Defines clock register CH2 EN mask  */
    #define CLOCK_CH2_EN_MASK                                               ((uint16_t) 0x0400)
    /*! @brief Defines clock register CH2 EN Disabled  */
    #define CLOCK_CH2_EN_DISABLED                                           ((uint16_t) 0x0000 << 10)
    /*! @brief Defines clock register CH2 EN enabled  */
    #define CLOCK_CH2_EN_ENABLED                                            ((uint16_t) 0x0001 << 10)


    /*! @brief Defines clock register CH1 EN mask  */
    #define CLOCK_CH1_EN_MASK                                               ((uint16_t) 0x0200)
    /*! @brief Defines clock register CH1 EN Disabled  */
    #define CLOCK_CH1_EN_DISABLED                                           ((uint16_t) 0x0000 << 9)
    /*! @brief Defines clock register CH1 EN enabled  */
    #define CLOCK_CH1_EN_ENABLED                                            ((uint16_t) 0x0001 << 9)


    /*! @brief Defines clock register CH0 EN mask  */
    #define CLOCK_CH0_EN_MASK                                               ((uint16_t) 0x0100)
    /*! @brief Defines clock register CH0 EN Disabled  */
    #define CLOCK_CH0_EN_DISABLED                                           ((uint16_t) 0x0000 << 8)
    /*! @brief Defines clock register CH0 EN enabled  */
    #define CLOCK_CH0_EN_ENABLED                                            ((uint16_t) 0x0001 << 8)    /* DEFAULT */ 

    /*! @brief Defines clock register reserved mask 04 */
    #define CLOCK_RESERVED_MASK_M04                                         ((uint16_t) 0x00E0)
    /*! @brief Defines clock register reserved mask 08 */
    #define CLOCK_RESERVED_MASK_M08                                         ((uint16_t) 0x0020)

    /*! @brief Defines clock register XTAL DIS mask */
    #define CLOCK_XTAL_DIS_MASK                                             ((uint16_t) 0x0080)
    /*! @brief Defines clock register XTAL DIS enabled */
    #define CLOCK_XTAL_DIS_ENABLED                                          ((uint16_t) 0x0000 << 7)    /* DEFAULT */ 
    /*! @brief Defines clock register XTAL DIS disabled */
    #define CLOCK_XTAL_DIS_DISABLED                                         ((uint16_t) 0x0001 << 7)

    /*! @brief Defines clock register EXTREF_EN mask */
    #define CLOCK_EXTREF_EN_MASK                                            ((uint16_t) 0x0040)
    /*! @brief Defines clock register EXTREF_EN disabled */
    #define CLOCK_EXTREF_EN_DISABLED                                        ((uint16_t) 0x0000 << 6)    /* DEFAULT */ 
    /*! @brief Defines clock register EXTREF_EN enabled */
    #define CLOCK_EXTREF_EN_ENABLED                                         ((uint16_t) 0x0001 << 6)

    /*! @brief Defines clock register OSR mask */
    #define CLOCK_OSR_MASK                                                  ((uint16_t) 0x001C)
    /*! @brief Defines clock register 128 mask */
    #define CLOCK_OSR_128                                                   ((uint16_t) 0x0000 << 2)
    /*! @brief Defines clock register 256 mask */
    #define CLOCK_OSR_256                                                   ((uint16_t) 0x0001 << 2)
    /*! @brief Defines clock register 512 mask */
    #define CLOCK_OSR_512                                                   ((uint16_t) 0x0002 << 2)
    /*! @brief Defines clock register 1024 mask */
    #define CLOCK_OSR_1024                                                  ((uint16_t) 0x0003 << 2)    /* DEFAULT */ 
    /*! @brief Defines clock register 2048 mask */
    #define CLOCK_OSR_2048                                                  ((uint16_t) 0x0004 << 2)
    /*! @brief Defines clock register 4096 mask */
    #define CLOCK_OSR_4096                                                  ((uint16_t) 0x0005 << 2)
    /*! @brief Defines clock register 8192 mask */
    #define CLOCK_OSR_8192                                                  ((uint16_t) 0x0006 << 2)
    /*! @brief Defines clock register 16384 mask */
    #define CLOCK_OSR_16384                                                 ((uint16_t) 0x0007 << 2)

    /*! @brief Defines clock register PWR mask */
    #define CLOCK_PWR_MASK                                                  ((uint16_t) 0x0003)
    /*! @brief Defines clock register PWR VLP */
    #define CLOCK_PWR_VLP                                                   ((uint16_t) 0x0000 << 0)
    /*! @brief Defines clock register PWR LP */
    #define CLOCK_PWR_LP                                                    ((uint16_t) 0x0001 << 0)
    /*! @brief Defines clock register PWR HR */
    #define CLOCK_PWR_HR                                                    ((uint16_t) 0x0002 << 0)     /* DEFAULT */



/* Register 0x04 (GAIN1) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |  RESERVED0 |             PGAGAIN3[2:0]            |  RESERVED1 |             PGAGAIN2[2:0]            |  RESERVED2 |             PGAGAIN1[2:0]            |  RESERVED3 |             PGAGAIN0[2:0]            |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Defines GAIN1 register Address */
    #define GAIN1_ADDRESS                                                   ((uint8_t)  0x04)
    /*! @brief Defines GAIN1 register Defaults */
    #define GAIN1_DEFAULT                                                   ((uint16_t) 0x0000)

    /*! @brief Defines GAIN1 register reserved0 mask */
    #define GAIN1_RESERVED0_MASK                                            ((uint16_t) 0x8000)

    /*! @brief Defines GAIN1 register PGAGAIB3 mask */
    #define GAIN1_PGAGAIN3_MASK                                             ((uint16_t) 0x7000)
    /*! @brief Defines GAIN1 register PGAGAIB3 1 */
    #define GAIN1_PGAGAIN3_1                                                ((uint16_t) 0x0000 << 12)    /* DEFAULT */ 
    /*! @brief Defines GAIN1 register PGAGAIB3 2 */
    #define GAIN1_PGAGAIN3_2                                                ((uint16_t) 0x0001 << 12)
    /*! @brief Defines GAIN1 register PGAGAIB3 4 */
    #define GAIN1_PGAGAIN3_4                                                ((uint16_t) 0x0002 << 12)
    /*! @brief Defines GAIN1 register PGAGAIB3 8 */
    #define GAIN1_PGAGAIN3_8                                                ((uint16_t) 0x0003 << 12)
    /*! @brief Defines GAIN1 register PGAGAIB3 16 */
    #define GAIN1_PGAGAIN3_16                                               ((uint16_t) 0x0004 << 12)
    /*! @brief Defines GAIN1 register PGAGAIB3 32 */
    #define GAIN1_PGAGAIN3_32                                               ((uint16_t) 0x0005 << 12)
    /*! @brief Defines GAIN1 register PGAGAIB3 64 */
    #define GAIN1_PGAGAIN3_64                                               ((uint16_t) 0x0006 << 12)
    /*! @brief Defines GAIN1 register PGAGAIB3 mas128k */
    #define GAIN1_PGAGAIN3_128                                              ((uint16_t) 0x0007 << 12)

    /*! @brief Defines GAIN1 register reserved1 mask */
    #define GAIN1_RESERVED1_MASK                                            ((uint16_t) 0x0800)

    /*! @brief Defines GAIN1 register PGAGAIB2 mask */
    #define GAIN1_PGAGAIN2_MASK                                             ((uint16_t) 0x0700)
    /*! @brief Defines GAIN1 register PGAGAIB2 1 */
    #define GAIN1_PGAGAIN2_1                                                ((uint16_t) 0x0000 << 8)    /* DEFAULT */ 
    /*! @brief Defines GAIN1 register PGAGAIB2 2 */
    #define GAIN1_PGAGAIN2_2                                                ((uint16_t) 0x0001 << 8)
    /*! @brief Defines GAIN1 register PGAGAIB2 4 */
    #define GAIN1_PGAGAIN2_4                                                ((uint16_t) 0x0002 << 8)
    /*! @brief Defines GAIN1 register PGAGAIB2 8 */
    #define GAIN1_PGAGAIN2_8                                                ((uint16_t) 0x0003 << 8)
    /*! @brief Defines GAIN1 register PGAGAIB2 16 */
    #define GAIN1_PGAGAIN2_16                                               ((uint16_t) 0x0004 << 8)
    /*! @brief Defines GAIN1 register PGAGAIB2 32 */
    #define GAIN1_PGAGAIN2_32                                               ((uint16_t) 0x0005 << 8)
    /*! @brief Defines GAIN1 register PGAGAIB2 64 */
    #define GAIN1_PGAGAIN2_64                                               ((uint16_t) 0x0006 << 8)
    /*! @brief Defines GAIN1 register PGAGAIB2 128 */
    #define GAIN1_PGAGAIN2_128                                              ((uint16_t) 0x0007 << 8)

    /*! @brief Defines GAIN1 register reserved2 mask */
    #define GAIN1_RESERVED2_MASK                                            ((uint16_t) 0x0080)

    /*! @brief Defines GAIN1 register PGAGAIB1 mask */
    #define GAIN1_PGAGAIN1_MASK                                             ((uint16_t) 0x0070)
    /*! @brief Defines GAIN1 register PGAGAIB1 1 */
    #define GAIN1_PGAGAIN1_1                                                ((uint16_t) 0x0000 << 4)    /* DEFAULT */ 
    /*! @brief Defines GAIN1 register PGAGAIB1 2 */
    #define GAIN1_PGAGAIN1_2                                                ((uint16_t) 0x0001 << 4)
    /*! @brief Defines GAIN1 register PGAGAIB1 4 */
    #define GAIN1_PGAGAIN1_4                                                ((uint16_t) 0x0002 << 4)
    /*! @brief Defines GAIN1 register PGAGAIB1 8 */
    #define GAIN1_PGAGAIN1_8                                                ((uint16_t) 0x0003 << 4)
    /*! @brief Defines GAIN1 register PGAGAIB1 16 */
    #define GAIN1_PGAGAIN1_16                                               ((uint16_t) 0x0004 << 4)
    /*! @brief Defines GAIN1 register PGAGAIB1 32 */
    #define GAIN1_PGAGAIN1_32                                               ((uint16_t) 0x0005 << 4)
    /*! @brief Defines GAIN1 register PGAGAIB1 64 */
    #define GAIN1_PGAGAIN1_64                                               ((uint16_t) 0x0006 << 4)
    /*! @brief Defines GAIN1 register PGAGAIB1 128 */
    #define GAIN1_PGAGAIN1_128                                              ((uint16_t) 0x0007 << 4)

    /*! @brief Defines GAIN1 register reserved3 mask */
    #define GAIN1_RESERVED3_MASK                                            ((uint16_t) 0x0008)

    /*! @brief Defines GAIN1 register PGAGAIB0 mask */
    #define GAIN1_PGAGAIN0_MASK                                             ((uint16_t) 0x0007)
    /*! @brief Defines GAIN1 register PGAGAIB0 1 */
    #define GAIN1_PGAGAIN0_1                                                ((uint16_t) 0x0000 << 0)    /* DEFAULT */ 
    /*! @brief Defines GAIN1 register PGAGAIB0 2 */
    #define GAIN1_PGAGAIN0_2                                                ((uint16_t) 0x0001 << 0)
    /*! @brief Defines GAIN1 register PGAGAIB0 4 */
    #define GAIN1_PGAGAIN0_4                                                ((uint16_t) 0x0002 << 0)
    /*! @brief Defines GAIN1 register PGAGAIB0 8 */
    #define GAIN1_PGAGAIN0_8                                                ((uint16_t) 0x0003 << 0)
    /*! @brief Defines GAIN1 register PGAGAIB0 16 */
    #define GAIN1_PGAGAIN0_16                                               ((uint16_t) 0x0004 << 0)
    /*! @brief Defines GAIN1 register PGAGAIB0 32 */
    #define GAIN1_PGAGAIN0_32                                               ((uint16_t) 0x0005 << 0)
    /*! @brief Defines GAIN1 register PGAGAIB0 64 */
    #define GAIN1_PGAGAIN0_64                                               ((uint16_t) 0x0006 << 0)
    /*! @brief Defines GAIN1 register PGAGAIB0 128 */
    #define GAIN1_PGAGAIN0_128                                              ((uint16_t) 0x0007 << 0)


/* Register 0x05 (GAIN2) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |  RESERVED0 |             PGAGAIN7[2:0]            |  RESERVED1 |             PGAGAIN6[2:0]            |  RESERVED2 |             PGAGAIN5[2:0]            |  RESERVED3 |             PGAGAIN4[2:0]            |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * NOTE 1: This register is RESERVED on the ADS131M04. Only write 0x0000 to this register.
 */

    /*! @brief Defines GAIN2 register Address */
    #define GAIN2_ADDRESS                                                   ((uint8_t)  0x05)
    /*! @brief Defines GAIN2 register Default */
    #define GAIN2_DEFAULT                                                   ((uint16_t) 0x0000)


    /*! @brief Defines GAIN2 register reserved0 mask */
    #define GAIN2_RESERVED0_MASK                                            ((uint16_t) 0x8000)

    /*! @brief Defines GAIN2 register PGAGAIN7 mask */
    #define GAIN2_PGAGAIN7_MASK                                             ((uint16_t) 0x7000)
    /*! @brief Defines GAIN2 register PGAGAIN7 1 */
    #define GAIN2_PGAGAIN7_1                                                ((uint16_t) 0x0000 << 12)   /* DEFAULT */ 
    /*! @brief Defines GAIN2 register PGAGAIN7 2 */
    #define GAIN2_PGAGAIN7_2                                                ((uint16_t) 0x0001 << 12)
    /*! @brief Defines GAIN2 register PGAGAIN7 4 */
    #define GAIN2_PGAGAIN7_4                                                ((uint16_t) 0x0002 << 12)
    /*! @brief Defines GAIN2 register PGAGAIN7 8 */
    #define GAIN2_PGAGAIN7_8                                                ((uint16_t) 0x0003 << 12)
    /*! @brief Defines GAIN2 register PGAGAIN7 16 */
    #define GAIN2_PGAGAIN7_16                                               ((uint16_t) 0x0004 << 12)
    /*! @brief Defines GAIN2 register PGAGAIN7 32 */
    #define GAIN2_PGAGAIN7_32                                               ((uint16_t) 0x0005 << 12)
    /*! @brief Defines GAIN2 register PGAGAIN7 64 */
    #define GAIN2_PGAGAIN7_64                                               ((uint16_t) 0x0006 << 12)
    /*! @brief Defines GAIN2 register PGAGAIN7 128 */
    #define GAIN2_PGAGAIN7_128                                              ((uint16_t) 0x0007 << 12)

    /*! @brief Defines GAIN2 register reserved1 mask */
    #define GAIN2_RESERVED1_MASK                                            ((uint16_t) 0x0800)

    /*! @brief Defines GAIN2 register PGAGAIN6 mask */
    #define GAIN2_PGAGAIN6_MASK                                             ((uint16_t) 0x0700)
    /*! @brief Defines GAIN2 register PGAGAIN6 1 */
    #define GAIN2_PGAGAIN6_1                                                ((uint16_t) 0x0000 << 8)    /* DEFAULT */ 
    /*! @brief Defines GAIN2 register PGAGAIN6 2 */
    #define GAIN2_PGAGAIN6_2                                                ((uint16_t) 0x0001 << 8)
    /*! @brief Defines GAIN2 register PGAGAIN6 4 */
    #define GAIN2_PGAGAIN6_4                                                ((uint16_t) 0x0002 << 8)
    /*! @brief Defines GAIN2 register PGAGAIN6 8 */
    #define GAIN2_PGAGAIN6_8                                                ((uint16_t) 0x0003 << 8)
    /*! @brief Defines GAIN2 register PGAGAIN6 16 */
    #define GAIN2_PGAGAIN6_16                                               ((uint16_t) 0x0004 << 8)
    /*! @brief Defines GAIN2 register PGAGAIN6 32 */
    #define GAIN2_PGAGAIN6_32                                               ((uint16_t) 0x0005 << 8)
    /*! @brief Defines GAIN2 register PGAGAIN6 64 */
    #define GAIN2_PGAGAIN6_64                                               ((uint16_t) 0x0006 << 8)
    /*! @brief Defines GAIN2 register PGAGAIN6 128 */
    #define GAIN2_PGAGAIN6_128                                              ((uint16_t) 0x0007 << 8)

    /*! @brief Defines GAIN2 register reserved2 mask */
    #define GAIN2_RESERVED2_MASK                                            ((uint16_t) 0x0080)

    /*! @brief Defines GAIN2 register PGAGAIN5 mask */
    #define GAIN2_PGAGAIN5_MASK                                             ((uint16_t) 0x0070)
    /*! @brief Defines GAIN2 register PGAGAIN5 1 */
    #define GAIN2_PGAGAIN5_1                                                ((uint16_t) 0x0000 << 4)    /* DEFAULT */ 
    /*! @brief Defines GAIN2 register PGAGAIN5 2 */
    #define GAIN2_PGAGAIN5_2                                                ((uint16_t) 0x0001 << 4)
    /*! @brief Defines GAIN2 register PGAGAIN5 4 */
    #define GAIN2_PGAGAIN5_4                                                ((uint16_t) 0x0002 << 4)
    /*! @brief Defines GAIN2 register PGAGAIN5 8 */
    #define GAIN2_PGAGAIN5_8                                                ((uint16_t) 0x0003 << 4)
    /*! @brief Defines GAIN2 register PGAGAIN5 16 */
    #define GAIN2_PGAGAIN5_16                                               ((uint16_t) 0x0004 << 4)
    /*! @brief Defines GAIN2 register PGAGAIN5 32 */
    #define GAIN2_PGAGAIN5_32                                               ((uint16_t) 0x0005 << 4)
    /*! @brief Defines GAIN2 register PGAGAIN5 64 */
    #define GAIN2_PGAGAIN5_64                                               ((uint16_t) 0x0006 << 4)
    /*! @brief Defines GAIN2 register PGAGAIN5 128 */
    #define GAIN2_PGAGAIN5_128                                              ((uint16_t) 0x0007 << 4)

    /*! @brief Defines GAIN2 register reserved3 mask */
    #define GAIN2_RESERVED3_MASK                                            ((uint16_t) 0x0008)

    /*! @brief Defines GAIN2 register PGAGAIN4 mask */
    #define GAIN2_PGAGAIN4_MASK                                             ((uint16_t) 0x0007)
    /*! @brief Defines GAIN2 register PGAGAIN4 1 */
    #define GAIN2_PGAGAIN4_1                                                ((uint16_t) 0x0000 << 0)    /* DEFAULT */ 
    /*! @brief Defines GAIN2 register PGAGAIN4 2 */
    #define GAIN2_PGAGAIN4_2                                                ((uint16_t) 0x0001 << 0)
    /*! @brief Defines GAIN2 register PGAGAIN4 4 */
    #define GAIN2_PGAGAIN4_4                                                ((uint16_t) 0x0002 << 0)
    /*! @brief Defines GAIN2 register PGAGAIN4 8 */
    #define GAIN2_PGAGAIN4_8                                                ((uint16_t) 0x0003 << 0)
    /*! @brief Defines GAIN2 register PGAGAIN4 16 */
    #define GAIN2_PGAGAIN4_16                                               ((uint16_t) 0x0004 << 0)
    /*! @brief Defines GAIN2 register PGAGAIN4 32 */
    #define GAIN2_PGAGAIN4_32                                               ((uint16_t) 0x0005 << 0)
    /*! @brief Defines GAIN2 register PGAGAIN4 64 */
    #define GAIN2_PGAGAIN4_64                                               ((uint16_t) 0x0006 << 0)
    /*! @brief Defines GAIN2 register PGAGAIN4 128 */
    #define GAIN2_PGAGAIN4_128                                              ((uint16_t) 0x0007 << 0)




/* Register 0x06 (CFG) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |            RESERVED0[2:0]            |                    GC_DLY[3:0]                    |    GC_EN   |  CD_ALLCH  |              CD_NUM[2:0]             |              CD_LEN[2:0]             |    CD_EN   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Defines CFG register Address */
    #define CFG_ADDRESS                                                     ((uint8_t)  0x06)
    /*! @brief Defines CFG register defaults */
    #define CFG_DEFAULT                                                     ((uint16_t) 0x0600)

    /*! @brief Defines CFG register reserved mask */
    #define CFG_RESERVED0_MASK                                              ((uint16_t) 0xE000)

    /*! @brief Defines CFG register GC DLY mask */
    #define CFG_GC_DLY_MASK                                                 ((uint16_t) 0x1E00)
    /*! @brief Defines CFG register GC DLY 2 */
    #define CFG_GC_DLY_2                                                    ((uint16_t) 0x0000 << 9)
    /*! @brief Defines CFG register GC DLY 4 */
    #define CFG_GC_DLY_4                                                    ((uint16_t) 0x0001 << 9)
    /*! @brief Defines CFG register GC DLY 8 */
    #define CFG_GC_DLY_8                                                    ((uint16_t) 0x0002 << 9)
    /*! @brief Defines CFG register GC DLY 16 */
    #define CFG_GC_DLY_16                                                   ((uint16_t) 0x0003 << 9)    /* DEFAULT */ 
    /*! @brief Defines CFG register GC DLY 32 */
    #define CFG_GC_DLY_32                                                   ((uint16_t) 0x0004 << 9)
    /*! @brief Defines CFG register GC DLY 64 */
    #define CFG_GC_DLY_64                                                   ((uint16_t) 0x0005 << 9)
    /*! @brief Defines CFG register GC DLY 128 */
    #define CFG_GC_DLY_128                                                  ((uint16_t) 0x0006 << 9)
    /*! @brief Defines CFG register GC DLY 256 */
    #define CFG_GC_DLY_256                                                  ((uint16_t) 0x0007 << 9)
    /*! @brief Defines CFG register GC DLY 512 */
    #define CFG_GC_DLY_512                                                  ((uint16_t) 0x0008 << 9)
    /*! @brief Defines CFG register GC DLY 1024 */
    #define CFG_GC_DLY_1024                                                 ((uint16_t) 0x0009 << 9)
    /*! @brief Defines CFG register GC DLY 2048 */
    #define CFG_GC_DLY_2048                                                 ((uint16_t) 0x000A << 9)
    /*! @brief Defines CFG register GC DLY 4096 */
    #define CFG_GC_DLY_4096                                                 ((uint16_t) 0x000B << 9)
    /*! @brief Defines CFG register GC DLY 8192 */
    #define CFG_GC_DLY_8192                                                 ((uint16_t) 0x000C << 9)
    /*! @brief Defines CFG register GC DLY 16484 */
    #define CFG_GC_DLY_16484                                                ((uint16_t) 0x000D << 9)
    /*! @brief Defines CFG register GC DLY 32768 */
    #define CFG_GC_DLY_32768                                                ((uint16_t) 0x000E << 9)
    /*! @brief Defines CFG register GC DLY 65536 */
    #define CFG_GC_DLY_65536                                                ((uint16_t) 0x000F << 9)

    /*! @brief Defines CFG register GC EN mask */
    #define CFG_GC_EN_MASK                                                  ((uint16_t) 0x0100)
    /*! @brief Defines CFG register GC EN disabled */
    #define CFG_GC_EN_DISABLED                                              ((uint16_t) 0x0000 << 8)    /* DEFAULT */ 
    /*! @brief Defines CFG register GC EN enabled */
    #define CFG_GC_EN_ENABLED                                               ((uint16_t) 0x0001 << 8)

    /*! @brief Defines CFG register CD ALLCH mask */
    #define CFG_CD_ALLCH_MASK                                               ((uint16_t) 0x0080)
    /*! @brief Defines CFG register CD ALLCH any */
    #define CFG_CD_ALLCH_ANY_CHANNEL                                        ((uint16_t) 0x0000 << 7)    /* DEFAULT */ 
    /*! @brief Defines CFG register CD ALLCH all */
    #define CFG_CD_ALLCH_ALL_CHANNELS                                       ((uint16_t) 0x0001 << 7)

    /*! @brief Defines CFG register CD NUM mask */
    #define CFG_CD_NUM_MASK                                                 ((uint16_t) 0x0070)
    /*! @brief Defines CFG register CD NUM 1 */
    #define CFG_CD_NUM_1                                                    ((uint16_t) 0x0000 << 4)    /* DEFAULT */ 
    /*! @brief Defines CFG register CD NUM 2 */
    #define CFG_CD_NUM_2                                                    ((uint16_t) 0x0001 << 4)
    /*! @brief Defines CFG register CD NUM 4 */
    #define CFG_CD_NUM_4                                                    ((uint16_t) 0x0002 << 4)
    /*! @brief Defines CFG register CD NUM 8 */
    #define CFG_CD_NUM_8                                                    ((uint16_t) 0x0003 << 4)
    /*! @brief Defines CFG register CD NUM 16 */
    #define CFG_CD_NUM_16                                                   ((uint16_t) 0x0004 << 4)
    /*! @brief Defines CFG register CD NUM 32 */
    #define CFG_CD_NUM_32                                                   ((uint16_t) 0x0005 << 4)
    /*! @brief Defines CFG register CD NUM 64 */
    #define CFG_CD_NUM_64                                                   ((uint16_t) 0x0006 << 4)
    /*! @brief Defines CFG register CD NUM 128 */
    #define CFG_CD_NUM_128                                                  ((uint16_t) 0x0007 << 4)

    /*! @brief Defines CFG register CD LEn mask */
    #define CFG_CD_LEN_MASK                                                 ((uint16_t) 0x000E)
    /*! @brief Defines CFG register CD LEn 128 */
    #define CFG_CD_LEN_128                                                  ((uint16_t) 0x0000 << 1)    /* DEFAULT */ 
    /*! @brief Defines CFG register CD LEn 256 */
    #define CFG_CD_LEN_256                                                  ((uint16_t) 0x0001 << 1)
    /*! @brief Defines CFG register CD LEn 512 */
    #define CFG_CD_LEN_512                                                  ((uint16_t) 0x0002 << 1)
    /*! @brief Defines CFG register CD LEn 768 */
    #define CFG_CD_LEN_768                                                  ((uint16_t) 0x0003 << 1)
    /*! @brief Defines CFG register CD LEn 1280 */
    #define CFG_CD_LEN_1280                                                 ((uint16_t) 0x0004 << 1)
    /*! @brief Defines CFG register CD LEn 1790 */
    #define CFG_CD_LEN_1792                                                 ((uint16_t) 0x0005 << 1)
    /*! @brief Defines CFG register CD LEn 2560 */
    #define CFG_CD_LEN_2560                                                 ((uint16_t) 0x0006 << 1)
    /*! @brief Defines CFG register CD LEn 3584 */
    #define CFG_CD_LEN_3584                                                 ((uint16_t) 0x0007 << 1)

    /*! @brief Defines CFG register CD EN mask */
    #define CFG_CD_EN_MASK                                                  ((uint16_t) 0x0001)
    /*! @brief Defines CFG register CD EN disabled */
    #define CFG_CD_EN_DISABLED                                              ((uint16_t) 0x0000 << 0)    /* DEFAULT */ 
    /*! @brief Defines CFG register CD EN enabled */
    #define CFG_CD_EN_ENABLED                                               ((uint16_t) 0x0001 << 0)



/* Register 0x07 (THRSHLD_MSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                                                                                CD_TH_MSB[15:0]                                                                                                |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Defines THRSHLD_MSB register address */
    #define THRSHLD_MSB_ADDRESS                                             ((uint8_t)  0x07)
    /*! @brief Defines THRSHLD_MSB register default */
    #define THRSHLD_MSB_DEFAULT                                             ((uint16_t) 0x0000)

    /*! @brief Defines THRSHLD_MSB register mask */
    #define THRSHLD_MSB_CD_TH_MSB_MASK                                      ((uint16_t) 0xFFFF)



/* Register 0x08 (THRSHLD_LSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                             CD_TH_LSB[7:0]                                            |                       RESERVED[7:4]               |                    DCBLOCK[3:0]                   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Defines THRSHLD_LSB register address */
    #define THRSHLD_LSB_ADDRESS                                             ((uint8_t)  0x08)
    /*! @brief Defines THRSHLD_LSB register default */
    #define THRSHLD_LSB_DEFAULT                                             ((uint16_t) 0x0000)

    /*! @brief Defines THRSHLD_LSB register mask */
    #define THRSHLD_LSB_CD_TH_LSB_MASK                                      ((uint16_t) 0xFF00)

    /*! @brief Defines THRSHLD_LSB register reserved mask */
    #define THRSHLD_LSB_RESERVED0_MASK                                      ((uint16_t) 0x00F0)

    /*! @brief Defines THRSHLD_LSB register DCBLOCk mask */
    #define THRSHLD_LSB_DCBLOCK_MASK                                        ((uint16_t) 0x000F)
    /*! @brief Defines THRSHLD_LSB register DCBLOCk disabled */
    #define THRSHLD_LSB_DCBLOCK_DISABLED                                    ((uint16_t) 0x0000 << 0)  // DC Block filter disabled
    /*! @brief Defines THRSHLD_LSB register DCBLOCk 181P0 */
    #define THRSHLD_LSB_DCBLOCK_181P0Hz                                     ((uint16_t) 0x0001 << 0)  // 181 Hz fc, 11.5 dB pass-band at 50 Hz, 10.1 dB pass-band at 60 Hz, 99% settled at 17 samples, fully settled at 88 samples
    /*! @brief Defines THRSHLD_LSB register DCBLOCk 84P8 */
    #define THRSHLD_LSB_DCBLOCK_84p8Hz                                      ((uint16_t) 0x0002 << 0)  // 84.8 Hz fc, 5.89 dB pass-band at 50 Hz, 4.77 dB pass-band at 60 Hz, 99% settled at 36 samples, fully settled at 187 samples
    /*! @brief Defines THRSHLD_LSB register DCBLOCk 41P1 */
    #define THRSHLD_LSB_DCBLOCK_41p1Hz                                      ((uint16_t) 0x0003 << 0)  // 41.1 Hz fc, 2.24 dB pass-band at 50 Hz, 1.67 dB pass-band at 60 Hz, 99% settled at 72 samples, fully settled at 387 samples
    /*! @brief Defines THRSHLD_LSB register DCBLOCk 20P2 */
    #define THRSHLD_LSB_DCBLOCK_20p2Hz                                      ((uint16_t) 0x0004 << 0)  // 20.2 Hz fc, 0.657 mdB pass-band at 50 Hz, 0.466dB pass-band at 60 Hz, 99% settled at 146 samples, fully settled at 786 samples
    /*! @brief Defines THRSHLD_LSB register DCBLOCk 10P0 */
    #define THRSHLD_LSB_DCBLOCK_10p0Hz                                      ((uint16_t) 0x0005 << 0)  // 10.0 Hz fc, 171 mdB pass-band at 50 Hz, 0.119dB pass-band at 60 Hz, 99% settled at 293 samples, fully settled at 1585 samples
    /*! @brief Defines THRSHLD_LSB register DCBLOCk 4P99 */
    #define THRSHLD_LSB_DCBLOCK_4p99Hz                                      ((uint16_t) 0x0006 << 0)  // 4.99 Hz fc, 43.1 mdB pass-band at 50 Hz, 29.9mdB pass-band at 60 Hz, 99% settled at 588 samples, fully settled at 3182 samples
    /*! @brief Defines THRSHLD_LSB register DCBLOCk 2P49 */
    #define THRSHLD_LSB_DCBLOCK_2p49Hz                                      ((uint16_t) 0x0007 << 0)  // 2.49 Hz fc, 10.8 mdB pass-band at 50 Hz, 7.47mdB pass-band at 60 Hz, 99% settled at 1178 samples, fully settled at 6376 samples
    /*! @brief Defines THRSHLD_LSB register DCBLOCk 1P24 */
    #define THRSHLD_LSB_DCBLOCK_1p24Hz                                      ((uint16_t) 0x0008 << 0)  // 1.24 Hz fc, 2.69 mdB pass-band at 50 Hz, 1.87mdB pass-band at 60 Hz, 99% settled at 2357 samples, fully settled at 12764 samples
    /*! @brief Defines THRSHLD_LSB register DCBLOCk 622m */
    #define THRSHLD_LSB_DCBLOCK_622mHz                                      ((uint16_t) 0x0009 << 0)  // 0.622 Hz fc, 671 udB pass-band at 50 Hz, 466udB pass-band at 60 Hz, 99% settled at 4714 samples, fully settled at 25540 samples
    /*! @brief Defines THRSHLD_LSB register DCBLOCk 311m */
    #define THRSHLD_LSB_DCBLOCK_311mHz                                      ((uint16_t) 0x000A << 0)  // 0.311 Hz fc, 168 udB pass-band at 50 Hz, 116 udB pass-band at 60 Hz, 99% settled at 9430 samples, fully settled at 51093 samples
    /*! @brief Defines THRSHLD_LSB register DCBLOCk 155m */
    #define THRSHLD_LSB_DCBLOCK_155mHz                                      ((uint16_t) 0x000B << 0)  // 0.155 Hz fc, 41.9 udB pass-band at 50 Hz, 29.1 udB pass-band at 60 Hz, 99% settled at 18861 samples, fully settled at 102202 samples
    /*! @brief Defines THRSHLD_LSB register DCBLOCk 77P7m */
    #define THRSHLD_LSB_DCBLOCK_77p7mHz                                     ((uint16_t) 0x000C << 0)  // 77.7 mHz fc, 10.5 udB pass-band at 50 Hz, 7.27 udB pass-band at 60 Hz, 99% settled at 37724 samples, fully settled at 204447 samples
    /*! @brief Defines THRSHLD_LSB register DCBLOCk 38p9m */
    #define THRSHLD_LSB_DCBLOCK_38p9mHz                                     ((uint16_t) 0x000D << 0)  // 38.9 mHz fc, 2.63 udB pass-band at 50 Hz, 1.82 udB pass-band at 60 Hz, 99% settled at 75450 samples, fully settled at 409156 samples
    /*! @brief Defines THRSHLD_LSB register DCBLOCk 19P4m */
    #define THRSHLD_LSB_DCBLOCK_19p4mHz                                     ((uint16_t) 0x000F << 0)  // 19.4 mHz fc, 655 ndB pass-band at 50 Hz, 455 ndB pass-band at 60 Hz, 99% settled at 150901 samples, fully settled at 820188 samples
    /*! @brief Defines THRSHLD_LSB register DCBLOCk 9P7m */
    #define THRSHLD_LSB_DCBLOCK_9p70mHz                                     ((uint16_t) 0x0007 << 0)  // 9.70 mHz fc, 164 ndB pass-band at 50 Hz, 114 ndB pass-band at 60 Hz, 99% settled at 301803 samples, fully settled at 1627730 samples



/* Register 0x09 (CH0_CFG) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                                           PHASE0[9:0]                                                           |                   RESERVED0[3:0]                  |        MUX0[1:0]        |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH0 CFG register Address*/
    #define CH0_CFG_ADDRESS                                                 ((uint8_t)  0x09)
    /*! @brief Define CH0 CFG register deafult*/
    #define CH0_CFG_DEFAULT                                                 ((uint16_t) 0x0000)

    /*! @brief Define CH0 CFG register Phase0 mask*/
    #define CH0_CFG_PHASE0_MASK                                             ((uint16_t) 0xFFC0)
    /*! @brief Define CH0 CFG register Phase0 shift*/
    #define PHASEn_SHIFT                                                    (6)
    /*! @brief Define CH0 CFG register Phase0 register value*/
    #define SET_PHASE_REGISTER_VALUE(phase_shift)                           ((phase_shift )<<PHASEn_SHIFT)

    /*! @brief Define CH0 CFG register reserved mask*/
    #define CH0_CFG_RESERVED0_MASK                                          ((uint16_t) 0x003C)

    /*! @brief Define CH0 CFG register MUX0 mask*/
    #define CH0_CFG_MUX0_MASK                                               ((uint16_t) 0x0003)
    /*! @brief Define CH0 CFG register MUX0 AIN0P_AIN0N*/
    #define CH0_CFG_MUX0_AIN0P_AIN0N                                        ((uint16_t) 0x0000 << 0)    /* DEFAULT */ 
    /*! @brief Define CH0 CFG register MUX0 ADC input short*/
    #define CH0_CFG_MUX0_ADC_INPUT_SHORT                                    ((uint16_t) 0x0001 << 0)
    /*! @brief Define CH0 CFG register MUX0 DC DIAGNOSTIC*/
    #define CH0_CFG_MUX0_DC_DIAGNOSTIC                                      ((uint16_t) 0x0002 << 0)
    /*! @brief Define CH0 CFG register MUX0 AC DIAGNOSTIC*/
    #define CH0_CFG_MUX0_AC_DIAGNOSTIC                                      ((uint16_t) 0x0003 << 0)



/* Register 0x0A (CH0_OCAL_MSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                                                                                OCAL0_MSB[15:0]                                                                                                |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH0 OCAL MSB register Address*/
    #define CH0_OCAL_MSB_ADDRESS                                            ((uint8_t)  0x0A)
    /*! @brief Define CH0 OCAL MSB register default*/
    #define CH0_OCAL_MSB_DEFAULT                                            ((uint16_t) 0x0000)

    /*! @brief Define CH0 OCAL MSB register mask*/
    #define CH0_OCAL_MSB_OCAL0_MSB_MASK                                     ((uint16_t) 0xFFFF)



/* Register 0x0B (CH0_OCAL_LSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                             OCAL0_LSB[7:0]                                            |                                             RESERVED0[7:0]                                            |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH0 OCAL LSB register Address*/
    #define CH0_OCAL_LSB_ADDRESS                                            ((uint8_t)  0x0B)
    /*! @brief Define CH0 OCAL LSB register default*/
    #define CH0_OCAL_LSB_DEFAULT                                            ((uint16_t) 0x0000)

    /*! @brief Define CH0 OCAL LSB register mask*/
    #define CH0_OCAL_LSB_OCAL0_LSB_MASK                                     ((uint16_t) 0xFF00)

    /*! @brief Define CH0 OCAL LSB register reserved mask*/
    #define CH0_OCAL_LSB_RESERVED0_MASK                                     ((uint16_t) 0x00FF)



/* Register 0x0C (CH0_GCAL_MSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                                                                                GCAL0_MSB[15:0]                                                                                                |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH0 GCAL MSB register Address*/
    #define CH0_GCAL_MSB_ADDRESS                                            ((uint8_t)  0x0C)
    /*! @brief Define CH0 GCAL MSB register default*/
    #define CH0_GCAL_MSB_DEFAULT                                            ((uint16_t) 0x8000)

    /*! @brief Define CH0 GCAL MSB register mask*/
    #define CH0_GCAL_MSB_GCAL0_MSB_MASK                                     ((uint16_t) 0xFFFF)



/* Register 0x0D (CH0_GCAL_LSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                             GCAL0_LSB[7:0]                                            |                                             RESERVED0[7:0]                                            |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH0 GCAL LSB register Address*/
    #define CH0_GCAL_LSB_ADDRESS                                            ((uint8_t)  0x0D)
    /*! @brief Define CH0 GCAL LSB register default*/
    #define CH0_GCAL_LSB_DEFAULT                                            ((uint16_t) 0x0000)

    /*! @brief Define CH0 GCAL LSB register mask*/
    #define CH0_GCAL_LSB_GCAL0_LSB_MASK                                     ((uint16_t) 0xFF00)

    /*! @brief Define CH0 GCAL LSB register reserved mask*/
    #define CH0_GCAL_LSB_RESERVED0_MASK                                     ((uint16_t) 0x00FF)



/* Register 0x0E (CH1_CFG) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                                           PHASE1[9:0]                                                           |                   RESERVED0[3:0]                  |        MUX1[1:0]        |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH1 CFG register Address*/
    #define CH1_CFG_ADDRESS                                                 ((uint8_t)  0x0E)
    /*! @brief Define CH1 CFG register Default*/
    #define CH1_CFG_DEFAULT                                                 ((uint16_t) 0x0000)

    /*! @brief Define CH1 CFG register phase1 mask*/
    #define CH1_CFG_PHASE1_MASK                                             ((uint16_t) 0xFFC0)

    /*! @brief Define CH1 CFG register reserved mask*/
    #define CH1_CFG_RESERVED0_MASK                                          ((uint16_t) 0x003C)

    /*! @brief Define CH1 CFG register MUX1 mask*/
    #define CH1_CFG_MUX1_MASK                                               ((uint16_t) 0x0003)
    /*! @brief Define CH1 CFG register MUX1 AIN1P_AIN1N*/
    #define CH1_CFG_MUX1_AIN1P_AIN1N                                        ((uint16_t) 0x0000 << 0)    /* DEFAULT */ 
    /*! @brief Define CH1 CFG register MUX1 ADC input short*/
    #define CH1_CFG_MUX1_ADC_INPUT_SHORT                                    ((uint16_t) 0x0001 << 0)
    /*! @brief Define CH1 CFG register MUX1 dc diagnostic*/
    #define CH1_CFG_MUX1_DC_DIAGNOSTIC                                      ((uint16_t) 0x0002 << 0)
    /*! @brief Define CH1 CFG register MUX1 ac diagnostic*/
    #define CH1_CFG_MUX1_AC_DIAGNOSTIC                                      ((uint16_t) 0x0003 << 0)



/* Register 0x0F (CH1_OCAL_MSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                                                                                OCAL1_MSB[15:0]                                                                                                |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH1 OCAL MSB register Address*/
    #define CH1_OCAL_MSB_ADDRESS                                            ((uint8_t)  0x0F)
    /*! @brief Define CH1 OCAL MSB register default*/
    #define CH1_OCAL_MSB_DEFAULT                                            ((uint16_t) 0x0000)

    /*! @brief Define CH1 OCAL MSB register mask*/
    #define CH1_OCAL_MSB_OCAL1_MSB_MASK                                     ((uint16_t) 0xFFFF)



/* Register 0x10 (CH1_OCAL_LSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                             OCAL1_LSB[7:0]                                            |                                             RESERVED0[7:0]                                            |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH1 OCAL LSB register Address*/
    #define CH1_OCAL_LSB_ADDRESS                                            ((uint8_t)  0x10)
    /*! @brief Define CH1 OCAL LSB register Defaullt*/
    #define CH1_OCAL_LSB_DEFAULT                                            ((uint16_t) 0x0000)

    /*! @brief Define CH1 OCAL LSB register mask*/
    #define CH1_OCAL_LSB_OCAL1_LSB_MASK                                     ((uint16_t) 0xFF00)

    /*! @brief Define CH1 OCAL LSB register reserved mask*/
    #define CH1_OCAL_LSB_RESERVED0_MASK                                     ((uint16_t) 0x00FF)



/* Register 0x11 (CH1_GCAL_MSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                                                                                GCAL1_MSB[15:0]                                                                                                |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH1 GCAL MSB register Address*/
    #define CH1_GCAL_MSB_ADDRESS                                            ((uint8_t)  0x11)
    /*! @brief Define CH1 GCAL MSB register default*/
    #define CH1_GCAL_MSB_DEFAULT                                            ((uint16_t) 0x8000)

    /*! @brief Define CH1 GCAL MSB register mask*/
    #define CH1_GCAL_MSB_GCAL1_MSB_MASK                                     ((uint16_t) 0xFFFF)



/* Register 0x12 (CH1_GCAL_LSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                             GCAL1_LSB[7:0]                                            |                                             RESERVED0[7:0]                                            |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH1 GCAL LSB register Address*/
    #define CH1_GCAL_LSB_ADDRESS                                            ((uint8_t)  0x12)
    /*! @brief Define CH1 GCAL LSB register default*/
    #define CH1_GCAL_LSB_DEFAULT                                            ((uint16_t) 0x0000)

    /*! @brief Define CH1 GCAL LSB register mask*/
    #define CH1_GCAL_LSB_GCAL1_LSB_MASK                                     ((uint16_t) 0xFF00)

    /*! @brief Define CH1 GCAL LSB register reserved mask*/
    #define CH1_GCAL_LSB_RESERVED0_MASK                                     ((uint16_t) 0x00FF)



/* Register 0x13 (CH2_CFG) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                                           PHASE2[9:0]                                                           |                   RESERVED0[3:0]                  |        MUX2[1:0]        |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH2 CFG register Address*/
    #define CH2_CFG_ADDRESS                                                 ((uint8_t)  0x13)
    /*! @brief Define CH2 CFG register Default*/
    #define CH2_CFG_DEFAULT                                                 ((uint16_t) 0x0000)

    /*! @brief Define CH2 CFG register Phase2 mask*/
    #define CH2_CFG_PHASE2_MASK                                             ((uint16_t) 0xFFC0)

    /*! @brief Define CH2 CFG register reserved0 mask*/
    #define CH2_CFG_RESERVED0_MASK                                          ((uint16_t) 0x003C)

    /*! @brief Define CH2 CFG register MUX mask*/
    #define CH2_CFG_MUX2_MASK                                               ((uint16_t) 0x0003)
    /*! @brief Define CH2 CFG register MUX AIN2P_AIN2N*/
    #define CH2_CFG_MUX2_AIN2P_AIN2N                                        ((uint16_t) 0x0000 << 0)    /* DEFAULT */ 
    /*! @brief Define CH2 CFG register MUX ADC input short*/
    #define CH2_CFG_MUX2_ADC_INPUT_SHORT                                    ((uint16_t) 0x0001 << 0)
    /*! @brief Define CH2 CFG register MUX dc diagnostic*/
    #define CH2_CFG_MUX2_DC_DIAGNOSTIC                                      ((uint16_t) 0x0002 << 0)
    /*! @brief Define CH2 CFG register MUX ac diagnostic*/
    #define CH2_CFG_MUX2_AC_DIAGNOSTIC                                      ((uint16_t) 0x0003 << 0)



/* Register 0x14 (CH2_OCAL_MSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                                                                                OCAL2_MSB[15:0]                                                                                                |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH2 OCAL MSB register Address*/
    #define CH2_OCAL_MSB_ADDRESS                                            ((uint8_t)  0x14)
    /*! @brief Define CH2 OCAL MSB register default*/
    #define CH2_OCAL_MSB_DEFAULT                                            ((uint16_t) 0x0000)

    /*! @brief Define CH2 OCAL MSB register mask*/
    #define CH2_OCAL_MSB_OCAL2_MSB_MASK                                     ((uint16_t) 0xFFFF)



/* Register 0x15 (CH2_OCAL_LSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                             OCAL2_LSB[7:0]                                            |                                             RESERVED0[7:0]                                            |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH2 OCAL LSB register Address*/
    #define CH2_OCAL_LSB_ADDRESS                                            ((uint8_t)  0x15)
    /*! @brief Define CH2 OCAL LSB register default*/
    #define CH2_OCAL_LSB_DEFAULT                                            ((uint16_t) 0x0000)

    /*! @brief Define CH2 OCAL LSB register mask*/
    #define CH2_OCAL_LSB_OCAL2_LSB_MASK                                     ((uint16_t) 0xFF00)

    /*! @brief Define CH2 OCAL LSB register reserved0 mask*/
    #define CH2_OCAL_LSB_RESERVED0_MASK                                     ((uint16_t) 0x00FF)



/* Register 0x16 (CH2_GCAL_MSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                                                                                GCAL2_MSB[15:0]                                                                                                |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH2 GCAL MSB register Address*/
    #define CH2_GCAL_MSB_ADDRESS                                            ((uint8_t)  0x16)
    /*! @brief Define CH2 GCAL MSB register default*/
    #define CH2_GCAL_MSB_DEFAULT                                            ((uint16_t) 0x8000)

    /*! @brief Define CH2 GCAL MSB register mask*/
    #define CH2_GCAL_MSB_GCAL2_MSB_MASK                                     ((uint16_t) 0xFFFF)



/* Register 0x17 (CH2_GCAL_LSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                             GCAL2_LSB[7:0]                                            |                                             RESERVED0[7:0]                                            |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH2 GCAL LSB register Address*/
    #define CH2_GCAL_LSB_ADDRESS                                            ((uint8_t)  0x17)
    /*! @brief Define CH2 GCAL LSB register default*/
    #define CH2_GCAL_LSB_DEFAULT                                            ((uint16_t) 0x0000)

    /*! @brief Define CH2 GCAL LSB register mask*/
    #define CH2_GCAL_LSB_GCAL2_LSB_MASK                                     ((uint16_t) 0xFF00)

    /*! @brief Define CH2 GCAL LSB register reserved mask*/
    #define CH2_GCAL_LSB_RESERVED0_MASK                                     ((uint16_t) 0x00FF)



/* Register 0x18 (CH3_CFG) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                                           PHASE3[9:0]                                                           |                   RESERVED0[3:0]                  |        MUX3[1:0]        |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH3 CFG register Address*/
    #define CH3_CFG_ADDRESS                                                 ((uint8_t)  0x18)
    /*! @brief Define CH3 CFG register Default*/
    #define CH3_CFG_DEFAULT                                                 ((uint16_t) 0x0000)

    /*! @brief Define CH3 CFG register phase3 mask*/
    #define CH3_CFG_PHASE3_MASK                                             ((uint16_t) 0xFFC0)

    /*! @brief Define CH3 CFG register resereved mask*/
    #define CH3_CFG_RESERVED0_MASK                                          ((uint16_t) 0x003C)

    /*! @brief Define CH3 CFG register MUX3 mask*/
    #define CH3_CFG_MUX3_MASK                                               ((uint16_t) 0x0003)
    /*! @brief Define CH3 CFG register MUX3 AIN3P_AIN3N*/
    #define CH3_CFG_MUX3_AIN3P_AIN3N                                        ((uint16_t) 0x0000 << 0)    /* DEFAULT */ 
    /*! @brief Define CH3 CFG register MUX3 ADC input short*/
    #define CH3_CFG_MUX3_ADC_INPUT_SHORT                                    ((uint16_t) 0x0001 << 0)
    /*! @brief Define CH3 CFG register MUX3 dc diagnostic*/
    #define CH3_CFG_MUX3_DC_DIAGNOSTIC                                      ((uint16_t) 0x0002 << 0)
    /*! @brief Define CH3 CFG register MUX3 ac diagnostic*/
    #define CH3_CFG_MUX3_AC_DIAGNOSTIC                                      ((uint16_t) 0x0003 << 0)



/* Register 0x19 (CH3_OCAL_MSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                                                                                OCAL3_MSB[15:0]                                                                                                |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH3 OCAL MSB register Address*/
    #define CH3_OCAL_MSB_ADDRESS                                            ((uint8_t)  0x19)
    /*! @brief Define CH3 OCAL MSB register Deafault*/
    #define CH3_OCAL_MSB_DEFAULT                                            ((uint16_t) 0x0000)

    /*! @brief Define CH3 OCAL MSB register mask*/
    #define CH3_OCAL_MSB_OCAL3_MSB_MASK                                     ((uint16_t) 0xFFFF)



/* Register 0x1A (CH3_OCAL_LSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                             OCAL3_LSB[7:0]                                            |                                             RESERVED0[7:0]                                            |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH3 OCAL LSB register Address*/
    #define CH3_OCAL_LSB_ADDRESS                                            ((uint8_t)  0x1A)
    /*! @brief Define CH3 OCAL LSB register default*/
    #define CH3_OCAL_LSB_DEFAULT                                            ((uint16_t) 0x0000)

    /*! @brief Define CH3 OCAL LSB register mask*/
    #define CH3_OCAL_LSB_OCAL3_LSB_MASK                                     ((uint16_t) 0xFF00)

    /*! @brief Define CH3 OCAL LSB register reserved mask*/
    #define CH3_OCAL_LSB_RESERVED0_MASK                                     ((uint16_t) 0x00FF)



/* Register 0x1B (CH3_GCAL_MSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                                                                                GCAL3_MSB[15:0]                                                                                                |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH3 GCAL MSB register Address*/
    #define CH3_GCAL_MSB_ADDRESS                                            ((uint8_t)  0x1B)
    /*! @brief Define CH3 GCAL MSB register default*/
    #define CH3_GCAL_MSB_DEFAULT                                            ((uint16_t) 0x8000)

    /*! @brief Define CH3 GCAL MSB register mask*/
    #define CH3_GCAL_MSB_GCAL3_MSB_MASK                                     ((uint16_t) 0xFFFF)



/* Register 0x1C (CH3_GCAL_LSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                             GCAL3_LSB[7:0]                                            |                                             RESERVED0[7:0]                                            |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH3 GCAL LSB register Address*/
    #define CH3_GCAL_LSB_ADDRESS                                            ((uint8_t)  0x1C)
    /*! @brief Define CH3 GCAL MSB register default*/
    #define CH3_GCAL_LSB_DEFAULT                                            ((uint16_t) 0x0000)

    /*! @brief Define CH3 GCAL MSB register mask*/
    #define CH3_GCAL_LSB_GCAL3_LSB_MASK                                     ((uint16_t) 0xFF00)

    /*! @brief Define CH3 GCAL MSB register reserved mask*/
    #define CH3_GCAL_LSB_RESERVED0_MASK                                     ((uint16_t) 0x00FF)



/* Register 0x1D (CH4_CFG) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                                           PHASE4[9:0]                                                           |                   RESERVED0[3:0]                  |        MUX4[1:0]        |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH4 CFG register Address*/
    #define CH4_CFG_ADDRESS                                                 ((uint8_t)  0x1D)
    /*! @brief Define CH4 CFG register default*/
    #define CH4_CFG_DEFAULT                                                 ((uint16_t) 0x0000)

    /*! @brief Define CH4 CFG register phase 4 mask*/
    #define CH4_CFG_PHASE4_MASK                                             ((uint16_t) 0xFFC0)

    /*! @brief Define CH4 CFG register reserved mask*/
    #define CH4_CFG_RESERVED0_MASK                                          ((uint16_t) 0x003C)

    /*! @brief Define CH4 CFG register mux4 mask*/
    #define CH4_CFG_MUX4_MASK                                               ((uint16_t) 0x0003)
    /*! @brief Define CH4 CFG register mux4 AIN4P_AIN4N*/
    #define CH4_CFG_MUX4_AIN4P_AIN4N                                        ((uint16_t) 0x0000 << 0)    /* DEFAULT */ 
    /*! @brief Define CH4 CFG register mux4 adc input short*/
    #define CH4_CFG_MUX4_ADC_INPUT_SHORT                                    ((uint16_t) 0x0001 << 0)
    /*! @brief Define CH4 CFG register mux4 dc diagnostic*/
    #define CH4_CFG_MUX4_DC_DIAGNOSTIC                                      ((uint16_t) 0x0002 << 0)
    /*! @brief Define CH4 CFG register mux4 ac diagnostic*/
    #define CH4_CFG_MUX4_AC_DIAGNOSTIC                                      ((uint16_t) 0x0003 << 0)



/* Register 0x1E (CH4_OCAL_MSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                                                                                OCAL4_MSB[15:0]                                                                                                |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH4 OCAL MSB register Address*/
    #define CH4_OCAL_MSB_ADDRESS                                            ((uint8_t)  0x1E)
    /*! @brief Define CH4 OCAL MSB register default*/
    #define CH4_OCAL_MSB_DEFAULT                                            ((uint16_t) 0x0000)

    /*! @brief Define CH4 OCAL MSB register mask*/
    #define CH4_OCAL_MSB_OCAL4_MSB_MASK                                     ((uint16_t) 0xFFFF)



/* Register 0x1F (CH4_OCAL_LSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                             OCAL4_LSB[7:0]                                            |                                             RESERVED0[7:0]                                            |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH4 OCAL LSB register Address*/
    #define CH4_OCAL_LSB_ADDRESS                                            ((uint8_t)  0x1F)
    /*! @brief Define CH4 OCAL LSB register default*/
    #define CH4_OCAL_LSB_DEFAULT                                            ((uint16_t) 0x0000)

    /*! @brief Define CH4 OCAL LSB register mask*/
    #define CH4_OCAL_LSB_OCAL4_LSB_MASK                                     ((uint16_t) 0xFF00)

    /*! @brief Define CH4 OCAL LSB register reserved mask*/
    #define CH4_OCAL_LSB_RESERVED0_MASK                                     ((uint16_t) 0x00FF)



/* Register 0x20 (CH4_GCAL_MSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                                                                                GCAL4_MSB[15:0]                                                                                                |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH4 GCAL MSB register Address*/
    #define CH4_GCAL_MSB_ADDRESS                                            ((uint8_t)  0x20)
    /*! @brief Define CH4 GCAL MSB register default*/
    #define CH4_GCAL_MSB_DEFAULT                                            ((uint16_t) 0x8000)

    /*! @brief Define CH4 GCAL MSB register mask*/
    #define CH4_GCAL_MSB_GCAL4_MSB_MASK                                     ((uint16_t) 0xFFFF)



/* Register 0x21 (CH4_GCAL_LSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                             GCAL4_LSB[7:0]                                            |                                             RESERVED0[7:0]                                            |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH4 GCAL LSB register Address*/
    #define CH4_GCAL_LSB_ADDRESS                                            ((uint8_t)  0x21)
    /*! @brief Define CH4 GCAL LSB register default*/
    #define CH4_GCAL_LSB_DEFAULT                                            ((uint16_t) 0x0000)

    /*! @brief Define CH4 GCAL LSB register mask*/
    #define CH4_GCAL_LSB_GCAL4_LSB_MASK                                     ((uint16_t) 0xFF00)

    /*! @brief Define CH4 GCAL LSB register reserved mask*/
    #define CH4_GCAL_LSB_RESERVED0_MASK                                     ((uint16_t) 0x00FF)



/* Register 0x22 (CH5_CFG) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                                           PHASE5[9:0]                                                           |                   RESERVED0[3:0]                  |        MUX5[1:0]        |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH5 CFG register Address*/
    #define CH5_CFG_ADDRESS                                                 ((uint8_t)  0x22)
    /*! @brief Define CH5 CFG register default*/
    #define CH5_CFG_DEFAULT                                                 ((uint16_t) 0x0000)

    /*! @brief Define CH5 CFG register mask*/
    #define CH5_CFG_PHASE5_MASK                                             ((uint16_t) 0xFFC0)

    /*! @brief Define CH5 CFG register reserved mask*/
    #define CH5_CFG_RESERVED0_MASK                                          ((uint16_t) 0x003C)

    /*! @brief Define CH5 CFG register MUX5 mask*/
    #define CH5_CFG_MUX5_MASK                                               ((uint16_t) 0x0003)
    /*! @brief Define CH5 CFG register MUX5 AIN5P_AIN5N*/
    #define CH5_CFG_MUX5_AIN5P_AIN5N                                        ((uint16_t) 0x0000 << 0)    /* DEFAULT */ 
    /*! @brief Define CH5 CFG register MUX5 adc input short*/
    #define CH5_CFG_MUX5_ADC_INPUT_SHORT                                    ((uint16_t) 0x0001 << 0)
    /*! @brief Define CH5 CFG register MUX5 dc diagnostic*/
    #define CH5_CFG_MUX5_DC_DIAGNOSTIC                                      ((uint16_t) 0x0002 << 0)
    /*! @brief Define CH5 CFG register MUX5 ac diagnostic*/
    #define CH5_CFG_MUX5_AC_DIAGNOSTIC                                      ((uint16_t) 0x0003 << 0)



/* Register 0x23 (CH5_OCAL_MSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                                                                                OCAL5_MSB[15:0]                                                                                                |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH5 OCAL MSB register Address*/
    #define CH5_OCAL_MSB_ADDRESS                                            ((uint8_t)  0x23)
    /*! @brief Define CH5 OCAL MSB register default*/
    #define CH5_OCAL_MSB_DEFAULT                                            ((uint16_t) 0x0000)

    /*! @brief Define CH5 OCAL MSB register mask*/
    #define CH5_OCAL_MSB_OCAL5_MSB_MASK                                     ((uint16_t) 0xFFFF)



/* Register 0x24 (CH5_OCAL_LSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                             OCAL5_LSB[7:0]                                            |                                             RESERVED0[7:0]                                            |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH5 OCAL LSB register Address*/
    #define CH5_OCAL_LSB_ADDRESS                                            ((uint8_t)  0x24)
    /*! @brief Define CH5 OCAL LSB register default*/
    #define CH5_OCAL_LSB_DEFAULT                                            ((uint16_t) 0x0000)

    /*! @brief Define CH5 OCAL LSB register mask*/
    #define CH5_OCAL_LSB_OCAL5_LSB_MASK                                     ((uint16_t) 0xFF00)

    /*! @brief Define CH5 OCAL LSB register reserved mask*/
    #define CH5_OCAL_LSB_RESERVED0_MASK                                     ((uint16_t) 0x00FF)



/* Register 0x25 (CH5_GCAL_MSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                                                                                GCAL5_MSB[15:0]                                                                                                |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH5 GCAL MSB register Address*/
    #define CH5_GCAL_MSB_ADDRESS                                            ((uint8_t)  0x25)
    /*! @brief Define CH5 GCAL MSB register default*/
    #define CH5_GCAL_MSB_DEFAULT                                            ((uint16_t) 0x8000)

    /*! @brief Define CH5 GCAL MSB register mask*/
    #define CH5_GCAL_MSB_GCAL5_MSB_MASK                                     ((uint16_t) 0xFFFF)



/* Register 0x26 (CH5_GCAL_LSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                             GCAL5_LSB[7:0]                                            |                                             RESERVED0[7:0]                                            |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH5 GCAL LSB register Address*/
    #define CH5_GCAL_LSB_ADDRESS                                            ((uint8_t)  0x26)
    /*! @brief Define CH5 GCAL LSB register default*/
    #define CH5_GCAL_LSB_DEFAULT                                            ((uint16_t) 0x0000)

    /*! @brief Define CH5 GCAL LSB register mask*/
    #define CH5_GCAL_LSB_GCAL5_LSB_MASK                                     ((uint16_t) 0xFF00)

    /*! @brief Define CH5 GCAL LSB register reserved mask*/
    #define CH5_GCAL_LSB_RESERVED0_MASK                                     ((uint16_t) 0x00FF)



/* Register 0x27 (CH6_CFG) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                                           PHASE6[9:0]                                                           |                   RESERVED0[3:0]                  |        MUX6[1:0]        |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH6 CFG register Address*/
    #define CH6_CFG_ADDRESS                                                 ((uint8_t)  0x27)
    /*! @brief Define CH6 CFG register defaults*/
    #define CH6_CFG_DEFAULT                                                 ((uint16_t) 0x0000)

    /*! @brief Define CH6 CFG register phase6 mask*/
    #define CH6_CFG_PHASE6_MASK                                             ((uint16_t) 0xFFC0)

    /*! @brief Define CH6 CFG register reserved mask*/
    #define CH6_CFG_RESERVED0_MASK                                          ((uint16_t) 0x003C)

    /*! @brief Define CH6 CFG register MUX6 mask*/
    #define CH6_CFG_MUX6_MASK                                               ((uint16_t) 0x0003)
    /*! @brief Define CH6 CFG register MUX6 AIN6P_AIN6N*/
    #define CH6_CFG_MUX6_AIN6P_AIN6N                                        ((uint16_t) 0x0000 << 0)    /* DEFAULT */ 
    /*! @brief Define CH6 CFG register MUX6 adc input short*/
    #define CH6_CFG_MUX6_ADC_INPUT_SHORT                                    ((uint16_t) 0x0001 << 0)
    /*! @brief Define CH6 CFG register MUX6 dc diagnostic*/
    #define CH6_CFG_MUX6_DC_DIAGNOSTIC                                      ((uint16_t) 0x0002 << 0)
    /*! @brief Define CH6 CFG register MUX6 ac diagnostic*/
    #define CH6_CFG_MUX6_AC_DIAGNOSTIC                                      ((uint16_t) 0x0003 << 0)



/* Register 0x28 (CH6_OCAL_MSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                                                                                OCAL6_MSB[15:0]                                                                                                |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH6 OCAL MSB register Address*/
    #define CH6_OCAL_MSB_ADDRESS                                            ((uint8_t)  0x28)
    /*! @brief Define CH6 OCAL MSB register default*/
    #define CH6_OCAL_MSB_DEFAULT                                            ((uint16_t) 0x0000)

    /*! @brief Define CH6 OCAL MSB register mask*/
    #define CH6_OCAL_MSB_OCAL6_MSB_MASK                                     ((uint16_t) 0xFFFF)



/* Register 0x29 (CH6_OCAL_LSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                             OCAL6_LSB[7:0]                                            |                                             RESERVED0[7:0]                                            |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH6 OCAL LSB register Address*/
    #define CH6_OCAL_LSB_ADDRESS                                            ((uint8_t)  0x29)
    /*! @brief Define CH6 OCAL LSB register default*/
    #define CH6_OCAL_LSB_DEFAULT                                            ((uint16_t) 0x0000)

    /*! @brief Define CH6 OCAL LSB register mask*/
    #define CH6_OCAL_LSB_OCAL6_LSB_MASK                                     ((uint16_t) 0xFF00)

    /*! @brief Define CH6 OCAL LSB register reserved mask*/
    #define CH6_OCAL_LSB_RESERVED0_MASK                                     ((uint16_t) 0x00FF)



/* Register 0x2A (CH6_GCAL_MSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                                                                                GCAL6_MSB[15:0]                                                                                                |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH6 GCAL MSB register Address*/
    #define CH6_GCAL_MSB_ADDRESS                                            ((uint8_t)  0x2A)
    /*! @brief Define CH6 GCAL MSB register default*/
    #define CH6_GCAL_MSB_DEFAULT                                            ((uint16_t) 0x8000)

    /*! @brief Define CH6 GCAL MSB register mask*/
    #define CH6_GCAL_MSB_GCAL6_MSB_MASK                                     ((uint16_t) 0xFFFF)



/* Register 0x2B (CH6_GCAL_LSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                             GCAL6_LSB[7:0]                                            |                                             RESERVED0[7:0]                                            |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH6 GCAL LSB register Address*/
    #define CH6_GCAL_LSB_ADDRESS                                            ((uint8_t)  0x2B)
    /*! @brief Define CH6 GCAL LSB register default*/
    #define CH6_GCAL_LSB_DEFAULT                                            ((uint16_t) 0x0000)

    /*! @brief Define CH6 GCAL LSB register mask*/
    #define CH6_GCAL_LSB_GCAL6_LSB_MASK                                     ((uint16_t) 0xFF00)

    /*! @brief Define CH6 GCAL LSB register reserved mask*/
    #define CH6_GCAL_LSB_RESERVED0_MASK                                     ((uint16_t) 0x00FF)



/* Register 0x2C (CH7_CFG) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                                           PHASE7[9:0]                                                           |                   RESERVED0[3:0]                  |        MUX7[1:0]        |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH7 CFG register Address*/
    #define CH7_CFG_ADDRESS                                                 ((uint8_t)  0x2C)
    /*! @brief Define CH7 CFG register default*/
    #define CH7_CFG_DEFAULT                                                 ((uint16_t) 0x0000)

    /*! @brief Define CH7 CFG register phase7 mask*/
    #define CH7_CFG_PHASE7_MASK                                             ((uint16_t) 0xFFC0)

    /*! @brief Define CH7 CFG register reserved mask*/
    #define CH7_CFG_RESERVED0_MASK                                          ((uint16_t) 0x003C)

    /*! @brief Define CH7 CFG register MUX7 mask*/
    #define CH7_CFG_MUX7_MASK                                               ((uint16_t) 0x0003)
    /*! @brief Define CH7 CFG register MUX7 AIN7P_AIN7N*/
    #define CH7_CFG_MUX7_AIN7P_AIN7N                                        ((uint16_t) 0x0000 << 0)    /* DEFAULT */ 
    /*! @brief Define CH7 CFG register MUX7 adc input short*/
    #define CH7_CFG_MUX7_ADC_INPUT_SHORT                                    ((uint16_t) 0x0001 << 0)
    /*! @brief Define CH7 CFG register MUX7 dc diagnostic*/
    #define CH7_CFG_MUX7_DC_DIAGNOSTIC                                      ((uint16_t) 0x0002 << 0)
    /*! @brief Define CH7 CFG register MUX7 ac diagnostic*/
    #define CH7_CFG_MUX7_AC_DIAGNOSTIC                                      ((uint16_t) 0x0003 << 0)



/* Register 0x2D (CH7_OCAL_MSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                                                                                OCAL7_MSB[15:0]                                                                                                |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH7 OCAL MSB register Address*/
    #define CH7_OCAL_MSB_ADDRESS                                            ((uint8_t)  0x2D)
    /*! @brief Define CH7 OCAL MSB register default*/
    #define CH7_OCAL_MSB_DEFAULT                                            ((uint16_t) 0x0000)

    /*! @brief Define CH7 OCAL MSB register mask*/
    #define CH7_OCAL_MSB_OCAL7_MSB_MASK                                     ((uint16_t) 0xFFFF)



/* Register 0x2E (CH7_OCAL_LSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                             OCAL7_LSB[7:0]                                            |                                             RESERVED0[7:0]                                            |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH7 OCAL LSB register Address*/
    #define CH7_OCAL_LSB_ADDRESS                                            ((uint8_t)  0x2E)
    /*! @brief Define CH7 OCAL LSB register default*/
    #define CH7_OCAL_LSB_DEFAULT                                            ((uint16_t) 0x0000)

    /*! @brief Define CH7 OCAL LSB register mask*/
    #define CH7_OCAL_LSB_OCAL7_LSB_MASK                                     ((uint16_t) 0xFF00)

    /*! @brief Define CH7 OCAL LSB register reserved mask*/
    #define CH7_OCAL_LSB_RESERVED0_MASK                                     ((uint16_t) 0x00FF)



/* Register 0x2F (CH7_GCAL_MSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                                                                                GCAL7_MSB[15:0]                                                                                                |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH7 GCAL MSB register Address*/
    #define CH7_GCAL_MSB_ADDRESS                                            ((uint8_t)  0x2F)
    /*! @brief Define CH7 GCAL MSB register default*/
    #define CH7_GCAL_MSB_DEFAULT                                            ((uint16_t) 0x8000)

    /*! @brief Define CH7 GCAL MSB register mask*/
    #define CH7_GCAL_MSB_GCAL7_MSB_MASK                                     ((uint16_t) 0xFFFF)



/* Register 0x30 (CH7_GCAL_LSB) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                             GCAL7_LSB[7:0]                                            |                                             RESERVED0[7:0]                                            |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define CH7 GCAL LSB register Address*/
    #define CH7_GCAL_LSB_ADDRESS                                            ((uint8_t)  0x30)
    /*! @brief Define CH7 GCAL LSB register default*/
    #define CH7_GCAL_LSB_DEFAULT                                            ((uint16_t) 0x0000)

    /*! @brief Define CH7 GCAL LSB register mask*/
    #define CH7_GCAL_LSB_GCAL7_LSB_MASK                                     ((uint16_t) 0xFF00)

    /*! @brief Define CH7 GCAL LSB register reserved mask*/
    #define CH7_GCAL_LSB_RESERVED0_MASK                                     ((uint16_t) 0x00FF)



/* Register 0x3E (REGMAP_CRC) definition
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |   Bit 15   |   Bit 14   |   Bit 13   |   Bit 12   |   Bit 11   |   Bit 10   |    Bit 9   |    Bit 8   |    Bit 7   |    Bit 6   |    Bit 5   |    Bit 4   |    Bit 3   |    Bit 2   |    Bit 1   |    Bit 0   |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * |                                                                                                 REG_CRC[15:0]                                                                                                 |
 * -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 */

    /*! @brief Define REGMAP CRC register Address*/
    #define REGMAP_CRC_ADDRESS                                              ((uint8_t)  0x3E)
    /*! @brief Define REGMAP CRC register default*/
    #define REGMAP_CRC_DEFAULT                                              ((uint16_t) 0x0000)

    /*! @brief Define REGMAP CRC register mask*/
    #define REGMAP_CRC_REG_CRC_MASK                                         ((uint16_t) 0xFFFF)


//****************************************************************************
//
// Register macros
//
//****************************************************************************

    /*! @brief Return channel count*/
#define CHANCNT(x)             ((uint8_t) ((getRegisterValue(ID_ADDRESS, x) & ID_CHANCNT_MASK) >> 8))

    /*! @brief Return revID*/
#define REVISION_ID(x)         ((uint8_t) ((getRegisterValue(ID_ADDRESS, x) & ID_REVID_MASK) >> 0))

    /*! @brief Return SPI locked */
#define SPI_LOCKED(x)          ((bool) (getRegisterValue(STATUS_ADDRESS, x) & STATUS_LOCK_LOCKED))

    /*! @brief Return word length*/
#define WLENGTH(x)             ((uint8_t) ((getRegisterValue(MODE_ADDRESS, x) & STATUS_WLENGTH_MASK) >> 8))

    /*! @brief Return CRC status*/
#define REGMAP_CRC_ENABLED(x)  ((bool) (getRegisterValue(MODE_ADDRESS, x) & MODE_REG_CRC_EN_ENABLED))

    /*! @brief Return SPI CRC status*/
#define SPI_CRC_ENABLED(x)     ((bool) (getRegisterValue(MODE_ADDRESS, x) & MODE_RX_CRC_EN_ENABLED))

    /*! @brief Return CRC type*/
#define SPI_CRC_TYPE(x)        ((bool) (getRegisterValue(MODE_ADDRESS, x) & MODE_CRC_TYPE_MASK))

    /*! @brief Return OSR index*/
#define OSR_INDEX(x)           ((uint8_t) ((getRegisterValue(CLOCK_ADDRESS, x) & CLOCK_OSR_MASK) >> 2))

    /*! @brief Return power mode*/
#define POWER_MODE(x)          ((uint8_t) ((getRegisterValue(CLOCK_ADDRESS, x) & CLOCK_PWR_MASK) >> 0))


/*!
 * @brief Write to a single register
 * @param[in] adsHandle     The ADS Instance
 * @param[in] regAddr       The register address
 * @param[in] data          Data to be written
 * @param[in] readCheck     write check
 * @return Write status
 */
bool ADS_writeSingleSPIReg(ADS_Instance *adsHandle, uint8_t regAddr, uint16_t data, bool readCheck);

/*!
 * @brief Read a single register
 * @param[in] adsHandle     The ADS Instance
 * @param[in] regAddr       The register address
 * @return Register Data
 */
uint16_t ADS_readSingleSPIReg(ADS_Instance *adsHandle, uint8_t regAddr);

/*!
 * @brief Reset ADS
 * @param[in] adsHandle     The ADS Instance
 */
void ADS_resetDevice(ADS_Instance *adsHandle);

/*!
 * @brief Lock ADS Registers
 * @param[in] adsHandle     The ADS Instance
 * @return Register status
 */
bool ADS_lockRegisters(ADS_Instance *adsHandle);

/*!
 * @brief Unlock ADS Registers
 * @param[in] adsHandle     The ADS Instance
 * @return Register status
 */
bool ADS_unlockRegisters(ADS_Instance *adsHandle);

/*!
 * @brief ADS standby mode
 * @param[in] adsHandle     The ADS Instance
 */
void ADS_standbymode(ADS_Instance *adsHandle);

/*!
 * @brief Wakeup ADS
 * @param[in] adsHandle     The ADS Instance
 */
void ADS_wakeupCommand(ADS_Instance *adsHandle);

/*!
 * @brief Reset ADS
 * @param[in] adsHandle     The ADS Instance
 */
void ADS_reset(ADS_Instance *adsHandle);

/*!
 * @brief Sync ADS
 * @param[in] adsHandle     The ADS Instance
 */
void ADS_toggleSYNC(ADS_Instance *adsHandle);

/*!
 * @brief ADS initialization
 * @param[in] adsHandle     The ADS Instance
 * @return status
 */
bool ADS_init(ADS_Instance *adsHandle);

/*!
 * @brief Start Data Collection
 * @param[in] adsHandle     The ADS Instance
 */
void ADS_startDataCollection(ADS_Instance *adsHandle);

/*!
 * @brief Start DMA Transfer
 * @param[in] adsHandle     The ADS Instance
 */
void ADS_startDMADataTransfer(ADS_Instance *adsHandle);

/*!
 * @brief Get ADS Channel Data
 * @param[in] adsHandle     The ADS Instance
 */
void ADS_getChannelData(ADS_Instance *adsHandle);

/*!
 * @brief Initialize ADS Registers
 * @param[in] adsHandle     The ADS Instance
 */
void ADS_initalizeADSRegisters(ADS_Instance *adsHandle);

/*!
 * @brief verify CRC for channel data
 * @param[in] adsHandle   The ADS Instance
 * @param[in] adsData     The ADS channel data
 */
void ADS_verifyADSCRC(ADS_Instance *adsHandle, ADS_channelData *adsData);

#ifdef __cplusplus
}
#endif

#endif /*ADS131M0X_H_ */
/** @}*/
