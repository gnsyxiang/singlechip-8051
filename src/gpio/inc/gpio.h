/**
 *
 * Release under GPLv2.
 * 
 * @file    gpio.h
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    31/10 2018 11:33
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        31/10 2018      create the file
 * 
 *     last modified: 31/10 2018 11:33
 */
#ifndef __SC_GPIO_H_
#define __SC_GPIO_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#ifndef SC_GPIO_GB
#define SC_GPIO_EX extern
#else
#define SC_GPIO_EX
#endif

typedef enum {
    GPIO_TYPE_PULL_UP = 0,       // 上拉准双向口
    GPIO_TYPE_HIGH_Z,            // 浮空输入
    GPIO_TYPE_OUT_OD,            // 开漏输出
    GPIO_TYPE_OUT_PP,            // 推挽输出

    GPIO_TYPE_MAX
} gpio_type_t;

typedef enum {
    GPIO_PIN_0 = 0x01,
    GPIO_PIN_1 = 0x02,
    GPIO_PIN_2 = 0x04,
    GPIO_PIN_3 = 0x08,
    GPIO_PIN_4 = 0x10,
    GPIO_PIN_5 = 0x20,
    GPIO_PIN_6 = 0x40,
    GPIO_PIN_7 = 0x80,

    GPIO_PIN_ALL = 0xFF,
} gpio_pin_t;

typedef enum {
    GPIO_P0 = 0,
    GPIO_P1,
    GPIO_P2,
    GPIO_P3,
    GPIO_P4,
    GPIO_P5,

    GPIO_PX_MAX
} gpio_group_t;

typedef struct {
    uint8_t mode;
    uint8_t pin;
} gpio_init_t;

SC_GPIO_EX int8_t gpio_init(gpio_group_t gpio_group, gpio_init_t *gpio_init_x);
SC_GPIO_EX void gpio_init_default(void);

#ifdef __cplusplus
}
#endif

#endif /* __SC_GPIO_H_ */

