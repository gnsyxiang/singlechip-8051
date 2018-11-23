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

static inline void timer_set_value(timer_init_t *timer_x)
{
    unsigned long timer_val;

    if (timer_x->tim_clk_source == TIM_CLK_12T) {
        timer_val = BIT16_VAL - timer_val_get(timer_x->tim_value_ms) / 12;
    } else {
        timer_val = BIT16_VAL - timer_val_get(timer_x->tim_value_ms);
    }

    switch (timer_x->tim_num) {
        case TIM_NUM_0:
            timer_val_get_hex(TH0, TL0, timer_val);
            break;
        case TIM_NUM_1:
            timer_val_get_hex(TH1, TL1, timer_val);
            break;
        case TIM_NUM_2:
            timer_val_get_hex(TH2, TL2, timer_val);
            break;
        case TIM_NUM_3:
            timer_val_get_hex(TH3, TL3, timer_val);
            break;
        case TIM_NUM_4:
            timer_val_get_hex(TH4, TL4, timer_val);
            break;
        default:
            break;
    }
}

#define int_enable(tim_interrupt, ETx)  \
    do {                                \
        if (tim_interrupt == ENABLE)    \
            ETx = 1;                    \
        else                            \
            ETx = 0;                    \
    } while(0)

#define int_enable_1(tim_interrupt, reg, bit)   \
    do {                                        \
        if (tim_interrupt == ENABLE)            \
            reg |=  (0x1 << bit);               \
        else                                    \
            reg &= ~(0x1 << bit);               \
    } while(0)

static inline void timer_enable_int(timer_init_t *timer_x)
{
    switch (timer_x->tim_num) {
        case TIM_NUM_0:
            int_enable(timer_x->tim_interrupt, ET0);
            break;
        case TIM_NUM_1:
            int_enable(timer_x->tim_interrupt, ET1);
            break;
        case TIM_NUM_2:
            int_enable_1(timer_x->tim_interrupt, IE2, 2);
            break;
        case TIM_NUM_3:
            int_enable_1(timer_x->tim_interrupt, IE2, 5);
            break;
        case TIM_NUM_4:
            int_enable_1(timer_x->tim_interrupt, IE2, 6);
            break;
        default:
            break;
    }
}

#define out_clk(tim_clk_out, reg, bit)  \
    do {                                \
        if (tim_clk_out == ENABLE)      \
            reg |=  (0x1 << bit);       \
        else                            \
            reg &= ~(0x1 << bit);       \
    } while(0)

static inline void timer_out_clk(timer_init_t *timer_x)
{
    switch (timer_x->tim_num) {
        case TIM_NUM_0:
            out_clk(timer_x->tim_clk_out, INT_CLKO, 0);
            break;
        case TIM_NUM_1:
            out_clk(timer_x->tim_clk_out, INT_CLKO, 1);
            break;
        case TIM_NUM_2:
            out_clk(timer_x->tim_clk_out, INT_CLKO, 2);
            break;
        case TIM_NUM_3:
            out_clk(timer_x->tim_clk_out, T4T3M, 0);
            break;
        case TIM_NUM_4:
            out_clk(timer_x->tim_clk_out, T4T3M, 4);
            break;
        default:
            break;
    }
}

#define polity_set(tim_polity, PTx)              \
    do {                                         \
        if (tim_polity == INT_POLITY_HIGHT)      \
            PTx = 1;                             \
        else                                     \
            PTx = 0;                             \
    } while(0)

static inline void timer_set_polity(timer_init_t *timer_x)
{
    switch (timer_x->tim_num) {
        case TIM_NUM_0:
            polity_set(timer_x->tim_polity, PT0);
            break;
        case TIM_NUM_1:
            polity_set(timer_x->tim_polity, PT1);
            break;
        // T2、T3、T4固定为低优先级
        default:
            break;
    }
}

#define mode_set(tim_mode, bit) TMOD = (TMOD & ~(0x03 << bit)) | tim_mode

static inline int8_t timer_set_mode(timer_init_t *timer_x)
{
    if (timer_x->tim_mode >= TIM_MODE_MAX)
        return -1;

    switch (timer_x->tim_num) {
        case TIM_NUM_0:
            mode_set(timer_x->tim_mode, 0);
            break;
        case TIM_NUM_1:
            if (timer_x->tim_mode >= TIM_MODE_16BitAutoReloadNoMask)
                return -2;
            mode_set(timer_x->tim_mode, 4);
            break;
        // T2、T3、T4固定为16位自动重装载模式
        default:
            break;
    }

    return 0;
}

#define clk_set(tim_clk_source, reg, bit)   \
    do {                                    \
        if (tim_clk_source == TIM_CLK_12T)  \
            reg &= ~(0x1 << bit);           \
        else                                \
            reg |=  (0x1 << bit);           \
    } while(0)

static inline void timer_set_clk(timer_init_t *timer_x)
{
    switch (timer_x->tim_num) {
        case TIM_NUM_0:
            clk_set(timer_x->tim_clk_source, AUXR, 7);
            break;
        case TIM_NUM_1:
            clk_set(timer_x->tim_clk_source, AUXR, 6);
            break;
        case TIM_NUM_2:
            clk_set(timer_x->tim_clk_source, AUXR, 2);
            break;
        case TIM_NUM_3:
            clk_set(timer_x->tim_clk_source, T4T3M, 1);
            break;
        case TIM_NUM_4:
            clk_set(timer_x->tim_clk_source, T4T3M, 5);
            break;
        default:
            break;
    }
}

#define cnt_timer_set(tim_cnt_timer, reg, bit) \
    do {                                    \
        if (tim_cnt_timer == TIM_CNT)       \
            reg |=  (0x1 << bit);           \
        else                                \
            reg &= ~(0x1 << bit);           \
    } while(0)

static inline void timer_set_cnt_timer(timer_init_t *timer_x)
{
    switch (timer_x->tim_num) {
        case TIM_NUM_0:
            cnt_timer_set(timer_x->tim_clk_source, TMOD, 2);
            break;
        case TIM_NUM_1:
            cnt_timer_set(timer_x->tim_clk_source, TMOD, 6);
            break;
        case TIM_NUM_2:
            cnt_timer_set(timer_x->tim_clk_source, AUXR, 3);
            break;
        case TIM_NUM_3:
            cnt_timer_set(timer_x->tim_clk_source, T4T3M, 2);
            break;
        case TIM_NUM_4:
            cnt_timer_set(timer_x->tim_clk_source, T4T3M, 6);
            break;
        default:
            break;
    }
}

static inline void timer_stop_running(timer_init_t *timer_x)
{
    switch (timer_x->tim_num) {
        case TIM_NUM_0:
            TR0 = 0;
            break;
        case TIM_NUM_1:
            TR1 = 0;
            break;
        case TIM_NUM_2:
            AUXR &= ~(0x1 << 4);
            break;
        case TIM_NUM_3:
            T4T3M &= ~(0x1 << 3);
            break;
        case TIM_NUM_4:
            T4T3M &= ~(0x1 << 7);
            break;
        default:
            break;
    }
}

static inline void timer_set_running(timer_init_t *timer_x)
{
    switch (timer_x->tim_num) {
        case TIM_NUM_0:
            if (timer_x->tim_is_run == ENABLE)
                TR0 = 1;
            break;
        case TIM_NUM_1:
            if (timer_x->tim_is_run == ENABLE)
                TR1 = 1;
            break;
        case TIM_NUM_2:
            AUXR |= (0x1 << 4);
            break;
        case TIM_NUM_3:
            T4T3M |= (0x1 << 3);
            break;
        case TIM_NUM_4:
            T4T3M |= (0x1 << 7);
            break;
        default:
            break;
    }
}

int8_t timer_init(timer_init_t *timer_x)
{
    int8_t ret;

    if (timer_x->tim_num >= TIM_NUM_MAX || !timer_x) {
        return -1;
    }

    timer_stop_running(timer_x);

    ret = timer_set_mode(timer_x);
    timer_set_polity(timer_x);
    timer_enable_int(timer_x);
    timer_set_clk(timer_x);
    timer_set_cnt_timer(timer_x);
    timer_out_clk(timer_x);
    timer_set_value(timer_x);

    timer_set_running(timer_x);

    return ret;
}

void delay02s(void)
{
    unsigned char i,j,k;

    for(i=250; i>0; i--)
        for(j=250; j>0; j--)
            for(k=248; k>0; k--);
}

