/****************************************Copyright (c)*********************************************
**                                     佛山三俊电子有限公司 
**									       智能电气事业部 
**--------------文件信息---------------------------------------------------------------------------
**文   件   名: Basic.h
**创   建   人: 
**创 建 日 期 ： 
**描        述: 基本控制程序 
**--------------当前版本修订-----------------------------------------------------------------------
** 修改人: 
** 日　期: 
** 描　述: 
**
**************************************************************************************************/
#ifdef	BASC_GLOBALS

#define	BASC_EXT	
#else
#define	BASC_EXT  extern
#endif



	 
BYTE fMaxBYTEArray(BYTE Array[],BYTE Size);
BYTE fMinBYTEArray(BYTE Array[],BYTE Size);
WORD fMaxWORDArray(WORD Array[],BYTE Size);
WORD fMinWORDArray(WORD Array[],BYTE Size);

BYTE fTwoDECToBCD(BYTE DEC);
BYTE fTwoBCDToDEC(BYTE BCD);
