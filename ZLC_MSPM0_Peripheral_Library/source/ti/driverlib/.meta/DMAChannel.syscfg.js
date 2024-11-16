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
 *  ======== DMAChannel.syscfg.js ========
 */
"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");
/* Determine channe availability depending on device */
let dmaInstances = 0;
let dmaFullInstances = 0;
if(Common.isDeviceM0G()){
    dmaInstances = 7;
    dmaFullInstances = 3;
}
else if(Common.isDeviceFamily_PARENT_MSPM0L11XX_L13XX()){
    dmaInstances = 3;
    dmaFullInstances = 1;
}
else if(Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()){
    dmaInstances = 7;
    dmaFullInstances = 3;
}
else if(Common.isDeviceM0C()){
    dmaInstances = 1;
    dmaFullInstances = 0;
}

/*
 *
 */
function validate(inst, validation){

    // make sure that the trigger select is valid:
    let mapping = require('./dma/DMA_TriggerMapping');
    // make sure that the inputted value is valid:
    let found = Object.keys(mapping.dma_triggers).includes(inst.triggerSelect);
    if(!found) {
       validation.logError("Invalid Option, please reselect", inst, "triggerSelect");
    }



    if(inst.hideTriggerSelect && inst.triggerType == "INTERNAL"){
        validation.logError("Internal Trigger Mode is not available for this configuration", inst, ["triggerType"])
    }

    // validate based on the interrupt priority value returned by owner
    if(inst.interruptPriority !== "DEFAULT"){
        let mod = system.modules["/ti/driverlib/DMA"];
        if(mod && mod.$static){
            let maxPri = parseInt(mod.$static.mostSevereInterruptPriority);
            if(maxPri < parseInt(inst.interruptPriority)){
                let warnStr = "Another DMA channel has a higher priority within the same interrupt group. Thus, this priority is supercedeed and unused. The current highest DMA channel priority is ";
                validation.logWarning(warnStr + maxPri, inst, "interruptPriority")
            }
        }
    }

    // EVENT Validation
    let mod = system.modules["/ti/driverlib/DMA"];
    if(mod && mod.$static){
        if((inst.triggerSelect == "FSUB_0") && !(mod.$static.subscriberIndex.includes("0"))){
            validation.logWarning("Subscriber Index 0 is not enabled in DMA global configuration", inst, ["triggerSelect"]);
        }
        if((inst.triggerSelect == "FSUB_1") && !(mod.$static.subscriberIndex.includes("1"))){
            validation.logWarning("Subscriber Index 1 is not enabled in DMA global configuration", inst, ["triggerSelect"]);
        }
        if(inst.enabledEvents.length>0){
            if(mod.$static.pubChanID == 0){
                validation.logError("Publisher Channel must be enabled to configure events", inst, ["enabledEvents"]);
            }
        }
    }
}

function validatePinmux(inst, validation){
    // FULL CHANNEL VALIDATION
    if(inst.channelID>(dmaFullInstances-1)){
        if(["FULL_CH_REPEAT_BLOCK","FULL_CH_REPEAT_SINGLE"].includes(inst.transferMode)){
            validation.logError("Repeat Mode only available on Full DMA Channels.", inst, ["transferMode", "channelID"]);
        }
        if(["fill","table"].includes(inst.addressMode)){
            validation.logError("Selected Address Mode only available on Full DMA Channels.", inst, ["addressMode", "channelID"]);
        }
        if(inst.enableEarlyInterrupt){
            validation.logError("Early IRQ only available on Full DMA Channels.", inst, ["enableEarlyInterrupt", "channelID"]);
        }
        // EVENT Validation
        if(inst.enabledEvents.includes("FULL_CH_EVENT_EARLY_CHANNEL")){
            validation.logError("Early IRQ Event only available on Full DMA Channels.", inst, ["enabledEvents", "channelID"]);
        }
    }
    else{
        validation.logInfo("Currently using a Full Channel.", inst, ["channelID"])
    }

    // Cascading Trigger Validation
    if(inst.triggerType == "INTERNAL"){
        if(inst.triggerSelectInternal >= dmaInstances){
            validation.logError("Please select a valid trigger", inst, ["triggerSelectInternal"]);
        }

        if(system.modules["/ti/driverlib/DMA"].$static["chan"+inst.triggerSelectInternal+"Parent"] == "Channel not configured"){
            validation.logError("Please select a valid trigger, selected DMA trigger is not configured.", inst, ["triggerSelectInternal"]);
        }
    }
}

function pinmuxRequirements(inst) {
    let dmaChan = {
        name          : "peripheral",
        displayName   : "DMA Channel",
        interfaceName : "DMA_CHANNEL",
        resources     : [],
        signalTypes   : {

        }
    };
    return [dmaChan];
}


function onChangeAddressMode(inst, ui) {
    switch(inst.addressMode){
        case "f2f":
            ui.transferMode.hidden = false;
            ui.transferMode.readOnly = false;
            ui.configureTransferSize.hidden = false;
            ui.transferSize.hidden = !inst.configureTransferSize;
            ui.srcLength.readOnly = false;
            ui.srcIncDec.hidden = true;
            ui.dstLength.readOnly = false;
            ui.dstIncDec.hidden = true;
            ui.fillIncrement.hidden = true;
            ui.fillIncAmount.hidden = true;
            ui.tableSize.hidden = true;
            ui.tableSrcAddressInc.hidden = true;
            break;
        case "f2b":
            ui.transferMode.hidden = false;
            ui.transferMode.readOnly = false;
            ui.configureTransferSize.hidden = false;
            ui.transferSize.hidden = !inst.configureTransferSize;
            ui.srcLength.readOnly = false;
            ui.srcIncDec.hidden = true;
            ui.dstLength.readOnly = false;
            ui.dstIncDec.hidden = false;
            ui.fillIncrement.hidden = true;
            ui.fillIncAmount.hidden = true;
            ui.tableSize.hidden = true;
            ui.tableSrcAddressInc.hidden = true;
            break;
        case "b2f":
            ui.transferMode.hidden = false;
            ui.transferMode.readOnly = false;
            ui.configureTransferSize.hidden = false;
            ui.transferSize.hidden = !inst.configureTransferSize;
            ui.srcLength.readOnly = false;
            ui.srcIncDec.hidden = false;
            ui.dstLength.readOnly = false;
            ui.dstIncDec.hidden = true;
            ui.fillIncrement.hidden = true;
            ui.fillIncAmount.hidden = true;
            ui.tableSize.hidden = true;
            ui.tableSrcAddressInc.hidden = true;
            break;
        case "b2b":
            ui.transferMode.hidden = false;
            ui.transferMode.readOnly = false;
            ui.configureTransferSize.hidden = false;
            ui.transferSize.hidden = !inst.configureTransferSize;
            ui.srcLength.readOnly = false;
            ui.srcIncDec.hidden = false;
            ui.dstLength.readOnly = false;
            ui.dstIncDec.hidden = false;
            ui.fillIncrement.hidden = true;
            ui.fillIncAmount.hidden = true;
            ui.tableSize.hidden = true;
            ui.tableSrcAddressInc.hidden = true;
            break;
        case "fill":
            // also set transfer mode to block
            inst.transferMode = "SINGLE_BLOCK";
            ui.transferMode.readOnly = true;
            //ui.transferMode.hidden = true;
            ui.srcLength.readOnly = true;
            ui.srcIncDec.hidden = true;
            ui.dstLength.readOnly = false;
            ui.dstIncDec.hidden = false;
            ui.configureTransferSize.hidden = false;
            ui.transferSize.hidden = !inst.configureTransferSize;
            ui.fillIncrement.hidden = false;
            ui.fillIncAmount.hidden = false;
            ui.tableSize.hidden = true;
            ui.tableSrcAddressInc.hidden = true;
            break;
        case "table":
            inst.transferMode = "SINGLE_BLOCK";
            ui.transferMode.readOnly = true;
            //ui.transferMode.hidden = true;
            inst.srcLength = "LONG";
            inst.dstLength = "WORD";
            ui.srcLength.readOnly = true;
            ui.srcIncDec.hidden = true;
            ui.dstLength.readOnly = true;
            ui.dstIncDec.hidden = true;
            ui.configureTransferSize.hidden = true;
            ui.transferSize.hidden = true;
            ui.fillIncrement.hidden = true;
            ui.fillIncAmount.hidden = true;
            ui.tableSize.hidden = false;
            ui.tableSrcAddressInc.hidden = false;
            break;
        default:
            //throw 'onChangeAddressMode given incorrect inst';
            break;
    }
}

function triggerMap(inst) {
    let options = [];
    let mapping = require('./dma/DMA_TriggerMapping');
    for(let key of Object.keys(mapping.dma_triggers)) {
        options.push({name: key, displayName: key});
    }
    return options;
}

const triggerMapOptions = [
    {name: "0", displayName: "DMA Channel 0" },
    {name: "1", displayName: "DMA Channel 1" },
    {name: "2", displayName: "DMA Channel 2" },
    {name: "3", displayName: "DMA Channel 3" },
    {name: "4", displayName: "DMA Channel 4" },
    {name: "5", displayName: "DMA Channel 5" },
    {name: "6", displayName: "DMA Channel 6" },
    {name: "7", displayName: "DMA Channel 7" }
];

function onChangeTriggerSelect(inst, ui){
    let mapping = require('./dma/DMA_TriggerMapping');
    // make sure that the inputted value is valid:
    let found = Object.keys(mapping.dma_triggers).includes(inst.triggerSelect);
    if(!found){
        return; // inputted value not valid, let validation handle it
    }
    if((mapping.dma_triggers[inst.triggerSelect]).length>1){
        ui.triggerNumber.readOnly = false;
    }
    else{
        ui.triggerNumber.readOnly = true;
    }
    inst.triggerNumber = ""+mapping.dma_triggers[inst.triggerSelect][0];
}

function getTriggerNumberOptions(inst,ui){
    let options = [];
    let mapping = require('./dma/DMA_TriggerMapping');
    // make sure that the inputted value is valid:
    let found = Object.keys(mapping.dma_triggers).includes(inst.triggerSelect);
    if(!found){
        return []; // inputted value not valid, let validation handle it
    }
    // inst.triggerNumber = mapping.dma_triggers[inst.triggerSelect];
    for(let key of mapping.dma_triggers[inst.triggerSelect]) {
        options.push({name: ""+key, displayName: ""+key});
    }
    return options;
}



/*
function triggerMapNumber(inst) {
    let options = [];
    let mapping = require('./MSPM0G350X_TriggerMapping');
    for(let key of Object.keys(mapping.dma_triggers)) {
        options.push({name: mapping.dma_triggers[key]});
    }
    return options;
}
*/

const eventOptions = [
    // DL_DMA_[...]
    {name: "EVENT_CHANNEL", displayName: "DMA channel interrupt"},
    {name: "FULL_CH_EVENT_EARLY_CHANNEL", displayName: "Early IRQ for DMA channel interrupt."},
]

let channelConfig = [
    {
        name: "$name",
        defaultPrefix: "DMA_CH",
        hidden: false
    },
    {   /* To possibly be replaced with peripheral channels */
        name: "channelID",
        displayName: "Channel ID",
        description: "Unique Channel Identification",
        longDescription: `
Specific Channel Identification number from 0-`+(dmaInstances-1).toString()+` that corresponds to the actual
channel hardware used by the module. This number must be unique and is defined by the Channel determined in
the Pinmux Section.
        `,
        default: 0,
        getValue: (inst) => {
            if(!_.isUndefined(inst.peripheral.$solution) && inst.peripheral.$solution.error == ""){
                // valid solution without error, parse should be successful
                let val = parseInt(inst.peripheral.$solution.peripheralName.slice(-1));
                if(!_.isInteger(val)){
                    throw "val not an integer?" + val.toString();
                } else {
                    return val;
                }
            } else {
                return 0;
            }
        }
    },
    {
        name: "triggerType",
        displayName: "Trigger Type",
        longDescription: `
Whether an internal or external DMA channel is
selected as the DMA trigger. Refer to the datasheet
for more information on the DMA channels.` ,
        default: "EXTERNAL",
        options: [
            // DL_DMA_TRIGGER_TYPE_[...]
            {name: "INTERNAL", displayName: "Internal DMA channel"},
            {name: "EXTERNAL", displayName: "External DMA channel"},
        ],
        onChange: (inst,ui) => {
            ui.triggerSelect.hidden = (inst.triggerType == "INTERNAL");
            ui.triggerNumber.hidden = (inst.triggerType == "INTERNAL");
            ui.triggerSelectInternal.hidden = !(inst.triggerType == "INTERNAL");
        }
    },
    {
        name: "triggerSelect",
        displayName: "Trigger Select",
        description: "Device-Specific Triggers that can be selected",
        longDescription: ``,
        default: "SW", /* default is SW? */
        hidden: false,
        options: triggerMap,
        onChange: onChangeTriggerSelect
    },
    {
        name: "triggerSelectInternal",
        displayName: "Trigger Select",
        description: "Device-Specific Triggers that can be selected",
        longDescription: ``,
        default: "0",
        hidden: true,
        options: triggerMapOptions.slice(0, dmaInstances),
    },
    {
        name: "hideTriggerSelect",
        longDescription: `
If the module is owned by another module, the trigger source is dictated by the
owning module's peripheral, which is retrieved at code generation (since at this
point we don't have an active solution and cannot reliably pass a peripheral).
Since trigger select is not necessary, we will hide it by passing true to this
hidden configurable
        `,
        default: false,
        hidden: true,
        onChange: (inst, ui) => {
            ui.triggerSelect.hidden = inst.hideTriggerSelect || (inst.triggerType == "INTERNAL");
            ui.triggerNumber.hidden = inst.hideTriggerSelect || (inst.triggerType == "INTERNAL");
            ui.triggerSelectInternal.hidden = inst.hideTriggerSelect || !(inst.triggerType == "INTERNAL");
            ui.triggerType.hidden = inst.hideTriggerSelect;
        }
    },
    {
        name: "passedTriggerSelect",
        longDescription: ``,
        default: 0,
        hidden: true,
        // readOnly: true,
    },
    {
        name: "triggerNumber",
        displayName: "Trigger Number",
        description: "Specific Trigger Number related to the trigger value",
        default: "DMA_SOFTWARE_TRIG",
        hidden: false,
        readOnly: true,
        options: getTriggerNumberOptions,
    },
    {
        name: "addressMode",
        displayName: "Address Mode",
        description: "Determines the addressing mode used for the specific DMA channel",
        longDescription: `
The addressing modes allow for different addressing modes

* Fill Mode (extended mode) - in fill mode, the DMA controller takes a predefined pattern
and writes the pattern to a user defined segment of memory.
* Table Mode (extended mode) - the DMA controller executes two reads from teh source and
one write to a determined destination. This feature can be leveraged to interpret a table
of addresses and data and uses the DMA to efficiently program that data to their associated
addresses without CPU intervention
        `,
        default: "f2f",
        options: [
            {name: "f2f", displayName: "Fixed addr. to Fixed addr."},
            {name: "f2b", displayName: "Fixed addr. to Block addr."},
            {name: "b2f", displayName: "Block addr. to Fixed addr."},
            {name: "b2b", displayName: "Block addr. to Block addr."},
            {name: "fill", displayName: "Fill Data Extended Mode"},
            {name: "table", displayName: "Data Table Extended Mode"}
        ],
        onChange: onChangeAddressMode
    },
    {
        name: "srcLength",
        displayName: "Source Length",
        description: "The size of the source transfer",
        longDescription: `
The size of the source transfer determines the size of the data transfer from the source
side to the destination, as well as the increment on each transfer if configured as a block.
\nIt is possible for an uneven transfer size to be configured. If the source is larger than the
destination, only the lower portion of the short word will be transferred, and the upper portion
is ignored. If the destination is larger, the upper portion source is zero-padded in order to fill
the entire segment.
\n**NOTE: Source Length is not used by the Fill Address Mode**
        `,
        default: "WORD",
        options: [
            {name: "BYTE", displayName: "Byte"},
            {name: "HALF_WORD", displayName: "Half Word (2 Bytes)"},
            {name: "WORD", displayName: "Word (4 Bytes)"},
            {name: "LONG", displayName: "Long (8 Bytes)"}
        ]
    },
    {
        name: "srcIncDec",
        displayName: "Source Address Direction",
        description: "Block Address Increment/Decrement Direction",
        longDescription: `
If the Source Is configured as a Block, then the source address will increment or decrement the given address
in DMASAx by the amount given in Source Length. This configures the direction of that amount.`,
        default: "INCREMENT",
        options: [
            {name: "INCREMENT", displayName: "Increment"},
            {name: "DECREMENT", displayName: "Decrement"},
            {name: "UNCHANGED", displayName: "Unchanged"},
        ],
        hidden: true

    },
    {
        name: "dstLength",
        displayName: "Destination Length",
        description: "The size of the destination transfer",
        longDescription: `
The size of the destination transfer determines the size of the data transfer from the source
side to the destination, as well as the increment on each transfer if configured as a block.
\nIt is possible for an uneven transfer size to be configured. If the source is larger than the
destination, only the lower portion of the short word will be transferred, and the upper portion
is ignored. If the destination is larger, the upper portion source is zero-padded in order to fill
the entire segment.
        `,
        default: "WORD",
        options: [
            {name: "BYTE", displayName: "Byte"},
            {name: "HALF_WORD", displayName: "Half Word (2 Bytes)"},
            {name: "WORD", displayName: "Word (4 Bytes)"},
            {name: "LONG", displayName: "Long (8 Bytes)"}
        ]
    },
    {
        name: "dstIncDec",
        displayName: "Destination Address Direction",
        description: "Block Address Increment/Decrement Direction",
        longDescription: `
If the Destination Is configured as a Block, then the destination address will increment or decrement the given address
in DMADAx by the amount given in Destination Length. This configures the direction of that amount.`,
        default: "INCREMENT",
        options: [
            {name: "INCREMENT", displayName: "Increment"},
            {name: "DECREMENT", displayName: "Decrement"},
            {name: "UNCHANGED", displayName: "Unchanged"},
        ],
        hidden: true
    },
    {
        name: "FILL_MODE_GROUP",
        displayName: "Fill Mode Parameters",
        collapsed: false,
        config: [
            {
                name: "fillIncrement",
                displayName: "Fill Increment",
                description: "Option to increment/decrement the fill pattern",
                default: "UNCHANGED",
                options: [
                    {name: "UNCHANGED", displayName: "Unchanged"},
                    {name: "DECREMENT", displayName: "Decrement"},
                    {name: "INCREMENT", displayName: "Increment"}
                ],
                hidden: true,
            },
            {
                name: "fillIncAmount",
                displayName: "Increment Amount",
                description: "Amount to increment or decrement",
                longDescription: ``,
                default: "WORD",
                options: [
                    {name: "BYTE", displayName: "1"},
                    {name: "HALF_WORD", displayName: "2"},
                    {name: "WORD", displayName: "4"},
                    {name: "LONG", displayName: "8"}
                ],
                hidden: true
            }
        ],
    },
    {
        name: "TABLE_MODE_GROUP",
        displayName: "Table Mode Parameters",
        longDescription: ``,
        collapsed: false,
        config: [
            {
                name: "tableSize",
                displayName: "Table Size",
                default: 20,
                isInteger: true,
                range: [0, 65535], /* 0 to 0xFFFF */
                hidden: true
            },
            {
                name: "tableSrcAddressInc",
                displayName: "Source Address Increment",
                description: "Option to increment/decrement the source address after a transfer",
                longDescription: `
After reading the source address from the table and writing the data to that place in memory, the source
address can be subsequently incremented or decremented to write to the next Word (4-byte) address on a future
transfer.
                `,
                default: "UNCHANGED",
                options: [
                    {name: "UNCHANGED", displayName: "Unchanged"},
                    {name: "DECREMENT", displayName: "Decremented"},
                    {name: "INCREMENT", displayName: "Incremented"}
                ],
                hidden: true

            }
        ],
    },
    {
        name: "configureTransferSize",
        displayName: "Configure Transfer Size",
        default: false,
        onChange: (inst,ui)=>{
            ui.transferSize.hidden = !inst.configureTransferSize;
        }
    },
    {
        name: "transferSize",
        displayName: "Transfer Size",
        hidden: true,
        description: "Transfer Size parameter with different functions depending on Transfer Mode",
        longDescription: `
The Transfer Size is used in tandem with **Transfer Mode** to determine the number of single transfers
expected or the size of a transfer block.
        `,
        default: 1,
        isInteger: true,
        range: [0, 65535] /* 0 to 0xFFFF */

    },
    {
        name: "transferMode",
        displayName: "Transfer Mode",
        default: "SINGLE",
        description: "Transfer Mode for the specific DMA Channel",
        longDescription: `
The transfer modes are selectable by channel and determines how bytes will be transferred
from source to destination. The four modes are:
* Single Transfer - Each transfer requires a trigger, and the DMA is disabled after the number
of transfers set by **Transfer Size** has been made.
* Block Transfer - A complete block of size **Transfer Size** is transferred with one trigger. the DMA is disabled at the
end of each transfer.
* Repeated Single Transfer - Each transfer requires a trigger and the DMA remains enabled after all have been made.
* Repeated Block Transfer - A complete block of size **Transfer Size** is transferred with one trigger
and the DMA remains enabled.
        `,
        options: [
            {name: "SINGLE", displayName: "Single"},
            {name: "SINGLE_BLOCK", displayName: "Block"},
            {name: "FULL_CH_REPEAT_SINGLE", displayName: "Repeat Single"},
            {name: "FULL_CH_REPEAT_BLOCK", displayName: "Repeat Block"}
        ]
    },
    // DL_DMA_setSrcIncrement
    {
        name: "srcIncrement",
        displayName: "Source Address Increment",
        default: "UNCHANGED",
        description: "Set a channel's source address increment amount",
        longDescription: `
After each DMA transfer the channel source address can be incremented,
decremented or remain unchanged. This controls if the DMA is copying from a
fixed address or a block of addresses.

The amount that is incremented/decremented is controlled by the Source Length.

The increment options are:
* Do not change address after each transfer
* **Decrement:** Decrement address by 1 * Source Length after each transfer
* **Increment:** Increment address by 1 * Source Length after each transfer
* **Stride Mode 2:** Increment address by 2 * Source Length (skip over every other element)
* **Stride Mode 3:** Increment address by 3 * Source Length (skip over two elements)
* **Stride Mode 4:** Increment address by 4 * Source Length (skip over three elements)
* **Stride Mode 5:** Increment address by 5 * Source Length (skip over four elements)
* **Stride Mode 6:** Increment address by 6 * Source Length (skip over five elements)
* **Stride Mode 7:** Increment address by 7 * Source Length (skip over six elements)
* **Stride Mode 8:** Increment address by 8 * Source Length (skip over seven elements)
* **Stride Mode 9:** Increment address by 9 * Source Length (skip over eight elements)
        `,
        options: [
            // DL_DMA_INCREMENT: DL_DMA_ADDR_[...]
            {name: "UNCHANGED", displayName: "Do not change address after each transfer"},
            {name: "DECREMENT", displayName: "Decrement"},
            {name: "INCREMENT", displayName: "Increment"},
            {name: "STRIDE_2", displayName: "Stride Mode 2"},
            {name: "STRIDE_3", displayName: "Stride Mode 3"},
            {name: "STRIDE_4", displayName: "Stride Mode 4"},
            {name: "STRIDE_5", displayName: "Stride Mode 5"},
            {name: "STRIDE_6", displayName: "Stride Mode 6"},
            {name: "STRIDE_7", displayName: "Stride Mode 7"},
            {name: "STRIDE_8", displayName: "Stride Mode 8"},
            {name: "STRIDE_9", displayName: "Stride Mode 9"},
        ]
    },
    // DL_DMA_setDestIncrement
    {
        name: "destIncrement",
        displayName: "Destination Address Increment",
        default: "UNCHANGED",
        description: "Set a channel's destination address increment amount",
        longDescription: `
After each DMA transfer the channel destination address can be incremented,
decremented or remain unchanged. This controls if the DMA is copying from a
fixed address or a block of addresses.

The amount that is incremented/decremented is controlled by the Destination Length.

The increment options are:
* Do not change address after each transfer
* **Decrement:** Decrement address by 1 * Destination Length after each transfer
* **Increment:** Increment address by 1 * Destination Length after each transfer
* **Stride Mode 2:** Increment address by 2 * Destination Length (skip over every other element)
* **Stride Mode 3:** Increment address by 3 * Destination Length (skip over two elements)
* **Stride Mode 4:** Increment address by 4 * Destination Length (skip over three elements)
* **Stride Mode 5:** Increment address by 5 * Destination Length (skip over four elements)
* **Stride Mode 6:** Increment address by 6 * Destination Length (skip over five elements)
* **Stride Mode 7:** Increment address by 7 * Destination Length (skip over six elements)
* **Stride Mode 8:** Increment address by 8 * Destination Length (skip over seven elements)
* **Stride Mode 9:** Increment address by 9 * Destination Length (skip over eight elements)
        `,
        options: [
            // DL_DMA_INCREMENT: DL_DMA_ADDR_[...]
            {name: "UNCHANGED", displayName: "Do not change address after each transfer"},
            {name: "DECREMENT", displayName: "Decrement"},
            {name: "INCREMENT", displayName: "Increment"},
            {name: "STRIDE_2", displayName: "Stride Mode 2"},
            {name: "STRIDE_3", displayName: "Stride Mode 3"},
            {name: "STRIDE_4", displayName: "Stride Mode 4"},
            {name: "STRIDE_5", displayName: "Stride Mode 5"},
            {name: "STRIDE_6", displayName: "Stride Mode 6"},
            {name: "STRIDE_7", displayName: "Stride Mode 7"},
            {name: "STRIDE_8", displayName: "Stride Mode 8"},
            {name: "STRIDE_9", displayName: "Stride Mode 9"},
        ]
    },
    {
        name: "INTERRUPT_GROUP",
        displayName: "Interrupt Configuration",
        collapsed: false,
        config: [
            {
                name: "enableInterrupt",
                displayName: "Enable Channel Interrupt",
                description: "Generates Interrupt when transfer size (DMASZ) is set to 0",
                longDescription: `
    Each DMA Channel has its own RIS flag. Each RIS flag is set in any mode when the corresponding
    DMASZx register (size of transaction) counts to zero. If the interrupt is enabled, an interrupt
    request is generated.
    \nAll RIS flags are prioritized, with DMA0 being the highest. The highest priority pending interrupt
    sets a value in the IIDX register. Any access of the IIDX register will clear the highest priority
    pending interrupt only.
    \nAddressing Modes and Interrupt Generation:
    * Single Transfer (normal or repeated): When transfer number is reached.
    * Block Transfer (normal or repeated): When an entire block is transferred.
    * Fill Mode: When the full block has been filled with the pattern.
    * Table Mode: When all entr ies in the table have been transferred.
                `,
                default: false,
                onChange: (inst, ui) => {
                    ui.interruptPriority.hidden = !inst.enableInterrupt;
                }
            },
            {
                name: "enableEarlyInterrupt",
                displayName: "Enable Early Channel Interrupt",
                description: "Early IRQ for DMA channel interrupt.",
                longDescription: `
Available for FULL-channel only. Early IRQ for DMA channel interrupt. Size counter has reached early IRQ threshold.
                `,
                default: false,
                onChange: (inst, ui) => {
                    ui.interruptPriority.hidden = !inst.enableInterrupt;
                    ui.earlyIntThresh.hidden = !inst.enableEarlyInterrupt;
                }
            },
            // DL_DMA_Full_Ch_setEarlyInterruptThreshold
            {
                name: "earlyIntThresh",
                displayName: "Early Channel Interrupt Threshold",
                description: "When to generate the early interrupt.",
                longDescription: `
Select to generate Early-IRQ event when DMASZ reaches the specified point of the
original transfer size
                `,
                hidden: true,
                default: "DISABLED",
                options: [
                    {name: "DISABLED", displayName: "Disable early interrupt events"},
                    {name: "1", displayName: "1 transfer pending"},
                    {name: "2", displayName: "2 transfers pending"},
                    {name: "4", displayName: "4 transfers pending"},
                    {name: "8", displayName: "8 transfers pending"},
                    {name: "32", displayName: "32 transfers pending"},
                    {name: "64", displayName: "64 transfers pending"},
                    {name: "HALF", displayName: "Half point of transfer size"},
                ],
            },
            {
                name: "interruptPriority",
                displayName: "Interrupt Priority",
                description: "Specifies interrupt priority",
                longDescription: '',
                hidden: true,
                default: "DEFAULT",
                options: Common.InterruptPriorityOptions,
            },
        ]
    },
    {
        name: "eventConfig",
        displayName: "Channel Event Configuration",
        longDescription: `Specifies the DMA Events that are to trigger an Event Condition and where the events are to be published`,
        collapsed: true,
        config: [
            /* DL_DMA_enableEvent / DL_DMA_disableEvent */
            {
                name        : "enabledEvents",
                displayName : "Enable Events",
                description : '',
                hidden      : false,
                default     : [],
                minSelections: 0,
                options     : eventOptions,
            },
        ]
    },
];
let base = {
    name: "DMAChannel",
    displayName: "DMA",
    longDescription: `
The **DMA module** allows you to transfer data from a source address to
a destination address without CPU intervention. Using the DMA controller
can increase the throughput of peripheral modules and can also reduce
power consumption by allowing the CPU to remain in a low-power mode.
Devices can have up to sixteen DMA channels available. Please refer to
the device-specific data sheet for the actual channel count of the DMA.

Users can select from six addressing modes:
1. Fixed address to fixed address
2. Fixed address to block of addresses
3. Block of addresses to fixed address
4. Block of addresses to block of addresses
5. Fill data to block of addresses
6. Data table to specific address

Users can also configure:
- Device-specific triggers
- Size of source transfer
- Size of destination transfer
- Transfer size / mode

The transfer modes are:
1. Single
2. Block
3. Repeat Single
4. Repeat Block

See the MSPM0 Technical Reference Manual for more information about DMA.
    `,
    config: channelConfig,
    pinmuxRequirements: pinmuxRequirements,
    validate: validate,
    validatePinmux: validatePinmux,
    modules: Common.autoForceModules(["Board", "SYSCTL"]),
//     templates: {
//         boardc: "/ti/driverlib/dma/DMA.Board.c.xdt",
//         boardh: "/ti/driverlib/dma/DMA.Board.h.xdt",
//         Call: true,
//         Reset: false,
//         Power: false,
//         GPIO: false,
//         Function: true
//     },
};

exports = base;
