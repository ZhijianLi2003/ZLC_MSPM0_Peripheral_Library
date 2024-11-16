/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
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
 *  ======== driverlib.component.js ========
 */

"use strict";

/* get ti/drivers common utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");
let topModules;
let displayName = "MSPM0 Driver Library";
let description = "MSPM0 DriverLib System Configuration";
/* universal modules */
let systemModulesList = [
    "/ti/driverlib/SYSCTL",
    "/ti/driverlib/Board",
    "/ti/driverlib/DMA",
    "/ti/driverlib/GPIO",
    "/ti/driverlib/WWDT",
];
/* nonmain */
// TODO: NONMAIN support for M0GX51X to be added later
if(!Common.isDeviceFamily_PARENT_MSPM0GX51X()){
systemModulesList.push(
    "/ti/driverlib/NONMAIN",
);
}
/* System: MSPM0Gxx-specific modules */
if(Common.isDeviceM0G()){
    systemModulesList.push(
        "/ti/driverlib/MATHACL",
    );
};
/* System: MSPM0Gxx-specific modules */
if(Common.isDeviceFamily_PARENT_MSPM0G1X0X_G3X0X()){
    systemModulesList.push(
        "/ti/driverlib/RTC",
    );
};
/* System: MSPM0L122X_L222X-specific modules */
if(Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()){
    systemModulesList.push(
        "/ti/driverlib/IWDT",
        "ti/driverlib/RTCA",
        "ti/driverlib/TAMPERIO",
    );
};
/* System (LCD): MSPM0L222X-specific modules */
if(Common.isDeviceFamily_PARENT_MSPM0L222X()){
    systemModulesList.push(
        "/ti/driverlib/LCD",
    );
};
/* System (SYSTICK): Devices with SysTick support */
if(Common.isDeviceM0G() || Common.isDeviceM0L()){
    systemModulesList.push(
        "/ti/driverlib/SYSTICK",
    );
};
/* System (BEEPER): MSPM0Cxx-specific modules */
if(Common.isDeviceM0C()){
    systemModulesList.push(
        "/ti/driverlib/BEEPER",
    );
};

let timerModulesList = [
    "/ti/driverlib/PWM",
    "/ti/driverlib/TIMER",
    "/ti/driverlib/CAPTURE",
    "/ti/driverlib/COMPARE",
];
/* Timer (QEI): Devices with QEI support */
if(Common.isDeviceM0G() || Common.isDeviceM0C()){
    timerModulesList.push(
        "/ti/driverlib/QEI",
    );
};
/* Timer (FAULT): Devices that support Timer Fault configuration */
if(Common.hasTimerA()){
    timerModulesList.push(
        "/ti/driverlib/TIMERFault",
    );
};

let commModulesList = [
    "/ti/driverlib/UART",
    "/ti/driverlib/uartLIN",
    "/ti/driverlib/I2C",
    "/ti/driverlib/i2cSMBUS",
    "/ti/driverlib/SPI",
];

let analogModulesList = [
    "/ti/driverlib/ADC12",
    "/ti/driverlib/VREF",
];
/* Analog (GPAMP): add device-specific modules - not available on MSPM0Cxx */
if(Common.isDeviceFamily_PARENT_MSPM0G1X0X_G3X0X() || Common.isDeviceFamily_PARENT_MSPM0L11XX_L13XX()){
    analogModulesList.push(
        "/ti/driverlib/GPAMP",
    )
}
/* add device-specific modules - not available on MSPM0X110X, MSPM0C */
if((Common.isDeviceM0G() || Common.isDeviceM0L()) && !Common.isDeviceM0x110x() && !Common.isDeviceM0x310x()){
    analogModulesList.push(
        "/ti/driverlib/COMP",
    );
};
/* add device-specific modules - not available on MMSPM0X110X or MSPM0LX22X, or MSPM0GX51X*/
if((Common.isDeviceFamily_PARENT_MSPM0G1X0X_G3X0X() || Common.isDeviceFamily_PARENT_MSPM0L11XX_L13XX()) && !Common.isDeviceM0x110x() && !Common.isDeviceM0x310x()){
    analogModulesList.push(
        "/ti/driverlib/OPA",
    );
};
/* MSPM0Gxx-specific modules - only available for MSPM0G350X and MSPM0G150X */
if(["MSPM0G350X","MSPM0G150X"].includes(system.deviceData.device) || Common.isDeviceFamily_PARENT_MSPM0GX51X()){
    analogModulesList.push(
        "/ti/driverlib/DAC12",
    );
};
/* MSPM0Gxx-specific modules - only available for MSPM0G350X, MSPM0G310X, MSPM0G351X */
if(["MSPM0G350X","MSPM0G310X", "MSPM0G351X"].includes(system.deviceData.device)){
    commModulesList.push(
        "/ti/driverlib/MCAN",
    );
};

let securityModulesList = [
]
/* MSPM0Gxx-specific modules - not available for MSPM0G110x */
if(Common.isDeviceFamily_PARENT_MSPM0G1X0X_G3X0X() && !Common.isDeviceM0x110x()){
    securityModulesList.push(
        "/ti/driverlib/AES",
    );
};
/* MSPM0Gxx-specific modules - not available for MSPM0G110x */
if(Common.isDeviceM0G() && !Common.isDeviceM0x110x()){
    securityModulesList.push(
        "/ti/driverlib/TRNG",
    );
};
/* Modules available on MSPM0L122X_L222X and MSPM0GX51X  */
if(Common.isDeviceFamily_PARENT_MSPM0L122X_L222X() || Common.isDeviceFamily_PARENT_MSPM0GX51X()){
    securityModulesList.push(
        "/ti/driverlib/AESADV",
    );
};
/* Modules available on MSPM0L122X_L222X */
if(Common.isDeviceFamily_PARENT_MSPM0L122X_L222X()){
    securityModulesList.push(
        "/ti/driverlib/SECCONFIG",
    );
};

let dataIntegrityModulesList = [
]
/* add device-specific modules - not available on MSPM0L122X_L222X */
if(Common.isDeviceFamily_PARENT_MSPM0G1X0X_G3X0X() || Common.isDeviceFamily_PARENT_MSPM0L11XX_L13XX() || Common.isDeviceM0C()){
    dataIntegrityModulesList.push(
        "/ti/driverlib/CRC",
    );
};
/* Modules available on MSPM0L122X_L222X and MSPM0GX51X */
if(Common.isDeviceFamily_PARENT_MSPM0L122X_L222X() || Common.isDeviceFamily_PARENT_MSPM0GX51X()){
    dataIntegrityModulesList.push(
        "/ti/driverlib/CRCP",
    );
};

let readOnlyModulesList = [
    "/ti/driverlib/EVENT",
];

topModules = [
    {
        displayName: displayName,
        description: description,
        categories: [
            {
                displayName: "System",
                modules: systemModulesList
            },
            {
                displayName: "Analog",
                modules: analogModulesList
            },
            {
                displayName: "Communications",
                modules: commModulesList
            },
            {
                displayName: "Timers",
                modules: timerModulesList
            },
            {
                displayName: "Security",
                modules: securityModulesList
            },
            {
                displayName: "Data Integrity",
                modules: dataIntegrityModulesList
            },
            {
                displayName: "Read-Only",
                modules: readOnlyModulesList
            }
        ]
    },
];

let templates = [
    {
        "name": "/ti/driverlib/templates/Board.c.xdt",
        "outputPath": "ti_msp_dl_config.c",
        "alwaysRun": false
    },
    {
        "name": "/ti/driverlib/templates/Board.h.xdt",
        "outputPath": "ti_msp_dl_config.h",
        "alwaysRun": false
    },
    {
        "name": "/ti/driverlib/templates/peripheralPinAssignments.txt.xdt",
        "outputPath": "peripheralPinAssignments.txt",
        "alwaysRun": false
    },
    {
        "name": "/ti/driverlib/templates/EVENT.dot.xdt",
        "outputPath": "Event.dot",
        "alwaysRun": false
    },
    /* TODO: Future enhancement: remove nonmain from driverlib area */
    {
        "name": "/ti/driverlib/nonmain/NonMain.c.xdt",
        "outputPath": "boot_config.c",
        "alwaysRun": false
    },
    {
        "name": "/ti/driverlib/nonmain/NonMain.h.xdt",
        "outputPath": "boot_config.h",
        "alwaysRun": false
    },
    {
        "name": "/ti/driverlib/sec_config/SECCONFIG.Board.h.xdt",
        "outputPath": "customer_secure_config.h",
        "alwaysRun": false
    },
];

/*
 * ======== getExtraMigrationMarkdown ========
 * Returns aggregated text in markdown format that customers can use to aid in
 * migrating a project between device/boards.
 *
 *
 * @returns String - Full extra markdown text
 */
function getExtraMigrationMarkdown()
{
    const fixedMarkdown = `See \
    [MSPM0 SDK CCS IDE Guide](https://dev.ti.com/tirex/explore/node?node=A__AGfjuVVhlYfXCIsTGwVuIA__MSPM0-SDK__a3PaaoK__LATEST)\
    for extended details on Migrating Between MSPM0 Derivatives. \n\n`;

    return(fixedMarkdown);
}


/*
 * ======== getIsMigrationValidDialog ========
 * Determines whether a migration from one board/device to another board/device
 * is supported by all the currently selected stacks.
 *
 * @param args - Object. Only contains the target device/board
 *
 * @returns Object - Object containing aggregated warning or disable hover text
 *                   to determine whether a migration is fully supported,
 *                   disabled, or flagged with a warning symbol
 */
function getIsMigrationValidDialog(args){
    /* Note: currently no existing case-specific validation, return valid use case */
    return({});
}

/*
 * ======== getMigrationDialogInfo ========
 * Allows for modules to contribute additional markdown text to the migration
 * instructions and to determine whether a migration is fully supported,
 * disabled, or flagged with a warning symbol
 *
 * @returns Object - Object containing extra markdown text and hover text used
 *                   to determine whether a migration is supported
 */
function getMigrationDialogInfo(){
    return({
        extraMarkdown: getExtraMigrationMarkdown(),
        isValid: (args) => getIsMigrationValidDialog(args)
    });
}

exports = {
    displayName: displayName,
    topModules: topModules,
    templates: templates,
    getMigrationDialogInfo: getMigrationDialogInfo
};
