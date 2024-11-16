let config = [
    {
        name: "initVal",
        displayName: "Initial Value",
        default: "LOW",
        options: [
            { name: "LOW", displayName: "Low" },
            { name: "HIGH", displayName: "High" },
        ]
    },
    {
        name: "ccValue",
        displayName: "Counter Compare Value",
        isInteger: true,
        default: 0,
    },
    {
        name: "dutyCycle",
        displayName: "Desired Duty Cycle (%)",
        default: 0.0,
        description: "Duty Cycle is the Percent Time spent high of the PWM (from 0 to 100)",
        range: [0.0, 100.0],
        onChange: updateCCValue
    },
    {
        name: "actualDutyCycle",
        displayName: "Actual Duty Cycle (%)",
        description: "Actual Duty Cycle that will be present based on clock and nearest Compare Value",
        longDescription: `Since the Compare value loaded into the register must be finite, there is a limit to the precision that can
        be achieved. Therefore, the duty cycle based on the input frequency and the counter compare value used is given below, and may differ from the desired duty cycle.
        \n Smaller deviations can be achieved by having a larger TimerCount value`,
        default: 0.0,
        getValue: (inst) => {
            let value = 0.0;
            let period = 0;
            if(inst.passedPwmMode == "EDGE_ALIGN"){
                period = inst.passedCount + 1;
                value = (1 - ((inst.ccValue + 1) / (inst.passedCount + 1))) * 100;
            }else if(inst.passedPwmMode == "EDGE_ALIGN_UP"){
                period = inst.passedCount + 1;
                value = (((inst.ccValue + 1) / (inst.passedCount + 1))) * 100;
            }  else {
                /* here it's the count times 2 */
                if(inst.passedCount != 0) {
                    value = (1 - ((inst.ccValue * 2) / inst.passedCount)) * 100;
                } else {
                    value = 0.0;
                }
            }
            return value;
        }
    },
    {
        name: "passedCount",
        default: 0,
        hidden: true,
        onChange: updateCCValue
    },
    {
        name: "passedPwmMode",
        default: "EDGE_ALIGN",
        hidden: true,
        onChange: updateCCValue
    },
    {
        name: "invert",
        displayName: "Invert Channel",
        default: false,
    },
    {
        name: "shadowUpdateMode",
        displayName: "Channel Update Mode",
        default: "IMMEDIATE",
        options: [
            { name: "IMMEDIATE", displayName: "Capture Compare value has immediate effect" },
            { name: "ZERO_EVT", displayName: "Capture Compare value has effect one TIMCLK cycle after timer counter reaches 0" },
            { name: "COMP_DN_EVT", displayName: "Capture Compare value has effect one TIMCLK cycle after timer counter reaches Capture Compare value in down counting mode" },
            { name: "COMP_UP_EVT", displayName: "Capture Compare value has effect one TIMCLK cycle after timer counter reaches Capture Compare value in up counting mode" },
            { name: "ZERO_OR_LOAD_EVT", displayName: "Capture Compare value has effect one TIMCLK cycle after timer counter reaches 0 or in a LOAD event" },
            { name: "ZERO_RC_EVT", displayName: "Capture Compare value has effect one TIMCLK cycle after timer counter reaches 0 and repeat count is also 0" },
            { name: "TRIG_EVT", displayName: "Capture Compare value has effect one TIMCLK cycle after timer trigger event" },
        ]
    }
    /*
    {
        name: "outputSource",
        displayName: "Output Source",
        default: "DEAD_BAND",
        options: [
            { name: "FUNCVAL" },
            { name: "LOAD" },
            { name: "CMPVAL" },
            { name: "ZERO" },
            { name: "DEAD_BAND" },
        ]
    },
    */
];

/* Update the Capture Compare Value
 */
function updateCCValue(inst, ui){
    let proposedccValue = 0;
    let period = 0;
    if(inst.passedPwmMode == "EDGE_ALIGN"){
        period = inst.passedCount + 1;
        proposedccValue = Math.round( (100-inst.dutyCycle) * (period) / 100) - 1;
    }else if(inst.passedPwmMode == "EDGE_ALIGN_UP"){
        period = inst.passedCount + 1;
        proposedccValue = Math.round( (inst.dutyCycle) * (period) / 100) - 1;
    }else {
        /* In center aligned mode the cc value needs to be halved to configure duty cycle */
        proposedccValue = Math.round(( (100-inst.dutyCycle) * inst.passedCount / 100) / 2);
    }
    if(proposedccValue < 0){
        /* Special case where the user inputted a small duty cycle and the proposed value
        is less than 0 */
        proposedccValue = 0;
    }
    if(inst.ccValue != proposedccValue){
        inst.ccValue = proposedccValue;
    }
}

function passCCValue(inst, ui){
    inst.ccValue = inst.passedCCValue;
}

exports = {
    //update: updateCCValue,
    config: config
};
