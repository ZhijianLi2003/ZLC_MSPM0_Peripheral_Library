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
 *  ======== UART.common.js ========
 */

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

exports = {
    getBasicConfig      : getBasicConfig,
    getAdvancedConfig   : getAdvancedConfig,
    getAdvancedConfigUART   : getAdvancedConfigUART,
    getAdvancedConfigLIN    : getAdvancedConfigLIN,
    getExtendConfig     : getExtendConfig,
    getDMAConfig        : getDMAConfig,
    getDMAModInstances  : getDMAModInstances,
    setRequiredModules  : setRequiredModules,
    getValidation       : getValidation,
    updateGUIbasedonConfig  : updateGUIbasedonConfig,
};

/************************* Config defines *******************************/
/* Retention configurable */
let retentionConfig = [];
if(Common.isDeviceM0G()){
    retentionConfig = retentionConfig.concat(
        {
            name        : "enableRetention",
            default     : false,
            hidden      : true,
            getValue: (inst) => {
                let solution = false;
                try{
                    solution = (/UART3/.test(inst.peripheral.$solution.peripheralName));
                }catch (e) {
                    // do nothing
                }
                return solution;
            }
        },
        {
            name        : "enableRetentionUI",
            displayName : "Low-Power Register Retention",
            default     : "",
            longDescription: `
Some MSPM0G peripherals residing in PD1 domain do not retain register contents when
entering STOP or STANDBY modes. Please view the datasheet for more details.\n
Developers can decide to re-initialize the peripheral using the default
initialization from SysConfig in their application. This approach is more
memory-efficient.\n
Alternatively, the user may also call the provided DriverLib APIs to save and
restore the register configuration of the peripheral before and after entering
low-power mode. This approach is recommended if the peripheral configuration is
modified at runtime.
            `,
            getValue: (inst) => {
                let solution = false;
                try{
                    solution = (/UART3/.test(inst.peripheral.$solution.peripheralName)) && !(/SLEEP/.test(system.modules["/ti/driverlib/SYSCTL"].$static.powerPolicy));
                }catch (e) {
                    // do nothing
                }
                return (solution?"Registers not retained":"Registers retained");
            }
        },
        {
            name        : "overrideRetention",
            displayName : "Disable Retention APIs",
            longDescription: `
When selected, the retention APIs will not be generated regardless of selected peripheral.`,
            default     : false,
            hidden      : false,
        },
    );
}

/* DL_UART_DMA_INTERRUPT_RX */
let dmaRxOptions = [
    {name: "None", displayName: "None"},
    {name: "DL_UART_DMA_INTERRUPT_RX", displayName: "UART RX interrupt"},
    {name: "DL_UART_DMA_INTERRUPT_RX_TIMEOUT", displayName: "UART RX Timeout interrupt"},

]

/* DL_UART_DMA_INTERRUPT_TX */
let dmaTxOptions = [
    {name: "None", displayName: "None"},
    {name: "DL_UART_DMA_INTERRUPT_TX", displayName: "UART TX interrupt"},
]

/************************UART Mode Functions **********************************/
const UARTModeOptions = [
    { name: "NORMAL", displayName: "Normal UART Mode" },
    { name: "RS485", displayName: "RS485 Mode" },
    { name: "IDLE_LINE", displayName: "Idle Line Mode" },
    { name: "ADDR_9_BIT", displayName: "9 Bit Address Mode" },
    { name: "SMART_CARD", displayName: "ISO7816 Smart Card Support Mode" },
    { name: "DALI", displayName: "DALI Mode" },
];

function getDisabledUARTModeOptions(inst)
{
    let allOptions = [
        { name: "SMART_CARD", displayName: "ISO7816 Smart Card Support Mode", reason: "Extend mode is disabled"},
        { name: "DALI", displayName: "DALI Mode", reason: "Extend mode is disabled" },
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


/************************* Advanced functions *******************************/

function onIrdaEnable(inst, ui){
    if(inst.enableIrda){
        if(inst.uartMode == "NORMAL"){
            ui["setIrdaTxPulseClock"].hidden = false
            ui["setIrdaTxPolarity"].hidden = false
            ui["setIrdaPulseLength"].hidden = false
            ui["irdaPulseLengthCalc"].hidden = false
            ui["uartClkDiv2"].hidden = false
        }
    }
    else{
        ui["setIrdaTxPulseClock"].hidden = true
        ui["setIrdaTxPolarity"].hidden = true
        ui["setIrdaPulseLength"].hidden = true
        ui["irdaPulseLengthCalc"].hidden = true
        ui["uartClkDiv2"].hidden = true
    }
}

function updateIrdaConfig(inst,ui){
    if(inst.uartMode != "NORMAL"){
        inst.enableIrda = false
        ui.enableIrda.hidden = true
        ui["setIrdaTxPulseClock"].hidden = true
        ui["setIrdaTxPolarity"].hidden = true
        ui["setIrdaPulseLength"].hidden = true
        ui["irdaPulseLengthCalc"].hidden = true
        ui["uartClkDiv2"].hidden = true
    }
    else{
        if(inst.enableExtend){
            ui.enableIrda.hidden = false
            if(inst.enableIrda){
                ui["setIrdaTxPulseClock"].hidden = false
                ui["setIrdaTxPolarity"].hidden = false
                ui["setIrdaPulseLength"].hidden = false
                ui["irdaPulseLengthCalc"].hidden = false
                ui["uartClkDiv2"].hidden = false
            }
        }
    }
}

function onUARTModeEnable(inst, ui){
    if(inst.uartMode == "DALI" || inst.uartMode == "ADDR_9_BIT" || inst.uartMode == "IDLE_LINE"){
        ui["addressMask"].hidden = false
        ui["address"].hidden = false
    }
    else{
        ui["addressMask"].hidden = true
        ui["address"].hidden = true
    }
    if (inst.uartMode == "RS485")
    {
        ui["setExtDriverSetup"].hidden = false
        ui["setExtDriverHold"].hidden = false
    }
    else{
        ui["setExtDriverSetup"].hidden = true
        ui["setExtDriverHold"].hidden = true
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

const UARTHWFlowControlPinsOptions = [
    { name: "NONE", displayName: "Disable HW flow control" },
    { name: "RTS", displayName: "RTS enabled" },
    { name: "CTS", displayName: "CTS enabled" },
    { name: "RTS_CTS", displayName: "RTS and CTS enabled" },
];

/* Get which UART pins are disabled */
function getUARTHWFlowControlPinsDisabledOptions(inst)
{
    let disabledOptions = [];

    if (!hasMuxablePins("UART", "RTS"))
    {
        disabledOptions.push({name: "RTS",
                              displayName: "RTS enabled",
                              reason: "RTS is not available in this package"});
        disabledOptions.push({name: "RTS_CTS",
                              displayName: "RTS and CTS enabled",
                              reason: "RTS and CTS is not available in this package"});
    }
    if (!hasMuxablePins("UART", "CTS"))
    {
        disabledOptions.push({name: "CTS",
                              displayName: "CTS enabled",
                              reason: "CTS is not available in this package"});

    }
    // TODO case for both

    return disabledOptions;
}

/************************* Profiles functions *******************************/
function updateGUIbasedonConfig(inst, ui)
{
    updateGUIEnableExtend(inst, ui)
    updateFifoThresholds(inst, ui)
}

function updateGUIEnableExtend(inst, ui)
{
    if (inst.enableExtend == false) {
        ui.enableManchester.hidden = true

        ui.enableIrda.hidden = true
        ui["setIrdaTxPulseClock"].hidden = true
        ui["setIrdaTxPolarity"].hidden = true
        ui["setIrdaPulseLength"].hidden = true
        ui["irdaPulseLengthCalc"].hidden = true
        ui["uartClkDiv2"].hidden = true
        ui.setExtDriverSetup.hidden = true
        ui.setExtDriverHold.hidden = true
    }
    else {
        ui.enableManchester.hidden = false
        if(inst.uartMode == "NORMAL"){
            ui.enableIrda.hidden = false
            if(inst.enableIrda){
                ui["setIrdaTxPulseClock"].hidden = false
                ui["setIrdaTxPolarity"].hidden = false
                ui["setIrdaPulseLength"].hidden = false
                ui["irdaPulseLengthCalc"].hidden = false
                ui["uartClkDiv2"].hidden = false
            }
            else{
                ui["setIrdaTxPulseClock"].hidden = true
                ui["setIrdaTxPolarity"].hidden = true
                ui["setIrdaPulseLength"].hidden = true
                ui["irdaPulseLengthCalc"].hidden = true
                ui["uartClkDiv2"].hidden = true
            }
        }
        else{
            ui.enableIrda.hidden = true
            inst.enableIrda = false
            ui["setIrdaTxPulseClock"].hidden = true
            ui["setIrdaTxPolarity"].hidden = true
            ui["setIrdaPulseLength"].hidden = true
            ui["irdaPulseLengthCalc"].hidden = true
            ui["uartClkDiv2"].hidden = true
        }
        if (inst.enableIrda == false)
        {
            ui["setIrdaTxPulseClock"].hidden = true
            ui["setIrdaTxPolarity"].hidden = true
            ui["setIrdaPulseLength"].hidden = true
            ui["irdaPulseLengthCalc"].hidden = true
            ui["uartClkDiv2"].hidden = true
        }
        else{
            ui["setIrdaTxPulseClock"].hidden = false
            ui["setIrdaTxPolarity"].hidden = false
            ui["setIrdaPulseLength"].hidden = false
            ui["irdaPulseLengthCalc"].hidden = false
            ui["uartClkDiv2"].hidden = false
        }
    }
    // for interrupts
    ui.interruptPriority.hidden = (inst.enabledInterrupts.length === 0);

}

/* When target baud rate is changed, set the calculated baud rate back to 0 */
function updateGUIbasicBaudRateCalc(inst, ui) {
    inst.calculatedBaudRate = 0;
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

function onChangeSetCustomProfile(inst,ui){
    inst.profile = "CUSTOM";
}



/************************* Basic onChange functions *******************************/
/* onChange functions for Basic Configuration */

function onChangeBasicClockSource(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeBasicClockSourceDivider(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeBasicEnableExtend(inst, ui)
{
    updateGUIEnableExtend(inst, ui);
    onChangeSetCustomProfile(inst, ui);
}

function onChangeBasicBaudRateCalc(inst, ui)
{
    updateGUIbasicBaudRateCalc(inst, ui);
    onChangeSetCustomProfile(inst, ui);
}

function onChangeBasicFlowControl(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

/************************* Advanced onChange functions *******************************/
/* onChange functions for Advanced Configuration */

function onChangeAdvUartMode(inst, ui)
{
    updateIrdaConfig(inst,ui);
    onUARTModeEnable(inst, ui);
    onChangeSetCustomProfile(inst, ui);
}

function onChangeAdvUartModeLIN(inst, ui)
{
    onUARTModeEnable(inst, ui);
    onChangeSetCustomProfile(inst, ui);
}

function onChangeAdvDirection(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeOvsRate(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeAdvEnableFifo(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
    updateFifoThresholds(inst, ui);
}

function onChangeAdvRxFifoThreshold(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeAdvTxFifoThreshold(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeAdvDigitalGlitchFilter(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeAdvAnalogGlitchFilter(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeAdvRxTimeoutValue(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeAdvLoopbackMode(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

/************************* Extend onChange functions *******************************/
/* onChange functions for Extend Configuration */

function onChangeExtendManchesterMode(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

// function onChangeExtendLinMode(inst, ui)
// {
//     onLinEnable(inst, ui);
//     onChangeSetCustomProfile(inst, ui);
// }

function onChangeExtendIrdaMode(inst, ui)
{
    onIrdaEnable(inst, ui);
    onChangeSetCustomProfile(inst, ui);
}

/************************* DMA onChange functions *******************************/
/* onChange functions for DMA Configuration */

function onChangeDMAEvent1(inst, ui)
{
    ui.enableDMARX.hidden = (inst.enabledDMARXTriggers == "None");
    onChangeSetCustomProfile(inst, ui);
}

function onChangeDMAEvent2(inst, ui)
{
    ui.enableDMATX.hidden = (inst.enabledDMATXTriggers == "None");
    onChangeSetCustomProfile(inst, ui);
}

/************************* General functions **********************************/
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

/*
 *  ======== getValueBaudRateCalc ========
 *  Calculate the actual UART baud rate based on UART clock source
 *  This is used for displaying to inst.calculatedBaudRate
 */
function getValueBaudRateCalc(inst) {
    let clockFreq;
    let baudRate;
    let ovsRate;
    let ibrd;
    let fbrd;
    let divisor;
    let calcBaudRate;
    let baudArray = [];

    baudRate = inst.targetBaudRate;
    clockFreq = getUARTClockSourceFreq(inst);

    switch (inst.ovsRate)
    {
        case "3":
            ovsRate = 3;
            divisor = ((clockFreq * 64) / (baudRate * ovsRate)) + 1/2;
            break;
        case "8":
            ovsRate = 8;
            baudRate = baudRate / 2;
            divisor = (((clockFreq * 8) / baudRate) + 1) / 2;
            break;
        case "16":
            ovsRate = 16;
            divisor = (((clockFreq * 8) / baudRate) + 1) / 2;
            break;
        default:
            break;
    }

    ibrd = divisor >> 6;
    fbrd = divisor & 0x3F;

    calcBaudRate = clockFreq / ovsRate / (ibrd + (fbrd/64));

    baudArray.push({name: 0, displayName: calcBaudRate.toFixed(2)});

    fbrd = fbrd + 1;
    calcBaudRate = clockFreq / ovsRate / (ibrd + (fbrd/64));
    baudArray.push({name: 1, displayName: calcBaudRate.toFixed(2)});

    if((fbrd - 2) > 0)
    {
        fbrd = fbrd - 2;
        calcBaudRate = clockFreq / ovsRate / (ibrd + (fbrd/64));
        if (calcBaudRate <= 10000000) {
            baudArray.push({name: -2, displayName: calcBaudRate.toFixed(2)});
        }
    }

    return baudArray;
}

/*
 *  ======== getSelectedBaudRateCalc ========
 * Calculate the UART baud values using the offset from the option that the
 * user selects in inst.calculatedBaudRate.
 * This is used for the error calculation in inst.calculatedError
 *
 */
function getSelectedBaudRateCalc(inst) {
    let calcBaudRate;
    let fbrd;
    let fbrdOffset;

    let clockFreq;
    let baudRate;
    let ovsRate;
    let ibrd;
    let divisor;

    baudRate = inst.targetBaudRate;
    clockFreq = getUARTClockSourceFreq(inst);

    switch (inst.ovsRate)
    {
        case "3":
            ovsRate = 3;
            divisor = ((clockFreq * 64) / (baudRate * ovsRate)) + 1/2;
            break;
        case "8":
            ovsRate = 8;
            baudRate = baudRate / 2;
            divisor = (((clockFreq * 8) / baudRate) + 1) / 2;
            break;
        case "16":
            ovsRate = 16;
            divisor = (((clockFreq * 8) / baudRate) + 1) / 2;
            break;
        default:
            break;
    }

    ibrd = divisor >> 6;
    fbrd = divisor & 0x3F;

    fbrdOffset = inst.calculatedBaudRate; /* This gets the fbrd offset store in "name" */

    fbrd = fbrd + fbrdOffset;

    calcBaudRate = clockFreq / ovsRate / (ibrd + (fbrd/64));

    return calcBaudRate;
}

function getFBRD(inst) {
    let fbrd;
    let fbrdOffset;
    let clockFreq;
    let baudRate;
    let ovsRate;
    let divisor;

    baudRate = inst.targetBaudRate;
    clockFreq = getUARTClockSourceFreq(inst);

    switch (inst.ovsRate)
    {
        case "3":
            ovsRate = 3;
            divisor = ((clockFreq * 64) / (baudRate * ovsRate)) + 1/2;
            break;
        case "8":
            ovsRate = 8;
            baudRate = baudRate / 2;
            divisor = (((clockFreq * 8) / baudRate) + 1) / 2;
            break;
        case "16":
            ovsRate = 16;
            divisor = (((clockFreq * 8) / baudRate) + 1) / 2;
            break;
        default:
            break;
    }

    fbrd = divisor & 0x3F;
    fbrdOffset = inst.calculatedBaudRate; /* This gets the fbrd offset store in "name" */
    fbrd = fbrd + fbrdOffset;

    return fbrd;
}

function getIBRD(inst) {
    let clockFreq;
    let baudRate;
    let ovsRate;
    let ibrd;
    let divisor;

    baudRate = inst.targetBaudRate;
    clockFreq = getUARTClockSourceFreq(inst);

    switch (inst.ovsRate)
    {
        case "3":
            ovsRate = 3;
            divisor = ((clockFreq * 64) / (baudRate * ovsRate)) + 1/2;
            break;
        case "8":
            ovsRate = 8;
            baudRate = baudRate / 2;
            divisor = (((clockFreq * 8) / baudRate) + 1) / 2;
            break;
        case "16":
            ovsRate = 16;
            divisor = (((clockFreq * 8) / baudRate) + 1) / 2;
            break;
        default:
            break;
    }

    ibrd = divisor >> 6;

    return ibrd;
}

/*
 *  ======== getErrorCalc ========
 *  Calculate the UART baud error percentage
 *
 */
function getErrorCalc(inst) {
    let error;
    let calcBaud = getSelectedBaudRateCalc(inst);

    error = ((calcBaud - inst.targetBaudRate) / inst.targetBaudRate * 100).toFixed(4);

    return parseFloat(Math.abs(error));
}



/*
 *  ======== getValueUARTdigitalGlitchFilterCalc ========
 *  Calculate the actual UART digital glitch filter based on UART clock source
 *
 */
function getValueUARTdigitalGlitchFilterCalc(inst) {
    let sourceClkFreq;
    let filterTime;

    sourceClkFreq = getUARTClockSourceFreq(inst);

    filterTime = (inst.digitalGlitchFilter) / sourceClkFreq;

    return filterTime;
}

/*
 *  ======== getValueUARTIrDAPulseLength ========
 *  Calculate the actual IrDA pulse length based on UART clock source
 *
 */
function getValueUARTIrDAPulseLength(inst) {
    let sourceClkFreq;
    let pulseLength;

    sourceClkFreq = getUARTClockSourceFreq(inst);

    pulseLength = (inst.setIrdaPulseLength) / sourceClkFreq;

    return pulseLength;
}

/*
 *  ======== getValueUARTdigitalGlitchFilterCalc ========
 *  Calculate the actual UART digital glitch filter based on UART clock source
 *
 */
function getRXTimeoutCalc(inst) {
    let sourceClkFreq;
    let timeout;

    sourceClkFreq = getUARTClockSourceFreq(inst);

    timeout = (inst.rxTimeoutValue) / sourceClkFreq;

    return timeout;
}


/************************* Config functions *******************************/
function getBasicConfig(inst,ui){
    return [
        {
            name: "GROUP_INIT",
            displayName: "UART Initialization Configuration",
            description: "",
            longDescription: "Initializes UART for selected operation",
            collapsed: false,
            config: [
                    {
                        name        : "uartClkSrc",
                        displayName : "Clock Source",
                        description : 'Clock source selection',
                        longDescription:`
The UART clock can be sourced from:\n
* LFCLK, or
* MFCLK, or
* BUSCLK, which depends on the power domain:
    * If the UART is in PD1, BUSCLK is derived from MCLK, or,
    * If the UART is in PD0, BUSCLK is derived from ULPCLK.\n
The frequency of the clock sources are configured
in the __SYSCTL Module__. `,
                        hidden      : false,
                        default     : "BUSCLK",
                        options     : [
                            {name: "BUSCLK", displayName: "BUSCLK"},
                            {name: "MFCLK", displayName: "MFCLK"},
                            {name: "LFCLK", displayName: "LFCLK"},
                        ],
                        onChange    : onChangeBasicClockSource,
                    },
                    {
                        name        : "uartClkDiv",
                        displayName : "Clock Divider",
                        description : 'Clock divider selection',
                        hidden      : false,
                        default     : "1",
                        options     : [
                            {name: "1", displayName: "Divide by 1"},
                            {name: "2", displayName: "Divide by 2"},
                            {name: "3", displayName: "Divide by 3"},
                            {name: "4", displayName: "Divide by 4"},
                            {name: "5", displayName: "Divide by 5"},
                            {name: "6", displayName: "Divide by 6"},
                            {name: "7", displayName: "Divide by 7"},
                            {name: "8", displayName: "Divide by 8"},
                        ],
                        onChange    : onChangeBasicClockSourceDivider,
                    },
                    {
                        name        : "basicClockSourceCalculated",
                        displayName : "Calculated Clock Source",
                        description : 'Calculated UART Clock Source in Hz',
                        hidden      : false,
                        default     : "0 Hz",
                        getValue: (inst) => {
                            let freq = getUARTClockSourceFreq(inst);
                            return (Common.getUnitPrefix(freq)).str+"Hz";

                        },
                    },
                    {
                        name        : "basicClockSourceCalculatedHidden",
                        displayName : "Calculated Clock Source",
                        description : 'Calculated UART Clock Source in Hz',
                        hidden      : true,
                        default     : 0,
                        getValue: (inst) => getUARTClockSourceFreq(inst),
                    },
                    {
                        name        : "targetBaudRate",
                        displayName : "Target Baud Rate",
                        description : 'The target baud rate in bps',
                        longDescription: `
This UART module supports programmable baud-rate generation.`,
                        hidden      : false,
                        default     : 9600,
                        range       : [0, 10000000],
                        onChange    : onChangeBasicBaudRateCalc,
                    },
                    {
                        name        : "calculatedBaudRate",
                        displayName : "Calculated Baud Rate",
                        description : 'The calculated baud rate in bps',
                        longDescription: `
This setting shows the closest baud rates based on the target baud.\n
The next available options are shown in drop-down for convenience purposes
and can be selected if needed.\n
**A warning will be shown if the calculated baud rate differs significantly
from desired setting. Adjust the clock source or target baud if needed.** \n
The frequency period is calculated as:\n
        brd = ibrd.fbrd = clockOutput / (OVS * baudRate)\n
        where ibrd is the integer part, fbrd is the fractional part.\n
        Since fbrd is 6 bits, multiply brd by 64:\n
            64 * brd = (clockOutput * 64) / (16 * baudRate)\n
                    = (clockOutput * 4) / baudRate\n
        add 1/2 to round the least significant bit of fbrd:\n
            64 * brd + 1/2 = (clockOutput * 8 / (2 * baudRate) + 1/2\n
            divisor = 64*brd+1/2  = [(clockOutput * 8)/ baudRate + 1] / 2\n
        The lower 6 bits is fbrd, upper part is ibrd\n
`,
                        hidden      : false,
                        options    : (inst) => getValueBaudRateCalc(inst),
                        default     : 0
                    },
                    {
                        name        : "calculatedBaudRateNum", /* Used internally for code gen */
                        displayName : "Calculated Baud Rate",
                        description : 'The calculated baud rate in bps',
                        hidden      : true,
                        getValue    : (inst) => parseFloat(getSelectedBaudRateCalc(inst).toFixed(2)),
                        default     : 0
                    },
                    {
                        name        : "calculatedError",
                        displayName : "Calculated Error (%)",
                        description : 'The calculated error percentage',
                        longDescription: `
This shows the calculated baud rate error percentage.\n
This is calculated by:\n
        error = (calculatedBaudRate - targetBaudRate) / (targetBaudRate * 100)\n
`,
                        hidden      : false,
                        getValue    : (inst) => getErrorCalc(inst),
                        default     : 0
                    },
                    {
                        name        : "fbrd", /* Used internally for code gen */
                        displayName : "FBRD",
                        description : 'FBRD',
                        hidden      : true,
                        getValue    : (inst) => getFBRD(inst),
                        default     : 0
                    },
                    {
                        name        : "ibrd", /* Used internally for code gen */
                        displayName : "IBRD",
                        description : 'IBRD',
                        hidden      : true,
                        getValue    : (inst) => getIBRD(inst),
                        default     : 0
                    },

                    /* DL_UART_setWordLength */
                    {
                        name: "wordLength",
                        displayName: "Word Length",
                        description: "The size of the data transfer",
                        default: "8_BITS",
                        options: [
                            { name: "5_BITS", displayName: "5 bits" },
                            { name: "6_BITS", displayName: "6 bits" },
                            { name: "7_BITS", displayName: "7 bits" },
                            { name: "8_BITS", displayName: "8 bits" },
                        ]
                    },
                    /* DL_UART_setParityMode */
                    {
                        name: "parity",
                        displayName: "Parity",
                        description: "The parity configuration",
                        default: "NONE",
                        options: [
                            { name: "NONE", displayName: "None" },
                            { name: "EVEN", displayName: "Even" },
                            { name: "ODD", displayName: "Odd" },
                            { name: "STICK_ONE", displayName: "Stick One" },
                            { name: "STICK_ZERO", displayName: "Stick Zero" },
                        ]
                    },
                    /* DL_UART_setStopBits */
                    {
                        name: "stopBits",
                        displayName: "Stop Bits",
                        description: "The number of stop bits",
                        default: "ONE",
                        options: [
                            { name: "ONE", displayName: "One" },
                            { name: "TWO", displayName: "Two" },
                        ]
                    },
                    /* DL_UART_setFlowControl */
                    {
                        name: "flowControl",
                        displayName: "HW Flow Control",
                        description: "The hardware flow control configuration",
                        longDescription: `
Hardware flow control between two devices is accomplished by connecting the RTS
output to the CTS input on the receiving device, and connecting the RTS output
on the receiving device to the CTS input. The RTS output signal is low active,
the CTS input expects a low signal on a send request.

![UART HW Flow Control Diagram](../docs/english/sysconfig/images/uartFlowControlDiagM0G3xx.png "UART HW Flow Control Diagram")
`,
                        default: "NONE",
                        options: UARTHWFlowControlPinsOptions,
                        getDisabledOptions: getUARTHWFlowControlPinsDisabledOptions,
                        onChange    : onChangeBasicFlowControl,
                    },
                ]
            },
    ];
}

function getAdvancedConfigUART(inst,ui){
    let uartConfig =  [{
        /* DL_UART_setCommunicationMode */
        name: "uartMode",
        displayName: "UART Mode",
        description: "The UART communication mode and protocol used",
        longDescription: `
The UART can be set into various modes.\n
To select a UART Extend-only mode, a UART Extend instance must be selected.
        `,
        default: "NORMAL",
        options: UARTModeOptions,
        getDisabledOptions: getDisabledUARTModeOptions,
        onChange : onChangeAdvUartMode,
    }].concat(getAdvancedConfig(inst,ui));

    return uartConfig;
}
function getAdvancedConfigLIN(inst,ui){
    let uartConfig =  [{
        /* DL_UART_setCommunicationMode */
        name: "uartMode",
        displayName: "UART Mode",
        description: "The UART communication mode and protocol used",
        longDescription: `
The UART can be set into various modes.\n
To select a UART Extend-only mode, a UART Extend instance must be selected.
        `,
        default: "NORMAL",
        options: UARTModeOptions,
        getDisabledOptions: getDisabledUARTModeOptions,
        onChange : onChangeAdvUartModeLIN,
    }].concat(getAdvancedConfig(inst,ui));

    return uartConfig;
}

function getAdvancedConfig(inst,ui){
    return [
{
    name: "rs485Config",
    displayName: "RS485 Configuration",
    longDescription:
`Configuration for RS485 mode.\n
RS485 is a standard used in serial communications systems. This standard can be used effectively over long
distances and in electrically noisy environments. Multiple receivers can be connected to such a network. These
characteristics make RS-485 useful in industrial control systems and similar applications.
`,
    collapsed: false,
    config: [
        /* DL_UART_setExternalDriverSetup */
        {
            name        : "setExtDriverSetup",
            displayName : "EXT Driver Setup Val (Ticks)",
            description : 'Set the number of UART clock ticks for the external driver setup',
            longDescription:
`
Defines the number of UART clock ticks the signal to control the external driver for the RS485
will be set before the START bit is sent. The generated setup time will be between EXDIR_SETUP
value and EXDIR_SETUP + one baud rate cycle
`,
            hidden      : true,
            default     : 0,
            range : [0,31],
            isInteger : true,
        },
        /* DL_UART_setExternalDriverHold */
        {
        name        : "setExtDriverHold",
        displayName : "EXT Driver Setup Hold Val (Ticks)",
        description : 'Set the number of UART clock ticks for the external driver setup will be reset',
        longDescription:
`
Defines the number of UART clock ticks the signal to control the external driver for the
RS485 will be reset after the beginning of the stop bit. (If 2 STOP bits are enabled the beginning of the 2nd
STOP bit.)
`,
        hidden      : true,
        default     : 0,
        range : [0,31],
        isInteger : true,
        },
    ]

},
{
    name: "addressConfig",
    displayName: "Address Configuration",
    longDescription:
`Configuration for Idle-Line mode.\n
In Idle-Line mode, blocks of data are separated by an idle time on the transmit or receive lines. An idle receive line is
detected when ten or more continuous ones (marks) are received after the one or two stop bits of a character.
The baud-rate generator is switched off after reception of an idle line until the next start edge is detected.
`,
    collapsed: false,
    config: [
        /* DL_UART_setAddressMask */
        {
            name        : "addressMask",
            displayName : "Address Mask",
            description : 'Set the address mask for DALI, 9-bit, or Idle-Line mode',
            longDescription:
`The first character received after an idle period is an address character. The IDLE bit
is used as an address tag for each block of characters. In idle-line multiprocessor format, this bit is set when a
received character is an address.
If an address character is received it is compared against the value set in "Address" with the "Address Mask" applied. If the
received character matches, the address character and all following received characters are transferred into the
RXDATA buffer and interrupts/flags are generated until the next address without a match is received. The IDLE
bit in UARTx.STAT register is automatically cleared when the address does match; otherwise the IDLE bit is set
until the address is matched.
`,
            hidden      : true,
            default     : 0x0,
            range : [0x0,0xFF],
            isInteger : true,
        },
        /* DL_UART_setAddress */
        {
            name        : "address",
            displayName : "Address To Match",
            description : 'Set the address that should be matched with the receiving byte',
            longDescription:
`The first character received after an idle period is an address character. The IDLE bit
is used as an address tag for each block of characters. In idle-line multiprocessor format, this bit is set when a
received character is an address.
If an address character is received it is compared against the value set in "Address" with the "Address Mask" applied. If the
received character matches, the address character and all following received characters are transferred into the
RXDATA buffer and interrupts/flags are generated until the next address without a match is received. The IDLE
bit in UARTx.STAT register is automatically cleared when the address does match; otherwise the IDLE bit is set
until the address is matched.
`,
            hidden      : true,
            default     : 0x0,
            range : [0x0,0xFF],
            isInteger : true,
        },
    ]
},

        /* DL_UART_setDirection */
        {
            name: "direction",
            displayName: "Communication Direction",
            description: "The communication direction",
            default: "TX_RX",
            options: [
                { name: "TX_RX", displayName: "TX and RX" },
                { name: "TX", displayName: "TX only" },
                { name: "RX", displayName: "RX only" },
            ],
            onChange : onChangeAdvDirection,
        },
        /* DL_UART_setOversampling */
        {
            name        : "ovsRate",
            displayName : "Oversampling",
            description : 'The oversampling rate.',
            longDescription: `
The UART supports oversampling by 16, 8, or by 3 .\n

![UART Oversampling Diagram](../docs/english/sysconfig/images/uartOvsDiagM0G3xx.png "UART Oversampling Diagram")

* When 16x oversampling is selected, the receiving bits are expected to have the
length of 16 UART clock UARTclk cycles and is sampled on the 8th UARTclk cycle.\n
* When 8x oversampling is selected,the receiving bits are expected to have
the length of 8 UART clock UARTclk cycles and is sampled on the 4th UARTclk cycle.\n
* When 3x oversampling is selected, the receiving bits are expected to have the
length of 3 UART clock UARTclk cycles and are sampled on the 1st UARTclk cycle.\n
Depending on the application:\n
* Select oversampling by 3 or 8 to achieve higher speed with UARTclk/8 or UARTclk/3.
In this case the receiver tolerance to clock deviation is reduced.\n
* Select oversampling by 16 to increase the tolerance of the receiver to clock
deviations. But the maximumspeed is limited to UARTclk/16.\n
            `,
            hidden      : false,
            default     : "16",
            options     : [
                {name: "16", displayName: "16x"},
                {name: "8", displayName: "8x"},
                {name: "3", displayName: "3x"},
            ],
            onChange : onChangeOvsRate,
        },
        /* DL_UART_enableFIFOs */
        {
            name        : "enableFIFO",
            displayName : "Enable FIFOs",
            description : 'Enable the TX and RX FIFOs',
            longDescription: `
The UART has two FIFOs with a depth of 4 entries, one for transmit and one for receive.\n
The FIFOs are accessed via the UART Data registers.
Read operations of the RXDATA register return a 12-bit value consisting of 8
data bits and 4 error flags. Write operations to TXDATA place 8-bit data in the
transmit FIFO.\n
When disabled, the FIFOs act as 1-byte-deep holding registers.\n
            `,
            hidden      : false,
            default     : false,
            onChange : onChangeAdvEnableFifo,
        },
        /* DL_UART_setRXFIFOThreshold */
        {
            name        : "rxFifoThreshold",
            displayName : "RX FIFO Threshold Level",
            description : 'The RX FIFO threshold level for when the interrupt triggers',
            hidden      : true,
            default     : "DL_UART_RX_FIFO_LEVEL_1_2_FULL",
            options     : [
                {name: "DL_UART_RX_FIFO_LEVEL_ONE_ENTRY", displayName: "RX FIFO contains >= 1 entry"},
                {name: "DL_UART_RX_FIFO_LEVEL_FULL", displayName: "RX FIFO is full"},
                {name: "DL_UART_RX_FIFO_LEVEL_3_4_FULL", displayName: "RX FIFO contains>= 3 entries"},
                {name: "DL_UART_RX_FIFO_LEVEL_1_2_FULL", displayName: "RX FIFO contains>= 2 entries"},
                {name: "DL_UART_RX_FIFO_LEVEL_1_4_FULL", displayName: "RX FIFO contains >= 3/4 full"},
            ],
            onChange : onChangeAdvRxFifoThreshold,
        },
        /* DL_UART_setTXFIFOThreshold */
        {
            name        : "txFifoThreshold",
            displayName : "TX FIFO Threshold Level",
            description : 'The TX FIFO interrupt threshold level',
            hidden      : true,
            default     : "DL_UART_TX_FIFO_LEVEL_1_2_EMPTY",
            options     : [
                {name: "DL_UART_TX_FIFO_LEVEL_3_4_EMPTY", displayName: "TX FIFO contains <= 1 entry"},
                {name: "DL_UART_TX_FIFO_LEVEL_1_2_EMPTY", displayName: "TX FIFO contains <= 2 entries"},
                {name: "DL_UART_TX_FIFO_LEVEL_1_4_EMPTY", displayName: "TX FIFO contains <= 3 entries"},
                {name: "DL_UART_TX_FIFO_LEVEL_EMPTY", displayName: "TX FIFO is empty"},
                {name: "DL_UART_TX_FIFO_LEVEL_ONE_ENTRY", displayName: "TX FIFO contains 1 entry"}, // TODO: Differentiate between 3_4 empty and one entry
            ],
            onChange : onChangeAdvTxFifoThreshold,
        },
        /* DL_UART_enableAnalogGlitchFilter */
        {
            name        : "analogGlitchFilter",
            displayName : "Analog Glitch Filter",
            description : 'Configure the pulse width for the analog glitch filter supprression on the RX input',
            longDescription : `
The analog glitch suppression on the RX line is based on the analog glitch filter.\n
When disabled, the input signals will be passed through to the UART module
without filtering.\n
`,
            default     : "Disabled",
            options     : [
                {name: "Disabled", displayName: "Disabled"},
                {name: "DL_UART_PULSE_WIDTH_5_NS", displayName: "Filter pulses < 5ns"},
                {name: "DL_UART_PULSE_WIDTH_10_NS", displayName: "Filter pulses < 10ns"},
                {name: "DL_UART_PULSE_WIDTH_25_NS", displayName: "Filter pulses < 25ns"},
                {name: "DL_UART_PULSE_WIDTH_50_NS", displayName: "Filter pulses < 50ns"},
            ],
            onChange : onChangeAdvAnalogGlitchFilter,
        },
        /* DL_UART_setDigitalPulseWidth */
        {
            name        : "digitalGlitchFilter",
            displayName : "Digital Glitch Filter",
            description : 'Set the pulse width select for the digital gitch filter suppression ',
            longDescription: `
The digital filter is optional and it's bypassed by default.\n
This filter is based on the functional clock and provides glitch suppression
on the RX line and assure proper signal values.\n
All signals are delayed internally when glitch suppression is nonzero.\n
For example, if DGFSEL is set to 0x5, 5 clocks should be added onto the
calculation for the expected transaction time.\n
`,
            hidden      : false,
            default     : 0,
            range : [0,63],
            isInteger : true,
            onChange : onChangeAdvDigitalGlitchFilter,
        },
        {
            name        : "advDigitalGlitchFilterCalc",
            displayName : "Calculated Digital Glitch Filter",
            description : 'Calculated Digital Glitch Filter',
            hidden      : false,
            default     : "0s",
            getValue    : (inst) => (Common.getUnitPrefix((getValueUARTdigitalGlitchFilterCalc(inst))).str+'s'),
        },
        /* DL_UART_setRXInterruptTimeout*/
        {
            name        : "rxTimeoutValue",
            displayName : "RX Timeout Interrupt Counts",
            description : 'Set the timeout for the RX Timeout Interrupt. The RTOUT interrupt needs to be set for the timeout to work.',
            hidden      : false,
            default     : 0,
            range : [0,15],
            isInteger : true,
            onChange : onChangeAdvRxTimeoutValue,
        },

        {
            name        : "rxTimeoutValueCalc",
            displayName : "Calculated RX Timeout Interrupt",
            description : 'Calculated timeout for the RX Timeout Interrupt',
            hidden      : false,
            default     : "0s",
            getValue    : (inst) => (Common.getUnitPrefix((getRXTimeoutCalc(inst))).str+'s'),


        },
        /* DL_UART_enableLoopbackMode */
        {
            name        : "enableInternalLoopback",
            displayName : "Enable Internal Loopback",
            description : 'Enable the internal loopback',
            longDescription: `
In loopback mode, data transmitted on the TXD output is received on the RXD input.\n
Data received on the RXD IO pin will be ignored when loopback is enabled.\n
`,
            hidden      : false,
            default     : false,
            onChange : onChangeAdvLoopbackMode,
        },
        /* DL_UART_enableMajorityVoting */
        {
            name        : "enableMajorityVoting",
            displayName : "Enable Majority Voting",
            description : 'Enable majority voting',
            longDescription :
`
When enabled with oversampling of 16, samples 7, 8, and 9 are
majority voted to decide the sampled bit value. The value corresponding to
at least 2 of the 3 samples is considered to be the received value.
\n
When enabled with oversampling of 8, samples 3, 4, and 5 are majority
voted to decide the sampled bit value. The value corresponding to at least 2
of the 3 samples is considered to be the received value.
\n
If the 3 sampled values do not match, then DL_UART_INTERRUPT_NOISE_ERROR interrupt is set.
\n
When enabled with oversampling of 3, only sample 2 is used to decide the sampled
bit value.
\n
`,
            hidden      : false,
            default     : false,
            onChange : onChangeSetCustomProfile,
        },
        /* DL_UART_enableMSBFirst */
        {
            name        : "enableMSBFirst",
            displayName : "Enable MSB First",
            description : 'Enable MSB first',
            longDescription :
`
When enabled, the most significant bit (MSB) is sent first in the protocol packet.
\n
When disabled, the least significant bit (LSB) is sent first in the protocol packet. This is the default configuration.
\n
This bit has effect on both the way the protocol byte is transmitted and received.
`,
            hidden      : false,
            default     : false,
            onChange : onChangeSetCustomProfile,
        },
        {
            name: "GROUP_RETENTION",
            displayName: "Retention Configuration",
            description: "",
            longDescription: ``,
            collapsed: false,
            config: retentionConfig,
        },
    ]
}

function getExtendConfig(inst,ui){
    return [
        {
            name        : "enableExtend",
            displayName : "Enable Extend Features",
            description : 'Enable the UART Extend mode features. A UART instance that supports Extend functionality must be selected in the PinMux section.',
            hidden      : false,
            default     : false,
            onChange    : onChangeBasicEnableExtend,
        },
        /* DL_UART_enableManchesterEncoding */
        {
            name        : "enableManchester",
            displayName : "Enable Manchester Encoding",
            description : 'Enable Manchester encoding and decoding',
            longDescription: `
UART provides option to receive and transmit Manchester encoded/decoded data.
The IEEE 802.3 compliant waveform will be generated. With the invert function
in GPIO control module the output signals can be inverted to generate the
G.E.Thomas compliant waveform. The output signal is generated by XORing the
data with UART clock signal.\n
The UART clock needs to be double the speed of the baud-rate.
So for the data transmit there is an edge at the beginning and the middle of
each data bit. For the receive signal the edge in the middle of the bit is
detected to decode the RX data.
            `,
            hidden      : true,
            default     : false,
            onChange : onChangeExtendManchesterMode,
        },
        /* DL_UART_enableIrDAMode */
        {
            name        : "enableIrda",
            displayName : "Enable IrDA Mode",
            description : 'Enable IrDA Mode',
            longDescription: `
Infrared Data Association, or IrDA, is a serial protocol designed for wireless infrared communication.
It is useful in enabling communication over longer distances via wireless when the devices are in each other's line of sight.
This form of communication requires encoding/decoding mechanisms to ensure the security of messages sent through this protocol.
`,
            hidden      : true,
            default     : false,
            onChange    : onChangeExtendIrdaMode
        },
        {
            name: "GROUP_IRDA",
            displayName: "IrDA Configuration",
            description: "",
            longDescription: "Configures IrDA mode",
            collapsed: false,
            config: [
                /* DL_UART_setIrDATXPulseClockSelect */
                {
                    name        : "setIrdaTxPulseClock",
                    displayName : "IrDA TX Pulse Clock",
                    description : 'Select the IrDA clock to be used for the transmit pulse',
                    hidden      : true,
                    default     : "DL_UART_IRDA_CLOCK_BAUD_RATE",
                    options     : [
                        {name: "DL_UART_IRDA_CLOCK_BAUD_RATE", displayName: "Baud Rate clock"},
                        {name: "DL_UART_IRDA_CLOCK_FUNCTIONAL", displayName: "Functional clock"},
                    ],
                },
                /* DL_UART_setIrDARXPulsePolarity */
                {
                    name        : "setIrdaTxPolarity",
                    displayName : "IrDA Polarity",
                    description : 'Set the IrDA receive input polarity',
                    hidden      : true,
                    default     : "DL_UART_IRDA_POLARITY_LOW",
                    options     : [
                        {name: "DL_UART_IRDA_POLARITY_LOW", displayName: "Low Polarity"},
                        {name: "DL_UART_IRDA_POLARITY_HIGH", displayName: "High Polarity"},
                    ],
                },
                /* DL_UART_setIrDAPulseLength */
                {
                    name        : "setIrdaPulseLength",
                    displayName : "IrDA Pulse Length (s)",
                    description : 'Set the IrDA transmit pulse length',
                    hidden      : true,
                    default     : 0,
                    range : [0,63],
                    isInteger : true,
                },
                {
                    name        : "irdaPulseLengthCalc",
                    displayName : "Calculated IrDA Pulse Length",
                    description : 'Calculated IrDA pulse length',
                    hidden      : true,
                    default     : "0s",
                    getValue    : (inst) => (Common.getUnitPrefix((getValueUARTIrDAPulseLength(inst))).str+'s'),
                },
                {
                    name        : "uartClkDiv2",
                    displayName : "Clock Divider 2",
                    description : 'Clock divider 2 ratio selection',
                    hidden      : true,
                    default     : "1",
                    options     : [
                        {name: "1", displayName: "Divide by 1"},
                        {name: "2", displayName: "Divide by 2"},
                        {name: "3", displayName: "Divide by 3"},
                        {name: "4", displayName: "Divide by 4"},
                        {name: "5", displayName: "Divide by 5"},
                        {name: "6", displayName: "Divide by 6"},
                        {name: "7", displayName: "Divide by 7"},
                        {name: "8", displayName: "Divide by 8"},
                    ],
                    onChange    : onChangeBasicClockSourceDivider,
                },
            ]
        },

    ];
}

function getDMAConfig(inst,ui){
    // UART does not support DMA for MSPM0Cxx
    if(Common.isDeviceM0C()){
        return [];
    }
    return [
        /* DL_UART_enableDMAReceiveEvent */
        {
            name        : "enabledDMARXTriggers",
            displayName : "Configure DMA RX Trigger",
            description : 'Configure the UART interrupts to use as triggers for the DMA RX event',
            longDescription:
            `Only one DMA receive trigger can be enabled at the same time. \n`,
            hidden      : false,
            default     : "None",
            options     : dmaRxOptions,
            onChange    : onChangeDMAEvent1
        },
        {
            name        : "enableDMARX",
            displayName : "Enable DMA RX Trigger",
            hidden      : true,
            default     : true,
            onChange    : onChangeSetCustomProfile,
        },
        /* DL_UART_enableDMATransmitEvent */
        {
            name        : "enabledDMATXTriggers",
            displayName : "Configure DMA TX Trigger",
            description : 'Configure the UART interrupt to use as triggers for the DMA TX event',
            hidden      : false,
            default     : "None",
            options     : dmaTxOptions,
            onChange    : onChangeDMAEvent2
        },
        {
            name        : "enableDMATX",
            displayName : "Enable DMA TX Trigger",
            hidden      : true,
            default     : true,
            onChange    : onChangeSetCustomProfile,
        },
    ];
}

/************************* devSpecific functions *******************************/
function getDMAModInstances(inst, modInstances){
    /* UART does not support DMA configuration for MSPM0Cxx */
    if(!Common.isDeviceM0C()){
    if(!["None"].includes(inst.enabledDMARXTriggers)){
        let mod = {
            name: "DMA_CHANNEL_RX",
            displayName: "DMA Channel RX",
            moduleName: '/ti/driverlib/DMAChannel',
            group: "GROUP_DMA",
            args: {
                //triggerSelect: inst.dmaPassedSolution
            },
            requiredArgs: {
                hideTriggerSelect: true,
                passedTriggerSelect: 0,
                /* empty for now */
            },

        }
        modInstances.push(mod);
        /* TODO: pickup here */
    }
    if(!["None"].includes(inst.enabledDMATXTriggers)){
        let mod = {
            name: "DMA_CHANNEL_TX",
            displayName: "DMA Channel TX",
            moduleName: '/ti/driverlib/DMAChannel',
            group: "GROUP_DMA",
            args: {
                //triggerSelect: inst.dmaPassedSolution
            },
            requiredArgs: {
                hideTriggerSelect: true,
                passedTriggerSelect: 1,
                /* empty for now */
            },

        }
        modInstances.push(mod);
        /* TODO: pickup here */
    }
    }
}

function setRequiredModules(inst){
    let theModules = ["Board", "SYSCTL"]
    /* UART does not support DMA configuration for MSPM0Cxx */
    if(!Common.isDeviceM0C()){
        if(!["None"].includes(inst.enabledDMARXTriggers) || !["None"].includes(inst.enabledDMATXTriggers)){
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

function getValidation(inst, validation){
    Common.validateNames(inst, validation);

    let  baudRate = inst.targetBaudRate;
    let clockFreq = getUARTClockSourceFreq(inst);

    if(inst.enableExtend && inst.enableIrda && inst.uartMode == "NORMAL"){
        if(baudRate != 9600){
            Common.logWarning(validation, inst,
                "targetBaudRate",
                "A baud rate of 9600 should be used for IrDA mode"
            )
        }
    }

    /* Check if oversampling is valid given the target baud rate and UART clock */
    if ((((baudRate * 3) > clockFreq) && (inst.ovsRate == "3"))   ||
            (((baudRate * 8) > clockFreq) && (inst.ovsRate == "8")) ||
            (((baudRate * 16) > clockFreq) && (inst.ovsRate == "16")))
    {
        Common.logError(validation, inst,
            "ovsRate",
            "To select this oversampling rate, the target baud rate must be less than the UARTclk/oversamplingRate."
        )
    }

    /* Check if a higher oversampling rate can be selected */
    if (inst.ovsRate == "3") {
        if (baudRate < (clockFreq / 8))
        {
            Common.logWarning(validation, inst,
                "ovsRate",
                "A higher oversampling rate is possible given the target baud rate and UART clock source frequency. \
                It is recommended to pick a higher oversampling rate to improve tolerance to clock deviation."
            )
        }
        /* If 3x OVS selected, check if UART is in a valid mode */
        if (inst.uartMode == "DALI" || inst.enableIrda == true || inst.enableManchester == true)
        {
            Common.logError(validation, inst,
                "ovsRate",
                "IrDA, Manchester and DALI modes are not supported 3x oversampling is enabled."
            )
        }

    } else if (inst.ovsRate == "8") {
        if (baudRate < (clockFreq / 16))
        {
            Common.logWarning(validation, inst,
                "ovsRate",
                "A higher oversampling rate is possible given the target baud rate and UART clock source frequency. \
                It is recommended to pick a higher oversampling rate to increase the tolerance of the receiver to clock deviations."
            )
        }
    }

    /* Check if calculated baud is > 0.1% difference than target baud */
    if (inst.calculatedError > 0.1)
    {
        /* Speical case for 3x oversampling with LFCLK */
        if (inst.ovsRate == 3) {
            Common.logInfo(validation, inst,
                            "calculatedError",
                            "Using 3x oversampling with LFCLK can result in significant deviation in\
                            the actual baud rate."
            )
        } else {

            Common.logWarning(validation, inst,
                "calculatedError",
                "Actual baud rate differs significantly from requested. Try using a\
                different clock source, or adjusting the baud rate or oversampling rate if needed.\
                See detailed help."
            )
        }
    }

    /* Make sure clocks are initialized properly */
    if(inst.basicClockSourceCalculated == 0)
    {
        let str = "Clock Source " + inst.uartClkSrc + " not properly initialized in SYSCTL";
        validation.logError(str, inst, "uartClkSrc");
    }

    /* If ISO7816 Smart Card mode is selected, number of stop bits is forced to 2 */
    if(inst.uartMode == "SMART_CARD" && inst.stopBits != "TWO")
    {
        validation.logError("In ISO7816 Smart Code mode is selected, the stop bits should be 2.", inst, "stopBits");
    }

    /* In Idle-Line mode, parity must in no parity mode. */
    if(inst.uartMode == "IDLE_LINE" && inst.parity != "NONE")
    {
        validation.logError("In Idle-Line mode, parity must be in no parity mode.", inst, "parity");
    }

    /* In Idle-Line mode, word length must be set to 8 bits. */
    if(inst.uartMode == "IDLE_LINE" && inst.wordLength != "8_BITS")
    {
        validation.logError("In Idle-Line mode, word length must be set to 8 bits.", inst, "wordLength");
    }

}
