	
/**--------------------------------------------------------------------------------------------------------
** Created by:			zjjohn
** Created date:		2022-10-9
** Version:			    1.0.0.C
** Descriptions:		DS18B20*8 + SHT30 * 1 = 9 温度 + 1 湿度
** 此版本调试口不输出DEBUG信息 （无printf）
**********************************************************************************************************/

#include  "config.h"
#include	"uart.h"
#include 	"ds18b20.h" 
#include "sht30.h"
#include	"wdt.h" 
#include 	"receservice.h" 

/***************************************************************************
													全局变量定义

 **************************************************************************/
extern uint8 dipkey;							//dip8开关的状态，需要初始化，并实时监测
//uint8 CHNUM = 8;									//温度传感器的路数1路或8路
//extern	unsigned char strTemp[30];

/***************************************************************************
 * 描  述 : 主函数
 * 入  参 : 无
 * 返回值 : 无
 **************************************************************************/
void  main()
{		 
	uint8 TempCount = 0;
	uint8 autoTxCount = 0;					//工作临时计数变量，自动发送功能用
//	unsigned char strTemp[8];				//串口调试，输出用临时变量

	IO_init();											//IO口开机初始化、LED测试
	
	//uart1_rece_ack();		//调试用  向主机回送测温信息；
	//uart1_auto_tx();		//调试用  自动回传	
	//EEPROM_Init();			//调试用  

	if(dipkey_init())	EEPROM_Init();		//初始化EEPROM，第一次缺省参数，之后已经设置的参数	
	Timer0Init();	   			//初始化定时器0,作串口帧结束的定时器，３个接收baut时间长度
	Uart1_Init();         //串口1初始化，缺省9600，8，1-STOP，0-crc
	SHT3X_Init();					//sh30初始化
	
	EA = 1;               //总中断打开	
	
	TXEN485 = 1;					//控制485发送功能，需要发送时设定
	
	SendDataByUart1(BaudAddr[0]),SendDataByUart1(BaudAddr[1]),SendDataByUart1(BaudAddr[2]);	//显示初始工作参数

	TXEN485 = 0;					//控制485接收功能
	
	WDT_config();          //看门狗初始化  256T分频  12M频率下8秒
					
	while(1)
	{
/***********************同时获取1路温度和1路湿度********************************/			
//		if(CHNUM == 8)		
//		if(CHNUM == 1)		fTempM[0] = floatReadDs18B20();		//获取1路温度，同时在转换的间隙，查询串口命令，发送应答
		
		floatReadDs18B20_8(fTempM6[TempCount++]);				//获取8路温度，同时在转换的间隙，查询串口命令，发送应答
		SHT3X_Get();											//获取第9路温度，第10路湿度,（每次都初始化-已经修改)
		if(TempCount == 6)	TempCount =0;
		
		
/***********************自动发送功能*******************************************/				
		if(BaudAddr[2])						//如果不为0，则以此为间隔周期，自动发送
		{
			if(autoTxCount++ == BaudAddr[2])	
			{
				uart1_auto_tx();					//自动发送温度数据，8路或1路
				autoTxCount = 0; 
			}
		}
		
/***********************DIP开关变化，动态适应**********************************/		
		if(dipkey != ~P2)						
		{
				if((P2 & 0x1f) == 0x1f)	EEPROM_Factory();				//DIP开关地址为0，不起作用，出厂设置
				IAP_CONTR = 0x20;									//重启动     //检测如果开关变化，重启动，初始化
		}
		Wdt_Feed();     					//喂狗9秒之内需要喂狗  分频256，时钟11.0592MHz

		LED_R = ~LED_R;  
	}	
}  


/******************************* END  FILE**************************************/

//	uint 	j;
//**************测试dip8开关****************//
//dipkey_init();	
//while(1)
//{

//	if(dipkey != ~P2)	LED_R = 0 ;     //点亮红色LED
//	delay_ms(1000);     
//	LED_R = 1 ;  	
//}

/***************双路温度、湿度使用*****************/		
//		if(i++==40)
//		{
//				SHT3X_Get();  							//SHT30函数 获取温度、湿度
//				i=0;
//		}		
//		uart1_rece_proc();
//		delay_ms(5);     								//5ms间隔查询中断
//		if((BaudAddr[2]) && (j++==200))		//如果不为0，则以此为间隔周期，自动发送,同时步进速度1秒
//		{
//			j=0;
//			if(autoTxCount++ == BaudAddr[2])	
//			{
//				uart1_auto_tx();						//自动发送温度和湿度数据
//				autoTxCount = 0; 
//			}
//		}
//	
//			if(BaudAddr[2])						//如果不为0，则以此为间隔周期，自动发送
//		{
//			if(autoTxCount++ == BaudAddr[2])	
//			{
//				uart1_auto_tx();					//自动发送温度数据，8路或1路
//				autoTxCount = 0; 
//			}
//		}
//				if(BaudAddr[2])						//如果不为0，则以此为间隔周期，自动发送
//		{
//			if(autoTxCount++ == BaudAddr[2])	
//			{
//				uart1_auto_tx();					//自动发送温度数据，8路或1路
//				autoTxCount = 0; 
//			}
//		}
	
	



