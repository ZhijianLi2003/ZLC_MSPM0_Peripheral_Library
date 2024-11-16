/*
 * Copyright (c) 2020, Texas Instruments Incorporated
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

#include <stdbool.h>
#include <stdint.h>
#include <ti/devices/DeviceFamily.h>

#include <ti/driverlib/dl_flashctl.h>

static void DL_FlashCTL_programMemoryConfig(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd);
static DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_executeCommandFromRAM(
    FLASHCTL_Regs *flashctl);
static void DL_FlashCTL_programMemory8Config(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, uint8_t *data);
static void DL_FlashCTL_programMemory16Config(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, uint16_t *data);
static void DL_FlashCTL_programMemory32Config(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, uint32_t *data);
static void DL_FlashCTL_programMemory64Config(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, uint32_t *data);

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define RAMFUNC \
    __attribute__((section(".TI.ramfunc"))) __attribute__((noinline))
#elif defined(__GNUC__)
#define RAMFUNC __attribute__((section(".ramfunc"))) __attribute__((noinline))
#elif defined(__IAR_SYSTEMS_ICC__)
#define RAMFUNC __ramfunc __attribute__((noinline))
#else
#error "Compiler not supported for this function"
#endif
RAMFUNC static DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_executeCommandFromRAM(
    FLASHCTL_Regs *flashctl)
{
    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;

    uint32_t status =
        flashctl->GEN.STATCMD &
        (FLASHCTL_STATCMD_CMDDONE_MASK | FLASHCTL_STATCMD_CMDPASS_MASK |
            FLASHCTL_STATCMD_CMDINPROGRESS_MASK |
            FLASHCTL_STATCMD_CMDPASS_STATFAIL);

    while ((DL_FLASHCTL_COMMAND_STATUS) status ==
           DL_FLASHCTL_COMMAND_STATUS_IN_PROGRESS) {
        status =
            flashctl->GEN.STATCMD &
            (FLASHCTL_STATCMD_CMDDONE_MASK | FLASHCTL_STATCMD_CMDPASS_MASK |
                FLASHCTL_STATCMD_CMDINPROGRESS_MASK |
                FLASHCTL_STATCMD_CMDPASS_STATFAIL);
    }

#if (DeviceFamily_PARENT == DeviceFamily_PARENT_MSPM0G151X_G351X)
    /* Set COMMAND bit within CMDTYPE register to clear status*/
    flashctl->GEN.CMDTYPE = DL_FLASHCTL_COMMAND_TYPE_CLEAR_STATUS;
    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
#endif

    return (DL_FLASHCTL_COMMAND_STATUS)(status);
}

void DL_FlashCTL_eraseMemory(FLASHCTL_Regs *flashctl, uint32_t address,
    DL_FLASHCTL_COMMAND_SIZE memorySize)
{
    /* Set command type and size */
    flashctl->GEN.CMDTYPE =
        (uint32_t) memorySize | DL_FLASHCTL_COMMAND_TYPE_ERASE;

    /* Set address, address should be in the desired bank or sector to erase */
    DL_FlashCTL_setCommandAddress(flashctl, address);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_eraseMemoryFromRAM(
    FLASHCTL_Regs *flashctl, uint32_t address,
    DL_FLASHCTL_COMMAND_SIZE memorySize)
{
    /* Set command type and size */
    flashctl->GEN.CMDTYPE =
        (uint32_t) memorySize | DL_FLASHCTL_COMMAND_TYPE_ERASE;

    /* Set address, address should be in the desired bank or sector to erase */
    DL_FlashCTL_setCommandAddress(flashctl, address);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

bool DL_FlashCTL_massErase(FLASHCTL_Regs *flashctl)
{
    bool status;

    DL_FlashCTL_unprotectMainMemory(flashctl);
    DL_FlashCTL_protectNonMainMemory(flashctl);

    DL_FlashCTL_eraseMemory(
        flashctl, FLASHCTL_BANK0_ADDRESS, DL_FLASHCTL_COMMAND_SIZE_BANK);
    status = DL_FlashCTL_waitForCmdDone(flashctl);

    if (DL_FactoryRegion_getDATAFlashSize() && (status == true)) {
        status = DL_FlashCTL_eraseDataBank(flashctl);
    }
    return (status);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_massEraseFromRAM(
    FLASHCTL_Regs *flashctl)
{
    DL_FLASHCTL_COMMAND_STATUS status;

    DL_FlashCTL_unprotectMainMemory(flashctl);
    DL_FlashCTL_protectNonMainMemory(flashctl);

    status = DL_FlashCTL_eraseMemoryFromRAM(
        flashctl, FLASHCTL_BANK0_ADDRESS, DL_FLASHCTL_COMMAND_SIZE_BANK);

    if (DL_FactoryRegion_getDATAFlashSize() &&
        (status != DL_FLASHCTL_COMMAND_STATUS_FAILED)) {
        status = DL_FlashCTL_eraseDataBankFromRAM(flashctl);
    }

    return (status);
}

bool DL_FlashCTL_massEraseMultiBank(FLASHCTL_Regs *flashctl)
{
    bool status            = true;
    uint32_t bankStartAddr = 0x0;
    uint8_t numBanks       = DL_FactoryRegion_getNumBanks();
    uint32_t flashSize     = DL_FactoryRegion_getMAINFlashSize();
    /* Assuming a sector size of 1KB */
    uint32_t bankSize = (((uint32_t) flashSize / (uint32_t) numBanks) * 1024U);

    DL_FLASHCTL_BANK_SELECT bankSelect = DL_FLASHCTL_BANK_SELECT_0;

    bool eraseFlag    = true;
    uint8_t bankIndex = 0;
    while (bankIndex < numBanks && status != false) {
        /* If flash bank swap policy is enabled, the primary bank will be write
         * and erase protected. Thus, we will not attempt an erase of the
         * primary bank.
         */
        if (DL_SYSCTL_isFlashBankSwapEnabled()) {
            eraseFlag = (bankIndex < (numBanks / (uint8_t) 2)) ? false : true;
        } else {
            eraseFlag = true;
        }
        switch (bankIndex) {
            case 0:
                bankSelect = DL_FLASHCTL_BANK_SELECT_0;
                break;
            case 1:
                bankSelect = DL_FLASHCTL_BANK_SELECT_1;
                break;
            case 2:
                bankSelect = DL_FLASHCTL_BANK_SELECT_2;
                break;
            case 3:
                bankSelect = DL_FLASHCTL_BANK_SELECT_3;
                break;
            default:
                break;
        }

        bankStartAddr = (bankSize * bankIndex);

        if (eraseFlag == true) {
            DL_FlashCTL_enableAddressOverrideMode(flashctl);
            DL_FlashCTL_setBankSelect(flashctl, bankSelect);
            DL_FlashCTL_setRegionSelect(
                flashctl, DL_FLASHCTL_REGION_SELECT_MAIN);

            DL_FlashCTL_unprotectMainMemory(flashctl);
            DL_FlashCTL_protectNonMainMemory(flashctl);
            DL_FlashCTL_eraseMemory(
                flashctl, bankStartAddr, DL_FLASHCTL_COMMAND_SIZE_BANK);
            status = DL_FlashCTL_waitForCmdDone(flashctl);
        }
        bankIndex++;
    }
    DL_FlashCTL_disableAddressOverrideMode(flashctl);

    if (DL_FactoryRegion_getDATAFlashSize() && status == true) {
        status = DL_FlashCTL_eraseDataBank(flashctl);
    }

    return (status);
}

bool DL_FlashCTL_factoryReset(FLASHCTL_Regs *flashctl)
{
    bool status;

    /* Erase Main Memory */
    status = DL_FlashCTL_massErase(flashctl);

    if (status == true) {
        DL_FlashCTL_unprotectNonMainMemory(flashctl);
        DL_FlashCTL_eraseMemory(flashctl, FLASHCTL_NONMAIN_ADDRESS,
            DL_FLASHCTL_COMMAND_SIZE_SECTOR);

        status = DL_FlashCTL_waitForCmdDone(flashctl);
    }
    return (status);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_factoryResetFromRAM(
    FLASHCTL_Regs *flashctl)
{
    DL_FLASHCTL_COMMAND_STATUS status;

    /* Erase Main Memory */
    status = DL_FlashCTL_massEraseFromRAM(flashctl);

    if (status == DL_FLASHCTL_COMMAND_STATUS_PASSED) {
        DL_FlashCTL_unprotectNonMainMemory(flashctl);
        status = DL_FlashCTL_eraseMemoryFromRAM(flashctl,
            FLASHCTL_NONMAIN_ADDRESS, DL_FLASHCTL_COMMAND_SIZE_SECTOR);
    }
    return (status);
}

bool DL_FlashCTL_factoryResetMultiBank(FLASHCTL_Regs *flashctl)
{
    bool status;

    /* Erase Main Memory */
    status = DL_FlashCTL_massEraseMultiBank(flashctl);

    if (status == true) {
        DL_FlashCTL_unprotectNonMainMemory(flashctl);
        DL_FlashCTL_eraseMemory(flashctl, FLASHCTL_NONMAIN_ADDRESS,
            DL_FLASHCTL_COMMAND_SIZE_SECTOR);

        status = DL_FlashCTL_waitForCmdDone(flashctl);
    }
    return (status);
}

static void DL_FlashCTL_programMemoryConfig(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd)
{
    flashctl->GEN.CMDTYPE = (uint32_t) DL_FLASHCTL_COMMAND_SIZE_ONE_WORD |
                            DL_FLASHCTL_COMMAND_TYPE_PROGRAM;

    flashctl->GEN.CMDBYTEN = cmd;

    /* Set address, address should be in the sector that we want to erase */
    DL_FlashCTL_setCommandAddress(flashctl, address);
}

static void DL_FlashCTL_programMemory8Config(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, uint8_t *data)
{
    DL_FlashCTL_programMemoryConfig(flashctl, address, cmd);

    /* Set data registers */
    flashctl->GEN.CMDDATA0 = *data;
}

static void DL_FlashCTL_programMemory16Config(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, uint16_t *data)
{
    DL_FlashCTL_programMemoryConfig(flashctl, address, cmd);

    /* Set data registers */
    flashctl->GEN.CMDDATA0 = *data;
}

static void DL_FlashCTL_programMemory32Config(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, uint32_t *data)
{
    DL_FlashCTL_programMemoryConfig(flashctl, address, cmd);

    /* Set data registers */
    flashctl->GEN.CMDDATA0 = *data;
}

static void DL_FlashCTL_programMemory64Config(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, uint32_t *data)
{
    DL_FlashCTL_programMemoryConfig(flashctl, address, cmd);

    /* Set data registers */
    flashctl->GEN.CMDDATA0 = *data;
    flashctl->GEN.CMDDATA1 = *(data + 1);
}

void DL_FlashCTL_programMemory8(
    FLASHCTL_Regs *flashctl, uint32_t address, uint8_t *data)
{
    /* Only enable the bottom 8 bits for programming*/
    DL_FlashCTL_programMemory8Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_8_WITHOUT_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM8(
    FLASHCTL_Regs *flashctl, uint32_t address, uint8_t *data)
{
    /* Only enable the bottom 8 bits for programming*/
    DL_FlashCTL_programMemory8Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_8_WITHOUT_ECC, data);
    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory16(
    FLASHCTL_Regs *flashctl, uint32_t address, uint16_t *data)
{
    /* Enable 16 bits per data register for programming*/
    DL_FlashCTL_programMemory16Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_16_WITHOUT_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM16(
    FLASHCTL_Regs *flashctl, uint32_t address, uint16_t *data)
{
    /* Enable 16 bits per data register for programming*/
    DL_FlashCTL_programMemory16Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_16_WITHOUT_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory32(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data)
{
    /* Enable 32 bits per data register for programming*/
    DL_FlashCTL_programMemory32Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_32_WITHOUT_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM32(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data)
{
    /* Enable 32 bits per data register for programming*/
    DL_FlashCTL_programMemory32Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_32_WITHOUT_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory64(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data)
{
    /* Enable 64 bits per data register for programming*/
    DL_FlashCTL_programMemory64Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_64_WITHOUT_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM64(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data)
{
    /* Enable 64 bits per data register for programming*/
    DL_FlashCTL_programMemory64Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_64_WITHOUT_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory8WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint8_t *data)
{
    /* Only enable the bottom 8 bits for programming*/
    DL_FlashCTL_programMemory8Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_8_WITH_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM8WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint8_t *data)
{
    /* Only enable the bottom 8 bits for programming*/
    DL_FlashCTL_programMemory8Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_8_WITH_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory16WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint16_t *data)
{
    /* Enable 16 bits per data register for programming*/
    DL_FlashCTL_programMemory16Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_16_WITH_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM16WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint16_t *data)
{
    /* Enable 16 bits per data register for programming*/
    DL_FlashCTL_programMemory16Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_16_WITH_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory32WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data)
{
    /* Enable 32 bits per data register for programming*/
    DL_FlashCTL_programMemory32Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_32_WITH_ECC, data);
    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM32WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data)
{
    /* Enable 32 bits per data register for programming*/
    DL_FlashCTL_programMemory32Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_32_WITH_ECC, data);
    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory64WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data)
{
    /* Enable 64 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory64Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_64_WITH_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM64WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data)
{
    /* Enable 64 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory64Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_64_WITH_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory8WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, uint8_t *data, uint8_t *eccCode)
{
    /* Enable 8 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory8Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_8_WITH_ECC, data);

    flashctl->GEN.CMDDATAECC0 = *eccCode;

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM8WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, uint8_t *data, uint8_t *eccCode)
{
    /* Enable 8 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory8Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_8_WITH_ECC, data);

    flashctl->GEN.CMDDATAECC0 = *eccCode;

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory16WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, uint16_t *data, uint8_t *eccCode)
{
    /* Enable 16 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory16Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_16_WITH_ECC, data);

    flashctl->GEN.CMDDATAECC0 = *eccCode;

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM16WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, uint16_t *data,
    uint8_t *eccCode)
{
    /* Enable 16 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory16Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_16_WITH_ECC, data);

    flashctl->GEN.CMDDATAECC0 = *eccCode;

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory32WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, uint32_t *data, uint8_t *eccCode)
{
    /* Enable 32 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory32Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_32_WITH_ECC, data);

    flashctl->GEN.CMDDATAECC0 = *eccCode;

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM32WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data,
    uint8_t *eccCode)
{
    /* Enable 32 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory32Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_32_WITH_ECC, data);

    flashctl->GEN.CMDDATAECC0 = *eccCode;

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory64WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, uint32_t *data, uint8_t *eccCode)
{
    /* Enable 64 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory64Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_64_WITH_ECC, data);

    flashctl->GEN.CMDDATAECC0 = *eccCode;

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM64WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data,
    uint8_t *eccCode)
{
    /* Enable 64 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory64Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_64_WITH_ECC, data);

    flashctl->GEN.CMDDATAECC0 = *eccCode;

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

bool DL_FlashCTL_programMemoryBlocking64WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data,
    uint32_t dataSize, DL_FLASHCTL_REGION_SELECT regionSelect)
{
    bool status = true;

    /* Check for valid data size */
    if (dataSize == (uint32_t) 0 ||
        ((dataSize & (uint32_t) 1) == (uint32_t) 1)) {
        status = false;
    }

    while ((dataSize != (uint32_t) 0) && status) {
        /* Unprotect sector before every write */
        DL_FlashCTL_unprotectSector(flashctl, address, regionSelect);

        DL_FlashCTL_programMemory64WithECCGenerated(flashctl, address, data);
        dataSize = dataSize - (uint32_t) 2;
        data     = data + 2;
        address  = address + (uint32_t) 8;

        status = DL_FlashCTL_waitForCmdDone(flashctl);
    }

    return (status);
}

DL_FLASHCTL_COMMAND_STATUS
DL_FlashCTL_programMemoryBlockingFromRAM64WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data,
    uint32_t dataSize, DL_FLASHCTL_REGION_SELECT regionSelect)
{
    DL_FLASHCTL_COMMAND_STATUS status = DL_FLASHCTL_COMMAND_STATUS_IN_PROGRESS;

    /* Check for valid data size */
    if (dataSize == (uint32_t) 0 ||
        ((dataSize & (uint32_t) 1) == (uint32_t) 1)) {
        status = DL_FLASHCTL_COMMAND_STATUS_FAILED;
    }

    while ((dataSize != (uint32_t) 0) &&
           (status != DL_FLASHCTL_COMMAND_STATUS_FAILED)) {
        /* Unprotect sector before every write */
        DL_FlashCTL_unprotectSector(flashctl, address, regionSelect);

        status = DL_FlashCTL_programMemoryFromRAM64WithECCGenerated(
            flashctl, address, data);
        dataSize = dataSize - (uint32_t) 2;
        data     = data + 2;
        address  = address + (uint32_t) 8;
    }

    return (status);
}

bool DL_FlashCTL_programMemoryBlocking64WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, uint32_t *data, uint8_t *eccCode, uint32_t dataSize,
    DL_FLASHCTL_REGION_SELECT regionSelect)
{
    bool status = true;

    /* Check for valid data size */
    if (dataSize == (uint32_t) 0 ||
        ((dataSize & (uint32_t) 1) == (uint32_t) 1)) {
        status = false;
    }

    while ((dataSize != (uint32_t) 0) && status) {
        /* Unprotect sector before every write */
        DL_FlashCTL_unprotectSector(flashctl, address, regionSelect);

        DL_FlashCTL_programMemory64WithECCManual(
            flashctl, address, data, eccCode);
        dataSize = dataSize - (uint32_t) 2;
        data     = data + 2;
        eccCode  = eccCode + 1;
        address  = address + (uint32_t) 8;

        status = DL_FlashCTL_waitForCmdDone(flashctl);
    }

    return (status);
}

DL_FLASHCTL_COMMAND_STATUS
DL_FlashCTL_programMemoryBlockingFromRAM64WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data,
    uint8_t *eccCode, uint32_t dataSize,
    DL_FLASHCTL_REGION_SELECT regionSelect)
{
    DL_FLASHCTL_COMMAND_STATUS status = DL_FLASHCTL_COMMAND_STATUS_IN_PROGRESS;

    /* Check for valid data size */
    if (dataSize == (uint32_t) 0 ||
        ((dataSize & (uint32_t) 1) == (uint32_t) 1)) {
        status = DL_FLASHCTL_COMMAND_STATUS_FAILED;
    }

    while ((dataSize != (uint32_t) 0) &&
           (status != DL_FLASHCTL_COMMAND_STATUS_FAILED)) {
        /* Unprotect sector before every write */
        DL_FlashCTL_unprotectSector(flashctl, address, regionSelect);

        status = DL_FlashCTL_programMemoryFromRAM64WithECCManual(
            flashctl, address, data, eccCode);
        dataSize = dataSize - (uint32_t) 2;
        data     = data + 2;
        eccCode  = eccCode + 1;
        address  = address + (uint32_t) 8;
    }

    return (status);
}

bool DL_FlashCTL_programMemoryBlocking(FLASHCTL_Regs *flashctl,
    uint32_t address, uint32_t *data, uint32_t dataSize,
    DL_FLASHCTL_REGION_SELECT regionSelect)
{
    bool status = true;

    /* Check for valid data size */
    if (dataSize == (uint32_t) 0) {
        status = false;
    }

    while ((dataSize != (uint32_t) 0) && status) {
        /* Unprotect sector before every write */
        DL_FlashCTL_unprotectSector(flashctl, address, regionSelect);

        /* 32-bit case */
        if (dataSize == (uint32_t) 1) {
            DL_FlashCTL_programMemory32(flashctl, address, data);

            dataSize = dataSize - (uint32_t) 1;
            data     = data + 1;
            address  = address + (uint32_t) 4;
        } else {
            /* 64-bit case */
            DL_FlashCTL_programMemory64(flashctl, address, data);
            dataSize = dataSize - (uint32_t) 2;
            data     = data + 2;
            address  = address + (uint32_t) 8;
        }

        status = DL_FlashCTL_waitForCmdDone(flashctl);
    }

    return (status);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data,
    uint32_t dataSize, DL_FLASHCTL_REGION_SELECT regionSelect)
{
    DL_FLASHCTL_COMMAND_STATUS status = DL_FLASHCTL_COMMAND_STATUS_IN_PROGRESS;

    /* Check for valid data size */
    if (dataSize == (uint32_t) 0) {
        status = DL_FLASHCTL_COMMAND_STATUS_FAILED;
    }

    while ((dataSize != (uint32_t) 0) &&
           (status != DL_FLASHCTL_COMMAND_STATUS_FAILED)) {
        /* Unprotect sector before every write */
        DL_FlashCTL_unprotectSector(flashctl, address, regionSelect);

        /* 32-bit case */
        if (dataSize == (uint32_t) 1) {
            status =
                DL_FlashCTL_programMemoryFromRAM32(flashctl, address, data);

            dataSize = dataSize - (uint32_t) 1;
            data     = data + 1;
            address  = address + (uint32_t) 4;
        } else {
            /* 64-bit case */
            status =
                DL_FlashCTL_programMemoryFromRAM64(flashctl, address, data);
            dataSize = dataSize - (uint32_t) 2;
            data     = data + 2;
            address  = address + (uint32_t) 8;
        }
    }

    return (status);
}

void DL_FlashCTL_unprotectMainMemory(FLASHCTL_Regs *flashctl)
{
    flashctl->GEN.CMDWEPROTA = 0;
    flashctl->GEN.CMDWEPROTB = 0;
    flashctl->GEN.CMDWEPROTC = 0;
}

void DL_FlashCTL_unprotectDataMemory(FLASHCTL_Regs *flashctl)
{
    flashctl->GEN.CMDWEPROTA = 0;
    flashctl->GEN.CMDWEPROTB = 0;
    flashctl->GEN.CMDWEPROTC = 0;
}

void DL_FlashCTL_protectMainMemory(FLASHCTL_Regs *flashctl)
{
    flashctl->GEN.CMDWEPROTA = FLASHCTL_CMDWEPROTA_VAL_MAXIMUM;
    flashctl->GEN.CMDWEPROTB = FLASHCTL_CMDWEPROTB_VAL_MAXIMUM;
    flashctl->GEN.CMDWEPROTC = FLASHCTL_CMDWEPROTC_VAL_MAXIMUM;
}

void DL_FlashCTL_unprotectNonMainMemory(FLASHCTL_Regs *flashctl)
{
    flashctl->GEN.CMDWEPROTNM = 0;
}

void DL_FlashCTL_protectNonMainMemory(FLASHCTL_Regs *flashctl)
{
    flashctl->GEN.CMDWEPROTNM = FLASHCTL_CMDWEPROTNM_VAL_MAXIMUM;
}

void DL_FlashCTL_unprotectAllMemory(FLASHCTL_Regs *flashctl)
{
    flashctl->GEN.CMDWEPROTA  = 0;
    flashctl->GEN.CMDWEPROTB  = 0;
    flashctl->GEN.CMDWEPROTC  = 0;
    flashctl->GEN.CMDWEPROTNM = 0;
    flashctl->GEN.CMDWEPROTTR = 0;
    flashctl->GEN.CMDWEPROTEN = 0;
}

void DL_FlashCTL_protectAllMemory(FLASHCTL_Regs *flashctl)
{
    flashctl->GEN.CMDWEPROTA  = FLASHCTL_CMDWEPROTA_VAL_MAXIMUM;
    flashctl->GEN.CMDWEPROTB  = FLASHCTL_CMDWEPROTB_VAL_MAXIMUM;
    flashctl->GEN.CMDWEPROTC  = FLASHCTL_CMDWEPROTC_VAL_MAXIMUM;
    flashctl->GEN.CMDWEPROTNM = FLASHCTL_CMDWEPROTNM_VAL_MAXIMUM;
    flashctl->GEN.CMDWEPROTTR = FLASHCTL_CMDWEPROTTR_VAL_MAXIMUM;
    flashctl->GEN.CMDWEPROTEN = FLASHCTL_CMDWEPROTEN_VAL_MAXIMUM;
}

#ifdef DEVICE_HAS_NO_CMDWEPROTA
void DL_FlashCTL_unprotectSector(FLASHCTL_Regs *flashctl, uint32_t addr,
    DL_FLASHCTL_REGION_SELECT regionSelect)
{
    uint32_t sectorNumber = DL_FlashCTL_getFlashSectorNumber(flashctl, addr);
    uint32_t sectorInBank =
        DL_FlashCTL_getFlashSectorNumberInBank(flashctl, addr);
    uint32_t sectorMask;

    /*
     * Devices without CMDWEPROTA will use CMDWEPROTB to unprotect all sectors of MAIN memory
     */

    if ((uint32_t) regionSelect == FLASHCTL_CMDCTL_REGIONSEL_MAIN) {
        sectorMask = (uint32_t) 1 << (sectorInBank / (uint32_t) 8);
        flashctl->GEN.CMDWEPROTB &= ~sectorMask;
    } else if ((uint32_t) regionSelect == FLASHCTL_CMDCTL_REGIONSEL_NONMAIN) {
        sectorMask = (uint32_t) 1 << (sectorNumber % (uint32_t) 32);
        flashctl->GEN.CMDWEPROTNM &= ~sectorMask;
    } else {
        ; /* Not expected to reach this else statement */
    }
}
#else
void DL_FlashCTL_unprotectSector(FLASHCTL_Regs *flashctl, uint32_t addr,
    DL_FLASHCTL_REGION_SELECT regionSelect)
{
    uint32_t sectorNumber = DL_FlashCTL_getFlashSectorNumber(flashctl, addr);
    uint32_t sectorInBank =
        DL_FlashCTL_getFlashSectorNumberInBank(flashctl, addr);
    uint8_t numBanks              = DL_FactoryRegion_getNumBanks();
    uint32_t mainFlashSize        = DL_FactoryRegion_getMAINFlashSize();
    uint32_t physicalSectorNumber = 0;
    uint32_t sectorMask;

    if ((uint32_t) regionSelect == FLASHCTL_CMDCTL_REGIONSEL_MAIN) {
        /* If the banks have been swapped, CMDWEPROTA only protects physical
         * bank 0 (logical bank 1 in a swap), so if the address points to this
         * region we must protect it using CMDWEPROTA instead of CMDWEPROTB
         */
        if (DL_SYSCTL_isExecuteFromUpperFlashBank() && numBanks > 1) {
            /* physical sectors are swapped. Calculate physical sector to
             * determine use of CMDWEPROTA */
            if (sectorNumber > (mainFlashSize / 2)) {
                physicalSectorNumber = sectorNumber - (mainFlashSize / 2);
            } else {
                physicalSectorNumber = sectorNumber + (mainFlashSize / 2);
            }
        } else {
            physicalSectorNumber = sectorNumber;
        }

        if (physicalSectorNumber < (uint32_t) 32) {
            /* Use CMDWEPROTA */
            sectorMask = (uint32_t) 1 << physicalSectorNumber;
            flashctl->GEN.CMDWEPROTA &= ~sectorMask;
        } else {
            /* Use CMDWEPROTB */
            if (sectorInBank < (uint32_t) 256) {
                /* Single bank system */
                if (DL_FactoryRegion_getNumBanks() == (uint32_t) 1) {
                    sectorMask =
                        (uint32_t) 1
                        << ((sectorInBank - (uint32_t) 32) / (uint32_t) 8);
                    flashctl->GEN.CMDWEPROTB &= ~sectorMask;
                } else { /* Multi bank system */
                    sectorMask = (uint32_t) 1 << (sectorInBank / (uint32_t) 8);
                    flashctl->GEN.CMDWEPROTB &= ~sectorMask;
                }
            }
            /* Use CMDWEPROTC */
            else if (sectorInBank < (uint32_t) 511) {
                sectorMask =
                    ((uint32_t) 1
                        << ((sectorInBank - (uint32_t) 256) / (uint32_t) 8));
                flashctl->GEN.CMDWEPROTC &= ~sectorMask;
            } else {
                ; /* Not expected to reach this else statement */
            }
        }
    } else if ((uint32_t) regionSelect == FLASHCTL_CMDCTL_REGIONSEL_NONMAIN) {
        sectorMask = (uint32_t) 1 << (sectorNumber % (uint32_t) 32);
        flashctl->GEN.CMDWEPROTNM &= ~sectorMask;
    } else {
        ; /* Not expected to reach this else statement */
    }
}
#endif

#ifdef DEVICE_HAS_NO_CMDWEPROTA
void DL_FlashCTL_protectSector(FLASHCTL_Regs *flashctl, uint32_t addr,
    DL_FLASHCTL_REGION_SELECT regionSelect)
{
    uint32_t sectorNumber = DL_FlashCTL_getFlashSectorNumber(flashctl, addr);
    uint32_t sectorInBank =
        DL_FlashCTL_getFlashSectorNumberInBank(flashctl, addr);
    uint32_t sectorMask;

    /*
     * Devices without CMDWEPROTA will use CMDWEPROTB to protect all sectors of MAIN memory
     */

    if ((uint32_t) regionSelect == FLASHCTL_CMDCTL_REGIONSEL_MAIN) {
        sectorMask = ((uint32_t) 1 << (sectorInBank / (uint32_t) 8));
        flashctl->GEN.CMDWEPROTB |= sectorMask;
    } else if ((uint32_t) regionSelect == FLASHCTL_CMDCTL_REGIONSEL_NONMAIN) {
        sectorNumber = DL_FlashCTL_getFlashSectorNumber(flashctl, addr);
        sectorMask   = (uint32_t) 1 << (sectorNumber % (uint32_t) 32);
        flashctl->GEN.CMDWEPROTNM |= sectorMask;
    } else {
        ; /* Not expected to reach this else statement */
    }
}
#else
void DL_FlashCTL_protectSector(FLASHCTL_Regs *flashctl, uint32_t addr,
    DL_FLASHCTL_REGION_SELECT regionSelect)
{
    uint32_t sectorNumber = DL_FlashCTL_getFlashSectorNumber(flashctl, addr);
    uint32_t sectorInBank =
        DL_FlashCTL_getFlashSectorNumberInBank(flashctl, addr);
    uint8_t numBanks              = DL_FactoryRegion_getNumBanks();
    uint32_t mainFlashSize        = DL_FactoryRegion_getMAINFlashSize();
    uint32_t physicalSectorNumber = 0;
    uint32_t sectorMask;

    if ((uint32_t) regionSelect == FLASHCTL_CMDCTL_REGIONSEL_MAIN) {
        /* If the banks have been swapped, CMDWEPROTA only protects physical
         * bank 0 (logical bank 1 in a swap), so if the address points to this
         * region we must protect it using CMDWEPROTA instead of CMDWEPROTB
         */
        if (DL_SYSCTL_isExecuteFromUpperFlashBank() && numBanks > 1) {
            /* physical sectors are swapped. Calculate physical sector to
             * determine use of CMDWEPROTA */
            if (sectorNumber > (mainFlashSize / 2)) {
                physicalSectorNumber = sectorNumber - (mainFlashSize / 2);
            } else {
                physicalSectorNumber = sectorNumber + (mainFlashSize / 2);
            }
        } else {
            physicalSectorNumber = sectorNumber;
        }

        if (physicalSectorNumber < (uint32_t) 32) {
            /* Use CMDWEPROTA */
            sectorMask = (uint32_t) 1 << physicalSectorNumber;
            flashctl->GEN.CMDWEPROTA |= sectorMask;
        } else {
            /* Use CMDWEPROTB */
            if (sectorNumber < (uint32_t) 256) {
                /* Single bank system */
                if (DL_FactoryRegion_getNumBanks() == (uint32_t) 1) {
                    sectorMask =
                        ((uint32_t) 1 << ((
                             sectorInBank - (uint32_t) 32 / (uint32_t) 8)));
                    flashctl->GEN.CMDWEPROTB |= sectorMask;
                } else { /* Multi bank system */
                    sectorMask =
                        ((uint32_t) 1 << (sectorInBank / (uint32_t) 8));
                    flashctl->GEN.CMDWEPROTB |= sectorMask;
                }
            }
            /* Use CMDWEPROTC */
            else if (sectorNumber < (uint32_t) 511) {
                sectorMask =
                    ((uint32_t) 1
                        << ((sectorInBank - (uint32_t) 256) / (uint32_t) 8));
                flashctl->GEN.CMDWEPROTC |= sectorMask;
            } else {
                ; /* Not expected to reach this else statement */
            }
        }
    } else if ((uint32_t) regionSelect == FLASHCTL_CMDCTL_REGIONSEL_NONMAIN) {
        sectorNumber = DL_FlashCTL_getFlashSectorNumber(flashctl, addr);
        sectorMask   = (uint32_t) 1 << (sectorNumber % (uint32_t) 32);
        flashctl->GEN.CMDWEPROTNM |= sectorMask;
    } else {
        ; /* Not expected to reach this else statement */
    }
}
#endif

static void DL_FlashCTL_readVerifyConfig(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd)
{
    flashctl->GEN.CMDTYPE = (uint32_t) DL_FLASHCTL_COMMAND_SIZE_ONE_WORD |
                            DL_FLASHCTL_COMMAND_TYPE_READ_VERIFY;

    flashctl->GEN.CMDBYTEN = cmd;

    /* Set address, address should be in the sector that we want to erase */
    DL_FlashCTL_setCommandAddress(flashctl, address);
}

static void DL_FlashCTL_readVerify8Config(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, uint8_t *data)
{
    DL_FlashCTL_readVerifyConfig(flashctl, address, cmd);

    flashctl->GEN.CMDDATA0 = *data;
}

static void DL_FlashCTL_readVerify16Config(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, uint16_t *data)
{
    DL_FlashCTL_readVerifyConfig(flashctl, address, cmd);

    flashctl->GEN.CMDDATA0 = *data;
}

static void DL_FlashCTL_readVerify32Config(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, uint32_t *data)
{
    DL_FlashCTL_readVerifyConfig(flashctl, address, cmd);

    flashctl->GEN.CMDDATA0 = *data;
}

static void DL_FlashCTL_readVerify64Config(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, uint32_t *data)
{
    DL_FlashCTL_readVerifyConfig(flashctl, address, cmd);

    /* Set data registers */
    flashctl->GEN.CMDDATA0 = *data;
    flashctl->GEN.CMDDATA1 = *(data + 1);
}

void DL_FlashCTL_readVerify8(
    FLASHCTL_Regs *flashctl, uint32_t address, uint8_t *data)
{
    flashctl->GEN.CMDTYPE = (uint32_t) DL_FLASHCTL_COMMAND_SIZE_ONE_WORD |
                            (uint32_t) DL_FLASHCTL_COMMAND_TYPE_READ_VERIFY;

    /* Set the address we want to verify */
    DL_FlashCTL_setCommandAddress(flashctl, address);

    /* Configure bytes to use for comparison */
    flashctl->GEN.CMDBYTEN = DL_FLASHCTL_READ_VERIFY_8_WITHOUT_ECC;

    flashctl->GEN.CMDDATA0 = *data;

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_readVerify16(
    FLASHCTL_Regs *flashctl, uint32_t address, uint16_t *data)
{
    flashctl->GEN.CMDTYPE = (uint32_t) DL_FLASHCTL_COMMAND_SIZE_ONE_WORD |
                            (uint32_t) DL_FLASHCTL_COMMAND_TYPE_READ_VERIFY;

    /* Set the address we want to verify */
    DL_FlashCTL_setCommandAddress(flashctl, address);

    /* Configure bytes to use for comparison */
    flashctl->GEN.CMDBYTEN = DL_FLASHCTL_READ_VERIFY_16_WITHOUT_ECC;

    flashctl->GEN.CMDDATA0 = *data;

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_readVerify32(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data)
{
    flashctl->GEN.CMDTYPE = (uint32_t) DL_FLASHCTL_COMMAND_SIZE_ONE_WORD |
                            (uint32_t) DL_FLASHCTL_COMMAND_TYPE_READ_VERIFY;

    /* Set the address we want to verify */
    DL_FlashCTL_setCommandAddress(flashctl, address);

    /* Configure bytes to use for comparison */
    flashctl->GEN.CMDBYTEN = DL_FLASHCTL_READ_VERIFY_32_WITHOUT_ECC;

    flashctl->GEN.CMDDATA0 = *data;

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_readVerify64(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data)
{
    flashctl->GEN.CMDTYPE = (uint32_t) DL_FLASHCTL_COMMAND_SIZE_ONE_WORD |
                            (uint32_t) DL_FLASHCTL_COMMAND_TYPE_READ_VERIFY;

    /* Set the address we want to verify */
    DL_FlashCTL_setCommandAddress(flashctl, address);

    /* Configure bytes to use for comparison */
    flashctl->GEN.CMDBYTEN = DL_FLASHCTL_READ_VERIFY_64_WITHOUT_ECC;

    flashctl->GEN.CMDDATA0 = *data;
    flashctl->GEN.CMDDATA1 = *(data + 1);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM8(
    FLASHCTL_Regs *flashctl, uint32_t address, uint8_t *data)
{
    DL_FlashCTL_readVerify8Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_8_WITHOUT_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM16(
    FLASHCTL_Regs *flashctl, uint32_t address, uint16_t *data)
{
    DL_FlashCTL_readVerify16Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_16_WITHOUT_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM32(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data)
{
    DL_FlashCTL_readVerify32Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_32_WITHOUT_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM64(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data)
{
    DL_FlashCTL_readVerify64Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_64_WITHOUT_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM8WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint8_t *data)
{
    DL_FlashCTL_readVerify8Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_8_WITH_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM16WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint16_t *data)
{
    DL_FlashCTL_readVerify16Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_16_WITH_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM32WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data)
{
    DL_FlashCTL_readVerify32Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_32_WITH_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM64WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data)
{
    DL_FlashCTL_readVerify64Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_64_WITH_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM8WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, uint8_t *data, uint8_t *eccCode)
{
    DL_FlashCTL_readVerify8Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_8_WITH_ECC, data);

    flashctl->GEN.CMDDATAECC0 = *eccCode;

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM16WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, uint16_t *data,
    uint8_t *eccCode)
{
    DL_FlashCTL_readVerify16Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_16_WITH_ECC, data);

    flashctl->GEN.CMDDATAECC0 = *eccCode;

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM32WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data,
    uint8_t *eccCode)
{
    DL_FlashCTL_readVerify32Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_32_WITH_ECC, data);

    flashctl->GEN.CMDDATAECC0 = *eccCode;

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM64WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data,
    uint8_t *eccCode)
{
    DL_FlashCTL_readVerify64Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_64_WITH_ECC, data);

    flashctl->GEN.CMDDATAECC0 = *eccCode;

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_readVerify8WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint8_t *data)
{
    flashctl->GEN.CMDTYPE = (uint32_t) DL_FLASHCTL_COMMAND_SIZE_ONE_WORD |
                            (uint32_t) DL_FLASHCTL_COMMAND_TYPE_READ_VERIFY;

    /* Set the address we want to verify */
    DL_FlashCTL_setCommandAddress(flashctl, address);

    /* Configure bytes to use for comparison, with ECC enabled */
    flashctl->GEN.CMDBYTEN = DL_FLASHCTL_READ_VERIFY_8_WITH_ECC;

    flashctl->GEN.CMDDATA0 = *data;

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_readVerify16WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint16_t *data)
{
    flashctl->GEN.CMDTYPE = (uint32_t) DL_FLASHCTL_COMMAND_SIZE_ONE_WORD |
                            (uint32_t) DL_FLASHCTL_COMMAND_TYPE_READ_VERIFY;

    /* Set the address we want to verify */
    DL_FlashCTL_setCommandAddress(flashctl, address);

    /* Configure bytes to use for comparison, with ECC enabled */
    flashctl->GEN.CMDBYTEN = DL_FLASHCTL_READ_VERIFY_16_WITH_ECC;

    flashctl->GEN.CMDDATA0 = *data;

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_readVerify32WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data)
{
    flashctl->GEN.CMDTYPE = (uint32_t) DL_FLASHCTL_COMMAND_SIZE_ONE_WORD |
                            (uint32_t) DL_FLASHCTL_COMMAND_TYPE_READ_VERIFY;

    /* Set the address we want to verify */
    DL_FlashCTL_setCommandAddress(flashctl, address);

    /* Configure bytes to use for comparison, with ECC enabled */
    flashctl->GEN.CMDBYTEN = DL_FLASHCTL_READ_VERIFY_32_WITH_ECC;

    flashctl->GEN.CMDDATA0 = *data;

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_readVerify64WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data)
{
    flashctl->GEN.CMDTYPE = (uint32_t) DL_FLASHCTL_COMMAND_SIZE_ONE_WORD |
                            (uint32_t) DL_FLASHCTL_COMMAND_TYPE_READ_VERIFY;

    /* Set the address we want to verify */
    DL_FlashCTL_setCommandAddress(flashctl, address);

    /* Configure bytes to use for comparison, with ECC enabled */
    flashctl->GEN.CMDBYTEN = DL_FLASHCTL_READ_VERIFY_64_WITH_ECC;

    flashctl->GEN.CMDDATA0 = *data;
    flashctl->GEN.CMDDATA1 = *(data + 1);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_readVerify8WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, uint8_t *data, uint8_t *eccCode)
{
    flashctl->GEN.CMDTYPE = (uint32_t) DL_FLASHCTL_COMMAND_SIZE_ONE_WORD |
                            (uint32_t) DL_FLASHCTL_COMMAND_TYPE_READ_VERIFY;

    /* Set the address we want to verify */
    DL_FlashCTL_setCommandAddress(flashctl, address);

    /* Configure bytes to use for comparison, with ECC enabled */
    flashctl->GEN.CMDBYTEN = DL_FLASHCTL_READ_VERIFY_8_WITH_ECC;

    flashctl->GEN.CMDDATA0    = *data;
    flashctl->GEN.CMDDATAECC0 = *eccCode;

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_readVerify16WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, uint16_t *data, uint8_t *eccCode)
{
    flashctl->GEN.CMDTYPE = (uint32_t) DL_FLASHCTL_COMMAND_SIZE_ONE_WORD |
                            (uint32_t) DL_FLASHCTL_COMMAND_TYPE_READ_VERIFY;

    /* Set the address we want to verify */
    DL_FlashCTL_setCommandAddress(flashctl, address);

    /* Configure bytes to use for comparison, with ECC enabled */
    flashctl->GEN.CMDBYTEN = DL_FLASHCTL_READ_VERIFY_16_WITH_ECC;

    flashctl->GEN.CMDDATA0    = *data;
    flashctl->GEN.CMDDATAECC0 = *eccCode;

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_readVerify32WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, uint32_t *data, uint8_t *eccCode)
{
    flashctl->GEN.CMDTYPE = (uint32_t) DL_FLASHCTL_COMMAND_SIZE_ONE_WORD |
                            (uint32_t) DL_FLASHCTL_COMMAND_TYPE_READ_VERIFY;

    /* Set the address we want to verify */
    DL_FlashCTL_setCommandAddress(flashctl, address);

    /* Configure bytes to use for comparison, with ECC enabled */
    flashctl->GEN.CMDBYTEN = DL_FLASHCTL_READ_VERIFY_32_WITH_ECC;

    flashctl->GEN.CMDDATA0    = *data;
    flashctl->GEN.CMDDATAECC0 = *eccCode;

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_readVerify64WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, uint32_t *data, uint8_t *eccCode)
{
    flashctl->GEN.CMDTYPE = (uint32_t) DL_FLASHCTL_COMMAND_SIZE_ONE_WORD |
                            (uint32_t) DL_FLASHCTL_COMMAND_TYPE_READ_VERIFY;

    /* Set the address we want to verify */
    DL_FlashCTL_setCommandAddress(flashctl, address);

    /* Configure bytes to use for comparison, with ECC enabled */
    flashctl->GEN.CMDBYTEN = DL_FLASHCTL_READ_VERIFY_64_WITH_ECC;

    flashctl->GEN.CMDDATA0    = *data;
    flashctl->GEN.CMDDATA1    = *(data + 1);
    flashctl->GEN.CMDDATAECC0 = *eccCode;

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_blankVerify(FLASHCTL_Regs *flashctl, uint32_t address)
{
    /* Set command and word size. BLANKVERIFY can only be applied to a single
     * flash word at a time */
    flashctl->GEN.CMDTYPE = (uint32_t) DL_FLASHCTL_COMMAND_SIZE_ONE_WORD |
                            (uint32_t) DL_FLASHCTL_COMMAND_TYPE_BLANK_VERIFY;

    /* Set the address we want to verify */
    DL_FlashCTL_setCommandAddress(flashctl, address);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_blankVerifyFromRAM(
    FLASHCTL_Regs *flashctl, uint32_t address)
{
    /* Set command and word size. BLANKVERIFY can only be applied to a single
     * flash word at a time */
    flashctl->GEN.CMDTYPE = (uint32_t) DL_FLASHCTL_COMMAND_SIZE_ONE_WORD |
                            (uint32_t) DL_FLASHCTL_COMMAND_TYPE_BLANK_VERIFY;

    /* Set the address we want to verify */
    DL_FlashCTL_setCommandAddress(flashctl, address);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

bool DL_FlashCTL_eraseDataBank(FLASHCTL_Regs *flashctl)
{
    bool status;

    DL_FlashCTL_unprotectDataMemory(flashctl);
    DL_FlashCTL_eraseMemory(
        flashctl, FLASHCTL_DATA_ADDRESS, DL_FLASHCTL_COMMAND_SIZE_BANK);
    status = DL_FlashCTL_waitForCmdDone(flashctl);

    return (status);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_eraseDataBankFromRAM(
    FLASHCTL_Regs *flashctl)
{
    DL_FLASHCTL_COMMAND_STATUS status;

    DL_FlashCTL_unprotectDataMemory(flashctl);
    status = DL_FlashCTL_eraseMemoryFromRAM(
        flashctl, FLASHCTL_DATA_ADDRESS, DL_FLASHCTL_COMMAND_SIZE_BANK);

    return (status);
}

#ifdef DEVICE_HAS_FLASH_128_BIT_WORD

static void DL_FlashCTL_programMemory128Config(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, uint32_t *data);
static void DL_FlashCTL_programMemoryConfigMultiWord(FLASHCTL_Regs *flashctl,
    uint32_t address, uint32_t cmd, DL_FLASHCTL_COMMAND_SIZE cmdSize);

/*!
 * @brief Enable programming 128 bits without ECC enabled
 */
#define DL_FLASHCTL_PROGRAM_128_WITHOUT_ECC (0x0000FFFF)

/*!
 * @brief Enable programming 128 bits with ECC enabled
 */
#define DL_FLASHCTL_PROGRAM_128_WITH_ECC (0x0001FFFF)

static void DL_FlashCTL_programMemoryConfigMultiWord(FLASHCTL_Regs *flashctl,
    uint32_t address, uint32_t cmd, DL_FLASHCTL_COMMAND_SIZE cmdSize)
{
    flashctl->GEN.CMDTYPE =
        (uint32_t) cmdSize | DL_FLASHCTL_COMMAND_TYPE_PROGRAM;

    flashctl->GEN.CMDBYTEN = cmd;

    /* Set address, address should be in the sector that we want to erase */
    DL_FlashCTL_setCommandAddress(flashctl, address);
}

static void DL_FlashCTL_programMemory128Config(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, uint32_t *data)
{
    DL_FlashCTL_programMemoryConfigMultiWord(
        flashctl, address, cmd, DL_FLASHCTL_COMMAND_SIZE_TWO_WORDS);

    /* Set data registers */
    flashctl->GEN.CMDDATA0 = *data;
    flashctl->GEN.CMDDATA1 = *(data + 1);
    flashctl->GEN.CMDDATA2 = *(data + 2);
    flashctl->GEN.CMDDATA3 = *(data + 3);
}

void DL_FlashCTL_programMemory128(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data)
{
    /* Enable 128 bits per data register for programming*/
    DL_FlashCTL_programMemory128Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_128_WITHOUT_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_programMemory128WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data)
{
    /* Enable 128 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory128Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_128_WITH_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_programMemory128WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, uint32_t *data, uint8_t *eccCode)
{
    /* Enable 128 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory128Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_128_WITH_ECC, data);

    flashctl->GEN.CMDDATAECC0 = *eccCode;
    flashctl->GEN.CMDDATAECC1 = *(eccCode + 1);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

bool DL_FlashCTL_programMemoryBlocking128WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data,
    uint32_t dataSize, DL_FLASHCTL_REGION_SELECT regionSelect)
{
    bool status = true;

    /* Check for valid data size */
    if ((dataSize == (uint32_t) 0) || dataSize < (uint32_t) 4) {
        status = false;
    }

    while ((dataSize != (uint32_t) 0) && status) {
        /* Unprotect sector before every write */
        DL_FlashCTL_unprotectSector(flashctl, address, regionSelect);

        /* 32-bit case */
        if (dataSize == (uint32_t) 1) {
            DL_FlashCTL_programMemory32WithECCGenerated(
                flashctl, address, data);

            dataSize = dataSize - (uint32_t) 1;
            data     = data + 1;
            address  = address + (uint32_t) 4;
        } else if (dataSize < (uint32_t) 4) {
            /* 64-bit case */
            DL_FlashCTL_programMemory64WithECCGenerated(
                flashctl, address, data);
            dataSize = dataSize - (uint32_t) 2;
            data     = data + 2;
            address  = address + (uint32_t) 8;
        } else {
            /* 128-bit case */
            DL_FlashCTL_programMemory128WithECCGenerated(
                flashctl, address, data);
            dataSize = dataSize - (uint32_t) 4;
            data     = data + 4;
            address  = address + (uint32_t) 16;
        }

        status = DL_FlashCTL_waitForCmdDone(flashctl);
    }

    return (status);
}

#endif /* DEVICE_HAS_FLASH_128_BIT_WORD */
