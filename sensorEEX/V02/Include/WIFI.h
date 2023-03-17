/****************************************Copyright (c)*********************************************
**                                     ��ɽ�����������޹�˾ 
**									       ���ܵ�����ҵ�� 
**--------------�ļ���Ϣ---------------------------------------------------------------------------
**��   ��   ��: WIFI.h
**��   ��   ��: 
**�� �� �� �� �� 
**��        ��: ���ܿ��Ƴ��� 
**--------------��ǰ�汾�޶�-----------------------------------------------------------------------
** �޸���: 
** �ա���: 
** �衡��: 
**
**************************************************************************************************/
#ifdef	WIFI_GLOBALS

#define	WIFI_EXT	
#else
#define	WIFI_EXT  extern
#endif


WIFI_EXT	xdata char const APPLY_AT[];
WIFI_EXT	xdata char const APPLY_AT_ACK[];

WIFI_EXT	xdata char const ENT_AT[];
WIFI_EXT	xdata char const ENT_AT_ACK[];

WIFI_EXT	xdata char const WMAC[];
WIFI_EXT	xdata char const WMAC_ACK[];

WIFI_EXT	xdata char const WMODE[];
WIFI_EXT	xdata char const WMODE_ACK[];

WIFI_EXT	xdata char const WNETP[];
WIFI_EXT	xdata char const WNETP_ACK[];

WIFI_EXT	xdata char const WSLK[];
WIFI_EXT	xdata char const WSLK_ACK[];

WIFI_EXT	xdata char const TCPON[];
WIFI_EXT	xdata char const TCPON_ACK[];

WIFI_EXT	xdata char const TCPEN[];
WIFI_EXT	xdata char const TCPEN_ACK[];

WIFI_EXT	xdata char const TCPLK[];
WIFI_EXT	xdata char const TCPLK_ACK[];

WIFI_EXT	xdata char const RESET[];
WIFI_EXT	xdata char const RESET_ACK[];

WIFI_EXT	u8	Sensor_PowerOn_Time;


void fClean_RecWIFI_Buf(void);
void fInitWifi(void);
void fSendToWIFI(void);
void fRecWifi(void);
unsigned char HexToAsc(unsigned char aChar);
unsigned char IntegrateAscToHex(unsigned char High_aChar,unsigned char Low_aChar);