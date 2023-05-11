#ifndef __UART_H_
#define __UART_H_

#include	"timer.h"
#include "flashrom.h"

//#define RX_MAX_LEN 20 
//#define SEND_MAX_LEN 30

extern void Uart1_Init(void);
extern void SendStringByUart1(uint8 *s);
extern void SendDataByUart1(uint8 dat);

extern volatile uint8 Flag;
extern uint8 Uart1_RX_Buffer[RX_MAX_LEN];	//接收缓冲区
extern uint8 Recv_Cnt;										//接收字节个数，缓冲区索引
extern uint8 Recv_OK;											//一帧接收完成标志

extern uint8 Uart1_SEND_Buffer[SEND_MAX_LEN];		//发送缓冲区

#endif


