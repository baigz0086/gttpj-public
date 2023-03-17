
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
	
	SCON = 0x50;				//8λ�ɱ䲨����
	
	TL1 = BRT_U1;
    TH1 = BRT_U1 >> 8;
	
	AUXR |= 0x40;
	AUXR &= ~0x01;				//ѡ��ʱ��1λ1Tģʽ
	
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

//void Uart1SendStr(char *p)		//����Զ������
//{
//    while(*p) Uart1Send(*p++);
//}



