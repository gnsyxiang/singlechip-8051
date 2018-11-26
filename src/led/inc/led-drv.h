/**
 *
 * Release under GPLv2.
 * 
 * @file    led-drv.h
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    30/10 2018 21:24
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        30/10 2018      create the file
 * 
 *     last modified: 30/10 2018 21:24
 */
#ifndef __SC_LED_DRV_H_
#define __SC_LED_DRV_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef SC_LED_DRV_GB
#define SC_LED_DRV_EX extern
#else
#define SC_LED_DRV_EX
#endif

SC_LED_DRV_EX void led_init(void);

SC_LED_DRV_EX void led_off(void);
SC_LED_DRV_EX void led_on(void);
SC_LED_DRV_EX void led_trigger(void);

#ifdef __cplusplus
}
#endif

#endif /* __SC_LED_DRV_H_ */

