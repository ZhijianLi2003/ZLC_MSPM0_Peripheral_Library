/*
 * Copyright (c) 2018-2019 Texas Instruments Incorporated - http://www.ti.com
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
 *  ======== I2CMSPM0.syscfg.js ========
 */

"use strict";

/* get Common /ti/drivers utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");
let I2CCommon = system.getScript("/ti/driverlib/I2C.common.js");

/* PROFILES CONFIGURATION */
let i2cConfig = [
    /* Show selected peripheral below instance name */
    {
        name: "selectedInstance",
        displayName: "Selected Peripheral",
        default: "",
        longDescription: `Refer to the PinMux section for peripheral selection. Chosen instance name is not indicative of active peripheral.`,
        getValue: (inst) => {
            let solution = "";
            try{
                solution = inst.peripheral.$solution.peripheralName;
            }catch (e) {
                // do nothing
            }
            return solution;
        }
    },
    /****** PROFILES CONFIGURATION *******/
    {
        name: "GROUP_PROFILE",
        displayName: "Quick Profiles",
        description: "",
        collapsed: false,
        config: [
            {
                name        : "profile",
                displayName : "I2C Profiles",
                description : 'Pre-defined profiles for typical I2C configurations',
                longDescription: `
The I2C (Inter-IC) module provides a standardized serial interface to transfer
data between MSP devices and other external I2C devices (such as a Sensors,
Memory, or DACs).

![I2C Block Diagram](../docs/english/sysconfig/images/i2CBlockDiagM0G3xx.png "I2C Block Diagram")

The Quick Profile Options are:
* **Custom**:
    * Allows custom configuration.`,
                hidden      : false,
                default     : "CUSTOM",
                options     : [
                    {name: "CUSTOM", displayName: "Custom"},
                ],
                onChange    : onChangeI2CProfile,
            },
        ],
    },
]

/* BASIC CONFIGURATION */
function onChangeEnableControllerSMBUS(inst,ui){
    ui.enableControllerPEC.hidden = !inst.basicEnableController;
    I2CCommon.onChangeEnableController(inst,ui);
}
function onChangeEnableTargetSMBUS(inst,ui){
    let targetStatus = !inst.basicEnableTarget;
    ui.enableDefaultHostAddr.hidden = targetStatus;
    ui.enableAlertResponseAddr.hidden = targetStatus;
    ui.enableDefaultDevAddr.hidden = targetStatus;
    ui.enableTargetPEC.hidden = targetStatus;
    ui.enableTargetPECACKNext.hidden = targetStatus || !inst.enableTargetPEC;
    ui.enableTargetPECACKDone.hidden = targetStatus || !inst.enableTargetPEC;
    I2CCommon.onChangeEnableTarget(inst,ui);
}

let basicI2CConfig;
basicI2CConfig = [
    {
        name        : "basicEnableController",
        displayName : "Enable Controller Mode",
        description : 'Enables I2C Controller Mode',
        hidden      : false,
        default     : false,
        onChange    : onChangeEnableControllerSMBUS

    },
    {
        name        : "basicEnableTarget",
        displayName : "Enable Target Mode",
        description : 'Enables I2C Target Mode',
        hidden      : false,
        default     : false,
        onChange    : onChangeEnableTargetSMBUS

    },
];
basicI2CConfig = basicI2CConfig.concat(I2CCommon.getBasicConfig());

i2cConfig = i2cConfig.concat([
    /****** Start of BASIC CONFIGURATION *******/
    {
        name: "basicConfig",
        displayName: "Basic Configuration",
        longDescription:
`Basic I2C options allow configuration of Controller and/or Target mode with the
most common options to enable basic communication, such as frequency, and
addresses.
`,
        collapsed: false,
        config: basicI2CConfig,
    }, /****** End of BASIC CONFIGURATION *******/
])

/* SMBUS CONFIGURATION */
i2cConfig = i2cConfig.concat([
    /****** Start of SMBUS CONFIGURATION *******/
    {
        name: "smbusConfig",
        displayName: "SMBUS Configuration",
        longDescription:
`Configure SMBUS-specific features. \n
Options will become available once either of Controller/Target Modes are enabled.`,
        collapsed: false,
        config: [
            {
                name: "smbusController",
                displayName: "SMBUS Controller Configuration",
                longDescription:
        ``,
                collapsed: false,
                config: [
                    // DL_I2C_enableControllerPEC / DL_I2C_disableControllerPEC
                    {
                        name: "enableControllerPEC",
                        displayName: "Enable Packet Error Checking (PEC)",
                        description: "Enable target SMBus/PMBus Packet Error Checking (PEC)",
                        longDescription:
`When enabled, the PEC is calculated on all bits accept the Start, Stop, ACK
and NACK. The PEC LSFR and the Byte Counter is set to 0 when the State
Machine is in the IDLE state, which occurs following a Stop or when a
timeout occurs. The Counter is also set to 0 after the PEC byte is sent or
received. Note that the NACK is automatically sent following a PEC byte
that results in a PEC error.
`,
                        default: false,
                        hidden: true,
                    }
                ]
            },
            {
                name: "smbusTarget",
                displayName: "SMBUS Target Configuration",
                longDescription:
        ``,
                collapsed: false,
                config: [
                    // enableDefaultHostAddress / disableDefaultHostAddress
                    {
                        name: "enableDefaultHostAddr",
                        displayName: "Enable Default Host Address",
                        description: "Enable SMBus/PMBus default host address of 000_1000b",
                        default: false,
                        hidden: true,
                    },
                    // DL_I2C_enableAlertResponseAddress / DL_I2C_disableAlertResponseAddress
                    {
                        name: "enableAlertResponseAddr",
                        displayName: "Enable Alert Response Address (ARA)",
                        description: "Enable SMBus/PMBus Alert response address (ARA) of 000_1100b",
                        default: false,
                        hidden: true,
                    },
                    // DL_I2C_enableDefaultDeviceAddress / DL_I2C_disableDefaultDeviceAddress
                    {
                        name: "enableDefaultDevAddr",
                        displayName: "Enable Default Device Address",
                        description: "Enable SMBus/PMBus default device address of 110_0001b",
                        default: false,
                        hidden: true,
                    },
                    // DL_I2C_enableTargetPEC / DL_I2C_disableTargetPEC
                    {
                        name: "enableTargetPEC",
                        displayName: "Enable Packet Error Checking (PEC)",
                        description: "Enable target SMBus/PMBus Packet Error Checking (PEC)",
                        longDescription:
` When enabled, the PEC is calculated on all bits accept the Start, Stop, ACK
and NACK. The PEC LSFR and the Byte Counter is set to 0 when the State
Machine is in the IDLE state, which occurs following a Stop or when a
timeout occurs. The Counter is also set to 0 after the PEC byte is sent or
received. Note that the NACK is automatically sent following a PEC byte
that results in a PEC error.
`,
                        default: false,
                        hidden: true,
                        onChange: (inst,ui) => {
                            ui.enableTargetPECACKNext.hidden = !inst.enableTargetPEC;
                            ui.enableTargetPECACKDone.hidden = !inst.enableTargetPEC;
                        }
                    },
                    // DL_I2C_enableACKOverrideOnPECNext
                    {
                        name: "enableTargetPECACKNext",
                        displayName:"Enable Target ACK When PEC Is Next Byte",
                        description: "Enable Target ACK Override when SMBus/PMBus PEC is next byte",
                        default: false,
                        hidden: true,
                    },
                    // DL_I2C_enableACKOverrideOnPECDone
                    {
                        name: "enableTargetPECACKDone",
                        displayName: "Enable Target ACK When PEC Is Done",
                        description: "Enable Target ACK Override when SMBus/PMBus PEC is done",
                        default: false,
                        hidden: true,
                    },
                ],
            },
        ],
    }, /****** End of SMBUS CONFIGURATION *******/
])

/* ADVANCED CONFIGURATION */
i2cConfig = i2cConfig.concat([
    /****** Start of ADVANCED  CONFIGURATION *******/
    {
        name: "advancedConfig",
        displayName: "Advanced Configuration",
        longDescription:
`Advanced I2C options allow configuration of advanced features of this I2C
module, including loopback mode, clock timeout detection, glitch filters, etc. `,
        collapsed: true,
        config: I2CCommon.getAdvancedConfig(),
    }, /****** End of ADVANCED CONFIGURATION *******/
])

/* INTERRUPT CONFIGURATION */
i2cConfig = i2cConfig.concat([
    /****** Start of INTERRUPT CONFIGURATION *******/
    {
        name: "interruptConfig",
        displayName: "Interrupt Configuration",
        longDescription: "This section allows enabling/disabling I2C interrupts",
        collapsed: true,
        config: [
            /****** Start of INTERRUPT CONFIGURATION FOR CONTROLLER *******/
            {
                name: "intController",
                displayName: "Controller Interrupts",
                description: "Enables/Disables controller interrupts",
                longDescription: `
Multiple interrupt events can be selected. The application can read the
interrupt status or index to detect which flag triggered the interrupt.\n
I2C Controller mode must be enabled to configure interrupts`,
                default: [],
                options: getControllerIntOptions,
                getDisabledOptions: getControllerDisabledIntOptions,
                onChange    : onChangeintController
            },
            {
                name: "intTarget",
                displayName: "Target Interrupts",
                description: "Enables/Disables target interrupts",
                longDescription: `
Multiple interrupt events can be selected. The application can read the
interrupt status or index to detect which flag triggered the interrupt.\n
I2C Target mode must be enabled to configure interrupts`,
                hidden: false,
                default: [],
                options: getTargetIntOptions,
                getDisabledOptions: getTargetDisabledIntOptions,
                onChange    : onChangeintTarget
            },
            {
                name: "intGeneric",
                displayName: "Timeout Interrupts",
                description: "Enables/Disables timeout interrupts",
                longDescription: `
Multiple interrupt events can be selected. The application can read the
interrupt status or index to detect which flag triggered the interrupt.\n
Timeouts must be enabled to configure interrupts`,
                hidden: false,
                default: [],
                options: getGenericIntOptions,
                getDisabledOptions: getGenericDisabledIntOptions,
                onChange    : onChangeintGeneric
            },
            {
                name: "interruptPriority",
                displayName: "Interrupt Priority",
                description: "Specifies interrupt priority",
                longDescription: '',
                hidden: true,
                default: "DEFAULT",
                options: Common.InterruptPriorityOptions,
            },
        ]
    }, /****** End of INTERRUPT CONFIGURATION *******/
])

/* DMA CONFIGURATION */
i2cConfig = i2cConfig.concat([
    /****** Start of DMA CONFIGURATION *******/
    {
        name: "GROUP_DMA",
        displayName: "DMA Configuration",
        longDescription: `
This section allows configuring DMA Event triggers.\n
The I2C module provides an interface to the DMA controller with two channels.\n
When the DMA functionality is enabled, the I2C asserts a DMA request on the
selected channel when the associated FIFO can transfer or receive data.\n
Only one DMA trigger per channel must be enabled at the same time. \n
Controller and/or Target mode must be enabled to enable the corresponding DMA
triggers.
`,
        collapsed: true,
        config: I2CCommon.getDMAConfig(),
    }, /****** End of DMA CONFIGURATION *******/
])

/* Add Pinmux Peripheral Configuration group */
i2cConfig = i2cConfig.concat(Common.getGPIOGroupConfig());

/*
 * Gets a DMA module if available
 */
function moduleInstances(inst){
    let modInstances = []
    I2CCommon.getDMAModInstances(inst,modInstances);

    /*
     * Gets a Peripheral GPIO Configuration submodule
     */
    /* SDA */
    Common.pushGPIOConfigInst(inst, modInstances,   true,    "sdaPin",
     "SDA", "I2C Serial Data line (SDA)",
     "INPUT");

    /* SCL */
    Common.pushGPIOConfigInst(inst, modInstances,   true,    "sclPin",
     "SCL", "I2C Serial Clock line (SDL)",
     "INPUT");

    return modInstances;
}

/*
 *  ======== devSpecific ========
 *  Device-specific extensions to be added to base I2C configuration
 */
let devSpecific = {
    config: i2cConfig,

    maxInstances: Common.peripheralCount("I2C"),

    validate: validate,

    pinmuxRequirements: pinmuxRequirements,

    filterHardware: filterHardware,

    moduleInstances: moduleInstances,

    templates: {
        boardc : "/ti/driverlib/i2c/I2C.Board.c.xdt",
        boardh : "/ti/driverlib/i2c/I2C.Board.h.xdt",
        Call: true,
        Reset: true,
        Power: true,
        GPIO: true,
        Function: true
    },
    modules: I2CCommon.setRequiredModules,


    _getPinResources: _getPinResources
};

function setRequiredModules(inst){
    return I2CCommon.setRequiredModules(inst);
};

/*  ======== pinmuxRequirements ========
 *  Returns peripheral pin requirements of the specified instance
 *
 *  param inst    - a fully configured module instance
 *
 *  returns req[] - an array of pin requirements needed by inst
 */
function pinmuxRequirements(inst)
{
    let allResources = [
        {
            name:"sdaPin",
            displayName:"I2C Serial Data line (SDA)",
            interfaceNames:["SDA"],
        },
        {
            name:"sclPin",
            displayName:"I2C Serial Clock line (SCL)",
            interfaceNames:["SCL"],
        },
    ];

    let i2c = {
        name: "peripheral",
        displayName: "I2C Peripheral",
        interfaceName: "I2C",
        resources: allResources,
        signalTypes: {
            sdaPin: ["SDA"],
            sclPin: ["SCL"],
        }
    };

    return [i2c];
}

/*
 *  ========= filterHardware ========
 *  Check 'component' signals for compatibility with module
 *
 *  param component - hardware object describing signals and
 *                    resources they're attached to
 *  returns Boolean indicating whether or not to allow the component to
 *           be assigned to an instance's $hardware config
 */
function filterHardware(component)
{
    let modulePin;

    for (let sig in component.signals) {
        let type = component.signals[sig].type;
        if (Common.typeMatches(type, ["I2C"])) modulePin = sig;
    }
    let result = modulePin ? true : false;

    return (result);
}


/************************* Profiles functions *******************************/
/*
 *  ======== onChangeI2CProfile ========
 *  Called when I2C Profile is changed.
 *  Pre-configures I2C according to profiles
 *
 */
const profilesI2C = [];

function onChangeI2CProfile(inst, ui) {
    if (inst.profile != "CUSTOM")
    {
        let selectedProfileArray = profilesI2C.filter(obj =>
                                        {return obj.name === inst.profile});
        if (selectedProfileArray.length != 0)
        {
            const selectedProfile = Object.assign({}, selectedProfileArray[0]);
            //selectedProfile = selectedProfile[0];
            delete selectedProfile.name;
            Object.assign(inst, selectedProfile)
        }
        I2CCommon.updateGUIbasedonConfig(inst, ui);
    }
}

/************************Interrupt Functions **********************************/
/* OnChange functions for Interrupts */
function onChangeintController(inst, ui)
{
    I2CCommon.onChangeintController(inst,ui);
}

function onChangeintTarget(inst, ui)
{
    I2CCommon.onChangeintTarget(inst,ui);
}

function onChangeintGeneric(inst, ui)
{
    I2CCommon.onChangeintGeneric(inst,ui);
}

/* Functions to get Options for Interrupts */
function getGenericIntOptions(inst)
{
    let allOptions = [
        { name: "TIMEOUT_A", displayName: "Timeout A Event" , description: "Interrupt index for I2C Timeout A Event"},
        { name: "TIMEOUT_B", displayName: "Timeout B Event" , description: "Interrupt index for I2C Timeout B Event"},
    ];

    return allOptions;
}

function getGenericDisabledIntOptions(inst)
{
    let disabledInts = [];
    if(!inst.enableTimeoutA){
        disabledInts.push({ name: "TIMEOUT_A", displayName: "Timeout A Event" , reason: "Timeout A is disabled"});
    }
    if(!inst.enableTimeoutB){
        disabledInts.push({ name: "TIMEOUT_B", displayName: "Timeout B Event" , reason: "Timeout B is disabled"});
    }
    return disabledInts;
}

function getControllerIntOptions(inst)
{
    let allOptions = [
        { name: "RX_DONE", displayName: "RX Done", description: "Controller receive transaction completed interrupt" },
        { name: "TX_DONE", displayName: "TX Done", description: "Controller transmit transaction completed interrupt" },
        { name: "RXFIFO_TRIGGER", displayName: "RX FIFO trigger" , description: "Controller receive FIFO trigger. Trigger when RX FIFO contains >= defined bytes"},
        { name: "TXFIFO_TRIGGER", displayName: "TX FIFO trigger" , description: "Controller transmit FIFO trigger. Trigger when Transmit FIFO contains <= defined bytes"},
        { name: "RXFIFO_FULL", displayName: "RX FIFO Full" , description: "Controller RXFIFO full event. This interrupt is set if an RX FIFO is full"},
        { name: "TXFIFO_EMPTY", displayName: "TX FIFO Empty" , description: "Controller transmit FIFO empty interrupt. This interrupt is set if all data in the Transmit FIFO have been shifted out and the transmit goes into idle mode."},
        { name: "NACK", displayName: "Addr/Data NACK" , description: "Address/Data NACK interrupt"},
        { name: "START", displayName: "Start detection" , description: "Controller START detection interrupt"},
        { name: "STOP", displayName: "Stop detection" , description: "Controller STOP detection interrupt"},
        { name: "ARBITRATION_LOST", displayName: "Arbitration lost" , description: "Controller arbitration lost interrupt"},
        { name: "EVENT1_DMA_DONE", displayName: "DMA Event 1" , description: "Controller DMA done signal from event 1"},
        { name: "EVENT2_DMA_DONE", displayName: "DMA Event 2" , description: "Controller DMA done signal from event 2"},
        { name: "TIMEOUT_A", displayName: "Timeout A Event" , description: "Interrupt index for I2C Timeout A Event"},
        { name: "TIMEOUT_B", displayName: "Timeout B Event" , description: "Interrupt index for I2C Timeout B Event"},
        /* SMBUS- specific interrupts */
        { name: "PEC_RX_ERROR", displayName: "PEC RX Error" , description: "Interrupt index for I2C controller SMBus/PMBus PEC Receive Error Event"},

    ];

    return allOptions;
}

function getControllerDisabledIntOptions(inst)
{
    let allOptions = [
        { name: "RX_DONE", displayName: "RX Done", reason: "Controller mode is disabled"},
        { name: "TX_DONE", displayName: "TX Done", reason: "Controller mode is disabled"},
        { name: "RXFIFO_TRIGGER", displayName: "RX FIFO trigger" , reason: "Controller mode is disabled"},
        { name: "TXFIFO_TRIGGER", displayName: "TX FIFO trigger" , reason: "Controller mode is disabled"},
        { name: "RXFIFO_FULL", displayName: "RX FIFO Full" , reason: "Controller mode is disabled"},
        { name: "TXFIFO_EMPTY", displayName: "TX FIFO Empty" , reason: "Controller mode is disabled"},
        { name: "NACK", displayName: "Addr/Data NACK" , reason: "Controller mode is disabled"},
        { name: "START", displayName: "Start detection" , reason: "Controller mode is disabled"},
        { name: "STOP", displayName: "Stop detection" , reason: "Controller mode is disabled"},
        { name: "ARBITRATION_LOST", displayName: "Arbitration lost" , reason: "Controller mode is disabled"},
        { name: "EVENT1_DMA_DONE", displayName: "DMA Event 1" , reason: "Controller mode is disabled"},
        { name: "EVENT2_DMA_DONE", displayName: "DMA Event 2" , reason: "Controller mode is disabled"},
        { name: "TIMEOUT_A", displayName: "Timeout A Event" , reason: "Controller mode is disabled"},
        { name: "TIMEOUT_B", displayName: "Timeout B Event" , reason: "Controller mode is disabled"},
        /* SMBUS- specific interrupts */
        { name: "PEC_RX_ERROR", displayName: "PEC RX Error" , reason: "Controller mode is disabled"},
    ];

    if (inst.basicEnableController == true)
    {
        let disabledInts = [];
        if(!inst.enableTimeoutA){
            disabledInts.push({ name: "TIMEOUT_A", displayName: "Timeout A Event" , reason: "Timeout A is disabled"});
        }
        if(!inst.enableTimeoutB){
            disabledInts.push({ name: "TIMEOUT_B", displayName: "Timeout B Event" , reason: "Timeout B is disabled"});
        }
        return disabledInts;
    }
    else
    {
        return allOptions;
    }
}

function getTargetIntOptions(inst)
{
    let allOptions = [
        { name: "RX_DONE", displayName: "RX Done", description: "Target receive transaction completed interrupt" },
        { name: "TX_DONE", displayName: "TX Done", description: "Target transmit transaction completed interrupt" },
        { name: "RXFIFO_TRIGGER", displayName: "RX FIFO trigger" , description: "Target receive FIFO trigger. Trigger when RX FIFO contains >= defined bytes"},
        { name: "TXFIFO_TRIGGER", displayName: "TX FIFO trigger" , description: "Target transmit FIFO trigger. Trigger when Transmit FIFO contains <= defined bytes"},
        { name: "RXFIFO_FULL", displayName: "RX FIFO Full" , description: "Target RXFIFO full event. This interrupt is set if an RX FIFO is full"},
        { name: "TXFIFO_EMPTY", displayName: "TX FIFO Empty" , description: "Target transmit FIFO empty interrupt. This interrupt is set if all data in the Transmit FIFO have been shifted out and the transmit goes into idle mode."},
        { name: "START", displayName: "Start detection" , description: "Target START detection interrupt"},
        { name: "STOP", displayName: "Stop detection" , description: "Target STOP detection interrupt"},
        { name: "GENERAL_CALL", displayName: "General call" , description: "General call interrupt"},
        { name: "EVENT1_DMA_DONE", displayName: "DMA Event 1" , description: "Target DMA done signal from event 1"},
        { name: "EVENT2_DMA_DONE", displayName: "DMA Event 2" , description: "Target DMA done signal from event 2"},
        { name: "ARBITRATION_LOST", displayName: "Target Arbitration Lost Event" , description: "Interrupt index for I2C Target arbitration lost event"},
        { name: "TXFIFO_UNDERFLOW", displayName: "TX FIFO Underflow" , description: "Interrupt index for I2C Target TX FIFO underflow event"},
        { name: "RXFIFO_OVERFLOW", displayName: "RX FIFO Overflow" , description: "Interrupt index for I2C Target RX FIFO overflow event"},
        { name: "INTERRUPT_OVERFLOW ", displayName: "Interrupt Overflow" , description: "Interrupt index for I2C interrupt overflow event"},
        /* SMBUS- specific interrupts */
        { name: "PEC_RX_ERROR", displayName: "PEC RX Error" , description: "Target SMBus/PMBus PEC Receive Error Interrupt"},
    ];

    return allOptions;
}

function getTargetDisabledIntOptions(inst)
{
    let allOptions = [
        { name: "RX_DONE", displayName: "RX Done", reason: "Target mode is disabled"},
        { name: "TX_DONE", displayName: "TX Done", reason: "Target mode is disabled"},
        { name: "RXFIFO_TRIGGER", displayName: "RX FIFO trigger" , reason: "Target mode is disabled"},
        { name: "TXFIFO_TRIGGER", displayName: "TX FIFO trigger" , reason: "Target mode is disabled"},
        { name: "RXFIFO_FULL", displayName: "RX FIFO Full" , reason: "Target mode is disabled"},
        { name: "TXFIFO_EMPTY", displayName: "TX FIFO Empty" , reason: "Target mode is disabled"},
        { name: "START", displayName: "Start detection" , reason: "Target mode is disabled"},
        { name: "STOP", displayName: "Stop detection" , reason: "Target mode is disabled"},
        { name: "GENERAL_CALL", displayName: "General call" , reason: "Target mode is disabled"},
        { name: "EVENT1_DMA_DONE", displayName: "DMA Event 1" , reason: "Target mode is disabled"},
        { name: "EVENT2_DMA_DONE", displayName: "DMA Event 2" , reason: "Target mode is disabled"},
        { name: "ARBITRATION_LOST", displayName: "Target Arbitration Lost Event" , reason: "Target mode is disabled"},
        { name: "TXFIFO_UNDERFLOW", displayName: "TX FIFO Underflow" , reason: "Target mode is disabled"},
        { name: "RXFIFO_OVERFLOW", displayName: "RX FIFO Overflow" , reason: "Target mode is disabled"},
        { name: "INTERRUPT_OVERFLOW ", displayName: "Interrupt Overflow" , reason: "Target mode is disabled"},
        /* SMBUS- specific interrupts */
        { name: "PEC_RX_ERROR", displayName: "PEC RX Error" , reason: "Target mode is disabled"},
    ];

    if (inst.basicEnableTarget == true)
    {
        if(!inst.enableDefaultDevAddr){
            return[
                { name: "ARBITRATION_LOST", displayName: "Target Arbitration Lost Event" , reason: "Default Device Address is disabled."},
            ]
        }
        return [];
    }
    else
    {
        return allOptions;
    }
}

/*
 *  ======== validate ========
 *  Validate this inst's configuration
 *
 *  param inst       - PWM instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validate(inst, validation)
{
    I2CCommon.getValidation(inst,validation);
}

/*
 *  ======== _getPinResources ========
 */
function _getPinResources(inst)
{
    let pin;

    if (inst.module) {
        let modPin = "DIO" + inst.module.modulePin.$solution.devicePinName;
        modPin = modPin.match(/P\d+\.\d+/)[0];

        pin = "\nMODPIN: " + modPin;

        if (inst.$hardware && inst.$hardware.displayName) {
            pin += "\n" + inst.$hardware.displayName;
        }
    }

    return (pin);
}

/*
 *  ======== extend ========
 *  Extends a base exports object to include any device specifics
 *
 *  This function is invoked by the generic I2C module to
 *  allow us to augment/override as needed for MSPM0
 */
function extend(base)
{
    /* merge and overwrite base module attributes */
    let result = Object.assign({}, base, devSpecific);

    /* concatenate device-specific configs */
    result.config = base.config.concat(devSpecific.config);

    return (result);
}

/*
 *  ======== exports ========
 *  Export device-specific extensions to base exports
 */
exports = {
    extend: extend
};
