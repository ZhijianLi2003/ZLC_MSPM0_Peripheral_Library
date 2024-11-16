/*
 * Copyright (c) 2019 Texas Instruments Incorporated - http://www.ti.com
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
 *  ======== Board.syscfg.js ========
 */

/* Module used to invoke Board.c and Board.h templates */

"use strict";

/* get ti/drivers common utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

let MasterOrder = [];

if(["MSPM0G350X"].includes(Common.getDeviceName())){
    MasterOrder = [
        "SYSCTL", "PWM", "QEI", "CAPTURE", "COMPARE", "TIMER", "I2C", "i2cSMBUS", "UART", "uartLIN",
        "SPI", "ADC12", "COMP", "VREF", "OPA", "GPAMP", "EVENT", "DMA",
        "GPIO", "AES", "CRC", "RTC", "TRNG", "SYSTICK", "DAC12", "WWDT", "MATHACL", "MCAN"
    ];
}else if(["MSPM0G150X"].includes(Common.getDeviceName())){
    MasterOrder = [
        "SYSCTL", "PWM", "QEI", "CAPTURE", "COMPARE",  "TIMER", "I2C", "i2cSMBUS", "UART", "uartLIN",
        "SPI", "ADC12", "COMP", "VREF", "OPA", "GPAMP", "EVENT", "DMA",
        "GPIO", "AES", "CRC", "RTC", "TRNG", "SYSTICK", "DAC12", "WWDT", "MATHACL"
    ];
}
else if(["MSPM0G310X"].includes(Common.getDeviceName())){
    MasterOrder = [
        "SYSCTL", "PWM", "QEI", "CAPTURE", "COMPARE",  "TIMER", "I2C", "i2cSMBUS", "UART", "uartLIN",
        "SPI", "ADC12", "VREF", "GPAMP", "EVENT", "DMA",
        "GPIO", "AES", "CRC", "RTC", "TRNG", "SYSTICK", "WWDT", "MATHACL", "MCAN"
    ];
}
else if(["MSPM0G110X"].includes(Common.getDeviceName())){
    MasterOrder = [
        "SYSCTL", "PWM", "QEI", "CAPTURE", "COMPARE",  "TIMER", "I2C", "i2cSMBUS", "UART", "uartLIN",
        "SPI", "ADC12", "VREF", "GPAMP", "EVENT", "DMA",
        "GPIO", "CRC", "RTC", "SYSTICK", "WWDT", "MATHACL"
    ];
}
/* MSPM0L Series-Specific Option */
/* For MSPM0L134X and MSPM0L130X */
else if(Common.isDeviceFamily_PARENT_MSPM0L11XX_L13XX() && !Common.isDeviceM0x110x()){
    MasterOrder = [
        "SYSCTL", "PWM", "CAPTURE", "COMPARE",  "TIMER", "I2C", "i2cSMBUS", "UART", "uartLIN",
        "SPI", "ADC12", "COMP", "VREF", "OPA", "GPAMP", "EVENT", "DMA",
        "GPIO", "CRC", "SYSTICK", "WWDT"
    ];
}
/* For MSPM0L110X */
else if(Common.isDeviceFamily_PARENT_MSPM0L11XX_L13XX() && Common.isDeviceM0x110x()){
    MasterOrder = [
        "SYSCTL", "PWM", "CAPTURE", "COMPARE",  "TIMER", "I2C", "i2cSMBUS", "UART", "uartLIN",
        "SPI", "ADC12", "VREF", "GPAMP", "EVENT", "DMA",
        "GPIO", "CRC", "SYSTICK", "WWDT"
    ];
}
/* MSPM0L122X specific options */
else if(Common.isDeviceFamily_PARENT_MSPM0L122X()){
    MasterOrder = [
        "SYSCTL", "RTCA", "PWM", "CAPTURE", "COMPARE",  "TIMER", "TAMPERIO", "IWDT", "I2C", "i2cSMBUS", "UART", "uartLIN",
        "SPI", "ADC12", "COMP", "VREF", "EVENT", "DMA",
        "GPIO", "AESADV", "CRCP", "SYSTICK", "WWDT",
    ];
}
/* MSPM0L222X specific options */
else if(Common.isDeviceFamily_PARENT_MSPM0L222X()){
    MasterOrder = [
        "SYSCTL", "RTCA", "PWM", "CAPTURE", "COMPARE",  "TIMER", "TAMPERIO", "IWDT", "I2C", "i2cSMBUS", "UART", "uartLIN",
        "SPI", "ADC12", "COMP", "VREF", "EVENT", "DMA",
        "GPIO", "AESADV", "CRCP", "SYSTICK", "WWDT", "LCD",
    ];
}
/* MSPM0C110X specific options */
else if(Common.isDeviceFamily_PARENT_MSPM0C110X()){
    MasterOrder = [
        "SYSCTL", "BEEPER", "PWM", "QEI", "CAPTURE", "COMPARE",  "TIMER", "I2C",
        "i2cSMBUS", "UART", "uartLIN", "SPI", "ADC12", "VREF", "EVENT", "DMA",
        "GPIO", "CRC", "WWDT",
    ];
}
/* MSPM0GX51X specific options */
else if(["MSPM0G351X"].includes(Common.getDeviceName())){
    MasterOrder = [
        "SYSCTL", "PWM", "QEI", "CAPTURE", "COMPARE", "TIMER", "I2C", "i2cSMBUS", "UART", "uartLIN",
        "SPI", "ADC12", "COMP", "VREF", "GPAMP", "EVENT", "DMA",
        "GPIO", "AESADV", "CRCP", "RTC", "TRNG", "SYSTICK", "DAC12", "WWDT", "MATHACL", "MCAN"
    ];
}
else if(["MSPM0G151X"].includes(Common.getDeviceName())){
    MasterOrder = [
        "SYSCTL", "PWM", "QEI", "CAPTURE", "COMPARE", "TIMER", "I2C", "i2cSMBUS", "UART", "uartLIN",
        "SPI", "ADC12", "COMP", "VREF", "GPAMP", "EVENT", "DMA",
        "GPIO", "AESADV", "CRCP", "RTC", "TRNG", "SYSTICK", "DAC12", "WWDT", "MATHACL"
    ];
}


/* master sorted template list of modules */

let MasterList = [];
let MasterIndex = {};
for(let modIdx in MasterOrder){
    let mod = MasterOrder[modIdx];
    let nameStr = "/ti/driverlib/" + mod;
    MasterList.push({name: nameStr, displayName: mod});
    MasterIndex[mod] = modIdx;
}

/*
 *  ======== _getPinResources ========
 */
function _getPinResources(inst)
{
    let pin;

    if (inst.debug && inst.debug.debugOn) {
        let swclkPin = "DIO" + inst.debug.swclkPin.$solution.devicePinName;
        swclkPin = swclkPin.match(/P\d+\.\d+/)[0];
        let swdioPin = "DIO" + inst.debug.swdioPin.$solution.devicePinName;
        swdioPin = swdioPin.match(/P\d+\.\d+/)[0];
        pin = "\nSWCLK: " + swclkPin + "\nSWDIO: " + swdioPin;

        if (inst.$hardware && inst.$hardware.displayName) {
            pin += "\n" + inst.$hardware.displayName;
        }
    }

    return (pin);


}

/*  ======== pinmuxRequirements ========
 *  Returns peripheral pin requirements of the specified instance
 *
 *  param inst    - a fully configured Board instance
 *
 *  returns req[] - an array of pin requirements needed by inst
 */
function pinmuxRequirements(inst)
{
    let debug = {
        name: "peripheral",
        displayName: "Debug Peripheral",
        interfaceName: "DEBUGSS",
        resources: [],
        signalTypes: {
            swclkPin: ["SWCLK"],
            swdioPin: ["SWDIO"]
        }
    };
    if(inst.debugOn){
        debug.resources.push(
            {
                name: "swclkPin",
                displayName: "Debug Clock",
                interfaceNames: ["SWCLK"]
            },
            {
                name: "swdioPin",
                displayName: "Debug Data In Out",
                interfaceNames: ["SWDIO"]
            }
        )
    }
    return ([debug]);
}

/*
 *  ========= filterHardware ========
 *  Check 'component' signals for compatibility with Board
 *
 *  param component - hardware object describing signals and
 *                    resources they're attached to
 *  returns Boolean indicating whether or not to allow the component to
 *           be assigned to an instance's $hardware config
 */
function filterHardware(component)
{
    let swclk, swdio;

    for (let sig in component.signals) {
        let type = component.signals[sig].type;
        if (Common.typeMatches(type, ["SWCLK"])) swclk = sig;
        if (Common.typeMatches(type, ["SWDIO"])) swdio = sig;
    }
    let result = (swclk && swdio) ? true : false;

    return (result);
}

function validate(inst, validation)
{

    /* validate all init priorities */
    let validOptions = MasterList;
    let selectedOptions = [];
    for(let i = 0; i < MasterList.length; i++){
        let priorityConfigName = "InitPriority"+i;
        let selectedOption = inst[priorityConfigName];
        let duplicate = _.find(selectedOptions, (o) => o.name === selectedOption);
        if(duplicate){
            validation.logError("Duplicate Option. Please Reselect", inst, priorityConfigName);
        } else {
            selectedOptions.push(selectedOption);
        }
        let found = _.find(validOptions, (o) => o.name === selectedOption);
        if(!found){
            validation.logError("Invalid Option. Please Reselect", inst, priorityConfigName);
        }
    }

    /* debug configuration validation */
    if(!inst.debugOn){
        validation.logWarning("Debug Disabled! Code Cannot be Debugged", inst, "debugOn");
    }
}

function optionsGetCurrentModules(inst)
{
    let optionList = MasterList;

    for(let moduleName in system.modules){
        if(!moduleName.match(/clockTree|TIMERFault/)){ // exclude Clock Tree modules form board list
            let mod = system.modules[moduleName];
            if(mod.templates && mod.templates.boardc) {
                /* search in master list */
                let endName = moduleName.split('/');
                let displayName = endName[endName.length-1];
                let index = MasterIndex[displayName];
                if(index === undefined){
                    throw 'module not found in Master List in Board.syscfg.js';
                }
                optionList[index].displayName = displayName + " - active";
            }
        }
    }
    return optionList;
}

function onChangeSwapTwo(inst, index)
{
    /* first check that the entered value is valid */
    let validOptions = MasterList;
    let changed = inst["InitPriority"+index];
    let found = _.find(validOptions, (o) => o.name === changed);
    if(!found){
        return;
        /* just exit and let validation fix it */
    }

    let used = {};
    for(let mod of MasterOrder){
        used[mod] = false;
    }

    let duplicate = -1;
    for(let i = 0; i < MasterList.length; i++){
        if(inst["InitPriority"+i] === changed && i !== index){
            duplicate = i;
        }
        let endName = inst["InitPriority"+i].split('/');
        let displayName = endName[endName.length-1];
        used[displayName] = true;
    }
    if(duplicate === -1){
        /* couldn't find the new one, module underrepresented */
        return;
    }
    /* find the missing module */
    for(let u in used){
        let count = 0;
        if(used[u] == false){
            inst["InitPriority"+duplicate] = MasterList[MasterIndex[u]].name;
            count ++;
            if(count > 1){
                /* too many */
                return;
            }
        }
    }
}

let priorityConfig = [];
for(let i = 0; i < MasterList.length; i ++){
    priorityConfig.push({
        name: "InitPriority"+i,
        displayName: "Initialization Priority "+i,
        default: MasterList[i].name,
        options: optionsGetCurrentModules,
        onChange: (inst, ui) => {
            onChangeSwapTwo(inst,i);
        }
    })
}

let config = [
    {
        name: "GROUP_DEBUG",
        displayName: "Debug Configuration",
        description: "",
        longDescription: "",
	    collapsed: false,
        config: [
            {
                name: "debugOn",
                displayName: "Debug Enable On SWD Pins",
                description: "Enables or disables the debug function on SWD pins",
                longDescription: `
After a cold start, the SWD pins (SWDIO and SWCLK) are always configured in SWD mode allowing a debug connection to be established regardless of the value of this setting.
Enabling this feature (default) will retain the SWD functionality for these pins.
Disabling this feature will allow the SWD pins to be used as GPIOs, thus disabling debug capability.
Then we add the warning.

**WARNING:** Once software disables SWD functionality, it is not possible to re-
enable it other than by triggering a POR. A POR will automatically re-enable
the SWD functionality and put the SWD pins into SWD mode with pullup/pulldown
resistors enabled. To re-gain debug access to a device which contains software
that disables the SWD pins at startup, it is necessary to hold the device in a
reset state with the NRST pin during a POR. This will prevent the application
software from starting and will allow the debug probe to gain access to the
device, at which point a mass erase command may be sent to remove the
application software which is disabling the SWD pins.
                `,
                default: true
            }
        ],
    },
    {
        name: "GROUP_GLOBAL_GPIO",
        displayName: "Global Pin Configuration",
        description: "",
        longDescription:
`Configure GPIO Pin settings that apply to all pins. \n
Any conflicting configurations will be overriden by these settings.`,
	    collapsed: false,
        config: [
            {
                name: "globalFastWakeEn",
                displayName: "Enable Global Fast-Wake",
                description: "Enable Global Fast Wake for GPIO",
                longDescription: ``,
                default: false,
            },
            {
                name: "configureUnused",
                displayName: "Configure Unused Pins",
                description: "Configure all unused GPIO pins",
                longDescription: ``,
                default: false,
                onChange: (inst,ui) => {
                    ui.unusedDirection.hidden = !inst.configureUnused;
                    ui.unusedInternalResistor.hidden = (!inst.configureUnused || (inst.unusedDirection=="OUTPUT"));
                    ui.unusedOutputDrive.hidden = (!inst.configureUnused || inst.unusedDirection !== "OUTPUT");
                }
            },
            {
                name: "GROUP_UNUSED_PINS",
                displayName: "Unused Pin Configuration",
                description: "",
                longDescription: "The selected configurations will apply to all unused GPIO pins in the device.",
                collapsed: false,
                config: [
                    {
                        name: "unusedDirection",
                        displayName: "Direction",
                        description: "Configure Pins as Input or Output",
                        longDescription: ``,
                        default: "OUTPUT",
                        hidden: true,
                        options: [
                            {name: "OUTPUT", displayName: "Output"},
                            {name: "INPUT", displayName: "Input"},
                        ],
                        onChange: (inst,ui) => {
                            ui.unusedInternalResistor.hidden = (inst.unusedDirection=="OUTPUT");
                            ui.unusedOutputDrive.hidden = !(inst.unusedDirection=="OUTPUT");
                        },
                    },
                    {
                        name: "unusedOutputDrive",
                        displayName: "Configure Output",
                        description: "Set output to High or Low",
                        longDescription: ``,
                        default: "LOW",
                        hidden: true,
                        options: [
                            {name: "HIGH", displayName: "High"},
                            {name: "LOW", displayName: "Low"},
                        ],
                    },
                    {
                        name: "unusedInternalResistor",
                        displayName: "Internal Resistor",
                        description: "Optional Resistor to add to GPIO",
                        longDescription: ``,
                        default: "NONE",
                        hidden: true,
                        options: [
                            {name: "NONE", displayName: "No Resistor"},
                            {name: "PULL_UP", displayName: "Pull-Up Resistor"},
                            {name: "PULL_DOWN", displayName: "Pull-Down Resistor"},
                        ]
                    }
                ],
            },
            {
                name: "genPeriphPinFile",
                displayName: "Generate Peripherals & Pin Assignments File",
                description: "Generate output file with Peripherals & Pin Assignments",
                longDescription: ``,
                default: false,
            },
        ],
    },
    {
        name: "GROUP_VOLTAGE_CONFIG",
        displayName: "Voltage Configuration",
        description: "",
        longDescription:
`Voltage configuration settings that apply to all pins. \n
Any conflicting configurations will be overriden by these settings.`,
	    collapsed: false,
        config: [
            {
                name: "configureVDDA",
                displayName: "Configure ADC VDDA",
                description: "Configure VDDA",
                longDescription: ``,
                default: false,
                onChange: (inst,ui) => {
                    ui.voltageVDDA.hidden = !inst.configureVDDA;
                }
            },
            {
                name: "GROUP_VDDA_CONFIG",
                displayName: "VDDA Configuration",
                description: "",
                longDescription: "The selected configurations will apply to all applicable voltage configuration.",
                collapsed: false,
                config: [
                    {
                        name: "voltageVDDA",
                        displayName: "ADC VDDA (V)",
                        description: "Configure VDDA",
                        default: 3.3,
                        hidden: true,
                        range: [1.62, 3.6],
                    },
                ],
            },
        ],
    },
    {
        name: "GROUP_INIT",
        displayName: "Initialization Priority Configuration",
        description: "",
        longDescription: "",
	    collapsed: false,
        config: priorityConfig,
    },
]

function moduleInstances(inst){
    let modInstances = []
    if(inst.genPeriphPinFile){
        let mod = {
            name: "genFileMod",
            displayName: "Peripheral Pins File Generation",
            moduleName: '/ti/driverlib/BoardPins',
            group: "GROUP_GLOBAL_GPIO",
            args: {

            },
            requiredArgs: {

            },

        }
        modInstances.push(mod);
    }
    return modInstances;
}

function isFileGen(inst){
    return inst.genPeriphPinFile;
}


/*
 *  ======== base ========
 */
let base = {
    displayName  : "Board",
    description: "Generic Board Configuration",
    longDescription: `This is a generic board file which contains general functions
        regarding the entire system, as well as the initialization order. The
        initialization order can be specified by changed the priorities below. The
        default list is initially displayed, but modules can be swapped by selecting
        the desired module at that priority. The displaced module will then take
        the previous priority of the desired module, such that there are no duplicates.
        Only active modules will actually be included, so non-active modules are skipped.\n If
        PWM and SysConfig are the only active module, PWM priority 5 and SysConfig priority 8
        has the same function as PWM priority 0 and SysConfig 1`,

    moduleStatic: {
        config: config,
        validate: validate,
        /* override generic requirements with  device-specific reqs (if any) */
        pinmuxRequirements: pinmuxRequirements,
        filterHardware: filterHardware,
        moduleInstances : moduleInstances,
    },

    templates    : {
        /* trigger generation of ti_msp_dl_config.[ch] */
        "/ti/driverlib/templates/Board.c.xdt" : true,
        "/ti/driverlib/templates/Board.h.xdt" : true,
    }

};



/*
 *  ======== exports ========
 */
exports = base;
