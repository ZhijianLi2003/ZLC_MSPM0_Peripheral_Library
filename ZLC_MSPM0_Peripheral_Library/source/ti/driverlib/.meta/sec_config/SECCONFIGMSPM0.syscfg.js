/*
 * Copyright (c) 2024 Texas Instruments Incorporated - http://www.ti.com
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
 *  ======== SECCONFIGMSPM0.js ========
 */

"use strict";

/* get Common /ti/driverlib utility functions */
let Common = system.getScript("/ti/driverlib/Common.js");

/*
 *  ======== validate ========
 *  Validate this inst's configuration
 *
 *  param inst       - module instance to be validated
 *  param validation - object to hold detected validation issues
 */
function validate(inst, validation)
{
    if (!inst.unprivVerifyOptions.includes("writeExecuteOnly"))
    {
        validation.logInfo(
            "Write-execute exclusion is enabled by default in other verification methods",
            inst, "unprivVerifyOptions");
    }

    if (inst.cscSecretAddress && inst.cscSecretSize && !inst.cscLockStorageSize)
    {
        validation.logError("CSC secret storage is configured. Please specify lockable storage size",
        inst, "cscLockStorageSize");
    }

    /*
     * Sector/bank sizes of items stored in flash should be a multiple of a
     * flash sector size (0x400 or 1024 bytes).
     *
     * Addresses should also be aligned on a flash sector size
     */
    if ((inst.cscBankSize % 0x400) != 0)
    {
        validation.logError("CSC bank size should be a multiple of a flash sector size (1024 bytes)",
        inst, "cscBankSize");
    }

    if ((inst.cscSecretAddress % 0x400) != 0)
    {
        validation.logError("CSC secret address should be aligned on a multiple of a flash sector size (1024 bytes)",
        inst, "cscSecretAddress");
    }

    if ((inst.cscSecretSize % 0x400) != 0)
    {
        validation.logError("CSC secret size should be a multiple of a flash sector size (1024 bytes)",
        inst, "cscSecretSize");
    }

    if ((inst.cscLockStorageSize % 0x400) != 0)
    {
        validation.logError("CSC lock storage size should be a multiple of a flash sector size (1024 bytes)",
        inst, "cscLockStorageSize");
    }

    if ((inst.cscAppImageBaseAddr % 0x400) != 0)
    {
        validation.logError("CSC application base address should be aligned on a multiple of a flash sector size (1024 bytes)",
        inst, "cscAppImageBaseAddr");
    }

    if ((inst.cscAppImageSize % 0x400) != 0)
    {
        validation.logError("CSC application image size should be a multiple of a flash sector size (1024 bytes)",
        inst, "cscAppImageSize");
    }

    /* Customer must acknowledge prereqs for using CSC code examples */
    if (!inst.cscPrereqAck)
    {
        validation.logError("Please acknowledge TI recommended prerequisites for using CSC. See field description for more details",
        inst, "cscPrereqAck");
    }
}

function getQuickProfilesConfig()
{
    /* Careful with how future devices might impact profiles */
    let quickProfilesConfig = [
        {
            name: "profiles",
            displayName: "Security Configurator Profiles",
            description: "",
            longDescription: `
Pre-defined profiles for Security Configurator
`,
            hidden: false,
            default: "custom",
            options: [
                {name: "custom", displayName: "Custom"},
            ],
        }
    ];

    return quickProfilesConfig;
}

function getVerificationConfig()
{
    let verificationConfig = [
        {
            name: "privVerifyOptions",
            displayName: "Boot Time (Privileged) Verification Options",
            description: "Select verification method used when CSC is executing in privileged mode",
            longDescription: `
Select between Asymmetric ECDSA (with option to enable CMAC acceleration) and
Symmetric verification using AES-CMAC with shared key.

See the TI App Note [Cybersecurity Enablers for MSPM0 MCUs](https://www.ti.com/lit/slaae29)
and the generated header file for more details.
`,
            default: "asymmetric",
            options: [
                {name: "asymmetric", displayName: "Asymmetric Encryption (ECDSA)"},
                {name: "symmetric", displayName: "Symmetric Encryption"},
            ],
            onChange: onChangePrivVerifyOptions,
        },
        {
            name: "enableCMACAcceleration",
            displayName: "Enable CMAC Acceleration",
            description: "",
            longDescription: `
Used exclusively by the CSC during privileged mode on power up. If an image has
been previously verified using ECDSA, the CMAC key and tag can be computed and
stored in a read-protected region of flash. During power up, if the image has
not been updated (and is the same version), the tag can be re-computed for the
image using the key and ECDSA can be bypassed.

This greatly speeds up power-on-resets/BOOTRSTs where updates are not being
performed without compromising a thorough, 128-bit secure verification
(as key and tag are not exposed).

This also is separate from a standard symmetric encryption as the CMAC key is
unique per device, thus the leaking of a CMAC key does not represent a breach
in security to all devices, or that a user can begin signing arbitrary images
that will run in all devices.
`,
            default: true,
            hidden: false,
        },
        {
            name: "enableSymmEncOnlyNoECDSA",
            displayName: "Enable Symmetric Encryption Only (Remove ECDSA Support)",
            description: "",
            longDescription: `
This option will remove additional ECDSA cryptographic primitives if selected.
Requires Symmetric Encryption option to be selected.
`,
            default: true,
            hidden: true,
        },
        {
            name: "unprivVerifyOptions",
            displayName: "Unprivileged Verification Options",
            description: "Select verification method used when CSC is executing in unprivileged mode",
            longDescription: `
Select additional extension of trust options on the previously verified
application image during the unprivileged state. The purpose is to make sure
that the application is unchanged since verification in privileged CSC.

Option 1: Enforce bank write-protection such that the executing bank is
non-writeable, and trust that application remains unchanged from previous
verification. This option is the default and is part of Options 2 and 3.

Option 2: Re-compute hash of image and compare to verified hash in locked flash
(using write-protect firewalls). This is Option 1 and an additional integrity
check using SHA-256 SW hash.

Option 3: Re-perform asymmetric verification using SHA-256 and ECDSA. This is
Option 1 and full ECDSA.

See generated header file for more details.
`,
            default: ["writeExecuteOnly"],
            minSelections: 1,
            options: [
                {name: "writeExecuteOnly", displayName: "Extend execution with write-execute exclusion property"},
                {name: "addHashVerify", displayName: "Add SHA-256 SW Hash Verification"},
                {name: "addECDSAVerify", displayName: "Add Full ECDSA Verification"},
            ],
        },
        {
            name: "enableRollbackProtection",
            displayName: "Enable Rollback Protection",
            description: "",
            longDescription: ``,
            default: true,
            hidden: false,
        },
    ];

    return verificationConfig;
}

function onChangePrivVerifyOptions(inst, ui)
{
    if (inst.privVerifyOptions == "asymmetric")
    {
        ui.enableCMACAcceleration.hidden = false;
        ui.enableSymmEncOnlyNoECDSA.hidden = true;
    }
    else
    {
        ui.enableCMACAcceleration.hidden = true;
        ui.enableSymmEncOnlyNoECDSA.hidden = false;
    }
}

function getKeyConfig()
{
    let keyConfig = [
        {
            name: "enableStaticSharedSecretKey",
            displayName: "Enable Static Shared Secret Key",
            description: "",
            longDescription: `
This option adds a 256-bit shared secret exclusively used in the privileged
mode of execution. This shared secret may be used in order to decrypt incoming
keys/messages, or to use symmetric authentication of incoming messages.
`,
            default: true,
            hidden: false,
            onChange: (inst, ui) => {
                ui.enableStaticSharedSecretKeyInternal.hidden = !(inst.enableStaticSharedSecretKey);
            },
        },
        {
            name: "enableStaticSharedSecretKeyInternal",
            displayName: "Enable Static Shared Secret Key (Internal)",
            description: "",
            longDescription: `
Stores the secret inside the program at compile time, rather than provisioned
separately.
`,
            default: true,
            hidden: false,
        },
        {
            name: "enableKeystore",
            displayName: "Enable Keystore",
            description: "",
            longDescription: `
Enables the CSC to write keys into the keystore - an IP that allows the
privileged mode of execution to utilize but not read certain keys used by the
AES engine. The keystore is configured every boot routine (as it is in volatile
memory), so keys used are stored persistently in the secret memory.

Note: Keys used exclusively during the privileged execution should not be
placed in the keystore.

Note: If the application does not use the AES specifically, it is not necessary
to enable this option.

Must be enabled if the application is attempting to read from the keystore.
`,
            default: true,
            hidden: false,
            onChange: (inst, ui) => {
                ui.keystoreProvisionMethods.hidden = !(inst.enableKeystore);
            },
        },
        {
            name: "keystoreProvisionMethods",
            displayName: "Select Keystore Provision Methods",
            description: "Select keystore provision methods",
            longDescription: `
Select whether to provision keystore keys at compile (or static) time, at
run (or dynamic) time, or both.

See generated header file for more details.
`,
            default: ["compileTime"],
            minSelections: 1,
            hidden: false,
            options: [
                {name: "compileTime", displayName: "Provide keys at compile-time"},
                {name: "runTime", displayName: "Provide keys at run-time"},
            ],
        },
    ];

    return keyConfig;
}

function getMiscConfig()
{
    let miscConfig = [
        {
            name: "developmentOptions",
            displayName: "Ease-of-development Options",
            description: "Select options for ease-of-development",
            longDescription: `
Select options to make development and testing easier. See generated header
file for more details.
`,
            default: [],
            minSelections: 0,
            options: [
                {name: "enablePseudoRandom", displayName: "Enable Pseudo Random CMAC Key Generation"},
                {name: "enableDevErrorCodes", displayName: "Generate Dev Error Codes"},
            ],
        },
        {
            name: "enableIPProtection",
            displayName: "Enable IP Protection",
            description: "",
            longDescription: `
The customer will provide an IP Protection range in the header, such that the
CSC can enable the IP Protect firewall over a region of memory. The IP Protect
firewall will prevent reading of that segment of memory but will still allow
the device to execute the code.
`,
            default: true,
            hidden: false,
        },
        {
            name: "exposeSecurityPrimitives",
            displayName: "Expose Security Primitives",
            description: "Provide security primitives to application",
            longDescription: `
The CSC will provide external symbols such that the application can perform
hashing and ECDSA by way of a function table in the output.
`,
            default: true,
            hidden: false,
        },
    ];

    return miscConfig;
}

function getMemoryMapConfig()
{
    let memoryMapConfig = [
        {
            name: "cscBankSize",
            displayName: "CSC Bank Size (Bytes)",
            description: "Set the CSC Bank Size",
            longDescription: ``,
            default: 0,
            range: [0, 0xFFFFFFFF],
            isInteger: true,
        },
        {
            name: "cscSecretAddress",
            displayName: "CSC Secret Address",
            description: "Set the CSC Secret Address",
            longDescription: `
The SECRET (optional) is visible to the privileged execution flow but will be
protected by a Read Protect Firewall. This renders it invisible to any aspect
of the unprivileged flow (CSC and Application).

The secret can be used to store non-volatile keys that should be loaded into
keystore at runtime. Thus, the unprivileged code will be able to use these
keys, but not have read access.

It can also be customized by the user to include additional information.

Note: It is possible for the SECRET to reside inside the application image.
This could be useful if the keys to be loaded into the keystore should be
updatable by the application, and need to be authenticated. However, there will
need to be additional handshaking such that the CSC can locate the section and
read-protect it accordingly.
`,
            default: 0,
            range: [0, 0xFFFFFFFF],
            displayFormat: "hex",
            isInteger: true,
        },
        {
            name: "cscSecretSize",
            displayName: "CSC Secret Size (Bytes)",
            description: "Set the CSC Secret Size",
            longDescription: ``,
            default: 0,
            range: [0, 0xFFFFFFFF],
            isInteger: true,
        },
        {
            name: "cscLockStorageSize",
            displayName: "CSC Lock Storage Size (Bytes)",
            description: "Set the CSC Lock Storage Size",
            longDescription: ``,
            default: 0,
            range: [0, 0xFFFFFFFF],
            isInteger: true,
        },
        {
            name: "cscAppImageBaseAddr",
            displayName: "CSC Application Image Base Address",
            description: "Set the CSC Application Image Base Address",
            longDescription: ``,
            default: 0,
            range: [0, 0xFFFFFFFF],
            displayFormat: "hex",
            isInteger: true,
        },
        {
            name: "cscAppImageSize",
            displayName: "CSC Application Image Size (Bytes)",
            description: "Set the CSC Application Image Size",
            longDescription: ``,
            default: 0,
            range: [0, 0xFFFFFFFF],
            isInteger: true,
        },
    ];

    return memoryMapConfig;
}

let securityConfiguratorConfig = [
    {
        name: "GROUP_PREREQS",
        displayName: "CSC Prerequisites",
        collapsed: false,
        config: [
            {
                name        : "cscPrereqAck",
                displayName : "Acknowledge Prerequisites",
                description : "",
                longDescription: `
TI recommends the following for proper Customer Secure Code (CSC) usage:

1. This module is intended to be used with the customer_secure example suite
and enabled on the customer_secure_code example only. These examples are
located in the SDK and are available in the [TI Developer Zone](https://dev.ti.com/tirex/explore/node?node=A__AGhCTCesBW-3MfCYmsOU8Q__MSPM0-SDK__a3PaaoK__LATEST).

2. This module is intended to be used in combination with the
Configuration NVM (NONMAIN) module, which is used to configure the behavior of
the MSPM0 boot process. Please refer to the [Boot Image Manager User's Guide](https://dev.ti.com/tirex/explore/node?node=A__ALc36uNDN3PMrPxR8L5bsw__MSPM0-SDK__a3PaaoK__LATEST)
and the Boot Configuration and Security chapters of the device TRM for more details
on using Configuration NVM (NONMAIN) and CSC.
`,
                hidden      : false,
                default     : false,
            },
        ]
    },
    {
        name: "GROUP_PROFILES",
        displayName: "Quick Profiles",
        collapsed: false,
        config: getQuickProfilesConfig(),
    },
    {
        name: "GROUP_VERIFICATION",
        displayName: "Verification Mechanisms",
        collapsed: false,
        config: getVerificationConfig(),
    },
    {
        name: "GROUP_KEY_CONFIGURATION",
        displayName: "Key Configuration",
        collapsed: false,
        config: getKeyConfig(),
    },
    {
        name: "GROUP_MISC",
        displayName: "Miscellaneous",
        collapsed: false,
        config: getMiscConfig(),
    },
    {
        name: "GROUP_MEMORY_MAPS",
        displayName: "Memory Maps",
        collapsed: false,
        config: getMemoryMapConfig(),
    },
];

/*
 *  ======== devSpecific ========
 *  Device-specific extensions to be added to base module configuration
 */
let devSpecific = {

    config: securityConfiguratorConfig,

    validate: validate,
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
    /* merge and overwrite base module attributes */
    let result = Object.assign({}, base.moduleStatic, devSpecific);

    /* concatenate device-specific configs */
    // moduleStatic specific to SECCONFIG as it's statically defined
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
