/**
 * 
 * Release under GPLv2.
 * 
 * @file    time.c
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    29/10 2018 16:28
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        29/10 2018      create the file
 * 
 *     last modified: 29/10 2018 16:28
 */
#include <stdio.h>

#include <stc15wxxxx.h>

#define SC_TIME_GB
#include "time.h"
#undef SC_TIME_GB

#define CFG_SYS_CLK 	(22118400UL)
#define CFG_TIME0_CLK   (1 * 1000U)

#define TIME0_INIT_REG()                \
    do {                                \
        TL0 = g_timer0_init_val & 0xff; \
        TH0 = g_timer0_init_val >> 8;   \
    } while(0)

static unsigned int 
__code g_timer0_init_val = 65536 - (CFG_SYS_CLK / 12 / CFG_TIME0_CLK);

void time0_init(void)
{
    TMOD = (TMOD & 0xf0u) | 0x01u;

    TIME0_INIT_REG();

	ET0 = 1;
	TR0 = 1;
}

static volatile unsigned long __idata g_sys_ticks;

void timer0_ISR(void) __interrupt 1 __using 1
{
    TIME0_INIT_REG();

	g_sys_ticks++;
}

unsigned long time0_get_ticks(void)
{
	unsigned long ticks;

	EA = 0;
	ticks = g_sys_ticks;
	EA = 1;
	return ticks;
}

void delay02s(void)
{
    unsigned char i,j,k;

    for(i=250; i>0; i--)
        for(j=250; j>0; j--)
            for(k=248; k>0; k--);
}

