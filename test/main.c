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

#include <io/io.h>
#include <int/int.h>
#include <uart/uart.h>
#include <time/time.h>
#include <led-drv/led-drv.h>

#include <sys_tick.h>

#include <common.h>
#include <stc15wxxxx.h>

void main(void)
{
    unsigned long cnt = 0;
    static unsigned long cnt_old = 0;

    sys_tick_init();

    EA = 1;
    
    while (1) {
        cnt = sys_tick_get();
        if (cnt - cnt_old >= 1000) {
            cnt_old = cnt;
            RED_LED = !RED_LED;
        }
    }
}

