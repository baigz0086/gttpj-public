
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


#ifdef	UART4_GLOBALS
#define	UART4_EXT 
#else 
#define	UART4_EXT extern
#endif



#define BRT_U4             (65536 - FOSC / 57600 / 4)

UART4_EXT	BOOL bUART4_Busy;
UART4_EXT	char pUART4_wptr;		//UART4 buffer write pointer
UART4_EXT	char pUART4_rptr;		//UART4 buffer read pointer
//UART4_EXT	xdata char UART4_buffer[70];


void Uart4Init(void);
void Uart4Send(char dat);
void Uart4SendStr(char *p);

