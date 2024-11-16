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
/* clang-format off */
#include <string.h>

#include <ti/drivers/dpl/HwiP.h>
#include <ti/devices/DeviceFamily.h>
#include <ti/drivers/uart/UARTMSPM0.h>

extern const uint_least8_t UART_count;
extern const UART_Params UART_defaultParams;

static int_fast16_t UART_writeBufferedMode(UART_Handle handle,
    const void *buf, size_t size, size_t *bytesWritten, uint8_t mode);
static int_fast16_t UART_readBufferedMode(UART_Handle handle, void *buf,
    size_t size, size_t *bytesRead, uint8_t mode);


/*
 * ======== UART_readBufferedMode ========
 */
static int_fast16_t UART_readBufferedMode(UART_Handle handle, void *buf,
    size_t size, size_t *bytesRead, uint8_t mode)
{
    UART_Object *uartObject                = UART_Obj_Ptr(handle);
    UART_Buffers_Object *buffersObject = UART_buffersObject(uartObject);

    uint8_t *data                      = (uint8_t *) (buf);
    uint_fast16_t count                = 0;
    int_fast16_t result                = UART_STATUS_SUCCESS;
    uintptr_t key;

    key                = HwiP_disable();
    uartObject->readCancel = false;
    HwiP_restore(key);

    while (size - count)
    {
        /* Wait on Semaphore until a character has been received */
        /* The semaphore will be posted by ISR once the char is received, till that time
        * the task calling this function will be in sleep state */
        SemaphoreP_pend(buffersObject->rxSem, SemaphoreP_WAIT_FOREVER);

        if (uartObject->readCancel)
        {
            result = UART_STATUS_ECANCELLED;
            break;
        }
        count += RingBuf_getn(&buffersObject->rxBuf, ((uint8_t *) data) + count, size - count);

        if (mode == UART_Mode_NONBLOCKING)
        {
            if (count == 0)
            {
                result = UART_STATUS_EAGAIN;
            }
            break;
        }
    }
    if (bytesRead)
    {
        *bytesRead = count;
    }
    return result;
}

/*
 * ======== UART_writeBufferedMode ========
 */
static int_fast16_t UART_writeBufferedMode(UART_Handle handle,
    const void *buf, size_t size, size_t *bytesWritten, uint8_t mode)
{
    UART_Object *uartObject                = UART_Obj_Ptr(handle);
    UART_Buffers_Object *buffersObject = UART_buffersObject(uartObject);
    const uint8_t *data                = (const uint8_t *) (buf);
    uint_fast16_t count                = 0;
    int_fast16_t result                = UART_STATUS_SUCCESS;
    uintptr_t key;

    key                 = HwiP_disable();
    uartObject->writeCancel = false;
    HwiP_restore(key);

    while (size - count)
    {
        /* Wait for Semaphore to indicate that earlier transfer is over and
        * we are ready to load the buffer again */
        SemaphoreP_pend(buffersObject->txSem, SemaphoreP_WAIT_FOREVER );

        count += RingBuf_putn(&buffersObject->txBuf, ((uint8_t *) data) + count, size - count);

        if (mode == UART_Mode_NONBLOCKING)
        {
            if (count == 0)
            {
                result = UART_STATUS_EAGAIN;
            }
            break;
        }
        uartObject->supportFxns->txChar(handle);

        if (uartObject->writeCancel)
        {
            result = UART_STATUS_ECANCELLED;
            break;
        }
    }
    if (bytesWritten)
    {
        *bytesWritten = count;
    }
    return result;
}

/*
 * ======== UART_readBuffered ========
 */
int_fast16_t UART_readBuffered(UART_Handle handle, void *buf, size_t size, size_t *bytesRead)
{
    UART_Object *object = UART_Obj_Ptr(handle);

    return UART_readBufferedMode(handle, buf, size, bytesRead, object->readMode);
}

/*
 * ======== UART_writeBuffered ========
 */
int_fast16_t UART_writeBuffered(UART_Handle handle, const void *buf, size_t size, size_t *bytesWritten)
{
    UART_Object *object = UART_Obj_Ptr(handle);

    return UART_writeBufferedMode(handle, buf, size, bytesWritten, object->writeMode);
}

/*
 * ======== UART_readCallback ========
 */
int_fast16_t UART_readCallback(UART_Handle handle, void *buf, size_t size, size_t *bytesRead)
{
    UART_Object *object                  = UART_Obj_Ptr(handle);
    UART_Buffers_Object *buffersObject   = UART_buffersObject(object);
    UART_Callback_Object *callbackObj = UART_callbackObject(object);
    uintptr_t key;

    SemaphoreP_pend(buffersObject->rxSem, SemaphoreP_WAIT_FOREVER);

    key = HwiP_disable();
    if (object->readInUse)
    {
        HwiP_restore(key);
        return UART_STATUS_EINUSE;
    }

    object->readInUse         = true;
    callbackObj->bytesRead = 0;
    callbackObj->readBuf   = buf;
    callbackObj->readSize  = size;
    callbackObj->readCount = size;  /* bytes left to read */
    callbackObj->bytesRead = 0;
    callbackObj->rxStatus  = 0;  /* Clear receive errors */

    UARTMSP_enableInts(handle);
#if ((DeviceFamily_PARENT == DeviceFamily_PARENT_MSPM0G1X0X_G3X0X)||(DeviceFamily_PARENT == DeviceFamily_PARENT_MSPM0L122X_L222X))
    UARTMSP_dmaRx(handle, false);
#endif
    HwiP_restore(key);

    return UART_STATUS_SUCCESS;
}

/*
 * ======== UART_writeCallback ========
 */
int_fast16_t UART_writeCallback(UART_Handle handle, const void *buf, size_t size, size_t *bytesWritten)
{
    UART_Object *object                  = UART_Obj_Ptr(handle);
    UART_Buffers_Object *buffersObject   = UART_buffersObject(object);
    UART_Callback_Object *callbackObj = UART_callbackObject(object);
    uintptr_t key;
    int space;
    static unsigned char *dstAddr;

    /* Wait until TX semaphore is available */
    SemaphoreP_pend(buffersObject->txSem, SemaphoreP_WAIT_FOREVER);

    key = HwiP_disable();

    if (object->writeInUse)
    {
        HwiP_restore(key);
        return UART_STATUS_EINUSE;
    }
    object->writeInUse           = true;
    callbackObj->bytesWritten = 0;
    callbackObj->writeBuf     = buf;
    callbackObj->writeSize    = size;
    callbackObj->writeCount   = size;
    callbackObj->txStatus     = 0;

    /* Copy as much data as we can to the ring buffer */
    do {
        /*
         *  Get the number of bytes we can copy to the ring buffer
         *  and the location where we can start the copy into the
         *  ring buffer.
         */
        space = RingBuf_putPointer(&buffersObject->txBuf, &dstAddr);  /* dstaddr is being loaded with an address of ring buffer */

        key = HwiP_disable();
        if (space > callbackObj->writeCount)
        {
            space = callbackObj->writeCount;
        }
        memcpy(dstAddr, (unsigned char *) callbackObj->writeBuf + callbackObj->bytesWritten, space);

        /* Update the ring buffer state with the number of bytes copied */
        RingBuf_putAdvance(&buffersObject->txBuf, space);

        callbackObj->writeCount -= space;
        callbackObj->bytesWritten += space;

        HwiP_restore(key);
    } while ((space > 0) && (callbackObj->writeCount > 0));

    object->supportFxns->txChar(handle);
    HwiP_restore(key);

    return UART_STATUS_SUCCESS;
}

/*
 * ======== UART_readFullFeatured ========
 */
int_fast16_t UART_readFullFeatured(UART_Handle handle, void *buf, size_t size, size_t *bytesRead)
{
    UART_Object *object = UART_Obj_Ptr(handle);

    if (object->buffersSupported && object->readMode != UART_Mode_CALLBACK)
    {
        return UART_readBuffered(handle, buf, size, bytesRead);
    }
    if (object->callbacksSupported && object->readMode == UART_Mode_CALLBACK)
    {
        return UART_readCallback(handle, buf, size, bytesRead);
    }
    return UART_STATUS_EINVALID;
}

/*
 * ======== UART_writeFullFeatured ========
 */
int_fast16_t UART_writeFullFeatured(UART_Handle handle, const void *buf, size_t size, size_t *bytesWritten)
{
    UART_Object *object = UART_Obj_Ptr(handle);

    if (object->buffersSupported && object->writeMode != UART_Mode_CALLBACK)
    {
        return UART_writeBuffered(handle, buf, size, bytesWritten);
    }
    if (object->callbacksSupported && object->writeMode == UART_Mode_CALLBACK)
    {
        return UART_writeCallback(handle, buf, size, bytesWritten);
    }
    return UART_STATUS_EINVALID;
}

/*
 * ======== UART_Params_init ========
 */
void UART_Params_init(UART_Params *params)
{
    *params = UART_defaultParams;
}

/*
 * ======== UART_open ========
 */
UART_Handle UART_open(uint_least8_t index, UART_Params *params)
{
    /* Check for callback when in UART_Mode_CALLBACK */
    if (((params->readMode == UART_Mode_CALLBACK) && (params->readCallback == NULL)) ||
        ((params->writeMode == UART_Mode_CALLBACK) && (params->writeCallback == NULL)))
    {
        return (NULL);
    }

    if (index < UART_count)
    {
        UART_Handle handle = (UART_Handle)&UART_config[index];
        UART_Object *object = handle->object;
        uintptr_t key       = HwiP_disable();

        if (!object->inUse)
        {
            /* not already open */
            object->inUse = true;
            HwiP_restore(key);

            if (object->supportFxns->enable(handle, params))
            {
                /* enable successful */
                object->returnMode = params->readReturnMode;
                object->readMode   = params->readMode;
                object->writeMode  = params->writeMode;

                if (object->callbacksSupported)  /* if callbacks are supported */
                {
                    UART_Callback_Object *callbackObject = UART_callbackObject(object);
                    if(params->readCallback != NULL)
                    {
                        callbackObject->readCallback  = params->readCallback;
                    }
                    if(params->writeCallback != NULL)
                    {
                        callbackObject->writeCallback = params->writeCallback;
                    }
                }
                return handle;
            }
            key           = HwiP_disable();
            object->inUse = false;
            HwiP_restore(key);
        }
        else
        {
            /* already open */
            HwiP_restore(key);
        }
    }
    return NULL;
}

/*
 * ======== UART_close ========
 */
void UART_close(UART_Handle handle)
{
    UART_Object *object = UART_Obj_Ptr(handle);
    uintptr_t key;
    /* cancel ongoing read/write */
    UART_readCancel(handle);
    key = HwiP_disable();

    object->inUse = false;
    HwiP_restore(key);

    object->supportFxns->disable(handle);
    return;
}

/*
 * ======== UART_read ========
 */
int_fast16_t UART_read(UART_Handle handle, void *buf, size_t size, size_t *bytesRead)
{
    UART_Object *object = UART_Obj_Ptr(handle);
    int_fast16_t result;

    result = object->supportFxns->read(handle, buf, size, bytesRead);
    if (bytesRead)
    {
        *bytesRead = result < 0 ? 0 : *bytesRead;
    }

    return result < 0 ? result : UART_STATUS_SUCCESS;
}

/*
 * ======== UART_write ========
 */
int_fast16_t UART_write(UART_Handle handle, const void *buf, size_t size, size_t *bytesWritten)
{
    UART_Object *object = UART_Obj_Ptr(handle);
    int_fast16_t result;

    result = object->supportFxns->write(handle, buf, size, bytesWritten);

    if (bytesWritten)
    {
        *bytesWritten = result < 0 ? 0 : *bytesWritten;
    }

    return result < 0 ? result : UART_STATUS_SUCCESS;
}

/*
 * ======== UART_readTimeout ========
 */
int_fast16_t UART_readTimeout(UART_Handle handle, void *buf, size_t size, size_t *bytesRead, uint32_t timeout)
{
    UART_Object *object                = UART_Obj_Ptr(handle);
    UART_Buffers_Object *buffersObject = UART_buffersObject(object);
    uint8_t *data                      = (uint8_t *) (buf);
    int_fast16_t count                 = 0;
    int_fast16_t result;
    int_fast16_t bytesToRead;

    if (object->readMode == UART_Mode_CALLBACK)
    {
        return UART_STATUS_EINVALID;
    }

    bytesToRead = object->returnMode == UART_ReadReturnMode_FULL ? size : 1;

    while (1)
    {
        result = UART_readBufferedMode(handle, data, size, bytesRead, UART_Mode_NONBLOCKING);
        if (result >= 0)
        {
            count += *bytesRead;
            size -= *bytesRead;
            data += *bytesRead;
        }
        if (count >= bytesToRead)
        {
            break;
        }
        if (SemaphoreP_TIMEOUT == SemaphoreP_pend(buffersObject->rxSem, timeout))
        {
            object->readTimedOut = true;
            break;
        }
    }
    if (object->readMode != UART_Mode_CALLBACK)
    {
        object->readInUse = false;
    }
    if (bytesRead)
    {
        *bytesRead = count;
    }
    return (count < size) ? UART_STATUS_ETIMEOUT : UART_STATUS_SUCCESS;
}

/*
 * ======== UART_writeTimeout ========
 */
int_fast16_t UART_writeTimeout(UART_Handle handle, const void *buf,
    size_t size, size_t *bytesWritten, uint32_t timeout)
{
    UART_Object *object                = UART_Obj_Ptr(handle);
    UART_Buffers_Object *buffersObject = UART_buffersObject(object);
    const uint8_t *data                = (const uint8_t *) (buf);
    int_fast16_t count                 = 0;
    int_fast16_t result;

    if (object->readMode == UART_Mode_CALLBACK)
    {
        return UART_STATUS_EINVALID;
    }

    while (1)
    {
        result = UART_writeBufferedMode(handle, data, size, bytesWritten, UART_Mode_NONBLOCKING);
        if (result > 0)
        {
            count += result;
            size -= result;
            data += result;
        }
        if (count >= size)
        {
            break;
        }
        if (SemaphoreP_TIMEOUT == SemaphoreP_pend(buffersObject->txSem, timeout))
        {
            object->writeTimedOut = true;
            break;
        }
    }
    /* Don't set writeInUse to false for callback mode if not done. */
    if (object->writeMode != UART_Mode_CALLBACK)
    {
        object->writeInUse = false;
    }
    if (bytesWritten)
    {
        *bytesWritten = count;
    }
    return (count < size) ? UART_STATUS_ETIMEOUT : UART_STATUS_SUCCESS;
}

/*
 * ======== UART_readCancel ========
 */
void UART_readCancel(UART_Handle handle)
{
    UART_Object *object = UART_Obj_Ptr(handle);
    uintptr_t key;

    key = HwiP_disable();

    if (object->readMode == UART_Mode_CALLBACK)
    {
        UART_Callback_Object *callbackObject = UART_callbackObject(object);

        if (object->readInUse)
        {
            uint8_t *readBuf   = callbackObject->readBuf;
            uint16_t readSize  = callbackObject->readSize;
            uint16_t bytesRead = callbackObject->bytesRead;

            /* We need to clear the in use flag so that the callback can setup
             * another read transaction.
             */
            object->readInUse = false;

            callbackObject->readCallback(handle, readBuf, bytesRead,
                object->userArg, readSize != bytesRead ? UART_STATUS_ECANCELLED : UART_STATUS_SUCCESS);
        }
        HwiP_restore(key);
    }
    else
    {
        UART_Buffers_Object *buffersObject = UART_buffersObject(object);
        object->readCancel                 = true;

        HwiP_restore(key);
        SemaphoreP_post(buffersObject->rxSem);
    }
}

/*
 *  ======== UART_writeCancel ========
 */
void UART_writeCancel(UART_Handle handle)
{
    UARTMSP_HWAttrs *hwAttrs           = UART_HWAttrs_Ptr(handle);
    UART_Object *object = UART_Obj_Ptr(handle);
    UART_Buffers_Object *buffersObject = UART_buffersObject(object);
    UART_Callback_Object *callbackObject = UART_callbackObject(object);
    uintptr_t key;

    key = HwiP_disable();

    if (!object->writeCancel)
    {
        object->writeCancel = true;

#if ((DeviceFamily_PARENT == DeviceFamily_PARENT_MSPM0G1X0X_G3X0X)||(DeviceFamily_PARENT == DeviceFamily_PARENT_MSPM0L122X_L222X))
        /* Stop DMA transaction */
        UARTMSP_dmaStopTx(handle);
#endif
        if (object->writeInUse)
        {
            /* If the UART peripheral is actively transmitting, wait for it to clear the TX FIFO */
            while (!DL_UART_isTXFIFOEmpty(hwAttrs->regs)) {}

            /* If in blocking mode, wake up the blocked write task */
            if (object->writeMode == UART_Mode_BLOCKING)
            {
                SemaphoreP_post(&buffersObject->txSem);
            }

            /* Invoke callback if in callback mode */
            if (object->writeMode == UART_Mode_CALLBACK)
            {
                object->writeInUse = false;
                callbackObject->writeCount = 0;
                callbackObject->writeCallback(handle,
                                      (void *)callbackObject->writeBuf,
                                      callbackObject->bytesWritten,
                                      callbackObject->userArg,
                                      UART_STATUS_ECANCELLED);
            }
        }
    }

    HwiP_restore(key);
}

/* clang-format on */
