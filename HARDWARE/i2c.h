#ifndef __I2C_H
#define __I2C_H			 
#include "delay.h"

/**********************
引脚别名定义
***********************/			
sbit	SDA	= P4^6;	//定义SDA  
sbit	SCL	= P4^5;	//定义SCL

#define I2C_PageSize  8  

#define ADDR_24C08		0xA0

/* Private function prototypes -----------------------------------------------*/
void I2C_delay(void);
bit I2C_Start(void);
void I2C_Stop(void);
void I2C_Ack(void);
void I2C_NoAck(void);
bit I2C_WaitAck(void) ;
void I2C_SendByte(uint8 SendByte) ;
uint8 I2C_ReceiveByte(void)  ;


#endif 
/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
