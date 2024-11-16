let Common = system.getScript("/ti/driverlib/Common.js");

let DMA_TRIGGERS = {
    MSPM0G1X0X_G3X0X: {
        "SW"    : ["DMA_SOFTWARE_TRIG"],
        "FSUB_0": ["DMA_GENERIC_SUB0_TRIG"],
        "FSUB_1": ["DMA_GENERIC_SUB1_TRIG"],
        "AES"   : ["DMA_AES_AES_0_TRIG", "DMA_AES_AES_1_TRIG", "DMA_AES_AES_2_TRIG"],
        "DAC0"  : ["DMA_DAC0_EVT_BD_1_TRIG"],
        "I2C0"  : ["DMA_I2C0_TX_TRIG", "DMA_I2C0_RX_TRIG"],
        "I2C1"  : ["DMA_I2C1_TX_TRIG", "DMA_I2C1_RX_TRIG"],
        "SPI0"  : ["DMA_SPI0_RX_TRIG", "DMA_SPI0_TX_TRIG"],
        "SPI1"  : ["DMA_SPI1_RX_TRIG", "DMA_SPI1_TX_TRIG"],
        "UART3" : ["DMA_UART3_RX_TRIG", "DMA_UART3_TX_TRIG"],
        "UART0" : ["DMA_UART0_RX_TRIG", "DMA_UART0_TX_TRIG"],
        "UART1" : ["DMA_UART1_RX_TRIG", "DMA_UART1_TX_TRIG"],
        "UART2" : ["DMA_UART2_RX_TRIG", "DMA_UART2_TX_TRIG"],
        "ADC0"  : ["DMA_ADC0_EVT_GEN_BD_TRIG"],
        "ADC1"  : ["DMA_ADC1_EVT_GEN_BD_TRIG"]
    },
    MSPM0L11XX_L13XX: {
        "SW"    : ["DMA_SOFTWARE_TRIG"],
        "FSUB_0": ["DMA_GENERIC_SUB0_TRIG"],
        "FSUB_1": ["DMA_GENERIC_SUB1_TRIG"],
        "ADC0"  : ["DMA_ADC0_EVT_GEN_BD_TRIG"],
        "I2C0"  : ["DMA_I2C0_TX_TRIG", "DMA_I2C0_RX_TRIG"],
        "I2C1"  : ["DMA_I2C1_TX_TRIG", "DMA_I2C1_RX_TRIG"],
        "SPI0"  : ["DMA_SPI0_RX_TRIG", "DMA_SPI0_TX_TRIG"],
        "UART0" : ["DMA_UART0_RX_TRIG", "DMA_UART0_TX_TRIG"],
        "UART1" : ["DMA_UART1_RX_TRIG", "DMA_UART1_TX_TRIG"],
    },
    MSPM0L122X_L222X: {
        "SW"    : ["DMA_SOFTWARE_TRIG"],
        "FSUB_0": ["DMA_GENERIC_SUB0_TRIG"],
        "FSUB_1": ["DMA_GENERIC_SUB1_TRIG"],
        "AES"   : ["DMA_AESADV_AES_0_TRIG", "DMA_AESADV_AES_1_TRIG"],
        "ADC0"  : ["DMA_ADC0_EVT_GEN_BD_TRIG"],
        "I2C0"  : ["DMA_I2C0_TX_TRIG", "DMA_I2C0_RX_TRIG"],
        "I2C1"  : ["DMA_I2C1_TX_TRIG", "DMA_I2C1_RX_TRIG"],
        "I2C2"  : ["DMA_I2C2_TX_TRIG", "DMA_I2C2_RX_TRIG"],
        "SPI0"  : ["DMA_SPI0_RX_TRIG", "DMA_SPI0_TX_TRIG"],
        "SPI1"  : ["DMA_SPI1_RX_TRIG", "DMA_SPI1_TX_TRIG"],
        "UART0" : ["DMA_UART0_RX_TRIG", "DMA_UART0_TX_TRIG"],
        "UART1" : ["DMA_UART1_RX_TRIG", "DMA_UART1_TX_TRIG"],
        "UART2" : ["DMA_UART2_RX_TRIG", "DMA_UART2_TX_TRIG"],
        "UART3" : ["DMA_UART3_RX_TRIG", "DMA_UART3_TX_TRIG"],
        "UART4" : ["DMA_UART4_RX_TRIG", "DMA_UART4_TX_TRIG"],
    },
    MSPM0C110X: {
        "SW"    : ["DMA_SOFTWARE_TRIG"],
        "FSUB_0": ["DMA_GENERIC_SUB0_TRIG"],
        "FSUB_1": ["DMA_GENERIC_SUB1_TRIG"],
        "ADC0"  : ["DMA_ADC0_EVT_GEN_BD_TRIG"],
    },
    MSPM0GX51X: {
        "SW"    : ["DMA_SOFTWARE_TRIG"],
        "FSUB_0": ["DMA_GENERIC_SUB0_TRIG"],
        "FSUB_1": ["DMA_GENERIC_SUB1_TRIG"],
        "AES"   : ["DMA_AESADV_AES_0_TRIG", "DMA_AESADV_AES_1_TRIG"],
        "DAC0"  : ["DMA_DAC0_EVT_BD_1_TRIG"],
        "I2C0"  : ["DMA_I2C0_TX_TRIG", "DMA_I2C0_RX_TRIG"],
        "I2C1"  : ["DMA_I2C1_TX_TRIG", "DMA_I2C1_RX_TRIG"],
        "I2C2"  : ["DMA_I2C2_TX_TRIG", "DMA_I2C2_RX_TRIG"],
        "SPI0"  : ["DMA_SPI0_RX_TRIG", "DMA_SPI0_TX_TRIG"],
        "SPI1"  : ["DMA_SPI1_RX_TRIG", "DMA_SPI1_TX_TRIG"],
        "SPI2"  : ["DMA_SPI2_RX_TRIG", "DMA_SPI2_TX_TRIG"],
        "UART3" : ["DMA_UART3_RX_TRIG", "DMA_UART3_TX_TRIG"],
        "UART4" : ["DMA_UART4_RX_TRIG", "DMA_UART4_TX_TRIG"],
        "UART5" : ["DMA_UART5_RX_TRIG", "DMA_UART5_TX_TRIG"],
        "UART6" : ["DMA_UART6_RX_TRIG", "DMA_UART6_TX_TRIG"],
        "UART7" : ["DMA_UART7_RX_TRIG", "DMA_UART7_TX_TRIG"],
        "UART0" : ["DMA_UART0_RX_TRIG", "DMA_UART0_TX_TRIG"],
        "UART1" : ["DMA_UART1_RX_TRIG", "DMA_UART1_TX_TRIG"],
        "ADC0"  : ["DMA_ADC0_EVT_GEN_BD_TRIG"],
        "ADC1"  : ["DMA_ADC1_EVT_GEN_BD_TRIG"]
    },
};

let index = Common.getDeviceFamily();

exports = {
    dma_triggers: DMA_TRIGGERS[index]
}
