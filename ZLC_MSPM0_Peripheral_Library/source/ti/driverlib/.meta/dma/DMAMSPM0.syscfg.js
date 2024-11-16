/*
 * Copyright (c) 2023 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*
 *  ======== DMAMSPM0.syscfg.js ========
 */

"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");
let EVENT = system.getScript("/ti/driverlib/EVENT.syscfg.js");
/* Determine channe availability depending on device */
let dmaInstances = system.deviceData.interfaces["DMA_CHANNEL"].peripherals.length;

function getDMAChanParents(dmaChanIdx){
    return {
        name        : "chan"+dmaChanIdx.toString()+"Parent",
        displayName : "Channel "+dmaChanIdx.toString(),
        description : "Shows which module instance Channel "+dmaChanIdx.toString()+" is being configured by.",
        default     : "Channel not configured",
        getValue    : () => {
            let parent= "Channel not configured"
            try{
                let DMAChannels = system.modules["/ti/driverlib/DMAChannel"].$instances;
                for(let channel in DMAChannels){
                    let chanInst = DMAChannels[channel];
                    if(chanInst.channelID == dmaChanIdx){
                        parent = chanInst.$ownedBy.$name;
                        if(parent.includes("/ti/driverlib/")){
                            parent = parent.replace("/ti/driverlib/","");
                        }
                        else{
                            parent = chanInst.$ownedBy.peripheral.$solution.peripheralName+": "+parent;
                        }
                    }
                }
            }catch (e) {
                // do nothing
            }
            return parent;
        }
    }
}
let dmaParentConfig = [];
for(let dmaChanIdx=0;  dmaChanIdx<= (dmaInstances -1);  dmaChanIdx++){
    dmaParentConfig.push(getDMAChanParents(dmaChanIdx));
}

const globalEventOptions = [
    // DL_DMA_[...]
    {name: "EVENT_ADDR_ERROR", displayName: "DMA address error, source address not reachable"},
    {name: "EVENT_DATA_ERROR", displayName: "DMA data error, source data might be corrupted (PAR or ECC error)"},
]

let DMAConfig = [
    {
        name: "GROUP_BASIC_CONFIG",
        displayName: "Basic Configuration",
        description: "",
        longDescription: "",
	    collapsed: false,
        config: [
            // DL_DMA_setBurstSize
            {
                name: "enableBurst",
                displayName: "Enable Burst Block Mode",
                default: false,
                longDescription: `
When enabled, after the DMA transfers the amount of transfers defined by
the selected Burst Size, the ongoing block transfer is interrupted and the
priority encoder has the chance to assign a higher priority channel. The
previously interrupted block transfer is internally marked as pending and
when no other high priority channel is pending the block transfer will
continue with the next burst or until DMASZ counts down to 0.
                `,
                onChange: (inst,ui) => {
                    ui.burstSize.hidden = !inst.enableBurst;
                }
            },
            // DL_DMA_setBurstSize / DL_DMA_BURST_SIZE
            {
                name: "burstSize",
                displayName: "Burst Size",
                hidden: true,
                default: "INFINITY",
                description: "Set the burst size for block transfers",
                longDescription: `
**No burst interruption:** The block transfer always transfers all elements
defined in the DMASZ register before priority is newly evaluated
\n**Others:** Burst size of a block transfer is as selected
                `,
                options: [
                    {name: "INFINITY", displayName: "No burst interruption."},
                    {name: "8", displayName: "8"},
                    {name: "16", displayName: "16"},
                    {name: "32", displayName: "32"},
                ],
            },
            // DL_DMA_enableRoundRobinPriority
            {
                name: "enableRoundRobin",
                displayName: "Enable Round-Robin Priority",
                description: "Configure the DMA for round-robin priority",
                longDescription:`
When round-robin priority is enabled, the channel that completes a transfer
becomes the lowest priority. If multiple triggers happen simultaneously or
are pending, the channel that transferred least recently will transfer
first. Once it's complete the next highest priority channel will transfer.`,
                default: false,
            },
        ]
    },
    {
        name: "GROUP_CHAN_OVERVIEW",
        displayName: "Channel Overview",
        description: "",
        longDescription: `
In this section you can find a list of the available channels and which modules
are configuring them. In order to modify configuration settings of a desired
channel, please refer to the individual listed modules. The modules are shown
with the format of *peripheral name: instance name*.`,
	    collapsed: false,
        config: dmaParentConfig,
    },
    {
        name: "mostSevereInterruptPriority",
        description: "the highest explicitly defined interrupt priority among any channel",
        default: "DEFAULT",
        hidden: true,
        options: Common.InterruptPriorityOptions,
        getValue: (inst, ui) => {
            let mod = system.modules["/ti/driverlib/DMAChannel"];
            if(_.isUndefined(mod) || mod.$instances.length == 0){
                return "DEFAULT";
            } else {
                let candidatePriority = 4;
                for(let chanInst of mod.$instances){
                    if(chanInst.interruptPriority !== "DEFAULT"){
                        let intPri = parseInt(chanInst.interruptPriority);
                        if(intPri < candidatePriority){
                            candidatePriority = intPri;
                        }
                    }
                }
                if(candidatePriority < 4){
                    return candidatePriority.toString();
                } else {
                    return "DEFAULT"
                }
            }

        }
    },
    {
        name: "eventConfig",
        displayName: "Global Event Configuration",
        longDescription: `Specifies the DMA Events that are to trigger an Event Condition and where the events are to be published`,
        collapsed: true,
        config: [
            {
                name        : "pubChanID",
                displayName : "Event Publisher Channel ID",
                description : 'Sets the event publisher channel id',
                hidden      : false,
                default: 0,
                options: EVENT.getPublisherOptions,
                getDisabledOptions: EVENT.getPublisherDisabledOptions,
            },
            /* DL_DMA_enableEvent / DL_DMA_disableEvent */
            {
                name        : "enabledEvents",
                displayName : "Enable Events",
                description : '',
                hidden      : false,
                default     : [],
                minSelections: 0,
                options     : globalEventOptions,
            },
            {
                name: "subscriberIndex",
                displayName: "Subscriber Register Event Index",
                description: "Specifies the register event index to be configured",
                longDescription: `Specifies the register event index to be configured`,
                default: [],
                minSelections: 0,
                options: [
                    {name: "0", displayName: "Subscriber Index 0"},
                    {name: "1", displayName: "Subscriber Index 1"}
                ],
                onChange: (inst, ui) => {
                    ui.sub0ChanID.hidden = !(inst.subscriberIndex.includes("0"));
                    ui.sub1ChanID.hidden = !(inst.subscriberIndex.includes("1"));
                }
            },
            {
                name        : "sub0ChanID",
                displayName : "Event Subscriber Index 0 Channel ID",
                description : 'Sets the event subscriber channel id',
                hidden      : true,
                default: 0,
                options: EVENT.getSubscriberOptions,
                getDisabledOptions: EVENT.getSubscriberDisabledOptions,
            },
            {
                name        : "sub1ChanID",
                displayName : "Event Subscriber Index 1 Channel ID",
                description : 'Sets the event subscriber channel id',
                hidden      : true,
                default: 0,
                options: EVENT.getSubscriberOptions,
                getDisabledOptions: EVENT.getSubscriberDisabledOptions,
            },
            {
                name: "eventInfo",
                description: "information about configured events that's passed on to the EVENT module",
                default: [""],
                hidden: true,
                options: (inst) => {
                    let options = [{name: ""}]
                    if(inst.pubChanID != 0){
                        options.push({name: inst.pubChanID.toString() + "pub"});
                    }
                    if((inst.subscriberIndex.includes("0")) && (inst.sub0ChanID != 0)){
                        options.push({name: inst.sub0ChanID.toString() + "sub"});
                    }
                    if((inst.subscriberIndex.includes("1")) && (inst.sub1ChanID != 0)){
                        options.push({name: inst.sub1ChanID.toString() + "sub"});
                    }
                    return options;
                },
                getValue: (inst) => {
                    let result = [];
                    if(inst.pubChanID != 0){
                        result.push(inst.pubChanID.toString() + "pub");
                    }
                    if((inst.subscriberIndex.includes("0")) && (inst.sub0ChanID != 0)){
                        result.push(inst.sub0ChanID.toString() + "sub");
                    }
                    if((inst.subscriberIndex.includes("1")) && (inst.sub1ChanID != 0)){
                        result.push(inst.sub1ChanID.toString() + "sub");
                    }
                    if(result.length == 0){
                        result = [""];
                    }
                    return result;
                }
            }

        ]
    },
];


/*
 *  ======== validate ========
 *  Validate this inst's configuration
 *
 *  param inst       - module instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validate(inst, validation)
{
    // EVENT Validation
    let useSUB0 = false;
    let useSUB1 = false;
    let eventsAreEnabled = false;
    // Wrapped on try case in case DMA Channel has not been added
    try{
        let DMAChannels = system.modules["/ti/driverlib/DMAChannel"].$instances;
        for(let channel in DMAChannels){
            let chanInst = DMAChannels[channel];
            if(chanInst.triggerSelect == "FSUB_0"){
                useSUB0 = true;
            }
            if(chanInst.triggerSelect == "FSUB_1"){
                useSUB1 = true;
            }
            if(chanInst.enabledEvents.length>0){
                eventsAreEnabled = true;
            }
        }
        if(useSUB0 && useSUB1){
            if(!inst.subscriberIndex.length>0){
                validation.logWarning("Subscriber Index must be configured for event use", inst, ["subscriberIndex"]);
            }
        }
        else if(useSUB0){
            if(!inst.subscriberIndex.includes("0")){
                validation.logWarning("Subscriber Index 0 must be configured for event use", inst, ["subscriberIndex"]);
            }
        }
        else if(useSUB1){
            if(!inst.subscriberIndex.includes("1")){
                validation.logWarning("Subscriber Index 1 must be configured for event use", inst, ["subscriberIndex"]);
            }
        }

    }catch (e) {
        // do nothing
    }
    if(inst.enabledEvents.length>0){
        eventsAreEnabled = true;
    }
    if(eventsAreEnabled){
        if(inst.pubChanID == 0){
            validation.logError("Publisher Channel must be enabled to configure events", inst, ["pubChanID"]);
        }
    }
    if(inst.subscriberIndex.length>0 &&(!useSUB0 && !useSUB1)){
        validation.logWarning("Subscriber Index is being configured but no DMA Channel is configuring subscriber event", inst, ["subscriberIndex"]);
    }

    /* Validate Event selection for case of switching devices.
     * Checks that selected event is withing the valid options
     * for current device.
     */
    EVENT.validatePublisherOptions(inst,validation,"pubChanID");
    if(inst.subscriberIndex.includes("0")){
        EVENT.validateSubscriberOptions(inst,validation,"sub0ChanID");
    }
    if(inst.subscriberIndex.includes("1")){
        EVENT.validateSubscriberOptions(inst,validation,"sub1ChanID");
    }
}

/*
 *  ======== moduleInstances ========
 *  Add individual DMA Channels
 */
function moduleInstances(inst) {
    let modInstances = new Array();
    let firstCollapse = false;

    let longDescription = ``;
    let modInst = {
        name: "associatedChannels",
        displayName: "DMA Channels",
        useArray: true,
        defaultInstanceCount: 0,
        minInstanceCount: 0,
        longDescription: longDescription,
        collapsed: firstCollapse,
        moduleName: "/ti/driverlib/DMAChannel",
        hidden: false,
        args: {

        },
        requiredArgs: {

        }
    };
    modInstances.push(modInst);
    firstCollapse = true;

    return (modInstances);
}

/*
 *  ======== devSpecific ========
 *  Device-specific extensions to be added to base module configuration
 */
let devSpecific = {

    config: DMAConfig,

    validate: validate,

    moduleInstances: moduleInstances,

};

/*
 *  ======== extend ========
 *  Extends a base exports object to include any device specifics
 *
 *  This function is invoked by the generic module module to
 *  allow us to augment/override as needed for the MSPM0.
 */
function extend(base)
{
    /* merge and overwrite base module attributes */
    let result = Object.assign({}, base.moduleStatic, devSpecific);

    /* concatenate device-specific configs */
    // moduleStatic specific to CRC as it's statically defined
    result.config = base.moduleStatic.config.concat(devSpecific.config);
    base.moduleStatic = result;

    // Todo: This is causing issues declaring the module
    return (base);
}

/*
 *  ======== exports ========
 *  Export device-specific extensions to base exports
 */
exports = {
    /* required function, called by base module module */
    extend: extend
};
