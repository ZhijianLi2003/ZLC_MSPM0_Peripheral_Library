const typeMap = { // any sort of type, but this is an instance that's loaded from the device
	ClockDivider: "ti/clockTree/unknown.js",
	ClockMux: "ti/clockTree/unknown.js",
	Divider: "ti/clockTree/divider.js",
	externalSource: "ti/clockTree/externalSource.js",
	fcc: "ti/clockTree/fcc.js",
	FrequencyLabel: "ti/clockTree/unknown.js",
	Gate: "ti/clockTree/gate.js",
	Multiplier: "ti/clockTree/multiplier.js",
	Mux: "ti/clockTree/mux.js",
	Oscillator: "ti/clockTree/oscillator.js",
	Peripheral: "ti/clockTree/unknown.js",
	PinFunction: "ti/clockTree/pinFunction.js",
	pll: "ti/clockTree/pll.js",
	synchro: "ti/clockTree/synchro.js",
	sysosc: "ti/clockTree/sysosc.js",
	unknown: "ti/clockTree/unknown.js",
};


function defaultView(ipInstance) {
	return {
		displayName: ipInstance.displayName ?? ipInstance.name,
		ipInstances: [ipInstance.name],
		algorithm: "fanInAndOut",
	}
}

let Common = system.getScript("/ti/driverlib/Common.js");

let family = Common.getDeviceFamily();
let deviceComponent = system.getScript("/ti/clockTree/components/components" + family);

let tree = [
	{
		displayName: "Clock Views",
		entries: [
			{
				displayName: "Basic",
				ipInstances: 		deviceComponent.entriesSimple,
				frequencyLabels: 	deviceComponent.freqLabelSimple,
				layout: 			deviceComponent.layoutSimple,
				brokenConnections: 	deviceComponent.brokenConnectionsSimple,
			},
			{
				displayName: "Clock Output and FCC",
				ipInstances: 		deviceComponent.entriesEXT,
				frequencyLabels: 	deviceComponent.freqLabelEXT,
				layout: 			deviceComponent.layoutEXT,
				brokenConnections: 	deviceComponent.brokenConnectionsEXT
			}
		]
	},
];

if(deviceComponent.entriesFull.length > 0){
	tree[0].entries.push({
		displayName: "Full",
		ipInstances: deviceComponent.entriesFull,
		frequencyLabels: deviceComponent.freqLabelSimple,
		layout: deviceComponent.layoutFull,
		//brokenConnections: deviceComponent.brokenConnectionsFull
	});
}


let views = [
	{
		"name": "/ti/clockTree/views/freqSummary.xdt",
		"displayName": "Clock Tree Summary",
		"viewType": "markdown"
	},
];

let exportsConditional = {};
if(system.deviceData.clockTree){
	exportsConditional = {
		// topModules: [{
		// 	displayName: "Modules",
		// 	modules: ["/modules/basic.js"],
		// }],
		clockTree: {
			typeMap,
			tree,
			initialView: views[0].name,
			precision: 5,
		},
		views
	}
}

exports = exportsConditional;
