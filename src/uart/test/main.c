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

#include <stc15wxxxx.h>

// int main(void)
// {
    // return 0;
// }

//串口通讯实验
//只发数据
//波特率9600
//主频11.0592

char  __code  MESSAGE[]= "123456";

void delay(unsigned int m)
    {
	  int  a=0,b=0;
	  for(a=0;a<500;a++)
	  for(b=0;b<m;b++);

	}


void ISP_Check()
{
  unsigned char a;

	  a=0;
	   while(MESSAGE[a]!= '\0')
   	   {
		SBUF = MESSAGE[a];	        //SUBF接受/发送缓冲器(又叫串行通信特殊功能寄存器)
         while(!TI);				// 等特数据传送	(TI发送中断标志)
		 TI = 0;					// 清除数据传送标志

		a++;					    // 下一个字符
       }


     }



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


void main()
{
    IO_init();				   //真对 IAP15W4K61S4  IO口初始化
    P5_5=1;

    SCON = 0x50;       //REN=1允许串行接受状态，串口工作模式2
    TMOD= 0x20;      //定时器工作方式2       8位 自动重装载定时器  实现波特率

    // AUXR=0X40;		 //开启1T模式


    TH1 =TL1= 0xDC;			//  设置波特率为9600  公式 TH1=256-(11059200/32/9600)=256-36=220  0xDC
    // 如有不明白请查 STC15手册上有详细说明

    TR1  = 1;        //开启定时器1
    EA   = 1;        // 开总中断

    while(1)
    {
        ISP_Check();
        delay(1000);
    }

}

