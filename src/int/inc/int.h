/**
 *
 * Release under GPLv2.
 * 
 * @file    int.h
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    01/11 2018 10:29
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        01/11 2018      create the file
 * 
 *     last modified: 01/11 2018 10:29
 */
#ifndef __SC_INT_H_
#define __SC_INT_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef SC_INT_GB
#define SC_INT_EX extern
#else
#define SC_INT_EX
#endif

typedef enum {
    INT_MODE_RISING_AND_FALLING = 0,
    INT_MODE_FALLING,

    INT_MODE_MAX
}int_mode_t;

typedef enum {
    INT_NUM_0 = 0,
    INT_NUM_1,
    INT_NUM_2,
    INT_NUM_3,
    INT_NUM_4,

    INT_NUM_MAX
}int_num_t;

typedef struct {
    int8_t int_mode;            // 中断模式
    int8_t int_polity;          // 中断优先级
    int8_t int_is_interrupt;    // 是否允许中断
} int_init_t;

SC_INT_EX int8_t int_init(int_num_t int_num, int_init_t *int_init_x);

#if 0
#define _INT_IT(num, trigger_mode)   IT##num = trigger_mode
#define _INT_EX(num)                 EX##num = 1 

#define INT_IT(num, trigger_mode)    _INT_IT(num, trigger_mode)
#define INT_EX(num)                  _INT_EX(num)

#define int_init(int_num, trigger_mode) \
    do {                                \
        INT_IT(int_num, trigger_mode);  \
        INT_EX(int_num);                \
    } while(0)

SC_INT_EX char int0_get_flag(void);
SC_INT_EX void int0_set_flag(void);
SC_INT_EX void int0_isr(void) __interrupt 0;
#endif

#ifdef __cplusplus
}
#endif

#endif /* __SC_INT_H_ */

