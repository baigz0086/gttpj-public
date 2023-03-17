/*******************************Copyright (c)***********************************
**                          佛山三俊电子有限公司 
**				    	       智能电气事业部 
**--------------文件信息--------------------------------------------------------
**文   件   名: Time.C
**创   建   人: 
**创 建 日 期 ： 
**描        述: 
**--------------当前版本修订---------------------------------------------------
** 修改人: 
** 日　期: 
** 描　述: 
**
*******************************************************************************/
#define TX_GLOBALS

#include "Includes.h"




/*----------------------------
软件延时
----------------------------
void Delay(INT16U n)
{
    INT16U x;

    while (n--)
    {
        x = 5000;
        while (x--);
    }
}
*/

/**************************************************************************************************
**	函数名称:	Time0_Init()
**	功	能	:	Time0  用于主时钟定时中断，每1MS产生一次中断 
**	入口参数:	无 
**	出口参数:	无 
**  返回值  ：  无 
**	全局变量:	无 
**	调用模块:	无 
**	作	者	:
**	日	期	:	
**************************************************************************************************/
void Time0_Init(void)
{
//	AUXR |= 0x80;                   //定时器0为1T模式 
//	AUXR &= ~0x80;                   //定时器0为12T模式 

//    TMOD = 0x00;                    //设置定时器为模式0(16位自动重装载)
	
	TL0 = NORMAL_BASICTIME;       //初始化计时值 
 	TH0 = (unsigned char)(NORMAL_BASICTIME / 256);
	
    TR0 = 1;                        //定时器0开始计时 
    ET0 = 1;                        //使能定时器0中断 

}
/**************************************************************************************************
**	函数名称:	TimeE_Int()
**	功	能	:	定时器E中断处理程序,1ms执行1次 
**	入口参数:	无 
**	出口参数:	无 
**  返回值  ：  无 
**	全局变量:	无 
**	调用模块:	无 
**	作	者	:	
**	日	期	:	
**************************************************************************************************/
/* Timer0 interrupt routine */
void tm0_isr() interrupt 1 using 1
{
	bDo10ms = 1;
}


void Do10ms(void)
{
	bDo10ms = 0;
	
	Uart1NoRecTime++;
	Uart2NoRecTime++;
	
	if(WaitSensorData) WaitSensorData--;
	if(WaitSendWifi) WaitSendWifi--;
	
	Counter_To_100MS++;
	if(Counter_To_100MS >= 10)
	{
		Counter_To_100MS = 0;
		bDo100ms = 1;

		
		
		
	}
}


void Do100ms(void)
{			
	static  INT8U   Counter_To_1S;
	
	bDo100ms = 0;
	
	//fTime();
	
	
	if(bWaitRecSensor)
	{
		RecSensorOverTime++;
		
	}
	
	if(ReplayServerCount) ReplayServerCount--;
	
	oLED = 1;
	
    Counter_To_500mS++;
    if(Counter_To_500mS >= 5)
    {
        Counter_To_500mS = 0;

        bFlash ^= 1;

			
    }	

    
    Counter_To_1S++;
    if(Counter_To_1S >= 10)
    {
			fTime();  // chg 20220305
      Counter_To_1S   = 0;

		  bFlash1S ^= 1;	
		
		  if(StepCommWifi == WIFI_POWERON)
			{
				if(iapRead(WIFI_SETTED_FLAG) == 99){
					StepCommWifi = WIFI_WMAC_SEC;
				}else{
					StepCommWifi = WIFI_APPLY_AT;
				}
			}
			
    }	
}
   