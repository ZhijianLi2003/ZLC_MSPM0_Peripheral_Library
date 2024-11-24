# ZLC_MSPM0_Peripheral_Library
### Ⅰ. Introduction

​        This is an open source peripheral library developed in the KEIL development environment. It can be used to drive MSPM0G3507 microcontroller.  It is based on TI's official SDK and some third-party driver code. It can represent our work in the 2024 Chinese Undergraduate Electronic Design Competition (Question H) and we won the First Prize!. And our introductory video will be online soon.

​                                                                                                                                                  ————SDU-ZLC Electronic Design Competition Group

​                                                                                                                                                                                                            2024.11.20

### Ⅱ. Hardware Preparation

![hardware](images\hardware.jpg) 

​       In this project,we used the MSPM0G3507 Launchpad development board. If you want to enter the undergraduate Electronic Design Competition, this development board can be [applied for free](https://www.nuedc-training.com.cn/index/evm/index_2024). In order to make it easier for everyone to develop and use it,  we have designed its expansion board. It can provide a common interface to drive car models. [If you want to learn more, please click here.](http://oshwhub.com/hurricanchen/zlc_-dian-sai-mspm0g3507-launchpad-kuo-zhan-ban)

​       Here are our hardware connection：

| Wireless serial port module Pin(for debugging) | MSPM0G3507 Pin      |
| ---------------------------------------------- | ------------------- |
| RX                                             | TX(PA10)            |
| TX                                             | RX(PA11)            |
| GND                                            | Launchpad GND       |
| 3V3                                            | Launchpad Power 3V3 |

| IMU660ra Pin | MSPM0G3507 Pin      |
| ------------ | ------------------- |
| SCL/SPC      | PA12                |
| SDA/DSI      | PA9                 |
| SA0/SD0      | PA13                |
| CS           | PA8                 |
| GND          | Launchpad GND       |
| 3V3          | Launchpad Power 3V3 |

| Servo Pin(PWM) | MSPM0G3507 Pin      |
| -------------- | ------------------- |
| SCL/SPC        | PB2                 |
| GND            | Launchpad GND       |
| 3V3            | Launchpad Power 3V3 |

| DRV8701E Motor Drive Board | MSPM0G3507 Pin               |
| -------------------------- | ---------------------------- |
| DIR_1                      | PB0                          |
| PWM_1                      | PA0                          |
| GND                        | Launchpad GND                |
| DIR_2                      | PB8                          |
| PWM_2                      | PA1                          |
| GND                        | GND                          |
| Dirver_Board+              | Battery_Power+(7.4V ~ 12.0V) |
| Dirver_Board-              | Battery_Power-               |

| 1024 Orthogonal encoder | MSPM0G3507 Pin |
| ----------------------- | -------------- |
| Left_Phase_A            | PA15           |
| Left_Phase_B            | PA16           |
| Right_Phase_A           | A7             |
| Right_Phase_B           | A17            |

| Eight Gray-Scale sensors | MSPM0G3507 Pin（Set Pull up Resistance） |
| ------------------------ | ---------------------------------------- |
| PIN1                     | PB12                                     |
| PIN2                     | PB4                                      |
| PIN3                     | PB1                                      |
| PIN4                     | PB17                                     |
| PIN5                     | PB15                                     |
| PIN6                     | PB16                                     |
| PIN7                     | PB20                                     |
| PIN8                     | PB11                                     |

| Key   | MSPM0G3507 Pin |
| ----- | -------------- |
| KEY_1 | PB22           |
| KEY_2 | PB11           |
| KEY_3 | PB23           |
| KEY_4 | PB10           |

| Beep and  LED | MSPM0G3507 Pin |
| ------------- | -------------- |
| GPIO          | PB5            |

| Wireless switch for safety braking | MSPM0G3507 Pin |
| ---------------------------------- | -------------- |
| GPIO                               | PB13           |

​         Please make sure your development environment is configured before compiling. For  details about the configuration, you can refer to **KEIL_MSPM0_Environment_Config.pdf** in folder Development_Document. And Our software design can be found in the **Design_Report(2024_Question_H).pdf**.

### Ⅲ. Acknowledgements

​          We are very grateful to [TI](https://www.ti.com.cn/) and [DarWin](https://darwinlearns.com/) for the invitation. And we also thank the Smart-Car-Lab of Shandong University (Weihai) for providing us with the competition platform. **You don't have to be great to start,but you have to start to be great.**

​                                                                                                                            
