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
 *  ======== sysctlTimerMSP432.js ========
 */

"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");
let Options = system.getScript("/ti/driverlib/sysctl/SYSCTLMSPM0options.js");
let { ClockFrequencies, ClockConfig, ConfigurableList } = system.getScript("/ti/driverlib/sysctl/SYSCTLMSPM0Clocks.js");

function validatePowerPolicy(inst, validation){
    if(inst.runPowerPolicy != "RUN0"){
        validation.logInfo("Current Power Policy with CPU Enabled is "+ inst.runPowerPolicy + ".", inst);
    }

    if((inst.runPowerPolicy.slice(-1) !== inst.powerPolicy.slice(-1)) && inst.powerPolicy.match(/SLEEP\d/)){
        validation.logWarning("Incompatible transition between RUN and SLEEP power policies of different numbers. The end numbers must match. Sleep will be changed to match RUN.", inst, ["runPowerPolicy", "powerPolicy"]);
    }

    if(inst.runPowerPolicy == "RUN2" && inst.powerPolicy == "STOP0"){
        validation.logInfo("SYSOSC will remain disabled in STOP0 since jumping from RUN2", inst, ["powerPolicy"]);
    }

    if(inst.runPowerPolicy.match(/RUN[12]/) && inst.powerPolicy == "STOP1"){
        validation.logWarning("Illogical transition between RUN policy and STOP1", inst, ["runPowerPolicy", "powerPolicy"]);
    }


    // check that MF/MFP clocks are disabled in RUN1/2
    if(inst.runPowerPolicy != "RUN0"){
        let errStub = " cannot be enabled and used during RUN1 or RUN2 policy."+
        "\nDisable or change the run policy by sourcing MCLK from something other than LFCLK";
        if(inst.clockTreeEn){
            let mod = system.modules["/ti/clockTree/gate.js"];
            let mfclkgate = _.find(mod.$instances, ['$name', 'MFCLKGATE']);
            let gates = [ mfclkgate ];

            if(!_.isUndefined(system.clockTree['MFPCLKGATE'])){
                let mfpclkgate = _.find(mod.$instances, ['$name', 'MFPCLKGATE']);
                gates.push(mfpclkgate);
            }

            let offendingGates = _.filter(gates, (g) => g.enable === true);
            if(offendingGates.length > 0){
                _.each(offendingGates, (h) => {
                    validation.logError(_.trimEnd(h.$name, "GATE") + errStub, h, "enable");
                })
            }
        } else {
            if(inst.MFPCLKEn){
                validation.logError("MFPCLK" + errStub, inst, "MFPCLKEn");
            }
            if(inst.MFCLKEn){
                validation.logError("MFCLK" + errStub, inst, "MFCLKEn");
            }
        }
    }

    // MFPSourcing in STOP0 mode
    if(Common.isDeviceM0G() && inst.powerPolicy.match(/STOP[01]/)) {
        let errStr = "MFPCLK cannot be sourced from HFCLK and remain operational in any STOP mode";
        if(inst.clockTreeEn) {
            let mod = system.modules["/ti/clockTree/gate.js"];
            let mfpclkGate = _.find(mod.$instances, ['$name', 'MFPCLKGATE']);
            mod = system.modules["/ti/clockTree/mux.js"];
            let mfpclkMux = _.find(mod.$instances, ['$name', 'MFPCLKMUX']);
            if(mfpclkGate.enable && mfpclkMux.inputSelect.match(/HFCLK/)){
                validation.logError(errStr, mfpclkMux, "inputSelect");
            }
        } else {
            if(inst.MFPCLKEn && inst.MFPCLKSource === "HFCLK") {
                validation.logError(errStr, inst, "MFPCLKSource");
            }
        }
    }

    // check for HSCLKs in RUN1/2
    if(Common.isDeviceM0G() && inst.runPowerPolicy != "RUN0"){
        if(inst.clockTreeEn){

            // Checks for remaining HFCLK enabled
            let mod = system.modules["/ti/clockTree/divider.js"];

            let pllClk0Inst = _.find(mod.$instances, ['$name', 'PLL_CLK0_DIV']);
            let pllClk1Inst = _.find(mod.$instances, ['$name', 'PLL_CLK1_DIV']);
            let pllClk2XInst = _.find(mod.$instances, ['$name', 'PLL_CLK2X_DIV']);

            let pllInstances = [ pllClk0Inst, pllClk1Inst, pllClk2XInst ];

            mod = system.modules["/ti/clockTree/mux.js"];
            let hsclkMuxInst = _.find(mod.$instances, ['$name', 'HSCLKMUX']);
            let canclkMuxInst = _.find(mod.$instances, ['$name', 'CANCLKMUX']);
            let fccMux = _.find(mod.$instances, ['$name', 'FCCSELCLKMUX']);
            let exclkMux = _.find(mod.$instances, ['$name', 'EXCLKMUX']);
            let exhfclkMux = _.find(mod.$instances, ['$name', 'EXHFMUX']);
            let mfpclkMux = _.find(mod.$instances, ['$name', 'MFPCLKMUX']);

            let pllMuxes = [ hsclkMuxInst, canclkMuxInst, fccMux, exclkMux ];
            // TODO: later add ADC mux if applicable
            // canclk mux is not necessary because code is not generated on behalf of
            // CANCLK
            let hfMuxes = [ hsclkMuxInst, exclkMux, fccMux, mfpclkMux ];

            if(_.isUndefined(pllClk0Inst) || _.isUndefined(pllClk1Inst) ||
               _.isUndefined(pllClk2XInst) ||
               _.isUndefined(hsclkMuxInst) || _.isUndefined(canclkMuxInst) ||
               _.isUndefined(fccMux) || _.isUndefined(exclkMux) ||
               _.isUndefined(exhfclkMux))
            {
                throw 'Not all CLK Power check elements are defined appropriately';
            }


            let offendingPLL = _.filter(pllInstances, (i) => i.enable === true);
            let offendingMux = _.filter(pllMuxes, (m) => !_.isNull(m.inputSelect.match(/PLL/)));
            if(offendingPLL.length > 0){
                let errStr = "SYSPLL cannot be enabled during RUN1 or RUN2 policy.\nChange Run Policy by sourcing MCLK from something other than LFCLK";
                _.each(offendingPLL.concat(offendingMux), (p) => validation.logError(errStr, p));
            }
            let offendingHF = _.filter(hfMuxes, (m) => !_.isNull(m.inputSelect.match(/HFCLK/)))
            if(offendingHF.length > 0){
                let errStr = "HFCLK cannot be enabled and used during RUN1 or RUN2 policy.\nChange Run Policy by sourcing MCLK from something other than LFCLK";
                _.each(offendingHF, (h) => validation.logError(errStr, h))
            }

        } else {

            let potentialInstances = [ "SYSPLL_CLK0En", "SYSPLL_CLK1En", "SYSPLL_CLK2XEn", "useHFCLK_Manual" ];
            let offendingInstances = _.filter(potentialInstances, (x) => inst[x] == true);
            if(offendingInstances.length > 0)
            {
                offendingInstances.push("runPowerPolicy");
                validation.logError("High-Speed clocks cannot be enabled during a the run power policy " + inst.runPowerPolicy +
                ". Will not operate correctly", inst, offendingInstances);
            }

        }
    }
}

/*
 *  ======== validatePinmux ========
 *  Validate this inst's configuration
 *
 *  param inst       - module instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validatePinmux(inst, validation){
    /* CLKOUT Validation */
    if(inst.enableEXCLK){
        try{
            let clkOutPin = inst.peripheral.clkOutPin.$solution.packagePinName;
            let validPinSet = validClkOutPinSet(inst);

            if (!validPinSet.includes(clkOutPin)){
                validation.logError("Currently selected CLK_OUT pin not available when routing a high frequency. Please select a different CLK_OUT source or a different pin. See device documentation for pin limitations.",
                inst, ["EXCLKSource"]);
            }
            if(inst.ClkOutForceHighDrive){
                if(inst.VDD < 2.7){
                    validation.logError("When High Drive is enabled VDD supplied voltage cannot be less than 2.7V.",
                    inst, ["VDD"]);
                }
            }
        } catch (e){
            // do nothing
        }
    }
    /* NRST / PA1 Validation */
    if(!inst.disableNRSTPin){
        let keys = Common.getModuleKeys();
        let usedPins = Common.getUsedPins(keys);
        let usedNRST = (usedPins.usedPinNames.filter(e => (!_.isNull(e)?e.includes("NRST"):false)));
        let warningCondition = (usedNRST.filter(e => (!_.isNull(e)?e.includes("PA1"):false)));
        if(warningCondition.length > 0){
            validation.logWarning("Enabling NRST functionality while PA1/NRST pin is used by the application can cause unexpected reset.",
                inst, ["disableNRSTPin"]);
        }
    }
}

/*
 *  ======== validateSYSCTL ========
 *  Validate this inst's configuration
 *
 *  param inst       - module instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validateSYSCTL(inst, validation)
{
    if(system.modules["/ti/drivers/Board"]){
        if(!inst.driversEn){
            validation.logError("TI Drivers are being configured, must enable Driver configuration.", inst, ["driversEn"]);
        }
        else if(inst.driversEn){
            validation.logInfo("Power & Systems options are disabled from being configured in SysCtl.", inst, ["driversEn"]);
        }
    }
    else if(inst.driversEn){
        validation.logInfo("TI Drivers are not currently being configured. This option will lock other configurations.", inst, ["driversEn"]);
    }


    validatePowerPolicy(inst, validation);

    if(!inst.clockTreeEn){
    /* HFCLK Validation */
    if(Common.isDeviceM0G() || Common.isDeviceFamily_PARENT_MSPM0L122X_L222X() || Common.isDeviceM0C()){
        /* Validate case of disabled HFCLK */
        if(!["None"].includes(inst.usesHFCLK) && !inst.useHFCLK_Manual){
            validation.logError("Must enable HFCLK for this configuration", inst, ["useHFCLK_Manual"]);
        }
        if(["None"].includes(inst.usesHFCLK) && inst.useHFCLK_Manual){
            validation.logInfo("HFCLK is not being sourced by anything, initialization code will be generated once it's being used.",
             inst, ["useHFCLK_Manual"]);
        }
    }
    if(inst.MCLKSource === "HSCLK"){
        /* Wait state validation */
        /* Validate wait states with frequency ranges */
        if(inst.waitState == "0"){
            if(inst.MCLK_Freq > 24000000){
                validation.logError("Exceeded maximum frequency for selected wait state", inst, ["waitState","MCLK_Freq_unit"]);
            }
        }
        else if(inst.waitState == "1"){
            if(inst.MCLK_Freq > 48000000){
                validation.logError("Exceeded maximum frequency for selected wait state", inst, ["waitState","MCLK_Freq_unit"]);
            }
        }
        else if(inst.waitState == "2"){
            if(inst.MCLK_Freq > 80000000){
                validation.logError("Exceeded maximum frequency for selected wait state", inst, ["waitState","MCLK_Freq_unit"]);
            }
        }
    }

    /* SYSPLL Validation */
    if(Common.isDeviceM0G()){
        /* SYSPLL frequency range must be between [4MHz, 48MHz] */
        if (inst.SYSPLLSource == "HFCLK")
        {
            if ((inst.HFCLK_Freq < 4000000) ||
                (inst.HFCLK_Freq > 48000000))
            {
                if(inst.useSYSPLL){
                    validation.logError("SYSPLL input frequency must be within [4MHz, 48MHz]", inst, ["HFCLK_Freq","SYSPLL_InputCLKFreqRange"]);
                }
            }
        }
        /* SYSOSC frequency must be 32MHz when used as SYSPLL source. */
        else if (inst.SYSPLLSource == "SYSOSC"){
            if(inst.SYSOSC_Freq != 32000000){
                if(inst.useSYSPLL){
                    validation.logError("SYSPLL input frequency must be 32MHz when SYSOSC is source.", inst, ["SYSOSC_Freq","SYSPLL_InputCLKFreqRange"]);
                }
            }
        }
        if(inst.MCLKSource === "HSCLK"){
            /* Validate HSCLK Sources */
            if(inst.HSCLKSource === "SYSPLLCLK0" && !inst.SYSPLL_CLK0En){
                validation.logError("SYSPLL Clock 0 is not currently enabled", inst, "HSCLKSource");
                validation.logError("HSCLK has selected SYSPLL Clock 0 as its source, which is currently disabled.", inst, "SYSPLL_CLK0En");
            }
            else if(inst.HSCLKSource === "SYSPLLCLK2X" && !inst.SYSPLL_CLK2XEn){
                validation.logError("SYSPLL Clock 2 is not currently enabled", inst, "HSCLKSource");
                validation.logError("HSCLK has selected SYSPLL Clock 2 as its source, which is currently disabled.", inst, "SYSPLL_CLK2XEn");
            }
        }
        if (inst.SYSPLL_Freq_CLK0 > 80000000) {
            validation.logError("Calculated frequency is greater than 80MHz, which is a spec violation for this device.", inst, "SYSPLL_Freq_CLK0");
        }
        if (inst.SYSPLL_Freq_CLK1 > 80000000) {
            validation.logError("Calculated frequency is greater than 80MHz, which is a spec violation for this device.", inst, "SYSPLL_Freq_CLK1");
        }
        if (inst.SYSPLL_Freq_CLK2X > 80000000) {
            validation.logError("Calculated frequency is greater than 80MHz, which is a spec violation for this device.", inst, "SYSPLL_Freq_CLK2X");
        }

        // CAN CLK specific validation
        if(inst.CANCLKSource != "None"){
            if((inst.CANCLKSource == "SYSPLLCLK1") && !inst.SYSPLL_CLK1En){
                validation.logError("SYSPLLCLK1 is not enabled.", inst, "SYSPLL_CLK1En");
            }
        }
    }

    /* MSPM0L122X_L222X Unavailable Sources Validation */
    if(Common.isDeviceFamily_PARENT_MSPM0L122X_L222X() || Common.isDeviceM0C()){
        if(["SYSPLLOUT1"].includes(inst.EXCLKSource)){
            validation.logError("Please select a valid source", inst, "EXCLKSource");
        }
    }
    /* MSPM0L11XX_L13XX Unavailable Sources Validation */
    if(Common.isDeviceFamily_PARENT_MSPM0L11XX_L13XX()){
        if(["SYSPLLOUT1","HFCLK"].includes(inst.EXCLKSource)){
            validation.logError("Please select a valid source", inst, "EXCLKSource");
        }
        if(inst.MCLKSource === "HSCLK"){
            validation.logError("Please select a valid source", inst, "MCLKSource");
        }
        if(["LFCLK_IN","LFXT"].includes(inst.LFCLKSource)){
            validation.logError("Please select a valid source", inst, "LFCLKSource");
        }
    }

    /* Disable SYSOSC validation */
    if(inst.disableSYSOSC){
        validation.logInfo("SYSOSC has been disabled through MCLK source configuration", inst, ["enableSYSOSCFCL","SYSOSC_Freq"]);
        if(inst.MFCLKEn){
            validation.logError("SYSOSC has been disabled through MCLK source configuration", inst, "MFCLKEn");
        }
        if(inst.MFPCLKEn && (inst.MFPCLKSource === "SYSOSC")){
            validation.logError("SYSOSC has been disabled through MCLK source configuration", inst, "MFPCLKSource");
        }
        if(!_.isUndefined(inst.usesSYSPLL)){
            if(inst.useSYSPLL && inst.SYSPLLSource === "SYSOSC"){
                validation.logError("SYSOSC has been disabled through MCLK source configuration", inst, "SYSPLLSource");
            }
        }
    }
    else{
        if(!_.isUndefined(inst.enableROSC)){
            /* FCL Validation for devices that only have External Rosc supported */
            if(inst.enableSYSOSCFCL && !inst.enableROSC && Common.hasExternalRoscOnly()){
                validation.logError("External ROSC must be enabled for FCL usage with this device. See the device datasheet for more details.", inst, ["enableSYSOSCFCL", "enableROSC"]);
            }
            else if(!inst.enableSYSOSCFCL && inst.enableROSC){
                validation.logWarning("If ROSC has been enabled, it's recommended Frequency Correction Loop is enabled.", inst, ["enableSYSOSCFCL", "enableROSC"]);
            }
        }
    }

    /* CLK_OUT Validation */
    if(inst.enableEXCLK){
        if(Common.isDeviceM0G()){
            if(inst.EXCLKSource === "SYSPLLOUT1" && !inst.SYSPLL_CLK1En){
                validation.logError("SYSPLL Clock 1 is not currently enabled", inst, "EXCLKSource");
                validation.logError("CLK_OUT has selected SYSPLL Clock 1 as its source, which is currently disabled.", inst, "SYSPLL_CLK1En");
            }
        }
        else if(inst.EXCLKSource === "SYSOSC" && inst.disableSYSOSC){
            validation.logError("SYSOSC is currently disabled by MCLK", inst, "EXCLKSource");
        }
        else if(inst.EXCLKSource === "MFPCLK" && !inst.MFPCLKEn){
            validation.logError("MFPCLK is currently disabled.", inst, "EXCLKSource");
        }

        if(inst.EXCLKDivider === "DISABLE"){
            if(inst.EXCLKSource === "ULPCLK" || inst.EXCLKSource === "MFPCLK"){
                validation.logError("CLK_OUT Divider must be enabled for selected source.", inst, ["EXCLKSource", "EXCLKDivider"]);
            }
        }
    }

    /* FCC Clock Source validation */
    if(inst.enableFCC){
        if((inst.fccClkSrc == "SYSOSC")&&(inst.disableSYSOSC)){
            validation.logError("Must enable SYSOSC for this configuration", inst, ["fccClkSrc","disableSYSOSC"]);
        }
        if((inst.fccClkSrc == "CLK_OUT")&&(!inst.enableEXCLK)){
            validation.logError("Must enable CLK_OUT for this configuration", inst, ["fccClkSrc","enableEXCLK"]);
        }
        if(Common.isDeviceM0G() || Common.isDeviceFamily_PARENT_MSPM0L122X_L222X() || Common.isDeviceM0C()){
            if((inst.fccClkSrc == "HFCLK")&&(!inst.useHFCLK_Manual)){
                validation.logError("Must enable HFCLK for this configuration", inst, ["fccClkSrc"]);
            }
        }
        if(Common.isDeviceM0G()){
            if((inst.fccClkSrc == "SYSPLLCLK0")&&(!inst.SYSPLL_CLK0En)){
                validation.logError("Must enable SYSPLLCLK0 for this configuration", inst, ["fccClkSrc","SYSPLL_CLK0En"]);
            }
            if((inst.fccClkSrc == "SYSPLLCLK1")&&(!inst.SYSPLL_CLK1En)){
                validation.logError("Must enable SYSPLLCLK1 for this configuration", inst, ["fccClkSrc","SYSPLL_CLK1En"]);
            }
            if((inst.fccClkSrc == "SYSPLLCLK2X")&&(!inst.SYSPLL_CLK2XEn)){
                validation.logError("Must enable SYSPLLCLK2X for this configuration", inst, ["fccClkSrc","SYSPLL_CLK2XEn"]);
            }
        }
    }

    /* Special case MCLK validation */
    if(inst.MCLKSource == "LFCLK"){
        let COMPMod = system.modules["/ti/driverlib/COMP"];
        if (COMPMod){ if(COMPMod.$instances.length>0){
            let COMPerror = false;
            for(let COMPinst of COMPMod.$instances){
                if(COMPinst.compMode == "DL_COMP_MODE_FAST"){
                    COMPerror = true;
                }
            }
            if(COMPerror){
                validation.logError("LFCLK cannot source MCLK if COMP is enabled on Fast Mode.", inst, ["MCLKSource"]);
            }
        }}

        let OPAMod = system.modules["/ti/driverlib/OPA"];
        if (OPAMod){ if(OPAMod.$instances.length>0){
            validation.logError("LFCLK cannot source MCLK if OPA is enabled.", inst, ["MCLKSource"]);
        }}
    }

    /* Special Case: DAC12 Validation */
    let DACMod = system.modules["/ti/driverlib/DAC12"];
    if (DACMod){
        if (DACMod.$static.dacEnable && !inst.MFPCLKEn) {
            validation.logError("MFPCLK must be enabled when DAC12 peripheral is added.", inst, ["MFPCLKEn"]);
        }
    }

    /* MFPCLK Frequency Validation */
    if(inst.MFPCLKEn && inst.MFPCLK_Freq > 4000000){
        validation.logError("MFPCLK frequency must be under 4MHz.", inst, ["HFCLK4MFPCLKDIV","MFPCLK_Freq_unit"]);
    }

    /* VREF/MFCLK Validation */
    if(!inst.MFCLKEn){
        let vrefInstance = system.modules["/ti/driverlib/VREF"];
        if (vrefInstance){
            if(vrefInstance.$static.advClockConfigEnable){
                if((vrefInstance.$static.advClkSrc == "DL_VREF_CLOCK_MFCLK")){
                    validation.logError("MFCLK must be enabled for the current configuration.", inst, ["MFCLKEn"]);
                }
            }
        }
    }

    /* LFCLK Validation */
    if(inst.LFCLKSource == "LFXT"){
        validation.logInfo("After LFXT is enabled, the internal LFOSC is disabled, and cannot be re-enabled other than by executing a BOOTRST.", inst, ["LFCLKSource"]);
    }

    if(Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()){
        validation.logWarning("Note: VBAT needs to be powered for LFCLK operation.", inst, ["LFCLKSource"]);
    }

    } // if Clock Tree is enabled

    if(inst.ClkOutHighDriveEn){
        validation.logInfo("High Drive Enabled on the CLK_OUT pin", inst, "enableEXCLK");
    }

    /* Special Case Validation for ROSC */
    if(Common.isDeviceFamily_PARENT_MSPM0L122X_L222X() && !inst.clockTreeEn){
        if(inst.enableROSC){
            validation.logInfo("PA2 is being configured for ROSC and should not be used for other pin selections.", inst, "enableROSC");
        }
    }
}

function onChangeUseDrivers(inst, ui){
    // Power Settings
    // TODO: (H) leaving for now for retention. clarify if need to remove / overlaps with Drivers
    // ui.powerPolicy.readOnly    = inst.driversEn;
    ui.BORThresh.readOnly                       = inst.driversEn;
    ui.enableWriteLock.readOnly                 = inst.driversEn;
    ui.enableSleepOnExit.readOnly               = inst.driversEn;
    ui.enableEventOnPending.readOnly            = inst.driversEn;
    ui.disableNRSTPin.readOnly                  = inst.driversEn;
    ui.vboostMode.readOnly                      = inst.driversEn;
    ui.enableFCC.readOnly                       = inst.driversEn;
        ui.fccTrigLvl.readOnly                  = inst.driversEn;
        ui.fccPeriods.readOnly                  = inst.driversEn;
        ui.fccTrigSrc.readOnly                  = inst.driversEn;
        ui.fccClkSrc.readOnly                   = inst.driversEn;
    ui.enableIntDone.readOnly                   = inst.driversEn;
        ui.flashInterruptPriority.readOnly      = inst.driversEn;
    ui.nmiWWDT0Behav.readOnly                   = inst.driversEn;
    if(Common.isDeviceM0G()){
        ui.waitState.readOnly                   = inst.driversEn;
        ui.powerSysInterrupts.readOnly          = inst.driversEn;
            ui.pmcuInterruptPriority.readOnly   = inst.driversEn;
        ui.nmiWWDT1Behav.readOnly               = inst.driversEn;
        ui.nmiFlashDedBehav.readOnly            = inst.driversEn;
    }
}

function onChangeClockTree(inst, ui){
    // TODO: edit this based whether these elements are present.

    _.forEach(ConfigurableList, (configurable) => {
        ui[configurable].readOnly = inst.clockTreeEn;
    })

    if(Common.isDeviceM0G()){
        // ui.LFCLKLowCap.readOnly             = inst.clockTreeEn;
        // ui.LFCLKMonitor.readOnly            = inst.clockTreeEn;
        // ui.LFCLKDriveStrength.readOnly      = inst.clockTreeEn;
        // ui.HFXTStartup.readOnly             = inst.clockTreeEn;
        // ui.HFCLKMonitor.readOnly            = inst.clockTreeEn;
        // ui.SYSPLLSource.readOnly            = inst.clockTreeEn;
        // ui.SYSPLL_Pdiv.readOnly             = inst.clockTreeEn;
        // ui.SYSPLL_Qdiv.readOnly             = inst.clockTreeEn;
        // ui.SYSPLL_CLK0En.readOnly           = inst.clockTreeEn;
        // ui.SYSPLL_CLK1En.readOnly           = inst.clockTreeEn;
        // ui.SYSPLL_CLK2XEn.readOnly          = inst.clockTreeEn;
        // ui.SYSPLL_CLK0Div.readOnly          = inst.clockTreeEn;
        // ui.SYSPLL_CLK1Div.readOnly          = inst.clockTreeEn;
        // ui.SYSPLL_CLK2XDiv.readOnly         = inst.clockTreeEn;
        // ui.useHFCLK_Manual.readOnly         = inst.clockTreeEn;
        // ui.HFCLKSource.readOnly             = inst.clockTreeEn;
        // ui.HFCLK_Freq.readOnly              = inst.clockTreeEn;
        // ui.HSCLKSource.readOnly             = inst.clockTreeEn;
        // ui.UDIV.readOnly                    = inst.clockTreeEn;

        ui.validateClkStatus.readOnly       = (inst.LFCLKSource == "LFXT") || (inst.useHFCLK_Manual && inst.HFCLKSource == "HFXT");
        ui.waitState.hidden = !inst.clockTreeEn && !(inst.MCLKSource == "HSCLK");
        ui.CANCLKSource.readOnly                 = inst.clockTreeEn;
    }

    ui.MFCLKEn.readOnly                 = inst.clockTreeEn;
    // ui.MFPCLKEn.readOnly                = inst.clockTreeEn;
    // ui.MFPCLKSource.readOnly            = inst.clockTreeEn;
    ui.MCLKSource.readOnly              = inst.clockTreeEn;
    ui.disableSYSOSC.readOnly           = inst.clockTreeEn;
    ui.MDIV.readOnly                    = inst.clockTreeEn;
    ui.LFCLKSource.readOnly             = inst.clockTreeEn;
    ui.LFCLK_Freq_IN.readOnly           = inst.clockTreeEn;
    ui.enableEXCLK.readOnly             = inst.clockTreeEn;
    ui.EXCLKSource.readOnly             = inst.clockTreeEn;
    ui.EXCLKDivider.readOnly            = inst.clockTreeEn;
    //ui.SYSOSC_Freq.readOnly             = inst.clockTreeEn;
    //ui.enableSYSOSCFCL.readOnly         = inst.clockTreeEn;
    //ui.enableROSC.readOnly              = inst.clockTreeEn;
}

function getClockTreeDesc(){
    if(Common.isDeviceM0G()){
        return `
This is the Clock Tree diagram, refer to the TRM for more detailed information.

![Clock Tree Diagram](../docs/english/sysconfig/images/clocktree_M0G.png "Clock Tree Diagram")
`;
    }
    else if(Common.isDeviceM0L() || Common.isDeviceM0C()){
        return `
This is the Clock Tree diagram, refer to the TRM for more detailed information.

![Clock Tree Diagram](../docs/english/sysconfig/images/clocktree_M0L.png "Clock Tree Diagram")
`;
    }
    return "Refer to the TRM for more detailed information on Clock Tree";
};


function getLFXTConfig(){
    return ClockConfig["LFXT"];
};

function getHFXTConfig(){
    return ClockConfig["HFXT"];
};

function getSYSOSCConfig() {
    return ClockConfig["SYSOSC"].concat(ClockConfig["ROSC"]);
}

function getSYSPLLConfig(){
    return ClockConfig["SYSPLL"];
}

function getHFCLKConfig(){
    return ClockConfig["HFCLK"];
}

function getHSCLKConfig(){
    return ClockConfig["HSCLK"];
}

function getMFPCLKConfig(){
    return ClockConfig["MFPCLK"];
}

function getULPCLKConfig(){
    return ClockConfig["UDIV"];
}

function getCANCLKConfig(){
    return ClockConfig["CANCLK"];
}

function getNMIConfig(){
    let returnConfig = [
        //DL_SYSCTL_setWWDT0ErrorBehavior
        {
            name        : "nmiWWDT0Behav",
            displayName : "WWDT0 Error Behavior",
            description : 'Configures whether a WWDT0 error will trigger a BOOTRST or an NMI (non-maskable interrupt). By default, this error will trigger a BOOTRST.',
            hidden      : false,
            default     : "BOOTRST",
            options     : [
                { name: "BOOTRST" },
                { name: "Non-Maskable Interrupt" }
            ],
        },
    ];
    if(Common.isDeviceM0G()){
        returnConfig = returnConfig.concat([
            // DL_SYSCTL_setWWDT1ErrorBehavior
            {
                name        : "nmiWWDT1Behav",
                displayName : "WWDT1 Error Behavior",
                description : 'Configures whether a WWDT1 error will trigger a SYSRST or an NMI (non-maskable interrupt). By default, this error will trigger a SYSRST.',
                hidden      : false,
                default     : "SYSRST",
                options     : [
                    { name: "SYSRST" },
                    { name: "Non-Maskable Interrupt" }
                ],
            },
            //DL_SYSCTL_setFlashDEDErrorBehavior
            {
                name        : "nmiFlashDedBehav",
                displayName : "Flash DED Error Behavior",
                description : 'Configures whether a Flash DED error will trigger a SYSRST or an NMI (non-maskable interrupt). By default, this error will trigger a SYSRST.',
                hidden      : false,
                default     : "SYSRST",
                options     : [
                    { name: "SYSRST" },
                    { name: "Non-Maskable Interrupt" }
                ],
            },
        ]);
    }
    return returnConfig;
}

function getClkOutFreqConfig(){
    return ClockFrequencies;
}

function getFlashConfig(){
    let flashConfig = [
        // DL_FLASHCTL_INTERRUPT_DONE
        {
            name: "enableIntDone",
            displayName: "Enable FlashCtl Interrupt",
            description: "Enable flash command execution is done interrupt",
            longDescription: "Enable flash command execution is done interrupt",
            default: false,
            hidden: false,
            onChange: (inst, ui) => {
                ui.flashInterruptPriority.hidden = !inst.enableIntDone;
            }
        },
        {
            name: "flashInterruptPriority",
            displayName: "Flash Interrupt Priority",
            description: "Set the interrupt priority of Flash as a part of Group 0",
            longDescription: `
The FLASH interrupt is placed in the INT_GROUP0 peripheral group,
thus their interrupt priority is tied to other members of the group.

INT_GROUP0:
* WWDT (all)
* DEBUGSS
* FLASHCTL
* FSUB1/FSUB0
* Power Management Control Unit (SYSCTL)
            `,
            hidden: true,
            default: "DEFAULT",
            options: Common.InterruptPriorityOptions
        }
    ];
    if(Common.isDeviceM0G() || Common.isDeviceFamily_PARENT_MSPM0L122X_L222X() || Common.isDeviceM0C()){flashConfig.push(
            //DL_SYSCTL_setFlashWaitState()
            {
                name        : "waitState",
                displayName : "Wait States",
                description : 'Desired number of flash wait states.',
                hidden      : true,
                default     : "2",
                options     : [
                    // DL_SYSCTL_FLASH_WAIT_STATE_
                    {name: "0",},
                    {name: "1",},
                    {name: "2",},
                ],
            },
    );}
    return flashConfig;
}

function getPowerSysIntConfig(){
    if(Common.isDeviceM0G()){
        return [
            //DL_SYSCTL_enableInterrupt
            {
                name        : "powerSysInterrupts",
                displayName : "Enable Interrupts",
                description : '',
                hidden      : false,
                default     : [],
                minSelections: 0,
                options     : getPowerSysInterrupts(),
                onChange    : (inst, ui) => {
                    ui.pmcuInterruptPriority.hidden = (inst.powerSysInterrupts.length === 0)
                }
            },
            {
                name: "pmcuInterruptPriority",
                displayName: "Power Interrupt Priority",
                description: "Interrupt Priority of the Power Interrupts (Group 0)",
                longDescription: `
The power interrupts are placed in the INT_GROUP0 peripheral group,
thus their interrupt priority is tied to other members of the group.

INT_GROUP0:
* WWDT (all)
* DEBUGSS
* FLASHCTL
* FSUB1/FSUB0
* Power Management Control Unit (SYSCTL)
                `,
                hidden: true,
                default: "DEFAULT",
                options: Common.InterruptPriorityOptions
            }
        ]
    }
    return [];
}

function getInterruptGroupConfig(){
    let config = [
        {
            name: "intGroup0Primary",
            hidden: true,
            default: "",
            getValue: (inst) => {
                let priorityArg = 2048; // much larger than any real priority
                let outStr = "";
                let modWWDT = system.modules["/ti/driverlib/WWDT"];
                if(modWWDT && modWWDT.$instances){
                    for(let inst of modWWDT.$instances){
                        // finds the index since WWDT is dynamically assigned by the solver
                        let instIdx = inst.peripheral.$solution?parseInt(inst.peripheral.$solution.peripheralName.slice(-1)):0;
                        if(inst.enabledInterrupts && inst.interruptPriority !== "DEFAULT"){
                            let candidatePriority = parseInt(inst.interruptPriority);
                            if(candidatePriority < priorityArg){
                                priorityArg = candidatePriority;
                                outStr = "/ti/driverlib/WWDT:$instances:" + inst.$name +
                                    ":WWDT"+ instIdx;
                            }
                        }
                    }
                }
                /* SYSCTL interrupts, found in inst */
                /* Disabled when TI Drivers configuration enabled */
                if(!inst.driversEn){
                    if(inst.enableIntDone && inst.flashInterruptPriority !== "DEFAULT"){
                        let candidatePriority = parseInt(inst.flashInterruptPriority);
                        if(candidatePriority < priorityArg){
                            priorityArg = candidatePriority;
                            outStr = "/ti/driverlib/SYSCTL:$static:flashInterruptPriority:FLASHCTL";
                        }
                    }
                    if(Common.isDeviceM0G()){
                        if(inst.powerSysInterrupts.length > 0 && inst.pmcuInterruptPriority !== "DEFAULT"){
                            let candidatePriority = parseInt(inst.pmcuInterruptPriority);
                            if(candidatePriority < priorityArg){
                                priorityArg = candidatePriority;
                                outStr = "/ti/driverlib/SYSCTL:$static:pmcuInterruptPriority:SYSCTL";
                            }
                        }
                    }
                }

                // iterate through all pins
                return outStr;
            }
        },
        {
            name: "intGroup0Priority",
            hidden: true,
            default: "DEFAULT",
            options: Common.InterruptPriorityOptions,
            getValue: (inst) => {
                let priority = "DEFAULT";
                if(inst.intGroup0Primary !== "")
                {
                    let refStr = _.split(inst.intGroup0Primary, ':', 4);
                    if(refStr.length >= 3){
                        try {
                            if(refStr[1] === "$static"){
                                priority = system.modules[refStr[0]][refStr[1]][refStr[2]];
                            } else {
                                priority = _.find(system.modules[refStr[0]][refStr[1]], ['$name', refStr[2]])["interruptPriority"];
                            }
                        } catch {
                            throw "interrupt group 0 didn't exist appropriately";
                        }
                    }
                }
                return priority;
            }
        },
        {
            name: "intGroup0IRQnStr",
            hidden: true,
            default: "SYSCTL_INT_IRQn",
            getValue: (inst) => {
                let str = "SYSCTL_INT_IRQn";
                if(inst.intGroup0Primary !== "")
                {
                    let refStr = _.split(inst.intGroup0Primary, ':', 4);
                    if(refStr.length === 4){
                        try {
                            str = refStr[3] + "_INT_IRQn";
                        } catch {
                            throw "interrupt group 0 didn't exist appropriately";
                        }
                    }
                }
                return str;
            }
        },
        {
            name: "intGroup1Primary",
            hidden: true,
            default: "",
            getValue: (inst) => {
                let priorityArg = 2048; // much larger than any real priority
                let outStr = "";
                let pinmodGPIO = system.modules["/ti/driverlib/gpio/GPIOPin"];
                // iterate through all pins
                if(pinmodGPIO && pinmodGPIO.$instances){
                    for (let pinst of pinmodGPIO.$instances){
                        if(pinst.direction == "INPUT" && pinst.interruptEn){
                            if(pinst.interruptPriority !== "DEFAULT"){
                                let candidatePriority = parseInt(pinst.interruptPriority);
                                priorityArg = (candidatePriority < priorityArg)?candidatePriority:priorityArg;
                                let port = Common.getGPIOPortMultiPad(pinst.pin.$solution.packagePinName,pinst,undefined);
                                outStr = "/ti/driverlib/gpio/GPIOPin:$instances:" + pinst.$name + ":" + port;
                            }
                        }
                    }
                }
                let modCOMP = system.modules["/ti/driverlib/COMP"];
                if(modCOMP && modCOMP.$instances){
                    for(let inst of modCOMP.$instances){
                        if(inst.enabledInterrupts.length > 0 && inst.interruptPriority !== "DEFAULT"){
                            let candidatePriority = parseInt(inst.interruptPriority);
                            if(candidatePriority < priorityArg){
                                priorityArg = candidatePriority;
                                let solution = inst.peripheral.$solution;
                                let peripheral = system.deviceData.peripherals[solution.peripheralName];
                                outStr = "/ti/driverlib/COMP:$instances:" + inst.$name + ":" + peripheral.name;
                            }
                        }
                    }
                }
                let modTRNG = system.modules["/ti/driverlib/TRNG"];
                if(modTRNG && modTRNG.$static){
                    let stat = modTRNG.$static;
                    if(stat.length !== 0 && stat.enabledInterrupts.length > 0 && stat.interruptPriority !== "DEFAULT"){
                        let candidatePriority = parseInt(stat.interruptPriority);
                        if(candidatePriority < priorityArg){
                            priorityArg = candidatePriority;
                            outStr = "/ti/driverlib/TRNG:$static:interruptPriority:TRNG";
                        }
                    }
                }
                return outStr;
            }
        },
        {
            name: "intGroup1Priority",
            hidden: true,
            default: "DEFAULT",
            options: Common.InterruptPriorityOptions,
            getValue: (inst) => {
                let priority = "DEFAULT";
                if(inst.intGroup1Primary !== "")
                {
                    let refStr = _.split(inst.intGroup1Primary, ':', 3);
                    if(refStr.length === 3){
                        try {
                            if(refStr[1] === "$static"){
                                priority = system.modules[refStr[0]][refStr[1]][refStr[2]];
                            } else {
                                priority = _.find(system.modules[refStr[0]][refStr[1]], ['$name', refStr[2]])["interruptPriority"];
                            }
                        } catch {
                            throw "interrupt group 1 didn't exist appropriately";
                        }
                    }
                }
                return priority;
            }
        },
        {
            name: "intGroup1IRQnStr",
            hidden: true,
            default: "GPIOA_INT_IRQn",
            getValue: (inst) => {
                let str = "GPIOA_INT_IRQn";
                if(inst.intGroup1Primary !== "")
                {
                    let refStr = _.split(inst.intGroup1Primary, ':', 4);
                    if(refStr.length === 4){
                        try {
                            str = refStr[3] + "_INT_IRQn";
                        } catch {
                            throw "interrupt group 1 didn't exist appropriately";
                        }
                    }
                }
                return str;
            }
        },
    ];
    return config;
}

function getForceDefaultClkConfig(){
    if(Common.isDeviceFamily_PARENT_MSPM0L11XX_L13XX()||Common.isDeviceM0C()){
        return [];
    }
    else{
        return [
            {
                displayName: "Force Default Clock Configuration",
                name: "forceDefaultClkConfig",
                description: "Force the default state of the HFXT and SYSPLL to be disabled before initialization.",
                longDescription: `
SysConfig assumes a default POR configuration of SYSCTL registers during initialization; however, some configurations such as crystals or PLL are retained in lower reset levels.
This setting enforces disabling PLL and HFXT to keep a consistent behavior regardless of reset level. For example, HFXT and PLL are disabled after a System Reset, but not a CPU Reset.

Note: LFXT is not disabled by this setting since it requires a BOOTRST.
                `,
                default: false,
            }
        ]
    }
}
/*
 *  ======== devSpecific ========
 *  Device-specific extensions to be added to base sysctl configuration
 */
let devSpecific = {

    /* Important Note about disabling sysctl:
     *  Once software disables SWD functionality, it is not possible to re-
     * enable it other than by triggering a POR. A POR will automatically
     * re-enable the SWD functionality and put the SWD pins into SWD
     * mode with pullup/pulldown resistors enabled. To re-gain sysctl access
     * to a device which contains software that disables the SWD pins at
     * startup, it is necessary to hold the device in a reset state with the
     * NRST pin during a POR.
     */

    config: [
        {
            name: "GRAPHICAL_CLOCK_TREE",
            displayName: "Graphical Clock Configuration",
            description: "",
            longDescription: "",
            collapsed: false,
            config: [
                {
                    name: "clockTreeEn",
                    displayName: "Use Clock Tree",
                    description: "Use the graphical Clock Tree to configure clocking",
                    longDescription: `
Clock Tree is a feature supported by SysConfig that allows a graphical configuration of all clocks present in the system.
The Clock Tree window can be accessed by clicking on the following signal icon in the top left:

![Clock Tree Icon](../docs/english/sysconfig/images/clock_tree.png "Clock Tree Icon")

This view allows the user to configure clocks graphically and easily see signal flows and
connections rather than using menus. Code generation is supported and validation of clock configurations is also checked.

To get started:
* Enable Clock Tree using this button
* Click the signal icon on the top left of the sysconfig window
* Begin to click blocks of interest in order to manipulate the clock values
                    `,
                    default: false,
                    onChange: onChangeClockTree
                },
            ]
        },
        {
            name: "GROUP_PWR_SYS",
            displayName: "Power & Systems Configuration",
            description: "",
            longDescription: "",
            collapsed: false,
            config: [
                // TODO: [3/8 (H) - work in progress drivers SysCtl behavior]
                {
                    name: "driversEn",
                    displayName: "Use TI Drivers Configuration",
                    default: false,
                    onChange: onChangeUseDrivers,
                    hidden: true,
                },
                // DL_SYSCTL_setPowerPolicy[...]
                {
                    name: "runPowerPolicy",
                    displayName: "Run Power Policy",
                    description: `Set power policy during runtime (CPU up). Defined by clock configuration`,
                    longDescription: `
The run power policy of the device is set by the clocks that are enabled and how they are configured.
This configurable cannot be set but rather is a product of the clock configuration. The different policies are:

* **RUN0**: MCLK and CPUCLK can fun from a fast clock source (SYSOSC or a High-Frequency Clock if applicable)
* **RUN1**: MCLK and CPUCLK run from LFCLK (at 32 kHz), but SYSOSC is left enabled in order to service analog modules
* **RUN2**: MCLK and CPUCLK run from LFCLK, and SYSOSC is disabled. Lowest power state with the CPU running.

**NOTE** RUN1 and RUN2 require all HFCLK peripherals (HFXT, HFCLK_IN, SYSPLL if equipped) to be off, thus it
is not possible to source MCLK from LFCLK and have a high-frequency external clock.

**NOTE** Not every low power state can be reached from every run policy. There are some transitions that are
not possible or logical, such as:

* RUN A -> SLEEP B and A != B : MCLK doesn't change configuration so these are incompatible
* RUN1/2 -> STOP1 : SYSOSC is throttled down for MCLK use, not necessary for RUN1 (4MHz max in stop mode on ULPCLK) and off in RUN2.

                    `,
                    default: "RUN0",
                    options: [
                        { name: "RUN0" },
                        { name: "RUN1" },
                        { name: "RUN2" },
                    ],
                    getValue: (inst) => {
                        let policy = "RUN0";
                        if(inst.clockTreeEn){
                            let mod = system.modules["/ti/clockTree/mux.js"];
                            let mclkSrcInst = _.find(mod.$instances, ['$name', 'SYSCTLMUX']);
                            mod = system.modules["/ti/clockTree/oscillator.js"];
                            let sysoscInst = _.find(mod.$instances, ['$name', 'SYSOSC']);
                            if(_.isUndefined(mclkSrcInst) || _.isUndefined(sysoscInst)){
                                throw "runPowerPolicy cannot find appropriate modules";
                            }
                            if(_.endsWith(mclkSrcInst.inputSelect,"LFCLK")){
                                policy = sysoscInst.disableSYSOSC?"RUN2":"RUN1";
                            }
                        } else {
                            if(inst.MCLKSource === "LFCLK"){
                                policy = inst.disableSYSOSC?"RUN2":"RUN1";
                            }
                        }
                        return policy;
                    }

                },
                {
                    name: "powerPolicy",
                    displayName: "Low Power Policy",
                    description: `Set the low power state of the device when _WFI() called`,
                    longDescription: `
The low power state of the device is entered when _WFI() is called from the main function.
In each of these, the CPU will turn off but some subset of peripherals can remain active.
The severity of the power state goes:
* **SLEEP**: Same as corresponding run mode but CPU disabled
* **STOP**: SLEEP plus PD1 peripherals are disabled and in retention max PD0 frequency is 4MHz
* **STANDBY**: STOP plus max PD0 frequency now 32KHz and SYSOSC always disabled.
Additionally, higher numbers save more power by disabling more features`,
                    default: "SLEEP0",
                    options: [
                        { name: "SLEEP0" },
                        { name: "SLEEP1" },
                        { name: "SLEEP2" },
                        { name: "STOP0" },
                        { name: "STOP1" },
                        { name: "STOP2" },
                        { name: "STANDBY0" },
                        { name: "STANDBY1" }
                    ]
                },
                {
                    name        : "VDD",
                    displayName : "Supplied Operational Voltage (VDD)",
                    description : "Supplied Operational Voltage for the Board supplied by the user",
                    longDescription: "Voltage given for the DC Operation of the Device, used by GPIO pins for internal operating parameters.",
                    default     : 3.3,
                    range       : [1.71, 5]
                },
                //  DL_SYSCTL_setBORThreshold
                // DL_SYSCTL_BOR_THRESHOLD_LEVEL_[...]
                {
                    name        : "BORThresh",
                    displayName : "BOR Threshold",
                    description : ' Set the brown-out reset (BOR) threshold level',
                    longDescription: `Set the brown-out reset (BOR) threshold level.
                    A BOR0 violation will force a re-boot, this is the minimum allowed threshold.
                    A BOR1-BOR3 violation generates an interrupt.
                    `,
                    hidden      : false,
                    default     : "0",
                    options     : Options.BORThresh,
                    readOnly    : Common.isDeviceM0C(),
                },
                // DL_SYSCTL_enableWriteLock / DL_SYSCTL_disableWriteLock
                {
                    name        : "enableWriteLock",
                    displayName : "Enable Write Lock",
                    description : 'Enable write protection of selected SYSCTL registers',
                    longDescription: `Enable write protection of selected SYSCTL registers.
                    Does not protect all SYSCTL registers, see TRM for more detail.
                    `,
                    hidden      : false,
                    default     : false
                },
                // DL_SYSCTL_enableSleepOnExit
                {
                    name        : "enableSleepOnExit",
                    displayName : "Enable Sleep On Exit",
                    description : '',
                    longDescription: `Enables sleep on exit when the CPU moves from handler mode to thread mode.
                    By enabling, allows an interrupt driven application to avoid returning to an empty main application.
                    `,
                    hidden      : false,
                    default     : false
                },
                // DL_SYSCTL_enableEventOnPend
                {
                    name        : "enableEventOnPending",
                    displayName : "Enable Event On Pending",
                    description : 'Enable send event on pending bit',
                    longDescription: `When enabled, any enabled event and all interrupts (including disabled
                    interrupts) can wakeup the processor.
                    `,
                    hidden      : false,
                    default     : false
                },
                // DL_SYSCTL_disableNRSTPin
                {
                    name        : "disableNRSTPin",
                    displayName : "Disable NRST Pin",
                    description : 'Disable the functionality of the NRST pin',
                    longDescription: `When disabled, the NRST pin becomes free to use as a GPIO. This
                    can be advantageous for lower pin count devices.
                    **NOTE:** Once disabled, it can only be re-enabled by a POR.
                    `,
                    hidden      : false,
                    default     : false
                },
                // DL_SYSCTL_setVBOOSTConfig(DL_SYSCTL_VBOOST)
                {
                    name: "vboostMode",
                    displayName: "VBOOST Operating Mode",
                    longDescription: `
Sets operating mode of VBOOST (analog charge pump), the available modes are in the following table:

| Mode | VBOOST Enable | Application Use-Case |
| :------: | :----------: | :--------: |
| ONDEMAND | VBOOST is automatically enabled by SYSCTL only when a COMP, OPA, or the GPAMP is enabled. | This setting provides the lowest power consumption in all modes when fast startup of the COMP, OPA, or GPAMP is not critical. |
| ONACTIVE | VBOOST is forced to be enabled when the device is in RUN or SLEEP mode. VBOOST is also kept enabled in STOP or STANDBY mode if a COMP, OPA, or the GPAMP is enabled. | This setting provides low power consumption by disabling the VBOOST automatically in STOP and STANDBY modes when no peripherals requiring VBOOST are enabled. VBOOST is automatically reenabled upon exit to RUN mode to provide fast startup of the COMP, OPA, or GPAMP in the event that application software enables a COMP, OPA, or GPAMP in RUN mode |
| ONALWAYS | VBOOST is forced to be enabled in all operating modes except SHUTDOWN. | This setting ensures that the COMP, OPA, and GPAMP never incur additional startup latency due to VBOOST startup in applications where fast COMP, OPA, or GPAMP startup is critical. |
                    `,
                    default: "ONDEMAND",
                    hidden: false,
                    options: [
                        {name: "ONDEMAND", displayName: "ONDEMAND"},
                        {name: "ONACTIVE", displayName: "ONACTIVE"},
                        {name: "ONALWAYS", displayName: "ONALWAYS"},
                    ],
                },
                {
                    name: "GROUP_FLASH_CONFIG",
                    displayName: "Flash Controller (FlashCtl) Configuration",
                    description: "",
                    longDescription: "",
                    collapsed: false,
                    config: getFlashConfig(),
                },
                {
                    name: "GROUP_PWR_SYS_Interrupts",
                    displayName: "Power & Systems Interrupts",
                    description: "",
                    longDescription: "",
                    collapsed: false,
                    config: getPowerSysIntConfig()
                },
                {
                    name: "GROUP_NMI_Interrupts",
                    displayName: "Non-Maskable Interrupt (NMI) Configuration",
                    description: "",
                    longDescription:
`
The SYSCTL module supports generation of a non-maskable interrupt (NMI) to the Cortex-M0+ processor for some system error conditions.
The default behavior for some system error conditions can be configured.
`,
                    collapsed: false,
                    config: getNMIConfig(),
                },
            ]
        },
        {
            name: "GROUP_CLK",
            displayName: "Clock Configuration",
            description: "",
            longDescription: getClockTreeDesc(),
            collapsed: false,
            config: [
            ].concat(getForceDefaultClkConfig()).concat([
                {
                    name: "validateClkStatus",
                    displayName: "Enable Check for Clock Stabilization",
                    description: "Waits for clocks to return correct status",
                    longDescription: "Check For Clock Stabilization from an external source, must be on for external crystal",
                    default: false,
                    readOnly: false
                },
                {
                    name: "MCLK_Config_Group",
                    displayName: "MCLK (Main Clock)",
                    collapsed: false,
                    config: [
                        // DL_SYSCTL_setMCLKSource
                        {
                            name: "MCLKSource",
                            displayName: "MCLK Source",
                            description: "Specifies the clock source",
                            longDescription:`The frequency of the clock sources are
                                defined in their respective configurables`,
                            default: "SYSOSC",
                            options: Options.MCLKSource,
                            onChange: (inst, ui) => {
                                ui.disableSYSOSC.hidden = !(inst.MCLKSource == "LFCLK");
                                inst.disableSYSOSC = false;
                                if(Common.isDeviceM0G() || Common.isDeviceFamily_PARENT_MSPM0L122X_L222X() || Common.isDeviceM0C()){
                                    ui.HSCLKSource.hidden = !(inst.MCLKSource == "HSCLK");
                                    /* Wait configuration available only when MCLK source is HSCLK */
                                    ui.waitState.hidden = !inst.clockTreeEn && !(inst.MCLKSource == "HSCLK");
                                }
                                /* MDIV disabled when MCLK Source is HSCLK or LFCLK */
                                if(["HSCLK","LFCLK"].includes(inst.MCLKSource)){
                                    inst.MDIV = "DISABLE";
                                    ui.MDIV.hidden = true;
                                }
                                else{
                                    ui.MDIV.hidden = false;
                                }
                            }
                        },
                        // DL_SYSCTL_switchMCLKfromSYSOSCtoLFCLK
                        {
                            name: "disableSYSOSC",
                            displayName: "Disable SYSOSC",
                            description: "SYSOSC can be disabled if LFCLK is the clock used by MCLK",
                            default: false,
                            hidden: true
                        },
                        {
                            name: "MDIV",
                            displayName: "Main Clock Divider",
                            default: "DISABLE",
                            options: [ { name: "DISABLE" , displayName: "1"}, {name: "2" }, {name: "3" }, {name: "4" }, {name: "5" },
                                       {name: "6" }, {name: "7" }, {name: "8" }, {name: "9" }, {name: "10" }, {name: "11" }, {name: "12" },
                                       {name: "13" }, {name: "14" }, {name: "15"}, {name: "16"} ],
                            hidden: false
                        },
                        {
                            name: "HSCLK_Config_Group",
                            displayName: "HSCLK (High Speed Clock)",
                            collapsed: false,
                            config: getHSCLKConfig(),
                        },
                    ]
                },
                // TODO:(H) MFCLK can only be enabled based on certain power policies. throw error otherwise
                {
                    name: "MFCLK_Config_Group",
                    displayName: "MFCLK (Middle Frequency Clock)",
                    description: "",
                    longDescription: "",
                    collapsed: true,
                    config: [
                        // DL_SYSCTL_enableMFCLK
                        {
                            name: "MFCLKEn",
                            displayName: "MFCLK Enable",
                            description: "Enable the Mid-Frequency Clock (4MHz always)",
                            longDescription: `The Mid-Frequency Clock is a constant frequency 4MHz
                            clock that is sourced from the SYSOSC. Peripherals, specifically PD0
                            peripherals which may be used in STOP mode, may select MFCLK as their
                            clock source instead of ULPCLK. MFCLK will be maintained at 4MHz in RUN,
                            SLEEP and STOP, which is ideal for peripherals like UART, I2C, and low
                            power timers that need a consistent clock but require a clock source
                            greater than 32kHz`,
                            default: false
                        },
                    ]
                },
                {
                    name: "LFCLK_Config_Group",
                    displayName: "LFCLK (Low-Frequency Clock)",
                    description: "",
                    longDescription: "",
                    collapsed: true,
                    config: ClockConfig["LFCLK"]
                },
                {
                    name: "MFPCLK_Config_Group",
                    displayName: "MFPCLK (Middle Frequency Precision Clock)",
                    description: "",
                    longDescription: "",
                    collapsed: true,
                    config: getMFPCLKConfig(),
                },
                {
                    name: "ULPCLK_Config_Group",
                    displayName: "ULPCLK (Low Power Clock)",
                    description: "",
                    longDescription: "",
                    collapsed: true,
                    config: getULPCLKConfig(),
                },
                {
                    name: "HFCLK_Config_Group",
                    displayName: "HFCLK (High-Frequency External Clock)",
                    collapsed: true,
                    config: getHFCLKConfig(),
                },
                {
                    name: "CANCLK_Config_Group",
                    displayName: "CANCLK (CAN Clock)",
                    description: "",
                    longDescription: "",
                    collapsed: true,
                    config: getCANCLKConfig(),
                },
                {
                    name: "EXCLK_Config_Group",
                    displayName: "Clock Output (CLK_OUT)",
                    collapsed: true,
                    config: [
                        // DL_SYSCTL_enableExternalClock()
                        {
                            name: "enableEXCLK",
                            displayName: "Enable CLK_OUT",
                            description: "",
                            default: false,
                            hidden: false,
                            onChange: (inst,ui) => {
                                ui.clkOutPinDisplay.hidden  = !inst.enableEXCLK;
                                ui.clkOutPinIO.hidden       = !inst.enableEXCLK;
                            }
                        },
                        {
                            name: "clkOutPinDisplay",
                            displayName: "CLK_OUT Pin",
                            description: "",
                            default: "N/A",
                            hidden: true,
                            getValue: (inst) => {
                                try{
                                    let value = inst.peripheral.clkOutPin.$solution.devicePinName;
                                    if(value !== null){ return value};
                                } catch(e){
                                    return "N/A"
                                }
                                return "N/A"

                            }
                        },
                        {
                            name: "clkOutPinIO",
                            displayName: "CLK_OUT Pin IO Structure",
                            description: "",
                            default: "N/A",
                            hidden: true,
                            options: [
                                {name: "N/A", displayName: "N/A"},
                                {name: "SD", displayName: "Standard"},
                                {name: "SDL", displayName: "Standard"},
                                {name: "SDW", displayName: "Standard with Wake"},
                                {name: "HS", displayName: "High-Speed"},
                                {name: "HD", displayName: "High-Drive"},
                                {name: "OD", displayName: "5V Tolerant Open Drain"},
                            ],
                            getValue: (inst) => {
                                try{
                                    let value =  system.deviceData.gpio.pinInfo[inst.peripheral.clkOutPin.$solution.packagePinName].devicePin.attributes.io_type;
                                    if(value !== null){ return value};
                                } catch(e){
                                    return "N/A"
                                }
                                return "N/A"
                            }
                        },
                        // DL_SYSCTL_CLK_OUT_SOURCE_[...]
                        {
                            name: "EXCLKSource",
                            displayName: "CLK_OUT Source",
                            default: "SYSOSC",
                            options: Options.EXCLKSource,
                        },
                        //  DL_SYSCTL_CLK_OUT_DIVIDE_[...]
                        {
                            name: "EXCLKDivider",
                            displayName: "CLK_OUT Divider",
                            default: "DISABLE",
                            options: [ { name: "DISABLE"}, {name: "2" }, {name: "4" },
                               {name: "6" }, {name: "8" }, {name: "10" }, {name: "12" },
                               {name: "14" }, {name: "16"} ],
                        },
                        {
                            name: "ClkOut_Freq",
                            default: 32,
                            getValue: (inst, ui) => {
                                let sourceFreq = inst.EXCLKSource + "_Freq";
                                let div = (inst.EXCLKDivider == "DISABLE")?1:parseInt(inst.EXCLKDivider);
                                return inst[sourceFreq] / div;
                            }
                        },
                        {
                            name: "ClkOutForceHighDrive",
                            displayName: "Force High Drive",
                            description: "Force the output pin for the CLK_OUT Pin to High Drive",
                            longDescription: `
Forces the output pin to be of type HDIO or HSIO configured with High-Drive strength, useful when driving other devices.
High Drive is turned on automatically if the CLK_OUT frequency is above 32 MHz when VDD >= 2.7 or above 16 MHz otherwise.
                            `,
                            default: false
                        },
                        {
                            name: "ClkOutHighDriveEn",
                            default: false,
                            hidden: true,
                            getValue: (inst, ui) => {
                                if(inst.enableEXCLK){
                                    if(inst.ClkOutForceHighDrive){
                                        return true;
                                    } else {
                                        // automatic enabling due to the frequency
                                        let clkOutFreq = inst.ClkOut_Freq;
                                        let index = (inst.VDD >= 2.7)?1:0;
                                        if(clkOutFreq >  (maxFrequencyCLKOUTDir["SD"][index] * 1000000) &&
                                           clkOutFreq <= (maxFrequencyCLKOUTDir["HS"][index] * 1000000)){
                                            // in this condition, SD pins will already be filtered out
                                            // so we can be certain the pin in use will be high-speed
                                            return true;
                                        }
                                    }
                                }
                                return false
                            }
                        }
                    ]
                },
                {
                    name: "GROUP_FCC_CONFIG",
                    displayName: "FCC Configuration",
                    description: "",
                    longDescription: `
Configure the Frequency Clock Counter (FCC).
FCC enables flexible in-system testing and calibration of a variety of oscillators
and clocks on the device. The FCC counts the number of clock periods seen on the
selected clock source within a known fixed trigger period (derived from a secondary
reference source) to provide an estimation of the frequency of the source clock.
                    `,
                    collapsed: true,
                    config: [
                        {
                            name        : "enableFCC",
                            displayName : "Enable FCC",
                            description : '',
                            hidden      : false,
                            default     : false,
                            onChange    : (inst,ui) => {
                                ui.fccTrigLvl.hidden = !inst.enableFCC;
                                ui.fccTrigSrc.hidden = !inst.enableFCC;
                                ui.fccClkSrc.hidden = !inst.enableFCC;
                                ui.fccPeriods.hidden = (!inst.enableFCC) || !(inst.fccTrigLvl == "RISE_RISE");
                            }
                        },
                        // DL_SYSCTL_configFCC()
                        // DL_SYSCTL_FCC_TRIG_TYPE_ -> if RISE selected, must set period
                        {
                            name        : "fccTrigLvl",
                            displayName : "FCC Trigger Level",
                            description : 'Determines if active high level trigger or rising-edge to rising-edge',
                            hidden      : true,
                            default     : "RISE_RISE",
                            options     : [
                                {name: "RISE_RISE", displayName: "Rising-edge to rising-edge pulse"},
                                {name: "LEVEL", displayName: "Active-high pulse level"},
                            ],
                            onChange    : (inst,ui) => {
                                ui.fccPeriods.hidden = !(inst.fccTrigLvl == "RISE_RISE");
                            }
                        },
                        // DL_SYSCTL_setFCCPeriods()
                        {
                            name        : "fccPeriods",
                            displayName : "FCC Periods",
                            description : 'Set the number of rising-edge to rising-edge period for FCC',
                            hidden      : true,
                            default     : "01",
                            options     : [
                                // DL_SYSCTL_FCC_TRIG_CNT_
                                {name: "01", displayName: "1"},
                                {name: "02", displayName: "2"},
                                {name: "03", displayName: "3"},
                                {name: "04", displayName: "4"},
                                {name: "05", displayName: "5"},
                                {name: "06", displayName: "6"},
                                {name: "07", displayName: "7"},
                                {name: "08", displayName: "8"},
                                {name: "09", displayName: "9"},
                                {name: "10", displayName: "10"},
                                {name: "11", displayName: "11"},
                                {name: "12", displayName: "12"},
                                {name: "13", displayName: "13"},
                                {name: "14", displayName: "14"},
                                {name: "15", displayName: "15"},
                                {name: "16", displayName: "16"},
                                {name: "17", displayName: "17"},
                                {name: "18", displayName: "18"},
                                {name: "19", displayName: "19"},
                                {name: "20", displayName: "20"},
                                {name: "21", displayName: "21"},
                                {name: "22", displayName: "22"},
                                {name: "23", displayName: "23"},
                                {name: "24", displayName: "24"},
                                {name: "25", displayName: "25"},
                                {name: "26", displayName: "26"},
                                {name: "27", displayName: "27"},
                                {name: "28", displayName: "28"},
                                {name: "29", displayName: "29"},
                                {name: "30", displayName: "30"},
                                {name: "31", displayName: "31"},
                                {name: "32", displayName: "32"},

                            ],
                        },
                        // DL_SYSCTL_FCC_TRIG_SOURCE
                        {
                            name        : "fccTrigSrc",
                            displayName : "FCC Trigger Source",
                            description : 'Determines which clock source to trigger FCC from',
                            hidden      : true,
                            default     : "FCC_IN",
                            options     : [
                                {name: "FCC_IN", displayName: "FCC_IN external pin"},
                                {name: "LFCLK", displayName: "LFCLK"},
                            ],
                        },
                        // DL_SYSCTL_FCC_CLOCK_SOURCE
                        {
                            name        : "fccClkSrc",
                            displayName : "FCC Clock Source",
                            description : 'Which clock source to capture and measure frequency of',
                            hidden      : true,
                            default     : "MCLK",
                            options     : getFCCClkSrcs(),
                        },
                    ],
                },
                {
                    name: "OSC_NAME",
                    displayName: "Oscillators",
                    description: "",
                    longDescription: "",
                    collapsed: true,
                    config: [
                        {
                            name: "SYSOSC_Config_Group",
                            displayName: "SYSOSC (Internal System Oscillator)",
                            collapsed: true,
                            config: getSYSOSCConfig(),
                        },
                        {
                            name: "SYSPLL_Config_Group",
                            displayName: "SYSPLL (System Phase-Locked Loop)",
                            longDescription:
`
The system phase locked loop (SYSPLL) takes an input reference clock SYSPLLREF and scales the input
frequency to produce user-specified high frequency clocks (SYSPLLCLK0, SYSPLLCLK1, and SYSPLLCLK2X)
for use by the device. Specifically, the SYSPLL clock outputs can be used as sources to MCLK and CANCLK.
![SYSPLL Diagram](../docs/english/sysconfig/images/syspllDiagram.png "SYSPLL Diagram")
`,
                            collapsed: true,
                            config: getSYSPLLConfig(),
                        },
                        {
                            name: "HFXT_Config_Group",
                            displayName: "HFXT Configuration",
                            description: "",
                            longDescription: "",
                            collapsed: true,
                            config: getHFXTConfig(),
                        },
                        {
                            name: "LFXT_Config_Group",
                            displayName: "LFXT Configuration",
                            description: "",
                            longDescription: "",
                            collapsed: true,
                            config: getLFXTConfig(),
                        },
                    ]
                },
                {
                    name: "GROUP_CLK_Interrupts",
                    displayName: "Clock Interrupts",
                    description: "",
                    longDescription: "",
                    collapsed: false,
                    config: [
                        //DL_SYSCTL_enableInterrupt
                        {
                            name        : "clockInterrupts",
                            displayName : "Enable Interrupts",
                            description : '',
                            hidden      : false,
                            default     : [],
                            minSelections: 0,
                            options     : getClockInterrupts(),
                        },
                    ]
                },
                {
                    name: "Clock_Output_Group",
                    displayName: "Clock Output Frequencies",
                    collapsed: true,
                    config: getClkOutFreqConfig(),
                },
                {
                    name: "interruptGroup",
                    displayName: "Group Interrupts",
                    collapsed: true,
                    config: getInterruptGroupConfig(),
                }
            ])
        },
    ],

    /* override generic requirements with  device-specific reqs (if any) */
    pinmuxRequirements: pinmuxRequirements,

    filterHardware: filterHardware,

    //moduleInstances: moduleInstances,

    validate: validateSYSCTL,

    validatePinmux: validatePinmux,

    //_getPinResources: _getPinResources
};

function getClockInterrupts(inst){
    if(Common.isDeviceM0G()){
        return [
            // DL_SYSCTL_INTERRUPT_[...]
            {name: "LFOSC_GOOD", displayName: "Low Frequency Oscillator is stabilized and ready to use"},
            {name: "ANALOG_CLOCK_ERROR", displayName: "Analog clocking consistency error"},
            {name: "LFXT_GOOD", displayName: "Low Frequency Crystal is stabilized and ready to use"},
            {name: "HFCLK_GOOD", displayName: "High Frequency Clock is stabilized and ready to use"},
            {name: "SYSPLL_GOOD", displayName: "System PLL is stabilized and ready to use"},
            {name: "HSCLK_GOOD", displayName: "High Speed Clock is stabilized and ready to use"},
        ];
    }
    else if(Common.isDeviceFamily_PARENT_MSPM0L11XX_L13XX()){
        return [
            // DL_SYSCTL_INTERRUPT_[...]
            {name: "LFOSC_GOOD", displayName: "Low Frequency Oscillator is stabilized and ready to use"},
            {name: "ANALOG_CLOCK_ERROR", displayName: "Analog clocking consistency error"},
        ];
    }
    else if(Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()){
        return [
            // DL_SYSCTL_INTERRUPT_[...]
            {name: "LFOSC_GOOD", displayName: "Low Frequency Oscillator is stabilized and ready to use"},
            {name: "ANALOG_CLOCK_ERROR", displayName: "Analog clocking consistency error"},
            {name: "LFXT_GOOD", displayName: "Low Frequency Crystal is stabilized and ready to use"},
            {name: "HFCLK_GOOD", displayName: "High Frequency Clock is stabilized and ready to use"},
            {name: "HSCLK_GOOD", displayName: "High Speed Clock is stabilized and ready to use"},
        ];
    }
    else if(Common.isDeviceM0C()){
        return [
            // DL_SYSCTL_INTERRUPT_[...]
            {name: "LFOSC_GOOD", displayName: "Low Frequency Oscillator is stabilized and ready to use"},
            {name: "ANALOG_CLOCK_ERROR", displayName: "Analog clocking consistency error"},
            {name: "HFCLK_GOOD", displayName: "High Frequency Clock is stabilized and ready to use"},
            {name: "HSCLK_GOOD", displayName: "High Speed Clock is stabilized and ready to use"},
        ];
    }
    return [];
};

function getPowerSysInterrupts(inst){
    if(Common.isDeviceM0G()){
        return [
            // DL_SYSCTL_INTERRUPT_[...]
            {name: "FLASH_SEC", displayName: "Flash Single Error Correct"},
        ];
    }
    else if(Common.isDeviceM0L() || Common.isDeviceM0C()){
        return [
            // DL_SYSCTL_INTERRUPT_[...]
        ];
    }
    return [];
};

function getFCCClkSrcs(inst){
    if(Common.isDeviceM0G()){
        return [
            {name: "MCLK",},
            {name: "SYSOSC",},
            {name: "HFCLK",},
            {name: "CLK_OUT"},
            {name: "SYSPLLCLK0",},
            {name: "SYSPLLCLK1",},
            {name: "SYSPLLCLK2X",},
            {name: "FCC_IN",},
        ];
    }
    else if(Common.isDeviceFamily_PARENT_MSPM0L11XX_L13XX()){
        return [
            {name: "MCLK",},
            {name: "SYSOSC",},
            {name: "CLK_OUT",},
            {name: "FCC_IN",},
        ];
    }
    else if(Common.isDeviceFamily_PARENT_MSPM0L122X_L222X() || Common.isDeviceM0C()){
        return [
            {name: "MCLK",},
            {name: "SYSOSC",},
            {name: "HFCLK",},
            {name: "CLK_OUT"},
            {name: "FCC_IN",},
        ];
    }
    return [];
}

/*
 *  ======== _getPinResources ========
 */
function _getPinResources(inst)
{


    return ("");


}

const memoizedGPIOFilter = _.memoize(curryGPIOFilter, (validPinSet) => JSON.stringify(validPinSet));

function curryGPIOFilter(validPinSet) {
    return (devicePin, peripheralPin) => GPIOFilter(devicePin, validPinSet);
}

function GPIOFilter(devicePin, validPinSet) {
    return validPinSet.includes(devicePin.name);
}

const maxFrequencyCLKOUTDir = {
    "SD" : [ 16, 32 ],
    "SDW" : [16, 32], // same as SD simply with wake
    "SDL" : [16, 32], // same as SD simply with low leakage
    "HS_DRVLOW" : [ 16, 32 ], // LOW Drive, used later on in pinmux validation
    "HS" : [ 24, 40 ], // High drive enabled
    "HD" : [ 16, 20 ],
    "OD" : [ 1, 1 ]
};

/* Filter valid pins for Fault Pin configuration */
function validClkOutPinSet(inst){
    let validPinSet = [];

    // determine the frequency based on the table:
    /*  Type        | short |  >1.71    |   >2.7
     *  SDIO        |  SD   |  16 MHz   |   32 MHz
     *  HSIO(DRV 0) |  HS   |  16 MHz   |   32 MHz
     *  HSIO(DRV 1) |  HS   |  24 MHz   |   40 MHz
     *  HDIO        |  HD   |  16 MHz   |   20 MHz
     *  ODIO        |  OD   |   1 MHz   |    1 MHz
     *
     */
    let clkOutFreq = inst.ClkOut_Freq;

    for(let pinIdx in system.deviceData.gpio.pinInfo){
        let eligible = true;

        let pinType = system.deviceData.gpio.pinInfo[pinIdx].devicePin.attributes.io_type;

        if(inst.ClkOutForceHighDrive && !["HD", "HS"].includes(pinType)){
            eligible = false;
        } else {
            // determine eligibility based on the frequency value
            let index = 0;
            if(inst.VDD >= 2.7){
                index = 1;
            }

            if(_.isUndefined(maxFrequencyCLKOUTDir[pinType])){
                throw "max frequency not found for pin type" + pinType;
            }
            // if pinType is HSIO;
            let maxFreq = maxFrequencyCLKOUTDir[pinType][index] * 1000000;

            if(clkOutFreq > maxFreq){
            // pin.devicePin.attributes.io_type
                eligible = false;
            }
        }

        if(eligible){
            validPinSet.push(pinIdx);
        }
    }

    return validPinSet;
}

/*  ======== pinmuxRequirements ========
 *  Returns peripheral pin requirements of the specified instance
 *
 *  param inst    - a fully configured sysctl instance
 *
 *  returns req[] - an array of pin requirements needed by inst
 */
function pinmuxRequirements(inst)
{
    /* Regular Pinmux Requirements for SysCtl */ 
    let resources = [];
    if(Common.isDeviceM0G() || Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()){
        if(inst.LFCLKSource === "LFXT"){
            resources.push({
                name            : "lfxInPin",
                displayName     : "LFXIN",
                interfaceNames  : ["LFXIN"],
            },
            {
                name            : "lfxOutPin",
                displayName     : "LFXOUT",
                interfaceNames  : ["LFXOUT"],
            });
        }
        if(inst.LFCLKSource === "LFCLK_IN"){
            resources.push({
                name            : "lfclkInPin",
                displayName     : "LFCLK In",
                interfaceNames  : ["LFXOUT"],
            });
        }
        if(inst.useHFCLK_Manual && inst.HFCLKSource === "HFXT"){
            resources.push({
                name            : "hfxInPin",
                displayName     : "HFXIN",
                interfaceNames  : ["HFXIN"],
            },
            {
                name            : "hfxOutPin",
                displayName     : "HFXOUT",
                interfaceNames  : ["HFXOUT"],
            });
        }
        else if(inst.useHFCLK_Manual && inst.HFCLKSource === "HFCLK_IN"){
            resources.push({
                name            : "hfclkInPin",
                displayName     : "HFCLK In",
                interfaceNames  : ["HFXOUT"],
            });
        }
    }
    if(inst.fccTrigSrc == "FCC_IN" && inst.enableFCC){
        resources.push({
            name            : "fccInPin",
            displayName     : "FCC IN",
            interfaceNames  : ["FCC_IN"],
        });
    }
    if(inst.enableROSC){
        // SYSCTL ROSC
        if(!Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()){
            resources.push({
                name            : "roscPin",
                displayName     : "ROSC",
                interfaceNames  : ["ROSC"],
            });
        }
        
    }
    if(inst.enableEXCLK){
        resources.push({
            name            : "clkOutPin",
            displayName     : "CLK OUT",
            interfaceNames  : ["CLK_OUT"],
        });
    }
    let sysctl = {
        name          : "peripheral",
        displayName   : "SYSCTL Peripheral",
        interfaceName : "SYSCTL",
        canShareWith  : "CLOCK_TREE",
        resources     : resources,
        signalTypes   : {
            lfxInPin    : ["LFXIN"],
            lfxOutPin   : ["LFXOUT"],
            lfclkInPin  : ["LFXOUT"],
            hfxInPin    : ["LFXIN"],
            hfxOutPin   : ["HFXOUT"],
            hfclkInPin  : ["HFXOUT"],
            roscPin     : ["ROSC"],
            clkOutPin   : ["CLK_OUT"],
        }
    };
    if(inst.clockTreeEn){
        return [];
    } else {
        return [sysctl];
    }
}

/*
 *  ========= filterHardware ========
 *  Check 'component' signals for compatibility with sysctl
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

/*
 *  ======== extend ========
 *  Extends a base exports object to include any device specifics
 *
 *  This function is invoked by the generic sysctl module to
 *  allow us to augment/override as needed for the MSP432.
 */
function extend(base)
{
    // Special static extend

    /* merge and overwrite base module attributes */
    let result = Object.assign({}, base.moduleStatic, devSpecific);

    /* concatenate device-specific configs */
    // moduleStatic specific to SYSCTL as it's statically defined
    result.config = base.moduleStatic.config.concat(devSpecific.config);
    base.moduleStatic = result;

    return (base);
}

/*
 *  ======== exports ========
 *  Export device-specific extensions to base exports
 */
exports = {
    /* required function, called by base sysctl module */
    extend: extend
};
