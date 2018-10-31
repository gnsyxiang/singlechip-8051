/**
 * 
 * Release under GPLv2.
 * 
 * @file    main.c
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    29/10 2018 16:29
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        29/10 2018      create the file
 * 
 *     last modified: 29/10 2018 16:29
 */
#include <stdio.h>

#include <time/time.h>
#include <io/io.h>
#include <led-drv/led-drv.h>

#include <stc15wxxxx.h>

#define DELAY_TIME_MS  (1 * 1000)

void main(void)
{
    unsigned long ticks;
    static unsigned long old_ticks;

    io_init();
    led_init();
    time0_init();

    old_ticks = ticks = time0_get_ticks();

    EA = 1;
    
    while (1) {
        ticks = time0_get_ticks();
        if (ticks - old_ticks > DELAY_TIME_MS) {
            old_ticks = ticks;
            led_trigger();
        }
    }
}

