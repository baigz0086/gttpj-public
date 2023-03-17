
/****************************************Copyright (c)*********************************************
**                                     佛山三俊电子有限公司
**									       开   发   部
**--------------文件信息---------------------------------------------------------------------------
**文   件   名: 
**创   建   人: 
**创 建 日 期 ：
**描        述: 
**--------------当前版本修订-----------------------------------------------------------------------
** 修改人: 
** 日　期: 
** 描　述: 
**
**************************************************************************************************/
#define	UART1_GLOBALS

#include "Includes.h"



void Uart1Isr() interrupt 4 using 1
{
	if (TI)
    {
        TI = 0;               
        bUART1_Sending = 0;	
    }	
	if (RI)
    {
        RI = 0;     
		UART1_buffer[pUART1_rptr++] = SBUF;   
		Uart1NoRecTime = 0;
    }
}

void Uart1Init()
{
//	ACC = P_SW1;
//    ACC &= ~(S1_S0 | S1_S1);    //S1_S0=0 S1_S1=0fb
//    P_SW1 = ACC;                //(P3.0/RxD, P3.1/TxD)
	
	SCON = 0x50;				//8位可变波特率
	
	TL1 = BRT_U1;
    TH1 = BRT_U1 >> 8;
	
	AUXR |= 0x40;
	AUXR &= ~0x01;				//选择定时器1位1T模式
	
	TR1 = 1;
	ES = 1;

    pUART1_wptr = 0x00;		
    pUART1_rptr = 0x00;
    bUART1_Sending = 0;
	
}

void Uart1Send(char dat)
{
	while(bUART1_Sending);
	bUART1_Sending = 1;
	SBUF = dat;
}

//void Uart1SendStr(char *p)		//发送远程数据
//{
//    while(*p) Uart1Send(*p++);
//}



