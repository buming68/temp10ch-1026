
//	本程序是STC系列的内置EEPROM读写程序。
#include "eeprom.h"
#include	"uart.h"
#include "config.h"

u8 BaudAddr[3] = {0x05, 0x01, 0x00};		  		//实际通讯串口1，485接口缺省  速率标志、地址、是否自动回传（1：自动回传）
u8 EEPROMTemp[3] = {0x05, 0x01, 0x00};				//通讯串口1，485接口缺省  速率标志、地址、是否自动回传（1：自动回传）

u16 Addr_Baud = MOVC_ShiftAddress;    				//eeprom 第1个扇区（0开始）
u16 Addr_485 = 0x0200 +MOVC_ShiftAddress;    	//记住 一定要把偏移量加上，第2个扇区（512开始）
u16 Addr_autoT = 0x0400 +MOVC_ShiftAddress;    //记住 一定要把偏移量加上,eeprom 第3个扇区（1K开始）

//========================================================================
// 函数: void	ISP_Disable(void)
// 描述: 禁止访问ISP/IAP.
// 参数: non.
// 返回: non.
//========================================================================
void	DisableEEPROM(void)
{
	ISP_CONTR = 0;			//禁止ISP/IAP操作
	ISP_CMD   = 0;			//去除ISP/IAP命令
	ISP_TRIG  = 0;			//防止ISP/IAP命令误触发
	ISP_ADDRH = 0xff;		//清0地址高字节
	ISP_ADDRL = 0xff;		//清0地址低字节，指向非EEPROM区，防止误操作
}

//========================================================================
// 函数: void EEPROM_read_n(u16 EE_address,u8 *DataAddress,u16 number)
// 描述: 从指定EEPROM首地址读出n个字节放指定的缓冲.
// 参数: EE_address:  读出EEPROM的首地址.
//       DataAddress: 读出数据放缓冲的首地址.
//       number:      读出的字节长度.
// 返回: non.
//========================================================================
void EEPROM_read_n(u16 EE_address,u8 *DataAddress,u16 number)
{
	EA = 0;		//禁止中断
	ISP_CONTR = (ISP_EN + ISP_WAIT_FREQUENCY);	//设置等待时间，允许ISP/IAP操作，送一次就够
	ISP_READ();									//送字节读命令，命令不需改变时，不需重新送命令
	do
	{
		ISP_ADDRH = EE_address / 256;		//送地址高字节（地址需要改变时才需重新送地址）
		ISP_ADDRL = EE_address % 256;		//送地址低字节
		ISP_TRIG();							//先送5AH，再送A5H到ISP/IAP触发寄存器，每次都需要如此
											//送完A5H后，ISP/IAP命令立即被触发启动
											//CPU等待IAP完成后，才会继续执行程序。
		_nop_();
		*DataAddress = ISP_DATA;			//读出的数据送往
		EE_address++;
		DataAddress++;
	}while(--number);

	DisableEEPROM();
	EA = 1;		//重新允许中断
}


/******************** 扇区擦除函数 *****************/
//========================================================================
// 函数: void EEPROM_SectorErase(u16 EE_address)
// 描述: 把指定地址的EEPROM扇区擦除.
// 参数: EE_address:  要擦除的扇区EEPROM的地址.
// 返回: non.
//========================================================================
void EEPROM_SectorErase(u16 EE_address)
{
	EA = 0;		//禁止中断
											//只有扇区擦除，没有字节擦除，512字节/扇区。
											//扇区中任意一个字节地址都是扇区地址。
	ISP_CONTR = (ISP_EN + ISP_WAIT_FREQUENCY);	//设置等待时间，允许ISP/IAP操作，送一次就够
	ISP_ADDRH = EE_address / 256;			//送扇区地址高字节（地址需要改变时才需重新送地址）
	ISP_ADDRL = EE_address % 256;			//送扇区地址低字节
	ISP_CONTR = (ISP_EN + ISP_WAIT_FREQUENCY);	//设置等待时间，允许ISP/IAP操作，送一次就够
	ISP_ERASE();							//送扇区擦除命令，命令不需改变时，不需重新送命令
	ISP_TRIG();
	_nop_();
	DisableEEPROM();
	EA = 1;		//重新允许中断
}

//========================================================================
// 函数: void EEPROM_write_n(u16 EE_address,u8 *DataAddress,u16 number)
// 描述: 把缓冲的n个字节写入指定首地址的EEPROM.
// 参数: EE_address:  写入EEPROM的首地址.
//       DataAddress: 写入源数据的缓冲的首地址.
//       number:      写入的字节长度.
// 返回: non.
//========================================================================
void EEPROM_write_n(u16 EE_address,u8 *DataAddress,u16 number)
{
	EA = 0;		//禁止中断

	ISP_CONTR = (ISP_EN + ISP_WAIT_FREQUENCY);	//设置等待时间，允许ISP/IAP操作，送一次就够
	ISP_WRITE();							//送字节写命令，命令不需改变时，不需重新送命令
	do
	{
		ISP_ADDRH = EE_address / 256;		//送地址高字节（地址需要改变时才需重新送地址）
		ISP_ADDRL = EE_address % 256;		//送地址低字节
		ISP_DATA  = *DataAddress;			//送数据到ISP_DATA，只有数据改变时才需重新送
		ISP_TRIG();
		_nop_();
		EE_address++;
		DataAddress++;
	}while(--number);

	DisableEEPROM();
	EA = 1;		//重新允许中断
}

//========================================================================
// 函数: void EEPROM_Init()
// 初始化
// 读取EEPROM保存的通信速率标志，从机地址，如果没有读到，就用缺省值，定义在EEPROMTemp
// 返回: non.
//========================================================================

void EEPROM_Init(void)
{
	unsigned char strTemp[8];
	
	EEPROM_read_n(Addr_Baud,BaudAddr,1);	//在FLASH的首地址为0xE000处读取个字节存入数组中
	if(*BaudAddr == 0xff)	
		{
				EEPROM_SectorErase(Addr_Baud);    	   //对FLASH的首地址为0xE000处的扇区进行扇区擦除
				EEPROM_write_n(Addr_Baud,EEPROMTemp,1);		//在FLASH的首地址为写入1个字节
		}
		
	EEPROM_read_n(Addr_485,BaudAddr+1,1);	//在FLASH的首地址为0xE000处读取1个字节存入数组中		
	if(*(BaudAddr+1) == 0xff)	
	{
			EEPROM_SectorErase(Addr_485);    	   //对FLASH的首地址为0x????+200处的扇区进行扇区擦除
			EEPROM_write_n(Addr_485,EEPROMTemp+1,1);		//在FLASH的首地址为写入1个字节
	}	
	
	EEPROM_read_n(Addr_autoT,BaudAddr+2,1);		//在FLASH的首地址为0x????处读取1个字节存入数组中
	if(*(BaudAddr+2) == 0xff)	
	{
			EEPROM_SectorErase(Addr_autoT);    	   //对FLASH的首地址为0x????+400处的扇区进行扇区擦除
			EEPROM_write_n(Addr_autoT,EEPROMTemp+2,1);		//在FLASH的首地址为写入1个字节
	}
	
			EEPROM_read_n(Addr_Baud,BaudAddr,1);	//在FLASH的首地址为0xE000处读取1个字节存入数组中
			EEPROM_read_n(Addr_485,BaudAddr+1,1);	//在FLASH的首地址为0xE000+400 处读取1个字节存入数组中
			EEPROM_read_n(Addr_autoT,BaudAddr+2,1);	//在FLASH的首地址为0xE000+400 处读取1个字节存入数组中
		
			sprintf(strTemp, "%c%c%c\r\n", BaudAddr[0],BaudAddr[1],BaudAddr[2]); //浮点数转成字符串 
			SendStringByUart1(strTemp); 
}

//========================================================================
// 函数: void EEPROM_write(u16 EE_address,u8 *DataAddress)
// 描述: 把缓冲的n个字节写入指定首地址的EEPROM.
// 参数: EE_address:  写入EEPROM的首地址.
//       DataAddress: 写入源数据的缓冲的首地址.

// 返回: non.
//========================================================================
uint8 EEPROM_write_1(u16 EE_address,u8 *DataAddress)
{
	uint8 write_count = 3;
	uint8 tempdata;
	
	while(write_count--)
	{
			EEPROM_SectorErase(EE_address);    	   				//对FLASH的首地址为0xE000+400处的扇区进行扇区擦除
			EEPROM_write_n(EE_address, DataAddress, 1);		//在FLASH的首地址为写入1个字节
			EEPROM_read_n(EE_address, &tempdata,1);			//在FLASH的首地址为0xE000处读取1个字节存入数组中
			if(*DataAddress == tempdata)
				return 0;																	//成功写入
	}
	return 1;
	
}


