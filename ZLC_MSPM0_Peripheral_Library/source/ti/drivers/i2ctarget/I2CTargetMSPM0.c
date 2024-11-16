/*
 * Copyright (c) 2023-2024, Texas Instruments Incorporated
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
 *  ======== I2CTargetMSPM0.c ========
 */
/* clang-format off */

#include <stdint.h>

#include <ti/drivers/GPIO.h>
#include <ti/drivers/i2ctarget/I2CTargetMSPM0.h>

#ifdef POWER_MANAGEMENT_MSPM0
#include <ti/drivers/Power.h>
#include <ti/drivers/power/PowerMSPM0.h>
#endif

#include <ti/drivers/dpl/HwiP.h>
#include <ti/drivers/dpl/SemaphoreP.h>
#include <ti/drivers/dpl/DebugP.h>

/* Driverlib header files */
#include <ti/devices/DeviceFamily.h>

/* Prototypes */
static void I2CTargetMSPM0_hwiFxn(uintptr_t arg);
static void I2CTargetMSPM0_configHw(I2CTarget_Handle handle);
static int_fast16_t I2CTargetMSPM0_initIO(I2CTarget_Handle handle);
static void I2CTargetMSPM0_Init(I2CTarget_Handle handle);

/* Default I2C parameters structure */
extern const I2CTarget_Params I2CTarget_defaultParams;

/*!
 *  ======== I2CTargetMSPM0_Init ========
 */
static void I2CTargetMSPM0_Init(I2CTarget_Handle handle)
{
    I2CTargetMSPM0_Object *object         = handle->object;
    I2CTargetMSPM0_HWAttrs const *hwAttrs = handle->hwAttrs;

    /* Initialize target mode */
    DebugP_assert(I2CBaseValid(hwAttrs->i2c)); /* Check for valid i2c base address */
    DebugP_assert(!((uint8_t)object->targetAddress & 0x80)); /* Check for 7bit address */

    /* Enable the clock to the target module */
    DL_I2C_ClockConfig clockConfig =
    {
        .clockSel    = hwAttrs->clockSource,
        .divideRatio = hwAttrs->clockDivider,
    };
    DL_I2C_setClockConfig(hwAttrs->i2c, (DL_I2C_ClockConfig *) &clockConfig);
    /* Set the own target address. only one target address is supported */
    DL_I2C_setTargetOwnAddress(hwAttrs->i2c, object->targetAddress);

    /* Flush the Tx FIFOs */
    DL_I2C_flushTargetTXFIFO(hwAttrs->i2c);
    DL_I2C_flushTargetRXFIFO(hwAttrs->i2c);

    /* Set the FIFO threshold */
    DL_I2C_setTargetTXFIFOThreshold(hwAttrs->i2c, hwAttrs->txIntFifoThr);
    DL_I2C_setTargetRXFIFOThreshold(hwAttrs->i2c, hwAttrs->rxIntFifoThr);

    /* Configure the Clock Stratching */
    if (hwAttrs->isClockStretchingEnabled)
    {
        DL_I2C_enableTargetClockStretching(hwAttrs->i2c);
    }

    /* Configure the Analog Glitch Filter */
    if(hwAttrs->isAnalogGlitchFilterEnabled)
    {
        DL_I2C_disableAnalogGlitchFilter(hwAttrs->i2c);
    }
    /* Enable the tx fifo empty interrupt to wait on fifo reload */
    DL_I2C_enableTargetTXEmptyOnTXRequest(hwAttrs->i2c);
    /* Disable SWUEN */
    DL_I2C_disableTargetWakeup(hwAttrs->i2c);
    /* Enable manual ack mode */
    DL_I2C_setTargetACKOverrideValue(hwAttrs->i2c, 0);
    DL_I2C_enableACKOverrideOnStart(hwAttrs->i2c);

    /* Enable the Target */
    DL_I2C_enableTarget(hwAttrs->i2c);
}

/*!
 *  ======== I2CTarget_open ========
 */
I2CTarget_Handle I2CTarget_open(uint_least8_t index, I2CTarget_Params *params)
{
    I2CTarget_Handle handle = NULL;
    HwiP_Params hwiParams;
    uintptr_t key;
    I2CTargetMSPM0_Object *object;
    I2CTargetMSPM0_HWAttrs const *hwAttrs;

    if (index < I2CTarget_count)
    {
        if (params == NULL)
        {
            params = (I2CTarget_Params *)&I2CTarget_defaultParams;
        }
        handle  = (I2CTarget_Handle) & (I2CTarget_config[index]);
        hwAttrs = handle->hwAttrs;
        object  = handle->object;
    }
    else
    {
        return NULL;
    }

    /* Callback function must be defined */
    if (params->eventCallbackFxn == NULL)
    {
        return NULL;
    }

    /* Only 7-bit address supported by this driver implementation */
    if (params->targetAddress >> 7)
    {
        return NULL;
    }

    /* Determine if the device index was already opened */
    key = HwiP_disable();
    if (object->isOpen == true)
    {
        HwiP_restore(key);
        return NULL;
    }

    /* Mark the handle as being used */
    object->isOpen = true;
    HwiP_restore(key);
#ifdef POWER_MANAGEMENT_MSPM0
    /* Power on the I2C module */
    Power_setDependency(hwAttrs->powerMngrId);
#endif
    /* Configure the IOs.*/
    if (I2CTargetMSPM0_initIO(handle) != I2CTarget_STATUS_SUCCESS)
    {
        /* Mark the module as available */
        object->isOpen = false;
        #ifdef POWER_MANAGEMENT_MSPM0
        /* Release dependency if open fails */
        Power_releaseDependency(hwAttrs->powerMngrId);
        #endif
        /* Signal back to application that I2C driver was not successfully opened */
        return NULL;
    }

    /* Save parameters */
    object->eventCallbackFxn = params->eventCallbackFxn;
    object->targetAddress    = params->targetAddress;

    /* Set driver state */
    object->currentState = I2CTarget_State_STOPPED;

    /* Configure HW based on driver state */
    I2CTargetMSPM0_configHw(handle);

    /* Create Hwi object for this I2C peripheral */
    HwiP_Params_init(&hwiParams);
    hwiParams.arg      = (uintptr_t)handle;
    hwiParams.priority = hwAttrs->intPriority;
    HwiP_construct(&(object->hwi), hwAttrs->intNum, I2CTargetMSPM0_hwiFxn, &hwiParams);

    /* Create thread safe handles for this I2C peripheral
     * Semaphore to provide exclusive access to the I2C peripheral
     */
    SemaphoreP_constructBinary(&(object->mutex), 1);

    /* Return the address of the handle */
    return handle;
}

/*!
 *  @brief  Start I2C Target driver listening on I2C bus.
 *
 *  @param  handle  A I2CTarget_Handle returned from I2CTarget_open
 */
void I2CTarget_start(I2CTarget_Handle handle)
{
    I2CTargetMSPM0_Object *object;

    /* Get the pointer to the object */
    object = handle->object;

    object->currentState = I2CTarget_State_IDLE;

    /* Configure HW based on driver state */
    I2CTargetMSPM0_configHw(handle);

    #ifdef POWER_MANAGEMENT_MSPM0
    /* Set standby disallow constraint. */
    Power_setConstraint(PowerMSPM0_DISALLOW_STANDBY);
    #endif
}

/*!
 *  @brief  Stop I2C Target driver from listening on I2C bus.
 *
 *  @param  handle  A I2CTarget_Handle returned from I2CTarget_open
 */
void I2CTarget_stop(I2CTarget_Handle handle)
{
    I2CTargetMSPM0_Object *object;

    /* Get the pointer to the object */
    object = handle->object;

    object->currentState = I2CTarget_State_STOPPED;

    /* Configure HW based on driver state */
    I2CTargetMSPM0_configHw(handle);

    #ifdef POWER_MANAGEMENT_MSPM0
    /* Release power constraint */
    Power_releaseConstraint(PowerMSPM0_DISALLOW_STANDBY);
    #endif
}

/*!
 *  ======== I2CTarget_close ========
 */
void I2CTarget_close(I2CTarget_Handle handle)
{
    I2CTargetMSPM0_Object *object;
    I2CTargetMSPM0_HWAttrs const *hwAttrs;

    /* Get the pointer to the object and hwAttrs */
    hwAttrs = handle->hwAttrs;
    object  = handle->object;

    /* Stop I2C Target operation */
    if (object->currentState != I2CTarget_State_STOPPED)
    {
        I2CTarget_stop(handle);
    }

    /* Disable the I2C Target */
    DL_I2C_disableTarget(hwAttrs->i2c);

    #ifdef POWER_MANAGEMENT_MSPM0
    /* Power off the I2C module */
    Power_releaseDependency(hwAttrs->powerMngrId);
    #endif

    /* Destruct modules used in driver */
    HwiP_destruct(&(object->hwi));
    SemaphoreP_destruct(&(object->mutex));

    #ifdef POWER_MANAGEMENT_MSPM0
    /* Unregister power post notification object */
    Power_unregisterNotify(&object->i2cPostObj);
    #endif

    /* Mark the module as available */
    object->currentState = I2CTarget_State_STOPPED;
    object->isOpen       = false;

    return;
}

/*
 *  ======== I2CTargetMSPM0_hwiFxn ========
 *  Hwi interrupt handler to service the I2C peripheral
 *
 *  The handler is a generic handler for a I2C object.
 */
static void I2CTargetMSPM0_hwiFxn(uintptr_t arg)
{
    I2CTarget_Handle handle              = (I2CTarget_Handle)arg;
    I2CTargetMSPM0_Object *object         = handle->object;
    I2CTargetMSPM0_HWAttrs const *hwAttrs = handle->hwAttrs;
    uint8_t dataByte;
    I2CTarget_Event event;

    /* Get interrupt status and clear */
    uint32_t intFlags = DL_I2C_getEnabledInterruptStatus(hwAttrs->i2c, 0xFFFF);
    DL_I2C_clearInterruptStatus(hwAttrs->i2c, I2CTARGET_INT_FLAGS);

    /* Check if controller has written or requested data */
    uint32_t status = DL_I2C_getTargetStatus(hwAttrs->i2c);

    /* Controller will write to target (target-receive) */
    if (status & DL_I2C_TARGET_STATUS_RX_MODE) /* This state will tell us that byte is coming */
    {
        object->currentState = I2CTarget_State_RECEIVE;
        object->eventCallbackFxn(handle, I2CTarget_Event_WRITE_REQUESTED, NULL);
    }

    /* Controller has written first byte to target (target-receive) */
    if ((status & DL_I2C_TARGET_STATUS_RECEIVE_REQUEST)||(intFlags & DL_I2C_INTERRUPT_TARGET_RX_DONE))
    {
        /* Enable the manual ACK if it is not enabled */
        if(!DL_I2C_isACKOverrideOnStartEnabled(hwAttrs->i2c))
        {
            DL_I2C_enableACKOverrideOnStart(hwAttrs->i2c);
        }
        /* Read data byte from I2C peripheral */
        dataByte = DL_I2C_receiveTargetData(hwAttrs->i2c);

        object->currentState = I2CTarget_State_RECEIVE;
        object->eventCallbackFxn(handle, I2CTarget_Event_WRITE_RECEIVED, &dataByte);
        /* Send the ACK */
        DL_I2C_setTargetACKOverrideValue(hwAttrs->i2c, 0);
    }

    /* Controller wants to read from target (target-transmit) */
    if ((status & DL_I2C_TARGET_STATUS_TRANSMIT_REQUEST)||(intFlags & DL_I2C_INTERRUPT_TARGET_TXFIFO_EMPTY))
    {
        /* Disable manual ACK so it is handled automatically during transmit */
        DL_I2C_disableACKOverrideOnStart(hwAttrs->i2c);

        /* Use internal state machine to differentiate between
         * - the first byte (I2CTarget_Event_READ_REQUESTED), and
         * - subsequent bytes (I2CTarget_Event_READ_PROCESSED).
         */
        event = I2CTarget_Event_READ_REQUESTED;
        if (object->currentState == I2CTarget_State_TRANSMIT)
        {
            event = I2CTarget_Event_READ_PROCESSED;
        }

        object->currentState = I2CTarget_State_TRANSMIT;

        /* Call callback function */
        object->eventCallbackFxn(handle, event, &dataByte);

        /* Write byte to I2C peripheral */
        DL_I2C_transmitTargetData(hwAttrs->i2c, dataByte);
    }

    if (intFlags & DL_I2C_INTERRUPT_TARGET_STOP)
    {
        /* Stop condition received. */
        object->currentState = I2CTarget_State_IDLE;
        object->eventCallbackFxn(handle, I2CTarget_Event_STOP, NULL);
    }
}

/*
 *  ======== I2CTargetMSPM0_configHw ========
 *  This functions configures the I2C hardware module.
 *
 *  @pre    Function assumes that the I2C handle is pointing to a hardware
 *          module which has already been opened.
 */
static void I2CTargetMSPM0_configHw(I2CTarget_Handle handle)
{
    I2CTargetMSPM0_Object *object         = handle->object;
    I2CTargetMSPM0_HWAttrs const *hwAttrs = handle->hwAttrs;

    if (object->currentState == I2CTarget_State_STOPPED)
    {
        /* Driver is stopped/inactive. Disable interrupts */
        DL_I2C_disableInterrupt(hwAttrs->i2c, I2CTARGET_INT_FLAGS);

        /* Disable I2C module target mode */
        DL_I2C_disableTarget(hwAttrs->i2c);

        /* Clear interrupt flags */
        DL_I2C_clearInterruptStatus(hwAttrs->i2c, I2CTARGET_INT_FLAGS);
    }
    else
    {
        /* Driver is started/active. Clear flags and enable interrupts. */
        DL_I2C_clearInterruptStatus(hwAttrs->i2c, I2CTARGET_INT_FLAGS);
        DL_I2C_enableInterrupt(hwAttrs->i2c, I2CTARGET_INT_FLAGS);

        /* Initialize the I2C */
        I2CTargetMSPM0_Init(handle);
    }
}

/*
 *  ======== I2CTargetMSPM0_initIO ========
 *  This functions initializes the I2C IOs.
 *
 *  @pre    Function assumes that the I2C handle is pointing to a hardware
 *          module which has already been opened.
 */
static int_fast16_t I2CTargetMSPM0_initIO(I2CTarget_Handle handle)
{
    I2CTargetMSPM0_HWAttrs const *hwAttrs;

    /* Get the pointer to hwAttrs */
    hwAttrs = handle->hwAttrs;

    /* Configure I2C pins SDA and SCL and set their muxes */
    GPIO_setConfigAndMux(hwAttrs->sdaPinIndex,GPIO_CFG_INPUT | GPIO_CFG_IN_PU | GPIO_CFG_OUT_HIGH | GPIO_CFG_HIZ_ON | hwAttrs->sdaPincm,hwAttrs->sdaPinMux);
    GPIO_setConfigAndMux(hwAttrs->sclPinIndex,GPIO_CFG_INPUT | GPIO_CFG_IN_PU | GPIO_CFG_OUT_HIGH | GPIO_CFG_HIZ_ON | hwAttrs->sclPincm,hwAttrs->sclPinMux);

    return I2CTarget_STATUS_SUCCESS;
}
/* clang-format on */
