/****************************************Copyright (c)*********************************************
**                                     ��ɽ�����������޹�˾
**									       ��   ��   ��
**--------------�ļ���Ϣ---------------------------------------------------------------------------
**��   ��   ��: Control.c
**��   ��   ��: 
**�� �� �� �� ��
**��        ��: 
**--------------��ǰ�汾�޶�-----------------------------------------------------------------------
** �޸���: 
** �ա���: 
** �衡��: 
**
**************************************************************************************************/
#define	CTRL_GLOBALS

#include "Includes.h"


/**************************************************************************************************
**	��������:	InitPort()
**	��	��	:	��ʼ��IO�� 
**	��ڲ���:	�� 
**	���ڲ���:	�� 
**  ����ֵ  ��  �� 
**	ȫ�ֱ���:	�� 
**	����ģ��:	�� 
**	��	��	:	
**	��	��	:	
**************************************************************************************************/
void InitPort(void)
{

//	P1   = 0x01;			//no receive in uart2 when set this register
	P1M1 = 0; 
	P1M0 = 0;
	
	P3   = 0x43;
	P3M1 = 0x40; 
	P3M0 = 0x40;
	P3PU &= ~0x40;
	
	P5   = 0x10;
	P5M1 = 0x00; 
	P5M0 = 0x00;

}

/**************************************************************************************************
**	��������:	WatchdogInit()
**	��	��	:	���Ź���ʼ�� 
**	��ڲ���:	�� 
**	���ڲ���:	�� 
**  ����ֵ  ���� 
**	ȫ�ֱ���:	�� 
**	����ģ��:	�� 
**	��	��	:
**	��	��	:	
**************************************************************************************************/
void WatchdogInit(void)
{

	WDT_CONTR = 0x04;       //���Ź���ʱ�����ʱ����㹫ʽ: (12 * 32768 * PS) / FOSC (��)
                            //���ÿ��Ź���ʱ����Ƶ��Ϊ32,���ʱ������:
                            //11.0592M : 1.14s
                            //18.432M  : 0.68s
                            //20M      : 0.63s
	WDT_CONTR |= 0x20;      //�������Ź� 

}

//u8 Match;

void Control_Init(void)
{	
	EA = 0;									/* Interrupt disable */	 
	
	InitPort();   
	WatchdogInit();
	Time0_Init();
	Uart1Init();			//sence p30 rx p31 tx
	Uart2Init();			//wifi p10 rx p11 tx
//	Uart3Init();			//wifi p00 rx p01 tx
//	Uart4Init();			//sence p02 rx p03 tx
	
	fClean_RecSensor_Buf();
	WaitSensorData = 1000;
	StepCommSensor = HAND_SENSOR;
	
	SendInterval = 100;   //default 1s
	
	Year = 0;
	Month = 1;
	Day = 1;
	Hour = 0;
	Minute = 0;
	Second = 0;
	OTSecond = 0;
	
	timestamp.milSec = 0;
	
	fInitWifi();
	
	iapInit();

	oLED = 1;
	
	EA = 1;											/* Interrupt enable */
//	Uart1SendStr("Uart Test !\r\n");
}


void fKey_reload(void)
{
//	if(ilKey)			// key press
//	{
//		olReload = 0;
//	}
//	else
//	{
//		olReload = 1;
//	}
}

void ConFunction(void)
{
	WDT_CONTR |= 0x10;
	
	fKey_reload();
	
	if(bDo10ms) Do10ms();
	if(bDo100ms) Do100ms();
	
	if(WaitSensorData == 0) fSendToSensor();
	fRecSensor();
	
	if(WaitSendWifi == 0) fSendToWIFI();
	fRecWifi();
	
}




void fClean_RecSensor_Buf(void)
{
	u8 i;
	for(i=0;i<70;i++) UART1_buffer[i] = 0;
	pUART1_rptr = 0;		
	Uart1NoRecTime = 0;	
}

void fSendToSensor(void)
{
	switch(StepCommSensor)
	{
		case HAND_SENSOR: 						//shake hand sensor first
			fClean_RecSensor_Buf();
			Uart1Send('0'); 
			StepCommSensor = WAIT_HAND_SENSOR;
		break;
	
		case HAND2_SENSOR:						//shake hand sensor second
			fClean_RecSensor_Buf();
			Uart1Send('0'); 
			StepCommSensor = WAIT_HAND2_SENSOR;
		break;
		
		case STUDY_SENSOR:						//study continue 30 second
			fClean_RecSensor_Buf();
			Uart1Send('G'); 
		
			StepCommSensor = WAIT_STUDY_SENSOR;
		break;
		
		case RESET_SENSOR:						//reset Mio
			fClean_RecSensor_Buf();
			Uart1Send('u'); 
		
		  //IAP_CONTR = 0x60;           //reset STC
		  bSend_MIO_4_1000 = 1; // trace to server
			StepCommSensor = WAIT_RESET_SENSOR;
		break;
		
		case RESET_SENSOR1:						//reset Mio
			fClean_RecSensor_Buf();
			Uart1Send('0'); 
		
		  //IAP_CONTR = 0x60;           //reset STC
		  bSend_MIO_4_1000 = 1; // trace to server
			StepCommSensor = WAIT_RESET_SENSOR1;
		break;
		
		case RESET_SENSOR2:						//reset Mio
			fClean_RecSensor_Buf();
			Uart1Send('u'); 
		
		  //IAP_CONTR = 0x60;           //reset STC
		  bSend_MIO_4_1000 = 1; // trace to server
			StepCommSensor = WAIT_RESET_SENSOR2;
		break;
				
		// add by 2022-2-12
		case QUERY_STUDY_STATE: 
			fClean_RecSensor_Buf();
			Uart1Send('b'); 
		
//			bCommandResult=0;
		  ServerCommand = 'b';
			StepCommSensor = WAIT_QUERY_STATE;
		break;
		
		case SAVE_SENSOR:						//save surrounding parameter
			fClean_RecSensor_Buf();
			Uart1Send('S'); 
		
		  ServerCommand = 'S';
			StepCommSensor = WAIT_SAVE_SNESOR;
		break;
		
		case IDLE_SENSOR:						//sensor ready
			if(StepCommWifi == WIFI_IDLE)		//no receive server command,then query data	
			{
				fClean_RecSensor_Buf();
				if(bMamori){
					Uart1Send('3'); 
					StepCommSensor = WAIT_READY_SENSOR;
				}
			}
			else if(StepCommWifi == REC_SERVER_COMMAND)
			{
				//StepCommSensor = SEND_SENSOR_COMMAND;	// if receive server command,and no in normal data mode,
																								// turn to send sensor command
				
				//add 2022-2-12
				switch(ServerCommand)
				{
					case 'G':
						StepCommSensor = STUDY_SENSOR;	   // study
					break;
					case 'u':
						StepCommSensor = RESET_SENSOR1;	   // reset  // �ȷ���0���ɹ����Ӻ���u
					break;
					default:
						bCommandResult = 0;         
						bServer_Cmd_Ack = 1;        
					break;
				}
			}																				  
		break;

		case READY_SENSOR:
			fClean_RecSensor_Buf();
			Uart1Send('3'); 
			StepCommSensor = WAIT_READY_SENSOR;
		break;
		
		case DATA_SENSOR:	
			fClean_RecSensor_Buf();
			Uart1Send('4'); 
			StepCommSensor = WAIT_DATA_SENSOR;
		break;
		
		case SEND_SENSOR_COMMAND:
			fClean_RecSensor_Buf();
			bServer_Cmd_Ack = 0;
			Uart1Send(ServerCommand); 	
			StepCommSensor = WAIT_SENSOR_CMDACK;	// turn to wait command data of sensor
		break;
		
	}
}


// �ϵ�4.6��SENSOR���� "AT+WRUART=57600��1��N\r\n"

void fRecSensor(void)
{
	switch(StepCommSensor)
	{
		case WAIT_HAND_SENSOR: 	
			if(Uart1NoRecTime >= 5 && pUART1_rptr >= 1) 
			{
				if(UART1_buffer[0] == '1') 
				{
					StepCommSensor = HAND2_SENSOR;	
					WaitSensorData = 100;
				}
				else
				{
					StepCommSensor = HAND_SENSOR;	
					WaitSensorData = 100;
				}
			}
			else if(Uart1NoRecTime >= 100)  StepCommSensor = HAND_SENSOR;
		break;
	
		case WAIT_HAND2_SENSOR: 
			if(Uart1NoRecTime >= 5 && pUART1_rptr >= 1) 
			{	
				if(UART1_buffer[0] == '1') 
				{
					//StepCommSensor = STUDY_SENSOR;	   //del 2022-2-12
					//WaitSensorData = 500;              //del 2022-2-12
					
					// change STUDY_SENSOR->IDLE_SENSOR  2022-2-12
					StepCommSensor = IDLE_SENSOR;
				}
			}
			else if(Uart1NoRecTime >= 100)  StepCommSensor = HAND_SENSOR;
		break;	
			
		case WAIT_STUDY_SENSOR:	
			if(Uart1NoRecTime >= 5 && pUART1_rptr >= 1) 
			{
				if(UART1_buffer[0] == '1') 
				{
					StepCommSensor = SAVE_SENSOR;
				}else{
					StepCommSensor = QUERY_STUDY_STATE;
					WaitSensorData = 1000;
					
					bCommandResult = UART1_buffer[0];  // the result is failt by Study Command.
					bServer_Cmd_res = 1;					
				}
			}
			//else if(Uart1NoRecTime >= 3500) StepCommSensor = HAND_SENSOR; //del by 2022-2-12
			else if(Uart1NoRecTime >= 500) StepCommSensor = QUERY_STUDY_STATE;    //add by 2022-2-12
		break;
		
		//add by 2022-2-12
		case WAIT_QUERY_STATE:	
			if(Uart1NoRecTime >= 5 && pUART1_rptr >= 1) 
			{
				if(UART1_buffer[0] == '4') 
				{
					StepCommSensor = SAVE_SENSOR;
					bCommandResult = 0;
				}else if(UART1_buffer[0] == '2'){
					StepCommSensor = QUERY_STUDY_STATE;
					WaitSensorData = 200;
					
					bCommandResult = UART1_buffer[0];  // the result is failt by Study Command.
					bServer_Cmd_res = 1;	
					
				}else{
					StepCommSensor = IDLE_SENSOR;
					
					bCommandResult = UART1_buffer[0];  // the result is failt by Study Command.
					bServer_Cmd_Ack = 1;	
					
				}
			}
			else if(Uart1NoRecTime >= 200) StepCommSensor = QUERY_STUDY_STATE;    //2 second cycle confirmation
		break;
		
		case WAIT_SAVE_SNESOR:	
			if(Uart1NoRecTime >= 5 && pUART1_rptr >= 1) 
			{
				if(UART1_buffer[0] == '1') 
				{
					StepCommSensor = IDLE_SENSOR;
					bServer_Cmd_Ack = 1;        // add by 2022-2-12
				}
			}
			else if(Uart1NoRecTime >= 1500)  StepCommSensor = IDLE_SENSOR;
		break;
			
		case WAIT_READY_SENSOR:			//normal qurey data ack
			if(Uart1NoRecTime >= 5 && pUART1_rptr >= 1) 
			{
				if(UART1_buffer[0] == '1') {
					StepCommSensor = DATA_SENSOR;
				}else if(Uart1NoRecTime >= 100){   // �°�Mio��Ӧ������3�лش�1���������Ӧ������1s���ٴη�������3
					bSend_MIO_3_1000 = 1; // trace to server
					
					StepCommSensor = IDLE_SENSOR;
				}
			}
			else if(Uart1NoRecTime >= 100)  
			{
				StepCommSensor = IDLE_SENSOR;	
			}
		break;
		
		case WAIT_DATA_SENSOR:			//normal receive data
			if(Uart1NoRecTime >= 5 && pUART1_rptr >= 31) 
			{
				StepCommSensor = IDLE_SENSOR;
				WaitSensorData = SendInterval-16;     //change by 2022-2-12  84 to var

				bSend_WIFI_Data = 1;
			}
			//else if(Uart1NoRecTime >= SendInterval) StepCommSensor = IDLE_SENSOR;  // �°�Mio��Ӧ��չ����4�ò���Ԥ�ڽ���󣬷���3��һ�����ݲɼ�
			else if(Uart1NoRecTime >= 100){
				bSend_MIO_4_1000 = 1; // trace to server
				
				StepCommSensor = IDLE_SENSOR;
			}
		break;
		
		case WAIT_SENSOR_CMDACK:		//receive command ack data
			if(Uart1NoRecTime >= 5 && pUART1_rptr >= 1) 
			{
				bServer_Cmd_Ack = 1;
				WaitSensorData = 10;
				StepCommSensor = IDLE_SENSOR;
			}
			else if(Uart1NoRecTime >= 3500) 	//if no receive data in 35 seconds, return to idle
			{
				StepCommSensor = IDLE_SENSOR;	
				StepCommWifi = WIFI_IDLE;
			}
		break;

		case WAIT_RESET_SENSOR:			
			if(Uart1NoRecTime >= 5 ) 
			{
				WaitSensorData = 100;
				StepCommSensor = RESET_SENSOR1;
				
				bServer_Cmd_Ack = 1;        // add by 2022-2-12
			}

		break;
			
		case WAIT_RESET_SENSOR1:			
			if(Uart1NoRecTime >= 5 && pUART1_rptr >= 1) 
			{
				if(UART1_buffer[0] == '1') 
				{
					StepCommSensor = RESET_SENSOR2;	
					WaitSensorData = 100;
				}
				else
				{
					StepCommSensor = RESET_SENSOR1;	
					WaitSensorData = 100;
				}
			}
			else if(Uart1NoRecTime >= 100)  StepCommSensor = RESET_SENSOR1;
		break;
			
		case WAIT_RESET_SENSOR2:			
			if(Uart1NoRecTime >= 5 ) 
			{
				WaitSensorData = 100;
				StepCommSensor = HAND_SENSOR;
				
				bServer_Cmd_Ack = 1;        // add by 2022-2-12
			}

		break;
	}
}






void fTime(void)
{
	timestamp.milSec += 1;
//	unsigned char Temp;
//	if(OTSecond < 9) OTSecond++;
//	else
//	{
//		OTSecond = 0;
//		if(Second < 59) Second++;
//		else
//		{
//			Second = 0;
//			if(Minute < 59) Minute++;
//			else
//			{
//				Minute = 0;
//				if(Hour < 23) Hour++;
//				else
//				{
//					Hour = 0;
//					if(Month == 2)
//					{
//					//	if((Year%4==0 && Year%100!=0)||(Year%400==0)) Temp = 29;
//						if(Year%4==0 && Year%100!=0) Temp = 29;
//						else Temp = 28;
//						
//						if(Day < Temp) Day++;
//						else
//						{
//							Day = 1;
//							Month = 3;
//						}
//					}
//					else
//					{
//						Temp = DayOfMon[Month - 1];
//						if(Day < Temp) Day++;
//						else
//						{
//							Day = 1;
//							if(Month < 12) Month++;
//							else
//							{
//								Month = 1;
//								Year++;
//							}
//						}
//					}
//				}
//			}
//		}		
//	}
}


