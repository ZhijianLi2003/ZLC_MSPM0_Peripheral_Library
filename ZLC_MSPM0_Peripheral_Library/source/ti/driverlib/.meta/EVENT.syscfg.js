/*
 * Copyright (c) 2018-2019, Texas Instruments Incorporated - http://www.ti.com
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
 *  ======== SYSCTL.syscfg.js ========
 */
"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

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


function findOffendingInstance(offendingModuleName){
    for(let moduleName in system.modules){
        let mod = system.modules[moduleName];
        if(mod.$instances){
            let offInst = _.find(mod.$instances, '$name',offendingModuleName)
            if(offInst)
            {
                return offInst;
            }
        }
        /* Static module use case */
        if(mod.moduleStatic){
            if(mod.$static.$name == "/ti/driverlib/"+offendingModuleName){
                return mod.$static;
            }
        }

    }
    /* unsuccessful */
    return undefined;
}

function validate(inst, validation){
    for(let chanIdx = 1; chanIdx < MAX_NUM_EVENT_CHANNELS; chanIdx ++) {
        /* No more than two subscribers for splitter generic route channel */
        /* No more than one subscriber for point to point generic route channel */
        let subPorts = inst["channel"+chanIdx+"Type"][2];
        if(inst["channel"+chanIdx+"Sub"].length > subPorts) {
            /* Currently just throwing an error for the last module,
             * but all modules could throw an error?
             */
            validation.logError("More Subscribers than the channel limit",
                inst,"channel"+chanIdx+"Sub");
        }
        /* No more than one publisher per generic route channel */
        if(inst["channel"+chanIdx+"Pub"].length > 1)
        {
            /* The error only applies to non-GPIO modules */
            if (findOffendingInstance("GPIO") == undefined)
            {
                /* This only applies to modules that aren't GPIO pins */
                validation.logError("Multiple Publishers to one event channel not allowed",
                    inst,"channel"+chanIdx+"Pub");
            }
        }
    }
}

/* Functions for filling out the configuration portion of the event,
 * with module internal configurables for code generation purposes*/

function publishOptions(inst, channel){
    let ch;
    let isPub;
    let options = [{name: ""}];
    for(let moduleName in system.modules){
        let mod = system.modules[moduleName];
        for(let instance in mod.$instances){
            let inst = mod.$instances[instance];
            if(inst.eventInfo!= ""){
                /* parse event information */
                for(let infoIdx in inst.eventInfo){
                    let info = inst.eventInfo[infoIdx];
                    ch = parseInt(info);
                    isPub = info.endsWith("pub");
                    if(ch == channel && isPub){
                        options.push({name: inst.$name});
                    }
                }
            }
        }
        if(mod.moduleStatic){
                let stat = mod.$static;
                if(stat.eventInfo!= ""){
                    /* parse event information */
                    for(let infoIdx in stat.eventInfo){
                        let info = stat.eventInfo[infoIdx];
                        ch = parseInt(info);
                        isPub = info.endsWith("pub");
                        if(ch == channel && isPub){
                            options.push({name: (stat.$name).replace("/ti/driverlib/","")});
                        }
                    }
                }
        }

    }
    return options;
}
function publishGetValue(inst, channel){
    let ch;
    let isPub;
    let results = [];
    for(let moduleName in system.modules){
        let mod = system.modules[moduleName];
        for(let instance in mod.$instances){
            let inst = mod.$instances[instance];
            if(inst.eventInfo!= ""){
                /* parse event information */
                for(let infoIdx in inst.eventInfo){
                    let info = inst.eventInfo[infoIdx];
                    ch = parseInt(info);
                    isPub = info.endsWith("pub");
                    if(ch == channel && isPub){
                        results.push(inst.$name);
                    }
                }
            }
        }
        if(mod.moduleStatic){
                let stat = mod.$static;
                if(stat.eventInfo!= ""){
                    /* parse event information */
                    for(let infoIdx in stat.eventInfo){
                        let info = stat.eventInfo[infoIdx];
                        ch = parseInt(info);
                        isPub = info.endsWith("pub");
                        if(ch == channel && isPub){
                            results.push((stat.$name).replace("/ti/driverlib/",""));
                        }
                    }
                }
        }
    }
    if(results.length == 0) {return [""];}
    return results;
}

function subscribeOptions(inst, channel){
    let ch;
    let isSub;
    let options = [{name: ""}];
    for(let moduleName in system.modules){
        let mod = system.modules[moduleName];
        for(let instance in mod.$instances){
            let inst = mod.$instances[instance];
            if(inst.eventInfo!= ""){
                /* parse event information */
                for(let infoIdx in inst.eventInfo){
                    let info = inst.eventInfo[infoIdx];
                    ch = parseInt(info);
                    isSub = info.endsWith("sub");
                    if(ch == channel && isSub){
                        options.push({name: inst.$name});
                    }
                }
            }
        }
        if(mod.moduleStatic){
            let stat = mod.$static;
            if(stat.eventInfo!= ""){
                /* parse event information */
                for(let infoIdx in stat.eventInfo){
                    let info = stat.eventInfo[infoIdx];
                    ch = parseInt(info);
                    isSub = info.endsWith("sub");
                    if(ch == channel && isSub){
                        options.push({name: (stat.$name).replace("/ti/driverlib/","")});
                    }
                }
            }
        }

    }
    return options;
}
function subscribeGetValue(inst, channel){
    let ch;
    let isSub;
    let results = [];
    for(let moduleName in system.modules){
        let mod = system.modules[moduleName];
        for(let instance in mod.$instances){
            let inst = mod.$instances[instance];
            if(inst.eventInfo!= ""){
                /* parse event information */
                for(let infoIdx in inst.eventInfo){
                    let info = inst.eventInfo[infoIdx];
                    ch = parseInt(info);
                    isSub = info.endsWith("sub");
                    if(ch == channel && isSub){
                        results.push(inst.$name);
                    }
                }
            }
        }
        if(mod.moduleStatic){
            let stat = mod.$static;
            if(stat.eventInfo!= ""){
                /* parse event information */
                for(let infoIdx in stat.eventInfo){
                    let info = stat.eventInfo[infoIdx];
                    ch = parseInt(info);
                    isSub = info.endsWith("sub");
                    if(ch == channel && isSub){
                        results.push((stat.$name).replace("/ti/driverlib/",""));
                    }
                }
            }
        }
    }
    if(results.length == 0) {return [""];}
    return results;
}

let masterConfig = [];
/*
 * The number of generic event channels and channel type
 * (point-to-point or splitter) is device dependent
 */
for(let chanIdx = 1; chanIdx < MAX_NUM_EVENT_CHANNELS; chanIdx++){

    let desc = (!SPLITTER_EVENT_CHANNELS.includes(chanIdx)) ? "1:1":"1:2";

    let channel = {
        name: "channel"+chanIdx,
        displayName: "Channel "+chanIdx,
        description: desc,
        longDescription: `This is a summary of events that are publishing and subscribing
        to event Channel `+chanIdx+`. This also includes the type, namely how many publishers
        and subscriber this channel supports. To add a publisher or subscriber, select this
        channel in the module which is generating an event, the name of the module will appear
        here afterwards.`,
        config: [
            {
                name: "channel"+chanIdx+"Pub",
                displayName: "Channel "+chanIdx+" Publisher",
                default: [""],
                options: (inst) => publishOptions(inst, chanIdx),
                getValue: (inst) => publishGetValue(inst, chanIdx)
            },
            {
                name: "channel"+chanIdx+"Sub",
                displayName: "Channel "+chanIdx+" Subscriber",
                default: [""],
                options: (inst) => subscribeOptions(inst, chanIdx),
                getValue: (inst) => subscribeGetValue(inst, chanIdx)
            },
            {
                name: "channel"+chanIdx+"Type",
                displayName: "Channel "+chanIdx+" Type",
                default: desc,
                readOnly: true
            }
        ]
    }
    masterConfig.push(channel);
}


function getAllPublishers() {
    /* create empty array of the channels */
    let publisherList = [];
    publisherList.length = MAX_NUM_EVENT_CHANNELS;

    /* fill method does not create separate copies of the array */
    for(let idx = 0; idx < publisherList.length; idx++){
        publisherList[idx] = [];
    }
    let chanIdx;
    for(let moduleName in system.modules){
        let mod = system.modules[moduleName];
        for(let instance in mod.$instances){
            let inst = mod.$instances[instance];
            if(inst.eventInfo != ""){
                /* parse event information */
                for(let infoIdx in inst.eventInfo){
                    let info = inst.eventInfo[infoIdx];
                    chanIdx = parseInt(info);
                    if(info.endsWith("pub")){
                        let pubSingle = publisherList[chanIdx];
                        if(pubSingle){
                            pubSingle.push(inst.$name);
                        }
                    }
                }
            }
        }
        if(mod.moduleStatic){
            let stat = mod.$static;
            if(stat.eventInfo != ""){
                /* parse event information */
                for(let infoIdx in stat.eventInfo){
                    let info = stat.eventInfo[infoIdx];
                    chanIdx = parseInt(info);
                    if(info.endsWith("pub")){
                        let pubSingle = publisherList[chanIdx];
                        if(pubSingle){
                            pubSingle.push((stat.$name).replace("/ti/driverlib/",""));
                        }
                    }
                }
            }
        }
    }
    return publisherList;
}

function getAllSubscribers() {
    /* create empty array of the channels */
    let subscriberList = [];
    subscriberList.length = MAX_NUM_EVENT_CHANNELS;

    /* fill method does not create separate copies of the array */
    for(let idx = 0; idx < subscriberList.length; idx++){
        subscriberList[idx] = [];
    }
    let chanIdx;
    for(let moduleName in system.modules){
        let mod = system.modules[moduleName];
        for(let instance in mod.$instances){
            let inst = mod.$instances[instance];
            if(inst.eventInfo!= ""){
                /* parse event information */
                for(let infoIdx in inst.eventInfo){
                    let info = inst.eventInfo[infoIdx];
                    chanIdx = parseInt(info);
                    if(info.endsWith("sub")){
                        let subSingle = subscriberList[chanIdx];
                        if(subSingle){
                            subSingle.push(inst.$name);
                        }
                    }
                }
            }
        }
        if(mod.moduleStatic){
            let stat = mod.$static;
            if(stat.eventInfo!= ""){
                /* parse event information */
                for(let infoIdx in stat.eventInfo){
                    let info = stat.eventInfo[infoIdx];
                    chanIdx = parseInt(info);
                    if(info.endsWith("sub")){
                        let subSingle = subscriberList[chanIdx];
                        if(subSingle){
                            subSingle.push((stat.$name).replace("/ti/driverlib/",""));
                        }
                    }
                }
            }
        }
    }
    return subscriberList;
}

function getPublisherOptions(inst){
    let options = [
        { name: 0, displayName: "Disabled (0)"}
    ];
    let publishers = getAllPublishers();
    let subscribers = getAllSubscribers();
    let dispStr;
    for(let chanIdx = 1; chanIdx < MAX_NUM_EVENT_CHANNELS; chanIdx++){
        let pub = publishers[chanIdx];
        let sub = subscribers[chanIdx];
        if(pub.length > 0){
            dispStr = chanIdx.toString() + "- " + pub[0].toString();
            for(let i = 1; i < pub.length; i++){
                dispStr += " " + pub[i].toString();
            }

        } else {
            dispStr = chanIdx.toString();
        }
        if(sub.length > 0) {
            let i = 0;
            dispStr += " => ";
            while(i < sub.length) {
                dispStr += " " + sub[i].toString();
                i++;
            }
        }
        let channel = {
            name: chanIdx,
            displayName: dispStr
        }
        options.push(channel);
    }
    return options;
}

function getPublisherDisabledOptions(inst) {
    /* Look for channels that already have a publisher */
    let disOptions = [];
    let publishers = getAllPublishers();
    let subscribers = getAllSubscribers();
    let dispStr;
    for(let chanIdx = 1; chanIdx < MAX_NUM_EVENT_CHANNELS; chanIdx++){
        let pub = publishers[chanIdx];
        let sub = subscribers[chanIdx];
        let channelHere = inst.eventInfo.includes(chanIdx+"pub");
        if(pub.length > 0 && !channelHere){
            /* in this case a publisher is present IN ANOTHER MODULE
             * and the channel should be disabled. */
            dispStr = chanIdx.toString() + "- " + pub[0].toString();
            for(let i = 1; i < pub.length; i++){
                dispStr += " " + pub[i].toString();
            }
            if(sub.length > 0) {
                let i = 0;
                dispStr += " => ";
                while(i < sub.length) {
                    dispStr += " " + sub[i].toString();
                    i++;
                }
            }
            let channel = {
                name: chanIdx,
                displayName: dispStr,
                reason: "publisher ports on this channel are full"
            }
            disOptions.push(channel);
        }

    }
    return disOptions;
}

function getSubscriberOptions(inst){
    let options = [
        { name: 0, displayName: "Disabled (0)"}
    ];
    let publishers = getAllPublishers();
    let subscribers = getAllSubscribers();
    let dispStr;
    for(let chanIdx = 1; chanIdx < MAX_NUM_EVENT_CHANNELS; chanIdx++){
        let pub = publishers[chanIdx];
        let sub = subscribers[chanIdx];
        if(pub.length > 0){
            dispStr = chanIdx.toString() + "- " + pub[0].toString();
            for(let i = 1; i < pub.length; i++){
                dispStr += " " + pub[i].toString();
            }

        } else {
            dispStr = chanIdx.toString();
        }
        if(sub.length > 0) {
            let i = 0;
            dispStr += " => ";
            while(i < sub.length) {
                dispStr += " " + sub[i].toString();
                if(i<sub.length-1){dispStr+=","};
                i++;
            }
        }
        let channel = {
            name: chanIdx,
            displayName: dispStr
        }
        options.push(channel);
    }
    return options;
}

function getSubscriberDisabledOptions(inst) {
        /* Look for channels that already have a publisher */
        let disOptions = [];
        let publishers = getAllPublishers();
        let subscribers = getAllSubscribers();
        let dispStr;
        for(let chanIdx = 1; chanIdx < MAX_NUM_EVENT_CHANNELS; chanIdx++){
            let pub = publishers[chanIdx];
            let sub = subscribers[chanIdx];
            let channelHere = inst.eventInfo.includes(chanIdx+"sub");
            let subPorts = parseInt(system.modules["/ti/driverlib/EVENT"].$static["channel"+chanIdx+"Type"][2]);
            if(sub.length >= subPorts && !channelHere){
                /* in this case the max number of subscribers
                 * is present IN ANOTHER MODULE and the channel
                 * should be disabled for selection */
                if(pub.length > 0){
                    dispStr = chanIdx.toString() + "- " + pub[0].toString();
                    for(let i = 1; i < pub.length; i++){
                        dispStr += " " + pub[i].toString();
                    }
                } else {
                    dispStr = chanIdx.toString();
                }
                if(sub.length > 0) {
                    let i = 0;
                    dispStr += " => ";
                    while(i < sub.length) {
                        dispStr += " " + sub[i].toString();
                        i++;
                    }
                }
                let channel = {
                    name: chanIdx,
                    displayName: dispStr,
                    reason: "subscriber ports on this channel are full"
                }
                disOptions.push(channel);
            }

        }
        return disOptions;
}

function validateSubscriberOptions(inst,validation,configName){
    try{
        if(!Object.keys(getSubscriberOptions(inst)).includes(inst[configName].toString())){
            validation.logError("Please select a valid event option",inst,configName);
        }
    }catch (e) {
        return false;
    }
}

function validatePublisherOptions(inst,validation,configName){
    try{
        if(!Object.keys(getPublisherOptions(inst)).includes(inst[configName].toString())){
            validation.logError("Please select a valid event option",inst,configName);
        }
    }catch (e) {
        return false;
    }
}

/*
 *  ======== base ========
 *  Define the base SYSCTL properties and methods
 */
let base = {
    displayName: "EVENT",
    description: "Event Module, logs all event channels as well as publishers and subscribers on that channel",
    longDescription: `This event module contains channels and their corresponding publishers and subscribers`,

    defaultInstanceName: "EVENT",
    initPriority: 0,
    uiAdd: "staticOnly",


    /* Supporting External functions */
    getPublisherOptions: getPublisherOptions,
    getPublisherDisabledOptions: getPublisherDisabledOptions,
    getSubscriberOptions: getSubscriberOptions,
    getSubscriberDisabledOptions: getSubscriberDisabledOptions,
    validateSubscriberOptions: validateSubscriberOptions,
    validatePublisherOptions: validatePublisherOptions,


    moduleStatic: {
        config: masterConfig,
        validate: validate,
        modules:             Common.autoForceModules(["Board"]),

    },

    templates: {
        "/ti/driverlib/templates/EVENT.dot.xdt" : true
    }
    //_getPinResources: _getPinResources
};

exports = base;
