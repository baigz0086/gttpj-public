/*******************************Copyright (c)***********************************
**                          佛山三俊电子有限公司 
**				    	       智能电气事业部 
**--------------文件信息--------------------------------------------------------
**文   件   名: Time.h
**创   建   人: 
**创 建 日 期 ： 
**描        述: 
**--------------当前版本修订---------------------------------------------------
** 修改人: 
** 日　期: 
** 描　述: 
**
*******************************************************************************/


#ifdef TX_GLOBALS
#define  TX_EXT 
#else 
#define  TX_EXT extern
#endif


#define FOSC 11059200UL

#define	T100US		100e-6
#define	T250US		250e-6   
#define T1MS		1e-3
#define T10MS		10e-3 
#define	NORMAL_BASICTIME	(65536 - FOSC / 12 * T10MS)      //12T模式 

TX_EXT BOOLEAN	bDo10ms;
TX_EXT BOOLEAN	bDo100ms;
TX_EXT BOOLEAN	bFlash;
TX_EXT BOOLEAN	bFlash1S;

TX_EXT INT8U	Counter_To_100MS;
TX_EXT INT8U	Counter_To_500mS;
TX_EXT INT8U	Counter_To_1S;


//void delay_dec(INT8U);

//void delay_dec(INT8U count_dec);

//void Delay(INT16U n);

void Do10ms(void);
void Do100ms(void);

/*******************************************************************************
  函数名称         : timer_init
  函数描述         : 初始化timer
  调用模块         :  
  调用本函数的模块 : 
  全局变量         : 
  输入参数         : 
  输出参数         : 无。 
  返回值           : 无 
  创建日期         : 2007.11.27
  作    者         : AderWei 
********************************************************************************/
void Time0_Init(void);