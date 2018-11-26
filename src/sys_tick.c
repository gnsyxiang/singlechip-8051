/**
 * 
 * Release under GPLv2.
 * 
 * @file    sys_tick.c
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    23/11 2018 16:14
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        23/11 2018      create the file
 * 
 *     last modified: 23/11 2018 16:14
 */
#include <stdio.h>

#include <stc15wxxxx.h>
#include <common.h>

#include <time/time.h>

#define SC_SYS_TICK_GB
#include <sys_tick.h>
#undef SC_SYS_TICK_GB

static volatile unsigned long __idata g_sys_ticks;

void sys_tick_init(void)
{
    timer_init_t timer_0;

    timer_0.tim_num         = TIM_NUM_0;
    timer_0.tim_mode        = TIM_MODE_16BitAutoReload;
    timer_0.tim_polity      = TIM_POLITY_HIGHT;
    timer_0.tim_interrupt   = ENABLE;
    timer_0.tim_clk_source  = TIM_CLK_12T;
    timer_0.tim_cnt_timer   = TIM_TIMER;
    timer_0.tim_clk_out     = DISABLE;
    timer_0.tim_value_ms    = 1;
    timer_0.tim_is_run      = ENABLE;

    timer_init(&timer_0);
}

void timer0_ISR(void) __interrupt 1
{
    g_sys_ticks++;
}

unsigned long sys_tick_get(void)
{
	unsigned long ticks;

	EA = 0;
	ticks = g_sys_ticks;
	EA = 1;

	return ticks;
}

