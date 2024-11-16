exports = {
	displayName: "Synchro",
	config: [{
		name: "type",
		displayName: "Type",
		default: "synchro",
		readOnly: true,
	}],
	extendConfig: ({ $ipInstance }) => {
        let inputPin;
        let enablePossible = false;
        for(let pin of $ipInstance.inPins) {
            /* Case insensitive match */
            if(pin.name.match(/_IN/i)) {
                inputPin = pin;
            }
            if(pin.name.match(/_EN/i)){
                enablePossible = true;
            }
        }
        let allConfig = [{
            name: "enable",
            displayName: "Enable " + $ipInstance.name,
            default: true,
            hidden: !enablePossible
        }, {
            /* pipe pin if enabled */
            name: $ipInstance.outPins[0].name,
            default: [0, 0],
            getValue: (inst) => {
                if(inst.enable)
                    return inst[inputPin.name];
                else {
                    return 0;
                }
            }
        }]
        return allConfig;
    }
};
