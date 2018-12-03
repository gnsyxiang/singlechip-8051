/**
 * 
 * Release under GPLv2.
 * 
 * @file    main.c
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    30/10 2018 21:28
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        30/10 2018      create the file
 * 
 *     last modified: 30/10 2018 21:28
 */
#include <stdio.h>

#include <time/time.h>

#include "led-drv.h"

int main(void)
{
    led_init();

    while (1) {
        led_on();
        delay_ms(500);

        led_off();
        delay_ms(500);
    }

    return 0;
}
