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
    INT_RISING_AND_FALLING_EDGE_TRIGGER,
    INT_FALLING_EDGE_TRIGGER,

    INT_EDGE_MAX
}int_trigger_mode_t;

typedef enum {
    INT_NUM_0 = 0,

    INT_NUM_MAX
}int_num_t;

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

#ifdef __cplusplus
}
#endif

#endif /* __SC_INT_H_ */

