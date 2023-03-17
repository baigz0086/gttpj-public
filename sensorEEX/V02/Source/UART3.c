
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
#define	UART3_GLOBALS

#include "Includes.h"




//void Uart3Isr() interrupt 17
//{
//    if (S3CON & S3TI)
//    {
//        S3CON &= ~S3TI;
//        bUART3_Busy = 0;
//    }
//    if (S3CON & S3RI)
//    {
//        S3CON &= ~S3RI;
////        UART3_buffer[pUART3_wptr++] = S3BUF;
//    }
//}

//void Uart3Init()
//{
//    S3CON = 0x50;				//?
//    T3L = BRT_U3;
//    T3H = BRT_U3 >> 8;
//    T4T3M |= 0x0a;				//T3R = 1; T3x12 = 1;
//    pUART3_wptr = 0x00;		
//    pUART3_rptr = 0x00;
//    bUART3_Busy = 0;
//	
//	IE2 |= ES3;
//	
////	SendString("STC15F2K60S2\r\nUart Test !\r\n");
//}

//void Uart3Send(char dat)
//{
//    while (bUART3_Busy);
//    bUART3_Busy = 1;
//    S3BUF = dat;
//}

//void Uart3SendStr(char *p)		//发送远程数据
//{
//    while(*p) Uart3Send(*p++);
//}


