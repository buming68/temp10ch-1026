#ifndef __RECESERVICE_H_
#define __RECESERVICE_H_

#include	"uart.h"
//#include  "config.h"

/**************************************************************************
		�Ĵ�����ַ��������
		00 �¶����ݣ�04 �����룩 		-3276.8~3276.7 R		03    ������
			 1-8  8·�¶�        9-�¶�       10-ʪ��
		01 �豸��ַ������Ĭ�� 1�� 					1~255 R/W		03 06 ������

		15 �Զ����ͼ��������Ĭ�� 0�� 			1~255 R/W		03 06 ������
		//33 ģ����� ID 0~65535 R

		37 	д 0X55AA(������ֵ) ���Ĵ��������豸 		W		06 		������
		265 д 0X1234 ��λ��������           				W		06 		������
****************************************************************************/

//���ù�����궨��
#define READ_COIL          0x01   //����Ȧ״̬       DO ����̵�����LED
#define READ_INPUT_COIL    0x02   //��������Ȧ״̬   DI �����ⲿ����״̬
#define READ_HOLD_REG      0x03   //�����ּĴ���ֵ   AO ������ʪ������ֵ/�¶ȣ�������
#define READ_INPUT_REG     0x04   //������Ĵ���ֵ   AI ����4-20mA���� �¶Ȳ���ֵ
#define WRITE_COIL         0x05   //д������Ȧ״̬   DO
#define WRITE_HOLD_REG     0x06   //д�������ּĴ��� AO ������ַ
#define WRITE_MULTI_COIL   0x0F   //д�����Ȧ״̬   DO
#define WRITE_MULTI_REG    0x10   //д������ּĴ��� AO

//������궨��
#define RECV_NO_ERROR      0x00   
#define ILLEGAL_FUNCTION   0x01   //�Ƿ��Ĺ�����
#define ILLEGAL_DATA_ADDR  0x02   //�Ƿ���ʼ��ַ ADRR����
#define ILLEGAL_DATA_LEN   0x03   //�Ƿ����ݳ��� ADDR+LEN����
#define ILLEGAL_DATA_VALUE 0x03   //��д��Ƿ�����ֵ ���¶��趨ֵ����
#define DEVICE_FAILURE     0x04   //�豸�������

extern uint8 Uart1_SEND_Buffer[SEND_MAX_LEN];		//���ͻ�����
//extern uint8 CHNUM;

extern void uart1_rece_proc(void);			//��������1���յ�������
extern void uart1_rece_ack(void);				//���������Ͳ�����Ϣ��
extern uint8 Modbus_Req_Func_Match(uint8 *recv_pdu, uint8 recv_cnt, uint8 *send_pdu, uint8 *err);
extern uint8 Read_Mb_Reg_Rsp(uint8 *req_pdu, uint8 recv_cnt, uint8 *send_pdu, uint8 *err);
extern uint16 Read_Modbus_Reg(uint16 req_addr, uint8 *err);
extern uint8 Write_Mb_Reg_Rsp(uint8 *req_pdu, uint8 recv_cnt, uint8 *send_pdu, uint8 *err);
extern uint16 Write_Modbus_Reg(uint16 req_addr, uint16 req_data, uint8 *err);

extern void uart1_auto_tx(void);
extern unsigned int crc16(unsigned char *puchMsg, unsigned int usDataLen);
extern unsigned char strTemp[30];

extern float fTempM6[4][10];

float Temp_Average_Get(float *tempptr); 	//����ƽ��ֵ��ȥ��ߡ���ͣ�ʣ��2��ƽ��
#endif


