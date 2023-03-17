#ifdef	EEPROM_GLOBALS
#define	EEPROM_EXT 
#else 
#define	EEPROM_EXT extern
#endif

#define WT_12M  0x83
#define MAMORI_T_ADDR 0x0000
#define WIFI_SETTED_FLAG 0x0200

void iapInit();
void iapIdle();
u8 iapRead(int addr);
void iapErase(int addr);
void iapWrite(int addr,u8 t1);
