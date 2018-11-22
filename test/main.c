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

#include <stc15wxxxx.h>

#define CMD_RED_LED     P5_4

#define DELAY_TIME_MS_HIGHT  (1 * 1000)
#define DELAY_TIME_MS_LOW    (2 * 1000)

void cmd_red(void)
{
    static unsigned long old_ticks;
    unsigned long ticks;
    static unsigned char state = 0;

    ticks = time0_get_ticks();

    switch (state) {
        case 0:
            old_ticks = ticks;
            state = 1;
            break;

        case 1:
            if (ticks - old_ticks > DELAY_TIME_MS_HIGHT) {
                old_ticks = ticks;
                state = 2;

                CMD_RED_LED = 1;
            }
            break;
        case 2:
            if (ticks - old_ticks > DELAY_TIME_MS_LOW) {
                old_ticks = ticks;
                state = 1;

                CMD_RED_LED = 0;
            }
            break;
        default:
            break;
    }
}

void con_red_led(void)
{
    static unsigned long old_ticks;
    unsigned long ticks;
    static unsigned char state;

    ticks = time0_get_ticks();

    switch (state) {
        case 0:
            old_ticks = ticks;
            state = 1;
            break;
        case 1:
            if (int0_get_flag() 
                    && ticks - old_ticks > DELAY_TIME_MS_HIGHT) {
                old_ticks = ticks;
                state = 2;

                int0_set_flag();
                led_on();
                printf("-1-hahahaha\r\n");
            }
            break;
        case 2:
            if (int0_get_flag() 
                    && ticks - old_ticks > DELAY_TIME_MS_HIGHT) {
                old_ticks = ticks;
                state = 1;

                int0_set_flag();
                led_off();
                printf("-2-hahahaha\r\n");
            }
            break;
        default:
            break;
    }
}

void main(void)
{
    io_init();

    led_init();
    time0_init();
    int_init(0, INT_FALLING_EDGE_TRIGGER);
    uart1_init();

    EA = 1;
    
    while (1) {

        cmd_red();
        con_red_led();
    }
}

