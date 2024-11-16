function validate(inst, validation){
	if(inst.$name === "SYSPLLMUX"){
		let inputFreq = inst[inst.inputSelect];
		if(inputFreq < 4 || inputFreq > 48) {
			validation.logError("SYSPLL cannot be sourced outside the range of 4 MHz to 48 MHz.");
		}
	}
}

exports = {
	displayName: "Mux",
	config: [{
		name: "type",
		displayName: "Type",
		default: "Mux",
		readOnly: true,
	}],
	extendConfig: ({ $ipInstance }) => {
		let config = [
			{
				name: "inputSelect",
				displayName: "Input Select", default: $ipInstance.resetValue,
				options: _.map($ipInstance.inPins, ( name ) => ( name )),
			},
			{
				name: $ipInstance.outPins[0].name,
				default: [0, 0],
				getValue: (inst) => inst[inst.inputSelect],
			},
		];
		return config;
	}
};
