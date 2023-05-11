#include "sht30.h"


 float temperatureC;
 float humidityRH;

 uint8 buffer[6];

 /**************************************************************************************
 * 描  述 : 向SHT30写寄存器命令
 * 入  参 : cmd: 两字节命令
 * 返回值 :   1---成功写入,     0---失败
 **************************************************************************************/
bit SHT3X_WriteCMD(uint16 cmd)
{
	if(!I2C_Start())   return FALSE;
	I2C_SendByte(i2cAddWrite_8bit);
	if(!I2C_WaitAck()){I2C_Stop(); return FALSE;}
	I2C_SendByte(cmd>>8);
	I2C_WaitAck();
	I2C_SendByte(cmd);
	I2C_WaitAck();
	I2C_Stop();
	return TRUE;
}

 /**************************************************************************************
 * 描  述 : 设置测量周期
 * 入  参 : 无
 * 返回值 : 无
 **************************************************************************************/
void SHT3X_SetPeriodicMeasurement(void)
{
    SHT3X_WriteCMD(CMD_MEAS_PERI_2_H);
}

 /**************************************************************************************
 * 描  述 : 初始化SHT3X传感器
 * 入  参 : 无
 * 返回值 : 无
 **************************************************************************************/
void SHT3X_Init(void)
{
    delay_ms(100); 
    SHT3X_SetPeriodicMeasurement();
    delay_ms(100); 
}

 /**************************************************************************************
 * 描  述 : 从SHT30读取状态信息
 * 入  参 : temp: 待读出地址
 * 返回值 :   1---成功读取,     0---失败
 **************************************************************************************/
//bit SHT3X_ReadState(uint8 *temp)
//{
//  if(!I2C_Start())return FALSE;
//	I2C_SendByte(i2cAddWrite_8bit);
//	if(!I2C_WaitAck())		{I2C_Stop(); return FALSE;}
//	I2C_SendByte(0xf3);
//	I2C_WaitAck();
//	I2C_SendByte(0X2d);
//	I2C_WaitAck();
//  I2C_Stop(); 
//	delay_ms(100);
//  if(!I2C_Start())return FALSE;
//	I2C_SendByte(i2cAddRead_8bit);
//	I2C_WaitAck();
//	temp[0] = I2C_ReceiveByte();
//	I2C_Ack();
//	temp[1] = I2C_ReceiveByte();
//	I2C_Ack();
//	temp[2] = I2C_ReceiveByte();
//	I2C_NoAck(); 
//  I2C_Stop(); 
//	return TRUE;
//}

 /**************************************************************************************
 * 描  述 : 从SHT30读取测量结果
 * 入  参 : cmd: 待配置命令    p：待读出地址
 * 返回值 :   1---成功读取,     0---失败
 **************************************************************************************/
bit SHX3X_ReadResults(uint16 cmd,  uint8 *p)
{
	if(!I2C_Start())return FALSE;
	I2C_SendByte(0x88);
	if(!I2C_WaitAck())		{I2C_Stop(); return FALSE;}
	I2C_SendByte(cmd>>8);
	I2C_WaitAck();
	I2C_SendByte(cmd);
	I2C_WaitAck();
	I2C_Stop();
	
  if(!I2C_Start())return FALSE;
	I2C_SendByte(0x89);
	if(!I2C_WaitAck())		{I2C_Stop(); return FALSE;}

	p[0] = I2C_ReceiveByte();
	I2C_Ack();
	p[1] = I2C_ReceiveByte();
	I2C_Ack();
	p[2] = I2C_ReceiveByte();
	I2C_Ack();
	p[3] = I2C_ReceiveByte();
	I2C_Ack();
	p[4] = I2C_ReceiveByte();
	I2C_Ack();
	p[5] = I2C_ReceiveByte();
	I2C_NoAck();
	I2C_Stop();
	return TRUE;
}

 /**************************************************************************************
 * 描  述 : SHT30检测函数  crc校验
 * 入  参 : dat[]: 等待检验的数据   startByte: 开始数组的标号
            number: 检验个数         checksum: 接收到的CRC数据
 * 返回值 :   1---成功检测,     0---失败
 **************************************************************************************/
//bit SHT3x_CheckCrc(uint8 dat[],uint8 startBytes,uint8 number, uint8 checksum)
//{
//	uint8 temp=0;
//	uint8 crc = 0;	
//  uint8 byteCtr;
//  //calculates 8-Bit checksum with given polynomial
//  for (byteCtr = startBytes; byteCtr < startBytes+number; ++byteCtr)
//  { crc ^= (dat[byteCtr]);
//    for (temp = 8; temp > 0; --temp)
//    { if (crc & 0x80) crc = (crc << 1) ^ POLYNOMIAL;
//      else crc = (crc << 1);
//    }
//  }
//  if (crc ==checksum) 
//	return TRUE;
//  else
//	return FALSE;
//}

 /**************************************************************************************
 * 描  述 : 计算温度函数
 * 入  参 : dat：读取的温度信息
 * 返回值 : 计算出的温度值
 **************************************************************************************/
float SHT3X_CalcTemperature(uint16 dat)
{
    // calculate temperature 
    float temp;
    temp = (175 * (float)dat / 65535 - 45) ; // T = -45 + 175 * rawValue / (2^16-1)
    return temp;
}

 /**************************************************************************************
 * 描  述 : 计算湿度函数
 * 入  参 : dat：读取的湿度信息
 * 返回值 : 计算出的湿度值
 **************************************************************************************/
float SHT3X_CalcRH(uint16 dat)
{
    // calculate relative humidity [%RH]
	float temp;
  temp = (100 * (float)dat / 65535) ;  // RH = rawValue / (2^16-1) * 10
  return temp;
}

 /**************************************************************************************
 * 描  述 : SHT30函数 获取温度、湿度
 * 入  参 : 无
 * 返回值 : 无
 **************************************************************************************/
int SHT3X_Get(void)
{
   float p[6];
	 float cTemp,rhTemp;
    
		SHT3X_SetPeriodicMeasurement();		//初始化sh3X,设置命令；
	
	 //周期模式读出温湿度原始值，将原始值存放数组p
   if(SHX3X_ReadResults(CMD_FETCH_DATA, buffer))
	 {
     p[0] = buffer[0];
     p[1] = buffer[1];
     p[2] = buffer[2];
	   p[3] = buffer[3];
     p[4] = buffer[4];
     p[5] = buffer[5];
	 }
	 
   //计算温度原始信息，并带入算法计算出实际温度值
	 cTemp = (p[0] * 256.0) + p[1];
	 temperatureC =SHT3X_CalcTemperature(cTemp);
	 
	 if(temperatureC>120)	return 0;
	 if(temperatureC<-44)	return 0;
	 
	 
   //计算湿度原始信息，并带入算法计算出实际湿度值
	 rhTemp = (p[3] * 256.0) + p[4];
	 humidityRH = SHT3X_CalcRH(rhTemp);
	
	 //串口1上传温湿度信息
	 
//	P_SW1&=0X3F;     //串口1切换回 P30 P31
//	TXEN485 = 1;			//控制485发送功能，需要发送时设定
	 
	 fTempM[8] = temperatureC*10;					//值放大10倍的整数，实际精确到1位小数
	 fTempM[9] = humidityRH*10;
	 
	 if(fTempM[8] <= -440)			//未接传感器SHT30，温度为-450
	 {
			fTempM[8] = 0;					
			fTempM[9] = 0;
	 }
	 
//	 printf("温度：%f\r\n",fTempM[0]);
//	 printf("湿度：%f\r\n",fTempM[1]);
//	
//	TXEN485 = 0;			//控制485接收功能
//	P_SW1|=0X40;     	//串口1切换 P36,P37		
//	P_SW1&=0X7F; 			//串口1切换 P36,P37	

		return 1;
}
