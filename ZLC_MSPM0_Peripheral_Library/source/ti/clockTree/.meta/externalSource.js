const { getDefaultValue } = system.getScript("./defaultValue.js");
const { isDeviceM0G } = system.getScript("/ti/driverlib/Common.js");

function pinmuxRequirements(inst)
{
    let resources = [];
    if(isDeviceM0G() && inst.enabled){
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
                resources.push({
                    name            : "lfclkInPin",
                    displayName     : "LFCLK In",
                    interfaceNames  : ["LFXOUT"],
                });
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
                resources.push({
                    name            : "hfclkInPin",
                    displayName     : "HFCLK In",
                    interfaceNames  : ["HFXOUT"],
                });
                break;
            default:
                break;
        }
    }

}

exports = {
	displayName: "External Source",
	config: [{
		name: "type",
		displayName: "Type",
		default: "External Source",
		readOnly: true,
	}],
	extendConfig: ({ $ipInstance }) => {

        return [

        {
            /* I want them to insert their own value */
            name: $ipInstance.outPins[0].name,
            default: 0,
            getValue: (inst) => { return inst.outputFrequency; }
        },{
            name: "outputFrequency",
            default: 0,
        }];
    }
};
