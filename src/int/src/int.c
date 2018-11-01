/**
 * 
 * Release under GPLv2.
 * 
 * @file    int.c
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    01/11 2018 10:29
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        01/11 2018      create the file
 * 
 *     last modified: 01/11 2018 10:29
 */
#include <stdio.h>

#include <stc15wxxxx.h>

#define SC_INT_GB
#include "int.h"
#undef SC_INT_GB

static char volatile int0_flag = 0;

void int0_isr(void) __interrupt 0
{
    int0_flag++;
}

char int0_get_flag(void)
{
    return int0_flag;
}

void int0_set_flag(void)
{
    int0_flag = 0;
}

