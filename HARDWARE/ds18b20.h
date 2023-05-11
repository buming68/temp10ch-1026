#ifndef __DS18B20_H__
#define __DS18B20_H__

#include "config.h"	
/**********************
引脚别名定义
***********************/	

sbit Ds18b20IO_1 = P1^0;       //DS18B20数据引脚  1
sbit Ds18b20IO_2 = P1^1;       //DS18B20数据引脚  2
sbit Ds18b20IO_3 = P1^2;       //DS18B20数据引脚  3
sbit Ds18b20IO_4 = P1^3;       //DS18B20数据引脚  4
sbit Ds18b20IO_5 = P1^4;       //DS18B20数据引脚  5
sbit Ds18b20IO_6 = P1^5;       //DS18B20数据引脚  6
sbit Ds18b20IO_7 = P1^6;       //DS18B20数据引脚  7
sbit Ds18b20IO_8 = P1^7;       //DS18B20数据引脚  8  //////需要更改


extern unsigned char Init_Ds18b20_8(void);
extern void Ds18b20Write_8(unsigned char dat);
extern void Ds18b20Read_8(unsigned char *Valueptr);
extern void floatReadDs18B20_8(float *tempptr);

extern unsigned char Init_Ds18b20(void);
extern void Ds18b20Write(unsigned char dat);
extern unsigned char Ds18b20Read(void);
extern float floatReadDs18B20(void);

extern void uart1_rece_proc(void);			//process uart1 received dat
extern void UART1_Tx_Puts(void);

extern float floatReadDs18B20(void);

#endif