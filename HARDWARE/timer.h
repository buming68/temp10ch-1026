#ifndef __TIMER_H_
#define __TIMER_H_
  
#define T_MS   3 				//��ʱʱ�䳣������λms  4ms��ʱ�ж� ��9600���ʲο�ֵ
#define T1TMS    (T_MS*MAIN_Fosc/1000)       //1Tģʽ��  

#include "config.h"	

void Timer0Init(void);

void Timer2Init(void);
void SendStringByUart1(uint8 *s);

extern uint8 Recv_Cnt;		//�����ֽڸ���������������
extern uint8 Recv_OK;		//һ֡������ɱ�־

#endif
