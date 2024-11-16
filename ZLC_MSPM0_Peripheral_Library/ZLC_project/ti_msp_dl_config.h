/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
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
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     32000000



/* Defines for PWM_FOR_MOTOR */
#define PWM_FOR_MOTOR_INST                                                 TIMA0
#define PWM_FOR_MOTOR_INST_IRQHandler                           TIMA0_IRQHandler
#define PWM_FOR_MOTOR_INST_INT_IRQN                             (TIMA0_INT_IRQn)
#define PWM_FOR_MOTOR_INST_CLK_FREQ                                     32000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_FOR_MOTOR_C0_PORT                                         GPIOA
#define GPIO_PWM_FOR_MOTOR_C0_PIN                                  DL_GPIO_PIN_0
#define GPIO_PWM_FOR_MOTOR_C0_IOMUX                               (IOMUX_PINCM1)
#define GPIO_PWM_FOR_MOTOR_C0_IOMUX_FUNC              IOMUX_PINCM1_PF_TIMA0_CCP0
#define GPIO_PWM_FOR_MOTOR_C0_IDX                            DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_FOR_MOTOR_C1_PORT                                         GPIOA
#define GPIO_PWM_FOR_MOTOR_C1_PIN                                  DL_GPIO_PIN_1
#define GPIO_PWM_FOR_MOTOR_C1_IOMUX                               (IOMUX_PINCM2)
#define GPIO_PWM_FOR_MOTOR_C1_IOMUX_FUNC              IOMUX_PINCM2_PF_TIMA0_CCP1
#define GPIO_PWM_FOR_MOTOR_C1_IDX                            DL_TIMER_CC_1_INDEX

/* Defines for PWM_FOR_SERVO */
#define PWM_FOR_SERVO_INST                                                 TIMA1
#define PWM_FOR_SERVO_INST_IRQHandler                           TIMA1_IRQHandler
#define PWM_FOR_SERVO_INST_INT_IRQN                             (TIMA1_INT_IRQn)
#define PWM_FOR_SERVO_INST_CLK_FREQ                                      1000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_FOR_SERVO_C0_PORT                                         GPIOB
#define GPIO_PWM_FOR_SERVO_C0_PIN                                  DL_GPIO_PIN_2
#define GPIO_PWM_FOR_SERVO_C0_IOMUX                              (IOMUX_PINCM15)
#define GPIO_PWM_FOR_SERVO_C0_IOMUX_FUNC             IOMUX_PINCM15_PF_TIMA1_CCP0
#define GPIO_PWM_FOR_SERVO_C0_IDX                            DL_TIMER_CC_0_INDEX




/* Defines for QEI_0 */
#define QEI_0_INST                                                         TIMG8
#define QEI_0_INST_IRQHandler                                   TIMG8_IRQHandler
#define QEI_0_INST_INT_IRQN                                     (TIMG8_INT_IRQn)
/* Pin configuration defines for QEI_0 PHA Pin */
#define GPIO_QEI_0_PHA_PORT                                                GPIOB
#define GPIO_QEI_0_PHA_PIN                                         DL_GPIO_PIN_6
#define GPIO_QEI_0_PHA_IOMUX                                     (IOMUX_PINCM23)
#define GPIO_QEI_0_PHA_IOMUX_FUNC                    IOMUX_PINCM23_PF_TIMG8_CCP0
/* Pin configuration defines for QEI_0 PHB Pin */
#define GPIO_QEI_0_PHB_PORT                                                GPIOB
#define GPIO_QEI_0_PHB_PIN                                         DL_GPIO_PIN_7
#define GPIO_QEI_0_PHB_IOMUX                                     (IOMUX_PINCM24)
#define GPIO_QEI_0_PHB_IOMUX_FUNC                    IOMUX_PINCM24_PF_TIMG8_CCP1


/* Defines for PIT_FOR_CONTROL */
#define PIT_FOR_CONTROL_INST                                             (TIMG0)
#define PIT_FOR_CONTROL_INST_IRQHandler                         TIMG0_IRQHandler
#define PIT_FOR_CONTROL_INST_INT_IRQN                           (TIMG0_INT_IRQn)
#define PIT_FOR_CONTROL_INST_LOAD_VALUE                                  (1999U)
/* Defines for PIT_FOR_CUSTOM */
#define PIT_FOR_CUSTOM_INST                                             (TIMG12)
#define PIT_FOR_CUSTOM_INST_IRQHandler                         TIMG12_IRQHandler
#define PIT_FOR_CUSTOM_INST_INT_IRQN                           (TIMG12_INT_IRQn)
#define PIT_FOR_CUSTOM_INST_LOAD_VALUE                                   (3999U)



/* Defines for UART_0 */
#define UART_0_INST                                                        UART0
#define UART_0_INST_IRQHandler                                  UART0_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                        DL_GPIO_PIN_11
#define GPIO_UART_0_TX_PIN                                        DL_GPIO_PIN_10
#define GPIO_UART_0_IOMUX_RX                                     (IOMUX_PINCM22)
#define GPIO_UART_0_IOMUX_TX                                     (IOMUX_PINCM21)
#define GPIO_UART_0_IOMUX_RX_FUNC                      IOMUX_PINCM22_PF_UART0_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                      IOMUX_PINCM21_PF_UART0_TX
#define UART_0_BAUD_RATE                                                (115200)
#define UART_0_IBRD_4_MHZ_115200_BAUD                                        (2)
#define UART_0_FBRD_4_MHZ_115200_BAUD                                       (11)




/* Defines for SPI_FOR_IMU */
#define SPI_FOR_IMU_INST                                                   SPI0
#define SPI_FOR_IMU_INST_IRQHandler                             SPI0_IRQHandler
#define SPI_FOR_IMU_INST_INT_IRQN                                 SPI0_INT_IRQn
#define GPIO_SPI_FOR_IMU_PICO_PORT                                        GPIOA
#define GPIO_SPI_FOR_IMU_PICO_PIN                                 DL_GPIO_PIN_9
#define GPIO_SPI_FOR_IMU_IOMUX_PICO                             (IOMUX_PINCM20)
#define GPIO_SPI_FOR_IMU_IOMUX_PICO_FUNC             IOMUX_PINCM20_PF_SPI0_PICO
#define GPIO_SPI_FOR_IMU_POCI_PORT                                        GPIOA
#define GPIO_SPI_FOR_IMU_POCI_PIN                                DL_GPIO_PIN_13
#define GPIO_SPI_FOR_IMU_IOMUX_POCI                             (IOMUX_PINCM35)
#define GPIO_SPI_FOR_IMU_IOMUX_POCI_FUNC             IOMUX_PINCM35_PF_SPI0_POCI
/* GPIO configuration for SPI_FOR_IMU */
#define GPIO_SPI_FOR_IMU_SCLK_PORT                                        GPIOA
#define GPIO_SPI_FOR_IMU_SCLK_PIN                                DL_GPIO_PIN_12
#define GPIO_SPI_FOR_IMU_IOMUX_SCLK                             (IOMUX_PINCM34)
#define GPIO_SPI_FOR_IMU_IOMUX_SCLK_FUNC             IOMUX_PINCM34_PF_SPI0_SCLK
#define GPIO_SPI_FOR_IMU_CS0_PORT                                         GPIOA
#define GPIO_SPI_FOR_IMU_CS0_PIN                                  DL_GPIO_PIN_2
#define GPIO_SPI_FOR_IMU_IOMUX_CS0                               (IOMUX_PINCM7)
#define GPIO_SPI_FOR_IMU_IOMUX_CS0_FUNC                IOMUX_PINCM7_PF_SPI0_CS0



/* Port definition for Pin Group LED1 */
#define LED1_PORT                                                        (GPIOA)

/* Defines for PIN_14: GPIOA.14 with pinCMx 36 on package pin 7 */
#define LED1_PIN_14_PIN                                         (DL_GPIO_PIN_14)
#define LED1_PIN_14_IOMUX                                        (IOMUX_PINCM36)
/* Port definition for Pin Group SPI_FOR_IMU_CS */
#define SPI_FOR_IMU_CS_PORT                                              (GPIOA)

/* Defines for PIN_8: GPIOA.8 with pinCMx 19 on package pin 54 */
#define SPI_FOR_IMU_CS_PIN_8_PIN                                 (DL_GPIO_PIN_8)
#define SPI_FOR_IMU_CS_PIN_8_IOMUX                               (IOMUX_PINCM19)
/* Port definition for Pin Group MOTOR_DIR1 */
#define MOTOR_DIR1_PORT                                                  (GPIOB)

/* Defines for PIN_26: GPIOB.0 with pinCMx 12 on package pin 47 */
#define MOTOR_DIR1_PIN_26_PIN                                    (DL_GPIO_PIN_0)
#define MOTOR_DIR1_PIN_26_IOMUX                                  (IOMUX_PINCM12)
/* Port definition for Pin Group MOTOR_DIR2 */
#define MOTOR_DIR2_PORT                                                  (GPIOB)

/* Defines for PIN_27: GPIOB.8 with pinCMx 25 on package pin 60 */
#define MOTOR_DIR2_PIN_27_PIN                                    (DL_GPIO_PIN_8)
#define MOTOR_DIR2_PIN_27_IOMUX                                  (IOMUX_PINCM25)
/* Port definition for Pin Group Remote_Switch */
#define Remote_Switch_PORT                                               (GPIOB)

/* Defines for PIN: GPIOB.13 with pinCMx 30 on package pin 1 */
#define Remote_Switch_PIN_PIN                                   (DL_GPIO_PIN_13)
#define Remote_Switch_PIN_IOMUX                                  (IOMUX_PINCM30)
/* Port definition for Pin Group BEEP_AND_LED */
#define BEEP_AND_LED_PORT                                                (GPIOB)

/* Defines for PIN_0: GPIOB.5 with pinCMx 18 on package pin 53 */
#define BEEP_AND_LED_PIN_0_PIN                                   (DL_GPIO_PIN_5)
#define BEEP_AND_LED_PIN_0_IOMUX                                 (IOMUX_PINCM18)
/* Port definition for Pin Group KEY */
#define KEY_PORT                                                         (GPIOB)

/* Defines for KEY_1: GPIOB.22 with pinCMx 50 on package pin 21 */
#define KEY_KEY_1_PIN                                           (DL_GPIO_PIN_22)
#define KEY_KEY_1_IOMUX                                          (IOMUX_PINCM50)
/* Defines for KEY_2: GPIOB.21 with pinCMx 49 on package pin 20 */
#define KEY_KEY_2_PIN                                           (DL_GPIO_PIN_21)
#define KEY_KEY_2_IOMUX                                          (IOMUX_PINCM49)
/* Defines for KEY_3: GPIOB.23 with pinCMx 51 on package pin 22 */
#define KEY_KEY_3_PIN                                           (DL_GPIO_PIN_23)
#define KEY_KEY_3_IOMUX                                          (IOMUX_PINCM51)
/* Defines for KEY_4: GPIOB.10 with pinCMx 27 on package pin 62 */
#define KEY_KEY_4_PIN                                           (DL_GPIO_PIN_10)
#define KEY_KEY_4_IOMUX                                          (IOMUX_PINCM27)
/* Port definition for Pin Group Encoder */
#define Encoder_PORT                                                     (GPIOA)

/* Defines for A: GPIOA.15 with pinCMx 37 on package pin 8 */
// pins affected by this interrupt request:["A","B","C","D"]
#define Encoder_INT_IRQN                                        (GPIOA_INT_IRQn)
#define Encoder_INT_IIDX                        (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define Encoder_A_IIDX                                      (DL_GPIO_IIDX_DIO15)
#define Encoder_A_PIN                                           (DL_GPIO_PIN_15)
#define Encoder_A_IOMUX                                          (IOMUX_PINCM37)
/* Defines for B: GPIOA.16 with pinCMx 38 on package pin 9 */
#define Encoder_B_IIDX                                      (DL_GPIO_IIDX_DIO16)
#define Encoder_B_PIN                                           (DL_GPIO_PIN_16)
#define Encoder_B_IOMUX                                          (IOMUX_PINCM38)
/* Defines for C: GPIOA.7 with pinCMx 14 on package pin 49 */
#define Encoder_C_IIDX                                       (DL_GPIO_IIDX_DIO7)
#define Encoder_C_PIN                                            (DL_GPIO_PIN_7)
#define Encoder_C_IOMUX                                          (IOMUX_PINCM14)
/* Defines for D: GPIOA.17 with pinCMx 39 on package pin 10 */
#define Encoder_D_IIDX                                      (DL_GPIO_IIDX_DIO17)
#define Encoder_D_PIN                                           (DL_GPIO_PIN_17)
#define Encoder_D_IOMUX                                          (IOMUX_PINCM39)
/* Port definition for Pin Group HUIDU */
#define HUIDU_PORT                                                       (GPIOB)

/* Defines for PIN_1: GPIOB.12 with pinCMx 29 on package pin 64 */
#define HUIDU_PIN_1_PIN                                         (DL_GPIO_PIN_12)
#define HUIDU_PIN_1_IOMUX                                        (IOMUX_PINCM29)
/* Defines for PIN_2: GPIOB.4 with pinCMx 17 on package pin 52 */
#define HUIDU_PIN_2_PIN                                          (DL_GPIO_PIN_4)
#define HUIDU_PIN_2_IOMUX                                        (IOMUX_PINCM17)
/* Defines for PIN_3: GPIOB.1 with pinCMx 13 on package pin 48 */
#define HUIDU_PIN_3_PIN                                          (DL_GPIO_PIN_1)
#define HUIDU_PIN_3_IOMUX                                        (IOMUX_PINCM13)
/* Defines for PIN_4: GPIOB.17 with pinCMx 43 on package pin 14 */
#define HUIDU_PIN_4_PIN                                         (DL_GPIO_PIN_17)
#define HUIDU_PIN_4_IOMUX                                        (IOMUX_PINCM43)
/* Defines for PIN_5: GPIOB.15 with pinCMx 32 on package pin 3 */
#define HUIDU_PIN_5_PIN                                         (DL_GPIO_PIN_15)
#define HUIDU_PIN_5_IOMUX                                        (IOMUX_PINCM32)
/* Defines for PIN_6: GPIOB.16 with pinCMx 33 on package pin 4 */
#define HUIDU_PIN_6_PIN                                         (DL_GPIO_PIN_16)
#define HUIDU_PIN_6_IOMUX                                        (IOMUX_PINCM33)
/* Defines for PIN_7: GPIOB.20 with pinCMx 48 on package pin 19 */
#define HUIDU_PIN_7_PIN                                         (DL_GPIO_PIN_20)
#define HUIDU_PIN_7_IOMUX                                        (IOMUX_PINCM48)
/* Defines for PIN_9: GPIOB.11 with pinCMx 28 on package pin 63 */
#define HUIDU_PIN_9_PIN                                         (DL_GPIO_PIN_11)
#define HUIDU_PIN_9_IOMUX                                        (IOMUX_PINCM28)



/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_FOR_MOTOR_init(void);
void SYSCFG_DL_PWM_FOR_SERVO_init(void);
void SYSCFG_DL_QEI_0_init(void);
void SYSCFG_DL_PIT_FOR_CONTROL_init(void);
void SYSCFG_DL_PIT_FOR_CUSTOM_init(void);
void SYSCFG_DL_UART_0_init(void);
void SYSCFG_DL_SPI_FOR_IMU_init(void);

void SYSCFG_DL_SYSTICK_init(void);

bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
