/**
 * 
 * Release under GPLv2.
 * 
 * @file    led-drv.c
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
#include <stdio.h>

#include <stc15w404as.h>

#define SC_LED_DRV_GB
#include "led-drv.h"
#undef SC_LED_DRV_GB

#define RED_LED     P5_5

void led_init(void)
{
    RED_LED = 1;
}

void led_on(void)
{
    RED_LED = 0;
}

void led_off(void)
{
    RED_LED = 1;
}

