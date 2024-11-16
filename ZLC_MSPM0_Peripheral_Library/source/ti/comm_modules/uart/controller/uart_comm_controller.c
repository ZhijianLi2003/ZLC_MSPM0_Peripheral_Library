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
#include "uart_comm_controller.h"

#define LEFT_SHIFT_8(x) ((x) << 8)
#define RIGHT_SHIFT_8(x) ((x) >> 8)

/* Function Declarations */

/**
 * @brief     Checks UART frame in RX Buffer for errors
 * @param[in] UART_handle    Pointer to UART_Instance
 */
static void UART_processRxBuffer(UART_Instance *UART_handle);

/**
 * @brief     Transmits data stored in the buffer
 * @param[in] frame    Pointer to BufferInfo (TX)
 */
static void UART_sendBuffer(BufferInfo *frame);

/**
 * @brief     Calculates CRC 16 for an array of 8-bit data
 * @param[in] ptr   Pointer to the data to compute CRC
 * @param[in] size  size of the array of data in bytes
 * @return    Returns the CRC value
 */
static uint16_t CRC_calc16(uint8_t *ptr, uint8_t size);

/* Helper Functions */

/**
 * @brief     32 bit to 8 bit
 * @param[in] b  pointer to unsigned 8 bit output
 * @param[in] u32  unsigned 32 bit input
 */
static void u8From32(uint8_t *b, uint32_t u32)
{
    b[0] = (uint8_t) u32;
    b[1] = (uint8_t)(u32 = RIGHT_SHIFT_8(u32));
    b[2] = (uint8_t)(u32 = RIGHT_SHIFT_8(u32));
    b[3] = (uint8_t)(u32 = RIGHT_SHIFT_8(u32));
}

/**
 * @brief     16 bit to 8 bit
 * @param[in] b  pointer to unsigned 8 bit output
 * @param[in] u16  unsigned 16 bit input
 */
static void u8From16(uint8_t *b, uint16_t u16)
{
    b[0] = (uint8_t) u16;
    b[1] = (uint8_t)(u16 = RIGHT_SHIFT_8(u16));
}

/**
 * @brief     8 bit to 32 bit
 * @param[in] b  pointer to unsigned 8 bit output
 * @return    32 bit result
 */
static uint32_t u32(uint8_t *b)
{
    uint32_t u;
    u = b[3];
    u = LEFT_SHIFT_8(u) + b[2];
    u = LEFT_SHIFT_8(u) + b[1];
    u = LEFT_SHIFT_8(u) + b[0];
    return u;
}

/**
 * @brief     8 bit to 16 bit
 * @param[in] b  pointer to unsigned 8 bit output
 * @return    16 bit result
 */
static uint16_t u16(uint8_t *b)
{
    uint16_t u;
    u = b[1];
    u = LEFT_SHIFT_8(u) + b[0];
    return u;
}

uint16_t calcCRC16(uint8_t *ptr, uint8_t size)
{
    uint8_t remainder = (size & 1);
    uint16_t size16   = size >> 1;

    uint16_t checkSum =
        DL_CRC_calculateBlock16(CRC, CRC_SEED, (uint16_t *) ptr, size16);

    if (remainder) {
        DL_CRC_feedData8(CRC, ptr[size - 1]);
        checkSum = ((uint16_t) DL_CRC_getResult16(CRC));
    }

    return checkSum;
}

/**
 * @brief     Resets pointer and length of the buffer
 * @param[in] frame  Pointer to BufferInfo (Rx,Tx)
 */
__STATIC_INLINE void UART_clearBuffer(BufferInfo *frame)
{
    frame->ptr = 0;
    frame->len = 0;
}

void UART_init(UART_Instance *UART_handle)
{
    UART_clearBuffer(&UART_handle->rxMsg);
    UART_clearBuffer(&UART_handle->txMsg);

    UART_handle->dataLen = 0;
    UART_handle->isCrc   = false;
    UART_handle->status  = UART_STATUS_IDLE;
    UART_handle->error   = ERROR_TYPE_NONE;
}

void UART_checkForResponse(
    UART_Instance *UART_handle, UART_ResponseInfo *response)
{
    if (UART_handle->status == UART_STATUS_PROCESS_FRAME) {
        response->received = true;
        UART_processRxBuffer(UART_handle);

        /* Length stored in frame is 1 less than actual length */
        response->dataSize =
            (UART_handle->rxMsg.buffer[CTRL_IDX] & LEN_MASK) + 1;

        response->status = ERROR_TYPE_NONE;

        if (UART_handle->rxMsg.buffer[CTRL_IDX] & ERROR_MASK) {
            /* Stores error code sent by target */
            response->status =
                (ErrorType) UART_handle->rxMsg.buffer[RESP_DATA_IDX];
        }

        /* Decode buffer and store the values in response frame fields */
        response->frame.start = UART_handle->rxMsg.buffer[START_IDX];
        response->frame.targetAddr =
            UART_handle->rxMsg.buffer[TARGET_ADDR_IDX];
        response->frame.ctrl = UART_handle->rxMsg.buffer[CTRL_IDX];

        for (int i = 0; i < MAX_DATA_SIZE; i++) {
            if (i < response->dataSize) {
                response->frame.data[i] =
                    UART_handle->rxMsg.buffer[RESP_DATA_IDX + i];
            }
            /* Resetting extra space to zero*/
            else {
                response->frame.data[i] = 0;
            }
        }

        response->frame.crc = u16(
            &UART_handle->rxMsg.buffer[UART_handle->rxMsg.len - CRC_OFFSET]);
        response->frame.end =
            UART_handle->rxMsg.buffer[UART_handle->rxMsg.len - END_OFFSET];

        UART_handle->status = UART_STATUS_IDLE;
    }
}

void UART_storeRxData(UART_Instance *UART_handle, uint8_t rxByte)
{
    if (UART_handle->status == UART_STATUS_IDLE) {
        if (rxByte == FRAME_START_BYTE) {
            UART_clearBuffer(&UART_handle->rxMsg);

            UART_handle->rxMsg.buffer[UART_handle->rxMsg.ptr++] = rxByte;

            UART_handle->status = UART_STATUS_RX_BUFFERING;
        }
    }

    else if (UART_handle->status == UART_STATUS_RX_BUFFERING) {
        /* Check Buffer Out of Bounds*/
        if (UART_handle->rxMsg.ptr >= MAX_BUFFER_SIZE) {
            UART_handle->status = UART_STATUS_IDLE;
            UART_handle->error  = ERROR_TYPE_BUFFER_OVERFLOW;
            UART_clearBuffer(&UART_handle->rxMsg);
            return;
        }

        /* Store the recieved data in buffer */
        UART_handle->rxMsg.buffer[UART_handle->rxMsg.ptr++] = rxByte;

        /* Set Length if control byte is stored */
        if (UART_handle->rxMsg.ptr == CTRL_IDX + 1) {
            UART_handle->rxMsg.len = 0;

            /* Length stored in frame is 1 less than actual length */
            UART_handle->dataLen =
                (UART_handle->rxMsg.buffer[CTRL_IDX] & LEN_MASK) + 1;

            /* If command includes crc, then response is expected to send crc*/
            uint8_t crcLen = UART_handle->isCrc ? (CRC_SIZE) : 0;

            /* Total length of the frame */
            UART_handle->rxMsg.len =
                HEADER_SIZE + UART_handle->dataLen + crcLen + TRAILER_SIZE;
        }

        /* Check if the whole frame is stored */
        if (UART_handle->rxMsg.len != 0 &&
            UART_handle->rxMsg.ptr == UART_handle->rxMsg.len) {
            UART_handle->status = UART_STATUS_PROCESS_FRAME;
        }
    }
}

static void UART_sendBuffer(BufferInfo *frame)
{
    uint8_t i;
    for (i = (uint8_t) 0; i < frame->len; i++) {
        DL_UART_Main_clearInterruptStatus(
            UART_0_INST, DL_UART_MAIN_INTERRUPT_EOT_DONE);

        /* Waits until FIFO has space to fill the data */
        while (DL_UART_Main_isTXFIFOFull(UART_0_INST)) {
        }
        DL_UART_Main_transmitData(UART_0_INST, frame->buffer[i]);
    }

    /* Waits until the data is completely transmitted */
    while (DL_UART_Main_getRawInterruptStatus(
               UART_0_INST, DL_UART_MAIN_INTERRUPT_EOT_DONE) !=
           DL_UART_MAIN_INTERRUPT_EOT_DONE) {
    }
}

static void UART_processRxBuffer(UART_Instance *UART_handle)
{
    /* Verify Target Address */
    if (UART_handle->rxMsg.buffer[TARGET_ADDR_IDX] != TARGET_ADDR &&
        UART_handle->rxMsg.buffer[TARGET_ADDR_IDX] != BROADCAST_ADDR) {
        UART_handle->error = ERROR_TYPE_MISMATCH_TARGET_ADDR;
        return;
    }

    /* Verify end byte */
    if (UART_handle->rxMsg.buffer[UART_handle->rxMsg.len - 1] !=
        FRAME_END_BYTE) {
        UART_handle->error = ERROR_TYPE_MISMATCH_END_BYTE;
        return;
    }

    /* Verify CRC16 */
    if (UART_handle->isCrc) {
        uint8_t size = HEADER_SIZE + UART_handle->dataLen;
        uint16_t checkSum =
            calcCRC16((&UART_handle->rxMsg.buffer[START_IDX]), size);
        uint16_t expectedCheckSum = u16(
            &UART_handle->rxMsg.buffer[UART_handle->rxMsg.len - CRC_OFFSET]);

        if (checkSum != expectedCheckSum) {
            UART_handle->error = ERROR_TYPE_MISMATCH_CRC;
            return;
        }
    }

    UART_handle->error = ERROR_TYPE_NONE;
    return;
}

void UART_sendCommand(UART_Instance *UART_handle, UART_CommandInfo *command)
{
    /* Prepare TX Buffer */
    UART_handle->txMsg.ptr = 0;

    UART_handle->txMsg.buffer[UART_handle->txMsg.ptr++] = FRAME_START_BYTE;

    if (TARGET_ADDR_SIZE == 1) {
        UART_handle->txMsg.buffer[UART_handle->txMsg.ptr++] =
            command->targetAddr;
    }

    UART_handle->txMsg.buffer[UART_handle->txMsg.ptr++] =
        (command->commandType) | (command->crcEnable ? CRC_MASK : (0x00)) |
        ((command->dataSize - 1) & LEN_MASK);

    u8From32(
        &UART_handle->txMsg.buffer[UART_handle->txMsg.ptr], command->memAddr);
    UART_handle->txMsg.ptr += 4;

    if (command->commandType == WRITE_COMMAND) {
        for (int i = 0; i < command->dataSize; i++) {
            UART_handle->txMsg.buffer[UART_handle->txMsg.ptr++] =
                command->dataArray[i];
        }
    }

    UART_handle->isCrc = false;

    if (command->crcEnable) {
        UART_handle->isCrc = true;
        uint16_t Crc =
            calcCRC16((&UART_handle->txMsg.buffer[0]), UART_handle->txMsg.ptr);
        u8From16(&UART_handle->txMsg.buffer[UART_handle->txMsg.ptr], Crc);
        UART_handle->txMsg.ptr += 2;
    }

    UART_handle->txMsg.buffer[UART_handle->txMsg.ptr++] = FRAME_END_BYTE;

    UART_handle->txMsg.len = UART_handle->txMsg.ptr;

    UART_handle->status = UART_STATUS_TX_TRANSMITTING;

    UART_sendBuffer(&UART_handle->txMsg);

    UART_handle->status = UART_STATUS_IDLE;
}
