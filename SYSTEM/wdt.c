
#include	"wdt.h"

//========================================================================
//u8	Wdt_Inilize(WDT_InitTypeDef *WDTx)
// ����: ���Ź���ʼ������.
// ����: WDTx: �ṹ����,��ο�wdt.h��Ķ���.
// ����: �ɹ�����0, ���󷵻�2
//========================================================================
u8	Wdt_Inilize(WDT_InitTypeDef *WDTx)
{
   if(IDLE_Count==WDTx->WDT_IDLE)
   {
        WDT_CONTR|=(1<<3);      //IDLEģʽ���� 
   }
   else if(IDLE_Stop==WDTx->WDT_IDLE)
   {
        WDT_CONTR&=(~(1<<3));   //IDLEģʽ������ 
   } 
   else
   {
        return 2;
   }  
   
   if(7>=WDTx->WDT_CLOCK)
   {
        WDT_CONTR&=(~0x07);
        WDT_CONTR|=WDTx->WDT_CLOCK;  //�趨���Ź���������Ԥ��Ƶֵ  
   }
   else
   {
        return 2;
   }   

   if(ENABLE==WDTx->WDT_EN)
   {
        WDT_CONTR|=(1<<5);      //�����Ź�
   }
   else if(DISABLE==WDTx->WDT_EN)
   {
        WDT_CONTR&=(~(1<<5));   //��ֹ���Ź�
   } 
   else
   {
        return 2;
   }       

   return	0;		//�ɹ�
}


//========================================================================
//void	Wdt_EnOrNo(u8 theFlag)
// ����: ���Ź�����/��ֹ����
//��ʽ���� u8 theFlag 0=��ֹ  1=����
//========================================================================
void	Wdt_EnOrNo(u8 theFlag)
{
   if(1==theFlag)
   {
        WDT_CONTR|=(1<<5);      //�����Ź�
   }
   else
   {
        WDT_CONTR&=(~(1<<5));   //��ֹ���Ź�
   } 
}

//========================================================================
//void	Wdt_EnOrNo(u8 theFlag)
// ����: ���Ź�����/��ֹ����
//��ʽ���� u8 theFlag 0=��ֹ  1=����
//========================================================================
void Wdt_Feed(void)
{
    WDT_CONTR|=(1<<4);      //ι��
}

/**************************************************************************************
 * ��  �� : WDT���ú���
 * ��  �� : ��
 * ����ֵ : ��
 **************************************************************************************/
void	WDT_config(void)
{
    WDT_InitTypeDef WDT_InitStructure;		        //�ṹ����
    WDT_InitStructure.WDT_EN=DISABLE;             //���Ź���ֹ
    WDT_InitStructure.WDT_IDLE=IDLE_Stop;         //���Ź���IDLEģʽλ������ 
    WDT_InitStructure.WDT_CLOCK=WDT_CLOCK_256T;    //���Ź�������Ԥ��Ƶֵ 64T--2��  128T--4�룬256T--8��
    
    Wdt_Inilize(&WDT_InitStructure);	
		Wdt_EnOrNo(1);  //�������Ź�
// WDT_Flag=0;
}



