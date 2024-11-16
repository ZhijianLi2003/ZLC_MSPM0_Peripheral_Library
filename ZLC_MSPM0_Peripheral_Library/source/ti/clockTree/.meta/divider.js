const { isDeviceM0G } = system.getScript("/ti/driverlib/Common.js");
let Common = system.getScript("/ti/driverlib/Common.js");

/* Supporting functions for auto enable of the SYSPLL divider channels */
function getEnableSYSPLL0(inst) {
	let mod = system.modules["/ti/clockTree/mux.js"];
	let hsclkMux = _.find(mod.$instances, ['$name', 'HSCLKMUX']);
	let fccMux = _.find(mod.$instances, ['$name', 'FCCSELCLKMUX']);

	if(_.endsWith(hsclkMux.inputSelect, "SYSPLL0") ||
	   	_.endsWith(fccMux.inputSelect, "SYSPLLCLK0")){
		return true;
	} else {
		return false;
	}
}

function getEnableSYSPLL1(inst) {
	let mod = system.modules["/ti/clockTree/mux.js"];
	let canclkMux = _.find(mod.$instances, ['$name', 'CANCLKMUX']);
	let fccMux = _.find(mod.$instances, ['$name', 'FCCSELCLKMUX']);
	let exclkMux = _.find(mod.$instances, ['$name', 'EXCLKMUX']);

	if(_.endsWith(canclkMux.inputSelect, "PLLCLK1_OUT") ||
		_.endsWith(exclkMux.inputSelect, "PLLCLK1_OUT") ||
	   	_.endsWith(fccMux.inputSelect, "SYSPLLCLK1")){
		return true;
	} else {
		return false;
	}
}

function getEnableSYSPLL2X(inst) {
	let mod = system.modules["/ti/clockTree/mux.js"];
	let hsclkMux = _.find(mod.$instances, ['$name', 'HSCLKMUX']);
	let fccMux = _.find(mod.$instances, ['$name', 'FCCSELCLKMUX']);

	if(_.endsWith(hsclkMux.inputSelect, "SYSPLL2X") ||
	   	_.endsWith(fccMux.inputSelect, "SYSPLLCLK2X")){
		return true;
	} else {
		return false;
	}
}

// Passed as a getValue for UDIV
function isUDIVEnabled(inst) {
	let mod = system.modules["/ti/clockTree/mux.js"];
	let hsclkMux = _.find(mod.$instances, ['$name', 'HSCLKMUX']);
	let sysctlMux = _.find(mod.$instances, ['$name', 'SYSCTLMUX']);

	if(_.endsWith(sysctlMux.inputSelect, "LFCLK") ||
		_.endsWith(hsclkMux.inputSelect, "SYSOSC")) {
		return false;
	} else {
		return true;
	}
}

function isMDIVEnabled(inst) {
	let osc = system.modules["/ti/clockTree/oscillator.js"];
	let sysosc = _.find(osc.$instances, ['$name','SYSOSC']);
	if(isDeviceM0G()){
		let mod = system.modules["/ti/clockTree/mux.js"];
		let hsclkMux = _.find(mod.$instances, ['$name', 'HSCLKMUX']);
		let sysctlMux = _.find(mod.$instances, ['$name', 'SYSCTLMUX']);

		if(_.endsWith(sysctlMux.inputSelect, "MDIV") &&
			_.endsWith(hsclkMux.inputSelect, "SYSOSC") &&
			sysosc.frequencySelect === 4) {
			return true;
		}
	} else {
		if(sysosc.frequencySelect === 4){
			return true;
		}
	}
	return false;
}

function validate(inst, validation){

	if(inst.$name === "UDIV"){
		//Temporary fix for MSPM0L122X_L222X to not allow user to select UDIV value other than 1
		if(Common.isDeviceFamily_PARENT_MSPM0L122X_L222X() && inst.divideValue != 1) {
			validation.logError("MSPM0L122X_L222X only supports a UDIV value of 1.", inst, "divideValue");
		}
		else {
			if(inst.divideValue != 1 && !inst.isUDIVEnabled){
				validation.logWarning("UDIV will be disabled (/1) when sourced from LFCLK or SYSOSC and not reflect current setting", inst, "divideValue");
			} else {
				let ulpclk = inst[inst.$ipInstance.outPins[0].name];
				if(ulpclk > 40){
					validation.logError("ULPCLK is limited to below 40MHz. Frequency is currently " + ulpclk + "MHz. Please increase UDIV for the given MCLK.", inst, "divideValue");
					validation.logError("ULPCLK is limited to below 40MHz.", system.clockTree["net_ulpclk"]);
				}
			}
		}

	}
	else if(inst.$name === "MDIV"){
		if(inst.divideValue != 1 && !inst.isMDIVEnabled){
			validation.logWarning("MDIV will be disabled (/1) when sourced from anything other than SYSOSC with frequencyValue 4MHz", inst, "divideValue");
		}
	}
}



exports = {
	displayName: "Divider",
	//onChangeDisableUDIV: onChangeDisableUDIV,
	validate: validate,
	config: [{
		name: "type",
		displayName: "Type",
		default: "Divider",
		readOnly: true,
	}],
	extendConfig: ({ $ipInstance }) => {
		let isEnabled = false;
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
		let config = [
			{
				name: "divideValue",
				displayName: "Divide Value",
				default: $ipInstance.resetValue,
				options: _.map($ipInstance.divideValues, (v) => ({ name: v, displayName: `/${v}` })),
			},
			{
				name: $ipInstance.outPins[0].name,
				displayName: "Output",
				default: [0, 0],
				getValue: (inst) => {
					let value = inst[$ipInstance.inPins[0].name];
					if (_.isArray(value)) {
						return _.map(value, (v) => v / inst.divideValue);
					}
					return inst.enable?(value / inst.divideValue):0;
				},
			},
		]
		if($ipInstance.name === "UDIV")
		{
			let newDivValue = {
					description: "Divide Value when sourced from HSCLK only",
					longDescription: `
UDIV is used only when MCLK is sourced from a high-speed clock (SYSPLL, HFXT, or HFCLK_IN).

** Note: ULPCLK must be maintained below 40MHz at all times **
					`,
			};
			let newOut = {
				name: $ipInstance.outPins[0].name,
				default: [0, 0],
				getValue: (inst) => {
					let value = inst[$ipInstance.inPins[0].name];
					// Temporary fix for CLK2X in the PLL
					if (_.isArray(value)) {
						return _.map(value, (v) => {
							return inst.isUDIVEnabled?(v / inst.divideValue):v;
						});
					}
					return inst.isUDIVEnabled?(value / inst.divideValue):value;
				},
			}

			Object.assign(config[0], newDivValue); // added description
			Object.assign(config[1], newOut);
			config.push(
				{
					name: "isUDIVEnabled",
					displayName: "UDIV Enabled?",
					description: "Displays whether UDIV is enabled by the system (MCLK sourced from HSCLK)",
					longDescription: `
This read-only value shows whether UDIV is enabled and able to change the value of ULPCLK. It is only
enabled when sourced from neither LFCLK nor SYSOSC. If not enabled, the value of UDIV
will not affect the value of ULPCLK
					`,
					hidden: true,
					default: false,
					getValue: isUDIVEnabled
				}
			);
		}
		else if($ipInstance.name === "MDIV")
		{
			config = [
				{
					name: "divideValue",
					displayName: "Divide Value",
					default: $ipInstance.resetValue,
					description: "Divide Value for MDIV when sourced by SYSOSC with 4MHz",
					longDescription: `
MDIV is a special case divider that is used to enable MCLK operation in between the lowest SYSOSC
frequency (4MHz) and the LFCLK frequency (32 kHz). It is ideal for applications which are peak
current limited but still require a higher clock speed than 32 kHz. Asynchronous fast clock requests
will also be disabled. It must be sourced by SYSOSC when the frequency is selected as 4MHz.

**Note: If not sourced by SYSOSC with frequency 4MHz, MDIV should remain disabled (/1)**
					`,
					options: _.map($ipInstance.divideValues, (v) => ({ name: v, displayName: `/${v}` }))
				},
				{
					name: $ipInstance.outPins[0].name,
					displayName: "Output",
					default: [0, 0],
					getValue: (inst) => {
						let value = inst[$ipInstance.inPins[0].name];
						// Temporary fix for CLK2X in the PLL
						if (_.isArray(value)) {
							return _.map(value, (v) => {
								return inst.isMDIVEnabled?(v / inst.divideValue):v;
							});
						}
						return inst.isMDIVEnabled?(value / inst.divideValue):value;
					},
				},
				{
						name: "isMDIVEnabled",
						displayName: "MDIV Enabled?",
						description: "Displays whether MDIV is enabled by the system (SYSOSC sourced at 4MHz)",
						longDescription: `
						This read-only value shows whether MDIV is enabled and able to change the value of MCLK. It is only
						enabled when sourced from SYSOSC with a source frequency of 4MHz. If not enabled, the value of MDIV
						will not affect the end-signal
						`,
						hidden: true,
						default: false,
						getValue: isMDIVEnabled
				}
			];
		}
		let enableConfig = [];
		if(_.startsWith($ipInstance.name, "PLL")){
			if(isEnabled){
				let pllNum = $ipInstance.name.match(/\d/)[0];
				enableConfig = {
					name: "enable",
					displayName: "Enable "+$ipInstance.name,
					description: "Enables or Disables the "+$ipInstance.name + " automatically",
					default: false,
					hidden: true,
				};
				switch(pllNum){
					case "0":
						enableConfig.getValue = getEnableSYSPLL0;
						break;
					case "1":
						enableConfig.getValue = getEnableSYSPLL1;
						break;
					case "2":
						enableConfig.getValue = getEnableSYSPLL2X;
						break;
					default:
						throw "pll not found";
						break;
				}
			} else {
				enableConfig = {
					name: "enable",
					default: true,
					hidden: true
				};
			}
		} else {
			if(isEnabled){
				enableConfig = {
						name: "enable",
						displayName: "Enable "+$ipInstance.name,
						description: "Enables or Disables the "+$ipInstance.name,
						default: false
					}
			} else {
				enableConfig = {
						name: "enable",
						default: true,
						hidden: true
					};
			}
		}
		config.push(enableConfig);
		return config;
	}
};
