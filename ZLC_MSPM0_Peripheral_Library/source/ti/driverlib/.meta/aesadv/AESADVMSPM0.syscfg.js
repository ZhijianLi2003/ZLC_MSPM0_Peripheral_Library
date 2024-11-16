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
 *  ======== AESADVMSPM0.syscfg.js ========
 */

"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");


/*
 *  ======== _getPinResources ========
 */
function _getPinResources(inst)
{

}

/*
 *  ======== validatePinmux ========
 *  Validation run after solution
 *
 *  param inst       - module instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validatePinmux(inst, validation) {

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
    /* Check that CMAC and CBCMAC are only using encryption */
    if (inst.mode == "DL_AESADV_MODE_CMAC" || inst.mode == "DL_AESADV_MODE_CBCMAC")
    {
        if (inst.direction != "DL_AESADV_DIR_ENCRYPT")
        {
            validation.logError(
                "CMAC/CBCMAC must use encryption.",
                inst, "direction"
            );
        }
    }
    /* Check that names for key, IV, and nonce are valid C names */
    if (inst.key.length)
    {
        if (!Common.isCName(inst.key))
        {
            validation.logError(
                "Key name must be a valid C identifier.",
                inst, "key"
            );
        }
    }

    if (inst.iv.length)
    {
        if (!Common.isCName(inst.iv))
        {
            validation.logError(
                "IV name must be a valid C identifier.",
                inst, "iv"
            );
        }
    }

    if (inst.nonce.length)
    {
        if (!Common.isCName(inst.nonce))
        {
            validation.logError(
                "Nonce name must be a valid C identifier.",
                inst, "nonce"
            );
        }
    }

    /* AAD length for CCM must be within [0, (2^16 - 2^8, or 0xFF00)] */
    if (inst.mode == "DL_AESADV_MODE_CCM")
    {
        if (inst.aadLength > 0xFF00)
        {
            validation.logError("AAD length for CCM must be within 0 to (2^16 - 2^8) bytes",
                inst, "aadLength");
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
    /* AESADV has no pinmux requirements */
    return ([]);
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
    return (true);
}

/************************* AESADV Option Structures *************************/
const AESADVModeOptions = [
    {name: "DL_AESADV_MODE_ECB", displayName: "Electronic Codebook (ECB)"},
    {name: "DL_AESADV_MODE_CBC", displayName: "Cipher Block Chaining (CBC)"},
    {name: "DL_AESADV_MODE_CTR", displayName: "Counter (CTR)"},
    {name: "DL_AESADV_MODE_ICM", displayName: "Integer Counter Mode (ICM)"},
    {name: "DL_AESADV_MODE_CFB", displayName: "Cipher Feedback (CFB)"},
    {name: "DL_AESADV_MODE_OFB", displayName: "Output Feedback (OFB)"},
    //TODO: sanity tests may flag the displayNames being too long (> 32 chars)
    {name: "DL_AESADV_MODE_CMAC", displayName: "CMAC"},
    {name: "DL_AESADV_MODE_CBCMAC", displayName: "CBCMAC"},
    {name: "DL_AESADV_MODE_GCM_FORCE_ZERO", displayName: "GCM - Y0 forced to 0"},
    {name: "DL_AESADV_MODE_GCM_LOAD_HASH_KEY", displayName: "GCM - Y0 calculated internally"},
    {name: "DL_AESADV_MODE_GCM_AUTONOMOUS", displayName: "GCM - Both H and Y0 calculated internally"},
    {name: "DL_AESADV_MODE_GCM_HASH_ONLY", displayName: "GCM - GHASH only"},
    {name: "DL_AESADV_MODE_CCM", displayName: "CCM"},
];

const ctrCounterWidthOptions = [
    {name: "DL_AESADV_CTR_WIDTH_32_BIT", displayName: "32-bit counter"},
    {name: "DL_AESADV_CTR_WIDTH_64_BIT", displayName: "64-bit counter"},
    {name: "DL_AESADV_CTR_WIDTH_96_BIT", displayName: "96-bit counter"},
    {name: "DL_AESADV_CTR_WIDTH_128_BIT", displayName: "128-bit counter"},
];

function getInterruptOptions()
{
    let options = [
        {name: "DL_AESADV_INTERRUPT_OUTPUT_READY", displayName: "Output Ready Interrupt"},
        {name: "DL_AESADV_INTERRUPT_INPUT_READY", displayName: "Input Ready Interrupt"},
        {name: "DL_AESADV_INTERRUPT_SAVED_OUTPUT_CONTEXT_READY", displayName: "Saved Context Ready Interrupt"},
        {name: "DL_AESADV_INTERRUPT_INPUT_CONTEXT_READY", displayName: "Context Ready Interrupt"},
    ];

    return options;
};

/************************* Profiles functions *******************************/
const profilesAESADV = [
    {
        //TODO: Determine supported quick profile options
    },
];

/*
 *  ======== onChangeProfiles ========
 *  Set options based on configuration profiles selection
 */
function onChangeProfiles(inst,ui)
{
    //TODO when profiles are defined
}

function onChangeCustomProfile(inst,ui)
{
    // TODO when profiles are defined
    // inst.chosenProfile = "custom";
}

function onChangeMode(inst, ui)
{
    updateGUICTR_ctrWidth(inst, ui);
    updateGUICFB_fbWidth(inst, ui);
    updateGUICCMSpecificFields(inst, ui);
    updateGUIIV(inst, ui);
    updateGUIAADLength(inst, ui);
    // onChangeCustomProfile(inst, ui); TODO: when defining profiles
}

function updateGUICTR_ctrWidth(inst, ui)
{
    /*
     * Only AES CTR, CCM, and GCM modes (with the exception of GHASH_ONLY)
     * use a counter. ctr_ctrWidth should only be visible in these modes
     */
    let modesUsingCtr = ["DL_AESADV_MODE_CTR", "DL_AESADV_MODE_CCM",
        "DL_AESADV_MODE_GCM_FORCE_ZERO", "DL_AESADV_MODE_GCM_LOAD_HASH_KEY",
        "DL_AESADV_MODE_GCM_AUTONOMOUS"];

    ui.ctr_ctrWidth.hidden = !(modesUsingCtr.includes(inst.mode));

    // /* Reset ctr_ctrWidth to default values */
    // inst.ctr_ctrWidth = (modesUsingCtr.includes(inst.mode)) ?
    //     inst.ctr_ctrWidth : "DL_AESADV_CTR_WIDTH_32_BIT";
}

function updateGUICFB_fbWidth(inst, ui)
{
    /* cfb_fbWidth should only be visible in AES CFB and OFB modes */
    let modesUsingFb = ["DL_AESADV_MODE_CFB", "DL_AESADV_MODE_OFB"];

    ui.cfb_fbWidth.hidden = !(modesUsingFb.includes(inst.mode));
}

function updateGUICCMSpecificFields(inst, ui)
{
    /* The following fields are specific to CCM */
    ui.ccm_ctrWidth.hidden = !(inst.mode == "DL_AESADV_MODE_CCM");
    ui.ccm_tagWidth.hidden = !(inst.mode == "DL_AESADV_MODE_CCM");

    /* Reset the CCM width fields */
    inst.ccm_ctrWidth = (inst.mode == "DL_AESADV_MODE_CCM") ? inst.ccm_ctrWidth : 2;
    inst.ccm_tagWidth = (inst.mode == "DL_AESADV_MODE_CCM") ? inst.ccm_tagWidth : 1;

    ui.initApplicationNonce.hidden = !(inst.mode == "DL_AESADV_MODE_CCM");
    ui.nonce.hidden = !(inst.mode == "DL_AESADV_MODE_CCM");

    // /* Reset the nonce */
    // inst.nonce = (inst.mode == "DL_AESADV_MODE_CCM") ? inst.nonce : "";
}

function updateGUIIV(inst, ui)
{
    /*
     * The IV doesn't need to be provided for ECB, CBCMAC, and CMAC modes.
     * For CCM, the IV is replaced with a concatenation of A0 flags, the nonce,
     * and the counter. This is taken care of in DL_AESADV_initCCM. Therefore,
     * the IV field should not be modifiable for CCM as well.
     */
    let nonIVModes = ["DL_AESADV_MODE_ECB", "DL_AESADV_MODE_CBCMAC",
        "DL_AESADV_MODE_CMAC", "DL_AESADV_MODE_CCM"];

    ui.initApplicationIV.hidden = nonIVModes.includes(inst.mode);
    ui.iv.hidden = nonIVModes.includes(inst.mode);

    // /* Reset the IV */
    // inst.iv = (nonIVModes.includes(inst.mode)) ? "" : inst.iv;
}

function updateGUIAADLength(inst, ui)
{
    /* aadLength is only applicable to GCM and CCM */
    let modesUsingAAD = ["DL_AESADV_MODE_CCM",
        "DL_AESADV_MODE_GCM_FORCE_ZERO", "DL_AESADV_MODE_GCM_LOAD_HASH_KEY",
        "DL_AESADV_MODE_GCM_AUTONOMOUS", "DL_AESADV_MODE_GCM_HASH_ONLY"];

    ui.aadLength.hidden = !(modesUsingAAD.includes(inst.mode));

    // /* Reset aadLength */
    // inst.aadLength = (modesUsingAAD.includes(inst.mode)) ? inst.aadLength : 0;
}

function onChangeInterrupts(inst, ui)
{
    updateGUIInterrupts(inst, ui);
    // onChangeCustomProfile(inst,ui);
}

function updateGUIInterrupts(inst, ui)
{
    ui.interruptPriority.hidden = (inst.enabledInterrupts.length === 0);
}

let aesadvConfig  = [
    {
        name: "GROUP_PROFILE",
        displayName: "Quick Profiles",
        description: "",
        collapsed: false,
        config: [
            {
                name        : "profile",
                displayName : "AESADV Profiles",
                description : 'Pre-defined profiles for typical AESADV configurations',
                longDescription: ``,
                hidden      : true, //TODO: keep hidden until profiles are defined
                default     : "TODO: PLACEHOLDER FOR NOW",
            },
        ],
    },
    {
        name: "GROUP_BASIC",
        displayName: "Basic Operation Configuration",
        longDescription: `Basic AESADV options`,
        collapsed: false,
        config: [
            {
                name: "loadApplicationKey",
                displayName: "Load key in application",
                description: "Initialize and set the key in the application code",
                longDescription: `
Key bits can be configured in one of two ways:

1. By configuring the keystore controller to deposit or transfer a key securely
2. By directly writing the key using DL_AESADV_setKey()

When this field is checked, the key must be defined in the application and loaded
into the AES engine with DL_AESADV_setKey()
`,
                default: true,
                readOnly: true, //TODO: will be fixed to true for initial release
            },
            {
                name: "key",
                displayName: "Key",
                description: "Name of primary key used in AES operation",
                hidden: false,
                default: "",
            },
            {
                /* DL_AESADV_setKey */
                name: "keySize",
                displayName: "AES Key Size (bits)",
                description: "The AES key size to be used",
                hidden: false,
                default: "DL_AESADV_KEY_SIZE_128_BIT",
                options: [
                    {name: "DL_AESADV_KEY_SIZE_128_BIT", displayName: "128-bit Key"},
                    {name: "DL_AESADV_KEY_SIZE_256_BIT", displayName: "256-bit Key"},
                ],
            },
            {
                /* DL_AESADV_Config.mode */
                name: "mode",
                displayName: "AES Mode",
                description: "The AES mode",
                hidden: false,
                default: "DL_AESADV_MODE_ECB",
                options: AESADVModeOptions,
                onChange: onChangeMode,
            },
            {
                /* DL_AESADV_Config.direction */
                name: "direction",
                displayName: "AES Direction",
                description: "The direction of the AES engine",
                hidden: false,
                default: "DL_AESADV_DIR_ENCRYPT",
                options: [
                    {name: "DL_AESADV_DIR_ENCRYPT", displayName: "Encryption"},
                    {name: "DL_AESADV_DIR_DECRYPT", displayName: "Decryption"},
                ],
                getDisabledOptions:(inst) => {
                    if(inst.mode == "DL_AESADV_MODE_CBCMAC" || inst.mode == "DL_AESADV_MODE_CMAC")
                    {
                        return [{name: "DL_AESADV_DIR_DECRYPT", displayName: "Decryption", reason: "CBCMAC requires encryption"}];
                    } else {
                        return [];
                    }
                },
            },
            {
                /* DL_AESADV_Config.ctr_ctrWidth */
                name: "ctr_ctrWidth",
                displayName: "Counter mode (CTR) counter width",
                description: "Can be used with combined modes CCM and GCM",
                hidden: true,
                default: "DL_AESADV_CTR_WIDTH_32_BIT",
                options: ctrCounterWidthOptions,
                getDisabledOptions:(inst) => {
                    let disabledOptions = [];
                    let gcmModesUsingCtr = ["DL_AESADV_MODE_GCM_FORCE_ZERO",
                        "DL_AESADV_MODE_GCM_LOAD_HASH_KEY",
                        "DL_AESADV_MODE_GCM_AUTONOMOUS"];

                    if(gcmModesUsingCtr.includes(inst.mode))
                    {
                        disabledOptions.push(ctrCounterWidthOptions[1]);
                        disabledOptions.push(ctrCounterWidthOptions[2]);
                        disabledOptions.push(ctrCounterWidthOptions[3]);

                        return _.map(disabledOptions, o => ({name: o.name, reason: "GCM restricts counter width to 32-bits"}));
                    } else {
                        return [];
                    }
                },
            },
            {
                /* DL_AESADV_Config.cfb_fbWidth */
                name: "cfb_fbWidth",
                displayName: "Cipher Feedback (CFB) feedback width",
                description: "The CFB feedback width",
                hidden: true,
                /* Only one option is supported for now */
                default: "DL_AESADV_FB_WIDTH_128",
                options: [
                    {name: "DL_AESADV_FB_WIDTH_128", displayName: "128-bit Feedback Width"},
                ],
            },
            {
                /* DL_AESADV_Config.ccm_ctrWidth */
                name: "ccm_ctrWidth",
                displayName: "CCM counter field width (bytes)",
                description: "Value stored in CCM-L",
                longDescription: `
The CCM width of the counter length field for CCM operations. This sets the
width of the counter field that is loaded into the initialization vector along
with the nonce. This signal is sometimes referred to as CCM-L.
`,
                hidden: true,
                default: 2,
                range: [2, 8],
                isInteger: true,
            },
            {
                /* DL_AESADV_Config.ccm_tagWidth */
                name: "ccm_tagWidth",
                displayName: "CCM authentication field width (bytes)",
                description: "Value stored in CCM-M",
                longDescription: `
The CCM width of the authentication field for CCM operations. This sets the
width of the authentication field that is retrieved upon completion of the
operation. The first bytes of the calculated tag will be returned, and the
rest of the tag will be ignored. This signal is sometimes referred to as CCM-M.
`,
                hidden: true,
                default: 1,
                range: [1, 8],
                isInteger: true,
            },
            {
                name: "initApplicationIV",
                displayName: "Initialize IV in application",
                description: "Initialize the IV in the application code",
                longDescription: `
When this field is checked, the IV must be defined in the application.
`,
                hidden: true,
                default: true,
                readOnly: true, //TODO: will be fixed to true for initial release
            },
            {
                /* DL_AESADV_Config.iv */
                name: "iv",
                displayName: "Initialization vector",
                description: "Name of initialization vector",
                hidden: true,
                default: "",
            },
            {
                name: "initApplicationNonce",
                displayName: "Initialize nonce in application",
                description: "Initialize the nonce in the application code",
                hidden: true,
                longDescription: `
When this field is checked, the nonce must be defined in the application.
`,
                default: true,
                readOnly: true, //TODO: will be fixed to true for initial release
            },
            {
                /* DL_AESADV_Config.nonce */
                name: "nonce",
                displayName: "Nonce",
                description: "Name of nonce",
                longDescription: `
The nonce is specific to CCM. Refer to the AESADV Driverlib on instructions
for determining the nonce length.
`,
                hidden: true,
                default: "",
            },
            {
                /* DL_AESADV_Config.lowerCryptoLength */
                name: "lowerCryptoLength",
                displayName: "Lower crypto data length (bytes)",
                description: "Cryptographic data length (lower 32-bits)",
                longDescription: `
The cryptographic data length in bytes is stored in 2 32-bit registers. It is a
61-bit value that's expressed as an upper and lower value. This field represents
the lower 32-bits of that value.

Once processing with this context has started, the length decrements to zero.
Data lengths up to (2^61 - 1) bytes are allowed with certain additional restrictions
based on the AES mode. Refer to the AESADV Driverlib for more details on these
additional restrictions.

A write to the crypto length registers triggers the AES engine to start using
the context. This is valid in all modes except combined modes, GCM and CCM.

For combined modes, the crypto length does not include authentication-only
data (AAD), which must be provided separately in aadLength.

All modes, with the exception of combined modes, must have a crypto length value
that's greater than zero. For combined modes, it is allowed to have one of the
lengths (crypto length or AAD length) equal to zero.

For basic modes (ECB, CBC, CTR, ICM, CFB, OFB), crypto length can be programmed
to zero. In that case, the length is assumed to be infinite.

All data must be byte aligned for stream cipher modes. Block cipher modes require
the data length to be programmed in multiples of the block cipher size, 16 bytes.
`,
                hidden: false,
                default: 0,
                displayFormat: "hex",
                range: [0, 0xFFFFFFFF],
                isInteger: true,
            },
            {
                /* DL_AESADV_Config.upperCryptoLength */
                name: "upperCryptoLength",
                displayName: "Upper crypto data length (bytes)",
                description: "Cryptographic data length (upper 29 bits)",
                longDescription: `
The cryptographic data length in bytes is stored in 2 32-bit registers. It is a
61-bit value that's expressed as an upper and lower value. This field represents
the upper 29-bits of that value.

Once processing with this context has started, the length decrements to zero.
Data lengths up to (2^61 - 1) bytes are allowed with certain additional restrictions
based on the AES mode. Refer to the AESADV Driverlib for more details on these
additional restrictions.

A write to the crypto length registers triggers the AES engine to start using
the context. This is valid in all modes except combined modes, GCM and CCM.

For combined modes, the crypto length does not include authentication-only
data (AAD), which must be provided separately in aadLength.

All modes, with the exception of combined modes, must have a crypto length value
that's greater than zero. For combined modes, it is allowed to have one of the
lengths (crypto length or AAD length) equal to zero.

For basic modes (ECB, CBC, CTR, ICM, CFB, OFB), crypto length can be programmed
to zero. In that case, the length is assumed to be infinite.

All data must be byte aligned for stream cipher modes. Block cipher modes require
the data length to be programmed in multiples of the block cipher size, 16 bytes.
`,
                hidden: false,
                default: 0,
                displayFormat: "hex",
                range: [0, 0x1FFFFFFF],
                isInteger: true,
            },
            {
                /* DL_AESADV_Config.aadLength */
                name: "aadLength",
                displayName: "Additional authentication data (AAD) length (bytes)",
                description: "AAD. CCM/GCM specific",
                longDescription: `
Specific to combined modes, CCM and GCM only. This value can be zero if there's
no AAD, or it can be nonzero with a zero crypto length for authentication-only
operations. For GCM, this can be any value < 2^32. For CCM, this value must be
less than or equal to (2^16 - 2^8 bytes).
`,
                hidden: true,
                default: 0,
                displayFormat: "hex",
                range: [0, 0xFFFFFFFF],
                isInteger: true,
            },
        ]
    },
];

//TODO: Placeholders for now. Evaluate if every group should be supported
//or configurable. Some groups can be submodules (DMA or keystore?)
// aesadvConfig = aesadvConfig.concat(getAdvancedGroupConfig());
// aesadvConfig = aesadvConfig.concat(getDMAGroupConfig());
aesadvConfig = aesadvConfig.concat(getInterruptGroupConfig());
// aesadvConfig = aesadvConfig.concat(getKeystoreGroupConfig());
// aesadvConfig = aesadvConfig.concat(getRetentionGroupConfig());

function getAdvancedGroupConfig()
{
    //TODO: determine what advanced config options should be supported
    return [
        {
            name: "GROUP_ADVANCED",
            displayName: "Advanced Operation Configuration",
            longDescription: `Advanced AESADV options`,
            collapsed: false,
            config: [
                {
                    name: "testAdvParam",
                    displayName: "AESADV Test parameter",
                    description: "",
                    hidden: false,
                    default: false,
                },
            ]
        },
    ];
}

function getDMAGroupConfig()
{
    //TODO: placeholder. Maybe a subgroup instead
    return [
        {
            name: "GROUP_DMA",
            displayName: "DMA Configuration (TODO: maybe submodule instead?)",
            description: "",
            longDescription: "",
            collapsed: true,
            config: [
                {
                    name: "testDMAParam",
                    displayName: "AESADV Test parameter",
                    description: "",
                    hidden: false,
                    default: false,
                },
            ]
        },
    ];
}

function getInterruptGroupConfig()
{
    return [
        {
            name: "GROUP_INTERRUPTS",
            displayName: "Interrupt Configuration",
            description: "",
            longDescription: "This section allows enabling/disabling AESADV interrupts",
            collapsed: true,
            config: [
                {
                    /* DL_AESADV_enableInterrupt */
                    name: "enabledInterrupts",
                    displayName: "Enable Interrupts",
                    description: "Enable Interrupts",
                    hidden: false,
                    default: [],
                    options: getInterruptOptions,
                    onChange: onChangeInterrupts,
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
    ];
}

function getKeystoreGroupConfig()
{
    //TODO: placeholder. Maybe a subgroup instead
    return [
        {
            name: "GROUP_KEYSTORE",
            displayName: "Keystore Configuration (TODO: maybe submodule instead?)",
            description: "",
            longDescription: "",
            collapsed: true,
            config: [
                {
                    name: "testKeystoreParam",
                    displayName: "AESADV Test parameter",
                    description: "",
                    hidden: false,
                    default: false,
                },
            ]
        },
    ];
}

function getRetentionGroupConfig()
{
    //TODO: use items in common?
    return [
        {
            name: "GROUP_RETENTION",
            displayName: "Retention Configuration (TODO: do we need?)",
            description: "",
            longDescription: "",
            collapsed: true,
            config: [
                {
                    name: "testRetentionParam",
                    displayName: "AESADV Test parameter",
                    description: "",
                    hidden: false,
                    default: false,
                },
            ]
        },
    ];
}


function moduleInstances(inst){
    let modInstances = []
    return modInstances;
}

/*
 *  ======== devSpecific ========
 *  Device-specific extensions to be added to base module configuration
 */
let devSpecific = {

    config: aesadvConfig,

    /* override generic requirements with  device-specific reqs (if any) */
    validate: validate,

    validatePinmux: validatePinmux,

    pinmuxRequirements: pinmuxRequirements,

    filterHardware: filterHardware,

    moduleInstances: moduleInstances,

    modules: setRequiredModules,

    _getPinResources: _getPinResources
};

function setRequiredModules(inst){
    let theModules = ["Board", "SYSCTL"]

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

    return modArray
};

/*
 *  ======== extend ========
 *  Extends a base exports object to include any device specifics
 *
 *  This function is invoked by the generic module module to
 *  allow us to augment/override as needed for the MSP432.
 */
function extend(base)
{
    /* Special static extend */
    /* merge and overwrite base module attributes */
    let result = Object.assign({}, base.moduleStatic, devSpecific);

    /* concatenate device-specific configs */
    /* moduleStatic specific to AESADV as it's statically defined */
    result.config = base.moduleStatic.config.concat(devSpecific.config);
    base.moduleStatic = result;

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
