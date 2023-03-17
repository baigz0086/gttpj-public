/***********************************************************************/
/*                                                                     */
/*  FILE        :UL1.c                                    		       */
/*  DATE        :2019-02-10				                               */
/*  DESCRIPTION :main program file.                                    */
/*  CPU GROUP   :STC8F2K16S2                                           */
/*                                                                     */
/***********************************************************************/

/*
软件更改
1.更改MCU为STC8F2K16S2
2.更改新板IO口
3.更改串口分配，UART1 MOD1 TO mcu BUD 57600,UART2 TO WIFI BUD 115200
4.增加时间戳 https://www.jianshu.com/p/83ffccc5215e
年，月，日，时，分，秒，十分秒

191120 communication board add 100k resistence at keyin IO port.
       Programs add SmartLink function, start this function when press the sw1 key at time < 2 seconds.
       Link indicator flashes while smartlink process, and the indicator light stops flashing 
			 after successful setting. 


*/

#include "Includes.h"

void main(void)
{
	Control_Init();         
    while(1)
	{
		ConFunction();
	}
}
