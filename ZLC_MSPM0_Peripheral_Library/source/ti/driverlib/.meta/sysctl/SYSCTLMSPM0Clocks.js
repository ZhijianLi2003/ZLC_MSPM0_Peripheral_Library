let Common = system.getScript("/ti/driverlib/Common.js");
let Options = system.getScript("/ti/driverlib/sysctl/SYSCTLMSPM0options.js");

const clkValidationSuperset = {

}

let clkConfigShell = {
    "SYSOSC": [],
    "ROSC": [],
    "LFCLK": [],
    "MCLK": [],
    "MFPCLK": [],
    "HFCLK": [],
    "CANCLK": [],
    "HSCLK": [],
    "SYSPLL": [],
    "LFXT": [],
    "HFXT": [],
    "UDIV": [],
}

const clkConfigSuperset = {
    "SYSOSC": [
        {
            name        : "usesSYSOSC",
            displayName : "Sourced By SYSOSC",
            description : "List of components of the Clock Tree being sourced by SYSOSC",
            hidden      : false,
            default     : "",
            getValue    : (inst) => {
                if(inst.clockTreeEn){
                    return "None";
                }
                let inUse = "";
                if(!inst.disableSYSOSC){
                    if(inst.MCLKSource === "SYSOSC"){
                        inUse+= "MCLK, ";
                    }
                    if(inst.MFPCLKEn && inst.MFPCLKSource === "SYSOSC"){
                        inUse+= "MFPCLK, ";
                    }
                    if(inst.MFCLKEn){
                        inUse+= "MFCLK, ";
                    }
                    if(inst.enableEXCLK && inst.EXCLKSource === "SYSOSC"){
                        inUse+= "CLK_OUT, ";
                    }
                    let ADCMod = system.modules["/ti/driverlib/ADC12"];
                    if (ADCMod){
                        let ADCInsts = ADCMod.$instances
                        for(let singleInst of ADCInsts){
                            if(singleInst.sampClkSrc === "DL_ADC12_CLOCK_SYSOSC"){
                                if(singleInst.peripheral.$solution){
                                    inUse+= singleInst.peripheral.$solution.peripheralName+" ADCCLK, ";
                                }
                            }
                        }
                    }
                }
                if(inUse.length == 0){
                    return "None"
                }

                return inUse;
            }
        },
        {
            name: "SYSOSC_Freq",
            displayName: "SYSOSC Frequency",
            //default: Options.SYSOSCFreq[0].name,
            default: Options.SYSOSCFreq[0].name,
            options: Options.SYSOSCFreq
        },
        // DL_SYSCTL_enableSYSOSCFCL [!]
        {
            name: "enableSYSOSCFCL",
            displayName: "Enable Frequency Correction Loop (FCL)",
            description: "Used to increase SYSOSC accuracy.",
            longDescription:
`
The SYSOSC frequency accuracy can be improved through the use of the SYSOSC frequency correction
loop (FCL) feature.The FCL circuit utilizes either an internal resistor or external resistor,
to stabilize the SYSOSC frequency by providing a precise reference current for the SYSOSC.

By default, this configuration enables the internal resistor FCL mode for supported devices.
`,
            default: false,
            hidden: false,
        },
    ],

    "ROSC": [
        {
            name: "enableROSC",
            displayName: "Enable External Ref. Resistor ROSC",
            description: "External Reference Resistor used to increase SYSOSC accuracy",
            default: false,
            hidden: false,
        },
    ],

    "LFCLK": [
        // DL_SYSCTL_setLFCLKSourceEXLF / setLFCLKSourceLFXT [!]
        {
            name: "LFCLKSource",
            displayName: "LFCLK Source",
            default: "LFOSC",
            options: Options.LFCLKSource,
            onChange: (inst,ui) => {
                if(inst.LFCLKSource == "LFCLK_IN"){
                    ui.LFCLK_Freq_IN.hidden = false;
                } else {
                    ui.LFCLK_Freq_IN.hidden = true;
                    inst.LFCLK_Freq_IN = 32768;
                }

                if(Common.isDeviceM0G() || Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()){
                    if(inst.LFCLKSource == "LFXT"){
                        inst.validateClkStatus = true;
                        ui.validateClkStatus.readOnly = true;
                    }
                    else{
                        ui.validateClkStatus.readOnly = (inst.useHFCLK_Manual && inst.HFCLKSource == "HFXT");
                    }
                }
            }
        },
        {
            name: "LFCLK_Freq_IN",
            displayName: "External LF Clock Frequency (Hz)",
            default: 32768,
            isInteger: true,
            range: [29491, 36045],
            hidden: true
        },
    ],

    "MFPCLK": [
        {
            name        : "MFPCLKEn",
            displayName : "Enable MFPCLK",
            description : '',
            hidden      : false,
            default     : false
        },
        {
            name        : "MFPCLKSource",
            displayName : "MFPCLK Source",
            description : 'Source for the Middle Frequency Precision (MFP) CLK',
            longDescription : `
The source for MFPCLK, designed to be accurately set to 4MHz for precision peripherals
such as DAC.
            `,
            hidden      : false,
            default     : "SYSOSC",
            options     : Options.MFPCLKSource,
            onChange: (inst, ui) => {
                if(inst.MFPCLKSource == "HFCLK")
                {
                    ui.HFCLK4MFPCLKDIV.hidden = false;
                } else {
                    ui.HFCLK4MFPCLKDIV.hidden = true;
                }
            }
        },
        // Currently this is always present even if if is not applicable
        // on a device, in which case it will be hidden and code generation
        // should be unaffected
        {
            name        : "HFCLK4MFPCLKDIV",
            displayName : "HFCLK Divider for MFPCLK",
            description : "Divider value for HFCLK to MFPCLK to divide down for 4MHz",
            hidden      : true,
            default     : "DISABLE",
            options     : [
            { name: "DISABLE" , displayName: "1"}, {name: "2" }, {name: "3" }, {name: "4" }, {name: "5" },
            {name: "6" }, {name: "7" }, {name: "8" }, {name: "9" }, {name: "10" }, {name: "11" }, {name: "12" },
            {name: "13" }, {name: "14" }, {name: "15"}, {name: "16"}
            ]
        }
    ],

    "MCLK": [

    ],

    "HFXT": [
        {
            name: "HFXTRange",
            displayName: "HFXT Frequency Range",
            default: "DL_SYSCTL_HFXT_RANGE_4_8_MHZ",
            hidden: false,
            options: [
                {name: "DL_SYSCTL_HFXT_RANGE_4_8_MHZ", displayName: "4 and 8 MHz"},
                {name: "DL_SYSCTL_HFXT_RANGE_8_16_MHZ", displayName: "8 and 16 MHz"},
                {name: "DL_SYSCTL_HFXT_RANGE_16_32_MHZ", displayName: "16 and 32 MHz"},
                {name: "DL_SYSCTL_HFXT_RANGE_32_48_MHZ", displayName: "32 and 48 MHz"},
            ],
            getValue: (inst) => {
                if (inst.HFCLK_Freq <= 8000000) { return "DL_SYSCTL_HFXT_RANGE_4_8_MHZ" }
                else if (inst.HFCLK_Freq > 8000000 && inst.HFCLK_Freq <= 16000000) { return "DL_SYSCTL_HFXT_RANGE_8_16_MHZ" }
                else if (inst.HFCLK_Freq > 16000000 && inst.HFCLK_Freq <= 32000000) { return "DL_SYSCTL_HFXT_RANGE_16_32_MHZ" }
                else if (inst.HFCLK_Freq > 32000000) { return "DL_SYSCTL_HFXT_RANGE_32_48_MHZ" }
                else{ return "DL_SYSCTL_HFXT_RANGE_32_48_MHZ"}
            }
        },
        {
            name        : "HFXTStartup",
            displayName : "HFXT Startup Time",
            description : 'Specify the HFXT startup time in 64us resolution.',
            hidden      : false,
            range       : [0,255],
            default     : 0
        },
        {
            name        : "HFXTStartupCalculated",
            displayName : "Calculated HFXT Startup Time",
            description : 'Specifies the HFXStartup time.',
            hidden      : false,
            default     : "0 s",
            getValue    : (inst) => {
                return (Common.getUnitPrefix(inst.HFXTStartup * 0.000064)).str+"s";
            },
        },
        {
            name        : "HFCLKMonitor",
            displayName : "HFCLK Startup Monitor",
            description : 'Enable the HFCLK startup monitor',
            hidden      : false,
            default     : false
        },

    ],

    "LFXT": [
        {
            name        : "LFCLKLowCap",
            displayName : "Low Cap Low Power Enable",
            description : 'Enable if CAP is less than 3pF to reduce power consumption',
            longDescription : 'Enable if CAP is less than 3pF to reduce power consumption',
            hidden      : false,
            default     : false
        },
        // DL_SYSCTL_setLFCLKSourceLFXT
        {
            name        : "LFCLKMonitor",
            displayName : "LFCLK Monitor Enable",
            description : 'Enable to use monitor for LFXT, EXLF failure',
            longDescription : 'Enable to use monitor for LFXT, EXLF failure',
            hidden      : false,
            default     : false
        },
        // DL_SYSCTL_setLFCLKSourceLFXT
        // DL_SYSCTL_LFXT_DRIVE_STRENGTH_[...]
        {
            name        : "LFCLKDriveStrength",
            displayName : "Drive Strength",
            description : 'Drive strength and power consumption option',
            hidden      : false,
            default     : "HIGHEST",
            options     : [
                {name: "LOWEST", displayName: "Lowest Drive and Current"},
                {name: "LOWER", displayName: "Lower Drive and Current"},
                {name: "HIGHER", displayName: "Higher Drive and Current"},
                {name: "HIGHEST", displayName: "Highest Drive and Current"},
            ],
        },
    ],

    "HFCLK": [
        {
            name        : "useHFCLK_Manual",
            displayName : "Enable HFCLK",
            longDescription: `This setting is automatically enabled when XTAL configuration is enabled.`,
            hidden      : false,
            default     : false,
            onChange: (inst,ui) =>{
                if(inst.useHFCLK_Manual && inst.HFCLKSource == "HFXT"){
                    inst.validateClkStatus = true;
                    ui.validateClkStatus.readOnly = true;
                }
                else{
                    ui.validateClkStatus.readOnly = (inst.LFCLKSource == "LFXT");
                }
            },
        },
        {
            name        : "useHFCLK",
            hidden      : true,
            default     : false,
            getValue    : (inst) => {
                /* HFCLK is not available for MSPM0L11XX_L13XX device family */
                if(Common.isDeviceFamily_PARENT_MSPM0L11XX_L13XX() || !inst.useHFCLK_Manual){
                    return false;
                }
                let inUse = false;
                if(inst.MCLKSource === "HSCLK" && "HFCLK" === inst.HSCLKSource){
                    return true;
                }
                if(inst.CANCLKSource === "HFCLK"){
                    return true;
                }
                if(inst.MCLKSource === "HSCLK" && inst.useSYSPLL && inst.SYSPLLSource === "HFCLK"){
                    return true;
                }
                if(inst.MFPCLKEn && inst.MFPCLKSource === "HFCLK"){
                    return true;
                }
                if(inst.enableEXCLK && inst.EXCLKSource === "HFCLK"){
                    return true;
                }
                if(inst.enableFCC && inst.fccClkSrc == "HFCLK"){
                    return true;
                }
                let ADCMod = system.modules["/ti/driverlib/ADC12"];
                if (ADCMod){
                    let ADCInsts = ADCMod.$instances
                    for(let singleInst of ADCInsts){
                        if(singleInst.sampClkSrc === "DL_ADC12_CLOCK_HFCLK"){
                           inUse = true;
                        }
                    }
                }
                return inUse;
            }
        },
        {
            name        : "usesHFCLK",
            displayName : "Sourced By HFCLK",
            description : "List of components of the Clock Tree being sourced by HFCLK",
            hidden      : false,
            default     : "",
            getValue    : (inst) => {
                /* HFCLK is not available for MSPM0L11XX_L13XX device family */
                if(Common.isDeviceFamily_PARENT_MSPM0L11XX_L13XX() || inst.clockTreeEn){
                    return "None";
                }
                let inUse = "";
                if(inst.MCLKSource === "HSCLK" && "HFCLK" === inst.HSCLKSource){
                    inUse+= "MCLK, ";
                }
                if((inst.MCLKSource === "HSCLK")&&
                    (["SYSPLLCLK0","SYSPLLCLK2X"].includes(inst.HSCLKSource))){
                    if(inst.SYSPLLSource === "HFCLK"){
                        inUse+= "SYSPLL, ";
                    }
                }
                if(inst.MFPCLKEn && inst.MFPCLKSource === "HFCLK"){
                    inUse+= "MFPCLK, ";
                }
                if(inst.enableFCC && inst.fccClkSrc == "HFCLK"){
                    inUse+= "FCC, "
                }
                let ADCMod = system.modules["/ti/driverlib/ADC12"];
                if (ADCMod){
                    let ADCInsts = ADCMod.$instances
                    for(let singleInst of ADCInsts){
                        if(singleInst.sampClkSrc === "DL_ADC12_CLOCK_HFCLK"){
                            if(singleInst.peripheral.$solution){
                                inUse+= singleInst.peripheral.$solution.peripheralName+" ADCCLK, ";
                            }
                        }
                    }
                }
                if(inst.enableEXCLK && inst.EXCLKSource === "HFCLK"){
                    inUse+= "CLK_OUT, ";
                }
                if(inst.CANCLKSource === "HFCLK"){
                    inUse+= "CANCLK, ";
                }

                if(inUse.length == 0){
                    return "None"
                }

                return inUse;
            }
        },
        // setHFCLKSourceHFXT / setHFCLKSourceHFXTParams / setHFCLKSourceHFCLKIN
        {
            name: "HFCLKSource",
            displayName: "HFCLK Source",
            default: "HFCLK_IN",
            options: Options.HFCLKSource,
            onChange: (inst,ui) =>{
                if(inst.useHFCLK_Manual && inst.HFCLKSource == "HFXT"){
                    inst.validateClkStatus = true;
                    ui.validateClkStatus.readOnly = true;
                }
                else{
                    ui.validateClkStatus.readOnly = (inst.LFCLKSource == "LFXT");
                }
            },
        },
        // DL_SYSCTL_setHFCLKSourceHFXTParams -> range
        {
            name: "HFCLK_Freq",
            displayName: "External HF Clock Frequency (Hz)",
            default: 4000000,
            isInteger: true,
            range: [4000000,48000000]
        },
    ],

    "CANCLK": [
        {
            name: "CANCLKSource",
            displayName: "CANCLK Source",
            description: "Specifies the clock source of the CAN Clock",
            default: "None",
            hidden: (Common.isDeviceM0G() === false),
            options: [
                { name: "None" },
                { name: "SYSPLLCLK1" },
                { name: "HFCLK" },
            ]
        },
    ],

    "HSCLK": [
        {
            name: "HSCLKSource",
            displayName: "HSCLK Source",
            description: "Specifies the clock source of the High Speed Clock",
            default: Options.HSCLKSource[0].name,
            hidden: true,
            options: Options.HSCLKSource,
        },
        {
            name: "HSCLK_Freq",
            default: 0,
            hidden: true,
            getValue: (inst) => {
                switch(inst.HSCLKSource){
                    case "HFCLK":
                        return inst.HFCLK_Freq;
                    case "SYSPLLCLK0":
                        return inst.SYSPLLSource != "Disabled"? inst.SYSPLL_Freq_CLK0 : 0;
                    case "SYSPLLCLK2X":
                        return inst.SYSPLLSource != "Disabled"? inst.SYSPLL_Freq_CLK2X : 0;
                        break;
                    default:
                        return 0;
                }
            }
        },
    ],

    "SYSPLL": [
        {
            name        : "useSYSPLL",
            hidden      : true,
            default     : false,
            getValue    : (inst) => {
                /* SYSPLL is not available foor M0Lx device family */
                if(Common.isDeviceM0L() || Common.isDeviceM0C() || inst.clockTreeEn){
                    return false;
                }
                if((inst.MCLKSource === "HSCLK")&&
                (["SYSPLLCLK0","SYSPLLCLK2X"].includes(inst.HSCLKSource))){
                    return true;
                }
                if(inst.enableEXCLK && inst.EXCLKSource === "SYSPLLOUT1"){
                    return true;
                }
                if(inst.enableFCC && (["SYSPLLCLK0","SYSPLLCLK1","SYSPLLCLK2X"].includes(inst.fccClkSrc))){
                    return true;
                }
                if(inst.CANCLKSource === "SYSPLLCLK1"){
                    return true;
                }
                return false;
            }
        },
        {
            name        : "usesSYSPLL",
            displayName : "Sourced By SYSPLL",
            description : "List of components of the Clock Tree being sourced by SYSPLL",
            hidden      : false,
            default     : "",
            getValue    : (inst) => {
                /* SYSPLL is not available foor M0Lx device family */
                if(Common.isDeviceM0L() || Common.isDeviceM0C() || inst.clockTreeEn){
                    return "";
                }
                let inUse = "";
                if((inst.MCLKSource === "HSCLK")&&(["SYSPLLCLK0","SYSPLLCLK2X"].includes(inst.HSCLKSource))){
                    inUse += "MCLK, "
                }
                if(inst.enableEXCLK && (inst.EXCLKSource === "SYSPLLOUT1")){
                    inUse += "CLK_OUT, ";
                }
                if(inst.enableFCC && (["SYSPLLCLK0","SYSPLLCLK1","SYSPLLCLK2X"].includes(inst.fccClkSrc))){
                    inUse+= "FCC, "
                }
                if((inst.CANCLKSource === "SYSPLLCLK1")){
                    inUse += "CANCLK, "
                }
                if(inUse.length == 0){
                    return "None"
                }

                return inUse;
            }
        },
        // DL_SYSCTL_configSYSPLL
        {
            name: "SYSPLLSource",
            displayName: "SYSPLL Reference Clock (SYSPLLREF)",
            description : "The available reference clocks for the SYSPLL include SYSOSC and HFCLK.",
            longDescription : "The available reference clocks for the SYSPLL include SYSOSC and HFCLK.",
            default: "SYSOSC",
            options: [
                { name: "SYSOSC" }, { name: "HFCLK"},
            ]
        },
        {
            name        : "SYSPLLSource_freq",
            displayName : "SYSPLL Reference Clock Frequency",
            hidden      : true,
            getValue    : (inst) => {
                let sourceFreq = 0;
                switch (inst.SYSPLLSource){
                   case "SYSOSC":
                        sourceFreq = inst.SYSOSC_Freq;
                    break;
                    case "HFCLK":
                        sourceFreq = inst.HFCLK_Freq;
                    break;
                }
                return sourceFreq;
            },
            default     : 0
        },
        {
            name        : "SYSPLLSource_freq_disp",
            displayName : "SYSPLL Reference Clock Frequency",
            longDescription :
`The output frequency of the SYSPLL reference clock, fSYSPLL. The SYSPLL accepts an input reference clock from 4-48 MHz.`,
            hidden      : false,
            default     : "0 Hz",
            getValue: (inst) => {
                return (Common.getUnitPrefix(inst.SYSPLLSource_freq)).str+"Hz";
            }
        },
        {
            name: "SYSPLL_Pdiv",
            displayName: "SYSPLL Predivider (PDIV)",
            description: "Scales the selected input reference clock ahead of the feedback loop",
            longDescription:
`
PDIV can be selected as /1, /2, /4, or /8.\n
The SYSPLL reference clock, SYSPLLREF, will be scaled by the value selected by PDIV.
`,
            default: 2,
            options: [
                { name: 1, displayName: "Divide by 1" },
                { name: 2, displayName: "Divide by 2" },
                { name: 4, displayName: "Divide by 4" },
                { name: 8, displayName: "Divide by 8" },
            ]
        },
        {
            name: "SYSPLL_InputCLKFreqRange_disp",
            displayName: "SYSPLL Input Freq Range (fLOOPIN)",
            longDescription:
`
The predivider PDIV scales the selected input reference clock ahead of the PLL feedback loop.\n
This scaled input reference clock fed into the PLL feedback loop is fLOOPIN, and is calculated as:\n
fLOOPIN = SYSPLLREF / PDIV \n

For example, if the input SYSPLL reference is 32MHz, and PDIV is set to Divide by 2, then fLOOPIN is 16MHz:
fLOOPIN = fSYSPLLREF / PDIV \n
fLOOPIN = 32MHz / 2 \n
fLOOPIN = 16MHz \n
`,

            default: "0 Hz",
            hidden: false,
            getValue: (inst) => {
                let sourecFreq
                if (inst.SYSPLLSource == "SYSOSC")
                {
                    sourecFreq = inst.SYSOSC_Freq;
                }
                if (inst.SYSPLLSource == "HFCLK")
                {
                    sourecFreq = inst.HFCLK_Freq;
                }
                let floopin = sourecFreq / inst.SYSPLL_Pdiv;
                return (Common.getUnitPrefix(floopin)).str+"Hz";
            }
        },
        {
            name: "SYSPLL_InputCLKFreqRange",
            displayName: "SYSPLL Input Clock Frequency Range",
            default: "DL_SYSCTL_SYSPLL_INPUT_FREQ_32_48_MHZ",
            hidden: true,
            options: [
                {name: "DL_SYSCTL_SYSPLL_INPUT_FREQ_4_8_MHZ", displayName: "4 MHz to 8 MHz"},
                {name: "DL_SYSCTL_SYSPLL_INPUT_FREQ_8_16_MHZ", displayName: "8 MHz to 16 MHz"},
                {name: "DL_SYSCTL_SYSPLL_INPUT_FREQ_16_32_MHZ", displayName: "16 MHz to 32 MHz"},
                {name: "DL_SYSCTL_SYSPLL_INPUT_FREQ_32_48_MHZ", displayName: "32 MHz to 48 MHz"},
                /* special case for when out of range */
                {name: "DL_SYSCTL_SYSPLL_INPUT_FREQ_OUT_OF_RANGE", displayName: "OUT OF RANGE"}
            ],
            getValue: (inst) => {
                let floopin = inst.SYSPLLSource_freq / inst.SYSPLL_Pdiv;
                if (floopin >= 48000000)
                {
                    return "DL_SYSCTL_SYSPLL_INPUT_FREQ_OUT_OF_RANGE";
                }
                else if (floopin >= 32000000)
                {
                    return "DL_SYSCTL_SYSPLL_INPUT_FREQ_32_48_MHZ";
                }
                else if (floopin >= 16000000)
                {
                    return "DL_SYSCTL_SYSPLL_INPUT_FREQ_16_32_MHZ";
                }
                else if (floopin >= 8000000)
                {
                    return "DL_SYSCTL_SYSPLL_INPUT_FREQ_8_16_MHZ";
                }
                else if (floopin >= 4000000)
                {
                    return "DL_SYSCTL_SYSPLL_INPUT_FREQ_4_8_MHZ";
                }
                else
                {
                    return "DL_SYSCTL_SYSPLL_INPUT_FREQ_OUT_OF_RANGE";
                }
            }
        },
        // DL_SYSCTL_configSYSPLL
        {
            name: "SYSPLL_Qdiv",
            displayName: "SYSPLL Feedback Divider (QDIV)",
            description: "Multiplied with the divided input reference clock",
            longDescription:
`
The PLL feedback loop sets the VCO output, fVCO, equal to the divided input reference clock fLOOPIN multiplied by
the QDIV feedback divider. The QDIV divider is an integer divider with a valid range of /2 to /128.
`,
            isInteger: true,
            default: 10,
            range: [2, 128],
        },
        {
            name: "SYSPLL_VCOFreq",
            displayName: "Calculated PLL VCO Freq (Hz)",
            description: "VCO output frequency that is set by the SYSPLL feedback loop",
            longDescription:
`
The PLL feedback loop sets the VCO output, fVCO, equal to the divided input reference clock fLOOPIN multiplied by
the QDIV feedback divider. The QDIV divider is an integer divider with a valid range of /2 to /128.
`,
            default: 0,
            hidden: true,
            getValue: (inst) => {
                if(inst.SYSPLLSource == "SYSOSC") {
                    /*
                     * SYSOSC must be running at 32MHz (base frequency)
                     * for SYSPLL operation, even if HFCLK is the
                     * reference clock
                     */
                    return (32000000 / inst.SYSPLL_Pdiv) * inst.SYSPLL_Qdiv;
                } else if (inst.SYSPLLSource == "HFCLK") {
                    return (inst.HFCLK_Freq / inst.SYSPLL_Pdiv) * inst.SYSPLL_Qdiv;
                } else {
                    return 0;
                }
            }
        },
        {
            name: "SYSPLL_VCOFreq_disp",
            displayName: "Calculated VCO Freq (fVCO)",
            description: "VCO output frequency that is set by the SYSPLL feedback loop",
            longDescription:
`
The output frequency of the VCO, fVCO is calculated as:\n

fVCO = fSYSPLLREF / PDIV * QDIV\n

For example, if fSYSPLL is 32MHz, PDIV is set to /2, and QDIV is set to 10, then fVCO is calculated to be 160MHz.\n
fVCO = fSYSPLLREF / PDIV * QDIV\n
fVCO = 32MHz / 2 * 10 \n
fVCO = 160MHz \n
`,
            default: "0 Hz",
            hidden: false,
            getValue: (inst) => {
                return (Common.getUnitPrefix(inst.SYSPLL_VCOFreq)).str+"Hz";
            }
        },
        // DL_SYSCTL_configSYSPLL
        {
            name: "SYSPLL_CLK0En",
            displayName: "Enable SYSPLLCLK0",
            description: "Enables SYSPLL output clock SYSPLLCLK0",
            longDescription:
`
The VCO output sources three separate SYSPLL outputs (SYSPLLCLK0, SYSPLLCLK1, and SYSPLLCLK2X).
Each output has its own divider unit to enable generation of up to 3 different output frequencies for use by
different modules in the device. The third output (SYSPLLCLK2X) also contains a frequency doubler before the
divider unit to provide a wider range of output frequencies and lower power consumption.
`,
            default: false,
            onChange: (inst, ui) => {
                ui.SYSPLL_CLK0Div.hidden = !inst.SYSPLL_CLK0En;
            }
        },
        // DL_SYSCTL_configSYSPLL
        {
            name: "SYSPLL_CLK0Div",
            displayName: "SYSPLLCLK0 Divider",
            description: "Scales the output frequency of SYSPLLCLK0",
            longDescription:
`
For SYSPLLCLK1 and SYSPLLCLK0, the output dividers can be set from /2 to /32 in steps of 2.
The SYSPLL output clock frequencies are thus set by the combination of fVCO and the respective dividers.\n
`,
            hidden: true,
            default: 0,
            options: [
                { name: 0, displayName: "Divide by 2" },
                { name: 1, displayName: "Divide by 4" },
                { name: 2, displayName: "Divide by 6" },
                { name: 3, displayName: "Divide by 8" },
                { name: 4, displayName: "Divide by 10" },
                { name: 5, displayName: "Divide by 12" },
                { name: 6, displayName: "Divide by 14" },
                { name: 7, displayName: "Divide by 16" },
                { name: 8, displayName: "Divide by 18" },
                { name: 9, displayName: "Divide by 20" },
                { name: 10, displayName: "Divide by 22" },
                { name: 11, displayName: "Divide by 24" },
                { name: 12, displayName: "Divide by 26" },
                { name: 13, displayName: "Divide by 28" },
                { name: 14, displayName: "Divide by 30" },
                { name: 15, displayName: "Divide by 32" },
            ]
        },
        {
            name: "SYSPLL_Freq_CLK0",
            displayName: "Calculated SYSPLLCLK0 Output Freq (Hz)",
            description: "Clock frequency that is output by the SYSPLLCLK0",
            default: 0,
            hidden: true,
            getValue: (inst) => {
                let outputFreq = 0;

                if (inst.SYSPLL_CLK0En == true)
                {
                    outputFreq = inst.SYSPLL_VCOFreq / ((inst.SYSPLL_CLK0Div + 1) * 2);
                }

                return outputFreq;
            }
        },
        {
            name: "SYSPLL_Freq_CLK0_display",
            displayName: "Calculated SYSPLLCLK0 Output Freq",
            description: "Clock frequency that is output by the SYSPLLCLK0",
            longDescription:
`
The SYSPLLCLK0 output is calculated as shown:\n

fSYSPLLCLK0 = fVCO / SYSPLLCLK0DIV\n

For example, if fSYSPLL is 32MHz, PDIV is set to /2, QDIV is set to 10, then fVCO is 160MHz. Then, if SYSPLLCLK0DIV is set to /2, the output frequency of SYSPLLCLK0 is 80MHz.\n
fSYSPLLCLK0 = fVCO / SYSPLLCLK0DIV\n
fSYSPLLCLK0 = 160MHz / 2\n
fSYSPLLCLK0 = 80MHz \n
`,
            default: "0 Hz",
            hidden: false,
            getValue: (inst) => {
                return (Common.getUnitPrefix(inst.SYSPLL_Freq_CLK0)).str+"Hz";
            }
        },
        // DL_SYSCTL_configSYSPLL
        {
            name: "SYSPLL_CLK1En",
            displayName: "Enable SYSPLLCLK1",
            description: "Enables SYSPLL output clock SYSPLLCLK1",
            longDescription:
`
The VCO output sources three separate SYSPLL outputs (SYSPLLCLK0, SYSPLLCLK1, and SYSPLLCLK2X).
Each output has its own divider unit to enable generation of up to 3 different output frequencies for use by
different modules in the device. The third output (SYSPLLCLK2X) also contains a frequency doubler before the
divider unit to provide a wider range of output frequencies and lower power consumption.
`,
            default: false,
            onChange: (inst, ui) => {
                ui.SYSPLL_CLK1Div.hidden = !inst.SYSPLL_CLK1En;
            }
        },
        // DL_SYSCTL_configSYSPLL
        {
            name: "SYSPLL_CLK1Div",
            displayName: "SYSPLLCLK1 Divider",
            description: "Scales the output frequency of SYSPLLCLK1",
            longDescription:
`
For SYSPLLCLK1 and SYSPLLCLK0, the output dividers can be set from /2 to /32 in steps of 2.
The SYSPLL output clock frequencies are thus set by the combination of fVCO and the respective dividers.\n
`,
            hidden: true,
            default: 0,
            options: [
                { name: 0, displayName: "Divide by 2" },
                { name: 1, displayName: "Divide by 4" },
                { name: 2, displayName: "Divide by 6" },
                { name: 3, displayName: "Divide by 8" },
                { name: 4, displayName: "Divide by 10" },
                { name: 5, displayName: "Divide by 12" },
                { name: 6, displayName: "Divide by 14" },
                { name: 7, displayName: "Divide by 16" },
                { name: 8, displayName: "Divide by 18" },
                { name: 9, displayName: "Divide by 20" },
                { name: 10, displayName: "Divide by 22" },
                { name: 11, displayName: "Divide by 24" },
                { name: 12, displayName: "Divide by 26" },
                { name: 13, displayName: "Divide by 28" },
                { name: 14, displayName: "Divide by 30" },
                { name: 15, displayName: "Divide by 32" },
            ]
        },
        {
            name: "SYSPLL_Freq_CLK1",
            displayName: "Calculated SYSPLLCLK1 Output Freq (Hz)",
            description: "Clock frequency that is output by the SYSPLLCLK1",
            default: 0,
            hidden: true,
            getValue: (inst) => {
                let outputFreq = 0;

                if (inst.SYSPLL_CLK1En == true)
                {
                    outputFreq = inst.SYSPLL_VCOFreq / ((inst.SYSPLL_CLK1Div + 1) * 2);
                }

                return outputFreq;
            }
        },
        {
            name: "SYSPLL_Freq_CLK1_display",
            displayName: "Calculated SYSPLLCLK1 Output Freq",
            description: "Clock frequency that is output by the SYSPLLCLK1",
            longDescription:
`
The SYSPLLCLK1 output is calculated as shown:\n

fSYSPLLCLK1 = fVCO / SYSPLLCLK1DIV\n

For example, if fSYSPLL is 32MHz, PDIV is set to /2, QDIV is set to 10, then fVCO is 160MHz. Then, if SYSPLLCLK1DIV is set to /2, the output frequency of SYSPLLCLK1 is 80MHz.\n
fSYSPLLCLK1 = fVCO / SYSPLLCLK1DIV\n
fSYSPLLCLK1 = 160MHz / 2\n
fSYSPLLCLK1 = 80MHz \n
`,
            default: "0 Hz",
            hidden: false,
            getValue: (inst) => {
                return (Common.getUnitPrefix(inst.SYSPLL_Freq_CLK1)).str+"Hz";
            }
        },
        // DL_SYSCTL_configSYSPLL
        {
            name: "SYSPLL_CLK2XEn",
            displayName: "Enable SYSPLLCLK2X",
            description: "Enables SYSPLL output clock SYSPLLCLK2X",
            longDescription:
`
The VCO output sources three separate SYSPLL outputs (SYSPLLCLK0, SYSPLLCLK1, and SYSPLLCLK2X).
Each output has its own divider unit to enable generation of up to 3 different output frequencies for use by
different modules in the device. The third output (SYSPLLCLK2X) also contains a frequency doubler before the
divider unit to provide a wider range of output frequencies and lower power consumption.
`,
            default: false,
            onChange: (inst, ui) => {
                ui.SYSPLL_CLK2XDiv.hidden = !inst.SYSPLL_CLK2XEn;
            }
        },
        // DL_SYSCTL_configSYSPLL
        {
            name: "SYSPLL_CLK2XDiv",
            displayName: "SYSPLLCLK2X Divider",
            description: "Scales the output frequency of SYSPLLCLK2X",
            longDescription:
`
For SYSPLLCLK2X, the output divider can be set from /1 to /16 in steps of 1.\n

SYSPLLCLK2X also contains a frequency doubler before the
divider unit to provide a wider range of output frequencies and lower power consumption.\n

The SYSPLL output clock frequencies are thus set by the combination of fVCO and the respective dividers.\n
`,
            hidden: true,
            default: 0,
            options: [
                { name: 0, displayName: "Divide by 1" },
                { name: 1, displayName: "Divide by 2" },
                { name: 2, displayName: "Divide by 3" },
                { name: 3, displayName: "Divide by 4" },
                { name: 4, displayName: "Divide by 5" },
                { name: 5, displayName: "Divide by 6" },
                { name: 6, displayName: "Divide by 7" },
                { name: 7, displayName: "Divide by 8" },
                { name: 8, displayName: "Divide by 9" },
                { name: 9, displayName: "Divide by 10" },
                { name: 10, displayName: "Divide by 11" },
                { name: 11, displayName: "Divide by 12" },
                { name: 12, displayName: "Divide by 13" },
                { name: 13, displayName: "Divide by 14" },
                { name: 14, displayName: "Divide by 15" },
                { name: 15, displayName: "Divide by 16" },
            ]
        },
        {
            name: "SYSPLL_Freq_CLK2X",
            displayName: "Calculated SYSPLLCLK2X Output Freq (Hz)",
            description: "Clock frequency that is output by the SYSPLLCLK2X",
            default: 0,
            hidden: true,
            getValue: (inst) => {
                let outputFreq = 0;

                if (inst.SYSPLL_CLK2XEn == true)
                {
                    outputFreq = 2 * (inst.SYSPLL_VCOFreq / (inst.SYSPLL_CLK2XDiv + 1));
                }

                return outputFreq;
            }
        },
        {
            name: "SYSPLL_Freq_CLK2X_display",
            displayName: "Calculated SYSPLLCLK2X Output Freq",
            description: "Clock frequency that is output by the SYSPLLCLK2X",
            longDescription:
`
SYSPLLCLK2X contains a frequency doubler before the divider unit.
Therefore the SYSPLLCLK2 output is calculated as shown:\n

fSYSPLLCLK2 = 2 * fVCO / SYSPLLCLK2DIV\n

For example, if fSYSPLL is 32MHz, PDIV is set to /2, QDIV is set to 10, then fVCO is 160MHz. Then, if SYSPLLCLK2DIV is set to /4, the output frequency of SYSPLLCLK2 is 80MHz.\n
fSYSPLLCLK2 = 2 * fVCO / SYSPLLCLK2DIV\n
fSYSPLLCLK2 = 2 * 160MHz / 4\n
fSYSPLLCLK2 = 80MHz \n
`,
            default: "0 Hz",
            hidden: false,
            getValue: (inst) => {
                return (Common.getUnitPrefix(inst.SYSPLL_Freq_CLK2X)).str+"Hz";
            }
        },
    ],

    "UDIV": [
        {
            name: "UDIV",
            displayName: "ULPCLK Divider",
            description: "ULPCLK is MCLK divided by this value.",
            default: "1",
            options: [ { name: "1" }, { name: "2" }, { name: "3" } ]
        }
    ],
}

const clkFreqSuperset = {
    "ADCCLK_0": [
        { name: "ADC0_ADCCLK_Freq", displayName: "ADC0 ADCCLK", default: 32000000, hidden: true,
            getValue: (inst) => {
                let ADCMod = system.modules["/ti/driverlib/ADC12"];
                if (ADCMod){
                    let ADCInsts = ADCMod.$instances
                    for(let singleInst of ADCInsts){
                        if(singleInst.peripheral.$solution){
                            if(singleInst.peripheral.$solution.peripheralName == "ADC0"){
                                return singleInst.inputClock_Freq
                            }
                        }
                    }
                }
                return inst.SYSOSC_Freq
            },
        },
        { name: "ADC0_ADCCLK_Freq_unit", displayName: "ADC0 ADCCLK", default: "32 MHz", readOnly: true, getValue: (inst)=>{return (Common.getUnitPrefix(inst.ADC0_ADCCLK_Freq)).str+"Hz"}},
    ],
    "ADCCLK_1": [
        { name: "ADC1_ADCCLK_Freq", displayName: "ADC1 ADCCLK", default: 32000000, hidden: true,
                getValue: (inst) => {
                    let ADCMod = system.modules["/ti/driverlib/ADC12"];
                    if (ADCMod){
                        let ADCInsts = ADCMod.$instances
                        for(let singleInst of ADCInsts){
                            if(singleInst.peripheral.$solution){
                                if(singleInst.peripheral.$solution.peripheralName == "ADC1"){
                                    return singleInst.inputClock_Freq
                                }
                            }
                        }
                    }
                    return inst.SYSOSC_Freq;
                },
            },
            { name: "ADC1_ADCCLK_Freq_unit", displayName: "ADC1 ADCCLK", default: "32 MHz", readOnly: true, getValue: (inst)=>{return (Common.getUnitPrefix(inst.ADC1_ADCCLK_Freq)).str+"Hz"}},
    ],
    "CANCLK": [
        { name: "CANCLK_Freq", displayName: "CANCLK", default: 48000000, readOnly: true, hidden: true,
            getValue: (inst) => {
                if(inst.clockTreeEn){
                    return system.clockTree["net_canclk"].in * 1000000;
                }else{
                    if(inst.CANCLKSource == "SYSPLLCLK1")
                    {
                        return inst.SYSPLL_Freq_CLK1;
                    }else if(inst.CANCLKSource == "HFCLK" && inst.useHFCLK_Manual){
                        return inst.HFCLK_Freq;
                    }else{
                        return 0;
                    }
                }
            }},
        { name: "CANCLK_Freq_unit", displayName: "CANCLK", default: "48 MHz", readOnly: true, getValue: (inst)=>{return (Common.getUnitPrefix(inst.CANCLK_Freq)).str+"Hz"}},
    ],
    "CPUCLK": [
        { name: "CPUCLK_Freq", displayName: "CPUCLK", default: 32000000, hidden: true, getValue: (inst) => { return inst.MCLK_Freq; } },
        { name: "CPUCLK_Freq_unit", displayName: "CPUCLK", default: "32 MHz", readOnly: true, getValue: (inst)=>{return (Common.getUnitPrefix(inst.CPUCLK_Freq)).str+"Hz"}},
    ],
    "LFCLK": [
        { name: "LFCLK_Freq", displayName: "LFCLK", default: 32768, hidden: true,
            getValue: (inst) => {
                if(inst.clockTreeEn){
                    return system.clockTree["net_lfclk"].in * 1000000;
                }
                switch(inst.LFCLKSource){
                    case "LFOSC":
                        return 32768;
                    case "LFXT":
                    case "LFCLK_IN":
                        return inst.LFCLK_Freq_IN;
                }
            }
        },
        { name: "LFCLK_Freq_unit", displayName: "LFCLK", default: "32.7 kHz", readOnly: true, getValue: (inst)=>{return (Common.getUnitPrefix(inst.LFCLK_Freq)).str+"Hz"}},
    ],
    "MCLK": [
        { name: "MCLK_Freq",  displayName: "MCLK",  default: 32000000, hidden: true,
            getValue: (inst) => {
                if(inst.clockTreeEn){
                    return system.clockTree["net_mclk"].in * 1000000;
                }
                switch(inst.MCLKSource) {
                    case "SYSOSC":
                        return inst.MDIV == "DISABLE" ? inst.SYSOSC_Freq : inst.SYSOSC_Freq / parseInt(inst.MDIV);
                    case "HSCLK":
                        if(Common.isDeviceM0G()){
                            return inst.MDIV == "DISABLE" ? inst.HSCLK_Freq : inst.HSCLK_Freq / parseInt(inst.MDIV);
                        }
                        else{
                            return 0;
                        }
                    case "LFCLK":
                        return inst.LFCLK_Freq;
                    default:
                        return 0;
                }
            }
        },
        { name: "MCLK_Freq_unit", displayName: "MCLK", default: "32 MHz", readOnly: true, getValue: (inst)=>{return (Common.getUnitPrefix(inst.MCLK_Freq)).str+"Hz"}},
    ],
    "MFCLK": [
        { name: "MFCLK_Freq", displayName: "MFCLK", default: 4000000, hidden: true,
            getValue: (inst) => {
                if(inst.clockTreeEn){
                    return system.clockTree["net_mfclk"].in * 1000000;
                }
                return inst.MFCLKEn ? 4000000 : 0;
            }
        },
        { name: "MFCLK_Freq_unit", displayName: "MFCLK", default: "4 MHz", readOnly: true, getValue: (inst)=>{return (Common.getUnitPrefix(inst.MFCLK_Freq)).str+"Hz"}},
    ],
    "MFPCLK": [
        { name: "MFPCLK_Freq", displayName: "mfpclk_freq", default: 4000000, hidden: true, readOnly: true,
            getValue: (inst) => {
                if(inst.clockTreeEn){
                    return system.clockTree["net_mfpclk"].in * 1000000;
                } else if(inst.MFPCLKEn && inst.MFPCLKSource === "HFCLK"){
                    return inst.HFCLK_FreqOut / ((inst.HFCLK4MFPCLKDIV == "DISABLE") ? 1 : parseInt(inst.HFCLK4MFPCLKDIV))
                } else {
                    return inst.MFPCLKEn ? 4000000:0;
                }
            }
        },
        { name: "MFPCLK_Freq_unit", displayName: "MFPCLK", default: "4 MHz", readOnly: true, getValue: (inst)=>{ return (Common.getUnitPrefix(inst.MFPCLK_Freq)).str+"Hz"}},
    ],
    "RTCCLK": [
        { name: "RTCCLK_Freq", displayName: "RTCCLK", default: 32768, readOnly: true, hidden: true,},
        { name: "RTCCLK_Freq_unit", displayName: "RTCCLK", default: "32.7 kHz", readOnly: true, getValue: (inst)=>{return (Common.getUnitPrefix(inst.RTCCLK_Freq)).str+"Hz"}},
    ],
    "HFCLK": [
        { name: "HFCLK_FreqOut", displayName: "HFCLK", default: 0, hidden: true, readOnly: true,
            getValue: (inst) => {
                if(inst.clockTreeEn && (Common.isDeviceM0G() || Common.isDeviceFamily_PARENT_MSPM0L122X_L222X())){
                    return system.clockTree["net_hfclk"].in * 1000000;
                }
                if(inst.clockTreeEn && Common.isDeviceM0C()){
                    return system.clockTree["net_hfclkext"].in * 1000000;
                }
                return inst.useHFCLK_Manual?inst.HFCLK_Freq:0;
            }
        },
        { name: "HFCLK_Freq_unit", displayName: "HFCLK", default: "0 MHz", readOnly: true, getValue: (inst)=>{return (Common.getUnitPrefix(inst.HFCLK_FreqOut)).str+"Hz"}},
    ],
    "ULPCLK": [
        { name: "ULPCLK_Freq", displayName: "ULPCLK", default: 32000000, hidden: true,
            getValue: (inst) => {
                if(inst.clockTreeEn){
                    return system.clockTree["net_ulpclk"].in * 1000000;
                }
                if(Common.isDeviceM0G()){
                    return inst.MCLK_Freq / parseInt(inst.UDIV);
                }
                else if(Common.isDeviceM0L() || Common.isDeviceM0C()){
                    return inst.MCLK_Freq;
                }
                else return 0;
            }
        },
        { name: "ULPCLK_Freq_unit", displayName: "ULPCLK", default: "32 MHz", readOnly: true, getValue: (inst)=>{return (Common.getUnitPrefix(inst.ULPCLK_Freq)).str+"Hz"}},
    ],
    "SYSOSC": [
        { name: "SYSOSC_FreqOut", displayName: "SYSOSC", default: 32000000, hidden: true,
            getValue: (inst) => {
                if(inst.clockTreeEn){
                    return system.clockTree["net_sysosc"].in * 1000000;
                } else {
                    return inst.SYSOSC_Freq;
                }
            }
        },
        { name: "SYSOSC_Freq_unit", displayName: "SYSOSC", default: "32 MHz", readOnly: true, getValue: (inst)=>{return (Common.getUnitPrefix(inst.SYSOSC_FreqOut)).str+"Hz"}},
    ]
};

const commonClockSignals = [
    "SYSOSC",
    "MCLK",
    "ULPCLK",
    "CPUCLK",
    "LFCLK",
    "MFCLK",
    "CLK_OUT",
    "ADCCLK_0",
];

/* Eventually would be replaced by internal device data */
const ClockSignals = {
    "MSPM0G1X0X_G3X0X": [
        "MFPCLK",
        "ADCCLK_1",
        "CANCLK",
        "RTCCLK",
        "HFCLK",
        "HFXT",
        "LFXT",
        "HSCLK",
        "SYSPLL",
        "UDIV",
        "ROSC",
        ... commonClockSignals,
    ],
    "MSPM0L11XX_L13XX": [
        "MFPCLK",
        "ROSC",
        ... commonClockSignals,
    ],
    "MSPM0L122X_L222X": [
        "MFPCLK",
        "HFCLK",
        "HFXT",
        "HSCLK",
        "LFXT",
        "ROSC",
        ... commonClockSignals,
    ],
    "MSPM0C110X": [
        "HFCLK",
        "HSCLK",
        ... commonClockSignals,
    ],
    "MSPM0GX51X": [
        "MFPCLK",
        "ADCCLK_1",
        "CANCLK",
        "RTCCLK",
        "HFCLK",
        "HFXT",
        "LFXT",
        "HSCLK",
        "SYSPLL",
        "UDIV",
        "ROSC",
        ... commonClockSignals,
    ],
};


let index = Common.getDeviceFamily();




exports = {
    ClockConfig: Object.assign(clkConfigShell, _.pick(clkConfigSuperset, ClockSignals[index])),
    ConfigurableList: _.flatMap(_.pick(clkConfigSuperset, ClockSignals[index]), (x)=>{return _.map(_.filter(x,_.isUndefined(x.getValue)), "name");}),
    ClockFrequencies: _.flatMap(_.pick(clkFreqSuperset, ClockSignals[index])),
    ClockSignals: ClockSignals[index]
}
