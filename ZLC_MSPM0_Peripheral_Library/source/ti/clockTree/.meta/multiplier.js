function validateMultiplier(inst, validation){
	// VALIDATE FVCO frequency using QDIV (which is a multiplier since it's a loop)

	if(inst.$name == "PLL_QDIV")
	{
		let mod = system.modules["/ti/clockTree/divider.js"];
		let pllClk0Div = _.find(mod.$instances, ['$name', 'PLL_CLK0_DIV']);
		let pllClk1Div = _.find(mod.$instances, ['$name', 'PLL_CLK1_DIV']);
		let pllClk2XDiv = _.find(mod.$instances, ['$name', 'PLL_CLK2X_DIV']);
		let pllEnabled = false;
		if(pllClk0Div && pllClk1Div && pllClk2XDiv){
			pllEnabled = pllClk0Div.enable || pllClk1Div.enable || pllClk2XDiv.enable;
		}
	}
}

exports = {
	displayName: "Multiplier",
	validate: validateMultiplier,
	config: [{
		name: "type",
		displayName: "Type",
		default: "Multiplier",
		readOnly: true,
	}],
	extendConfig: ({ $ipInstance }) => [{
		name: "multiplyValue",
		displayName: "Multiply Value",
		default: $ipInstance.resetValue,
		options: _.map($ipInstance.multiplyValues, (v) => ({ name: v, displayName: `X ${v}` })),
	}, {
		name: $ipInstance.outPins[0].name,
		displayName: "Output",
		default: [0, 0],
		getValue: (inst) => {
			const value = inst[$ipInstance.inPins[0].name];
			if (_.isArray(value)) {
				return _.map(value, (v) => v * inst.multiplyValue);
			}
			return value * inst.multiplyValue;
		},
	}],
};
