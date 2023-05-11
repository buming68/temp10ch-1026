#include "ds18b20.h" 
#include  "config.h"

bit ReadTempFlag;


///******************************************************************************
// * ��  �� : ds18b20��ʼ��		��·
// * ��  �� : ��
// * ����ֵ : ��ʼ���ɹ�:0
// *          ��ʼ��ʧ��:1
// *****************************************************************************/
//unsigned char Init_Ds18b20(void)
//{
//    unsigned char Status = 0x00;
//    unsigned int CONT_1 = 0;
//    unsigned char Flag_1 = 1;

//    Ds18b20IO_1 = 1;      //DQ��λ
//    delayus(260);  //������ʱ
//    Ds18b20IO_1 = 0;      //��Ƭ����DQ����
//    delayus(750);  //��ȷ��ʱ ���� 480us С��960us
//    Ds18b20IO_1 = 1;      //��������
//    while((Ds18b20IO_1 != 0)&&(Flag_1 == 1)) 	//�ȴ�ds18b20��Ӧ�����з�ֹ��ʱ����
//    {                                      		//�ȴ�Լ60ms����
//				uart1_rece_proc();										//������յ��Ĵ���1������
//       
//				CONT_1++;
//        delayus(400);
//			
//        if(CONT_1 > 200)	Flag_1 = 0;
//        Status = Ds18b20IO_1;
//    }
//    Ds18b20IO_1 = 1;
//    delayus(100);
//    
//    return Status;       //���س�ʼ��״̬
//}

/******************************************************************************
 * ��  �� : ds18b20_8��ʼ��  (8���¶ȴ����� ͬʱ��ʼ��)
 * ��  �� : ��
 * ����ֵ : ��ʼ���ɹ�:0
 *          ��ʼ��ʧ��:1
 *****************************************************************************/
unsigned char Init_Ds18b20_8(void)
{
    unsigned char Status = 0x00;
    unsigned int CONT_1 = 0;
    unsigned char Flag_1 = 1;

    P1 = 0xFF;      		//DQ��λ
    delayus(260);  		//������ʱ
    P1 = 0;      				//��Ƭ����DQ����
    delayus(750);  		//��ȷ��ʱ ���� 480us С��960us
    P1 = 0xFF;      		//��������
    while((Ds18b20IO_1 != 0)&&(Flag_1 == 1)) 	//�ȴ�ds18b20��Ӧ�����з�ֹ��ʱ����
    {                                      		//�ȴ�Լ60ms����
				uart1_rece_proc();										//������յ��Ĵ���1������
       
				CONT_1++;
        delayus(400);
				//delayus(300);
			
        if(CONT_1 > 200)	Flag_1 = 0;
        Status = Ds18b20IO_1;
    }
    Ds18b20IO_1 = 1;
    delayus(100);
		//delayus(100);
		P1 = 0xFF;
    
    return Status;       //���س�ʼ��״̬
}

///******************************************************************************
// * ��  �� : Ds18b20д������д��1���ֽ�   		��·
// * ��  �� : ��
// * ����ֵ : ��
// *****************************************************************************/
//void Ds18b20Write(unsigned char dat)
//{
//    unsigned int i;
//    
//    for(i=0;i<8;i++)
//    {
//        if((dat & 0x01))
//        {
//            Ds18b20IO_1 = 0;
//            delayus(1);
//            Ds18b20IO_1 = 1;
//            delayus(60);
//        }
//        else
//        {
//            Ds18b20IO_1 = 0;
//            delayus(60);
//            Ds18b20IO_1 = 1;
//            delayus(1);
//        }
//        dat >>= 1;
//    }
//}

/******************************************************************************
 * ��  �� : Ds18b20д������д��1���ֽ�  8��������ͬʱд
 * ��  �� : ��
 * ����ֵ : ��
 *****************************************************************************/
void Ds18b20Write_8(unsigned char dat)
{
    unsigned int i;
	
EA = 0;               //���ж�����	
	
    for(i=0;i<8;i++)
    {
        if((dat & 0x01))
        {
            P1 = 0;
            delayus(1);
            P1 = 0xFF;
            delayus(60);
        }
        else
        {
            P1 = 0;
            delayus(60);
            P1 = 0xFF;
            delayus(1);
        }
        dat >>= 1;
    }
		
EA = 1;               //���жϴ�	
		
}



///******************************************************************************
// * ��  �� : Ds18b20������������1���ֽ�  		��·
// * ��  �� : ��
// * ����ֵ : ��ȡ��1�ֽ�����
// *****************************************************************************/
//unsigned char Ds18b20Read(void)
//{
//    unsigned char Value = 0x00;
//    unsigned int i;

//    Ds18b20IO_1 = 1;
//    delayus(10);
//    for(i=0;i<8;i++)
//    {
//        Value >>= 1; 
//        Ds18b20IO_1 = 0;// �������ź�
//        delayus(1);
//        Ds18b20IO_1 = 1;// �������ź�
//        delayus(1);
//        if(Ds18b20IO_1 == 1) Value |= 0x80;
//        delayus(60);
//    } 
//    return Value;
//}


/******************************************************************************
 * ��  �� : Ds18b20������������1���ֽ�  8��������ͬʱ��
 * �˳������ã�������ȡ4·Ϊ�ս�ʱ��������5���������޷�������
 * ��  �� : ��
 * ����ֵ : ��ȡ��1�ֽ�����			
 *****************************************************************************/
//void Ds18b20Read_8(unsigned char *Valueptr)
//{
//    unsigned int i, j;

//    P1 = 0xFF;
//    delayus(10);
//    for(i=0;i<8;i++)
//    {
//      for(j=0; j<8; j++)	Valueptr[j] >>= 1; 
//			P1 = 0;				// �������ź�
//			delayus(1);
//			P1 = 0xFF;		// �������ź�
//			delayus(1);
//			if(Ds18b20IO_1 == 1) Valueptr[0] |= 0x80;
//			if(Ds18b20IO_2 == 1) Valueptr[1] |= 0x80;
//			if(Ds18b20IO_3 == 1) Valueptr[2] |= 0x80;
//			if(Ds18b20IO_4 == 1) Valueptr[3] |= 0x80;
//			if(Ds18b20IO_5 == 1) Valueptr[4] |= 0x80;
//			if(Ds18b20IO_6 == 1) Valueptr[5] |= 0x80;
//			if(Ds18b20IO_7 == 1) Valueptr[6] |= 0x80;
//			if(Ds18b20IO_8 == 1) Valueptr[7] |= 0x80;
//			
//      delayus(60);
//    } 
//}
void Ds18b20Read_8(unsigned char *Valueptr)
{
    unsigned int i, j;

    P1 = 0xFF;
    delayus(10);
    for(i=0;i<8;i++)
    {
      for(j=0; j<4; j++)	Valueptr[j] >>= 1; 
			P1 = 0xF0;							// �������ź�
			delayus(1);
			P1 = 0xFF;							// �������ź�
			delayus(1);
			if(Ds18b20IO_1 == 1) Valueptr[0] |= 0x80;			//�ȶ�ȡǰ4·
			if(Ds18b20IO_2 == 1) Valueptr[1] |= 0x80;
			if(Ds18b20IO_3 == 1) Valueptr[2] |= 0x80;
			if(Ds18b20IO_4 == 1) Valueptr[3] |= 0x80;
//			if(Ds18b20IO_5 == 1) Valueptr[4] |= 0x80;
//			if(Ds18b20IO_6 == 1) Valueptr[5] |= 0x80;
//			if(Ds18b20IO_7 == 1) Valueptr[6] |= 0x80;
//			if(Ds18b20IO_8 == 1) Valueptr[7] |= 0x80;
			
      delayus(60);
    } 

    for(i=0;i<8;i++)
    {
      for(j=4; j<8; j++)	Valueptr[j] >>= 1; 
			P1 = 0x0F;				// �������ź�
			delayus(1);
			P1 = 0xFF;		// �������ź�
			delayus(1);
//			if(Ds18b20IO_1 == 1) Valueptr[0] |= 0x80;
//			if(Ds18b20IO_2 == 1) Valueptr[1] |= 0x80;
//			if(Ds18b20IO_3 == 1) Valueptr[2] |= 0x80;
//			if(Ds18b20IO_4 == 1) Valueptr[3] |= 0x80;
			if(Ds18b20IO_5 == 1) Valueptr[4] |= 0x80;		//�ٶ�ȡ��4·
			if(Ds18b20IO_6 == 1) Valueptr[5] |= 0x80;
			if(Ds18b20IO_7 == 1) Valueptr[6] |= 0x80;
			if(Ds18b20IO_8 == 1) Valueptr[7] |= 0x80;
			
      delayus(60);
    } 
}
//void Ds18b20Read_8(unsigned char *Valueptr)
//{
//    unsigned int i, j;

//    P1 = 0xFF;
//    delayus(10);
//    for(i=0;i<8;i++)
//    {
//      for(j=0; j<4; j++)	Valueptr[j] >>= 1; 
//			P1 = 0x0F;							// �������ź�
//			delayus(1);
//			P1 = 0xFF;							// �������ź�
//			delayus(1);
////			if(Ds18b20IO_1 == 1) Valueptr[0] |= 0x80;			//�ȶ�ȡǰ4·
////			if(Ds18b20IO_2 == 1) Valueptr[1] |= 0x80;
////			if(Ds18b20IO_3 == 1) Valueptr[2] |= 0x80;
////			if(Ds18b20IO_4 == 1) Valueptr[3] |= 0x80;
//			if(Ds18b20IO_5 == 1) Valueptr[4] |= 0x80;
//			if(Ds18b20IO_6 == 1) Valueptr[5] |= 0x80;
//			if(Ds18b20IO_7 == 1) Valueptr[6] |= 0x80;
//			if(Ds18b20IO_8 == 1) Valueptr[7] |= 0x80;
//			
//      delayus(60);
//    } 

//    for(i=0;i<8;i++)
//    {
//      for(j=4; j<8; j++)	Valueptr[j] >>= 1; 
//			P1 = 0xF0;				// �������ź�
//			delayus(1);
//			P1 = 0xFF;		// �������ź�
//			delayus(1);
//			if(Ds18b20IO_1 == 1) Valueptr[0] |= 0x80;
//			if(Ds18b20IO_2 == 1) Valueptr[1] |= 0x80;
//			if(Ds18b20IO_3 == 1) Valueptr[2] |= 0x80;
//			if(Ds18b20IO_4 == 1) Valueptr[3] |= 0x80;
////			if(Ds18b20IO_5 == 1) Valueptr[4] |= 0x80;		//�ٶ�ȡ��4·
////			if(Ds18b20IO_6 == 1) Valueptr[5] |= 0x80;
////			if(Ds18b20IO_7 == 1) Valueptr[6] |= 0x80;
////			if(Ds18b20IO_8 == 1) Valueptr[7] |= 0x80;
//			
//      delayus(60);
//    } 
//}

///******************************************************************************
// * ��  �� : �¶ȶ�ȡ���� ��1λС��λ   		��·
// * ��  �� : ��
// * ����ֵ : �¶�ֵ
// *****************************************************************************/
//float floatReadDs18B20(void) 
//{
//		uint8 th;
//		uint8 tl;
//    unsigned char V1,V2;   //����ߵ�8λ ����
//    float fValue;

//		unsigned int CONT_2 = 150;

//    Init_Ds18b20();
//    Ds18b20Write(0xcc);    // ����������кŵĲ���
//    Ds18b20Write(0x44);    // �����¶�ת��
//	
//		while(CONT_2--)					//150*5ms = 750ms ��ʱ
//		{
//					uart1_rece_proc();			//������յ��Ĵ���1������
//					delay_ms(5);
//		}	
//	    
//    Init_Ds18b20();
//    Ds18b20Write(0xcc);    //����������кŵĲ��� 
//    Ds18b20Write(0xbe);    //��ȡ�¶ȼĴ����ȣ����ɶ�9���Ĵ����� ǰ���������¶�
//    
//    V1 = Ds18b20Read();    //�¶�ֵ��λ
//    V2 = Ds18b20Read();    //�¶�ֵ��λ

//		tl = V1 & 0x0F;		//ȡ���ֽں���λ 
//		th = (V2 << 4) + (V1 >> 4);	//ȡ���ֽں���λ�͵��ֽ�ǰ��λ
//		fValue = th;						//��������
//		if (V2 > 0x08)
//		{
//			th = ~th + 1;						//ȡ����һ
//			fValue = -th;						//����
//		}
//		fValue += tl * 0.0625;		//�Ŵ�XX��
//		return  10*fValue;
//	
//}

/******************************************************************************
 * ��  �� : �¶ȶ�ȡ���� ��1λС��λ
 * ��  �� : ��
 * ����ֵ : �ޣ����� float fTempM[8]
 *****************************************************************************/
void floatReadDs18B20_8(float *tempptr) 
{
		uint8 th;
		uint8 tl;
    unsigned char V1M[8]=0,V2M[8]=0;   //����ߵ�8λ ����
    float fValue;
		unsigned int CONT_2 = 150;
		uint8 i;

    Init_Ds18b20_8();
    Ds18b20Write_8(0xcc);    // ����������кŵĲ���
    Ds18b20Write_8(0x44);    // �����¶�ת��
	
		while(CONT_2--)					//150*5ms = 750ms ��ʱ
		{
					uart1_rece_proc();			//������յ��Ĵ���1������
					delay_ms(5);
		}	
	    
    Init_Ds18b20_8();
    Ds18b20Write_8(0xcc);    //����������кŵĲ��� 
    Ds18b20Write_8(0xbe);    //��ȡ�¶ȼĴ����ȣ����ɶ�9���Ĵ����� ǰ���������¶�
    
    Ds18b20Read_8(V1M);    //�¶�ֵ��λ
    Ds18b20Read_8(V2M);    //�¶�ֵ��λ

		for(i=0; i<8; i++)
		{
			tl = V1M[i] & 0x0F;		//ȡ���ֽں���λ 
			th = (V2M[i] << 4) + (V1M[i] >> 4);	//ȡ���ֽں���λ�͵��ֽ�ǰ��λ
			fValue = th;						//��������
			if (V2M[i] > 0x08)
			{
				th = ~th + 1;						//ȡ����һ
				fValue = -th;						//����
			}
			fValue += tl * 0.0625;		//�Ŵ�XX��
			
			if((fValue<120)&&(fValue>-50))	*(tempptr++) =  10*fValue;
		}
}


//    V1 = 0x91;    		//�¶�ֵ��λ +25.06�� �������
//    V2 = 0x01;    		//�¶�ֵ��λ
//    V1 = 0x5E;    		//�¶�ֵ��λ -10.125��
//    V2 = 0xFF;    		//�¶�ֵ��λ

/*********************************END FILE*************************************/