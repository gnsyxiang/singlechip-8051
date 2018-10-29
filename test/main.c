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

#include "stc15w404as.h"

#include "time.h"

void main(void)
{
    while (1) {

        P1_0=0;
        delay02s();

        P1_0=1;
        delay02s();
    }
}

