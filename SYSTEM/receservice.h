#ifndef __RECESERVICE_H_
#define __RECESERVICE_H_

#include	"uart.h"
//#include  "config.h"

/**************************************************************************
		寄存器地址功能如下
		00 温度数据（04 功能码） 		-3276.8~3276.7 R		03    功能码
			 1-8  8路温度        9-温度       10-湿度
		01 设备地址（出厂默认 1） 					1~255 R/W		03 06 功能码

		15 自动发送间隔（出厂默认 0） 			1~255 R/W		03 06 功能码
		//33 模块随机 ID 0~65535 R

		37 	写 0X55AA(或任意值) 到寄存器重启设备 		W		06 		功能码
		265 写 0X1234 复位出厂设置           				W		06 		功能码
****************************************************************************/

//常用功能码宏定义
#define READ_COIL          0x01   //读线圈状态       DO 例如继电器、LED
#define READ_INPUT_COIL    0x02   //读输入线圈状态   DI 例如外部开关状态
#define READ_HOLD_REG      0x03   //读保持寄存器值   AO 例如温湿度设置值/温度，浮点数
#define READ_INPUT_REG     0x04   //读输入寄存器值   AI 例如4-20mA输入 温度测量值
#define WRITE_COIL         0x05   //写单个线圈状态   DO
#define WRITE_HOLD_REG     0x06   //写单个保持寄存器 AO 本机地址
#define WRITE_MULTI_COIL   0x0F   //写多个线圈状态   DO
#define WRITE_MULTI_REG    0x10   //写多个保持寄存器 AO

//错误码宏定义
#define RECV_NO_ERROR      0x00   
#define ILLEGAL_FUNCTION   0x01   //非法的功能码
#define ILLEGAL_DATA_ADDR  0x02   //非法起始地址 ADRR超界
#define ILLEGAL_DATA_LEN   0x03   //非法数据长度 ADDR+LEN超界
#define ILLEGAL_DATA_VALUE 0x03   //或写入非法数据值 如温度设定值超界
#define DEVICE_FAILURE     0x04   //设备服务故障

extern uint8 Uart1_SEND_Buffer[SEND_MAX_LEN];		//发送缓冲区
//extern uint8 CHNUM;

extern void uart1_rece_proc(void);			//处理串串口1接收到的数据
extern void uart1_rece_ack(void);				//向主机回送测温信息；
extern uint8 Modbus_Req_Func_Match(uint8 *recv_pdu, uint8 recv_cnt, uint8 *send_pdu, uint8 *err);
extern uint8 Read_Mb_Reg_Rsp(uint8 *req_pdu, uint8 recv_cnt, uint8 *send_pdu, uint8 *err);
extern uint16 Read_Modbus_Reg(uint16 req_addr, uint8 *err);
extern uint8 Write_Mb_Reg_Rsp(uint8 *req_pdu, uint8 recv_cnt, uint8 *send_pdu, uint8 *err);
extern uint16 Write_Modbus_Reg(uint16 req_addr, uint16 req_data, uint8 *err);

extern void uart1_auto_tx(void);
extern unsigned int crc16(unsigned char *puchMsg, unsigned int usDataLen);
extern unsigned char strTemp[30];

extern float fTempM6[4][10];

float Temp_Average_Get(float *tempptr); 	//计算平均值，去最高、最低，剩下2个平均
#endif


