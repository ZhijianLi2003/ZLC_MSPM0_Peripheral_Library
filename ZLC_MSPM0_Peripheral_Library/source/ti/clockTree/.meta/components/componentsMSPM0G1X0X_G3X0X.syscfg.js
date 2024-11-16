let M0G_Simple_Entries = [
	// Sources
	"HFCLKEXT",
	"HFXT",
	"LFCLKEXT",
	"LFOSC",
	"LFXT",
	"SYSOSC",

	// PLL
	"PLL_CLK0_DIV",
	"PLL_CLK1_DIV",
	"PLL_CLK2X_DIV",
	"PLL_CLK2X_MUL",
	"PLL_PDIV",
	"PLL_QDIV",
	"SYSPLLMUX",

	// MUX/Gates
	"EXLFMUX",
	"LFXTMUX",
	"EXHFMUX",
	"HSCLKMUX",
	"SYSCTLMUX",
	"ULPCLKGATE",
	"CANCLKMUX",
	//"ADCMUX",

	"MFPCLKMUX",
	"MFPCLKGATE",
	"MFCLKGATE",
	"LFCLKGATE",
	"MCLKGATE",
	"CPUCLKGATE",
	"CANCLKGATE",
	//"ADCCLKGATE",

	// // Dividers
	"MDIV",
	"UDIV",
	"HFCLK4MFPCLKDIV",

	// Nets
	"net_vco",
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
	"net_syspll0",
	"net_syspll1",
	"net_syspll2x",
	"net_ulpclk",
	"net_canclk",
	"net_cpuclk",
	"net_ulpclk",
];

let M0G_Full_Entries = M0G_Simple_Entries.concat([
	"FCC",
	"FCCEXT",
	"FCCSELCLKMUX",
	"FCCTRIGMUX",
	"net_fccin",

	"EXCLKMUX",
	"EXCLKDIV",
	"EXCLKGATE",
	"net_exclk",
	"CLKOUT",
]);


let M0G_CLK_OUT_FCC_Entries = [
	// input nets
	"net_sysosc",
	"net_ulpclk",
	"net_lfclk",
	"net_hfclk",
	"net_mclk",
	"net_mfpclkGate",
	"net_syspll0",
	"net_syspll1",
	"net_syspll2x",
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

let M0G_Peripherals = [
	"TIMG0"
];


let M0G_Simple_reasonableLayout = {

	"LFOSC": { layer: 1, position: 0 },
	"LFCLKEXT": { layer: 0, position: 1 },
	"LFXT": { layer: 0, position: 2 },
	"HFCLKEXT": { layer: 0, position: 4 },
	"HFXT": { layer: 0, position: 5 },

	"SYSOSC": { layer: 1, position: 3 },

	"PLLGroup": { layer: 4, position: 0 },

	"EXLFMUX": { layer: 1, position: 1 },
	"LFXTMUX": { layer: 7, position: 0 },
	"EXHFMUX": { layer: 1, position: 5 },
	"HSCLKMUX": { layer: 7, position: 4 },
	"CANCLKMUX": { layer: 7, position: 5 },
	"MFPCLKMUX": { layer: 8, position: 6 },
	"SYSCTLMUX": { layer: 9, position: 2 },

	"RTCCLKGATE": { layer: 10, position: 0 },
	"MDIV": { layer: 8, position: 4 },
	"UDIV": { layer: 10, position: 1 },
	"HFCLK4MFPCLKDIV": { layer: 7, position: 7 },
	//"MCLKGATE": { layer: 11, position: 2 },
	"MFCLKGATE": { layer: 10, position: 7 },
	"MFPCLKGATE": { layer: 10, position: 6 },
	"LFCLKGATE": {layer: 11, position: 0},
	"MCLKGATE": {layer: 11, position: 2},
	"ULPCLKGATE": {layer: 11, position: 1},
	"CPUCLKGATE": {layer: 11, position: 3},

	// "ADCMUX": { layer: 9, position: 8 },
	// "adc_sysosc": {layer: 8, position: 5},
	// "adc_ulp": {layer: 8, position: 6},
	// //"ADCCLK": { layer: 0, position: 0 },
	// "ADCCLKGATE": { layer: 10, position: 8 },
	"CANCLKGATE": { layer: 10, position: 5},

	// SYSPLL
	"SYSPLLMUX": { layer: 0, position: 1 },
	"PLL_PDIV": { layer: 1, position: 1 },
	"PLL_QDIV": { layer: 2, position: 1 },
	"net_vco": {layer: 3, position: 1},
	"PLL_CLK2X_MUL": { layer: 4, position: 1 },
	"PLL_CLK0_DIV": { layer: 5, position: 0 },
	"PLL_CLK2X_DIV": { layer: 5, position: 1 },
	"PLL_CLK1_DIV": { layer: 5, position: 2 },

	// "net_adcclk": { layer: 11, position: 9 },
	"net_canclk": { layer: 11, position: 5 },
	//"net_extlfclk": {layer: 2, position: 1},
	"net_hfclk": {layer: 2, position: 5 },
	"net_lfclk": { layer: 12, position: 0},
	"net_mclk": { layer: 11, position: 2},
	"net_sysosc4m": { layer: 7, position: 7 },
	"net_mfclk"	: {layer: 11, position: 7},
	"net_mfpclkGate": {layer: 9, position: 6 },
	"net_mfpclk": { layer: 11, position: 6 },
	"net_sysosc": { layer: 2, position: 4 },
	"net_syspll0": {layer: 5, position: 3 },
	"net_syspll1": {layer: 5, position: 4 },
	"net_syspll2x": {layer: 5, position: 3 },
	"net_ulpclk": {layer: 11, position: 1},
	"net_cpuclk": {layer: 11, position: 3},
	"sysosc_4m1": { layer: 2, position: 3 },
	"hfmfp_4m": { layer: 5, position: 7 },
	"hsclk_hf": { layer: 5, position: 2 },
};

let M0G_Full_AdditionalLayout = {
	"net_fccin": { layer: 0, position: 9 },
	"FCCEXT": { layer: 0, position: 9 },
	"fcctrig_lfclk": { layer: 1, position: 9 },
	"FCCTRIGMUX": { layer: 2, position: 9 },

	"fcc_mclk": { layer: 3, position: 9 },
	"fcc_sysosc": { layer: 3, position: 10 },
	"fcc_hfclk": { layer: 3, position: 11 },
	"fcc_extclk": { layer: 3, position: 12 },
	"pll0_out": { layer: 5, position: 3 },
	"fcc_syspll0": { layer: 3, position: 13 },
	"fcc_syspll1": { layer: 3, position: 14 },
	"fcc_syspll2x": { layer: 3, position: 15 },
	"fcc_fccin": { layer: 3, position: 16 },

	"FCCSELCLKMUX": { layer: 4, position: 9 },
	"FCC": { layer: 5, position: 9 },
	"exclk_sysosc": {layer: 6, position: 9 },
	"exclk_ulpclk": {layer: 6, position: 9 },
	"exclk_lfclk": {layer: 6, position: 9 },
	"exclk_mfclk": {layer: 6, position: 9 },
	"exclk_hfclk": {layer: 6, position: 9 },
	"exclk_syspll1": {layer: 6, position: 9 },
	"EXCLKMUX": { layer: 7, position: 9 },
	"EXCLKDIV": { layer: 8, position: 9 },
	"EXCLKGATE": { layer: 9, position: 9 },
	"net_exclk": { layer: 10, position: 9 },
	"CLKOUT": { layer: 11, position: 9 },


};


let M0G_CLK_OUT_FCC_Layout = {

	// input nets
	"net_hfclk": { layer: 0, position: 0 },
	"net_lfclk": { layer: 0, position: 1 },
	"net_mfpclkGate": { layer: 0, position: 2 },
	"net_syspll1": { layer: 0, position: 3 },
	"net_sysosc": { layer: 0, position: 4 },
	"net_ulpclk": { layer: 0, position: 5 },


	"fcc_hfclk": { layer: 4, position: 1 },
	"net_mclk": { layer: 4, position: 2 },
	"fcc_sysosc": { layer: 4, position: 3 },
	"net_syspll0": { layer: 4, position: 4 },
	"fcc_syspll1": { layer: 4, position: 5 },
	"net_syspll2x": { layer: 4, position: 6  },
	"fcctrig_lfclk": { layer: 4, position: 10 },

	// FCC
	"FCCEXT": { layer: 0, position: 9 },
	"FCC": { layer: 6, position: 2 },
	"FCCSELCLKMUX": { layer: 5, position: 1 },
	"FCCTRIGMUX": { layer: 5, position: 3 },
	"net_fccin": { layer: 4, position: 9 },

	// CLKOUT
	"EXCLKMUX": { layer: 1, position: 0 },
	"EXCLKDIV": { layer: 2, position: 0 },
	"EXCLKGATE": { layer: 3, position: 0 },
	"net_exclk": { layer: 4, position: 0 },
	"CLKOUT": { layer: 7, position: 0 },

};

let M0G_Simple_BrokenConnections = [
	{ instName: "SYSOSC", pinName: "SYSOSC_4M", name: "sysosc_4m1" },
	//{ instName: "HFCLK4MFPCLKDIV", pinName: "HFCLK4MFPCLKDIV_in", name: "hfmfp_4m" },
	{ instName: "HSCLKMUX", pinName: "HSCLKMUX_HFCLK", name: "hsclk_hf" },
	//	{ instName: "MFPCLKMUX", pinName: "MFPCLKMUX_SYSOSC", name: "mfpclk_sysosc" },
	// 	{ instName: "ADCMUX", pinName: "ADCMUX_ULPCLK", name: "adc_ulp"},
	// 	{ instName: "ADCMUX", pinName: "ADCMUX_SYSOSC", name: "adc_sysosc"},
];

let M0G_EXT_BrokenConnections = [
	{ instName: "FCCSELCLKMUX", pinName: "FCCSELCLKMUX_HFCLK", name: "fcc_hfclk" },
	{ instName: "FCCSELCLKMUX", pinName: "FCCSELCLKMUX_SYSOSC", name: "fcc_sysosc"},
	{ instName: "FCCSELCLKMUX", pinName: "FCCSELCLKMUX_SYSPLLCLK1", name: "fcc_syspll1"},
	{ instName: "FCCTRIGMUX", pinName: "FCCTRIGMUX_LFCLK", name: "fcctrig_lfclk" }
];

let M0G_Full_BrokenConnections = [
	{ instName: "EXCLKMUX", pinName: "EXCLKMUX_SYSOSC", name: "exclk_sysosc" },
	{ instName: "EXCLKMUX", pinName: "EXCLKMUX_ULPCLK", name: "exclk_ulpclk" },
	{ instName: "EXCLKMUX", pinName: "EXCLKMUX_LFCLK",  name: "exclk_lfclk" },
	{ instName: "EXCLKMUX", pinName: "EXCLKMUX_MFPCLK", 	name: "exclk_mfclk"},
	{ instName: "EXCLKMUX", pinName: "EXCLKMUX_HFCLK", 	name: "exclk_hfclk"},
	{ instName: "EXCLKMUX", pinName: "EXCLKMUX_PLLCLK1_OUT", name: "exclk_syspll1" },
	{ instName: "FCCSELCLKMUX", pinName: "FCCSELCLKMUX_MCLK" , name: "fcc_mclk" },
	{ instName: "FCCSELCLKMUX", pinName: "FCCSELCLKMUX_SYSOSC", name: "fcc_sysosc" },
	{ instName: "FCCSELCLKMUX", pinName: "FCCSELCLKMUX_HFCLK" , name: "fcc_hfclk" },
	{ instName: "FCCSELCLKMUX", pinName: "FCCSELCLKMUX_EXTCLK" , name: "fcc_extclk "},
	{ instName: "PLL_CLK0_DIV", pinName: "PLL_CLK0_DIV_OUT", name: "pll0_out" },
	{ instName: "FCCSELCLKMUX", pinName: "FCCSELCLKMUX_SYSPLLCLK0", name: "fcc_syspll0" },
	{ instName: "FCCSELCLKMUX", pinName: "FCCSELCLKMUX_SYSPLLCLK1", name: "fcc_syspll1"},
	{ instName: "FCCSELCLKMUX", pinName: "FCCSELCLKMUX_SYSPLLCLK2X", name: "fcc_syspll2x" },
	{ instName: "FCCSELCLKMUX", pinName: "FCCSELCLKMUX_FCCIN", name: "fcc_fccin" },
	{ instName: "FCCTRIGMUX", pinName: "FCCTRIGMUX_EXLFLFXT", name: "fcctrig_exlf" },
];

let full_layout = Object.assign(M0G_Full_AdditionalLayout, M0G_Simple_reasonableLayout);

const M0GGATESimple = [
	"net_mclk", "net_ulpclk", "net_lfclk", "net_cpuclk", "net_sysosc",
	"net_syspll2x", "net_syspll0", "net_syspll1",
	"net_mfclk", "net_mfpclk", "net_canclk", "net_adcclk", "net_vco"];

const M0GGATEEXT = [
	"net_mclk", "net_sysosc", "net_lfclk", "net_hfclk", "net_mfpclkGate",
	"net_syspll1", "net_ulpclk", "net_exclk", "net_syspll0", "net_syspll2x"
];

exports = {
    entriesSimple: M0G_Simple_Entries,
    layoutSimple: M0G_Simple_reasonableLayout,
	brokenConnectionsSimple: M0G_Simple_BrokenConnections,
	freqLabelSimple: M0GGATESimple,
	entriesFull: [],
	layoutFull: full_layout,
	brokenConnectionsFull: Object.assign(M0G_Full_BrokenConnections, M0G_Simple_BrokenConnections),
	entriesEXT: M0G_CLK_OUT_FCC_Entries,
	freqLabelEXT: M0GGATEEXT,
	layoutEXT: M0G_CLK_OUT_FCC_Layout,
	brokenConnectionsEXT: M0G_EXT_BrokenConnections
}
