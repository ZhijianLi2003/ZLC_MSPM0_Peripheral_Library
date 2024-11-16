let Common = system.getScript("/ti/driverlib/Common.js");
let EVENT = system.getScript("/ti/driverlib/EVENT.syscfg.js");

let config = [
    {
        name: "direction",
        displayName: "Direction",
        default: "OUTPUT",
        hidden: false,
        options: [
            { name: "OUTPUT", displayName: "Output" },
            { name: "INPUT", displayName: "Input" }
        ],
        onChange: (inst, ui) => {
            let hideAll = !(inst.enableConfig);
            let hideInput = !(inst.direction === "INPUT");
            // input specifics
            ui.hysteresisControl.hidden = hideInput || hideAll || inst.onlyInternalResistor;
            ui.wakeupLogic.hidden = !Common.hasWakeupLogic() || hideInput || hideAll || inst.onlyInternalResistor;
            // output specifics
            ui.driveStrength.hidden = !hideInput || hideAll || inst.onlyInternalResistor;
            ui.hiZ.hidden = !hideInput || hideAll || inst.onlyInternalResistor;

            /* Special Case: disabling output inversion */
            ui.invert.hidden = (hideInput && inst.hideOutputInversion) || hideAll || inst.onlyInternalResistor;
        }
    },
    {
        name: "pinIOStructure",
        displayName: "IO Structure",
        default: "SD",
        hidden: false,
        options: [
            {name: "SD", displayName: "Standard"},
            {name: "SDL", displayName: "Standard"},
            {name: "SDW", displayName: "Standard with Wake"},
            {name: "HS", displayName: "High-Speed"},
            {name: "HD", displayName: "High-Drive"},
            {name: "OD", displayName: "5V Tolerant Open Drain"},
        ],
        getValue: (inst) => {
            try{
                if(inst.$ownedBy.$module.$name == "/ti/driverlib/TIMERFault"){
                    return system.deviceData.gpio.pinInfo[inst.$ownedBy[inst.passedResourceName].$solution.packagePinName].devicePin.attributes.io_type;
                }
                else{
                    return system.deviceData.gpio.pinInfo[inst.$ownedBy.peripheral[inst.passedResourceName].$solution.packagePinName].devicePin.attributes.io_type;
                }
            }
            catch (e) {
                return "SD";
            }

        }
    },
    {
        name: "enableConfig",
        displayName: "Enable pin configuration",
        default: false,
        onChange: (inst, ui) => {
            let hideAll = !(inst.enableConfig);
            let hideInput = !(inst.direction === "INPUT");
            // input specifics
            ui.hysteresisControl.hidden = hideInput || hideAll || inst.onlyInternalResistor;
            ui.wakeupLogic.hidden = !Common.hasWakeupLogic() || hideInput || hideAll || inst.onlyInternalResistor;
            // output specifics
            ui.driveStrength.hidden = !hideInput || hideAll || inst.onlyInternalResistor;
            ui.hiZ.hidden = !hideInput || hideAll || inst.onlyInternalResistor;
            ui.internalResistor.hidden = hideAll;
            ui.invert.hidden = (hideInput && inst.hideOutputInversion) || hideAll || inst.onlyInternalResistor;
        }
    },
    {
        name: "INPUT_FEATURE_GROUP",
        displayName: "Digital IOMUX Features",
        longDescription: `<TODO: Add table 7-1 from the TRM>`,
        config: [
            {
                name: "internalResistor", // Both INPUT/OUTPUT
                displayName: "Internal Resistor",
                description: "Optional Internal Resistor to add to GPIO",
                hidden: true,
                default: "NONE",
                options: [
                    {name: "NONE", displayName: "No Resistor"},
                    {name: "PULL_UP", displayName: "Pull-Up Resistor"},
                    {name: "PULL_DOWN", displayName: "Pull-Down Resistor"}
                ],
            },
            {
                name: "invert",
                displayName: "Invert",
                description: "Option to invert the Input/Output",
                hidden: true,
                default: "DISABLE",
                options: [
                    {name: "ENABLE", displayName: "Enabled"},
                    {name: "DISABLE", displayName: "Disabled"}
                ]
            },
            /* Passed Parameter: if true, disable output inversion from being configured */
            {
                name: "hideOutputInversion",
                hidden: true,
                default: false,
                onChange: (inst,ui) => {
                    ui.invert.hidden = !(inst.enableConfig)|| (inst.hideOutputInversion && (inst.direction == "OUTPUT"));
                }
            },
            /* Passed Parameter: if true, only enable Internal Resistor configuration */
            {
                name: "onlyInternalResistor",
                hidden: true,
                default: false,
                onChange: (inst,ui) => {
                    let hideAll = !(inst.enableConfig);
                    let hideInput = !(inst.direction === "INPUT");
                    // input specifics
                    ui.hysteresisControl.hidden = hideInput || hideAll || inst.onlyInternalResistor;
                    ui.wakeupLogic.hidden = !Common.hasWakeupLogic() || hideInput || hideAll || inst.onlyInternalResistor;
                    // output specifics
                    ui.driveStrength.hidden = !hideInput || hideAll || inst.onlyInternalResistor;
                    ui.hiZ.hidden = !hideInput || hideAll || inst.onlyInternalResistor;
                    ui.internalResistor.hidden = hideAll;
                    ui.invert.hidden = (hideInput && inst.hideOutputInversion) || hideAll || inst.onlyInternalResistor;
                }
            },
            {
                name: "driveStrength", // OUTPUT only
                displayName: "Drive Strength Control",
                description: "Set drive strength on high-drive and high-speed capable pins",
                hidden: true,
                default: "LOW",
                options: [
                    {name: "LOW", displayName: "Low"},
                    {name: "HIGH", displayName: "High"}
                ],
                onChange: (inst) => {
                    // modify ioStructure if high drive selected

                },

            },
            {
                name: "hiZ", // OUTPUT only
                displayName: "High-Impedance",
                longDescription: `
In general, when analog functionality is used on a pin which also has digital functions, the IOMUX configuration
for that pin should be left in its default, High-Z state so as to not interfere with the correct operation of the analog
function. However, it is possible to have the IOMUX active on a pin when an analog peripheral is also interacting
with the pin, provided that the application software ensures that there is not a conflict between the functions. For
example, it is possible to have the pullup or pulldown resistor on an IO enabled at the same time that the ADC is
running a conversion on the same IO. However, an invalid configuration would be enabling the output driver on
an IO at the same time that an analog peripheral is driving the IO (for example, a DAC or OPA output) as this
creates an IO conflict
                `,
                hidden: true,
                default: "DISABLE",
                options: [
                    {name: "ENABLE", displayName: "Enabled"},
                    {name: "DISABLE", displayName: "Disabled"}
                ]
            },
            {
                name: "hysteresisControl", // INPUT only
                displayName: "Hysteresis Control",
                description: "Hysteresis Control on IO pins",
                longDescription: `Only available on 5V tolerant open drain IO structure`,
                hidden: true,
                default: "DISABLE",
                options: [
                    {name: "DISABLE", displayName: "Disabled"},
                    {name: "ENABLE", displayName: "Enabled"}
                ],

            },
            {
                name: "wakeupLogic", // INPUT only
                displayName: "Wakeup Logic",
                longDescription: `
Wakeup Logic allowing a wakeup of the device when either:
* Pin changes to 0
* Pin changes to 1

Only available on Standard-Drive with wake, 5V tolerant Open Drain and High-Drive IO structures`,
                hidden: true,
                default: "DISABLE",
                options: [
                    {name: "DISABLE", displayName: "Disabled"},
                    {name: "ON_0", displayName: "Wake when 0"},
                    {name: "ON_1", displayName: "Wake when 1"}
                ]
            }

        ]
    },
    /* Parameters to be Passed */
    /* Pin Name to utilize */
    {
        name: "passedPinName",
        default: "NONE",
        hidden: true,
    },
    {
        name: "passedResourceName",
        default: "NONE",
        hidden: true,
    },
    {
        name: "passedPeripheralType",
        default: "Digital",
        options: [{name: "Digital"}, {name: "Analog"}],
        hidden: true,
    },
];

/*  ======== pinmuxRequirements ========
 *  Returns peripheral pin requirements of the specified instance
 *
 *  param inst    - a fully configured module instance
 *
 *  returns req[] - an array of pin requirements needed by inst
 */
function pinmuxRequirements(inst)
{

}

function validate(inst, validation)
{

}

function validatePinmux(inst,validation){
    /* IOMUX validation Based on TRM table 7-1 */
    // make sure the IOMux configuration is possible,
    try{
        let pinIOStructure = "SD";
        if(inst.$ownedBy.$module.$name == "/ti/driverlib/TIMERFault"){
            pinIOStructure = system.deviceData.gpio.pinInfo[inst.$ownedBy[inst.passedResourceName].$solution.packagePinName].devicePin.attributes.io_type;
        }
        else{
            pinIOStructure = system.deviceData.gpio.pinInfo[inst.$ownedBy.peripheral[inst.passedResourceName].$solution.packagePinName].devicePin.attributes.io_type;
        }
        if(inst.direction === "OUTPUT") {
            if(inst.driveStrength === "HIGH" && (pinIOStructure.match(/HD|HS/) === null)){
                validation.logError("Drive Strength not possible on selected IO Structure", inst, "driveStrength");
            }
        } else {
            if(inst.hysteresisControl === "ENABLE" && (pinIOStructure.match(/OD/) === null)){
                validation.logError("Hysteresis only valid on Open Drain", inst, "hysteresisControl");
            }
            if(Common.hasWakeupLogic()){
                if(inst.wakeupLogic !== "DISABLE" && pinIOStructure.match(/Any|OD|SDW|HD/) == null) {
                    validation.logError("Wakeup Logic configuration only valid on Open Drain and Standard with Wake ", inst, "wakeupLogic");
                }
            }
            if(inst.internalResistor === "PULL_UP" && pinIOStructure.match(/OD/) !== null) {
                validation.logError("Pull-Up Resistor not valid on an Open Drain Configuration", inst, "internalResistor");
            }
        }
    }catch (e) {
        // do nothing
    }


}


let base = {
    name: "GPIOPinGeneric",
    displayName: "GPIO Pin",
    // longDescription: ``,
    config: config,
    // pinmuxRequirements: pinmuxRequirements,
    // validate: validate,
    validatePinmux: validatePinmux,
};

exports = base;
