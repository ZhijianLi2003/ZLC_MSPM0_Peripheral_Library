let Common = system.getScript("/ti/driverlib/Common.js");
let EVENT = system.getScript("/ti/driverlib/EVENT.syscfg.js");

// The index comes from the pin. LCD[index]
function getMemRow(inst){
    let index = 0;
    try{
        index = inst.peripheral.LCDSeg.$solution.peripheralPinName.slice(7);
    }catch(e){
        return -1
    }
    // For a Segment to exist, LCD has to be added in the first place.
    // Can access Mux Rate through parent LCD static module
    let muxRate = system.modules['/ti/driverlib/LCD'].$static.muxRate;
    // DL_LCD_MEMORY row depends on mux rate
    // Mux Rate 5-8
    if(muxRate>4){
        return parseInt(index);
    }
    // Mux Rate 1-4
    else{
        return Math.floor(index/2);
    }
}
function getMemBits(inst){
    let index = 0;
    try{
        index = inst.peripheral.LCDSeg.$solution.peripheralPinName.slice(7);
    }catch(e){
        return [0];
    }
    // For a Segment to exist, LCD has to be added in the first place.
    // Can access Mux Rate through parent LCD static module
    let muxRate = system.modules['/ti/driverlib/LCD'].$static.muxRate;
    // DL_LCD_MEMORY_BIT depends on mux rate
    // Mux Rate 5-8
    if(muxRate>4){
        return [0,1,2,3,4,5,6,7];
    }
    // Mux Rate 1-4
    else{
        // Even Pins
        if(index % 2 == 0){
            return [0,1,2,3];
        }
        // Odd Pins
        else{
            return [4,5,6,7];
        }
    }
}

let coreConfig = [
    {
        name: "$name",
        defaultPrefix: "LCD_SEG_",
        hidden: false
    },
    {
        name:"segNumber",
        displayName:"Segment Line",
        default: "Segment Line 0",
        getValue: (inst,ui) => {
            let index = 0;
            // index = system.modules['/ti/driverlib/lcd/LCDSeg'].$instances.findIndex(obj => {
            //     return obj.$name.includes(inst.$name)
            // });
            try{
                index = inst.peripheral.LCDSeg.$solution.peripheralPinName.slice(7);
                return "Segment Line "+index.toString();
            }catch(e){
                return "Segment Line not defined."
            }

        }
    },
    {
        name:"lcdPinName",
        displayName:"LCD Pin",
        default: "None",
        getValue: (inst,ui) => {
            let pinName = "N/A";
            try{
                pinName = inst.peripheral.LCDSeg.$solution.peripheralPinName.slice(4);
            }catch (e) {
                // do nothing
            }
            return pinName;
        }
    },
    // DL_LCD_setMemory
    {
        name: "memSet",
        displayName: "Set Memory",
        default: false,
    },
    {
        name: "memIndex",
        displayName: "Memory Row (memIndex)",
        default: 0,
        hidden: true,
        getValue: getMemRow,
    },
    {
        name: "memMask",
        displayName: "Memory Bits (mask)",
        default: [0],
        hidden: true,
        options: [
            {name: 0, displayName: "0"},
            {name: 1, displayName: "1"},
            {name: 2, displayName: "2"},
            {name: 3, displayName: "3"},
            {name: 4, displayName: "4"},
            {name: 5, displayName: "5"},
            {name: 6, displayName: "6"},
            {name: 7, displayName: "7"},
        ],
        getValue: getMemBits,
    },
];

let blinkConfig = [
    // DL_LCD_setBlinkingMemory / DL_LCD_clearBlinkingMemory
    {
        name: "blinkSet",
        displayName: "Set Blinking Memory",
        default: false,
    },
];


let config = coreConfig.concat(blinkConfig).concat([

]);

const allLCDInterface = [];
for(let ix = 0; ix <= 58; ix++){
    allLCDInterface.push("LCD"+ix);
}


function getPinmuxResources(){
    let resources = [];
    resources.push(
        {
            name:"LCDSeg",
            displayName:"LCD Seg",
            interfaceNames:allLCDInterface,
        },
    )
    return resources;
}

function pinmuxRequirements(inst)
{
    let allResources = getPinmuxResources();

    let lcd = {
        name: "peripheral",
        displayName: "LCD Peripheral",
        interfaceName: "LCD",
        resources: [
            // start off empty to get filled-in by the table
        ],
        signalTypes: {
            LCD0: ["LCD0"],
            LCD1: ["LCD1"],
            LCD2: ["LCD2"],
            LCD3: ["LCD3"],
            LCD4: ["LCD4"],
            LCD5: ["LCD5"],
            LCD6: ["LCD6"],
            LCD7: ["LCD7"],
            LCD8: ["LCD8"],
            LCD9: ["LCD9"],
            LCD10: ["LCD10"],
            LCD11: ["LCD11"],
            LCD12: ["LCD12"],
            LCD13: ["LCD13"],
            LCD14: ["LCD14"],
            LCD15: ["LCD15"],
            LCD16: ["LCD16"],
            LCD17: ["LCD17"],
            LCD18: ["LCD18"],
            LCD19: ["LCD19"],
            LCD20: ["LCD20"],
            LCD21: ["LCD21"],
            LCD22: ["LCD22"],
            LCD23: ["LCD23"],
            LCD24: ["LCD24"],
            LCD25: ["LCD25"],
            LCD26: ["LCD26"],
            LCD27: ["LCD27"],
            LCD28: ["LCD28"],
            LCD29: ["LCD29"],
            LCD30: ["LCD30"],
            LCD31: ["LCD31"],
            LCD32: ["LCD32"],
            LCD33: ["LCD33"],
            LCD34: ["LCD34"],
            LCD35: ["LCD35"],
            LCD36: ["LCD36"],
            LCD37: ["LCD37"],
            LCD38: ["LCD38"],
            LCD39: ["LCD39"],
            LCD40: ["LCD40"],
            LCD41: ["LCD41"],
            LCD42: ["LCD42"],
            LCD43: ["LCD43"],
            LCD44: ["LCD44"],
            LCD45: ["LCD45"],
            LCD46: ["LCD46"],
            LCD47: ["LCD47"],
            LCD48: ["LCD48"],
            LCD49: ["LCD49"],
            LCD50: ["LCD50"],
            LCD51: ["LCD51"],
            LCD52: ["LCD52"],
            LCD53: ["LCD53"],
            LCD54: ["LCD54"],
            LCD55: ["LCD55"],
            LCD56: ["LCD56"],
            LCD57: ["LCD57"],
            LCD58: ["LCD58"],
        },
        canShareWith  : "LCD",
    };
    lcd.resources.push(allResources[0]);

    return [lcd];
}

function validate(inst, validation)
{
    validation.logInfo(
        "Segment line number is automatically determined based pin selection",
        inst, "segNumber"
    );
    validation.logInfo(
        "LCD Pin selection is controlled through the PinMux configuration section.",
        inst, "lcdPinName"
    );
}

function validatePinmux(inst, validation)
{

}

exports = {
    config: config,
    pinmuxRequirements: pinmuxRequirements,
    validate: validate,
    validatePinmux: validatePinmux,

    /* Added for cleaner error message on duplicate pin name */
    displayName: "LCD Pin",
};
