
function validateGates(inst, validation) {
	let clockTreeEn = false;
	if(system.modules["/ti/driverlib/SYSCTL"]){
		clockTreeEn = system.modules["/ti/driverlib/SYSCTL"].$static.clockTreeEn;
	}

	if(inst.$name === "MFPCLKGATE"){
		if(inst[inst.$ipInstance.outPins[0].name] > 4){
			// this is only possible if sourced from the HFCLK and the divider needs to be increased.
			let divMod = system.modules["/ti/clockTree/divider.js"];
			let divInst = _.find(divMod.$instances, ['$name', 'HFCLK4MFPCLKDIV']);
			if(_.isUndefined(divInst)){ throw "cannot find instance HFCLK4MFPCLKDIV"; }
			validation.logError("MFPCLK is limited to below 4MHz.", system.clockTree["net_mfpclk"])
			validation.logError("MFPCLK is limited to below 4MHz.", divInst, "divideValue");
		}
		/* Special Case: DAC12 Validation */
		if(system.modules["/ti/driverlib/SYSCTL"]){
			if(system.modules["/ti/driverlib/SYSCTL"].$static.clockTreeEn){
				let DACMod = system.modules["/ti/driverlib/DAC12"];
				if (DACMod){
					if (DACMod.$static.dacEnable && !inst.enable) {
						validation.logError("MFPCLK must be enabled when DAC12 peripheral is added.", inst, ["enable"]);
					}
				}
			}
		}

	}
	if(inst.$name === "EXCLKGATE"){
		let modPF = system.modules["/ti/clockTree/pinFunction.js"];
		let clkOutInst = _.find(modPF.$instances, ['$name', 'CLKOUT']);

		if(_.isUndefined(clkOutInst)){
			throw 'could not find the CLKOUT pin function instance';
		}
		if(inst.enable & !clkOutInst.enable){
			validation.logWarning("The CLKOUT gate is enabled but the CLKOUT pin is not enabling the GPIO pin", clkOutInst, "enable");
		}
	}

	if(inst.$name === "MFCLKGATE"){
		if(!inst.enable && clockTreeEn){
			let vrefInstance = system.modules["/ti/driverlib/VREF"];
			if (vrefInstance){
				if(vrefInstance.$static.advClockConfigEnable){
					if((vrefInstance.$static.advClkSrc == "DL_VREF_CLOCK_MFCLK")){
						validation.logError("MFCLK must be enabled for the current configuration.", inst, ["enable"]);
					}
				}
			}
		}
	}
	if(inst.$name === "EXCLKGATE"){
		let modPF = system.modules["/ti/clockTree/pinFunction.js"];
		let clkOutInst = _.find(modPF.$instances, ['$name', 'CLKOUT']);

		if(_.isUndefined(clkOutInst)){
			throw 'could not find the CLKOUT pin function instance';
		}
		if(inst.enable & !clkOutInst.enable){
			validation.logWarning("The CLKOUT gate is enabled but the CLKOUT pin is not enabling the GPIO pin", clkOutInst, "enable");
		}
	}
	if(inst.$name === "EXCLKGATE"){
		let modPF = system.modules["/ti/clockTree/pinFunction.js"];
		let clkOutInst = _.find(modPF.$instances, ['$name', 'CLKOUT']);

		if(_.isUndefined(clkOutInst)){
			throw 'could not find the CLKOUT pin function instance';
		}
		if(inst.enable & !clkOutInst.enable){
			validation.logWarning("The CLKOUT gate is enabled but the CLKOUT pin is not enabling the GPIO pin", clkOutInst, "enable");
		}
	}

}


exports = {
	displayName: "Gate",
	validate: validateGates,
	config: [{
		name: "type",
		displayName: "Type",
		default: "Gate",
		readOnly: true,
	}],
	extendConfig: ({ $ipInstance }) => {
		let isFixed = false;
		if($ipInstance.fixed == true){
			/* option to remove enable */
			isFixed = true;
		}

		const enable = {
			name: "enable",
			displayName: "Enable",
			default: false,
		};

		const pin = {
			name: $ipInstance.outPins[0].name,
			default: [0, 0],
			getValue: (inst) => {
				if (inst.enable !== false) {
					return inst[$ipInstance.inPins[0].name];
				}
				return 0;
			},
		};

		return isFixed?[pin]:[enable, pin];
	},
};
