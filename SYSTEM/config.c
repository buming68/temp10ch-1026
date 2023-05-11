#include "config.h"	

extern void Wdt_Feed(void);
/*****************************************************************
功能描述：延时函数
入口参数：uint16 x ，该值为1时，延时1ms
返回值：无
*****************************************************************/
void delay_ms(uint16 x) 
{  
	uint16 j,i;   
	for(j=0;j<x;j++)   
	{    
		for(i=0;i<1100;i++);   
	}  
}


/**************************************
功能描述：延时函数
入口参数：uint x ，该值为1时，延时1us
返回值：无
***************************************/
void delayus(unsigned char n)                  
{
    while (n--)                        //DJNZ  4
    {
        _nop_();                       //NOP  1+1=12
        _nop_();   
        _nop_();                       //NOP  1+1=12
        _nop_();   
        _nop_();                       //NOP  1+1=12
        _nop_();   			
    }
}

/**********************************************
功能描述：IO口初始化，检测批示灯和传感器的IO状态
入口参数：无
返回值：无
***********************************************/

void IO_init(void)
{
	uint8 i;
	
	/***************************************************************************
  注意: STC15W4K32S4系列的芯片,上电后所有与PWM相关的IO口均为
        高阻态,需将这些口设置为准双向口或强推挽模式方可正常使用
  相关IO: P0.6/P0.7/P1.6/P1.7/P2.1/P2.2
          P2.3/P2.7/P3.7/P4.2/P4.4/P4.5
 **************************************************************************/
	P0M1 = 0;	P0M0 = 0;	//设置P0.0~P0.7为准双向口
	P1M1 = 0;	P1M0 = 0;	//设置P1.0~P1.7为准双向口
	P2M1 = 0;	P2M0 = 0;	//设置P2.0~P2.7为准双向口 
	P3M1 = 0;	P3M0 = 0;	//设置P3.0~P3.7为准双向口
	P4M1 = 0;	P4M0 = 0;	//设置P4.0~P4.7为准双向口
	P5M1 = 0;	P5M0 = 0;	//设置P5.0~P5.7为准双向口	
		
	i = 2;
	while(i--)     //程序开始执行，红灯会闪烁2次，一旦CPU重启，都会执行该操作，自检
	{
		 LED_R = 0 ;     //熄灭蓝色LED
		 delay_ms(200);
		 LED_R = 1;     //点亮蓝色LED
		 delay_ms(200);      
	}
		i = 2;	
		while(i--)     //程序开始执行，绿灯会闪烁2次，一旦CPU重启，都会执行该操作，自检
	{
		 LED_G = 0 ;     //熄灭蓝色LED
		 delay_ms(200);
		 LED_G = 1;     //点亮蓝色LED
		 delay_ms(200);      
	}		
		i =4;
	while(i--)     //蓝灯会闪烁4次，P1引脚交替高低电平（测试），一旦CPU重启，都会执行该操作，自检
	{
		Wdt_Feed();     				//喂狗9秒之内需要喂狗，防止软件下载硬件自动看门狗重启

		P0 = 0xFF;							// 给脉冲信号
		P1 = 0xFF;							// 给脉冲信号
		P4 = 0xFF;							// 给脉冲信号		
		LED_B = 0 ;     				//熄灭蓝色LED
		
		delay_ms(1000);
		P0 = 0x00;							// 给脉冲信号
		P1 = 0x00;							// 给脉冲信号
		P4 = 0x00;							// 给脉冲信号 		
		LED_B = 1;     					//点亮蓝色LED
		delay_ms(1000);      
		P0 = 0xFF;							// 给脉冲信号
		P1 = 0xFF;							// 给脉冲信号
		P4 = 0xFF;							// 给脉冲信号	
	}	

}	



/*********************************END FILE********************************************/	

