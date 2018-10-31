/**
 * 
 * Release under GPLv2.
 * 
 * @file    io.c
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    31/10 2018 11:34
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        31/10 2018      create the file
 * 
 *     last modified: 31/10 2018 11:34
 */
#include <stdio.h>

#include <stc15w404as.h>

/*
 * 针对 IAP15W4K61S4，STC15W4K56S4 系列IO口初始化
 * io口初始化 P0 P1 P2 P3 P4 为准双向IO口
 * 注意: STC15W4K32S4系列的芯片,上电后所有与PWM相关的IO口均为
 *       高阻态,需将这些口设置为准双向口或强推挽模式方可正常使用
 * 相关IO: P0.6/P0.7/P1.6/P1.7/P2.1/P2.2
 *         P2.3/P2.7/P3.7/P4.2/P4.4/P4.5
 */
void io_init(void)
{
  P0M0 = 0X00;
  P0M1 = 0X00;

  P1M0 = 0X00;
  P1M1 = 0X00;

  P2M0 = 0X00;
  P2M1 = 0X00;

  P3M0 = 0X00;
  P3M1 = 0X00;

  P4M0 = 0X00;
  P4M1 = 0X00;
}

