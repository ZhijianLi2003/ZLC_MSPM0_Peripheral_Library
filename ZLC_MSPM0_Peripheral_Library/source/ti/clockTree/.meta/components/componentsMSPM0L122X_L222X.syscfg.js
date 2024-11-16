let M0L122_Simple_Entries = [
	// Sources
	"HFCLKEXT",
	"HFXT",
	"LFCLKEXT",
	"LFOSC",
	"LFXT",
	"SYSOSC",

	// MUX/Gates
	"EXLFMUX",
	"LFXTMUX",
	"EXHFMUX",
	"HSCLKMUX",
	"SYSCTLMUX",
	"ULPCLKGATE",
	//"ADCMUX",

	"MFPCLKMUX",
	"MFPCLKGATE",
	"MFCLKGATE",
	"LFCLKGATE",
	"MCLKGATE",
	"CPUCLKGATE",
	//"ADCCLKGATE",

	// // Dividers
	"MDIV",
	"UDIV",
	"HFCLK4MFPCLKDIV",

	// Nets
	// "net_adcclk",
	//"net_extlfclk",
	"net_hfclk",
	"net_lfclk",
	"net_mclk",
	"net_mfclk",
	"net_mfpclk",
	"net_mfpclkGate",
	"net_sysosc",
	"net_sysosc4m",
	"net_ulpclk",
	"net_cpuclk",
	"net_ulpclk",
];

let M0L122_CLK_OUT_FCC_Entries = [
	// input nets
	"net_sysosc",
	"net_ulpclk",
	"net_lfclk",
	"net_hfclk",
	"net_mclk",
	"net_mfpclkGate",
	//"net_extlfclk",

	// FCC
	"FCC",
	"FCCEXT",
	"FCCSELCLKMUX",
	"FCCTRIGMUX",
	"net_fccin",

	// CLKOUT
	"EXCLKMUX",
	"EXCLKDIV",
	"EXCLKGATE",
	"net_exclk",
	"CLKOUT",
];

let M0L122_Simple_reasonableLayout = {

	// 0th layer: left-most on page
	"LFCLKEXT": 		{ layer: 0,  position: 1 },
	"LFXT": 			{ layer: 0,  position: 2 },
	"HFCLKEXT": 		{ layer: 0,  position: 4 },
	"HFXT": 			{ layer: 0,  position: 5 },

	"LFOSC": 			{ layer: 1,  position: 0 },
	"EXLFMUX": 			{ layer: 1,  position: 1 },
	"SYSOSC": 			{ layer: 1,  position: 3 },
	"EXHFMUX": 			{ layer: 1,  position: 5 },

	"sysosc_4m1": 		{ layer: 2,  position: 3 },
	"net_sysosc": 		{ layer: 2,  position: 4 },
	"net_hfclk": 		{ layer: 2,  position: 5 },
	// "net_extlfclk": 	{ layer: 2,  position: X },

	"hfmfp_4m": 		{ layer: 3,  position: 7 },
	//"hsclk_hf": 		{ layer: 3,  position: 2 },

	"LFXTMUX": 			{ layer: 4,  position: 0 },
	"HSCLKMUX": 		{ layer: 4,  position: 4 },
	"HFCLK4MFPCLKDIV": 	{ layer: 4,  position: 7 },
	"net_sysosc4m": 	{ layer: 4,  position: 8 },

	"MDIV": 			{ layer: 5,  position: 0 },
	"MFPCLKMUX": 		{ layer: 5,  position: 1 },
	// "adc_sysosc": 	{ layer: 5,  position: X },
	// "adc_ulp": 		{ layer: 5,  position: X },

	"SYSCTLMUX": 		{ layer: 6,  position: 2 },
	"net_mfpclkGate": 	{ layer: 6,  position: 6 },
	// "ADCMUX": 		{ layer: 6,  position: 8 },

	"UDIV": 			{ layer: 7,  position: 1 },

	"LFCLKGATE": 		{ layer: 8,  position: 0 },
	"ULPCLKGATE": 		{ layer: 8,  position: 1 },
	"MCLKGATE": 		{ layer: 8,  position: 2 },
	"CPUCLKGATE": 		{ layer: 8,  position: 3 },
	"MFPCLKGATE": 		{ layer: 8,  position: 4 },
	"MFCLKGATE": 		{ layer: 8,  position: 5 },
	// "MCLKGATE": 		{ layer: 8,  position: X },
	// "ADCCLKGATE": 	{ layer: 8,  position: X },

	"net_mclk": 		{ layer: 9,  position: 2 },
	"net_mfclk"	: 		{ layer: 9,  position: 7 },
	"net_mfpclk": 		{ layer: 9,  position: 6 },
	"net_ulpclk": 		{ layer: 9,  position: 1 },
	"net_cpuclk": 		{ layer: 9,  position: 3 },
	"net_lfclk": 		{ layer: 9,  position: 0 },
	// "net_adcclk": 	{ layer: 9,  position: X },
};

let M0L122_CLK_OUT_FCC_Layout = {

	"net_hfclk": 		{ layer: 0, position: 0 },
	"net_lfclk": 		{ layer: 0, position: 1 },
	"net_mfpclkGate": 	{ layer: 0, position: 2 },
	"net_sysosc": 		{ layer: 0, position: 4 },
	"net_ulpclk": 		{ layer: 0, position: 5 },
	"FCCEXT": 			{ layer: 0, position: 9 },

	"EXCLKMUX": 		{ layer: 1, position: 0 },
	"EXCLKDIV": 		{ layer: 2, position: 0 },
	"EXCLKGATE": 		{ layer: 3, position: 0 },

	"net_exclk": 		{ layer: 4, position: 0 },
	"fcc_hfclk": 		{ layer: 4, position: 1 },
	"net_mclk": 		{ layer: 4, position: 2 },
	"fcc_sysosc": 		{ layer: 4, position: 3 },
	"net_fccin": 		{ layer: 4, position: 9 },
	"fcctrig_lfclk": 	{ layer: 4, position: 10 },

	"FCCSELCLKMUX": 	{ layer: 5, position: 1 },
	"FCCTRIGMUX": 		{ layer: 5, position: 3 },
	"FCC": 				{ layer: 6, position: 2 },

	"CLKOUT": 			{ layer: 7, position: 0 },

};

let M0L122_Simple_BrokenConnections = [
	{ instName: "SYSOSC", pinName: "SYSOSC_4M", name: "sysosc_4m1" },
	// 	{ instName: "ADCMUX", pinName: "ADCMUX_ULPCLK", name: "adc_ulp"},
	// 	{ instName: "ADCMUX", pinName: "ADCMUX_SYSOSC", name: "adc_sysosc"},
];

let M0L122_EXT_BrokenConnections = [
	{ instName: "FCCSELCLKMUX", pinName: "FCCSELCLKMUX_HFCLK", name: "fcc_hfclk" },
	{ instName: "FCCSELCLKMUX", pinName: "FCCSELCLKMUX_SYSOSC", name: "fcc_sysosc"},
	{ instName: "FCCTRIGMUX", 	pinName: "FCCTRIGMUX_LFCLK", name: "fcctrig_lfclk" }
];

const M0L122_GATESimple = [
	"net_mclk", "net_ulpclk", "net_lfclk", "net_cpuclk", "net_sysosc",
	"net_mfclk", "net_mfpclk", "net_adcclk", "net_vco"
];

const M0L122_GATEEXT = [
	"net_mclk", "net_sysosc", "net_lfclk", "net_hfclk",
	"net_mfpclkGate", "net_ulpclk", "net_exclk"
];

exports = {
    entriesSimple: M0L122_Simple_Entries,
    layoutSimple: M0L122_Simple_reasonableLayout,
	brokenConnectionsSimple: M0L122_Simple_BrokenConnections,
	freqLabelSimple: M0L122_GATESimple,
	entriesFull: [],
	layoutFull: {},
	brokenConnectionsFull: [],
	entriesEXT: M0L122_CLK_OUT_FCC_Entries,
	freqLabelEXT: M0L122_GATEEXT,
	layoutEXT: M0L122_CLK_OUT_FCC_Layout,
	brokenConnectionsEXT: M0L122_EXT_BrokenConnections
}
