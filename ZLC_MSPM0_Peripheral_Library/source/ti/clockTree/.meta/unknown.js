const { getDefaultValue } = system.getScript("./defaultValue.js");

exports = {
	displayName: "Unknown",
	config: [{
		name: "type",
		displayName: "Type",
		default: "Unknown",
		readOnly: true,
	}],
	extendConfig: ({ $ipInstance }) => {

		// Create a pin frequency configurable for every output pin.
		// Base the value of it on the value of an arbitrary input pin
		// If there are no input pins, then base the output on the name of the module (to get predictable yet different values)

		const source = getDefaultInput($ipInstance);
		const pinConfig = _.map($ipInstance.outPins, (pin) => ({
			name: pin.name,
			default: [0, 0],
			getValue: (inst) => source ? inst[source.name] : getDefaultValue($ipInstance.name),
			hidden: false,
		}));

		// For testing, we'll generate a config for PLLCTRL0 which will cause an error when reading from a specific pin

		if ($ipInstance.name === "PLLCTRL0") {
			pinConfig[0].getValue = (inst) => {
				switch (inst.problemType) {
					default:
					case "none": return inst[source.name];
					case "undefined": return inst.wrongPinName;
					case "exception": throw new Error("whoops");
				}
			};
			return [
				{
					name: "problemType",
					displayName: "Problem Type",
					options: _.map(["none", "undefined", "exception"], (name) => ({ name })),
					default: "none",
				},
				...pinConfig,
			];
		}

		// For testing, we'll also add a configurable to change the error message on frequency to a warning

		if ($ipInstance.name === "ADC0") {
			return [
				{
					name: "warning",
					default: false,
				},
				...pinConfig,
			];
		}
		return pinConfig;
	},
	validate: (inst, { logError, logWarning }) => {
		if (inst.$ipInstance.name === "ADC0") {
			const [low, high] = inst["adc_clk"];
			if (high > 20) {
				if (inst.warning) {
					logWarning("frequency over limit", inst, "adc_clk")
				} else {
					logError("frequency over limit", inst, "adc_clk")
				}
			}
		}
	},
};

function getDefaultInput(ipInstance) {

	// Real meta-code will not read from an input that is circular, as it will all be internally meaningful.
	// But this dummy meta-data is just going to change the default input based on the name in order to avoid it.

	switch (ipInstance.name) {
		case "MAIN_EMMCSD1_IO_CLKLB_SEL":
			return ipInstance.inPins[1];
		default:
			return _.first(ipInstance.inPins);
	}
}
