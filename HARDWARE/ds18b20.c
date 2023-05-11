#include "ds18b20.h" 
#include  "config.h"

bit ReadTempFlag;


///******************************************************************************
// * 描  述 : ds18b20初始化		单路
// * 入  参 : 无
// * 返回值 : 初始化成功:0
// *          初始化失败:1
// *****************************************************************************/
//unsigned char Init_Ds18b20(void)
//{
//    unsigned char Status = 0x00;
//    unsigned int CONT_1 = 0;
//    unsigned char Flag_1 = 1;

//    Ds18b20IO_1 = 1;      //DQ复位
//    delayus(260);  //稍做延时
//    Ds18b20IO_1 = 0;      //单片机将DQ拉低
//    delayus(750);  //精确延时 大于 480us 小于960us
//    Ds18b20IO_1 = 1;      //拉高总线
//    while((Ds18b20IO_1 != 0)&&(Flag_1 == 1)) 	//等待ds18b20响应，具有防止超时功能
//    {                                      		//等待约60ms左右
//				uart1_rece_proc();										//处理接收到的串口1的数据
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
//    return Status;       //返回初始化状态
//}

/******************************************************************************
 * 描  述 : ds18b20_8初始化  (8个温度传感器 同时初始化)
 * 入  参 : 无
 * 返回值 : 初始化成功:0
 *          初始化失败:1
 *****************************************************************************/
unsigned char Init_Ds18b20_8(void)
{
    unsigned char Status = 0x00;
    unsigned int CONT_1 = 0;
    unsigned char Flag_1 = 1;

    P1 = 0xFF;      		//DQ复位
    delayus(260);  		//稍做延时
    P1 = 0;      				//单片机将DQ拉低
    delayus(750);  		//精确延时 大于 480us 小于960us
    P1 = 0xFF;      		//拉高总线
    while((Ds18b20IO_1 != 0)&&(Flag_1 == 1)) 	//等待ds18b20响应，具有防止超时功能
    {                                      		//等待约60ms左右
				uart1_rece_proc();										//处理接收到的串口1的数据
       
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
    
    return Status;       //返回初始化状态
}

///******************************************************************************
// * 描  述 : Ds18b20写操作：写入1个字节   		单路
// * 入  参 : 无
// * 返回值 : 无
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
 * 描  述 : Ds18b20写操作：写入1个字节  8个传感器同时写
 * 入  参 : 无
 * 返回值 : 无
 *****************************************************************************/
void Ds18b20Write_8(unsigned char dat)
{
    unsigned int i;
	
EA = 0;               //总中断送亲	
	
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
		
EA = 1;               //总中断打开	
		
}



///******************************************************************************
// * 描  述 : Ds18b20读操作：读出1个字节  		单路
// * 入  参 : 无
// * 返回值 : 读取的1字节数据
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
//        Ds18b20IO_1 = 0;// 给脉冲信号
//        delayus(1);
//        Ds18b20IO_1 = 1;// 给脉冲信号
//        delayus(1);
//        if(Ds18b20IO_1 == 1) Value |= 0x80;
//        delayus(60);
//    } 
//    return Value;
//}


/******************************************************************************
 * 描  述 : Ds18b20读操作：读出1个字节  8个传感器同时读
 * 此程序弃用，连续读取4路为空接时，后续第5个传感器无法读出。
 * 入  参 : 无
 * 返回值 : 读取的1字节数据			
 *****************************************************************************/
//void Ds18b20Read_8(unsigned char *Valueptr)
//{
//    unsigned int i, j;

//    P1 = 0xFF;
//    delayus(10);
//    for(i=0;i<8;i++)
//    {
//      for(j=0; j<8; j++)	Valueptr[j] >>= 1; 
//			P1 = 0;				// 给脉冲信号
//			delayus(1);
//			P1 = 0xFF;		// 给脉冲信号
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
			P1 = 0xF0;							// 给脉冲信号
			delayus(1);
			P1 = 0xFF;							// 给脉冲信号
			delayus(1);
			if(Ds18b20IO_1 == 1) Valueptr[0] |= 0x80;			//先读取前4路
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
			P1 = 0x0F;				// 给脉冲信号
			delayus(1);
			P1 = 0xFF;		// 给脉冲信号
			delayus(1);
//			if(Ds18b20IO_1 == 1) Valueptr[0] |= 0x80;
//			if(Ds18b20IO_2 == 1) Valueptr[1] |= 0x80;
//			if(Ds18b20IO_3 == 1) Valueptr[2] |= 0x80;
//			if(Ds18b20IO_4 == 1) Valueptr[3] |= 0x80;
			if(Ds18b20IO_5 == 1) Valueptr[4] |= 0x80;		//再读取后4路
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
//			P1 = 0x0F;							// 给脉冲信号
//			delayus(1);
//			P1 = 0xFF;							// 给脉冲信号
//			delayus(1);
////			if(Ds18b20IO_1 == 1) Valueptr[0] |= 0x80;			//先读取前4路
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
//			P1 = 0xF0;				// 给脉冲信号
//			delayus(1);
//			P1 = 0xFF;		// 给脉冲信号
//			delayus(1);
//			if(Ds18b20IO_1 == 1) Valueptr[0] |= 0x80;
//			if(Ds18b20IO_2 == 1) Valueptr[1] |= 0x80;
//			if(Ds18b20IO_3 == 1) Valueptr[2] |= 0x80;
//			if(Ds18b20IO_4 == 1) Valueptr[3] |= 0x80;
////			if(Ds18b20IO_5 == 1) Valueptr[4] |= 0x80;		//再读取后4路
////			if(Ds18b20IO_6 == 1) Valueptr[5] |= 0x80;
////			if(Ds18b20IO_7 == 1) Valueptr[6] |= 0x80;
////			if(Ds18b20IO_8 == 1) Valueptr[7] |= 0x80;
//			
//      delayus(60);
//    } 
//}

///******************************************************************************
// * 描  述 : 温度读取函数 带1位小数位   		单路
// * 入  参 : 无
// * 返回值 : 温度值
// *****************************************************************************/
//float floatReadDs18B20(void) 
//{
//		uint8 th;
//		uint8 tl;
//    unsigned char V1,V2;   //定义高低8位 缓冲
//    float fValue;

//		unsigned int CONT_2 = 150;

//    Init_Ds18b20();
//    Ds18b20Write(0xcc);    // 跳过读序号列号的操作
//    Ds18b20Write(0x44);    // 启动温度转换
//	
//		while(CONT_2--)					//150*5ms = 750ms 延时
//		{
//					uart1_rece_proc();			//处理接收到的串口1的数据
//					delay_ms(5);
//		}	
//	    
//    Init_Ds18b20();
//    Ds18b20Write(0xcc);    //跳过读序号列号的操作 
//    Ds18b20Write(0xbe);    //读取温度寄存器等（共可读9个寄存器） 前两个就是温度
//    
//    V1 = Ds18b20Read();    //温度值低位
//    V2 = Ds18b20Read();    //温度值高位

//		tl = V1 & 0x0F;		//取低字节后四位 
//		th = (V2 << 4) + (V1 >> 4);	//取高字节后三位和低字节前四位
//		fValue = th;						//整数部分
//		if (V2 > 0x08)
//		{
//			th = ~th + 1;						//取反加一
//			fValue = -th;						//负数
//		}
//		fValue += tl * 0.0625;		//放大XX倍
//		return  10*fValue;
//	
//}

/******************************************************************************
 * 描  述 : 温度读取函数 带1位小数位
 * 入  参 : 无
 * 返回值 : 无，更改 float fTempM[8]
 *****************************************************************************/
void floatReadDs18B20_8(float *tempptr) 
{
		uint8 th;
		uint8 tl;
    unsigned char V1M[8]=0,V2M[8]=0;   //定义高低8位 缓冲
    float fValue;
		unsigned int CONT_2 = 150;
		uint8 i;

    Init_Ds18b20_8();
    Ds18b20Write_8(0xcc);    // 跳过读序号列号的操作
    Ds18b20Write_8(0x44);    // 启动温度转换
	
		while(CONT_2--)					//150*5ms = 750ms 延时
		{
					uart1_rece_proc();			//处理接收到的串口1的数据
					delay_ms(5);
		}	
	    
    Init_Ds18b20_8();
    Ds18b20Write_8(0xcc);    //跳过读序号列号的操作 
    Ds18b20Write_8(0xbe);    //读取温度寄存器等（共可读9个寄存器） 前两个就是温度
    
    Ds18b20Read_8(V1M);    //温度值低位
    Ds18b20Read_8(V2M);    //温度值高位

		for(i=0; i<8; i++)
		{
			tl = V1M[i] & 0x0F;		//取低字节后四位 
			th = (V2M[i] << 4) + (V1M[i] >> 4);	//取高字节后三位和低字节前四位
			fValue = th;						//整数部分
			if (V2M[i] > 0x08)
			{
				th = ~th + 1;						//取反加一
				fValue = -th;						//负数
			}
			fValue += tl * 0.0625;		//放大XX倍
			
			if((fValue<120)&&(fValue>-50))	*(tempptr++) =  10*fValue;
		}
}


//    V1 = 0x91;    		//温度值低位 +25.06度 测度数据
//    V2 = 0x01;    		//温度值高位
//    V1 = 0x5E;    		//温度值低位 -10.125度
//    V2 = 0xFF;    		//温度值高位

/*********************************END FILE*************************************/