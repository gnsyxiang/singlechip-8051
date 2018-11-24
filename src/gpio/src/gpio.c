/**
 * 
 * Release under GPLv2.
 * 
 * @file    gpio.c
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    31/10 2018 11:34
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        31/10 2018      create the file
 * 
 *     last modified: 31/10 2018 11:34
 */
#include <stdio.h>
#include <stdint.h>

#include <stc15wxxxx.h>

#define SC_GPIO_GB
#include "gpio.h"
#undef SC_GPIO_GB

#define set_gpio_type(gpio_init_x, PxM1, PxM0)  \
    do {                                        \
        switch (gpio_init_x->mode) {            \
            case GPIO_TYPE_PULL_UP:             \
                PxM1 &= ~gpio_init_x->pin;      \
                PxM0 &= ~gpio_init_x->pin;      \
                break;                          \
            case GPIO_TYPE_HIGH_Z:              \
                PxM1 |=  gpio_init_x->pin;      \
                PxM0 &= ~gpio_init_x->pin;      \
                break;                          \
            case GPIO_TYPE_OUT_OD:              \
                PxM1 |=  gpio_init_x->pin;      \
                PxM0 |=  gpio_init_x->pin;      \
                break;                          \
            case GPIO_TYPE_OUT_PP:              \
                PxM1 &= ~gpio_init_x->pin;      \
                PxM0 |=  gpio_init_x->pin;      \
                break;                          \
            default:                            \
                break;                          \
        }                                       \
    } while(0)

int8_t gpio_init(gpio_group_t gpio_group, gpio_init_t *gpio_init_x)
{
    if (gpio_group >= GPIO_PX_MAX || !gpio_init_x) {
        return -1;
    }

    switch (gpio_group) {
        case GPIO_P0: set_gpio_type(gpio_init_x, P0M1, P0M0); break;
        case GPIO_P1: set_gpio_type(gpio_init_x, P1M1, P1M0); break;
        case GPIO_P2: set_gpio_type(gpio_init_x, P2M1, P2M0); break;
        case GPIO_P3: set_gpio_type(gpio_init_x, P3M1, P3M0); break;
        case GPIO_P4: set_gpio_type(gpio_init_x, P4M1, P4M0); break;
        case GPIO_P5: set_gpio_type(gpio_init_x, P5M1, P5M0); break;
        default:
            break;
    }
    
    return 0;
}

/*
 * 针对 IAP15W4K61S4，STC15W4K56S4 系列IO口初始化
 * io口初始化 P0 P1 P2 P3 P4 为准双向IO口
 * 注意: STC15W4K32S4系列的芯片,上电后所有与PWM相关的IO口均为
 *       高阻态,需将这些口设置为准双向口或强推挽模式方可正常使用
 * 相关IO: P0.6/P0.7/P1.6/P1.7/P2.1/P2.2
 *         P2.3/P2.7/P3.7/P4.2/P4.4/P4.5
 */
void gpio_init_default(void)
{
    gpio_init_t gpio_init_x;

    gpio_init_x.mode = GPIO_TYPE_PULL_UP;
    gpio_init_x.pin  = GPIO_PIN_ALL;

    for (gpio_group_t i = 0; i < GPIO_PX_MAX; i++) {
        gpio_init(i, &gpio_init_x);
    }
}

