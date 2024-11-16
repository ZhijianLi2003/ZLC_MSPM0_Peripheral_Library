/* --COPYRIGHT--,BSD
 * Copyright (c) 2019, Texas Instruments Incorporated
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
 * --/COPYRIGHT--*/
//*****************************************************************************
//        MSP430 HAL
//
// Hardware Abstraction Layer for MSP430
//
// Texas Instruments, Inc.

#ifndef __HAL_H__
#define __HAL_H__

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

//! \brief GUI Comm RX Callback function pointer
//!
//! \param[in] char with Received byte
//!
//! \return true if device wakes-up after ISR, false if not.
typedef bool (*tGUICommRXCharCallback)(char);

// ********************* System ************************************************
//! \brief Initializes I/Os used by the system.
//!           Initialization is done to achieve lowest power consumption.
//!
//!
//! \return none
extern void HAL_System_Init(void);

// ********************* I/O ***************************************************
//! \brief Initializes I/Os used by the system.
//!           Initialization is done to achieve lowest power consumption.
//!
//!
//! \return none
extern void HAL_IO_Init(void);

//! \brief Initializes inputs used for push-buttons
//!           Pins are initialized with pull-ups and interrupts are enabled.
//!
//!
//! \return none
extern void HAL_IO_InitButtons(void);

// ********************* Timer ***************************************************
//! \brief Initializes a simple periodic interrupt timer.
//!           Timer is initialized using Low-frequency clock and interrupts
//!           are enabled.
//!
//! \return none
extern void HAL_Timer_Init(void);

// ********************* GUI Communication *************************************
//! \brief Initializes the communication interface for GUI.
//!
//! \param[in] RxByteCallback is the function called when a byte is received.
//!
//! \return none
extern void HAL_GUI_Init(tGUICommRXCharCallback RxByteCallback);

//! \brief Transmits a character to the GUI in blocking mode.
//!
//! \param[in] character is the character being transmitted to GUI.
//!
//! \return none
extern void HAL_GUI_TransmitCharBlocking(char character);

#endif  //__HAL_H__
