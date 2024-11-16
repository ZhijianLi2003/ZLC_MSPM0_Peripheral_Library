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
 *  @file       eeprom_emulation_type_a.h
 *  @brief      EEPROM Emulation Type A
 *  @defgroup   EEPROM_TYPE_A EEPROM Emulation Type A
 *
 *  @anchor EEPROM_EMULATION_TYPE_A_H__Overview
 *  # Overview
 *
 *  MSPM0 support EEPROM emulation through its internal Flash. Compared to using
 *  an external serial EEPROM, EEPROM emulation using the internal Flash saves
 *  pin usage and cost.
 *  The EEPROM emulation Type A solution is suitable if the user application
 *  needs to store large "blocks" of data.
 *
 *  <hr>
 ******************************************************************************/
/** @addtogroup EEPROM_TYPE_A
 * @{
 */
#ifndef EEPROM_EMULATION_TYPE_A_H_
#define EEPROM_EMULATION_TYPE_A_H_

#include <stdbool.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

/* clang-format off */

 /** @addtogroup EEPROM_TYPE_A_USER_CONFIGURABLE_PARAMETERS
  *
  * EEPROM Type A library user configurable parameters.
 * @{
 */
/*!
 * @brief The sector address to use
 */
#define EEPROM_EMULATION_ADDRESS                                    (0x00001000)
/*!
 * @brief The number of sectors to use
 */
#define EEPROM_EMULATION_SECTOR_ACCOUNT                                      (2)
/*!
 * @brief The record size. Valid values are 64 (64B), 128 (128B), or 256 (256B).
 */
#define EEPROM_EMULATION_RECORD_SIZE                                       (128)
/** @}*/

 /** @addtogroup EEPROM_TYPE_A_LIB_PARAMETERS
  *
  * These defines are used by the EEPROM Type A Library. It is not recommended
  *  to modify the following parameters
 * @{
 */
/*!
 * @brief The size of the data
 */
#define EEPROM_EMULATION_DATA_SIZE            (EEPROM_EMULATION_RECORD_SIZE - 8)
/*!
 * @brief The number of records in a sector
 */
#define EEPROM_EMULATION_RECORD_ACCOUNT    (1024 / EEPROM_EMULATION_RECORD_SIZE)
/*!
 * @brief The minimum number of records in a sector
 */
#define EEPROM_EMULATION_ACTIVE_RECORD_NUM_MIN                               (1)
/*!
 * @brief The maximum number of records in a sector
 */
#define EEPROM_EMULATION_ACTIVE_RECORD_NUM_MAX                                 \
                                               (EEPROM_EMULATION_RECORD_ACCOUNT)
/*!
 * @brief The minimum number of active sectors
 */
#define EEPROM_EMULATION_ACTIVE_SECTOR_NUM_MIN                               (1)
/*!
 * @brief The maximum number of active sectors
 */
#define EEPROM_EMULATION_ACTIVE_SECTOR_NUM_MAX                                 \
                                               (EEPROM_EMULATION_SECTOR_ACCOUNT)
 /** @}*/

 /** @addtogroup EEPROM_TYPE_A_STATUS
  *
  * These defines are used for the return status of some commands.
 * @{
 */
/*!
 * @brief Data write is successful
 */
#define EEPROM_EMULATION_WRITE_OK                       ((uint32_t) 0x00000000U)
/*!
 * @brief Data write failed
 */
#define EEPROM_EMULATION_WRITE_ERROR                    ((uint32_t) 0x00000001U)
/*!
 * @brief Formatting error
 */
#define EEPROM_EMULATION_FORMAT_ERROR                   ((uint32_t) 0x00000010U)
/*!
 * @brief Initialization is successful
 */
#define EEPROM_EMULATION_INIT_OK                        ((uint32_t) 0x00000000U)
/*!
 * @brief Initialization failed
 */
#define EEPROM_EMULATION_INIT_ERROR                     ((uint32_t) 0x00000002U)
/** @}*/

/* clang-format on */

/** \brief Store the address of the current active record */
extern uint32_t gActiveRecordAddress;
/** \brief Store the address of the next active record */
extern uint32_t gNextRecordAddress;
/** \brief Store the number of active records */
extern uint16_t gActiveRecordNum;
/** \brief Store the number of active sectors */
extern uint16_t gActiveSectorNum;

/** \brief Indicate when the active record exists */
extern bool gEEPROMTypeASearchFlag;
/** \brief Indicate when the sector is full nad needs to be erased */
extern bool gEEPROMTypeAEraseFlag;
/** \brief Indicate when a format error is found */
extern bool gEEPROMTypeAFormatErrorFlag;

/**
 *  @brief      Store provided data to the virtual EEPROM
 *
 *  The function will store the data to the flash to be a new record. It
 *  will also add a header to the record to mark its state. When the flash
 *  sector is full, it will set the gEEPROMTypeAEraseFlag.
 *
 *  @param[in]  data          Pointer to the buffer in RAM
 *
 *  @return     Whether or not the program succeeded
 *
 *  @retval     EEPROM_EMULATION_WRITE_OK        Program was successful
 *  @retval     EEPROM_EMULATION_FORMAT_ERROR    Next address was not erased
 *
 *  @pre         The user must ensure that the length of the buffer in RAM is
 *               equal to the length of the data portion of the record.
 *  @post        When the sector is full, the function only set the gEEPROMTypeAEraseFlag.
 *               The user should erase the sector before all sectors are full.
 *               Refer to @ref EEPROM_TypeA_eraseLastSector.
 */
uint32_t EEPROM_TypeA_writeData(uint32_t *data);

/**
 *  @brief      Initialize the specified area in flash
 *
 *  The function will first search the active record and check the format
 *  at the specified area. If active record exists, it will copy the data of
 *  active record to the buffer in RAM. If format is not correct, it will repair
 *  the format.
 *
 *  @param[in]  data          Pointer to the buffer in RAM
 *
 *  @return     Whether or not the program succeeded
 *
 *  @retval     EEPROM_EMULATION_INIT_OK        Program was successful
 *  @retval     EEPROM_EMULATION_INIT_ERROR    Next address was not erased
 *
 *  @pre         The user must ensure that the length of the buffer in RAM is
 *               equal to the length of the data portion of the record.
 *  @post        After @ref EEPROM_TypeA_init, there will be a format-correct
 *               area in flash, a buffer in RAM copied the active record,
 *               and some global variables that have been written.
 *
 *               4 global variables about active record:
 *                  gActiveRecordAddress
 *                  gNextRecordAddress
 *                  gActiveRecordNum
 *                  gActiveSectorNum
 *               3 global variables about format:
 *                  gEEPROMTypeASearchFlag
 *                  gEEPROMTypeAEraseFlag
 *                  gEEPROMTypeAFormatErrorFlag
 */
uint32_t EEPROM_TypeA_init(uint32_t *data);

/**
 *  @brief      Read the data from active record to the buffer in RAM
 *
 *  @param[in]  data          Pointer to the buffer in RAM
 *
 *  @pre         The user must ensure that the length of the buffer in RAM
 *               is equal to the length of the data portion of the record.
 *
 */
void EEPROM_TypeA_readData(uint32_t *data);

/**
 *  @brief      Repair the format
 *
 *  The function will first erase sectors other than the active sector. Then
 *  it will copy the data from the buffer in RAM to the beginning of next sector,
 *  which is to be new active record. 4 global variables about active record are
 *  updated too. Finally, the function erase the last sector
 *
 *  @param[in]  data          Pointer to the buffer in RAM
 *
 *  @return     Whether or not the program succeeded
 *
 *  @retval     false   Program didn't succeed
 *  @retval     true    Program was successful
 *
 *  @pre         The user must firstly prepare the data in RAM before call the
 *               function. The user must ensure that the length of the buffer
 *               in RAM is equal to the length of the data portion of the record.
 *  @post        After EEPROM_TypeA_repairFormat, all sectors are erased
 *               and the active record is at the beginning of next sector
 *
 *  NOTE: The user must firstly prepare the data in RAM before call the function.
 *        It is recommended to read active record into RAM first, then call the
 *        function to repair the format and write active record back.
 */
bool EEPROM_TypeA_repairFormat(uint32_t *data);

/**
 *  @brief      Search the active record and check the format
 *
 *  The function will traverse records� header. If the active record exists,
 *  gEEPROMTypeASearchFlag will be set, and 4 global variables about active record are
 *  updated. If the format is wrong, gEEPROMTypeAFormatErrorFlag is set
 *
 *  @post        If the active record exists, gEEPROMTypeASearchFlag will be set,
 *               and 4 global variables about active record are updated.
 *               If the format is wrong, gEEPROMTypeAFormatErrorFlag is set
 */
void EEPROM_TypeA_searchCheck(void);

/**
 *  @brief      Erase the previous sector of the active sector
 *
 *  @return     Whether or not the program succeeded
 *
 *  @retval     false   Program didn't succeed
 *  @retval     true    Program was successful
 *
 * According to gActiveSectorNum, the function can find the sector with active record.
 * Then it will erase the previous sector
 */
bool EEPROM_TypeA_eraseLastSector(void);

/**
 *  @brief     Erases sectors other than the active sector
 *
 *  @return     Whether or not the program succeeded
 *
 *  @retval     false   Program didn't succeed
 *  @retval     true    Program was successful
 *
 * According to gActiveSectorNum, the function can find the sector with active record.
 * Then it will erase sectors other than the active sector
 */
bool EEPROM_TypeA_eraseNonActiveSectors(void);

/**
 *  @brief      Erase all sectors used by EEPROM emulation
 *
 *  @return     Whether or not the program succeeded
 *
 *  @retval     false   Program didn't succeed
 *  @retval     true    Program was successful
 */
bool EEPROM_TypeA_eraseAllSectors(void);

#endif /* EEPROM_EMULATION_TYPE_A_H_ */
/** @}*/
