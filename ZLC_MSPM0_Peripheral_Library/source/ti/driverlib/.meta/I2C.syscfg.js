/*
 * Copyright (c) 2018-2019, Texas Instruments Incorporated - http://www.ti.com
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
 *
 */

/*
 *  ======== I2C.syscfg.js ========
 */

/*
 * I2C speed configuration (Philips I2C specification
 * http://www.nxp.com/documents/user_manual/UM10204.pdf):
 *    Standard-mode, Fast-mode (Fm), Fast-mode Plus (Fm+), and High-speed
 *    mode (Hs-mode) devices are downward-compatible - any device may be
 *    operated at a lower bus speed. Ultra Fast-mode devices are not
 *    compatible with previous versions since the bus is unidirectional.
 *        Bidirectional bus:
 *            o Standard-mode (Sm), with a bit rate up to 100 kbit/s
 *            o Fast-mode (Fm), with a bit rate up to 400 kbit/s
 *            o Fast-mode Plus (Fm+), with a bit rate up to 1 Mbit/s
 *            o High-speed mode (Hs-mode), with a bit rate up to 3.4 Mbit/s.
 *        Unidirectional bus:
 *            o Ultra Fast-mode (UFm), with a bit rate up to 5 Mbit/s
 *
 * Each device connected to the bus is software addressable by a unique
 * address and simple master/slave relationships exist at all times.
 *
 * A master is the device which initiates a data transfer on the bus and
 * generates the clock signals to permit that transfer. At that time,
 * any device addressed is considered a slave.
 */

"use strict";

/* get Common /ti/drivers utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

/* generic configuration parameters for I2C instances */
let I2cConfig = [];

/*
 *  ======== validate ========
 *  Validate this inst's configuration
 *
 *  @param inst - I2C instance to be validated
 *  @param vo   - object to hold detected validation issues
 */
function validate(inst, validation)
{
    Common.validateNames(inst, validation);
}

/*
 *  ======== _getPinResources ========
 */
/* istanbul ignore next */
function _getPinResources(inst)
{
    return;
}

/*
 *  ======== base ========
 *  Define the base properties and methods
 */
let base = {
    /* generic sysconfig module interface */
    displayName:         "I2C",
    description:         "Inter-Integrated Circuit (I2C) Bus Driver",

    longDescription: `
The **I2C module** provides bidirectional data transfer through a two-wire
serial bus consisting of a data (SDA) and clock (SCL) line.

Under *Basic Configuration* users can:
- Enable and configure 4 supported I2C modes:
    - Controller transmit
    - Controller receive
    - Target transmit
    - Target receive
- Configure source clock

Under *Advanced Configuration* users can:
- Configure glitch filters
- Configure controller/target specific options such as:
    - TX/RX FIFO trigger levels, loopback mode, clock-low timeout, etc.

I2C Functional Block Diagram:

![I2C Block Diagram](../docs/english/sysconfig/images/i2CBlockDiagM0G3xx.png "I2C Block Diagram")

Check the datasheet of your selected device for more detailed information.
`,

    defaultInstanceName: "I2C_",

    /* instance properties and methods */
    config:              Common.addNameConfig(
        I2cConfig, "/ti/driverlib/I2C", "CONFIG_I2C_"),
    initPriority: 5,
    modules:             Common.autoForceModules(["SYSCTL","Board"]),
    validate:            validate,

    _getPinResources: _getPinResources,
};

/* extend the base exports to include family-specific content */
let deviceI2C = system.getScript("/ti/driverlib/i2c/I2CMSPM0");
exports = deviceI2C.extend(base);
