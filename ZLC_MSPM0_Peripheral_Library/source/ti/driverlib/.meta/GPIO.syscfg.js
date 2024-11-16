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
 *  ======== GPIO.syscfg.js ========
 */

"use strict";

/* get Common /ti/drivers utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");
let logError = Common.logError;
let logWarning = Common.logWarning;
let logInfo = Common.logInfo;

/* get /ti/drivers family name from device object */
let family = Common.device2Family(system.deviceData, "GPIO");

/* generic configuration parameters for GPIO instances */
let gpioConfig = [

];

/* map validation options to validation logging functions */
let logHandlers = {"Warn": logWarning, "Fail": logError, "Remark": logInfo};

/*
 *  ======== validate ========
 *  Validate this inst's configuration
 *
 *  @param inst - GPIO instance to be validated
 *  @param vo   - object to hold detected validation issues
 */
function validate(inst, validation)
{
    if (inst.$hardware != null) {
        /* get _all_ HW components attached to this GPIO */
        let components = inst.$hardware.$parents;
    }
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
    displayName:         "GPIO",
    description:         "GPIO Module",
    longDescription: `
The **GPIO module** enables and configures General Purpose I/O pins.

Under *Basic Configuration* users can:
- Put GPIO's into groups
- Configure digital IOMUX features
- Configure I/O based on Interrupts/Events
- Configure GPIO pins in low-power modes using FaskWake

Under *Advanced Configuration* users can configure glitch filters, clock
timeout detection, etc.

For *Global Pin Configuration,* see the Board module.

![GPIO Block Diagram](../docs/english/sysconfig/images/gpioBlockDiagram.png "GPIO Block Diagram")

Check the datasheet of your selected device for more detailed information.
`,
    config:              gpioConfig,
    modules:             Common.autoForceModules(["SYSCTL","Board","EVENT"]),
    validate:            validate,

    _getPinResources: _getPinResources,

};

/* extend the base exports to include family-specific content */
let deviceGPIO = system.getScript("/ti/driverlib/gpio/GPIOMSPM0");
exports = deviceGPIO.extend(base);
