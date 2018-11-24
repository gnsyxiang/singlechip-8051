/**
 * 
 * Release under GPLv2.
 * 
 * @file    main.c
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    31/10 2018 17:22
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        31/10 2018      create the file
 * 
 *     last modified: 31/10 2018 17:22
 */
#include <stdio.h>

#include <common.h>
#include <stc15wxxxx.h>

#include <uart/uart.h>
#include <time/time.h>

char putchar(char ch)
{
    tx1_write2buff(ch);

	return ch;
}

void main(void)
{
    uart_conf_t uart_conf;

    uart_conf.mode              = UART_MODE_8BIT_BRTx;
    uart_conf.is_interrupt      = ENABLE;
    uart_conf.rx_enable         = ENABLE;
    uart_conf.more_communicate  = DISABLE;

    uart_conf.rate              = 115200UL;
    uart_conf.use_rate          = TIM_NUM_1;
    uart_conf.rate_double       = DISABLE;

    uart_conf.polity            = INT_POLITY_HIGHT;
    uart_conf.port_sw           = UART1_PORT_SW_P30_P31;
    uart_conf.is_rxd_txd        = DISABLE;

    uart_init(UART_NUM_1, &uart_conf);

    EA = 1;

    RED_LED = 1;

    while (1)
        putchar('a');
}

