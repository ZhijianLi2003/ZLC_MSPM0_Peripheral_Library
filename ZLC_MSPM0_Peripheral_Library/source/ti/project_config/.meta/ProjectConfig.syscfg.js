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
 *  ======== Board.syscfg.js ========
 */

/* Module used to invoke Board.c and Board.h templates */

"use strict";

/* get ti/drivers common utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");
let MigrationCommon = system.getScript("/ti/project_config/Common.js");

/*
 *  ======== _getPinResources ========
 */
function _getPinResources(inst)
{
    let pin;
    return (pin);

}

/*  ======== pinmuxRequirements ========
 *  Returns peripheral pin requirements of the specified instance
 *
 *  param inst    - a fully configured Board instance
 *
 *  returns req[] - an array of pin requirements needed by inst
 */
function pinmuxRequirements(inst)
{

}

function validate(inst, validation)
{
    /* For Projects not compatible with SysConfig Migration */
    if(inst.genDisable){
        validation.logWarning("Project Configuration File generation is disabled for this project. SysConfig Project Migration is not currently supported for this project.",inst)
    }
    /* For Projects that use SysConfig Project Configuration Files */
    else{
        let compilerWarning = "";
        if((["ccs","ticlang","gcc"].includes(system.compiler))&&(!system.isStandAloneGUI())){
            compilerWarning = "User must make sure to select the same device as the CCS Launch Device setting for proper configuration."
        }
        if(inst.switchCondition){
            validation.logWarning("Migrating requires going through the Switch Board or Device menu in the Device View section.",inst,"deviceSpin")
        }
        if(inst.migrationCondition){
            validation.logError("User must select device after migration. "+compilerWarning,inst,"deviceSpin")
        }else{
            validation.logInfo("Note: User must select a device after migration. "+compilerWarning,inst,"deviceSpin")
        }
        if(!inst.genLinker | !inst.genStartup | !inst.genOpts| !inst.genLibs){
            validation.logWarning("All four File Generation options must be enabled in order to guarantee Device Migration support. If an option is disabled, the user must manually configure that setting on its own file.",inst);
        }
        if(inst.genLibs && !inst.genLibDL){
            validation.logWarning("Driverlib inclusion is required for most use cases. Disable with caution.",inst,"genLibDL");
        }
        if(inst.genLibs && inst.genLibPMBUS){
            validation.logInfo("SMBUS is automatically included when adding PMBUS.",inst,"genLibSMBUS");
        }
        if(inst.genLibs && inst.genLibMC){
            validation.logInfo("IQMath is automatically included when adding Motor Control.",inst,"genLibIQ");
        }
    }

}

let deviceList = system.getScript("/ti/project_config/deviceList.js")

let compilerConfig = {
    name: "compiler",
    displayName: "Compiler",
    default: "Unknown",
    options: [
        {name: "Unknown"},
        {name: "ccs", displayName: "Using Stand-Alone Tool"},
        {name: "ticlang", displayName: "TIClang"},
        {name: "gcc", displayName: "GCC"},
        /* --- Temporarily Disabling IAR and KEIL options --- */
        {name: "iar", displayName: "IAR"},
        {name: "keil", displayName: "Keil"},
    ],
    getValue: () => {
        /* --- Temporarily Disabling IAR and KEIL options --- */
        return system.compiler;
    }
};
if(system.isStandAloneGUI() && (system.compiler == "ccs")){
    compilerConfig = {
        name: "compiler",
        displayName: "Compiler",
        longDescription: `
All project configuration files are generated by default. The user can select a
specific compiler to filter the generated files.

Currently only TI Arm Clang and Arm GCC are supported.
`,
        default: "ccs",
        options: [
            {name: "ccs", displayName: "All"},
            {name: "ticlang", displayName: "TIClang"},
            {name: "gcc", displayName: "GCC"},
            /* --- Temporarily Disabling IAR and KEIL options --- */
            // {name: "iar", displayName: "IAR"},
            // {name: "keil", displayName: "Keil"},
        ]
    }
}

/* Hide/Show Library Config */
function onChangeGenLibs(inst,ui){
    ui.genLibDL.hidden = !inst.genLibs;
    ui.genLibDrivers.hidden = !inst.genLibs;
    ui.genLibGC.hidden = !inst.genLibs;
    ui.genLibIQ.hidden = !inst.genLibs;
    ui.genLibIQVersion.hidden = (!inst.genLibIQ)||(!inst.genLibs);
    ui.genLibMC.hidden = !inst.genLibs;
    ui.genLibPMBUS.hidden = !inst.genLibs;
    ui.genLibSMBUS.hidden = !inst.genLibs;
    ui.genLibCMSIS.hidden = !inst.genLibs;
    ui.genLibGaugeL2.hidden = !inst.genLibs;
    ui.genLibGaugeL2Version.hidden = (!inst.genLibGaugeL2)||(!inst.genLibs);
};
/* Set File Gen Options as Read-Only when disabled */
function onChangeDisable(inst,ui){
    if(inst.genDisable){
        inst.genLinker          = false;
        inst.genStartup         = false;
        inst.genOpts            = false;
        inst.genLibs            = false;
    }
    ui.genLinker.readOnly   = inst.genDisable;
    ui.genStartup.readOnly  = inst.genDisable;
    ui.genOpts.readOnly     = inst.genDisable;
    ui.genLibs.readOnly     = inst.genDisable;
}

let deviceSelectLongDesc = `The device selection will be taken into account for
Linker and Linker Options file generation. The list of devices is filtered based
on the currently configured device family for the tool.
`;
if((["ccs","ticlang","gcc"].includes(system.compiler))&&(!system.isStandAloneGUI())){
    deviceSelectLongDesc = deviceSelectLongDesc += `User must make sure to
    select the same device as the CCS Launch Device setting for proper configuration.`
};

let config = [
    compilerConfig,
    {
        name: "genDisable",
        displayName: "Disable Project Configuration Files Generation",
        default: false,
        hidden: true,
        onChange: (inst,ui)=>{
            onChangeDisable(inst,ui);
            onChangeGenLibs(inst,ui);
        }
    },
    {
        name: "GROUP_FILEGEN",
        displayName: "File Generation",
        description: "",
        longDescription: "",
        collapsed: false,
        config: [
            {
                name: "genLinker",
                displayName: "Linker File Generation",
                longDescription: `
Linker command files can contain anything that might appear on the command line:
options, object file names, library names. More importantly, they allow
configuration of the MEMORY and SECTIONS directive, which appear in
every linker command file.

This file is specific to the selected device.
`,
                default: true,
            },
            {
                name: "genStartup",
                displayName: "Startup File Reference",
                longDescription: `
Startup file includes peripheral and interrupt configuration options.
This file will not be included on the SysConfig generated files section, but
rather is referenced from the installed SDK into the existing project. Thus, in
order to access the referenced file the user should open SysConfig through CCS.

This file is specific to the selected device family.
`,
                default: true,
            },
            {
                name: "genOpts",
                displayName: "Option File Generation",
                longDescription: `
The Linker Options file includes device-specific symbols for project configuration.

This file is specific to the selected device.
`,
                default: true,
            },
            {
                name: "genLibs",
                displayName: "Linker Libraries File Generation",
                longDescription: `
The Library Includes file will include the selected libraries on the project configuration.

This file is specific to the selected device family.
`,
                default: true,
                onChange: onChangeGenLibs,
            },
            {
                name: "GROUP_LIBS",
                displayName: "Include Libraries",
                description: "",
                longDescription: "",
                collapsed: false,
                config: [

                    // driverlib
                    {
                        name: "genLibDL",
                        displayName: "DriverLib",
                        default: true,
                        // readOnly: true,
                    },
                    // drivers
                    {
                        name: "genLibDrivers",
                        displayName: "TI Drivers",
                        default: false,
                    },
                    // gui composer
                    {
                        name: "genLibGC",
                        displayName: "GUI Composer",
                        default: false,
                    },
                    // iqmath
                    {
                        name: "genLibIQ",
                        displayName: "IQMath",
                        default: false,
                        onChange: (inst,ui) => {
                            ui.genLibIQVersion.hidden = !inst.genLibIQ;
                        }
                    },
                    {
                        name: "genLibIQVersion",
                        displayName: "Select IQMath version",
                        default: "RTS",
                        hidden: true,
                        options: [
                            {name: "RTS"},
                            {name: "MATHACL"},
                        ]
                    },
                    // motor control bldc sensorless foc
                    {
                        name: "genLibMC",
                        displayName: "Motor Control BLDC Sensorless FOC",
                        default: false,
                        onChange: (inst,ui) => {
                            if(inst.genLibMC){
                                inst.genLibIQ = true;
                            }
                            ui.genLibIQ.readOnly = inst.genLibMC;
                            ui.genLibIQVersion.hidden = !inst.genLibIQ;

                        }
                    },
                    // pmbus
                    {
                        name: "genLibPMBUS",
                        displayName: "PMBUS",
                        default: false,
                        onChange: (inst,ui) => {
                            ui.genLibSMBUS.readOnly = inst.genLibPMBUS;
                            if(inst.genLibPMBUS){
                                inst.genLibSMBUS = true;
                            }
                        }
                    },
                    // smbus
                    {
                        name: "genLibSMBUS",
                        displayName: "SMBUS",
                        default: false,

                    },
                    // cmsis
                    {
                        name: "genLibCMSIS",
                        displayName: "CMSIS/DSP",
                        default: false,
                    },
                    // Battery Gauge L2
                    {
                        name: "genLibGaugeL2",
                        displayName: "Battery Gauge L2",
                        default: false,
                        onChange: (inst,ui) => {
                            ui.genLibGaugeL2Version.hidden = !inst.genLibGaugeL2;
                        }
                    },
                    {
                        name: "genLibGaugeL2Version",
                        displayName: "Select Battery Gauge L2 version",
                        default: "RTS",
                        hidden: true,
                        options: [
                            {name: "RTS"},
                            {name: "MATHACL"},
                        ]
                    },
                ],
            },
        ],
    },
    {
        name: "migrationCondition",
        displayName: "Migration Condition",
        default: false,
        hidden: true,
    },
    {
        name: "switchCondition",
        displayName: "Switch Condition",
        default: false,
        hidden: true,
    },
    {
        name: "deviceSpin",
        displayName: "Select Device",
        longDescription: deviceSelectLongDesc,
        default: "Unknown",
        options: [
            {name:  "Unknown", displayName: "Default Board Configuration"},
        ].concat(deviceList.gpnOptions),
        onChange: (inst,ui) => {
            if(!inst.migrationCondition){
                inst.switchCondition = true;
            }
            inst.migrationCondition = false;

        }
    },
    {
        name: "deviceSpinAdvanced",
        displayName: "Active Device Spin",
        default: "Unknown",
        hidden: true,
        getValue: (inst) => {
            if(inst.deviceSpin !== "Unknown"){
                return inst.deviceSpin;
            }
            else{
                let defaultSpin = "MSPM0G3507";
                switch(Common.getDeviceFamily()){
                    case "MSPM0G1X0X_G3X0X":
                        defaultSpin = "MSPM0G3507";
                        break;
                    case "MSPM0L11XX_L13XX":
                        defaultSpin = "MSPM0L1306";
                        break;
                    case "MSPM0L122X_L222X":
                        defaultSpin = "MSPM0L2228"
                        break;
                    case "MSPM0C110X":
                        defaultSpin = "MSPM0C1104";
                        break;
                    case "MSPM0GX51X":
                        defaultSpin = "MSPM0G3519"
                        break;
                    default:
                        break;
                }
                return defaultSpin;
            }
        },
    }
];

function modules(inst){
    var mods = []
    let linkerExtension = MigrationCommon.getLinkerExtension(inst.compiler);
    /* --- Temporarily Disabling IAR and KEIL options --- */
    if(!["iar","keil"].includes(inst.compiler) && !(inst.genDisable)){
        if(inst.genStartup){
            let mod = {
                name: "startup",
                moduleName: "/ti/project_config/startup/startup.syscfg.js",
            }
            mods.push(mod);
        }
        if(inst.genOpts){
            let mod = {
                name: "opts",
                moduleName: "/ti/project_config/opt/board_opt.syscfg.js",
            }
            mods.push(mod);
        }
    }
    /* On default case: generate all files */

    if(inst.compiler == "ccs" && !(inst.genDisable)){
        if(inst.genLinker){
            let mod = {
                name: "genLinkerFileModTICLANG",
                moduleName: '/ti/project_config/linker/linker_cmd.syscfg.js',
            }
            mods.push(mod);
            mod = {
                name: "genLinkerFileModGCC",
                moduleName: '/ti/project_config/linker/linker_lds.syscfg.js',
            }
            mods.push(mod);
            /* --- Temporarily Disabling IAR and KEIL options --- */
            // mod = {
            //     name: "genLinkerFileModIAR",
            //     moduleName: '/ti/project_config/linker/linker_icf.syscfg.js',
            // }
            // mods.push(mod);
            // mod = {
            //     name: "genLinkerFileModKEIL",
            //     moduleName: '/ti/project_config/linker/linker_sct.syscfg.js',
            // }
            // mods.push(mod);
        }
        if(inst.genLibs){
            let mod = {
                name: "board_genlibs_cmd",
                moduleName: "/ti/project_config/linker/board_genlibs_cmd.syscfg.js",
            }
            mods.push(mod);
            mod = {
                name: "board_genlibs_lds",
                moduleName: "/ti/project_config/linker/board_genlibs_lds.syscfg.js",
            }
            mods.push(mod);
            /* --- Temporarily Disabling IAR and KEIL options --- */
            // mod = {
            //     name: "board_genlibs_icf",
            //     moduleName: "/ti/project_config/linker/board_genlibs_icf.syscfg.js",
            // }
            // mods.push(mod);
            // mod = {
            //     name: "board_genlibs_sct",
            //     moduleName: "/ti/project_config/linker/board_genlibs_sct.syscfg.js",
            // }
            // mods.push(mod);
        }
    }else{
        /* --- Temporarily Disabling IAR and KEIL options --- */
        if(!["iar","keil"].includes(inst.compiler) && !(inst.genDisable)){
            if(inst.genLinker){
                let mod = {
                    name: "genLinkerFileMod",
                    moduleName: '/ti/project_config/linker/linker_'+linkerExtension,
                }
                mods.push(mod);
            }
            if(inst.genLibs){
                let mod = {
                    name: "board_genlibs",
                    moduleName: "/ti/project_config/linker/board_genlibs_"+linkerExtension,
                }
                mods.push(mod);
            }
        }
    }

    return mods
}

function moduleInstances(inst){
    let modInstances = []
    return modInstances;
}

/*
 *  ======== base ========
 */
let base = {
    displayName     : "Project Configuration Files",
    description     : "Project Configuration Files",
    longDescription : ``,
    moduleStatic    : {
        config          : config,
        validate        : validate,
        modules         : modules,
        onMigrate       : function (newInst, oldInst, oldSystem) {
            newInst.deviceSpin = "Unknown";
            newInst.migrationCondition = true;
            newInst.switchCondition = false;
        },
    },
    // templates    : {}

};

/*
 *  ======== exports ========
 */
exports = base;
