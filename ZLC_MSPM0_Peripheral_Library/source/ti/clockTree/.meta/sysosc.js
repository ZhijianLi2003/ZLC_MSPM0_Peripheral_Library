const { getDefaultValue } = system.getScript("./defaultValue.js");

exports = {
	displayName: "SYSOSC",
	config: [{
		name: "type",
		displayName: "Type",
		default: "SYSOSC",
		readOnly: true,
	}],
	extendConfig: ({ $ipInstance }) => {
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

        return [
        {
            name: "frequencySelect",
            default: 32,
            options: [
                {name: 32}, {name: 24}, {name: 16}, {name: 8}
            ]
        },
        {
            name: outPin.name,
            default: 0,
            getValue: (inst) => { return inst.frequencySelect; }
        },{
            /* 4 MHz constant output */
            name: const4MHzPin.name,
            default: 4,
            getValue: (inst) => { return 4; }
        }];
    }
};
