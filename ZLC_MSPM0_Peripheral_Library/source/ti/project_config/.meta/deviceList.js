let Common = system.getScript("/ti/driverlib/Common.js");

const gpns = {
    "MSPM0G1X0X_G3X0X": [
        { name: "MSPM0G1105"},
        { name: "MSPM0G1106"},
        { name: "MSPM0G1107"},
        { name: "MSPM0G1505"},
        { name: "MSPM0G1506"},
        { name: "MSPM0G1507"},
        { name: "MSPM0G3105"},
        { name: "MSPM0G3106"},
        { name: "MSPM0G3107"},
        { name: "MSPM0G3505"},
        { name: "MSPM0G3506"},
        { name: "MSPM0G3507"},
        { name: "MSPM0G3519"},
    ],
    "MSPM0L11XX_L13XX": [
        { name: "MSPM0L1105"},
        { name: "MSPM0L1106"},
        { name: "MSPM0L1303"},
        { name: "MSPM0L1304"},
        { name: "MSPM0L1305"},
        { name: "MSPM0L1306"},
        { name: "MSPM0L1343"},
        { name: "MSPM0L1344"},
        { name: "MSPM0L1345"},
        { name: "MSPM0L1346"},
    ],
    "MSPM0L122X_L222X": [
        { name: "MSPM0L1226"},
        { name: "MSPM0L1227"},
        { name: "MSPM0L1228"},
        { name: "MSPM0L2226"},
        { name: "MSPM0L2227"},
        { name: "MSPM0L2228"},
    ],
    "MSPM0C110X": [
        { name: "MSPM0C1103"},
        { name: "MSPM0C1104"},
        { name: "MSPS003F3"},
        { name: "MSPS003F4"},
    ],
    "MSPM0GX51X": [
        { name: "MSPM0G3518"},
        { name: "MSPM0G3519"},
        { name: "MSPM0G1518"},
        { name: "MSPM0G1519"},
    ],
}

const GPNOptionsPerDevice = {
    "MSPM0G110X": [
        { name: "MSPM0G1105"},
        { name: "MSPM0G1106"},
        { name: "MSPM0G1107"},
    ],
    "MSPM0G150X": [
        { name: "MSPM0G1505"},
        { name: "MSPM0G1506"},
        { name: "MSPM0G1507"},
    ],
    "MSPM0G310X": [
        { name: "MSPM0G3105"},
        { name: "MSPM0G3106"},
        { name: "MSPM0G3107"},
    ],
    "MSPM0G350X": [
        { name: "MSPM0G3505"},
        { name: "MSPM0G3506"},
        { name: "MSPM0G3507"},
    ],
    "MSPM0L110X": [
        { name: "MSPM0L1105"},
        { name: "MSPM0L1106"},
    ],
    "MSPM0L130X": [
        { name: "MSPM0L1303"},
        { name: "MSPM0L1304"},
        { name: "MSPM0L1305"},
        { name: "MSPM0L1306"},
    ],
    "MSPM0L134X": [
        { name: "MSPM0L1343"},
        { name: "MSPM0L1344"},
        { name: "MSPM0L1345"},
        { name: "MSPM0L1346"},
    ],
    "MSPM0L122X": [
        { name: "MSPM0L1226"},
        { name: "MSPM0L1227"},
        { name: "MSPM0L1228"},
    ],
    "MSPM0L222X": [
        { name: "MSPM0L2226"},
        { name: "MSPM0L2227"},
        { name: "MSPM0L2228"},
    ],
    "MSPM0C110X": [
        { name: "MSPM0C1103"},
        { name: "MSPM0C1104"},
    ],
    // TODO: this can likely be improved in presentation
    "MSPS003FX": [
        { name: "MSPS003F3"},
        { name: "MSPS003F4"},
    ],
    "MSPM0G351X": [
        { name: "MSPM0G3518"},
        { name: "MSPM0G3519"},
    ],
    "MSPM0G151X": [
        { name: "MSPM0G1518"},
        { name: "MSPM0G1519"},
    ],

};

let index = Common.getDeviceFamily();

exports = {
    gpnOptions : GPNOptionsPerDevice[system.deviceData.device],
}
