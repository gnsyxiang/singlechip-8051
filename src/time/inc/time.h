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

SC_TIME_EX void delay02s(void);

#ifdef __cplusplus
}
#endif

#endif /* __SC_TIME_H_ */

