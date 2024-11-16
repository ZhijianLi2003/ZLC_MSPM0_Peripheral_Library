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
/*!****************************************************************************
 *  @file       dali_target_command.h
 *  @brief      DALI Command List and Functionality
 *  @defgroup   DALI Library (DALI)
 *
 *  @anchor ti_dali_commands_overview
 *  # Overview
 *
 *  The DALI Commands and Functionality
 *
 *  <hr>
 ******************************************************************************/


#ifndef DALI_TARGET_COMMAND_H_
#define DALI_TARGET_COMMAND_H_

#include "dali_variables.h"
#include <ti/iqmath/include/IQmathLib.h>
#include "ti_msp_dl_config.h"


/* Execution Command */
/**
 * @brief perform direct arc power control via fade time
 *
 * DAPC uses fade rate to fade to the desired level.  It translates a value 1-15
 * to a set time using the formula rate(steps/sec) = 506 / 2^(Fade Time/2).
 *
 * starts fade timer(TIMER_0) and concludes all action in the TIMER_0
 * interrupt handler
 *
 * @param[in] receivedData contains the desired target level to fade to
 *
 */
void DALI_DAPC(uint8_t * receivedData);

/**
 * @brief perform DALI Up command by increasing actual level
 * to calculated target level via fade rate
 *
 *
 * This function starts fade timer(TIMER_0) and concludes all action in the
 * TIMER_0 interrupt handler.  This command should execute in 200 ms.  DAPC
 * uses fade time to fade to the desired level.  It translates a value 1-15
 * to a set time using the formula Time(seconds) = 2^((Fade Time/2) - 1)
 *
 */
void DALI_up(void);

/**
 * @brief perform DALI Down command by decreasing actual level to calculated
 * target level via fade rate
 *
 * This function starts fade timer(TIMER_0) and concludes all action in the
 * TIMER_0 interrupt handler.  This command should execute in 200 ms.  DAPC
 * uses fade rate to fade to the desired level.  It translates a value 1-15
 * to a set time using the formula rate(steps/sec) = 506 / 2^(Fade Time/2).
 *
 */
void DALI_down(void);


/* Level Instructions without Fading */
/**
 * @brief perform DALI Off command and turn of connected control gear light source
 *
 * @note actual level should be achieved immediately/as soon as possible
 *
 */
void DALI_turnOff(void);

/**
 * @brief perform DALI Step Up command and increase the actual level by 1
 *
 * @note actual level should be achieved immediately/as soon as possible
 *
 */
void DALI_stepUp(void);

/**
 * @brief perform DALI Step Down command and decrease the actual level by 1
 *
 * @note actual level should be achieved immediately/as soon as possible
 *
 */
void DALI_stepDown(void);

/**
 * @brief perform DALI Recall Min Level command and increase the actual level by 1
 *
 * @note actual level should be achieved immediately/as soon as possible
 *
 */
void DALI_recallMinLevel(void);

/**
 * @brief perform DALI Recall Max Level command and increase the actual level by 1
 *
 * @note actual level should be achieved immediately/as soon as possible
 *
 */
void DALI_recallMaxLevel(void);

/* Configuration Command */

/**
 * @brief reset all control gear variables to reset value
 *
 * This function starts a 300 ms timer for the reset period, and should not
 * execute any other command properly.  It should also set reset state to
 * true during this period
 */
void DALI_reset(void);

/**
 * @brief store the actual level of the light source in data transfer register 0
 *
 */
void DALI_storeActualLevelDTR0(void);

/**
 * @brief set the operating mode value from the value stored in DTR0
 *
 */
void DALI_setOperatingMode(void);

/**
 * @brief reset the memory bank values
 *
 */
void DALI_resetMemoryBank(void);

/**
 * @brief define procedure to identify device
 *
 */
void DALI_identifyDevice(void);

/**
 * @brief set max level based on command information
 *
 * @note adjust actual level of light source to new max level
 */
void DALI_setMaxLevel(void);

/**
 * @brief set min level based on command information
 *
 * @note adjust actual level of light source to new min level
 */
void DALI_setMinLevel(void);

/**
 * @brief set system failure level based on command information
 *
 */
void DALI_setSystemFailureLevel(void);

/**
 * @brief set power on level based on command information
 *
 */
void DALI_setPowerOnLevel(void);

/**
 * @brief set fade time based on command information
 *
 */
void DALI_setFadeTime(void);

/**
 * @brief set fade rate based on command information
 *
 */
void DALI_setFadeRate(void);

/**
 * @brief set extended fade rate based on command information
 *
 */
void DALI_setExtendedFadeTime(void);

/**
 * @brief set desired scene based on command information
 *
 * @param[in] receivedData short address to be assigned to device
 *
 */
void DALI_setScene(uint8_t * receivedData);

/**
 * @brief remove a value for a specific scene and set to MASK based on command information
 *
 * @param[in] receivedData short address to be assigned to device
 *
 */
void DALI_removeFromScene(uint8_t * receivedData);

/**
 * @brief add device to a specific group based on command information
 *
 * @param[in] receivedData short address to be assigned to device
 *
 */
void DALI_addToGroup(uint8_t * receivedData);

/**
 * @brief remove a device from a specific group based on command information
 *
 * @param[in] receivedData short address to be assigned to device
 *
 */
void DALI_removeGroup(uint8_t * receivedData);

/**
 * @brief assign a short address to a device based on command information
 *
 */
void DALI_setShortAddress(void);

/**
 * @brief assign a short address to a device based on command information
 *
 */
void DALI_enableWriteMemory(void);

/* Query Commands */

/**
 * @brief transmit status bit info
 *
 */
void DALI_queryStatus(void);

/**
 * @brief transmit whether control gear is present
 *
 */
void DALI_queryControlGearPresent(void);

/**
 * @brief transmit whether control gear failure is detected
 *
 */
void DALI_queryControlGearFailure(void);

/**
 * @brief transmit whether lamp failure is detected
 *
 */
void DALI_queryLampFailure(void);

/**
 * @brief transmit whether lamp is on
 *
 */
void DALI_queryLampPowerOn(void);

/**
 * @brief transmit whether limit error is detected
 *
 */
void DALI_queryLimitError(void);

/**
 * @brief transmit reset state of device
 *
 */
void DALI_queryResetState(void);

/**
 * @brief transmit whether short address is MASK or an actual address
 *
 */
void DALI_queryMissingShortAddress(void);

/**
 * @brief transmit version number to controller
 *
 */
void DALI_queryVersionNumber(void);

/**
 * @brief transmit contents of data transfer register 0
 *
 */
void DALI_queryContentDTR0(void);

/**
 * @brief transmit contents of data transfer register 1
 *
 */

void DALI_queryDeviceType(void);

/**
 * @brief transmit device type and features based on prior command/reported types/features
 *
 */
void DALI_queryNextDeviceType(void);

/**
 * @brief transmit PHM to controller
 *
 */
void DALI_queryPhysicalMinimum(void);

/**
 * @brief transmit whether power cycle is detected
 *
 */
void DALI_queryPowerFailure(void);

/**
 * @brief transmit contents of data transfer register 1
 *
 */
void DALI_queryContentDTR1(void);

/**
 * @brief transmit contents of data transfer register 2
 *
 */
void DALI_queryContentDTR2(void);

/**
 * @brief transmit operating mode to controller
 *
 */
void DALI_queryOperatingMode(void);

/**
 * @brief transmit type of light source to controller
 *
 */
void DALI_queryLightSourceType(void);

/**
 * @brief transmit actual level of light source
 *
 */
void DALI_queryActualLevel(void);

/**
 * @brief transmit max level of light source
 *
 */
void DALI_queryMaxLevel(void);

/**
 * @brief transmit min level of light source
 *
 */
void DALI_queryMinLevel(void);

/**
 * @brief transmit power on level of light source
 *
 */
void DALI_queryPowerOnLevel(void);

/**
 * @brief transmit system failure level of light source
 *
 */
void DALI_querySystemFailureLevel(void);

/**
 * @brief transmit fade rate and time of device to controller
 *
 */
void DALI_queryFadeRateTime(void);

/**
 * @brief transmit extended fade time of device to controller
 *
 */
void DALI_queryExtendedFadeTime(void);

/**
 * @brief transmit manufacturer mode of device to controller
 *
 */
void DALI_queryManufacturerMode(void);

/**
 * @brief transmit level for specific scene to controller
 *
 * @param[in] receivedData short address to be assigned to device
 *
 */
void DALI_querySceneLevel(uint8_t * receivedData);

/**
 * @brief transmit whether device is part of any group between 0 and 7
 *
 */
void DALI_queryGroup0_7(void);

/**
 * @brief transmit whether device is part of any group between 8 and 15
 *
 */
void DALI_queryGroups8_15(void);

/**
 * @brief transmit the 8 MSB of the random address
 *
 */
void DALI_queryRandomAddressHigh(void);

/**
 * @brief transmit the 8 middle bit of the random address
 *
 */
void DALI_queryRandomAddressMiddle(void);

/**
 * @brief transmit the 8 LSB of the random address
 *
 */
void DALI_queryRandomAddressLow(void);

/**
 * @brief read information from specific memory bank
 *
 * This function reads a specific piece of information from
 * a specific memory bank, which are determined by the values in the
 * data transfer registers.
 *
 */
void DALI_readMemoryLocation(void);

/* Special Commands */

/**
 * @brief terminate initialization process
 *
 */
void DALI_terminate(void);

/**
 * @brief initiate initialization process
 *
 */
void DALI_initialize(void);

/**
 * @brief set DTR0 with value from command
 *
 */
void DALI_dtr0(uint8_t * receivedData);

/**
 * @brief generate a random address for device
 *
 */
void DALI_randomiseAddress(void);

/**
 * @brief compare search address with random address
 *
 */
void DALI_compareAddress(void);

/**
 * @brief withdraw device from pool of possible devices to be initialized
 *        and set initialisationState to WITHDRAW
 *
 */
void DALI_withdraw(void);

/**
 * @brief set 8 MSB of search address
 *
 * @param[in] receivedData short address to be assigned to device
 *
 */
void DALI_searchAddrH(uint8_t * receivedData);

/**
 * @brief set 8 middle bits of search address
 *
 * @param[in] receivedData short address to be assigned to device
 *
 */
void DALI_searchAddrM(uint8_t * receivedData);

/**
 * @brief set 8 LSB of search address
 *
 * @param[in] receivedData short address to be assigned to device
 *
 */
void DALI_searchAddrL(uint8_t * receivedData);

/**
 * @brief set short address for device during initialization
 *
 * @param[in] receivedData short address to be assigned to device
 *
 */
void DALI_programShortAddress(uint8_t * receivedData);

/**
 * @brief check if the sent address is equal to the device short address
 *
 * @param[in] receivedData address to be verified
 *
 */
void DALI_verifyShortAddress(uint8_t * receivedData);

/**
 * @brief transmit short address to host
 *
 */
void DALI_queryShortAddress(void);

/**
 * @brief enables the control gear to execute LED specific commands
 *
 * @param[in] receivedData short address to be assigned to device
 *
 * This function sets a flag indicating that the control gear can execute any of the
 * LED specific functions per IEC 62386-207.  This flag resides in the LED Control Gear variable
 * that is stored within the overall control gear variable.
 *
 */
void DALI_enableDeviceType(uint8_t * receivedData);

/**
 * @brief set DTR1 with value from command
 *
 * @param[in] receivedData short address to be assigned to device
 *
 */
void DALI_dtr1(uint8_t * receivedData);

/**
 * @brief set DTR2 with value from command
 *
 * @param[in] receivedData short address to be assigned to device
 *
 */
void DALI_dtr2(uint8_t * receivedData);

/**
 * @brief write data into memory bank and sends response
 *
 * This function writes data into a specific memory location within
 * a non-zero memory bank(not memory bank 0).  If no such memory bank
 * exists, nothing will happen and 0x00 will be sent back to the host.
 * Otherwise, the data written will be echoed back to the host.
 *
 * @param[in] receivedData short address to be assigned to device
 *
 */
void DALI_writeMemoryLocation(uint8_t * receivedData);

/**
 * @brief write data into memory bank and sends response
 *
 * This function writes data into a specific memory location within
 * a non-zero memory bank(not memory bank 0).  If no such memory bank
 * exists, nothing will happen.  No reply, success or fail, will be
 * transmitted back to the host.
 *
 * @param[in] receivedData short address to be assigned to device
 *
 */
void DALI_writeMemoryLocationNoReply(uint8_t * receivedData);








#endif /* DALI_TARGET_COMMAND_H_ */
