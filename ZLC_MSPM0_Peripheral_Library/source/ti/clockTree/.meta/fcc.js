const { getDefaultValue } = system.getScript("./defaultValue.js");

exports = {
	displayName: "Frequency Clock Counter",
	config: [{
		name: "type",
		displayName: "Type",
		default: "fcc",
		readOnly: true,
	}],
	extendConfig: ({ $ipInstance }) => {

		// Create a pin frequency configurable for every output pin.
		// Base the value of it on the value of an arbitrary input pin
		// If there are no input pins, then base the output on the name of the module (to get predictable yet different values)

		const source = getDefaultInput($ipInstance);

		const config = [
			// {
			// 	name  		: "$isUsed",
			// 	hidden		: true,
			// 	readOnly	: true,
			// 	getValue	: (inst) => {
			// 		return inst.enable;
			// 	}
			// },
			{
				name        : "enable",
				displayName : "Enable FCC",
				description : 'Enable in-system testing and calibration',
				longDescription: `
Enable the Frequency Clock Counter (FCC).
FCC enables flexible in-system testing and calibration of a variety of oscillators
and clocks on the device. The FCC counts the number of clock periods seen on the
selected clock source within a known fixed trigger period (derived from a secondary
reference source) to provide an estimation of the frequency of the source clock.
				`,
				hidden      : false,
				default     : false,
				onChange    : (inst,ui) => {
					ui.fccTrigLvl.hidden = !inst.enable;
					ui.fccPeriods.hidden = (!inst.enable) || !(inst.fccTrigLvl == "RISE_RISE");
				}
			},
			// DL_SYSCTL_configFCC()
			// DL_SYSCTL_FCC_TRIG_TYPE_ -> if RISE selected, must set period
			{
				name        : "fccTrigLvl",
				displayName : "FCC Trigger Level",
				description : 'Determines if active high level trigger or rising-edge to rising-edge',
				hidden      : true,
				default     : "RISE_RISE",
				options     : [
					{name: "RISE_RISE", displayName: "Rising-edge to rising-edge pulse"},
					{name: "LEVEL", displayName: "Active-high pulse level"},
				],
				onChange    : (inst,ui) => {
					ui.fccPeriods.hidden = !(inst.fccTrigLvl == "RISE_RISE");
				}
			},
			{
				name        : "fccPeriods",
				displayName : "FCC Periods",
				description : 'Set the number of rising-edge to rising-edge period for FCC',
				hidden      : true,
				default     : "01",
				options     : [
					// DL_SYSCTL_FCC_TRIG_CNT_
					{name: "01", displayName: "1"},
					{name: "02", displayName: "2"},
					{name: "03", displayName: "3"},
					{name: "04", displayName: "4"},
					{name: "05", displayName: "5"},
					{name: "06", displayName: "6"},
					{name: "07", displayName: "7"},
					{name: "08", displayName: "8"},
					{name: "09", displayName: "9"},
					{name: "10", displayName: "10"},
					{name: "11", displayName: "11"},
					{name: "12", displayName: "12"},
					{name: "13", displayName: "13"},
					{name: "14", displayName: "14"},
					{name: "15", displayName: "15"},
					{name: "16", displayName: "16"},
					{name: "17", displayName: "17"},
					{name: "18", displayName: "18"},
					{name: "19", displayName: "19"},
					{name: "20", displayName: "20"},
					{name: "21", displayName: "21"},
					{name: "22", displayName: "22"},
					{name: "23", displayName: "23"},
					{name: "24", displayName: "24"},
					{name: "25", displayName: "25"},
					{name: "26", displayName: "26"},
					{name: "27", displayName: "27"},
					{name: "28", displayName: "28"},
					{name: "29", displayName: "29"},
					{name: "30", displayName: "30"},
					{name: "31", displayName: "31"},
					{name: "32", displayName: "32"},
				],
			},
		];
		const pinConfig = _.map($ipInstance.outPins, (pin) => ({
			name: pin.name,
			default: [0, 0],
			getValue: (inst) => source ? inst[source.name] : getDefaultValue($ipInstance.name),
			hidden: false,
		}));

		return config;
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
