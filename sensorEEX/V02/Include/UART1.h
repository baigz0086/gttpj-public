
/*******************************Copyright (c)***********************************
**                          佛山三俊电子有限公司 
**				    	       智能电气事业部 
**--------------文件信息--------------------------------------------------------
**文   件   名: 
**创   建   人: 
**创 建 日 期 ： 
**描        述: 
**--------------当前版本修订---------------------------------------------------
** 修改人: 
** 日　期: 
** 描　述: 
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

UART1_EXT	BOOL bUART1_Sending;
UART1_EXT	char pUART1_wptr;		//UART1 buffer write pointer
UART1_EXT	char pUART1_rptr;		//UART1 buffer read pointer
UART1_EXT	xdata char UART1_buffer[70];


void Uart1Init(void);
void Uart1Send(char dat);
void Uart1SendStr(char *p);

