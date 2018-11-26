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

#ifndef SC_UART_GB
#define SC_UART_EX extern
#else
#define SC_UART_EX
#endif

#define SMOD        (PCON & (0x1 << 7)) // 波特率选择位 
#define SMOD0       (PCON & (0x1 << 6)) // 帧错误检测有效控制位

                    //
#define T0x12       (AUXR & (0x1 << 7))
#define T1x12       (AUXR & (0x1 << 7))
#define UART_M0x6   (AUXR & (0x1 << 7))
#define T2R         (AUXR & (0x1 << 7))

SC_UART_EX void uart1_init(void);
SC_UART_EX int putchar(int c);

#ifdef __cplusplus
}
#endif

#endif /* __SC_UART_H_ */

