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
#include <stdint.h>

#include <common.h>
#include <stc15wxxxx.h>

#define SC_INT_GB
#include <int/int.h>
#undef SC_INT_GB

#if 0
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
#endif

int8_t int_init(int_num_t int_num, int_init_t *int_init_x)
{
    if (int_num > INT_NUM_MAX)
        return -1;

    switch (int_num) {
        case INT_NUM_0:
            reg_set1(int_init_x->int_mode, INT_MODE_FALLING, IT0);
            reg_set1(int_init_x->int_polity, INT_POLITY_HIGHT, PX0);
            reg_set1(int_init_x->int_is_interrupt, ENABLE, EX0);

            break;
        case INT_NUM_1:
            reg_set1(int_init_x->int_mode, INT_MODE_FALLING, IT1);
            reg_set1(int_init_x->int_polity, INT_POLITY_HIGHT, PX1);
            reg_set1(int_init_x->int_is_interrupt, ENABLE, EX1);

            break;
        //外中断2、3、4，固定为下降沿低优先级中断
        case INT_NUM_2:
            reg_set(int_init_x->int_is_interrupt, ENABLE, INT_CLKO, 4);

            break;
        case INT_NUM_3:
            reg_set(int_init_x->int_is_interrupt, ENABLE, INT_CLKO, 5);

            break;
        case INT_NUM_4:
            reg_set(int_init_x->int_is_interrupt, ENABLE, INT_CLKO, 6);

            break;
        default:
            break;
    }

    return 0;
}

