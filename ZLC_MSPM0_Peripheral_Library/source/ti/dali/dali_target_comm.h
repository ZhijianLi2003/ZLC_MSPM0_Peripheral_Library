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
 *  @file       dali_target_comm.h
 *  @brief      DALI Communication and Execution
 *  @defgroup   DALI Library (DALI)
 *
 *  @anchor ti_dali_overview
 *  # Overview
 *
 *  The DALI Communication and Execution Functions
 *
 *  <hr>
 ******************************************************************************/

#ifndef DALI_TARGET_COMM_H_
#define DALI_TARGET_COMM_H_

/**
 * @brief number of incoming 8 bit packets per RX 
 */
#define DATA_SIZE 2

#include <ti/eeprom/emulation_type_a/eeprom_emulation_type_a.h>
#include "dali_target_command.h"
#include "dali_target_led_command.h"

/**
 * @brief flag to indicate that receive occurred
 */
extern volatile bool gReceive;


/**
 * @brief Initialize memory variables
 *
 */
void DALI_Target_init(void);

/**
 * @brief Check for an incoming message from host system
 *
 * @param[in] rxBuffer  input buffer with command information
 *
 */
void DALI_Target_receive(uint8_t * rxBuffer);

/**
 * @brief Execute incoming command
 *
 * @param[in] receivedData  data received from the RX line which is
 *                          parsed to determine what command to execute
 */

void DALI_Target_execute(uint8_t * receivedData);

/**
 * @brief Transmit data indicating response to command
 *
 * This function transmits the backward frame to the host
 * and performs cleanup in the FIFOs before accepting a new command
 */
void DALI_Target_transmit(void);

/**
 * @brief Check for Failure
 *
 * Checks for any light source failure and set status bits
 */
void DALI_Target_failure(void);

/**
 * @brief Flash Update before reset/power cycle
 *
 * Load control gear data to flash
 */
void DALI_Target_flashUpdate(void);


/**
 * @brief Load default values during initialization
 *
 * Load default values into control gear variable
 */
void DALI_Target_loadDefaults(void);

/**
 * @brief Set status bits for device based on failure checks
 *
 * set status bits to indicate success or failure
 */
void DALI_Target_setStatusBits(void);

#endif /* DALI_TARGET_COMM_H_ */
