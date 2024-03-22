
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


#ifdef	UART1_GLOBALS
#define	UART1_EXT 
#else 
#define	UART1_EXT extern
#endif

#define S1_S0 0x40              //P_SW1.6
#define S1_S1 0x80              //P_SW1.7

#define BRT_U1             (65536 - FOSC / 57600 / 4)

#define UART1_BUFFER_LEN 90
UART1_EXT	xdata char UART1_buffer[90]; // 70 to 90. because 'p' jieguo 80,'M' jieguo 88. 2023-5-7

UART1_EXT	BOOL bUART1_Sending;
UART1_EXT	char pUART1_wptr;		//UART1 buffer write pointer
UART1_EXT	char pUART1_rptr;		//UART1 buffer read pointer

UART1_EXT	xdata char Gain_set_buffer[45];

UART1_EXT	xdata char SEND_buffer[72]; // cmd4 + cmd5 ���


void Uart1Init(void);
void Uart1Send(char dat);
void Uart1SendStr(char *p);

