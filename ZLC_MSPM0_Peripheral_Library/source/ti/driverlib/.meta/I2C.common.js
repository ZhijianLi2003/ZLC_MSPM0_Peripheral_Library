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
 *  ======== I2C.common.js ========
 */

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

exports = {
    getBasicConfig      : getBasicConfig,
    getAdvancedConfig   : getAdvancedConfig,
    getDMAConfig        : getDMAConfig,
    getDMAModInstances  : getDMAModInstances,
    setRequiredModules  : setRequiredModules,
    getValidation       : getValidation,
    updateGUIbasedonConfig  : updateGUIbasedonConfig,
    onChangeintController   : onChangeintController,
    onChangeintTarget       : onChangeintTarget,
    onChangeintGeneric       : onChangeintGeneric,
    onChangeEnableTarget    : onChangeEnableTarget,
    onChangeEnableController: onChangeEnableController,
};
/************************* Config defines *******************************/
const DMAOptions = [
    { name: "None", displayName: "None", description: "No DMA trigger selected" },
    { name: "CONTROLLER_RXFIFO_TRIGGER", displayName: "Controller RX FIFO Trigger",
        description: "Controller receive FIFO trigger. Trigger when RX FIFO contains >= defined bytes" },
    { name: "CONTROLLER_TXFIFO_TRIGGER", displayName: "Controller TX FIFO Trigger",
        description: "Controller transmit FIFO trigger. Trigger when Transmit FIFO contains <= defined bytes" },
    { name: "TARGET_RXFIFO_TRIGGER", displayName: "Target RX FIFO Trigger",
        description: "Target receive FIFO trigger. Trigger when RX FIFO contains >= defined bytes" },
    { name: "TARGET_TXFIFO_TRIGGER", displayName: "Target TX FIFO Trigger",
        description: "Target transmit FIFO trigger. Trigger when Transmit FIFO contains <= defined bytes" },
];
/************************* Profiles functions *******************************/
/* Functions that update GUI based on Configuration */
function updateGUIEnableController(inst, ui)
{
    if (inst.basicEnableController == false)
    {
        ui.basicControllerStandardBusSpeed.hidden = true;
        ui.basicControllerBusSpeed.hidden = true;
        ui.basicControllerBusSpeedArray.hidden = true;
        ui.basicEnableController10BitAddress.hidden = true;
        ui.advControllerRXFIFOTRIG.hidden = true;
        ui.advControllerTXFIFOTRIG.hidden = true;
        ui.advControllerLoopback.hidden = true;
        ui.advControllerMultiController.hidden = true;
        ui.advControllerClkStretch.hidden = true;
        inst.intController = [];
        /* MSPM0Cxx does not support DMA configuration for I2C */
        if(!Common.isDeviceM0C()){
            if ((inst.DMAEvent1).includes("CONTROLLER"))
            {
                inst.DMAEvent1 = "None";
                inst.enableDMAEvent1 = false;
                ui.enableDMAEvent1.hidden = true;
            }
            if ((inst.DMAEvent2).includes("CONTROLLER"))
            {
                inst.DMAEvent2 = "None";
                inst.enableDMAEvent2 = false;
                ui.enableDMAEvent2.hidden = true;
            }
        }
    }
    else
    {
        ui.basicControllerStandardBusSpeed.hidden = false;
        ui.basicControllerBusSpeed.hidden = false;
        ui.basicControllerBusSpeedArray.hidden = false;
        ui.basicEnableController10BitAddress.hidden = false;
        ui.advControllerRXFIFOTRIG.hidden = false;
        ui.advControllerTXFIFOTRIG.hidden = false;
        ui.advControllerLoopback.hidden = false;
        ui.advControllerMultiController.hidden = false;
        ui.advControllerClkStretch.hidden = false;
    }
    updateGUIInterrupts(inst, ui);
}

function updateGUIEnableTarget(inst, ui) {
    if (inst.basicEnableTarget == false)
    {
        ui.basicEnableTarget10BitAddress.hidden = true;
        ui.basicTargetOwnAddressEnable.hidden = true;
        ui.basicTargetAddress.hidden = true;
        ui.basicTargetSecAddressEnable.hidden = true;
        ui.basicTargetSecAddress.hidden = true;
        ui.basicTargetGeneralCall.hidden = true;
        ui.advTargetRXFIFOTRIG.hidden = true;
        ui.advTargetTXFIFOTRIG.hidden = true;
        ui.advTargetAckOverride.hidden = true;
        ui.advTargetTXEmptyEn.hidden = true;
        ui.advTargetClkStretch.hidden = true;
        inst.intTarget = [];
        /* MSPM0Cxx does not support DMA configuration for I2C */
        if(!Common.isDeviceM0C()){
            if ((inst.DMAEvent1).includes("TARGET"))
            {
                inst.DMAEvent1 = "None";
                inst.enableDMAEvent1 = false;
                ui.enableDMAEvent1.hidden = true;
            }
            if ((inst.DMAEvent2).includes("TARGET"))
            {
                inst.DMAEvent2 = "None";
                inst.enableDMAEvent2 = false;
                ui.enableDMAEvent2.hidden = true;
            }
        }
    }
    else
    {
        ui.basicEnableTarget10BitAddress.hidden = false;
        ui.basicTargetOwnAddressEnable.hidden = false;
        if (inst.basicTargetOwnAddressEnable == true)
        {
            ui.basicTargetAddress.hidden = false;
        }
        ui.basicTargetSecAddressEnable.hidden = false;
        if (inst.basicTargetSecAddressEnable == true)
        {
            ui.basicTargetSecAddress.hidden = false;
        }
        ui.basicTargetGeneralCall.hidden = false;
        ui.advTargetRXFIFOTRIG.hidden = false;
        ui.advTargetTXFIFOTRIG.hidden = false;
        ui.advTargetAckOverride.hidden = false;
        ui.advTargetTXEmptyEn.hidden = false;
        ui.advTargetClkStretch.hidden = false;
    }
    updateGUIInterrupts(inst, ui);
}

function updateGUIbasicControllerStandardBusSpeed(inst, ui) {
    switch (inst.basicControllerStandardBusSpeed)
    {
        case "Standard":
            inst.basicControllerBusSpeed = 100000;
            break;
        case "Fast":
            inst.basicControllerBusSpeed = 400000;
            break;
        case "FastPlus":
            inst.basicControllerBusSpeed = 1000000;
                break;
    }
    updateGUIbasicControllerBusSpeed(inst, ui);
}

function updateGUIbasicControllerBusSpeed(inst, ui) {
    inst.basicControllerBusSpeedArray = 0;
}

function updateGUIEnableTargetOwnAddress(inst, ui) {
    if (ui.basicTargetOwnAddressEnable.hidden == false)
    {
        ui.basicTargetAddress.hidden = (inst.basicTargetOwnAddressEnable === false);
    }
}

function updateGUIEnableTargetSecAddress(inst, ui) {
    if (ui.basicTargetSecAddressEnable.hidden == false)
    {
        ui.basicTargetSecAddress.hidden = (inst.basicTargetSecAddressEnable === false);
    }
}

function updateGUIInterrupts(inst, ui)
{
    ui.interruptPriority.hidden = !(inst.basicEnableController && inst.intController.length !== 0) &&
                                  !(inst.basicEnableTarget && inst.intTarget.length !== 0) &&
                                  !((inst.enableTimeoutA || inst.enableTimeoutB) && inst.intGeneric.length !== 0);
}

function updateGUIbasedonConfig(inst, ui)
{
    updateGUIEnableController(inst, ui);
    updateGUIbasicControllerStandardBusSpeed(inst, ui);
    updateGUIEnableTarget(inst, ui);
    updateGUIEnableTargetOwnAddress(inst,ui);
    updateGUIEnableTargetSecAddress(inst,ui);
    updateGUIInterrupts(inst, ui);
}

/************************Interrupt Functions **********************************/
/* OnChange functions for Interrupts */
function onChangeintController(inst, ui)
{
    updateGUIInterrupts(inst, ui);
    onChangeSetCustomProfile(inst, ui);
}

function onChangeintTarget(inst, ui)
{
    updateGUIInterrupts(inst, ui);
    onChangeSetCustomProfile(inst, ui);
}

function onChangeintGeneric(inst, ui)
{
    updateGUIInterrupts(inst, ui);
    onChangeSetCustomProfile(inst, ui);
}

/************************* General functions **********************************/
/*
 *  ======== getI2CClockSourceFreq ========
 *  Get the I2C Clock source frequency in Hz
 *
 */
function getI2CClockSourceFreq(inst) {
    var i2CClockFreq = 0;
    /* I2C has 2 sources:
        BUSCLK = MCLK in PD1, ULPCLK in PD0
        MFCLK
    */
   switch (inst.basicClockSource){
       case "BUSCLK":
            i2CClockFreq = Common.getBUSCLKFreq(inst, "I2C");
        break;
        case "MFCLK":
            i2CClockFreq = system.modules["/ti/driverlib/SYSCTL"].$static.MFCLK_Freq;
        break;
   }
   i2CClockFreq = i2CClockFreq / inst.basicClockSourceDivider;

   return i2CClockFreq;
}

/* onChange functions for general parameterts */
function onChangebasicClockSource(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangebasicClockSourceDivider(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}
function onChangeadvAnalogGlitchFilter(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeadvDigitalGlitchFilter(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeSetCustomProfile(inst,ui){
    inst.profile = "CUSTOM";
}

/************************* Controller functions *******************************/
/* onChange functions for Controller - Basic */
function onChangeEnableController(inst, ui) {
    updateGUIEnableController(inst, ui);
    onChangeSetCustomProfile(inst, ui);
}

function onChangebasicControllerStandardBusSpeed(inst, ui)
{
    updateGUIbasicControllerStandardBusSpeed(inst, ui);
    onChangeSetCustomProfile(inst, ui);
}

function onChangebasicControllerBusSpeed(inst, ui)
{
    updateGUIbasicControllerBusSpeed(inst, ui);
    onChangeSetCustomProfile(inst, ui);
}

/* onChange functions for Controller - Advanced */
function onChangeadvControllerRXFIFOTRIG(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeadvControllerTXFIFOTRIG(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeadvControllerLoopback(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeadvControllerMultiController(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeadvControllerClkStretch(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

/* Controller APIs for calculations */
function getValueI2CBusSpeedCalc(inst) {
    let sourceClkFreq;
    let controllerTPR;

    sourceClkFreq = getI2CClockSourceFreq(inst);

    if ((inst.basicControllerBusSpeed * 10) > sourceClkFreq)
    {
        return 0;   // Invalid frequency, can't be achieved with TPR < 0
    }
    else if (inst.basicControllerBusSpeed < (sourceClkFreq/(10*128)))
    {
        return 0;   // Invalid frequency, can't be achieved with TPR > 128
    }
    else
    {
        controllerTPR = Math.ceil (sourceClkFreq / (inst.basicControllerBusSpeed * 10)) - 1;
        sourceClkFreq = sourceClkFreq / (10 * (1 + controllerTPR));
        return sourceClkFreq;
    }
}

function getClosestI2CTPR(inst)
{
    var sourceClkFreq;

    sourceClkFreq = getI2CClockSourceFreq(inst);

    if ((inst.basicControllerBusSpeed * 10) > sourceClkFreq)
    {
        return 0;   // Invalid frequency
    }
    else if (inst.basicControllerBusSpeed < (sourceClkFreq/(10*128)))
    {
        return 0;   // Invalid frequency, can't be achieved with TPR > 128
    }
    else
    {
        return (Math.ceil (sourceClkFreq / (inst.basicControllerBusSpeed * 10)) - 1);
    }
}

function getArrayI2CBusSpeedCalc(inst) {
    var sourceClkFreq;
    var calcI2cFreq;
    var tpr;
    let freqArray = [];

    sourceClkFreq = getI2CClockSourceFreq(inst);

    tpr = getClosestI2CTPR(inst);

    if (tpr == 0)
    {
        return freqArray;   // Invalid settings
    }
    else
    {
        calcI2cFreq = sourceClkFreq / (10 * (1 + tpr));
        freqArray.push({name: 0, displayName: calcI2cFreq.toFixed(2)});
        if (tpr > 0)
        {
            calcI2cFreq = sourceClkFreq / (10 * (1 + (tpr-1)));
            freqArray.push({name: -1, displayName: calcI2cFreq.toFixed(2)});
        }
        if (tpr > 1)
        {
            calcI2cFreq = sourceClkFreq / (10 * (1 + (tpr-2)));
            freqArray.push({name: -2, displayName: calcI2cFreq.toFixed(2)});
        }
        if (tpr < 127)
        {
            calcI2cFreq = sourceClkFreq / (10 * (1 + (tpr+1)));
            freqArray.push({name: 1, displayName: calcI2cFreq.toFixed(2)});
        }
        if (tpr < 126)
        {
            calcI2cFreq = sourceClkFreq / (10 * (1 + (tpr+2)));
            freqArray.push({name: 2, displayName: calcI2cFreq.toFixed(2)});
        }
        return freqArray;
    }
}

function getValueI2CBusSpeedSelection(inst){
    var sourceClkFreq;
    var calcI2cFreq;
    var tpr;

    sourceClkFreq = getI2CClockSourceFreq(inst);

    tpr = getClosestI2CTPR(inst);

    if (tpr == 0)
    {
        return 0;   // Invalid settings
    }
    else
    {
        tpr += inst.basicControllerBusSpeedArray;
        calcI2cFreq = sourceClkFreq / (10 * (1 + tpr));
        return calcI2cFreq;
    }
}

function getValueI2CBusSpeedTPR(inst)
{
    var sourceClkFreq;
    var tpr;

    sourceClkFreq = getI2CClockSourceFreq(inst);

    tpr = getClosestI2CTPR(inst);

    if (tpr == 0)
    {
        return 0;   // Invalid settings
    }
    else
    {
        tpr += inst.basicControllerBusSpeedArray;
        return tpr;
    }
}

/************************* Target functions ***********************************/
/* onChange functions for Target - Basic */
function onChangeEnableTarget(inst, ui) {
    updateGUIEnableTarget(inst, ui);
    updateGUIEnableTargetOwnAddress(inst,ui);
    updateGUIEnableTargetSecAddress(inst, ui);
    onChangeSetCustomProfile(inst, ui);
}

function onChangebasicTargetOwnAddressEnable(inst, ui)
{
    updateGUIEnableTargetOwnAddress(inst, ui);
    onChangeSetCustomProfile(inst, ui);
}

function onChangebasicTargetAddress(inst, ui)
{
    updateGUIEnableTargetSecAddress(inst, ui);
    onChangeSetCustomProfile(inst, ui);
}

function onChangebasicTargetSecAddressEnable(inst, ui)
{
    updateGUIEnableTargetSecAddress(inst, ui);
    onChangeSetCustomProfile(inst, ui);
}

function onChangebasicTargetSecAddress(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangebasicTargetGeneralCall(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

/* onChange functions for Target - Advanced */
function onChangeadvTargetRXFIFOTRIG(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeadvTargetTXFIFOTRIG(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeadvTargetAckOverride(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

/* Target calculations  */
function getValueI2CdigitalGlitchFilterCalc(inst) {
    let sourceClkFreq;
    let filterTimeNs;

    sourceClkFreq = getI2CClockSourceFreq(inst);

    switch (inst.advDigitalGlitchFilter)
    {
        case "1":
            filterTimeNs = (1)/sourceClkFreq;
        break;
        case "2":
            filterTimeNs = (2)/sourceClkFreq;
        break;
        case "3":
            filterTimeNs = (3)/sourceClkFreq;
        break;
        case "4":
            filterTimeNs = (4)/sourceClkFreq;
        break;
        case "8":
            filterTimeNs = (8)/sourceClkFreq;
        break;
        case "16":
            filterTimeNs = (16)/sourceClkFreq;
        break;
        case "31":
            filterTimeNs = (31)/sourceClkFreq;
        break;
        case "DISABLED":
        default:
            filterTimeNs = 0;
    }

    return filterTimeNs;
}

/************************ DMA Functions **********************************/
/* OnChange functions for DMA */
function onChangeDMAEvent1(inst, ui)
{
    ui.enableDMAEvent1.hidden = (inst.DMAEvent1 == "None");
    onChangeSetCustomProfile(inst, ui);
}

function onChangeDMAEvent2(inst, ui)
{
    ui.enableDMAEvent2.hidden = (inst.DMAEvent2 == "None");
    onChangeSetCustomProfile(inst, ui);
}

/* Functions to get Options for DMA */

function getDMADisabledOptions(inst) {
    let disabledOptions = [];
    if (!inst.basicEnableController)
    {
        disabledOptions.push({ name: "CONTROLLER_RXFIFO_TRIGGER", reason: "Controller not enabled" });
        disabledOptions.push({ name: "CONTROLLER_TXFIFO_TRIGGER", reason: "Controller not enabled" });
    }
    if (!inst.basicEnableTarget)
    {
        disabledOptions.push({ name: "TARGET_RXFIFO_TRIGGER", reason: "Target not enabled" });
        disabledOptions.push({ name: "TARGET_TXFIFO_TRIGGER", reason: "Target not enabled" });
    }
    return disabledOptions;
}

/************************* Config functionss *******************************/
function getBasicConfig(inst,ui){
    return [
            {
                name: "GROUP_BASIC_CLOCK_CONFIG",
                displayName: "Clock Configuration",
                description: "",
                collapsed: true,
                config: [
                    {
                        name        : "basicClockSource",
                        displayName : "Clock Source",
                        description : "Specifies the clock source for the I2C peripheral",
                        longDescription:`
The I2C clock can be sourced from:\n
* MFCLK, or
* BUSCLK, which depends on the power domain:
    * If the I2C is in PD1, BUSCLK is derived from MCLK, or,
    * If the I2C is in PD0, BUSCLK is derived from ULPCLK.\n
The frequency of the clock sources are configured
in the __SYSCTL Module__. `,
                        default     : "BUSCLK",
                        options     : [
                            {name: "BUSCLK"},
                            {name: "MFCLK"}
                        ],
                        onChange    : onChangebasicClockSource
                    },
                    {
                        name        : "basicClockSourceDivider",
                        displayName : "Clock Source Divider",
                        description: "Selects the I2C module clock divide ratio",
                        default: 1,
                        options: [
                            { name: 1, displayName: "Divide By 1"},
                            { name: 2, displayName: "Divide by 2"},
                            { name: 3, displayName: "Divide by 3"},
                            { name: 4, displayName: "Divide by 4"},
                            { name: 5, displayName: "Divide by 5"},
                            { name: 6, displayName: "Divide by 6"},
                            { name: 7, displayName: "Divide by 7"},
                            { name: 8, displayName: "Divide by 8"}
                        ],
                        onChange    : onChangebasicClockSourceDivider
                    },
                    {
                        name        : "basicClockSourceCalculated",
                        displayName : "Calculated Clock Source",
                        description : 'Calculated I2C Clock Source in Hz',
                        hidden      : false,
                        getValue    : (inst) => getI2CClockSourceFreq(inst),
                        default     : 0
                    },
                ],
            },
            /****** Start of CONTROLLER BASIC CONFIGURATION *******/
            {
                name: "basicControllerConfig",
                displayName: "I2C Controller Basic Configuration",
                longDescription: "",
                collapsed: false,
                config: [
                    {
                        name        : "basicControllerStandardBusSpeed",
                        displayName : "Standard Bus Speed",
                        description : 'I2C Standard Bus Speed',
                        longDescription: `
This I2C module supports:
* Standard speed (100kHz),
* Fast Mode (400kHz), and
* Fast Mode Plus (1Mbps).\n
However, the bitrate will depend on the module's clock source and the
calculated dividers.\n
Note that the actual bus frequency will depend on bus capacitance and loading.`,
                        hidden      : true,
                        default     : "Standard",
                        options     : [
                            {name: "Standard", displayName: "Standard (100kHz)"},
                            {name: "Fast", displayName: "Fast Mode (400kHz)"},
                            {name: "FastPlus", displayName: "Fast Mode Plus (1MHz)"},
                        ],
                        onChange    : onChangebasicControllerStandardBusSpeed
                    },
                    {
                        name        : "basicControllerBusSpeed",
                        displayName : "Custom Bus Speed (Hz)",
                        description : 'I2C Bus Speed in Hz',
                        longDescription: `
This option allows to configure a custom frequency if desired. \n
The frequency will be adjusted to the closest value without exceeding the
specified bus speed.\n
Note that the actual bus frequency will depend on bus capacitance and loading.`,
                        hidden      : true,
                        default     : 100000,
                        onChange    : onChangebasicControllerBusSpeed
                    },
                    {
                        name        : "basicControllerBusSpeedArray",
                        displayName : "Actual Bus Speed (Hz)",
                        description : 'Actual I2C Bus Speed in Hz',
                        longDescription: `
This setting shows the closest bus speeds based on the desired setting.\n
The frequency will be adjusted to the closest value without exceeding the
specified bus speed.
The next available options are shown in drop-down for convenience purposes
and can be selected if needed.\n
**A warning will be shown if the calculated bus speed differs from desired
setting. Adjust the clock source or bus frequency if needed.** \n
The frequency period is calculated as:\n
        SCL_FREQ = INT_CLK_FREQ / ( (1+TPR) x (SCL_LP + SCL_HP) ), where:\n
            SCL_FREQ = Desired I2C frequency\n
            INT_CLK_FREQ = BUSCLK (MCLK if in PD1, or ULPCLK if in PD0) or MFCLK\n
            SCL_LP = 6\n
            SCL_HP = 4\n
            TPR = INT_CLK_FREQ/(SCL_FREQ x 10) - 1 \n
        I.e.\n
            If SCL_FREQ = 100kHz and INT_CLK_FREQ = 32MHz\n
            TPR = ceil(32MHz/(100kHz x 10)) - 1 = 31\n
`,
                        hidden      : true,
                        options     : (inst) => getArrayI2CBusSpeedCalc(inst),
                        default     : 0
                    },
                    {
                        name        : "basicControllerBusSpeedSelected",
                        displayName : "Selected Bus Speed (Hz)",
                        description : 'Only for internal purposes',
                        hidden      : true,
                        getValue    : (inst) => getValueI2CBusSpeedSelection(inst),
                        default     : 0
                    },
                    {
                        name        : "basicControllerBusSpeedTPR",
                        displayName : "Selected TPR",
                        description : "Only for Internal purposes",
                        hidden      : true,
                        getValue    : (inst) => getValueI2CBusSpeedTPR(inst),
                        default     : 0
                    },
                    {
                        name        : "basicEnableController10BitAddress",
                        displayName : "Enable 10-bit Addressing Mode",
                        description : 'Enables 10-bit addressing mode.',
                        longDescription: `
The target to communicate with should use a 10-bit address.\n
Targets using a 7-bit address will ignore any 10-bit addresses.
`,
                        hidden      : true,
                        default     : false,
                        onChange    : onChangeSetCustomProfile,
                    },
                ]
            }, /****** End  of CONTROLLER BASIC CONFIGURATION *******/
            /****** Start of TARGET BASIC CONFIGURATION *******/
            {
                name: "basicTargetConfig",
                displayName: "I2C Target Configuration",
                longDescription: "",
                collapsed: false,
                config: [
                    {
                        name        : "basicEnableTarget10BitAddress",
                        displayName : "Enable 10-bit Addressing Mode",
                        description : 'Enables 10-bit addressing mode.',
                        longDescription: `
The controller to communicate with should use 10-bit addresses.
`,
                        hidden      : true,
                        default     : false,
                        onChange    : onChangeSetCustomProfile,
                    },
                    {
                        name        : "basicTargetOwnAddressEnable",
                        displayName : "Enable Target's Own Address",
                        description : `The target's own address is usually enabled
                        but it can be optionally disabled.`,
                        hidden      : true,
                        default     : true,
                        onChange    : onChangebasicTargetOwnAddressEnable
                    },
                    {
                        name        : "basicTargetAddress",
                        displayName : "Target's Own Address",
                        description : `The device will respond to this address.
                                    Use 7-bit address without R/W bit.`,
                        longDescription: `
The target address must be defined without R/W bit in either:\n
* 7-bit format
* 10-bit format
The developer should define a valid address ensuring no conflicts.\n
Per I2C spec, the following addresses are reserved:\n
* 000 0000: General call address,
* 000 0001: CBUS address,
* 000 0010: Reserved for different bus format,
* 000 0011: Reserved for future purposes,
* 000 01xx: Hs-mode controller code,
* 111 11xx: Device ID,
* 111 10xx: 10-bit target addressing
`,
                        hidden      : true,
                        displayFormat: "hex",
                        isInteger   : true,
                        default     : 0x10,
                        onChange    : onChangebasicTargetAddress
                    },
                    {
                        name        : "basicTargetSecAddressEnable",
                        displayName : "Enable Target's Secondary Address",
                        description : `The secondary address is optional and allows
                        the device to respond to a different address.`,
                        hidden      : true,
                        default     : false,
                        onChange    : onChangebasicTargetSecAddressEnable
                    },
                    {
                        name        : "basicTargetSecAddress",
                        displayName : "Target's Secondary Own Address",
                        description : `The device will respond to this address.
                                    Use 7-bit address without R/W bit.`,
                        longDescription:`
The secondary address is optional.\n
The target address must be defined without R/W bit in either:\n
* 7-bit format
* 10-bit format
The developer should define a valid address ensuring no conflicts.\n
Per I2C spec, the following addresses are reserved:\n
* 000 0000: General call address,
* 000 0001: CBUS address,
* 000 0010: Reserved for different bus format,
* 000 0011: Reserved for future purposes,
* 000 01xx: Hs-mode controller code,
* 111 11xx: Device ID,
* 111 10xx: 10-bit target addressing
`,
                        hidden      : true,
                        displayFormat: "hex",
                        isInteger   : true,
                        default     : 0x11,
                        onChange    : onChangebasicTargetSecAddress
                    },
                    {
                        name        : "basicTargetGeneralCall",
                        displayName : "Enable General Call Response",
                        description : `Enables/Disables the target
                        functionality to respond to a General Call`,
                        longDescription:`
The General Call address is defined as 0x00 in I2C specification; however,
responding to the General Call is optional.\n
This feature is used to address every device on the I2C bus at the same time
but a target can choose to ignore it.\n
Otherwise, if this feature is enabled, the target will acknowledge the call
and will behave as a receiver.
`,
                        hidden      : true,
                        default     : false,
                        onChange    : onChangebasicTargetGeneralCall
                    },
                ]
            }, /****** End of TARGET BASIC CONFIGURATION *******/
    ];
}

function getAdvancedConfig(inst,ui){
    return [
            {
                name        : "advEnableAfterInit",
                displayName : "Enable I2C After Initialization",
                description : `Enables the I2C module after initialization`,
                longDescription:`
The I2C peripheral must be enabled in the application if left disabled after
initialization.`,
                default     : true,
            },
            {
                name        : "advAnalogGlitchFilter",
                displayName : "Analog Glitch Filter",
                description : `Enables and configures the analog filter`,
                longDescription:`
The analog filter is optional.\n
By default the analog filter is enabled and configured to suppress spikes with
a pulse width up to 50ns.\n
When disabled, the input signal will be passed to the I2C module without
filtering.\n
The analog filter has variation over temperature and voltage.
Please see datasheet for more information.\n
The analog filter can be used to wake-up the I2C module from low-power mode.`,
                default     : "50",
                options     : [
                    {name: "DISABLED",  displayName: "Disabled"},
                    {name: "5",         displayName: "Filter pulses < 5ns"},
                    {name: "10",        displayName: "Filter pulses < 10ns"},
                    {name: "25",        displayName: "Filter pulses < 25ns"},
                    {name: "50",        displayName: "Filter pulses < 50ns"}
                ],
                onChange    : onChangeadvAnalogGlitchFilter
            },
            {
                name        : "advDigitalGlitchFilter",
                displayName : "Digital Glitch Filter",
                description : `Enables and configures the digital filter`,
                longDescription:`
The digital filter is optional and it's bypassed by default.\n
This filter is based on the functional clock and provides a stable filtering
length; however, it's not available to wake-up the device from low-power mode.`,
                default     : "DISABLED",
                options     : [
                    {name: "DISABLED",  displayName: "Disabled"},
                    {name: "CLOCKS_1",         displayName: "1 clock"},
                    {name: "CLOCKS_2",         displayName: "2 clocks"},
                    {name: "CLOCKS_3",         displayName: "3 clocks"},
                    {name: "CLOCKS_4",         displayName: "4 clocks"},
                    {name: "CLOCKS_8",         displayName: "8 clocks"},
                    {name: "CLOCKS_16",        displayName: "16 clocks"},
                    {name: "CLOCKS_31",        displayName: "31 clocks"}
                ],
                onChange    : onChangeadvDigitalGlitchFilter
            },
            {
                name        : "advDigitalGlitchFilterCalc",
                displayName : "Calculated Digital Glitch Filter",
                description : 'Calculated digital glitch filter',
                hidden      : false,
                default     : "0 s",
                getValue    : (inst) => (Common.getUnitPrefix((getValueI2CdigitalGlitchFilterCalc(inst))).str+'s'),
            },
            /****** Start of CONTROLLER ADVANCED CONFIGURATION *******/
            {
                name: "advControllerConfig",
                displayName: "I2C Controller Advanced Configuration",
                longDescription: "",
                collapsed: false,
                config: [
                    {
                        name        : "advControllerRXFIFOTRIG",
                        displayName : "RX FIFO Trigger Level",
                        description : 'Indicates at what fill level the RX \
                        FIFO trigger will be generated',
                        hidden      : true,
                        default     : "BYTES_1",
                        options     : [
                            {name: "BYTES_1", displayName: "RX FIFO contains >= 1 bytes"},
                            {name: "BYTES_2", displayName: "RX FIFO contains >= 2 bytes"},
                            {name: "BYTES_3", displayName: "RX FIFO contains >= 3 bytes"},
                            {name: "BYTES_4", displayName: "RX FIFO contains >= 4 bytes"},
                            {name: "BYTES_5", displayName: "RX FIFO contains >= 5 bytes"},
                            {name: "BYTES_6", displayName: "RX FIFO contains >= 6 bytes"},
                            {name: "BYTES_7", displayName: "RX FIFO contains >= 7 bytes"},
                            {name: "BYTES_8", displayName: "RX FIFO contains >= 8 bytes"},
                        ],
                        onChange    : onChangeadvControllerRXFIFOTRIG
                    },
                    {
                        name        : "advControllerTXFIFOTRIG",
                        displayName : "TX FIFO Trigger Level",
                        description : 'Indicates at what fill level the TX \
                        FIFO trigger will be generated',
                        hidden      : true,
                        default     : "EMPTY",
                        options     : [
                            {name: "EMPTY", displayName: "TX FIFO contains <= 0 bytes"},
                            {name: "BYTES_1", displayName: "TX FIFO contains <= 1 bytes"},
                            {name: "BYTES_2", displayName: "TX FIFO contains <= 2 bytes"},
                            {name: "BYTES_3", displayName: "TX FIFO contains <= 3 bytes"},
                            {name: "BYTES_4", displayName: "TX FIFO contains <= 4 bytes"},
                            {name: "BYTES_5", displayName: "TX FIFO contains <= 5 bytes"},
                            {name: "BYTES_6", displayName: "TX FIFO contains <= 6 bytes"},
                            {name: "BYTES_7", displayName: "TX FIFO contains <= 7 bytes"},
                        ],
                        onChange    : onChangeadvControllerTXFIFOTRIG
                    },
                    {
                        name        : "advControllerLoopback",
                        displayName : "Enable Loopback Mode",
                        description : 'Enable internal loopback mode',
                        longDescription: `
The I2C module can be placed into an internal loopback mode for diagnostic or
debug.\n
In loopback mode, the SDA and SCL signals from the controller part of the I2C
are tied to the SDA and SCL signals of the target part of the I2C module to
allow internal testing of the device without having to go through I/O.
    `,
                        hidden      : true,
                        default     : false,
                        onChange    : onChangeadvControllerLoopback
                    },
                    {
                        name        : "advControllerMultiController",
                        displayName : "Enable Multi-Controller Mode",
                        description : 'Enables/disables multi-controller mode',
                        longDescription: `
Enable to be compliant with I2C specification when multiple controllers are
present. \n
During the arbitration procedure, the clocks from the different controllers
must be synchronized. A device that first generates a low period on SCL
overrules the other devices, forcing them to start their own low periods.
SCL is then held low by the device with the longest low period.
The other devices must wait for SCL to be released before starting their
high periods.\n
In multi-controller configuration, the clock synchronization during the
arbitration is enabled, the SCL high time counts once the SCL line has been
detected high. If not enabled the high time counts as soon as the SCL line
has been set high by the I2C module which allows the I2C to reach the maximum
speed.`,
                        hidden      : true,
                        default     : false,
                        onChange    : onChangeadvControllerMultiController
                    },
                    {
                        name        : "advControllerClkStretch",
                        displayName : "Enable Controller Clock Stretching",
                        description : 'Enables/disables support for clock \
                        stretching in Controller mode.',
                        longDescription: `
Enable to be compliant with I2C specification.
Disable to reach maximum speed if no I2C target on the bus supports clock
stretching.`,
                        hidden      : true,
                        default     : true,
                        onChange    : onChangeadvControllerClkStretch
                    },
                    {
                        name: "i2cTimeout",
                        displayName: "Additional Timeout Configuration",
                        longDescription:
                ``,
                        collapsed: false,
                        config: [
                            // DL_I2C_enableTimeoutA / DL_I2C_disableTimeoutA
                            // TODO: [(H) JAN] there is also some interrupts enabled by this choice
                            {
                                name: "enableTimeoutA",
                                displayName: "Enable Timeout Counter A",
                                default: false,
                                onChange: (inst,ui)=> {
                                    ui.timeoutACount.hidden = !inst.enableTimeoutA;
                                    // ui.timeoutACountCalc.hidden = !inst.enableTimeoutA;
                                }
                            },
                            // DL_I2C_setTimeoutACount
                            {
                                name: "timeoutACount",
                                displayName: "Set the Timeout Counter A value",
                                default: 0,
                                isInteger: true,
                                range: [0x0,0xFF],
                                hidden: true,
                            },
                            // TODO: [JAN/27 (H)] Removing/hiding calculated timeout for now while we clarify values
                            // {
                            //     name: "timeoutACountCalc",
                            //     displayName: "Calculated Timeout A",
                            //     default: "0s",
                            //     hidden: true,
                            //     getValue: (inst)=>{
                            //         let calcVal = (1/(inst.basicClockSourceCalculated * inst.basicClockSourceDivider))*520*inst.timeoutACount;
                            //         calcVal = (Common.getUnitPrefix(calcVal).str+'s')
                            //         return calcVal;
                            //     },
                            // },
                            // DL_I2C_enableTimeoutB / DL_I2C_disableTimeoutB
                            // TODO: [(H) JAN] there is also some interrupts enabled by this choice
                            {
                                name: "enableTimeoutB",
                                displayName: "Enable Timeout Counter B",
                                default: false,
                                onChange: (inst,ui)=> {
                                    ui.timeoutBCount.hidden = !inst.enableTimeoutB;
                                    // ui.timeoutBCountCalc.hidden = !inst.enableTimeoutB;
                                }
                            },
                            // DL_I2C_setTimeoutBCount
                            {
                                name: "timeoutBCount",
                                displayName: "Set the Timeout Counter B value",
                                default: 0,
                                isInteger: true,
                                range: [0x0,0xFF],
                                hidden: true,
                            },
                            // {
                            //     name: "timeoutBCountCalc",
                            //     displayName: "Calculated Timeout B",
                            //     default: "0s",
                            //     hidden: true,
                            //     getValue: (inst)=>{
                            //         let calcVal = (1/(inst.basicClockSourceCalculated * inst.basicClockSourceDivider))*520*inst.timeoutBCount;
                            //         calcVal = (Common.getUnitPrefix(calcVal).str+'s')
                            //         return calcVal;
                            //     },
                            // },
                        ],
                    },
                ]
            }, /****** End of CONTROLLER ADVANCED CONFIGURATION *******/
            /****** Start of TARGET ADVANCED CONFIGURATION *******/
            {
                name: "advTargetConfig",
                displayName: "I2C Target Advanced Configuration",
                longDescription: "",
                collapsed: false,
                config: [
                    {
                        name        : "advTargetRXFIFOTRIG",
                        displayName : "RX FIFO Trigger Level",
                        description : 'Indicates at what fill level the RX \
                        FIFO trigger will be generated',
                        hidden      : true,
                        default     : "BYTES_1",
                        options     : [
                            {name: "BYTES_1", displayName: "RX FIFO contains >= 1 bytes"},
                            {name: "BYTES_2", displayName: "RX FIFO contains >= 2 bytes"},
                            {name: "BYTES_3", displayName: "RX FIFO contains >= 3 bytes"},
                            {name: "BYTES_4", displayName: "RX FIFO contains >= 4 bytes"},
                            {name: "BYTES_5", displayName: "RX FIFO contains >= 5 bytes"},
                            {name: "BYTES_6", displayName: "RX FIFO contains >= 6 bytes"},
                            {name: "BYTES_7", displayName: "RX FIFO contains >= 7 bytes"},
                            {name: "BYTES_8", displayName: "RX FIFO contains >= 8 bytes"},
                        ],
                        onChange    : onChangeadvTargetRXFIFOTRIG
                    },
                    {
                        name        : "advTargetTXFIFOTRIG",
                        displayName : "TX FIFO Trigger Level",
                        description : 'Indicates at what fill level the TX \
                        FIFO trigger will be generated',
                        hidden      : true,
                        default     : "EMPTY",
                        options     : [
                            {name: "EMPTY",   displayName: "TX FIFO contains <= 0 bytes"},
                            {name: "BYTES_1", displayName: "TX FIFO contains <= 1 bytes"},
                            {name: "BYTES_2", displayName: "TX FIFO contains <= 2 bytes"},
                            {name: "BYTES_3", displayName: "TX FIFO contains <= 3 bytes"},
                            {name: "BYTES_4", displayName: "TX FIFO contains <= 4 bytes"},
                            {name: "BYTES_5", displayName: "TX FIFO contains <= 5 bytes"},
                            {name: "BYTES_6", displayName: "TX FIFO contains <= 6 bytes"},
                            {name: "BYTES_7", displayName: "TX FIFO contains <= 7 bytes"},
                        ],
                        onChange    : onChangeadvTargetTXFIFOTRIG
                    },
                    {
                        name        : "advTargetAckOverride",
                        displayName : "Enable ACK Override",
                        description : 'Enable Target Acknowledge override',
                        longDescription: `
When disabled, the I2C target module will acknowledge (ACK) received commands
and data automatically allowing for a more efficient use of the FIFO and faster
throughput.\n
When enabled, the I2C module will require setting ACKOVAL to either ACK or NACK
each received byte. This allows for a more reliable checking of data and
compliance with SMBus which requests NACKing on an invalid command or data.
    `,
                        hidden      : true,
                        default     : false,
                        onChange    : onChangeadvTargetAckOverride
                    },
                    {
                        name            : "advTargetTXEmptyEn",
                        displayName     : "Enable Target TX Empty Interrupt",
                        description     : "Enable Target TX empty interrupt on transmit request",
                        longDescription : `
When enabled, the Target's TXEMPTY event will be set when the state machine is
in the TX_WAIT state which occurs when the TX FIFO is empty AND the I2C
transaction is clock stretched waiting for the FIFO to be filled. When disabled,
 the event will be set simply by having an empty TX FIFO.`,
                        default         : false,
                        hidden          : true,
                        onChange        : onChangeSetCustomProfile,
                    },
                    {
                        name        : "advTargetClkStretch",
                        displayName : "Enable Target Clock Stretching",
                        description : 'Enables/disables support for clock \
                        stretching in Target mode.',
                        longDescription: `
Enable to be compliant with I2C specification.
When enabled, the SCL will be stretched when data must be read or written from the
FIFO.\n
It can optionally be disabled if a controller does not support it or
to achieve maximum I2C frequency; however the developer should ensure that
the FIFO is written or read on time.
`,
                        hidden      : true,
                        default     : true,
                        onChange    : onChangeSetCustomProfile,
                    },
                ]
            }, /****** End of TARGET ADVANCED CONFIGURATION *******/
    ];
}

function getDMAConfig(inst,ui){
    // I2C does not support DMA for MSPM0Cxx
    if(Common.isDeviceM0C()){
        return [];
    }
    return [
            /****** Start of DMA CONFIGURATION FOR INT_EVENT1 *******/
            {
                name: "DMAEvent1",
                displayName: "Configure DMA Event 1 Trigger",
                description: "Configure DMA triggers for INT_EVENT1",
                longDescription: `Configure DMA triggers for INT_EVENT1`,
                default: "None",
                options: DMAOptions,
                getDisabledOptions: getDMADisabledOptions,
                onChange    : onChangeDMAEvent1
            },
            {
                name        : "enableDMAEvent1",
                displayName : "Enable DMA Event 1 Trigger",
                longDescription: `If left unchecked, the module-specific enable
                DMA API should be called in the application code.`,
                hidden      : true,
                default     : true,
                onChange    : onChangeSetCustomProfile,
            },
            {
                name: "DMAEvent2",
                displayName: "Configure DMA Event 2 Trigger",
                description: "Configure DMA triggers for INT_EVENT2",
                longDescription: `Configure DMA triggers for INT_EVENT2`,
                default: "None",
                options: DMAOptions,
                getDisabledOptions: getDMADisabledOptions,
                onChange    : onChangeDMAEvent2
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
    ];
}

/************************* devSpecific functions *******************************/
function getDMAModInstances(inst, modInstances){
    /* I2C does not support DMA configuration for MSPM0Cxx */
    if(!Common.isDeviceM0C()){
    if(!["None"].includes(inst.DMAEvent1)){
        let triggerType;
        if(inst.DMAEvent1 == "CONTROLLER_TXFIFO_TRIGGER" || inst.DMAEvent1 == "TARGET_TXFIFO_TRIGGER") {
            triggerType = 0;
        }
        else if(inst.DMAEvent1 == "CONTROLLER_RXFIFO_TRIGGER" || inst.DMAEvent1 == "TARGET_RXFIFO_TRIGGER") {
            triggerType = 1;
        }

        let mod = {
            name: "DMA_CHANNEL_EVENT1",
            displayName: "DMA Channel Event 1",
            moduleName: '/ti/driverlib/DMAChannel',
            group: "GROUP_DMA",
            args: {

            },
            requiredArgs: {
                hideTriggerSelect: true,
                passedTriggerSelect: triggerType,
            },

        }
        modInstances.push(mod);
    }
    if(!["None"].includes(inst.DMAEvent2)){
        let triggerType;
        if(inst.DMAEvent2 == "CONTROLLER_TXFIFO_TRIGGER" || inst.DMAEvent2 == "TARGET_TXFIFO_TRIGGER") {
            triggerType = 0;
        }
        else if(inst.DMAEvent2 == "CONTROLLER_RXFIFO_TRIGGER" || inst.DMAEvent2 == "TARGET_RXFIFO_TRIGGER") {
            triggerType = 1;
        }
        let mod = {
            name: "DMA_CHANNEL_EVENT2",
            displayName: "DMA Channel Event 2",
            moduleName: '/ti/driverlib/DMAChannel',
            group: "GROUP_DMA",
            args: {

            },
            requiredArgs: {
                hideTriggerSelect: true,
                passedTriggerSelect: triggerType,
            },

        }
        modInstances.push(mod);
    }
    }
}

function setRequiredModules(inst){
    let theModules = ["Board", "SYSCTL"]
    /* I2C does not support DMA configuration for MSPM0Cxx */
    if(!Common.isDeviceM0C()){
        if(!["None"].includes(inst.DMAEvent1) || !["None"].includes(inst.DMAEvent2)){
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
}

function getValidation(inst, validation){
    if (inst.basicClockSource == "BUSCLK"){
        // Todo validate BUSCLK based on PD1/PD0
    }
    else if (inst.basicClockSource == "MFCLK"){
        if(system.modules["/ti/driverlib/SYSCTL"].$static.MFCLKEn != true){
            Common.logError(validation, inst,
                            "basicClockSource",
                            "MFCLK not initialized in SYSCTL");
        }
    }
    if (inst.basicEnableTarget == true)
    {
        if (inst.basicEnableTarget10BitAddress == false) {
            if (inst.basicTargetOwnAddressEnable && inst.basicTargetAddress > 0x7F) {
                Common.logError(validation, inst,
                "basicTargetAddress",
                "I2C Target's Own Address must be a valid 7-bit address.");
            }
            if (inst.basicTargetSecAddressEnable && inst.basicTargetSecAddress > 0x7F) {
                Common.logError(validation, inst,
                "basicTargetSecAddress",
                "I2C Target's Secondary Address must be a valid 7-bit address.");
            }
        }
        else {
            if (inst.basicTargetOwnAddressEnable && inst.basicTargetAddress > 0x3FF) {
                Common.logError(validation, inst,
                "basicTargetAddress",
                "I2C Target's Own Address must be a valid 10-bit address.");
            }
            if (inst.basicTargetSecAddressEnable && inst.basicTargetSecAddress > 0x3FF) {
                Common.logError(validation, inst,
                "basicTargetSecAddress",
                "I2C Target's Secondary Address must be a valid 10-bit address.");
            }
        }
    }

    if (inst.basicEnableController == true)
    {
        if (getValueI2CBusSpeedCalc(inst) == 0)
        {
            Common.logError(validation, inst,
                            "basicControllerBusSpeedArray",
                            "I2C Bus speed not possible, adjust I2C clock source \
                            and desired speed");
            Common.logError(validation, inst,
                            "basicControllerBusSpeed",
                            "I2C Bus speed not possible, adjust I2C clock source \
                            and desired speed");
            Common.logError(validation, inst,
                            "basicClockSource",
                            "I2C Bus speed not possible, adjust I2C clock source \
                            and desired speed");
            Common.logError(validation, inst,
                            "basicClockSourceDivider",
                            "I2C Bus speed not possible, adjust I2C clock source \
                            and desired speed");
        }
        if ((inst.basicControllerBusSpeed) != (inst.basicControllerBusSpeedSelected))
        {
            Common.logWarning(validation, inst,
                            "basicControllerBusSpeedArray",
                            "Actual bus speed differs from requested. Try using a\
                            different clock source or adjust bus speed if needed.\
                            See detailed help.");
        }
    }
}
