
#ifndef	__FLASHROM_H
#define	__FLASHROM_H

#include	"config.h"

//	选择MCU型号
//#define	MCU_Type	STC15W_4K16S4	
//#define	MCU_Type	STC15W_4K32S4	
//#define	MCU_Type	STC15W_4K40S4	
//#define	MCU_Type	STC15W_4K48S4	
//#define	MCU_Type	STC15W_4K56S4	
//#define	MCU_Type  IAP15W_4K58S4


//#define	MCU_Type	IAP15W_4K61S4		

//#define	MCU_Type	IAP15W_413AS

#define	MCU_Type  IAP15W_4K63S4
/************************** ISP/IAP *****************************
 IAP系列 可以在应用程序修改应用程序。

STC15W4KxxS4	扇区分配，512字节/扇区，从0x0000开始。

     型号        大小   扇区数  开始地址  结束地址   MOVC读偏移地址
STC15W4K16S4   42K   		84扇区  0x0000  ~  0xD3FF        0x0000
STC15W4K32S4   26K    	52扇区  0x0000  ~  0xB3FF        0x0000
STC15W4K40S4   18K    	36扇区  0x0000  ~  0x93FF        0x0000
STC15W4K48S4   10K   		20扇区  0x0000  ~  0xD3FF        0x0000
STC15W4K56S4   2K    		4扇区  0x0000  	~  0xB3FF         0x0000

IAP15W4K58S4   K    		116扇区  0x0000  ~  0xE7FF        0xE000
IAP15W4K61S4   K    		122扇区  0x0000  ~  0xF3FF        0xE000
IRC15W4K63S4   K    		127扇区  0x0000  ~  0xFDFF        0xE000

IAP15W413AS              26扇区  0x0000  ~  0x33FF				0x2C00  占用程序最后2K  程序可用空间11K
*/


#if   (MCU_Type == STC15W_4K16S4)
      #define   MOVC_ShiftAddress    0x0000
#elif (MCU_Type == STC15W_4K32S4)
      #define   MOVC_ShiftAddress    0x0000
#elif (MCU_Type == STC15W_4K40S4)
      #define   MOVC_ShiftAddress    0x0000
#elif (MCU_Type == STC15W_4K48S4)
      #define   MOVC_ShiftAddress    0x0000
#elif (MCU_Type == STC15W_4K56S4)
      #define   MOVC_ShiftAddress    0x0000
#elif (MCU_Type == IAP15W_4K58S4)
/*根据实际需要更改 但要注意不要覆盖了自己的有效程序区 在这里我们取2K*/
      #define   MOVC_ShiftAddress    0xE000 
#elif (MCU_Type == IAP15W_4K61S4)
      #define   MOVC_ShiftAddress    0xE000
#elif (MCU_Type == IAP15W_4K63S4)
//      #define   MOVC_ShiftAddress    0xE000			//预留2K以上字节给EEPROM---flash
			#define   MOVC_ShiftAddress    0xC000				//预留8K字节给其它调试程序
#elif (MCU_Type == IAP15W_413AS)
      #define   MOVC_ShiftAddress    0x2C00				
#endif

///**************************通信速率和站址说明 *****************************
//BaudAddr[2],EEPROMTemp[2]
//第一位：波特率标志位  2--1200， 3--2400， 4--4800， 5--9600（初始缺省值）
//											6--19200，7-=38400，8--				9--56000
//											0x0A--57600,        0x0B--115200
//				 目前仅支持9600和19200							
//第二位：从机485地址   01---250  初始缺省值:01
//											00---广播地址，所有从站都可以接收
//											
//第三位：是否自动回传
//                      0---不回传  其它1---加值间隔时间，单位秒
//									    如果DIP地址为0，则 第P26 P25  00---不回传   01----1秒  
//											                              10---3秒      11----5秒
//****************************************************************************/



extern u8 BaudAddr[3];						//通讯串口1，485接口正在使用的  速率标志、地址
extern u8 EEPROMTemp[3];					//通讯串口1，485接口缺省  速率标志、地址,初次使用初始化值
extern u16 Addr_Baud ;    				//通讯速率代码
extern u16 Addr_485 ;    					//485地址
extern u16 Addr_autoT ;						//是否自动回传，1：回传

extern uint8 dipkey;							//dip8开关的状态，需要初始化，并实时监测

void	DisableEEPROM(void);
void 	EEPROM_read_n(u16 EE_address,u8 *DataAddress,u16 number);
void 	EEPROM_write_n(u16 EE_address,u8 *DataAddress,u16 number);
void	EEPROM_SectorErase(u16 EE_address);

void EEPROM_Init(void);
extern void EEPROM_Factory(void);
extern uint8 EEPROM_write_1(u16 EE_address,u8 *DataAddress);

extern u8 dipkey_init(void);					//初始化功能设置 dip开关

#endif