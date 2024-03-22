/****************************************Copyright (c)*********************************************
**                                     佛山三俊电子有限公司 
**									       智能电气事业部 
**--------------文件信息---------------------------------------------------------------------------
**文   件   名: Control.h
**创   建   人: 
**创 建 日 期 ： 
**描        述: 功能控制程序 
**--------------当前版本修订-----------------------------------------------------------------------
** 修改人: 
** 日　期: 
** 描　述: 
**
**************************************************************************************************/
#ifdef	CTRL_GLOBALS

#define	CTRL_EXT	
#else
#define	CTRL_EXT  extern
#endif


//	M1 M0
//   0  0	双向口
//   0  1	推挽输出
//   1  0	高阻
//   1  1	开漏


/*
P1-7		olReload
   6		
   5    olWPS
   4
   3
   2
   1    oWIFI_Tx
   0    iWIFI_Rx

	P1   = 0xA1;
	P1M1 = 0; 
	P1M0 = 0xA2;

P3-7		
   6    ilKey
	 5		
	 4
	 3
	 2
	 1		oMCU_Tx
	 0		iMCU_Rx
	 
	P3   = 0x41;
	P3M1 = 0; 
	P3M0 = 0x02;
	 
P5-5		
	 4		olReset
	 
	P5   = 0x10;
	P5M1 = 0x00; 
	P5M0 = 0x10;
	 
*/

sbit	olReload = P1^7;
sbit	olWPS = P1^5;
sbit	ilKey = P3^6;
sbit	olReset = P5^4;
sbit	oTx = P3^1;
sbit	oP32 = P3^2;

sbit oLED	= P5^5;


typedef enum
{
	HAND_SENSOR					,
	WAIT_HAND_SENSOR		,
	HAND2_SENSOR				,
	WAIT_HAND2_SENSOR		,
	STUDY_SENSOR				,
	WAIT_STUDY_SENSOR		,
	RESET_SENSOR				,
	RESET_SENSOR1				,
	RESET_SENSOR2				,
	WAIT_RESET_SENSOR		,
	WAIT_RESET_SENSOR1	,
	WAIT_RESET_SENSOR2	,
	QUERY_STUDY_STATE   ,
	WAIT_QUERY_STATE    ,
	SAVE_SENSOR					,
	WAIT_SAVE_SNESOR		,
	GET_STUDY_VAL		    , //cmd 'p'. 取得学习结果
	WAIT_GET_STUDY_VAL	,
	READY_SENSOR				,
	WAIT_READY_SENSOR		,
	IDLE_SENSOR					,
	SEND_SENSOR_COMMAND	,	//send command to sensor after receive server command
	WAIT_SENSOR_CMDACK	,	//wait for sensor data of command
	DATA_SENSOR					,	//send normal surrounding parameter data ask
	WAIT_DATA_SENSOR		,	//wait for data
	DATA_STAT_SENSOR    , // comand '5'
	GAIN_SET            , // to set GAIN
	WAIT_EX_MODE_SENSOR ,
  START_EX_MODE       ,
	WAIT_START_EX_MODE  ,
	READ_GAIN_SETTING   ,
	WAIT_READ_GAIN      ,
	WRITE_GAIN_QUERY    ,
	WAIT_WRITE_GAIN_QUERY,
	WRITE_GAIN_SETTING  ,
	WAIT_WRITE_GAIN_SETTING,
	FLUSH_GAIN_SETTING  ,
	WAIT_FLUSH_GAIN_SETTING,
	NORMAL_MODE_SENSER  ,
	WAIT_NORMAL_MODE_SENSOR,
	START_NORMAL_MODE   ,
	WAIT_START_NORMAL_MODE,
	WAIT_DATA_STAT_SENSOR      // wiat for cmd '5'
}eStepCommSensor;

CTRL_EXT eStepCommSensor StepCommSensor;



CTRL_EXT	BOOL	bSend_Sensor_Interval;
CTRL_EXT	BOOL	bWaitRecSensor;
CTRL_EXT	u8	ResendSensorTime;		//按10Ms基数计时1S
CTRL_EXT	u8	ResendSensorCount;		
CTRL_EXT	u16	RecSensorOverTime;
CTRL_EXT	u8	AlarmRecSensor;

CTRL_EXT	u16	Uart1NoRecTime;
CTRL_EXT	u16	WaitSensorData;
CTRL_EXT	BOOL	bSend_WIFI_Data;

CTRL_EXT	BOOL	bServer_Cmd_Ack;
CTRL_EXT	BOOL	bServer_Cmd_res; //add by 2022-2-12

CTRL_EXT	u16	Uart2NoRecTime;

//add 2022-2-12 
CTRL_EXT	BOOL	bMamori;  // pause/resume
CTRL_EXT	u16	SendInterval;  // communication interval
CTRL_EXT	u8	bCommandResult;
CTRL_EXT  u8  isFirst; // the Wifi moduler is first setting.
CTRL_EXT  xdata char GAIN_SETTING[18];

/* add 2022-10-16 write trace for debug start */
CTRL_EXT	BOOL	bSend_MIO_0; 
CTRL_EXT	BOOL	bSend_MIO_3; 
CTRL_EXT	BOOL	bSend_MIO_4; 
CTRL_EXT	BOOL	bSend_MIO_3_1000; 
CTRL_EXT	BOOL	bSend_MIO_4_1000; 
/* add 2022-10-16 write trace for debug end */

typedef enum
{
	WIFI_POWERON				,			//上电1秒钟后开始初始化WIFI模块
	WIFI_APPLY_AT				,			//申请进入设置模式
	WIFI_APPLY_AT_ACK		,			//设置模式回复
	WIFI_ENT_AT					,			//进入设置模式
	WAIT_ENT_AT_ACK			,			//进入设置模式回复
	WIFI_CMDPW_STAT     ,     //查询透传命令设定情况
	WIFI_CMDPW_STAT_ACK ,     //查询透传命令设定情况回复
	WIFI_CMDPW_SET      ,     //透传命令设定
	WIFI_CMDPW_SET_ACK  ,     //透传命令设定回复
	WIFI_ENTM           ,     //进入透传模式
	WIFI_ENTM_ACK       ,     //进入透传模式回复
	WIFI_WMAC						,			//查询MAC
	WIFI_WMAC_ACK				,			//查询MAC回复
	WIFI_SMARTAP_ON     ,     //打开SMARTAP模式
	WIFI_SMARTAP_ON_ACK ,     //打开SMARTAP模式回复
	WIFI_WMODE					,			//set wifi mode
	WIFI_WMODE_ACK			,			//set wifi mode reply
	WIFI_WNETP					,			//set tcp id and terminal port
	WIFI_WNETP_ACK			,			//set tcp id and terminal port reply
	WIFI_RESET1					, 		//WIFI模块重启1
	WIFI_RESET1_ACK			, 		//WIFI模块重启1回复
	WIFI_APPLY1_AT			, 		//apply enter set mode again
	WIFI_APPLY1_AT_ACK	, 		//apply enter set mode again reply
	WIFI_ENT1_AT				,			//enter set mode again
	WAIT_ENT1_AT_ACK		,			//enter set mode again reply
	WIFI_WSLK						,			//查询WIFI连接状态
	WIFI_WSLK_ACK				,			//查询WIFI连接状态回复
	WIFI_WSLK2					,			//等待AP页面设定后查询WIFI连接状态
	WIFI_WSLK2_ACK			,			//等待AP页面设定后查询WIFI连接状态回复
	WIFI_TCPON					,			//设置开启TCP
	WIFI_TCPON_ACK			,			//设置开启TCP回复
	WIFI_TCPEN					,			//查询TCP设置状态
	WIFI_TCPEN_ACK			,			//查询TCP设置状态回复
	WIFI_TCPLK					,			//查询TCP连接状态
	WIFI_TCPLK_ACK			,			//查询TCP连接状态回复
	WIFI_RESET2					,			//WIFI模块重启2
	WIFI_RESET2_ACK			,			//WIFI模块重启2回复
	WIFI_NREGEN         ,     //注册包使能
	WIFI_NREGEN_ACK     ,     //注册包使能
	WIFI_NREGDT         ,     //注册包格式（Mac地址）
	WIFI_NREGDT_ACK     ,     //注册包格式（Mac地址）
	WIFI_APCONFIG       ,     //smartAPLink模式打开（ver0.3）
	WIFI_APCONFIG_ACK   ,     
	INIT_WIFI						,			//完成WiFi初始化
	SERVER_HAND					,	
	SERVER_HAND_ACK			,	
	WIFI_IDLE						,	
	REC_SERVER_COMMAND  ,
	WIFI_GAIN_SET       ,     // GAIN设置等待
	WIFI_GAIN_SET_ACK   ,
	GET_GAIN            ,     // 取得GAIN设定值
	GET_GAIN_ACK        ,     
	WIFI_TCPTO          ,
	WIFI_TCPTO_ACK      ,
	WIFI_CMDPW          ,
	WIFI_CMDPW_ACK      ,
	WIFI_WMAC_SEC				,			//查询MAC
	WIFI_WMAC_SEC_ACK		,			//查询MAC回复
	WIFI_TCPON_SEC      ,
	WIFI_TCPON_SEC_ACK  ,
	WIFI_TCPEN_SEC      ,
	WIFI_TCPEN_SEC_ACK  ,
	WIFI_APMODE_CHECK   ,     //判断是否ap模式
	WIFI_APMODE_CHECK_ACK  ,
	WIFI_APMODE_SET     ,     //设置终端ap模式
	WIFI_APMODE_SET_ACK  ,
	WIFI_TCPLK_SEC			,			//查询TCP连接状态
	WIFI_TCPLK_SEC_ACK  			//查询TCP连接状态回复
	
	
}nStepCommWifi;

CTRL_EXT	nStepCommWifi	StepCommWifi;

CTRL_EXT	u16	WaitSendWifi;
CTRL_EXT	u8	ServerCommand,ReplyTime,ReplayLen;
CTRL_EXT	u16	ReplayServerCount;	
CTRL_EXT	u8	MacAddr[6];


CTRL_EXT INT8U const ENTATP[];


//时间

//CTRL_EXT	u8	DayOfMon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
CTRL_EXT	u8	DayOfMon[12];
CTRL_EXT	u8	Year;
CTRL_EXT	u8	Month;
CTRL_EXT	u8	Day;
CTRL_EXT	u8	Hour;
CTRL_EXT	u8	Minute;
CTRL_EXT	u8	Second;
CTRL_EXT	u8	OTSecond;

CTRL_EXT union timeStamp{
	u32 milSec;
	u8  time[4];
}timestamp;



void Control_Init(void);				//功能初始化
void ConFunction(void);					//功能操作
void fSendToSensor(void);
void fRecSensor(void);
void fClean_RecSensor_Buf(void);
void fTime(void);
void cpyUart1ToBuffer(int flag);
void cpyGainSetting(void);


