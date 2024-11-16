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
 *  ======== CRCMSPM0.syscfg.js ========
 */

"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

/************************* Profiles functions *******************************/
const profilesCRC = [
    {
        /* CRC16_AUG_CCIT */
        name                    : "CONFIG_PROFILE_1",
        polynomial              : "16_POLYNOMIAL_AUG_CCIT",
        bitReverse              : "NOT_REVERSED",
        endianness              : "LITTLE_ENDIAN",
        byteswap                : false,
        seed                    : 0x1D0F,
    },
    {
        /* CRC32_JAMCRC */
        name                    : "CONFIG_PROFILE_2",
        polynomial              : "32_POLYNOMIAL_JAMCRC",
        bitReverse              : "REVERSED",
        endianness              : "LITTLE_ENDIAN",
        byteswap                : false,
        seed                    : 0xFFFFFFFF,
    },
];

/************************* General functions **********************************/
/*
 * Polynomial Configuration:
 * MSPM0G / MSPM0L support 32 and 16-bit polynomial.
 * MSPM0C only supports 16-bit polynomial
 */
let polyOptions = [];
if(Common.isDeviceM0G() || Common.isDeviceM0L()){
    polyOptions.push({name: "32_POLYNOMIAL_MPEG2", displayName: "CRC-32 MPEG2"})
}
polyOptions = polyOptions.concat([
    {name: "16_POLYNOMIAL_CCIT_ZERO", displayName: "CRC-16 CCIT ZERO"},
    {name: "16_POLYNOMIAL_ARC", displayName: "CRC-16 ARC"},
    {name: "16_POLYNOMIAL_AUG_CCIT", displayName: "CRC-16 AUG CCIT"},
    {name: "16_POLYNOMIAL_BUYPASS", displayName: "CRC-16 BUYPASS"},
    {name: "16_POLYNOMIAL_CCIT_FALSE", displayName: "CRC-16 CCIT FALSE"},
    {name: "16_POLYNOMIAL_CDMA2000", displayName: "CRC-16 CDMA2000"},
    {name: "16_POLYNOMIAL_MODBUS", displayName: "CRC-16 MODBUS"},
    {name: "16_POLYNOMIAL_CUSTOM", displayName: "CRC-16 CUSTOM"},
    {name: "32_POLYNOMIAL_Q", displayName: "CRC-32 Q"},
    {name: "32_POLYNOMIAL_JAMCRC", displayName: "CRC-32 JAMCRC"},
    {name: "32_POLYNOMIAL_XFER", displayName: "CRC-32 XFER"},
    {name: "32_POLYNOMIAL_CUSTOM", displayName: "CRC-32 CUSTOM"},
]);

const bitReverseOptions = [
    {name: "NOT_REVERSED", displayName: "Not reversed"},
    {name: "REVERSED"   , displayName: "Reversed"},
]

const endiannessOptions = [
    {name: "LITTLE_ENDIAN", displayName: "Little"},
    {name: "BIG_ENDIAN"   , displayName: "Big"},
]

function onChangeSetCustomProfile(inst,ui){
    inst.profile = "CUSTOM";
}

function onChangeCRCProfile(inst, ui) {
    if (inst.profile != "CUSTOM")
    {
        let selectedProfileArray = profilesCRC.filter(obj =>
                                        {return obj.name === inst.profile});
        if (selectedProfileArray.length != 0)
        {
            const selectedProfile = Object.assign({}, selectedProfileArray[0]);
            delete selectedProfile.name;
            Object.assign(inst, selectedProfile)
        }
    }
    else{
        ui.polynomialDisplayed.hidden = false;
        ui.polynomialTypeIn.hidden = true;
    }
}

//todo
function onChangeCfgPoly(inst, ui)
{
    inst.profile = "CUSTOM";
    if (inst.polynomial == "16_POLYNOMIAL_CUSTOM" || inst.polynomial == "32_POLYNOMIAL_CUSTOM"){
        ui.polynomialDisplayed.hidden = true;
        ui.polynomialTypeIn.hidden = false;
    }
    else{
        ui.polynomialDisplayed.hidden = false;
        ui.polynomialTypeIn.hidden = true;
    }
}

/************************* Basic functions *******************************/

/* onChange functions for Basic Configuration */
function onChangeCfgBitReverse(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

/* onChange functions for Basic Configuration */
function onChangeCfgEndianness(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}
/* onChange functions for Basic Configuration */
function onChangeCfgSeed(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

/* Profile Options vary by device depending on Polynomial availability */
let profileOptions = [
    {name: "CONFIG_PROFILE_1", displayName: "CRC-16 CCITT"},
];
/* CRC32 only supported on MSPM0G and MSPM0L */
if(Common.isDeviceM0G() || Common.isDeviceM0L()){
    profileOptions = profileOptions.concat([
        {name: "CONFIG_PROFILE_2", displayName: "CRC-32 ISO-3309"},
    ]);
}
profileOptions.push({name: "CUSTOM", displayName: "Custom"},)

/* PROFILES CONFIGURATION */
let CRCConfig = [
    /****** PROFILES CONFIGURATION *******/
    {
        name: "GROUP_PROFILE",
        displayName: "Quick Profiles",
        description: "",
	    collapsed: false,
        config: [
            {
                name        : "profile",
                displayName : "CRCP Profiles",
                description : 'Pre-defined profiles for typical CRC configurations',
                longDescription: `
The CRC accelerator produces signatures for given sequences of data.\n
CRC16-CCITT and CRC32-ISO3309 CRC functions are supported.\n
Identical input data sequences result in identical CRC signatures when the CRC
is initialized with a fixed seed value.\n
Different sequences of input data, in general, result in different signatures
for a given CRC function.

![CRC Polynomials](../docs/english/sysconfig/images/crcpolynomials.png "CRC Polynomials")

The following online tool can be used to calculate the output of the CRC:
[CRC online tool](http://www.sunshine2k.de/coding/javascript/crc/crc_js.html)

The Quick Profile Options are:
* **CRC16-CCITT**:
    * Polynomial: CRC16_AUG_CCIT
    * Bit order: Not reversed
    * Endianess: Little
    * Output Byteswap: Disabled
    * Seed Value: 0x1D0F
* **CRC32-ISO3309**:
    * Polynomial: CRC32_JAMCRC
    * Bit order: Reversed
    * Endianess: Little
    * Output Byteswap: Disabled
    * Seed Value: 0xFFFFFFFF
* **Custom**:
    * Allows custom configuration.`,
                hidden      : false,
                default     : "CUSTOM",
                options     : profileOptions,
                onChange    : onChangeCRCProfile,
            },
        ],
    },
]

/*
 * Polynomial Configuration:
 * MSPM0G / MSPM0L support 32 and 16-bit polynomial.
 * MSPM0C only supports 16-bit polynomial
 */
let polyConfig = {
    name        : "polynomial",
    displayName : "CRC Polynomial",
    description : 'Select the polynomial to be used by the CRC calculation',
    longDescription:`
The CRCP Polynomial selected.\n
A pre-configured polynomial can be selected or a custom 16 or 32-bit polynomial can be inputted in hex format using the Polynomial Value field if either CRC-16 CUSTOM or CRC-32 CUSTOM is selected.\n
If inputting a custom polynomial for a 16-bit CRC, x^16 is implied and should not be included in the inputted hex value for the polynomial. For a 32-bit CRC, x^32 is implied and should not be included in the inputted hex value for the polynomial.\n
`,
    hidden      : false,
    default     : "32_POLYNOMIAL_JAMCRC",
    options     : polyOptions,
    onChange    : onChangeCfgPoly,
};
if(Common.isDeviceM0C()){
    polyConfig = {
        name        : "polynomial",
        displayName : "CRC Polynomial",
        description : 'Select the polynomial to be used by the CRCP calculation',
        longDescription:`
The CRCP Polynomial selected.\n
A pre-configured polynomial can be selected or a custom 16 or 32-bit polynomial can be inputted in hex format using the Polynomial Value field if either CRC-16 CUSTOM or CRC-32 CUSTOM is selected.\n
If inputting a custom polynomial for a 16-bit CRC, x^16 is implied and should not be included in the inputted hex value for the polynomial. For a 32-bit CRC, x^32 is implied and should not be included in the inputted hex value for the polynomial.\n
    `,
        hidden      : false,
        default     : "16_POLYNOMIAL",
        options     : polyOptions,
        onChange    : onChangeCfgPoly,
        readOnly    : Common.isDeviceM0C(),
    };
}

CRCConfig = CRCConfig.concat([
    {
        name: "GROUP_BASIC",
        displayName: "Configuration",
        description: "",
        longDescription:
`Basic CRC options allow configuration of polynomial, bit order, endianess, and
seed value.
`,
        collapsed: false,
        config: [
            /* Polynomial OPtion availability depends on device selection */
            polyConfig,
            {
                name        : "polynomialDisplayed",
                displayName : "Polynomial Value",
                description : 'Polynomial',
                longDescription:`
The hex value of the polynomial selected. Can be typed in or from a pre-selected option. In order to convert from the hex value to the polynomial:\n
(1) Convert the hex value to binary\n
(2) Add x to the power of each bit that is set + x to the total number of bits in the polynomial\n
\n
With CRC16-CCITT, the polynomial hex value is 0x1021\n
(1) 0x1021 in binary is 0001000000100001\n
(2) Bits 0, 5, and 12 are set. So, we will add x to the power of 0, 5, 12, and 16.\n
\n
        `,
                hidden      : false,
                getValue    : (inst) => getCRCPPolynomial(inst),
                default     : 0,
                displayFormat: "hex",
                //options     : bitReverseOptions,
                //onChange    : onChangeCfgPolynomialField,
            },
            {
                name        : "polynomialTypeIn",
                displayName : "Polynomial",
                description : 'Polynomial',
                longDescription:`
The hex value of the polynomial. In order to convert from the hex value to the polynomial:\n
(1) Convert the hex value to binary\n
(2) Add x to the power of each bit that is set + x to the total number of bits in the polynomial\n
\n
With CRC16-CCITT, the polynomial hex value is 0x1021\n
(1) 0x1021 in binary is 0001000000100001\n
(2) Bits 0, 5, and 12 are set. So, we will add x to the power of 0, 5, 12, and 16.\n
\n
        `,
                hidden      : true,
                default     : 0,
                displayFormat: "hex",
                //options     : bitReverseOptions,
                //onChange    : onChangeCfgPolynomialField,
            },
            {
                name        : "bitReverse",
                displayName : "Input/Output Bit Order",
                description : 'Select the Input/Output Order',
                longDescription:`
The CRC Input/Output bit order can select the following options:
* Not Reversed
* Reversed
        `,
                hidden      : false,
                default     : "NOT_REVERSED",
                options     : bitReverseOptions,
                onChange    : onChangeCfgBitReverse,
            },
            {
                name        : "endianness",
                displayName : "Input Byte Order (Endianness)",
                description : 'Byte order within a word or half word of input',
                longDescription:`
The CRC Input byte order can select the following options:
* Little
* Big

![CRC Byte Endianness](../docs/english/sysconfig/images/crcendianess.png "CRC Byte Endianness")

        `,
                hidden      : false,
                default     : "LITTLE_ENDIAN",
                options     : endiannessOptions,
                onChange    : onChangeCfgEndianness,
            },
            {
                name        : "byteswap",
                displayName : "Enable Output Byteswap",
                description : 'CRC output byteswap',
                longDescription:`
The CRC output byteswap can be enabled or disabled.

![CRC Byteswap 16-bit Polynomial](../docs/english/sysconfig/images/crcByteswap16.png "CRC Byteswap 16-bit Polynomial")

![CRC Byteswap 32-bit Polynomial](../docs/english/sysconfig/images/crcByteswap32.png "CRC Byteswap 32-bit Polynomial")
        `,
                hidden      : false,
                default     : false,
                onChange    : onChangeSetCustomProfile,
            },
            {
                name        : "seed",
                displayName : "CRCP Seed",
                description : 'Set CRCP seed value',
                longDescription:`
The P seed valid range has a dependency with the CRC polynomial selected. Below are
the valid ranges based on the CRC polynomial selected:
* CRC-32 ISO-3309 valid range [0x00000000,0xFFFFFFFF]
* CRC-16 CCITT valid range [0x0000,0xFFFF]
`,
                hidden      : false,
                default     : 0,
                isInteger   : true,
                displayFormat: "hex",
                onChange    : onChangeCfgSeed,
            },
        ],

    },
])

/* CRC does not support DMA configuration for MSPM0Cxx */
if(!Common.isDeviceM0C()){
CRCConfig = CRCConfig.concat([
    {
        name: "GROUP_DMA",
        displayName: "DMA Configuration",
        longDescription: `
This section allows configuring a DMA Channel to be used for CRC calculation.\n
When the DMA functionality is enabled, the CRC module will configure the DMA
channel's trigger to software trigger which allows users to trigger the
calculation at the application level, after the DMA source and destination addresses
and the CRC seed value have been loaded.\n
`,
	    collapsed: true,
        config: [
            {
                name        : "enableCRCCalcWithDMA",
                displayName : "Configure DMA Channel For CRC",
                description : 'Configures a DMA channel to be used for CRC calculation',
                longDescription:
                `Only one DMA channel can be configured for this calculation \n`,
                hidden      : false,
                default     : false,
                onChange    : onChangeSetCustomProfile

            },
        ]
    },
])
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
    // Common.validateNames(inst, validation);

    if(inst.polynomial.slice(0,2) == "16"){
        if(inst.seed > 0xFFFF){
            validation.logError(
                "CRCP seed valid range is [0x0000,0xFFFF]",
                inst, "seed"
            );
        }
    }else if (inst.polynomial.slice(0,2) == "32"){
        if(inst.seed > 0xFFFFFFFF){
            validation.logError(
                "CRCP seed valid range is [0x00000000,0xFFFFFFFF])",
                inst, "seed"
            );
        }
    }

    if(inst.polynomial.slice(14) == "CUSTOM"){
        if (inst.polynomialTypeIn == 0){
            validation.logError(
                "Must type in a polynomial", inst, "polynomialTypeIn"
            );
        }
        else if (inst.polynomial.slice(0,2) == "16" && inst.polynomialTypeIn > 0xFFFF){
            validation.logError(
                "CRC polynomial valid range is (0x0000,0xFFFF]", inst, "polynomialTypeIn"
            );
        }
        else if (inst.polynomial.slice(0,2) == "32" && inst.polynomialTypeIn > 0xFFFFFFFF){
            validation.logError(
                "CRC polynomial valid range is (0x00000000,0xFFFFFFFF]", inst, "polynomialTypeIn"
            );
        }
    }

}

/*
 * Gets a DMA module if available
 */
function moduleInstances(inst){
    let modInstances = []
    if(inst.enableCRCCalcWithDMA){
        let mod = {
            name: "DMA_CHANNEL_CRC",
            displayName: "DMA Channel for CRC",
            moduleName: '/ti/driverlib/DMAChannel',
            group: "GROUP_DMA",
            args: {

            },
            requiredArgs: {
                hideTriggerSelect: false,
                passedTriggerSelect: 0,
                triggerNumber: "DMA_SOFTWARE_TRIG",
                triggerSelect:"SW",
                addressMode:"b2f",
                transferMode:"SINGLE_BLOCK",
                transferSize: 1,
                tableSrcAddressInc:"UNCHANGED",
            },

        }
        modInstances.push(mod);
    }
    return modInstances;
}

/*
 *  ======== devSpecific ========
 *  Device-specific extensions to be added to base module configuration
 */
let devSpecific = {

    config: CRCConfig,

    validate: validate,

    moduleInstances: moduleInstances,

    modules: setRequiredModules,

};

function setRequiredModules(inst){
    let theModules = ["Board", "SYSCTL"]
    if(inst.enableCRCCalcWithDMA){
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

function getCRCPPolynomial(inst) {
    var crcp_poly_hex = 0;
    switch (inst.polynomial){
        case "32_POLYNOMIAL_MPEG2":
            crcp_poly_hex = 0x04C11DB7;
            break;
        case "32_POLYNOMIAL_Q":
            crcp_poly_hex = 0x814141AB;
            break;
        case "32_POLYNOMIAL_JAMCRC":
                crcp_poly_hex = 0x04C11DB7;
                break;
        case "32_POLYNOMIAL_XFER":
            crcp_poly_hex = 0x000000AF;
            break;
        case "16_POLYNOMIAL_CCIT_ZERO":
            crcp_poly_hex = 0x00001021;
            break;
        case "16_POLYNOMIAL_ARC":
            crcp_poly_hex = 0x00001DCF;
            break;
        case "16_POLYNOMIAL_AUG_CCIT":
            crcp_poly_hex = 0x00001021;
            break;
        case "16_POLYNOMIAL_BUYPASS":
            crcp_poly_hex = 0x00008005;
            break;
        case "16_POLYNOMIAL_CCIT_FALSE":
            crcp_poly_hex = 0x00001021;
            break;
        case "16_POLYNOMIAL_CDMA2000":
            crcp_poly_hex = 0x0000C867;
            break;
        case "16_POLYNOMIAL_MODBUS":
            crcp_poly_hex = 0x00001DCF;
            break;
   }
   return crcp_poly_hex;
}
