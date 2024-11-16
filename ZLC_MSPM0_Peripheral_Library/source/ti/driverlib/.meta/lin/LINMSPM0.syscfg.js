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
 *  ======== LINMSPM0.js ========
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

    if (inst.enableLinFallingEdgeCapture && inst.enableLinCounterCompare) {
        validation.logError("Counter Compare Match Mode and LIN Capture on RXD Falling Edge cannot be enabled at the same time. One of these options must be disabled", inst, ["enableLinFallingEdgeCapture", "enableLinCounterCompare"]);
    }
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
        if(!(/UART0/.test(solution))){
            validation.logError("LIN functionality is only available on the UART0 instance. Please select a UART0 instance from PinMux if available.",
                inst,"peripheral");
        }
    }
    else if(Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()){
        if(!(/UART0|UART1/.test(solution))){
            validation.logError("LIN functionality is only available on the UART0 and UART1 instances. Please select a valid instance from PinMux if available.",
                inst,"peripheral");
        }
    }
    else if(Common.isDeviceFamily_PARENT_MSPM0GX51X()){
        if(!(/UART0|UART7/.test(solution))){
            validation.logError("LIN functionality is only available on the UART0 and UART7 instances. Please select a valid instance from PinMux if available.",
                inst,"peripheral");
        }
    }
}

function onLinCounterCompareEnabled(inst, ui){
    if(inst.enableLinCounterCompare){
        ui["setLinCounterCompare"].hidden = false
        ui["tbitVal"].hidden = false
        ui["tbitWidth"].hidden = false
    }
    else{
        ui["setLinCounterCompare"].hidden = true
        ui["tbitVal"].hidden = true
        ui["tbitWidth"].hidden = true
    }
}

function updateFifoThresholds(inst, ui) {
    if (inst.enableFIFO == true) {
        ui.rxFifoThreshold.hidden = false;
        ui.txFifoThreshold.hidden = false;
    } else {
        ui.rxFifoThreshold.hidden = true;
        ui.txFifoThreshold.hidden = true;
    }
}


/* PROFILES CONFIGURATION */
    let defaultDMAConfig = {
        enabledDMARXTriggers : "None",
        enabledDMATXTriggers : "None",
        enableDMARX : false,
        enableDMATX : false,
    }
    let configProfile1 = {
        name            : "CONFIG_PROFILE_1", /* LIN_BREAK_DETECTION_CONFIG */
        uartClkSrc      : "BUSCLK",
        targetBaudRate  : 19200,
        calculatedBaudRate : 0,
        ovsRate         : "16",
        wordLength      : "8_BITS",
        parity          : "NONE",
        stopBits        : "ONE",
        flowControl     : "NONE",
        enableFIFO      : false,
        rxTimeoutValue  : 0,
        enableInternalLoopback : false,
        enableMajorityVoting : false,
        enableMSBFirst : false,
        enableLinCounter : true,
        enableLinCounterClearFallingEdge : true,
        enableLinCountWhileLow : true,
        enableLinFallingEdgeCapture : false,
        enableLinRisingEdgeCapture : false,
        enableLinCounterCompare : true,
        tbitVal : 9.5,
        enabledInterrupts : ["BREAK_ERROR","LINC0_MATCH","LIN_COUNTER_OVERFLOW","LIN_FALLING_EDGE","RXD_POS_EDGE"],
        interruptPriority : "DEFAULT",
    };
    if(!Common.isDeviceM0C()){
        configProfile1 = {...configProfile1, ...defaultDMAConfig};
    };
const profilesUART = [
    configProfile1,
];

/************************Interrupt Functions **********************************/
const IntOptions = [
    {name: "DMA_DONE_TX", displayName: "DMA done on transmit"},
    {name: "DMA_DONE_RX", displayName: "DMA done on receive"},
    {name: "CTS_DONE", displayName: "CTS"},
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
    { name: "LIN_COUNTER_OVERFLOW", displayName: "LIN counter overflow"},
    { name: "LIN_RISING_EDGE", displayName: "LIN rising edge"},
    { name: "LIN_FALLING_EDGE", displayName: "LIN falling edge"},
    { name: "LINC0_MATCH", displayName: "LINC0 match"},
];


function onChangeSetCustomProfile(inst,ui){
    inst.profile = "CUSTOM";
}

/************************* Interrupt onChange functions *******************************/
/* onChange functions for Interrupt Configuration */

function onChangeCounterCompare(inst, ui)
{
    onLinCounterCompareEnabled(inst, ui);
    onChangeSetCustomProfile(inst, ui);
}

/*
 *  ======== getUARTClockSourceFreq ========
 *  Get the UART Clock source frequency in Hz
 *
 */
function getUARTClockSourceFreq(inst) {
    let uartClockFreq = 0;
    /* UART has 3 sources:
        BUSCLK = MCLK in PD1, ULPCLK in PD0
        MFCLK
        LFCLK
    */
   switch (inst.uartClkSrc){
       case "BUSCLK":
            uartClockFreq = Common.getBUSCLKFreq(inst, "UART");
        break;
        case "MFCLK":
            uartClockFreq = system.modules["/ti/driverlib/SYSCTL"].$static.MFCLK_Freq;
        break;
        case "LFCLK":
            uartClockFreq = system.modules["/ti/driverlib/SYSCTL"].$static.LFCLK_Freq;
        break;
   }
   uartClockFreq = uartClockFreq / inst.uartClkDiv;

   return uartClockFreq;
}

function getTbit(inst) {
    return (getUARTClockSourceFreq(inst) / inst.targetBaudRate);
}

function getCounterCompareValue(inst) {

    let ccVal = getTbit(inst) * inst.tbitVal;

    return Math.round(ccVal);
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

        updateFifoThresholds(inst, ui);
        onLinCounterCompareEnabled(inst,ui);
        ui.interruptPriority.hidden = (inst.enabledInterrupts.length === 0);
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
                displayName : "LIN Profiles",
                description : 'Pre-defined profiles for typical UART configurations',
                longDescription: `
The universal asynchronous receiver-transmitter (UART) module provides an
interface for serial communication protocols.

![UART Block Diagram](../docs/english/sysconfig/images/uartBlockDiagM0G3xx.png "UART Block Diagram")

The Quick Profile Options are:
* **LIN at 19200 baud with Break Detection**:
    * Normal UART mode
    * 19200 baud
    * 8N1
    * Uses BUSCLK/1 (can be used in SLEEP mode)
    * UART0 instance (with Extend capability) selected
    * LIN Counter enabled
    * LIN Counter Compare Match mode enabled
    * LIN Counter Compare Value set to 9.5. This is to set a Break Field threshold of 9.5*Tbit to enable detecting the break field.
    * LIN Counter Clear on RXD Falling Edge enabled
    * LIN Count while RXD is Low enabled
    * Break error, LINC0 Match, LIN Counter Overflow, LIN Falling Edge, and RXD Positive Edge interrupts enabled
* **Custom**:
    * Allows custom configuration.`,
                hidden      : false,
                default     : "CUSTOM",
                options     : [
                    {name: "CONFIG_PROFILE_1", displayName: "LIN at 19200 baud with Break Detection"},
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
            name: "GROUP_LIN",
            displayName: "LIN Configuration",
            description: "",
            longDescription:
`
This section is only relevant for UART Extend because it supports LIN mode.
A UART instance that supports UART Extend must be selected to use LIN.
Refer to the device data sheet for the device-specific configuration of UART Extend and UART Main.\n
For supporting local interconnect network (LIN) protocol, the following hardware enhancements are implemented
in the UART module:
- 16 bit up-counter (LINCNT) clocked by the UART clock.
- Interrupt capability on counter overflow (INT_EVENT0.IMASK.LINOVF).
- 16 bit capture register (LINC0) with two configurable modes
- Capture of LINCNT value on RXD falling edge. Interrupt capability on capture.
- Compare of LINCNT with interrupt capability on match.
- 16 bit capture register (LINC1) can be configured:
- Capture LINCNT value on RXD rising edge. Interrupt capability on capture.

`,
            collapsed: false,
            config: [
                /* DL_UART_enableLinCounter */
                {
                    name        : "enableLinCounter",
                    displayName : "Enable LIN Counter",
                    description : 'The LIN counter will only count when enabled',
                    hidden      : false,
                    default     : false,
                    onChange    : onChangeSetCustomProfile,
                },
    {
        name: "GROUP_COUNTER_COMPARE",
        displayName: "Counter Compare Match Configuration",
        longDescription:
`
The LIN counter can be compared to a set value in LINC0, with interrupt capability on match.\n
Select the "LINC0_MATCH" interrupt to enable triggering an interrupt on match with the set counter compare value.\n\n

If enabled, capture on RXD falling edge is disabled.
`,
        collapsed: false,
        config: [
                    /* DL_UART_enableLINCounterCompareMatch */
                    {
                        name        : "enableLinCounterCompare",
                        displayName : "Enable Counter Compare Match Mode",
                        description : 'Enable LIN Counter Compare Match Mode',
                        longDescription :
`
The UART Counter Compare can be used to detect timing between edge events. This functionality is useful for LIN break detection where a valid break can be detected when RXD is low for 9.5 consecutive bits.
`,
                        hidden      : false,
                        default     : false,
                        onChange    : onChangeCounterCompare,
                    },
                    /* DL_UART_setLINCounterCompareValue */
                    {
                        name        : "tbitWidth",
                        displayName : "TBit Width (cycles)",
                        description : '',
                        hidden      : true,
                        longDescription :
`
Tbit is the nominal time required to transmit a bit.\n

Tbit is calculated as:\n
Tbit = (UART Clock Source Frequency) / (UART Baud Rate)\n\n

For example, with a clock source of 32MHz, a baudrate of 19200bps, Tbit width is:\n
Tbit = (32,000,0000) / (19,200) = 1,666\n
`,
                        default     : 0,
                        getValue    : (inst) => Math.floor(getTbit(inst)),
                    },
                    {
                        name        : "tbitVal",
                        displayName : "Counter Compare Timing (Tbits)",
                        description : '',
                        longDescription :
    `
The UART Counter Compare can be used to detect timing between edge events. This functionality is useful for LIN break detection where a valid break can be detected when RXD is low for 9.5 consecutive bits.\n\n

The input should be given in the number of Tbits, where Tbit is the nominal time required to transmit a bit.\n
For example, to set the counter compare value to "9.5 * Tbit", the user should enter a value of "9.5".
    `,
                        hidden      : true,
                        default     : 0,
                        onChange    : onChangeSetCustomProfile,
                    },
                    /* DL_UART_setLINCounterCompareValue */
                    {
                        name        : "setLinCounterCompare",
                        displayName : "Counter Compare Value (cycles)",
                        description : 'Set the value to be compared to the LIN counter',
                        longDescription :
`
Sets the counter compare value of LINC0 to be used to compare to the LIN counter.\n
The counter compare value is calculated as:\n
CounterCompareValue = (Tbit * CounterCompareTiming)\n\n

Tbit is calculated as:\n
Tbit = (UART Clock Source Frequency) / (UART Baud Rate)\n\n

For example, with a clock source of 32MHz, a baudrate of 19200bps, and a counter compare timing of 9.5Tbits, the result is:\n
Tbit = (32,000,0000) / (19,200) = 1,666\n
CounterCompareValue = (1,666 x 9.5) = 15,833\n
`,
                        hidden      : true,
                        default     : 0,
                        getValue    : (inst) => getCounterCompareValue(inst),
                    },
                ]
            },
                /* DL_UART_enableLINFallingEdgeCapture */
                {
                    name        : "enableLinFallingEdgeCapture",
                    displayName : "Capture On RXD Falling Edge",
                    description : 'When enabled, the LIN counter value is captured to the LINC0 register on each falling RXD edge',
                    longDescription :
`
Interrupt capability can be enabled.
Select the "LIN_FALLING_EDGE" interrupt to enable triggering an interrupt when the LINC0 counter captures a value to the LINC0 register on each RXD falling edge.\n\n

If enabled, counter compare match mode is disabled.
`,
                    hidden      : false,
                    default     : false,
                    onChange    : onChangeSetCustomProfile,
                },
                /* DL_UART_enableLINCounterClearOnFallingEdge */
                {
                    name        : "enableLinCounterClearFallingEdge",
                    displayName : "Counter Reset On RXD Falling Edge",
                    description : 'When enabled, on a falling edge of RXD the LIN counter is set to 0 and then starts counting',
                    hidden      : false,
                    default     : false,
                    onChange    : onChangeSetCustomProfile,
                },
                /* DL_UART_enableLINCountWhileLow */
                {
                    name        : "enableLinCountWhileLow",
                    displayName : "Count While RXD Is Low",
                    description : 'When the LIN counter is enabled and the signal on RXD is low, the counter increments',
                    hidden      : false,
                    default     : false,
                    onChange    : onChangeSetCustomProfile,
                },
                /* DL_UART_enableLINRisingEdgeCapture */
                {
                    name        : "enableLinRisingEdgeCapture",
                    displayName : "Capture On RXD Rising Edge",
                    description : 'When enabled the LIN counter value is captured to LINC1 register on each rising RXD edge',
                    longDescription :
`
Interrupt capability can be enabled.
Select the "LIN_RISING_EDGE" interrupt to enable triggering an interrupt when the LINC1 counter captures a value to the LINC1 register on each RXD rising edge.\n
`,
                    hidden      : false,
                    default     : false,
                    onChange    : onChangeSetCustomProfile,
                },
            ]
        },
    {
        name: "GROUP_ADVANCED",
        displayName: "Advanced Configuration",
        description: "",
        longDescription: "",
        collapsed: true,
        config: UARTCommon.getAdvancedConfigLIN(),
    },
    {
        name: "GROUP_INTERRUPTS",
        displayName: "Interrupt Configuration",
        longDescription: "This section allows enabling/disabling UART interrupts",
        collapsed: true,
        config: [
            {
                name        : "enabledInterrupts",
                displayName : "Enable Interrupts",
                description : 'Enable UART interrupt',
                default     : [],
                options     : IntOptions,
                minSelections: 0,
                onChange    : (inst, ui) => {
                    ui.interruptPriority.hidden = (inst.enabledInterrupts.length === 0);
                    onChangeSetCustomProfile(inst, ui);
                }
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
    {
        name: "GROUP_LIN",
        displayName: "LIN Configuration",
        longDescription: ``,
        collapsed: true,
        config: [],
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
