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
#include <common.h>

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

struct time_init {
    int8_t  tim_mode;           // 工作模式
    int8_t  tim_polity;         // 优先级
    int8_t  tim_interrupt;      // 中断允许
    int8_t  tim_clk_source;     // 时钟源
    int8_t  tim_clk_out;        // 可编程时钟输出
    int16_t tim_value;          // 装载初值
    int8_t  tim_is_run;         // 是否运行
} tim_init_t;

static int8_t timer0_init(timer_init_t *timer_x)
{
    TR0 = 0;		//停止计数

    // 设置工作模式
    if (timer_x->tim_mode >= TIM_MODE_MAX)
        return -2;
    TMOD = (TMOD & ~(0x03 << 0)) | timer_x->tim_mode;

    // 设置优先级
    if (timer_x->tim_polity == INT_POLITY_HIGHT)
        PT0 = 1;
    else
        PT0 = 0;

    // 是否允许中断
    if (timer_x->tim_interrupt == ENABLE)
        ET0 = 1;
    else
        ET0 = 0;

    // 设置频率
    if (timer_x->tim_clk_source == TIM_CLK_12T)
        AUXR &= ~(0x1 << 7);	//12T
    if (timer_x->tim_clk_source == TIM_CLK_1T)
        AUXR |=  (0x1 << 7);	//1T
    if (timer_x->tim_clk_source == TIM_CLK_EXT)
        TMOD |=  (0x1 << 2);	//对外计数或分频
    else
        TMOD &= ~(0x1 << 2);	//定时

    // 输出时钟
    if (timer_x->tim_clk_out == ENABLE)
        INT_CLKO |=  (0x1 << 0);
    else
        INT_CLKO &= ~(0x1 << 0);

    // 设置初始值
    TH0 = (uint8_t)(timer_x->tim_value >> 8);
    TL0 = (uint8_t)timer_x->tim_value;

    // 是否运行
    if (timer_x->tim_is_run == ENABLE)
        TR0 = 1;	//开始运行

    return 0;
}

int8_t timer_init(TIM_NUM_t timer_num, timer_init_t *timer_x)
{
    if (timer_num > TIM_NUM_MAX || !timer_x) {
        return -1;
    }

    switch (timer_num) {
        case TIM_NUM_0:
            return timer0_init(timer_x);
        case TIM_NUM_1:
            break;
        case TIM_NUM_2:
            break;
        case TIM_NUM_3:
            break;
        case TIM_NUM_4:
            break;
        default:
            break;
    }

    return 0;
}

void time0_init(void)
{
    TMOD = (TMOD & 0xf0u) | 0x01u;

    TIME0_INIT_REG();

	ET0 = 1;
	TR0 = 1;
}

static volatile unsigned long __idata g_sys_ticks;

void timer0_ISR(void) __interrupt 1
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

