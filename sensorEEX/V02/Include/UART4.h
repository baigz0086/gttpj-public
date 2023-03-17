
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

