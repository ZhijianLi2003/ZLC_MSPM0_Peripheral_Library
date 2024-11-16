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
 *  @file       eeprom_emulation_type_b.h
 *  @brief      EEPROM Emulation Type B
 *  @defgroup   EEPROM_TYPE_B EEPROM Emulation Type B
 *
 *  @anchor EEPROM_EMULATION_TYPE_B_H__Overview
 *  # Overview
 *
 *  MSPM0 support EEPROM emulation through its internal Flash. Compared to using
 *  an external serial EEPROM, EEPROM emulation using the internal Flash saves
 *  pin usage and cost.
 *  The EEPROM emulation Type B solution is suitable if the user application
 *  needs to store small "variable" data.
 *
 *  <hr>
 ******************************************************************************/
/** @addtogroup EEPROM_TYPE_B
 * @{
 */
#include <stdbool.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifndef EEPROM_EMULATION_TYPE_B_H_
#define EEPROM_EMULATION_TYPE_B_H_

/* clang-format off */

 /** @addtogroup EEPROM_TYPE_B_USER_CONFIGURABLE_PARAMETERS
  *
  * EEPROM Type B library user configurable parameters.
 * @{
 */
/*!
 * @brief The sector address to use
 */
#define EEPROM_EMULATION_ADDRESS                                    (0x00001000)
/*!
 * @brief The number of groups to use
 */
#define EEPROM_EMULATION_GROUP_ACCOUNT                                       (3)
/*!
 * @brief The number of sectors in groups to use
 */
#define EEPROM_EMULATION_SECTOR_INGROUP_ACCOUNT                              (2)
/*!
 * @brief Enable or disable repair
 */
#define EEPROM_EMULATION_REPAIR_ENABLE                                       (0)
/** @}*/

 /** @addtogroup EEPROM_TYPE_B_LIB_PARAMETERS
  *
  * These defines are used by the EEPROM Type B Library. It is not recommended
  *  to modify the following parameters
 * @{
 */
/*!
 * @brief The number of data items
 */
#define EEPROM_EMULATION_DATAITEM_ACCOUNT                                      \
                             (EEPROM_EMULATION_SECTOR_INGROUP_ACCOUNT * 128 - 1)
/*!
 * @brief The minimum number of data items
 */
#define EEPROM_EMULATION_ACTIVE_DATAITEM_NUM_MIN                             (0)
/*!
 * @brief The maximum number of data items
 */
#define EEPROM_EMULATION_ACTIVE_DATAITEM_NUM_MAX                               \
                                             (EEPROM_EMULATION_DATAITEM_ACCOUNT)
/*!
 * @brief The minimum number of groups
 */
#define EEPROM_EMULATION_ACTIVE_GROUP_NUM_MIN                                (1)
/*!
 * @brief The maximum number of groups
 */
#define EEPROM_EMULATION_ACTIVE_GROUP_NUM_MAX   (EEPROM_EMULATION_GROUP_ACCOUNT)
/** @}*/

 /** @addtogroup EEPROM_TYPE_B_STATUS
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
 * @brief Transfer is successful
 */
#define EEPROM_EMULATION_TRANSFER_OK                    ((uint32_t) 0x00000000U)
/*!
 * @brief Transfer failed
 */
#define EEPROM_EMULATION_TRANSFER_ERROR                 ((uint32_t) 0x00000002U)

/*!
 * @brief Initialization is successful
 */
#define EEPROM_EMULATION_INIT_OK                        ((uint32_t) 0x00000000U)
/*!
 * @brief Initialization is successful with format repair
 */
#define EEPROM_EMULATION_INIT_OK_FORMAT_REPAIR          ((uint32_t) 0x00000004U)
/*!
 * @brief Initialization is all erased
 */
#define EEPROM_EMULATION_INIT_OK_ALL_ERASE              ((uint32_t) 0x00000040U)
/*!
 * @brief Initialization failed
 */
#define EEPROM_EMULATION_INIT_ERROR                     ((uint32_t) 0x00000400U)
/*!
 * @brief Item not found error
 */
#define EEPROM_EMULATION_FINDITEM_NOT_FOUND             ((uint32_t) 0x00000000U)
/*!
 * @brief Group is active
 */
#define CHECK_ONE_ACTIVE_GROUP                          ((uint32_t) 0x00000000U)
/*!
 * @brief The next address was not erased
 */
#define CHECK_NO_ACTIVE_ONE_ERROR_GROUP                 ((uint32_t) 0x00000001U)
/*!
 * @brief Writing new data item was not successful
 */
#define CHECK_NO_ACTIVE_NO_ERROR_GROUP                  ((uint32_t) 0x00000002U)
/** @}*/

/* clang-format on */

/** \brief Store the number of active data items */
extern uint16_t gActiveDataItemNum;
/** \brief Store the number of active groups */
extern uint16_t gActiveGroupNum;

/** \brief Indicate when the data item is found */
extern bool gEEPROMTypeBSearchFlag;
/** \brief Indicate when the group is full nad needs to be erased */
extern bool gEEPROMTypeBEraseFlag;

/**
 *  @brief      Write provided data and identifier to the Flash
 *
 *  The function brings together the data and the identifier into a new data
 *  item. Refer to @ref EEPROM_TypeB_writeDataItem. If group is full,
 *  transfer is performed. Refer to @ref EEPROM_TypeB_transferDataItem.
 *
 *  @param[in]  identifier          Used to tag and distinguish data
 *  @param[in]  data                User's data
 *
 *  @return     Whether or not the function succeeded
 *
 *  @retval     EEPROM_EMULATION_WRITE_OK        Program was successful
 *  @retval     EEPROM_EMULATION_TRANSFER_ERROR  Transfer is not successful
 *  @retval     EEPROM_EMULATION_WRITE_ERROR     Writing new data item is not successful
 */
uint32_t EEPROM_TypeB_write(uint16_t identifier, uint32_t data);

/**
 *  @brief      Store provided data and identifier to the specified data item
 *
 *  The function brings together the data and the identifier into a new data
 *  item at the specified location.
 *
 *  @param[in]  identifier          Used to tag and distinguish data
 *  @param[in]  data                User's data
 *  @param[in]  groupNum            Specifies the group number to write
 *  @param[in]  dataItemNum         Specifies the number of the data item to write
 *
 *  @return     Whether or not the function succeeded
 *
 *  @retval     EEPROM_EMULATION_WRITE_OK        Program was successful
 *  @retval     EEPROM_EMULATION_FORMAT_ERROR    Next address was not erased
 *  @retval     EEPROM_EMULATION_WRITE_ERROR     Writing new data item is not successful
 */
uint32_t EEPROM_TypeB_writeDataItem(uint16_t identifier, uint32_t data,
    uint16_t groupNum, uint16_t dataItemNum);

/**
 *  @brief      Transfer the data items to next group
 *
 *  The function will transfer the latest data items from one group to next group.
 *  Not all items will be transfer. Only the latest data item corresponding to each
 *  identifier is transferred.
 *
 *  @param[in]  groupNum            Specifies the group number to be transferred
 *
 *  @return     Whether or not the function succeeded
 *
 *  @retval     EEPROM_EMULATION_TRANSFER_OK       Transfer was successful
 *  @retval     EEPROM_EMULATION_TRANSFER_ERROR    Transfer was not successful
 *
 *  @post        When the transfer is over, the group will be marked as 'Erasing'
 *               and gEEPROMTypeBEraseFlag is set. The user should erase the group before all
 *               groups are full. Refer to @ref EEPROM_TypeB_eraseGroup.
 */
uint32_t EEPROM_TypeB_transferDataItem(uint16_t groupNum);

/**
 *  @brief      Read the latest data item based on the identifier
 *
 *  The function is used to read the data item that matches the input identifier.
 *
 *  @param[in]  identifier          Used to tag and distinguish data
 *
 *  @return     If data item exists, the data will be returned and gEEPROMTypeBSearchFlag is set.
 *              If not, gEEPROMTypeBSearchFlag is clear.
 *
 *  @post       gEEPROMTypeBSearchFlag shows whether item is found and read correctly
 */
uint32_t EEPROM_TypeB_readDataItem(uint16_t identifier);

/**
 *  @brief      Find the latest data item based on the identifier
 *
 *  The function is used to search for data items within the specified group.
 *
 *  @param[in]  identifier          Used to tag and distinguish data
 *  @param[in]  groupNum            Specifies the group number to search
 *  @param[in]  dataItemNum         Specifies the number of the last data item
 *                                  to search. To search the whole group, it can
 *                                  be set to the maximum value.
 *
 *  @return     If the data item is found, the address will be returned. If not,
 *              EEPROM_EMULATION_FINDITEM_NOT_FOUND will be returned.
 */
uint32_t EEPROM_TypeB_findDataItem(
    uint16_t identifier, uint16_t groupNum, uint16_t dataItemNum);

/**
 *  @brief      Initialize the specified area in flash
 *
 *  The function will first search the active group and check the format
 *  at the specified area. If active group exists, it will erase other groups
 *  and transfer the active group. If format is not correct, it will repair
 *  the format.
 *
 *  @return     Whether or not the function succeeded
 *
 *  @retval     EEPROM_EMULATION_INIT_OK                  Initialize was successful
 *  @retval     EEPROM_EMULATION_INIT_OK_FORMAT_REPAIR    Initialize with format repair
 *  @retval     EEPROM_EMULATION_INIT_OK_ALL_ERASE        Initialize with all erase
 *  @retval     EEPROM_EMULATION_INIT_ERROR               Initialize met error
 *  @retval     EEPROM_EMULATION_TRANSFER_ERROR           transfer was not successful
 *
 *  NOTE:       The user can choose whether or not to enable format repair by setting
 *              or clearing EEPROM_EMULATION_REPAIR_ENABLE.
 */
uint32_t EEPROM_TypeB_init(void);

/**
 *  @brief      Search the active group and check the format
 *
 *  The function will traverse groups' header. It will check if active group exists and
 *  if there is an error.
 *
 *  @return     The result of the format check
 *
 *  @retval     CHECK_ONE_ACTIVE_GROUP             Active
 *  @retval     CHECK_NO_ACTIVE_ONE_ERROR_GROUP    Next address was not erased
 *  @retval     CHECK_NO_ACTIVE_NO_ERROR_GROUP     Writing new data item is not successful
 *
 *  @post       The function is called in EEPROM_TypeB_init(). According to the result
 *              of format check, take different initiatives to ensure that the format is right.
 */
uint32_t EEPROM_TypeB_checkFormat(void);

/**
 *  @brief      Erases the 'Erasing' group
 *
 *  @return     Whether or not the function succeeded
 *
 *  @retval     false   function didn't succeed
 *  @retval     true    function was successful
 *
 *  NOTE:       When the group is full, transfer is performed first,
 *              then the full group will be marked as 'Erasing',
 *              waiting to be erased.
 */
bool EEPROM_TypeB_eraseGroup(void);

/**
 *  @brief      Erases groups other than the active group
 *
 *  @return     Whether or not the function succeeded
 *
 *  @retval     false   function didn't succeed
 *  @retval     true    function was successful
 */
bool EEPROM_TypeB_eraseNonActiveGroups(void);

/**
 *  @brief      Erase all groups used by EEPROM emulation
 *
 *  @return     Whether or not the function succeeded
 *
 *  @retval     false   function didn't succeed
 *  @retval     true    function was successful
 */
bool EEPROM_TypeB_eraseAllGroups(void);

#endif /* EEPROM_EMULATION_TYPE_B_H_ */
/** @}*/
