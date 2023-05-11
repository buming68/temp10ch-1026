#ifndef __CONFIG_H_
#define __CONFIG_H_

#define MAIN_Fosc		11059200L	//������ʱ��
#include	"15W4KxxS4.H"

#include <string.h>
#include <stdio.h>
#include <intrins.H>

/********************************************
				���ű�������
*********************************************/
//sbit led=P3^3;   			//��ɫLED��IO��P33

sbit LED_R=P3^2;     	//��ɫLED��IO��P32
sbit LED_G=P3^3;     	//��ɫLED��IO��P33
sbit LED_B=P3^4;     	//��ɫLED��IO��P34

sbit TXEN485 = P5^5;	//485���Ϳ��ƿڣ�����Ϊ1������Ϊ0

/*******************************************
		  ���Բ���  DEBUG
			1---����    P30��P31 ���������Ϣ��������Ӧ��
			0---�ǵ���  ������������Ӧ�ٶȿ�
*********************************************/
//#define DEBUG


/*******************************************
		����ȱʡ����
*********************************************/
#define BaudFLAG 0x05						//���ʱ�־ 5--9600����ʼȱʡֵ����P27=0��  	6--19200��P27=1��
#define DefaultAddress 0x01			//���ʵ�ַ��DIP��ַΪ0ʱ���ɴ����趨��ַ
#define AutoTxTime 0x00					//DIP��ַΪ0ʱ���Զ��ش����ʱ��	 0---���ش�  ����ֵ---���ʱ�䣬��λ��
																//DIP��ַ��0ʱ��1-32��P20--P24������:P25 P26Ϊ��00---���Զ��ش�
																//01----�Զ��ش����1��    10---���3��      11----���5��	

/*******************************************
		����ȫ�ֳ���
*********************************************/
#define RX_MAX_LEN 20 
#define SEND_MAX_LEN 30


#define  uint32   unsigned long
#define  uint16   unsigned int  
#define  uint8    unsigned char  

typedef unsigned char BYTE;
typedef unsigned int WORD;

extern void delay_ms(uint16 x);
extern void delayus(unsigned char n);
extern void IO_init(void);


#endif
