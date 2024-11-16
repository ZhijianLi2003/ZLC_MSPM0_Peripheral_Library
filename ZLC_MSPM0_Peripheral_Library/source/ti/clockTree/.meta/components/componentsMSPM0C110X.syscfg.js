let M0C_Simple_Entries = [
	"LFOSC",
	"SYSOSC",
	"LFCLKEXT",
	"HFCLKEXT",
	"SYSCTLMUX",
	"EXLFMUX",
	"EXHFMUX",
	//"ADCCLKMUX",
	"MDIV",
	//"ADCCLKGATE",
	"CPUCLKGATE",
	"LFCLKGATE",
	"MCLKGATE",
	"MFCLKGATE",
	"ULPCLKGATE",

	//"net_adcclk",
	"net_cpuclk",
	"net_hfclkext",
	"net_lfclk",
	"net_mclk",
	"net_mfclk",
	"net_sysosc",
	"net_sysosc4m",
	"net_ulpclk",

];

let M0C_Full_Entries = M0C_Simple_Entries.concat([
	"EXCLKMUX",
	"FCCSELCLKMUX",
	"EXCLKDIV",
	"EXCLKGATE",

	"CLKOUT",
	"FCC",
	"FCCEXT",
	"FCCTRIGMUX",

	"net_exclk",
]);

let M0C_Simple_Layout = {
	"SYSOSC": 			{ layer: 0, position: 0 },
	"HFCLKEXT": 		{ layer: 0, position: 1 },
	"LFCLKEXT": 		{ layer: 0, position: 3 },
	"LFOSC": 			{ layer: 0, position: 4 },

	"net_sysosc4m": 	{ layer: 1, position: 0 },
	"net_sysosc": 		{ layer: 1, position: 1 },
	"net_hfclkext": 	{ layer: 1, position: 2 },

	"EXLFMUX": 			{ layer: 1, position: 5 },

	"MDIV": 			{ layer: 2, position: 3 },

	"EXHFMUX": 			{ layer: 3, position: 3},

	"SYSCTLMUX": 		{ layer: 5, position: 3 },
	//"ADCCLKMUX": 		{ layer: 5, position: X },

	"MFCLKGATE": 		{ layer: 6, position: 0 },
	"MCLKGATE":  		{ layer: 6, position: 1 },
	"CPUCLKGATE": 		{ layer: 6, position: 2 },
	"ULPCLKGATE": 		{ layer: 6, position: 3 },
	"LFCLKGATE":  		{ layer: 6, position: 5 },
	//"ADCCLKGATE": 	{ layer: 6, position: X },

	"net_mfclk": 		{ layer: 10, position: 0 },
	"net_mclk":  		{ layer: 10, position: 1 },
	"net_cpuclk": 		{ layer: 10, position: 2 },
	"net_ulpclk": 		{ layer: 10, position: 4 },
	"net_lfclk": 		{ layer: 10, position: 5 },
	//"net_adcclk": 	{ layer: 10, position: X },

}

let M0C_EXT_FCC_Entries = [
	"EXCLKMUX",
	"FCCSELCLKMUX",
	"EXCLKDIV",
	"EXCLKGATE",
	"CLKOUT",

	"FCC",
	"FCCEXT",
	"FCCTRIGMUX",

	// nets

	"net_exclk",
	"net_sysosc",
	"net_mfclk",
	"net_hfclkext",
	"net_lfclk",
	"net_mclk",
	"net_ulpclk",
];

let M0C_EXT_Layout = {

	"net_hfclkext": 	{ layer: 0, position: 0 },
	"net_lfclk": 		{ layer: 0, position: 1 },
	"net_mfclk": 		{ layer: 0, position: 2 },
	"net_sysosc": 		{ layer: 0, position: 3 },
	"net_ulpclk": 		{ layer: 0, position: 4 },
	"FCCEXT": 	  		{ layer: 0, position: 6 },

	"EXCLKMUX": 		{ layer: 1, position: 0 },

	"EXCLKDIV": 		{ layer: 2, position: 0 },
	//"fcc_clkout": 	{ layer: 2, position: 6 },

	"EXCLKGATE": 		{ layer: 3, position: 0 },

	"net_exclk":  		{ layer: 4, position: 0 },
	"net_mclk": 		{ layer: 4, position: 1 },
	"fcc_sysosc": 		{ layer: 4, position: 2 },
	"fcctrig_lfclk": 	{ layer: 4, position: 5 },

	"FCCSELCLKMUX": 	{ layer: 5, position: 5 },
	"FCCTRIGMUX": 		{ layer: 5, position: 7 },

	"CLKOUT": 			{ layer: 6, position: 0 },
	"FCC": 		  		{ layer: 6, position: 2 },
};

let M0C_BrokenConnections = [
	// { instName: "ADCCLKMUX", pinName: "ADCCLKMUX_HFCLKEXT", name: "adc_hfclk" },
	// { instName: "ADCCLKMUX", pinName: "ADCCLKMUX_SYSOSC", name: "adc_sysosc" },
	// { instName: "ADCCLKMUX", pinName: "ADCCLKMUX_ULPCLK", name: "adc_ulpclk"}
];

let M0C_EXT_BrokenConnections = [
	{ instName: "FCCSELCLKMUX", pinName: "FCCSELCLKMUX_SYSOSC", name: "fcc_sysosc" },
	//{ instName: "FCCSELCLKMUX", pinName: "FCCSELCLKMUX_EXTCLK", name: "fcc_clkout" },
	{ instName: "FCCTRIGMUX", pinName: "FCCTRIGMUX_LFCLK", name: "fcctrig_lfclk" },
];


const M0CGATESimple = [
	"net_mclk", "net_ulpclk", "net_lfclk",
	"net_mfclk", "net_cpuclk",
	"net_adcclk"
];

const M0CGATEEXT = [
	"net_mclk", "net_lfclk", "net_ulpclk", "net_exclk",
	"net_mfclk", "net_sysosc", "net_hfclkext", "net_sysosc4m"
];

exports = {
    entriesSimple: M0C_Simple_Entries,
    layoutSimple: M0C_Simple_Layout,
	brokenConnectionsSimple: M0C_BrokenConnections,
	freqLabelSimple: M0CGATESimple,
	entriesFull: [],
	layoutFull: {},
	entriesEXT: M0C_EXT_FCC_Entries,
	freqLabelEXT: M0CGATEEXT,
	layoutEXT: M0C_EXT_Layout,
	brokenConnectionsEXT: M0C_EXT_BrokenConnections
}
