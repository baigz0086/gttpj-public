
/*******************************Copyright (c)***********************************
**                          ��ɽ�����������޹�˾ 
**				    	       ���ܵ�����ҵ�� 
**--------------�ļ���Ϣ--------------------------------------------------------
**��   ��   ��: 
**��   ��   ��: 
**�� �� �� �� �� 
**��        ��: 
**--------------��ǰ�汾�޶�---------------------------------------------------
** �޸���: 
** �ա���: 
** �衡��: 
**
*******************************************************************************/


#ifdef	UART3_GLOBALS
#define	UART3_EXT 
#else 
#define	UART3_EXT extern
#endif



#define BRT_U3             (65536 - FOSC / 115200 / 4)

UART3_EXT	BOOL bUART3_Busy;
UART3_EXT	char pUART3_wptr;		//UART3 buffer write pointer
UART3_EXT	char pUART3_rptr;		//UART3 buffer read pointer
//UART3_EXT	xdata char UART3_buffer[70];


void Uart3Init(void);
void Uart3Send(char dat);
void Uart3SendStr(char *p);