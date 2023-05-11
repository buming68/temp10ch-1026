#ifndef __CONFIG_H_
#define __CONFIG_H_

#define MAIN_Fosc		11059200L	//定义主时钟
#include	"15W4KxxS4.H"

#include <string.h>
#include <stdio.h>
#include <intrins.H>

/********************************************
				引脚别名定义
*********************************************/
//sbit led=P3^3;   			//绿色LED用IO口P33

sbit LED_R=P3^2;     	//红色LED用IO口P32
sbit LED_G=P3^3;     	//绿色LED用IO口P33
sbit LED_B=P3^4;     	//蓝色LED用IO口P34

sbit TXEN485 = P5^5;	//485发送控制口，发送为1，接收为0

/*******************************************
		  调试参数  DEBUG
			1---调试    P30、P31 输出调试信息，程序响应慢
			0---非调试  正常工作，响应速度快
*********************************************/
//#define DEBUG


/*******************************************
		出厂缺省设置
*********************************************/
#define BaudFLAG 0x05						//速率标志 5--9600（初始缺省值）（P27=0）  	6--19200（P27=1）
#define DefaultAddress 0x01			//速率地址，DIP地址为0时，由串口设定地址
#define AutoTxTime 0x00					//DIP地址为0时：自动回传间隔时间	 0---不回传  其它值---间隔时间，单位秒
																//DIP地址非0时（1-32由P20--P24决定）:P25 P26为：00---不自动回传
																//01----自动回传间隔1秒    10---间隔3秒      11----间隔5秒	

/*******************************************
		定义全局常量
*********************************************/
#define RX_MAX_LEN 20 
#define SEND_MAX_LEN 30


#define  uint32   unsigned long
#define  uint16   unsigned int  
#define  uint8    unsigned char  

typedef unsigned char BYTE;
typedef unsigned int WORD;

extern void delay_ms(uint16 x);
extern void delayus(unsigned char n);
extern void IO_init(void);


#endif
