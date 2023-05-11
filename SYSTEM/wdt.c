
#include	"wdt.h"

//========================================================================
//u8	Wdt_Inilize(WDT_InitTypeDef *WDTx)
// 描述: 看门狗初始化程序.
// 参数: WDTx: 结构参数,请参考wdt.h里的定义.
// 返回: 成功返回0, 错误返回2
//========================================================================
u8	Wdt_Inilize(WDT_InitTypeDef *WDTx)
{
   if(IDLE_Count==WDTx->WDT_IDLE)
   {
        WDT_CONTR|=(1<<3);      //IDLE模式计数 
   }
   else if(IDLE_Stop==WDTx->WDT_IDLE)
   {
        WDT_CONTR&=(~(1<<3));   //IDLE模式不计数 
   } 
   else
   {
        return 2;
   }  
   
   if(7>=WDTx->WDT_CLOCK)
   {
        WDT_CONTR&=(~0x07);
        WDT_CONTR|=WDTx->WDT_CLOCK;  //设定看门狗计数器的预分频值  
   }
   else
   {
        return 2;
   }   

   if(ENABLE==WDTx->WDT_EN)
   {
        WDT_CONTR|=(1<<5);      //允许看门狗
   }
   else if(DISABLE==WDTx->WDT_EN)
   {
        WDT_CONTR&=(~(1<<5));   //禁止看门狗
   } 
   else
   {
        return 2;
   }       

   return	0;		//成功
}


//========================================================================
//void	Wdt_EnOrNo(u8 theFlag)
// 描述: 看门狗允许/禁止函数
//形式参数 u8 theFlag 0=禁止  1=允许
//========================================================================
void	Wdt_EnOrNo(u8 theFlag)
{
   if(1==theFlag)
   {
        WDT_CONTR|=(1<<5);      //允许看门狗
   }
   else
   {
        WDT_CONTR&=(~(1<<5));   //禁止看门狗
   } 
}

//========================================================================
//void	Wdt_EnOrNo(u8 theFlag)
// 描述: 看门狗允许/禁止函数
//形式参数 u8 theFlag 0=禁止  1=允许
//========================================================================
void Wdt_Feed(void)
{
    WDT_CONTR|=(1<<4);      //喂狗
}

/**************************************************************************************
 * 描  述 : WDT配置函数
 * 入  参 : 无
 * 返回值 : 无
 **************************************************************************************/
void	WDT_config(void)
{
    WDT_InitTypeDef WDT_InitStructure;		        //结构定义
    WDT_InitStructure.WDT_EN=DISABLE;             //看门狗禁止
    WDT_InitStructure.WDT_IDLE=IDLE_Stop;         //看门狗在IDLE模式位不计数 
    WDT_InitStructure.WDT_CLOCK=WDT_CLOCK_256T;    //看门狗计数器预分频值 64T--2秒  128T--4秒，256T--8秒
    
    Wdt_Inilize(&WDT_InitStructure);	
		Wdt_EnOrNo(1);  //开启看门狗
// WDT_Flag=0;
}



