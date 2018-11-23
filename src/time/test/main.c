/**
 * 
 * Release under GPLv2.
 * 
 * @file    main.c
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    29/10 2018 16:29
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        29/10 2018      create the file
 * 
 *     last modified: 29/10 2018 16:29
 */
#include <stdio.h>

#include <stc15wxxxx.h>
#include <common.h>
#include <time/time.h>

static int8_t cnt = 0;
static int8_t cnt_flag = 0;
static int8_t test = 0;

void timer0_ISR(void) __interrupt 1
{
    if (cnt++ >= 10) {
        cnt = 0;

        cnt_flag = 1;
    }
}

void timer1_ISR(void) __interrupt 3
{
    if (cnt_flag && test++ >= 100) {
        cnt_flag = 0;
        test = 0;

        RED_LED = !RED_LED;
    }
}

void main(void)
{
    timer_init_t timer_0;

    timer_0.tim_num         = TIM_NUM_0;
    timer_0.tim_mode        = TIM_MODE_16BitAutoReload;
    timer_0.tim_polity      = TIM_POLITY_HIGHT;
    timer_0.tim_interrupt   = ENABLE;
    timer_0.tim_clk_source  = TIM_CLK_12T;
    timer_0.tim_cnt_timer   = TIM_TIMER;
    timer_0.tim_clk_out     = DISABLE;
    timer_0.tim_value_ms    = 10;
    timer_0.tim_is_run      = ENABLE;

    timer_init(&timer_0);

    timer_0.tim_num         = TIM_NUM_1;

    timer_init(&timer_0);

    EA = 1;

    while (1) {
    }
}

