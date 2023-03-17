
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
#define	UART4_GLOBALS

#include "Includes.h"

//void Uart4Isr() interrupt 18
//{
//    if (S4CON & 0x02)
//    {
//        S4CON &= ~0x02;				//发送完成准备接收
//        bUART4_Busy = 0;
//		pUART4_rptr = 0;		
////		NoRecTime = 0;
////		fTurnSendState();
//    }
//    if (S4CON & 0x01)
//    {
//        S4CON &= ~0x01;
////        UART4_buffer[pUART4_rptr++] = S4BUF;
////		NoRecTime = 0;
//    }
//}

//void Uart4Init()
//{
//    S4CON = 0x50;
//    T4L = BRT_U4;
//    T4H = BRT_U4 >> 8;
//    T4T3M |= 0xa0;
//    pUART4_wptr = 0x00;
//    pUART4_rptr = 0x00;
//    bUART4_Busy = 0;
//	
//	IE2 |= ES4;
//}

//void Uart4Send(char dat)
//{
//	if(!bUART4_Busy)
//	{	
//		bUART4_Busy = 1;
//		S4BUF = dat;
//	}
//}

//void Uart4SendStr(char *p)
//{
//    while(*p) Uart4Send(*p++);		//发送远程数据
//}

