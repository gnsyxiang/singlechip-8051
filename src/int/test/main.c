/**
 * 
 * Release under GPLv2.
 * 
 * @file    main.c
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    01/11 2018 10:44
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        01/11 2018      create the file
 * 
 *     last modified: 01/11 2018 10:44
 */
#include <stdio.h>
#include <stdint.h>

#include <int/int.h>

#include <stc15wxxxx.h>
#include <hwconfig.h>
#include <common.h>

void int0_ISR(void) __interrupt 0
{
    RED_LED = !RED_LED;
}

void int1_ISR(void) __interrupt 2
{
    RED_LED = !RED_LED;
}

int8_t main(void)
{
    int_init_t int_init_0;

    int_init_0.int_mode         = INT_MODE_FALLING;
    int_init_0.int_polity       = INT_POLITY_HIGHT;
    int_init_0.int_is_interrupt = ENABLE;

    int_init(INT_NUM_1, &int_init_0);

    EA = 1;

    while (1) {
    
    }

    return 0;
}

