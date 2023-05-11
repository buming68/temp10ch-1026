#ifndef __TIMER_H_
#define __TIMER_H_
  
#define T_MS   3 				//定时时间常量，单位ms  4ms定时中断 对9600速率参考值
#define T1TMS    (T_MS*MAIN_Fosc/1000)       //1T模式下  

#include "config.h"	

void Timer0Init(void);

void Timer2Init(void);
void SendStringByUart1(uint8 *s);

extern uint8 Recv_Cnt;		//接收字节个数，缓冲区索引
extern uint8 Recv_OK;		//一帧接收完成标志

#endif
