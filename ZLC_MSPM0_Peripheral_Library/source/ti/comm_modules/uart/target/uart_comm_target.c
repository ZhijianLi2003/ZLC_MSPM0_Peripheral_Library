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
#include "uart_comm_target.h"

#define LEFT_SHIFT_8(x) ((x) << 8)
#define RIGHT_SHIFT_8(x) ((x) >> 8)

/* Function Declarations */
/**
 * @brief    Services the Command stored in Rx Buffer.
 * @param[in] UART_handle  Pointer to UART_Instance
 */
static void UART_serviceCommand(UART_Instance *UART_handle);

/**
 * @brief    Stores Start Byte and target address (if enabled) in Tx Buffer.
 * @param[in] txMsg  Pointer to BufferInfo (Tx)
 */
static void UART_prepareTxHeader(BufferInfo *txMsg);

/**
 * @brief    Stores End Byte and CRC (if enabled) in Tx Buffer.
 * @param[in] txMsg  Pointer to BufferInfo (Tx)
 * @param[in] isCrc  Flag to store CRC
 */
static void UART_prepareTxTrailer(BufferInfo *txMsg, _Bool isCrc);

/**
 * @brief    Process the read command and stores the data in Tx Buffer.
 * @param[in] frame  Pointer to BufferInfo (Tx)
 * @param[in] len    length of the data to be read
 * @param[in] addr   starting address of the data
 */
static void UART_readCommand(BufferInfo *frame, uint8_t len, uint32_t addr);

/**
 * @brief    Process the write command and stores ACK in Tx Buffer.
 * @param[in] frame  Pointer to BufferInfo (Tx)
 * @param[in] len    length of the data to be written
 * @param[in] addr   starting address of the data
 */
static void UART_writeCommand(
    BufferInfo *frame, uint8_t len, uint32_t addr, uint8_t *data);

/**
 * @brief    Stores the corresponding error byte in Tx Buffer.
 * @param[in] UART_handle  Pointer to UART_Instance
 */
static void UART_sendErrorType(UART_Instance *UART_handle);

/**
 * @brief     Process the stored data in buffer.
 * @param[in] UART_handle  Pointer to UART_Instance
 */
static void UART_processBuffer(UART_Instance *UART_handle);

/**
 * @brief     Verifies the buffer and sets the type of error if any.
 * @param[in] UART_handle  Pointer to UART_Instance
 */
static void UART_verifyBuffer(UART_Instance *UART_handle);

/**
 * @brief     Initializes DMA to send the response stored in Tx Buffer
 * @param[in] frame  Pointer to BufferInfo (Tx)
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

    DMA_RX_init(UART_handle);
}

void UART_checkForCommand(UART_Instance *UART_handle)
{
    if (UART_handle->status == UART_STATUS_RX_BUFFERING) {
        /* Check if all the bytes of command frame are stored */
        if (UART_handle->rxMsg.len <=
            (DMA_RX_TRANSFER_SIZE -
                DL_DMA_getTransferSize(DMA, DMA_CH0_CHAN_ID))) {
            UART_handle->status = UART_STATUS_PROCESS_FRAME;
            UART_processBuffer(UART_handle);
        }
    }
}

static void UART_processBuffer(UART_Instance *UART_handle)
{
    if (UART_handle->status == UART_STATUS_PROCESS_FRAME) {
        UART_verifyBuffer(UART_handle);

        if (UART_handle->error == ERROR_TYPE_NONE) {
            UART_serviceCommand(UART_handle);
        }

        /* Ignores the Command if error is target address mismatch */
        else if (UART_handle->error == ERROR_TYPE_MISMATCH_TARGET_ADDR) {
            UART_handle->status = UART_STATUS_IDLE;
            DMA_RX_init(UART_handle);
        }

        /* Waits till end byte is stored in the buffer if buffering is out of sync */
        else if (UART_handle->error == ERROR_TYPE_MISMATCH_START_BYTE ||
                 UART_handle->error == ERROR_TYPE_MISMATCH_END_BYTE) {
            if (DL_DMA_getTransferSize(DMA, DMA_CH0_CHAN_ID) !=
                DMA_RX_TRANSFER_SIZE) {
                /* Check if last byte stored is end byte */
                while (
                    UART_handle->rxMsg.buffer[(DMA_RX_TRANSFER_SIZE -
                                                  DL_DMA_getTransferSize(
                                                      DMA, DMA_CH0_CHAN_ID)) -
                                              1] != FRAME_END_BYTE) {
                };
            }

            UART_sendErrorType(UART_handle);
        }

        else {
            UART_sendErrorType(UART_handle);
        }
    }
}

void UART_getFrameLength(UART_Instance *UART_handle)
{
    if (UART_handle->rxMsg.buffer[START_IDX] != FRAME_START_BYTE) {
        UART_handle->rxMsg.len = 0;
        return;
    }

    UART_handle->dataLen =
        (UART_handle->rxMsg.buffer[CTRL_IDX] & LEN_MASK) + 1;

    UART_handle->isCrc = (UART_handle->rxMsg.buffer[CTRL_IDX] & CRC_MASK);

    uint8_t crcLen = UART_handle->isCrc ? (CRC_SIZE) : 0;

    /* Command Frame Length */
    UART_handle->rxMsg.len = HEADER_SIZE + MEM_ADDR_SIZE +
                             UART_handle->dataLen + crcLen + TRAILER_SIZE;

    /* Data is not sent in Read Command */
    if ((UART_handle->rxMsg.buffer[CTRL_IDX] & CMD_MASK) == READ_CMD) {
        UART_handle->rxMsg.len =
            HEADER_SIZE + MEM_ADDR_SIZE + 0 + crcLen + TRAILER_SIZE;
    }
}

static void UART_sendErrorType(UART_Instance *UART_handle)
{
    /* Clear Tx Buffer */
    UART_clearBuffer(&UART_handle->txMsg);

    /* Prepare Tx Header */
    UART_prepareTxHeader(&UART_handle->txMsg);

    /* Add Error Bit and length */
    UART_handle->txMsg.buffer[UART_handle->txMsg.ptr++] = (1 << ERROR_OFFSET);

    /* Add Error Type */
    UART_handle->txMsg.buffer[UART_handle->txMsg.ptr++] = UART_handle->error;

    /* Prepare Tx Trailer */
    UART_prepareTxTrailer(&UART_handle->txMsg, UART_handle->isCrc);

    UART_handle->status = UART_STATUS_TX_TRANSMITTING;

    /* Send Tx Buffer */
    UART_sendBuffer(&UART_handle->txMsg);

    UART_handle->status = UART_STATUS_IDLE;
}

static void UART_serviceCommand(UART_Instance *UART_handle)
{
    if ((UART_handle->rxMsg.buffer[CTRL_IDX] & CMD_MASK) == READ_CMD) {
        /* Clear Tx Buffer */
        UART_clearBuffer(&UART_handle->txMsg);

        /* Prepare Tx Header */
        UART_prepareTxHeader(&UART_handle->txMsg);

        UART_readCommand(&UART_handle->txMsg, UART_handle->dataLen,
            u32(&UART_handle->rxMsg.buffer[MEM_ADDR_IDX]));

        /* Prepare Tx Trailer */
        UART_prepareTxTrailer(&UART_handle->txMsg, UART_handle->isCrc);

        UART_handle->status = UART_STATUS_TX_TRANSMITTING;

        /* Send Tx Buffer */
        UART_sendBuffer(&UART_handle->txMsg);

        UART_handle->status = UART_STATUS_IDLE;
    }

    else if ((UART_handle->rxMsg.buffer[CTRL_IDX] & CMD_MASK) == WRITE_CMD) {
        /* Clear Tx Buffer */
        UART_clearBuffer(&UART_handle->txMsg);

        /* Prepare Tx Header */
        UART_prepareTxHeader(&UART_handle->txMsg);

        UART_writeCommand(&UART_handle->txMsg, UART_handle->dataLen,
            u32(&UART_handle->rxMsg.buffer[MEM_ADDR_IDX]),
            &UART_handle->rxMsg.buffer[DATA_IDX]);

        /* Prepare Tx Trailer */
        UART_prepareTxTrailer(&UART_handle->txMsg, UART_handle->isCrc);

        UART_handle->status = UART_STATUS_TX_TRANSMITTING;

        /* Send Tx Buffer */
        UART_sendBuffer(&UART_handle->txMsg);

        UART_handle->status = UART_STATUS_IDLE;
    }

    return;
}

static void UART_readCommand(BufferInfo *frame, uint8_t len, uint32_t addr)
{
    /* Add Len in Tx Buffer*/
    frame->buffer[frame->ptr++] = len - 1;

    while (len > 0) {
        uint8_t *dataPtr;
        dataPtr                   = (uint8_t *) addr;
        frame->buffer[frame->ptr] = *dataPtr;
        frame->ptr += 1;
        len -= 1;
        addr += 1;
    }
}

static void UART_writeCommand(
    BufferInfo *frame, uint8_t len, uint32_t addr, uint8_t *data)
{
    uint8_t i = 0;
    /* Add Len in Tx Buffer*/
    frame->buffer[frame->ptr++] = 0;

    while (len > 0) {
        uint8_t *dataPtr;
        dataPtr  = (uint8_t *) addr;
        *dataPtr = data[i];
        i += 1;
        len -= 1;
        addr += 1;
    }

    frame->buffer[frame->ptr++] = ACK_WRITE;
    return;
}

static void UART_sendBuffer(BufferInfo *frame)
{
    DL_DMA_setSrcAddr(DMA, DMA_CH1_CHAN_ID, (uint32_t) &frame->buffer[0]);
    DL_DMA_setDestAddr(DMA, DMA_CH1_CHAN_ID, (uint32_t) &UART_0_INST->TXDATA);
    DL_DMA_setTransferSize(DMA, DMA_CH1_CHAN_ID, frame->len);
    DL_DMA_enableChannel(DMA, DMA_CH1_CHAN_ID);
}

static void UART_verifyBuffer(UART_Instance *UART_handle)
{
    /* Verify start byte */
    if (UART_handle->rxMsg.buffer[START_IDX] != FRAME_START_BYTE) {
        UART_handle->error = ERROR_TYPE_MISMATCH_START_BYTE;
        return;
    }

    /* Verify Target Address */
    if (TARGET_ADDR_SIZE == 1 &&
        UART_handle->rxMsg.buffer[TARGET_ADDR_IDX] != TARGET_ADDR &&
        UART_handle->rxMsg.buffer[TARGET_ADDR_IDX] != BROADCAST_ADDR) {
        UART_handle->error = ERROR_TYPE_MISMATCH_TARGET_ADDR;
        return;
    }

    /* Verify end byte */
    if (UART_handle->rxMsg.buffer[UART_handle->rxMsg.len - END_OFFSET] !=
        FRAME_END_BYTE) {
        UART_handle->error = ERROR_TYPE_MISMATCH_END_BYTE;
        return;
    }

    /* Verify Address is in the range */
    uint32_t addr = u32(&UART_handle->rxMsg.buffer[MEM_ADDR_IDX]);
    if (addr < MEM_ADDR_RANGE_START ||
        addr + UART_handle->dataLen > MEM_ADDR_RANGE_END) {
        UART_handle->error = ERROR_TYPE_ADDR_RANGE;
        return;
    }

    /* Verify CRC16 */
    if (UART_handle->isCrc) {
        uint8_t size = HEADER_SIZE + MEM_ADDR_SIZE + UART_handle->dataLen;
        if ((UART_handle->rxMsg.buffer[CTRL_IDX] & CMD_MASK) == READ_CMD) {
            size = HEADER_SIZE + MEM_ADDR_SIZE + 0;
        }
        uint16_t checkSum =
            CRC_calc16((&UART_handle->rxMsg.buffer[START_IDX]), size);
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

static void UART_prepareTxHeader(BufferInfo *txMsg)
{
    /* Add Preamble bytes */
    for (int i = 0; i < PREAMBLE_BYTE_SIZE; i++) {
        txMsg->buffer[txMsg->ptr++] = PREAMBLE_BYTE;
    }

    /* Add Start Byte */
    txMsg->buffer[txMsg->ptr++] = FRAME_START_BYTE;

    /* Add Target Address */
    if (TARGET_ADDR_SIZE == 1) {
        txMsg->buffer[txMsg->ptr++] = TARGET_ADDR;
    }

    return;
}

static void UART_prepareTxTrailer(BufferInfo *txMsg, _Bool isCrc)
{
    if (isCrc) {
        /* Calculate CRC16 */
        /* From Start byte to end of data byte */
        uint8_t size = txMsg->ptr - PREAMBLE_BYTE_SIZE;
        /* Send address of startbyte */
        uint16_t checkSum =
            CRC_calc16(&txMsg->buffer[PREAMBLE_BYTE_SIZE], size);

        /* Add Checksum */
        u8From16(&txMsg->buffer[txMsg->ptr], checkSum);
        txMsg->ptr += 2;
    }

    /* Add End byte */
    txMsg->buffer[txMsg->ptr++] = FRAME_END_BYTE;

    txMsg->len = txMsg->ptr;
    txMsg->ptr = 0;

    return;
}

void DMA_RX_init(UART_Instance *UART_handle)
{
    DL_DMA_disableChannel(DMA, DMA_CH0_CHAN_ID);

    DL_DMA_setSrcAddr(DMA, DMA_CH0_CHAN_ID, (uint32_t) &UART_0_INST->RXDATA);
    DL_DMA_setDestAddr(
        DMA, DMA_CH0_CHAN_ID, (uint32_t) &UART_handle->rxMsg.buffer[0]);
    DL_DMA_setTransferSize(DMA, DMA_CH0_CHAN_ID, DMA_RX_TRANSFER_SIZE);

    DL_DMA_Full_Ch_setEarlyInterruptThreshold(
        DMA, DMA_CH0_CHAN_ID, DL_DMA_EARLY_INTERRUPT_THRESHOLD_64);
    DL_DMA_enableInterrupt(DMA, DL_DMA_FULL_CH_INTERRUPT_EARLY_CHANNEL0);

    DL_DMA_enableChannel(DMA, DMA_CH0_CHAN_ID);
}

static uint16_t CRC_calc16(uint8_t *ptr, uint8_t size)
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
