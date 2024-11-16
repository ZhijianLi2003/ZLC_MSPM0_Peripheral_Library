let Common = system.getScript("/ti/driverlib/Common.js");
let EVENT = system.getScript("/ti/driverlib/EVENT.syscfg.js");

/* out of the IO structure, determines which are invalid */
function determineInvalidOptions(inst){
    let toDisable = {
        SD: false,
        SDL: false,
        SDW: false,
        HS: false,
        HD: false,
        OD: false
    }

    if(inst.direction === "INPUT"){
        if(inst.wakeupLogic != "DISABLE"){
            // disable all but Open Drain, Standard with Wake and High-Drive
            toDisable.SD = true; // disable Standard
            toDisable.SDL = true; // disable Low-leakage Standard
            toDisable.HS = true; // disable High-Speed
        }
        if(inst.hysteresisControl == "ENABLE"){
            // disable all but Open Drain
            toDisable.SD = true; // disable Standard
            toDisable.SDL = true; // disable Low-leakage Standard
            // SDW not available for M0C
            if(!Common.isDeviceM0C()){
                toDisable.SDW = true; // disable Standard with Wake
            }
            toDisable.HS = true; // disable High-Speed
            // HD only available on M0Gxx
            if(Common.isDeviceM0G() || Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()){
                toDisable.HD = true; // disable High-Drive
            }
        }
        if(inst.internalResistor === "PULL_UP") {
            toDisable.OD = true; // disable Open Drain
        }
    } else {
        if(inst.driveStrength === "HIGH"){
            toDisable.SD = true; // disable Standard
            toDisable.SDL = true; // disable Low-leakage Standard
            // SDW not available for M0C
            if(!Common.isDeviceM0C()){
                toDisable.SDW = true; // disable Standard with Wake
            }
            toDisable.OD = true; // disable Open Drain
        }
    }
    if(inst.ioStructure !== "Any"){
        // specified. All others are invalid
        _.each(toDisable, (s) => { if(s !== inst.ioStructure){ s = true; } });
        return toDisable;
    }
    return toDisable;
}

const LPInfo = [
    {
        name: "LED1En",
        displayName: "Launchpad LED1",
        description: "Shortcut to enable LED1 on PA.0 of the LaunchPad",
        longDescription: "Shortcut to enable LED1 on PA.0 of the LaunchPad",
        direction: "OUTPUT",
        assignedPort: "PORTA",
        assignedPortSegment: "Lower",
        assignedPin: "0"
    },
    {
        name: "LED2RedEn",
        displayName: "Launchpad LED2 Red",
        description: "Shortcut to enable Red on LED2 on PB.26 of the LaunchPad",
        longDescription: "Shortcut to enable Red on LED2 on PB.26 of the LaunchPad",
        direction: "OUTPUT",
        assignedPort: "PORTB",
        assignedPortSegment: "Upper",
        assignedPin: "26"
    },
    {
        name: "LED2GreenEn",
        displayName: "Launchpad LED2 Green",
        description: "Shortcut to enable Green on LED2 on PB.27 of the LaunchPad",
        longDescription: "Shortcut to enable Green on LED2 on PB.27 of the LaunchPad",
        direction: "OUTPUT",
        assignedPort: "PORTB",
        assignedPortSegment: "Upper",
        assignedPin: "27"
    },
    {
        name: "LED2BlueEn",
        displayName: "Launchpad LED2 Blue",
        description: "Shortcut to enable Blue on LED2 on PB.22 of the LaunchPad",
        longDescription: "Shortcut to enable Blue on LED2 on PB.22 of the LaunchPad",
        direction: "OUTPUT",
        assignedPort: "PORTB",
        assignedPortSegment: "Upper",
        assignedPin: "22"
    },
    {
        name: "Button2En",
        displayName: "Launchpad Button 2",
        description: "Shortcut to enable Button 2 on PA.18 of the LaunchPad",
        longDescription: "Shortcut to enable Button 2 on PA.18 of the LaunchPad",
        direction: "INPUT",
        assignedPort: "PORTA",
        assignedPortSegment: "Upper",
        assignedPin: "18",
        internalResistor: "PULL_UP",
    },
    {
        name: "Button3En",
        displayName: "Launchpad Button 3",
        description: "Shortcut to enable Button 3 on PB.21 of the LaunchPad",
        longDescription: "Shortcut to enable Button 3 on PB.21 of the LaunchPad",
        direction: "INPUT",
        assignedPort: "PORTB",
        assignedPortSegment: "Upper",
        assignedPin: "21",
        internalResistor: "PULL_UP"
    }
]

function getLPOptions(inst){
    let opts = [
        {
            name: "off",
            displayName: "No Shortcut Used"
        },
    ];
    for(let info of LPInfo){
        opts.push(_.pick(info,["name","displayName","description","longDescription"]));
    }
    return opts;
}

function getDisabledLPOptions(inst){
    let opts = getLPOptions;
    return [];
}

function applyLPShortcut(inst, ui){
    if(inst.launchPadShortcut !== "off"){
        let proposedShortcutInd = _.findIndex(LPInfo, (lp) => lp.name === inst.launchPadShortcut);
        let proposedShortcut = LPInfo[proposedShortcutInd];
        Object.assign(inst, _.pick(proposedShortcut, ["assignedPort", "assignedPortSegment", "assignedPin",
            "direction", "internalResistor"]));
        ui.direction.readOnly = true;
        ui.assignedPort.readOnly = true;
        ui.assignedPortSegment.readOnly = true;
        ui.assignedPin.readOnly = true;
        inst.$module.$configByName.direction.onChange(inst,ui);
    } else {
        let defaults = {
            direction: "OUTPUT",
            assignedPort: "Any",
            assignedPortSegment: "Any",
            assignedPin: "Any"
        }
        Object.assign(inst, defaults);
        ui.direction.readOnly = false;
        ui.assignedPort.readOnly = false;
        ui.assignedPortSegment.readOnly = false;
        ui.assignedPin.readOnly = false;
        inst.$module.$configByName.direction.onChange(inst,ui);
    }
}

let gpioLaunchPadConfig = [
    /****** Start of BASIC CONFIGURATION *******/
    {
        name: "launchPadShortcut",
        displayName: "LaunchPad-Specific Pin",
        description: "A quick-configuration method allowing for ease of LED/Button Use",
        longDescription: `
Users of a LaunchPad can quickly go to this section of the configuration, and can edit the
pin configuration such that only the peripheral pieces can be added.
        `,
        default: "off",
        options: getLPOptions,
        getDisabledOptions: getDisabledLPOptions,
        onChange: applyLPShortcut
    },

];

let config = [
    {
        name: "$name",
        defaultPrefix: "PIN_",
        hidden: false
    },
    {
        name: "direction",
        displayName: "Direction",
        default: "OUTPUT",
        options: [
            { name: "OUTPUT", displayName: "Output" },
            { name: "INPUT", displayName: "Input" }
        ],
        onChange: (inst, ui) => {
            let hideInput = !(inst.direction === "INPUT");
            // input specifics
            ui.fastWakeEn.hidden = hideInput;
            ui.inputFilter.hidden = hideInput;
            ui.hysteresisControl.hidden = hideInput;
            ui.wakeupLogic.hidden = (Common.hasWakeupLogic())?hideInput:true;
            ui.interruptEn.hidden = hideInput;
            ui.interruptPriority.hidden = hideInput || !inst.interruptEn;
            ui.polarity.hidden = hideInput;
            ui.pubChanID.hidden = hideInput;
            // output specifics
            ui.driveStrength.hidden = !hideInput;
            ui.initialValue.hidden = !hideInput;
            ui.hiZ.hidden = !hideInput;
            ui.subChanID.hidden = !hideInput;
            ui.subOutputPolicy.hidden = !hideInput;
        }
    },
    {
        name: "initialValue",
        displayName: "Initial Value",
        description: "Initial Output Value for the pin, set or cleared before enabling.",
        longDescription: `Sets the initial state of a pin when configured as an output.
        The state also depends on other IOMUX configuration settings, such as Invert and High-Impedance
        `,
        hidden: false,
        default: "CLEARED",
        options: [
            {name: "CLEARED", displayName: "Cleared" },
            {name: "SET", displayName: "Set" },
        ]
    },
    {
        name: "ioStructure",
        displayName: "IO Structure",
        description: "The input/output structure of a given pin denoting the available configurables",
        longDescription: `
<TODO: Add table 7-1 from the TRM>

There are several input output structures on different pins on each device that have different functionality.
The table above shows the specific differences for each pin and which configurables are available
on each pin.\n

It is recommended to configure the IOMUX features on the device first, as this will allow for the maximum possible
structures to be used in the solution.\n
        `,
        default: "Any",
        options: (inst) => {
            if(Common.isDeviceM0G()){
                return [
                    {name: "Any"},
                    {name: "SD", displayName: "Standard"},
                    {name: "SDW", displayName: "Standard with Wake"},
                    {name: "HS", displayName: "High-Speed"},
                    {name: "HD", displayName: "High-Drive"},
                    {name: "OD", displayName: "5V Tolerant Open Drain"}
                ];
            }
            else if(Common.isDeviceFamily_PARENT_MSPM0L11XX_L13XX()){
                return [
                    {name: "Any"},
                    {name: "SD", displayName: "Standard"},
                    {name: "SDW", displayName: "Standard with Wake"},
                    {name: "HS", displayName: "High-Speed"},
                    {name: "OD", displayName: "5V Tolerant Open Drain"}
                ];
            }
            else if(Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()){
                return [
                    {name: "Any"},
                    {name: "SD", displayName: "Standard"},
                    {name: "SDW", displayName: "Standard with Wake"},
                    {name: "HS", displayName: "High-Speed"},
                    {name: "HD", displayName: "High-Drive"},
                    {name: "OD", displayName: "5V Tolerant Open Drain"}
                ];
            }
            else if(Common.isDeviceM0C()){
                return [
                    {name: "Any"},
                    {name: "SD", displayName: "Standard"},
                    {name: "HS", displayName: "High-Speed"},
                    {name: "OD", displayName: "5V Tolerant Open Drain"}
                ];
            }
            else{
                return [
                    {name: "Any"},
                ];
            }
        },
        getDisabledOptions: (inst) => {
            let disabledOptions = [];
            let badOpts = determineInvalidOptions(inst);
            for(let opt in badOpts){
                if(badOpts[opt] === true){ // then it should be disabled
                    /* Check for special case for SDL type */
                    if(opt !== "SDL"){
                        disabledOptions.push({name: opt,
                            reason: "IOMux configuration does not allow for this type of IO structure"});
                    }

                }
            }
            return disabledOptions;
        },
        onChange: (inst) => {
            // TODO: hide some specific functions depending on IO Structure
            // hysteresis control only on open drain

            // read only wake if not available (or hide)

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
                hidden: false,
                default: "NONE",
                options: [
                    {name: "NONE", displayName: "No Resistor"},
                    {name: "PULL_UP", displayName: "Pull-Up Resistor"},
                    {name: "PULL_DOWN", displayName: "Pull-Down Resistor"}
                ],
                getDisabledOptions: (inst) => {
                    // pull up not available on Open Drain
                    if(inst.ioStructure === "OD"){
                        return [{name: "PULL_UP", displayName: "Pull-Up (Not Available)",
                        reason: "Open Drain IO structure does not contain an internal Pull-Up resistor"}];
                    } else {
                        return [];
                    }
                }
            },
            {
                name: "invert",
                displayName: "Invert",
                description: "Option to invert the Input/Output",
                hidden: false,
                default: "DISABLE",
                options: [
                    {name: "ENABLE", displayName: "Enabled"},
                    {name: "DISABLE", displayName: "Disabled"}
                ]
            },
            {
                name: "driveStrength", // OUTPUT only
                displayName: "Drive Strength Control",
                description: "Set drive strength on high-drive and high-speed capable pins",
                hidden: false,
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
                hidden: false,
                default: "DISABLE",
                options: [
                    {name: "ENABLE", displayName: "Enabled"},
                    {name: "DISABLE", displayName: "Disabled"}
                ]
            },
            {
                name: "inputFilter", // INPUT only
                displayName: "Input Filter",
                description: "Optional Input filter to smooth inputs",
                longDescription: `
This feature allows users to easily implement input filtering in hardware for cases where fast switching on the
input pin is needed to be filtered out. The GPIO module supports 4 levels of user-specified input filtering:
* Sampled input without filtering (no minimum pulse width requirement)
* Input filter sampling window equal to 1 ULPCLK period
* Input filter sampling window equal to 3 ULPCLK periods
* Input filter sampling window equal to 8 ULPCLK periods`,
                hidden: true,
                default: "DISABLE",
                options: [
                    {name: "DISABLE", displayName: "Disabled"},
                    {name: "1_CYCLE", displayName: "One ULPCLK Cycle"},
                    {name: "3_CYCLES", displayName: "Three ULPCLK Cycles"},
                    {name: "8_CYCLES", displayName: "Eight ULPCLK Cycles"}
                ],
            },
            {
                name: "fastWakeEn", // INPUT only
                displayName: "Enable Fast-Wake",
                description: "Enable detection of interrupt events without a high-speed clock",
                longDescription: `
The FastWake feature in the MSPM0 GPIO peripheral allows the GPIO module to stay in a low power state and
detect interrupt events on the device pins without requiring a high-speed clock. This allows the device to support
fast wakeup from low-power modes, such as STOP and STANDBY, on any GPIO pin.\n

NOTE: Fast-Wake can be utilized on any GPIO, but only works down to STANDBY mode. For wakeup in SHUTDOWN mode, a GPIO with Wakeup functionality must be chosen.
                `,
                hidden: true,
                default: false,
                readOnly: false,
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
    {
        name: "assignedPort",
        displayName: "Assigned Port",
        default: "Any",
        options: (inst) => {
            let portOptions = [
                {name: "Any"},
            ];
            if(Common.hasGPIOPortA()){
                portOptions.push(
                    {name: "PORTA"}
                )
            }
            if(Common.hasGPIOPortB()){
                portOptions.push(
                    {name: "PORTB"}
                )
            }
            if(Common.hasGPIOPortC()){
                portOptions.push(
                    {name: "PORTC"}
                )
            }
            return portOptions;
        }
    },
    {
        name: "assignedPortSegment",
        displayName: "Assigned Port Segment",
        description: "Determine Upper or Lower Port Segment",
        longDescription: `
Explicitly allows for upper or lower port utilization on the device. Some functions in
GPIO are grouped at the segment level. Pins can be chosen to all be in a specific segment to
reduce code size
\nAdditionally, Events are set up at the port segment level. Therefore, if more complicated
Event Configurations are needed, it may be necessary to separate event functionality into multiple
port Segments.
        `,
        default: "Any",
        options: [
            {name: "Any"},
            {name: "Lower"},
            {name: "Upper"},
        ]
    },
    {
        name: "assignedPin",
        displayName: "Assigned Pin",
        description: "User assigned pin index on the Port",
        longDescription: `
Optionally Specify the specific Pin Index on the Port. Possible Values are Any and 0-31.
Selecting the Upper or Lower Segment limits the possible values further.
        `,
        default: "Any"
    },
    {
       name: "Interrupts Group",
       displayName: "Interrupts/Events",
       config: [
            {
                name: "interruptEn",
                displayName: "Enable Interrupts",
                description: "Enables CPU Interrupt based on Polarity",
                longDescription: ``,
                hidden: true,
                default: false,
                onChange: (inst, ui) => {
                    ui.interruptPriority.hidden = !(inst.direction === "INPUT") || !inst.interruptEn;
                }
            },
            {
                name: "interruptPriority",
                displayName: "Interrupt Priority",
                description: "Specifies interrupt priority for entire port",
                longDescription: `
All pins in GPIO (both ports) are placed in the INT_GROUP1 peripheral
group, thus their interrupt priority is tied to other members of the group.

INT_GROUP1:
* GPIO
* COMP
* TRNG (if available)
                `,
                hidden: true,
                default: "DEFAULT",
                options: Common.InterruptPriorityOptions,
            },
            {
                name: "polarity",
                displayName: "Trigger Polarity",
                description: "Manner in which an input will cause a triggering event",
                longDescription: `
                When configured as an input, each GPIO pin can be configured independently
                to generate a specific trigger condition (for both interrupt and event)
                `,
                hidden: true,
                default: "DISABLE",
                options: [
                    {name: "DISABLE", displayName: "Disabled" },
                    {name: "RISE", displayName: "Trigger on Rising Edge"},
                    {name: "FALL", displayName: "Trigger on Falling Edge"},
                    {name: "RISE_FALL", displayName: "Trigger on Both Edges"}
                ],

            },
            {
                name: "pubChanID",
                displayName: "Event Publishing Channel",
                description: "Enable Publishing to a Selected Generic Event Channel",
                longDescription: `
Event Channel ID for a GPIO event to occur. Polarity is Shared with Events and Interrupts. \n
NOTE: On a given port, pins 0-15 share a channel FPUB0, and pins 16-31 share
a second channel FPUB1. There cannot be more channels or multiple pins in 0-15
publishing to more than one channel.
                `,
                hidden: true,
                default: 0,
                options: EVENT.getPublisherOptions,
                getDisabledOptions: (inst) => {
                    return getGPIODisabledPublisherOptions(inst);
                }
            },
            {
                name: "subChanID",
                displayName: "Event Subscribing Channel",
                description: "Enable Subscribing to a Selected Generic Event Channel",
                longDescription: `
Event Channel ID for a GPIO event to occur. \n
NOTE: On a given port, pins 0-15 share a channel FSUB0, and pins 16-31 share
a second channel FSUB1. Only one bit per channel can be affected by an event
as dictated by the output policy.
                `,
                hidden: false,
                default: 0,
                options: EVENT.getSubscriberOptions,
                getDisabledOptions: (inst) => {
                    return getGPIODisabledSubscriberOptions(inst);
                }
            },
            {
                name: "subOutputPolicy",
                displayName: "Output Policy",
                description: "Determine what the pin will do during a Subscribe Event",
                longDescription: `Upon a Subscribe Event, one pin in each lower/upper grouping is able to be
                set, cleared, or toggled each time the event arrives.
                `,
                hidden: false,
                default: "SET",
                options: [
                    {name: "SET", displayName: "Bit will be Set" },
                    {name: "CLEAR", displayName: "Bit will be Cleared" },
                    {name: "TOGGLE", displayName: "Bit will be Toggled" }
                ]
            },
            {
                name: "eventInfo",
                hidden: true,
                description: "information about configured events that is passed to the EVENT module",
                /*
                 * A GPIO pin is set as an input or output, so a pin can only
                 * be a publisher or subscriber. As a result, eventInfo is
                 * always an 1 element array per GPIO pin instance. Other
                 * modules such as ADC can publish and subscribe at the same
                 * time so eventInfo can be an array of multiple elements.
                 */
                default: [""],
                options: (inst) => {
                    let options = [{name: ""}]
                    if(inst.pubChanID != 0){
                        options.push({name: inst.pubChanID.toString() + "pub"});
                    }
                    if(inst.subChanID != 0){
                        options.push({name: inst.subChanID.toString() + "sub"});
                    }
                    return options;
                },
                getValue: (inst) => {
                    let result = [];
                    if(inst.direction === "INPUT" && inst.pubChanID != 0){
                        result.push(inst.pubChanID.toString() + "pub");
                    }
                    if(inst.direction === "OUTPUT" && inst.subChanID != 0){
                        result.push(inst.subChanID.toString() + "sub");
                    }
                    if(result.length == 0){
                        result = [""];
                    }
                    return result;
                }
            }
       ]

   }
];

/* EVENT.MAX_NUM_EVENT_CHANNELS and EVENT.SPLITTER_EVENT_CHANNELS is undefined */
let MAX_NUM_EVENT_CHANNELS;
let SPLITTER_EVENT_CHANNELS = [];
if (Common.isDeviceM0L() || Common.isDeviceM0C())
{
    /*
     * M0L devices support 4 event channels (0, 1, 2, and 3). Event channel
     * 3 is a splitter (1:2) channel
     */
    MAX_NUM_EVENT_CHANNELS = 4;
    SPLITTER_EVENT_CHANNELS = [3];
}
else
{
    /*
     * M0G devices support 16 event channels (0 to 15). Event channels 12-15
     * are splitters
     */
    MAX_NUM_EVENT_CHANNELS = 16;
    SPLITTER_EVENT_CHANNELS = [12, 13, 14, 15];
}

/*
 * The disabled options for GPIO events works a little differently. GPIO event
 * indexes (FSUB0/1, FPUB0/1) must use the same event channel. The particular
 * event index depends on whether a GPIO pin is selected as an input or output
 * (publisher or subscriber) and the pin number. GPIO pins 0-15 are mapped to
 * FSUB/PUB0, pins 16-31 are mapped to FSUB/PUB1.
*/
function getGPIODisabledPublisherOptions(inst)
{
    let disabledOptions = [];

    let gpioPinModules = system.modules["/ti/driverlib/gpio/GPIOPin"];

    let currentPinName;
    let eventChannel;

    if (gpioPinModules && gpioPinModules.$instances)
    {
        /* Escape condition if $solution does not exist */
        if(!inst.pin.$solution){
            return [];
        }

        currentPinName = inst.pin.$solution.peripheralPinName;

        for (let pinInst of gpioPinModules.$instances)
        {
            let pinInstName = pinInst.pin.$solution.peripheralPinName;
            /*
             * For a GPIO pin, eventInfo is an 1 element array. See eventInfo
             * field description for more details
             */
            let pinInstEventInfo = pinInst.eventInfo[0];

            /* Make sure you aren't looking at the same exact pin */
            if ((currentPinName != pinInstName) && pinInstEventInfo)
            {
                if (pinInstEventInfo.endsWith("pub"))
                {
                    eventChannel = parseInt(pinInstEventInfo.match(/\d+/)[0]);

                    /* Check if any pins are already using an event index */
                    if (isUsingSameEventIndex(pinInstName, currentPinName))
                    {
                        for (let chanIdx = 1; chanIdx < MAX_NUM_EVENT_CHANNELS; chanIdx++)
                        {
                            /*
                             * If another pin is using the same publisher
                             * event index, then they must use the same
                             * event channel. All other channel options
                             * should be disabled.
                             */
                            if (chanIdx != eventChannel)
                            {
                                let disabledChannel = {
                                    name: chanIdx,
                                    displayName: "",
                                    reason: "Publishers using the same event index (FPUB0 or FPUB1) must use the same event channel"
                                }

                                /* Don't push duplicates */
                                if (!disabledOptions.find(element => element.name == chanIdx))
                                {
                                    disabledOptions.push(disabledChannel);
                                }
                            }
                        }
                    }
                    else
                    {
                        let disabledChannel = {
                            name: eventChannel,
                            displayName: "",
                            reason: "Publishers using the different event indexes (FPUB0 or FPUB1) must use different event channels"
                        }

                        /* Don't push duplicates */
                        if (!disabledOptions.find(element => element.name == eventChannel))
                        {
                            disabledOptions.push(disabledChannel);
                        }
                    }
                }
            }
        }
    }

    return disabledOptions;
}

function getGPIODisabledSubscriberOptions(inst)
{
    let disabledOptions = [];

    let gpioPinModules = system.modules["/ti/driverlib/gpio/GPIOPin"];

    let currentPinName;
    let eventChannel;

    if (gpioPinModules && gpioPinModules.$instances)
    {
        /* Escape condition if $solution does not exist */
        if(!inst.pin.$solution){
            return [];
        }

        currentPinName = inst.pin.$solution.peripheralPinName;

        for (let pinInst of gpioPinModules.$instances)
        {
            let pinInstName = pinInst.pin.$solution.peripheralPinName;
            /*
             * For a GPIO pin, eventInfo is an 1 element array. See eventInfo
             * field description for more details
             */
            let pinInstEventInfo = pinInst.eventInfo[0];

            /* Make sure you aren't looking at the same exact pin */
            if ((currentPinName != pinInstName) && pinInstEventInfo)
            {
                if (pinInstEventInfo.endsWith("sub"))
                {
                    eventChannel = parseInt(pinInstEventInfo.match(/\d+/)[0]);

                    /* Check if any pins are already using an event index */
                    if (isUsingSameEventIndex(pinInstName, currentPinName))
                    {
                        for (let chanIdx = 1; chanIdx < MAX_NUM_EVENT_CHANNELS; chanIdx++)
                        {
                           /*
                            * For subscribers, only one pin can be used per event
                            * index
                            */
                            let disabledChannel = {
                                name: chanIdx,
                                displayName: "",
                                reason: "Only one subscriber per event index"
                            }

                            /* Don't push duplicates */
                            if (!disabledOptions.find(element => element.name == chanIdx))
                            {
                                disabledOptions.push(disabledChannel);
                            }
                        }
                    }
                    else
                    {
                        /*
                         * For splitter channels (1:2) where multiple
                         * subscribers are allowed, multiple GPIO
                         * subscribers are allowed only if they are
                         * using different event indexes
                         */
                        if (!SPLITTER_EVENT_CHANNELS.includes(eventChannel))
                        {
                            let disabledChannel = {
                                name: eventChannel,
                                displayName: "",
                                reason: "Subscribers using the different event indexes (FSUB0 or FSUB1) must use different event channels"
                            }

                            /* Don't push duplicates */
                            if (!disabledOptions.find(element => element.name == eventChannel))
                            {
                                disabledOptions.push(disabledChannel);
                            }
                        }
                    }
                }
            }
        }
    }

    return disabledOptions;
}

function isUsingSameEventIndex(pinOneName, pinTwoName)
{
    /* Prevent case of accessing non-existing pin name */
    if([pinOneName,pinTwoName].includes(null)){
        return false;
    }

    /* In the case of more than one mux per pad, GPIO defaults to the first one */
    let pinOneGPIOPort = Common.getGPIOPort(pinOneName.split("/")[0]);
    let pinTwoGPIOPort = Common.getGPIOPort(pinTwoName.split("/")[0]);
    let pinOneGPIONumber = parseInt(Common.getGPIONumber(pinOneName.split("/")[0]));
    let pinTwoGPIONumber = parseInt(Common.getGPIONumber(pinTwoName.split("/")[0]));

    let usingSameEventIndex = false;

    if ((pinOneGPIOPort == "GPIOA" && pinTwoGPIOPort == "GPIOA") ||
        (pinOneGPIOPort == "GPIOB" && pinTwoGPIOPort == "GPIOB"))
    {
        if ((pinOneGPIONumber < 16 && pinTwoGPIONumber < 16) ||
            (pinOneGPIONumber >= 16 && pinTwoGPIONumber >= 16))
        {
            usingSameEventIndex = true;
        }
    }

    return usingSameEventIndex;
}

const memoizedGPIOFilter = _.memoize(curryGPIOFilter, (validPinSet) => JSON.stringify(validPinSet));

function curryGPIOFilter(validPinSet) {
	return (devicePin, peripheralPin) => GPIOFilter(devicePin, validPinSet);
}

function GPIOFilter(devicePin, validPinSet) {
    return validPinSet.includes(devicePin.name);
}

/*  ======== pinmuxRequirements ========
 *  Returns peripheral pin requirements of the specified instance
 *
 *  param inst    - a fully configured module instance
 *
 *  returns req[] - an array of pin requirements needed by inst
 */
function pinmuxRequirements(inst)
{
    let validPinSet = [];
    let invalid = determineInvalidOptions(inst);
    for(let pinIdx in system.deviceData.gpio.pinInfo){
        let pin = system.deviceData.gpio.pinInfo[pinIdx];
        let eligible = true;
        if(inst.assignedPort !== "Any"){
            let port = new RegExp("^P" + inst.assignedPort.slice(-1));
            eligible &= (pin.peripheralPin.name.match(port) !== null);
            if(!eligible){ continue; }
        }
        if(inst.assignedPortSegment !== "Any" || inst.assignedPin.toLowerCase() !== "any"){
            let num = undefined;
            if(pin.peripheralPin.peripheralName.split("/").length>1){
                let nums = (pin.peripheralPin.peripheralName.split("/")).map(a => a.match(/\d+$/)[0]);
                let numIndex = nums.indexOf(inst.assignedPin);
                if(numIndex>=0){num = parseInt(nums[numIndex])};
            }
            else{
                num = parseInt(pin.peripheralPin.name.match(/\d+$/)[0]);
            }
            if(inst.assignedPin.toLowerCase() !== "any") {
                eligible &= (num === parseInt(inst.assignedPin));
            } else {
                if(inst.assignedPortSegment === "Upper"){
                    eligible &= (num >= 16);
                } else {
                    eligible &= (num < 16);
                }
                if(!eligible){ continue; }
            }
        }
        let struct = pin.devicePin.attributes.io_type;
        if(inst.ioStructure == "SD"){
            // possible GPIO pin must match specific structure
            // also handling special case of SDL io type
            eligible &= (struct === inst.ioStructure || struct === "SDL");
        }
        else if(inst.ioStructure !== "Any"){
            // possible GPIO pin must match specific structure
            eligible &= (struct === inst.ioStructure);
        }
        else if(_.some(invalid, (s) => {return s === true;})) {
            // possible GPIO pin must not be invalid
            // if invalid is true, then pin should be ineligible
            eligible &= (invalid[struct] !== true);
        }
        if(eligible){
            validPinSet.push(pinIdx);
        }
    }
    // one pin per module
    let gpio_pin = {
        name: "pin",
        displayName: inst.$name,
        interfaceName: "GPIO",
        filter: memoizedGPIOFilter(validPinSet)
    };
    return ([gpio_pin]);
}

function validate(inst, validation)
{
    /* validate launchpad shortcut */
    if(inst.launchPadShortcut !== undefined){
        let validOptions = inst.$module.$configByName.launchPadShortcut.options(inst);
        let selectedOption = inst.launchPadShortcut;
        let found = _.find(validOptions, (o) => o.name === selectedOption);
        if(!found) {
            validation.logError("LaunchPad Shortcut Option is invalid, please re-select",
                inst, "launchPadShortcut");
        }
    }
    /* TODO: need to also validate that each shortcut is used at most once
       (currently gives resource conflict) */


    /* Fast Wake Notes */
    if(inst.ioStructure == "SDW" && !inst.fastWakeEn){
        validation.logInfo("Wakeup is only needed to wake the device from Shutdown mode. Fast-Wake option can be used on any GPIO for faster wakeup times from other LPMs.",
        inst, ["ioStructure"]);
    }


    /* validate ioStructure PinMux */
    let validOptions = inst.$module.$configByName.ioStructure.options(inst);
	let selectedOption = inst.ioStructure;
    let found = _.find(validOptions, (o) => o.name === selectedOption);
    if(!found) {
        validation.logError("Selected Option is invalid, please reselect", inst, "ioStructure");
    }
    // validate assigned pin
    if(inst.assignedPin.match(/Any/i) === null){
        let num = parseInt(inst.assignedPin);
        let min = 0;
        let max = 31;
        if(inst.assignedPortSegment == "Upper"){
            min = 16;
        } else if (inst.assignedPortSegment == "Lower"){
            max = 15;
        }
        if(!(num >= min && num <= max)){
            validation.logError("Invalid Pin Assignment. Valid values are Any and "+min+"-"+max,
                inst, "assignedPin");
        }
    }

    /* IOMUX validation Based on TRM table 7-1 */
    // make sure the IOMux configuration is possible,
    if(inst.direction === "OUTPUT") {
        if(inst.driveStrength === "HIGH" && (inst.ioStructure.match(/Any|HD|HS/) === null)){
            validation.logError("Drive Strength not possible on selected IO Structure", inst, "ioStructure");
        }
    } else {
        if(inst.hysteresisControl === "ENABLE" && (inst.ioStructure.match(/Any|OD/) === null)){
            validation.logError("Hysteresis only valid on Open Drain", inst, "ioStructure");
        }
        // wakeupLogic option not configurable in M0C
        if(Common.hasWakeupLogic()){
            if(inst.wakeupLogic !== "DISABLE" && inst.ioStructure.match(/Any|OD|SDW|HD/) == null) {
                validation.logError("Wakeup Logic configuration only valid on Open Drain and Standard with Wake ", inst, "wakeupLogic");
            }
        }
        if(inst.internalResistor === "PULL_UP" && inst.ioStructure.match(/OD/) !== null) {
            validation.logError("Pull-Up Resistor not valid on an Open Drain Configuration", inst, "ioStructure");
        }
    }
    // checks if invalid options returns any that are valid (false)
    // if not, then it is impossible to find a valid configuration
    if( !(_.some(determineInvalidOptions(inst), (s) => {return s === false;}) ) ) {
        validation.logError("Current configuration of IOMUX features does not apply to any structure", inst, "ioStructure");
    }

    // TODO: add logic that pin exists outside of assigns but can
    // not be chosen based on filtering

    /* Special Case: global fast wake validation */
    if (inst.direction === "INPUT"){
        let board = system.modules["/ti/driverlib/Board"].$static;
        if(board){
            if(board.globalFastWakeEn){
                validation.logInfo("This selection is currently being overriden by enabling Global Fast-Wake in Board module", inst, "fastWakeEn");
            }
        }
    }

    /* Validate Event selection for case of switching devices.
     * Checks that selected event is withing the valid options
     * for current device.
     */
    if(inst.direction === "INPUT"){
        EVENT.validatePublisherOptions(inst,validation,"pubChanID");
    }
    else{
        EVENT.validateSubscriberOptions(inst,validation,"subChanID");
    }
}

function validatePinmux(inst, validation)
{
    let pin = inst.pin.$solution;

    // if there's already an error, the solution is null and not useful
    if(pin.error === ""){
        // make sure io function matches selected capabilities
        let packagePin = pin.packagePinName;
        let invalid = determineInvalidOptions(inst);
        if(_.some(invalid, (s) => {return s === true;})) {
            // some limitations on possible GPIO pins
            let struct = system.deviceData.devicePins[packagePin].attributes.io_type;
            // if invalid is true, then pin should be ineligible
            if(invalid[struct] === true) {
                validation.logError("Selected Pin with structure "+ struct +" incapable of current configuration",inst,"ioStructure");
            }
        }
        if(inst.direction === "INPUT" ){
            if( (inst.interruptEn || inst.pubChanID !== 0) && inst.polarity === "DISABLE") {
                validation.logWarning("Interrupt does not have active polarity, and thus cannot be triggered", inst, "polarity");
            }
        }
    }

    /* validate use of PA0. A3 and A2 LP's have active low LED on PA0.
    *  Inform the user to use DL_GPIO_clearPins() to turn on the LED
    */
    if(_.startsWith(Common.boardName(), "LP")) {
        try{
            if (inst.pin.$solution && inst.pin.$solution.peripheralPinName.includes("PA0")) {
                validation.logInfo("Tip: LED PA0 on Launchpads is Active Low.",
                inst, ["initialValue"]);
            }
        }
        catch(e){
            // Avoid validation message if pin resource does not exist or there is a conflict.
        }

    }

    /* EVENT validation */
    // only one pin per subscriber

    // only one channel per segment

    // have some option where the interrupt needs to live on the same port?
    // set warning if interrupts on the same group live on different ports
    // set info if more than one group has an interrupt on the same port
}

if(system.deviceData.package === "LQFP-64(PM)"){
    config = config.concat(gpioLaunchPadConfig);
}

exports = {
    config: config,
    pinmuxRequirements: pinmuxRequirements,
    validate: validate,
    validatePinmux: validatePinmux,

    /* Added for cleaner error message on duplicate pin name */
    displayName: "MSPM0 GPIO Pin",
};
