let Common = system.getScript("/ti/driverlib/Common.js");
let EVENT = system.getScript("/ti/driverlib/EVENT.syscfg.js");

let config = [
    {
        name: "$name",
        defaultPrefix: "LCD_COM_",
        hidden: false
    },
    {
        name:"comNumber",
        displayName: "Common Line",
        default: "COM 0",
        getValue: (inst,ui) => {
            let index = 0;
            try{
                index = system.modules['/ti/driverlib/lcd/LCDCom'].$instances.findIndex(obj => {
                    return obj.$name.includes(inst.$name)
                });
            }catch (e) {
                // do nothing
            }
            return "COM "+index.toString();
        }
    },
    {
        name:"lcdPinName",
        displayName:"LCD Pin",
        default: "None",
        getValue: (inst,ui) => {
            let pinName = "N/A";
            try{
                pinName = inst.peripheral.LCDCom.$solution.peripheralPinName.slice(4);
            }catch (e) {
                // do nothing
            }
            return pinName;
        }
    },

];

const allLCDInterface = [];
for(let ix = 0; ix <= 58; ix++){
    allLCDInterface.push("LCD"+ix);
}


function getPinmuxResources(){
    let resources = [];
    resources.push(
        {
            name:"LCDCom",
            displayName:"LCD Com",
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
        "Common line number is atomatically determined based on the instance order",
        inst, "comNumber"
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
