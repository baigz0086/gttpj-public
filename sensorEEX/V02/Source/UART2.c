
/****************************************Copyright (c)*********************************************
**                                     ��ɽ�����������޹�˾
**									       ��   ��   ��
**--------------�ļ���Ϣ---------------------------------------------------------------------------
**��   ��   ��: 
**��   ��   ��: 
**�� �� �� �� ��
**��        ��: 
**--------------��ǰ�汾�޶�-----------------------------------------------------------------------
** �޸���: 
** �ա���: 
** �衡��: 
**
**************************************************************************************************/
#define	UART2_GLOBALS

#include "Includes.h"



void Uart2Isr() interrupt 8
{
    if (S2CON & S2TI)
    {
        S2CON &= ~S2TI;
        bUART2_Sending = 0;
				
    }
    if (S2CON & S2RI)
    {
        S2CON &= ~S2RI;
				UART2_buffer[pUART2_rptr++] = S2BUF;
				Uart2NoRecTime = 0;
    }
}

void Uart2Init()
{
    S2CON = 0x10;
    T2L = BRT_U2;
    T2H = BRT_U2 >> 8;
    AUXR |= 0x14;
    pUART2_wptr = 0x00;		
    pUART2_rptr = 0x00;
    bUART2_Sending = 0;
	
		IE2 |= ES2;
}

void Uart2Send(char dat)
{
	while(bUART2_Sending);
	bUART2_Sending = 1;
	S2BUF = dat;
}

void Uart2SendStr(char *p)
{
    while (*p)
    {
        Uart2Send(*p++);
    }
}


