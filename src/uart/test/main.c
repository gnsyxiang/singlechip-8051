/**
 * 
 * Release under GPLv2.
 * 
 * @file    main.c
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    31/10 2018 17:22
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        31/10 2018      create the file
 * 
 *     last modified: 31/10 2018 17:22
 */
#include <stdio.h>

#include <common.h>
#include <stc15wxxxx.h>

#include <uart/uart.h>
#include <time/time.h>

// char putchar(char ch)
// {
    // tx1_write2buff(ch);
//
    // return ch;
// }

#if 1
char putchar(char c)
{
    SBUF = c;
    while (TI == 0);
    TI = 0;
    return c;
}

uint8_t main(void)
{
    RED_LED = 1;
    uart_conf_t uart_conf;

    uart_conf.mode              = UART_MODE_8BIT_BRTx;
    uart_conf.more_communicate  = DISABLE;
    uart_conf.rx_enable         = ENABLE;
    uart_conf.is_interrupt      = ENABLE;

    uart_conf.rate              = 115200UL;
    uart_conf.use_rate          = TIM_NUM_1;
    uart_conf.rate_double       = DISABLE;

    uart_conf.polity            = INT_POLITY_HIGHT;
    uart_conf.port_sw           = UART1_PORT_SW_P30_P31;
    uart_conf.is_rxd_txd        = DISABLE;

    uart_init(UART_NUM_1, &uart_conf);

    EA   = 1;        // 开总中断

    putchar('b');

    return 0;
}

#else

char  __code  MESSAGE[]= "我爱单片机 ";	//定义到程序空间中


//真对 IAP15W4K61S4   STC15W4K56S4 系列 IO口初始化
//io口初始化 P0 P1 P2 P3 P4 为准双向IO口
//注意: STC15W4K32S4系列的芯片,上电后所有与PWM相关的IO口均为
//      高阻态,需将这些口设置为准双向口或强推挽模式方可正常使用
//相关IO: P0.6/P0.7/P1.6/P1.7/P2.1/P2.2
//        P2.3/P2.7/P3.7/P4.2/P4.4/P4.5
void IO_init(void)
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

void delay(unsigned int m)				//延时函数
    {
	  int  a=0,b=0;
	  for(a=0;a<500;a++)
	  for(b=0;b<m;b++);

	}

void ISP_Check()						//串口发送调用函数
{
  unsigned char a;

     IO_init();  //真对 IAP15W4K61S4  IO口初始化

	  a=0;
	   while(MESSAGE[a]!= '\0')
   	   {
		SBUF = MESSAGE[a];	        //SUBF接受/发送缓冲器(又叫串行通信特殊功能寄存器)
         while(!TI);				// 等特数据传送	(TI发送中断标志)
		 TI = 0;					// 清除数据传送标志

		a++;					    // 下一个字符
       }
}

void main() 			 //主函数
{

    SCON=0x50;        //REN=1允许串行接受状态，串口工作模式2
    TMOD= 0x00;       //定时器1为模式0（16位自动重载）
    AUXR=0X40;		 //开启1T模式
    TL1=(65535-(11059200/4/115200)) & 0xff;    //设置波特率重装值
    TH1=(65535-(11059200/4/115200))>>8;

    TR1  = 1;        //开启定时器1
    EA   = 1;        // 开总中断
    int8_t cnt = 0;

    while(1) {
        if (cnt++ > 3) {
            TR1 = 0;
            RED_LED = 0;
            break;
        }
        ISP_Check();	 //发送数据
        delay(1000);	 //延时
    }
}
#endif

