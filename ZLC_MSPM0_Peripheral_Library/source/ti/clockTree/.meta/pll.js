exports = {
	displayName: "PLL",
	config: [{
		name: "type",
		displayName: "Type",
		default: "PLL",
		readOnly: true,
	}],
	extendConfig: ({ $ipInstance }) => {
        // determine which pin is which:
        let clk0Pin;
        let clk1Pin;
        let clk2XPin;
        for(let pin of $ipInstance.outPins) {
            /* Case insensitive match */
            if(pin.name.match(/_CLK0/i)) {
                clk0Pin = pin;
            }
            else if(pin.name.match(/_CLK1/i)) {
                clk1Pin = pin;
            }
            else if(pin.name.match(/_CLK2X/i)) {
                clk2XPin = pin;
            }
        }

        return [
            {
                name: "enableclk0",
                displayName: "Enable CLK0",
                default: true
            },
            {
                name: "clk0DIV",
                displayName: "PLL CLK 0 Divider",
                description: "CLK0 specific divider that divides the VCO value",
                longDescription: `This is a divider that belongs only to Clk 0 and
                can be set from /2 to /32 in steps of 2.
                \n CLK0 Frequency = VCO / CLK0Div`,
                default: 0,
                options: (inst) => {
                    let options = [];
                    let factor;
                    for(let i = 0; i < 16; i++){
                        factor = 2*(i+1);
                        options.push({name: i, displayName: "/"+factor})
                    }
                    return options;
                }
            },
            {
                name: "enableclk1",
                displayName: "Enable CLK1",
                default: true
            },
            {
                name: "clk1DIV",
                displayName: "PLL CLK 1 Divider",
                description: "CLK1 specific divider that divides the VCO value",
                longDescription: `This is a divider that belongs only to Clk 1 and
                can be set from /2 to /32 in steps of 2.
                \n CLK1 Frequency = VCO / CLK0Div`,
                default: 0,
                options: (inst) => {
                    let options = [];
                    let factor;
                    for(let i = 0; i < 16; i++){
                        factor = 2*(i+1);
                        options.push({name: i, displayName: "/"+factor})
                    }
                    return options;
                }
            },
            {
                name: "enableclk2x",
                displayName: "Enable CLK2X",
                default: true
            },
            {
                name: "clk2XDIV",
                displayName: "PLL CLK 2X Divider",
                description: "CLK1 specific divider that divides the VCO value",
                longDescription: `This is a divider that belongs only to Clk 1 and
                can be set from /1 to /16 in steps of 1.
                \n CLK2X Frequency = 2 * VCO / CLK2XDiv`,
                default: 0,
                options: (inst) => {
                    let options = [];
                    let factor;
                    for(let i = 0; i < 16; i++){
                        factor = i+1;
                        options.push({name: i, displayName: "/"+factor})
                    }
                    return options;
                }
            },
            {
                name: "PDIV",
                displayName: "Pre-Divider",
                description: "Pre-Divides the input",
                longDescription: `Divides the input reference clock prior to beginning the PLL feedback loop`,
                default: 0,
                options: [
                    {name: 0, displayName: "/1"},
                    {name: 1, displayName: "/2"},
                    {name: 2, displayName: "/4"},
                    {name: 3, displayName: "/8"}
                ]
            },
            {
                name: "QDIV",
                displayName: "QDIV",
                description: "Feedback divider value",
                longDescription: `Value of the QDIV feedback divider, valid range: /2 to /128`,
                default: 2,
                isInteger: true,
                range: [2, 128]
            },
            {
                name: "VCO",
                displayName: "VCO",
                description: "Voltage-Controlled Oscillator",
                longDescription: `Output Frequency = Reference Frequency * QDIV / PreDivider`,
                default: 0,
                getValue: (inst) => {
                    return inst[$ipInstance.inPins[0].name] * inst.QDIV / (1 << inst.PDIV);
                }
            },
            {
                name: clk0Pin.name,
                default: [0, 0],
                getValue: (inst) => {
                    return inst.VCO / (2 * (inst.clk0DIV + 1));
                }
            },
            {
                name: clk1Pin.name,
                default: [0, 0],
                getValue: (inst) => {
                    return inst.VCO / (2 * (inst.clk1DIV + 1));
                }
            },
            {
                name: clk2XPin.name,
                default: [0, 0],
                getValue: (inst) => {
                    return 2 * inst.VCO / (inst.clk2XDIV + 1);
                }
            }
        ];
    }
};
