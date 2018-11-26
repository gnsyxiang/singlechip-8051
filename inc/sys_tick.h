/**
 *
 * Release under GPLv2.
 * 
 * @file    sys_tick.h
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    23/11 2018 16:22
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        23/11 2018      create the file
 * 
 *     last modified: 23/11 2018 16:22
 */
#ifndef __SC_SYS_TICK_H_
#define __SC_SYS_TICK_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef SC_SYS_TICK_GB
#define SC_SYS_TICK_EX extern
#else
#define SC_SYS_TICK_EX
#endif

SC_SYS_TICK_EX void sys_tick_init(void);
SC_SYS_TICK_EX void timer0_ISR(void) __interrupt 1;
SC_SYS_TICK_EX unsigned long sys_tick_get(void);

#ifdef __cplusplus
}
#endif

#endif /* __SC_SYS_TICK_H_ */

