
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


#ifdef	UART2_GLOBALS
#define	UART2_EXT 
#else 
#define	UART2_EXT extern
#endif



#define BRT_U2             (65536 - FOSC / 115200 / 4)

UART2_EXT	BOOL bUART2_Sending;
UART2_EXT	char pUART2_wptr;		//UART2 buffer write pointer
UART2_EXT	char pUART2_rptr;		//UART2 buffer read pointer
UART2_EXT	xdata char UART2_buffer[70];


void Uart2Init(void);
void Uart2Send(char dat);
void Uart2SendStr(char *p);