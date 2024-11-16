/*
 * Copyright (c) 2023 Texas Instruments Incorporated - http://www.ti.com
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
 *  ======== UARTMSPM0.js ========
 */

"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");
let UARTCommon = system.getScript("/ti/driverlib/UART.common.js");

/*
 *  ======== validate ========
 *  Validate this inst's configuration
 *
 *  param inst       - module instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validate(inst, validation)
{
    UARTCommon.getValidation(inst,validation);
}

/*
 *  ======== validatePinmux ========
 *  Validation run after solution
 *
 *  param inst       - module instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validatePinmux(inst, validation) {
    /* Validation run after solution */
    let solution = inst.peripheral.$solution.peripheralName;
    /* Verify if using UART Advanced instance */
    if(Common.isDeviceFamily_PARENT_MSPM0G1X0X_G3X0X()){
        if(inst.enableExtend){
            if(!(/UART0/.test(solution))){
                validation.logError("Extend features are only available on UART0 instances. Please select a UART0 instance from PinMux if available.",
                    inst,"enableExtend");
            }
        }
    }
    else if(Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()){
        if(inst.enableExtend){
            if(!(/UART0|UART1/.test(solution))){
                validation.logError("Extend features are only available on UART0 and UART1 instances. Please select a valid instance from PinMux if available.",
                    inst,"enableExtend");
            }
        }
    }
    else if(Common.isDeviceFamily_PARENT_MSPM0GX51X()){
        if(inst.enableExtend){
            if(!(/UART0|UART7/.test(solution))){
                validation.logError("Extend features are only available on UART0 and UART7 instances. Please select a valid instance from PinMux if available.",
                    inst,"enableExtend");
            }
        }
    }
    // /* Retention Validation */
    Common.getRetentionValidation(inst,validation);
}

/* PROFILES CONFIGURATION */
    let defaultDMAConfig = {
        enabledDMARXTriggers : "None",
        enabledDMATXTriggers : "None",
        enableDMARX : false,
        enableDMATX : false,
    }
    let configProfile1 = {
        name            : "CONFIG_PROFILE_1", /* INT_LOOPBACK_115200_BAUD */
        uartClkSrc      : "BUSCLK",
        enableExtend    : false,
        targetBaudRate  : 115200,
        calculatedBaudRate : 0,
        ovsRate         : "16",
        wordLength      : "8_BITS",
        parity          : "NONE",
        stopBits        : "ONE",
        flowControl     : "NONE",
        enableFIFO      : true,
        rxFifoThreshold : "DL_UART_RX_FIFO_LEVEL_ONE_ENTRY",
        rxTimeoutValue  : 0,
        enableInternalLoopback : true,
        enableMajorityVoting : false,
        enableMSBFirst : false,
        enableManchester : false,
        enableIrda      : false,
        setIrdaTxPulseClock : "DL_UART_IRDA_CLOCK_BAUD_RATE",
        setIrdaTxPolarity : "DL_UART_IRDA_POLARITY_LOW",
        setIrdaPulseLength : 0,
        enabledInterrupts : [],
        interruptPriority: "DEFAULT",
    };
    if(!Common.isDeviceM0C()){
        configProfile1 = {...configProfile1, ...defaultDMAConfig};
    };
    let configProfile2 = {
        name            : "CONFIG_PROFILE_2", /* 9600 LFCLK */
        uartClkSrc      : "LFCLK",
        enableExtend    : false,
        targetBaudRate  : 9600,
        calculatedBaudRate : 0,
        ovsRate         : "3",
        wordLength      : "8_BITS",
        parity          : "NONE",
        stopBits        : "ONE",
        flowControl     : "NONE",
        enableFIFO      : true,
        rxFifoThreshold : "DL_UART_RX_FIFO_LEVEL_ONE_ENTRY",
        rxTimeoutValue  : 0,
        enableInternalLoopback : false,
        enableMajorityVoting : false,
        enableMSBFirst : false,
        enableManchester : false,
        enableIrda      : false,
        setIrdaTxPulseClock : "DL_UART_IRDA_CLOCK_BAUD_RATE",
        setIrdaTxPolarity : "DL_UART_IRDA_POLARITY_LOW",
        setIrdaPulseLength : 0,
        enabledInterrupts : [],
        interruptPriority: "DEFAULT",
    };
    if(!Common.isDeviceM0C()){
        configProfile2 = {...configProfile2, ...defaultDMAConfig};
    };
    let configProfile3 = {
        name            : "CONFIG_PROFILE_3", /* 1 MHZ, HW Flow Control */
        uartClkSrc      : "BUSCLK",
        enableExtend    : false,
        targetBaudRate  : 1000000,
        calculatedBaudRate : 0,
        ovsRate         : "16",
        wordLength      : "8_BITS",
        parity          : "NONE",
        stopBits        : "ONE",
        flowControl     : "RTS_CTS",
        enableFIFO      : true,
        rxFifoThreshold : "DL_UART_RX_FIFO_LEVEL_3_4_FULL",
        rxTimeoutValue  : 15,
        enableInternalLoopback : false,
        enableMajorityVoting : false,
        enableMSBFirst : false,
        enableManchester : false,
        enableIrda      : false,
        setIrdaTxPulseClock : "DL_UART_IRDA_CLOCK_BAUD_RATE",
        setIrdaTxPolarity : "DL_UART_IRDA_POLARITY_LOW",
        setIrdaPulseLength : 0,
        enabledInterrupts : [],
        interruptPriority: "DEFAULT",
    };
    if(!Common.isDeviceM0C()){
        configProfile3 = {...configProfile3, ...defaultDMAConfig};
    };

const profilesUART = [
    configProfile1,
    configProfile2,
    configProfile3,
];

/************************Interrupt Functions **********************************/
function getIntOptions(inst)
{
    let allOptions = [
        {name: "DMA_DONE_TX", displayName: "DMA done on transit"},
        {name: "DMA_DONE_RX", displayName: "DMA done on receive"},
        {name: "CTS_DONE", displayName: "CTS"},
        {name: "ADDRESS_MATCH", displayName: "9-bit mode address match"},
        {name: "EOT_DONE", displayName: "End of transmission"},
        {name: "TX", displayName: "Transmit"},
        {name: "RX", displayName: "Receive"},
        {name: "RXD_POS_EDGE", displayName: "Positive edge on RX"},
        {name: "RXD_NEG_EDGE", displayName: "Negative edge on RX"},
        {name: "OVERRUN_ERROR", displayName: "Overrun error"},
        {name: "BREAK_ERROR", displayName: "Break error"},
        {name: "PARITY_ERROR", displayName: "Parity error"},
        {name: "FRAMING_ERROR", displayName: "Framing error"},
        {name: "NOISE_ERROR", displayName: "Noise error"},
        {name: "RX_TIMEOUT_ERROR", displayName: "RX timeout"},
    ];

    return allOptions;
}

function getDisabledIntOptions(inst)
{
    let allOptions = [
        {name: "ADDRESS_MATCH", displayName: "9-bit mode address match", reason: "Extend mode is disabled"},
    ];

    if (inst.enableExtend == true)
    {
        return [];
    }
    else
    {
        return allOptions;
    }
}

function onChangeSetCustomProfile(inst,ui){
    inst.profile = "CUSTOM";
}


/************************* Interrupt onChange functions *******************************/
/* onChange functions for Interrupt Configuration */

function onChangeInt(inst, ui)
{
    ui.interruptPriority.hidden = (inst.enabledInterrupts.length === 0);
    onChangeSetCustomProfile(inst, ui);
}


/************************* Profiles functions *******************************/
/*
 *  ======== onChangeUARTProfile ========
 *  Called when UART Profile is changed.
 *  Pre-configures UART according to profiles
 *
 */
function onChangeUARTProfile(inst, ui) {
    if (inst.profile != "CUSTOM")
    {
        let selectedProfileArray = profilesUART.filter(obj =>
                                        {return obj.name === inst.profile});
        if (selectedProfileArray.length != 0)
        {
            const selectedProfile = Object.assign({}, selectedProfileArray[0]);
            //selectedProfile = selectedProfile[0];
            delete selectedProfile.name;
            Object.assign(inst, selectedProfile)
        }
        UARTCommon.updateGUIbasedonConfig(inst, ui);
    }
}

let config = [
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
                displayName : "UART Profiles",
                description : 'Pre-defined profiles for typical UART configurations',
                longDescription: `
The universal asynchronous receiver-transmitter (UART) module provides an
interface for serial communication protocols.

![UART Block Diagram](../docs/english/sysconfig/images/uartBlockDiagM0G3xx.png "UART Block Diagram")

The Quick Profile Options are:
* **115200 baud Internal Loopback Mode using BUSCLK**:
    * Normal UART mode
    * 115200 baud
    * 8N1
    * Uses BUSCLK/1 (can be used in SLEEP mode).
    * Internal loopback mode enabled
    * RX FIFO level at >=1 entry.
    * TX FIFO level at <= 2 entries.
    * No interrupts enabled by default.
* **9600 baud using LFCLK**:
    * Normal UART mode
    * 9600 baud
    * 8N1
    * Uses LFCLK/1 (can be used in SLEEP/STOP/STANDBY modes).
    * RX FIFO level at >=1 entry.
    * TX FIFO level at <= 2 entries.
    * No interrupts enabled by default.
* **1 Mbaud using BUSCLK with HW Flow Control**:
    * Normal UART mode
    * 1 Mbaud
    * 8N1
    * Uses BUSCLK/1 (can be used in SLEEP mode).
    * Enabled HW Flow Control
    * RX FIFO level at >=3 entries.
    * TX FIFO level at <= 2 entries.
    * RX timeout set to ~468ns
    * No interrupts enabled by default.
* **Custom**:
    * Allows custom configuration.`,
                hidden      : false,
                default     : "CUSTOM",
                options     : [
                    {name: "CONFIG_PROFILE_1", displayName: "115200 baud Internal Loopback Mode using BUSCLK"},
                    {name: "CONFIG_PROFILE_2", displayName: "9600 baud using LFCLK"},
                    {name: "CONFIG_PROFILE_3", displayName: "1 Mbaud using BUSCLK with HW Flow Control"},
                    {name: "CUSTOM", displayName: "Custom"},
                ],
                onChange    : onChangeUARTProfile,
            },
        ],
    },
]

config = config.concat([
    {
        name: "GROUP_BASIC",
        displayName: "Basic Configuration",
        description: "",
        longDescription:
`Basic UART options allow configuration of the most common options to enable
basic communication and configure the serial interface.
`,
        collapsed: false,
        config: UARTCommon.getBasicConfig(),

    }
])

config = config.concat([
    {
        name: "GROUP_ADVANCED",
        displayName: "Advanced Configuration",
        description: "",
        longDescription: "",
        collapsed: true,
        config: UARTCommon.getAdvancedConfigUART(),
    },
    {
        name: "GROUP_EXTEND",
        displayName: "Extend Configuration",
        description: "",
        longDescription:
`This section allows configuration of the UART Extend specific features.
A UART Extend instance must be selected to use these features.
The table below shows the main differences between UART Main and UART Extend.

![UART Main vs Extend Table](../docs/english/sysconfig/images/uartExtendFeaturesTableM0G3xx.png "UART Main vs Extend Table")
`,
        collapsed: true,
        config: UARTCommon.getExtendConfig(),
    },
    {
        name: "GROUP_INTERRUPTS",
        displayName: "Interrupt Configuration",
        longDescription: "This section allows enabling/disabling UART interrupts",
        collapsed: true,
        config:[
            {
                name        : "enabledInterrupts",
                displayName : "Enable Interrupts",
                description : 'Enable UART interrupt',
                default     : [],
                options     : getIntOptions,
                getDisabledOptions: getDisabledIntOptions,
                onChange    : onChangeInt
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
        ],
    },
    {
        name: "GROUP_DMA",
        displayName: "DMA Configuration",
        longDescription: `
This section allows configuring DMA Event triggers.\n
The UART module can set trigger conditions for the DMA through receive or
transmit events. \n
When the DMA functionality is enabled, the UART asserts a DMA request
when the configured receive or transmit trigger condition occurs. \n
`,
        collapsed: true,
        config: UARTCommon.getDMAConfig(),
    },
])

/* Add Pinmux Peripheral Configuration group */
config = config.concat(Common.getGPIOGroupConfig());


function moduleInstances(inst){
    let modInstances = []
    /*
    * Gets a DMA module if available
    */
    UARTCommon.getDMAModInstances(inst,modInstances);

    /*
     * Gets a Peripheral GPIO Configuration submodule
     */
    /* CONDITIONS CODE START */
    let txConfig, rxConfig, rtsConfig, ctsConfig = false;

    switch (inst.direction)
    {
        case 'TX':
            txConfig = true;
        break;
        case 'RX':
            rxConfig = true;
        break;
        case 'TX_RX':
            txConfig = true;
            rxConfig = true;
        break;
    }

    switch (inst.flowControl)
    {
        case 'RTS':
            rtsConfig = true;
        break;
        case 'CTS':
            ctsConfig = true;
        break;
        case 'RTS_CTS':
            rtsConfig = true;
            ctsConfig = true;
        break;
    }
    /* CONDITIONS CODE END */

    /* TX */
    Common.pushGPIOConfigInst(inst, modInstances,   txConfig,    "txPin",
     "TX", "TX Pin",
     "OUTPUT");
    /* RX */
    Common.pushGPIOConfigInst(inst, modInstances,   rxConfig,    "rxPin",
     "RX", "RX Pin",
     "INPUT");
    /* RTS */
    Common.pushGPIOConfigInst(inst, modInstances,   rtsConfig,    "rtsPin",
     "RTS", "RTS Pin",
     "OUTPUT");
    /* CTS */
    Common.pushGPIOConfigInst(inst, modInstances,   ctsConfig,    "ctsPin",
     "CTS", "CTS Pin",
     "INPUT");


    return modInstances;

}

/*
 *  ======== devSpecific ========
 *  Device-specific extensions to be added to base module configuration
 */
let devSpecific = {

    config: config,


    maxInstances: Common.peripheralCount("UART"),

    /* override generic requirements with  device-specific reqs (if any) */
    validate: validate,

    validatePinmux: validatePinmux,

    pinmuxRequirements: pinmuxRequirements,

    filterHardware: filterHardware,

    moduleInstances: moduleInstances,

    /* override device-specific templates */
    templates: {
        boardc: "/ti/driverlib/uart/UART.Board.c.xdt",
        boardh: "/ti/driverlib/uart/UART.Board.h.xdt",
        Call: true,
        Reset: true,
        Power: true,
        GPIO: true,
        Function: true,
        Retention: Common.isDeviceM0G(),

    },
    modules: setRequiredModules,


    _getPinResources: _getPinResources
};

function setRequiredModules(inst){
    return UARTCommon.setRequiredModules(inst);
};

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

/*  ======== pinmuxRequirements ========
 *  Returns peripheral pin requirements of the specified instance
 *
 *  param inst    - a fully configured module instance
 *
 *  returns req[] - an array of pin requirements needed by inst
 */
function pinmuxRequirements(inst)
{
    let tx = {
        name              : "txPin",  /* config script name */
        displayName       : "TX Pin", /* GUI name */
        interfaceNames    : ["TX"]   /* pinmux tool name */
    };

    let rx = {
        name              : "rxPin",
        displayName       : "RX Pin",
        interfaceNames    : ["RX"]
    };

    let cts = {
        name              : "ctsPin",
        displayName       : "CTS Pin",
        interfaceNames    : ["CTS"]
    };

    let rts = {
        name              : "rtsPin",
        displayName       : "RTS Pin",
        interfaceNames    : ["RTS"]
    };

    let resources = [];

    switch (inst.direction)
    {
        case 'TX':
            resources.push(tx);
        break;
        case 'RX':
            resources.push(rx);
        break;
        case 'TX_RX':
            resources.push(rx);
            resources.push(tx);
        break;
    }

    switch (inst.flowControl)
    {
        case 'RTS':
            resources.push(rts);
        break;
        case 'CTS':
            resources.push(cts);
        break;
        case 'RTS_CTS':
            resources.push(rts);
            resources.push(cts);
        break;
    }


    let uart = {
        name          : "peripheral",
        displayName   : "UART Peripheral",
        interfaceName : "UART",
        resources     : resources,
        signalTypes   : {
            txPin     : ['UART_TX'],
            rxPin     : ['UART_RX'],
            ctsPin     : ['UART_CTS'],
            rtsPin     : ['UART_RTS']
        }
    };
    return [uart];
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
        if (Common.typeMatches(type, ["UART"])) modulePin = sig;
    }
    let result = modulePin ? true : false;

    return (result);
}

/*
 *  ======== extend ========
 *  Extends a base exports object to include any device specifics
 *
 *  This function is invoked by the generic module module to
 *  allow us to augment/override as needed for the MSP432.
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
    /* required function, called by base module module */
    extend: extend
};
