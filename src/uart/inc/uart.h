/**
 *
 * Release under GPLv2.
 * 
 * @file    uart.h
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    31/10 2018 17:19
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        31/10 2018      create the file
 * 
 *     last modified: 31/10 2018 17:19
 */
#ifndef __SC_UART_H_
#define __SC_UART_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>

#ifndef SC_UART_GB
#define SC_UART_EX extern
#else
#define SC_UART_EX
#endif

#define	COM_TX2_Lenth	128
#define	COM_RX2_Lenth	128

#define UART_RX_TX_LEN  (40)

#define	UART_ShiftRight	0		//同步移位输出
#define	UART_8bit_BRTx	(1<<6)	//8位数据,可变波特率
#define	UART_9bit		(2<<6)	//9位数据,固定波特率
#define	UART_9bit_BRTx	(3<<6)	//9位数据,可变波特率

#define	UART1_SW_P30_P31	0
#define	UART1_SW_P36_P37	(1<<6)
#define	UART1_SW_P16_P17	(2<<6)	//必须使用内部时钟
#define	UART2_SW_P10_P11	0
#define	UART2_SW_P46_P47	1


#define	TimeOutSet1		5
#define	TimeOutSet2		5

#define	BRT_Timer1	1
#define	BRT_Timer2	2

typedef enum {
    UART_NUM_1 = 1,
    UART_NUM_2,
    UART_NUM_3,
    UART_NUM_5,

    UART_NUM_MAX
} uart_num_t;

typedef enum {
    UART_MODE_SHIFTRIGHT = 0,
    UART_MODE_8BIT_BRTx,
    UART_MODE_9BIT,
    UART_MODE_9BIT_BRTx,

    UART_MODE_MAX
} uart_mode_t;

typedef enum {
    UART1_PORT_SW_P30_P31,
    UART1_PORT_SW_P36_P37,
    UART1_PORT_SW_P16_P17,      // 必须使用内部时钟
} uart_port_sw_t;

typedef struct {
	int8_t  mode;			    //模式, 见uart_mode_t
	int8_t  is_interrupt;		//中断控制,   ENABLE, DISABLE
	int8_t  rx_enable;		    //允许接收,   ENABLE, DISABLE
	int8_t  more_communicate;	//多机通讯允许, ENABLE,DISABLE

	int32_t rate;		        //波特率, 110 ~ 115200
	int8_t  use_rate;		    //使用波特率, BRT_Timer1,BRT_Timer2(注意: 串口2固定使用BRT_Timer2)
	int8_t  rate_double;		//波特率加倍, ENABLE, DISABLE

	int8_t  polity;		        //优先级,     INT_POLITY_LOW, INT_POLITY_HIGHT
	int8_t  port_sw;			//切换端口, 见uart_port_sw_t
	int8_t  is_rxd_txd;	        //内部短路RXD与TXD, 做中继, ENABLE,DISABLE
} uart_conf_t;

#define SMOD        (PCON & (0x1 << 7)) // 波特率选择位 
#define SMOD0       (PCON & (0x1 << 6)) // 帧错误检测有效控制位

                    //
#define T0x12       (AUXR & (0x1 << 7))
#define T1x12       (AUXR & (0x1 << 7))
#define UART_M0x6   (AUXR & (0x1 << 7))
#define T2R         (AUXR & (0x1 << 7))

SC_UART_EX int8_t uart_init(uart_num_t uart_num, uart_conf_t *uart_conf);
SC_UART_EX void tx1_write2buff(int8_t ch);

SC_UART_EX void uart1_init(void);

#ifdef __cplusplus
}
#endif

#endif /* __SC_UART_H_ */

