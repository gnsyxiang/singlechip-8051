/**
 * 
 * Release under GPLv2.
 * 
 * @file    time.c
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    29/10 2018 16:28
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        29/10 2018      create the file
 * 
 *     last modified: 29/10 2018 16:28
 */
#include <stdio.h>

void delay02s(void)
{
    unsigned char i,j,k;

    for(i=20; i>0; i--)
        for(j=20; j>0; j--)
            for(k=248; k>0; k--);
}

