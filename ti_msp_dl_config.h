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



/* Defines for PWM_1 */
#define PWM_1_INST                                                        TIMG12
#define PWM_1_INST_IRQHandler                                  TIMG12_IRQHandler
#define PWM_1_INST_INT_IRQN                                    (TIMG12_INT_IRQn)
#define PWM_1_INST_CLK_FREQ                                              4000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_1_C0_PORT                                                 GPIOA
#define GPIO_PWM_1_C0_PIN                                         DL_GPIO_PIN_14
#define GPIO_PWM_1_C0_IOMUX                                      (IOMUX_PINCM36)
#define GPIO_PWM_1_C0_IOMUX_FUNC                    IOMUX_PINCM36_PF_TIMG12_CCP0
#define GPIO_PWM_1_C0_IDX                                    DL_TIMER_CC_0_INDEX

/* Defines for PWM_0 */
#define PWM_0_INST                                                         TIMA1
#define PWM_0_INST_IRQHandler                                   TIMA1_IRQHandler
#define PWM_0_INST_INT_IRQN                                     (TIMA1_INT_IRQn)
#define PWM_0_INST_CLK_FREQ                                              4000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_0_C0_PORT                                                 GPIOA
#define GPIO_PWM_0_C0_PIN                                         DL_GPIO_PIN_17
#define GPIO_PWM_0_C0_IOMUX                                      (IOMUX_PINCM39)
#define GPIO_PWM_0_C0_IOMUX_FUNC                     IOMUX_PINCM39_PF_TIMA1_CCP0
#define GPIO_PWM_0_C0_IDX                                    DL_TIMER_CC_0_INDEX



/* Defines for TIMER_10ms */
#define TIMER_10ms_INST                                                  (TIMG0)
#define TIMER_10ms_INST_IRQHandler                              TIMG0_IRQHandler
#define TIMER_10ms_INST_INT_IRQN                                (TIMG0_INT_IRQn)
#define TIMER_10ms_INST_LOAD_VALUE                                        (399U)




/* Defines for I2C_0 */
#define I2C_0_INST                                                          I2C0
#define I2C_0_INST_IRQHandler                                    I2C0_IRQHandler
#define I2C_0_INST_INT_IRQN                                        I2C0_INT_IRQn
#define I2C_0_BUS_SPEED_HZ                                                400000
#define GPIO_I2C_0_SDA_PORT                                                GPIOA
#define GPIO_I2C_0_SDA_PIN                                         DL_GPIO_PIN_0
#define GPIO_I2C_0_IOMUX_SDA                                      (IOMUX_PINCM1)
#define GPIO_I2C_0_IOMUX_SDA_FUNC                       IOMUX_PINCM1_PF_I2C0_SDA
#define GPIO_I2C_0_SCL_PORT                                                GPIOA
#define GPIO_I2C_0_SCL_PIN                                         DL_GPIO_PIN_1
#define GPIO_I2C_0_IOMUX_SCL                                      (IOMUX_PINCM2)
#define GPIO_I2C_0_IOMUX_SCL_FUNC                       IOMUX_PINCM2_PF_I2C0_SCL


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
/* Defines for UART_1 */
#define UART_1_INST                                                        UART1
#define UART_1_INST_IRQHandler                                  UART1_IRQHandler
#define UART_1_INST_INT_IRQN                                      UART1_INT_IRQn
#define GPIO_UART_1_RX_PORT                                                GPIOA
#define GPIO_UART_1_TX_PORT                                                GPIOA
#define GPIO_UART_1_RX_PIN                                         DL_GPIO_PIN_9
#define GPIO_UART_1_TX_PIN                                         DL_GPIO_PIN_8
#define GPIO_UART_1_IOMUX_RX                                     (IOMUX_PINCM20)
#define GPIO_UART_1_IOMUX_TX                                     (IOMUX_PINCM19)
#define GPIO_UART_1_IOMUX_RX_FUNC                      IOMUX_PINCM20_PF_UART1_RX
#define GPIO_UART_1_IOMUX_TX_FUNC                      IOMUX_PINCM19_PF_UART1_TX
#define UART_1_BAUD_RATE                                                (115200)
#define UART_1_IBRD_4_MHZ_115200_BAUD                                        (2)
#define UART_1_FBRD_4_MHZ_115200_BAUD                                       (11)
/* Defines for UART3_jy901 */
#define UART3_jy901_INST                                                   UART3
#define UART3_jy901_INST_IRQHandler                             UART3_IRQHandler
#define UART3_jy901_INST_INT_IRQN                                 UART3_INT_IRQn
#define GPIO_UART3_jy901_RX_PORT                                           GPIOB
#define GPIO_UART3_jy901_TX_PORT                                           GPIOB
#define GPIO_UART3_jy901_RX_PIN                                    DL_GPIO_PIN_3
#define GPIO_UART3_jy901_TX_PIN                                    DL_GPIO_PIN_2
#define GPIO_UART3_jy901_IOMUX_RX                                (IOMUX_PINCM16)
#define GPIO_UART3_jy901_IOMUX_TX                                (IOMUX_PINCM15)
#define GPIO_UART3_jy901_IOMUX_RX_FUNC                 IOMUX_PINCM16_PF_UART3_RX
#define GPIO_UART3_jy901_IOMUX_TX_FUNC                 IOMUX_PINCM15_PF_UART3_TX
#define UART3_jy901_BAUD_RATE                                             (9600)
#define UART3_jy901_IBRD_32_MHZ_9600_BAUD                                  (208)
#define UART3_jy901_FBRD_32_MHZ_9600_BAUD                                   (21)





/* Port definition for Pin Group KEY */
#define KEY_PORT                                                         (GPIOA)

/* Defines for PIN_18: GPIOA.18 with pinCMx 40 on package pin 11 */
// groups represented: ["KEY2_USER","GPIO_EncoderA","KEY"]
// pins affected: ["PIN_28","PIN_EncoderA1","PIN_EncoderA2","PIN_18"]
#define GPIO_MULTIPLE_GPIOA_INT_IRQN                            (GPIOA_INT_IRQn)
#define GPIO_MULTIPLE_GPIOA_INT_IIDX            (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define KEY_PIN_18_IIDX                                     (DL_GPIO_IIDX_DIO18)
#define KEY_PIN_18_PIN                                          (DL_GPIO_PIN_18)
#define KEY_PIN_18_IOMUX                                         (IOMUX_PINCM40)
/* Port definition for Pin Group KEY1_USER */
#define KEY1_USER_PORT                                                   (GPIOB)

/* Defines for PIN_24: GPIOB.24 with pinCMx 52 on package pin 23 */
// groups represented: ["GPIO_EncoderB","KEY1_USER"]
// pins affected: ["PIN_EncoderB2","PIN_EncoderB1","PIN_24"]
#define GPIO_MULTIPLE_GPIOB_INT_IRQN                            (GPIOB_INT_IRQn)
#define GPIO_MULTIPLE_GPIOB_INT_IIDX            (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define KEY1_USER_PIN_24_IIDX                               (DL_GPIO_IIDX_DIO24)
#define KEY1_USER_PIN_24_PIN                                    (DL_GPIO_PIN_24)
#define KEY1_USER_PIN_24_IOMUX                                   (IOMUX_PINCM52)
/* Port definition for Pin Group KEY2_USER */
#define KEY2_USER_PORT                                                   (GPIOA)

/* Defines for PIN_28: GPIOA.28 with pinCMx 3 on package pin 35 */
#define KEY2_USER_PIN_28_IIDX                               (DL_GPIO_IIDX_DIO28)
#define KEY2_USER_PIN_28_PIN                                    (DL_GPIO_PIN_28)
#define KEY2_USER_PIN_28_IOMUX                                    (IOMUX_PINCM3)
/* Port definition for Pin Group GPIO_EncoderA */
#define GPIO_EncoderA_PORT                                               (GPIOA)

/* Defines for PIN_EncoderA1: GPIOA.16 with pinCMx 38 on package pin 9 */
#define GPIO_EncoderA_PIN_EncoderA1_IIDX                    (DL_GPIO_IIDX_DIO16)
#define GPIO_EncoderA_PIN_EncoderA1_PIN                         (DL_GPIO_PIN_16)
#define GPIO_EncoderA_PIN_EncoderA1_IOMUX                        (IOMUX_PINCM38)
/* Defines for PIN_EncoderA2: GPIOA.15 with pinCMx 37 on package pin 8 */
#define GPIO_EncoderA_PIN_EncoderA2_IIDX                    (DL_GPIO_IIDX_DIO15)
#define GPIO_EncoderA_PIN_EncoderA2_PIN                         (DL_GPIO_PIN_15)
#define GPIO_EncoderA_PIN_EncoderA2_IOMUX                        (IOMUX_PINCM37)
/* Port definition for Pin Group GPIO_EncoderB */
#define GPIO_EncoderB_PORT                                               (GPIOB)

/* Defines for PIN_EncoderB2: GPIOB.9 with pinCMx 26 on package pin 61 */
#define GPIO_EncoderB_PIN_EncoderB2_IIDX                     (DL_GPIO_IIDX_DIO9)
#define GPIO_EncoderB_PIN_EncoderB2_PIN                          (DL_GPIO_PIN_9)
#define GPIO_EncoderB_PIN_EncoderB2_IOMUX                        (IOMUX_PINCM26)
/* Defines for PIN_EncoderB1: GPIOB.8 with pinCMx 25 on package pin 60 */
#define GPIO_EncoderB_PIN_EncoderB1_IIDX                     (DL_GPIO_IIDX_DIO8)
#define GPIO_EncoderB_PIN_EncoderB1_PIN                          (DL_GPIO_PIN_8)
#define GPIO_EncoderB_PIN_EncoderB1_IOMUX                        (IOMUX_PINCM25)
/* Port definition for Pin Group GPIO_AIN */
#define GPIO_AIN_PORT                                                    (GPIOA)

/* Defines for AIN1: GPIOA.13 with pinCMx 35 on package pin 6 */
#define GPIO_AIN_AIN1_PIN                                       (DL_GPIO_PIN_13)
#define GPIO_AIN_AIN1_IOMUX                                      (IOMUX_PINCM35)
/* Defines for AIN2: GPIOA.12 with pinCMx 34 on package pin 5 */
#define GPIO_AIN_AIN2_PIN                                       (DL_GPIO_PIN_12)
#define GPIO_AIN_AIN2_IOMUX                                      (IOMUX_PINCM34)
/* Port definition for Pin Group GPIO_BIN */
#define GPIO_BIN_PORT                                                    (GPIOA)

/* Defines for BIN1: GPIOA.25 with pinCMx 55 on package pin 26 */
#define GPIO_BIN_BIN1_PIN                                       (DL_GPIO_PIN_25)
#define GPIO_BIN_BIN1_IOMUX                                      (IOMUX_PINCM55)
/* Defines for BIN2: GPIOA.24 with pinCMx 54 on package pin 25 */
#define GPIO_BIN_BIN2_PIN                                       (DL_GPIO_PIN_24)
#define GPIO_BIN_BIN2_IOMUX                                      (IOMUX_PINCM54)
/* Port definition for Pin Group GPIO_GRAY_SENSOR */
#define GPIO_GRAY_SENSOR_PORT                                            (GPIOB)

/* Defines for SENSOR1: GPIOB.1 with pinCMx 13 on package pin 48 */
#define GPIO_GRAY_SENSOR_SENSOR1_PIN                             (DL_GPIO_PIN_1)
#define GPIO_GRAY_SENSOR_SENSOR1_IOMUX                           (IOMUX_PINCM13)
/* Defines for SENSOR2: GPIOB.4 with pinCMx 17 on package pin 52 */
#define GPIO_GRAY_SENSOR_SENSOR2_PIN                             (DL_GPIO_PIN_4)
#define GPIO_GRAY_SENSOR_SENSOR2_IOMUX                           (IOMUX_PINCM17)
/* Defines for SENSOR3: GPIOB.7 with pinCMx 24 on package pin 59 */
#define GPIO_GRAY_SENSOR_SENSOR3_PIN                             (DL_GPIO_PIN_7)
#define GPIO_GRAY_SENSOR_SENSOR3_IOMUX                           (IOMUX_PINCM24)
/* Defines for SENSOR4: GPIOB.12 with pinCMx 29 on package pin 64 */
#define GPIO_GRAY_SENSOR_SENSOR4_PIN                            (DL_GPIO_PIN_12)
#define GPIO_GRAY_SENSOR_SENSOR4_IOMUX                           (IOMUX_PINCM29)
/* Defines for SENSOR5: GPIOB.17 with pinCMx 43 on package pin 14 */
#define GPIO_GRAY_SENSOR_SENSOR5_PIN                            (DL_GPIO_PIN_17)
#define GPIO_GRAY_SENSOR_SENSOR5_IOMUX                           (IOMUX_PINCM43)
/* Port definition for Pin Group GPIO_BEEP_PORT */
#define GPIO_BEEP_PORT_PORT                                              (GPIOA)

/* Defines for BEEP1: GPIOA.7 with pinCMx 14 on package pin 49 */
#define GPIO_BEEP_PORT_BEEP1_PIN                                 (DL_GPIO_PIN_7)
#define GPIO_BEEP_PORT_BEEP1_IOMUX                               (IOMUX_PINCM14)
/* Defines for LED1: GPIOA.22 with pinCMx 47 on package pin 18 */
#define GPIO_BEEP_PORT_LED1_PIN                                 (DL_GPIO_PIN_22)
#define GPIO_BEEP_PORT_LED1_IOMUX                                (IOMUX_PINCM47)



/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_1_init(void);
void SYSCFG_DL_PWM_0_init(void);
void SYSCFG_DL_TIMER_10ms_init(void);
void SYSCFG_DL_I2C_0_init(void);
void SYSCFG_DL_UART_0_init(void);
void SYSCFG_DL_UART_1_init(void);
void SYSCFG_DL_UART3_jy901_init(void);

void SYSCFG_DL_SYSTICK_init(void);

bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
