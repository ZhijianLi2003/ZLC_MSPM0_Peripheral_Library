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
 *  @file       drv8706-q1.h
 *  @brief      Brushed Motor Driver Library DRV8706-Q1 Motor Driver Module
 *  @defgroup   BSM__MSPM0L_DRV8706Q1 DRV8706-Q1 - Motor Driver Module
 *
 *  @anchor bsm_motor_driver_drv8706q1_Overview
 *  # Overview
 * 
 *  The DRV8706-Q1 motor driver module utilizes the HAL's apis to control the
 *  drv8706-q1 brushed motor driver.
 *
 *  <hr>
 ******************************************************************************/
/** @addtogroup BSM__MSPM0L_DRV8706Q1
 * @{
 */
#ifndef bsm_motor_driver_drv8706q1_h
#define bsm_motor_driver_drv8706q1_h

#include "hal.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! @enum DRV8706Q1_MODES
 *  @brief Represents the four different input control modes the DRV8706-Q1
 *         supports.
 */
typedef enum
{
    /*! DRV8706-Q1 H-Bridge Control Mode */
    DRV8706Q1_H_BRIDGE = 0,
    /*! DRV8706-Q1 Phase Enable Control Mode */
    DRV8706Q1_PH_EN,
    /*! DRV8706-Q1 Half Bridge Control Mode */
    DRV8706Q1_HALF_BRIDGE,
    /*! DRV8706-Q1 Solenoid Control Mode */
    DRV8706Q1_SPLIT_SOLENOID,
} DRV8706Q1_MODES;

/*! @enum DRV8706Q1_H_BRIDGE_DRIVES
 *  @brief Represents all the different configurations the H-Bridge control
 *         mode supports
 */
typedef enum {
    /*! H-Bridge Mode Coast Configuration */
    DRV8706Q1_H_BRIDGE_COAST = 0,
    /*! H-Bridge Mode Reverse Configuration */
    DRV8706Q1_H_BRIDGE_REVERSE,
    /*! H-Bridge Mode Forward Configuration */
    DRV8706Q1_H_BRIDGE_FORWARD,
    /*! H-Bridge Mode Freewheel Configuration */
    DRV8706Q1_H_BRIDGE_ACTIVE_FREEWHEEL,
} DRV8706Q1_H_BRIDGE_DRIVES;

/*! @enum DRV8706Q1_PHASE_DRIVES
 *  @brief Represents all the different configurations the Phase Enable
 *         control mode supports
 */
typedef enum {
    /*! Phase Enable Mode Reverse Configuration */
    DRV8706Q1_PHASE_REVERSE = 0,
    /*! Phase Enable Mode Forward Configuration */
    DRV8706Q1_PHASE_FORWARD,
    /*! Phase Enable Mode Freewheel Configuration */
    DRV8706Q1_PHASE_ACTIVE_FREEWHEEL,
} DRV8706Q1_PHASE_DRIVES;

/*! @enum DRV8706Q1_SOLENOID_DRIVES
 *  @brief Represents all the different configurations the Solenoid
 *         control mode supports
 */
typedef enum {
    /*! Solenoid Mode Disable Configuration */
    DRV8706Q1_SOLENOID_DISABLE = 0,
    /*! Solenoid Mode PWM Configuration */
    DRV8706Q1_SOLENOID_PWM,
} DRV8706Q1_SOLENOID_DRIVES;

/*! @enum DRV8706Q1_HALF_BRIDGE_DRIVES
 *  @brief Represents all the different configurations the Half Bridge
 *         control mode supports
 */
typedef enum {
    /*! Half-Bridge Mode Hi-Z Configuration */
    DRV8706Q1_HALF_BRIDGE_HI_Z = 0,
    /*! Half-Bridge Mode PWM Configuration*/
    DRV8706Q1_HALF_BRIDGE_PWM,
} DRV8706Q1_HALF_BRIDGE_DRIVES;

/*! @enum DRV8706Q1_PWM_CHANNELS
 *  @brief Represents the motor driver's input pins that expects a PWM
 *         signal.
 */
typedef enum {
    /*! MCU PWM pin connected to IN1/EN */
    DRV8706Q1_PWM_CHANNEL_0 = 0,
    /*! MCU PWM pin connected to IN2/PH */
    DRV8706Q1_PWM_CHANNEL_1,
} DRV8706Q1_PWM_CHANNELS;

/*! @enum DRV8706Q1_SPI_ADDR
 *  @brief Represents the addresses for all the SPI registers
 */
typedef enum {
    /*! Address value for IC_STAT_1 register */
    DRV8706Q1_SPI_ADDR_IC_STAT_1 = 0,
    /*! Address value for VGS_VDS_STAT register */
    DRV8706Q1_SPI_ADDR_VGS_VDS_STAT,
    /*! Address value for IC_STAT_2 register */
    DRV8706Q1_SPI_ADDR_IC_STAT_2,
    /*! Address value for RSVD_STAT register */
    DRV8706Q1_SPI_ADDR_RSVD_STAT,
    /*! Address value for IC_CTRL register */
    DRV8706Q1_SPI_ADDR_IC_CTRL,
    /*! Address value for BRG_CTRL register */
    DRV8706Q1_SPI_ADDR_BRG_CTRL,
    /*! Address value for DRV_CTRL_1 register */
    DRV8706Q1_SPI_ADDR_DRV_CTRL_1,
    /*! Address value for DRV_CTRL_2 register */
    DRV8706Q1_SPI_ADDR_DRV_CTRL_2,
    /*! Address value for DRV_CTRL_3 register */
    DRV8706Q1_SPI_ADDR_DRV_CTRL_3,
    /*! Address value for VDS_CTRL_1 register */
    DRV8706Q1_SPI_ADDR_VDS_CTRL_1,
    /*! Address value for VDS_CTRL_2 register */
    DRV8706Q1_SPI_ADDR_VDS_CTRL_2,
    /*! Address value for OLSC_CTRL register */
    DRV8706Q1_SPI_ADDR_OLSC_CTRL,
    /*! Address value for UVOV_CTRL register */
    DRV8706Q1_SPI_ADDR_UVOV_CTRL,
    /*! Address value for CSA_CTRL register */
    DRV8706Q1_SPI_ADDR_CSA_CTRL
} DRV8706Q1_SPI_ADDR;

/*! @enum DRV8706Q1_CSA_GAINS
 *  @brief Represents all the current sense amplifier gain settings
 */
typedef enum {
    /*! For 10.15 V/V Gain Setting */
    DRV8706Q1_CSA_GAIN_10 = 10,
    /*! For 20 V/V Gain Setting */
    DRV8706Q1_CSA_GAIN_20 = 20,
    /*! For 40 V/V Gain Setting */
    DRV8706Q1_CSA_GAIN_40 = 40,
    /*! For 80 V/V Gain Setting */
    DRV8706Q1_CSA_GAIN_80 = 80,
} DRV8706Q1_CSA_GAINS;

/*! @enum DRV8706Q1_CSA_DIV
 *  @brief Represents all the current sense amplifier reference voltage
 *         divider settings.
 */
typedef enum {
    /*! Current shunt amplifier reference divided by 2 */
    DRV8706Q1_CSA_DIV_2 = 2,
    /*! Current shunt amplifier reference divided by 8 */
    DRV8706Q1_CSA_DIV_8 = 8,
} DRV8706Q1_CSA_DIV;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*! @enum DRV8706Q1_SPI_W0_BIT */
typedef enum {
    /*! MCU is sending a SPI write command to motor driver */
    DRV8706Q1_SPI_W0_WRITE = 0,
    /*! MCU is sending a SPI read command to motor driver */
    DRV8706Q1_SPI_W0_READ = 1,
} DRV8706Q1_SPI_W0_BIT;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

/*! @struct DRV8706Q1_INSTANCE
 *  @brief Internal structure that represents a specific DRV8706-Q1
 */
typedef struct {
    /*!
     * HAL ADC channel used to read from the motor driver's CSA. @ref ADC_CHANS
     */
    ADC_CHANS adcChan;
    /*!
     * Scale factor used to cache values needed to calculate current from CSA
     * output
     */
    _iq20 csaSF;
    /*!
     * HAL output pin connected to the motor driver's nSleep pin.
     * @ref GPIO_OUTPUT_PINS
     */
    GPIO_OUTPUT_PINS    nSleep;
    /*!
     * HAL output pin connected to the motor driver's drvOff pin.
     * @ref GPIO_OUTPUT_PINS
     */
    GPIO_OUTPUT_PINS    drvOff;
    /*!
     * HAL input pin connected to the motor driver's nFault pin.
     * @ref GPIO_OUTPUT_PINS
     */
    GPIO_INPUT_PINS     nFault;
    /*!
     * HAL output pin connected to the motor driver's nHiz1 pin.
     * @ref GPIO_OUTPUT_PINS
     */
    GPIO_OUTPUT_PINS    nHiz1;
    /*!
     * HAL output pin connected to the motor driver's nHiz2 pin.
     * @ref GPIO_OUTPUT_PINS
     */
    GPIO_OUTPUT_PINS    nHiz2;
    /*!
     * HAL PWM channel connected to the motor driver's IN1 pin
     * @ref PWM_CHANNELS
     */
    PWM_CHANNELS        in1En;
    /*!
     * HAL PWM channel connected to the motor driver's IN2 pin
     * @ref PWM_CHANNELS
     */
    PWM_CHANNELS        in2Ph;
    /*!
     * HAL SPI channel connected to the motor driver's spi pins
     * @ref SPI_CHANNELS
     */
    SPI_CHANNELS        spiChan;
    /*!
     * HAL SPI CS connected to the motor driver's spi cs pin
     * @ref SPI_CS
     */
    SPI_CS              spiCS;

    /*!
     * Voltage connected to motor driver analog reference pin
     */
    _iq20               aRef_V;

    /*!
     * Motor driver current sense amplifier gain setting
     */
    DRV8706Q1_CSA_GAINS csaGain;

    /*!
     * Current shunt amplifier reference voltage divider
     */
    DRV8706Q1_CSA_DIV csaDiv;

    /*!
     * Current shunt resistor value in mΩ
     */
    _iq20               shuntRes;

    /*!
     * The current control mode the motor driver is configured to
     */
    DRV8706Q1_MODES     driveMode;
} DRV8706Q1_INSTANCE;


/**
 * @brief Initialized critical structure representing specific instance of
 *        the motor driver. <b> Important </b> Not calling this function will
 *        result in unexpected results.
 * 
 * @param drv Motor driver instances to use
 */
void DRV8706Q1_init(DRV8706Q1_INSTANCE* drv);

/**
 * @brief Function will program the motor driver to switch to H-bridge
 *        control mode and reconfigure the pin to the selected H-bridge mode
 *        pin configuration to use.
 *        <b> Important </b>
 *        Note this function updates the motor driver registers via SPI.
 *
 * @param drv Motor driver instances to use
 * @param drive H-Bridge configuration to use when the mode is switch.
 * @return SPI value (uint16_t) returned when performing the write operation
 */
uint16_t DRV8706Q1_switchToHBridgeDrive(DRV8706Q1_INSTANCE* drv,
                                        DRV8706Q1_H_BRIDGE_DRIVES drive);

/**
 * @brief Function will reconfigure the pins for the specific H-bridge mode
 *        configuration. Unlike @ref DRV8706Q1_switchToHBridgeDrive this
 *        function does not update the control mode via SPI. So the device
 *        must be configured to H-bridge mode already.
 *
 * @param drv Motor driver instances to use
 * @param drive H-Bridge configuration to use when the mode is switch.
 */
void DRV8706Q1_changeHBridgeDrive(DRV8706Q1_INSTANCE drv,
                                  DRV8706Q1_H_BRIDGE_DRIVES drive);

/**
 * @brief Function will program the motor driver to switch to Phase
 *        control mode and reconfigure the pin to the selected Phase mode
 *        pin configuration to use. Note this function updates the motor driver
 *        registers via SPI.
 *
 * @param drv Motor driver instances to use
 * @param drive Phase Enable configuration to use when the mode is switched.
 * @return SPI value (uint16_t) returned when performing the write operation
 */
uint16_t DRV8706Q1_switchToPhaseDrive(DRV8706Q1_INSTANCE* drv,
                                      DRV8706Q1_PHASE_DRIVES drive);

/**
 * @brief Function will reconfigure the pins for the specific Phase enable mode
 *        configuration. Unlike @ref DRV8706Q1_switchToPhaseDrive this function
 *        does not update the control mode via SPI. So the device must be
 *        configured to Phase enable mode already.
 *
 * @param drv Motor driver instances to use
 * @param drive Phase enable configuration to use when the mode is switch.
 */
void DRV8706Q1_changePhaseDrive(DRV8706Q1_INSTANCE drv,
                                DRV8706Q1_PHASE_DRIVES drive);

/**
 * @brief Function will reconfigure the pins for the specific Solenoid mode
 *        configuration. Unlike @ref DRV8706Q1_switchToSolenoidDrive this
 *        function does not update the control mode via SPI. So the device
 *        must be configured to solenoid already.
 *
 * @param drv Motor driver instances to use
 * @param drive Solenoid mode configuration to use.
 */
void DRV8706Q1_changeSolenoidDrive(DRV8706Q1_INSTANCE drv,
                                   DRV8706Q1_SOLENOID_DRIVES drive);

/**
 * @brief Function will reconfigure the pins for the specific Half Bridge mode
 *        configuration. Unlike @ref DRV8706Q1_switchToHalfBridgeDrive this
 *        function does not update the control mode via SPI. So the device must
 *        be configured to Phase enable mode already.
 *
 * @param drv Motor driver instances to use
 * @param drvChan The DRV PWM channel being configured
 * @param drive Half Bridge drive configuration to use when the mode is switch.
 */
void DRV8706Q1_changeHalfBridgeDrive(DRV8706Q1_INSTANCE drv,
                             DRV8706Q1_PWM_CHANNELS drvChan,
                             DRV8706Q1_HALF_BRIDGE_DRIVES drive);

/**
 * @brief Function will reconfigure the pins for the specific Half Bridge mode
 *        configuration. Also the control mode will be updated via SPI.
 *
 * @param drv Motor driver instances to use
 * @param driveChan0 Half Bridge drive configuration for PWM channel 0 to use
 *                   when the mode is switch.
 * @param driveChan1 Half Bridge drive configuration for PWM channel 1 to use
 *                   when the mode is switch.
 * @return SPI value (uint16_t) returned when performing the write operation
 */
uint16_t DRV8706Q1_switchToHalfBridgeDrive(DRV8706Q1_INSTANCE* drv,
                                    DRV8706Q1_HALF_BRIDGE_DRIVES driveChan0,
                                    DRV8706Q1_HALF_BRIDGE_DRIVES driveChan1);

/**
 * @brief Function will program the motor driver to switch to Solenoid
 *        control mode and reconfigure the pin to the selected Solenoid mode
 *        pin configuration to use. Note this function updates the motor driver
 *        registers via SPI.
 *
 * @param drv Motor driver instances to use
 * @param drive Solenoid configuration to use when the mode is switched.
 * @return SPI value (uint16_t) returned when performing the write operation
 */
uint16_t DRV8706Q1_switchToSolenoidDrive(DRV8706Q1_INSTANCE* drv,
                                         DRV8706Q1_SOLENOID_DRIVES drive);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
uint16_t DRV8706Q1_spiCmd(SPI_CHANNELS spiChan,
                          SPI_CS spiCS,
                          DRV8706Q1_SPI_W0_BIT wo_bit,
                          DRV8706Q1_SPI_ADDR addr,
                          uint8_t data);
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

/**
 * @brief Function to allow a user to modify a specific bitfield in one of the
 *        motor driver's registers. This function automatically converts the
 *        parameters to the data format needed for SPI communication with the
 *        DRV8706-Q1.
 *
 * @param drv
 * @param addr Register address @ref DRV8706Q1_SPI_ADDR
 * @param mask Mask for the bitfield you want to update. Mask passed in
 *              should already be shifted so that it can be ~ANDed against
 *              the previously read register value. For example, if you want
 *              to create a mask for DRV_CTRL_3.VGS_TDRV (bit 5-4) you would
 *              write (3 << 4) or 0x30 for the mask.
 * @param value Bitfield value to write. Value passed in should already be
 *              shifted so that it can be ORed against the previously read
 *              register value. For example, if you want to set
 *              DRV_CTRL_3.VGS_TDRV (bit 5-4) to 4 us (10b). You would set
 *              value to (2<<4) or 0x20
 * @return uint16_t
 */
uint16_t DRV8706Q1_spiUpdateRegister(DRV8706Q1_INSTANCE drv,
                                     DRV8706Q1_SPI_ADDR addr,
                                     uint8_t mask,
                                     uint8_t value);


/**
 * @brief Perform a SPI write operation. This function already converts the
 *        address and data to the data format required by the motor driver.
 *        Note that if the motor driver is sleeping then the motor driver
 *        will ignore the spi operation
 *
 * @param drv The motor driver instances
 * @param addr The motor driver SPI address to be written to.
 * @param data The value to be written to the specific motor driver SPI
 *             address. Note this function will overwrite the entire register
 *             value with the value you passed here. If you only want to update
 *             a specific bitfield use @ref DRV8706Q1_spiUpdateRegister instead.
 *
 * @return Return the 16 bit value returned by the motor driver when reading
 *         SPI.
 */
__STATIC_INLINE uint16_t DRV8706Q1_spiWriteCmd(DRV8706Q1_INSTANCE drv,
                                      DRV8706Q1_SPI_ADDR addr,
                                      uint8_t data) {
    return DRV8706Q1_spiCmd(drv.spiChan,drv.spiCS, DRV8706Q1_SPI_W0_WRITE,addr,data);
}

/**
 * @brief Perform a SPI read operation. This function converts the
 *        address to the data format required by the motor driver.
 *        Note that if the motor driver is sleeping then the motor driver
 *        will ignore the spi operation and you will read back 0x0.
 *
 * @param drv The motor driver instances
 * @param addr The motor driver SPI address to be read
 *
 * @return Return the 16 bit value returned by the motor driver when reading
 *         SPI.
 */
__STATIC_INLINE  uint16_t DRV8706Q1_spiReadCmd(DRV8706Q1_INSTANCE drv,
                                     DRV8706Q1_SPI_ADDR addr) {
    return DRV8706Q1_spiCmd(drv.spiChan,drv.spiCS, DRV8706Q1_SPI_W0_READ,addr,0x0);
}


/**
 * @brief Return the current read from the DRV8706-Q1 motor driver
 *
 * @param drv
 * @return _iq20
 */
_iq20 DRV8706Q1_getCurrent(DRV8706Q1_INSTANCE drv);

#ifndef DOXYGEN_SHOULD_SKIP_THIS

void DRV8706Q1_setPWMFreq(DRV8706Q1_INSTANCE drv,
                          DRV8706Q1_PWM_CHANNELS drvChan,
                          uint32_t value);

void DRV8706Q1_setDutyCycle(DRV8706Q1_INSTANCE drv,
                            DRV8706Q1_PWM_CHANNELS drvChan,
                            uint8_t value);
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

/**
 * @brief Sets the PWM frequency for the correct channel based on the drive
 *        specified.
 *
 * @param drv Motor driver instance
 * @param drvPwmChan The value for this parameter only matters when using
 *                   half-bridge mode which is the only mode that the PWM
 *                   frequency should be different.
 * @param value PWM frequency specified. Note that the value you set here
 *              and the actual output frequency is dependent on the timer's
 *              clock configuration.
 */
void DRV8706Q1_setDrivePWMFreq(DRV8706Q1_INSTANCE drv,
                               DRV8706Q1_PWM_CHANNELS drvPwmChan,
                               uint32_t value);


/**
 * @brief Sets the duty cycle for the correct channel based on the drive
 *        specified.
 *
 * @param drv Motor driver instance
 * @param drvPwmChan The value for this parameter only matters when using
 *                   half-bridge mode which is the only mode that the
 *                   duty cycle can be different for each channel.
 * @param value Duty Cycle to use. Valid values are 0-100. Using any other
 *              value can cause unexpected behavior.
 */
void DRV8706Q1_setDriveDutyCycle(DRV8706Q1_INSTANCE drv,
                                 DRV8706Q1_PWM_CHANNELS drvPwmChan,
                                 uint8_t value);

/**
 * @brief This functions resets the SPI registers of the motor driver by
 *        putting it to sleep, delaying and waking it up. Note that when
 *        this function is called the motor driver sleep pin will be high.
 *        This functional internally calls @ref DRV8706Q1_powerOnResetVal
 *
 * @param drv Motor driver instance.
 */
void DRV8706Q1_reset(DRV8706Q1_INSTANCE* drv);

/**
 * @brief Reset internal DRV structure variables to sync with the motor driver
 *        registers power on reset value.
 *
 * @param drv Motor driver instance.
 */
void DRV8706Q1_powerOnResetVal(DRV8706Q1_INSTANCE* drv);

/**
 * @brief Help function that controls the MCU pin connected to nSleep pin on
 *        the motor driver. Note if you manually set nSLEEP low for more than
 *        1 ms then all the register values will be reset to their default
 *        values. Therefore, it would be important to immediately call
 *        @ref DRV8706Q1_powerOnResetVal whenver you set nSLEEP to high to make
 *        sure internal structures are sync.
 *
 * @param drv Motor driver instance
 * @param value True = pin is HIGH or False = pin is LOW
 */
__STATIC_INLINE void DRV8706Q1_setNSleep(DRV8706Q1_INSTANCE drv,bool value) {
    HAL_setGPIOOutput(drv.nSleep,value);
    /* tWake - Turnon time = 1ms
     * tSleep - Turnoff time = 1ms
     * So not matter what you set sleep pin to just wait 1 ms
     */
    HAL_delayMilliSeconds(1);
}

/**
 * @brief Help function that controls the MCU pin connected to DrvOff pin on
 *        the motor driver.
 *
 * @param drv Motor driver instance
 * @param value True = pin is HIGH or False = pin is LOW
 */
__STATIC_INLINE void DRV8706Q1_setDrvOff(DRV8706Q1_INSTANCE drv,bool value) {
    HAL_setGPIOOutput(drv.drvOff,value);
}

/**
 * @brief Help function that controls the MCU pin connected to nHiZ1 pin on
 *        the motor driver.
 *
 * @param drv Motor driver instance
 * @param value True = pin is HIGH or False = pin is LOW
 */
__STATIC_INLINE void DRV8706Q1_setNHiZ1(DRV8706Q1_INSTANCE drv,bool value) {
    HAL_setGPIOOutput(drv.nHiz1,value);
}

/**
 * @brief Help function that controls the MCU pin connected to nHiZ2 pin on
 *        the motor driver.
 *
 * @param drv Motor driver instance
 * @param value True = pin is HIGH or False = pin is LOW
 */
__STATIC_INLINE void DRV8706Q1_setNHiZ2(DRV8706Q1_INSTANCE drv,bool value) {
    HAL_setGPIOOutput(drv.nHiz2,value);
}

/**
 * @brief Set voltage connected to the motor driver's AREF pin. This value
 *        is needed to properly calculate the motor's current.
 *
 * @param drv Reference to the motor driver instance
 * @param aRef_V Analog voltage reference in _iq20 format. Use the function
 *               _IQ20() to convert the voltage from a int or float to _iq20
 *               before passing it as a parameter. Otherwise the calculations
 *               will be incorrect.
 */
void DRV8706Q1_setAnalogReference(DRV8706Q1_INSTANCE *drv, _iq20 aRef_V);

/**
 * @brief Set current shunt amplifier reference voltage divider. This function
 *        will update the CSA_CTRL.CSA_DIV register bitfield to the specified
 *        voltage divider.
 *
 * @param drv Reference to motor driver instance
 * @param csaDiv Analog reference voltage divider
 * @return uint16_t This function will return the SPI value returned after
 *         writing the SPI register.
 */
uint16_t DRV8706Q1_setAnalogReferenceDivider(DRV8706Q1_INSTANCE *drv,
                                            DRV8706Q1_CSA_DIV csaDiv);

/**
 * @brief Configure the CSA to the gain setting specified. This function will
 *        update the CSA_CTRL.CSA_GAIN register bitfield with the gain you
 *        specified.
 *
 * @param drv Reference to motor driver instance
 * @param gcsa Gain setting you want to use.
 * @return uint16_t This function will return the SPI value returned after
 *         writing the SPI register.
 */
uint16_t DRV8706Q1_setCurrentSenseGain(DRV8706Q1_INSTANCE *drv,
                                       DRV8706Q1_CSA_GAINS gcsa);

/**
 * @brief Set the current shunt resistor value used by the current sense
 *        amplifier. This value needs to be set based on the used by your
 *        hardware.
 *
 * @param drv Reference to motor driver instance
 * @param rShunt Current shunt resistor value in mOhms in _iq20 format. Use
 *               the function _IQ20() to convert the voltage from a int or
 *               float to _iq20 before passing it as a parameter. Otherwise
 *               the calculations will be incorrect.
 */
void DRV8706Q1_setCurrentShuntResistor(DRV8706Q1_INSTANCE *drv,
                                       _iq20 rShunt);

#ifdef __cplusplus
}
#endif

#endif

/** @}*/
