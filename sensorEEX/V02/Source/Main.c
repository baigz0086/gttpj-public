/***********************************************************************/
/*                                                                     */
/*  FILE        :UL1.c                                    		       */
/*  DATE        :2019-02-10				                               */
/*  DESCRIPTION :main program file.                                    */
/*  CPU GROUP   :STC8F2K16S2                                           */
/*                                                                     */
/***********************************************************************/

/*
�������
1.����MCUΪSTC8F2K16S2
2.�����°�IO��
3.���Ĵ��ڷ��䣬UART1 MOD1 TO mcu BUD 57600,UART2 TO WIFI BUD 115200
4.����ʱ��� https://www.jianshu.com/p/83ffccc5215e
�꣬�£��գ�ʱ���֣��룬ʮ����

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
