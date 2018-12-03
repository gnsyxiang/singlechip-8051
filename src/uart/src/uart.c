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
#include <common.h>

#include <time/time.h>

#define SC_UART_GB
#include "uart.h"
#undef SC_UART_GB

typedef struct {
    int8_t id;				// 串口号

    int8_t tx_read; 		// 发送读指针
    int8_t tx_write; 		// 发送写指针
    int8_t is_tx_busy; 	    // 忙标志

    int8_t rx_cnt;			// 接收字节计数
    int8_t rx_timeout;		// 接收超时
    int8_t is_rx_ok;		// 接收块完成
} uart_t;

static uart_t uart_1;

__idata uint8_t rx_buf[UART_RX_TX_LEN];
__idata uint8_t tx_buf[UART_RX_TX_LEN];

int8_t uart_init(uart_num_t uart_num, uart_conf_t *uart_conf)
{
    if (uart_num >= UART_NUM_MAX)
        return -1;

    if (!uart_conf || uart_conf->mode >= UART_MODE_MAX)
        return -2;

    uart_1.id                     = uart_num;
    uart_1.tx_read                = 0;
    uart_1.tx_write               = 0;
    uart_1.is_tx_busy             = 0;
    uart_1.rx_cnt                 = 0;
    uart_1.rx_timeout             = 0;
    uart_1.is_rx_ok               = 0;

    for (int8_t i = 0; i < UART_RX_TX_LEN; i++) {
        rx_buf[i] = 0;
        tx_buf[i] = 0;
    }

    switch (uart_num) {
        case UART_NUM_1:
            reg_reset_all(SCON);
            bit_set_val(SCON, 6, uart_conf->mode);  // 串口1工作方式1
            bit_reset(SCON, 5);                     // 不允许多机通信 
            bit_set(SCON, 4);                       // 允许接收
            bit_reset(SCON, 1);                     // 清零发送中断标志位
            bit_reset(SCON, 0);                     // 清零接收中断标志位 

            switch (uart_conf->mode) {
                case UART_MODE_8BIT_BRTx:
                case UART_MODE_9BIT_BRTx: {
                    if (uart_conf->use_rate == TIM_NUM_1) {
                        TR1 = 0;

                        reg_reset_all(TMOD);
                        bit_reset(TMOD, 7);         // 不受外部INT1引脚的控制
                        bit_reset(TMOD, 6);         // 用作定时器使用 
                        bit_set_val(TMOD, 4, TIM_MODE_16BitAutoReload);// 16位自动重装模式

                        reg_reset_all(AUXR);
                        bit_set(AUXR, 6);           // 1T模式
                        bit_reset(AUXR, 0);         // 定时器1作为串口1的波特率发生器

                        bit_reset(INT_CLKO, 1); //不输出时钟

                        uint32_t j = (CFG_SYS_CLK / 4) / uart_conf->rate;
                        if(j >= BIT16_VAL)	
                            return -3;

                        timer_val_get_hex(TH1, TL1, BIT16_VAL - j); //设置定时器初始值

                        ET1 = 0;	            //禁止定时器1中断
                        TR1  = 1;
                    } else if (uart_conf->use_rate == TIM_NUM_2) { 

                    } else
                        return -4;

                    break;
                 }
                case UART_MODE_SHIFTRIGHT:
                    break;
                case UART_MODE_9BIT:
                    break;
                default:
                    break;
            }

            reg_set1(uart_conf->polity, INT_POLITY_HIGHT, PS);
            reg_set1(uart_conf->is_interrupt, ENABLE, ES);
            reg_set1(uart_conf->rx_enable, ENABLE, REN);
            bit_set_val(P_SW1, 6, uart_conf->port_sw);
            reg_set(uart_conf->is_rxd_txd, ENABLE, PCON2, 4);

            break;

        default:
            break;
    }

    return 0;
}

void uart1_ISR(void) __interrupt 4 
{
#if 0
	if (RI) {
		RI = 0;

		if(COM1.B_RX_OK == 0) {
			if(COM1.RX_Cnt >= COM_RX1_Lenth)
                COM1.RX_Cnt = 0;
			RX1_Buffer[COM1.RX_Cnt++] = SBUF;
			COM1.RX_TimeOut = TimeOutSet1;
		}
	}
#endif

	// if (TI) {
        // RED_LED = 0;
		// TI = 0;
//
        // if (uart_1.tx_read != uart_1.tx_write) {
            // SBUF = tx_buf[uart_1.tx_read];
            // if (++uart_1.tx_read >= UART_RX_TX_LEN)
                // uart_1.tx_read = 0;
        // } else
            // uart_1.is_tx_busy = 0;
	// }
}

void tx1_write2buff(int8_t ch)
{
	tx_buf[uart_1.tx_write] = ch;

    if (++uart_1.tx_write >= UART_RX_TX_LEN)
        uart_1.tx_write = 0;

	if (uart_1.is_tx_busy == 0) {  
		uart_1.is_tx_busy = 1;

		TI = 1; //触发发送中断
	}
}

