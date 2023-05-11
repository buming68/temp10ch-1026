#include "sht30.h"


 float temperatureC;
 float humidityRH;

 uint8 buffer[6];

 /**************************************************************************************
 * ��  �� : ��SHT30д�Ĵ�������
 * ��  �� : cmd: ���ֽ�����
 * ����ֵ :   1---�ɹ�д��,     0---ʧ��
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
 * ��  �� : ���ò�������
 * ��  �� : ��
 * ����ֵ : ��
 **************************************************************************************/
void SHT3X_SetPeriodicMeasurement(void)
{
    SHT3X_WriteCMD(CMD_MEAS_PERI_2_H);
}

 /**************************************************************************************
 * ��  �� : ��ʼ��SHT3X������
 * ��  �� : ��
 * ����ֵ : ��
 **************************************************************************************/
void SHT3X_Init(void)
{
    delay_ms(100); 
    SHT3X_SetPeriodicMeasurement();
    delay_ms(100); 
}

 /**************************************************************************************
 * ��  �� : ��SHT30��ȡ״̬��Ϣ
 * ��  �� : temp: ��������ַ
 * ����ֵ :   1---�ɹ���ȡ,     0---ʧ��
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
 * ��  �� : ��SHT30��ȡ�������
 * ��  �� : cmd: ����������    p����������ַ
 * ����ֵ :   1---�ɹ���ȡ,     0---ʧ��
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
 * ��  �� : SHT30��⺯��  crcУ��
 * ��  �� : dat[]: �ȴ����������   startByte: ��ʼ����ı��
            number: �������         checksum: ���յ���CRC����
 * ����ֵ :   1---�ɹ����,     0---ʧ��
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
 * ��  �� : �����¶Ⱥ���
 * ��  �� : dat����ȡ���¶���Ϣ
 * ����ֵ : ��������¶�ֵ
 **************************************************************************************/
float SHT3X_CalcTemperature(uint16 dat)
{
    // calculate temperature 
    float temp;
    temp = (175 * (float)dat / 65535 - 45) ; // T = -45 + 175 * rawValue / (2^16-1)
    return temp;
}

 /**************************************************************************************
 * ��  �� : ����ʪ�Ⱥ���
 * ��  �� : dat����ȡ��ʪ����Ϣ
 * ����ֵ : �������ʪ��ֵ
 **************************************************************************************/
float SHT3X_CalcRH(uint16 dat)
{
    // calculate relative humidity [%RH]
	float temp;
  temp = (100 * (float)dat / 65535) ;  // RH = rawValue / (2^16-1) * 10
  return temp;
}

 /**************************************************************************************
 * ��  �� : SHT30���� ��ȡ�¶ȡ�ʪ��
 * ��  �� : ��
 * ����ֵ : ��
 **************************************************************************************/
int SHT3X_Get(void)
{
   float p[6];
	 float cTemp,rhTemp;
    
		SHT3X_SetPeriodicMeasurement();		//��ʼ��sh3X,�������
	
	 //����ģʽ������ʪ��ԭʼֵ����ԭʼֵ�������p
   if(SHX3X_ReadResults(CMD_FETCH_DATA, buffer))
	 {
     p[0] = buffer[0];
     p[1] = buffer[1];
     p[2] = buffer[2];
	   p[3] = buffer[3];
     p[4] = buffer[4];
     p[5] = buffer[5];
	 }
	 
   //�����¶�ԭʼ��Ϣ���������㷨�����ʵ���¶�ֵ
	 cTemp = (p[0] * 256.0) + p[1];
	 temperatureC =SHT3X_CalcTemperature(cTemp);
	 
	 if(temperatureC>120)	return 0;
	 if(temperatureC<-44)	return 0;
	 
	 
   //����ʪ��ԭʼ��Ϣ���������㷨�����ʵ��ʪ��ֵ
	 rhTemp = (p[3] * 256.0) + p[4];
	 humidityRH = SHT3X_CalcRH(rhTemp);
	
	 //����1�ϴ���ʪ����Ϣ
	 
//	P_SW1&=0X3F;     //����1�л��� P30 P31
//	TXEN485 = 1;			//����485���͹��ܣ���Ҫ����ʱ�趨
	 
	 fTempM[8] = temperatureC*10;					//ֵ�Ŵ�10����������ʵ�ʾ�ȷ��1λС��
	 fTempM[9] = humidityRH*10;
	 
	 if(fTempM[8] <= -440)			//δ�Ӵ�����SHT30���¶�Ϊ-450
	 {
			fTempM[8] = 0;					
			fTempM[9] = 0;
	 }
	 
//	 printf("�¶ȣ�%f\r\n",fTempM[0]);
//	 printf("ʪ�ȣ�%f\r\n",fTempM[1]);
//	
//	TXEN485 = 0;			//����485���չ���
//	P_SW1|=0X40;     	//����1�л� P36,P37		
//	P_SW1&=0X7F; 			//����1�л� P36,P37	

		return 1;
}
