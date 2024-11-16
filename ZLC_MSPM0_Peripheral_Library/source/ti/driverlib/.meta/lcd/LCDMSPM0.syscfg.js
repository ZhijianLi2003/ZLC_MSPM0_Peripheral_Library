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
 *  ======== LCDMSPM0.syscfg.js ========
 */

"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");
const lcdPortRange = 59; // TODO: define elsewhere or access from device data
const lcdComRange = 8;

/************************* Profiles functions *******************************/


/************************* General functions **********************************/
function onChangeSetCustomProfile(inst,ui){
    // inst.profile = "CUSTOM";
}

/************************* Basic functions *******************************/
/* Profile Options vary by device depending on Polynomial availability */
let profileOptions = [
    {name: "CONFIG_PROFILE_1", displayName: "Default"},
];

let blinkConfig = [
    // DL_LCD_BLINKING_MODE_
    {
        name:"blinkMode",
        displayName:"Blinking Mode",
        default: "DISABLED",
        options: [
            { name: "DISABLED", displayName: "Disabled"},
            { name: "INDIVIDUAL_SEGMENTS", displayName: "Individual segments as enabled in LCDBMx"},
            { name: "ALL_SEGMENTS", displayName: "All blinking segments enabled"},
            { name: "TOGGLE", displayName: "Switch between display contents stored in LCDMx and LCDMBx"},
        ],
        onChange: (inst,ui)=>{
            ui.blinkFreqDiv.hidden = (inst.blinkMode == "DISABLED");
            ui.blinkFreq.hidden = (inst.blinkMode == "DISABLED");
        }
    },
    // DL_LCD_BLINKING_DIVIDE_
    {
        name:"blinkFreqDiv",
        displayName:"Blinking Frequency Divider",
        hidden: true,
        default: "2",
        options: [
            { name: "2", displayName: "2"},
            { name: "4", displayName: "4"},
            { name: "8", displayName: "8"},
            { name: "16", displayName: "16"},
            { name: "32", displayName: "32"},
            { name: "64", displayName: "64"},
            { name: "128", displayName: "128"},
            { name: "256", displayName: "256"},
        ]
    },
    {
        name: "blinkFreq",
        displayName: "Blinking Frequency",
        hidden: true,
        readOnly: true,
        default: "0Hz",
        getValue: (inst,ui) =>{
            let lcdFreq = system.modules["/ti/driverlib/SYSCTL"].$static.LFCLK_Freq/inst.freqDiv/inst.blinkFreqDiv;
            return (Common.getUnitPrefix(lcdFreq)).str+"Hz"
        }
    },

];
let modeConfig = [
    //
    // Mux rate (already chosen if Quick Profile used)
    //     Bias mode (if 5-8 mux)

    //         Low power waveforms (if 1/3 bias)
    //     Internal bias voltage resistor divider (for all mux)
    //         Higher/lower power LCD (if checked resistor divider)
    //     Bias voltage source (if checked resistor divider)
    // --------------
    // DL_LCD_Config
    {
        // DL_LCD_MUX_RATE
        name        : "muxRate",
        displayName : "Mux Rate",
        description : 'LCD mux rate',
        hidden      : false,
        default     : 1,
        options     : [
            {name: 1, displayName: "Static Mode"},
            {name: 2, displayName: "2-mux"},
            {name: 3, displayName: "3-mux"},
            {name: 4, displayName: "4-mux"},
            {name: 5, displayName: "5-mux"},
            {name: 6, displayName: "6-mux"},
            {name: 7, displayName: "7-mux"},
            {name: 8, displayName: "8-mux"},
        ],
        getValue: (inst) => {
            let muxVal = 1;
            try{
                if(inst.numberOfComInst !== undefined){
                    muxVal = inst.numberOfComInst;
                }
            } catch(e){
                // do nothing
            }
            return muxVal;
        },
    },
    // {
    //     // DL_LCD_FREQ_DIVIDE - see Freq Group
    // },
]
let biasConfig = [
    {
        // DL_LCD_BIAS (5-8 Mux only.)
        name: "biasSel",
        displayName: "Bias Select",
        default: "ONE_THIRD",
        options: [
            {name: "ONE_THIRD", displayName: "1/3 bias"},
            {name: "ONE_FOURTH", displayName: "1/4 bias"},
        ]
    },
    {
        // DL_LCD_enableInternalBias
        name: "biasEnable",
        displayName: "Internal Bias Enable",
        default: false,
        onChange: (inst,ui) =>{
            ui.biasPowerMode.hidden      = !inst.biasEnable;
            ui.biasVSource.hidden   = !inst.biasEnable;
        }
    },
    {
        name: "biasPowerMode",
        displayName: "Internal Bias Power Mode",
        hidden: true,
        default: "LOW",
        // DL_LCD_POWER_MODE
        options: [
            {name: "LOW", displayName: "Low power resistor ladder"},
            {name: "HIGH", displayName: "High power resistor ladder"},
        ]
    },
    {
        // DL_LCD_BIAS_VOLTAGE_SOURCE
        name: "biasVSource",
        displayName: "Internal Bias Voltage Source",
        hidden: true,
        default: "R33",
        options: [
            {name: "R33", displayName: "R33 Pin"},
            {name: "AVDD", displayName: "Internal Supply Voltage AVDD"},
        ]
    },
]

let vlcdConfig = [
    {
        // DL_LCD_WAVEFORM_POWERMODE
        name: "waveMode",
        displayName: "Waveform Power Mode",
        default: "STANDARD",
        options: [
            {name: "STANDARD", displayName: "Standard"},
            {name: "LOWPOWER", displayName: "Low Power"},
        ]
    },
    // Charge Pump
    {
        // DL_LCD_enableChargePump
        name: "pumpEnable",
        displayName: "Enable Charge Pump",
        default: false,
        onChange: (inst,ui) => {
            ui.pumpFreq.hidden = !(inst.pumpEnable);
        }
    },
    // Charge Pump Freq Divide
    //
    // Charge pump Clock Freq
    {
        // DL_LCD_CHARGE_PUMP_FREQUENCY
        name: "pumpFreq",
        displayName: "Charge Pump Frequency",
        default: "4096HZ",
        hidden: true,
        // DL_LCD_CHARGE_PUMP_FREQUENCY_[]
        options:[
            { name: "4096HZ", displayName: "4.096 kHz"},
            { name: "2048HZ", displayName: "2.048 kHz"},
            { name: "1365HZ", displayName: "1.365 kHz"},
            { name: "1024HZ", displayName: "1.024 kHz"},
            { name: "819HZ", displayName: "819 Hz"},
            { name: "682HZ", displayName: "682 Hz"},
            { name: "585HZ", displayName: "585 Hz"},
            { name: "512HZ", displayName: "512 Hz"},
            { name: "455HZ", displayName: "455 Hz"},
            { name: "409HZ", displayName: "409 Hz"},
            { name: "372HZ", displayName: "372 Hz"},
            { name: "341HZ", displayName: "341 Hz"},
            { name: "315HZ", displayName: "315 Hz"},
            { name: "292HZ", displayName: "292 Hz"},
            { name: "273HZ", displayName: "273 Hz"},
            { name: "256HZ", displayName: "256 Hz"},
        ]
    },
    // Bias
    {
        name: "GROUP_BIAS",
        displayName: "Bias Voltage Configuration",
        description: "",
        longDescription: "",
        collapsed: false,
        config: biasConfig,
    },
    // Voltage Source -- dependnecy on VREF module [*]
    // VREF Voltage
        // Set by VREF module?
    // VREF R33
    {
        // DL_LCD_R33_SOURCE + R13 selection
        name: "vlcdSource",
        displayName: "VLCD Source",
        default: "EXTERNAL",
        // DL_LCD_R33_SOURCE_[...] + R13 selection
        options:[
            /* This option enables R13 configuration */
            { name: "INTERNAL_VREF", displayName: "Internal VREF"},
            /* The following options enable R33 configuraiton */
            { name: "EXTERNAL", displayName: "External VREF"},
            { name: "INTERNAL", displayName: "Internal AVDD"},

        ],
        onChange: (inst,ui) => {
            ui.vrefR13.hidden       = !(inst.vlcdSource == "INTERNAL_VREF");
            ui.vrefCycles.hidden    = !(inst.vlcdSource == "INTERNAL_VREF");
        }
    },
    {
        // DL_LCD_VREF_INTERNAL
        name: "vrefR13",
        displayName: "Internal VREF",
        default: "2_60V",
        hidden: true,
        // DL_LCD_VREF_INTERNAL_[#]
        options:[
            { name: "2_60V", displayName: "2.60 V"},
            { name: "2_66V", displayName: "2.66 V"},
            { name: "2_72V", displayName: "2.72 V"},
            { name: "2_78V", displayName: "2.78 V"},
            { name: "2_84V", displayName: "2.84 V"},
            { name: "2_90V", displayName: "2.90 V"},
            { name: "2_96V", displayName: "2.96 V"},
            { name: "3_02V", displayName: "3.02 V"},
            { name: "3_08V", displayName: "3.08 V"},
            { name: "3_14V", displayName: "3.14 V"},
            { name: "3_20V", displayName: "3.20 V"},
            { name: "3_26V", displayName: "3.26 V"},
            { name: "3_32V", displayName: "3.32 V"},
            { name: "3_38V", displayName: "3.38 V"},
            { name: "3_44V", displayName: "3.44 V"},
            { name: "3_50V", displayName: "3.50 V"},
        ],
    },
    // DL_LCD_VREFGEN_CYCLES / DL_LCD_setVrefOnTimeCycles
    {
        name: "vrefCycles",
        displayName: "Number of Cycles for Voltage Generation",
        description: "The number of cycles to enable voltage generation circuitry.",
        hidden: true,
        default: "16",
        options: [
            { name: "16", displayName: "16" },
            { name: "32", displayName: "32" },
            { name: "128", displayName: "128" },
            { name: "256", displayName: "256" },
        ],
    },

    // Reference mode for R13 Voltage
    // VBOOST enable -- separate from SysCtl?
    {
        // DL_LCD_enableVBOOST / DL_LCD_disableVBOOST
        name: "vboostEnable",
        displayName: "Enable VBOOST",
        default: false,
    },
];

let IntOptions = [
    {name: "FRAME_START", displayName: "Start of a new LCD frame"},
    {name: "BLINKING_SEGMENTS_OFF", displayName: "Blinking segments are turned off"},
    {name: "BLINKING_SEGMENTS_ON ", displayName: "Blinking segments are turned on"},
];

let LCDConfig = [
    {
        name: "GROUP_BASIC",
        displayName: "Basic Configuration",
        description: "",
        longDescription: "",
        collapsed: false,
        config: [
            {
                name: "MODE_CONFIG",
                displayName: "Mode Configuration",
                description: "",
                longDescription: `
Select the LCD mode. Segmented LCDs use multiplexing (muxing) to limit control
pin count. The notation N-mux means each segment pin Sx drives N segments on the
 display and there are N common (COMx) pins. Mode is dependent on the number of
 COMs initialized.
                `,
                collapsed: false,
                config: modeConfig,
            },
            /* DL_LCD_setClockConfig */
            {
                name: "GROUP_CLOCK",
                displayName: "Clock Configuration",
                description: "",
                longDescription: "Configures LCD sample clock divider and sample clock frequency range",
                collapsed: false,
                config: [
                    {
                        name        : "lcdClkSrc",
                        displayName : "LCD Clock Source",
                        description : 'LCD sample clock source selection',
                        hidden      : false,
                        default     : "lfclk",
                        readOnly    : true,
                        options     : [
                            {name: "lfclk", displayName: "LFCLK"},
                        ],
                    },
                    {
                        name: "lcdSourceClkFreq",
                        displayName: "Source Clock Frequency",
                        hidden: false,
                        readOnly: true,
                        default: "0Hz",
                        getValue: (inst,ui) =>{
                            return system.modules["/ti/driverlib/SYSCTL"].$static.LFCLK_Freq_unit;
                        }
                    },
                    // DL_LCD_FREQ_DIVIDE
                    {
                        name        : "freqDiv",
                        displayName : "Frequency Divider",
                        description : 'LCD frequency divider',
                        longDescription: `
Together with LCDMXx, the LCD frequency fLCD is calculated as fLCD = fSOURCE / ((LCDDIVx + 1) × Value[LCDMXx]).
                        `,
                        hidden      : false,
                        default     : 1,
                        isInteger   : true,
                        range       : [1,32],
                        onChange    : onChangeSetCustomProfile,
                    },
                    {
                        name: "lcdClkFreq",
                        displayName: "LCD Clock Frequency",
                        hidden: false,
                        readOnly: true,
                        default: "0Hz",
                        getValue: (inst,ui) =>{
                            let lcdFreq = system.modules["/ti/driverlib/SYSCTL"].$static.LFCLK_Freq/inst.freqDiv;
                            return (Common.getUnitPrefix(lcdFreq)).str+"Hz"
                        }
                    },
                ]
            },
            {
                name: "COM_CONFIG",
                displayName: "Common Line Configuration",
                description: "",
                longDescription: "Configures the number of COMx lines used.",
                collapsed: false,
                config: [
                    {
                        name        : "numberOfComInst",
                        displayName : "Number of Common Lines",
                        description : '',
                        hidden      : true,
                        default     : 1,
                        getValue: (inst) => {
                            if(system.modules['/ti/driverlib/lcd/LCDCom']){
                                return system.modules['/ti/driverlib/lcd/LCDCom'].$instances.length
                            }
                        }
                    },
                ]
            },
            {
                name: "SEGMENT_CONFIG",
                displayName: "Segment Line Configuration",
                description: "",
                longDescription: "Configures LCD sample clock divider and sample clock frequency range",
                collapsed: false,
                config: [
                    {
                        name        : "numberOfSegInst",
                        displayName : "Number of Segment Lines",
                        description : '',
                        hidden      : true,
                        default     : 1,
                        getValue: (inst) => {
                            if(system.modules['/ti/driverlib/lcd/LCDSeg']){
                                return system.modules['/ti/driverlib/lcd/LCDSeg'].$instances.length
                            }
                        }
                    },
                // Add Blink Configuration Options
                ].concat(blinkConfig).concat([

                ])
            },
            {
                name: "VLCD_CONFIG",
                displayName: "Voltage Configuration",
                description: "",
                longDescription: "",
                collapsed: false,
                config: vlcdConfig,
            },
        ]
    },
    {
        name: "GROUP_INTERRUPT",
        displayName: "Interrupt Configuration",
        description: "",
        longDescription: "",
        collapsed: false,
        config: [
            {
                name        : "enabledInterrupts",
                displayName : "Enable Interrupts",
                description : 'Enable LCD interrupts',
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
        ],
    },
]

function validatePinmux(inst, validation){
    let ind = 0;
    let resources = [];
    for(let idx = 0; idx <= inst.muxRate-1; idx++){
        let tempIdx = inst["lcdCom"+idx.toString()+"_pin"];
        let tempIdxTrim = tempIdx.slice(20);
        ind = parseInt(tempIdxTrim);
        if(!((resources).includes(tempIdxTrim))){
            resources.push(tempIdxTrim)
        }
        else{
            validation.logError(
                "Pin already in use. Please select a different pin.",
                inst, "lcdCom"+idx.toString()+"_pin"
            );
        }
    }
    /* Add SEG pin resources */
    ind = 0;
    for(let idx = 0; idx < inst.numberOfSegments; idx++){
        let tempIdx = inst["lcdSeg"+idx.toString()+"_pin"];
        let tempIdxTrim = tempIdx.slice(20);
        ind = parseInt(tempIdxTrim);
        if(!((resources).includes(tempIdxTrim))){
            resources.push(tempIdxTrim)
        }
        else{
            validation.logError(
                "Pin already in use. Please select a different pin.",
                inst, "lcdSeg"+idx.toString()+"_pin"
            );
        }
    }
}

/*
 *  ======== validate ========
 *  Validate this inst's configuration
 *
 *  param inst       - module instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validate(inst, validation)
{
    /* Waveform Validation */
    if(inst.waveMode == "LOWPOWER"){
        if(inst.biasSel !== "ONE_THIRD"){
            if(!inst.biasEnable){
                validation.logError(
                    "Low Power Waveform requires Internal Bias be set to 1/3",
                    inst, ["waveMode", "biasSel"]
                );
            }
            if(inst.muxRate<5){
                validation.logError(
                    "Low Power Waveform can only be set for 5-mux to 8-mux LCD modes",
                    inst, ["waveMode", "muxRate"]
                );
            }
        }
    }
    /* Bias Mode Validation */
    if(inst.muxRate <5){
        validation.logInfo(
            "This selection is ignored in static mode and for 2-mux, 3-mux, and 4-mux LCD modes",
            inst, ["biasSel"]
        );
    }

    /* Voltage Configuration Validation */
    if(inst.biasEnable &&  inst.pumpEnable){
        validation.logError(
            "Internal Bias and Charge Pump cannot be enabled at the same time.",
            inst, ["biasEnable", "pumpEnable"]
        );
    }
    if(inst.vlcdSource == "INTERNAL_VREF"){
        if(!inst.pumpEnable){
            validation.logError(
                "Internal VREF requires Charge Pump to be enabled.",
                inst, ["vlcdSource", "pumpEnable"]
            );
        }
    }
}

/*
 * Gets a DMA module if available
 */



function moduleInstances(inst){
    let modInstances = [];
    let longDescription = ``;
    let firstCollapse = false;

    let modInst = {
        name: "associatedCOM",
        displayName: "Common Lines",
        useArray: true,
        defaultInstanceCount: 0,
        minInstanceCount: 1,
        maxInstanceCount: 8,
        longDescription: longDescription,
        collapsed: firstCollapse,
        moduleName: "/ti/driverlib/lcd/LCDCom",
        hidden: false,
        args: {

        },
        requiredArgs: {

        },
        group: "COM_CONFIG", //lcdComIdx.toString(),
    };

    modInstances.push(modInst);

    modInst = {
        name: "associatedSEG",
        displayName: "Segment Lines",
        useArray: true,
        defaultInstanceCount: 0,
        minInstanceCount: 1,
        maxInstanceCount: lcdPortRange,
        longDescription: longDescription,
        collapsed: firstCollapse,
        moduleName: "/ti/driverlib/lcd/LCDSeg",
        hidden: false,
        args: {

        },
        requiredArgs: {

        },
        group: "SEGMENT_CONFIG", //lcdComIdx.toString(),
    };

    modInstances.push(modInst);


    return (modInstances);
}

// TODO: this could be a Common (or LCDCommon) function
const allLCDInterface = [];
for(let ix = 0; ix <= 58; ix++){
    allLCDInterface.push("LCD"+ix);
}

function getPinmuxResources(inst){
    let resources = [];

    /* TODO: temporarily removing LCDEN/LCDLFCLK pin pending alignment on necessity */
    // resources.push({
    //     name:"LCDEN",
    //     displayName:"LCDEN Pin",
    //     interfaceNames:["LCDEN"],
    // },
    // {
    //     name:"LCDLFCLK",
    //     displayName:"LCDLFCLK Pin",
    //     interfaceNames:["LCDLFCLK"],
    // });

    if(!(inst.biasEnable && (inst.biasVSource !== "R33"))){
        resources.push({
            name:"R33",
            displayName:"R33 Pin",
            interfaceNames:["R33"],
        });
    }

    // if(inst.numberOfSegments>0){
    //     resources.push({
    //         name:"LCDSON",
    //         displayName:"LCDSON Pin",
    //         interfaceNames:["LCDSON"],
    //     });
    // }

    if(inst.pumpEnable){
        resources.push({
            name:"R13",
            displayName:"R13 Pin",
            interfaceNames:["R13"],
        },
        {
            name:"R23",
            displayName:"R23 Pin",
            interfaceNames:["R23"],
        });
        if(inst.biasSel == "ONE_FOURTH"){
            resources.push({
                name:"R24",
                displayName:"R24 Pin",
                interfaceNames:["R24"],
            });
        }
    }
    if(inst.pumpEnable){
        resources.push({
            name:"LCDCAP0",
            displayName:"LCDCAP0 Pin",
            interfaceNames:["LCDCAP0"],
        },
        {
            name:"LCDCAP1",
            displayName:"LCDCAP1 Pin",
            interfaceNames:["LCDCAP1"],
        });
    }

    return resources;
}

function pinmuxRequirements(inst)
{
    let lcd = {
        name: "peripheral",
        displayName: "LCD Peripheral",
        interfaceName: "LCD",
        resources: getPinmuxResources(inst),
        signalTypes: {
            LCDCAP0: ["LCDCAP0"],
            LCDCAP1: ["LCDCAP1"],
            // LCDEN: ["LCDEN"],
            // LCDLFCLK: ["LCDLFCLK"],
            // LCDLCDSON: ["LCDSON"],
            R13: ["R13"],
            R23: ["R23"],
            R24: ["R24"],
            R33: ["R33"]
        },
        canShareWith  : "LCD",
    };

    let ind = 0;

    return [lcd];
}

/*
 *  ======== devSpecific ========
 *  Device-specific extensions to be added to base module configuration
 */
let devSpecific = {

    config: LCDConfig,

    validate: validate,

    // validatePinmux: validatePinmux,

    moduleInstances: moduleInstances,

    modules: setRequiredModules,

    pinmuxRequirements: pinmuxRequirements,

};

function setRequiredModules(inst){
    let theModules = ["Board", "SYSCTL"]
    if(inst.enableCRCCalcWithDMA){
        theModules.push("DMA");
    }

    let kwargs = theModules;
    let modArray = [];

    for (let args = kwargs.length - 1; args >= 0; args--) {
        let modPath = kwargs[args];
        if (modPath.indexOf('/') == -1) {
            modPath = "/ti/driverlib/" + modPath;
        }
        modArray.push({
            name      : modPath.substring(modPath.lastIndexOf('/') + 1),
            moduleName: modPath,
            hidden    : true
        });
    }

    return modArray;



}

/*
 *  ======== extend ========
 *  Extends a base exports object to include any device specifics
 *
 *  This function is invoked by the generic module module to
 *  allow us to augment/override as needed for the MSPM0.
 */
function extend(base)
{
    /* merge and overwrite base module attributes */
    let result = Object.assign({}, base.moduleStatic, devSpecific);

    /* concatenate device-specific configs */
    // moduleStatic specific to CRC as it's statically defined
    result.config = base.moduleStatic.config.concat(devSpecific.config);
    base.moduleStatic = result;

    return (base);
}

/*
 *  ======== exports ========
 *  Export device-specific extensions to base exports
 */
exports = {
    /* required function, called by base module module */
    extend: extend
};
