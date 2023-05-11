
//	��������STCϵ�е�����EEPROM��д����
#include "eeprom.h"
#include	"uart.h"
#include "config.h"

u8 BaudAddr[3] = {0x05, 0x01, 0x00};		  		//ʵ��ͨѶ����1��485�ӿ�ȱʡ  ���ʱ�־����ַ���Ƿ��Զ��ش���1���Զ��ش���
u8 EEPROMTemp[3] = {0x05, 0x01, 0x00};				//ͨѶ����1��485�ӿ�ȱʡ  ���ʱ�־����ַ���Ƿ��Զ��ش���1���Զ��ش���

u16 Addr_Baud = MOVC_ShiftAddress;    				//eeprom ��1��������0��ʼ��
u16 Addr_485 = 0x0200 +MOVC_ShiftAddress;    	//��ס һ��Ҫ��ƫ�������ϣ���2��������512��ʼ��
u16 Addr_autoT = 0x0400 +MOVC_ShiftAddress;    //��ס һ��Ҫ��ƫ��������,eeprom ��3��������1K��ʼ��

//========================================================================
// ����: void	ISP_Disable(void)
// ����: ��ֹ����ISP/IAP.
// ����: non.
// ����: non.
//========================================================================
void	DisableEEPROM(void)
{
	ISP_CONTR = 0;			//��ֹISP/IAP����
	ISP_CMD   = 0;			//ȥ��ISP/IAP����
	ISP_TRIG  = 0;			//��ֹISP/IAP�����󴥷�
	ISP_ADDRH = 0xff;		//��0��ַ���ֽ�
	ISP_ADDRL = 0xff;		//��0��ַ���ֽڣ�ָ���EEPROM������ֹ�����
}

//========================================================================
// ����: void EEPROM_read_n(u16 EE_address,u8 *DataAddress,u16 number)
// ����: ��ָ��EEPROM�׵�ַ����n���ֽڷ�ָ���Ļ���.
// ����: EE_address:  ����EEPROM���׵�ַ.
//       DataAddress: �������ݷŻ�����׵�ַ.
//       number:      �������ֽڳ���.
// ����: non.
//========================================================================
void EEPROM_read_n(u16 EE_address,u8 *DataAddress,u16 number)
{
	EA = 0;		//��ֹ�ж�
	ISP_CONTR = (ISP_EN + ISP_WAIT_FREQUENCY);	//���õȴ�ʱ�䣬����ISP/IAP��������һ�ξ͹�
	ISP_READ();									//���ֽڶ���������ı�ʱ����������������
	do
	{
		ISP_ADDRH = EE_address / 256;		//�͵�ַ���ֽڣ���ַ��Ҫ�ı�ʱ���������͵�ַ��
		ISP_ADDRL = EE_address % 256;		//�͵�ַ���ֽ�
		ISP_TRIG();							//����5AH������A5H��ISP/IAP�����Ĵ�����ÿ�ζ���Ҫ���
											//����A5H��ISP/IAP������������������
											//CPU�ȴ�IAP��ɺ󣬲Ż����ִ�г���
		_nop_();
		*DataAddress = ISP_DATA;			//��������������
		EE_address++;
		DataAddress++;
	}while(--number);

	DisableEEPROM();
	EA = 1;		//���������ж�
}


/******************** ������������ *****************/
//========================================================================
// ����: void EEPROM_SectorErase(u16 EE_address)
// ����: ��ָ����ַ��EEPROM��������.
// ����: EE_address:  Ҫ����������EEPROM�ĵ�ַ.
// ����: non.
//========================================================================
void EEPROM_SectorErase(u16 EE_address)
{
	EA = 0;		//��ֹ�ж�
											//ֻ������������û���ֽڲ�����512�ֽ�/������
											//����������һ���ֽڵ�ַ����������ַ��
	ISP_CONTR = (ISP_EN + ISP_WAIT_FREQUENCY);	//���õȴ�ʱ�䣬����ISP/IAP��������һ�ξ͹�
	ISP_ADDRH = EE_address / 256;			//��������ַ���ֽڣ���ַ��Ҫ�ı�ʱ���������͵�ַ��
	ISP_ADDRL = EE_address % 256;			//��������ַ���ֽ�
	ISP_CONTR = (ISP_EN + ISP_WAIT_FREQUENCY);	//���õȴ�ʱ�䣬����ISP/IAP��������һ�ξ͹�
	ISP_ERASE();							//������������������ı�ʱ����������������
	ISP_TRIG();
	_nop_();
	DisableEEPROM();
	EA = 1;		//���������ж�
}

//========================================================================
// ����: void EEPROM_write_n(u16 EE_address,u8 *DataAddress,u16 number)
// ����: �ѻ����n���ֽ�д��ָ���׵�ַ��EEPROM.
// ����: EE_address:  д��EEPROM���׵�ַ.
//       DataAddress: д��Դ���ݵĻ�����׵�ַ.
//       number:      д����ֽڳ���.
// ����: non.
//========================================================================
void EEPROM_write_n(u16 EE_address,u8 *DataAddress,u16 number)
{
	EA = 0;		//��ֹ�ж�

	ISP_CONTR = (ISP_EN + ISP_WAIT_FREQUENCY);	//���õȴ�ʱ�䣬����ISP/IAP��������һ�ξ͹�
	ISP_WRITE();							//���ֽ�д��������ı�ʱ����������������
	do
	{
		ISP_ADDRH = EE_address / 256;		//�͵�ַ���ֽڣ���ַ��Ҫ�ı�ʱ���������͵�ַ��
		ISP_ADDRL = EE_address % 256;		//�͵�ַ���ֽ�
		ISP_DATA  = *DataAddress;			//�����ݵ�ISP_DATA��ֻ�����ݸı�ʱ����������
		ISP_TRIG();
		_nop_();
		EE_address++;
		DataAddress++;
	}while(--number);

	DisableEEPROM();
	EA = 1;		//���������ж�
}

//========================================================================
// ����: void EEPROM_Init()
// ��ʼ��
// ��ȡEEPROM�����ͨ�����ʱ�־���ӻ���ַ�����û�ж���������ȱʡֵ��������EEPROMTemp
// ����: non.
//========================================================================

void EEPROM_Init(void)
{
	unsigned char strTemp[8];
	
	EEPROM_read_n(Addr_Baud,BaudAddr,1);	//��FLASH���׵�ַΪ0xE000����ȡ���ֽڴ���������
	if(*BaudAddr == 0xff)	
		{
				EEPROM_SectorErase(Addr_Baud);    	   //��FLASH���׵�ַΪ0xE000��������������������
				EEPROM_write_n(Addr_Baud,EEPROMTemp,1);		//��FLASH���׵�ַΪд��1���ֽ�
		}
		
	EEPROM_read_n(Addr_485,BaudAddr+1,1);	//��FLASH���׵�ַΪ0xE000����ȡ1���ֽڴ���������		
	if(*(BaudAddr+1) == 0xff)	
	{
			EEPROM_SectorErase(Addr_485);    	   //��FLASH���׵�ַΪ0x????+200��������������������
			EEPROM_write_n(Addr_485,EEPROMTemp+1,1);		//��FLASH���׵�ַΪд��1���ֽ�
	}	
	
	EEPROM_read_n(Addr_autoT,BaudAddr+2,1);		//��FLASH���׵�ַΪ0x????����ȡ1���ֽڴ���������
	if(*(BaudAddr+2) == 0xff)	
	{
			EEPROM_SectorErase(Addr_autoT);    	   //��FLASH���׵�ַΪ0x????+400��������������������
			EEPROM_write_n(Addr_autoT,EEPROMTemp+2,1);		//��FLASH���׵�ַΪд��1���ֽ�
	}
	
			EEPROM_read_n(Addr_Baud,BaudAddr,1);	//��FLASH���׵�ַΪ0xE000����ȡ1���ֽڴ���������
			EEPROM_read_n(Addr_485,BaudAddr+1,1);	//��FLASH���׵�ַΪ0xE000+400 ����ȡ1���ֽڴ���������
			EEPROM_read_n(Addr_autoT,BaudAddr+2,1);	//��FLASH���׵�ַΪ0xE000+400 ����ȡ1���ֽڴ���������
		
			sprintf(strTemp, "%c%c%c\r\n", BaudAddr[0],BaudAddr[1],BaudAddr[2]); //������ת���ַ��� 
			SendStringByUart1(strTemp); 
}

//========================================================================
// ����: void EEPROM_write(u16 EE_address,u8 *DataAddress)
// ����: �ѻ����n���ֽ�д��ָ���׵�ַ��EEPROM.
// ����: EE_address:  д��EEPROM���׵�ַ.
//       DataAddress: д��Դ���ݵĻ�����׵�ַ.

// ����: non.
//========================================================================
uint8 EEPROM_write_1(u16 EE_address,u8 *DataAddress)
{
	uint8 write_count = 3;
	uint8 tempdata;
	
	while(write_count--)
	{
			EEPROM_SectorErase(EE_address);    	   				//��FLASH���׵�ַΪ0xE000+400��������������������
			EEPROM_write_n(EE_address, DataAddress, 1);		//��FLASH���׵�ַΪд��1���ֽ�
			EEPROM_read_n(EE_address, &tempdata,1);			//��FLASH���׵�ַΪ0xE000����ȡ1���ֽڴ���������
			if(*DataAddress == tempdata)
				return 0;																	//�ɹ�д��
	}
	return 1;
	
}


