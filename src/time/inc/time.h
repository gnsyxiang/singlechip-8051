/**
 *
 * Release under GPLv2.
 * 
 * @file    time.h
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    30/10 2018 19:48
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        30/10 2018      create the file
 * 
 *     last modified: 30/10 2018 19:48
 */
#ifndef __SC_TIME_H_
#define __SC_TIME_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef SC_TIME_GB
#define SC_TIME_EX extern
#else
#define SC_TIME_EX
#endif

#include <stdint.h>

typedef enum {
    TIM_NUM_0 = 0,
    TIM_NUM_1,
    TIM_NUM_2,
    TIM_NUM_3,
    TIM_NUM_4,

    TIM_NUM_MAX
} TIM_NUM_t;

typedef enum {
    TIM_MODE_16BitAutoReload = 0,
    TIM_MODE_16Bit,
    TIM_MODE_8BitAutoReload,
    TIM_MODE_16BitAutoReloadNoMask,

    TIM_MODE_MAX
} TIM_MODE_t;

typedef enum {
    TIM_POLITY_HIGHT = 0,
    TIM_POLITY_LOW,

    TIM_POLITY_MAX
} TIM_POLITY_t;

typedef enum {
    TIM_CLK_1T = 0,
    TIM_CLK_12T,

    TIM_CLK_MAX
} TIM_CLK_t;

typedef enum {
    TIM_CNT = 0,
    TIM_TIMER,

    TIM_MAX
} TIM_CNT_TIMER_t;

typedef struct timer_init {
    TIM_NUM_t tim_num;          // 定时器x

    int8_t tim_mode;            // 工作模式
    int8_t tim_polity;          // 优先级
    int8_t tim_interrupt;       // 中断允许
    int8_t tim_clk_source;      // 时钟源
    int8_t tim_cnt_timer;       // 定时器/计数器选择
    int8_t tim_clk_out;         // 可编程时钟输出
    int8_t tim_value_ms;        // 装载初值
    int8_t tim_is_run;          // 是否运行
} timer_init_t;

SC_TIME_EX int8_t timer_init(timer_init_t *timer_init);

SC_TIME_EX void delay02s(void);

#ifdef __cplusplus
}
#endif

#endif /* __SC_TIME_H_ */

