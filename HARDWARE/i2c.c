
//头文件
#include "i2c.h"
#include "uart.h"
#include "delay.h"
 /**
  * @file   I2C_delay
  * @brief  延迟时间
  * @param  无
  * @retval 无
  */
void I2C_delay(void)  //for 1T  STC	delay 
{	
	uint16 j,i;   
	for(j=0;j<2;j++)   
	{    
		for(i=0;i<7;i++);   
	} 
}

 /**
  * @file   I2C_Start
  * @brief  起始信号
  * @param  无
  * @retval 无
  */
bit I2C_Start(void)
{
	SDA = 1;
	SCL = 1;
	I2C_delay();
	if(!SDA)return FALSE;	/* SDA线为低电平则总线忙,退出 */
	SDA = 0;
	I2C_delay();
	if(SDA) return FALSE;	/* SDA线为高电平则总线出错,退出 */
	SDA = 0;
	I2C_delay();
	return TRUE;
}

 /**
  * @file   I2C_Stop
  * @brief  停止信号
  * @param  无
  * @retval 无
  */
void I2C_Stop(void)
{
	SCL = 0;
	I2C_delay();
	SDA = 0;
	I2C_delay();
	SCL = 1;
	I2C_delay();
	SDA = 1;
	I2C_delay();
}

 /**
  * @file   I2C_Ack
  * @brief  应答信号
  * @param  无
  * @retval 无
  */
void I2C_Ack(void)
{	
	SCL = 0;
	I2C_delay();
	SDA = 0;
	I2C_delay();
	SCL = 1;
	I2C_delay();
	SCL = 0;
	I2C_delay();
}

 /**
  * @file   I2C_NoAck
  * @brief  无应答信号
  * @param  无
  * @retval 无
  */
void I2C_NoAck(void)
{	
	SCL = 0;
	I2C_delay();
	SDA = 1;
	I2C_delay();
	SCL = 1;
	I2C_delay();
	SCL = 0;
	I2C_delay();
}

 /**
  * @file   I2C_WaitAck
  * @brief  等待Ack
  * @param  无
  * @retval 返回为:=1有ACK,=0无ACK
  */
bit I2C_WaitAck(void) 	
{
	SCL = 0;
	I2C_delay();
	SDA = 1;			
	I2C_delay();
	SCL = 1;
	I2C_delay();
	if(SDA)
	{
      SCL = 0;
      return FALSE;
	}
	SCL = 0;
	return TRUE;
}

 /**
  * @file   I2C_SendByte
  * @brief  数据从高位到低位
  * @param  - SendByte: 发送的数据
  * @retval 无
  */
void I2C_SendByte(uint8 SendByte) 
{
    uint8 i=8;
    while(i--)
    {
			SCL = 0;
			I2C_delay();
			if(SendByte&0x80)
			SDA = 1;  
			else 
			SDA = 0;   
			SendByte<<=1;
			I2C_delay();
			SCL = 1;
			I2C_delay();
    }
    SCL = 0;
}


 /**
  * @file   I2C_ReceiveByte
  * @brief  数据从高位到低位
  * @param  无
  * @retval I2C总线返回的数据
  */
uint8 I2C_ReceiveByte(void)  
{ 
    uint8 i=8;
    uint8 ReceiveByte=0;

    SDA = 1;				
    while(i--)
    {
      ReceiveByte<<=1;      
      SCL = 0;
      I2C_delay();
	    SCL = 1;
      I2C_delay();	
      if(SDA)
      {
        ReceiveByte|=0x01;
      }
    }
    SCL = 0;
    return ReceiveByte;
} 
   
 


/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
