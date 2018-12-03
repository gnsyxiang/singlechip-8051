/**
 *
 * Release under GPLv2.
 * 
 * @file    hwconfig.h
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    23/11 2018 10:51
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        23/11 2018      create the file
 * 
 *     last modified: 23/11 2018 10:51
 */
#ifndef __SC_HWCONFIG_H_
#define __SC_HWCONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif

#define CFG_SYS_CLK 	(11059200UL)
// #define CFG_SYS_CLK 	(22118400UL)
// #define CFG_SYS_CLK 	(24000000UL)

#define CFG_SYS_TICK_MS (1)

#define RED_LED     P5_5

#ifdef __cplusplus
}
#endif

#endif /* __SC_HWCONFIG_H_ */

