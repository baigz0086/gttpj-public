/*******************************Copyright (c)***********************************
**                          ��ɽ�����������޹�˾ 
**				    	       ���ܵ�����ҵ�� 
**--------------�ļ���Ϣ--------------------------------------------------------
**��   ��   ��: Time.C
**��   ��   ��: 
**�� �� �� �� �� 
**��        ��: 
**--------------��ǰ�汾�޶�---------------------------------------------------
** �޸���: 
** �ա���: 
** �衡��: 
**
*******************************************************************************/
#define TX_GLOBALS

#include "Includes.h"




/*----------------------------
�����ʱ
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
**	��������:	Time0_Init()
**	��	��	:	Time0  ������ʱ�Ӷ�ʱ�жϣ�ÿ1MS����һ���ж� 
**	��ڲ���:	�� 
**	���ڲ���:	�� 
**  ����ֵ  ��  �� 
**	ȫ�ֱ���:	�� 
**	����ģ��:	�� 
**	��	��	:
**	��	��	:	
**************************************************************************************************/
void Time0_Init(void)
{
//	AUXR |= 0x80;                   //��ʱ��0Ϊ1Tģʽ 
//	AUXR &= ~0x80;                   //��ʱ��0Ϊ12Tģʽ 

//    TMOD = 0x00;                    //���ö�ʱ��Ϊģʽ0(16λ�Զ���װ��)
	
	TL0 = NORMAL_BASICTIME;       //��ʼ����ʱֵ 
 	TH0 = (unsigned char)(NORMAL_BASICTIME / 256);
	
    TR0 = 1;                        //��ʱ��0��ʼ��ʱ 
    ET0 = 1;                        //ʹ�ܶ�ʱ��0�ж� 

}
/**************************************************************************************************
**	��������:	TimeE_Int()
**	��	��	:	��ʱ��E�жϴ������,1msִ��1�� 
**	��ڲ���:	�� 
**	���ڲ���:	�� 
**  ����ֵ  ��  �� 
**	ȫ�ֱ���:	�� 
**	����ģ��:	�� 
**	��	��	:	
**	��	��	:	
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
   