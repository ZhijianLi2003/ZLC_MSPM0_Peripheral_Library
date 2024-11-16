let Common = system.getScript("/ti/driverlib/Common.js");
const { getDefaultValue } = system.getScript("./defaultValue.js");
const { device2Family, isDeviceFamily_PARENT_MSPM0L122X_L222X } = system.getScript("../../driverlib/Common.js");
const family = device2Family(system.deviceData);

function validateM0GSYSOSC(inst, validation)
{
    if(inst.$isUsed && inst.disableSYSOSC){
        // find who's using it
        let str = "";

        let mod = system.modules["/ti/clockTree/mux.js"];
        let exclkMux = _.find(mod.$instances, ['$name','EXCLKMUX']);
        let syspllMux = _.find(mod.$instances, ['$name','SYSPLLMUX']);
        let hsclkMux = _.find(mod.$instances, ['$name', 'HSCLKMUX']);
        let fccMux = _.find(mod.$instances, ['$name', 'FCCSELCLKMUX']);
        let mfpclkMux = _.find(mod.$instances, ['$name', 'MFPCLKMUX']);
        let sysctlMux = _.find(mod.$instances, ['$name', "SYSCTLMUX"]);

        mod = system.modules["/ti/clockTree/gate.js"];
        let exclkGate = _.find(mod.$instances, ['$name', 'EXCLKGATE']);
        let mfclkGate = _.find(mod.$instances, ['$name', 'MFCLKGATE']);
        let mfpclkGate = _.find(mod.$instances, ['$name', 'MFPCLKGATE']);

        mod = system.modules["/ti/clockTree/divider.js"];
        let pllClk0Div = _.find(mod.$instances, ['$name', 'PLL_CLK0_DIV']);
        let pllClk1Div = _.find(mod.$instances, ['$name', 'PLL_CLK1_DIV']);
        let pllClk2XDiv = _.find(mod.$instances, ['$name', 'PLL_CLK2X_DIV']);
        let pllEnabled = false;
        if(pllClk0Div && pllClk1Div && pllClk2XDiv){
            pllEnabled = pllClk0Div.enable || pllClk1Div.enable || pllClk2XDiv.enable;
        }

        mod = system.modules["/ti/clockTree/fcc.js"];
        let fcc = _.find(mod.$instances, ['$name', 'FCC']);

        if(_.endsWith(sysctlMux.inputSelect, "MDIV")){
            validation.logError("SYSOSC can only be disabled when MCLK is sourced from LFCLK (in RUN2 mode)", sysctlMux, "inputSelect");
        }
        if(exclkGate && exclkGate.enable &&
            exclkMux && _.endsWith(exclkMux.inputSelect, "SYSOSC")) {
            str += "EXCLK ";
            validation.logError("SYSOSC has been disabled but it is in use by EXCLK", exclkMux, 'inputSelect');
        }
        if(pllEnabled && syspllMux && _.endsWith(syspllMux.inputSelect, "SYSOSC")) {
            str += "SYSPLL ";
            validation.logError("SYSOSC has been disabled but it is in use by SYSPLL", syspllMux, 'inputSelect');
        }
        if(fcc && fcc.enable &&
           fccMux && _.endsWith(fccMux.inputSelect, "SYSOSC")){
            str += "FCC ";
            validation.logError("SYSOSC has been disabled but it is in use by FCC", fccMux, "inputSelect");
        }
        if( (hsclkMux && _.endsWith(hsclkMux.inputSelect, "SYSOSC")) &&
            (syspllMux && _.endsWith(syspllMux.inputSelect, "MDIV")))
        {
            str += "MCLK ";
            validation.logError("SYSOSC has been disabled but it is in use by MCLK", hsclkMux, 'inputSelect');
        }
        if(mfclkGate && mfclkGate.enable){
            str += "MFCLK ";
            validation.logError("SYSOSC has been disabled but it is in use by MFCLK", mfclkGate, 'enable');
        }
        if(mfpclkGate && mfpclkGate.enable){
            if(!(mfpclkMux && !_.endsWith(mfpclkMux.inputSelect, "SYSOSC"))){
                validation.logError("SYSOSC has been disabled but it is in use by MFPCLK", mfpclkMux, 'enable');
            }
        }

        if(str != ""){
            validation.logError("SYSOSC has been disabled but it is in use by "+ str, inst, ["disableSYSOSC"]);
        } else {
            // the disabling of SYSOSC is allowed as it it does not have a configurable bypass.
        }
    }
    else if (inst.disableSYSOSC){
        validation.logInfo("SYSOSC has been disabled, in RUN2 power mode", inst, "disableSYSOSC");
    }
    else{
        if(!_.isUndefined(inst.enableROSC)){
            /* FCL Validation for devices that only have External Rosc supported */
            if(inst.enableSYSOSCFCL && !inst.enableROSC && Common.hasExternalRoscOnly()){
                validation.logError("External ROSC must be enabled for FCL usage with this device. See the device datasheet for more details.", inst, ["enableSYSOSCFCL", "enableROSC"]);
            }
            else if(!inst.enableSYSOSCFCL && inst.enableROSC){
                validation.logWarning("If ROSC has been enabled, it's recommended Frequency Correction Loop is enabled.", inst, ["enableSYSOSCFCL", "enableROSC"]);
            }
        }
    }
}

function validateM0LSYSOSC(inst, validation) {

    if(Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()) {
        let sysctl = system.modules["/ti/driverlib/SYSCTL"];
        if(sysctl && sysctl.$static.clockTreeEn) {
            let mod = system.modules["/ti/clockTree/mux.js"];
            let lfxtMux = _.find(mod.$instances, ['$name','LFXTMUX']);
            if(lfxtMux && _.endsWith(lfxtMux.inputSelect, "FALSE")){
                validation.logWarning("Note: VBAT needs to be powered for LFCLK operation.", lfxtMux, "inputSelect");
            }
        }

        /* Special Case Validation for ROSC */
        if(inst.enableROSC){
            validation.logInfo("PA2 is being configured for ROSC and should not be used for other pin selections.", inst, "enableROSC");
        }
    }

    // todo: set this for the M0L, currently keeping compatible with M0G
    return validateM0GSYSOSC(inst, validation);
}

function validateM0CSYSOSC(inst, validation) {
    if(inst.disableSYSOSC){
        let mod = system.modules["/ti/clockTree/mux.js"];
        // make sure nobody is trying to use it
        let sysctlMux = _.find(mod.$instances, ['$name', "SYSCTLMUX"]);
        let exhfMux = _.find(mod.$instances, ['$name','EXHFMUX']);
        let fccMux = _.find(mod.$instances, ['$name', 'FCCSELCLKMUX']);
        let exclkMux = _.find(mod.$instances, ['$name','EXCLKMUX']);

        mod = system.modules["/ti/clockTree/gate.js"];
        let exclkGate = _.find(mod.$instances, ['$name', 'EXCLKGATE']);
        let mfclkGate = _.find(mod.$instances, ['$name', 'MFCLKGATE']);

        mod = system.modules["/ti/clockTree/fcc.js"];
        let fcc = _.find(mod.$instances, ['$name', 'FCC']);

        let inUseStr = "";

        if(_.endsWith(sysctlMux.inputSelect, "HFCLK"))
        {
            validation.logError("SYSOSC can only be disabled when MCLK is sourced from LFCLK (in RUN2 mode)", sysctlMux, "inputSelect");
            if(_.endsWith(exhfMux.inputSelect, "SYSOSC")){
                inUseStr += "MCLK ";
            }
        }

        if(mfclkGate && mfclkGate.enable){
            inUseStr += "MFCLK ";
            validation.logError("SYSOSC has been disabled but it is in use by MFCLK", mfclkGate, 'enable');
        }

        if(exclkGate && exclkGate.enable &&
            exclkMux && _.endsWith(exclkMux.inputSelect, "SYSOSC")) {
            inUseStr += "EXCLK ";
            validation.logError("SYSOSC has been disabled but it is in use by EXCLK", exclkMux, 'inputSelect');
        }

        if(fcc && fcc.enable &&
            fccMux && _.endsWith(fccMux.inputSelect, "SYSOSC")){
            inUseStr += "FCC ";
            validation.logError("SYSOSC has been disabled but it is in use by FCC", fccMux, "inputSelect");
        }
        // todo: add ADC case

        if(inUseStr != ""){
            validation.logError("SYSOSC has been disabled but it is in use by "+ inUseStr, inst, ["disableSYSOSC"]);
        } else {
            // the disabling of SYSOSC is allowed as it it does not have a configurable bypass.
        }

    }
}


function validate(inst, validation)
{
    if(inst.$name == "SYSOSC")
    {
        switch(family){
            case "MSPM0G":
                validateM0GSYSOSC(inst, validation);
                break;
            case "MSPM0L":
                validateM0LSYSOSC(inst, validation);
                break;
            case "MSPM0C":
                validateM0CSYSOSC(inst, validation);
                break;
            default:
                throw "family not recognized";
                break;
        }
    }
}

function pinmuxRequirements(inst)
{
    let resources = [];
    // CLOCKTREE ROSC
    if(!inst.disableSYSOSC && inst.enableROSC){
        if(!Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()){
            resources.push({
                name            : "roscPin",
                displayName     : "ROSC",
                interfaceNames  : ["ROSC"],
            });
        }
    }
	let sysctl = {
        name          : "peripheral",
        displayName   : "Clock Tree Peripheral",
        interfaceName : "SYSCTL",
		canShareWith  : "CLOCK_TREE",
        resources     : resources,
		signalTypes   : {
            lfxInPin    : ["LFXIN"],
            lfxOutPin   : ["LFXOUT"],
            lfclkInPin  : ["LFXOUT"],
            hfxInPin    : ["LFXIN"],
            hfxOutPin   : ["HFXOUT"],
            hfclkInPin  : ["HFXOUT"],
            roscPin     : ["ROSC"],
            clkOutPin   : ["CLK_OUT"],
			fccInPin	: ["FCC_IN"],
        }
    };
	if(resources.length > 0){
		return [sysctl];
	} else {
		return [];
	}
}

let SYSOSC_extraConfig = [
    {
        name: "enableSYSOSCFCL",
        displayName: "Enable Frequency Correction Loop (FCL)",
        description: "Used to increase SYSOSC accuracy",
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
    {
        name: "enableROSC",
        displayName: "Enable Ext Reference Resistor (ROSC)",
        description: "Enable to increase SYSOSC accuracy",
        longDescription: "The External Reference Resistor is an added external component to increase accuracy of the SYSOSC",
        default: false,
        hidden: false,
    },
    {
        name: "disableSYSOSC",
        displayName: "Disable SYSOSC",
        description: "Disable SYSOSC to enter RUN2 power mode (lowest power with CPU up)",
            longDescription: `
SYSOSC can be optionally disabled when MCLK is sourced from LFCLK in order to enter the lowest run power policy: RUN2.
RUN2 is the lowest power mode when the CPU is still operational. If SYSOSC remains enabled to service other peripherals,
then RUN1 is the power mode used. This is reflected in SYSCTL module and the Clock Tree Summary
            `,
        default: false,
        hidden: false,
        onChange: (inst, ui) => {}
    },

];

function extendConfig({ $ipInstance })
{
    let outPin;
    let const4MHzPin;
    for(let pin of $ipInstance.outPins) {
        /* Case insensitive match */
        if(pin.name.match(/_out/i)) {
            outPin = pin;
        }
        if(pin.name.match(/_4M/i)) {
            const4MHzPin = pin;
        }
    }
    if($ipInstance.name === "SYSOSC") {
        let frequencySelectOptions = [
            {name: 32},
            // {name: 24}, trimming not supported yet
            // {name: 16},
            {name: 4}
        ];
        if(family === "MSPM0C"){
            /* M0C does not have a ROSC and has a max frequency of 24 */
            _.remove(SYSOSC_extraConfig, ["name", "enableROSC"]);
            //_.remove(SYSOSC_extraConfig, ["name", "disableSYSOSC"]);
            SYSOSC_extraConfig.concat([
                {
                    name: "$isUsed",
                    hidden: true,
                    readOnly: true,
                    getValue: (inst) => {
                        return !inst.disableSYSOSC;
                    }
                },
            ]);
            // _.find(SYSOSC_extraConfig,
            //     ["name", "disableSYSOSC"]).onChange = function (inst) {
            //     inst.$isUsed = !inst.disableSYSOSC;
            // }
            frequencySelectOptions = [
                {name: 24},
                {name: 4}
            ];
        }
        return [
            {
                name: "frequencySelect",
                    displayName: "Frequency Select",
                    description: "Set Frequency Output of Main SYSOSC channel",
                    longDescription: `
        SYSOSC supports factory trimmed frequencies of 32 MHz and 4 MHz.
        SYSOSC can be lowered to 4MHz and combined with MDIV to create a range of frequencies between 4MHz and 32 kHz (LFCLK).
        MDIV cannot be used in combination with SYSOSC when it is sourced from 32 MHz.
        The 4 MHz constant output remains unaffected by this configurable.
                    `,
                default: frequencySelectOptions[0].name,
                options: frequencySelectOptions
            },
            ...SYSOSC_extraConfig,
            {
                name: outPin.name,
                    displayName: "Main Output",
                default: [0, 0],
                getValue: (inst) => { return !inst.disableSYSOSC?inst.frequencySelect:0; }
            },
            {
                /* 4 MHz constant output */
                name: const4MHzPin.name,
                    displayName: "4 MHz Output",
                default: 4,
                getValue: (inst) => { return !inst.disableSYSOSC?4:0; }
            }
        ];

    }

    else
    {
        /* TODO: this fix is temporary while incorrect output value is supported in clocktree values */
        let modifiedOutputValue = ($ipInstance.outputValue == 0.032)?0.032768:$ipInstance.outputValue;
        return [
            {
                name: $ipInstance.outPins[0].name,
                default: [0.000, 0.000],
                getValue: (inst) => { return modifiedOutputValue; }
            }
        ];
        /* End of fix */
    }
}

exports = {
	displayName: "Oscillator",
	config: [{
		name: "type",
		displayName: "Type",
		default: "Oscillator",
		readOnly: true,
	}],
    validate: validate,
    pinmuxRequirements: pinmuxRequirements,

    templates: {
		boardc: "/ti/clockTree/templates/oscillator.Board.c.xdt",
		boardh: "/ti/clockTree/templates/oscillator.Board.h.xdt"
	},
    extendConfig: extendConfig

};
