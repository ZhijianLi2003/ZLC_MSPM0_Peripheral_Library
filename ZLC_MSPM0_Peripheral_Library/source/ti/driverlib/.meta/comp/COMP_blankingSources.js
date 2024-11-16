let Common = system.getScript("/ti/driverlib/Common.js");

let blankingSources = {
    MSPM0G1X0X_G3X0X: {
        1: {  
            peripheral: "TIMA0",
            channel: "2",
        },
        2: {  
            peripheral: "TIMA0",
            channel: "3",
        },
        3: {  
            peripheral: "TIMA1",
            channel: "1",
        },
        4: {  
            peripheral: "TIMG12",
            channel: "1",
        },
        5: {  
            peripheral: "TIMG6",
            channel: "1",
        },
        6: {  
            peripheral: "TIMG7",
            channel: "1",
        },
    },
    MSPM0L11XX_L13XX: {
        0: {  
            peripheral: "TIMG0",
            channel: "1",
        },
        1: {  
            peripheral: "TIMG1",
            channel: "1",
        },
        2: {  
            peripheral: "TIMG2",
            channel: "1",
        },
    },
    MSPM0L122X_L222X: {
        1: {  
            peripheral: "TIMA0",
            channel: "2",
        },
        2: {  
            peripheral: "TIMA0",
            channel: "3",
        },
        3: {  
            peripheral: "TIMG12",
            channel: "1",
        },
        4: {  
            peripheral: "TIMG0",
            channel: "1",
        },
        5: {  
            peripheral: "TIMG4",
            channel: "1",
        },
        6: {  
            peripheral: "TIMG5",
            channel: "1",
        },
    },
    MSPM0C110X: {
        // N/A: COMP not available for this device
    },
    MSPM0GX51X: {
        1: {  
            peripheral: "TIMA0",
            channel: "2",
        },
        2: {  
            peripheral: "TIMA0",
            channel: "3",
        },
        3: {  
            peripheral: "TIMA1",
            channel: "1",
        },
        4: {  
            peripheral: "TIMG12",
            channel: "1",
        },
        5: {  
            peripheral: "TIMG6",
            channel: "1",
        },
        6: {  
            peripheral: "TIMG7",
            channel: "1",
        },
    },
}

let index = Common.getDeviceFamily();

exports = {
    blankingSources  : blankingSources[index],
}