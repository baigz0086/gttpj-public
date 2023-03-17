/*******************************Copyright (c)***********************************
**                          ��ɽ�����������޹�˾ 
**				    	       ���ܵ�����ҵ�� 
**--------------�ļ���Ϣ--------------------------------------------------------
**��   ��   ��: Time.h
**��   ��   ��: 
**�� �� �� �� �� 
**��        ��: 
**--------------��ǰ�汾�޶�---------------------------------------------------
** �޸���: 
** �ա���: 
** �衡��: 
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
#define	NORMAL_BASICTIME	(65536 - FOSC / 12 * T10MS)      //12Tģʽ 

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
  ��������         : timer_init
  ��������         : ��ʼ��timer
  ����ģ��         :  
  ���ñ�������ģ�� : 
  ȫ�ֱ���         : 
  �������         : 
  �������         : �ޡ� 
  ����ֵ           : �� 
  ��������         : 2007.11.27
  ��    ��         : AderWei 
********************************************************************************/
void Time0_Init(void);