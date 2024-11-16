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

#include "eeprom_emulation_type_a.h"
/* 4 global variables about active record  */
uint32_t gActiveRecordAddress = EEPROM_EMULATION_ADDRESS;
uint32_t gNextRecordAddress   = EEPROM_EMULATION_ADDRESS;
uint16_t gActiveRecordNum     = 0;
uint16_t gActiveSectorNum     = EEPROM_EMULATION_ACTIVE_SECTOR_NUM_MIN;
/* 3 global variables about format  */
bool gEEPROMTypeASearchFlag      = 0;
bool gEEPROMTypeAEraseFlag       = 0;
bool gEEPROMTypeAFormatErrorFlag = 0;

uint32_t EEPROM_TypeA_writeData(uint32_t *data)
{
    uint32_t *NextRecordPointer = (void *) gNextRecordAddress;
    uint32_t HeaderArray64[]    = {0x0000ffff, 0xffffffff};
    DL_FLASHCTL_COMMAND_STATUS FlashAPIState;

    /* Check next address*/
    if (*NextRecordPointer != 0xffffffff) {
        return EEPROM_EMULATION_FORMAT_ERROR;
    }

    /* Set the new record's header to Recording */
    DL_FlashCTL_unprotectSector(
        FLASHCTL, gNextRecordAddress, DL_FLASHCTL_REGION_SELECT_MAIN);
#ifdef __MSPM0_HAS_ECC__
    FlashAPIState = DL_FlashCTL_programMemoryFromRAM64WithECCGenerated(
        FLASHCTL, gNextRecordAddress, &HeaderArray64[0]);
#else
    FlashAPIState = DL_FlashCTL_programMemoryFromRAM64(
        FLASHCTL, gNextRecordAddress, &HeaderArray64[0]);
#endif
    if (FlashAPIState == DL_FLASHCTL_COMMAND_STATUS_FAILED)
        return EEPROM_EMULATION_WRITE_ERROR;

        /* Program data to the new record */
#ifdef __MSPM0_HAS_ECC__
    FlashAPIState = DL_FlashCTL_programMemoryBlockingFromRAM64WithECCGenerated(
        FLASHCTL, (gNextRecordAddress + 8), data,
        EEPROM_EMULATION_DATA_SIZE / sizeof(uint32_t),
        DL_FLASHCTL_REGION_SELECT_MAIN);
#else
    FlashAPIState =
        DL_FlashCTL_programMemoryFromRAM(FLASHCTL, (gNextRecordAddress + 8),
            data, EEPROM_EMULATION_DATA_SIZE / sizeof(uint32_t),
            DL_FLASHCTL_REGION_SELECT_MAIN);

#endif
    if (FlashAPIState == DL_FLASHCTL_COMMAND_STATUS_FAILED)
        return EEPROM_EMULATION_WRITE_ERROR;

    /* Set the new record's header to Active */
    HeaderArray64[1] = 0x0000ffff;
    DL_FlashCTL_unprotectSector(
        FLASHCTL, gNextRecordAddress, DL_FLASHCTL_REGION_SELECT_MAIN);
    FlashAPIState = DL_FlashCTL_programMemoryFromRAM64(
        FLASHCTL, gNextRecordAddress, &HeaderArray64[0]);
    if (FlashAPIState == DL_FLASHCTL_COMMAND_STATUS_FAILED)
        return EEPROM_EMULATION_WRITE_ERROR;

    /* Update gActiveRecordNum, gActiveSectorNum*/
    gActiveRecordNum++;
    if (gActiveRecordNum > EEPROM_EMULATION_ACTIVE_RECORD_NUM_MAX) {
        gActiveRecordNum      = EEPROM_EMULATION_ACTIVE_RECORD_NUM_MIN;
        gEEPROMTypeAEraseFlag = 1;
        gActiveSectorNum++;
        if (gActiveSectorNum > EEPROM_EMULATION_ACTIVE_SECTOR_NUM_MAX) {
            gActiveSectorNum = EEPROM_EMULATION_ACTIVE_SECTOR_NUM_MIN;
        }
    }

    /* if last active record exists, set the last active record's header to Used */
    if (gEEPROMTypeASearchFlag == 1) {
        HeaderArray64[0] = 0x00000000;
        DL_FlashCTL_unprotectSector(
            FLASHCTL, gActiveRecordAddress, DL_FLASHCTL_REGION_SELECT_MAIN);
        FlashAPIState = DL_FlashCTL_programMemoryFromRAM64(
            FLASHCTL, gActiveRecordAddress, &HeaderArray64[0]);
        if (FlashAPIState == DL_FLASHCTL_COMMAND_STATUS_FAILED)
            return EEPROM_EMULATION_WRITE_ERROR;
    } else {
        gEEPROMTypeASearchFlag = 1;
    }

    /* Update gActiveRecordAddress, gNextRecordAddress*/
    gActiveRecordAddress = gNextRecordAddress;
    if (gActiveRecordNum >= EEPROM_EMULATION_ACTIVE_RECORD_NUM_MAX &&
        gActiveSectorNum >= EEPROM_EMULATION_ACTIVE_SECTOR_NUM_MAX) {
        gNextRecordAddress = EEPROM_EMULATION_ADDRESS;
    } else {
        gNextRecordAddress =
            gActiveRecordAddress + EEPROM_EMULATION_RECORD_SIZE;
    }
    return EEPROM_EMULATION_WRITE_OK;
}

uint32_t EEPROM_TypeA_init(uint32_t *data)
{
    bool FlashAPIState;
    /* Search the active record and check the format*/
    EEPROM_TypeA_searchCheck();

    if (gEEPROMTypeASearchFlag == 1) {
        /* If active record is found, copy the active record's data to buffer in RAM*/
        EEPROM_TypeA_readData(data);
        if (gEEPROMTypeAFormatErrorFlag == 1) {
            /* If active record exists and format is not correct, repair the format*/
            FlashAPIState = EEPROM_TypeA_repairFormat(data);
            if (FlashAPIState == false) return EEPROM_EMULATION_INIT_ERROR;
            gEEPROMTypeAFormatErrorFlag = 0;
        } else {
            /* If active record exists and format is correct, just erase other sectors*/
            FlashAPIState = EEPROM_TypeA_eraseNonActiveSectors();
            if (FlashAPIState == false) return EEPROM_EMULATION_INIT_ERROR;
        }
    } else {
        /* If active record doesn't exist, erase all sectors, set global variables*/
        FlashAPIState = EEPROM_TypeA_eraseAllSectors();
        if (FlashAPIState == false) return EEPROM_EMULATION_INIT_ERROR;
        gActiveRecordAddress = EEPROM_EMULATION_ADDRESS;
        gNextRecordAddress   = EEPROM_EMULATION_ADDRESS;
        gActiveRecordNum     = 0;
        gActiveSectorNum     = EEPROM_EMULATION_ACTIVE_SECTOR_NUM_MIN;
    }
    return EEPROM_EMULATION_INIT_OK;
}

void EEPROM_TypeA_readData(uint32_t *data)
{
    uint32_t *ReadRecordPointer;
    uint32_t ReadRecordAddress;

    ReadRecordAddress = gActiveRecordAddress + 8;
    for (uint16_t num = 0; num < EEPROM_EMULATION_DATA_SIZE / sizeof(uint32_t);
         num++) {
        ReadRecordPointer = (void *) ReadRecordAddress;
        data[num]         = *ReadRecordPointer;
        ReadRecordAddress += 4;
    }
}

bool EEPROM_TypeA_repairFormat(uint32_t *data)
{
    uint32_t FormatRepairAddress;
    uint32_t EraseSectorAddress;
    uint32_t HeaderArray64[] = {0x0000ffff, 0xffffffff};
    DL_FLASHCTL_COMMAND_STATUS FlashAPIState;

    /* Firstly erase other sectors*/
    FlashAPIState = EEPROM_TypeA_eraseNonActiveSectors();
    if (FlashAPIState == DL_FLASHCTL_COMMAND_STATUS_FAILED) return false;

    /* Set pointer to next sector's beginning*/
    if (gActiveSectorNum == EEPROM_EMULATION_ACTIVE_SECTOR_NUM_MAX) {
        FormatRepairAddress = EEPROM_EMULATION_ADDRESS;
    } else {
        FormatRepairAddress =
            EEPROM_EMULATION_ADDRESS + gActiveSectorNum * 1024;
    }

    /* Set the new record's header to Recording */
    DL_FlashCTL_unprotectSector(
        FLASHCTL, FormatRepairAddress, DL_FLASHCTL_REGION_SELECT_MAIN);
#ifdef __MSPM0_HAS_ECC__
    FlashAPIState = DL_FlashCTL_programMemoryFromRAM64WithECCGenerated(
        FLASHCTL, FormatRepairAddress, &HeaderArray64[0]);
#else
    FlashAPIState = DL_FlashCTL_programMemoryFromRAM64(
        FLASHCTL, FormatRepairAddress, &HeaderArray64[0]);
#endif
    if (FlashAPIState == DL_FLASHCTL_COMMAND_STATUS_FAILED) return false;

        /* Copy the data in RAM to the new record*/
#ifdef __MSPM0_HAS_ECC__
    FlashAPIState = DL_FlashCTL_programMemoryBlockingFromRAM64WithECCGenerated(
        FLASHCTL, (FormatRepairAddress + 8), data,
        EEPROM_EMULATION_DATA_SIZE / sizeof(uint32_t),
        DL_FLASHCTL_REGION_SELECT_MAIN);
#else
    FlashAPIState =
        DL_FlashCTL_programMemoryFromRAM(FLASHCTL, (gNextRecordAddress + 8),
            data, EEPROM_EMULATION_DATA_SIZE / sizeof(uint32_t),
            DL_FLASHCTL_REGION_SELECT_MAIN);
#endif

    if (FlashAPIState == DL_FLASHCTL_COMMAND_STATUS_FAILED) return false;

    /* Set the new record's header to Active */
    HeaderArray64[1] = 0x0000ffff;
    DL_FlashCTL_unprotectSector(
        FLASHCTL, FormatRepairAddress, DL_FLASHCTL_REGION_SELECT_MAIN);
    FlashAPIState = DL_FlashCTL_programMemoryFromRAM64(
        FLASHCTL, FormatRepairAddress, &HeaderArray64[0]);
    if (FlashAPIState == DL_FLASHCTL_COMMAND_STATUS_FAILED) return false;

    /* Update 4 global variables about active record */
    gActiveRecordNum = EEPROM_EMULATION_ACTIVE_RECORD_NUM_MIN;
    if (gActiveSectorNum == EEPROM_EMULATION_ACTIVE_SECTOR_NUM_MAX) {
        gActiveSectorNum = EEPROM_EMULATION_ACTIVE_SECTOR_NUM_MIN;
    } else {
        gActiveSectorNum += 1;
    }
    gActiveRecordAddress = FormatRepairAddress;
    gNextRecordAddress   = gActiveRecordAddress + EEPROM_EMULATION_RECORD_SIZE;

    /* Erase the last sector */
    FlashAPIState = EEPROM_TypeA_eraseLastSector();
    if (FlashAPIState == DL_FLASHCTL_COMMAND_STATUS_FAILED) return false;
    return true;
}

void EEPROM_TypeA_searchCheck(void)
{
    uint16_t SearchRecordNum, SearchSectorNum;
    uint32_t Temp0, Temp1;
    bool SectorState;
    uint32_t SearchRecordAddress  = EEPROM_EMULATION_ADDRESS;
    uint32_t *SearchRecordPointer = (void *) SearchRecordAddress;

    /* Clear flag*/
    gEEPROMTypeASearchFlag      = 0;
    gEEPROMTypeAFormatErrorFlag = 0;

    /* Traverse records header to search the active record and check the format*/
    for (SearchSectorNum = EEPROM_EMULATION_ACTIVE_SECTOR_NUM_MIN;
         SearchSectorNum <= EEPROM_EMULATION_ACTIVE_SECTOR_NUM_MAX;
         SearchSectorNum++) {
        SectorState = 0;
        for (SearchRecordNum = EEPROM_EMULATION_ACTIVE_RECORD_NUM_MIN;
             SearchRecordNum <= EEPROM_EMULATION_ACTIVE_RECORD_NUM_MAX;
             SearchRecordNum++) {
            /* Read the header*/
            SearchRecordPointer = (void *) SearchRecordAddress;
            Temp0               = *SearchRecordPointer;
            SearchRecordPointer = (void *) (SearchRecordAddress + 4);
            Temp1               = *SearchRecordPointer;

            if (Temp0 == 0xffffffff && Temp1 == 0xffffffff)  //Erased
            {
                /* if Erased is followed by other states in a sector, the format is error.
                 * SectorState is to find out this situation*/
                SectorState = 1;
            } else if (Temp0 == 0x00000000 && Temp1 == 0x0000ffff &&
                       SectorState == 0)  //Used
            {
            } else if (Temp0 == 0x0000ffff && Temp1 == 0x0000ffff &&
                       SectorState == 0)  //Active
            {
                /* If active record is found, 4 global variables are updated, and gEEPROMTypeASearchFlag is set*/
                gActiveRecordAddress = SearchRecordAddress;
                gActiveRecordNum     = SearchRecordNum;
                gActiveSectorNum     = SearchSectorNum;
                if (gActiveRecordNum >=
                        EEPROM_EMULATION_ACTIVE_RECORD_NUM_MAX &&
                    gActiveSectorNum >=
                        EEPROM_EMULATION_ACTIVE_SECTOR_NUM_MAX) {
                    gNextRecordAddress = EEPROM_EMULATION_ADDRESS;
                } else {
                    gNextRecordAddress =
                        gActiveRecordAddress + EEPROM_EMULATION_RECORD_SIZE;
                }
                gEEPROMTypeASearchFlag = 1;
            } else if (Temp0 == 0x0000ffff && Temp1 == 0xffffffff &&
                       SectorState == 0)  //Recording
            {
                gEEPROMTypeAFormatErrorFlag = 1;
            } else {
                gEEPROMTypeAFormatErrorFlag = 1;
            }
            /* Point to next record*/
            SearchRecordAddress += (EEPROM_EMULATION_RECORD_SIZE);
        }
    }
}

bool EEPROM_TypeA_eraseLastSector(void)
{
    uint32_t EraseSectorAddress;
    DL_FLASHCTL_COMMAND_STATUS FlashAPIState;
    if (gActiveSectorNum > EEPROM_EMULATION_ACTIVE_SECTOR_NUM_MIN) {
        EraseSectorAddress =
            EEPROM_EMULATION_ADDRESS + 1024 * (gActiveSectorNum - 2);
    } else {
        EraseSectorAddress =
            EEPROM_EMULATION_ADDRESS +
            1024 * (EEPROM_EMULATION_ACTIVE_SECTOR_NUM_MAX - 1);
    }

    DL_FlashCTL_unprotectSector(
        FLASHCTL, EraseSectorAddress, DL_FLASHCTL_REGION_SELECT_MAIN);
    FlashAPIState = DL_FlashCTL_eraseMemoryFromRAM(
        FLASHCTL, EraseSectorAddress, DL_FLASHCTL_COMMAND_SIZE_SECTOR);
    if (FlashAPIState == DL_FLASHCTL_COMMAND_STATUS_FAILED) return false;

    return true;
}

bool EEPROM_TypeA_eraseNonActiveSectors(void)
{
    uint32_t EraseSectorAddress;
    DL_FLASHCTL_COMMAND_STATUS FlashAPIState;
    uint16_t num;
    for (num = 0; num < EEPROM_EMULATION_SECTOR_ACCOUNT; num++) {
        if (num != (gActiveSectorNum - 1)) {
            EraseSectorAddress = EEPROM_EMULATION_ADDRESS + 1024 * num;
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

bool EEPROM_TypeA_eraseAllSectors(void)
{
    uint32_t EraseSectorAddress;
    DL_FLASHCTL_COMMAND_STATUS FlashAPIState;
    uint16_t num;
    for (num = 0; num < EEPROM_EMULATION_SECTOR_ACCOUNT; num++) {
        EraseSectorAddress = EEPROM_EMULATION_ADDRESS + 1024 * num;
        DL_FlashCTL_unprotectSector(
            FLASHCTL, EraseSectorAddress, DL_FLASHCTL_REGION_SELECT_MAIN);
        FlashAPIState = DL_FlashCTL_eraseMemoryFromRAM(
            FLASHCTL, EraseSectorAddress, DL_FLASHCTL_COMMAND_SIZE_SECTOR);
        if (FlashAPIState == DL_FLASHCTL_COMMAND_STATUS_FAILED) return false;
    }
    return true;
}
