 /*
 * This file is the serial port configuration file and clock configuration file.
 * forum: https://oshwhub.com/forum
 * Change Logs:
 * Date           Author       Notes
 * 2024-06-26     LCKFB     first version
 */
 
#ifndef	__BOARD_H__
#define __BOARD_H__

#include "ti_msp_dl_config.h"

void board_init(void);

void delay_us(unsigned long __us);
void delay_ms(unsigned long ms);
void delay_1us(unsigned long __us);
void delay_1ms(unsigned long ms);

void uart0_send_char(char ch);
void uart0_send_string(char* str);



#endif
