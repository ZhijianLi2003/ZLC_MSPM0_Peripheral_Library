let Common = system.getScript("/ti/driverlib/Common.js");

const { getDefaultValue } = system.getScript("./defaultValue.js");
const { isDeviceM0G, isDeviceM0C, isDeviceFamily_PARENT_MSPM0L122X_L222X, getUnitPrefix } = system.getScript("/ti/driverlib/Common.js");

function validatePinmux(inst, validation){
	/* CLK_OUT validation */
	if(inst.$name == "CLKOUT"){
		if(inst.enable){
			try{
				let clkOutPin = inst.peripheral.clkOutPin.$solution.packagePinName;
				let validPinSet = validClkOutPinSet(inst);

				if (!validPinSet.includes(clkOutPin)){
					validation.logError("Currently selected CLK_OUT pin not available when routing a high frequency. Please select a different CLK_OUT source or a different pin. See device documentation for pin limitations.",
					inst, ["enable"]);
				}
				if(inst.ClkOutForceHighDrive){
					if(inst.VDD < 2.7){
						validation.logError("When High Drive is enabled VDD supplied voltage cannot be less than 2.7V.",
						inst, ["VDD"]);
					}
				}
			} catch (e){
				// do nothing
			}
		}
	}
}

function validate(inst, validation)
{
	let clockTreeEn = false;
	if(system.modules["/ti/driverlib/SYSCTL"]){
		clockTreeEn = system.modules["/ti/driverlib/SYSCTL"].$static.clockTreeEn;
	}

	/* MDIV must be disabled for MFCLK to be enabled */
	if(inst.$name == "MFCLK" && inst.enable){
		// filter returns an array
		let mdiv = system.modules["/ti/clockTree/divider.js"].$instances.filter( inst => inst.$name == "MDIV")[0].divideValue;
		if(mdiv != 1){
			validation.logError("MFCLK Unable to be enabled when MDIV not 1",inst,"enable");
		}
	}

	if(inst.$name == "HFXT" || inst.$name == "HFCLKEXT"){
		if(clockTreeEn){
			let ADCMod = system.modules["/ti/driverlib/ADC12"];
			if(ADCMod){
				if(_.some(ADCMod.$instances, ['sampClkSrc', "DL_ADC12_CLOCK_HFCLK"])){
					if(inst.$name == "HFCLKEXT" && !inst.enable){
						let HFCLKSource = system.clockTree.EXHFMUX.inputSelect;
						if(HFCLKSource == "EXHFMUX_DIG"){
							validation.logError("HFCLK must be enabled for the selected configuration",inst,"enable");
						}
					}
					else if(inst.$name == "HFXT" && !inst.enable){
						let HFCLKSource = system.clockTree.EXHFMUX.inputSelect;
						if(HFCLKSource == "EXHFMUX_XTAL"){
							validation.logError("HFCLK must be enabled for the selected configuration",inst,"enable");
						}
					}
				}
			}
		}
	}

	if(inst.$name == "LFXT" && inst.enable){
		if(clockTreeEn){
			validation.logInfo("After LFXT is enabled, the internal LFOSC is disabled, and cannot be re-enabled other than by executing a BOOTRST.",inst,"enable");
		}
		if(Common.isDeviceFamily_PARENT_MSPM0L122X_L222X() && clockTreeEn) {
			validation.logWarning("Note: VBAT needs to be powered for LFCLK operation.", inst, "enable");
		}
	}

	if(inst.$name == "LFCLKEXT" && inst.enable && clockTreeEn){
		if(Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()) {
			validation.logWarning("Note: VBAT needs to be powered for LFCLK operation.", inst, "enable");
		}
	}

	if(inst.enable && !_.isNil(inst.minVal)){
		if(inst.inputFreq < inst.minVal || inst.inputFreq > inst.maxVal)
		{
			let valStr = "Input Value exceeds range of [" + inst.minVal + "MHz, " + inst.maxVal + "MHz]";
			if(inst.iskHzInput){
				valStr = "Input Value exceeds range of [" + inst.minVal + "kHz, " + inst.maxVal + "kHz]";
			}
			validation.logError(valStr, inst, "inputFreq")
		}
	}
}

const LFCLKEXT_extendedConfig = [
	{
		name		: "LFCLKMonitorEnable",
		displayName	: "LFCLK Startup Monitor",
		description : "Enable the LFCLK Startup Monitor to check for a Valid Signal",
		longDescription: `
The LFCLK Monitor can be enabled to check for a valid clock signal.
By Default, the LFCLK Monitor will check LFCLK_IN if LFXT was not started.

If an LFCLK stuck fault is detected, the system will respond in one of two ways:

* If LFCLK is sourcing MCLK, then it is considered fatal and BOOTRST is asserted.
* Otherwise, LFCLK will assert an interrupt request in SYSCTL so that the application
  can determine how to proceed `,
		default: false
	}
]

const LFXT_extendedConfig = [
	// DL_SYSCTL_setLFCLKSourceLFXT
	{
		name        : "LFCLKLowCap",
		displayName : "Ultra-Low Capacitance Optimization",
		description : `Enable if the the crystal has less than 3pF capacitance to reduce power consumption`,
		longDescription: `Ultra-low capacitance crystals (<3 pF) can benefit from additional power savings
						  by enabling the LOWCAP bit on the device`,
		default     : false
	},
	{
		name        : "LFCLKDriveStrength",
		displayName : "Drive Strength",
		description : 'Drive strength and power consumption option',
		default     : "HIGHEST",
		options     : [
				{name: "LOWEST", displayName: "Lowest Drive and Current"},
				{name: "LOWER", displayName: "Lower Drive and Current"},
				{name: "HIGHER", displayName: "Higher Drive and Current"},
				{name: "HIGHEST", displayName: "Highest Drive and Current"},
		],
	},
	{
		name		: "LFCLKMonitorEnable",
		displayName	: "LFCLK Startup Monitor",
		description : "Enable the LFCLK Startup Monitor",
		longDescription: `
The LFCLK Monitor can be enabled to check for a valid clock signal on LFXT.

If an LFCLK stuck fault is detected, the system will respond in one of two ways:

* If LFCLK is sourcing MCLK, then it is considered fatal and BOOTRST is asserted.
* Otherwise, LFCLK will assert an interrupt request in SYSCTL so that the application
  can determine how to proceed `,
		default		: false
	}
];

const CLKOUT_extendedConfig = [
	{
		name: "clkOutPinDisplay",
		displayName: "CLK_OUT Pin",
		description: "",
		default: "N/A",
		hidden: true,
		getValue: (inst) => {
			try{
				let value = inst.peripheral.clkOutPin.$solution.devicePinName;
				if(value !== null){return value}
			} catch(e){
				return "N/A"
			}
			return("N/A");

		}
	},
	{
		name: "clkOutPinIO",
		displayName: "CLK_OUT Pin IO Structure",
		description: "",
		default: "N/A",
		hidden: true,
		options: [
			{name: "N/A", displayName: "N/A"},
			{name: "SD", displayName: "Standard"},
			{name: "SDL", displayName: "Standard"},
			{name: "SDW", displayName: "Standard with Wake"},
			{name: "HS", displayName: "High-Speed"},
			{name: "HD", displayName: "High-Drive"},
			{name: "OD", displayName: "5V Tolerant Open Drain"},
		],
		getValue: (inst) => {
			try{
				let value =  system.deviceData.gpio.pinInfo[inst.peripheral.clkOutPin.$solution.packagePinName].devicePin.attributes.io_type;
				if(value !== null){ return value};
			} catch(e){
				return "N/A"
			}
			return "N/A"
		}
	},
	{
		name        : "VDD",
		displayName : "Supplied Operational Voltage (VDD)",
		description : "Supplied Operational Voltage for the Board supplied by the user",
		longDescription: "Voltage given for the DC Operation of the Device, used by GPIO pins for internal operating parameters.",
		default     : 3.3,
		range       : [1.71, 5]
	},
	{
		name: "ClkOutForceHighDrive",
		displayName: "Force High Drive",
		description: "Force the output pin for the CLK_OUT Pin to High Drive",
		longDescription: `
Forces the output pin to be of type HDIO or HSIO configured with High-Drive strength, useful when driving other devices.
High Drive is turned on automatically if the CLK_OUT frequency is above 32 MHz when VDD >= 2.7 or above 16 MHz otherwise.
		`,
		default: false
	},
	{
		name: "ClkOutHighDriveEn",
		default: false,
		hidden: true,
		getValue: (inst, ui) => {
			if(inst.enable){
				if(inst.ClkOutForceHighDrive){
					return true;
				} else {
					// automatic enabling due to the frequency
					let clkOutFreq = inst.outActual;
					let index = (inst.VDD >= 2.7)?1:0;
					if(clkOutFreq >  (maxFrequencyCLKOUTDir["SD"][index] * 1000000) &&
					   clkOutFreq <= (maxFrequencyCLKOUTDir["HS"][index] * 1000000)){
						// in this condition, SD pins will already be filtered out
						// so we can be certain the pin in use will be high-speed
						return true;
					}
				}
			}
			return false
		}
	},
	{
		name: "outActual",
		displayName: "Output Frequency Actual",
		default: 0,
		getValue: getActualOutFreq,

	},
];

const HFXT_extendedConfig = [

	{	name: "HFXTRange",
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
			if (inst.inputFreq <= 8) { return "DL_SYSCTL_HFXT_RANGE_4_8_MHZ" }
			else if (inst.inputFreq > 8 && inst.inputFreq <= 16) { return "DL_SYSCTL_HFXT_RANGE_8_16_MHZ" }
			else if (inst.inputFreq > 16 && inst.inputFreq <= 32) { return "DL_SYSCTL_HFXT_RANGE_16_32_MHZ" }
			else if (inst.inputFreq > 32) { return "DL_SYSCTL_HFXT_RANGE_32_48_MHZ" }
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
			return (getUnitPrefix(inst.HFXTStartup * 0.000064)).str+"s";
		},
	},
	{
		name        : "HFCLKMonitor",
		displayName : "HFCLK Startup Monitor",
		description : 'Enable the HFCLK startup monitor',
		hidden      : false,
		default     : false
	}
];

// function sharedModuleInstances(inst) {
// 	if(inst.$name == "LFXT" || inst.$name == "LFCLKEXT"){
// 		if(inst.enable){
// 			return [{
// 				name: "LFCLKMonitor",
// 				displayName: "LFCLK Monitor",
// 				moduleName: "/ti/clockTree/monitor.js",
// 				//sharewithByDefault: "LFCLK_SHARE_DEFAULT"
// 			}]
// 		}
// 	}
// 	return [];
// }

const memoizedGPIOFilter = _.memoize(curryGPIOFilter, (validPinSet) => JSON.stringify(validPinSet));

function curryGPIOFilter(validPinSet) {
	return (devicePin, peripheralPin) => GPIOFilter(devicePin, validPinSet);
}

function GPIOFilter(devicePin, validPinSet) {
    return validPinSet.includes(devicePin.name);
}

const maxFrequencyCLKOUTDir = {
    "SD" : [ 16, 32 ],
    "SDW" : [16, 32], // same as SD simply with wake
    "SDL" : [16, 32], // same as SD simply with low leakage
    "HS_DRVLOW" : [ 16, 32 ], // LOW Drive, used later on in pinmux validation
    "HS" : [ 24, 40 ], // High drive enabled
    "HD" : [ 16, 20 ],
    "OD" : [ 1, 1 ]
};

/* Filter valid pins for Fault Pin configuration */
function validClkOutPinSet(inst){
    let validPinSet = [];

    // determine the frequency based on the table:
    /*  Type        | short |  >1.71    |   >2.7
     *  SDIO        |  SD   |  16 MHz   |   32 MHz
     *  HSIO(DRV 0) |  HS   |  16 MHz   |   32 MHz
     *  HSIO(DRV 1) |  HS   |  24 MHz   |   40 MHz
     *  HDIO        |  HD   |  16 MHz   |   20 MHz
     *  ODIO        |  OD   |   1 MHz   |    1 MHz
     *
     */
    let clkOutFreq = inst.outActual;

    for(let pinIdx in system.deviceData.gpio.pinInfo){
        let eligible = true;

        let pinType = system.deviceData.gpio.pinInfo[pinIdx].devicePin.attributes.io_type;

        if(inst.ClkOutForceHighDrive && !["HD", "HS"].includes(pinType)){
            eligible = false;
        } else {
            // determine eligibility based on the frequency value
            let index = 0;
            if(inst.VDD >= 2.7){
                index = 1;
            }

            if(_.isUndefined(maxFrequencyCLKOUTDir[pinType])){
                throw "max frequency not found for pin type" + pinType;
            }
            // if pinType is HSIO;
            let maxFreq = maxFrequencyCLKOUTDir[pinType][index] * 1000000;

            if(clkOutFreq > maxFreq){
            // pin.devicePin.attributes.io_type
                eligible = false;
            }
        }

        if(eligible){
            validPinSet.push(pinIdx);
        }
    }

    return validPinSet;
}

function pinmuxRequirements(inst)
{
    let resources = [];
	let signalTypes = {
		lfxInPin    : ["LFXIN"],
		lfxOutPin   : ["LFXOUT"],
		lfclkInPin  : ["LFXOUT"],
		hfxInPin    : ["LFXIN"],
		hfxOutPin   : ["HFXOUT"],
		hfclkInPin  : ["HFXOUT"],
		roscPin     : ["ROSC"],
		clkOutPin   : ["CLK_OUT"],
		fccInPin	: ["FCC_IN"],
	};
	if(isDeviceM0C()){
		signalTypes.lfclkInPin = ["LFCLKIN"];
		signalTypes.hfclkInPin = ["HFCLKIN"];
	}
	if(inst.enable){
        switch(inst.$name){
            case "LFXT":
                resources.push({
                    name            : "lfxInPin",
                    displayName     : "LFXIN",
                    interfaceNames  : ["LFXIN"],
                },
                {
                    name            : "lfxOutPin",
                    displayName     : "LFXOUT",
                    interfaceNames  : ["LFXOUT"],
                });
                break;
            case "LFCLKEXT":
				if(!isDeviceM0C()){
					resources.push({
						name            : "lfclkInPin",
						displayName     : "LFCLK In",
						interfaceNames  : ["LFXOUT"],
					});
				} else {
					resources.push({
						name            : "lfclkInPin",
						displayName     : "LFCLK In",
						interfaceNames  : ["LFCLKIN"],
					});
				}
                break;
            case "HFXT":
                resources.push({
                    name            : "hfxInPin",
                    displayName     : "HFXIN",
                    interfaceNames  : ["HFXIN"],
                },
                {
                    name            : "hfxOutPin",
                    displayName     : "HFXOUT",
                    interfaceNames  : ["HFXOUT"],
                });
                break;
            case "HFCLKEXT":
				if(!isDeviceM0C()){
					resources.push({
						name            : "hfclkInPin",
						displayName     : "HFCLK In",
						interfaceNames  : ["HFXOUT"],
					});
				} else {
					resources.push({
						name            : "hfclkInPin",
						displayName     : "HFCLK In",
						interfaceNames  : ["HFCLKIN"],
					});
				}
                break;
			case "CLKOUT":
				resources.push({
					name            : "clkOutPin",
            		displayName     : "CLK OUT",
            		interfaceNames  : ["CLK_OUT"],
				});
				break;
			case "FCCEXT":
				resources.push({
					name            : "fccInPin",
					displayName     : "FCC IN",
					interfaceNames  : ["FCC_IN"],
				});
				break;
            default:
				/* no resource to be added */
                break;
        }
    }
	let sysctl = {
        name          : "peripheral",
        displayName   : "Clock Tree Peripheral",
        interfaceName : "SYSCTL",
		canShareWith  : "CLOCK_TREE",
        resources     : resources,
		signalTypes   : signalTypes
    };

	if(resources.length > 0){
		return [sysctl];
	} else {
		return [];
	}
}

function getActualOutFreq(inst){
    let actualOutFreq = Common.parseFloatUnitInput(inst.out,"Hz");
	return actualOutFreq;
}

function extendConfig({ $ipInstance })
{
	let isEnabled = false;
	let isConfigurable = false;
	let iskHzInput = false;

	let minVal = 0;
	let maxVal = 1000; /* 1 GHz */
	let descriptStr = "";
	let suffix = "MHz"

	if($ipInstance.iskHzInput === true){
		/* This optional config parameter in clockTree.json will
		 * print an input in kHz rather than the typical MHz for ease.
		 * range and all other inputs will be dealt with in kHz and
		 * then the output will be converted up.
		 */
		iskHzInput = true;
		suffix = "kHz";
	}

	if($ipInstance.enabled === true){
		/* This optional config parameter in clockTree.json
		 * allows for a configurable to have an enable parameter
		 * that should be present and validate-able based on other
		 * configuration information.
		 * Ex: MFCLK is enabled but must check that MDIV is disabled
		 * Error should appear on MFCLK, as this has generally less
		 * priority than MDIV and MDIV doesn't have a left pane and
		 * is currently unable to have an error appear under it.
		 */
		isEnabled = true;
	}
	if($ipInstance.isConfigurable === true){
		/* This optional config parameter in clocktree.json
		 * allows for a pin function to have a configurable output
		 * that is inputted by the user. Currently not validated.
		 * Also can be enabled/disabled.
		 * TODO: validate the input as well.
		 */
		isConfigurable = true;

		/* Check for the existance of a range */
		if($ipInstance.range && $ipInstance.range.length == 2)
		{
			minVal = $ipInstance.range[0];
			maxVal = $ipInstance.range[1];
			descriptStr = "Input value from " + minVal + " " + suffix + " to " + maxVal + " " + suffix;
		}
	}


	if (!_.isEmpty($ipInstance.outPins)) {
		let config;
		if(isConfigurable === true){
			config = [
				{
					name: "inputFreq",
					displayName: "Input Frequency (" + suffix + ")",
					description: descriptStr,
					default: 0,
					readOnly: isEnabled
				},
				{
					name: "enable",
					displayName: "Enable "+$ipInstance.name,
					default: isEnabled,
					/*onChange: (inst, ui) => {
						if(!inst["enable" + $ipInstance.name]){
							inst["inputFreq" + $ipInstance.name] = 0;
							ui["inputFreq" + $ipInstance.name ].readOnly = true;
						} else {
							ui["inputFreq" + $ipInstance.name ].readOnly = false;
						}
					}*/
				},
				{
					name: $ipInstance.outPins[0].name,
					default: [0, 0],
					getValue: (inst) => {
						/* must be output in MHz */
						if(inst.enable){
							return inst.iskHzInput?(inst.inputFreq/1000):inst.inputFreq;
						} else {
							return 0;
						}
					}
				},
				{
					name: "minVal",
					default: minVal,
					hidden: true
				},
				{
					name: "maxVal",
					default: maxVal,
					hidden: true
				},
				{
					name: "iskHzInput",
					default: iskHzInput,
					hidden: true
				},
			];

			if($ipInstance.name === "LFXT"){
				config = config.concat(LFXT_extendedConfig);
			}
			else if($ipInstance.name === "HFXT"){
				config = config.concat(HFXT_extendedConfig);
			}
			else if($ipInstance.name === "LFCLKEXT") {
				config = config.concat(LFCLKEXT_extendedConfig);
			}
			// TODO: Temporary fix while PG1 doesn't support FCCIN
			else if($ipInstance.name == "FCCEXT"){
				let enableFix = {
					name: "enable",
					displayName: "Enable FCC_IN"
				};
				Object.assign(_.find(config, ["name", "enable"]), enableFix);
			}
		} else {
			config = [
				{
					name: $ipInstance.outPins[0].name,
					default: [0, 0],
					getValue: (inst) => {return $ipInstance.outputValue;}
				}
			];
		}
		return config;
	} else {
		// Override the input pin so it's visible with a tool tip
		let config = [
			{
				name: "out",
				displayName: "Output Frequency",
				default: "0 MHz",
				getValue: (inst) => {
					return inst.enable?inst[$ipInstance.inPins[0].name] + suffix:"0 "+suffix;
				}
			},
			{
				name: $ipInstance.inPins[0].name,
				default: [0,0],
				hidden: true,
				getValue: (inst) => {
					if(inst.enable == true){
						return inst[$ipInstance.inPins[0].name];
					} else {
						return [0,0];
					}
				} // Tool will update
		}];
		if($ipInstance.name == "CLKOUT"){
			config = config.concat(CLKOUT_extendedConfig);
		}
		let enableConfig;

		if(isEnabled === true){
			if($ipInstance.name == "CLKOUT"){
				enableConfig = {
					name: "enable",
					displayName: "Enable "+$ipInstance.name,
					description: "Enables or Disables the "+$ipInstance.name,
					default: false,
					onChange: (inst,ui) => {
						ui.clkOutPinDisplay.hidden  = !inst.enable;
						ui.clkOutPinIO.hidden       = !inst.enable;
					}
				};
			}
			else {
				enableConfig = {
					name: "enable",
					displayName: "Enable "+$ipInstance.name,
					description: "Enables or Disables the "+$ipInstance.name,
					default: false
				};
			}

		} else {
			enableConfig = {
				name: "enable",
				default: true,
				hidden: true
			};
		}
		config.push(enableConfig);
		return config;
	}
}

exports = {
	displayName: "Pin Function",
	config: [{
		name: "type",
		displayName: "Type",
		default: "Pin Function",
		readOnly: true,
	}],
	validate: validate,
	validatePinmux: validatePinmux,
	pinmuxRequirements: pinmuxRequirements,

	templates: {
		boardc: "/ti/clockTree/templates/pinFunction.Board.c.xdt",
		boardh: "/ti/clockTree/templates/pinFunction.Board.h.xdt"
	},
	extendConfig: extendConfig
};
