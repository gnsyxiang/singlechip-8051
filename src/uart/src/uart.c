/**
 * 
 * Release under GPLv2.
 * 
 * @file    uart.c
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    31/10 2018 17:20
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        31/10 2018      create the file
 * 
 *     last modified: 31/10 2018 17:20
 */
#include <stdio.h>

#include <stc15wxxxx.h>

#define SC_UART_GB
#include "uart.h"
#undef SC_UART_GB

void uart1_init(void)
{
	/*Timer1 as baud rate generator for UART1. */
	PCON |= 0x80; /*SMOD=1, double baud-rate */
	TMOD = (TMOD & 0x0fu) | 0x20u; /*Timer1 as 8-bit auto-reload mode.*/
	TH1 = 255u;
	TL1 = 255u; /* 11059200/12/16/(256-255) = 57600 */
	            /* 22118400/12/16/(256-255) = 115200 */
	TR1 = 1; /*Start Timer1 running.*/

	SCON = 0x50u;/*UART1 at mode 1:8-N-1 57600 or 115200 Enable Receiver.*/

	ES = 1; /*Disable UART1 interrupt.*/
}

/*implemented for printf() */
char putchar(char c)
{
	SBUF = c;
	while (TI == 0);
	TI = 0;
	return c;
}

