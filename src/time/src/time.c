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

#define timer_val_get(tim_value_ms) (CFG_SYS_CLK * tim_value_ms) / 1000
#define timer_val_get_hex(THx, TLx, timer_val)  \
    do {                                        \
        TLx = timer_val & 0xff;                 \
        THx = timer_val >> 8;                   \
    } while(0)

#define mode_set(tim_mode, bit) TMOD = (TMOD & ~(0x03 << bit)) | tim_mode

static inline int8_t timer_init_0(timer_init_t *timer_x, uint32_t timer_val)
{
    TR0 = 0;
    mode_set(timer_x->tim_mode, 0);
    reg_set1(timer_x->tim_polity, INT_POLITY_HIGHT, PT0);
    reg_set1(timer_x->tim_interrupt, ENABLE, ET0);
    reg_set(timer_x->tim_clk_source, TIM_CLK_1T, AUXR, 7);
    reg_set(timer_x->tim_clk_source, TIM_CNT, TMOD, 2);
    reg_set(timer_x->tim_clk_out, ENABLE, INT_CLKO, 0);
    timer_val_get_hex(TH0, TL0, timer_val);

    if (timer_x->tim_is_run == ENABLE)
        TR0 = 1;

    return 0;
}

static inline int8_t timer_init_1(timer_init_t *timer_x, uint32_t timer_val)
{
    if (timer_x->tim_mode >= TIM_MODE_16BitAutoReloadNoMask)
        return -2;

    TR1 = 0;
    mode_set(timer_x->tim_mode, 4);
    reg_set1(timer_x->tim_polity, INT_POLITY_HIGHT, PT1);
    reg_set1(timer_x->tim_interrupt, ENABLE, ET1);
    reg_set(timer_x->tim_clk_source, TIM_CLK_1T, AUXR, 6);
    reg_set(timer_x->tim_clk_source, TIM_CNT, TMOD, 6);
    reg_set(timer_x->tim_clk_out, ENABLE, INT_CLKO, 1);
    timer_val_get_hex(TH1, TL1, timer_val);

    if (timer_x->tim_is_run == ENABLE)
        TR1 = 1;

    return 0;
}

static inline int8_t timer_init_2(timer_init_t *timer_x, uint32_t timer_val)
{
    bit_reset(AUXR, 4);
    reg_set(timer_x->tim_interrupt, ENABLE, IE2, 2);
    reg_set(timer_x->tim_clk_source, TIM_CLK_1T, AUXR, 2);
    reg_set(timer_x->tim_clk_source, TIM_CNT, AUXR, 3);
    reg_set(timer_x->tim_clk_out, ENABLE, INT_CLKO, 2);
    timer_val_get_hex(TH2, TL2, timer_val);

    if (timer_x->tim_is_run == ENABLE)
        bit_set(AUXR, 4);

    return 0;
}

static inline int8_t timer_init_3(timer_init_t *timer_x, uint32_t timer_val)
{
    bit_reset(T4T3M, 3);
    reg_set(timer_x->tim_interrupt, ENABLE, IE2, 5);
    reg_set(timer_x->tim_clk_source, TIM_CLK_1T, T4T3M, 1);
    reg_set(timer_x->tim_clk_source, TIM_CNT, T4T3M, 2);
    reg_set(timer_x->tim_clk_out, ENABLE, T4T3M, 0);
    timer_val_get_hex(TH3, TL3, timer_val);

    if (timer_x->tim_is_run == ENABLE)
        bit_set(T4T3M, 3);

    return 0;
}

static inline int8_t timer_init_4(timer_init_t *timer_x, uint32_t timer_val)
{
    bit_reset(T4T3M, 7);
    reg_set(timer_x->tim_interrupt, ENABLE, IE2, 6);
    reg_set(timer_x->tim_clk_source, TIM_CLK_1T, T4T3M, 5);
    reg_set(timer_x->tim_clk_source, TIM_CNT, T4T3M, 6);
    reg_set(timer_x->tim_clk_out, ENABLE, T4T3M, 4);
    timer_val_get_hex(TH4, TL4, timer_val);

    if (timer_x->tim_is_run == ENABLE)
        bit_set(T4T3M, 7);

    return 0;
}

int8_t timer_init(timer_init_t *timer_x)
{
    if (timer_x->tim_num >= TIM_NUM_MAX || !timer_x) {
        return -1;
    }

    uint32_t timer_val;

    if (timer_x->tim_clk_source == TIM_CLK_12T) {
        timer_val = BIT16_VAL - timer_val_get(timer_x->tim_value_ms) / 12;
    } else {
        timer_val = BIT16_VAL - timer_val_get(timer_x->tim_value_ms);
    }

    switch (timer_x->tim_num) {
        case TIM_NUM_0:
            return timer_init_0(timer_x, timer_val);
            break;
        case TIM_NUM_1:
            return timer_init_1(timer_x, timer_val);
            break;
        // T2、T3、T4固定为16位自动重装载模式
        // T2、T3、T4固定为低优先级
        case TIM_NUM_2:
            return timer_init_2(timer_x, timer_val);
            break;
        case TIM_NUM_3:
            return timer_init_3(timer_x, timer_val);
            break;
        case TIM_NUM_4:
            return timer_init_4(timer_x, timer_val);
            break;
        default:
            break;
    }

    return 0;
}

void delay02s(void)
{
    unsigned char i,j,k;

    for(i=250; i>0; i--)
        for(j=250; j>0; j--)
            for(k=248; k>0; k--);
}

