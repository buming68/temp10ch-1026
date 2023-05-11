#include	"uart.h"

volatile uint8 Flag=FALSE;


//���ջ��������ݶ���
uint8 Uart1_RX_Buffer[RX_MAX_LEN];	//���ջ�����
uint8 Recv_Cnt = 0;									//�����ֽڸ���������������
uint8 Recv_OK = 0;									//һ֡������ɱ�־
uint8 Unitaddr = 0x30;							//������ַ

uint8 Uart1_SEND_Buffer[SEND_MAX_LEN];		//���ͻ���������config.h�ж���ȫ�ֱ���SEND_MAX_LEN


/***************************************************************************
 * ��  �� : ����1��ʼ������
 * ��  �� : ��
 * ����ֵ : ��
��ע��������9600bps   ����11.0592MHz
 **************************************************************************/
void Uart1_Init(void)
{	
//	P_SW1|=0X40;     	//����1�л� P36,P37				ȱʡ
//	P_SW1&=0X7F; 			//����1�л� P36,P37	
	
	S1_USE_P36P37();		//����1�л� P36,P37	
	TXEN485 = 0;				//��ʼ485�ڴ��ڽ���״̬		ȱʡ
	
	PCON &= 0x3f;				//�����ʲ����٣����пڹ�����ʽ��SM0��SM1����
	SCON = 0x50;				//8λ����,�ɱ䲨���ʣ��������н�����
	
	//AUXR |= 0x04;     //��ʱ��2ʱ��ΪFosc,��1T
	Timer2_1T();				//��ʱ��2ʱ��ΪFosc,��1T
	//AUXR |= 0x05;     	//��ʱ��2��Ϊ�����ʷ�����
	S1_BRT_UseTimer2();	//��ʱ��2��Ϊ�����ʷ�����

	T2L = (65536 - (MAIN_Fosc/4/9600)); //���ò�������װֵ,ȱʡ9600
	T2H = (65536 - (MAIN_Fosc/4/9600))>>8;	
	
	if(BaudAddr[0] == 0x06)
	{
			T2L = (65536 - (MAIN_Fosc/4/19200)); //���ò�������װֵ19200
			T2H = (65536 - (MAIN_Fosc/4/19200))>>8;	
	}

	
	//AUXR |= 0x10;     //������ʱ��2
	Timer2_Run();     //������ʱ��2
	
	//IE2 &= 0xfb;			//��ֹ��ʱ��2�ж�
	Timer2_InterruptDisable();	//��ֹ��ʱ��2�ж�
	ES = 1;         	// �����������жϣ���
}


/***************************************************************************
 * ��  �� : ����1�������ݺ���
 * ��  �� : uint8 ����
 * ����ֵ : ��
 **************************************************************************/
void SendDataByUart1(uint8 dat)
{
    SBUF = dat;                 //д���ݵ�UART���ݼĴ���
		while(TI == 0);             //��ֹͣλû�з���ʱ��TIΪ0��һֱ�ȴ�
		TI = 0;                     //���TIλ����λ�����������㣩
}

/***************************************************************************
 * ��  �� : ����1�����ַ�������
 * ��  �� : uint8 *s �������ַ��� 
 * ����ֵ : ��
 **************************************************************************/
void SendStringByUart1(uint8 *s)
{
	while(*s)
	{
		SendDataByUart1(*s++);       //���ַ����е��ַ�һ��һ������
	}
}

/***************************************************************************
 * ��  �� : �ض���c�⺯��printf��USART1
 * ��  �� : char dat
 * ����ֵ : char 
 **************************************************************************/
char putchar(char dat)
{
		SendDataByUart1(dat);           
		return dat;                    
}


/***************************************************************************
 * ��  �� : ����1�жϷ�����
 * ��  �� : ��
 * ����ֵ : ��
 **************************************************************************/
void Uart1() interrupt UART1_VECTOR using 1
{
	ES = 0;  	                  // ����1�жϹر�
	if (RI)                     //���н��յ�ֹͣλ���м�ʱ��ʱ����λ��1
  {
      RI = 0;                 //���RIλ ����λ�����������㣩
			
			//�Ǳ�����ַ���ݲ�����
			//�㲥��ַ0����վ��ַ���׸��ַ�����ʱ
			if(Recv_Cnt == 0 || Uart1_RX_Buffer[0] == BaudAddr[1] || Uart1_RX_Buffer[0] == 0x00)	//�ӻ���ַ,��EEPROM.C����
			{
					Uart1_RX_Buffer[Recv_Cnt++] = SBUF;
					if(Recv_Cnt >= RX_MAX_LEN)
							Recv_Cnt = 0;
					
					TR0 = 0;     				//�رն�ʱ��0��ʱ���������޷������趨TL0??				
					TL0 = (65536-T1TMS);       	//ÿ�ν��յ����ݣ���ʱ������װ�ض�ʱֵ
					TH0 = (65536-T1TMS) >> 8; 	//ÿ�ν��յ����ݣ���ʱ������װ�ض�ʱֵ
					TR0 = 1;     	 			//�򿪶�ʱ��0����ʼ���� 					
   	 			//�򿪶�ʱ��2����ʼ���� 
			}  
   }
   if (TI)                    //��ֹͣλ��ʼ����ʱ����λ��1
   {
      TI = 0;                 //���TIλ����λ�����������㣩
   }
	 ES =  1;                   // ����1�жϴ�
}


/*********************************END FILE********************************************/	
