/****************************************Copyright (c)*********************************************
**                                     ��ɽ�����������޹�˾ 
**									       ���ܵ�����ҵ�� 
**--------------�ļ���Ϣ---------------------------------------------------------------------------
**��   ��   ��: Basic.h
**��   ��   ��: 
**�� �� �� �� �� 
**��        ��: �������Ƴ��� 
**--------------��ǰ�汾�޶�-----------------------------------------------------------------------
** �޸���: 
** �ա���: 
** �衡��: 
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
