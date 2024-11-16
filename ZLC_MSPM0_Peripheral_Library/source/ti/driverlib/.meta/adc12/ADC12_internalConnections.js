let ADC12_internalSignals = {
    MSPM0G1X0X_G3X0X: {
        ADC0: {
            CH11: "Temperature Sensor",
            CH13: "OPA0 output",
            CH14: "GPAMP output",
            CH15: "Supply/Battery Monitor"
        },
        ADC1: {
            CH12: "Temperature Sensor",
            CH13: "OPA1 output",
            CH14: "GPAMP output",
            CH15: "Supply/Battery Monitor"
        }
    },
    MSPM0L11XX_L13XX: {
        ADC0: {
            CH11: "Temperature Sensor",
            CH12: "OPA0 output",
            CH13: "OPA1 output",
            CH14: "GPAMP output",
            CH15: "Supply/Battery Monitor"
        },
    },
    MSPM0L122X_L222X: {
        ADC0: {
            CH29: "Temperature Sensor",
            CH30: "VBAT Battery monitor",
            CH31: "Supply/Battery Monitor",
        },
    },
    MSPM0C110X: {
        ADC0: {
            CH11: "Temperature Sensor",
            CH15: "Supply Monitor"
        },
    },
    MSPM0GX51X: {
        ADC0: {
            CH11: "Temperature Sensor",
            CH15: "Supply Monitor",
        },
        ADC1: {
            CH15: "Supply Monitor",
        }
    },
}

exports = {
    ADC12_internalSignals: ADC12_internalSignals,
}
