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
 *  ======== SPIMSPM0.syscfg.js ========
 */

"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

/************************Interrupt Functions **********************************/

/************************Interrupt Functions **********************************/
function getIntOptions(inst)
{
    let allOptions = [
        {name: "DMA_DONE_TX", displayName: "DMA done on transit"},
        {name: "DMA_DONE_RX", displayName: "DMA done on receive"},
        {name: "IDLE", displayName: "Idle"},
        {name: "TX_EMPTY", displayName: "Transmit FIFO empty"},
        {name: "TX", displayName: "Transmit"},
        {name: "RX", displayName: "Receive"},
        {name: "RX_TIMEOUT", displayName: "RX timeout"},
        {name: "PARITY_ERROR", displayName: "Parity error"},
        {name: "RX_OVERFLOW", displayName: "Receive FIFO overflow"},
        {name: "RX_FULL", displayName: "Receive FIFO full"},
        {name: "TX_UNDERFLOW", displayName: "Transmit FIFO underflow"},
    ];

    return allOptions;
}

function onFrameFormatEnable(inst, ui){

    if (inst.mode == "CONTROLLER") {
        if((inst.frameFormat == "MOTO4") || (inst.frameFormat == "MOTO3")){
            ui["enableCDMode"].hidden = false
            ui["polarity"].hidden = false
            ui["phase"].hidden = false
        }
        else {
            ui["enableCDMode"].hidden = true
            ui["polarity"].hidden = true
            ui["phase"].hidden = true
        }
    }

    if (inst.frameFormat == "MOTO3")
    {
        ui["chipSelect"].hidden = true
        ui["defaultChipSelect"].hidden = true
        ui["peripheralChipSelect"].hidden = true
    }
    else
    {
        if (inst.mode == "CONTROLLER")
        {
            ui["chipSelect"].hidden = false
            /* Only show defaultChipSelect if > 1 CS has been selected */
            ui["defaultChipSelect"].hidden = !(inst.chipSelect.length > 1)
            ui["peripheralChipSelect"].hidden = true
        }
        else
        {
            ui["chipSelect"].hidden = true
            ui["defaultChipSelect"].hidden = true
            ui["peripheralChipSelect"].hidden = false
        }
    }
    onCDModeEnable(inst, ui)
    onCDModeCustom(inst, ui)
}


function onParityEnable(inst, ui){
    if (inst.parity != "NONE") {
        ui["parityDirection"].hidden = false
    }
    else
    {
        ui["parityDirection"].hidden = true
    }
}

function onCDModeEnable(inst, ui){
    if (inst.mode == "CONTROLLER" && inst.frameFormat == "MOTO4")
    {
        if (inst.enableCDMode) {
            ui["cdModeDefaultValue"].hidden = false
            if (inst.cdModeDefaultValue == "CUSTOM") {
                ui["cdModeValue"].hidden = false
            } else {
                ui["cdModeValue"].hidden = true
            }
        }
        else
        {
            ui["cdModeDefaultValue"].hidden = true
            ui["cdModeValue"].hidden = true
        }
    } else {
        ui["enableCDMode"].hidden = true
        ui["cdModeValue"].hidden = true
        ui["cdModeDefaultValue"].hidden = true
    }


}

function onCDModeCustom(inst, ui){
    if (inst.mode == "CONTROLLER" && inst.frameFormat == "MOTO4")
    {
        if (inst.cdModeDefaultValue == "CUSTOM") {
            ui["cdModeValue"].hidden = false
        } else {
            ui["cdModeValue"].hidden = true
        }
    } else {
        ui["enableCDMode"].hidden = true
        ui["cdModeValue"].hidden = true
        ui["cdModeDefaultValue"].hidden = true
    }

}

/************************* General functions *******************************/
function hasMuxablePins(interfaceName, pinName) {
    /*
     * _.some returns true if the function supplied in the second parameter
     *  returns true for any element)
     */

    const interfacePin = system.deviceData.interfaces[interfaceName].interfacePins[pinName];
    return _.some(interfacePin.pinMappings, (peripheralPin) => peripheralPin.pinMappings.length !== 0);
}

const SPICSOptions = [
    {name: "0", displayName: "CS0"},
    {name: "1", displayName: "CS1"},
    {name: "2", displayName: "CS2"},
    {name: "3", displayName: "CS3"},
];

function getSPICSDisabledOptions(inst)
{
    let disabledOptions = [];

    if (inst.enableCDMode == true)
    {
        disabledOptions.push({name: "3",
                              displayName: "CS3",
                              reason: "CS3 reserved for CD Mode usage"});
    }

    return disabledOptions;
}

function getSPIDefaultCSDisabledOptions(inst)
{
    let disabledOptions = [];

    if (inst.enableCDMode == true)
    {
        disabledOptions.push({name: "3",
                              displayName: "CS3",
                              reason: "CS3 reserved for CD Mode usage"});
    }

    for (let csOption in SPICSOptions)
    {
        if (!inst.chipSelect.includes(csOption))
        {
            disabledOptions.push({name: csOption,
                                  displayName: "CS" + csOption,
                                  reason: "CS" + csOption + " has not been selected as CS"});
        }
    }

    return disabledOptions;
}

/************************* Profiles functions *******************************/
/*
 *  ======== onChangeSPIProfile ========
 *  Called when SPI Profile is changed.
 *  Pre-configures SPI according to profiles
 *
 */
    let defaultDMAConfig = {
        enabledDMAEvent1Triggers : "None",
        enabledDMAEvent2Triggers : "None",
        enableDMAEvent1 : false,
        enableDMAEvent2 : false,
    }
    let configProfile1 = {
        name : "CONFIG_PROFILE_1", /* Controller 4-Wire Mode at Maximum Frequency using BUSCLK */
        mode : "CONTROLLER",
        spiClkSrc      : "BUSCLK",
        targetBitRate : 16000000,
        calculatedBitRate: 0,
        frameFormat : "MOTO4",
        polarity : "0",
        phase : "0",
        dataSize: 8,
        bitOrder: "MSB",
        chipSelect: ["0"],
        peripheralChipSelect: "0",
        rxFifoThreshold: "DL_SPI_RX_FIFO_LEVEL_1_2_FULL",
        txFifoThreshold: "DL_SPI_TX_FIFO_LEVEL_1_2_EMPTY",
        direction: "PICO_POCI",
        parity: "NONE",
        parityDirection: "TX_RX",
        rxTimeoutValue: 0,
        enableCDMode: false,
        cdModeDefaultValue: "COMMAND",
        cdModeValue: 1,
        enableInternalLoopback: false,
        delayedSampling: 0,
        clearRXCounterOnCSIdle: false,
        enabledInterrupts : [],
        interruptPriority : "DEFAULT",
    };
    if(!Common.isDeviceM0C()){
        configProfile1 = {...configProfile1, ...defaultDMAConfig};
    };
    let configProfile2 = {
        name : "CONFIG_PROFILE_2", /* Controller 3-Wire Mode at 1 MHZ using MFCLK */
        mode : "CONTROLLER",
        spiClkSrc      : "MFCLK",
        targetBitRate : 1000000,
        calculatedBitRate: 0,
        frameFormat : "MOTO3",
        polarity : "0",
        phase : "0",
        dataSize: 8,
        bitOrder: "MSB",
        chipSelect: [],
        peripheralChipSelect: "0",
        rxFifoThreshold: "DL_SPI_RX_FIFO_LEVEL_1_2_FULL",
        txFifoThreshold: "DL_SPI_TX_FIFO_LEVEL_1_2_EMPTY",
        direction: "PICO_POCI",
        parity: "NONE",
        parityDirection: "TX_RX",
        rxTimeoutValue: 0,
        enableCDMode: false,
        cdModeDefaultValue: "COMMAND",
        cdModeValue: 1,
        enableInternalLoopback: false,
        delayedSampling: 0,
        clearRXCounterOnCSIdle: false,
        enabledInterrupts : [],
        interruptPriority : "DEFAULT",
    };
    if(!Common.isDeviceM0C()){
        configProfile2 = {...configProfile2, ...defaultDMAConfig};
    };
    let configProfile3 = {
        name : "CONFIG_PROFILE_3", /* Peripheral 4-Wire Mode using BUSCLK */
        mode : "PERIPHERAL",
        spiClkSrc      : "BUSCLK",
        frameFormat : "MOTO4",
        polarity : "0",
        phase : "0",
        dataSize: 8,
        bitOrder: "MSB",
        chipSelect: [],
        peripheralChipSelect: "0",
        rxFifoThreshold: "DL_SPI_RX_FIFO_LEVEL_1_2_FULL",
        txFifoThreshold: "DL_SPI_TX_FIFO_LEVEL_1_2_EMPTY",
        direction: "PICO_POCI",
        parity: "NONE",
        parityDirection: "TX_RX",
        rxTimeoutValue: 0,
        enableCDMode: false,
        cdModeDefaultValue: "COMMAND",
        cdModeValue: 1,
        enableInternalLoopback: false,
        delayedSampling: 0,
        clearRXCounterOnCSIdle: false,
        enabledInterrupts : [],
        interruptPriority : "DEFAULT",
    };
    if(!Common.isDeviceM0C()){
        configProfile3 = {...configProfile3, ...defaultDMAConfig};
    };
const profilesSPI = [
    configProfile1,
    configProfile2,
    configProfile3,
];

function onChangeSPIProfile(inst, ui) {
    if (inst.profile != "CUSTOM")
    {
        let selectedProfileArray = profilesSPI.filter(obj =>
                                        {return obj.name === inst.profile});
        if (selectedProfileArray.length != 0)
        {
            const selectedProfile = Object.assign({}, selectedProfileArray[0]);
            //selectedProfile = selectedProfile[0];
            delete selectedProfile.name;
            Object.assign(inst, selectedProfile)
        }
        updateGUIbasedonConfig(inst, ui);
    }
}

function updateGUIbasedonConfig(inst, ui)
{
    updateGUIChangeMode(inst, ui)
    onFrameFormatEnable(inst, ui)
    onParityEnable(inst, ui)
    onCDModeEnable(inst, ui)
    onCDModeCustom(inst,ui)
}

/* Functions that update GUI based on Configuration */
function updateGUIChangeMode(inst, ui)
{
    if (inst.mode == "CONTROLLER")
    {
        /* Reveal Controller specific functions */
        ui["delayedSampling"].hidden = false
        ui["delayedSamplingCalc"].hidden = false
        ui["enableCDMode"].hidden = false
        ui["enableInternalLoopback"].hidden = false
        ui["targetBitRate"].hidden = false
        ui["calculatedBitRate"].hidden = false
        ui["calculatedError"].hidden = false

        /* Hide Peripheral specific functions */
        ui["clearRXCounterOnCSIdle"].hidden = true
        ui["rxTimeoutValue"].hidden = true
        ui["rxTimeoutValueCalc"].hidden = true
    }
    else if (inst.mode == "PERIPHERAL")
    {
        /* Hide Controller specific functions */
        ui["delayedSampling"].hidden = true
        ui["delayedSamplingCalc"].hidden = true

        ui["enableCDMode"].hidden = true
        ui["enableInternalLoopback"].hidden = true
        ui["targetBitRate"].hidden = true
        ui["calculatedBitRate"].hidden = true
        ui["calculatedError"].hidden = true

        /* Reveal Peripheral specific functions */
        ui["clearRXCounterOnCSIdle"].hidden = false
        ui["rxTimeoutValue"].hidden = false
        ui["rxTimeoutValueCalc"].hidden = false
    }

    if (inst.frameFormat == "MOTO3")
    {
        ui["chipSelect"].hidden = true
        ui["defaultChipSelect"].hidden = true
        ui["peripheralChipSelect"].hidden = true
    }
    else
    {
        if (inst.mode == "CONTROLLER")
        {
            ui["chipSelect"].hidden = false
            /* Only show defaultChipSelect if > 1 CS has been selected */
            ui["defaultChipSelect"].hidden = !(inst.chipSelect.length > 1)
            ui["peripheralChipSelect"].hidden = true
        }
        else
        {
            ui["chipSelect"].hidden = true
            ui["defaultChipSelect"].hidden = true
            ui["peripheralChipSelect"].hidden = false
        }
    }
    onCDModeEnable(inst,ui)
    onCDModeCustom(inst,ui)
}

/* When target baud rate is changed, set the calculated baud rate back to 0 */
function updateGUIbasicBitRateCalc(inst, ui) {
    inst.calculatedBitRate = 0;
}

function updateGUIInterrupts(inst, ui){
    ui.interruptPriority.hidden = (inst.enabledInterrupts.length === 0);
}

function onChangeSetCustomProfile(inst,ui){
    inst.profile = "CUSTOM";
}

/************************* On Change functions *******************************/
/* onChange functions  */
function onChangeEnableController(inst, ui) {
    updateGUIChangeMode(inst, ui);
    onChangeSetCustomProfile(inst, ui);
}

function onChangeBasicBitRateCalc(inst, ui)
{
    updateGUIbasicBitRateCalc(inst, ui);
    onChangeSetCustomProfile(inst, ui);
}

function onChangeFrameFormat(inst, ui)
{
    onFrameFormatEnable(inst,ui);
    onChangeSetCustomProfile(inst, ui);
}

function onChangeParity(inst, ui)
{
    onParityEnable(inst,ui);
    onChangeSetCustomProfile(inst, ui);
}

function onChangeDefaultChipSelect(inst, ui)
{
    /*
     * Dynamically reassign Default Chip Select to be the first item in the
     * chipSelect array. If the array is empty, set Default Chip Select to
     * Chip Select 0
     */
    let chipSelectArg = (inst.chipSelect.length) ? inst.chipSelect[0] : "0";

    let updatedField = {
        defaultChipSelect: chipSelectArg,
    }

    Object.assign(inst, updatedField);
}

function onChangeCDMode(inst, ui)
{
    onCDModeEnable(inst,ui);
    onChangeSetCustomProfile(inst, ui);
}

function onChangeCDModeValue(inst, ui)
{
    onCDModeCustom(inst,ui);
    onChangeSetCustomProfile(inst, ui);
}

/************************* General functions **********************************/
/*
 *  ======== getSPIClockSourceFreq ========
 *  Get the SPI Clock source frequency in Hz
 *
 */
function getSPIClockSourceFreq(inst) {
    let spiClockFreq = 0;
    /* SPI has 3 sources:
        BUSCLK
        MFCLK
        LFCLK
    */
   switch (inst.spiClkSrc){
       case "BUSCLK":
           spiClockFreq = Common.getBUSCLKFreq(inst, "SPI");
        break;
        case "MFCLK":
            spiClockFreq = system.modules["/ti/driverlib/SYSCTL"].$static.MFCLK_Freq;
        break;
        case "LFCLK":
            spiClockFreq = system.modules["/ti/driverlib/SYSCTL"].$static.LFCLK_Freq;
        break;
   }
   spiClockFreq = spiClockFreq / inst.spiClkDiv;

   return spiClockFreq;
}

/*
 *  ======== getValueBitRateCalc ========
 *  Calculate the actual SPI bit rate based on clock source
 *  This is used for displaying to inst.calculatedBitRate
 */
function getValueBitRateCalc(inst) {
    let clockFreq;
    let bitRate;
    let scr;
    let calcBitRate;
    let bitArray = [];

    bitRate = inst.targetBitRate;
    clockFreq = getSPIClockSourceFreq(inst);

    scr = (Math.round(clockFreq / (2*bitRate)) - 1);

    calcBitRate = clockFreq / ((1 + scr)*2);
    bitArray.push({name: 0, displayName: calcBitRate.toFixed(2)});

    if(scr - 1 > 0)
    {
        calcBitRate = clockFreq / ((1 + (scr-1))*2);
        bitArray.push({name: -1, displayName: calcBitRate.toFixed(2)});
    }

    if ((scr + 1) < 500)
    {
        calcBitRate = clockFreq / ((1 + (scr+1))*2);
        bitArray.push({name: 1, displayName: calcBitRate.toFixed(2)});
    }

    return bitArray;
}

/*
 *  ======== getSelectedBitRateCalc ========
 * Calculate the SPI bit rate values using the offset from the option that the
 * user selects in inst.calculatedBitRate.
 * This is used for the error calculation in inst.calculatedError
 *
 */
function getSelectedBitRateCalc(inst) {
    let clockFreq;
    let bitRate;
    let scr;
    let calcBitRate;
    let scrOffset;

    bitRate = inst.targetBitRate;
    clockFreq = getSPIClockSourceFreq(inst);

    scr = (Math.round(clockFreq / (2*bitRate)) - 1);
    scrOffset = inst.calculatedBitRate; /* This gets the offset */
    scr = scr + scrOffset;

    calcBitRate = clockFreq / ((1 + scr)*2);

    return calcBitRate;
}

function getSCR(inst) {
    let clockFreq;
    let bitRate;
    let scr;
    let scrOffset;

    bitRate = inst.targetBitRate;
    clockFreq = getSPIClockSourceFreq(inst);

    scr = (Math.round(clockFreq / (2*bitRate)) - 1);
    scrOffset = inst.calculatedBitRate; /* This gets the offset */
    scr = scr + scrOffset;

    return scr;
}

/*
 *  ======== getErrorCalc ========
 *  Calculate the SPI baud error percentage
 *
 */
function getErrorCalc(inst) {
    let error;
    let calcBItRate = getSelectedBitRateCalc(inst);

    error = ((calcBItRate - inst.targetBitRate) / inst.targetBitRate * 100).toFixed(4);

    return parseFloat(Math.abs(error));
}

function getRXTimeoutCalc(inst) {
    let sourceClkFreq;
    let timeout;

    sourceClkFreq = getSPIClockSourceFreq(inst);

    timeout = (inst.rxTimeoutValue) / sourceClkFreq;

    return timeout;
}

function getDelayedSamplingCalc(inst) {
    let sourceClkFreq;
    let delay;

    sourceClkFreq = getSPIClockSourceFreq(inst);

    delay = (inst.delayedSampling) / sourceClkFreq;

    return delay;
}

/*
 *  ======== validatePinmux ========
 *  Validation run after solution
 *
 *  param inst       - module instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validatePinmux(inst, validation) {
    /* Retention Validation */
    /* SPI does not require retention configuration for MSPM0Cxx */
    if(!Common.isDeviceM0C()){
        Common.getRetentionValidation(inst,validation);
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
    Common.validateNames(inst, validation);

    /* Check clocks are initialized properly */
    if(inst.basicClockSourceCalculated == 0)
    {
        let str = "Clock Source " + inst.spiClkSrc + " not properly initialized in SYSCTL";
        validation.logError(str, inst, "spiClkSrc");
    }

    if (inst.mode == "CONTROLLER")
    {
        let maxFrequency = 16000000;
        if(Common.isDeviceM0G())
        {
            if(inst.basicClockSourceCalculated >= 64000000){
                maxFrequency = 32000000;
            } else if (inst.basicClockSourceCalculated >= 48000000){
                maxFrequency = 24000000;
            }
        }
        /* Check frame size is valid */
        if ((inst.dataSize < 4) || (inst.dataSize > 16)) {
            let str = "The frame size must be between 4-16 bits for Controller mode";
            validation.logError(str, inst, "dataSize");
        }

        /* Check that SCLK rate is valid */
        if((inst.targetBitRate) > maxFrequency) {
            let str = "The input clock frequency must be at least 2x faster than the SPI output clock.";
            validation.logError(str, inst, "targetBitRate");
            validation.logError(str, inst, "basicClockSourceCalculated");
        }
    } else if (inst.mode == "PERIPHERAL")
    {
        if ((inst.dataSize < 7) || (inst.dataSize > 16)) {
            let str = "The frame size must be between 7-16 bits for Peripheral mode";
            validation.logError(str, inst, "dataSize");
        }
    }

    /* Check CS3 is not being used in CD mode */
    if (inst.enableCDMode == true)
    {
        if (inst.chipSelect == "3")
        {
            let str = "CS3 is reserved for use with CD Mode enabled. Select a different Chip Select";
            validation.logError(str, inst, "chipSelect");
        }
    }

    /* Check that at least one CS pin is selected in Controller 4-pin modes */
    if ((inst.frameFormat != "MOTO3") && (inst.mode == "CONTROLLER"))
    {
        if (inst.chipSelect.length == 0)
        {
            let str = "A 4-pin frame format has been selected, so you must select at least one Chip Select.";
            validation.logError(str, inst, "chipSelect");
        }
    }
}

/* PROFILES CONFIGURATION */
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
                displayName : "SPI Profiles",
                description : 'Pre-defined profiles for typical SPI configurations',
                longDescription: `
The serial peripheral interface (SPI) module provides a standardized serial interface to transfer data between
MSPM0 devices and other external devices with SPI interface.

![SPI Block Diagram](../docs/english/sysconfig/images/spiBlockDiagM0G3xx.png "SPI Block Diagram")

The Quick Profile Options are:
* **Controller 4-Wire Mode at Maximum Frequency using BUSCLK**:
    * Enables Controller mode
    * Maximum frequency using BUSCLK
    * Motorola 4-wire frame format
    * Clock polarity is low (SPO = 0)
    * Phase bit is cleared, data captured on first clock edge transition (SPH = 0)
    * Frame size is 8 bits
    * Bit order is MSB
    * CS0 selected
    * RX FIFO level at >= 1 entries
    * TX FIFO level at FIFO empty
    * No interrupts enabled by default
* **Controller 3-Wire Mode at 1 MHz using MFCLK**:
    * Enables Controller mode
    * 1 MHZ using MFCLK
    * Motorola 3-wire frame format
    * Phase bit is cleared, data captured on first clock edge transition (SPH = 0)
    * Frame size is 8 bits
    * Bit order is MSB
    * RX FIFO level at >= 1 entries
    * TX FIFO level at FIFO empty
    * No interrupts enabled by default
* **Peripheral 4-Wire Mode using BUSCLK**:
    * Enables Peripheral mode
    * Clock is BUSCLK
    * Motorola 4-wire frame format
    * Phase bit is cleared, data captured on first clock edge transition (SPH = 0)
    * Frame size is 8 bits
    * Bit order is MSB
    * RX FIFO level at >= 1 entries
    * TX FIFO level at FIFO empty
    * No interrupts enabled by default
* **Custom**:
    * Allows custom configuration.`,
                hidden      : false,
                default     : "CUSTOM",
                options     : [
                    {name: "CONFIG_PROFILE_1", displayName: "Controller 4-Wire Mode at Maximum Frequency using BUSCLK"},
                    {name: "CONFIG_PROFILE_2", displayName: "Controller 3-Wire Mode at 1 MHZ using MFCLK"},
                    {name: "CONFIG_PROFILE_3", displayName: "Peripheral 4-Wire Mode using BUSCLK"},
                    {name: "CUSTOM", displayName: "Custom"},
                ],
                onChange    : onChangeSPIProfile,
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
`Basic SPI options allow configuration of the most common options to enable
basic communication and configure the serial interface.
`,
        collapsed: false,
        config: [
        {
            name: "GROUP_INIT",
            displayName: "SPI Initialization Configuration",
            description: "",
            longDescription: "Initializes SPI for selected operation",
            collapsed: false,
            config: [
                    {
                        name        : "mode",
                        displayName : "Mode Select",
                        description : 'Enables SPI Controller Mode',
                        hidden      : false,
                        default     : "CONTROLLER",
                        options     : [
                            {name: "CONTROLLER", displayName: "Controller"},
                            {name: "PERIPHERAL", displayName: "Peripheral"},
                        ],
                        onChange : onChangeEnableController,
                    },
                    {
                        name: "GROUP_BASIC_CLOCK_CONFIG",
                        displayName: "Clock Configuration",
                        description: "",
                        collapsed: true,
                        config: [
                        {
                            name        : "spiClkSrc",
                            displayName : "Clock Source",
                            description : 'Clock source selection',
                            longDescription:`
    The SPI clock can be sourced from:\n
    * LFCLK, or
    * MFCLK, or
    * BUSCLK, which depends on the power domain:
        * If the SPI is in PD1, BUSCLK is derived from MCLK, or,
        * If the SPI is in PD0, BUSCLK is derived from ULPCLK.\n
    The frequency of the clock sources are configured
    in the __SYSCTL Module__. `,
                            default     : "BUSCLK",
                            options     : [
                                {name: "BUSCLK", displayName: "BUSCLK"},
                                {name: "MFCLK", displayName: "MFCLK"},
                                {name: "LFCLK", displayName: "LFCLK"},
                            ],
                            onChange    : onChangeSetCustomProfile,
                        },
                        {
                            name        : "spiClkDiv",
                            displayName : "Clock Divider",
                            description : 'Clock divider selection',
                            default     : "1",
                            options     : [
                                {name: "1", displayName: "Divided by 1"},
                                {name: "2", displayName: "Divided by 2"},
                                {name: "3", displayName: "Divided by 3"},
                                {name: "4", displayName: "Divided by 4"},
                                {name: "5", displayName: "Divided by 5"},
                                {name: "6", displayName: "Divided by 6"},
                                {name: "7", displayName: "Divided by 7"},
                                {name: "8", displayName: "Divided by 8"},
                            ],
                            onChange    : onChangeSetCustomProfile,
                        },
                        {
                            name        : "basicClockSourceCalculated",
                            displayName : "Calculated Clock Source",
                            description : 'Calculated SPI Clock Source in Hz',
                            hidden      : false,
                            getValue    : (inst) => getSPIClockSourceFreq(inst),
                            default     : 0
                        },
                    ]
                },
                    {
                        name        : "targetBitRate",
                        displayName : "Target Bit Rate (Hz)",
                        description : 'The target bit rate in Hz for the serial output clock',
                        longDescription:`
The SPI includes a programmable bit rate clock divider and prescaler to generate the serial output clock.\n
The bit rates are supported up to the input clock divided by 2.
The input clock selection depends on the specific device.`,
                        hidden      : false,
                        default     : 8000000,
                        range       : (Common.isDeviceM0G() ? [0, 32000000] : [0, 16000000]),
                        onChange    : onChangeBasicBitRateCalc
                    },
                    {
                        name        : "calculatedBitRate",
                        displayName : "Calculated Bit Rate",
                        description : 'The calculated bit rate in Hz',
                        longDescription:`
This setting shows the closest calculated bit rates based on the target bit rate.\n
The next available options are shown in drop-down for convenience purposes
and can be selected if needed.\n
The serial bit rate is derived by dividing down the input clock. \n
First, the clock is divided by a ratio selected by the clock divider. The clock
is further divided by a value from 1 to 1024, which is 1 + SCR, where SCR is the
serial clock divider ratio value programmed in the CLKCTL.SCR register.\n
The equation below defines the frequency of the output clock:\n
        bitRate = (spiClock) / ((1 + SCR) * 2)\n
The factor of two (*2) is set by CLKDIV and the input clock must be at least
2 times faster than SPI output clock.\n
Givven the SPI clock and the Target Bit Rate, the SCR can be calculated with the
following equation:\n
        SCR = (spiClock) / (2 * bitRate)) - 1)
`,
                        hidden      : false,
                        options    : (inst) => getValueBitRateCalc(inst),
                        default     : 0
                    },
                    {
                        name        : "scr", /* Used internally for code gen */
                        displayName : "SCR",
                        description : 'The scr',
                        hidden      : true,
                        getValue    : (inst) => getSCR(inst),
                        default     : 0
                    },
                    {
                        name        : "calculatedBitRateNum", /* Used internally for code gen */
                        displayName : "Calculated Bit Rate",
                        description : 'The calculated bit rate in Hz',
                        hidden      : true,
                        getValue    : (inst) => parseFloat(getSelectedBitRateCalc(inst).toFixed(2)),
                        default     : 0
                    },
                    {
                        name        : "calculatedError",
                        displayName : "Calculated Error (%)",
                        description : 'The calculated error percentage',
                        longDescription: `
This shows the calculated baud rate error percentage.\n
This is calculated by:\n
        error = (calculatedBitRate - targetBitRate) / (targetBitRate * 100)\n
`,
                        hidden      : false,
                        getValue    : (inst) => getErrorCalc(inst),
                        default     : 0
                    },
                    /* DL_SPI_setFrameFormat */
                    {
                        name: "frameFormat",
                        displayName: "Frame Format",
                        description: "The protocol format for the SPI mode",
                        longDescription: `
The supported options are: Motorola 4-wire, Motorola 3-wire, and Texas Instruments
Synchronous.\n
__Motorola SPI Frame Format:__\n
The Motorola SPI interface is a 4-wire interface where the CS signal behaves
as a peripheral select. In the 3-wire mode the CS signals is not required and
the module behaves as if always selected. The main feature of the Motorola SPI
format is that the inactive state and phase of the SCLK signal can be programmed
through the clock polarity (SPO) and phase (SPH) bits.\n

* Signal sequences for Motorola SPI format with SPO = 0 and SPH = 0.\n
    ![SPI Motorola SPO0 SPH0](../docs/english/sysconfig/images/spimotospo0sph0M0G3xx.png "SPI Motorola Diagram SPO0 SPH0")\n

* Signal sequences for Motorola SPI format with SPO = 0 and SPH = 1.\n
    ![SPI Motorola SPO0 SPH1](../docs/english/sysconfig/images/spimotospo0sph1M0G3xx.png "SPI Motorola Diagram SPO0 SPH1")\n

* Signal sequences for Motorola SPI format with SPO = 1 and SPH = 0.\n
    ![SPI Motorola SPO1 SPH0](../docs/english/sysconfig/images/spimotospo1sph0M0G3xx.png "SPI Motorola Diagram SPO1 SPH0")\n

* Signal sequences for Motorola SPI format with SPO = 1 and SPH = 1.\n
    ![SPI Motorola SPO1 SPH1](../docs/english/sysconfig/images/spimotospo1sph1M0G3xx.png "SPI Motorola Diagram SPO1 SPH1")\n

 __Texas Instruments Synchronous:__\n
SCLK and CS are forced low and the transmit data line PICO is put in tristate whenever the SPI is idle. When
the bottom entry of the TX FIFO contains data, CS is pulsed high for one SCLK period. The transmitted value
is also transferred from the TX FIFO to the serial shift register of the transmit logic. On the next rising edge of
SCLK, the MSB of the 4- to 16-bit data frame is shifted out on the PICO pin. Likewise, the MSB of the received
data is shifted onto the POCI pin by the off-chip serial peripheral device. Both the SPI and the off-chip serial
peripheral device then clock each data bit into their serial shifter on each falling edge of SCLK. The received
data is transferred from the serial shifter to the RX FIFO on the first rising edge of SCLK after the least significant
bit (LSB) is latched.\n
The serial clock (SCLK) is held inactive while the SPI is idle and SCLK transitions at the programmed frequency
only during active transmission or reception of data. The IDLE state of SCLK provides a receive time-out
indication that occurs when the RX FIFO still contains data after a time-out period.\n
![SPI TI Sync](../docs/english/sysconfig/images/spitisyncM0G3xx.png "SPI TI Sync Diagram")\n
`,
                        hidden      : false,
                        default: "MOTO4",
                        options: [
                            { name: "MOTO4", displayName: "Motorola 4-wire" },
                            { name: "MOTO3", displayName: "Motorola 3-wire" },
                            { name: "TI_SYNC", displayName: "TI Synchronous" },
                        ],
                        onChange :  onChangeFrameFormat,
                    },
                    {
                        name: "polarity",
                        displayName: "Clock Polarity",
                        description: "The clock polarity",
                        longDescription: `
The clock polarity (SPO) is used when data is not being transferred. It is only used in the
Motorola 4-wire or Motorola 3-wire modes.\n
* Low (SPO = 0): Peripheral produces a steady state LOW value on the CLKOUT pin when data is not being transferred.\n
* High (SPO = 1): Peripheral produces a steady state HIGH value on the CLKOUT pin when data is not being transferred.\n
`,
                        default: "0",
                        options: [
                            { name: "0", displayName: "Low" },
                            { name: "1", displayName: "High" },
                        ]
                    },
                    {
                        name: "phase",
                        displayName: "Phase",
                        description: "The clock phase",
                        longDescription: `
The clock phase (SPH) selects the clock edge that captures data and enables it to change state. It has the
most impact on the first bit transmitted by either permitting or not permitting a clock transition before the first data
capture edge. It is only used in the Motorola 4-wire or Motorola 3-wire modes.\n
* Data captured on the first clock edge transition (SPH = 0).\n
* Data captured on the second clock edge transition (SPH = 1).\n
`,
                        hidden      : false,
                        default: "0",
                        options: [
                            { name: "0", displayName: "Data captured on first clock edge" },
                            { name: "1", displayName: "Data captured on second clock edge" },
                        ]
                    },
                    /* DL_SPI_setDataSize */
                    {
                        name: "dataSize",
                        displayName: "Frame Size (bits)",
                        description: "The bit length of each frame",
                        longDescription: `
The bit length per transfer is defined between 4-16 bits for Controller mode and 7-16 bits for Peripheral mode.\n
A transfer will be triggered with writing to the TX buffer register. The data write needs to have at least the number
of bits of the transfer. For example, if only a byte is written to the TX buffer but the length of the transfer is > 8,
then the missing bits will be filled with 0s.\n
On the receive path the received data will be moved to the RXFIFO or RX buffer after the number of bit defined
have been received.
`,
                        hidden      : false,
                        default: 8,
                        options: [
                            { name: 4, displayName: "4" },
                            { name: 5, displayName: "5" },
                            { name: 6, displayName: "6" },
                            { name: 7, displayName: "7" },
                            { name: 8, displayName: "8" },
                            { name: 9, displayName: "9" },
                            { name: 10, displayName: "10" },
                            { name: 11, displayName: "11" },
                            { name: 12, displayName: "12" },
                            { name: 13, displayName: "13" },
                            { name: 14, displayName: "14" },
                            { name: 15, displayName: "15" },
                            { name: 16, displayName: "16" },
                        ]
                    },
                    /* DL_SPI_setBitOrder */
                    {
                        name: "bitOrder",
                        displayName: "Bit Order",
                        description: "The bit order",
                        longDescription: `
Defines the direction of the data input and output with MSB or LSB first.\n
If the parity is enabled the parity bits is always received as last bit.
`,
                        hidden      : false,
                        default: "MSB",
                        options: [
                            { name: "MSB", displayName: "MSB" },
                            { name: "LSB", displayName: "LSB" },
                        ]
                    },
                    /****** Start of CONTROLLER BASIC CONFIGURATION *******/
                    {
                        name: "basicControllerConfig",
                        displayName: "SPI Controller Basic Configuration",
                        collapsed: false,
                        config: [
                            /* DL_SPI_setChipSelect */
                            {
                                name        : "chipSelect",
                                displayName : "Chip Select",
                                hidden      : false,
                                description : 'Choose which chip select should be used for data transfer',
                                longDescription: `
Select which connected SPI Peripheral device is addressed by the SPI Controller using up to 4 Chip Select (CS) signals.
Enabling a pin will initialize it and reserve it for SPI_CS functionality; however, only one CS can be enabled by the
SPI Controller at a time. Developers can optionally use regular GPIOs as CS by controlling them manually and using
SPI 3-wire mode.
`,
                                minSelections: 0,
                                default     : ["0"],
                                options     : SPICSOptions,
                                getDisabledOptions: getSPICSDisabledOptions,
                                onChange :  (inst, ui) => {
                                    ui.defaultChipSelect.hidden = !(inst.chipSelect.length > 1);
                                    onChangeDefaultChipSelect(inst, ui);
                                    onChangeSetCustomProfile(inst, ui);
                                },
                            },
                            {
                                name        : "defaultChipSelect",
                                displayName : "Default Chip Select",
                                hidden      : true,
                                description : 'Choose which chip select to initially enable',
                                longDescription: `
Configures the Chip Select signal which will be used by default after initialization. Only one CS can be enabled by the
SPI Controller at a time. Developers can switch to a different CS signal during runtime
(i.e. using DL_SPI_setControllerChipSelect) in the application code.
`,
                                default     : "0",
                                options     : SPICSOptions,
                                getDisabledOptions: getSPIDefaultCSDisabledOptions,
                                onChange :  onChangeSetCustomProfile,
                            },
                        ]
                    }, /****** End  of CONTROLLER BASIC CONFIGURATION *******/
                    /****** Start of PERIPHERAL BASIC CONFIGURATION *******/
                    {
                        name: "basicPeripheralConfig",
                        displayName: "SPI Peripheral Basic Configuration",
                        collapsed: false,
                        config: [
                            /* DL_SPI_setChipSelect */
                            {
                                name        : "peripheralChipSelect",
                                displayName : "Chip Select",
                                hidden      : true,
                                description : 'Choose which chip select should be used for data transfer',
                                longDescription: `
Select the Chip Select to be used by the SPI Peripheral after initialization.
Only one CS can be enabled by the SPI Peripheral at a time.
`,
                                default     : "0",
                                options     : SPICSOptions,
                                onChange :  onChangeSetCustomProfile,
                            },
                        ]
                    }, /****** End of PERIPHERAL BASIC CONFIGURATION *******/
                ]
            },
        ],

    }
])

/* DL_SPI_DMA_INTERRUPT_RX */
let dmaEvt1Options = [
    {name: "None", displayName: "None"},
    {name: "DL_SPI_DMA_INTERRUPT_RX", displayName: "SPI RX interrupt"},
    {name: "DL_SPI_DMA_INTERRUPT_RX_TIMEOUT", displayName: "SPI RX Timeout interrupt"},
]
/* DL_SPI_DMA_INTERRUPT_TX */
let dmaEvt2Options = [
    {name: "None", displayName: "None"},
    {name: "DL_SPI_DMA_INTERRUPT_TX", displayName: "SPI TX interrupt"},
]

config = config.concat([
    {
        name: "GROUP_ADVANCED",
        displayName: "Advanced Configuration",
        description: "",
        longDescription: "",
        collapsed: true,
        config: [
            {
                name: "parity",
                displayName: "Parity",
                description: "The type of parity to enable and use for both receive and transmit directions.",
                longDescription: `
Selected parity configuration will be applied for both receive and transmit directions. To only configure parity
When parity check is enabled, an additional bit as parity bit is received and the parity of the
data is calculated and with the received data evaluated. The last bit will be used
as parity to evaluate the integrity of the previous bits.\n
The parity mode can be selected as even or odd.
When detecting a fault, the interrupt flag PER is set (to mark the data as invalid).
`,
                hidden      : false,
                default: "NONE",
                options: [
                    { name: "NONE", displayName: "Disabled" },
                    { name: "ODD", displayName: "Odd Parity" },
                    { name: "EVEN", displayName: "Even Parity" },
                ],
                onChange : onChangeParity,
            },
            {
                name        : "parityDirection",
                displayName : "Parity Direction",
                description : 'Select whether parity is enabled for Transmit only, Receive only, or Transmit and Receive.',
                hidden      : true,
                default     : "TX_RX",
                options     : [
                    {name: "TX_RX", displayName: "Transmit and Receive"},
                    {name: "TX", displayName: "Transmit only"},
                    {name: "RX", displayName: "Receive only"},
                ],
                onChange : onChangeSetCustomProfile,
            },
            /* DL_SPI_setRXFIFOThreshold */
            {
                name        : "rxFifoThreshold",
                displayName : "RX FIFO Threshold Level",
                description : 'The RX FIFO threshold level for when the interrupt triggers',
                default     : "DL_SPI_RX_FIFO_LEVEL_1_2_FULL",
                options     : [
                    {name: "DL_SPI_RX_FIFO_LEVEL_ONE_FRAME", displayName: "RX FIFO contains >= 1 entry"},
                    {name: "DL_SPI_RX_FIFO_LEVEL_FULL", displayName: "RX FIFO is full"},
                    {name: "DL_SPI_RX_FIFO_LEVEL_3_4_FULL", displayName: "RX FIFO contains>= 3 entries"},
                    {name: "DL_SPI_RX_FIFO_LEVEL_1_2_FULL", displayName: "RX FIFO contains>= 2 entries"},
                    {name: "DL_SPI_RX_FIFO_LEVEL_1_4_FULL", displayName: "RX FIFO contains >= 3/4 full"},
                ],
                onChange : onChangeSetCustomProfile,
            },
            /* DL_SPI_setTXFIFOThreshold */
            {
                name        : "txFifoThreshold",
                displayName : "TX FIFO Threshold Level",
                description : 'The TX FIFO interrupt threshold level',
                default     : "DL_SPI_TX_FIFO_LEVEL_1_2_EMPTY",
                options     : [
                    {name: "DL_SPI_TX_FIFO_LEVEL_3_4_EMPTY", displayName: "TX FIFO contains <= 1 entry"},
                    {name: "DL_SPI_TX_FIFO_LEVEL_1_2_EMPTY", displayName: "TX FIFO contains <= 2 entries"},
                    {name: "DL_SPI_TX_FIFO_LEVEL_1_4_EMPTY", displayName: "TX FIFO contains <= 3 entries"},
                    {name: "DL_SPI_TX_FIFO_LEVEL_EMPTY", displayName: "TX FIFO is empty"},
                    {name: "DL_SPI_TX_FIFO_LEVEL_ONE_FRAME", displayName: "TX FIFO contains 1 entry"},
                ],
                onChange : onChangeSetCustomProfile,
            },
            {
                name        : "direction",
                displayName : "Communication Direction",
                description : 'Select the direction for communication. This affects which pins are available in the PinMux section.',
                default     : "PICO_POCI",
                options     : [
                    {name: "PICO_POCI", displayName: "PICO and POCI"},
                    {name: "PICO", displayName: "PICO only"},
                    {name: "POCI", displayName: "POCI only"},
                ],
                onChange : onChangeSetCustomProfile,
            },
            /* DL_SPI_enablePacking */
            {
                name        : "enablePacking",
                displayName : "Enable Packing",
                description : 'Enables packing feature',
                longDescription: `
 When enabled, two entries of the RX FIFO are returned as a 32-bit value.\n
 When reading the TX FIFO, if the last write to that field was a 32-bit
 write, those 32-bits will be returned.\n
 When writing to the TX FIFO, a 32-bit write will be written as one FIFO
 entry.
`,
                hidden      : false,
                default     : false,
                onChange : onChangeSetCustomProfile,
            },
            /****** Start of CONTROLLER ADVANCED CONFIGURATION *******/
            {
                name: "advancedControllerConfig",
                displayName: "SPI Controller Advanced Configuration",
                longDescription: "",
                collapsed: false,
                config: [
                    /* DL_SPI_enableControllerCommandDataMode */
                    {
                        name        : "enableCDMode",
                        displayName : "Enable Command Data Mode",
                        description : 'Enables Command Data Mode',
                        longDescription: `
When using the Motorola frame format, Command Data mode can be enabled to use the CS3 line as a signal to distinguish
between Command and Data information. This is often used for LCD or data storage devices.
`,
                        hidden      : false,
                        default     : false,
                        onChange :  (inst, ui) => {
                            onChangeDefaultChipSelect(inst, ui);
                            onChangeCDMode(inst, ui);
                        },
                    },
                    {
                        name        : "cdModeDefaultValue",
                        displayName : "Command Data Default Mode",
                        description : 'The default level for the CS3/CD line',
                        longDescription: `
When using the Motorola frame format, Command Data mode can be enabled to use the CS3 line as a signal to distinguish
between Command and Data information.
* CD Level Low (Command Mode): The CD signal stays low, indicating Command information
* CD Level High (Data Mode): The CD signal stays high, indicating Data information
* Custom: A value between 1-14 can be written to specify the number of bytes which are sent by the SPI until the CD line goes high.
The CD line will stay low for the given number of bytes, and then the CD will go high automatically
`,
                        hidden      : true,
                        default     : "COMMAND",
                        options     : [
                            {name: "COMMAND", displayName: "CD Level Low (Commmand Mode)"},
                            {name: "DATA", displayName: "CD Level High (Data Mode)"},
                            {name: "CUSTOM", displayName: "Custom"},
                        ],
                        onChange : onChangeCDModeValue,
                    },
                    {
                        name        : "cdModeValue",
                        displayName : "CD Mode Custom Level (Bytes)",
                        description : 'The number of bytes to be transferred by the SPI before the CD line goes high.',
                        longDescription: `
When using Command Data Control, a value between 1-14 can be written to specify the number of bytes which are sent by the SPI until the CD line goes high.
The CD line will stay low for the given number of bytes, and then CD will go high automatically
`,
                        hidden      : true,
                        default     : 1,
                        range : [1,14]
                    },
                    /* DL_SPI_enableLoopbackMode */
                    {
                        name        : "enableInternalLoopback",
                        displayName : "Enable Internal Loopback",
                        description : 'Enables internal loopback mode',
                        longDescription: `
        In loopback mode, data transmitted on the TXD output is received on the RXD input.\n
        Data received on the RXD IO pin will be ignored when loopback is enabled.\n
        `,
                        hidden      : false,
                        default     : false,
                        onChange : onChangeSetCustomProfile,
                    },
                    /* DL_SPI_setDelayedSampling */
                    {
                        name        : "delayedSampling",
                        displayName : "Delayed Data Sampling Counts",
                        description : 'Set the count in clock steps for delayed data sampling',
                        longDescription: `
When due to run time conditions the input data arrives with some additional delay at the POCI pin and the
following input data sampling stage, the previous data would be sampled at the sampling clock edge. To
compensate that a delayed sampling can be set. The delay is adjusted in steps of SPI input clock steps.\n
The maximum allowed delay should not exceed the length of one data frame.
`,
                        hidden      : false,
                        default     : 0,
                        range : [0,15],
                        isInteger : true,
                        onChange : onChangeSetCustomProfile,
                    },
                    {
                        name        : "delayedSamplingCalc",
                        displayName : "Calculated Delayed Sampling",
                        description : 'Calculated time for delayed data sampling',
                        hidden      : false,
                        default     : "0s",
                        getValue    : (inst) => (Common.getUnitPrefix((getDelayedSamplingCalc(inst))).str+'s'),
                    },
                ]
            }, /****** End  of CONTROLLER ADVANCED CONFIGURATION *******/
            /****** Start of PERIPHERAL ADVANCED CONFIGURATION *******/
            {
                name: "advancedPeripheralConfig",
                displayName: "SPI Peripheral Advanced Configuration",
                longDescription: "",
                collapsed: false,
                config: [
                    /* DL_SPI_enablePeripheralAlignDataOnChipSelect */
                    {
                        name        : "clearRXCounterOnCSIdle",
                        displayName : "Enable Clear Shift Ctr On CS Idle",
                        hidden      : true,
                        description : 'Enable clearing the shift counter when the CS signal is idle',
                        longDescription: `
When enabled, the shift counter on CS idle is cleared automatically when CS gets set
inactive. This helps the peripheral to synchronize again on the controller in case of a disturbance or glitch on the
clock line or during initialization.\n
This is relevant only in the peripheral mode.`,
                        default     : false,
                        onChange : onChangeSetCustomProfile,
                    },
                    /* DL_SPI_setRXInterruptTimeout*/
                    {
                        name        : "rxTimeoutValue",
                        displayName : "RX Timeout Interrupt Counts",
                        description : 'Defines the number of Clock Cycles before after which the Receive Timeout flag RTOUT is set.',
                        hidden      : true,
                        default     : 0,
                        range : [0,15],
                        isInteger : true,
                        onChange : onChangeSetCustomProfile,
                    },

                    {
                        name        : "rxTimeoutValueCalc",
                        displayName : "Calculated RX Timeout interrupt",
                        description : 'Calculated timeout for the RX Timeout Interrupt',
                        hidden      : true,
                        default     : "0s",
                        getValue    : (inst) => (Common.getUnitPrefix((getRXTimeoutCalc(inst))).str+'s'),
                    },
                ]
            }, /****** End  of PERIPHERAL ADVANCED CONFIGURATION *******/
            {
                name: "GROUP_RETENTION",
                displayName: "Retention Configuration",
                description: "",
                longDescription: ``,
                collapsed: false,
                config: Common.getRetentionConfig(),
            },
        ]
    },
    {
        name: "GROUP_INTERRUPTS",
        displayName: "Interrupt Configuration",
        longDescription: "This section allows enabling/disabling SPI interrupts",
        collapsed: true,
        config: [
            /* DL_SPI_enableInterrupt */
            {
                name        : "enabledInterrupts",
                displayName : "Enable Interrupts",
                description : 'Enable SPI interrupt',
                default     : [],
                options     : getIntOptions,
                onChange    : (inst, ui) => {
                    updateGUIInterrupts(inst, ui);
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
]);

/* CRC does not support DMA configuration for MSPM0Cxx */
if(!Common.isDeviceM0C()){
config = config.concat([
    {
        name: "GROUP_DMA",
        displayName: "DMA Configuration",
        longDescription: `
This section allows configuring DMA Event triggers.\n
The SPI module can set trigger conditions for the DMA through receive or
transmit events. \n
When the DMA functionality is enabled, the SPI asserts a DMA request
when the configured receive or transmit trigger condition occurs. \n
`,
        collapsed: true,
        config: [
            /* DL_SPI_enableDMAReceiveEvent */
            {
                name        : "enabledDMAEvent1Triggers",
                displayName : "Configure DMA Event 1 Triggers",
                description : 'Configure the SPI interrupts to use as triggers for the DMA RX event',
                hidden      : false,
                default     : "None",
                options     : dmaEvt1Options,
                onChange    : (inst,ui) => {
                    ui.enableDMAEvent1.hidden = (inst.enabledDMAEvent1Triggers == "None");
                    onChangeSetCustomProfile(inst,ui);
                },
            },
            {
                name        : "enableDMAEvent1",
                displayName : "Enable DMA Event 1 Trigger",
                longDescription: `Only one DMA receive trigger can be enabled
                at the same time. If left unchecked, the module-specific enable
                DMA API should be called in the application code.`,
                hidden      : true,
                default     : true,
                onChange    : onChangeSetCustomProfile,
            },
            /* DL_SPI_enableDMATransmitEvent */
            {
                name        : "enabledDMAEvent2Triggers",
                displayName : "Configure DMA Event 2 Trigger",
                description : 'Configure the SPI interrupt to use as triggers for the DMA TX event',
                hidden      : false,
                default     : "None",
                options     : dmaEvt2Options,
                onChange    : (inst,ui) => {
                    ui.enableDMAEvent2.hidden = (inst.enabledDMAEvent1Triggers == "None");
                    onChangeSetCustomProfile(inst,ui);
                },
            },
            {
                name        : "enableDMAEvent2",
                displayName : "Enable DMA Event 2 Trigger",
                longDescription: `If left unchecked, the module-specific enable
                DMA API should be called in the application code.`,
                hidden      : true,
                default     : true,
                onChange    : onChangeSetCustomProfile,
            },
        ]
    },
])
}

/* Add Pinmux Peripheral Configuration group */
config = config.concat(Common.getGPIOGroupConfig());

function moduleInstances(inst){
    let modInstances = []
    /* SPI does not support DMA configuration for MSPM0Cxx */
    if(!Common.isDeviceM0C()){
        /*
        * Gets a DMA module if available
        */
        if(!["None"].includes(inst.enabledDMAEvent1Triggers)){
            let mod = {
                name: "DMA_CHANNEL_EVENT1",
                displayName: "DMA Channel Event 1",
                moduleName: '/ti/driverlib/DMAChannel',
                group: "GROUP_DMA",
                args: {

                },
                requiredArgs: {
                    hideTriggerSelect: true,
                    passedTriggerSelect: 0,

                },

            }
            modInstances.push(mod);
        }
        if(!["None"].includes(inst.enabledDMAEvent2Triggers)){
            let mod = {
                name: "DMA_CHANNEL_EVENT2",
                displayName: "DMA Channel Event 2",
                moduleName: '/ti/driverlib/DMAChannel',
                group: "GROUP_DMA",
                args: {
                },
                requiredArgs: {
                    hideTriggerSelect: true,
                    passedTriggerSelect: 1,

                },

            }
            modInstances.push(mod);
        }
    }

    /*
     * Gets a Peripheral GPIO Configuration submodule
     */
    /* CONDITIONS CODE START */
    let sclkConfig, picoConfig, pociConfig, cs0Config, cs1Config, cs2Config, cs3Config = false;

    sclkConfig = true;

    switch(inst.direction) {
        case 'PICO_POCI':
            picoConfig = true;
            pociConfig = true;
            break;
        case 'POCI':
            pociConfig = true;
            break;
        case 'PICO':
            picoConfig = true;
            break;
    }

    if (inst.mode == "PERIPHERAL")
    {
        if (inst.frameFormat == "MOTO4" || inst.frameFormat == "TI_SYNC")
        {
            switch(inst.peripheralChipSelect) {
                case "0":
                    cs0Config = true;
                    break;
                case "1":
                    cs1Config = true;
                    break;
                case "2":
                    cs2Config = true;
                    break;
                case "3":
                    cs3Config = true;
                    break;
            }
        }
    }
    else if (inst.mode == "CONTROLLER") {
        if (inst.frameFormat == "MOTO4" || inst.frameFormat == "TI_SYNC") {
            if (inst.chipSelect.includes("0"))
            {
                cs0Config = true;
            }
            if (inst.chipSelect.includes("1"))
            {
                cs1Config = true;
            }
            if (inst.chipSelect.includes("2"))
            {
                cs2Config = true;
            }
            if (inst.chipSelect.includes("3") && inst.enableCDMode == false)
            {
                cs3Config = true;
            }
        }

        if (inst.enableCDMode == true) {
            cs3Config = true;
        }
    }
    /* CONDITIONS CODE END */

    /* SCLK */
    /* SCLK pin does not support output inversion */
    Common.pushGPIOConfigInstHideOutInv(inst, modInstances,   sclkConfig,    "sclkPin",
     "SCLK", "SPI SCLK (Clock)",
     ((inst.mode == "PERIPHERAL") ? "INPUT" : "OUTPUT"));
    /* PICO */
    Common.pushGPIOConfigInst(inst, modInstances,   picoConfig,    "mosiPin",
     "PICO", "SPI PICO (Peripheral In, Controller Out)",
     ((inst.mode == "PERIPHERAL") ? "INPUT" : "OUTPUT"));
    /* POCI */
    /* POCI pin does not support output inversion */
    Common.pushGPIOConfigInstHideOutInv(inst, modInstances,   pociConfig,    "misoPin",
     "POCI", "SPI POCI (Peripheral Out, Controller In)",
     ((inst.mode == "CONTROLLER") ? "INPUT" : "OUTPUT"));
    /* CS0 */
    Common.pushGPIOConfigInst(inst, modInstances,   cs0Config,    "cs0Pin",
     ((inst.mode == "CONTROLLER") ? "CS0" : "CS"), "SPI CS0 (Chip Select 0)",
     ((inst.mode == "PERIPHERAL") ? "INPUT" : "OUTPUT"));
    /* CS1 */
    Common.pushGPIOConfigInst(inst, modInstances,   cs1Config,     "cs1Pin",
     ((inst.mode == "CONTROLLER") ? "CS1" : "CS"), "SPI CS1 (Chip Select 1)",
     ((inst.mode == "PERIPHERAL") ? "INPUT" : "OUTPUT"));
    /* CS2 */
    Common.pushGPIOConfigInst(inst, modInstances,   cs2Config,     "cs2Pin",
     ((inst.mode == "CONTROLLER") ? "CS2" : "CS"), "SPI CS2 (Chip Select 2)",
     ((inst.mode == "PERIPHERAL") ? "INPUT" : "OUTPUT"));
    /* CS3 */
    Common.pushGPIOConfigInst(inst, modInstances,   cs3Config,     "cs3Pin",
     ((inst.mode == "CONTROLLER") ? ((inst.enableCDMode) ? "CD" : "CS3") : "CS"), "SPI CS3 (Chip Select 3)",
     ((inst.mode == "PERIPHERAL") ? "INPUT" : "OUTPUT"));

    return modInstances;

}

/*
 *  ======== devSpecific ========
 *  Device-specific extensions to be added to base module configuration
 */
let devSpecific = {

    config: config,


    maxInstances: Common.peripheralCount("SPI"),

    /* override generic requirements with  device-specific reqs (if any) */
    validate: validate,

    validatePinmux: validatePinmux,

    pinmuxRequirements: pinmuxRequirements,

    moduleInstances: moduleInstances,

    filterHardware: filterHardware,

    /* override device-specific templates */
    templates: {
        boardc: "/ti/driverlib/spi/SPI.Board.c.xdt",
        boardh: "/ti/driverlib/spi/SPI.Board.h.xdt",
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
    let theModules = ["Board", "SYSCTL"]
    /* SPI does not support DMA configuration for MSPM0Cxx */
    if(!Common.isDeviceM0C()){
        if(!["None"].includes(inst.enabledDMAEvent1Triggers) || !["None"].includes(inst.enabledDMAEvent2Triggers)){
            theModules.push("DMA");
        }
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

    return modArray
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
    let sclk = {
        name              : "sclkPin",  /* config script name */
        displayName       : "SPI SCLK (Clock)", /* GUI name */
        interfaceNames    : ["SCLK"]   /* pinmux tool name */
    };

    let mosi = {
        name              : "mosiPin",
        displayName       : "SPI PICO (Peripheral In, Controller Out)",
        interfaceNames    : ["PICO"]
    };
    let miso = {
        name              : "misoPin",
        displayName       : "SPI POCI (Peripheral Out, Controller In)",
        interfaceNames    : ["POCI"]
    };

    let cs0 = {
        name              : "cs0Pin",
        displayName       : "SPI CS0 (Chip Select 0)",
        interfaceNames    : ["CS0"]
    };

    let cs1 = {
        name              : "cs1Pin",
        displayName       : "SPI CS1 (Chip Select 1)",
        interfaceNames    : ["CS1_POCI1"]
    };

    let cs2 = {
        name              : "cs2Pin",
        displayName       : "SPI CS2 (Chip Select 2)",
        interfaceNames    : ["CS2_POCI2"]
    };

    let cs3 = {
        name              : "cs3Pin",
        displayName       : "SPI CS3/CD (Chip Select 3/Command Data)",
        interfaceNames    : ["CS3_CD_POCI3"]
    };

    let resources = [];

    resources.push(sclk);

    switch(inst.direction) {
        case 'PICO_POCI':
            resources.push(mosi);
            resources.push(miso);
            break;
        case 'POCI':
            resources.push(miso);
            break;
        case 'PICO':
            resources.push(mosi);
            break;
    }

    if (inst.mode == "PERIPHERAL")
    {
        if (inst.frameFormat == "MOTO4" || inst.frameFormat == "TI_SYNC")
        {
            switch(inst.peripheralChipSelect) {
                case "0":
                    resources.push(cs0);
                    break;
                case "1":
                    resources.push(cs1);
                    break;
                case "2":
                    resources.push(cs2);
                    break;
                case "3":
                    resources.push(cs3);
                    break;
            }
        }
    }
    else if (inst.mode == "CONTROLLER") {
        if (inst.frameFormat == "MOTO4" || inst.frameFormat == "TI_SYNC") {
            if (inst.chipSelect.includes("0"))
            {
                resources.push(cs0);
            }
            if (inst.chipSelect.includes("1"))
            {
                resources.push(cs1);
            }
            if (inst.chipSelect.includes("2"))
            {
                resources.push(cs2);
            }
            if (inst.chipSelect.includes("3") && inst.enableCDMode == false)
            {
                resources.push(cs3);
            }
        }

        if (inst.enableCDMode == true) {
            resources.push(cs3);
        }
    }




    let spi = {
        name          : "peripheral",
        displayName   : "SPI Peripheral",
        interfaceName : "SPI",
        resources     : resources,
        signalTypes   : {
            sclkPin     : ['SPI_SCLK'],
            mosiPin     : ['SPI_MOSI'],
            misoPin     : ['SPI_MISO'],
            cs0Pin      : ['SPI_CS0'],
            cs1Pin      : ['SPI_CS1'],
            cs2Pin      : ['SPI_CS2'],
            cs3Pin      : ['SPI_CS3'],
        }
    };
    return [spi];
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
        if (Common.typeMatches(type, ["SPI"])) modulePin = sig;
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
