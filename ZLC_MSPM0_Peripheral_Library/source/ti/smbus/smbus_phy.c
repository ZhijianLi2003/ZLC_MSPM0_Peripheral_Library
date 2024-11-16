/* --COPYRIGHT--,BSD
 * Copyright (c) 2023, Texas Instruments Incorporated
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
 * --/COPYRIGHT--*/

#include <stdint.h>
#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>


#include "smbus.h"
#include "smbus_nwk.h"
#include "smbus_phy.h"

void SMBus_PHY_disable(SMBus *smbus)
{
    DL_I2C_reset(smbus->phy.SMBus_Phy_i2cBase);
    DL_I2C_disablePower(smbus->phy.SMBus_Phy_i2cBase);

    smbus->ctrl.bits.phyEn = 0;      // Update control flag
}


void SMBus_PHY_targetEnable(SMBus *smbus)
{
    extern void SYSCFG_DL_SMB_I2C_init(void);

    DL_I2C_reset(smbus->phy.SMBus_Phy_i2cBase);
    DL_I2C_enablePower(smbus->phy.SMBus_Phy_i2cBase);
    delay_cycles(SMB_POWER_STARTUP_DELAY);

    /*
        This implementation uses the SysConfig initialization.
        Developers can implement a custom initialization
    */
    SYSCFG_DL_SMB_I2C_init();
    smbus->ctrl.bits.phyEn = 1;      // Set global flag
}

void SMBus_PHY_targetInit(SMBus *smbus, I2C_Regs *i2cInst)
{
    SMBus_Phy *SMBusPHY = &smbus->phy;

    smbus->phy.SMBus_Phy_i2cBase = i2cInst;     /* Set the I2C Base Address */
    smbus->ctrl.bits.swackEn = true;            /* SW ACK is enabled */
    smbus->phy.SMBus_Phy_AckPending = false;    /* Clear Ack flag */

    SMBus_PHY_disable(smbus);
    /* I2C init and enable done in SMBus_PHY_targetEnable */
    SMBus_PHY_targetEnable(smbus);
}

void SMBus_PHY_targetEnableInt(SMBus *smbus)
{

    DL_I2C_clearInterruptStatus(smbus->phy.SMBus_Phy_i2cBase,
                                DL_I2C_INTERRUPT_TARGET_PEC_RX_ERROR |
                                DL_I2C_INTERRUPT_TARGET_RXFIFO_TRIGGER |
                                DL_I2C_INTERRUPT_TARGET_START |
                                DL_I2C_INTERRUPT_TARGET_STOP |
                                DL_I2C_INTERRUPT_TARGET_TXFIFO_EMPTY |
                                DL_I2C_INTERRUPT_TIMEOUT_A);
    DL_I2C_enableInterrupt(smbus->phy.SMBus_Phy_i2cBase,
                            DL_I2C_INTERRUPT_TARGET_RXFIFO_TRIGGER |
                            DL_I2C_INTERRUPT_TARGET_START |
                            DL_I2C_INTERRUPT_TARGET_STOP |
                            DL_I2C_INTERRUPT_TARGET_TXFIFO_EMPTY |
                            DL_I2C_INTERRUPT_TIMEOUT_A);
#if (SMB_TARGET_SUPPORTS_HOST_NOTIFY == true)
    DL_I2C_clearInterruptStatus(smbus->phy.SMBus_Phy_i2cBase,
                                DL_I2C_INTERRUPT_CONTROLLER_ARBITRATION_LOST |
                                DL_I2C_INTERRUPT_CONTROLLER_NACK |
                                DL_I2C_INTERRUPT_CONTROLLER_RXFIFO_TRIGGER |
                                DL_I2C_INTERRUPT_CONTROLLER_STOP );
    DL_I2C_enableInterrupt(smbus->phy.SMBus_Phy_i2cBase,
                           DL_I2C_INTERRUPT_CONTROLLER_ARBITRATION_LOST |
                           DL_I2C_INTERRUPT_CONTROLLER_NACK |
                           DL_I2C_INTERRUPT_CONTROLLER_RXFIFO_TRIGGER |
                           DL_I2C_INTERRUPT_CONTROLLER_STOP );
#endif /* SMB_TARGET_SUPPORTS_HOST_NOTIFY*/


    /* Set global flag */
    smbus->ctrl.bits.intEn = 1;
}

void SMBus_PHY_targetDisableInt(SMBus *smbus)
{

    DL_I2C_disableInterrupt(smbus->phy.SMBus_Phy_i2cBase,
                            DL_I2C_INTERRUPT_TARGET_PEC_RX_ERROR |
                            DL_I2C_INTERRUPT_TARGET_RXFIFO_TRIGGER |
                            DL_I2C_INTERRUPT_TARGET_START |
                            DL_I2C_INTERRUPT_TARGET_STOP |
                            DL_I2C_INTERRUPT_TARGET_TXFIFO_EMPTY |
                            DL_I2C_INTERRUPT_TIMEOUT_A);
#if (SMB_TARGET_SUPPORTS_HOST_NOTIFY == true)
    DL_I2C_disableInterrupt(smbus->phy.SMBus_Phy_i2cBase,
                            DL_I2C_INTERRUPT_CONTROLLER_ARBITRATION_LOST |
                            DL_I2C_INTERRUPT_CONTROLLER_NACK |
                            DL_I2C_INTERRUPT_CONTROLLER_RXFIFO_TRIGGER |
                            DL_I2C_INTERRUPT_CONTROLLER_STOP );
#endif /* SMB_TARGET_SUPPORTS_HOST_NOTIFY*/


    /* Set global flag */
    smbus->ctrl.bits.intEn = 0;
}

SMBus_State SMBus_PHY_targetProcessInt(SMBus *smbus)
{
    SMBus_State ret_state = SMBus_State_Target_NTR;
    SMBus_Phy *SMBusPHY = &smbus->phy;
    uint8_t data, addr;
    /* Prioritized interrupts processing */
    if ( DL_I2C_getEnabledInterruptStatus(SMBusPHY->SMBus_Phy_i2cBase,
                                          DL_I2C_INTERRUPT_TARGET_STOP) )
    {
        ret_state = SMBus_NWK_targetProcessStop(smbus);
        DL_I2C_clearInterruptStatus(SMBusPHY->SMBus_Phy_i2cBase,
                                      DL_I2C_INTERRUPT_TARGET_STOP);
    }
    else if ( DL_I2C_getEnabledInterruptStatus(SMBusPHY->SMBus_Phy_i2cBase,
                                               DL_I2C_INTERRUPT_TARGET_START) )
    {
        data = (uint8_t) DL_I2C_getTargetAddressMatch(SMBusPHY->SMBus_Phy_i2cBase);
        ret_state = SMBus_NWK_targetProcessStart(smbus, data);
        DL_I2C_clearInterruptStatus(SMBusPHY->SMBus_Phy_i2cBase,
                                      DL_I2C_INTERRUPT_TARGET_START);
    }
    else
    {
        switch (DL_I2C_getPendingInterrupt(SMBusPHY->SMBus_Phy_i2cBase)) {
            /* SMBus Target Interrupts */
            case DL_I2C_IIDX_TARGET_RXFIFO_TRIGGER:
                data = DL_I2C_receiveTargetData(SMBusPHY->SMBus_Phy_i2cBase);
                ret_state = SMBus_NWK_targetProcessRx(smbus, data);
				// Check if last byte in the transfer that the PEC checked out, 
				// otherwise NACK
                if(DL_I2C_getRawInterruptStatus(SMBusPHY->SMBus_Phy_i2cBase,
                                              DL_I2C_INTERRUPT_TARGET_PEC_RX_ERROR)){

                    DL_I2C_clearInterruptStatus(SMBusPHY->SMBus_Phy_i2cBase,
                                              DL_I2C_INTERRUPT_TARGET_PEC_RX_ERROR);
                    smbus->status.bits.pecErr = 1;
                    ret_state = SMBus_State_PECError;
                }
                smbus->phy.SMBus_Phy_AckPending = true;
            break;
            case DL_I2C_IIDX_TARGET_START:
                /* Handled with higher priority */
            break;
            case DL_I2C_IIDX_TARGET_STOP:
                /* Handled with higher priority */
            break;
            case DL_I2C_IIDX_TARGET_TXFIFO_EMPTY:
                ret_state = SMBus_NWK_targetProcessTx(smbus, &data);
                DL_I2C_fillTargetTXFIFO(SMBusPHY->SMBus_Phy_i2cBase, &data, 1);
            break;
            case DL_I2C_IIDX_TARGET_PEC_RX_ERROR:
                smbus->status.bits.pecErr = 1;
                ret_state = SMBus_State_PECError;
            break;
            /* SMBus Timeout interrupt */
            case DL_I2C_IIDX_TIMEOUT_A:
                ret_state = SMBus_NWK_targetProcessTimeout(smbus);
            break;
#if (SMB_TARGET_SUPPORTS_HOST_NOTIFY == true)
            /* SMBus Controller interrupts as target */
            case DL_I2C_IIDX_CONTROLLER_TX_DONE:
                SMBus_NWK_controllerTxDone(smbus);
            break;
            case DL_I2C_IIDX_CONTROLLER_TXFIFO_TRIGGER:
                /*
                 * TXIFG0 is set when the TX buffer is empty and we need to send
                 *  data to target
                 */
                ret_state = SMBus_NWK_controllerProcessTx(smbus, &data);
                // Send the data
                DL_I2C_fillControllerTXFIFO(SMBusPHY->SMBus_Phy_i2cBase, &data, 1);
            break;
            case DL_I2C_IIDX_CONTROLLER_NACK:
                ret_state = SMBus_NWK_controllerProcessNACK(smbus);
            break;
            case DL_I2C_IIDX_CONTROLLER_STOP:
                ret_state = SMBus_NWK_controllerProcessStop(smbus);
            break;
#endif /* SMB_TARGET_SUPPORTS_HOST_NOTIFY */
            default:
                break;

        }
    }
    return(ret_state);
}

void SMBus_PHY_targetSetPECCount(SMBus * smbus, uint16_t length){
    DL_I2C_setTargetPECCountValue(smbus->phy.SMBus_Phy_i2cBase, (uint32_t) 0x00000000 | length);
}

void SMBus_PHY_targetManualACK(SMBus *smbus, bool ackVal)
{
    if (ackVal == true)
    {
        DL_I2C_setTargetACKOverrideValue(smbus->phy.SMBus_Phy_i2cBase,
                                    DL_I2C_TARGET_RESPONSE_OVERRIDE_VALUE_ACK);
    }
    else
    {
        DL_I2C_setTargetACKOverrideValue(smbus->phy.SMBus_Phy_i2cBase,
                                    DL_I2C_TARGET_RESPONSE_OVERRIDE_VALUE_NACK);
    }
    smbus->phy.SMBus_Phy_AckPending = false;
}

void SMBus_PHY_controllerEnable(SMBus *smbus)
{
    extern void SYSCFG_DL_SMB_I2C_init(void);

    DL_I2C_reset(smbus->phy.SMBus_Phy_i2cBase);
    DL_I2C_enablePower(smbus->phy.SMBus_Phy_i2cBase);
    delay_cycles(SMB_POWER_STARTUP_DELAY);

    /*
        This implementation uses the SysConfig initialization.
        Developers can implement a custom initialization
    */
    SYSCFG_DL_SMB_I2C_init();

    smbus->ctrl.bits.phyEn = 1;      // Set global flag
}

void SMBus_PHY_controllerEnableInt(SMBus *smbus)
{
    DL_I2C_clearInterruptStatus(smbus->phy.SMBus_Phy_i2cBase,
                                DL_I2C_INTERRUPT_CONTROLLER_ARBITRATION_LOST |
                                DL_I2C_INTERRUPT_CONTROLLER_NACK |
                                DL_I2C_INTERRUPT_CONTROLLER_PEC_RX_ERROR |
                                DL_I2C_INTERRUPT_CONTROLLER_RXFIFO_TRIGGER |
                                DL_I2C_INTERRUPT_CONTROLLER_START |
                                DL_I2C_INTERRUPT_CONTROLLER_STOP |
                                DL_I2C_INTERRUPT_CONTROLLER_TXFIFO_TRIGGER |
                                DL_I2C_INTERRUPT_TIMEOUT_A);
    DL_I2C_enableInterrupt(smbus->phy.SMBus_Phy_i2cBase,
                            DL_I2C_INTERRUPT_CONTROLLER_ARBITRATION_LOST |
                            DL_I2C_INTERRUPT_CONTROLLER_NACK |
                            DL_I2C_INTERRUPT_CONTROLLER_PEC_RX_ERROR |
                            DL_I2C_INTERRUPT_CONTROLLER_RXFIFO_TRIGGER |
                            DL_I2C_INTERRUPT_CONTROLLER_START |
                            DL_I2C_INTERRUPT_CONTROLLER_STOP |
                            DL_I2C_INTERRUPT_CONTROLLER_TXFIFO_TRIGGER |
                            DL_I2C_INTERRUPT_TIMEOUT_A);
#if (SMB_CONTROLLER_SUPPORTS_HOST_NOTIFY == true)
    DL_I2C_clearInterruptStatus(smbus->phy.SMBus_Phy_i2cBase,
                                DL_I2C_INTERRUPT_TARGET_RXFIFO_TRIGGER |
                                DL_I2C_INTERRUPT_TARGET_START |
                                DL_I2C_INTERRUPT_TARGET_STOP |
                                DL_I2C_INTERRUPT_TARGET_TXFIFO_EMPTY );
    DL_I2C_enableInterrupt(smbus->phy.SMBus_Phy_i2cBase,
                           DL_I2C_INTERRUPT_TARGET_START |
                           DL_I2C_INTERRUPT_TARGET_STOP |
                           DL_I2C_INTERRUPT_TARGET_TXFIFO_EMPTY );
#endif /* SMB_CONTROLLER_SUPPORTS_HOST_NOTIFY */


    /* Set global flag */
    smbus->ctrl.bits.intEn = 1;
}

void SMBus_PHY_controllerDisableInt(SMBus *smbus)
{
    DL_I2C_disableInterrupt(smbus->phy.SMBus_Phy_i2cBase,
                            DL_I2C_INTERRUPT_CONTROLLER_ARBITRATION_LOST |
                            DL_I2C_INTERRUPT_CONTROLLER_NACK |
                            DL_I2C_INTERRUPT_CONTROLLER_PEC_RX_ERROR |
                            DL_I2C_INTERRUPT_CONTROLLER_RXFIFO_TRIGGER |
                            DL_I2C_INTERRUPT_CONTROLLER_START |
                            DL_I2C_INTERRUPT_CONTROLLER_STOP |
                            DL_I2C_INTERRUPT_CONTROLLER_TXFIFO_TRIGGER |
                            DL_I2C_INTERRUPT_TIMEOUT_A);
#if (SMB_CONTROLLER_SUPPORTS_HOST_NOTIFY == true)
    DL_I2C_disableInterrupt(smbus->phy.SMBus_Phy_i2cBase,
                            DL_I2C_INTERRUPT_TARGET_RXFIFO_TRIGGER |
                            DL_I2C_INTERRUPT_TARGET_START |
                            DL_I2C_INTERRUPT_TARGET_STOP |
                            DL_I2C_INTERRUPT_TARGET_TXFIFO_EMPTY );
#endif /* SMB_CONTROLLER_SUPPORTS_HOST_NOTIFY */

    /* Set global flag */
    smbus->ctrl.bits.intEn = 0;
}

void SMBus_PHY_controllerInit(SMBus *smbus,
                          I2C_Regs *i2cRegs,
                          uint32_t busClk)
{
    SMBus_Phy *SMBusPHY = &smbus->phy;
    smbus->phy.SMBus_Phy_i2cBase = i2cRegs;

    // Target Address not initialized by default
    smbus->ownTargetAddr = 0;

    SMBus_PHY_disable(smbus);
    /* I2C init and enable done in SMBus_PHY_controllerEnable */
    SMBus_PHY_controllerEnable(smbus);
}

void SMBus_PHY_controllerSendStop(SMBus *smbus)
{
        DL_I2C_startControllerTransferAdvanced(smbus->phy.SMBus_Phy_i2cBase,
                                               0x0, // This is a don't care
                                               DL_I2C_CONTROLLER_DIRECTION_TX,
                                               0,
                                               DL_I2C_CONTROLLER_START_DISABLE,
                                               DL_I2C_CONTROLLER_STOP_ENABLE,
                                               DL_I2C_CONTROLLER_ACK_DISABLE);
}

void SMBus_PHY_controllerStartTx(SMBus *smbus,
                             uint8_t targetaddr,
                             uint16_t length,
                             SMBus_Stop stopFlag,
                             uint8_t setPEC)

{
    uint8_t data;
    DL_I2C_CONTROLLER_STOP phy_stop;

    if (stopFlag == SMBus_Stop_After_Transfer)
    {
        phy_stop = DL_I2C_CONTROLLER_STOP_ENABLE;
        DL_I2C_disableInterrupt(smbus->phy.SMBus_Phy_i2cBase, DL_I2C_INTERRUPT_CONTROLLER_TX_DONE);
    }
    else
    {
        phy_stop = DL_I2C_CONTROLLER_STOP_DISABLE;
        DL_I2C_clearInterruptStatus(smbus->phy.SMBus_Phy_i2cBase, DL_I2C_INTERRUPT_CONTROLLER_TX_DONE);
        DL_I2C_enableInterrupt(smbus->phy.SMBus_Phy_i2cBase, DL_I2C_INTERRUPT_CONTROLLER_TX_DONE);
    }


    if (length > 0) {
      DL_I2C_disableInterrupt(smbus->phy.SMBus_Phy_i2cBase,
                             DL_I2C_INTERRUPT_CONTROLLER_TXFIFO_TRIGGER);
      DL_I2C_flushControllerTXFIFO(smbus->phy.SMBus_Phy_i2cBase);
      DL_I2C_clearInterruptStatus(smbus->phy.SMBus_Phy_i2cBase,
                                  DL_I2C_INTERRUPT_CONTROLLER_TXFIFO_TRIGGER);
      DL_I2C_enableInterrupt(smbus->phy.SMBus_Phy_i2cBase,
                            DL_I2C_INTERRUPT_CONTROLLER_TXFIFO_TRIGGER);

      SMBus_NWK_controllerProcessTx(smbus, &data);
      DL_I2C_fillControllerTXFIFO(smbus->phy.SMBus_Phy_i2cBase, &data, 1);
    }

    if (setPEC == 1 && smbus->ctrl.bits.pecEn == 1) {
        DL_I2C_setControllerPECCountValue(smbus->phy.SMBus_Phy_i2cBase, length);
    }
    else {
        DL_I2C_setControllerPECCountValue(smbus->phy.SMBus_Phy_i2cBase, 0);
    }

    DL_I2C_startControllerTransferAdvanced(smbus->phy.SMBus_Phy_i2cBase,
                                           targetaddr,
                                           DL_I2C_CONTROLLER_DIRECTION_TX,
                                           length,
                                           DL_I2C_CONTROLLER_START_ENABLE,
                                           phy_stop,
                                           DL_I2C_CONTROLLER_ACK_ENABLE);
}

void SMBus_PHY_controllerStartRx(SMBus *smbus,
                             uint8_t targetaddr,
                             uint16_t length,
                             SMBus_Start startFlag,
                             SMBus_Stop stopFlag,
                             SMBus_Auto_Ack ackFlag,
                             uint8_t setPEC)
{
    DL_I2C_CONTROLLER_START phy_start;
    DL_I2C_CONTROLLER_STOP phy_stop;
    DL_I2C_CONTROLLER_ACK phy_ack;
    uint8_t data;
    volatile uint32_t timeout = SMB_SW_TIMEOUT;

    if (startFlag == SMBus_Start_Before_Transfer)
    {
        phy_start = DL_I2C_CONTROLLER_START_ENABLE;
    }
    else
    {
        phy_start = DL_I2C_CONTROLLER_START_DISABLE;
    }

    if (stopFlag == SMBus_Stop_After_Transfer)
    {
        phy_stop = DL_I2C_CONTROLLER_STOP_ENABLE;
    }
    else
    {
        phy_stop = DL_I2C_CONTROLLER_STOP_DISABLE;
    }

    if (ackFlag == SMBus_Auto_Ack_Last_Byte)
    {
        phy_ack = DL_I2C_CONTROLLER_ACK_ENABLE;
    }
    else
    {
        phy_ack = DL_I2C_CONTROLLER_ACK_DISABLE;
    }

    if (setPEC == 1 && smbus->ctrl.bits.pecEn == 1) {
        DL_I2C_setControllerPECCountValue(smbus->phy.SMBus_Phy_i2cBase, length);
    }
    else {
        DL_I2C_setControllerPECCountValue(smbus->phy.SMBus_Phy_i2cBase, 0);
    }

    // HW will ignore new transfer requests while a transfer is active, so wait until the HW is ready + 1 delay_cycle
    // In normal operation this should just be a small region of time between when the HW has received a byte
    // and while ack is being generated.
    while (timeout &&
               ( (DL_I2C_getControllerStatus(smbus->phy.SMBus_Phy_i2cBase) |
                       DL_I2C_CONTROLLER_STATUS_BUSY) ==
                       DL_I2C_CONTROLLER_STATUS_BUSY ) )
    {
        timeout--;
    }


    DL_I2C_startControllerTransferAdvanced(smbus->phy.SMBus_Phy_i2cBase,
                                           targetaddr,
                                           DL_I2C_CONTROLLER_DIRECTION_RX,
                                           length,
                                           phy_start,
                                           phy_stop,
                                           phy_ack);

}

void SMBus_PHY_controllerEnableHostNotify(SMBus *smbus)
{
    DL_I2C_enableDefaultHostAddress(smbus->phy.SMBus_Phy_i2cBase);
}

void SMBus_PHY_controllerDisableHostNotify(SMBus *smbus)
{
    DL_I2C_disableDefaultHostAddress(smbus->phy.SMBus_Phy_i2cBase);
}


SMBus_State SMBus_PHY_controllerProcessInt(SMBus *smbus)
{
    uint8_t data;
    SMBus_State ret_state;
    SMBus_Phy *SMBusPHY = &smbus->phy;

    switch (DL_I2C_getPendingInterrupt(SMBusPHY->SMBus_Phy_i2cBase)) {
        /* SMBus Controller interrupts */
        case DL_I2C_IIDX_CONTROLLER_TX_DONE:
            SMBus_NWK_controllerTxDone(smbus);
        break;
        case DL_I2C_IIDX_CONTROLLER_RXFIFO_TRIGGER:
            data = DL_I2C_receiveControllerData(SMBusPHY->SMBus_Phy_i2cBase);
           // Pass data to NWK layer
           ret_state = SMBus_NWK_controllerProcessRx(smbus, data);
        break;
        case DL_I2C_IIDX_CONTROLLER_TXFIFO_TRIGGER:
            // TXIFG0 is set when the TX buffer is empty and we need to send data to
            // target
            ret_state = SMBus_NWK_controllerProcessTx(smbus, &data);
            // Send the data
            DL_I2C_fillControllerTXFIFO(SMBusPHY->SMBus_Phy_i2cBase, &data, 1);
        break;
        case DL_I2C_IIDX_CONTROLLER_NACK:
            ret_state = SMBus_NWK_controllerProcessNACK(smbus);
            //__BKPT(0); /* Placeholder for debugging purposes */
        break;
        case DL_I2C_IIDX_CONTROLLER_START:
            //__BKPT(0); /* Placeholder for debugging purposes */
        break;
        case DL_I2C_IIDX_CONTROLLER_STOP:
            ret_state = SMBus_NWK_controllerProcessStop(smbus);
        break;
        case DL_I2C_IIDX_CONTROLLER_ARBITRATION_LOST:
            //__BKPT(0); /* Placeholder for debugging purposes */
        break;
        /* SMBus Timeout interrupt */
        case DL_I2C_IIDX_TIMEOUT_A:
            ret_state = SMBus_NWK_controllerProcessTimeout(smbus);
        break;
#if (SMB_CONTROLLER_SUPPORTS_HOST_NOTIFY == true)
        /* SMBus Controller interrupts as target */
        case DL_I2C_IIDX_TARGET_RXFIFO_TRIGGER:
            data = DL_I2C_receiveTargetData(SMBusPHY->SMBus_Phy_i2cBase);
            ret_state = SMBus_NWK_targetProcessRx(smbus, data);
        break;
        case DL_I2C_IIDX_TARGET_START:
            data = (uint8_t) DL_I2C_getTargetAddressMatch(SMBusPHY->SMBus_Phy_i2cBase);
            ret_state = SMBus_NWK_targetProcessStart(smbus, data);
        break;
        case DL_I2C_IIDX_TARGET_STOP:
            ret_state = SMBus_NWK_targetProcessStop(smbus);
        break;
#endif  /* SMB_CONTROLLER_SUPPORTS_HOST_NOTIFY*/
        default:
        break;
    }

    return(ret_state);
}



