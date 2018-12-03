/**
 * 
 * Release under GPLv2.
 * 
 * @file    main.c
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    02/12 2018 20:30
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        02/12 2018      create the file
 * 
 *     last modified: 02/12 2018 20:30
 */
#include <stdio.h>

#include <common.h>
#include <stc15wxxxx.h>

#include <time/time.h>

#define INT0_IO P3_2

#define RED_LED P5_5
#define RESET_KEY P3_4

unsigned volatile int time_cnt = 0;

void timer0_ISR(void) __interrupt 1
{
    time_cnt++;
}

void sys_init(void)
{
    timer_init_t timer_0;

    timer_0.tim_num         = TIM_NUM_0;
    timer_0.tim_mode        = TIM_MODE_16BitAutoReload;
    timer_0.tim_polity      = TIM_POLITY_HIGHT;
    timer_0.tim_interrupt   = ENABLE;
    timer_0.tim_clk_source  = TIM_CLK_12T;
    timer_0.tim_cnt_timer   = TIM_TIMER;
    timer_0.tim_clk_out     = DISABLE;
    timer_0.tim_value_ms    = 50;
    timer_0.tim_is_run      = DISABLE;

    timer_init(&timer_0);

    EA = 1;

	RED_LED = 1;
	RESET_KEY = 0;
}

void main(void)
{
	char int0_flag = 0;
	char key_flag = 0;
	char int0_hight_flag = 0;

    sys_init();

	while (1) {
		INT0_IO = 1;

		if (int0_hight_flag && !key_flag && INT0_IO == 0) {
			delay_ms(10);
			if (INT0_IO == 0) {				
				key_flag = 1;
				 
				int0_flag = 1;
				TR0 = 1;
			}	
		}

		if (INT0_IO == 0) {
			delay_ms(10);
			if (INT0_IO == 0) {
				int0_hight_flag = 1;
			}
		} else {
			int0_hight_flag = 0;		//排除由低到高电平变化
			key_flag = 0;
            key_flag = 0;
            int0_flag = 0;
            TR0 = 0;
            time_cnt = 0;
		}

        if (int0_flag && time_cnt == 20 * 60) {
            time_cnt = 0;
            int0_flag = 0;

            TR0 = 0; 				// 排除从高到低后，触发一次后，定时器一直运行

            RED_LED = 0;
            RESET_KEY = 1;
            delay_ms(5000);

            RED_LED = 1;
            RESET_KEY = 0;
            delay_ms(1000);
        }
	}
}

