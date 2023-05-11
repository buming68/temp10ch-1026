
//ͷ�ļ�
#include "i2c.h"
#include "uart.h"
#include "delay.h"
 /**
  * @file   I2C_delay
  * @brief  �ӳ�ʱ��
  * @param  ��
  * @retval ��
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
  * @brief  ��ʼ�ź�
  * @param  ��
  * @retval ��
  */
bit I2C_Start(void)
{
	SDA = 1;
	SCL = 1;
	I2C_delay();
	if(!SDA)return FALSE;	/* SDA��Ϊ�͵�ƽ������æ,�˳� */
	SDA = 0;
	I2C_delay();
	if(SDA) return FALSE;	/* SDA��Ϊ�ߵ�ƽ�����߳���,�˳� */
	SDA = 0;
	I2C_delay();
	return TRUE;
}

 /**
  * @file   I2C_Stop
  * @brief  ֹͣ�ź�
  * @param  ��
  * @retval ��
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
  * @brief  Ӧ���ź�
  * @param  ��
  * @retval ��
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
  * @brief  ��Ӧ���ź�
  * @param  ��
  * @retval ��
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
  * @brief  �ȴ�Ack
  * @param  ��
  * @retval ����Ϊ:=1��ACK,=0��ACK
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
  * @brief  ���ݴӸ�λ����λ
  * @param  - SendByte: ���͵�����
  * @retval ��
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
  * @brief  ���ݴӸ�λ����λ
  * @param  ��
  * @retval I2C���߷��ص�����
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
