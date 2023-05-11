#include	"receservice.h"

float fTempM[10]=0 ;					//8·�¶�ȫ�ֱ���,��ʼ��Ϊ0��,����ƽ��ֵ
float fTempM6[4][10]=0 ;					//8·�¶�ȫ�ֱ���,��ʼ��Ϊ0�ȣ�6�β�����ֵ����ƽ��
unsigned char strTemp[30];		//ȫ����ʱ�������������



/******************************************************
��������uart1_rece_proc(void)
���ܣ������ڽ��յ���Ч���ݣ��յ�֡������־��
�������޲���
*******************************************************/
void uart1_rece_proc(void)
{
		if(Recv_OK)
		{	
//			uart1_rece_ack();				//���������Ͳ�����Ϣ���򴮿ڷ�������
			
#ifdef DEBUG									//���������Ϣ
		S1_USE_P30P31();					//����1�л��� P30 P31 ���Կ�	
			
		sprintf(strTemp, "%d-%d-%d-%d-%d", (int)fTempM[0],(int)fTempM[1],(int)fTempM[2],(int)fTempM[3],(int)fTempM[4]); //������ת���ַ��� 
		SendStringByUart1(strTemp);       //���ڴ�ӡ���¶�ֵ
		sprintf(strTemp, "-%d-%d-%d-%d-%d%%\r\n", (int)fTempM[5],(int)fTempM[6],(int)fTempM[7],(int)fTempM[8],(int)fTempM[9]); //������ת���ַ��� 
		SendStringByUart1(strTemp);       //���ڴ�ӡ���¶�ֵ
			
		S1_USE_P36P37();					//����1�л� P36,P37	
#endif
			
			uart1_rece_ack();				//���������Ͳ�����Ϣ���򴮿ڷ�������
			
			REN = 1;								//�����ڽ���
			Recv_Cnt = 0;						//����1���ռ�����0
			Recv_OK = 0;						//�崮��1���ձ�־
		}	
}

/******************************************************
��������uart1_auto_tx(void)
���ܣ��Զ���ʱ����10�����������¶�:8+1���¶�+1��ʪ��
�������޲���
*******************************************************/
void uart1_auto_tx(void)
{			
		uint16 crc16bit;	

		Recv_Cnt = 0x08;										//8�����ݣ�ֻ������8��
			
		Uart1_RX_Buffer[0] = BaudAddr[1];		//��վ��ַ
		Uart1_RX_Buffer[1] = 0x03;					//ģ���ѯ������ 03
		Uart1_RX_Buffer[2] = 0x00;
		Uart1_RX_Buffer[3] = 0x00;
		Uart1_RX_Buffer[4] = 0x00;
		Uart1_RX_Buffer[5] = 0x0A;					//��ȡ2���¶Ⱥ�ʪ����ֵ8+2=10
//		if(CHNUM == 1)	Uart1_RX_Buffer[5] = 0x01;					//��ȡ1���¶���ֵ	
		crc16bit = crc16(Uart1_RX_Buffer, Recv_Cnt - 2);		//����CRC
		Uart1_RX_Buffer[6] = crc16bit /256;		
		Uart1_RX_Buffer[7] = crc16bit %256;	

		uart1_rece_ack();				//���������Ͳ�����Ϣ���Զ��ش�	
	
		REN = 1;							//�����ڽ���
		Recv_Cnt = 0;					//����1���ռ�����0
		Recv_OK = 0;					//�崮��1���ձ�־
}

/******************************************************
��������uart1_rece_ack()
���ܣ����ݽ��յ���Uart1_RX_Buffer[]���ݣ�����λ�����ط�������
�������޲���������ȫ�����飩
*******************************************************/
void uart1_rece_ack()				//���������Ͳ�����Ϣ��
{
//	uint8 Uart1_RX_Buffer[8] = {0x30,0x03,0x00,0x00,0x00,0x01,0x80,0x2B};  //У���� 802B
//  uint8 Uart1_RX_Buffer[8] = {0x30,0x03,0x00,0x00,0x00,0x02,0xC0,0x2A};		
//  uint8 Uart1_RX_Buffer[8] = {0x00,0x03,0x00,0x00,0x00,0x01,0x85,0xDB};  //�㲥���Ե�ַ
//	uint8 Uart1_RX_Buffer[8] = {0x00,0x03,0x00,0x01,0x00,0x01,0xD4,0x1B};  //��ѯ�ӻ���ַ49=0x31
//	uint8 Uart1_RX_Buffer[8] = {0x00,0x06,0x00,0x01,0x00,0x31,0x18,0x0F};  //���ôӻ���ַ
//	uint8 Uart1_RX_Buffer[8] = {0x00,0x06,0x00,0x25,0x55,0xAA,0x26,0xFF};  //�����λ����
//	uint8 Uart1_RX_Buffer[8] = {0x30,0x03,0x00,0x00,0x00,0x02,0xC0,0x2A};  //˫·�¶Ȼش�����
//	uint8 Uart1_RX_Buffer[8] = {0x30,0x03,0x00,0x00,0x00,0x03,0x01,0xEA};  //��·�¶Ȼش�����
//	uint8 Uart1_RX_Buffer[8] = {0x00,0x06,0x01,0x09,0x12,0x34,0x54,0x92};  //�ָ�������������05 01 00	
//	uint8	Recv_Cnt = 8;
	
	uint16 crc16bit;	
	uint8	send_cnt = 0;
	uint8 rsp_cnt, err=RECV_NO_ERROR;
	uint8 i;
	uint8 j;
	float aver_temp[4] = 0;
	
	crc16bit = crc16(Uart1_RX_Buffer, Recv_Cnt - 2);
	if(memcmp(Uart1_RX_Buffer + Recv_Cnt - 2 , &crc16bit, 2)==0)
	{				
			memcpy(Uart1_SEND_Buffer, Uart1_RX_Buffer, 2);    //modbus addr + func code
		
		//TXEN485 = 1;					//����485���͹��ܣ���Ҫ����ʱ�趨	
		for(i=0; i<8; i++)			//����10������ֵ��ƽ��ֵ,����fTempM
		{
			for(j=0; j<4; j++)	
			{
				aver_temp[j] = fTempM6[j][i];
				//printf("%d--",(int) fTempM6[j][i]);
			}
			
			fTempM[i] = Temp_Average_Get(aver_temp);
			//printf("\nƽ���¶�%d\n", (int) fTempM[i]);			
		}
		//TXEN485 = 0;					//����485���չ���		
				
			rsp_cnt = Modbus_Req_Func_Match(Uart1_RX_Buffer+1, Recv_Cnt, Uart1_SEND_Buffer+2,&err);
			if(rsp_cnt == 0)           	//֡���ȴ���ʱ��rsp_cntΪ0��������
        return;

			if (err != RECV_NO_ERROR){
					Uart1_SEND_Buffer[1] += 0x80;
					Uart1_SEND_Buffer[2] = err;
					rsp_cnt = 3;
			}
			else rsp_cnt += 2;         //����pdu���Ȳ�������ַ�͹�����
			
			send_cnt = rsp_cnt; 			//���͵���Ч���ݳ��ȣ�����2λCRC
			
			crc16bit = crc16(Uart1_SEND_Buffer, send_cnt);	//��CRC16
			Uart1_SEND_Buffer[send_cnt] = crc16bit>>8 ;
			Uart1_SEND_Buffer[send_cnt+1] = crc16bit;

			TXEN485 = 1;							//����485���͹��ܣ���Ҫ����ʱ�趨
			for(i=0; i<send_cnt+2; i++)
			{
				SendDataByUart1(Uart1_SEND_Buffer[i]);			//����Ӧ���������
			}		
			TXEN485 = 0;							//����485���չ���
	}
}

//Modbus������������ƥ��
/**
  *	  ��������·�����Ӧ֡ȫ��payload���ֽ�����������֡ͷ��modbus��ַ�������룬��֡βCRCУ�����
  *   ����֡���ȴ���ʱ������0
  *   �Ƿ��������ַ�����Ȼ�����ֵʱ���豸�������ʱ��err��Ϊ0������-1
 */
uint8 Modbus_Req_Func_Match(uint8 *recv_pdu, uint8 recv_cnt, uint8 *send_pdu, uint8 *err)
{
    uint8 rsp_cnt;
    uint8 func_code;
    
    func_code = *recv_pdu++;
    switch(func_code){						//ֻ֧��04��06������
        case READ_COIL:						//01��02������ʹ��ʱ��������
        case READ_INPUT_COIL:*err = ILLEGAL_FUNCTION;break;  //��֧�ֵĹ������ȷ���01������
        case READ_HOLD_REG:				//03��04������ʹ��ʱ��������
        case READ_INPUT_REG:			//04������
							rsp_cnt=Read_Mb_Reg_Rsp(recv_pdu, recv_cnt, send_pdu, err);
							break;
        case WRITE_COIL:
        case WRITE_HOLD_REG:			//08������
							rsp_cnt=Write_Mb_Reg_Rsp(recv_pdu, recv_cnt, send_pdu, err);
							break;
        case WRITE_MULTI_COIL:
        case WRITE_MULTI_REG:
        default:*err = ILLEGAL_FUNCTION;break;              //��֧�ֵĹ������ȷ���01������
    }
    return rsp_cnt;
}

//�������Ĵ���ֵ��������0x03��0x04
uint8 Read_Mb_Reg_Rsp(uint8 *req_pdu, uint8 recv_cnt, uint8 *send_pdu, uint8 *err)
{
	uint16 req_addr,req_len,pdu_len;
	uint16 *pdu_ptr;

	if(recv_cnt != 8)           //������03��04�����󳤶�ֻ��Ϊ8byte 
			return 0;

	pdu_ptr = (uint16 *)req_pdu;
	req_addr =  (*pdu_ptr++)*1000;
	req_len  = *pdu_ptr;
	
	if(req_len == 0 || req_len > 125    //��׼����֡�������ܳ���
    || req_len > (SEND_MAX_LEN-5)/2){	//���ط�������
		*err = ILLEGAL_DATA_LEN;
		return -1;
	}

	*send_pdu++ = pdu_len = 2 * req_len;
	pdu_ptr = (uint16 *)send_pdu;
	
	while(req_len--){
		*pdu_ptr++ = Read_Modbus_Reg(req_addr++, err);	//����ַ��ȡ��Ӧ����ֵ
		if(*err != RECV_NO_ERROR)
			return -1;
	}
    return pdu_len+1;
}

//��modbus�Ĵ������,������0x03��0x04����
uint16 Read_Modbus_Reg(uint16 req_addr, uint8 *err)
{
	uint16 reg = 0xFFFF;   //Ԥ����modbus��ַ�������ض�����ֵ��ʾ����Ҳ����Ϊ0
		
	switch(req_addr){												//�Ĵ���0
        case 0:
						reg = (int) fTempM[0];
						break;
        case 1:		
						reg = (int) fTempM[1] ;	
						break;
				case 2:		
						reg = (int) fTempM[2];	
						break;
				case 3:		
						reg = (int) fTempM[3];	
						break;
				case 4:
						reg = (int) fTempM[4];
						break;
        case 5:		
						reg = (int) fTempM[5] ;	
						break;
				case 6:		
						reg = (int) fTempM[6];	
						break;
				case 7:		
						reg = (int) fTempM[7];	
						break;
				case 8:		
						reg = (int) fTempM[8];	
						break;				
				case 9:		
						reg = (int) fTempM[9];	
						break;
                                         
        //case 10:break;                                           
				case 1000:									//��ѯ485��ַ�ӻ���ַ  �Ĵ���1
					reg = BaudAddr[1];
					break;                   
				case 15000:									//��ѯ�ӻ��Ƿ��Զ����ͣ�0--���Զ�������---��� �Ĵ���15
					reg = BaudAddr[2];
					break;  
				case 3000:									//��ѯ�ӻ���ͨѶ���ʣ�5--9600 6---19200  �Ĵ���3
					reg = BaudAddr[0];
					break; 
				
		default:*err=ILLEGAL_DATA_ADDR;break;                   //�Ƿ���ַ
	}
	return reg;
}

//д�����Ĵ���ֵ��������0x06
uint8 Write_Mb_Reg_Rsp(uint8 *req_pdu, uint8 recv_cnt, uint8 *send_pdu, uint8 *err)
{
    uint16 req_addr,req_data;
		//uint16 req_len,pdu_len;
    uint16 *pdu_ptr;
		uint8 i;
	
    if(recv_cnt != 8)           //������06�����󳤶�ֻ��Ϊ8byte 
        return 0;

		for(i=0; i<4; i++)	*(send_pdu+i) = *(req_pdu+i);
		
		pdu_ptr = (uint16 *)req_pdu;
		req_addr = *pdu_ptr;
		req_data = (uint16)(*(pdu_ptr+1));
		Write_Modbus_Reg(req_addr, req_data, err);	//����ַ��ȡ��Ӧ����ֵ	

    return 4;
}

//��modbus�Ĵ������,������0x06����
uint16 Write_Modbus_Reg(uint16 req_addr, uint16 req_data, uint8 *err)
{
	uint16 reg = 0xFFFF;   //Ԥ����modbus��ַ�������ض�����ֵ��ʾ����Ҳ����Ϊ0
	
	switch(req_addr){
        case 1:										//���ô�վ��ַ	
						BaudAddr[1] = (uint8) req_data;				
						EEPROM_write_1(Addr_485, BaudAddr+1);	//BaudAddr[1] д��eeprom

						break;
				case 0x0025:							//������   37����
						IAP_CONTR = 0x20;
						break;
				
				case 0x0109:							//�ָ��������� 9600��վַ1  ���Զ�����0  263����
						if(req_data != 0x1234)	break;						//�ָ��������00 06 01 09 12 34 54 92
						EEPROM_Factory();
						IAP_CONTR = 0x20;													//������
						break;	
				case 0x000F:							//�����Ƿ��Զ��ش���1-255���Զ��ش�  0�����ش�
						BaudAddr[2] = (uint8) req_data;				
						EEPROM_write_1(Addr_autoT, BaudAddr+2);		//BaudAddr[1] д��eeprom
						IAP_CONTR = 0x20;
				
						break;	
				
					case 0x0003:					//����ͨѶ���ʣ�5--9600   6-19200��Ŀǰֻ֧��2��
						if((req_data==5) || (req_data==6))				
						{
								BaudAddr[0] = (uint8) req_data;				
								EEPROM_write_1(Addr_Baud, BaudAddr);	//BaudAddr[0] д��eeprom
								IAP_CONTR = 0x20;										//��������
						}
						break;	
				
			default:*err=ILLEGAL_DATA_ADDR;break;                   //�Ƿ���ַ
	}
	return reg;
}


//modbusrtu���岿��
/*
								unsigned char crc_high8;//modbusrtu_crc16Ч��
								unsigned char crc_low8;//modbusrtu_crc16Ч��
								//modbusrtu_crc16Ч��������ݰ�	//
								//unsigned char data_CRC[6] = {0x03,0x10,0x00,0x01,0x00,0x08};//У����91ED
								//unsigned char data_CRC[6] = {0x01,0x05,0x00,0x00,0xFF,0x00};//У����8C3A
								//modbusrtu_crc16Ч��������ݰ�	//
*/
//modbusrtu���岿��

//modbusrtu��������
/* CRC��λ�ֽ�ֵ��*/ 
const unsigned char code auchCRCHi[] = { //code��ʾ����ram
0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 
0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 
0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 
0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 
0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 
0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 
0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 
0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 
0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 
0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 
0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 
0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 
0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 
0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 
0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 
0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
0x80, 0x41, 0x00, 0xC1, 0x81, 0x40} ;/* CRC��λ�ֽ�ֵ��*/  
/* CRC��λ�ֽ�ֵ��*/ 
const unsigned char code auchCRCLo[] = { //code��ʾ����ram
0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06, 
0x07, 0xC7, 0x05, 0xC5, 0xC4, 0x04, 0xCC, 0x0C, 0x0D, 0xCD, 
0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09, 
0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A, 
0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC, 0x14, 0xD4, 
0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3, 
0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3, 
0xF2, 0x32, 0x36, 0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4, 
0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A, 
0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29, 
0xEB, 0x2B, 0x2A, 0xEA, 0xEE, 0x2E, 0x2F, 0xEF, 0x2D, 0xED, 
0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26, 
0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60, 
0x61, 0xA1, 0x63, 0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67, 
0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F, 
0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68, 
0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA, 0xBE, 0x7E, 
0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5, 
0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71, 
0x70, 0xB0, 0x50, 0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92, 
0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C, 
0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B, 
0x99, 0x59, 0x58, 0x98, 0x88, 0x48, 0x49, 0x89, 0x4B, 0x8B, 
0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C, 
0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42, 
0x43, 0x83, 0x41, 0x81, 0x80, 0x40} ;/* CRC��λ�ֽ�ֵ��*/ 

unsigned int crc16(unsigned char *puchMsg, unsigned int usDataLen) //����У�������׵�ַ����У������λ����
{ 
	unsigned char uchCRCHi = 0xFF ; /* ��CRC�ֽڳ�ʼ�� */ 
	unsigned char uchCRCLo = 0xFF ; /* ��CRC �ֽڳ�ʼ�� */ 
	unsigned long uIndex ; /* CRCѭ���е����� */ 
	while (usDataLen--) /* ������Ϣ������ */ 
	{ 
		
		uIndex = uchCRCHi ^ *puchMsg++ ; /* ����CRC */ 
		uchCRCHi = uchCRCLo ^ auchCRCHi[uIndex] ; /* ����CRC��λ */ 
		uchCRCLo = auchCRCLo[uIndex] ; 		/* ����CRC��λ */ 
	} 
				//���õ������ݴ��浽crc	
				//crc_high8=uchCRCHi;
				//crc_low8=uchCRCLo;
	
				//���õ������ݷŵ����ڽ����õ�������
	return (uchCRCHi << 8 | uchCRCLo) ; //����ֵ����  
}
//modbusrtu��������
//modbusrtu�������в���
				//�������溯�����Եõ�Ч������ һ���Ƿŵ����������ٷ���ȥ����ȥ��//����ֵ����  ��һ��
				//��������������������У�����ģ�//����ֵ����  ������ȡ��ע��
				//crc_high8=crc16(data_CRC,6)>>8;//crc��8λ
				//crc_low8=crc16(data_CRC,6) & 0xFF;//crc��8λ

				//crc16(data_CRC,6);//Ҳ�������������м�������������������к���Ч�����ݷŵ�crc_high8,crc_low8������ȫ�ֱ�����
//modbusrtu�������в���

/*********�������еĳ�ǿȥ��1����ߡ�1����ͺ�ļ���ƽ��ֵ****************/
float Temp_Average_Get(float *tempptr)
{
	float aver=0; 
	float min;
	float max;
	static int i;
	
	min = *tempptr;
	max = *tempptr;		
	
    for(i = 0;i < 4 ;++i)
	{
       aver+= *(tempptr+i);
       if(max<*(tempptr+i)) 		max=*(tempptr+i);
       else if(min>*(tempptr+i))	min=*(tempptr+i);
	}
    aver-=min+max;			
    aver/=(4 - 2);				
    //printf("%d\n", aver);	
	return aver;
}


/*********************************END FILE********************************************/	