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
 *  ======== Common.js ========
 */

const InterruptPriorityOptions = [
    { name: "DEFAULT", displayName: "Default", description: "Default interrupt priority" },
    { name: "0", displayName: "Level 0 - Highest", description: "Priority Level: Highest" },
    { name: "1", displayName: "Level 1 - High", description: "Priority Level: High" },
    { name: "2", displayName: "Level 2 - Low", description: "Priority Level: Low" },
    { name: "3", displayName: "Level 3 - Lowest", description: "Priority Level: Lowest" },
];

exports = {
    boardName: boardName,  /* get /ti/boards name */

    device2Family: device2Family,  /* get /ti/drivers device family name */

    getCompName: getCompName,      /* get fully qualified component name */
    getConfigs: getConfigs,        /* get all of a module's config params */

    getName: getName,              /* get C name for instance */
    getPort: getPort,              /* get pin port name: Px_y */
    getInstanceIndex: getInstanceIndex, /* returns mod.$instances array index of inst */
    isCName: isCName,              /* validate name is C identifier */
    genAliases: genAliases,        /* generate list of instance name aliases */
    pinToName: pinToName,          /* convert pin number to pin name */
    intPriority2Hex: intPriority2Hex, /* translate logical priority into a
                                       * valid hex value
                                       */
    swiPriority2Int: swiPriority2Int,
    logError: logError,           /* push error onto into validation obj */
    logWarning: logWarning,       /* push warning onto into validation obj */
    logInfo: logInfo,             /* push remark onto into validation obj */

    newConfig: newConfig,         /* create /ti/drivers config structure */

    newIntPri: newIntPri,         /* create a common 'intPriority' config */

    newSwiPri: newSwiPri,         /* create a common 'swiPriority' config */

    print: print,                 /* debug: print specified object */
    printModule: printModule,     /* debug: print module configs and methods */
    printPins: printPins,         /* debug: print pinmux solution */

    useModule: useModule,

    typeMatches: typeMatches,
    setDefaults: setDefaults,

    validateNames: validateNames, /* validate inst names are unique C names */

    addNameConfig: addNameConfig, /* add driver-specific $name config */

    autoForceModules: autoForceModules,
    autoForceDriversModules: autoForceDriversModules,
    genBoardHeader: genBoardHeader,
    genResourceComment: genResourceComment,
    findSignalTypes : findSignalTypes,


    findDuplicates : findDuplicates,
    stringOrEmpty: stringOrEmpty,
    getUnitPrefix: getUnitPrefix,
    parseFloatUnitInput: parseFloatUnitInput,

    peripheralCount: peripheralCount,
    getDeviceName: getDeviceName,

    isDeviceM0G                             : isDeviceM0G,
    isDeviceM0L                             : isDeviceM0L,
    isDeviceM0C                             : isDeviceM0C,
    isDeviceM0x110x                         : isDeviceM0x110x,
    isDeviceM0x310x                         : isDeviceM0x310x,
    isDeviceFamily_PARENT_MSPM0L11XX_L13XX  : isDeviceFamily_PARENT_MSPM0L11XX_L13XX,
    isDeviceFamily_PARENT_MSPM0G1X0X_G3X0X  : isDeviceFamily_PARENT_MSPM0G1X0X_G3X0X,
    isDeviceFamily_PARENT_MSPM0GX51X        : isDeviceFamily_PARENT_MSPM0GX51X,
    isDeviceFamily_PARENT_MSPM0L122X_L222X  : isDeviceFamily_PARENT_MSPM0L122X_L222X,
    isDeviceFamily_PARENT_MSPM0L122X        : isDeviceFamily_PARENT_MSPM0L122X,
    isDeviceFamily_PARENT_MSPM0L222X        : isDeviceFamily_PARENT_MSPM0L222X,
    isDeviceFamily_PARENT_MSPM0C110X        : isDeviceFamily_PARENT_MSPM0C110X,
    isDeviceFamily_MSPS003FX                : isDeviceFamily_MSPS003FX,

    I2CTargetWakeupWorkaroundFixed          : I2CTargetWakeupWorkaroundFixed,

    getDeviceFamily                         : getDeviceFamily,

    hasTimerA                               : hasTimerA,
    hasExternalRoscOnly                     : hasExternalRoscOnly,

    hasGPIOPortA                            : hasGPIOPortA,
    hasGPIOPortB                            : hasGPIOPortB,
    hasGPIOPortC                            : hasGPIOPortC,
    hasBSLConfig                            : hasBSLConfig,

    isInternalTimerChannel                  : isInternalTimerChannel,

    sliceNumber : sliceNumber,
    getGPIOPort : getGPIOPort,
    getGPIONumber : getGPIONumber,

    init: init,

    getRetentionConfig              : getRetentionConfig,
    getRetentionDeclareC            : getRetentionDeclareC,
    getRetentionRdyC                : getRetentionRdyC,
    getRetentionSaveC               : getRetentionSaveC,
    getRetentionRestoreC            : getRetentionRestoreC,
    getStaticRetentionDeclareC      : getStaticRetentionDeclareC,
    getStaticRetentionRdyC          : getStaticRetentionRdyC,
    getStaticRetentionSaveC         : getStaticRetentionSaveC,
    getStaticRetentionRestoreC      : getStaticRetentionRestoreC,
    getRetentionValidation          : getRetentionValidation,

    pushGPIOConfigInst              : pushGPIOConfigInst,
    pushGPIOConfigInstAlt           : pushGPIOConfigInstAlt,
    pushGPIOConfigInstAll           : pushGPIOConfigInstAll,
    pushGPIOConfigInstHideOutInv    : pushGPIOConfigInstHideOutInv,
    pushGPIOConfigInstOnlyIntRes    : pushGPIOConfigInstOnlyIntRes,
    getGPIOGroupConfig              : getGPIOGroupConfig,
    getGPIOConfigBoardC             : getGPIOConfigBoardC,

    createFormattedArray: createFormattedArray,

    getBUSCLKFreq       : getBUSCLKFreq,

    getModuleKeys       : getModuleKeys,
    getUsedPins         : getUsedPins,

    InterruptPriorityOptions : InterruptPriorityOptions,

    hasWakeupLogic      : hasWakeupLogic,

    getPinCM                : getPinCM,
    getGPIOPortMultiPad     : getGPIOPortMultiPad,
    getGPIONumberMultiPad   : getGPIONumberMultiPad,
    getAllPorts             : getAllPorts,
    getTimerPWMInstance     : getTimerPWMInstance,
};

/*
 *  ======== IModule ========
 *  Names and types defined by _all_ sysconfig modules
 */
let IModule = {
    config               : [],
    defaultInstanceName  : "",
    description          : "",
    displayName          : "",
    filterHardware       : function (component){return false;},
    longDescription      : "",
    groups               : [], /* unused?? */
    layout               : [], /* unused?? */
    maxInstances         : 0,
    moduleInstances      : function (inst){return [];},
    moduleStatic         : {/* IModule declaration */},
    modules              : function (inst){return [];},
    onHardwareChanged    : function (inst, ui){},
    pinmuxRequirements   : function (inst){return [];},
    sharedModuleInstances: function (inst){return [];},
    templates            : {},
    validate             : function (inst, validation){}
};

let deferred = {
    errs: [],
    warn: [],
    info: [],
    logError:   function (inst, field, msg) {this.errs.push({inst: inst, field: field, msg: msg});},
    logWarning: function (inst, field, msg) {this.warn.push({inst: inst, field: field, msg: msg});},
    logInfo:    function (inst, field, msg) {this.info.push({inst: inst, field: field, msg: msg});}
};

/*
 *  ======== init ========
 */
function init()
{
}

/*
 *  ======== useModule ========
 */
function useModule(name)
{
    let mod = {};
    mod.$mod = scripting.addModule(name);

    /* hoist module statics to mod */
    let spec = system.getScript(mod.$mod.$name.split('$')[0]);
    if (spec.moduleStatic != null && spec.moduleStatic.config != null) {
        let configs = spec.moduleStatic.config;
        for (var i = 0; i < configs.length; i++) {
            let p = configs[i].name;
            let setter = function(x) { this.$mod[p] = x; };
            Object.defineProperty(mod, p, {set: setter});
        }
    }

    /* add create method */
    mod.create = function (name, params) {
        if (params == null) {
            params = {};
        }
        let inst = mod.$mod.addInstance();
        if (name) {
            inst.$name = name;
        }
        for (let p in params) {
            if ("$hardware" == p && params[p] === undefined) {
                console.log("warning: " + name
                            + ".$hardware was set to undefined");
            }
            if (params[p] !== undefined) {
                inst[p] = params[p];
            }
        }
        return (inst);
    };
    return (mod);
}


/*!
 *  ======== boardName ========
 *  Get the name of the board (or device)
 *
 *  @returns String - Name of the board with prefix /ti/boards and
 *                    suffix .syscfg.json stripped off.  If no board
 *                    was specified, the device name is returned.
 */
function boardName()
{
    let boardName = system.deviceData.deviceId;

    if (system.deviceData.board != null) {
        boardName = system.deviceData.board.source;

        /* Strip off everything up to and including the last '/' */
        boardName = boardName.replace(/.*\//, '');

        /* Strip off everything after and including the first '.' */
        boardName = boardName.replace(/\..*/, '');
    }
    return (boardName);
}

/*!
 *  ======== device2Family ========
 *  Map a pimux device object to a TI-driver device family string
 *
 *  @param device   - a pinmux device object (system.deviceData)
 *  @param mod      - module name ("ADC", "PWM", etc)
 *
 *  @returns String - the name of a device family that's used to
 *                    create family specifc-implementation module
 *                    names.  Returns null, in the event of an
 *                    unsupported device.
 */
function device2Family(device)
{
    if(isDeviceM0C()){
        return "MSPM0C"
    }
    /* deviceId is the directory name within the pinmux/deviceData */
    let deviceId = device.deviceId;

    let family = deviceId.match(/MSP(M0G|M0L|M0C)/)[0];

    return(family);
}

/*!
 *  ======== device2DeviceFamily ========
 *  Map a pimux deviceID to a TI-driver device family string
 *
 *  @param deviceId  - a pinmux deviceId (system.deviceData)
 *
 *  @returns String - the corresponding "DeviceFamily_xxxx" string
 *                    used by driverlib header files.
 */
function device2DeviceFamily(deviceId, part)
{
    var DriverLib = system.getScript("/ti/devices/DriverLib");

    let attrs = DriverLib.getAttrs(deviceId, part);

    return (attrs.deviceDefine);
}

/*
 *  ======== getCompName ========
 *  Get fully qualified name of a (sub)component
 */
function getCompName(component)
{
    var name = component.name;
    if (component.$parents && component.$parents.length > 0) {
        name = getCompName(component.$parents[0]) + "." + name;
    }
    return (name);
}

/*
 *  ======== getInstanceIndex ========
 *  returns module.$instances array index of this inst
 */
function getInstanceIndex(inst)
{
    let instances = inst.$module.$instances;
    for (let i = 0; i < instances.length; i++) {
        if (inst == instances[i]) {
            return (i);
        }
    }
    return (-1);
}

/*
 *  ======== getConfigs ========
 *  Return a description of all the configs of the specified module
 *
 *  The description is an object of the form:
 *   {
 *      modName: "",  // full name of the module
 *      baseName: "", // only the last component of the full name
 *      family: ""    // the TI-DRIVERS device family used
 *      mod:  {
 *          portable: {}, // map of all portable module configs
 *          device: {},   // map of all device-specific module configs
 *      },
 *      inst: {
 *          portable: {}, // map of all portable instance configs
 *          device: {},   // map of all device-specific instance configs
 *      }
 *   }
 *  Each config object is of the form:
 *   {
 *      name: "",                         // name of the confg param
 *      default: "",                      // default value
 *      options: [{name: "", ...}, ...],  // array of "named" options
 *   }
 */
function getConfigs(modName)
{
    /* flatten GUI grouping within a config array */
    function flattenGroups(cfgArray) {
        let result = [];
        cfgArray = (cfgArray == null) ? [] : cfgArray;
        for (var i = 0; i < cfgArray.length; i++) {
            var elem = cfgArray[i];
            if (elem.name == null) {
                result = result.concat(flattenGroups(elem.config));
            }
            else {
                result.push(elem);
            }
        }
        return (result);
    }

    /* deep clone needed to prevent inadvertent model corruption */
    function clone(obj) {
        return (JSON.parse(JSON.stringify(obj)));
    }

    /* get current device family */
    let baseName = modName.substring(modName.lastIndexOf("/") + 1);
    let family = device2Family(system.deviceData, baseName);
    let result = {
        modName: modName, baseName: baseName, family: family,
        mod:  {portable: {}, device: {}},
        inst: {portable: {}, device: {}}
    };

    /* get all instance configs */
    let Mod = undefined;
    let allConfigs = [];
    try {
        Mod = system.getScript(modName);
        if (Mod.config) {
            allConfigs = Mod.config;
        }
    }
    catch (x) {
        //console.log("can't find script: '" + modName + "': " + x);
        return result;
    }
    allConfigs = flattenGroups(allConfigs);

    /* determine device-specific instance configs */
    let ModDev = undefined;
    let deviceConfigs = {};
    let portableConfigs = {};
    let base = {moduleStatic: {config:[]}, config: []};
    let devModName =
        modName.substring(0, modName.lastIndexOf('/'))
        + '/' + baseName.toLowerCase() + '/'
        + baseName + family + ".syscfg.js";
    try {
        ModDev = system.getScript(devModName);
        base = ModDev.extend(base);
        if (base.config) {
            base.config = flattenGroups(base.config);
            for (let i = 0; i < base.config.length; i++) {
                let cfg = base.config[i];
                deviceConfigs[cfg.name] = cfg;
            }
        }
    }
    catch (x) {
        //console.log("can't find script: '" + devModName + "': " + x);
    }

    /* determine portable instance configs */
    for (let i = 0; i < allConfigs.length; i++) {
        let cfg = allConfigs[i];
        if (deviceConfigs[cfg.name] == null) {
            portableConfigs[cfg.name] = cfg;
        }
    }
    result.inst.portable = portableConfigs;
    result.inst.device = deviceConfigs;

    /* get all module configs */
    allConfigs = [];
    if (Mod.moduleStatic && Mod.moduleStatic.config) {
        allConfigs = Mod.moduleStatic.config;
    }
    allConfigs = flattenGroups(allConfigs);

    /* determine device-specific module configs */
    deviceConfigs = {};
    portableConfigs = {};
    if (base.moduleStatic && base.moduleStatic.config) {
        let modCfgs = flattenGroups(base.moduleStatic.config);
        for (let i = 0; i < modCfgs.length; i++) {
            let cfg = modCfgs[i];
            deviceConfigs[cfg.name] = cfg;
        }
    }

    /* determine portable module configs */
    for (let i = 0; i < allConfigs.length; i++) {
        let cfg = allConfigs[i];
        if (deviceConfigs[cfg.name] == null) {
            portableConfigs[cfg.name] = cfg;
        }
    }
    result.mod.portable = portableConfigs;
    result.mod.device = deviceConfigs;

    /* make $name appear to be a regular config parameter */
    var nameCfg = result.inst.portable["$name"];
    if (nameCfg != null) {
        /* clone nameCfg so we can add default without breaking
         * addModule/addInstance
         */
        nameCfg = clone(nameCfg);
        nameCfg.displayName = "Name";
        nameCfg.default = Mod.defaultInstanceName + "{num}";
        result.inst.portable["$name"] = nameCfg;
    }

    return (result);
}

/*
 *  ======== getName ========
 *  Compute C name for specified instance
 */
function getName(inst, index)
{
    return (inst.$name);
}

/*
 *  ======== getPort ========
 *  Return pin port name or "". This function is intended to be used for single
 *  functionality pins, for other use cases see getGPIOPortMultiPad.
 *
 *  @param pin - pin object representing the
 *               solution found by pinmux
 *  @returns string of the form P<port>_<index>
 */
function getPort(pin)
{
    let port = "";
    if (pin != null && pin.$solution != null) {
        let pname = pin.$solution.devicePinName;
        port = pname.match(/P\d+\.\d+/);
        port = port ? port[0] : "";

    }
    return port.replace(".", "_");
}

/*
 *  ======== isCName ========
 *  Determine if specified id is either empty or a valid C identifier
 *
 *  @param id  - String that may/may not be a valid C identifier
 *
 *  @returns true if id is a valid C identifier OR is the empty
 *           string; otherwise false.
 */
function isCName(id)
{
    if ((id != null && id.match(/^[a-zA-Z_][0-9a-zA-Z_]*$/) != null)
            || id == '') { /* '' is a special value that means "default" */
        return true;
    }
    return false;
}

/*
 *  ======== genAliases ========
 */
function genAliases(inst, name)
{
    let lines = [];
    if (inst.cAliases != null && inst.cAliases.length > 0) {
        let aliases = inst.cAliases.split(/[,;\s]+/);
        for (let i = 0; i < aliases.length; i++) {
            let alias = aliases[i];
            lines.push("    " + alias + " = " + name + ",");
        }
        lines.push('');
    }
    return (lines.join('\n'));
}

/*
 *  ======== logError ========
 *  Log a new error
 *
 *  @param vo     - a validation object passed to the validate() method
 *  @param inst   - module instance object
 *  @param field  - instance property name, or array of property names, with
 *                  which this error is associated
 */
/* global global */
function logError(vo, inst, field, msg)
{
    if (typeof global != "undefined" && global.__coverage__) {
        vo = deferred;
    }
    if (typeof(field) === 'string') {
        vo.logError(msg, inst, field);
    }
    else {
        for (let i = 0; i < field.length; i++) {
            vo.logError(msg, inst, field[i]);
        }
    }
}

/*
 *  ======== logInfo ========
 *  Log a new remark
 *
 *  @param vo     - a validation object passed to the validate() method
 *  @param inst   - module instance object
 *  @param field  - instance property name, or array of property names, with
 *                  which this remark is associated
 */
function logInfo(vo, inst, field, msg)
{
    if (typeof global != "undefined" && global.__coverage__) {
        vo = deferred;
    }
    if (typeof(field) === 'string') {
        vo.logInfo(msg, inst, field);
    }
    else {
        for (let i = 0; i < field.length; i++) {
            vo.logInfo(msg, inst, field[i]);
        }
    }
}

/*
 *  ======== logWarning ========
 *  Log a new warning
 *
 *  @param vo     - a validation object passed to the validate() method
 *  @param inst   - module instance object
 *  @param field  - instance property name, or array of property names, with
 *                  which this warning is associated
 */
function logWarning(vo, inst, field, msg)
{
    if (typeof global != "undefined" && global.__coverage__) {
        vo = deferred;
    }
    if (typeof(field) === 'string') {
        vo.logWarning(msg, inst, field);
    }
    else {
        for (let i = 0; i < field.length; i++) {
            vo.logWarning(msg, inst, field[i]);
        }
    }
}

/*
 *  ======== newConfig ========
 */
function newConfig()
{
    let config = [
        {
            name: "cAliases",
            displayName: "Alternate Names",
            description: "A comma separated list of valid C identifiers",
            default: ""
        }
    ];

    return (config);
}

/*
 *  ======== newIntPri ========
 *  Create a new intPriority config parameter
 *
 *  Presents a constrained set of logical NVIC interrupt priorities,
 *  excluding priority 0, which is the "Zero Latency"
 *  interrupt priority.
 */
function newIntPri()
{
    let intPri = [{
        name: "interruptPriority",
        displayName: "Hardware Interrupt Priority",
        description: "Hardware interrupt priority",
        longDescription:`This configuration allows you to configure the
hardware interrupt priority.
`,
        default: "7",
        options: [
            { name: "7", displayName: "7 - Lowest Priority" },
            { name: "6" },
            { name: "5" },
            { name: "4" },
            { name: "3" },
            { name: "2" },
            { name: "1", displayName: "1 - Highest Priority" }
        ]
    }];

    return (intPri);
}

/*
 * ======== intPriority2Hex ========
 * translate user readable priority into NVIC priority value
 */
function intPriority2Hex(intPri)
{

    /*
     *(~0) is always interpreted as the lowest priority.
     * NoRTOS DPL does not support "7" as a HwiP priority.
     */
    if (intPri == "7") {

        return ("(~0)");
    }

    return ("0x" + (intPri << 5).toString(16));
}

/*
 *  ======== newSwiPri ========
 *  Create a new swiPriority config parameter
 */
function newSwiPri()
{
    let swiPri = {
        name: "softwareInterruptPriority",
        displayName: "Software Interrupt Priority",
        description: "Software interrupt priority",
        longDescription:`This configuration allows you to configure the
software interrupt priority.
`,
        default: "0",
        options: [
            { name: "0", displayName: "0 - Lowest Priority" },
            { name: "1" },
            { name: "2" },
            { name: "3" },
            { name: "4" },
            { name: "5" },
            { name: "6" },
            { name: "7" },
            { name: "8" },
            { name: "9" },
            { name: "10" },
            { name: "11" },
            { name: "12" },
            { name: "13" },
            { name: "14" },
            { name: "15", displayName: "15 - Highest Priority" }
        ]
    };

    return (swiPri);
}

/*
 * ======== swiPriority2Int ========
 * translate user priority to integer
 */
function swiPriority2Int(swiPri)
{
    return (swiPri);
}

/*
 *  ======== pinToName ========
 * Translate device pin number into pin name
 */
function pinToName(pinNum)
{
    for (let x in system.deviceData.devicePins) {
        if (system.deviceData.devicePins[x].ball == pinNum) {
            let desc = String(system.deviceData.devicePins[x].designSignalName);
            return (desc);
        }
    }

    return ("");
}

/*
 *  ======== print ========
 *  Print specified obj
 */
function print(obj, header, depth, indent)
{
    if (indent == null) indent = "";
    if (header == null) header = "";
    if (depth == null) depth = 4;
    if (indent.length > 2 * depth) return;

    if (obj == null) {
        console.log(header + (obj === null ? "null" : "undefined"));
        return;
    }
    if (indent == "") {
        if (obj.$name != null) {
            console.log(header + obj.$name + ":");
        }
        else if (obj.name != null) {
            console.log(header + obj.name + ":");
        }
        else {
            console.log(header + obj + " (nameless):");
        }
    }

    for (let p in obj) {
        /* print the enumerable properties of obj and their value */
        let line = indent + "  " + p + ": ";

        let value = obj[p];

        let fxn = null;
        if (typeof value == "function") {
            try {
                var src = String(value);
                var k = src.indexOf('{');
                if (k <= 0) {
                    k = src.indexOf('\n');
                }
                fxn = src.substring(0, k);
            } catch (x){/* ignore any exception */}
        }
        if (fxn != null) {
            /* only print declaration of functions (not their entire source) */
            console.log(line + fxn);
        }
        else if (value != null && (typeof value == "object")) {
            console.log(line
                + (("$name" in value) ? (" (" + value.$name + ")") : ""));

            if (p[0] != '$') {
                /* recursively print (non-tool) object properties */
                print(value, "", depth - 1, indent + "  ");
            }
        }
        else {
            /* print non-object values */
            console.log(line + value);
        }
    }
}

/*
 *  ======== printModule ========
 */
function printModule(mod, header, indent)
{
    if (indent == null) indent = "";
    if (header == null) header = "";

    function printConfigs(configs, indent) {

        /* recursively find config arrays and accumulate into flat array */
        function flatten(cfgs, result) {
            if (cfgs != null) {
                for (var i = 0; i < cfgs.length; i++) {
                    var cfg = cfgs[i];
                    if (cfg.name == null) { /* must be a config group */
                        flatten(cfg.config, result);
                    }
                    else {
                        result.push(cfg);
                    }
                }
            }
        }

        if (configs != null && configs.length != 0) {
            /* accumulate all configs */
            var flatCfgs = [];
            flatten(configs, flatCfgs);
            configs = flatCfgs;

            /* maxPad is the maximum field width */
            let maxPad = "                           ";

            /* compute max config name field width */
            let maxName = 1;
            for (let i = 0; i < configs.length; i++) {
                let len = configs[i].name.length;
                if (len > maxName) {
                    maxName = len;
                }
            }
            if (maxName > maxPad.length) {
                maxName = maxPad.length;
            }

            /* compute max config default value field width */
            let maxValue = 1;
            for (let i = 0; i < configs.length; i++) {
                let len = String(configs[i].default).length;
                if (len > maxValue) {
                    maxValue = len;
                }
            }
            if (maxValue > maxPad.length) {
                maxValue = maxPad.length;
            }

            /* print all configs */
            for (let i = 0; i < configs.length; i++) {
                let nLen = configs[i].name.length;
                let vLen = String(configs[i].default).length;
                var npad = maxPad.substring(0, maxName - nLen);
                var vpad = maxPad.substring(0, maxValue - vLen);
                printCfg(configs[i], indent + "  ", npad, vpad);
            }
        }
        else {
            console.log(indent + "  <none>");
        }
    }

    function printCfg(cfg, indent, npad, vpad) {
        npad = npad == null ? "" : npad;
        vpad = vpad == null ? "" : vpad;
        let quote = " ";
        if (typeof cfg.default == "string" || cfg.default instanceof String) {
            quote = "'";
        }
        let desc = cfg.description != null ? (" - " + cfg.description) : "";
        console.log(indent + cfg.name + npad
                    + ": " + quote + cfg.default + quote + vpad
                    + " <" + cfg.displayName + desc + ">"
        );
        printCfgOptions(cfg, indent, quote);
    }

    function printCfgOptions(cfg, indent, quote) {
        /* maxPad is the maximum field width */
        let maxPad = "                           ";

        if (cfg.options != null) {
            let maxName = 0;
            for (let i = 0; i < cfg.options.length; i++) {
                let name = cfg.options[i].name;
                if (maxName < name.length) {
                    maxName = name.length;
                }
            }

            let prefix = indent + "   " + quote;
            for (let i = 0; i < cfg.options.length; i++) {
                let opt = cfg.options[i];
                let desc = opt.description != null ? (" - " + opt.description) : "";
                let displayName = opt.displayName == null ? opt.name : opt.displayName;
                let suffix = ((opt.displayName == opt.name || opt.displayName == null) && desc.length == 0) ? "" : (" <" + displayName + desc +  ">");
                let namePad = maxPad.substring(0, maxName - opt.name.length + 1);
                console.log(prefix + opt.name + quote + namePad + suffix );
            }
        }
    }

    function printLine(line, indent, maxLen) {
        let curline = line;
        while (curline.length > 0) {
            let lastSpace;
            let i;

            /* trim leading space */
            for (i = 0; (curline[i] == ' ') && (i < curline.length);) {
                i++;
            }
            curline = curline.substring(i);
            if (curline.length == 0) return;

            /* find last white space within maxLen characters */
            lastSpace = 0;
            for (i = 0; (i < curline.length) && (i < maxLen); i++) {
                if (curline[i] == ' ') {
                    lastSpace = i;
                }
            }
            if (i == curline.length) {
                lastSpace = i;
            }
            else if (i == maxLen && lastSpace == 0) {
                /* advance i to first space or end of string */
                while ((i < curline.length) && (curline[i] != ' ')) {
                    i++;
                }
                lastSpace = i;
            }

            /* print up to lastSpace and reset curline */
            console.log(indent + curline.substring(0, lastSpace));
            curline = curline.substring(lastSpace);
        }
    }

    /* get the real module object (gack!) */
    mod = system.getScript(mod.$name.split('$')[0]);
    console.log(header + mod.$name + " - " + mod.description);

    indent += "  ";

    console.log(indent + "Module Description");
    if  (mod.longDescription) {
        let lines = mod.longDescription.split('\n');
        for (let i = 0; i < lines.length; i++) {
            printLine(lines[i], indent + "  ", 60);
        }
    }
    else {
        console.log(indent + "  <none>");
    }

    console.log("\n" + indent + "Module Configuration Options");
    if (mod.moduleStatic != null) {
        printConfigs(mod.moduleStatic.config, indent);
    }
    else {
        console.log(indent + "  <none>");
    }

    console.log("\n" + indent + "Instance Configuration Options");
    printConfigs(mod.config, indent);

    console.log("\n" + indent + "Module Methods");
    let methods = [];
    for (let m in mod) {
        if (typeof mod[m] == "function") {
            let mname = String(mod[m]).match(/function [^)(]+(\([^)]+\))/);
            if (mname == null) {
                mname = "function ()";
            }
            else {
                mname = "function " + mname[1];
            }
            let prefix = "";
            if (m in IModule && typeof IModule[m] == "function") {
                prefix = "IModule::";
            }
            methods.push(indent + "  " + prefix + m + ": " + mname);
        }
    }
    console.log(methods.sort().join('\n'));
}

/*
 *  ======== printPins ========
 *  Print specified pinmux solution
 */
function printPins(obj, indent)
{
    if (indent == null) {
        indent = "    ";
    }
    if (obj == null) {
        console.log(obj === null ? "null" : "udefined");
        return;
    }
    let solution = obj.$solution;
    let resources = obj.$resources;
    let peripheral = system.deviceData.peripherals[solution.peripheralName];
    console.log(indent + "peripheral.name = " + peripheral.name);
    for (let p in resources) {
        console.log(indent + "    resources." + p
                    + " = " + resources[p].$solution.devicePinName);
        //            for (let q in resources[p].$solution) {
        //                console.log("          " + q + ": "
        //                    + resources[p].$solution[q]);
        //            }
    }
}

/*
 *  ======== typeMatches ========
 *  Check that HW signal type matches a specified array of types
 *
 *  Example: within a module's filterHardware(component) method:
 *      for (sig in component.signals) {
 *          let type = component.signals[sig].type;
 *          if (Common.typeMatches(type, ["PWM", "DOUT"])) {
 *              :
 *          }
 *      }
 *
 *  type      - a string or array of strings that are valid signal types
 *  nameArray - array of signal name types that must match one of the signal
 *              types named by type
 *
 *  Returns true iff nameArray contains at least one type name that's
 *          specified the type parameter.
 */
function typeMatches(type, nameArray)
{
    let options = {};

    if (type instanceof Array || typeof type == "object") {
        for (let i = 0; i < type.length; i++) {
            options[type[i]] = 1;
        }
    }
    else if (typeof type == "string" || type instanceof String) {
        options[type] = 1;
    }

    for (let i = 0; i < nameArray.length; i++) {
        let name = nameArray[i];
        if (name in options) {
            return (true);
        }
    }

    return (false);
}

/*
 *  ======== setDefaults ========
 *  Copy properties from a signal's settings into inst
 *
 *  inst   - the instance whose properties need to be modified by
 *           an inst.$hardware assignment
 *  signal - a signal object defined by a component
 *  type   - a specific type for the signal (DOUT, PWM, ...)
 *
 *  If type is undefined or null, no properties of inst are modified.
 */
function setDefaults(inst, signal, type)
{
    let settings = {};

    let comp = inst.$hardware;

    /* populate settings hash from the specified signal settings */
    if (signal.settings != null) {
        if (signal.type instanceof Array && signal.type.length > 1) {
            settings = signal.settings[type];
            /* if settings == null, there aren't settings for this type */
        }
        else {
            settings = signal.settings;
        }
    }

    /* allow component settings to override signal settings */
    if (comp.settings != null) {
        let csettings = null;
        if (comp.type instanceof Array && comp.type.length > 1) {
            csettings = comp.settings[type];
            /* if settings == null, there aren't settings for this type */
        }
        else {
            csettings = comp.settings;
        }
        for (let cfg in csettings) {
            settings[cfg] = csettings[cfg];
        }
    }

    /* apply any settings to the instance */
    for (let cfg in settings) {
        try {
            inst[cfg] = settings[cfg];
        }
        catch (x) {
            let msg = "signal '" + signal.name
                + "' of component " + comp.name
                + " specified an unknown setting (" + cfg + ") for "
                + inst.$name;
            console.log("error: " + msg);
            throw new Error(msg);
        }
    }
}

/*
 *  ======== validateNames ========
 *  Validate that all names defined by inst are globally unique and
 *  valid C identifiers.
 */
function validateNames(inst, validation)
{
    let myNames = {}; /* all C identifiers defined by inst) */

    /* check that $name is a C identifier */
    if (inst.$name != "") {
        let token = inst.$name;
        if (!isCName(token)) {
            logError(validation, inst, "$name",
                "'" + token + "' is not a valid a C identifier");
        }
        myNames[token] = 1;
    }

    /* check that cAliases are all C identifiers and there are no dups */
    let tokens = [];
    if ("cAliases" in inst && inst.cAliases != "") {
        tokens = inst.cAliases.split(/[,;\s]+/);
    }

    for (let i = 0; i < tokens.length; i++) {
        let token = tokens[i];
        if (!isCName(token)) {
            logError(validation, inst, "cAliases",
                "'" + token + "' is not a valid a C identifier");
        }
        if (myNames[token] != null) {
            logError(validation, inst, "cAliases",
                "'" + token + "' is defined twice");
        }
        myNames[token] = 1;
    }

    /* ensure all inst C identifiers are globally unique */
    let mods = system.modules;
    for (let i in mods) {
        /* for all instances in all modules in /ti/drivers ... */
        let instances = mods[i].$instances;
        for (let j = 0; j < instances.length; j++) {
            let other = instances[j];

            /* skip self */
            if (inst.$name == other.$name) {
                continue;
            }

            /* compute all other names */
            let name = other.$name;
            if (name != "" && name in myNames) {
                logError(validation, inst, "cAliases",
                    "multiple instances with the same name: '"
                         + name + "': " + inst.$name + " and " + other.$name);
                break;
            }
            if (other.cAliases != null && other.cAliases != "") {
                let tokens = other.cAliases.split(/[,;\s]+/);
                for (let k = 0; k < tokens.length; k++) {
                    name = tokens[k];
                    if (name != "" && name in myNames) {
                        logError(validation, inst, "cAliases",
                            "multiple instances with the same name: '" + name
                                 + "': " + inst.$name + " and " + other.$name);
                        break;
                    }
                }
            }
        }
    }
}

/*
 *  ======== addNameConfig ========
 *  Add $name config for context-sensitive and reference documentation
 */
function addNameConfig(config, modName, prefix)
{
    let baseName = modName.split('/').pop();                 // GPIO
    let fullName = modName.replace(/\//g, '_').substring(1); // ti_drivers_GPIO
    //let docsDir =  modName.split('/').slice(0, -1).join(""); // tidrivers
    let docsDir = "tidrivers"; // Since this function is tidrivers specific

    let nameCfg = {
        name: "$name",
        description: "The C/C++ identifier used in applications as the index"
                   + " parameter passed to " + baseName + " runtime APIs",

        /* The name should be declared as an extern const in ti_drivers_config.h
         * and defined in ti_drivers_config.c. Using an extern const
         * allows libraries to define symbolic names for GPIO
         * signals they require for their use _without_ requiring
         * editing or rebuilding of the library source files.
         */
        longDescription: "This name is declared in the generated ti_drivers_config.h"
                   + " file so applications can reference this instance"
                   + " symbolically. "
    };

    return ([nameCfg].concat(config));
}


/*
 *  ======== autoForceModules ========
 *  Returns an implementation of a module's modules method that just
 *  forces the addition of the specified modules
 *
 *  @param kwargs An array of module name strings.
 *
 *  @return An array with module instance objects
 *
 *  Example:
 *     modules: Common.autoForceModules(["Board", "DMA"])
 */
function autoForceModules(kwargs)
{
    return (function(){

        let modArray = [];

        if (kwargs == undefined || kwargs == null || !Array.isArray(kwargs)) {
            console.log("Common.js:autoForceModules('kwargs'): 'kwargs' invalid!");
            return (modArray);
        }

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
    });
}

/*
 *  ======== autoForceDriversModules ========
 *  Returns an implementation of a module's modules method that just
 *  forces the addition of the specified modules
 *
 *  @param kwargs An array of module name strings.
 *
 *  @return An array with module instance objects
 *
 *  Example:
 *     modules: Common.autoForceDriversModules(["Board", "UART"])
 */
function autoForceDriversModules(kwargs)
{
    return (function(){

        let modArray = [];

        if (kwargs == undefined || kwargs == null || !Array.isArray(kwargs)) {
            console.log("Common.js:autoForceModules('kwargs'): 'kwargs' invalid!");
            return (modArray);
        }

        for (let args = kwargs.length - 1; args >= 0; args--) {
            let modPath = kwargs[args];
            if (modPath.indexOf('/') == -1) {
                modPath = "/ti/drivers/" + modPath;
            }
            modArray.push({
                name      : modPath.substring(modPath.lastIndexOf('/') + 1),
                moduleName: modPath,
                hidden    : true
            });
        }

        return modArray;
    });
}

/*
 *  ======== genBoardHeader ========
 *  Common Board.h.xdt function to generate standard module header
 *  including instance #defines
 *
 *  instances = array of module instances
 *  mod       = module object
 */
function genBoardHeader(instances, mod)
{
    let padding = Array(80).join(' ');
    let maxLineLength = 30;
    let line;
    let lines = [];
    let banner = [];
    let pinResources = [];

    banner.push("/*");
    banner.push(" *  ======== " + mod.displayName + " ========");
    banner.push(" */");
    banner.push("");

    /* Construct each line and determine max line length */
    for (let i = 0; i < instances.length; i++) {
        let inst = instances[i];

        /* Does the module have a '_getPinResources()' method */
        if (mod._getPinResources) {

            /* Construct pin resources string to be used as a comment */
            pinResources[i] = mod._getPinResources(inst);

            /* Check if anything was returned */
            if (pinResources[i] != null && pinResources[i] != undefined) {

                /* Construct a comment string */
                line = genResourceComment(pinResources[i]);
                lines.push(line);
            }
        }

        line = "#define x" + inst.$name;
        lines.push(line);

        /* Is this line length greater than the previous max */
        if (line.length > maxLineLength) {
            maxLineLength = line.length;
        }
    }

    /*
     * No comment was included in this original implementation. Not sure
     * what wizardry is going on here.
     */
    maxLineLength = ((maxLineLength + 3) & 0xfffc) + 4;

    /* Modulate lines based on max line length, append instance number */
    let instanceNum = 0;
    for (let i = 0; i < lines.length; i++) {

        /* If this instance has a comment, assume 1 comment per instance */
        if (pinResources[instanceNum] && pinResources[instanceNum] != null) {
            i++;
        }
        lines[i] += padding.substring(0, maxLineLength - lines[i].length);
        lines[i] += instanceNum++;
    }

    return ((banner.concat(lines)).join("\n"));
}

/*
 *  ======== genResourceComment ========
 * Construct a comment string from (potentially) multi-line text
 *
 * Assumes 'text' is a string containing one or more
 * lines delimited by new lines (\n)
 */
function genResourceComment(text)
{
    /* split into separate lines and trim trailing white space */
    let lines = text.split(/[ \t]*\n/);

    /* if it's a multi-line comment ... */
    if (lines.length > 1) {

        /* Prevent trailing space after digraph */
        lines[0] = "/*" + lines[0];

        for (let i = 1; i < lines.length; i++) {
            /* prefix intermediate lines with asterisks and spaces */
            lines[i] = " *  " + lines[i];
        }
        lines.push(""); /* add new line for comment end */
    }
    else {
        /* If single line comment, add a space after initial digraph */
        lines[0] = "/* " + lines[0];
    }

    /* end the comment */
    lines[lines.length - 1] += " */";

    /* return a single string with embedded \n's */
    return (lines.join("\n"));
}

/*
 *  ======== findSignalTypes ========
 *  Function to recursively parse a hardware component for a signal type.
 *
 *  hardware    - an object representing a hardware component
 *  signalTypes - an array of signal type strings
 *
 * Example:
 *    findSignalTypes(hardware, ["SPI_SS", "DOUT", "I2S_SCL"])
 *
 *  Returns true if any signal in 'signalTypes' is found in the hardware
 *  component. This function returns as soon as any signal in 'signalTypes' is
 *  found.
 */
function findSignalTypes(hardware, signalTypes)
{
    /* 'signalTypes' should be an array of signal names in a string */
    if (signalTypes == undefined || signalTypes == null || !Array.isArray(signalTypes)) {
        console.log("Common.js:findSignalTypes(hardware, signalTypes):"
            + "'signalTypes' invalid!");
        return (false);
    }

    /* Ensure hardware is not null or undefined */
    if (hardware == undefined || hardware == null) {
        console.log("Common.js:findSignalTypes(hardware, signalTypes):"
            + "'hardware' undefined!");
        return (false);
    }

    /* Evaluate if this hardware component has any signals */
    if (hardware.signals) {
        for (let sig in hardware.signals) {
            let signal = hardware.signals[sig];
            for (let i in signal.type) {
                let type = signal.type[i];
                if (signalTypes.includes(type)) {
                    return (true);
                }
            }
        }
    }

    /* Evaluate if this hardware component has any subcomponents */
    if (hardware.subComponents || hardware.components) {
        let result;

        /* Ensure we don't pass an empty object */
        if (hardware.subComponents != undefined && hardware.subComponents != null) {

            /* Iterate over all subComponents of this hardware component */
            for (let components in hardware.subComponents) {

                /* Recursively pass each component */
                result = findSignalTypes(hardware.subComponents[components], signalTypes);
                if (result == true) {
                    return (result);
                }
            }
        }

        /* Repeat steps above for "components" instead of "subComponents" */
        if (hardware.components != undefined && hardware.components != null) {
            for (let components in hardware.components) {
                result = findSignalTypes(hardware.components[components], signalTypes);
                if (result == true) {
                    return (result);
                }
            }
        }
    }

    return (false);
}

function findDuplicates(arrayToCheck)
{
    const count = arrayToCheck =>
      arrayToCheck.reduce((a, b) => ({ ...a,
        [b]: (a[b] || 0) + 1
      }), {})

    const duplicates = dict =>
      Object.keys(dict).filter((a) => dict[a] > 1)

    return {count: count(arrayToCheck), duplicates: duplicates(count(arrayToCheck))};
}

function stringOrEmpty(stringToCheck, stringToAdd)
{
    if (stringToCheck != "")
    {
        return stringToAdd;
    }
    return "";
}

function getUnitPrefix(num, precision_optional) {
    let precision;
    if(precision_optional !== undefined){
        precision = precision_optional;
    } else {
        precision = 2;
    }
    /* Currently only works on positive integers */
    let out = num;
    let pre = "";
    if(num == 0){
        num = 0;
        pre = '';
    } else if(num * 0.000000001 >= 1){
        out = num * 0.000000001;
        pre = 'G';
    } else if(num * 0.000001 >= 1){
        out = num * 0.000001;
        pre = 'M';
    } else if(num * 0.001 >= 1){
        out = num * 0.001;
        pre = 'k';
    } else if(num >= 1){
        out = num;
        pre = "";
    } else if(num * 1000 >= 1){
        out = num * 1000;
        pre = 'm';
    } else if(num * 1000000 >= 1){
        out = num * 1000000;
        pre = 'μ';
    } else {
        out = num * 1000000000;
        pre = 'n';
    }
    return {num: out, pre: pre, str: out.toFixed(precision) + " " + pre };
}


function parseFloatUnitInput(inputStr, unit) {
    /* Parses a string float input which must have a unit and can have a unit prefix attached
     * Valid inputs include:
     * 1.234 V, -50 mV, 7890.123uA
     * will return:
     * 1.234 , 0.05, 0.007890123
     *
     * Invalid inputs include
     * gas3ewr, -a3215, <nothing>,
     * will return NaN.
     *
     * To validate:
     *  let value = Common.parseFloatUnitInput(inst.LowThresholdIn);
     *  if(isNaN(value)) {
     *      validation.logWarning("The input cannot be successfully parsed.\nValid Examples: (1 V, 10 mV, 245.67uV)", inst, "nameOfConfig");
     *  } else if(value > max || value < min) {
     *      validation.logError("The input exceeds the configured Voltage maximum of +/-"+inst.yourValue, inst, "nameOfconfig");
     *  }
     */
    let units = "";
    if(!inputStr){
        return NaN;
    }
    if(unit){
        units = unit;
    } else {
        units = "[A-Za-z]"; // any arbitrary character
    }
    let initialValue = parseFloat(inputStr);
    let movedValue;

    // only supported prefixes
    let validStr = new RegExp("^[0-9\\.]+\\s*[GMkcmun]{1}"+units+"$");

    let validStrwoPref = new RegExp("^[0-9\\.]+\\s*"+units+"$");
    let validStrUnitless = new RegExp("^[0-9\\.]+\\s*$");
    let validStrExponent = new RegExp("^[0-9\\.]+e[-\\+]{0,1}[0-9]\\s*"+units+"$");
    let validStrExponentwoUnits = new RegExp("^[0-9\\.]+e[-\\+]{0,1}[0-9]\\s*$");
    let sign = inputStr.match(/[A-Za-z]/); // return a match object with first character
    if(inputStr.match(validStr)){
        switch(sign[0]){
            case 'G':
                movedValue = initialValue * 1000000000;
                break;
            case 'M':
                movedValue = initialValue * 1000000;
                break;
            case 'k':
                movedValue = initialValue * 1000;
                break;
            case 'c':
                movedValue = initialValue * 0.01;
                break;
            case 'm':
                movedValue = initialValue * 0.001;
                break;
            case 'u':
                movedValue = initialValue * 0.000001;
                break;
            case 'n':
                movedValue = initialValue * 0.000000001;
                break;
            default: // invald prefix detected
                movedValue = NaN;
        }
    } else if (inputStr.match(validStrwoPref) || inputStr.match(validStrUnitless)) {
        movedValue = initialValue;
    } else if (inputStr.match(validStrExponent) || inputStr.match(validStrExponentwoUnits)) {
        // parse float can parse exponents
        movedValue = initialValue;
    }
    else {
        movedValue = NaN;
    }

    return movedValue;
}

function peripheralCount(peripheralType)
{
	let peripherals = system.deviceData.peripherals
	let numberOfPeripherals = Object.keys(peripherals).length;
	var count = 0;

	//console.log(numberOfPeripherals);

	for (var peripheral in peripherals) {

	  	try
	  	{
	  		var interfaces = peripherals[peripheral]["interfaces"];
	  		for (var interfaceType in interfaces)
	  		{
	  			if (peripheralType == interfaceType)
	  			{
	  				let peripheralNames = interfaces[interfaceType].peripherals;
	  				//console.log(peripheralNames);
	  				count = peripheralNames.length;
					//console.log(count);
	  				return count;
	  			}
			}
		}
		catch(err) {

		}
	}
	//console.log(peripheralType);
	//console.log(count);
	if (count == 0)
	{
		return -1;
	}
    return (count);
}

function getDeviceName()
{
	var deviceName = system.deviceData.device;
	return deviceName
}

/* Device Family Functions - identify selected device */
/* Checks if device is part of MSPM0L11XX_L13XX family */
function isDeviceFamily_PARENT_MSPM0L11XX_L13XX(){
    var deviceName = system.deviceData.device;
    return (["MSPM0L134X","MSPM0L130X","MSPM0L110X"].includes(deviceName));
}
/* Checks if device is part of MSPM0G1X0X_G3X0X device family */
function isDeviceFamily_PARENT_MSPM0G1X0X_G3X0X(){
    var deviceName = system.deviceData.device;
    return (["MSPM0G350X","MSPM0G310X","MSPM0G150X","MSPM0G110X"].includes(deviceName));
}
/* Checks if device is part of MSPM0GX51X device family */
function isDeviceFamily_PARENT_MSPM0GX51X(){
    var deviceName = system.deviceData.device;
    return (["MSPM0G351X","MSPM0G151X"].includes(deviceName));
}
/* Checks if device is part of MSPM0L122X_L222X device family */
function isDeviceFamily_PARENT_MSPM0L122X_L222X(){
    var deviceName = system.deviceData.device;
    return (["MSPM0L122X","MSPM0L222X"].includes(deviceName));
}
/* Checks if device is part of MSPM0L122X device family */
function isDeviceFamily_PARENT_MSPM0L122X(){
    var deviceName = system.deviceData.device;
    return (["MSPM0L122X"].includes(deviceName));
}
/* Checks if device is part of MSPM0L222X device family */
function isDeviceFamily_PARENT_MSPM0L222X(){
    var deviceName = system.deviceData.device;
    return (["MSPM0L222X"].includes(deviceName));
}
/* Checks if device is part of MSPM0C110X device family */
function isDeviceFamily_PARENT_MSPM0C110X(){
    var deviceName = system.deviceData.device;
    return (["MSPM0C110X","MSPS003FX"].includes(deviceName));
}
/* Checks if device is part of MSPS003FX device family */
function isDeviceFamily_MSPS003FX(){
    var deviceName = system.deviceData.device;
    return (["MSPS003FX"].includes(deviceName));
}

/* checks if current device is one of M0x110x series */
function isDeviceM0x110x(){
	var deviceName = system.deviceData.device;
    return (["MSPM0G110X","MSPM0L110X","MSPM0C110X","MSPS003FX"].includes(deviceName));
}

/* checks if current device is one of M0x310x series */
function isDeviceM0x310x(){
	var deviceName = system.deviceData.device;
    return (["MSPM0G310X"].includes(deviceName));
}

/* Generic Device Check Functions */
/* checks if current device is one of MSPM0G-series */
function isDeviceM0G()
{
	return (isDeviceFamily_PARENT_MSPM0G1X0X_G3X0X() || isDeviceFamily_PARENT_MSPM0GX51X());
}
/* checks if current device is one of MSPM0L-series */
function isDeviceM0L(){
    return (isDeviceFamily_PARENT_MSPM0L11XX_L13XX() || isDeviceFamily_PARENT_MSPM0L122X_L222X());
}
/* checks if current device is one of MSPM0C-series */
function isDeviceM0C(){
    return (isDeviceFamily_PARENT_MSPM0C110X());
}

/* gets the device family name */
function getDeviceFamily(){
    if(isDeviceFamily_PARENT_MSPM0G1X0X_G3X0X()){
        return "MSPM0G1X0X_G3X0X";
    }
    else if(isDeviceFamily_PARENT_MSPM0L11XX_L13XX()){
        return "MSPM0L11XX_L13XX";
    }
    else if(isDeviceFamily_PARENT_MSPM0L122X_L222X()){
        return "MSPM0L122X_L222X";
    }
    else if(isDeviceFamily_PARENT_MSPM0C110X()){
        return "MSPM0C110X";
    }
    if(isDeviceFamily_PARENT_MSPM0GX51X()){
        return "MSPM0GX51X";
    }
    return undefined;
}

/*
 * Check if the current device is not affected by I2C_ERR_04
 * Currently affects all devices, but once we have a device it is fixed in
   add it to list the of fixed devices.
   TODO: Once the # of devices it is fixed in outnumbers the problem devices, likely want to reverse
   logic.
*/
function I2CTargetWakeupWorkaroundFixed() {
    var deviceName = system.deviceData.device;
    let fixedDevices = [];
    return (fixedDevices.includes(deviceName));
}

// TODO: confirm with documentation
/* Check if device supports BSL configuration */
function hasBSLConfig(){
    return (isDeviceM0G() || isDeviceM0L());
}

/* Check if device supports Timer A configuration */
function hasTimerA(){
    return (isDeviceM0G() || isDeviceM0C() || isDeviceFamily_PARENT_MSPM0L122X_L222X());
}

function isInternalTimerChannel(cc){
    // Internal timer channels are currently defined as channels 4 and 5, only available for TIMA
    return(hasTimerA() && (cc>=4));
}

/* Checks if device only supports external resistor (rosc) for FCL*/
function hasExternalRoscOnly(){
    return (isDeviceFamily_PARENT_MSPM0L11XX_L13XX());
}


/* Check if device supports GPIO Port A configuration */
function hasGPIOPortA(){
    return Object.keys(system.deviceData.gpio.pinInfo).some(str=>system.deviceData.gpio.pinInfo[str].devicePin.designSignalName.includes("PA"));
}
/* Check if device supports GPIO Port B configuration */
function hasGPIOPortB(){
    return Object.keys(system.deviceData.gpio.pinInfo).some(str=>system.deviceData.gpio.pinInfo[str].devicePin.designSignalName.includes("PB"));
}
/* Check if device supports GPIO Port B configuration */
function hasGPIOPortC(){
    return Object.keys(system.deviceData.gpio.pinInfo).some(str=>system.deviceData.gpio.pinInfo[str].devicePin.designSignalName.includes("PC"));
}

/* return last integer portion of string. useful for extracting pin number */
function sliceNumber(stringValue){
	return stringValue.match(/\d+$/)[0]
}

/* return pin number from single pin name */
function getGPIONumber(gpioName){
	return sliceNumber(gpioName);
}

/* return GPIO port (GPIOA / GPIOB) based on single device data pin name */
function getGPIOPort(gpioName){
    // TODO: define the ports somewhere else so we can update univerally instead of just here 'ABC'
    // --> decide between global define or new Common function.
    // --> confirm if accesible from device data
	return "GPIO"+gpioName.match(/[ABC]/)[0];
}

/*
 *  ======== getGPIOPortMultiPad ========
 *  Return pin port name for specified pin mux functionality.
 *  Supports use case of dual functionality pad
 *
 *  @param packagePin - package pin number
 *  @param inst - sysconfig module instance of peripheral that contains the pin
 *  @pinInterfaceName - interface name of specific pin functionality
 *
 *  @returns string of the form P<port>
 */
function getGPIOPortMultiPad(packagePin, inst, pinInterfaceName){
    let pinNames = (system.deviceData.devicePins[packagePin].mux.muxSetting[0].peripheralPin.peripheralName).split("/");
    let padIndex = identifyPadIndex(packagePin,inst,pinInterfaceName);
    return getGPIOPort(pinNames[padIndex])
}

/*
 *  ======== getGPIOPinNumberMultiPad ========
 *  Return pin number for specified pin mux functionality.
 *  Supports use case of dual functionality pad
 *
 *  @param packagePin - package pin number
 *  @param inst - sysconfig module instance of peripheral that contains the pin
 *  @pinInterfaceName - interface name of specific pin functionality
 *
 *  @returns string of the form <pin number>
 */
function getGPIONumberMultiPad(packagePin, inst, pinInterfaceName){
    let pinNames = (system.deviceData.devicePins[packagePin].mux.muxSetting[0].peripheralPin.peripheralName).split("/");
    let padIndex = identifyPadIndex(packagePin,inst,pinInterfaceName);
    return getGPIONumber(pinNames[padIndex])

}

/*
 *  ======== isInstanceStatic ========
 *  Check if a SysConfig module is static or not
*       - Static modules have default name of the actual module name ( "/ti/driverlib/SYSCTL" )
*       - Dynamic modules cannot have symbols on name, not a valid C identifier
 *  @param inst - sysconfig module instance
 *
 *  @returns boolean true if module is static, false if dynamic
 */
function isInstanceStatic(inst){
    /*
     * Handling use case of static module:
     * - Static modules have default name of the actual module name ( "/ti/driverlib/SYSCTL" )
     * - Dynamic modules cannot have symbols on name, not a valid C identifier
     */
    return (inst.$name.includes("/"))
}

/*
 *  ======== identifyPadIndex ========
 *  Return index of the specified pin's mux location
 *  Accesses device data to find the id of the specified package pin id
 *  index location of the provided <PERIPHERAL>.<PIN INTERFACE NAME>
 *
 *  @param packagePin - package pin number
 *  @param inst - sysconfig module instance of peripheral that contains the pin
 *  @pinInterfaceName - interface name of specific pin functionality
 *
 *  @returns string index of the desired pin mux
 */
function identifyPadIndex(packagePin,inst,pinInterfaceName){
    let peripheralName = undefined;
    let gpioName = undefined;
    /* Handling use case of static module: */
    if(isInstanceStatic(inst)){
       peripheralName = system.modules[inst.$name].displayName;
    }
    /* Dynamic Modules */
    else{
        /* Handle use case of GPIO module */
        if(inst.$module.$name.includes("GPIO")){
            gpioName = inst.pin.$solution;
        }
        /* All other modules */
        /* TODO: Need to handle cases for TIMERFault and NONMAIN */
        else{
            peripheralName = inst.peripheral.$solution.peripheralName;
        }
    }
    /* determine index of mux functionality */
    let muxId = undefined;
    if(peripheralName !== undefined){
        muxId = ((system.deviceData.devicePins[packagePin].mux.muxSetting).map(a => a.peripheralPin.name)).indexOf(peripheralName+"."+pinInterfaceName)
    }
    else if(gpioName !== undefined){
        muxId = ((system.deviceData.devicePins[packagePin].mux.muxSetting).map(a => a.peripheralPin.name)).indexOf(peripheralName+"."+pinInterfaceName)
    }
    /* divide the pad functionality, determine appropiate segment */
    let modeMiddleIndex = getModeIndex(packagePin);
    if(muxId !== undefined){
        if(muxId>modeMiddleIndex){
            return 1;
        }
    }
    return 0;
}

// TODO: Want a better way to acces all ports possible
// may be device data, may not be.
// -- used for getPinNumber/getGPIOPort filtering, + used for Unused Pin Configuration
function getAllPorts(){
    return ["A","B","C"]
}

/*
 *  ======== getPinCM ========
 *  Return PinCM number of the specified pin
 *  Accesses device data to find the id of the specified package pin id
 *  index location of the provided <PERIPHERAL>.<PIN INTERFACE NAME>
 *
 *  @param packagePin - package pin number
 *  @param inst - sysconfig module instance of peripheral that contains the pin
 *  @pinInterfaceName - interface name of specific pin functionality
 *
 *  @returns string PinCM number.
 */
function getPinCM(packagePin, inst, pinInterfaceName)
// TODO: example call => getPinCM(11, (spi inst), "POCI")
{
    // TODO: want to add condition to only do the steps after this one if more than one pinCM is returned
    let pinCMs = (system.deviceData.devicePins[packagePin].attributes.iomux_pincm).split(",")
    let padIndex = identifyPadIndex(packagePin,inst,pinInterfaceName);
    return pinCMs[padIndex];

}

/*
 *  ======== getModeIndex ========
 *  Get the index of the last element of the pinmux dividing the pins in the
 *  same pad
 *  Where in device data the modes are ordered ['1', '2', '0', '2', '3', '0'],
 *  the rule to follow is that where the mode either decreases to a non-zero
 *  number, or increases after a 0 number, that marks the beginning of a
 *  different pin.
 *
 *  @param packagePin - package pin id
 *
 *  @returns string index of the last object in the mode list belonging to the
 *  first pin
 */
function getModeIndex(packagePin){
    let modes = (system.deviceData.devicePins[packagePin].mux.muxSetting).map(a => a.mode);
    for(let modeIdx in modes){
        /* In order to find the midpoint of that divides the pins, the logic is as follows:
         * if(((mode[i]>mode[i+1])&&(mode[i]!=0))||((mode[i]==0)&&(mode[i]<mode[i+1])))
         * The midpoint exists when the mode decreases to a non-zero number, or increases after a zero
         */
        if(((parseInt(modes[parseInt(modeIdx)])>parseInt(modes[parseInt(modeIdx)+1]))&&(parseInt(modes[parseInt(modeIdx)+1])!==0))
        ||((parseInt(modes[parseInt(modeIdx)])==0)&&(parseInt(modes[parseInt(modeIdx)])<parseInt(modes[parseInt(modeIdx)+1])))){
            return parseInt(modeIdx)
        }
    };
    return modes.length-1;
}

/* Common Config & Code Generation Elements */
/* Retention Configuration Option */
function getRetentionConfig(){
    if(isDeviceM0G()){
        return [
            {
                name        : "enableRetention",
                default     : true,
                hidden      : true,
            },
            {
                name: "enableRetentionUI",
                displayName: "Low-Power Register Retention",
                default: "",
                longDescription: `
Some MSPM0G peripherals residing in PD1 domain do not retain register contents when
entering STOP or STANDBY modes. Please view the datasheet for more details.\n
Developers can decide to re-initialize the peripheral using the default
initialization from SysConfig in their application. This approach is more
memory-efficient.\n
Alternatively, the user may also call the provided DriverLib APIs to save and
restore the register configuration of the peripheral before and after entering
low-power mode. This approach is recommended if the peripheral configuration is
modified at runtime.
                `,
                getValue: (inst)=> {
                    let solution = false;
                    try{
                        solution = !(/SLEEP/.test(system.modules["/ti/driverlib/SYSCTL"].$static.powerPolicy));
                    }catch (e) {
                        // do nothing
                    }
                    return (solution?"Registers not retained":"Registers retained");
                }
            },
            {
                name        : "overrideRetention",
                displayName : "Disable Retention APIs",
                longDescription: `
When selected, the retention APIs will not be generated regardless of selected peripheral.`,
                default     : false,
                hidden      : false,
            },
        ];
    }
    else return [];
}
function getRetentionDeclareC(instances,module){
    let retentionString = "";
    let retCount = 0;
    for (let i in instances) {
        let inst = instances[i];
        if(inst.enableRetention&&!inst.overrideRetention){
            /* special UART condition */
            let moduleModifier = ""
            if(module == "UART"){
                moduleModifier = ((inst.enableExtend)?"_Extend":"_Main");
            }
            if(module == "Timer"){
                let flavor = inst.peripheral.$solution.peripheralName;
                moduleModifier = (flavor.replace(/[0-9]/g, '')).slice(3);
            }
            if(retCount>0){retentionString += "\n";}
            retentionString += "DL_"+module+moduleModifier+"_backupConfig g"+inst.$name+"Backup;";
            retCount++;
        }
    }
    return retentionString;
}
function getRetentionRdyC(instances,module){
    let retentionString = "";
    let retCount = 0;
    for (let i in instances) {
        let inst = instances[i];
        if(inst.enableRetention&&!inst.overrideRetention){
            if(retCount>0){retentionString += "\n";}
            retentionString += "\tg"+inst.$name+"Backup.backupRdy \t= false;";
            retCount++;
        }
    }
    return retentionString;
}
function getRetentionSaveC(instances,module){
    let retentionString = "";
    let retCount = 0;
    for (let i in instances) {
        let inst = instances[i];
        if(inst.enableRetention&&!inst.overrideRetention){
            /* special UART condition */
            let moduleModifier = ""
            if(module == "UART"){
                moduleModifier = ((inst.enableExtend)?"_Extend":"_Main");
            }
            if(module == "Timer"){
                let flavor = inst.peripheral.$solution.peripheralName;
                moduleModifier = (flavor.replace(/[0-9]/g, '')).slice(3);
            }
            if(retCount>0){retentionString += "\n";}
            retentionString += "\tretStatus &= DL_"+module+moduleModifier+"_saveConfiguration("+inst.$name+"_INST, &g"+inst.$name+"Backup);"
            retCount++;
        }
    }
    return retentionString;
}
function getRetentionRestoreC(instances,module){
    let retentionString = "";
    let retCount = 0;
    for (let i in instances) {
        let inst = instances[i];
        if(inst.enableRetention&&!inst.overrideRetention){
            /* special UART or TIMER condition */
            let moduleModifier = "";
            if(module == "UART"){
                moduleModifier = ((inst.enableExtend)?"_Extend":"_Main");
            }
            if(module == "Timer"){
                let flavor = inst.peripheral.$solution.peripheralName;
                moduleModifier = (flavor.replace(/[0-9]/g, '')).slice(3);
            }
            if(retCount>0){retentionString += "\n";}
            retentionString += "\tretStatus &= DL_"+module+moduleModifier+"_restoreConfiguration("+inst.$name+"_INST, &g"+inst.$name+"Backup";
            /* For TIMER modules, need to add restoreCounter options */
            if(module == "Timer"){
                retentionString += ", "+inst.retentionRestoreCnt;
            }
            retentionString += ");";
            retCount++;
        }
    }
    return retentionString;
}

function getStaticRetentionDeclareC(stat,module){
    let retentionString = "";
    if(stat.enableRetention&&!stat.overrideRetention){
        retentionString += "DL_"+module+"_backupConfig g"+module+"Backup;"
    }
    return retentionString;
}
function getStaticRetentionRdyC(stat,module){
    let retentionString = "";
    if(stat.enableRetention&&!stat.overrideRetention){
        retentionString += "\tg"+module+"Backup.backupRdy \t= false;"
    }
    return retentionString;
}
function getStaticRetentionSaveC(stat,module){
    let retentionString = "";
        if(stat.enableRetention&&!stat.overrideRetention){
            retentionString += "\tretStatus &= DL_"+module+"_saveConfiguration("+module+", &g"+module+"Backup);"
        }
    return retentionString;
}
function getStaticRetentionRestoreC(stat,module){
    let retentionString = "";
        if(stat.enableRetention&&!stat.overrideRetention){
        retentionString += "\tretStatus &= DL_"+module+"_restoreConfiguration("+module+", &g"+module+"Backup);"
    }
    return retentionString;
}

function getRetentionValidation(inst,validation){
    if(isDeviceM0G()){
        if(inst.enableRetention&&!inst.overrideRetention){
            validation.logInfo("Peripheral does not retain register contents in STOP or STANDBY modes. User should take care to save and restore register configuration in application. See Retention Configuration section for more details.", inst);
        }
    }
}

/* Peripheral Pin Configuration Options */
/*
 *  ======== pushGPIOConfigInstAll ========
 *  Returns GPIOPinGeneric module for use in moduleInstances function
 *
 *  @param inst The peripheral instance
 *  @param modInstances The collection of submodule instances
 *  @param pinmuxCondition Boolean condition of whether to add pin configuration
 *  @param resourceName Pin name used for pinmuxResourcess
 *  @param pinName Pin name formatted for use in DL_GPIO_ header
 *  @param pinDisplayName Full display name for use in group config item
 *  @param direction Determine if pin is Input / Output
 *  @param hideOutputInversion Determine if Output Inversion option should be disabled
 *  @param onlyInternalResistor determine if should only be able to configure internal resistor
 *  @param peripheralType determine if digital or analog peripheral
 *  @param altIOMUX use alternate IOMUX naming order
 *
 *  @return the config item for the GPIOPinGeneric submodule
 *
 *  Example:
 *         pushGPIOConfigInstAll(inst, modInstances,   sclkConfig,    "sclkPin",  "SCLK",
 *          "SPI SCLK (Clock) Pin Configuration",
 *          "OUTPUT", true, false, "Digital");
 */
function pushGPIOConfigInstAll(inst, modInstances, pinmuxCondition, resourceName, pinName, pinDisplayName, direction, hideOutputInversion, onlyInternalResistor, peripheralType, altIOMUX){
    let passedPinName = "GPIO_"+inst.$name.replace("/ti/driverlib/","")+"_IOMUX_"+pinName;
    if(altIOMUX){
        passedPinName = "GPIO_"+inst.$name.replace("/ti/driverlib/","")+"_"+pinName+"_IOMUX";
    }
    if(pinmuxCondition){
        let mod = {
            name: resourceName+"Config",
            displayName: pinDisplayName,
            moduleName: '/ti/driverlib/gpio/GPIOPinGeneric',
            group: "GROUP_PINMUX_PERIPH",
            collapsed: true,
            // args: {

            // },
            requiredArgs: {
                passedPinName: passedPinName,
                passedResourceName: resourceName,
                passedPeripheralType: peripheralType,
                direction: direction,
                hideOutputInversion: hideOutputInversion,
                onlyInternalResistor: onlyInternalResistor,
            },
        }
        modInstances.push(mod);
    }
}
/* Default version of function call + Digital Configuration */
function pushGPIOConfigInst(inst, modInstances, pinmuxCondition, resourceName, pinName, pinDisplayName, direction){
    pushGPIOConfigInstAll(inst, modInstances, pinmuxCondition, resourceName, pinName, pinDisplayName, direction, false, false, "Digital",false);
}
/* Default version of function call + Digital Configuration (Alternate IOMUX naming order) */
function pushGPIOConfigInstAlt(inst, modInstances, pinmuxCondition, resourceName, pinName, pinDisplayName, direction){
    pushGPIOConfigInstAll(inst, modInstances, pinmuxCondition, resourceName, pinName, pinDisplayName, direction, false, false, "Digital",true);
}
/* Add GPIO config with hidden output inversion + Digital Configuration */
function pushGPIOConfigInstHideOutInv(inst, modInstances, pinmuxCondition, resourceName, pinName, pinDisplayName, direction){
    pushGPIOConfigInstAll(inst, modInstances, pinmuxCondition, resourceName, pinName, pinDisplayName, direction, true, false, "Digital",false);
}
/* Add GPIO config with only internal resistor configurable + Analog Configuration */
function pushGPIOConfigInstOnlyIntRes(inst, modInstances, pinmuxCondition, resourceName, pinName, pinDisplayName, direction){
    pushGPIOConfigInstAll(inst, modInstances, pinmuxCondition, resourceName, pinName, pinDisplayName, direction, false, true, "Analog",false);
}

function getGPIOGroupConfig(){
    return [
        {
            name: "GROUP_PINMUX_PERIPH",
            displayName: "Pin Configuration",
            description: "",
            longDescription: "",
            collapsed: true,
            config: []
        },
    ]
}

/*
 *  ======== hasWakeupLogic ========
 *  Check if selected device support GPIO wakeup logic configuration.
 *  M0C does not support this.
 *
 *  @return boolean value answer
 *
 */
function hasWakeupLogic(){
    if(isDeviceM0C()){
        return false;
    }
    return true;

}

function getGPIOConfigBoardC(inst){
    let returnString = "";
    let initIOMux = "";
    // consolidate information from the different GPIOs that should come together
    let pinMod = system.modules["/ti/driverlib/gpio/GPIOPinGeneric"];
    let pinstances = [];
    if(pinMod){
        pinstances = pinMod.$instances;
    }

    let pinGroups = { GPIOA: { Outs: [], Ins: [] }, GPIOB: { Outs: [], Ins: [] } };
    for(let pinst of pinstances) {
        if(pinst.$ownedBy.$name == inst.$name){
            /* For Analog peripherals, only generate code for internal resistor */
            if(pinst.passedPeripheralType == "Analog"){
                if(pinst.enableConfig){
                    returnString += "\n\t"+"DL_GPIO_set"+pinst.passedPeripheralType+"InternalResistor("+pinst.passedPinName+", DL_GPIO_RESISTOR_" + pinst.internalResistor+");"
                }
                else{
                    /* Verify special case of SWD pins */
                    try{
                        if(["PA19","PA20"].includes(inst.peripheral[pinst.passedResourceName].$solution.devicePinName)){
                            returnString += "\n\t"+"DL_GPIO_set"+pinst.passedPeripheralType+"InternalResistor("+pinst.passedPinName+", DL_GPIO_RESISTOR_NONE);"
                        }
                    }catch (e) {
                        // do nothing
                    }
                }
            }
            /* For digital peripherals, generated code depends on options configured */
            else{
                try{
                    /* Verify special case of SWD pins */
                    if(!(pinst.enableConfig && pinst.internalResistor != "NONE")){
                        /* Special case for TIMERFault */
                        if(inst.peripheral === undefined){
                            if(["PA19","PA20"].includes(inst[pinst.passedResourceName].$solution.devicePinName)){
                                returnString += "\n\t"+"DL_GPIO_set"+pinst.passedPeripheralType+"InternalResistor("+pinst.passedPinName+", DL_GPIO_RESISTOR_NONE);"
                            }
                        }
                        else if(["PA19","PA20"].includes(inst.peripheral[pinst.passedResourceName].$solution.devicePinName)){
                            returnString += "\n\t"+"DL_GPIO_set"+pinst.passedPeripheralType+"InternalResistor("+pinst.passedPinName+", DL_GPIO_RESISTOR_NONE);"
                        }
                    }
                }catch (e) {
                    // do nothing
                }
                if(pinst.enableConfig){
                    let ioMuxName = pinst.passedPinName;
                    try{
                        let port = "GPIOA";
                        if(inst.$module.$name == "/ti/driverlib/TIMERFault"){
                            port = getGPIOPort(inst[pinst.passedResourceName].$solution.devicePinName);
                        }
                        else{
                            port = getGPIOPort(inst.peripheral[pinst.passedResourceName].$solution.devicePinName);
                        }
                        // pin specific stuff
                        if(pinst.direction == "OUTPUT") {
                            /* Special case: output inversion default to false if disabled */
                            let outputInvert = ((pinst.invert == "ENABLE") && !pinst.hideOutputInversion) ? "ENABLE" : "DISABLE";
                            if(outputInvert === "ENABLE" || pinst.driveStrength === "HIGH" ||
                            pinst.hiZ === "ENABLE" || pinst.internalResistor !== "NONE")
                            {
                                initIOMux = "DL_GPIO_initPeripheralOutputFunctionFeatures("+
                                "\n\t\t "+ioMuxName +", "+ioMuxName+"_FUNC"+
                                ",\n\t\t DL_GPIO_INVERSION_" + outputInvert +
                                ", DL_GPIO_RESISTOR_" + pinst.internalResistor +
                                ",\n\t\t DL_GPIO_DRIVE_STRENGTH_" + pinst.driveStrength +
                                ", DL_GPIO_HIZ_" + pinst.hiZ + ");";
                            } else {
                                initIOMux = "DL_GPIO_initPeripheralOutputFunction("+
                                "\n\t\t "+ioMuxName +", "+ioMuxName+"_FUNC);";
                            }
                        } else {
                            // input
                            if((pinst.wakeupLogic === "DISABLE" || !hasWakeupLogic()) && pinst.internalResistor === "NONE" &&
                                pinst.hysteresisControl === "DISABLE" && pinst.invert === "DISABLE"){
                                    initIOMux = "DL_GPIO_initPeripheralInputFunction("+
                                    "\n\t\t "+ioMuxName +", "+ioMuxName+"_FUNC);";
                            } else {
                                initIOMux = "DL_GPIO_initPeripheralInputFunctionFeatures("+
                                "\n\t\t "+ioMuxName +", "+ioMuxName+"_FUNC"+
                                    ",\n\t\t DL_GPIO_INVERSION_" + pinst.invert +
                                    ", DL_GPIO_RESISTOR_" + pinst.internalResistor +
                                    ",\n\t\t DL_GPIO_HYSTERESIS_" + pinst.hysteresisControl +
                                    ", DL_GPIO_WAKEUP_" + ((hasWakeupLogic())?pinst.wakeupLogic:"DISABLE") + ");";
                            }
                        }
                        // create pin groups for lower/upper functions
                        if (pinst.direction === "OUTPUT") {
                            pinGroups[port].Outs.push(pinst);
                        } else {
                            pinGroups[port].Ins.push(pinst);
                        }
                    }catch (e) {
                        // do nothing
                    }

                    returnString +=  "\n\t"+initIOMux;


                } // if(pinst.enableConfig)
            }
        } // if(pin.$ownedBy.$name == inst.$name)

    } // for let pin in pinstances
 return returnString;
}

 /*
 * Create a formatted array where array values are separated by commas, and
 * each line of the array contains "X" number of elements per line.
 *
 * values: An array of values that should be formatted
 * numElemPerLine: The number of array elements per line
 * nestingLevel: The nesting level of the array. For example, if nesting level
 * is 1, that means there are 4 spaces preceding each line of the array.
 */
function createFormattedArray(values, numElemPerLine, nestingLevel)
{
    let index = 0;
    let formattedArrayStr = ``;

    for (let val of values)
    {
        /* Don't add a newline before the first line of the array */
        if ((index != 0) && (index % numElemPerLine == 0))
        {
            formattedArrayStr += "\n";

            /* Apply the nesting at the start of each new line of the array */
            for (let idx = 0; idx < nestingLevel * 4; idx++)
            {
                formattedArrayStr += " ";
            }
        }

        if (index == (values.length - 1))
        {
            /* The very last array element should just end (no comma) */
            formattedArrayStr += val;
        }
        else if ((index + 1) % numElemPerLine == 0)
        {
            /*
             * The last element of each array line should end with a comma to
             * avoid trailing whitespace at the end of lines
             */
            formattedArrayStr += (val + ",");
        }
        else
        {
            /* Otherwise values should be separated with a comma and space */
            formattedArrayStr += (val + ", ");
        }

        index++;
    }

    return formattedArrayStr;
}

/*
 *  ======== getBUSCLKFreq ========
 *  Get the BUSCLK frequency based on peripheral power domain
 *
 *  @param inst The peripheral instance
 *  @param peripheralName the peripheral name used for the device data interface
 *
 *  @return the BUSCLK frequency based on power domain ( 0 = ULPCLK, 1 = MCLK )
 *
 */
function getBUSCLKFreq(inst, peripheralName){
    // Default Bus Clock Frequency to MCLK Frequency
    let busclkFreq = system.modules["/ti/driverlib/SYSCTL"].$static.MCLK_Freq;
    let powerDomain = "";
    // Get Power Domain of selected peripheral via device data
    try{
        let peripheralIndex = system.deviceData.interfaces[peripheralName].peripherals.findIndex(object => { return object.name === inst.peripheral.$solution.peripheralName });
        powerDomain = system.deviceData.interfaces[peripheralName].peripherals[peripheralIndex].attributes.power_domain;
    }catch (e) {
        // do nothing
    }
    // Power Domain 0 - ULPCLK
    if(powerDomain == "PD_ULP_AON"){
        busclkFreq = system.modules["/ti/driverlib/SYSCTL"].$static.ULPCLK_Freq;
    }
    // Power Domain 1 - MCLK
    else if(powerDomain == "PD_ULP_AAON"){
        busclkFreq = system.modules["/ti/driverlib/SYSCTL"].$static.MCLK_Freq;
    }
    return busclkFreq;
}

/*
 *  ======== getModuleKeys ========
 *  Get organized list of used peripheral modules
 *
 * @return list of names of enabled modules
 *         (Example: ["ti/driverlib/OPA", "ti/driverlib/UART"])
 */
function getModuleKeys(){
    let keys = [];
    let board = system.modules["/ti/driverlib/Board"].$static;
    if(board){
        let priority = 0;
        let proposedKey = board["InitPriority"+priority];
        while(proposedKey !== undefined){
            if(system.modules[proposedKey] && proposedKey)
            {
                keys.push(proposedKey);
            }
            priority++;
            proposedKey = board["InitPriority"+priority];
        }
    }
    return keys
}

/*
 *  ======== getusedPins ========
 *  Gets a list of all the pins currently being used by active SysConfig modules
 *
 *  @param keys list of names of enabled peripheral modules
 *              (Example:["ti/driverlib/OPA", "ti/driverlib/UART"])
 *
 *  @return object with usedPinNames and usedPinIDs parameters.
 *          pin names in the format of "PA1" and pin IDs being
 *          the device pin number
 *
 */
function getUsedPins(keys){
    let usedPinNames = [];
    let usedPinIDs = [];
    let allPins = system.deviceData.devicePins;
    /* Special Case of GPIO module pins, get used pins */
    if(keys.includes("/ti/driverlib/GPIO")){
        if(system.modules["/ti/driverlib/gpio/GPIOPin"].$instances){
            for(let currentInstance of system.modules["/ti/driverlib/gpio/GPIOPin"].$instances){
                usedPinNames.push(currentInstance.pin.$solution.devicePinName);
                usedPinIDs.push(currentInstance.pin.$solution.packagePinName);
            }
        }
    }
    /* Special Case of TimerFault module, get used pins */
    if(hasTimerA()){
        try{
            if(system.modules["/ti/driverlib/TIMERFault"].$instances){
                for(let currentInstance of system.modules["/ti/driverlib/TIMERFault"].$instances){
                    if(system.modules["/ti/driverlib/TIMERFault"].pinmuxRequirements){
                        if(system.modules["/ti/driverlib/TIMERFault"].pinmuxRequirements(currentInstance)){
                            for(let currentResource of system.modules["/ti/driverlib/TIMERFault"].pinmuxRequirements(currentInstance)){
                                usedPinNames.push(currentInstance[currentResource.name].$solution.devicePinName);
                                usedPinIDs.push(currentInstance[currentResource.name].$solution.packagePinName);
                            }
                        }
                    }
                }
            }
        }catch (e) {
            // do nothing
        }
    }

    for(let currentModule of keys){
        /* Special Case: Tamper IO pin filtering - only for MSPM0L122X_L222X family */
        if(currentModule == "/ti/driverlib/TAMPERIO"){
            try{
                if(system.modules[currentModule].moduleStatic.pinmuxRequirements){
                    if(system.modules[currentModule].moduleStatic.pinmuxRequirements(system.modules[currentModule].$static)){
                        for(let currentResource of system.modules[currentModule].moduleStatic.pinmuxRequirements(system.modules[currentModule].$static)){
                            if(currentResource.interfaceName !== "LFSS"){
                                usedPinNames.push(system.modules[currentModule].$static[currentResource.name].$solution.devicePinName);
                                usedPinIDs.push(system.modules[currentModule].$static[currentResource.name].$solution.packagePinName);
                            }
                        }
                    }
                }
            }catch (e) {
                // do nothing
            }
        }
        /* Get used pins from static modules */
        else if(system.modules[currentModule].moduleStatic){
            if(system.modules[currentModule].moduleStatic.pinmuxRequirements){
                if(system.modules[currentModule].moduleStatic.pinmuxRequirements(system.modules[currentModule].$static)[0]){
                    for(let currentResource of system.modules[currentModule].moduleStatic.pinmuxRequirements(system.modules[currentModule].$static)[0].resources){
                        usedPinNames.push(system.modules[currentModule].$static.peripheral[currentResource.name].$solution.devicePinName);
                        usedPinIDs.push(system.modules[currentModule].$static.peripheral[currentResource.name].$solution.packagePinName);
                    }
                }
            }
        }
        /* Get used pins from non-static modules */
        else if(system.modules[currentModule].$instances){
            for(let currentInstance of system.modules[currentModule].$instances){
                if(system.modules[currentModule].pinmuxRequirements){
                    if(system.modules[currentModule].pinmuxRequirements(currentInstance)[0]){
                        for(let currentResource of system.modules[currentModule].pinmuxRequirements(currentInstance)[0].resources){
                            usedPinNames.push(currentInstance.peripheral[currentResource.name].$solution.devicePinName);
                            usedPinIDs.push(currentInstance.peripheral[currentResource.name].$solution.packagePinName);
                        }
                    }
                }
            }
        }

    }
    /* Special Case of Board module, get used pins */
    if(system.modules["/ti/driverlib/Board"].moduleStatic){
        for(let currentResource of system.modules["/ti/driverlib/Board"].moduleStatic.pinmuxRequirements(system.modules["/ti/driverlib/Board"].$static)[0].resources){
            usedPinNames.push(system.modules["/ti/driverlib/Board"].$static.peripheral[currentResource.name].$solution.devicePinName);
            usedPinIDs.push(system.modules["/ti/driverlib/Board"].$static.peripheral[currentResource.name].$solution.packagePinName);
        }
    }
    /* Special Case of Clock Tree Pins */
    if(system.modules["/ti/driverlib/SYSCTL"]){
        if(system.modules["/ti/driverlib/SYSCTL"].moduleStatic){
            // Clock Tree enabled
            if(system.modules["/ti/driverlib/SYSCTL"].$static.clockTreeEn){

                /* Get used pins from Clock Tree pinFunction */
                if(system.modules["/ti/clockTree/pinFunction.js"].$instances){
                    for(let currentInstance of system.modules["/ti/clockTree/pinFunction.js"].$instances){
                        if(system.modules["/ti/clockTree/pinFunction.js"].pinmuxRequirements){
                            if(system.modules["/ti/clockTree/pinFunction.js"].pinmuxRequirements(currentInstance)[0]){
                                for(let currentResource of system.modules["/ti/clockTree/pinFunction.js"].pinmuxRequirements(currentInstance)[0].resources){
                                    usedPinNames.push(currentInstance.peripheral[currentResource.name].$solution.devicePinName);
                                    usedPinIDs.push(currentInstance.peripheral[currentResource.name].$solution.packagePinName);
                                }
                            }
                        }
                    }
                }

                /* Get used pins from Clock Tree oscillator */
                if(system.modules["/ti/clockTree/oscillator.js"].$instances){
                    for(let currentInstance of system.modules["/ti/clockTree/oscillator.js"].$instances){
                        if(system.modules["/ti/clockTree/oscillator.js"].pinmuxRequirements){
                            if(system.modules["/ti/clockTree/oscillator.js"].pinmuxRequirements(currentInstance)[0]){
                                for(let currentResource of system.modules["/ti/clockTree/oscillator.js"].pinmuxRequirements(currentInstance)[0].resources){
                                    usedPinNames.push(currentInstance.peripheral[currentResource.name].$solution.devicePinName);
                                    usedPinIDs.push(currentInstance.peripheral[currentResource.name].$solution.packagePinName);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return {
        usedPinNames: usedPinNames,
        usedPinIDs  : usedPinIDs,
    }
}

/*
 *  ======== getTimerPWMInstance ========
 *  Gets the PWM instance that is assigned to a specific timer peripheral (if it
 *  exists).
 *
 *  @param timerPeripheral the timer peripheral to search for (example: "TIMA0")
 *
 *  @return the desired instance if it exists, undefined otherwise.
 *
 */
function getTimerPWMInstance(timerPeripheral){
    let PWMMod = system.modules["/ti/driverlib/PWM"];
    let index = -1;
    if(PWMMod){
        index = (PWMMod.$instances).findIndex((instance)=> instance.peripheral.$solution.peripheralName == timerPeripheral);
    };
    if(index==-1){
        return undefined;
    }
    return PWMMod.$instances[index];
}
