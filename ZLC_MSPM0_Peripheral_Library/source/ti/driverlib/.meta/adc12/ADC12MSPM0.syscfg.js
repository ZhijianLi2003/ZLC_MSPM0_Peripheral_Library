/*
 * Copyright (c) 2018-2019 Texas Instruments Incorporated - http://www.ti.com
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
 *  ======== ADC12MSPM0.syscfg.js ========
 */

"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");
let EVENT = system.getScript("/ti/driverlib/EVENT.syscfg.js");
let InternalConnections = system.getScript("ADC12_internalConnections.js")

/* ADCMEM range varies per device family */
const adcMemRange = (Common.isDeviceM0G() || Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()) ? 11:3;


/*
 *  ======== _getPinResources ========
 */
function _getPinResources(inst)
{
    let pin;

    if (inst.module) {
        let modPin = "DIO" + inst.module.modulePin.$solution.devicePinName;
        modPin = modPin.match(/P\d+\.\d+/)[0];

        pin = "\nMODPIN: " + modPin;

        if (inst.$hardware && inst.$hardware.displayName) {
            pin += "\n" + inst.$hardware.displayName;
        }
    }

    return ("");
}

/*
 *  ======== isCNameOrNum ========
 *  Determine if specified id is either empty or a valid C identifier
 *
 *  @param id  - String that may/may not be a valid C identifier or number
 *
 *  @returns true if id is a valid C identifier, number OR is the empty
 *           string; otherwise false.
 */
function isCNameOrNum(id)
{
    if ((id != null && id.match(/^\w*$/) != null)
            || id == '') {
        return true;
    }
    return false;
}

/*
 *  ======== isAveragingEnabled ========
 *  Determine if Averaging is enabled for selected device
 *
 *  @returns true if averaging is enabled for selected device, false otherwise
 */
function isAveragingEnabled()
{
    return(Common.isDeviceM0G() || Common.isDeviceM0L() || Common.isDeviceM0C());
}

/*
 *  ======== validatePinmux ========
 *  Validate this inst's configuration
 *
 *  param inst       - module instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validatePinmux(inst, validation){
    if(Common.isDeviceFamily_PARENT_MSPM0G1X0X_G3X0X()){
        if(inst.peripheral.$solution.peripheralName == "ADC1"){
            if(isChannelSelected(inst,12) && !inst.disChan12){
                validation.logError(
                    "Channel 12 is an internal connection for the current configuration, requires disabling the pin resource",
                    inst, "disChan12"
                );
            }
        }else if(isChannelSelected(inst,12) && inst.disChan12){
            validation.logError(
                "Channel 12 pin is required to be enabled for current configuration",
                inst, "disChan12"
            );
        }
    }
    if(Common.isDeviceFamily_PARENT_MSPM0GX51X()){
        if(inst.peripheral.$solution.peripheralName == "ADC0"){
            if(isChannelSelected(inst,11) && !inst.disChan11){
                validation.logError(
                    "Channel 11 is an internal connection for the current configuration, requires disabling the pin resource",
                    inst, "disChan11"
                );
            }
        }else if(isChannelSelected(inst,11) && inst.disChan11){
            validation.logError(
                "Channel 11 pin is required to be enabled for current configuration",
                inst, "disChan11"
            );
        }
    }
}

/*
 *  ======== validate ========
 *  Validate this inst's configuration
 *
 *  param inst       - module instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validate(inst, validation)
{
    Common.validateNames(inst, validation);

    // Validate Sequence Start Address <= End Address
    if(inst.samplingOperationMode == "sequence"){
        if(inst.startAdd > inst.endAdd){
            validation.logError(
                "The Sequence Conversion starting address cannot be higher than the ending address",
                inst, "startAdd"
            );
            validation.logError(
                "The Sequence Conversion ending address cannot be lower than the ending address",
                inst, "endAdd"
            );
        }
    }

    let enabledWinComp = false;
    let enabledAvg = false;
    let adcMemNames = [];
    let adcMemNamesEnabled = [];
    /* Validation for each ADCMEM */
    for(let adcMemIdx = 0; adcMemIdx <= adcMemRange; adcMemIdx++){
        if( inst.enabledADCMems.includes(adcMemIdx) ) {
            /* Determines if window comparator enabled in any ADCMEM */
            if(inst["adcMem"+adcMemIdx.toString()+"wincomp"] == true){
                enabledWinComp = true;
            }
            /* Determines if HW Averaging enabled in any ADCMEM */
                if(inst["adcMem" + adcMemIdx.toString() + "avgen"] == true){
                    enabledAvg = true;
                }


            /* Checks if VREF module is added when voltage reference is internal */
            if((inst["adcMem"+adcMemIdx.toString()+"vref"])=="VREF"){
                /* External VREF validation */
                let vrefInstance = system.modules["/ti/driverlib/VREF"];
                if((inst["adcMem"+adcMemIdx.toString()+"vrefDependency"])=="DL_ADC12_REFERENCE_VOLTAGE_EXTREF"){
                    if(Common.isDeviceM0L()){
                        if(!vrefInstance.$static.basicMode.includes("DL_VREF_ENABLE_DISABLE")){
                            validation.logError(
                                "External Reference is not enabled in VREF module.",
                                inst, "adcMem"+adcMemIdx.toString()+"vrefDependencySelect"
                            );
                        }
                    }
                    if(inst.calcVoltage == "0V"){
                        validation.logWarning(
                            "External voltage source is 0V",
                            inst, "adcMem"+adcMemIdx.toString()+"calcVoltage"
                        );
                    }
                }
                /* Internal VREF validation */
                else if((inst["adcMem"+adcMemIdx.toString()+"vrefDependency"])=="DL_ADC12_REFERENCE_VOLTAGE_INTREF"){
                    if(Common.isDeviceM0L()){
                        if(!vrefInstance.$static.basicMode.includes("DL_VREF_ENABLE_ENABLE")){
                            validation.logError(
                                "Internal Reference is not enabled in VREF module.",
                                inst, "adcMem"+adcMemIdx.toString()+"vrefDependencySelect"
                            );
                        }
                    }
                }
            }
            /* Check that ADCMEM is a C identifier */
            if ((inst["adcMem"+adcMemIdx.toString()+"_name"]) != "") {
                let proposedName = inst["adcMem"+adcMemIdx.toString()+"_name"];
                adcMemNames.push(proposedName);
                if (!isCNameOrNum(proposedName)) {
                    validation.logError(
                        "'" + proposedName + "' is not a valid a C identifier",
                        inst, "adcMem"+adcMemIdx.toString()+"_name",
                    );
                }
                // TODO: validate empty name.
                if (!proposedName || proposedName.length === 0){
                    validation.logError(
                        "Cannot be empty.",
                        inst, "adcMem"+adcMemIdx.toString()+"_name",
                    );
                }
            }

            /* Keep track of which ADCMEM names to validate */
            adcMemNamesEnabled.push("adcMem"+adcMemIdx+"_name");
        }
    }
    /* Find duplicate ADCMEM names on instance */
    if(adcMemNames.length>0){
        let duplicatesResult = Common.findDuplicates(adcMemNames)
        if (duplicatesResult.duplicates.length != 0)
        {
            let allDuplicates = "";
            for (let duplicateName of duplicatesResult.duplicates)
            {
                allDuplicates = allDuplicates + Common.stringOrEmpty(allDuplicates, ", ")
                                + duplicateName;
            }
            validation.logError(
                "The ADCMEM name is used. Duplicates: " + allDuplicates,
                inst, adcMemNamesEnabled
            );
        }
    }
    /* Enabling Window Comparator settings without enabling for any ADCMEM has no effect */
    if ((inst.enableWinComp) && (!enabledWinComp)){
        validation.logWarning(
            "This selection has no effect unless Window Comparator Mode is enabled in any of the ADCMEMs",
            inst, ["configWinCompLowThld","configWinCompHighThld","enableWinComp"]
        );
    }
    /* HW Averaging Validation */
        /* Enabling HW Averaging settings without enabling for any ADCMEM has no effect */
        if ((inst.enableHWAverage) && (!enabledAvg)){
            validation.logWarning(
                "This selection has no effect unless Averaging Mode is enabled in any of the ADCMEMs",
                inst, ["hwNumerator","hwDenominator","enableHWAverage"]
            );
        }

    /* Make sure clocks are initialized properly */
    let sysctl = system.modules["/ti/driverlib/SYSCTL"].$static;

    if(inst.inputClock_Freq == 0)
    {
        let str = "";
        if(sysctl.clockTreeEn === true){
            str = "Clock Source " + (inst.sampClkSrc).slice(15) + " not properly initialized in Clock Tree";
        } else {
            str = "Clock Source " + (inst.sampClkSrc).slice(15) + " not properly initialized in SYSCTL";
        }
        validation.logError(str, inst, "sampClkSrc");
    }
    if(inst.sampClkSrc == "DL_ADC12_CLOCK_SYSOSC"){
        if(sysctl.clockTreeEn){
            let sysoscInst = _.find(system.modules["/ti/clockTree/oscillator.js"].$instances, ['$name','SYSOSC']);
            if(_.isUndefined(sysoscInst)){
                throw "SYSOSC instance not found in Clock Tree";
            } else {
                if(sysoscInst.disableSYSOSC){
                    validation.logError(
                        "Selected Clock Source not available, SYSOSC is disabled in Clock Tree.",
                        inst, "sampClkSrc"
                    );
                }
            }

        }
        else{
            if(system.modules["/ti/driverlib/SYSCTL"].$static.disableSYSOSC){
                validation.logError(
                    "Selected Clock Source not available, SYSOSC is disabled in SYSCTL.",
                    inst, "sampClkSrc"
                );
            }
        }

    }

    /* Validate unsupported configurations */
    if((inst.samplingOperationMode == "sequence")&&(inst.repeatMode)&&(!inst.enableFIFO)&&(inst.configureDMA)){
        validation.logError(
            "Unsupported configuration for DMA Read/Write. See TRM for supported ADC-DMA/CPU Operation Summary Matrix.",
            inst, ["configureDMA","enableFIFO","repeatMode","samplingOperationMode"]
        );
    }
    if((inst.samplingOperationMode == "single")&&(!inst.repeatMode)&&(inst.enableFIFO)){
        validation.logWarning(
            "Configuration not recommended for DMA Read/Write. See TRM for supported ADC-DMA/CPU Operation Summary Matrix.",
            inst, ["enableFIFO","repeatMode","samplingOperationMode"]
        );
    }

    /* Validate user does not select a disabled ADCMEM as start address */
    if( inst.samplingOperationMode === "single" && inst.enabledADCMems.length > 0 ){
        if( !inst.enabledADCMems.includes(inst.startAdd) ) {
            validation.logWarning(
                "Start address must be an enabled ADC Memory Conversion",
                inst, ["startAdd","enabledADCMems"]
            );
        }
    }

    /* Validate expected profile frequency */
    if(inst.chosenProfile == "singleChannel"){
        if(Common.isDeviceM0G()) {
            if(inst.sampleClk_Freq != 40000000) {
                validation.logWarning(
                    "Single-Channel Max Sampling requires ULPCLK to be configured for 40MHz",
                    inst, ["sampleClk_Freq_unit","chosenProfile"]
                );
            }
        } else {
            if(inst.sampleClk_Freq != 32000000) {
                validation.logWarning(
                    "Single-Channel Max Sampling requires ULPCLK to be configured for 32MHz",
                    inst, ["sampleClk_Freq_unit","chosenProfile"]
                );
            }
        }
    }
    else if(inst.chosenProfile == "lowJitter"){
        if(inst.sampleClk_Freq != 48000000){
            validation.logWarning(
                "Low Jitter DMA + Hardware Averaging requires HFCLK to be configured for 48MHz",
                inst, ["sampleClk_Freq_unit","chosenProfile"]
            );
        }
    }

    /* Check for maximum supported frequency */
    if(inst.sampClkFreqRange=="DL_ADC12_CLOCK_FREQ_RANGE_OUT_OF_RANGE"){
        validation.logError(
            "ADC12 maximum supported frequency is 48MHz",
            inst, ["sampleClk_Freq_unit"]
        );
    }

    if(inst.enableWinComp == true){
        for(let adcMemIdx=0; adcMemIdx<=adcMemRange; adcMemIdx++){
            var name = "adcMem" + adcMemIdx.toString() + "wincomp"
            if(inst[name] == true)
            {
                validation.logInfo(
                    "Window Comparator Enabled for ADC Conversion Memory " + adcMemIdx + " Configuration",
                    inst, name)
            }
        }

    }

    /* MSPM0C-specific validation */
    if(Common.isDeviceM0C()){
        /* Resolution Validation */
        if(inst.resolution == "DL_ADC12_SAMP_CONV_RES_12_BIT"){
            validation.logInfo(
                "Note: for MSPM00C, please refer to the device datasheet to review the reduction on linearity when using 12-bit resolution",
                inst, "resolution")
        }
    }

    /* Validate Event selection for case of switching devices.
     * Checks that selected event is withing the valid options
     * for current device.
     */
    EVENT.validatePublisherOptions(inst,validation,"pubChanID");
    EVENT.validateSubscriberOptions(inst,validation,"subChanID");

    /* Wakeup Time validation */
    validation.logInfo(
        "When Power Down Mode is set to Auto, ADC wakeup time may need to be considered in each sample window. Refer to the device specific data sheet for specifications on the ADC Wakeup Time.",
        inst, ["totalConversionRate"])
}

function getPinmuxResources(){
    let resources = [];
    for(let ix = 0; ix < 26; ix++){
        resources.push(
            {
                name:"adcPin"+ix,
                displayName:"ADC12 Channel "+ix+" Pin",
                interfaceNames:[ix.toString()],
            },
        )
    }
    return resources;
}

/*  ======== isChannelSelected ========
 *  Checks if a specific channel number is enabled on the current ADC instance
 *
 *  param inst    - a fully configured module instance
 *  param chanNum - number of the channel to check for
 *
 *  returns chanExists true if it exists, false if not
 */
function isChannelSelected(inst, chanNum){
    let chanExists = false;
    for(let adcMemIdx = 0; adcMemIdx <= adcMemRange; adcMemIdx++){
        if( inst.enabledADCMems.includes(adcMemIdx) ){
            let tempIdx = inst["adcMem" + adcMemIdx.toString() + "chansel"]
            let tempIdxTrim = tempIdx.slice(20);
            let ind = parseInt(tempIdxTrim);
            if(ind == chanNum){ chanExists = true;};
            return chanExists;
        }
    }
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
    let allResources = getPinmuxResources();

    let adc = {
        name: "peripheral",
        displayName: "ADC12 Peripheral",
        interfaceName: "ADC",
        resources: [
            // start off empty to get filled-in by the table
        ],
        signalTypes: {
            adcPin0: ["0"],
            adcPin1: ["1"],
            adcPin2: ["2"],
            adcPin3: ["3"],
            adcPin4: ["4"],
            adcPin5: ["5"],
            adcPin6: ["6"],
            adcPin7: ["7"],
            adcPin8: ["8"],
            adcPin9: ["9"],
            adcPin10: ["10"],
            adcPin11: ["11"],
            adcPin12: ["12"],
            adcPin13: ["13"],
            adcPin14: ["14"],
            adcPin15: ["15"],
            adcPin16: ["16"],
            adcPin17: ["17"],
            adcPin18: ["18"],
            adcPin19: ["19"],
            adcPin20: ["20"],
            adcPin21: ["21"],
            adcPin22: ["22"],
            adcPin23: ["23"],
            adcPin24: ["24"],
            adcPin25: ["25"],
        }
    };
    /*
     * MSPM0G1X0X_G3X0X can configure Channels 0-8,11-15
     * M0L11XX_L13XX family can configure channels 0-9, 11-15
     * M0L122X_L222X family can configure channels 0-25,29-31
     * M0C can configure channels 0-9,11,15
     * MSPM0GX51X can configure channels 0-15
     */
    let ind = 0;
    for(let adcMemIdx = 0; adcMemIdx <= adcMemRange; adcMemIdx++){
        if( inst.enabledADCMems.includes(adcMemIdx) ){
            let tempIdx = inst["adcMem" + adcMemIdx.toString() + "chansel"]
            let tempIdxTrim = tempIdx.slice(20);
            ind = parseInt(tempIdxTrim);
            /* Channels 1-8 Configuration */
            if(ind<9){
                if(!((adc.resources).includes(allResources[ind]))){
                    adc.resources.push(allResources[ind])
                }
            }
            /* MSPM0L11XX_L13XX, MSPM0C, MSPM0GX51X can also configure channel 9 to pins */
            else if((Common.isDeviceFamily_PARENT_MSPM0L11XX_L13XX() || Common.isDeviceM0C() || Common.isDeviceFamily_PARENT_MSPM0GX51X()) && ind<10){
                if(!((adc.resources).includes(allResources[ind]))){
                    adc.resources.push(allResources[ind])
                }
            }
            /* MSPM0L122X_L222X and M0GX51X can also configure channel 10 to pins */
            else if((Common.isDeviceFamily_PARENT_MSPM0L122X_L222X() || Common.isDeviceFamily_PARENT_MSPM0GX51X()) && ind==10){
                if(!((adc.resources).includes(allResources[ind]))){
                    adc.resources.push(allResources[ind])
                }
            }
            /* MSPM0L122X_L222X can also configure channel 11 to pins */
            else if((Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()) && ind==11){
                if(!((adc.resources).includes(allResources[ind]))){
                    adc.resources.push(allResources[ind])
                }
            }
            /* MSPM0L122X_L222X and M0GX51X can also configure channels 12-14 to pins */
            else if((Common.isDeviceFamily_PARENT_MSPM0L122X_L222X() || Common.isDeviceFamily_PARENT_MSPM0GX51X()) && ind>11 && ind<15){
                if(!((adc.resources).includes(allResources[ind]))){
                    adc.resources.push(allResources[ind])
                }
            }
            /* MSPM0L122X_L222X can also configure channels 15-25 to pins */
            else if(Common.isDeviceFamily_PARENT_MSPM0L122X_L222X() && ind>14 && ind<26){
                if(!((adc.resources).includes(allResources[ind]))){
                    adc.resources.push(allResources[ind])
                }
            }
            /* Special case of M0G Channel 12 on MSPM0G1X0X_G3X0X */
            if(Common.isDeviceFamily_PARENT_MSPM0G1X0X_G3X0X() && ind == 12 && !inst.disChan12){
                if(!((adc.resources).includes(allResources[ind]))){
                    adc.resources.push(allResources[ind])
                }
            }
            /* Special case of M0G Channel 11 on MSPM0GX51X */
            if(Common.isDeviceFamily_PARENT_MSPM0GX51X() && ind == 11 && !inst.disChan11){
                if(!((adc.resources).includes(allResources[ind]))){
                    adc.resources.push(allResources[ind])
                }
            }

        }
    }

    return [adc];
}

/*
 *  ========= filterHardware ========
 *  Check 'component' signals for compatibility with module
 *
 *  param component - hardware object describing signals and
 *                    resources they're attached to
 *  returns Boolean indicating whether or not to allow the component to
 *           be assigned to an instance's $hardware config
 */
function filterHardware(component)
{
    return true;
}

const MemoryIndexOptions = _.map(Array(adcMemRange + 1).fill(), (_,idx) =>
    ({name: idx, displayName: "ADC Conversion Memory " + idx }));
const AddressOptions = _.map(Array(adcMemRange + 1).fill(), (_,idx) => ({name: idx}));


/* onChangeADC */
function onChangeADC(inst, ui) {
    // global on change function that should make any and all changes

}

/*
 *  ======== onChangeSampleClkUpdate ========
 *  Controls whether to show/hide adcClk_Freq_cconstop or adcClk_Freq_cconrun
 *  configuration options based on user sampClkSrc selection
 */
function onChangeSampleClkUpdate(inst, ui){
    updateGUICCon(inst,ui)
    /* set current profile to custom */
    onChangeCustomProfile(inst,ui);
}

function updateGUICCon(inst,ui){
    if(inst.sampClkSrc === "DL_ADC12_CLOCK_SYSOSC") {
        ui.adcClk_Freq_cconstop.hidden = false;
        ui.adcClk_Freq_cconrun.hidden = false;
    }else{
        ui.adcClk_Freq_cconstop.hidden = true;
        ui.adcClk_Freq_cconrun.hidden = true;
    }
}

/*
 *  ======== onChangeEnabledADCMem ========
 *  Controls whether to show/hide ADCMEM configuration options
 *  based on user selection
 */
function onChangeEnabledADCMem(inst,ui){
    updateGUIEnabledADCMem(inst,ui);
    /* set current profile to custom */
    onChangeCustomProfile(inst,ui);
}

function updateGUIEnabledADCMem(inst,ui){
    for(let adcMemIdx=0; adcMemIdx<=adcMemRange; adcMemIdx++){
        let adcMemConfigs = [
            //"adcMem" + adcMemIdx.toString() + "ConversionRate",
            "adcMem" + adcMemIdx.toString() + "chansel",
            "adcMem" + adcMemIdx.toString() + "_name",
            "adcMem" + adcMemIdx.toString() + "vref",
            //"adcMem" + adcMemIdx.toString() + "stime",
            "adcMem" + adcMemIdx.toString() + "bcsen",
            "adcMem" + adcMemIdx.toString() + "trig",
            "adcMem" + adcMemIdx.toString() + "wincomp",
            "adcMem" + adcMemIdx.toString() + "channelConnection",
            // "adcMem" + adcMemIdx.toString() + "calcVoltage", // calcVoltage cannot be turned on always
        ];
        if(Common.isDeviceM0G() || Common.isDeviceM0C()){
            adcMemConfigs.push(
                "adcMem" + adcMemIdx.toString() + "vrefDependency",
            )
        }
        else if(Common.isDeviceM0L()){
            adcMemConfigs.push(
                "adcMem" + adcMemIdx.toString() + "vrefDependencySelect",
            )
        }
        if(isAveragingEnabled()){
            adcMemConfigs.push(
                "adcMem" + adcMemIdx.toString() + "avgen",
            )
        }
        for (let adcMemConfig of adcMemConfigs)
        {
            ui[adcMemConfig].hidden = !inst.enabledADCMems.includes(adcMemIdx);
        }
    }

    updateGUISampleMode(inst,ui); // updates conversionRate, STIME
    updateGUIVREF(inst,ui); // updates calcVoltage, dependencySelect appropriately
}

/*
 *  ======== onChangeVREF ========
 *  determine whether to show/hide calculated voltage based on chosen vref
 *
 */
function onChangeVREF(inst,ui){
    updateGUIVREF(inst,ui);
    /* set current profile to custom */
    onChangeCustomProfile(inst,ui);
}
function updateGUIVREF(inst,ui){
    let isHidden = true;
    for(let adcMemIdx=0; adcMemIdx<=adcMemRange; adcMemIdx++){
        isHidden = true;
        if( inst.enabledADCMems.includes(adcMemIdx) ){
            isHidden = false;
            if(inst["adcMem"+adcMemIdx.toString()+"vref"]=="VREF"){
                /* un-hide VREF components, hide VDDA components */
                if(Common.isDeviceM0G() || Common.isDeviceM0C()) {
                    ui["adcMem"+adcMemIdx.toString()+"vrefDependency"].hidden = isHidden;
                }
                else if(Common.isDeviceM0L()){
                    ui["adcMem"+adcMemIdx.toString()+"vrefDependencySelect"].hidden = isHidden;
                }
                ui["adcMem"+adcMemIdx.toString()+"calcVoltage"].hidden = isHidden;

                ui["adcMem"+adcMemIdx.toString()+"getVDDA"].hidden = !isHidden;
            }
            else if(inst["adcMem"+adcMemIdx.toString()+"vref"]=="VDDA"){
                /* un-hide VDDA components, hide VREF components */
                ui["adcMem"+adcMemIdx.toString()+"getVDDA"].hidden = isHidden;

                if(Common.isDeviceM0G() || Common.isDeviceM0C()) {
                    ui["adcMem"+adcMemIdx.toString()+"vrefDependency"].hidden = !isHidden;
                }
                else if(Common.isDeviceM0L()){
                    ui["adcMem"+adcMemIdx.toString()+"vrefDependencySelect"].hidden = !isHidden;
                }
                ui["adcMem"+adcMemIdx.toString()+"calcVoltage"].hidden = !isHidden;
            }
        }
    }
}


function calculateVREFDependency(inst,adcMemIdx){
    let vrefMode = "DL_VREF_ENABLE_ENABLE"
    let calcDependency = "DL_ADC12_REFERENCE_VOLTAGE_VDDA"
    let vrefInstance = system.modules["/ti/driverlib/VREF"];
    if (vrefInstance){
        vrefMode = vrefInstance.$static.basicMode
    }
    if(inst["adcMem"+adcMemIdx.toString()+"vref"]=="VDDA"){
        calcDependency="DL_ADC12_REFERENCE_VOLTAGE_VDDA"
    }
    else if(Common.isDeviceM0G() || Common.isDeviceM0C()){
        if(inst["adcMem"+adcMemIdx.toString()+"vref"]=="VREF"){
            if(vrefMode=="DL_VREF_ENABLE_ENABLE"){
                calcDependency="DL_ADC12_REFERENCE_VOLTAGE_INTREF"
            }
            else if(vrefMode=="DL_VREF_ENABLE_DISABLE"){
                calcDependency="DL_ADC12_REFERENCE_VOLTAGE_EXTREF"
            }
        }
    }
    else if(Common.isDeviceM0L()){
        if(inst["adcMem"+adcMemIdx.toString()+"vref"]=="VREF"){
            calcDependency = inst["adcMem"+adcMemIdx.toString()+"vrefDependencySelect"];
        }
    }
    return calcDependency
}

/*
 *  ======== onChangeSamplingMode ========
 *  show/hide ADCMEM GUI elements based on sampling mode
 */
function onChangeSamplingMode(inst,ui){

    onChangeAddress(inst,ui);
    updateGUISamplingMode(inst,ui);
    /* set current profile to custom */
    onChangeCustomProfile(inst,ui);
}
function updateGUISamplingMode(inst,ui){
    ui.endAdd.hidden = (inst.samplingOperationMode === "single");
}

/*
 *  ======== onChangeAddress ========
 *  show/hide selected ADCMEMs based on address selection
 */
function onChangeAddress(inst,ui) {
    if(inst.samplingOperationMode === "sequence"){
        let startIdx = inst.startAdd;
        let endIdx = inst.endAdd;
        if(startIdx <= endIdx){
            let tempADCMems = [];
            for(let addressIdx = startIdx; addressIdx<=endIdx; addressIdx++){
                tempADCMems.push(addressIdx);
            }
            inst.enabledADCMems = tempADCMems;
        } else {
            /* error to be addressed by validation, but
               line necessary for serialization Sanity Test */
            inst.enabledADCMems = [];
        }
    } else {
        // TODO: review this especially!!!!!
        // sampling operation Mode is single, via description, thus we change enabled to just 0
        /* Cannot have it rely on the previous state here.
           Multiple enabled ADC mems are allowed but changing the address
           to single necessitates clearing the enabled ADC mems in order to preserve
           determinism. */
        inst.enabledADCMems = [inst.startAdd];

    }
    updateGUIEnabledADCMem(inst,ui);
    /* set current profile to custom */
    onChangeCustomProfile(inst,ui);
}


/*
 *  ======== onChangeHWAverage ========
 *  show/hide HW Averaging options
 */
function onChangeHWAverage(inst, ui){
    updateGUIHWAverage(inst,ui);
    /* set current profile to custom */
    onChangeCustomProfile(inst,ui);
}
function updateGUIHWAverage(inst,ui){
    if(inst.enableHWAverage){
        ui["hwNumerator"].hidden = false;
        ui["hwDenominator"].hidden = false;
    }
    else{
        ui["hwNumerator"].hidden = true;
        ui["hwDenominator"].hidden = true;
    }
}

/*
 *  ========  onChangeWinComp ========
 *  show/hide Window Comparator options
 */
function onChangeWinComp(inst, ui){
    updateGUIWinComp(inst,ui);
    /* set current profile to custom */
    onChangeCustomProfile(inst,ui);
}
function updateGUIWinComp(inst,ui){
    if(inst.enableWinComp){
        ui["adcMemWinComSelEn"].hidden = false;
        ui["configWinCompLowThld"].hidden = false;
        ui["configWinCompHighThld"].hidden = false;
    }
    else{
        ui["adcMemWinComSelEn"].hidden = true;
        ui["configWinCompLowThld"].hidden = true;
        ui["configWinCompHighThld"].hidden = true;
    }
}

/*
 *  ======== onChangeWinCompADCMem ========
 *  show/hide ADCMEM-specific Window Comparator options.
 *  also helps keep track of whether any one comparator is enabled
 */
function onChangeWinCompADCMem(inst,ui){
    updateGUIWinCompADCMem(inst,ui);
    /* set current profile to custom */
    onChangeCustomProfile(inst,ui);
}
function updateGUIWinCompADCMem(inst,ui){
    let winCompADCMem = false;
    for(let adcMemIdx = 0; adcMemIdx <= adcMemRange; adcMemIdx++){
        if(inst["adcMem"+adcMemIdx.toString()+"wincomp"] == true){
            winCompADCMem = true;
            ui["adcMem"+adcMemIdx.toString()+"wincompSetting"].hidden = false
        }else{
            ui["adcMem"+adcMemIdx.toString()+"wincompSetting"].hidden = true
        }
    }
    if(winCompADCMem){
        inst.enableWinComp = true;
        ui["adcMemWinComSelEn"].hidden = false;
        ui["configWinCompLowThld"].hidden = false;
        ui["configWinCompHighThld"].hidden = false;
    }
    else{
        inst.enableWinComp = false;
        ui["adcMemWinComSelEn"].hidden = true;
        ui["configWinCompLowThld"].hidden = true;
        ui["configWinCompHighThld"].hidden = true;
    }
}

/*
 *  ======== onChangeHWAvgADCMem ========
 *  show/hide ADCMEM-specific HW Averaging options.
 *  also helps keep track of whether any one HW Averaging is enabled
 */
function onChangeHWAvgADCMem(inst,ui){
    updateGUIHWAvgADCMem(inst,ui);
    /* set current profile to custom */
    onChangeCustomProfile(inst,ui);
}
function updateGUIHWAvgADCMem(inst,ui){
    let hwAvgADCMem = false;
    for(let adcMemIdx = 0; adcMemIdx <= adcMemRange; adcMemIdx++){
        if(inst["adcMem"+adcMemIdx.toString()+"avgen"] == true){
            hwAvgADCMem = true;
        }
    }
    if(hwAvgADCMem){
        inst.enableHWAverage = true;
        ui["hwNumerator"].hidden = false;
        ui["hwDenominator"].hidden = false;
    }
    else{
        inst.enableHWAverage = false;
        ui["hwNumerator"].hidden = true;
        ui["hwDenominator"].hidden = true;
    }
}

/*
 *  ======== onChangeSampleMode ========
 *  show/hide sampling time options and calculated
 *  conversion rate based on sample mode
 */
function onChangeSampleMode(inst,ui){
    updateGUISampleMode(inst,ui);
    /* set current profile to custom */
    onChangeCustomProfile(inst,ui);
}

function isConversionRateHidden(inst){
    let isConversionRateHidden = true;
    if(inst.sampleMode == "DL_ADC12_SAMPLING_SOURCE_AUTO" &&
         inst.powerDownMode == "DL_ADC12_POWER_DOWN_MODE_AUTO"){
            isConversionRateHidden = false;
    }
    return isConversionRateHidden
}

function updateGUISampleMode(inst,ui){
    let isReadOnly = false;
    let isConversionRateHidden = true;
    if(inst.sampleMode == "DL_ADC12_SAMPLING_SOURCE_AUTO" &&
         inst.powerDownMode == "DL_ADC12_POWER_DOWN_MODE_AUTO"){
            isConversionRateHidden = false;
    } else if (inst.sampleMode == "DL_ADC12_SAMPLING_SOURCE_MANUAL") {
        isReadOnly = true;
    }
    ui.sampleTime0.readOnly = isReadOnly;
    ui.sampleTime1.readOnly = isReadOnly;

    for(let adcMemIdx=0; adcMemIdx<=adcMemRange; adcMemIdx++) {
        let isHidden = !inst.enabledADCMems.includes(adcMemIdx);
        ui["adcMem" + adcMemIdx + "ConversionRate" ].hidden = isHidden || isConversionRateHidden;
        ui["adcMem" + adcMemIdx + "stime" ].hidden = isHidden;
        ui["adcMem" + adcMemIdx + "stime" ].readOnly = isReadOnly;
    }
}

/*
 *  ======== onChangePowerDownMode ========
 *  show/hide sampling time options and calculated
 *  conversion rate based on sample mode
 */
function onChangePowerDownMode(inst,ui){
    updateGUIPowerDownMode(inst,ui);
    /* set current profile to custom */
    onChangeCustomProfile(inst,ui);
}
function updateGUIPowerDownMode(inst,ui){
    if((inst.powerDownMode == "DL_ADC12_POWER_DOWN_MODE_AUTO")&&(inst.sampleMode == "DL_ADC12_SAMPLING_SOURCE_AUTO")){
        for(let adcMemIdx=0; adcMemIdx<=adcMemRange; adcMemIdx++){
            if( inst.enabledADCMems.includes(adcMemIdx) )
            {
                ui["adcMem" + adcMemIdx.toString() + "ConversionRate"].hidden = false;
            }
        }
    }
    else if(inst.powerDownMode == "DL_ADC12_POWER_DOWN_MODE_MANUAL"){
        for(let adcMemIdx=0; adcMemIdx<=adcMemRange; adcMemIdx++){
            if( inst.enabledADCMems.includes(adcMemIdx) )
            {
                ui["adcMem" + adcMemIdx.toString() + "ConversionRate"].hidden = true;
            }
        }
    }
}

/************************* Parsing functions *******************************/

function getScaledPeriod(valueInSec)
{
    let value;
    let maxPerUnits;
    let maxPeriodStr;

    /* Avoid ks notation */
    if((valueInSec / 1000) > 1)
    {
        value = (valueInSec / 60);
        /* Avoid kmin notation */
        if((value / 1000) > 1)
        {
            value = (value / 60);
            maxPerUnits = "hrs ";
        }else
        {
            maxPerUnits = "min ";
        }
    }else{
       value = valueInSec;
       maxPerUnits = "s ";
    }

     maxPeriodStr = Common.getUnitPrefix(value).str;

     return [maxPeriodStr , maxPerUnits]
}

function getActualSampleTime0(inst){
    let desiredSampleTime = Common.parseFloatUnitInput(inst.sampleTime0,"s");
    let ticks = Math.round(desiredSampleTime*inst.sampleClk_Freq);
    let actualSampleTime = ticks/inst.sampleClk_Freq
    return actualSampleTime
}
function getActualSampleTime1(inst){
    let desiredSampleTime = Common.parseFloatUnitInput(inst.sampleTime1,"s");
    let ticks = Math.round(desiredSampleTime*inst.sampleClk_Freq);
    let actualSampleTime = ticks/inst.sampleClk_Freq
    return actualSampleTime
}
function getADCMemWinSettings(inst){
    let winComLow = inst.configWinCompLowThld
    let winComHigh = inst.configWinCompHighThld
    return "High threshold = " + winComHigh + " Low threshold = " + winComLow
}

function getADCMemWithWinCompEn(inst){
    let adcMemWinComEn = "ADC Conversion Memory Configuration [";
    for(let adcMemIdx=0; adcMemIdx<=adcMemRange; adcMemIdx++){
        var name = "adcMem" + adcMemIdx.toString() + "wincomp"
        if(inst[name] == true)
        {
            adcMemWinComEn = adcMemWinComEn.concat(adcMemIdx.toString() +",")
        }
    }
    adcMemWinComEn =  adcMemWinComEn.concat("]")
    adcMemWinComEn = adcMemWinComEn.replace(",]","]")
    return adcMemWinComEn;
}
// ===============================

function getActualDisplaySampleTime(actualSampleTime){
    if(actualSampleTime === NaN){
        return "NaN";
    }
    let result = getScaledPeriod(actualSampleTime);
    let actualStr = result[0] + result[1];
    return actualStr;
}
function getActualDisplaySampleTime0(inst){
    let actualSampleTime = inst.sampleTime0Actual;
    return getActualDisplaySampleTime(actualSampleTime);
}
function getActualDisplaySampleTime1(inst){
    let actualSampleTime = inst.sampleTime1Actual;
    return getActualDisplaySampleTime(actualSampleTime);
}



/************************* Profiles functions *******************************/
/*
 *  ======== onChangeProfiles ========
 *  Called when ADC Profile is changed.
 *  Pre-configures ADC according to profiles
 *
 */

const profilesADC12 = [
    {
        name                    : "singleChannel",
        samplingOperationMode   : "single",
        resolution              : (Common.isDeviceM0C())?"DL_ADC12_SAMP_CONV_RES_10_BIT":"DL_ADC12_SAMP_CONV_RES_12_BIT",
        sampClkSrc              : "DL_ADC12_CLOCK_ULPCLK",
        sampClkDiv              : "DL_ADC12_CLOCK_DIVIDE_1",
        enabledADCMems          : [0],
        adcMem0chansel          : "DL_ADC12_INPUT_CHAN_0",
        adcMem0vref             : "VDDA",
        repeatMode              : true,
        sampleMode              : "DL_ADC12_SAMPLING_SOURCE_AUTO",
        dataFormat              : "DL_ADC12_SAMP_CONV_DATA_FORMAT_UNSIGNED",
        enabledInterrupts       : ["DL_ADC12_INTERRUPT_MEM0_RESULT_LOADED"],
        interruptPriority       : "DEFAULT",
        adcMem0stime            : "DL_ADC12_SAMPLE_TIMER_SOURCE_SCOMP0",
        sampleTime0             : "62.5ns",

    },
    {
            name: "default",
            // Basic
            // -sample clock
            sampClkSrc              : "DL_ADC12_CLOCK_SYSOSC",
            sampClkDiv              : "DL_ADC12_CLOCK_DIVIDE_8",
            // -sampling mode
            samplingOperationMode   : "single",
            startAdd                : 0,
            endAdd                  : 0,
            repeatMode              : false,
            sampleMode              : "DL_ADC12_SAMPLING_SOURCE_AUTO",
            trigSrc                 : "DL_ADC12_TRIG_SRC_SOFTWARE",
            dataFormat              : "DL_ADC12_SAMP_CONV_DATA_FORMAT_UNSIGNED",
            // Advanced
            resolution              : (Common.isDeviceM0C())?"DL_ADC12_SAMP_CONV_RES_10_BIT":"DL_ADC12_SAMP_CONV_RES_12_BIT",
            enableFIFO              : false,
            powerDownMode           : "DL_ADC12_POWER_DOWN_MODE_AUTO",
            enableHWAverage         : false,
            hwNumerator             : "DL_ADC12_HW_AVG_NUM_ACC_DISABLED",
            hwDenominator           : "DL_ADC12_HW_AVG_DEN_DIV_BY_1",
            sampleTime0             : "0 ms",
            sampleTime1             : "0 ms",
            enableWinComp           : false,
            configWinCompLowThld    : 0,
            configWinCompHighThld   : 0,
            // Interrupt
            enabledInterrupts       : [],
            interruptPriority       : "DEFAULT",
            // DMA
            enableDMA               : false,
            configureDMA            : false,
            sampCnt                 : 0,
            enabledDMATriggers      : [],
            // Events
            pubChanID               : 0,
            subChanID               : 0,
            enabledEvents           : [],
            // ADCMEM
            enabledADCMems          : [0],
            // ADCMEM0 specific
            adcMem0chansel          : "DL_ADC12_INPUT_CHAN_0",
            adcMem0vref             : "VDDA",
            adcMem0stime            : "DL_ADC12_SAMPLE_TIMER_SOURCE_SCOMP0",
            adcMem0avgen            : false,
            adcMem0bcsen            : false,
            adcMem0wincomp          : false,
            adcMem0trig             : "DL_ADC12_TRIGGER_MODE_AUTO_NEXT",
        }
];
/* Default Profile: default options will be set before profile-specific options */
if(Common.isDeviceM0G()){
    profilesADC12.push(
        {
            name                    : "lowPowerSequence",
            samplingOperationMode   : "sequence",
            startAdd                : 2,
            endAdd                  : 5,
            enabledADCMems          : [2,3,4,5],
            sampleMode              : "DL_ADC12_SAMPLING_SOURCE_AUTO",
            dataFormat              : "DL_ADC12_SAMP_CONV_DATA_FORMAT_UNSIGNED",
            resolution              : "DL_ADC12_SAMP_CONV_RES_8_BIT",
            enableFIFO              : false,
            sampClkDiv              : "DL_ADC12_CLOCK_DIVIDE_2",
            sampClkSrc              : "DL_ADC12_CLOCK_ULPCLK",
            adcMem2stime            : "DL_ADC12_SAMPLE_TIMER_SOURCE_SCOMP0",
            adcMem3stime            : "DL_ADC12_SAMPLE_TIMER_SOURCE_SCOMP0",
            adcMem4stime            : "DL_ADC12_SAMPLE_TIMER_SOURCE_SCOMP0",
            adcMem5stime            : "DL_ADC12_SAMPLE_TIMER_SOURCE_SCOMP0",
            sampleTime0             : "875ns",
        },
        {
            name: "default",
            // Basic
            // -sample clock
            sampClkSrc              : "DL_ADC12_CLOCK_SYSOSC",
            sampClkDiv              : "DL_ADC12_CLOCK_DIVIDE_8",
            // -sampling mode
            samplingOperationMode   : "single",
            startAdd                : 0,
            endAdd                  : 0,
            repeatMode              : false,
            sampleMode              : "DL_ADC12_SAMPLING_SOURCE_AUTO",
            trigSrc                 : "DL_ADC12_TRIG_SRC_SOFTWARE",
            dataFormat              : "DL_ADC12_SAMP_CONV_DATA_FORMAT_UNSIGNED",
            // Advanced
            resolution              : "DL_ADC12_SAMP_CONV_RES_12_BIT",
            enableFIFO              : false,
            powerDownMode           : "DL_ADC12_POWER_DOWN_MODE_AUTO",
            sampleTime0             : "0 ms",
            sampleTime1             : "0 ms",
            enableWinComp           : false,
            configWinCompLowThld    : 0,
            configWinCompHighThld   : 0,
            // Interrupt
            enabledInterrupts       : [],
            interruptPriority       : "DEFAULT",
            // DMA
            enableDMA               : false,
            configureDMA            : false,
            sampCnt                 : 0,
            enabledDMATriggers      : [],
            // Events
            pubChanID               : 0,
            subChanID               : 0,
            enabledEvents           : [],
            // ADCMEM
            enabledADCMems          : [0],
            adcMem0avgen            : true,
            hwNumerator             : "DL_ADC12_HW_AVG_NUM_ACC_8",
            hwDenominator           : "DL_ADC12_HW_AVG_DEN_DIV_BY_8",
            adcMem0stime            : "DL_ADC12_SAMPLE_TIMER_SOURCE_SCOMP0",
            sampleTime0             : "1us",
            enableDMA               : true,
            configureDMA            : true,
            sampCnt                 : 1,
            enabledDMATriggers      : ["DL_ADC12_DMA_MEM0_RESULT_LOADED"],
            adcMem0trig             : "DL_ADC12_TRIGGER_MODE_AUTO_NEXT",
        },

    );
}

/*
 *  ======== onChangeProfiles ========
 *  Set options based on configuration profiles selection
 */
function onChangeProfiles(inst,ui){
    if (inst.chosenProfile != "custom") {

        /* set configuration to default */
        let defaultingProfileArray = profilesADC12.filter(obj =>
            {return obj.name === "default"} );
        const defaultProfile = Object.assign({}, defaultingProfileArray[0]);
        //selectedProfile = selectedProfile[0];

        delete defaultProfile.name;
        Object.assign(inst, defaultProfile)
        /* set configuration to selected profile */
        let selectedProfileArray = profilesADC12.filter(obj =>
                                        {return obj.name === inst.chosenProfile});
        if (selectedProfileArray.length != 0){
            const selectedProfile = Object.assign({}, selectedProfileArray[0]);
            delete selectedProfile.name;
            Object.assign(inst, selectedProfile)
        }
        updateGUIbasedonConfig(inst, ui);
    }
}
function onChangeCustomProfile(inst,ui){
    inst.chosenProfile = "custom";
}
function updateGUIbasedonConfig(inst,ui){
    updateGUIEnabledADCMem(inst,ui);
    //updateGUIVREF(inst,ui);
    //updateGUISampleMode(inst,ui);
    updateGUISamplingMode(inst,ui);
    updateGUIWinComp(inst,ui);
    updateGUIWinCompADCMem(inst,ui);
    updateGUIConfigureDMA(inst,ui);
    updateGUIInterrupts(inst,ui);
    updateGUICCon(inst,ui);
    if(isAveragingEnabled()){
        updateGUIHWAverage(inst,ui);
        updateGUIHWAvgADCMem(inst,ui);
    }
}

/*
 *  ======== onChangeConfigureDMA ========
 *  set dma options to read-only if disabled
 */
function onChangeConfigureDMA(inst,ui){
    updateGUIConfigureDMA(inst,ui);
    /* set current profile to custom */
    onChangeCustomProfile(inst,ui);
}
function updateGUIConfigureDMA(inst,ui){
    if(inst.configureDMA){
        ui.sampCnt.hidden = false;
        ui.enabledDMATriggers.hidden = false;
        ui.enableDMA.hidden = false;
    }
    else{
        ui.sampCnt.hidden = true;
        ui.enabledDMATriggers.hidden = true;
        ui.enableDMA.hidden = true;
    }
}

function onChangeInterrupts(inst, ui){
    updateGUIInterrupts(inst, ui);
    onChangeCustomProfile(inst,ui);
}

function updateGUIInterrupts(inst, ui){
    ui.interruptPriority.hidden = (inst.enabledInterrupts.length === 0);
}

/* DL_ADC12_configConversionMem */
let adcMem_configs = [
    {
        name        : "enabledADCMems",
        displayName : "Active Memory Control Blocks",
        description : 'Selects which memory conversions will be configured',
        hidden      : false,
        default     : [0],
        minSelections: 0,
        options     :  MemoryIndexOptions,
        getDisabledOptions:(inst) => {
            let disabledOptions = [];
            if(inst.samplingOperationMode == "sequence"){
                disabledOptions = MemoryIndexOptions.slice(0,inst.startAdd);
                if(inst.endAdd >= inst.startAdd){
                    disabledOptions = disabledOptions.concat(MemoryIndexOptions.slice(inst.endAdd+1));
                }
                return _.map(disabledOptions, o => ({name: o.name, reason: "outside range"}));
            } else {
                return [];
            }
        },
        onChange    : onChangeEnabledADCMem,
    }
]

const chanselRange = 32;
const channelSelectOptions = [];
for(let chanselIdx = 0; chanselIdx < chanselRange; chanselIdx++){
    /*
     * MSPM0G1X0X_G3X0X can configure Channels 0-8,11-15
     * M0L11XX_L13XX family can configure channels 0-9, 11-15
     * M0L122X_L222X family can configure channels 0-25,29-31
     * M0C can configure channels 0-9,11,15
     * MSPM0GX51X can configure channels 0-15
     */
    if(!(chanselIdx == 9  && Common.isDeviceFamily_PARENT_MSPM0G1X0X_G3X0X()) &&
        !(chanselIdx == 10 && (Common.isDeviceFamily_PARENT_MSPM0G1X0X_G3X0X() || Common.isDeviceFamily_PARENT_MSPM0L11XX_L13XX() || Common.isDeviceM0C())) &&
        !(([12,13,14].includes(chanselIdx)) && (Common.isDeviceM0C())) &&
        ((!((chanselIdx) > 15 && !Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()))) &&(![26,27,28].includes(chanselIdx)))
    {
        channelSelectOptions.push({name: "DL_ADC12_INPUT_CHAN_"+chanselIdx.toString(),displayName: "Channel "+chanselIdx.toString()})
    }
}



/*
 *  ======== calculateTotalConversionRate ========
 *  Calculates total conversion time for all the enabled ADCMEMs
 */
function calculateTotalConversionRate(inst){
    let totalConversionRate = 0;
    for(let adcMemIdx = 0; adcMemIdx<=adcMemRange; adcMemIdx++){
        if( inst.enabledADCMems.includes(adcMemIdx) ){
            let indexConversionRate = calculateConversionRate(inst,adcMemIdx);
            totalConversionRate = totalConversionRate + indexConversionRate;
        }
    }
    if(totalConversionRate>0){
        totalConversionRate = 1/totalConversionRate
    }
    return totalConversionRate;
}

/*
 *  ======== calculateConversionRate ========
 *  Calculate conversion period for selected ADCMEM. This calculation depends
 *  on many factors including the chosen device and other gui selections.
 *
 *  param adcMemIdx - the number of the selected ADCMEM

 */
function calculateConversionRate(inst,adcMemIdx){
    let convTriggerSync = 0;
    let convSampling = 0;
    let convTime = 0;
    let convHWAvg = 1;

    // Trigger Sync Time
    if((inst.sampClkSrc == "DL_ADC12_CLOCK_SYSOSC")||(inst.sampClkSrc == "DL_ADC12_CLOCK_HFCLK")){
        convTriggerSync = 3/inst.sampleClk_Freq;
    }
    else{
        convTriggerSync = 0;
    }

    // Sampling Time
    if(inst["adcMem"+adcMemIdx.toString()+"stime"] == "DL_ADC12_SAMPLE_TIMER_SOURCE_SCOMP0"){
        let desiredSampleTime = inst.sampleTime0Actual;
        if(desiredSampleTime === NaN){
           convSampling = 0;
        }
        else{
            convSampling = desiredSampleTime;
        }
    }
    else if(inst["adcMem"+adcMemIdx.toString()+"stime"] == "DL_ADC12_SAMPLE_TIMER_SOURCE_SCOMP1"){
        let desiredSampleTime = inst.sampleTime1Actual;
        if(desiredSampleTime === NaN){
            convSampling = 0;
         }
         else{
             convSampling = desiredSampleTime;
         }
    }

    // Conversion Time
    let convTimeStruct = {
        DL_ADC12_CLOCK_FREQ_RANGE_1_TO_4: {
            DL_ADC12_SAMP_CONV_RES_12_BIT: 1,
            DL_ADC12_SAMP_CONV_RES_10_BIT: 1,
            DL_ADC12_SAMP_CONV_RES_8_BIT: 1,
        },
        DL_ADC12_CLOCK_FREQ_RANGE_4_TO_8: {
            DL_ADC12_SAMP_CONV_RES_12_BIT: 2,
            DL_ADC12_SAMP_CONV_RES_10_BIT: 2,
            DL_ADC12_SAMP_CONV_RES_8_BIT: 1,
        },
        DL_ADC12_CLOCK_FREQ_RANGE_8_TO_16: {
            DL_ADC12_SAMP_CONV_RES_12_BIT: 3,
            DL_ADC12_SAMP_CONV_RES_10_BIT: 3,
            DL_ADC12_SAMP_CONV_RES_8_BIT: 2,
        },
        DL_ADC12_CLOCK_FREQ_RANGE_16_TO_20: {
            DL_ADC12_SAMP_CONV_RES_12_BIT: 4,
            DL_ADC12_SAMP_CONV_RES_10_BIT: 4,
            DL_ADC12_SAMP_CONV_RES_8_BIT: 3,
        },
        DL_ADC12_CLOCK_FREQ_RANGE_20_TO_24: {
            DL_ADC12_SAMP_CONV_RES_12_BIT: 5,
            DL_ADC12_SAMP_CONV_RES_10_BIT: 4,
            DL_ADC12_SAMP_CONV_RES_8_BIT: 3,
        },
        DL_ADC12_CLOCK_FREQ_RANGE_24_TO_32: {
            DL_ADC12_SAMP_CONV_RES_12_BIT: 6,
            DL_ADC12_SAMP_CONV_RES_10_BIT: 6,
            DL_ADC12_SAMP_CONV_RES_8_BIT: 4,
        },
        DL_ADC12_CLOCK_FREQ_RANGE_32_TO_40: {
            DL_ADC12_SAMP_CONV_RES_12_BIT: 8,
            DL_ADC12_SAMP_CONV_RES_10_BIT: 7,
            DL_ADC12_SAMP_CONV_RES_8_BIT: 5,
        },
        DL_ADC12_CLOCK_FREQ_RANGE_40_TO_48: {
            DL_ADC12_SAMP_CONV_RES_12_BIT: 9,
            DL_ADC12_SAMP_CONV_RES_10_BIT: 8,
            DL_ADC12_SAMP_CONV_RES_8_BIT: 6,
        },
    }
    /* MSPM0G-specific options */
    if(Common.isDeviceM0G()){
        convTime = (convTimeStruct[inst.sampClkFreqRange][inst.resolution])/inst.sampleClk_Freq;
    }
    /* MSPM0L-specific options */
    else if(Common.isDeviceM0L() || Common.isDeviceM0C()){
        if(inst.resolution  == "DL_ADC12_SAMP_CONV_RES_12_BIT"){
            convTime = 14/inst.sampleClk_Freq;
        }
        else if(inst.resolution  == "DL_ADC12_SAMP_CONV_RES_10_BIT"){
            convTime = 12/inst.sampleClk_Freq;
        }
        else if(inst.resolution  == "DL_ADC12_SAMP_CONV_RES_8_BIT"){
            convTime = 9/inst.sampleClk_Freq;
        }
    }

    /* Hardware Average Accumulation */
        if(inst["adcMem"+adcMemIdx.toString()+"avgen"]&&inst.enableHWAverage){
            convHWAvg = inst.hwNumerator;
            if(inst.hwNumerator == "DL_ADC12_HW_AVG_NUM_ACC_DISABLED"){
                convHWAvg = 1;
            }
            else{
                convHWAvg = parseInt((inst.hwNumerator).slice(24));
            }
        }

    let convRate = convTriggerSync+((convSampling+convTime)*convHWAvg)
    return convRate;
}

/*
 *  ======== calculateVoltage ========
 *  calculate voltage based on selected voltage reference.
 *  requires VREF module to be added.
 *
 *
 */
function calculateVoltage(inst, adcMemIdx){
    let calcVoltage = 0;
    // "adcMem"+adcMemIdx.toString()+"vref"
    // DL_ADC12_REFERENCE_VOLTAGE_INTREF
    let vrefVoltage = -1;
    let vrefInstance = system.modules["/ti/driverlib/VREF"];

    if (vrefInstance){
        if(Common.isDeviceM0G() || Common.isDeviceM0C()){
            vrefVoltage = (vrefInstance.$static.basicVREFVoltage)
        }
        else if(Common.isDeviceM0L()){
            if(inst["adcMem"+adcMemIdx.toString()+"vrefDependency"] == "DL_ADC12_REFERENCE_VOLTAGE_INTREF"){
                vrefVoltage = (vrefInstance.$static.basicVREFVoltageInternal)
            }
            else if(inst["adcMem"+adcMemIdx.toString()+"vrefDependency"] == "DL_ADC12_REFERENCE_VOLTAGE_EXTREF"){
                vrefVoltage = (vrefInstance.$static.basicVREFVoltageExternal)
            }
        }
    }

    calcVoltage =  vrefVoltage
    // TODO: if VREF is updated to use prefix, update this as needed. right now assuming mV, thus conversion
    return calcVoltage/1000;
}

/*
 *  ======== getVDDAVoltage ========
 *  get VDDA reference voltage from Board module.
 *  requires Board module to be added.
 *
 *
 */
function getVDDAVoltage(inst, adcMemIdx){

    let vddaVoltage = 3.3;

    let vddaInstance = system.modules["/ti/driverlib/Board"];

    if (vddaInstance && (vddaInstance.$static.configureVDDA == true)){
        vddaVoltage = (vddaInstance.$static.voltageVDDA)
    }

    return vddaVoltage;
}

function getPinName(inst,adcMemIdx){
    let pinInfo =  "-"
    if(inst.peripheral.$solution){
        let baseName = inst.peripheral.$solution.peripheralName
        let chanSel = (inst["adcMem"+adcMemIdx.toString()+"chansel"]).slice(20)
        let peripheral = system.deviceData.peripherals[baseName];
        if (peripheral){
            let peripheralPins = system.deviceData.peripherals[baseName].peripheralPins[baseName+"."+chanSel]
            if(peripheralPins){
                let pinMappings = peripheralPins.pinMappings["0"]
                if(pinMappings){
                    pinInfo = pinMappings.designSignalName
                }
            }
            else{
                let checkConnection = InternalConnections.ADC12_internalSignals[Common.getDeviceFamily()][baseName]["CH"+chanSel]
                if(checkConnection){
                    /* Check for device compatibility: MSPM0L110X does not have a DAC */
                    if(Common.isDeviceM0x110x()){
                        if(checkConnection.includes("DAC")){
                            return pinInfo
                        }
                    }
                    pinInfo = checkConnection;
                }
            }
        }
    }

    return pinInfo
}

/*
 *  ======== addADCMEMGroup ========
 *  Prepares the config object for ADCMEM
 *
 *  param hiddenStatus - whether to hide/show selected ADCMEM
 */
function addADCMEMGroup(adcMemIdx, hiddenStatus){
    /* DL_ADC12_configConversionMem */
    let adcMem_advancedConfigs = [];
    adcMem_advancedConfigs.push(
        {
            name        : "adcMem"+adcMemIdx.toString()+"avgen",
            displayName : "Averaging Mode",
            description : 'Implements digital sample averaging in hardware',
            longDescription: `The Averaging Mode is configured using the Hardware Average Numerator and Hardware Average Denominator in the Advanced Configuration panel.`,
            hidden      : hiddenStatus,
            default     : false,
            onChange    : onChangeHWAvgADCMem,
        },
        {
            name        : "adcMem"+adcMemIdx.toString()+"bcsen",
            displayName : "Burn Out Current Source",
            description : 'Enable burn out current source',
            hidden      : hiddenStatus,
            default     : false,
            onChange    : onChangeCustomProfile,
        },
        {
            name        : "adcMem"+adcMemIdx.toString()+"wincomp",
            displayName : "Window Comparator Mode",
            description : 'Enable window comparator mode',
            hidden      : hiddenStatus,
            default     : false,
            onChange    : onChangeWinCompADCMem,
        },
        {
            name        : "adcMem"+adcMemIdx.toString()+"wincompSetting",
            displayName : "Current Window Comparator Setting",
            description : 'Shows current window comparator settings',
            hidden      : true,
            readOnly    : true,
            default     : "",
            getValue    : getADCMemWinSettings
        },
        {
            name        : "adcMem"+adcMemIdx.toString()+"trig",
            displayName : "Trigger Mode",
            description : 'Selects trigger mode',
            hidden      : hiddenStatus,
            default     : "DL_ADC12_TRIGGER_MODE_AUTO_NEXT",
            options     : [
                {name: "DL_ADC12_TRIGGER_MODE_AUTO_NEXT", displayName: "Trigger will automatically step to next memory conversion register"},
                {name: "DL_ADC12_TRIGGER_MODE_TRIGGER_NEXT", displayName: "Valid trigger will step to next memory conversion register"},
            ],
            onChange    : onChangeCustomProfile,
        },
    )

    let adcMem_config = [
        {
            name        : "adcMem"+adcMemIdx.toString()+"_name",
            displayName : "Name",
            description : 'ADC Configuration Memory Name',
            longDescription: `User can provide a name to be used for sysconfig-generated code when refering to the selected ADC Conversion Memory.`,
            hidden      : hiddenStatus,
            default     : adcMemIdx.toString(),
        },
        {
            name        : "adcMem"+adcMemIdx.toString()+"chansel",
            displayName : "Input Channel",
            description : 'Selects input channel',
            hidden      : hiddenStatus,
            default     : "DL_ADC12_INPUT_CHAN_0",
            options     : channelSelectOptions,
            onChange    : onChangeCustomProfile,
        },
        {
            name        : "adcMem"+adcMemIdx.toString()+"channelConnection",
            displayName : "Device Pin Name",
            getValue    : (inst) => getPinName(inst,adcMemIdx),
            default     : "-",
            hidden      : hiddenStatus,
        },
        {
            name        : "adcMem"+adcMemIdx.toString()+"vref",
            displayName : "Reference Voltage",
            description : 'Selects reference voltage',
            hidden      : hiddenStatus,
            default     : "VDDA",
            longDescription: `
            \nSupported Reference Voltage:
            \n* VDDA
            \n  * MCU supply voltage
            \n  * VDDA can be configured through the SysConfig Board module and is set to a default of 3.3V
            \n* VREF External
            \n  * External reference supplied to the ADC through the VREF+/- pins.
            \n* VREF Internal
            \n  * Configurable internal reference voltage of 1.4V and 2.5V via VREF module.
            `,
            onChange    : onChangeVREF,
            options     : [
                {name: "VDDA", displayName: "VDDA"},
                {name: "VREF", displayName: "VREF"},
            ],
        },
        {
            name        : "adcMem"+adcMemIdx.toString()+"getVDDA",
            displayName : "VDDA",
            default     : "3.3V",
            getValue    : (inst) => {
                let returnVoltage = Common.getUnitPrefix(getVDDAVoltage(inst,adcMemIdx)).str+"V";
                return returnVoltage;
            },
            hidden      : hiddenStatus,
        },
        {
            name        : "adcMem"+adcMemIdx.toString()+"vrefDependency",
            displayName : "VREF Mode",
            description : 'Selected VREF mode from VREF module',
            hidden      : true,
            getValue    : (inst) => calculateVREFDependency(inst,adcMemIdx),
            default     : "DL_ADC12_REFERENCE_VOLTAGE_VDDA",
            options     : [
                {name: "DL_ADC12_REFERENCE_VOLTAGE_VDDA", displayName: "VDDA"},
                {name: "DL_ADC12_REFERENCE_VOLTAGE_EXTREF", displayName: "External"},
                {name: "DL_ADC12_REFERENCE_VOLTAGE_INTREF", displayName: "Internal"},
            ],
        },
    ];
    if(Common.isDeviceM0L()){
        adcMem_config = adcMem_config.concat([
            {
                name        : "adcMem"+adcMemIdx.toString()+"vrefDependencySelect",
                displayName : "VREF Mode",
                description : 'Selected VREF mode from VREF module',
                hidden      : true,
                default     : "DL_ADC12_REFERENCE_VOLTAGE_INTREF",
                options     : [
                    {name: "DL_ADC12_REFERENCE_VOLTAGE_EXTREF", displayName: "External"},
                    {name: "DL_ADC12_REFERENCE_VOLTAGE_INTREF", displayName: "Internal"},
                ],
            },
        ]);
    }
    adcMem_config = adcMem_config.concat([
        {
            name        : "adcMem"+adcMemIdx.toString()+"calcVoltage",
            displayName : "Calculated reference voltage",
            default     : "0V",
            getValue    : (inst) => {
                let returnVoltage = Common.getUnitPrefix(calculateVoltage(inst,adcMemIdx)).str+"V";
                return returnVoltage;
            },
            hidden      : true,
        },
        {
            name        : "adcMem"+adcMemIdx.toString()+"stime",
            displayName : "Sample Period Source",
            description : 'Selects source of sample period',
            hidden      : hiddenStatus,
            default     : "DL_ADC12_SAMPLE_TIMER_SOURCE_SCOMP0",
            options     : [
                {name: "DL_ADC12_SAMPLE_TIMER_SOURCE_SCOMP0", displayName: "Sampling Timer 0"},
                {name: "DL_ADC12_SAMPLE_TIMER_SOURCE_SCOMP1", displayName: "Sampling Timer 1"},
            ],
            onChange: onChangeCustomProfile,
        },
        {
            name        : "adcMem"+adcMemIdx.toString()+"ConversionRate",
            displayName : "ADC Conversion Period",
            description : "Approximate time period for one conversion",
            longDescription : `
* **The calculation for ADC Conversion time is based on the following factors**:
    * ADC Trigger Synchronization Time
        * 3 ADC Clock Cycles are needed for synchronization after the trigger signal is set
        * Note that this synchronization time is bypassed when ULPCLK sources the ADC Clock
    * ADC Sample Time
        * User determined time based on Sample Time 0 (SCOMP0) and Sample Time 1 (SCOMP1) values
    * ADC Conversion Time
        * The number of clock cycles required to perform the conversion
        * Dependent on ADC resolution and device specifics. Refer to the datasheet for specific values.
    * Hardware Accumulation
        * When configured, hardware accumulation takes multiple samples back-to-back

* **Calculation Formula**:
    * ADC Conversion Period = ADCSyncTime + [(ADCSampleTime + ADCConversionTime) * HWAccumulation]

* **Note: This calculation is not avaiable when the ADC is configured in manual sampling mode.**
            `,
            default     : "0s",
            getValue    : (inst) => {
                let returnRate = Common.getUnitPrefix(calculateConversionRate(inst,adcMemIdx)).str+"s";
                return returnRate;
            },
            hidden      : hiddenStatus,
        },
        {
            name: "GROUP_ADCMEM"+adcMemIdx.toString()+"_ADVANCED",
            displayName: "Optional Configuration",
            description: "",
            longDescription: "",
            collapsed: true,
            config: adcMem_advancedConfigs
        },
    ]);

    adcMem_configs = adcMem_configs.concat([
        {
            name: "GROUP_ADCMEM"+adcMemIdx.toString(),
            displayName: "ADC Conversion Memory "+adcMemIdx.toString()+" Configuration",
            description: "",
            longDescription: "",
            collapsed: true,
            config: adcMem_config,
        },
    ])
}

addADCMEMGroup(0,false)
for(let adcMemIdx=1; adcMemIdx<=adcMemRange; adcMemIdx++){
    addADCMEMGroup(adcMemIdx,true)
}

function getQuickProfilesConfig(){
    let quickProfilesConfig = [];

    if(Common.isDeviceM0G()){quickProfilesConfig.push(
    {
        name        : "chosenProfile",
        displayName : "ADC12 Profiles",
        description : '',
        longDescription: `
Pre-defined profiles for typical ADC12 configurations.

The Analog-to-Digital Converter (ADC) supports fast 12, 10, and 8-bit ADC
conversions and integrated oversampling for averaging up to 128 samples.
It implements a 12-bit SAR core, sample/conversion mode control,
and up to 12 independent conversion-and-control buffers. The conversion-and-control
buffer allows up to 12 independent ADC samples to be converted and stored without
any CPU intervention.

The Quick Profile Options are:
* **Single-Channel Max Sampling Rate**:
    * Enables single sampling operation mode
    * Sets 12-bit resolution
    * Sets Clock Source to ULPCLK
        * ULPCLK must be configured for 40MHz in SYSCTL
    * Enables ADC Memory Configuration 0
        * Set input channel 0,
        * Set VDDA as voltage reference.
        * Sets source of sample period to Sampling Timer 0
    * Enables repeat mode
    * Sets sample mode to auto
    * Sets sample conversion data format to unsigned
    * Enables MEM0 result loaded interrupt
    * Sets Sample Time 0 to 62.5 nanoseconds
* **Low-Power Channel Sequence**:
    * Enables sequence sampling operation mode
    * Enables ADC Memory Configuration 2, 3, 4 and 5
        * Sets source of sample period to Sampling Timer 0
    * Sets sample mode to auto
    * Sets sample conversion data format to unsigned
    * Sets 8-bit resolution
    * Disables FIFO
    * Set sample clock divider to divide by 2
    * Sets Clock Source to ULPCLK
        * ULPCLK must be configured for 32MHz in SYSCTL
    * Sets Sample Time 0 to 0.71 microseconds
        * Total Conversion Frequency is 250kHz
* **Low Jitter DMA + Hardware Averaging**:
    * Enables single sampling operation mode
    * Sets Clock Source to HFCLK
        * HFCLK must be configured for 48MHz in SYSCTL
    * Enables ADC Memory Configuration 0
        * Enables Hardware Averaging
        * Sets source of sample period to Sampling Timer 0
        * Sets trigger mode to automatically step to next memory connversion register
    * Sets Hardware Numerator to accumulate 8 conversions
    * Sets Hardware Denominator to 8
    * Sets Sample Time 0 to 1 microseconds
    * Enables DMA
        * Sets DMA sample count to 1
        * Enables DMA trigger for MEM0
* **Custom**:
    * Allows custom configuration.`,
                hidden      : false,
                default     : "custom",
                onChange    : onChangeProfiles,
                options: [
                    {name: "singleChannel", displayName: "Single-Channel Max Sampling Rate"},
                    {name: "lowPowerSequence", displayName: "Low-Power Channel Sequence"},
                    {name: "lowJitter", displayName: "Low Jitter DMA + Hardware Averaging"},
                    {name: "custom", displayName: "Custom"},
                ]
            });
    }

    if(Common.isDeviceM0L() || Common.isDeviceM0C()){quickProfilesConfig.push(
    {
                name        : "chosenProfile",
                displayName : "ADC12 Profiles",
                description : '',
                longDescription: `
Pre-defined profiles for typical ADC12 configurations.

The Analog-to-Digital Converter (ADC) supports fast 12, 10, and 8-bit ADC
conversions. It implements a 12-bit SAR core, sample/conversion mode control,
and up to 4 independent conversion-and-control buffers. The conversion-and-control
buffer allows up to 4 independent ADC samples to be converted and stored without
any CPU intervention.

The Quick Profile Options are:
* **Single-Channel Max Sampling Rate**:
    * Enables single sampling operation mode
    * Sets 12-bit resolution
    * Sets Clock Source to ULPCLK
        * ULPCLK must be configured for 32MHz in SYSCTL
    * Enables ADC Memory Configuration 0
        * Set input channel 0,
        * Set VDDA as voltage reference.
        * Sets source of sample period to Sampling Timer 0
    * Enables repeat mode
    * Sets sample mode to auto
    * Sets sample conversion data format to unsigned
    * Enables MEM0 result loaded interrupt
    * Sets Sample Time 0 to 62.5 nanoseconds
* **Low-Power Channel Sequence**:
    * Enables sequence sampling operation mode
    * Enables ADC Memory Configuration 2, 3, 4 and 5
        * Sets source of sample period to Sampling Timer 0
    * Sets sample mode to auto
    * Sets sample conversion data format to unsigned
    * Sets 8-bit resolution
    * Disables FIFO
    * Set sample clock divider to divide by 2
    * Sets Clock Source to ULPCLK
        * ULPCLK must be configured for 32MHz in SYSCTL
    * Sets Sample Time 0 to 0.71 microseconds
        * Total Conversion Frequency is 250kHz
* **Custom**:
    * Allows custom configuration.`,
                hidden      : false,
                default     : "custom",
                onChange    : onChangeProfiles,
                options: [
                    {name: "singleChannel", displayName: "Single-Channel Max Sampling Rate"},
                    // {name: "lowPowerSequence", displayName: "Low-Power Channel Sequence"},
                    {name: "custom", displayName: "Custom"},
                ]
            });
    }

    return quickProfilesConfig;
}

/* Get ADC clock options based on device family */
function getClockOptions(inst)
{
    /* Base clock options for device families */
    let clockOptions = [
        {name: "DL_ADC12_CLOCK_SYSOSC", displayName: "SYSOSC"},
        {name: "DL_ADC12_CLOCK_ULPCLK", displayName: "ULPCLK"},
    ];

    if (Common.isDeviceM0G() || Common.isDeviceFamily_PARENT_MSPM0L122X_L222X() || Common.isDeviceM0C())
    {
        clockOptions.push(
            {name: "DL_ADC12_CLOCK_HFCLK", displayName: "HFCLK"},
        );
    }

    return (clockOptions);
}

let config = [
    /* Show selected peripheral below instance name */
    {
        name: "selectedInstance",
        displayName: "Selected Peripheral",
        default: "",
        longDescription: `Refer to the PinMux section for peripheral selection. Chosen instance name is not indicative of active peripheral.`,
        getValue: (inst) => {
            let solution = "";
            try{
                solution = inst.peripheral.$solution.peripheralName;
            }catch (e) {
                // do nothing
            }
            return solution;
        }
    },
    {
        name: "GROUP_PROFILES",
        displayName: "Quick Profiles",
        collapsed: false,
        config: getQuickProfilesConfig(),
    },
    {
        name: "GROUP_BASIC",
        displayName: "Basic Configuration",
        description: "",
        longDescription: "",
        collapsed: false,
        config: [
            /* DL_ADC12_setClockConfig */
            {
                name: "GROUP_SAMPLE_CLOCK",
                displayName: "Sample Clock Configuration",
                description: "",
                longDescription: "Configures ADC12 sample clock divider and sample clock frequency range",
                collapsed: false,
                config: [
                    {
                        name        : "sampClkSrc",
                        displayName : "ADC Clock Source",
                        description : 'ADC12 sample clock source selection',
                        hidden      : false,
                        default     : "DL_ADC12_CLOCK_SYSOSC",
                        options     : getClockOptions(),
                        onChange    : onChangeSampleClkUpdate,
                    },
                    {
                        name: "inputClock_Freq",
                        hidden: true,
                        default: 0,
                        getValue: (inst) => {
                            switch(inst.sampClkSrc){
                                case "DL_ADC12_CLOCK_SYSOSC":
                                    return system.modules["/ti/driverlib/SYSCTL"].$static.SYSOSC_FreqOut;
                                case "DL_ADC12_CLOCK_ULPCLK":
                                    return system.modules["/ti/driverlib/SYSCTL"].$static.ULPCLK_Freq;
                                case "DL_ADC12_CLOCK_HFCLK":
                                    return system.modules["/ti/driverlib/SYSCTL"].$static.HFCLK_FreqOut;
                            }
                        }
                    },
                    {
                        name: "adcClk_Freq_disp",
                        displayName: "ADC Clock Frequency",
                        description: "ADC Clock Frequency",
                        longDescription: ``,
                        default: "0Hz",
                        hidden: false,
                        getValue: (inst) => {
                            return (Common.getUnitPrefix(inst.inputClock_Freq)).str + "Hz";
                        }
                    },
                    {
                        name: "adcClk_Freq_cconstop",
                        displayName: "Force SYSOSC Base Freq In STOP",
                        description: "Forces SYSOSC to run at base frequency when device is in STOP mode.",
                        longDescription: 'Forces SYSOSC to run at base frequency when device is in STOP mode.',
                        default: false,
                        hidden: false,
                    },
                    {
                        name: "adcClk_Freq_cconrun",
                        displayName: "Force SYSOSC Base Freq In RUN",
                        description: "Forces SYSOSC to run at base frequency when device is in RUN mode.",
                        longDescription: `Forces SYSOSC to run at base frequency when device is in RUN mode.`,
                        default: false,
                        hidden: false,
                    },
                    {
                        name        : "sampClkDiv",
                        displayName : "Sample Clock Divider",
                        description : 'ADC12 sample clock divider selection',
                        hidden      : false,
                        default     : "DL_ADC12_CLOCK_DIVIDE_1",
                        options     : [
                            {name: "DL_ADC12_CLOCK_DIVIDE_1", displayName: "Divide by 1"},
                            {name: "DL_ADC12_CLOCK_DIVIDE_2", displayName: "Divide by 2"},
                            {name: "DL_ADC12_CLOCK_DIVIDE_4", displayName: "Divide by 4"},
                            {name: "DL_ADC12_CLOCK_DIVIDE_8", displayName: "Divide by 8"},
                            {name: "DL_ADC12_CLOCK_DIVIDE_16", displayName: "Divide by 16"},
                            {name: "DL_ADC12_CLOCK_DIVIDE_24", displayName: "Divide by 24"},
                            {name: "DL_ADC12_CLOCK_DIVIDE_32", displayName: "Divide by 32"},
                            {name: "DL_ADC12_CLOCK_DIVIDE_48", displayName: "Divide by 48"},
                        ],
                        onChange    : onChangeCustomProfile,
                    },
                    {
                        name        : "sampClkFreqRange",
                        displayName : "ADC Clock Frequency Range",
                        description : 'ADC12 sample clock freq range',
                        hidden      : true,
                        default     : "DL_ADC12_CLOCK_FREQ_RANGE_32_TO_40",
                        options     : [
                            {name: "DL_ADC12_CLOCK_FREQ_RANGE_1_TO_4", displayName: "1 MHz to 4 MHz"},
                            {name: "DL_ADC12_CLOCK_FREQ_RANGE_4_TO_8", displayName: "4 MHz to 8 MHz"},
                            {name: "DL_ADC12_CLOCK_FREQ_RANGE_8_TO_16", displayName: "8 MHz to 16 MHz"},
                            {name: "DL_ADC12_CLOCK_FREQ_RANGE_16_TO_20", displayName: "16 MHz to 20 MHz"},
                            {name: "DL_ADC12_CLOCK_FREQ_RANGE_20_TO_24", displayName: "20 MHz to 24 MHz"},
                            {name: "DL_ADC12_CLOCK_FREQ_RANGE_24_TO_32", displayName: "24 MHz to 32 MHz"},
                            {name: "DL_ADC12_CLOCK_FREQ_RANGE_32_TO_40", displayName: "32 MHz to 40 MHz"},
                            {name: "DL_ADC12_CLOCK_FREQ_RANGE_40_TO_48", displayName: "40 MHz to 48 MHz"},
                            /* special case for when out of range */
                            {name: "DL_ADC12_CLOCK_FREQ_RANGE_OUT_OF_RANGE", displayName: "OUT OF RANGE"}
                        ],
                        getValue    : (inst) => {
                            if(inst.adcClk_Freq <= 4000000){
                                return "DL_ADC12_CLOCK_FREQ_RANGE_1_TO_4";
                            }
                            else if((4000000 < inst.adcClk_Freq) && (inst.adcClk_Freq <= 8000000)){
                                return "DL_ADC12_CLOCK_FREQ_RANGE_4_TO_8";
                            }
                            else if((8000000 < inst.adcClk_Freq) && (inst.adcClk_Freq  <= 16000000)){
                                return "DL_ADC12_CLOCK_FREQ_RANGE_8_TO_16";
                            }
                            else if((16000000 < inst.adcClk_Freq) && (inst.adcClk_Freq  <= 20000000)){
                                return "DL_ADC12_CLOCK_FREQ_RANGE_16_TO_20";
                            }
                            else if((20000000 < inst.adcClk_Freq) && (inst.adcClk_Freq  <= 24000000)){
                                return "DL_ADC12_CLOCK_FREQ_RANGE_20_TO_24";
                            }
                            else if((24000000 < inst.adcClk_Freq) && (inst.adcClk_Freq  <= 32000000)){
                                return "DL_ADC12_CLOCK_FREQ_RANGE_24_TO_32";
                            }
                            else if((32000000 < inst.adcClk_Freq) && (inst.adcClk_Freq  <= 40000000)){
                                return "DL_ADC12_CLOCK_FREQ_RANGE_32_TO_40";
                            }
                            else if((40000000 < inst.adcClk_Freq) && (inst.adcClk_Freq  <= 48000000)){
                                return "DL_ADC12_CLOCK_FREQ_RANGE_40_TO_48";
                            }
                            else if(inst.adcClk_Freq > 48000000){
                                return "DL_ADC12_CLOCK_FREQ_RANGE_OUT_OF_RANGE"
                            }
                            return "DL_ADC12_CLOCK_FREQ_RANGE_32_TO_40";

                        }
                    },
                    {
                        name: "adcClk_Freq",
                        displayName: "ADC Clock Frequency",
                        description: "ADC Clock Frequency",
                        longDescription: ``,
                        default: 0,
                        hidden: true,
                        getValue: (inst) => {
                            return (inst.inputClock_Freq);
                        }
                    },
                    {
                        name: "sampleClk_Freq",
                        displayName: "Calculated Sample Clock Frequency",
                        description: "Calculated Sample Clock Frequency",
                        longDescription: ``,
                        default: 0,
                        hidden: true,
                        getValue: (inst) => {
                            let tempDiv  = parseInt((inst.sampClkDiv).slice(22))
                            let tempFreq = (inst.inputClock_Freq / tempDiv);
                            return tempFreq
                        }
                    },
                    {
                        name: "sampleClk_Freq_unit",
                        displayName: "Calculated Sample Clock Frequency",
                        description: "Calculated Sample Clock Frequency",
                        longDescription: ``,
                        default: "0Hz",
                        getValue: (inst) => {
                            let tempDiv  = parseInt((inst.sampClkDiv).slice(22))
                            let tempFreq = (inst.inputClock_Freq / tempDiv);
                            let tempUnits = Common.getUnitPrefix(tempFreq);
                            return tempUnits.str + "Hz";
                        }
                    },
                ]
            },
            /* DL_ADC12_initSingleSample / DL_ADC12_initSeqSample */
            {
                name: "GROUP_SAMPLE_INIT",
                displayName: "Sampling Mode Configuration",
                description: "",
                longDescription: "Initializes ADC12 for selected sampling mode operation",
                collapsed: false,
                config: [
                    {
                        name        : "samplingOperationMode",
                        displayName : "Conversion Mode",
                        description : 'Selects ADC conversion mode',
                        longDescription : `
                        \nSupported conversion modes:
                        \n* Single:
                        \n  * Only  one ADC channel is sampled. Input channel is configured in "ADCMEM0 Configuration" section
                        \n* Sequence:
                        \n  * Groups of ADC channels to be sampled can be configured via "Sequence Conversion Starting Address" and " Sequence Conversion End Address". ADC channel for each memory address is configured in "ADC Memory Conversion Configurations"
                        \n`,
                        hidden      : false,
                        default     : "single",
                        onChange    : onChangeSamplingMode,
                        options     : [
                            {name: "single",    displayName: "Single"},
                            {name: "sequence",  displayName: "Sequence"},
                        ],
                    },
                    {
                        name        : "startAdd",
                        displayName : "Conversion Starting Address",
                        description : 'Specifies the starting address to sequence conversion',
                        longDescription: `
Start Address will point to the first active memory configuration that will be used:
* Sequence sampling mode: points to the first of a range of memory configurations
* Single sampling mode: points to the active memory configuration that will be sampled **Note: Can be changed at runtime**
                        `,
                        hidden      : false,
                        default     : 0,
                        onChange    : onChangeAddress,
                        options     : AddressOptions
                    },
                    {
                        name        : "endAdd",
                        displayName : "Conversion End Address (Sequence)",
                        description : 'Specifies the ending address to sequence conversion',
                        hidden      : true,
                        default     : 0,
                        onChange    : onChangeAddress,
                        options     : AddressOptions
                    },
                    {
                        name        : "repeatMode",
                        displayName : "Enable Repeat Mode",
                        description : 'Specifies repeat configuration',
                        longDescription : `When "Enable Repeat Mode" is selected, Sampling Operation Mode is repeated until application calls DL_ADC12_disableConversions.`,
                        hidden      : false,
                        default     : false,
                        onChange    : onChangeCustomProfile,
                    },
                    {
                        name        : "sampleMode",
                        displayName : "Sampling Mode",
                        description : 'Specifies source of the sampling signal',
                        hidden      : false,
                        default     : "DL_ADC12_SAMPLING_SOURCE_AUTO",
                        longDescription : `
                        \nSupported sampling modes:
                        \n* Manual:
                        \n  * Application control sampling time via  DL_ADC12_startConversion and DL_ADC12_stopConversion
                        \n* AUTO:
                        \n  * ADC12 controls sampling time via Sample Time 0 and Sample Time 1 parameters in Advance Configuration section
                        `,
                        onChange    : onChangeSampleMode,
                        options     : [
                            {name: "DL_ADC12_SAMPLING_SOURCE_AUTO", displayName: "Auto"},
                            {name: "DL_ADC12_SAMPLING_SOURCE_MANUAL", displayName: "Manual"},
                        ],
                    },
                    {
                        name        : "trigSrc",
                        displayName : "Trigger Source",
                        description : 'Specifies sampling trigger source',
                        hidden      : false,
                        default     : "DL_ADC12_TRIG_SRC_SOFTWARE",
                        longDescription : `
                        \nSupported trigger sources:
                        \n* Software: \
                        \n  * Sampling is triggered when application calls DL_ADC12_startConversion
                        \n* Event:
                        \n  * Sampling is triggered via event fabric. (In this mode the ADC event subscriber must be configured to a valid event channel)
                        \n![ADC12 Trigger & Sample Mode Usage Matrix](../docs/english/sysconfig/images/adc12TriggerSampleMode.png "ADC12 Trigger & Sample Mode Usage Matrix")
                        `,
                        options     : [
                            {name: "DL_ADC12_TRIG_SRC_SOFTWARE", displayName: "Software"},
                            {name: "DL_ADC12_TRIG_SRC_EVENT", displayName: "Event"},
                        ],
                        onChange    : onChangeCustomProfile,
                    },
                    {
                        name        : "dataFormat",
                        displayName : "Conversion Data Format",
                        description : 'Specifies sample conversion data format',
                        hidden      : false,
                        default     : "DL_ADC12_SAMP_CONV_DATA_FORMAT_UNSIGNED",
                        options     : [
                            {name: "DL_ADC12_SAMP_CONV_DATA_FORMAT_UNSIGNED", displayName: "Binary unsigned, right aligned"},
                            {name: "DL_ADC12_SAMP_CONV_DATA_FORMAT_SIGNED", displayName: "Signed binary (2s complement), left aligned"},
                        ],
                        onChange    : onChangeCustomProfile,
                    },
                    /* DL_ADC12_configConversionMem */
                    {
                        name: "GROUP_ADCMEM",
                        displayName: "ADC Conversion Memory Configurations",
                        description: "",
                        longDescription: "",
                        collapsed: true,
                        config: adcMem_configs
                    },
                ]
            },
        ]
    },
]

/* adcMem interrupts + adcMem DMA options */
const adcMemInterruptOptions = [];
const adcMemDMAOptions = [];
for(let memIdx = 0; memIdx <= adcMemRange; memIdx++){
    adcMemInterruptOptions.push({name: "DL_ADC12_INTERRUPT_MEM"+memIdx.toString()+"_RESULT_LOADED",displayName: "MEM"+memIdx.toString()+" result loaded interrupt"})
    adcMemDMAOptions.push({name: "DL_ADC12_DMA_MEM"+memIdx.toString()+"_RESULT_LOADED",displayName: "MEM"+memIdx.toString()+" result loaded interrupt"})
}
/* DL_ADC12_INTERRUPTS */
let interruptOptions = [
    {name: "DL_ADC12_INTERRUPT_OVERFLOW", displayName: "MEMRESX overflow"},
    {name: "DL_ADC12_INTERRUPT_TRIG_OVF", displayName: "Sequence conversion trigger overflow"},
    {name: "DL_ADC12_INTERRUPT_WINDOW_COMP_HIGH", displayName: "MEMRESx result higher than window comparator high threshold"},
    {name: "DL_ADC12_INTERRUPT_WINDOW_COMP_LOW", displayName: "MEMRESx result lower than window comparator low threshold"},
    {name: "DL_ADC12_INTERRUPT_INIFG", displayName: "MEMRESx result is between low and high window comparator threshold"},
    {name: "DL_ADC12_INTERRUPT_DMA_DONE", displayName: "DMA done"},
    {name: "DL_ADC12_INTERRUPT_UNDERFLOW", displayName: "MEMRESX underflow"},
]
/* Add adcMem interrupts */
interruptOptions = interruptOptions.concat(adcMemInterruptOptions);

/* DL_ADC12_EVENT */
let eventOptions = [
    {name: "DL_ADC12_EVENT_WINDOW_COMP_HIGH", displayName: "MEMRESx result higher than window comparator high threshold"},
    {name: "DL_ADC12_EVENT_WINDOW_COMP_LOW", displayName: "MEMRESx result lower than window comparator low threshold"},
    {name: "DL_ADC12_EVENT_INIFG", displayName: "MEMRESx result between high and low window comparator threshold"},
    {name: "DL_ADC12_EVENT_MEM0_RESULT_LOADED", displayName: "MEM0 result loaded interrupt"},
]

/* DL_ADC12_DMA */
let dmaOptions = adcMemDMAOptions;

let hwAvgAdvancedConfig = [];
    hwAvgAdvancedConfig.push(
        /* DL_ADC12_configHwAverage */
        {
            name        : "enableHWAverage",
            displayName : "Configure Hardware Average",
            description : 'Configure ADC12 hardware average',
            hidden      : true,
            default     : false,
            onChange    : onChangeHWAverage
        },
        /* DL_ADC12_configHwAverage */
        {
            name        : "hwNumerator",
            displayName : "Hardware Average Numerator",
            description : 'Specifies the number of conversions to accumulate',
            hidden      : true,
            default     : "DL_ADC12_HW_AVG_NUM_ACC_DISABLED",
            options     : [
                {name: "DL_ADC12_HW_AVG_NUM_ACC_DISABLED", displayName: "Doesn't accumulate conversions"},
                {name: "DL_ADC12_HW_AVG_NUM_ACC_2", displayName: "2 conversions"},
                {name: "DL_ADC12_HW_AVG_NUM_ACC_4", displayName: "4 conversions"},
                {name: "DL_ADC12_HW_AVG_NUM_ACC_8", displayName: "8 conversions"},
                {name: "DL_ADC12_HW_AVG_NUM_ACC_16", displayName: "16 conversions"},
                {name: "DL_ADC12_HW_AVG_NUM_ACC_32", displayName: "32 conversions"},
                {name: "DL_ADC12_HW_AVG_NUM_ACC_64", displayName: "64 conversions"},
                {name: "DL_ADC12_HW_AVG_NUM_ACC_128", displayName: "128 conversions"},
            ],
            onChange    : onChangeCustomProfile,
        },
        /* DL_ADC12_configHwAverage */
        {
            name        : "hwDenominator",
            displayName : "Hardware Average Denominator",
            description : 'Specifies the number to divide the accumulated value by',
            hidden      : true,
            default     : "DL_ADC12_HW_AVG_DEN_DIV_BY_1",
            options     : [
                {name: "DL_ADC12_HW_AVG_DEN_DIV_BY_1", displayName: "1"},
                {name: "DL_ADC12_HW_AVG_DEN_DIV_BY_2", displayName: "2"},
                {name: "DL_ADC12_HW_AVG_DEN_DIV_BY_4", displayName: "4"},
                {name: "DL_ADC12_HW_AVG_DEN_DIV_BY_8", displayName: "8"},
                {name: "DL_ADC12_HW_AVG_DEN_DIV_BY_16", displayName: "16"},
                {name: "DL_ADC12_HW_AVG_DEN_DIV_BY_32", displayName: "32"},
                {name: "DL_ADC12_HW_AVG_DEN_DIV_BY_64", displayName: "64"},
                {name: "DL_ADC12_HW_AVG_DEN_DIV_BY_128", displayName: "128"},
            ],
            onChange    : onChangeCustomProfile,
        },
    );

/*
 * ADC Resolution Configuration:
 */
let resOptions = [
    {name: "DL_ADC12_SAMP_CONV_RES_12_BIT", displayName: "12-bits"},
    {name: "DL_ADC12_SAMP_CONV_RES_10_BIT", displayName: "10-bits"},
    {name: "DL_ADC12_SAMP_CONV_RES_8_BIT", displayName: "8-bits"},
];

let resolutionConfig = {
    name        : "resolution",
    displayName : "Conversion Resolution",
    description : 'Specifies sample conversion resolution',
    hidden      : false,
    default     : "DL_ADC12_SAMP_CONV_RES_12_BIT",
    options     : resOptions,
    onChange    : onChangeCustomProfile,
};
if(Common.isDeviceM0C()){
        resolutionConfig = {
        name        : "resolution",
        displayName : "Conversion Resolution",
        description : 'Specifies sample conversion resolution',
        hidden      : false,
        default     : "DL_ADC12_SAMP_CONV_RES_10_BIT",
        options     : resOptions,
        onChange    : onChangeCustomProfile,
    };
}

config = config.concat([
    {
        name: "GROUP_ADVANCED",
        displayName: "Advanced Configuration",
        description: "",
        longDescription: "",
        collapsed: true,
        config: [
            {
                name        : "totalConversionRate",
                displayName : "Total Conversion Frequency",
                description : '',
                longDescription: `
Summation of all ADC Conversion Memory X Configuration ADC conversion periods.
\n **Note:** the value is only calculated on Auto mode, for Manual Power Down or
Sampling Mode, user controls the value.`,
                hidden      : false,
                getValue    : (inst) => {
                    if(isConversionRateHidden(inst)){
                        return "N/A";
                    }
                    let returnTotal = Common.getUnitPrefix(calculateTotalConversionRate(inst)).str+"Hz";
                    return returnTotal;
                },
                default     : "0Hz"
            },
            /* DL_ADC12_initSingleSample / DL_ADC12_initSeqSample */
            /* Resolution Options vary by device selection */
            resolutionConfig,
            /* DL_ADC12_enableFIFO / DL_ADC12_disableFIFO */
            {
                name        : "enableFIFO",
                displayName : "Enable FIFO Mode",
                description : 'Enables FIFO mode',
                hidden      : false,
                default     : false,
                onChange    : onChangeCustomProfile,
            },
            /* DL_ADC12_setPowerDownMode */
            {
                name        : "powerDownMode",
                displayName : "Power Down Mode",
                description : 'Configures ADC12 power down mode',
                longDescription: `
Power down modes:
\n* AUTO: ADC is powered down on completion of a conversion **if there is no pending trigger**
\n* MANUAL: ADC remains powered on as long as it is enabled through software.
`,
                hidden      : false,
                default     : "DL_ADC12_POWER_DOWN_MODE_AUTO",
                options     : [
                    {name: "DL_ADC12_POWER_DOWN_MODE_AUTO", displayName: "Auto"},
                    {name: "DL_ADC12_POWER_DOWN_MODE_MANUAL", displayName: "Manual"},
                ],
                onChange    : onChangePowerDownMode,
            },
            {
                name: "GROUP_HWAVG_ADVANCED",
                displayName: "Hardware Average Configuration",
                description: "",
                longDescription: "",
                collapsed: false,
                config: hwAvgAdvancedConfig,
            },
            /* DL_ADC12_setSampleTime0 */
            {
                name        : "sampleTime0",
                displayName : "Desired Sample Time 0",
                description : 'Set sample time 0, specifies the sample time in seconds',
                hidden      : false,
                default     : "0 ms",
                readOnly    : false,
                onChange    : onChangeCustomProfile,
            },
            {
                name        : "sampleTime0ActualDisplay",
                displayName : "Actual Sample Time 0",
                description : 'Actual Sample Time 0',
                hidden      : false,
                default     : "0ms",
                getValue    : getActualDisplaySampleTime0,
            },
            {
                name        : "sampleTime0Actual",
                hidden      : true,
                default     : 0,
                getValue    : getActualSampleTime0,
            },
            {
                name        : "sampleTime0_cycles",
                displayName : "Sample Time 0 (ADCCLK cycles)",
                description : 'Set sample time 0, specifies the sample time in number of ADCCLK cycles',
                hidden      : true,
                default     : 0,
                range       : [0,65535],
                getValue    : (inst) => {
                    if(inst.sampleTime0Actual === NaN){
                        return 0;
                    }
                    let samplingCycles = Math.round(inst.sampleTime0Actual*inst.sampleClk_Freq);
                    return samplingCycles
                }
            },
            /* DL_ADC12_setSampleTime1 */
            {
                name        : "sampleTime1",
                displayName : "Desired Sample Time 1",
                description : 'Set sample time 1, specifies the sample time in seconds',
                hidden      : false,
                default     : "0 ms",
                readOnly    : false,
                onChange    : onChangeCustomProfile,
            },
            {
                name        : "sampleTime1ActualDisplay",
                displayName : "Actual Sample Time 1",
                description : 'Actual Sample Time 1',
                hidden      : false,
                default     : "0ms",
                getValue    : getActualDisplaySampleTime1,
            },
            {
                name        : "sampleTime1Actual",
                hidden      : true,
                default     : 0,
                getValue    : getActualSampleTime1,
            },
            {
                name        : "sampleTime1_cycles",
                displayName : "Sample Time 1 (ADCCLK cycles)",
                description : 'Set sample time 1, specifies the sample time in number of ADCCLK cycles',
                hidden      : true,
                default     : 0,
                range       : [0,65535],
                getValue    : (inst) => {
                    if(inst.sampleTime1Actual === NaN){
                        return 0;
                    }
                    let samplingCycles = Math.round(inst.sampleTime1Actual*inst.sampleClk_Freq);
                    return samplingCycles
                }
            },
            {
                name: "GROUP_WINCOMP_ADVANCED",
                displayName: "Window Comparator Configuration",
                description: "",
                longDescription: "",
                collapsed: false,
                config: [
                    {
                        name        : "enableWinComp",
                        displayName : "Configure Window Comparator",
                        description : '',
                        hidden      : true,
                        default     : false,
                        onChange    : onChangeWinComp
                    },
                    {
                        name        : "adcMemWinComSelEn",
                        displayName : "Window Comparator Enabled for",
                        description : '',
                        hidden      : true,
                        default     : "None",
                        getValue    : getADCMemWithWinCompEn,
                    },
                    /* DL_ADC12_configWinCompLowThld */
                    {
                        name        : "configWinCompLowThld",
                        displayName : "Window Comparator Low Threshold",
                        description : 'Configures window comparator low threshold',
                        hidden      : true,
                        default     : 0,
                        isInteger   : true,
                        range       : [0,65535],
                        onChange    : onChangeCustomProfile,
                    },
                    /* DL_ADC12_configWinCompHighThld */
                    {
                        name        : "configWinCompHighThld",
                        displayName : "Window Comparator High Threshold",
                        description : 'Configures window comparator high threshold',
                        hidden      : true,
                        default     : 0,
                        isInteger   : true,
                        range       : [0,65535],
                        onChange    : onChangeCustomProfile,
                    },
                ]
            },
        ]
    },
    {
        name: "GROUP_INTERRUPTS",
        displayName: "Interrupt Configuration",
        description: "",
        longDescription: "",
        collapsed: true,
        config: [
            /* DL_ADC12_enableInterrupt / DL_ADC12_disableInterrupt */
            {
                name        : "enabledInterrupts",
                displayName : "Enable Interrupts",
                description : 'Enable ADC12 interrupt',
                hidden      : false,
                default     : [],
                minSelections: 0,
                options     : interruptOptions,
                getDisabledOptions:(inst) => {
                    let disabledOptions = [];
                    let disabledADCMEMOptions = [];
                    let disabledWinCompOptions = [];
                    if(!inst.enableFIFO){
                        if(inst.samplingOperationMode == "single"){
                            for(let adcMemIdx=1; adcMemIdx<=adcMemRange; adcMemIdx++){
                                if(!inst.enabledADCMems.includes(adcMemIdx)){
                                    disabledADCMEMOptions.push(interruptOptions[adcMemIdx+7]);
                                }
                            }
                        }
                        else if(inst.samplingOperationMode == "sequence"){
                        disabledADCMEMOptions = interruptOptions.slice(7,inst.startAdd+7);
                            if(inst.endAdd >= inst.startAdd){
                                disabledADCMEMOptions = disabledADCMEMOptions.concat(interruptOptions.slice(inst.endAdd+8));
                            }
                        }
                    }
                    if(!inst.enableWinComp){
                        disabledWinCompOptions = disabledWinCompOptions.concat(interruptOptions[2]);
                        disabledWinCompOptions = disabledWinCompOptions.concat(interruptOptions[3]);
                        disabledWinCompOptions = disabledWinCompOptions.concat(interruptOptions[4]);
                    }
                    else{
                        disabledWinCompOptions = [];
                    }
                    disabledOptions = disabledADCMEMOptions.concat(disabledWinCompOptions);
                    return disabledOptions.map((option => ({name: option.name, reason: "outside range"})));
                },
                onChange    : onChangeInterrupts
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
        name: "GROUP_DMA",
        displayName: "DMA Configuration",
        description: "",
        longDescription: "",
        collapsed: true,
        config: [
            /* DL_ADC12_enableDMA / DL_ADC12_disableDMA */
            {
                name        : "configureDMA",
                displayName : "Configure DMA Trigger",
                description : 'Configure DMA for data transfer',
                hidden      : false,
                default     : false,
                onChange    : onChangeConfigureDMA,
            },
            {
                name        : "enableDMA",
                displayName : "Enable DMA Trigger",
                description : 'Enables DMA for data transfer',
                longDescription: `If left unchecked, the module-specific enable DMA API should
                be called in the application code.`,
                hidden      : true,
                default     : true,
                onChange    : onChangeCustomProfile,
            },
            /* DL_ADC12_setDMASamplesCnt */
            {
                name        : "sampCnt",
                displayName : "DMA Samples Count",
                description : 'Set number of ADC results to be transfered on a DMA trigger',
                hidden      : true,
                default     : 0,
                isInteger   : true,
                range       : [0,24],
                onChange    : onChangeCustomProfile,
            },
            /* DL_ADC12_enableDMATrigger / DL_ADC12_disableDMATrigger */
            {
                name        : "enabledDMATriggers",
                displayName : "Enable DMA Triggers",
                description : 'Enable ADC12 DMA triggers',
                hidden      : true,
                default     : [],
                minSelections: 0,
                options     : dmaOptions,
                onChange    : onChangeCustomProfile,
            },
        ]
    },
    {
        name: "GROUP_EVENTS",
        displayName: "Event Configuration",
        description: "",
        longDescription: "",
        collapsed: true,
        config: [
            /* DL_ADC12_setPublisherChanID */
            {
                name        : "pubChanID",
                displayName : "Event Publisher Channel ID",
                description : 'Sets the event publisher channel id',
                hidden      : false,
                default: 0,
                options: EVENT.getPublisherOptions,
                getDisabledOptions: EVENT.getPublisherDisabledOptions,
                onChange    : onChangeCustomProfile,
            },
            /* DL_ADC12_setSubscriberChanID */
            {
                name        : "subChanID",
                displayName : "Event Subscriber Channel ID",
                description : 'Sets the event subscriber channel id',
                hidden      : false,
                default: 0,
                options: EVENT.getSubscriberOptions,
                getDisabledOptions: EVENT.getSubscriberDisabledOptions,
                onChange    : onChangeCustomProfile,
            },
            /* DL_ADC12_enableEvent / DL_ADC12_disableEvent */
            {
                name        : "enabledEvents",
                displayName : "Enable Events",
                description : 'Enable ADC12 event',
                hidden      : false,
                default     : [],
                minSelections: 0,
                options     : eventOptions,
                onChange    : onChangeCustomProfile,
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
                    if(inst.subChanID != 0){
                        options.push({name: inst.subChanID.toString() + "sub"});
                    }
                    return options;
                },
                getValue: (inst) => {
                    let result = [];
                    if(inst.pubChanID != 0){
                        result.push(inst.pubChanID.toString() + "pub");
                    }
                    if(inst.subChanID != 0){
                        result.push(inst.subChanID.toString() + "sub");
                    }
                    if(result.length == 0){
                        result = [""];
                    }
                    return result;
                }
            }
        ]
    },
])

/* Add Pinmux Peripheral Configuration group */
config = config.concat(Common.getGPIOGroupConfig());

if(Common.isDeviceFamily_PARENT_MSPM0G1X0X_G3X0X()){
    config = config.concat([
        {
            name        : "disChan12",
            displayName : "Disable Channel 12 Pin",
            description : 'Disable Channel 12 Pin Resource from being reserved',
            hidden      : false,
            default     : false,
        },
    ]);
}
if(Common.isDeviceFamily_PARENT_MSPM0GX51X()){
    config = config.concat([
        {
            name        : "disChan11",
            displayName : "Disable Channel 11 Pin",
            description : 'Disable Channel 11 Pin Resource from being reserved',
            hidden      : false,
            default     : false,
        },
    ]);
}

function moduleInstances(inst){
    let modInstances = [];
    /*
    * Gets a DMA module if available
    */
    if(inst.configureDMA){
        let mod = {
            name: "DMA_CHANNEL",
            displayName: "DMA Channel",
            moduleName: '/ti/driverlib/DMAChannel',
            group: "GROUP_DMA",
            args: {
                //triggerSelect: inst.dmaPassedSolution
            },
            requiredArgs: {
                hideTriggerSelect: true
                /* empty for now */
            },

        }
        modInstances.push(mod);
        /* TODO: pickup here */
    }

    /*
     * Gets a Peripheral GPIO Configuration submodule
     */
    /* CONDITIONS CODE START */
    // ADC Channel 0-9 Pins
    let adcConfig = [...new Array(26)].map(() => false);

    let ind = 0;
    for(let adcMemIdx = 0; adcMemIdx <= adcMemRange; adcMemIdx++){
        if( inst.enabledADCMems.includes(adcMemIdx) ){
            let tempIdx = inst["adcMem" + adcMemIdx.toString() + "chansel"]
            let tempIdxTrim = tempIdx.slice(20);
            ind = parseInt(tempIdxTrim);
            /* Both MSPM0 families can configure Channels 1-8 to pins */
            if(ind<9){
                adcConfig[ind] = true;
            }
            /* MSPM0L can also configure channels 8-9 to pins */
            else if(Common.isDeviceM0L() && ind<10){
                adcConfig[ind] = true;
            }

            if(ind<9){
                adcConfig[ind] = true;
            }
            /* MSPM0L11XX_L13XX can also configure channel 9 to pins */
            else if((Common.isDeviceFamily_PARENT_MSPM0L11XX_L13XX() || Common.isDeviceM0C() || Common.isDeviceFamily_PARENT_MSPM0GX51X()) && ind<10){
                adcConfig[ind] = true;
            }
            /* MSPM0L122X_L222X and M0GX51X can also configure channel 10 to pins */
            else if((Common.isDeviceFamily_PARENT_MSPM0L122X_L222X() || Common.isDeviceFamily_PARENT_MSPM0GX51X()) && ind==10){
                adcConfig[ind] = true;
            }
            /* MSPM0L122X_L222X can also configure channel 11 to pins */
            else if((Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()) && ind==11){
                adcConfig[ind] = true;
            }
            /* MSPM0L122X_L222X and M0GX51X can also configure channels 12-14 to pins */
            else if((Common.isDeviceFamily_PARENT_MSPM0L122X_L222X() || Common.isDeviceFamily_PARENT_MSPM0GX51X()) && ind>11 && ind<15){
                adcConfig[ind] = true;
            }
            /* MSPM0L122X_L222X can also configure channels 15-25 to pins */
            else if(Common.isDeviceFamily_PARENT_MSPM0L122X_L222X() && ind>14 && ind<26){
                adcConfig[ind] = true;
            }
            /* Special case of MSPM0G1X0X_G3X0X Channel 12 */
            if(Common.isDeviceFamily_PARENT_MSPM0G1X0X_G3X0X() && ind == 12){
                adcConfig[ind] = true;
            }
            /* Special case of M0GX51X Channel 11 */
            if(Common.isDeviceFamily_PARENT_MSPM0GX51X() && ind == 11){
                adcConfig[ind] = true;
            }

        }
    }
    /* CONDITIONS CODE END */

    for(let ix = 0; ix < 26; ix++){
        /* ADC Channel Pin Configuration */
        if(ix == 12 && inst.disChan12) continue;
        if(ix == 11 && inst.disChan11) continue;
        Common.pushGPIOConfigInstOnlyIntRes(inst, modInstances,   adcConfig[ix],    "adcPin"+ix,
        "C"+ix, "ADC12 Channel "+ix+" Pin",
        "INPUT");
    }

    return modInstances;
}

/*
 *  ======== devSpecific ========
 *  Device-specific extensions to be added to base module configuration
 */
let devSpecific = {

    /* This is where you should be putting all of your configurable information.
    If you want a configurable or variable that is not visible, you can make it
    hidden
     */

    config: config,

    maxInstances: Common.peripheralCount("ADC"),

    /* override generic requirements with  device-specific reqs (if any) */
    validate: validate,
    validatePinmux: validatePinmux,

    pinmuxRequirements: pinmuxRequirements,

    filterHardware: filterHardware,

    moduleInstances: moduleInstances,

    /* override device-specific templates */
    templates: {
        boardc: "/ti/driverlib/adc12/ADC12.Board.c.xdt",
        boardh: "/ti/driverlib/adc12/ADC12.Board.h.xdt",
        Call: true,
        Reset: true,
        Power: true,
        GPIO: true,
        Function: true
    },
    modules: setRequiredModules,

    _getPinResources: _getPinResources
};

function setRequiredModules(inst){
    let theModules = ["Board", "SYSCTL", "EVENT"]
    let enabledVREF = false;
    for(let adcMemIdx = 0; adcMemIdx <= adcMemRange; adcMemIdx++){
        if ( inst.enabledADCMems.includes(adcMemIdx) ){
            if((inst["adcMem"+adcMemIdx+"vref"])=="VREF"){
                enabledVREF = true;
            }
        }
    }
    if(enabledVREF){
        theModules.push("VREF");
    }
    if(inst.configureDMA){
        theModules.push("DMA");
    }

    let kwargs = theModules;
    let modArray = [];

    for (let args = kwargs.length - 1; args >= 0; args--) {
        let modPath = kwargs[args];
        if (modPath.indexOf('/') == -1) {
            modPath = "/ti/driverlib/" + modPath;
        }
        modArray.push({
            name      : modPath.substring(modPath.lastIndexOf('/') + 1),
            moduleName: modPath,
            hidden    : true
        });
    }

    return modArray;



}

/*
 *  ======== extend ========
 *  Extends a base exports object to include any device specifics
 *
 *  This function is invoked by the generic module module to
 *  allow us to augment/override as needed for the MSP432.
 */
function extend(base)
{
    /* merge and overwrite base module attributes */
    let result = Object.assign({}, base, devSpecific);

    /* concatenate device-specific configs */
    result.config = base.config.concat(devSpecific.config);

    return (result);
}

/*
 *  ======== exports ========
 *  Export device-specific extensions to base exports
 */
exports = {
    /* required function, called by base module module */
    extend: extend
};
