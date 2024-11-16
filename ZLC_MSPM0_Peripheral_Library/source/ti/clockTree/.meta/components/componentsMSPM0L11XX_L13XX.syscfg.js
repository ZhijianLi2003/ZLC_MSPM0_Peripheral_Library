let M0L_Simple_Entries = [
	"LFOSC",
	"SYSOSC",
	"SYSCTLMUX",
	"MDIV",
	"ADCCLKGATE",
	"CPUCLKGATE",
	"LFCLKGATE",
	"MCLKGATE",
	"MFCLKGATE",
	"ULPCLKGATE",

	"net_adcclk",
	"net_cpuclk",
	"net_lfclk",
	"net_mclk",
	"net_mfclk",
	"net_sysosc",
	"net_sysosc4m",
	"net_ulpclk",

];

let M0L_Full_Entries = M0L_Simple_Entries.concat([
	"EXCLKMUX",
	"FCCSELCLKMUX",
	"EXCLKDIV",
	"EXCLKGATE",
	"CLKOUT",
	"MFPCLKGATE",
	"FCC",
	"FCCEXT",
	"FCCTRIGMUX",

	"net_exclk",
	"net_mfpclk",
]);

let M0L_EXT_FCC_Entries = [
	"EXCLKMUX",
	"FCCSELCLKMUX",
	"EXCLKDIV",
	"EXCLKGATE",
	"CLKOUT",

	"FCC",
	"FCCEXT",
	"FCCTRIGMUX",
	"MFPCLKGATE", // only applicable to FCC

	// nets
	"net_exclk",
	"net_sysosc",
	"net_sysosc4m",
	"net_lfclk",
	"net_mfpclk",
	"net_mclk",
	"net_ulpclk",
];

let M0L_Simple_Layout = {
	"LFOSC": { layer: 2, position: 1 },
	"SYSOSC": { layer: 0, position: 0 },
	"SYSCTLMUX": { layer: 4, position: 3 },
	"MDIV": { layer: 3, position: 3 },

	"MFCLKGATE": { layer: 5, position: 0 },
	"LFCLKGATE": { layer: 5, position: 1 },
	"MCLKGATE": { layer: 5, position: 2 },
	"ULPCLKGATE": { layer: 5, position: 3 },
	"CPUCLKGATE": { layer: 5, position: 4 },
	"ADCCLKGATE": { layer: 5, position: 5 },

	"net_mfclk": { layer: 6, position: 0 },
	"net_lfclk": { layer: 6, position: 1 },
	"net_mclk":  { layer: 6, position: 2 },
	"net_ulpclk": { layer: 6, position: 3 },
	"net_cpuclk": { layer: 6, position: 4 },
	"net_adcclk": { layer: 6, position: 5 },

	"net_sysosc4m": { layer: 1, position: 0 },
	"net_sysosc": { layer: 1, position: 3 },
}

let M0L_EXT_Layout = {
	"EXCLKMUX": { layer: 3, position: 0 },
	"EXCLKDIV": { layer: 4, position: 0 },
	"EXCLKGATE": { layer: 5, position: 0 },
	"net_exclk":  { layer: 6, position: 0 },
	"CLKOUT": { layer: 8, position: 0 },

	"FCCSELCLKMUX": { layer: 3, position: 5 },
	"FCC": 		  { layer: 4, position: 2 },
	"FCCEXT": 	  { layer: 0, position: 6 },
	"FCCTRIGMUX": { layer: 3, position: 7 },

	"net_lfclk": { layer: 2, position: 0 },
	"net_sysosc4m": { layer: 0, position: 1 },
	"MFPCLKGATE": { layer: 1, position: 1 },
	"net_mfpclk": { layer: 2, position: 1 },
	"net_sysosc": { layer: 2, position: 2 },
	"net_ulpclk": { layer: 2, position: 3 },

	// nets
	"net_mclk": { layer: 2, position: 7 },
	"fcc_sysosc": { layer: 2, position: 8 },
	"fcc_clkout": { layer: 2, position: 6 },
	"fcctrig_lfclk": {layer: 2, position: 9},
};

let M0L_BrokenConnections = [];

let M0L_EXT_BrokenConnections = [
	{ instName: "FCCSELCLKMUX", pinName: "FCCSELCLKMUX_SYSOSC", name: "fcc_sysosc" },
	{ instName: "FCCSELCLKMUX", pinName: "FCCSELCLKMUX_EXTCLK", name: "fcc_clkout" },
	{ instName: "FCCTRIGMUX", pinName: "FCCTRIGMUX_LFCLK", name: "fcctrig_lfclk" },
];


const M0LGATESimple = [
	"net_mclk", "net_ulpclk", "net_lfclk",
	"net_mfclk", "net_mfpclk", "net_cpuclk",
	"net_adcclk"
];

const M0LGATEEXT = [
	"net_mclk", "net_lfclk", "net_ulpclk", "net_exclk",
	"net_mfclk", "net_sysosc", "net_mfpclk", "net_sysosc4m"
];

exports = {
    entriesSimple: M0L_Simple_Entries,
    layoutSimple: M0L_Simple_Layout,
	brokenConnectionsSimple: M0L_BrokenConnections,
	freqLabelSimple: M0LGATESimple,
	entriesFull: [],
	layoutFull: {},
	entriesEXT: M0L_EXT_FCC_Entries,
	freqLabelEXT: M0LGATEEXT,
	layoutEXT: M0L_EXT_Layout,
	brokenConnectionsEXT: M0L_EXT_BrokenConnections
}
