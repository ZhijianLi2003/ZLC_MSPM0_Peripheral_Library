/*
 * Copyright (c) 2022-2023, Texas Instruments Incorporated
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

/*
 *  ======== I2CMSPM0.c ========
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include <ti/drivers/GPIO.h>
#include <ti/drivers/i2c/I2CMSPM0.h>

#ifdef POWER_MANAGEMENT_MSPM0
#include <ti/drivers/Power.h>
#include <ti/drivers/power/PowerMSPM0.h>
#endif

#include <ti/drivers/dpl/DebugP.h>
#include <ti/drivers/dpl/HwiP.h>
#include <ti/drivers/dpl/SemaphoreP.h>
#include <ti/drivers/dpl/SwiP.h>

/* Driverlib header files */
#include <ti/devices/DeviceFamily.h>

/*
 *  =============================== Macros =====================================
 *
 * Specific I2C CMD MACROs that are not defined in I2C.h are defined here. Their
 * equivalent values are taken from the existing MACROs in I2C.h
 *
 */
#ifndef I2C_CONTROLLER_CMD_BURST_RECEIVE_START_NACK
#define I2C_CONTROLLER_CMD_BURST_RECEIVE_START_NACK \
    I2C_CONTROLLER_CMD_BURST_SEND_START
#endif

#ifndef I2C_CONTROLLER_CMD_BURST_RECEIVE_STOP
#define I2C_CONTROLLER_CMD_BURST_RECEIVE_STOP \
    I2C_CONTROLLER_CMD_BURST_RECEIVE_ERROR_STOP
#endif

#ifndef I2C_CONTROLLER_CMD_BURST_RECEIVE_CONT_NACK
#define I2C_CONTROLLER_CMD_BURST_RECEIVE_CONT_NACK \
    I2C_CONTROLLER_CMD_BURST_SEND_CONT
#endif

#define I2CMSPM0_ERROR_INTS                            \
    (DL_I2C_INTERRUPT_CONTROLLER_NACK |                \
        DL_I2C_INTERRUPT_CONTROLLER_ARBITRATION_LOST | \
        DL_I2C_INTERRUPT_TIMEOUT_A | DL_I2C_INTERRUPT_TIMEOUT_B)

#define I2CMSPM0_TRANSFER_INTS \
    (DL_I2C_INTERRUPT_CONTROLLER_STOP | I2CMSPM0_ERROR_INTS)

#define I2CMSPM0_FIFO_SIZE 8
#define I2CMSPM0_MAX_BURST 255

/* Prototypes */
static void I2CMSPM0_blockingCallback(
    I2C_Handle handle, I2C_Transaction *msg, bool transferStatus);
static void I2CMSPM0_completeTransfer(I2C_Handle handle, uint32_t intStatus);
static void I2CMSPM0_hwiFxn(uintptr_t arg);
static void I2CMSPM0_initHw(I2C_Handle handle);
static int_fast16_t I2CMSPM0_initIO(I2C_Handle handle, void *pinCfg);
static int I2CMSPM0_postNotify(
    unsigned int eventType, uintptr_t eventArg, uintptr_t clientArg);
static void I2CMSPM0_primeReadBurst(
    I2CMSPM0_Object *object, I2CMSPM0_HWAttrs const *hwAttrs);
static void I2CMSPM0_primeWriteBurst(
    I2CMSPM0_Object *object, I2CMSPM0_HWAttrs const *hwAttrs);
static uint16_t I2CMSPM0_fillTransmitFifo(
    I2CMSPM0_Object *object, I2CMSPM0_HWAttrs const *hwAttrs);
static void I2C_waitTillBusAvailable(I2CMSPM0_HWAttrs const *hwAttrs);
/* Default I2C parameters structure */
static const I2C_Params I2C_defaultParams = {
    I2C_MODE_BLOCKING, /* transferMode */
    NULL,              /* transferCallbackFxn */
    I2C_100kHz,        /* bitRate */
    NULL               /* custom */
};

/*
 *  ======== I2CMSPM0_fillTransmitFifo ========
 */
static uint16_t I2CMSPM0_fillTransmitFifo(
    I2CMSPM0_Object *object, I2CMSPM0_HWAttrs const *hwAttrs)
{
    uint16_t count = 0;

    if (object->writeCount) {
        count = DL_I2C_fillControllerTXFIFO(
            hwAttrs->i2c, (uint8_t *) object->writeBuf, object->writeCount);
        /*decrement the counter to update the number of bytes to write*/
        object->writeCount -= count;
        /*increment the buffer pointer with bytes written*/
        object->writeBuf += count;
        object->burstCount -= count;
    }
    DL_I2C_clearInterruptStatus(
        hwAttrs->i2c, DL_I2C_INTERRUPT_CONTROLLER_TXFIFO_EMPTY);

    return count;
}

/*
 *  ======== I2CMSPM0_readReceiveFifo ========
 */
static void I2CMSPM0_readReceiveFifo(
    I2CMSPM0_Object *object, I2CMSPM0_HWAttrs const *hwAttrs)
{
    if (object->readCount && object->burstCount) {
        /* Read data */
        while (DL_I2C_isControllerRXFIFOEmpty(hwAttrs->i2c) != true) {
            if (object->readCount >= 1) {
                *(object->readBuf++) =
                    DL_I2C_receiveControllerData(hwAttrs->i2c);
                object->readCount--;
                object->burstCount--;
            } else {
                /* Ignore and remove from FIFO if the buffer is full */
                DL_I2C_receiveControllerData(hwAttrs->i2c);
            }
        }
    }
    DL_I2C_clearInterruptStatus(
        hwAttrs->i2c, (DL_I2C_INTERRUPT_CONTROLLER_RXFIFO_FULL |
                          DL_I2C_INTERRUPT_CONTROLLER_RXFIFO_TRIGGER));
}

/*!
 *  ======== I2C_close ========
 *  @brief Function to close a given MSPM0 I2C peripheral specified by the
 *         I2C handle.
 *
 *  After calling the close function, the I2C is disabled.
 *
 *  @pre    I2C_open() has to be called first.
 *          Calling context: Task
 *
 *  @param handle An I2C_Handle returned by I2C_open()
 *
 *  @note  The generic I2C API should be used when accessing the I2CMSPM0.
 *
 *  @sa     I2C_open(), I2C_close(), I2C_open()
 */
void I2C_close(I2C_Handle handle)
{
    /* Get the pointer to the object and hwAttrs */
    I2CMSPM0_Object *object         = handle->object;
    I2CMSPM0_HWAttrs const *hwAttrs = handle->hwAttrs;

    /* Check to see if a I2C transaction is in progress */
    DebugP_assert(object->headPtr == NULL);

    /* Mask I2C interrupts */
    DL_I2C_disableInterrupt(hwAttrs->i2c, I2C_CONTROLLER_INTERRUPTS_MASK);

    /* Disable the I2C Controller */
    DL_I2C_disableController(hwAttrs->i2c);

    /* Deallocate pins */
    GPIO_resetConfig(hwAttrs->sclPinIndex);
    GPIO_resetConfig(hwAttrs->sdaPinIndex);

    /* Power off the I2C module */
#ifdef POWER_MANAGEMENT_MSPM0
    Power_releaseDependency(hwAttrs->powerMngrId);
#endif
    /* Destruct modules used in driver */
    HwiP_destruct(&(object->hwi));

    SemaphoreP_destruct(&(object->mutex));

    if (object->transferMode == I2C_MODE_BLOCKING) {
        SemaphoreP_destruct(&(object->transferComplete));
    }

    /* Unregister power post notification object */
#ifdef POWER_MANAGEMENT_MSPM0
    Power_unregisterNotify(&object->i2cPostObj);
#endif
    /* Mark the module as available */
    object->isOpen = false;

    return;
}

/*!
 *  ======== I2C_control ========
 *  @brief  Function for setting control parameters of the I2C driver
 *          after it has been opened.
 *
 *  @pre    Function assumes that the handle is not NULL
 *
 *  @note   Currently not in use.
 */
int_fast16_t I2C_control(I2C_Handle handle, uint_fast16_t cmd, void *arg)
{
    /* No implementation */
    return (I2C_STATUS_UNDEFINEDCMD);
}

/*!
 *  ======== I2C_open ========
 *  @brief Function to initialize a given I2C MSPM0 peripheral specified by the
 *         particular handle. The parameter specifies which mode the I2C
 *         will operate.
 *
 *  After calling the open function, the I2C is enabled. If there is no active
 *  I2C transactions, the device can enter standby.
 *
 *  @pre    The I2CMSPM0_Config structure must exist and be persistent before this
 *          function can be called. I2CMSPM0 has been initialized with I2C_open().
 *          Calling context: Task
 *
 *  @param  handle   An I2C_Handle
 *
 *  @param  params   Pointer to a parameter block, if NULL it will use default values.
 *
 *  @return A I2C_Handle on success, or a NULL on an error or if it has been
 *          already opened.
 *
 *  @note  The generic I2C API should be used when accessing the I2CMSPM0.
 *
 *  @sa     I2C_close(), I2C_open()
 */
I2C_Handle I2C_open(uint_least8_t index, I2C_Params *params)
{
    I2C_Handle handle = NULL;
    HwiP_Params hwiParams;
    uintptr_t key;
    I2CMSPM0_Object *object;
    I2CMSPM0_HWAttrs const *hwAttrs;

    if (index < I2C_count) {
        if (params == NULL) {
            params = (I2C_Params *) &I2C_defaultParams;
        }

        handle  = (I2C_Handle) & (I2C_config[index]);
        hwAttrs = handle->hwAttrs;
        object  = handle->object;
    } else {
        return (NULL);
    }

    /* Check for valid bit rate */
    DebugP_assert(params->bitRate <= I2C_1000kHz);

    /* Determine if the device index was already opened */
    key = HwiP_disable();
    if (object->isOpen == true) {
        HwiP_restore(key);
        return (NULL);
    }

    /* Mark the handle as being used */
    object->isOpen = true;
    HwiP_restore(key);

    /* Power on the I2C module */
#ifdef POWER_MANAGEMENT_MSPM0
    Power_setDependency(hwAttrs->powerMngrId);
#endif

    /* Configure the IOs.*/
    if (I2CMSPM0_initIO(handle, params->custom)) {
        /* Mark the module as available */
        key            = HwiP_disable();
        object->isOpen = false;
        HwiP_restore(key);
        /* Release dependency if open fails */
        /*Power_releaseDependency(hwAttrs->powerMngrId);*/
        /* Signal back to application that I2C driver was not successfully opened */
        return (NULL);
    }

    /* Save parameters */
    object->transferMode        = params->transferMode;
    object->transferCallbackFxn = params->transferCallbackFxn;
    object->bitRate             = params->bitRate;

    /* Disable and clear interrupts possible from soft resets */
    DL_I2C_disableInterrupt(hwAttrs->i2c, I2C_CONTROLLER_INTERRUPTS_MASK);
    DL_I2C_clearInterruptStatus(hwAttrs->i2c, I2C_CONTROLLER_INTERRUPTS_MASK);

    /* Create Hwi object for this I2C peripheral */
    HwiP_Params_init(&hwiParams);
    hwiParams.arg      = (uintptr_t) handle;
    hwiParams.priority = hwAttrs->intPriority;
    HwiP_construct(
        &(object->hwi), hwAttrs->intNum, I2CMSPM0_hwiFxn, &hwiParams);

    /*
     * Create thread safe handles for this I2C peripheral
     * Semaphore to provide exclusive access to the I2C peripheral
     */
    SemaphoreP_constructBinary(&(object->mutex), 1);

    /*
     * Store a callback function that posts the transfer complete
     * semaphore for synchronous mode
     */
    if (object->transferMode == I2C_MODE_BLOCKING) {
        /* Semaphore to cause the waiting task to block for the I2C to finish */
        SemaphoreP_constructBinary(&(object->transferComplete), 0);

        /* Store internal callback function */
        object->transferCallbackFxn = I2CMSPM0_blockingCallback;
    } else {
        /* Check to see if a callback function was defined for async mode */
        DebugP_assert(object->transferCallbackFxn != NULL);
    }

    /* Clear the head pointer */
    object->headPtr            = NULL;
    object->tailPtr            = NULL;
    object->currentTransaction = NULL;

    /* Initialize the I2C hardware module */
    I2CMSPM0_initHw(handle);

    /* Register notification functions */
    /* Power_registerNotify(&object->i2cPostObj,
                         PowerMSPM0_AWAKE_STANDBY,
                         (Power_NotifyFxn)I2CMSPM0_postNotify,
                         (uint32_t)handle);*/

    /* Return the address of the handle */
    return (handle);
}

/*
 *  ======== I2CMSPM0_hwiFxn ========
 *  Hwi interrupt handler to service the I2C peripheral
 *
 *  The handler is a generic handler for a I2C object.
 */
static void I2CMSPM0_hwiFxn(uintptr_t arg)
{
    I2C_Handle handle               = (I2C_Handle) arg;
    I2CMSPM0_Object *object         = handle->object;
    I2CMSPM0_HWAttrs const *hwAttrs = handle->hwAttrs;
    uint32_t command                = I2C_MCTR_BURSTRUN_ENABLE;
    uint32_t mask                   = I2C_MCTR_BURSTRUN_MASK;
    uint16_t count                  = 0;
    uint32_t intStatus              = 0;

    //Get the interrupts
    intStatus = DL_I2C_getEnabledInterruptStatus(
        hwAttrs->i2c, 0xFFFF);  //DL_I2C_getControllerStatus(hwAttrs->i2c);
    /* Current transaction is cancelled */
    if (object->currentTransaction->status == I2C_STATUS_CANCEL) {
        DL_I2C_enableStopCondition(hwAttrs->i2c);
        I2CMSPM0_completeTransfer(handle, intStatus);
        return;
    }

    if (intStatus & I2CMSPM0_ERROR_INTS) {
        /*since we have error detected, the status of the controller should be updated*/
        uint32_t status = DL_I2C_getControllerStatus(hwAttrs->i2c);

        /* Decode interrupt status */
        if (status & DL_I2C_CONTROLLER_STATUS_ARBITRATION_LOST) {
            object->currentTransaction->status = I2C_STATUS_ARB_LOST;
        } else if (status & DL_I2C_CONTROLLER_STATUS_DATA_ACK) {
            object->currentTransaction->status = I2C_STATUS_DATA_NACK;
        } else if (status & DL_I2C_CONTROLLER_STATUS_ADDR_ACK) {
            object->currentTransaction->status = I2C_STATUS_ADDR_NACK;
        } else {
            object->currentTransaction->status = I2C_STATUS_ERROR;
        }

        /* If arbitration is lost, another I2C controller owns the bus */
        if (status & DL_I2C_CONTROLLER_STATUS_ARBITRATION_LOST) {
            DL_I2C_enableStopCondition(hwAttrs->i2c);
            I2CMSPM0_completeTransfer(handle, intStatus);
            return;
        }
    } else if (intStatus & (DL_I2C_INTERRUPT_CONTROLLER_TXFIFO_EMPTY |
                               DL_I2C_INTERRUPT_CONTROLLER_TXFIFO_TRIGGER)) {
        /* If there is more data to transmit */
        if (object->writeCount) {
            /* If we need to configure a new burst */
            if (object->burstCount == 0) {
                I2CMSPM0_primeWriteBurst(object, hwAttrs);
            } else /*Fill the FIFO buffer for whatever space has left*/
            {
                I2CMSPM0_fillTransmitFifo(object, hwAttrs);
            }
        }
        /* Finished writing, is there data to receive? */
        else {
            /*Disable TX Interrupt*/
            DL_I2C_clearInterruptStatus(
                hwAttrs->i2c, (DL_I2C_INTERRUPT_CONTROLLER_TXFIFO_EMPTY |
                                  DL_I2C_INTERRUPT_CONTROLLER_TXFIFO_TRIGGER));
            if (object->readCount) {
                object->burstStarted = false;
                I2CMSPM0_primeReadBurst(object, hwAttrs);
            }
        }
    } else if (intStatus & (DL_I2C_INTERRUPT_CONTROLLER_RXFIFO_FULL |
                               DL_I2C_INTERRUPT_CONTROLLER_RXFIFO_TRIGGER)) {
        I2CMSPM0_readReceiveFifo(object, hwAttrs);

        /* If we need to configure a new burst */
        if (object->readCount && (object->burstCount == 0)) {
            I2CMSPM0_primeReadBurst(object, hwAttrs);
        } else {
            DL_I2C_clearInterruptStatus(
                hwAttrs->i2c, (DL_I2C_INTERRUPT_CONTROLLER_RXFIFO_FULL |
                                  DL_I2C_INTERRUPT_CONTROLLER_RXFIFO_TRIGGER));
        }
    } else if (intStatus & DL_I2C_INTERRUPT_CONTROLLER_RX_DONE) {
        DL_I2C_clearInterruptStatus(
            hwAttrs->i2c, DL_I2C_INTERRUPT_CONTROLLER_RX_DONE);
        /*Update the current transaction readCount*/
        object->currentTransaction->readCount = object->readCount;
        object->isReadInProgress              = false;
    } else if (intStatus & DL_I2C_INTERRUPT_CONTROLLER_TX_DONE) {
        DL_I2C_clearInterruptStatus(
            hwAttrs->i2c, (DL_I2C_INTERRUPT_CONTROLLER_TX_DONE |
                              DL_I2C_INTERRUPT_CONTROLLER_TXFIFO_TRIGGER));
        /*Update the current transaction writeCount*/
        object->currentTransaction->writeCount = object->writeCount;
        if (object->readCount) {
            object->burstStarted = false;
            I2CMSPM0_primeReadBurst(object, hwAttrs);
        }
    }
    /* If the STOP condition was set, complete the transfer */
    if (intStatus & DL_I2C_INTERRUPT_CONTROLLER_STOP) {
        /* If the transaction completed, update the transaction status */
        if (object->currentTransaction->status == I2C_STATUS_INCOMPLETE &&
            (!(object->readCount || object->writeCount))) {
            /* If both FIFOs are empty */
            if (DL_I2C_isControllerRXFIFOEmpty(hwAttrs->i2c) &&
                DL_I2C_isControllerTXFIFOEmpty(hwAttrs->i2c)) {
                object->currentTransaction->status = I2C_STATUS_SUCCESS;
            }
        }

        I2CMSPM0_completeTransfer(handle, intStatus);
    }
}

/*
 *  ======== I2C_setClockTimeout ========
 */
int_fast16_t I2C_setClockTimeout(I2C_Handle handle, uint32_t timeout)
{
    return (I2C_STATUS_ERROR);
}
#if 0
/*
 *  ======== I2CMSPM0_swiFxn ========
 *  SWI interrupt handler to service the I2C peripheral
 *
 *  Takes care of cleanup and the callback in SWI context after an I2C transfer
 */
/*static void I2CMSPM0_swiFxn(uintptr_t arg0, uintptr_t arg1)
{
    I2C_Handle handle        = (I2C_Handle)arg0;
    I2C_Object *object = handle->object;
    int_fast16_t status;

    /*
     *  If this current transaction was canceled, we need to cancel
     *  any queued transactions
     /
    if (object->currentTransaction->status == I2C_STATUS_CANCEL)
    {
        /*
         * Allow callback to run. If in CALLBACK mode, the application
         * may initiate a transfer in the callback which will call
         * primeTransfer().
         /
        object->transferCallbackFxn(handle, object->currentTransaction, false);
        object->currentTransaction->status = I2C_STATUS_CANCEL;

        /* release the constraint to disallow standby /
        Power_releaseConstraint(PowerMSPM0_DISALLOW_STANDBY);

        /* also dequeue and call the transfer callbacks for any queued transfers /
        while (object->headPtr != object->tailPtr)
        {
            object->headPtr         = object->headPtr->nextPtr;
            object->headPtr->status = I2C_STATUS_CANCEL;
            object->transferCallbackFxn(handle, object->headPtr, false);
            object->headPtr->status = I2C_STATUS_CANCEL;
        }

        /* clean up object /
        object->currentTransaction = NULL;
        object->headPtr            = NULL;
        object->tailPtr            = NULL;
    }
    else if (object->currentTransaction->status == I2C_STATUS_TIMEOUT)
    {
        /*
         * This can only occur in BLOCKING mode. No need to call the blocking
         * callback as the Semaphore has already timed out.
         /
        object->headPtr = NULL;
        object->tailPtr = NULL;

        /* Release standby disallow constraint. /
        Power_releaseConstraint(PowerMSPM0_DISALLOW_STANDBY);
    }
    /* See if we need to process any other transactions /
    else if (object->headPtr == object->tailPtr)
    {

        /* No other transactions need to occur /
        object->headPtr = NULL;
        object->tailPtr = NULL;

        /*
         * Allow callback to run. If in CALLBACK mode, the application
         * may initiate a transfer in the callback which will call
         * primeTransfer().
         /
        object->transferCallbackFxn(handle,
                                    object->currentTransaction,
                                    (object->currentTransaction->status == I2C_STATUS_SUCCESS));

        /* Release standby disallow constraint. /
        Power_releaseConstraint(PowerMSPM0_DISALLOW_STANDBY);
    }
    else
    {
        /* Another transfer needs to take place /
        object->headPtr = object->headPtr->nextPtr;

        /*
         * Allow application callback to run. The application may
         * initiate a transfer in the callback which will add an
         * additional transfer to the queue.
         /
        object->transferCallbackFxn(handle,
                                    object->currentTransaction,
                                    (object->currentTransaction->status == I2C_STATUS_SUCCESS));

        status = I2CSupport_primeTransfer(handle, object->headPtr);

        /* Call back now if not able to start transfer /
        if (status != I2C_STATUS_SUCCESS)
        {
            /* Transaction status set in primeTransfer()/
            SwiP_post(&(object->swi));
        }
    }
}*/
#endif
/*
 *  ======== I2CSupport_controllerFinish ========
 */
void I2CSupport_controllerFinish(I2C_HWAttrs const *hwAttrs)
{
    /* Asynchronously generate a STOP condition. */
    DL_I2C_enableStopCondition(hwAttrs->i2c);
}

/*
 *  ======== I2CSupport_powerRelConstraint =======
 */
void I2CSupport_powerRelConstraint(void)
{
    /* Release standby disallow constraint. */
    /*Power_releaseConstraint(PowerMSPM0_DISALLOW_STANDBY);*/
}

static void I2C_waitTillBusAvailable(I2CMSPM0_HWAttrs const *hwAttrs)
{
    while ((DL_I2C_getControllerStatus(hwAttrs->i2c) &
               DL_I2C_CONTROLLER_STATUS_BUSY) &&
           !(DL_I2C_getControllerStatus(hwAttrs->i2c) &
               DL_I2C_CONTROLLER_STATUS_IDLE)) {
        ;
    }
}
/*
 *  ======== I2CSupport_powerSetConstraint =======
 */
void I2CSupport_powerSetConstraint(void)
{
    /* Set standby disallow constraint. */
    /*Power_setConstraint(PowerMSPM0_DISALLOW_STANDBY);*/
}
/*
 *  ======== I2CMSPM0_primeReadBurst =======
 */
static void I2CMSPM0_primeReadBurst(
    I2CMSPM0_Object *object, I2CMSPM0_HWAttrs const *hwAttrs)
{
    if (object->isReadInProgress)
        return;
    else
        object->isReadInProgress = true;
    /* Wait until the bus is available */
    while (DL_I2C_getControllerStatus(hwAttrs->i2c) &
           DL_I2C_CONTROLLER_STATUS_BUSY)
        ;
    /* Disable the burst before setting up the new transaction */
    DL_I2C_disableControllerBurst(hwAttrs->i2c);

    /* Determine the size of this burst */
    if (object->readCount > I2CMSPM0_MAX_BURST) {
        object->burstCount = I2CMSPM0_MAX_BURST;
    } else {
        object->burstCount = object->readCount;
    }

    /*
     * If we are reading less than FIFO_SIZE bytes, set the MRXFIFOTRG
     * interrupt to trigger when we finish burstCount bytes.
     * If we are reading more than 8 bytes, set the MRXFIFOTRG
     * interrupt to trigger when full. If we are reading less than RXTRIG
     * bytes during the final byte reads, the RXDONE interrupt will allow
     * us to complete the read transaction.
     */
    if (object->burstCount < I2CMSPM0_FIFO_SIZE) {
        DL_I2C_setControllerRXFIFOThreshold(
            hwAttrs->i2c, (DL_I2C_RX_FIFO_LEVEL)((object->burstCount - 1)
                                                 << I2C_MFIFOCTL_RXTRIG_OFS));
    } else {
        DL_I2C_setControllerRXFIFOThreshold(
            hwAttrs->i2c, I2C_MFIFOCTL_RXTRIG_LEVEL_8);
    }

    DL_I2C_setTransactionLength(hwAttrs->i2c, object->burstCount);

    /* If we will be receiving multiple bursts */
    if (object->readCount > I2CMSPM0_MAX_BURST) {
        DL_I2C_disableStopCondition(hwAttrs->i2c);
    } else {
        DL_I2C_enableStopCondition(hwAttrs->i2c);
    }

    /* Only generate a start condition if the burst hasn't started */
    if (!object->burstStarted) {
        object->burstStarted = true;
    }

    DL_I2C_enableInterrupt(hwAttrs->i2c,
        DL_I2C_INTERRUPT_CONTROLLER_RXFIFO_TRIGGER |
            DL_I2C_INTERRUPT_CONTROLLER_RX_DONE |
            DL_I2C_INTERRUPT_CONTROLLER_RXFIFO_FULL | I2CMSPM0_TRANSFER_INTS);
    /* Set the target Address */
    DL_I2C_setTargetAddress(
        hwAttrs->i2c, object->currentTransaction->targetAddress);
    /* Set the controller direction */
    DL_I2C_setControllerDirection(
        hwAttrs->i2c, DL_I2C_CONTROLLER_DIRECTION_RX);
    /* Enable the start condition */
    DL_I2C_enableStartCondition(hwAttrs->i2c);
    /* Disable the manual ACK, hardware will ack automatically */
    DL_I2C_disableControllerACK(hwAttrs->i2c);
    /* Enable the burst run */
    DL_I2C_enableControllerBurst(hwAttrs->i2c);
}

/*
 *  ======== I2CMSPM0_primeWriteBurst =======
 */
static void I2CMSPM0_primeWriteBurst(
    I2CMSPM0_Object *object, I2CMSPM0_HWAttrs const *hwAttrs)
{
    /* Wait until bus is available */
    I2C_waitTillBusAvailable(hwAttrs);
    /* Disable the burst before setting up the new transaction */
    DL_I2C_disableControllerBurst(hwAttrs->i2c);
    /* Determine the size of this burst */
    if (object->writeCount > I2CMSPM0_MAX_BURST) {
        object->burstCount = I2CMSPM0_MAX_BURST;
    } else {
        object->burstCount = object->writeCount;
    }

    /* Write burst length */
    DL_I2C_setTransactionLength(hwAttrs->i2c, object->burstCount);

    /* If we will be sending multiple bursts */
    if (object->readCount || object->writeCount > I2CMSPM0_MAX_BURST) {
        DL_I2C_disableStopCondition(hwAttrs->i2c);
    } else {
        DL_I2C_enableStopCondition(hwAttrs->i2c);
    }

    /* Only generate a start condition if the burst hasn't started */
    if (!object->burstStarted) {
        object->burstStarted = true;
    }
    /*Before filling the FIFO, we need to clear the interrupt else it will trigger interrupt immediately*/
    DL_I2C_clearInterruptStatus(
        hwAttrs->i2c, DL_I2C_INTERRUPT_CONTROLLER_TXFIFO_TRIGGER);
    /* Fill transmit FIFO. This will modify the object counts */
    I2CMSPM0_fillTransmitFifo(object, hwAttrs);

    /* Enable TXFIFOEMPTY interrupt and other standard transfer interrupts */
    DL_I2C_enableInterrupt(hwAttrs->i2c,
        DL_I2C_INTERRUPT_CONTROLLER_TXFIFO_TRIGGER |
            DL_I2C_INTERRUPT_CONTROLLER_TX_DONE |
            DL_I2C_INTERRUPT_CONTROLLER_TXFIFO_EMPTY | I2CMSPM0_TRANSFER_INTS);
    /* Set the target Address */
    DL_I2C_setTargetAddress(
        hwAttrs->i2c, object->currentTransaction->targetAddress);
    /* Set the controller direction */
    DL_I2C_setControllerDirection(
        hwAttrs->i2c, DL_I2C_CONTROLLER_DIRECTION_TX);
    /* Enable the start condition */
    DL_I2C_enableStartCondition(hwAttrs->i2c);
    /* Disable the manual ACK, hardware will ack automatically */
    DL_I2C_disableControllerACK(hwAttrs->i2c);
    /* Enable the burst run */
    DL_I2C_enableControllerBurst(hwAttrs->i2c);
}

/*
 *  ======== I2CSupport_primeTransfer =======
 */
int_fast16_t I2CSupport_primeTransfer(
    I2C_Handle handle, I2C_Transaction *transaction)
{
    I2CMSPM0_Object *object         = handle->object;
    I2CMSPM0_HWAttrs const *hwAttrs = handle->hwAttrs;
    int_fast16_t status             = I2C_STATUS_SUCCESS;
    int_fast16_t count              = 0;

    /* Store the new internal counters and pointers */
    object->currentTransaction = transaction;

    object->writeBuf     = transaction->writeBuf;
    object->writeCount   = transaction->writeCount;
    object->readBuf      = transaction->readBuf;
    object->readCount    = transaction->readCount;
    object->burstCount   = 0;
    object->burstStarted = false;

    /*
     * Transaction is incomplete unless the stop condition occurs AND
     * all bytes have been sent and received. This condition is checked
     * in the hardware interrupt.
     */
    transaction->status = I2C_STATUS_INCOMPLETE;

    /* Flush the FIFOs */
    DL_I2C_flushControllerTXFIFO(hwAttrs->i2c);
    DL_I2C_flushControllerRXFIFO(hwAttrs->i2c);

    /* Determine if the bus is in use by another I2C Controller */
    if (DL_I2C_getControllerStatus(hwAttrs->i2c) &
        DL_I2C_CONTROLLER_STATUS_BUSY_BUS) {
        transaction->status = I2C_STATUS_BUS_BUSY;
        status              = I2C_STATUS_BUS_BUSY;
    }
    /* Start transfer in Transmit */
    else if (object->writeCount) {
        I2CMSPM0_primeWriteBurst(object, hwAttrs);
    } else {
        I2CMSPM0_primeReadBurst(object, hwAttrs);
    }

    return (status);
}

/*
 *  ======== I2CMSPM0_completeTransfer ========
 *  This function may be invoked in the context of the HWI.
 */
static void I2CMSPM0_completeTransfer(I2C_Handle handle, uint32_t intStatus)
{
    I2CMSPM0_Object *object         = handle->object;
    I2CMSPM0_HWAttrs const *hwAttrs = handle->hwAttrs;

    /* Disable and clear any interrupts */
    /* Disable and clear interrupts possible from soft resets */
    DL_I2C_disableInterrupt(hwAttrs->i2c, intStatus);
    DL_I2C_clearInterruptStatus(hwAttrs->i2c, intStatus);

    /*
     *  If this current transaction was canceled, we need to cancel
     *  any queued transactions
     */
    if (object->currentTransaction->status == I2C_STATUS_CANCEL) {
        /*
         * Allow callback to run. If in CALLBACK mode, the application
         * may initiate a transfer in the callback which will call
         * primeTransfer().
         */
        object->transferCallbackFxn(handle, object->currentTransaction, false);
        object->currentTransaction->status = I2C_STATUS_CANCEL;

        /*Power_releaseConstraint(PowerCC32XX_DISALLOW_LPDS);*/

        /* also dequeue and call the transfer callbacks for any queued transfers */
        while (object->headPtr != object->tailPtr) {
            object->headPtr         = object->headPtr->nextPtr;
            object->headPtr->status = I2C_STATUS_CANCEL;
            object->transferCallbackFxn(handle, object->headPtr, false);
            object->headPtr->status = I2C_STATUS_CANCEL;
        }

        /* clean up object */
        object->currentTransaction = NULL;
        object->headPtr            = NULL;
        object->tailPtr            = NULL;
    }
    /* See if we need to process any other transactions */
    else if (object->headPtr == object->tailPtr) {
        /* No other transactions need to occur */
        object->headPtr = NULL;
        object->tailPtr = NULL;

        /*
         * Allow callback to run. If in CALLBACK mode, the application
         * may initiate a transfer in the callback which will call
         * primeTransfer().
         */
        object->transferCallbackFxn(handle, object->currentTransaction,
            (object->currentTransaction->status == I2C_STATUS_SUCCESS));

        /* Release constraint since transaction is done */
        /* Power_releaseConstraint(PowerCC32XX_DISALLOW_LPDS);*/
    } else {
        /* Another transfer needs to take place */
        object->headPtr = object->headPtr->nextPtr;

        /*
         * Allow application callback to run. The application may
         * initiate a transfer in the callback which will add an
         * additional transfer to the queue.
         */
        object->transferCallbackFxn(handle, object->currentTransaction,
            (object->currentTransaction->status == I2C_STATUS_SUCCESS));

        I2CSupport_primeTransfer(handle, object->headPtr);
    }
}

/*
 *  ======== I2CMSPM0_blockingCallback ========
 */
static void I2CMSPM0_blockingCallback(
    I2C_Handle handle, I2C_Transaction *msg, bool transferStatus)
{
    I2CMSPM0_Object *object = handle->object;

    SemaphoreP_post(&(object->transferComplete));
}

/*
 *  ======== I2CMSPM0_initHw ========
 *  This functions initializes the I2C hardware module.
 *
 *  @pre    Function assumes that the I2C handle is pointing to a hardware
 *          module which has already been opened.
 */
static void I2CMSPM0_initHw(I2C_Handle handle)
{
    I2CMSPM0_Object *object         = handle->object;
    I2CMSPM0_HWAttrs const *hwAttrs = handle->hwAttrs;

    uint32_t divratio    = 0;
    uint32_t clkFreq     = 0;
    uint8_t TPR_Value    = 0;
    uint16_t bitRate_Mhz = 0;

    /* Disable and clear interrupts */
    DL_I2C_disableInterrupt(hwAttrs->i2c, I2C_CONTROLLER_INTERRUPTS_MASK);
    DL_I2C_clearInterruptStatus(hwAttrs->i2c, I2C_CONTROLLER_INTERRUPTS_MASK);
    DL_I2C_resetControllerTransfer(hwAttrs->i2c);

    /* Set the I2C configuration */

    DL_I2C_ClockConfig clockConfig = {
        .clockSel    = hwAttrs->clockSource,
        .divideRatio = hwAttrs->clockDivider,
    };
    DL_I2C_setClockConfig(hwAttrs->i2c, (DL_I2C_ClockConfig *) &clockConfig);
    /* Configure Controller Mode */
    DL_I2C_resetControllerTransfer(hwAttrs->i2c);

    switch (object->bitRate) {
        case I2C_100kHz:
            object->bitRate = 100;
            break;
        case I2C_400kHz:
            object->bitRate = 400;
            break;
        case I2C_1000kHz:
            object->bitRate = 1000;
            break;
        default:
            object->bitRate = 100;
            break;
    };

    divratio = clockConfig.divideRatio + 1;
    /*roundup the integer division using the equation x/y = (x+(y-1))/y*/
    /*After dividing the input freq, we get the actual i2c input clock*/
    clkFreq = (uint32_t)((hwAttrs->i2cClk + (divratio - 1)) / divratio);
    /* The calculation to get TPR value is
    * TPR_Value = (clkFreq/(bitrate *10))-1
    * Since we have three bit rate support 100khz, 400khz and 1000Khz,
    * as per the equation, we multiply bitrate with 10 hence we can convert
    * the bitrate value to Mhz for the equation since clkFreq is in Mhz.
    */
    bitRate_Mhz = object->bitRate / 100;
    TPR_Value   = (clkFreq / bitRate_Mhz) - 1;
    DL_I2C_setTimerPeriod(hwAttrs->i2c, TPR_Value);

    /* Flush the FIFOs */
    DL_I2C_flushControllerTXFIFO(hwAttrs->i2c);
    DL_I2C_flushControllerRXFIFO(hwAttrs->i2c);

    DL_I2C_setControllerTXFIFOThreshold(hwAttrs->i2c, hwAttrs->txIntFifoThr);
    DL_I2C_setControllerRXFIFOThreshold(hwAttrs->i2c, hwAttrs->rxIntFifoThr);

    if (hwAttrs->isClockStretchingEnabled) {
        DL_I2C_enableControllerClockStretching(hwAttrs->i2c);
    }
    /* Configure Interrupts */
    DL_I2C_enableInterrupt(
        hwAttrs->i2c, DL_I2C_INTERRUPT_CONTROLLER_ARBITRATION_LOST |
                          DL_I2C_INTERRUPT_CONTROLLER_NACK |
                          DL_I2C_INTERRUPT_CONTROLLER_RXFIFO_TRIGGER |
                          DL_I2C_INTERRUPT_CONTROLLER_RX_DONE |
                          DL_I2C_INTERRUPT_CONTROLLER_TX_DONE);

    /* Enable the I2C Controller for operation */
    DL_I2C_enableController(hwAttrs->i2c);
}

/*
 *  ======== I2CMSPM0_initIO ========
 *  This functions initializes the I2C IOs.
 *
 *  @pre    Function assumes that the I2C handle is pointing to a hardware
 *          module which has already been opened.
 */
static int_fast16_t I2CMSPM0_initIO(I2C_Handle handle, void *pinCfg)
{
    I2CMSPM0_Object *object;
    I2CMSPM0_HWAttrs const *hwAttrs;

    /* Get the pointer to the object and hwAttrs */
    object  = handle->object;
    hwAttrs = handle->hwAttrs;

    /* If the pinCfg pointer is NULL, use hwAttrs pins */
    if (pinCfg == NULL) {
        object->sdaPincm = hwAttrs->sdaPincm;
        object->sclPincm = hwAttrs->sclPincm;
    } else {
        object->sdaPincm = ((I2CMSPM0_I2CPinCfg *) pinCfg)->pinSDA;
        object->sclPincm = ((I2CMSPM0_I2CPinCfg *) pinCfg)->pinSCL;
    }

    /* Configure I2C pins SDA and SCL and set their muxes */
    GPIO_setConfigAndMux(hwAttrs->sdaPinIndex,
        GPIO_CFG_INPUT | GPIO_CFG_HIZ_ON | hwAttrs->sdaPincm,
        hwAttrs->sdaPinMux);
    GPIO_setConfigAndMux(hwAttrs->sclPinIndex,
        GPIO_CFG_INPUT | GPIO_CFG_HIZ_ON | hwAttrs->sclPincm,
        hwAttrs->sclPinMux);

    return I2C_STATUS_SUCCESS;
}

/*
 *  ======== I2CMSPM0_postNotify ========
 *  This functions is called to notify the I2C driver of an ongoing transition
 *  out of sleep mode.
 *
 *  @pre    Function assumes that the I2C handle (clientArg) is pointing to a
 *          hardware module which has already been opened.
 */
static int I2CMSPM0_postNotify(
    unsigned int eventType, uintptr_t eventArg, uintptr_t clientArg)
{
    /* reconfigure the hardware if returning from sleep*/
    /*  if (eventType == PowerMSPM0_AWAKE_STANDBY)
    {
        I2CMSPM0_initHw((I2C_Handle)clientArg);
    }

    return (Power_NOTIFYDONE);*/
    return 0;
}
