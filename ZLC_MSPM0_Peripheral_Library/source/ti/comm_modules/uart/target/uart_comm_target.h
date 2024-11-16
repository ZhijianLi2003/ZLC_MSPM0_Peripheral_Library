/*
 * Copyright (c) 2024, Texas Instruments Incorporated
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
 *  @file       uart_comm_target.h
 *  @brief      UART communication Module
 *
 *
 *  @anchor uart_comm_target
 *  # Overview
 *
 *  APIs for UART communication module
 *
 *  <hr>
 ******************************************************************************/

#ifndef UART_COMM_TARGET_H_
#define UART_COMM_TARGET_H_

#include <stdbool.h>
#include "ti_msp_dl_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/* FRAME STRUCTURE */
/*! @brief Preamble byte */
#define PREAMBLE_BYTE (0xFE)
/*! @brief Preamble byte size */
#define PREAMBLE_BYTE_SIZE (0)

/*! @brief Target address */
#define TARGET_ADDR (0xAD)
/*! @brief Broadcast address */
#define BROADCAST_ADDR (0xFF)

/* SOF */
/*! @brief Start index */
#define START_IDX (0)
/*! @brief Start byte size */
#define START_BYTE_SIZE (1)
/*! @brief Frame start byte */
#define FRAME_START_BYTE (0x68)

/* Target Address */
/*! @brief Target address index */
#define TARGET_ADDR_IDX (START_IDX + START_BYTE_SIZE)
/*! @brief Target address size */
#define TARGET_ADDR_SIZE (1)

/* Control Byte */
/*! @brief Control index */
#define CTRL_IDX (TARGET_ADDR_IDX + TARGET_ADDR_SIZE)
/*! @brief Control size */
#define CTRL_SIZE (1)
/*! @brief Control mask */
#define CMD_MASK (0x80)
/*! @brief CRC mask */
#define CRC_MASK (0x40)
/*! @brief Length mask */
#define LEN_MASK (0x1F)
/*! @brief Write command */
#define WRITE_CMD (0x80)
/*! @brief Read command */
#define READ_CMD (0x00)

/*! @brief Header size */
#define HEADER_SIZE (START_BYTE_SIZE + TARGET_ADDR_SIZE + CTRL_SIZE)

/* Memory Address */
/*! @brief Memory address index */
#define MEM_ADDR_IDX (CTRL_IDX + CTRL_SIZE)
/*! @brief Memory address size */
#define MEM_ADDR_SIZE (4)

/*! @brief Memory address range start */
#define MEM_ADDR_RANGE_START (0x0)
/*! @brief Memory address range end */
#define MEM_ADDR_RANGE_END (0xFFFFFFFF)

/* Data */
/*! @brief Data index */
#define DATA_IDX (MEM_ADDR_IDX + MEM_ADDR_SIZE)
/*! @brief maximum data size */
#define MAX_DATA_SIZE (32)

/*! @brief Data in Acknowledge frame */
#define ACK_WRITE (0xAC)

/* OFFSET is from the end of frame */
/* CRC */
/*! @brief CRC offset */
#define CRC_OFFSET (END_OFFSET + CRC_SIZE)
/*! @brief CRC size */
#define CRC_SIZE (2)

/* EOF */
/*! @brief End offset */
#define END_OFFSET (1)
/*! @brief Frame end byte */
#define FRAME_END_BYTE (0x16)
/*! @brief End byte size */
#define END_BYTE_SIZE (1)

/* TRAILER */

/*! @brief Trailer size */
#define TRAILER_SIZE (END_BYTE_SIZE)
/*! @brief Maximum buffer size */
#define MAX_BUFFER_SIZE \
    (HEADER_SIZE + MEM_ADDR_SIZE + MAX_DATA_SIZE + CRC_SIZE + TRAILER_SIZE)
/*! @brief Error offset */
#define ERROR_OFFSET (7)
/*! @brief DMA receive transfer size */
#define DMA_RX_TRANSFER_SIZE (71)

/*! @brief Buffer info structure */
typedef struct {
    /*! Buffer array */
    _Alignas(uint32_t) uint8_t buffer[MAX_BUFFER_SIZE];
    /*! Pointer */
    uint8_t ptr;
    /*! Length */
    uint8_t len;
} BufferInfo;

/*! @brief UART status */
typedef enum {
    /*! UART IDLE state */
    UART_STATUS_IDLE = 0,
    /*! UART RX buffering state */
    UART_STATUS_RX_BUFFERING,
    /*! UART process frame state */
    UART_STATUS_PROCESS_FRAME,
    /*! UART TX transmitting state */
    UART_STATUS_TX_TRANSMITTING
} UART_Status;

/*! @brief UART ERROR types */
typedef enum {
    /*! No error */
    ERROR_TYPE_NONE = 0x00,
    /*! Mismatch Start byte error */
    ERROR_TYPE_MISMATCH_START_BYTE = 0xE1,
    /*! Mismatch end byte error */
    ERROR_TYPE_MISMATCH_END_BYTE = 0xE2,
    /*! Error in Address range */
    ERROR_TYPE_ADDR_RANGE = 0xE3,
    /*! Mismatch CRC error */
    ERROR_TYPE_MISMATCH_CRC = 0xE4,
    /*! Mismatch target address error*/
    ERROR_TYPE_MISMATCH_TARGET_ADDR = 0xE5
} ErrorType;

/*! @brief UART instance */
typedef struct {
    /*! Transmit message */
    BufferInfo txMsg;
    /*! Receive message */
    BufferInfo rxMsg;

    /*! Data length */
    uint8_t dataLen;
    /*! CRC enabled */
    _Bool isCrc;

    /*! UART status */
    UART_Status status;
    /*! UART error type */
    ErrorType error;
} UART_Instance;

/**
 * @brief     Initializes the UART module
 * @param[in] UART_handle    A pointer to UART_Instance
 */
void UART_init(UART_Instance *UART_handle);

/**
 * @brief     Checks the Rx Buffer for commands
 * @param[in] UART_handle    A pointer to UART_Instance
 */
void UART_checkForCommand(UART_Instance *UART_handle);

/**
 * @brief     Decodes frame length from buffer
 * @param[in] UART_handle    A pointer to UART_Instance
 */
void UART_getFrameLength(UART_Instance *UART_handle);

/**
 * @brief     Initializes DMA to store the command in RX Buffer
 * @param[in] UART_handle  Pointer to UART_Instance
 */
void DMA_RX_init(UART_Instance *UART_handle);

#ifdef __cplusplus
}
#endif
#endif /* UART_COMM_TARGET_H_ */
