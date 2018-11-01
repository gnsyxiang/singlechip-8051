/**
 *
 * Release under GPLv2.
 * 
 * @file    stc15wxxxx.h
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    31/10 2018 15:07
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        31/10 2018      create the file
 * 
 *     last modified: 31/10 2018 15:07
 */
#ifndef __SC_STC15WXXXX_H_
#define __SC_STC15WXXXX_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <sdcc/compiler.h>
#include <sdcc/lint.h>
#include <sdcc/compiler-compativility.h>

/* io */
#define _P0     (0x80)      // port 0
#define _P0M0   (0x94)
#define _P0M1   (0x93)

SFR   (P0, _P0);
SFR   (P0M0, _P0M0);
SFR   (P0M1, _P0M1);

SBIT  (P0_7, _P0, 7);
SBIT  (P0_6, _P0, 6);
SBIT  (P0_5, _P0, 5);
SBIT  (P0_4, _P0, 4);
SBIT  (P0_3, _P0, 3);
SBIT  (P0_2, _P0, 2);
SBIT  (P0_1, _P0, 1);
SBIT  (P0_0, _P0, 0);

#define _P1     (0x90)      // port 1
#define _P1M0   (0x92)
#define _P1M1   (0x91)

SFR   (P1, _P1);
SFR   (P1M0, _P1M0);
SFR   (P1M1, _P1M1);

SBIT  (P1_7, _P1, 7);
SBIT  (P1_6, _P1, 6);
SBIT  (P1_5, _P1, 5);
SBIT  (P1_4, _P1, 4);
SBIT  (P1_3, _P1, 3);
SBIT  (P1_2, _P1, 2);
SBIT  (P1_1, _P1, 1);
SBIT  (P1_0, _P1, 0);

#define _P2     (0xA0)      // port 2
#define _P2M0   (0x96)
#define _P2M1   (0x95)

SFR   (P2, _P2);
SFR   (P2M0, _P2M0);
SFR   (P2M1, _P2M1);

SBIT  (P2_7, _P2, 7);
SBIT  (P2_6, _P2, 6);
SBIT  (P2_5, _P2, 5);
SBIT  (P2_4, _P2, 4);
SBIT  (P2_3, _P2, 3);
SBIT  (P2_2, _P2, 2);
SBIT  (P2_1, _P2, 1);
SBIT  (P2_0, _P2, 0);

#define _P3     (0xB0)      // port 3
#define _P3M0   (0xB2)
#define _P3M1   (0xB1)

SFR   (P3, _P3);
SFR   (P3M0, _P3M0);
SFR   (P3M1, _P3M1);

SBIT  (P3_7, _P3, 7);
SBIT  (P3_6, _P3, 6);
SBIT  (P3_5, _P3, 5);
SBIT  (P3_4, _P3, 4);
SBIT  (P3_3, _P3, 3);
SBIT  (P3_2, _P3, 2);
SBIT  (P3_1, _P3, 1);
SBIT  (P3_0, _P3, 0);

#define _P4     (0xC0)      // port 4
#define _P4M0   (0xB4)
#define _P4M1   (0xB3)

SFR   (P4, _P4);
SFR   (P4M0, _P4M0);
SFR   (P4M1, _P4M1);

SBIT  (P4_7, _P4, 7);
SBIT  (P4_6, _P4, 6);
SBIT  (P4_5, _P4, 5);
SBIT  (P4_4, _P4, 4);
SBIT  (P4_3, _P4, 3);
SBIT  (P4_2, _P4, 2);
SBIT  (P4_1, _P4, 1);
SBIT  (P4_0, _P4, 0);

#define _P5     (0xC8)      // port 5
#define _P5M0   (0xCA)
#define _P5M1   (0xC9)

SFR   (P5, _P5);
SFR   (P5M0, _P5M0);
SFR   (P5M1, _P5M1);

SBIT  (P5_5, _P5, 5);
SBIT  (P5_4, _P5, 4);
SBIT  (P5_3, _P5, 3);
SBIT  (P5_2, _P5, 2);
SBIT  (P5_1, _P5, 1);
SBIT  (P5_0, _P5, 0);

/* timer or counter */
#define _TCON   (0x88)
#define _TMOD   (0x89)
#define _AUXR   (0X8E)
#define _AUXR2  (0x8F)

#define _TL0    (0x8A)
#define _TH0    (0x8C)

SFR   (TCON, _TCON);
SFR   (TMOD, _TMOD);
SFR   (AUXR, _AUXR);
SFR   (AUXR2, _AUXR2);

SFR   (TL0, _TL0);
SFR   (TH0, _TH0);

SBIT  (TF1, _TCON, 7);	    // T1溢出中断标志位
SBIT  (TR1, _TCON, 6);	    // 定时器T1运行控制位, 配合GATE，可以外部控制T1
SBIT  (TF0, _TCON, 5);	    // T0溢出中断标志位
SBIT  (TR0, _TCON, 4);	    // 定时器T0运行控制位, 配合GATE，可以外部控制T0
SBIT  (IE1, _TCON, 3);	    // 外部中断1请求源(INT1/P3.3)标志位 
SBIT  (IT1, _TCON, 2);	    // 外部中断源1触发控制位
SBIT  (IE0, _TCON, 1);	    // 外部中断0请求源(INT0/P3.2)标志
SBIT  (IT0, _TCON, 0);	    // 外部中断源0触发控制位

SFR16 (TMR2, 0xCC);         // Timer 2, lsb at 0xCC, msb at 0xCD

SFR16E(TMR0, 0x8C8A);       // Timer 0, lsb at 0x8A, msb at 0x8C

/* interrupt */
#define _IE     (0xA8)
#define _IE2    (0xAF)
#define _IP     (0xB8)

SFR   (IE, _IE);            // interrupt enable 
SFR   (IE2, _IE2);	        // interrupt enable 2
SFR   (IP, _IP);	        // 中断优先级控制寄存器

SBIT  (EA,   _IE, 7);	    // 总中断
SBIT  (ELVD, _IE, 6);	    // 低压检测中断允许位
SBIT  (EADC, _IE, 5);	    // A/D转换中断允许位
SBIT  (ES,   _IE, 4);	    // 串行口1中断允许位
SBIT  (ET1,  _IE, 3);	    // 定时器/计数器T1的溢出中断允许位
SBIT  (EX1,  _IE, 2);	    // 外部中断1中断允许位
SBIT  (ET0,  _IE, 1);	    // 定时器/计数器T0的溢出中断允许位
SBIT  (EX0,  _IE, 0);	    // 外部中断1中断允许位
 

SFRX  (CPUCS, 0xE600);      // Cypress FX2 Control and Status register in xdata memory at 0xE600


SFR32 (MAC0ACC, 0x93);      // SiLabs C8051F120 32 bits MAC0 Accumulator, lsb at 0x93, msb at 0x96

SFR32E(SUMR, 0xE5E4E3E2);   // TI MSC1210 SUMR 32 bits Summation register, lsb at 0xE2, msb at 0xE5


#ifdef __cplusplus
}
#endif

#endif /* __SC_STC15WXXXX_H_ */

