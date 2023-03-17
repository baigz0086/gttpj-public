#define EEPROM_GLOBALS

#include "Includes.h"

void iapInit()
{
	u8 t1;
	
	iapIdle();	

  t1 = iapRead(MAMORI_T_ADDR);
	
	if(t1<=0 || t1 >10){
		t1 = 1;
	}	
	SendInterval = t1 * 100;
	
	isFirst = iapRead(WIFI_SETTED_FLAG);
	
}

void iapIdle()
{
	IAP_CONTR = 0;      //关闭IAP功能
	IAP_CMD = 0;        //清除命令寄存器
	IAP_TRIG = 0;       //清除触发寄存器
	IAP_ADDRH = 0x80;   //将地址设置到非IAP区域
	IAP_ADDRL = 0;
}

u8 iapRead(int addr)
{
	u8 t1 = 0;
	
	IAP_CONTR = WT_12M;
	IAP_CMD = 1;
	IAP_ADDRL = addr;
	IAP_ADDRH = addr>>8;
	
	IAP_TRIG = 0x5a;
	IAP_TRIG = 0xa5;
	
	_nop_();
	
	t1 = IAP_DATA;
	
	iapIdle();
	
	//if(t1<=0 || t1 >10){
	//	t1 = 1;
	//}
	
	return t1;
}

void iapWrite(int addr,u8 t1)
{
	IAP_CONTR = WT_12M;
	IAP_CMD = 2;
	IAP_ADDRL = addr;
	IAP_ADDRH = addr>>8;
	
	IAP_DATA = t1;

	IAP_TRIG = 0x5a;
	IAP_TRIG = 0xa5;
	
	_nop_();
	
	iapIdle();	
}

void iapErase(int addr)
{
	IAP_CONTR = WT_12M;
	IAP_CMD = 3;
	IAP_ADDRL = addr;
	IAP_ADDRH = addr>>8;
	
	IAP_TRIG = 0x5a;
	IAP_TRIG = 0xa5;
	
	_nop_();
	
	iapIdle();	
}