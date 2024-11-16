/*
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
 */

/*
 *  ============ ti_msp_dl_config.c =============
 *  Configured MSPM0 DriverLib module definitions
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */

#include "ti_msp_dl_config.h"

DL_TimerA_backupConfig gPWM_FOR_MOTORBackup;
DL_TimerA_backupConfig gPWM_FOR_SERVOBackup;
DL_TimerG_backupConfig gQEI_0Backup;
DL_SPI_backupConfig gSPI_FOR_IMUBackup;

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform any initialization needed before using any board APIs
 */
SYSCONFIG_WEAK void SYSCFG_DL_init(void)
{
    SYSCFG_DL_initPower();
    SYSCFG_DL_GPIO_init();
    /* Module-Specific Initializations*/
    SYSCFG_DL_SYSCTL_init();
    SYSCFG_DL_PWM_FOR_MOTOR_init();
    SYSCFG_DL_PWM_FOR_SERVO_init();
    SYSCFG_DL_QEI_0_init();
    SYSCFG_DL_PIT_FOR_CONTROL_init();
    SYSCFG_DL_PIT_FOR_CUSTOM_init();
    SYSCFG_DL_UART_0_init();
    SYSCFG_DL_SPI_FOR_IMU_init();
    SYSCFG_DL_SYSTICK_init();
    /* Ensure backup structures have no valid state */
	gPWM_FOR_MOTORBackup.backupRdy 	= false;
	gPWM_FOR_SERVOBackup.backupRdy 	= false;
	gQEI_0Backup.backupRdy 	= false;


	gSPI_FOR_IMUBackup.backupRdy 	= false;

}
/*
 * User should take care to save and restore register configuration in application.
 * See Retention Configuration section for more details.
 */
SYSCONFIG_WEAK bool SYSCFG_DL_saveConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerA_saveConfiguration(PWM_FOR_MOTOR_INST, &gPWM_FOR_MOTORBackup);
	retStatus &= DL_TimerA_saveConfiguration(PWM_FOR_SERVO_INST, &gPWM_FOR_SERVOBackup);
	retStatus &= DL_TimerG_saveConfiguration(QEI_0_INST, &gQEI_0Backup);
	retStatus &= DL_SPI_saveConfiguration(SPI_FOR_IMU_INST, &gSPI_FOR_IMUBackup);

    return retStatus;
}


SYSCONFIG_WEAK bool SYSCFG_DL_restoreConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerA_restoreConfiguration(PWM_FOR_MOTOR_INST, &gPWM_FOR_MOTORBackup, false);
	retStatus &= DL_TimerA_restoreConfiguration(PWM_FOR_SERVO_INST, &gPWM_FOR_SERVOBackup, false);
	retStatus &= DL_TimerG_restoreConfiguration(QEI_0_INST, &gQEI_0Backup, false);
	retStatus &= DL_SPI_restoreConfiguration(SPI_FOR_IMU_INST, &gSPI_FOR_IMUBackup);

    return retStatus;
}

SYSCONFIG_WEAK void SYSCFG_DL_initPower(void)
{
    DL_GPIO_reset(GPIOA);
    DL_GPIO_reset(GPIOB);
    DL_TimerA_reset(PWM_FOR_MOTOR_INST);
    DL_TimerA_reset(PWM_FOR_SERVO_INST);
    DL_TimerG_reset(QEI_0_INST);
    DL_TimerG_reset(PIT_FOR_CONTROL_INST);
    DL_TimerG_reset(PIT_FOR_CUSTOM_INST);
    DL_UART_Main_reset(UART_0_INST);
    DL_SPI_reset(SPI_FOR_IMU_INST);


    DL_GPIO_enablePower(GPIOA);
    DL_GPIO_enablePower(GPIOB);
    DL_TimerA_enablePower(PWM_FOR_MOTOR_INST);
    DL_TimerA_enablePower(PWM_FOR_SERVO_INST);
    DL_TimerG_enablePower(QEI_0_INST);
    DL_TimerG_enablePower(PIT_FOR_CONTROL_INST);
    DL_TimerG_enablePower(PIT_FOR_CUSTOM_INST);
    DL_UART_Main_enablePower(UART_0_INST);
    DL_SPI_enablePower(SPI_FOR_IMU_INST);

    delay_cycles(POWER_STARTUP_DELAY);
}

SYSCONFIG_WEAK void SYSCFG_DL_GPIO_init(void)
{

    DL_GPIO_initPeripheralOutputFunction(GPIO_PWM_FOR_MOTOR_C0_IOMUX,GPIO_PWM_FOR_MOTOR_C0_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_PWM_FOR_MOTOR_C0_PORT, GPIO_PWM_FOR_MOTOR_C0_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_PWM_FOR_MOTOR_C1_IOMUX,GPIO_PWM_FOR_MOTOR_C1_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_PWM_FOR_MOTOR_C1_PORT, GPIO_PWM_FOR_MOTOR_C1_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_PWM_FOR_SERVO_C0_IOMUX,GPIO_PWM_FOR_SERVO_C0_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_PWM_FOR_SERVO_C0_PORT, GPIO_PWM_FOR_SERVO_C0_PIN);

    DL_GPIO_initPeripheralInputFunction(GPIO_QEI_0_PHA_IOMUX,GPIO_QEI_0_PHA_IOMUX_FUNC);
    DL_GPIO_initPeripheralInputFunction(GPIO_QEI_0_PHB_IOMUX,GPIO_QEI_0_PHB_IOMUX_FUNC);

    DL_GPIO_initPeripheralOutputFunction(
        GPIO_UART_0_IOMUX_TX, GPIO_UART_0_IOMUX_TX_FUNC);
    DL_GPIO_initPeripheralInputFunction(
        GPIO_UART_0_IOMUX_RX, GPIO_UART_0_IOMUX_RX_FUNC);

    DL_GPIO_initPeripheralOutputFunction(
        GPIO_SPI_FOR_IMU_IOMUX_SCLK, GPIO_SPI_FOR_IMU_IOMUX_SCLK_FUNC);
    DL_GPIO_initPeripheralOutputFunction(
        GPIO_SPI_FOR_IMU_IOMUX_PICO, GPIO_SPI_FOR_IMU_IOMUX_PICO_FUNC);
    DL_GPIO_initPeripheralInputFunction(
        GPIO_SPI_FOR_IMU_IOMUX_POCI, GPIO_SPI_FOR_IMU_IOMUX_POCI_FUNC);
    DL_GPIO_initPeripheralOutputFunction(
        GPIO_SPI_FOR_IMU_IOMUX_CS0, GPIO_SPI_FOR_IMU_IOMUX_CS0_FUNC);

    DL_GPIO_initDigitalOutputFeatures(LED1_PIN_14_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);

    DL_GPIO_initDigitalOutput(SPI_FOR_IMU_CS_PIN_8_IOMUX);

    DL_GPIO_initDigitalOutput(MOTOR_DIR1_PIN_26_IOMUX);

    DL_GPIO_initDigitalOutput(MOTOR_DIR2_PIN_27_IOMUX);

    DL_GPIO_initDigitalInput(Remote_Switch_PIN_IOMUX);

    DL_GPIO_initDigitalOutput(BEEP_AND_LED_PIN_0_IOMUX);

    DL_GPIO_initDigitalInputFeatures(KEY_KEY_1_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(KEY_KEY_2_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(KEY_KEY_3_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(KEY_KEY_4_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInput(Encoder_A_IOMUX);

    DL_GPIO_initDigitalInput(Encoder_B_IOMUX);

    DL_GPIO_initDigitalInput(Encoder_C_IOMUX);

    DL_GPIO_initDigitalInput(Encoder_D_IOMUX);

    DL_GPIO_initDigitalInputFeatures(HUIDU_PIN_1_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(HUIDU_PIN_2_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(HUIDU_PIN_3_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(HUIDU_PIN_4_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(HUIDU_PIN_5_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(HUIDU_PIN_6_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(HUIDU_PIN_7_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(HUIDU_PIN_9_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_clearPins(GPIOA, LED1_PIN_14_PIN);
    DL_GPIO_setPins(GPIOA, SPI_FOR_IMU_CS_PIN_8_PIN);
    DL_GPIO_enableOutput(GPIOA, LED1_PIN_14_PIN |
		SPI_FOR_IMU_CS_PIN_8_PIN);
    DL_GPIO_setLowerPinsPolarity(GPIOA, DL_GPIO_PIN_15_EDGE_RISE |
		DL_GPIO_PIN_7_EDGE_RISE);
    DL_GPIO_setUpperPinsPolarity(GPIOA, DL_GPIO_PIN_16_EDGE_RISE |
		DL_GPIO_PIN_17_EDGE_RISE);
    DL_GPIO_clearInterruptStatus(GPIOA, Encoder_A_PIN |
		Encoder_B_PIN |
		Encoder_C_PIN |
		Encoder_D_PIN);
    DL_GPIO_enableInterrupt(GPIOA, Encoder_A_PIN |
		Encoder_B_PIN |
		Encoder_C_PIN |
		Encoder_D_PIN);
    DL_GPIO_clearPins(GPIOB, MOTOR_DIR1_PIN_26_PIN |
		MOTOR_DIR2_PIN_27_PIN |
		BEEP_AND_LED_PIN_0_PIN);
    DL_GPIO_enableOutput(GPIOB, MOTOR_DIR1_PIN_26_PIN |
		MOTOR_DIR2_PIN_27_PIN |
		BEEP_AND_LED_PIN_0_PIN);

}



SYSCONFIG_WEAK void SYSCFG_DL_SYSCTL_init(void)
{

	//Low Power Mode is configured to be SLEEP0
    DL_SYSCTL_setBORThreshold(DL_SYSCTL_BOR_THRESHOLD_LEVEL_0);

    
	DL_SYSCTL_setSYSOSCFreq(DL_SYSCTL_SYSOSC_FREQ_BASE);
	/* Set default configuration */
	DL_SYSCTL_disableHFXT();
	DL_SYSCTL_disableSYSPLL();
    DL_SYSCTL_enableMFCLK();
    /* INT_GROUP1 Priority */
    NVIC_SetPriority(GPIOA_INT_IRQn, 2);

}


/*
 * Timer clock configuration to be sourced by  / 1 (32000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   32000000 Hz = 32000000 Hz / (1 * (0 + 1))
 */
static const DL_TimerA_ClockConfig gPWM_FOR_MOTORClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_1,
    .prescale = 0U
};

static const DL_TimerA_PWMConfig gPWM_FOR_MOTORConfig = {
    .pwmMode = DL_TIMER_PWM_MODE_EDGE_ALIGN_UP,
    .period = 2133,
    .isTimerWithFourCC = true,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_PWM_FOR_MOTOR_init(void) {

    DL_TimerA_setClockConfig(
        PWM_FOR_MOTOR_INST, (DL_TimerA_ClockConfig *) &gPWM_FOR_MOTORClockConfig);

    DL_TimerA_initPWMMode(
        PWM_FOR_MOTOR_INST, (DL_TimerA_PWMConfig *) &gPWM_FOR_MOTORConfig);

    DL_TimerA_setCaptureCompareOutCtl(PWM_FOR_MOTOR_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERA_CAPTURE_COMPARE_0_INDEX);

    DL_TimerA_setCaptCompUpdateMethod(PWM_FOR_MOTOR_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERA_CAPTURE_COMPARE_0_INDEX);
    DL_TimerA_setCaptureCompareValue(PWM_FOR_MOTOR_INST, 0, DL_TIMER_CC_0_INDEX);

    DL_TimerA_setCaptureCompareOutCtl(PWM_FOR_MOTOR_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERA_CAPTURE_COMPARE_1_INDEX);

    DL_TimerA_setCaptCompUpdateMethod(PWM_FOR_MOTOR_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERA_CAPTURE_COMPARE_1_INDEX);
    DL_TimerA_setCaptureCompareValue(PWM_FOR_MOTOR_INST, 0, DL_TIMER_CC_1_INDEX);

    DL_TimerA_enableClock(PWM_FOR_MOTOR_INST);


    
    DL_TimerA_setCCPDirection(PWM_FOR_MOTOR_INST , DL_TIMER_CC0_OUTPUT | DL_TIMER_CC1_OUTPUT );


}
/*
 * Timer clock configuration to be sourced by  / 8 (4000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   1000000 Hz = 4000000 Hz / (8 * (3 + 1))
 */
static const DL_TimerA_ClockConfig gPWM_FOR_SERVOClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_8,
    .prescale = 3U
};

static const DL_TimerA_PWMConfig gPWM_FOR_SERVOConfig = {
    .pwmMode = DL_TIMER_PWM_MODE_EDGE_ALIGN_UP,
    .period = 20000,
    .isTimerWithFourCC = true,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_PWM_FOR_SERVO_init(void) {

    DL_TimerA_setClockConfig(
        PWM_FOR_SERVO_INST, (DL_TimerA_ClockConfig *) &gPWM_FOR_SERVOClockConfig);

    DL_TimerA_initPWMMode(
        PWM_FOR_SERVO_INST, (DL_TimerA_PWMConfig *) &gPWM_FOR_SERVOConfig);

    DL_TimerA_setCaptureCompareOutCtl(PWM_FOR_SERVO_INST, DL_TIMER_CC_OCTL_INIT_VAL_HIGH,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERA_CAPTURE_COMPARE_0_INDEX);

    DL_TimerA_setCaptCompUpdateMethod(PWM_FOR_SERVO_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERA_CAPTURE_COMPARE_0_INDEX);
    DL_TimerA_setCaptureCompareValue(PWM_FOR_SERVO_INST, 10, DL_TIMER_CC_0_INDEX);

    DL_TimerA_enableClock(PWM_FOR_SERVO_INST);


    
    DL_TimerA_setCCPDirection(PWM_FOR_SERVO_INST , DL_TIMER_CC0_OUTPUT );


}


static const DL_TimerG_ClockConfig gQEI_0ClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_1,
    .prescale = 0U
};


SYSCONFIG_WEAK void SYSCFG_DL_QEI_0_init(void) {

    DL_TimerG_setClockConfig(
        QEI_0_INST, (DL_TimerG_ClockConfig *) &gQEI_0ClockConfig);

    DL_TimerG_configQEI(QEI_0_INST, DL_TIMER_QEI_MODE_2_INPUT,
        DL_TIMER_CC_INPUT_INV_NOINVERT, DL_TIMER_CC_0_INDEX);
    DL_TimerG_configQEI(QEI_0_INST, DL_TIMER_QEI_MODE_2_INPUT,
        DL_TIMER_CC_INPUT_INV_NOINVERT, DL_TIMER_CC_1_INDEX);
    DL_TimerG_setLoadValue(QEI_0_INST, 65535);
    DL_TimerG_enableClock(QEI_0_INST);
    DL_TimerG_startCounter(QEI_0_INST);
}



/*
 * Timer clock configuration to be sourced by BUSCLK /  (4000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   100000 Hz = 4000000 Hz / (8 * (39 + 1))
 */
static const DL_TimerG_ClockConfig gPIT_FOR_CONTROLClockConfig = {
    .clockSel    = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_8,
    .prescale    = 39U,
};

/*
 * Timer load value (where the counter starts from) is calculated as (timerPeriod * timerClockFreq) - 1
 * PIT_FOR_CONTROL_INST_LOAD_VALUE = (20 ms * 100000 Hz) - 1
 */
static const DL_TimerG_TimerConfig gPIT_FOR_CONTROLTimerConfig = {
    .period     = PIT_FOR_CONTROL_INST_LOAD_VALUE,
    .timerMode  = DL_TIMER_TIMER_MODE_PERIODIC_UP,
    .startTimer = DL_TIMER_STOP,
};

SYSCONFIG_WEAK void SYSCFG_DL_PIT_FOR_CONTROL_init(void) {

    DL_TimerG_setClockConfig(PIT_FOR_CONTROL_INST,
        (DL_TimerG_ClockConfig *) &gPIT_FOR_CONTROLClockConfig);

    DL_TimerG_initTimerMode(PIT_FOR_CONTROL_INST,
        (DL_TimerG_TimerConfig *) &gPIT_FOR_CONTROLTimerConfig);
    DL_TimerG_enableInterrupt(PIT_FOR_CONTROL_INST , DL_TIMERG_INTERRUPT_LOAD_EVENT);
	NVIC_SetPriority(PIT_FOR_CONTROL_INST_INT_IRQN, 2);
    DL_TimerG_enableClock(PIT_FOR_CONTROL_INST);





}

/*
 * Timer clock configuration to be sourced by BUSCLK /  (4000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   4000000 Hz = 4000000 Hz / (8 * (0 + 1))
 */
static const DL_TimerG_ClockConfig gPIT_FOR_CUSTOMClockConfig = {
    .clockSel    = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_8,
    .prescale    = 0U,
};

/*
 * Timer load value (where the counter starts from) is calculated as (timerPeriod * timerClockFreq) - 1
 * PIT_FOR_CUSTOM_INST_LOAD_VALUE = (1 ms * 4000000 Hz) - 1
 */
static const DL_TimerG_TimerConfig gPIT_FOR_CUSTOMTimerConfig = {
    .period     = PIT_FOR_CUSTOM_INST_LOAD_VALUE,
    .timerMode  = DL_TIMER_TIMER_MODE_PERIODIC_UP,
    .startTimer = DL_TIMER_STOP,
};

SYSCONFIG_WEAK void SYSCFG_DL_PIT_FOR_CUSTOM_init(void) {

    DL_TimerG_setClockConfig(PIT_FOR_CUSTOM_INST,
        (DL_TimerG_ClockConfig *) &gPIT_FOR_CUSTOMClockConfig);

    DL_TimerG_initTimerMode(PIT_FOR_CUSTOM_INST,
        (DL_TimerG_TimerConfig *) &gPIT_FOR_CUSTOMTimerConfig);
    DL_TimerG_enableInterrupt(PIT_FOR_CUSTOM_INST , DL_TIMERG_INTERRUPT_LOAD_EVENT);
	NVIC_SetPriority(PIT_FOR_CUSTOM_INST_INT_IRQN, 3);
    DL_TimerG_enableClock(PIT_FOR_CUSTOM_INST);





}



static const DL_UART_Main_ClockConfig gUART_0ClockConfig = {
    .clockSel    = DL_UART_MAIN_CLOCK_MFCLK,
    .divideRatio = DL_UART_MAIN_CLOCK_DIVIDE_RATIO_1
};

static const DL_UART_Main_Config gUART_0Config = {
    .mode        = DL_UART_MAIN_MODE_NORMAL,
    .direction   = DL_UART_MAIN_DIRECTION_TX_RX,
    .flowControl = DL_UART_MAIN_FLOW_CONTROL_NONE,
    .parity      = DL_UART_MAIN_PARITY_NONE,
    .wordLength  = DL_UART_MAIN_WORD_LENGTH_8_BITS,
    .stopBits    = DL_UART_MAIN_STOP_BITS_ONE
};

SYSCONFIG_WEAK void SYSCFG_DL_UART_0_init(void)
{
    DL_UART_Main_setClockConfig(UART_0_INST, (DL_UART_Main_ClockConfig *) &gUART_0ClockConfig);

    DL_UART_Main_init(UART_0_INST, (DL_UART_Main_Config *) &gUART_0Config);
    /*
     * Configure baud rate by setting oversampling and baud rate divisors.
     *  Target baud rate: 115200
     *  Actual baud rate: 115107.91
     */
    DL_UART_Main_setOversampling(UART_0_INST, DL_UART_OVERSAMPLING_RATE_16X);
    DL_UART_Main_setBaudRateDivisor(UART_0_INST, UART_0_IBRD_4_MHZ_115200_BAUD, UART_0_FBRD_4_MHZ_115200_BAUD);


    /* Configure Interrupts */
    DL_UART_Main_enableInterrupt(UART_0_INST,
                                 DL_UART_MAIN_INTERRUPT_RX);
    /* Setting the Interrupt Priority */
    NVIC_SetPriority(UART_0_INST_INT_IRQN, 1);


    DL_UART_Main_enable(UART_0_INST);
}

static const DL_SPI_Config gSPI_FOR_IMU_config = {
    .mode        = DL_SPI_MODE_CONTROLLER,
    .frameFormat = DL_SPI_FRAME_FORMAT_MOTO4_POL0_PHA0,
    .parity      = DL_SPI_PARITY_NONE,
    .dataSize    = DL_SPI_DATA_SIZE_8,
    .bitOrder    = DL_SPI_BIT_ORDER_MSB_FIRST,
    .chipSelectPin = DL_SPI_CHIP_SELECT_0,
};

static const DL_SPI_ClockConfig gSPI_FOR_IMU_clockConfig = {
    .clockSel    = DL_SPI_CLOCK_BUSCLK,
    .divideRatio = DL_SPI_CLOCK_DIVIDE_RATIO_1
};

SYSCONFIG_WEAK void SYSCFG_DL_SPI_FOR_IMU_init(void) {
    DL_SPI_setClockConfig(SPI_FOR_IMU_INST, (DL_SPI_ClockConfig *) &gSPI_FOR_IMU_clockConfig);

    DL_SPI_init(SPI_FOR_IMU_INST, (DL_SPI_Config *) &gSPI_FOR_IMU_config);

    /* Configure Controller mode */
    /*
     * Set the bit rate clock divider to generate the serial output clock
     *     outputBitRate = (spiInputClock) / ((1 + SCR) * 2)
     *     5333333.33 = (32000000)/((1 + 2) * 2)
     */
    DL_SPI_setBitRateSerialClockDivider(SPI_FOR_IMU_INST, 2);
    /* Set RX and TX FIFO threshold levels */
    DL_SPI_setFIFOThreshold(SPI_FOR_IMU_INST, DL_SPI_RX_FIFO_LEVEL_1_2_FULL, DL_SPI_TX_FIFO_LEVEL_1_2_EMPTY);

    /* Enable module */
    DL_SPI_enable(SPI_FOR_IMU_INST);
}

SYSCONFIG_WEAK void SYSCFG_DL_SYSTICK_init(void)
{
    /* Initialize the period to 1.00 μs */
    DL_SYSTICK_init(32);
    /* Enable the SysTick and start counting */
    DL_SYSTICK_enable();
}

