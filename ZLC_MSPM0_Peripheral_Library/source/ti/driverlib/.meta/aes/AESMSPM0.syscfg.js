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
 *  ======== AESMSPM0.syscfg.js ========
 */

"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");


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

    return (pin);


}

/*
 *  ======== validatePinmux ========
 *  Validation run after solution
 *
 *  param inst       - module instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validatePinmux(inst, validation) {
    /* Retention Validation */
    Common.getRetentionValidation(inst,validation);
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
    /* AES has no pinmux requirements */
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

/************************* Profiles functions *******************************/
const profilesAES = [
    {
        name: "aes128Enc",
        keyLength: "DL_AES_KEY_LENGTH_128",
        operationType: "ENCRYPT",
    },
    {
        name: "aes256Enc",
        keyLength: "DL_AES_KEY_LENGTH_256",
        operationType: "ENCRYPT",
    },
    {
        name: "aes128Dec",
        keyLength: "DL_AES_KEY_LENGTH_128",
        operationType: "DECRYPT_SAME_KEY",
    },
    {
        name: "aes256Dec",
        keyLength: "DL_AES_KEY_LENGTH_256",
        operationType: "DECRYPT_SAME_KEY",
    },
    {
        name: "aes128GenKey",
        keyLength: "DL_AES_KEY_LENGTH_128",
        operationType: "GEN_FIRST_ROUND_KEY",
    },
    {
        name: "aes256GenKey",
        keyLength: "DL_AES_KEY_LENGTH_256",
        operationType: "GEN_FIRST_ROUND_KEY",
    },
    {
        name: "aes128UsePregenKey",
        keyLength: "DL_AES_KEY_LENGTH_128",
        operationType: "DECRYPT_KEY_IS_FIRST_ROUND_KEY",
    },
    {
        name: "aes256UsePregenKey",
        keyLength: "DL_AES_KEY_LENGTH_256",
        operationType: "DECRYPT_KEY_IS_FIRST_ROUND_KEY",
    },
];

function onChangeSetCustomProfile(inst, ui)
{
    inst.profile = "CUSTOM";
}

function onChangeAESProfile(inst, ui)
{
    if (inst.profile != "CUSTOM")
    {
        let selectedProfileArray = profilesAES.filter(obj =>
                                        {return obj.name === inst.profile});
        if (selectedProfileArray.length != 0)
        {
            const selectedProfile = Object.assign({}, selectedProfileArray[0]);
            delete selectedProfile.name;
            Object.assign(inst, selectedProfile)
        }
    }
}

/* onChange functions for Basic Configuration */
function onChangeCfgKeyLength(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

function onChangeCfgOperationType(inst, ui)
{
    onChangeSetCustomProfile(inst, ui);
}

let config = [
    {
        name: "GROUP_PROFILE",
        displayName: "Quick Profiles",
        description: "",
        collapsed: false,
        config: [
            {
                name: "profile",
                displayName: "AES Profiles",
                description: "Pre-defined profiles for typical AES configurations",
                longDescription: `
The AES accelerator module for the MSPM0Gxx family performs encryption and
decryption of 128-bit data blocks with a 128-bit or 256-bit key in hardware
according to the advanced encryption standard (AES). AES is a symmetric-key
block cipher algorithm specified in FIPS PUB 197.

![AES Block Diagram](../docs/english/sysconfig/images/aesBlockDiagM0Gxxx.PNG "AES Block Diagram")

The Quick Profile Options are:
* **AES128/256 Encryption**:
    * Key Length: 128-bits (or 256-bits)
    * Operation: Encryption
* **AES128/256 Decryption**:
    * Key Length: 128-bits (or 256-bits)
    * Operation: Decryption using the same key used for encryption
* **AES128/256 Encryption Key Schedule**:
    * Key Length: 128-bits (or 256-bits)
    * Operation: Generation of the first round key used for decryption
* **AES128/256 Decryption with first round key**:
    * Key Length: 128-bits (or 256-bits)
    * Operation: Decryption using a pregenerated key that is the first round key
* **Custom**:
    * Allows custom configuration

![AES Profiles](../docs/english/sysconfig/images/aesProfiles.PNG "AES Profiles")
`,
                hidden: false,
                default: "CUSTOM",
                options: [
                    {name: "aes128Enc", displayName: "AES128 Encryption"},
                    {name: "aes256Enc", displayName: "AES256 Encryption"},
                    {name: "aes128Dec", displayName: "AES128 Decryption"},
                    {name: "aes256Dec", displayName: "AES256 Decryption"},
                    {name: "aes128GenKey", displayName: "AES128 Encryption Key Schedule (to generate first round key for decryption)"},
                    {name: "aes256GenKey", displayName: "AES256 Encryption Key Schedule (to generate first round key for decryption)"},
                    {name: "aes128UsePregenKey", displayName: "AES128 Decryption with first round key"},
                    {name: "aes256UsePregenKey", displayName: "AES256 Decryption with first round key"},
                    {name: "CUSTOM", displayName: "Custom"},
                ],
                onChange: onChangeAESProfile,
            },
        ],
    },
]

config  = config.concat([
    {
        name: "GROUP_BASIC",
        displayName: "Basic Operation Configuration",
        longDescription: `Basic AES options that allow configuration of the key
                          length, AES operation, and AES mode.`,
        collapsed: false,
        config: [
            /* Part of DL_AES_init */
            {
                name: "keyLength",
                displayName: "AES Key Length (bits)",
                description: "The AES key length to be used",
                hidden: false,
                default: "DL_AES_KEY_LENGTH_128",
                options: [
                    {name: "DL_AES_KEY_LENGTH_128", displayName: "128-bit Key"},
                    {name: "DL_AES_KEY_LENGTH_256", displayName: "256-bit Key"},
                ],
                onChange: onChangeCfgKeyLength,
            },
            /*
             * DL_AES_init. operationType will be concatenated with aesMode
             * to form the values of the DL_AES_MODE enum in dl_aes.h
             */
            {
                name: "operationType",
                displayName: "AES Operation",
                description: "The AES operation to perform",
                longDescription: `
The supported AES operations are:
- Encryption
- Decryption using the same key that was used for encryption. The original cipher
  key used for encryption is loaded into AESAKEY.
- Generation of the first round key required for decryption
- Decryption using a provided key that is the first round key required for decryption`,
                hidden: false,
                default: "ENCRYPT",
                options: [
                    {name: "ENCRYPT", displayName: "Encryption"},
                    {name: "DECRYPT_SAME_KEY", displayName: "Decryption"},
                    {name: "GEN_FIRST_ROUND_KEY", displayName: "Generate First Round Key Required for Decryption"},
                    {name: "DECRYPT_KEY_IS_FIRST_ROUND_KEY", displayName: "Decryption with Pregenerated First Round Key"},
                ],
                onChange: onChangeCfgOperationType,
            },
            /*
             * DL_AES_init. blockCipherMode will be concatenated with
             * operationType to form the values of the DL_AES_MODE enum in
             * dl_aes.h
             */
            {
                name: "blockCipherMode",
                displayName: "Block Cipher Mode",
                description: "The block cipher mode to use",
                longDescription: `
The block cipher modes that use AES as the underlying block cipher are:
- Electronic Codebook (ECB) Mode
    - Simplest block cipher mode where plaintext data is divided into 128-bit
      blocks, and each block is encrypted/decrypted independently from one another.
    - Note, the same 128-bit block is always encrypted into the same ciphertext
      block, allowing patterns in the ciphertext to be detected.

![ECB Block Diagram](../docs/english/sysconfig/images/ecbBlockDiag.png "ECB Block Diagram")

- Cipher Block Chaining (CBC) Mode
    - Similar to ECB, but the ciphertext output for each block is dependent
      on the previous ciphertext block.\n
      The plaintext data is divided into 128-bit blocks, and each plaintext
      block is XORed with the previous ciphertext block to create the input to the AES block cipher.
    - An unpredictable initialization vector (IV) must be provided, and it's
      XORed with the 1st plaintext block.

![CBC Block Diagram](../docs/english/sysconfig/images/cbcBlockDiag.png "CBC Block Diagram")

- Output Feedback (OFB) Mode
    - An IV is repeatedly encrypted with the cipher key, creating a keystream.
      The output ciphertext is obtained by XORing plaintext with the encrypted
      and re-encrypted versions of the IV.
    - The IV must be a nonce (number used once), and each IV must be used only
      once with a given key to prevent loss of confidentiality.

![OFB Block Diagram](../docs/english/sysconfig/images/ofbBlockDiag.png "OFB Block Diagram")

- Cipher Feedback (CFB) Mode
    - Similar to OFB, but the input block to the block cipher used to generated
      the keystream is taken from the previous ciphertext block\n
      (after being XORed with the plaintext), making the keystream dependent upon the plaintext.
    - An IV is required and must be unpredictable.

![CFB Block Diagram](../docs/english/sysconfig/images/cfbBlockDiag.png "CFB Block Diagram")
`,
                hidden: false,
                default: "ECB_MODE",
                options: [
                    {name: "ECB_MODE", displayName: "Electronic Code Book (ECB)"},
                    {name: "CBC_MODE", displayName: "Cipher Block Chaining (CBC)"},
                    {name: "OFB_MODE", displayName: "Output Feedback (OFB)"},
                    {name: "CFB_MODE", displayName: "Cipher Feedback (CFB)"},
                ]
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
            {
                name        : "aesConfigureDMA0",
                displayName : "Configure DMA Trigger 0",
                hidden      : false,
                default     : false,
                onChange    : (inst,ui) => {
                    ui.aesDMATrigger0.hidden = !(inst.aesConfigureDMA0);
                }
            },
            {
                name        : "aesDMATrigger0",
                displayName : "Enable DMA Trigger 0",
                description : 'The bit to enable a DMA trigger source to use the DMA instead of the CPU to input data.',
                hidden      : true,
                default     : true,

            },
            {
                name        : "aesConfigureDMA1",
                displayName : "Configure DMA Trigger 1",
                hidden      : false,
                default     : false,
                onChange    : (inst,ui) => {
                    ui.aesDMATrigger1.hidden = !(inst.aesConfigureDMA1);
                }
            },
            {
                name        : "aesDMATrigger1",
                displayName : "Enable DMA Trigger 1",
                description : 'The bit to enable a DMA trigger source to use the DMA instead of the CPU to input data.',
                hidden      : true,
                default     : true,

            },
            {
                name        : "aesConfigureDMA2",
                displayName : "Configure DMA Trigger 2",
                hidden      : false,
                default     : false,
                onChange    : (inst,ui) => {
                    ui.aesDMATrigger2.hidden = !(inst.aesConfigureDMA2);
                }
            },
            {
                name        : "aesDMATrigger2",
                displayName : "Enable DMA Trigger 2",
                description : 'The bit to enable a DMA trigger source to use the DMA instead of the CPU to input data.',
                hidden      : true,
                default     : true,

            },

        ]
    },
    /* Retention configurable */
    {
        name: "GROUP_RETENTION",
        displayName: "Retention Configuration",
        description: "",
        longDescription: ``,
        collapsed: false,
        config: Common.getRetentionConfig(),
    },
])

config = config.concat([
    {
        name: "GROUP_INTERRUPTS",
        displayName: "Interrupt Configuration",
        collapsed: true,
        config: [
            /* DL_AES_enableInterrupt */
            {
                name        : "enableInterrupt",
                displayName : "Enable AES Ready Interrupt",
                description : `The AES Ready interrupt indicates that the AES
                               module has completed the operation, and results
                               can be ready from AESADOUT (if applicable).`,
                default     : false,
                onChange    : (inst, ui) => {
                    ui.interruptPriority.hidden = !inst.enableInterrupt;
                }
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
])

/*
 * Gets a DMA module if available
 */
function moduleInstances(inst){
    let modInstances = []
    if(inst.aesConfigureDMA0){
        let mod = {
            name: "DMA_CHANNEL_0",
            displayName: "DMA Channel 0",
            moduleName: '/ti/driverlib/DMAChannel',
            group: "GROUP_DMA",
            args: {
                //triggerSelect: inst.dmaPassedSolution
            },
            requiredArgs: {
                hideTriggerSelect: true,
                passedTriggerSelect: 0,
                /* empty for now */
            },

        }
        modInstances.push(mod);
    }
    if(inst.aesConfigureDMA1){
        let mod = {
            name: "DMA_CHANNEL_1",
            displayName: "DMA Channel 1",
            moduleName: '/ti/driverlib/DMAChannel',
            group: "GROUP_DMA",
            args: {
                //triggerSelect: inst.dmaPassedSolution
            },
            requiredArgs: {
                hideTriggerSelect: true,
                passedTriggerSelect: 1,
                /* empty for now */
            },

        }
        modInstances.push(mod);
    }
    if(inst.aesConfigureDMA2){
        let mod = {
            name: "DMA_CHANNEL_2",
            displayName: "DMA Channel 2",
            moduleName: '/ti/driverlib/DMAChannel',
            group: "GROUP_DMA",
            args: {
                //triggerSelect: inst.dmaPassedSolution
            },
            requiredArgs: {
                hideTriggerSelect: true,
                passedTriggerSelect: 2,
                /* empty for now */
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

    config: config,

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
    if(inst.aesConfigureDMA0 || inst.aesConfigureDMA1 || inst.aesConfigureDMA2){
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
    /* moduleStatic specific to AES as it's statically defined */
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
