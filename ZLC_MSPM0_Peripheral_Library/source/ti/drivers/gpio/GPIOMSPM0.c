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

#include <stdbool.h>
#include <stdint.h>

#include <ti/drivers/dpl/HwiP.h>
#include <ti/drivers/dpl/SemaphoreP.h>

#include <ti/drivers/GPIO.h>
#include <ti/drivers/gpio/GPIOMSPM0.h>

#include <ti/driverlib/driverlib.h>

/* Internal boolean to confirm that GPIO_init() has been called */
static bool initCalled = false;

/* Link to config values defined by SysConfig */
extern GPIO_Config GPIO_config;
extern const uint_least8_t GPIO_pinLowerBound;
extern const uint_least8_t GPIO_pinUpperBound;

/*
 * Bitmask to determine if a Hwi has been created/constructed
 * for a port already
 */
static uint8_t portHwiCreatedBitMask = 0;

/* Used to contain device specific port information */
typedef struct {
    const IRQn_Type interruptNum;
    const uint32_t baseAddress;
} PortConfig;

#if (DeviceFamily_PARENT == DeviceFamily_PARENT_MSPM0L11XX_L13XX)

#define NUM_PORTS (1)
#define PORTA_INDEX (0)

/* Port information */
static const PortConfig portConfigs[NUM_PORTS] = {
    {GPIOA_INT_IRQn, GPIOA_BASE},
};

#elif (DeviceFamily_PARENT == DeviceFamily_PARENT_MSPM0G1X0X_G3X0X)

#define NUM_PORTS (2)
#define PORTA_INDEX (0)
#define PORTB_INDEX (1)

/* Port information */
static const PortConfig portConfigs[NUM_PORTS] = {
    {GPIOA_INT_IRQn, GPIOA_BASE},
    {GPIOB_INT_IRQn, GPIOB_BASE},
};

#elif (DeviceFamily_PARENT == DeviceFamily_PARENT_MSPM0L122X_L222X)

#define NUM_PORTS (3)
#define PORTA_INDEX (0)
#define PORTB_INDEX (1)
#define PORTC_INDEX (2)

/* Port information */
static const PortConfig portConfigs[NUM_PORTS] = {
    {GPIOA_INT_IRQn, GPIOA_BASE},
    {GPIOB_INT_IRQn, GPIOB_BASE},
    {GPIOC_INT_IRQn, GPIOC_BASE},
};

#else

#error "Drivers is not supported on this device yet"

#endif

#define MAX_PINS_PER_GPIO_PORT (32)

/* Returns the GPIO port number or port config struct */
#define indexToPortId(pinIndex) (pinIndex / MAX_PINS_PER_GPIO_PORT)
#define indexToPortConfig(pinIndex) (portConfigs[indexToPortId(pinIndex)])

/* Generates a per-port mask for a pin, e.g. the second pin in a port should be 0x10 */
#define indexToPortMask(pinIndex) (1U << (pinIndex % MAX_PINS_PER_GPIO_PORT))

#define ALL_INTERRUPTS_MASK (0xFFFFFFFFU)

/*
 *  ======== GPIO_clearInt ========
 */
void GPIO_clearInt(uint_least8_t index)
{
    if (index == GPIO_INVALID_INDEX) {
        return;
    }

    /* Clear GPIO interrupt flag */
    DL_GPIO_clearInterruptStatus(
        (GPIO_Regs *) (indexToPortConfig(index).baseAddress),
        indexToPortMask(index));
}

/*
 *  ======== GPIO_disableInt ========
 */
void GPIO_disableInt(uint_least8_t index)
{
    if (index == GPIO_INVALID_INDEX) {
        return;
    }

    /* Update the config table and disable interrupts */
    uintptr_t key = HwiP_disable();

    GPIO_config.configs[index] &= ~GPIO_CFG_INT_MASK;
    DL_GPIO_disableInterrupt(
        (GPIO_Regs *) (indexToPortConfig(index).baseAddress),
        indexToPortMask(index));

    /* Clear pending interrupts at the NVIC level */
    NVIC_ClearPendingIRQ(indexToPortConfig(index).interruptNum);

    HwiP_restore(key);
}

/*
 *  ======== GPIO_enableInt ========
 */
void GPIO_enableInt(uint_least8_t index)
{
    if (index == GPIO_INVALID_INDEX) {
        return;
    }

    /* Update the config table and enable interrupts */
    uintptr_t key = HwiP_disable();

    GPIO_config.configs[index] |= GPIO_CFG_INT_MASK;
    DL_GPIO_enableInterrupt(
        (GPIO_Regs *) (indexToPortConfig(index).baseAddress),
        indexToPortMask(index));

    HwiP_restore(key);
}

/*
 *  ======== GPIO_hwiIntFxn ========
 *  Hwi function that processes GPIO interrupts.
 */
void GPIO_hwiIntFxn(uintptr_t portIndex)
{
    uint32_t pinIndex            = 0;
    uint32_t flagIndex           = 0;
    uint32_t pendingIntMaskGPIOA = 0;
    uint32_t pendingIntMaskGPIOB = 0;
    uint32_t pendingIntMaskGPIOC = 0;

    /* Determine if a GPIO interrupt occurred, not another group element */
    uint32_t groupIIDX = DL_Interrupt_getPendingGroup(DL_INTERRUPT_GROUP_1);
    if ((groupIIDX == DL_INTERRUPT_GROUP1_IIDX_GPIOA) ||
        (groupIIDX == DL_INTERRUPT_GROUP1_IIDX_GPIOB) ||
        (groupIIDX == DL_INTERRUPT_GROUP1_IIDX_GPIOC)) {
        /*
         * Find out which pins have their interrupt flags set.
         * GPIOA and GPIOB are grouped interrupts with the same
         * interrupt number, and are therefore considered to be the
         * same entry in the Hwi dispatch table. As a workaround,
         * check all pending interrupts on both ports.
         */
        pendingIntMaskGPIOA =
            DL_GPIO_getEnabledInterruptStatus(GPIOA, ALL_INTERRUPTS_MASK);

        /* Clear the set bits at once */
        DL_GPIO_clearInterruptStatus(GPIOA, ALL_INTERRUPTS_MASK);

        /* Match the interrupt to its corresponding callback function */
        while (pendingIntMaskGPIOA) {
            /* Note MASK_TO_PIN only detects the highest set bit */
            flagIndex = GPIO_MASK_TO_PIN(pendingIntMaskGPIOA);
            pendingIntMaskGPIOA &= ~GPIO_PIN_TO_MASK(flagIndex);

            /* Need to go from port index up to global index */
            pinIndex = flagIndex + (PORTA_INDEX * MAX_PINS_PER_GPIO_PORT);

            if (pinIndex >= GPIO_pinLowerBound &&
                pinIndex <= GPIO_pinUpperBound) {
                if (GPIO_config.callbacks[pinIndex] != NULL) {
                    GPIO_config.callbacks[pinIndex](pinIndex);
                }
            }
        }
#if ((DeviceFamily_PARENT == DeviceFamily_PARENT_MSPM0G1X0X_G3X0X) || \
     (DeviceFamily_PARENT == DeviceFamily_PARENT_MSPM0L122X_L222X))
        pendingIntMaskGPIOB =
            DL_GPIO_getEnabledInterruptStatus(GPIOB, ALL_INTERRUPTS_MASK);
        DL_GPIO_clearInterruptStatus(GPIOB, ALL_INTERRUPTS_MASK);

        while (pendingIntMaskGPIOB) {
            flagIndex = GPIO_MASK_TO_PIN(pendingIntMaskGPIOB);
            pendingIntMaskGPIOB &= ~GPIO_PIN_TO_MASK(flagIndex);

            pinIndex = flagIndex + (PORTB_INDEX * MAX_PINS_PER_GPIO_PORT);

            if (pinIndex >= GPIO_pinLowerBound &&
                pinIndex <= GPIO_pinUpperBound) {
                if (GPIO_config.callbacks[pinIndex] != NULL) {
                    GPIO_config.callbacks[pinIndex](pinIndex);
                }
            }
        }
#endif
#if (DeviceFamily_PARENT == DeviceFamily_PARENT_MSPM0L122X_L222X)
        pendingIntMaskGPIOC =
            DL_GPIO_getEnabledInterruptStatus(GPIOC, ALL_INTERRUPTS_MASK);
        DL_GPIO_clearInterruptStatus(GPIOC, ALL_INTERRUPTS_MASK);

        while (pendingIntMaskGPIOC) {
            flagIndex = GPIO_MASK_TO_PIN(pendingIntMaskGPIOC);
            pendingIntMaskGPIOC &= ~GPIO_PIN_TO_MASK(flagIndex);

            pinIndex = flagIndex + (PORTC_INDEX * MAX_PINS_PER_GPIO_PORT);

            if (pinIndex >= GPIO_pinLowerBound &&
                pinIndex <= GPIO_pinUpperBound) {
                if (GPIO_config.callbacks[pinIndex] != NULL) {
                    GPIO_config.callbacks[pinIndex](pinIndex);
                }
            }
        }
#endif
    }

    return;
}

/*
 *  ======== GPIO_init ========
 */
void GPIO_init()
{
    uint32_t i;
    uintptr_t key;
    SemaphoreP_Handle sem;
    static SemaphoreP_Handle initSem;

    sem = SemaphoreP_createBinary(1);

    if (sem == NULL) {
        /* Error with creating binary semaphore */
        return;
    }

    /* Disable interrupts for critical region */
    key = HwiP_disable();

    if (initSem == NULL) {
        initSem = sem;
        HwiP_restore(key);
    } else {
        /* init has already been called */
        HwiP_restore(key);

        if (sem) {
            SemaphoreP_delete(sem);
        }
    }

    /* Use semaphore to protect init code */
    SemaphoreP_pend(initSem, SemaphoreP_WAIT_FOREVER);

    /* If init has already been called, restore interrupts and return */
    if (initCalled) {
        SemaphoreP_post(initSem);
        return;
    }

    for (i = GPIO_pinLowerBound; i < GPIO_pinUpperBound; i++) {
        GPIO_setConfig(i, GPIO_config.configs[i]);

        if (GPIO_config.callbacks[i] != NULL) {
            GPIO_setCallback(i, GPIO_config.callbacks[i]);
        }
    }

    initCalled = true;
    SemaphoreP_post(initSem);
}

/*
 *  ======== GPIO_setConfig ========
 */
int_fast16_t GPIO_setConfig(uint_least8_t index, GPIO_PinConfig pinConfig)
{
    return (GPIO_setConfigAndMux(index, pinConfig, GPIO_MUX_GPIO));
}

/*
 *  ======== GPIO_setInterruptConfig ========
 */
void GPIO_setInterruptConfig(uint_least8_t index, GPIO_PinConfig pinConfig)
{
    if (index == GPIO_INVALID_INDEX) {
        return;
    }

    GPIO_Regs *port;
    uint32_t pinMask;
    uint32_t pinIndex;
    uint32_t intValue;

    port    = (GPIO_Regs *) (indexToPortConfig(index).baseAddress);
    pinMask = indexToPortMask(index);

    intValue = (pinConfig & GPIO_CFG_INT_MASK) >> GPIO_CFG_INT_LSB;

    pinIndex = index % MAX_PINS_PER_GPIO_PORT;

    /* Configure the polarity, which is needed to trigger interrupts */
    if (intValue != GPIO_CFG_IN_INT_NONE) {
        if (pinMask < DL_GPIO_PIN_16) {
            DL_GPIO_setLowerPinsPolarity(port, intValue << (pinIndex * 2));
        } else {
            DL_GPIO_setUpperPinsPolarity(
                port, intValue << ((pinIndex - 16) * 2));
        }

        /* Clear interrupt status before enabling */
        GPIO_clearInt(index);

        GPIO_enableInt(index);
    } else {
        GPIO_disableInt(index);
    }
}

/*
 *  ======== GPIO_getConfig ========
 */
void GPIO_getConfig(uint_least8_t index, GPIO_PinConfig *pinConfig)
{
    *pinConfig = GPIO_config.configs[index];
}

/*
 *  ======== GPIO_read ========
 */
uint_fast8_t GPIO_read(uint_least8_t index)
{
    uint32_t value =
        DL_GPIO_readPins((GPIO_Regs *) (indexToPortConfig(index).baseAddress),
            indexToPortMask(index));

    return value ? 1 : 0;
}

/*
 *  ======== GPIO_toggle ========
 */
void GPIO_toggle(uint_least8_t index)
{
    if (index == GPIO_INVALID_INDEX) {
        return;
    }

    uintptr_t key;

    GPIO_Regs *port;
    uint32_t pinMask;

    port    = (GPIO_Regs *) (indexToPortConfig(index).baseAddress);
    pinMask = indexToPortMask(index);

    /* Make atomic update */
    key = HwiP_disable();

    DL_GPIO_togglePins(port, pinMask);

    /* Update config table entry with value written */
    GPIO_config.configs[index] ^= GPIO_CFG_OUT_HIGH;

    HwiP_restore(key);
}

/*
 *  ======== GPIO_write ========
 */
void GPIO_write(uint_least8_t index, unsigned int value)
{
    if (index == GPIO_INVALID_INDEX) {
        return;
    }

    uintptr_t key;

    GPIO_Regs *port;
    uint32_t pinMask;

    port    = (GPIO_Regs *) (indexToPortConfig(index).baseAddress);
    pinMask = indexToPortMask(index);

    /* Disable interrupts to set pins */
    key = HwiP_disable();

    /* Update the pin config table if the value is different */
    if (value && !(GPIO_config.configs[index] & GPIO_CFG_OUT_HIGH)) {
        GPIO_config.configs[index] |= GPIO_CFG_OUT_HIGH;
    } else if (!value && (GPIO_config.configs[index] & GPIO_CFG_OUT_HIGH)) {
        GPIO_config.configs[index] &= ~GPIO_CFG_OUT_HIGH;
    }

    /* Write the value to the GPIO pins */
    if (value) {
        DL_GPIO_writePins(port, pinMask);
    } else {
        DL_GPIO_clearPins(port, pinMask);
    }

    HwiP_restore(key);
}

uint32_t GPIO_getMux(uint_least8_t index)
{
    GPIO_PinConfig pinConfig = GPIO_config.configs[index];

    /* Last 16-bits of pinConfig encode the iomux pincm */
    uint32_t pincm = pinConfig & 0xFF;

    /* Return pin function encoding */
    return (IOMUX->SECCFG.PINCM[pincm] & IOMUX_PINCM_PF_MASK);
}

int_fast16_t GPIO_setConfigAndMux(
    uint_least8_t index, GPIO_PinConfig pinConfig, uint32_t mux)
{
    if (index == GPIO_INVALID_INDEX) {
        return (GPIO_STATUS_ERROR);
    }

    uintptr_t key;

    GPIO_Regs *port;
    uint32_t portIdx;
    uint32_t pinMask;
    uint32_t pincm;

    HwiP_Handle hwiHandle;
    HwiP_Params hwiParams;

    if (index < GPIO_pinLowerBound || index > GPIO_pinUpperBound) {
        /* Configuring out of bounds index */
        return (GPIO_STATUS_ERROR);
    }

    if (pinConfig & GPIO_DO_NOT_CONFIG) {
        /* Return success if the pin will be configured dynamically */
        return (GPIO_STATUS_SUCCESS);
    }

    /* The particular GPIO port can be determined from the index */
    port    = (GPIO_Regs *) (indexToPortConfig(index).baseAddress);
    pinMask = indexToPortMask(index);

    /* The lower 16 bits incode the IOMUX PINCM, which is device dependent */
    pincm = pinConfig & 0xFF;

    DL_GPIO_INVERSION inversion          = DL_GPIO_INVERSION_DISABLE;
    DL_GPIO_DRIVE_STRENGTH driveStrength = DL_GPIO_DRIVE_STRENGTH_LOW;
    DL_GPIO_RESISTOR resistor            = DL_GPIO_RESISTOR_NONE;
    DL_GPIO_HYSTERESIS hysteresis        = DL_GPIO_HYSTERESIS_DISABLE;
    DL_GPIO_WAKEUP wakeup                = DL_GPIO_WAKEUP_DISABLE;
    DL_GPIO_HIZ hiZ                      = DL_GPIO_HIZ_DISABLE;

    /* Input and output pins support inversion */
    if ((pinConfig & GPIO_CFG_INVERSION_MASK) == GPIO_CFG_INVERT_ON) {
        inversion = DL_GPIO_INVERSION_ENABLE;
    }

    /* Input and output pins both support pull-up and pull-down resistors */
    if (((pinConfig & GPIO_CFG_IO_MASK) == GPIO_CFG_OUT_OD_PU) ||
        ((pinConfig & GPIO_CFG_IO_MASK) == GPIO_CFG_IN_PU)) {
        resistor = DL_GPIO_RESISTOR_PULL_UP;
    } else if (((pinConfig & GPIO_CFG_IO_MASK) == GPIO_CFG_OUT_OD_PD) ||
               ((pinConfig & GPIO_CFG_IO_MASK) == GPIO_CFG_IN_PD)) {
        resistor = DL_GPIO_RESISTOR_PULL_DOWN;
    }

    /*
     * Input pins can set Hi-Z independently. This is mainly for open drain
     * interface purposes such as I2C
     */
    if ((pinConfig & GPIO_CFG_HIZ_MASK) == GPIO_CFG_HIZ_ON) {
        hiZ = DL_GPIO_HIZ_ENABLE;
    }

    key = HwiP_disable();

    if (pinConfig & GPIO_CFG_INPUT) {
        if ((pinConfig & GPIO_CFG_HYSTERESIS_MASK) == GPIO_CFG_HYSTERESIS_ON) {
            hysteresis = DL_GPIO_HYSTERESIS_ENABLE;
        }

        if ((pinConfig & GPIO_CFG_WAKEUP_MASK) == GPIO_CFG_WAKEUP_ON_0) {
            wakeup = DL_GPIO_WAKEUP_ON_0;
        } else if ((pinConfig & GPIO_CFG_WAKEUP_MASK) ==
                   GPIO_CFG_WAKEUP_ON_1) {
            wakeup = DL_GPIO_WAKEUP_ON_1;
        }

        DL_GPIO_initPeripheralInputFunctionFeatures(
            pincm, mux, inversion, resistor, hysteresis, wakeup);

        /* Check for case where the pins are input but need Hi-Z (I2C) */
        if (hiZ == DL_GPIO_HIZ_ENABLE) {
            DL_GPIO_enableHiZ(pincm);
        }

    } else {
        if ((pinConfig & GPIO_CFG_OUT_STRENGTH_MASK) ==
            GPIO_CFG_OUT_STR_HIGH) {
            driveStrength = DL_GPIO_DRIVE_STRENGTH_HIGH;
        }

        DL_GPIO_initPeripheralOutputFunctionFeatures(
            pincm, mux, inversion, resistor, driveStrength, hiZ);

        if (mux == GPIO_MUX_GPIO) {
            DL_GPIO_enableOutput(port, pinMask);
        }

        /* Set output pin state */
        if ((pinConfig & GPIO_CFG_OUT_HIGH) == GPIO_CFG_OUT_HIGH) {
            GPIO_write(index, 1);
        } else {
            GPIO_write(index, 0);
        }
    }

    HwiP_restore(key);

    uint32_t portBitMask;

    if ((pinConfig & GPIO_CFG_INT_MASK) != GPIO_CFG_IN_INT_NONE) {
        portIdx     = indexToPortId(index);
        portBitMask = 1 << portIdx;

        key = HwiP_disable();

        if ((portHwiCreatedBitMask & portBitMask) == 0) {
            portHwiCreatedBitMask |= portBitMask;
            HwiP_restore(key);

            HwiP_Params_init(&hwiParams);

            hwiParams.arg      = (uintptr_t) portIdx;
            hwiParams.priority = GPIO_config.intPriority;

            hwiHandle = HwiP_create(indexToPortConfig(index).interruptNum,
                GPIO_hwiIntFxn, &hwiParams);

            if (hwiHandle == NULL) {
                return (GPIO_STATUS_ERROR);
            }

            /* Can also set hwiParams.enableInt to true */
            NVIC_EnableIRQ(indexToPortConfig(index).interruptNum);
        } else {
            HwiP_restore(key);
        }
    }

    GPIO_setInterruptConfig(index, pinConfig);

    key = HwiP_disable();

    GPIO_config.configs[index] = pinConfig;

    HwiP_restore(key);

    return GPIO_STATUS_SUCCESS;
}
