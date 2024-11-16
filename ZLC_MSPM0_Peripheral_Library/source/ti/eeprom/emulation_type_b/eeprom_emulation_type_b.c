/*
 * Copyright (c) 2021, Texas Instruments Incorporated
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

#include "eeprom_emulation_type_b.h"

/* 2 global variables about active group */
uint16_t gActiveDataItemNum = EEPROM_EMULATION_ACTIVE_DATAITEM_NUM_MIN;
uint16_t gActiveGroupNum    = EEPROM_EMULATION_ACTIVE_GROUP_NUM_MIN;

/* 2 global variables about format  */
bool gEEPROMTypeBSearchFlag = 0;
bool gEEPROMTypeBEraseFlag  = 0;

uint32_t EEPROM_TypeB_write(uint16_t Identifier, uint32_t Data)
{
    uint32_t EEPROMEmulationState;

    /* Call EEPROM_TypeB_writeDataItem to write one data item */
    EEPROMEmulationState = EEPROM_TypeB_writeDataItem(
        Identifier, Data, gActiveGroupNum, gActiveDataItemNum);
    if (EEPROMEmulationState != EEPROM_EMULATION_WRITE_OK) {
        return EEPROM_EMULATION_WRITE_ERROR;
    }

    /* Update gActiveGroupNum, gActiveDataItemNum*/
    gActiveDataItemNum++;
    if (gActiveDataItemNum >= EEPROM_EMULATION_ACTIVE_DATAITEM_NUM_MAX) {
        gActiveDataItemNum = EEPROM_EMULATION_ACTIVE_DATAITEM_NUM_MIN;
        /* If group is full, call EEPROM_TypeB_transferDataItem to transfer the latest data items */
        EEPROMEmulationState = EEPROM_TypeB_transferDataItem(gActiveGroupNum);
        if (EEPROMEmulationState != EEPROM_EMULATION_TRANSFER_OK) {
            return EEPROM_EMULATION_TRANSFER_ERROR;
        }
    }
    return EEPROM_EMULATION_WRITE_OK;
}
uint32_t EEPROM_TypeB_writeDataItem(uint16_t Identifier, uint32_t Data,
    uint16_t GroupNum, uint16_t DataItemNum)
{
    uint32_t WriteGroupAddress;
    uint32_t WriteDataItemAddress;
    uint32_t* WriteDataItemPointer;
    uint32_t HeaderArray64[] = {0x00000000, 0xffffffff};
    uint32_t ItemArray64[]   = {0xffffffff, 0xffffffff};
    DL_FLASHCTL_COMMAND_STATUS FlashAPIState;

    /* Point to the next address */
    WriteGroupAddress =
        EEPROM_EMULATION_ADDRESS +
        EEPROM_EMULATION_SECTOR_INGROUP_ACCOUNT * (GroupNum - 1) * 1024;
    WriteDataItemAddress = WriteGroupAddress + DataItemNum * 8 + 8;

    /* Check next address */
    WriteDataItemPointer = (void*) WriteDataItemAddress;
    if (*WriteDataItemPointer != 0xffffffff) {
        return EEPROM_EMULATION_FORMAT_ERROR;
    }

    /* If all group is empty, update the group header to active */
    if (DataItemNum == 0) {
        DL_FlashCTL_unprotectSector(
            FLASHCTL, WriteGroupAddress, DL_FLASHCTL_REGION_SELECT_MAIN);
#ifdef __MSPM0_HAS_ECC__
        FlashAPIState = DL_FlashCTL_programMemoryFromRAM64WithECCGenerated(
            FLASHCTL, WriteGroupAddress, &HeaderArray64[0]);
#else
        FlashAPIState = DL_FlashCTL_programMemoryFromRAM64(
            FLASHCTL, WriteGroupAddress, &HeaderArray64[0]);
#endif
        if (FlashAPIState == DL_FLASHCTL_COMMAND_STATUS_FAILED)
            return EEPROM_EMULATION_WRITE_ERROR;
    }

    /* Combines data and identifiers into new data item */
    ItemArray64[0] = ((uint32_t) Identifier) + 0xffff0000;
    ItemArray64[1] = Data;
    DL_FlashCTL_unprotectSector(
        FLASHCTL, WriteDataItemAddress, DL_FLASHCTL_REGION_SELECT_MAIN);
#ifdef __MSPM0_HAS_ECC__
    FlashAPIState = DL_FlashCTL_programMemoryFromRAM64WithECCGenerated(
        FLASHCTL, WriteDataItemAddress, &ItemArray64[0]);
#else
    FlashAPIState = DL_FlashCTL_programMemoryFromRAM64(
        FLASHCTL, WriteDataItemAddress, &ItemArray64[0]);
#endif
    if (FlashAPIState == DL_FLASHCTL_COMMAND_STATUS_FAILED)
        return EEPROM_EMULATION_WRITE_ERROR;

    /* Set the end of write flag */
    ItemArray64[0] = ItemArray64[0] & 0x0000ffff;
    DL_FlashCTL_unprotectSector(
        FLASHCTL, WriteDataItemAddress, DL_FLASHCTL_REGION_SELECT_MAIN);
    FlashAPIState = DL_FlashCTL_programMemoryFromRAM64(
        FLASHCTL, WriteDataItemAddress, &ItemArray64[0]);
    if (FlashAPIState == DL_FLASHCTL_COMMAND_STATUS_FAILED)
        return EEPROM_EMULATION_WRITE_ERROR;

    return EEPROM_EMULATION_WRITE_OK;
}

uint32_t EEPROM_TypeB_transferDataItem(uint16_t GroupNum)
{
    uint32_t TransferGroupAddress;
    uint32_t TransferDataItemAddress;
    uint32_t* TransferDataItemPointer;
    uint32_t TransferDataItemHeader;
    uint16_t TransferIdentifier;
    uint32_t TransferData;
    uint16_t DataItemCount;

    uint32_t ReceivingGroupAddress;
    uint32_t ReceivingDataItemAddress;
    uint32_t* ReceivingDataItemPointer;
    uint16_t ReceivingGroupNum;
    uint16_t ReceivingDataItemNum;

    uint32_t HeaderArray64[] = {0x0000ffff, 0xffffffff};
    uint32_t ItemArray64[]   = {0xffffffff, 0xffffffff};
    DL_FLASHCTL_COMMAND_STATUS FlashAPIState;
    uint32_t EEPROMEmulationState;

    /* Set variables for receiving group */
    if (GroupNum == EEPROM_EMULATION_ACTIVE_GROUP_NUM_MAX) {
        ReceivingGroupNum = EEPROM_EMULATION_ACTIVE_GROUP_NUM_MIN;
    } else {
        ReceivingGroupNum = GroupNum + 1;
    }
    ReceivingDataItemNum = 0;
    ReceivingGroupAddress =
        EEPROM_EMULATION_ADDRESS + EEPROM_EMULATION_SECTOR_INGROUP_ACCOUNT *
                                       (ReceivingGroupNum - 1) * 1024;

    /* Update receiving group's header */
    DL_FlashCTL_unprotectSector(
        FLASHCTL, ReceivingGroupAddress, DL_FLASHCTL_REGION_SELECT_MAIN);
#ifdef __MSPM0_HAS_ECC__
    FlashAPIState = DL_FlashCTL_programMemoryFromRAM64WithECCGenerated(
        FLASHCTL, ReceivingGroupAddress, &HeaderArray64[0]);
#else
    FlashAPIState = DL_FlashCTL_programMemoryFromRAM64(
        FLASHCTL, ReceivingGroupAddress, &HeaderArray64[0]);
#endif
    if (FlashAPIState == DL_FLASHCTL_COMMAND_STATUS_FAILED)
        return EEPROM_EMULATION_TRANSFER_ERROR;

    /* Set variables for transfer group */
    TransferGroupAddress =
        EEPROM_EMULATION_ADDRESS +
        EEPROM_EMULATION_SECTOR_INGROUP_ACCOUNT * (GroupNum - 1) * 1024;
    TransferDataItemAddress =
        TransferGroupAddress + (EEPROM_EMULATION_DATAITEM_ACCOUNT - 1) * 8 + 8;

    /* Traverses the transfer group from the back to the front */
    DataItemCount = EEPROM_EMULATION_DATAITEM_ACCOUNT;
    while (DataItemCount > 0) {
        TransferDataItemPointer = (void*) TransferDataItemAddress;
        TransferDataItemHeader  = *TransferDataItemPointer;
        /* check if end of write flag is set */
        if ((TransferDataItemHeader & 0xffff0000) == 0x00000000) {
            TransferIdentifier = (uint16_t) TransferDataItemHeader;
            /* call EEPROM_TypeB_findDataItem to check if current item exists in receiving group */
            if (EEPROM_TypeB_findDataItem(TransferIdentifier,
                    ReceivingGroupNum, ReceivingDataItemNum) ==
                EEPROM_EMULATION_FINDITEM_NOT_FOUND) {
                /* If not, transfer current item to receiving group */
                TransferDataItemAddress += 4;
                TransferDataItemPointer = (void*) TransferDataItemAddress;
                TransferData            = *TransferDataItemPointer;
                EEPROMEmulationState =
                    EEPROM_TypeB_writeDataItem(TransferIdentifier,
                        TransferData, ReceivingGroupNum, ReceivingDataItemNum);
                if (EEPROMEmulationState != EEPROM_EMULATION_WRITE_OK) {
                    return EEPROM_EMULATION_TRANSFER_ERROR;
                }
                ReceivingDataItemNum++;
                TransferDataItemAddress -= 4;
            }
        }
        TransferDataItemAddress -= 8;
        DataItemCount--;
    }
    /* Update gActiveDataItemNum, gActiveGroupNum */
    gActiveDataItemNum = ReceivingDataItemNum;
    gActiveGroupNum    = ReceivingGroupNum;

    /* Update receiving group's header to 'Active' */
    HeaderArray64[0] = 0x00000000;
    DL_FlashCTL_unprotectSector(
        FLASHCTL, ReceivingGroupAddress, DL_FLASHCTL_REGION_SELECT_MAIN);
#ifdef __MSPM0_HAS_ECC__
    FlashAPIState = DL_FlashCTL_programMemoryFromRAM64WithECCGenerated(
        FLASHCTL, ReceivingGroupAddress, &HeaderArray64[0]);
#else
    FlashAPIState = DL_FlashCTL_programMemoryFromRAM64(
        FLASHCTL, ReceivingGroupAddress, &HeaderArray64[0]);
#endif
    if (FlashAPIState == DL_FLASHCTL_COMMAND_STATUS_FAILED)
        return EEPROM_EMULATION_TRANSFER_ERROR;

    /* Update transfer group's header to 'Erasing' */
    HeaderArray64[1] = 0x00000000;
    DL_FlashCTL_unprotectSector(
        FLASHCTL, TransferGroupAddress, DL_FLASHCTL_REGION_SELECT_MAIN);
#ifdef __MSPM0_HAS_ECC__
    FlashAPIState = DL_FlashCTL_programMemoryFromRAM64WithECCGenerated(
        FLASHCTL, TransferGroupAddress, &HeaderArray64[0]);
#else
    FlashAPIState = DL_FlashCTL_programMemoryFromRAM64(
        FLASHCTL, TransferGroupAddress, &HeaderArray64[0]);
#endif
    if (FlashAPIState == DL_FLASHCTL_COMMAND_STATUS_FAILED)
        return EEPROM_EMULATION_TRANSFER_ERROR;

    /* Set gEEPROMTypeBEraseFlag to indicate tha there are groups waiting to be erased */
    gEEPROMTypeBEraseFlag = 1;

    return EEPROM_EMULATION_TRANSFER_OK;
}

uint32_t EEPROM_TypeB_readDataItem(uint16_t Identifier)
{
    uint32_t* ReadDataItemPointer;
    uint32_t ReadDataItemAddress;

    /* Call EEPROM_TypeB_findDataItem to find the item with right identifier */
    ReadDataItemAddress = EEPROM_TypeB_findDataItem(
        Identifier, gActiveGroupNum, gActiveDataItemNum);

    if (ReadDataItemAddress != EEPROM_EMULATION_FINDITEM_NOT_FOUND) {
        /* If the item is found, read the data */
        ReadDataItemAddress += 4;
        ReadDataItemPointer    = (void*) ReadDataItemAddress;
        gEEPROMTypeBSearchFlag = 1;
        return *ReadDataItemPointer;
    } else {
        /* If the item is not found, clear the flag*/
        gEEPROMTypeBSearchFlag = 0;
        return 0;
    }
}

uint32_t EEPROM_TypeB_findDataItem(
    uint16_t Identifier, uint16_t GroupNum, uint16_t DataItemNum)
{
    uint32_t SearchGroupAddress;
    uint32_t SearchDataItemAddress;
    uint32_t* SearchDataItemPointer;
    uint16_t DataItemCount;

    /* Point to the last item */
    SearchGroupAddress =
        EEPROM_EMULATION_ADDRESS +
        EEPROM_EMULATION_SECTOR_INGROUP_ACCOUNT * (GroupNum - 1) * 1024;
    SearchDataItemAddress = SearchGroupAddress + (DataItemNum - 1) * 8 + 8;

    /* Traverses from the back to the front */
    DataItemCount = DataItemNum;
    while (DataItemCount > 0) {
        SearchDataItemPointer = (void*) SearchDataItemAddress;
        if (*SearchDataItemPointer == ((uint32_t) Identifier)) {
            return SearchDataItemAddress;
        }
        SearchDataItemAddress -= 8;
        DataItemCount--;
    }
    /* If item is not found, return the error message */
    return EEPROM_EMULATION_FINDITEM_NOT_FOUND;
}

uint32_t EEPROM_TypeB_init(void)
{
    uint32_t FormatCheckState, EEPROMEmulationState;
    bool FlashAPIState;

    /* Call EEPROM_TypeB_checkFormat to check the format */
    FormatCheckState = EEPROM_TypeB_checkFormat();

    /* According to the result of format check, take different initiatives */
    if (FormatCheckState == CHECK_ONE_ACTIVE_GROUP) {
        /* Erase other groups */
        FlashAPIState = EEPROM_TypeB_eraseNonActiveGroups();
        if (FlashAPIState == false) return EEPROM_EMULATION_INIT_ERROR;

        /* Transfer the current group */
        EEPROMEmulationState = EEPROM_TypeB_transferDataItem(gActiveGroupNum);
        if (EEPROMEmulationState != EEPROM_EMULATION_TRANSFER_OK) {
            return EEPROM_EMULATION_TRANSFER_ERROR;
        }

        /* Erase last group */
        FlashAPIState = EEPROM_TypeB_eraseGroup();
        if (FlashAPIState == false) return EEPROM_EMULATION_INIT_ERROR;
        gEEPROMTypeBEraseFlag = 0;
        return EEPROM_EMULATION_INIT_OK;
    } else if (FormatCheckState == CHECK_NO_ACTIVE_ONE_ERROR_GROUP &&
               EEPROM_EMULATION_REPAIR_ENABLE) {
        /* Erase other groups */
        FlashAPIState = EEPROM_TypeB_eraseNonActiveGroups();
        if (FlashAPIState == false) return EEPROM_EMULATION_INIT_ERROR;

        /* Transfer the current group */
        EEPROMEmulationState = EEPROM_TypeB_transferDataItem(gActiveGroupNum);
        if (EEPROMEmulationState != EEPROM_EMULATION_TRANSFER_OK) {
            return EEPROM_EMULATION_TRANSFER_ERROR;
        }

        /* Erase last group */
        FlashAPIState = EEPROM_TypeB_eraseGroup();
        if (FlashAPIState == false) return EEPROM_EMULATION_INIT_ERROR;
        gEEPROMTypeBEraseFlag = 0;
        return EEPROM_EMULATION_INIT_OK_FORMAT_REPAIR;
    } else {
        /* Erase all groups */
        FlashAPIState = EEPROM_TypeB_eraseAllGroups();
        if (FlashAPIState == false) return EEPROM_EMULATION_INIT_ERROR;
        gEEPROMTypeBEraseFlag = 0;

        /* Update gActiveDataItemNum, gActiveGroupNum */
        gActiveDataItemNum = EEPROM_EMULATION_ACTIVE_DATAITEM_NUM_MIN;
        gActiveGroupNum    = EEPROM_EMULATION_ACTIVE_GROUP_NUM_MIN;
        return EEPROM_EMULATION_INIT_OK_ALL_ERASE;
    }
}

uint32_t EEPROM_TypeB_checkFormat(void)
{
    uint16_t CheckGroupNum;
    uint16_t ErrorGroupNum;
    uint32_t Temp0, Temp1;
    bool CheckState, FormatErrorFlag;
    uint32_t CheckGroupAddress;
    uint32_t* CheckGroupPointer;

    /* Clear flag */
    CheckState      = 0;
    FormatErrorFlag = 0;

    /* Traverse groups' header to search the active record and check the format */
    for (CheckGroupNum = EEPROM_EMULATION_ACTIVE_GROUP_NUM_MIN;
         CheckGroupNum <= EEPROM_EMULATION_ACTIVE_GROUP_NUM_MAX;
         CheckGroupNum++) {
        /* Read the header*/
        CheckGroupAddress = EEPROM_EMULATION_ADDRESS +
                            EEPROM_EMULATION_SECTOR_INGROUP_ACCOUNT *
                                (CheckGroupNum - 1) * 1024;
        CheckGroupPointer = (void*) CheckGroupAddress;
        Temp0             = *CheckGroupPointer;
        CheckGroupPointer = (void*) (CheckGroupAddress + 4);
        Temp1             = *CheckGroupPointer;
        if (Temp0 == 0xffffffff && Temp1 == 0xffffffff)  //Erased
        {
        } else if (Temp0 == 0x00000000 && Temp1 == 0xffffffff)  //Active
        {
            /* If active group is found, record the gActiveGroupNum */
            gActiveGroupNum = CheckGroupNum;
            CheckState      = 1;
        } else if (Temp0 == 0x0000ffff && Temp1 == 0xffffffff)  //Receiving
        {
        } else if (Temp1 == 0x00000000)  //Erasing
        {
        } else {
            /* If error group is found, record the ErrorGroupNum */
            ErrorGroupNum   = CheckGroupNum;
            FormatErrorFlag = 1;
        }
    }

    if (CheckState == 1 && FormatErrorFlag == 0) {
        /* Active group exists */
        return CHECK_ONE_ACTIVE_GROUP;
    } else if (CheckState == 0 && FormatErrorFlag == 1) {
        /* Active group does not exist, and error group exists */
        gActiveGroupNum = ErrorGroupNum;
        return CHECK_NO_ACTIVE_ONE_ERROR_GROUP;
    } else {
        /* Other cases */
        return CHECK_NO_ACTIVE_NO_ERROR_GROUP;
    }
}

bool EEPROM_TypeB_eraseGroup(void)
{
    uint16_t EraseGroupNum;
    uint32_t Temp1;
    uint32_t EraseGroupAddress, EraseSectorAddress;
    uint32_t* EraseGroupPointer;
    DL_FLASHCTL_COMMAND_STATUS FlashAPIState;
    uint16_t num;
    for (EraseGroupNum = EEPROM_EMULATION_ACTIVE_GROUP_NUM_MIN;
         EraseGroupNum <= EEPROM_EMULATION_ACTIVE_GROUP_NUM_MAX;
         EraseGroupNum++) {
        EraseGroupAddress = EEPROM_EMULATION_ADDRESS +
                            EEPROM_EMULATION_SECTOR_INGROUP_ACCOUNT *
                                (EraseGroupNum - 1) * 1024;
        EraseGroupPointer = (void*) (EraseGroupAddress + 4);
        Temp1             = *EraseGroupPointer;
        if (Temp1 == 0x00000000) {
            for (num = 0; num < EEPROM_EMULATION_SECTOR_INGROUP_ACCOUNT;
                 num++) {
                EraseSectorAddress = EraseGroupAddress + 1024 * num;
                DL_FlashCTL_unprotectSector(FLASHCTL, EraseSectorAddress,
                    DL_FLASHCTL_REGION_SELECT_MAIN);
                FlashAPIState = DL_FlashCTL_eraseMemoryFromRAM(FLASHCTL,
                    EraseSectorAddress, DL_FLASHCTL_COMMAND_SIZE_SECTOR);
                if (FlashAPIState == DL_FLASHCTL_COMMAND_STATUS_FAILED)
                    return false;
            }
        }
    }
    return true;
}

bool EEPROM_TypeB_eraseNonActiveGroups(void)
{
    uint16_t EraseGroupNum;
    uint32_t EraseGroupAddress, EraseSectorAddress;
    DL_FLASHCTL_COMMAND_STATUS FlashAPIState;
    uint16_t num;
    for (EraseGroupNum = EEPROM_EMULATION_ACTIVE_GROUP_NUM_MIN;
         EraseGroupNum <= EEPROM_EMULATION_ACTIVE_GROUP_NUM_MAX;
         EraseGroupNum++) {
        if (EraseGroupNum != gActiveGroupNum) {
            EraseGroupAddress = EEPROM_EMULATION_ADDRESS +
                                EEPROM_EMULATION_SECTOR_INGROUP_ACCOUNT *
                                    (EraseGroupNum - 1) * 1024;
            for (num = 0; num < EEPROM_EMULATION_SECTOR_INGROUP_ACCOUNT;
                 num++) {
                EraseSectorAddress = EraseGroupAddress + 1024 * num;
                DL_FlashCTL_unprotectSector(FLASHCTL, EraseSectorAddress,
                    DL_FLASHCTL_REGION_SELECT_MAIN);
                FlashAPIState = DL_FlashCTL_eraseMemoryFromRAM(FLASHCTL,
                    EraseSectorAddress, DL_FLASHCTL_COMMAND_SIZE_SECTOR);
                if (FlashAPIState == DL_FLASHCTL_COMMAND_STATUS_FAILED)
                    return false;
            }
        }
    }
    return true;
}

bool EEPROM_TypeB_eraseAllGroups(void)
{
    uint16_t EraseGroupNum;
    uint32_t EraseGroupAddress, EraseSectorAddress;
    DL_FLASHCTL_COMMAND_STATUS FlashAPIState;
    uint16_t num;
    for (EraseGroupNum = EEPROM_EMULATION_ACTIVE_GROUP_NUM_MIN;
         EraseGroupNum <= EEPROM_EMULATION_ACTIVE_GROUP_NUM_MAX;
         EraseGroupNum++) {
        EraseGroupAddress = EEPROM_EMULATION_ADDRESS +
                            EEPROM_EMULATION_SECTOR_INGROUP_ACCOUNT *
                                (EraseGroupNum - 1) * 1024;
        for (num = 0; num < EEPROM_EMULATION_SECTOR_INGROUP_ACCOUNT; num++) {
            EraseSectorAddress = EraseGroupAddress + 1024 * num;
            DL_FlashCTL_unprotectSector(
                FLASHCTL, EraseSectorAddress, DL_FLASHCTL_REGION_SELECT_MAIN);
            FlashAPIState = DL_FlashCTL_eraseMemoryFromRAM(
                FLASHCTL, EraseSectorAddress, DL_FLASHCTL_COMMAND_SIZE_SECTOR);
            if (FlashAPIState == DL_FLASHCTL_COMMAND_STATUS_FAILED)
                return false;
        }
    }
    return true;
}
