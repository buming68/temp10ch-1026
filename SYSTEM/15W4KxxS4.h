#ifndef __15W4KxxS4_H_
#define __15W4KxxS4_H_

#include "intrins.h"

/////////////////////////////////////////////////
//注意: STC15W4K32S4系列的芯片,上电后所有与PWM相关的IO口均为
//      高阻态,需将这些口设置为准双向口或强推挽模式方可正常使用
//相关IO: P0.6/P0.7/P1.6/P1.7/P2.1/P2.2
//        P2.3/P2.7/P3.7/P4.2/P4.4/P4.5
/////////////////////////////////////////////////

/////////////////////////////////////////////////

//包含本头文件后,不用另外再包含"REG51.H"

//内核特殊功能寄存器        // 复位值   描述
sfr ACC         =   0xE0;   //0000,0000 累加器Accumulator
sbit ACC0 = ACC^0;
sbit ACC1 = ACC^1;
sbit ACC2 = ACC^2;
sbit ACC3 = ACC^3;
sbit ACC4 = ACC^4;
sbit ACC5 = ACC^5;
sbit ACC6 = ACC^6;
sbit ACC7 = ACC^7;

sfr B           =   0xF0;   //0000,0000 B寄存器
sbit B0 = B^0;
sbit B1 = B^1;
sbit B2 = B^2;
sbit B3 = B^3;
sbit B4 = B^4;
sbit B5 = B^5;
sbit B6 = B^6;
sbit B7 = B^7;

sfr PSW         =   0xD0;   //0000,0000 程序状态字
sbit CY   = PSW^7;
sbit AC   = PSW^6;
sbit F0   = PSW^5;
sbit RS1  = PSW^4;
sbit RS0  = PSW^3;
sbit OV   = PSW^2;
sbit F1   = PSW^1;
sbit P    = PSW^0;

sfr SP          =   0x81;   //0000,0111 堆栈指针

sfr DPL         =   0x82;   //0000,0000 数据指针低字节
sfr DPH         =   0x83;   //0000,0000 数据指针高字节

//I/O 口特殊功能寄存器
sfr P0          =   0x80;   //1111,1111 端口0
sbit P00        =   P0^0;
sbit P01        =   P0^1;
sbit P02        =   P0^2;
sbit P03        =   P0^3;
sbit P04        =   P0^4;
sbit P05        =   P0^5;
sbit P06        =   P0^6;
sbit P07        =   P0^7;
sfr P1          =   0x90;   //1111,1111 端口1
sbit P10        =   P1^0;
sbit P11        =   P1^1;
sbit P12        =   P1^2;
sbit P13        =   P1^3;
sbit P14        =   P1^4;
sbit P15        =   P1^5;
sbit P16        =   P1^6;
sbit P17        =   P1^7;
sfr P2          =   0xA0;   //1111,1111 端口2
sbit P20        =   P2^0;
sbit P21        =   P2^1;
sbit P22        =   P2^2;
sbit P23        =   P2^3;
sbit P24        =   P2^4;
sbit P25        =   P2^5;
sbit P26        =   P2^6;
sbit P27        =   P2^7;
sfr P3          =   0xB0;   //1111,1111 端口3
sbit P30        =   P3^0;
sbit P31        =   P3^1;
sbit P32        =   P3^2;
sbit P33        =   P3^3;
sbit P34        =   P3^4;
sbit P35        =   P3^5;
sbit P36        =   P3^6;
sbit P37        =   P3^7;
sfr P4          =   0xC0;   //1111,1111 端口4
sbit P40        =   P4^0;
sbit P41        =   P4^1;
sbit P42        =   P4^2;
sbit P43        =   P4^3;
sbit P44        =   P4^4;
sbit P45        =   P4^5;
sbit P46        =   P4^6;
sbit P47        =   P4^7;
sfr P5          =   0xC8;   //xxxx,1111 端口5
sbit P50        =   P5^0;
sbit P51        =   P5^1;
sbit P52        =   P5^2;
sbit P53        =   P5^3;
sbit P54        =   P5^4;
sbit P55        =   P5^5;
sbit P56        =   P5^6;
sbit P57        =   P5^7;
sfr P6          =   0xE8;   //0000,0000 端口6
sbit P60        =   P6^0;
sbit P61        =   P6^1;
sbit P62        =   P6^2;
sbit P63        =   P6^3;
sbit P64        =   P6^4;
sbit P65        =   P6^5;
sbit P66        =   P6^6;
sbit P67        =   P6^7;
sfr P7          =   0xF8;   //0000,0000 端口7
sbit P70        =   P7^0;
sbit P71        =   P7^1;
sbit P72        =   P7^2;
sbit P73        =   P7^3;
sbit P74        =   P7^4;
sbit P75        =   P7^5;
sbit P76        =   P7^6;
sbit P77        =   P7^7;

//////////////////////////////////////////////////////////////
//=00--->Standard,	    01--->push-pull
//=10--->pure input,	11--->open drain
sfr P0M0        =   0x94;   //0000,0000 端口0模式寄存器0
sfr P0M1        =   0x93;   //0000,0000 端口0模式寄存器1
sfr P1M0        =   0x92;   //0000,0000 端口1模式寄存器0
sfr P1M1        =   0x91;   //0000,0000 端口1模式寄存器1
sfr P2M0        =   0x96;   //0000,0000 端口2模式寄存器0
sfr P2M1        =   0x95;   //0000,0000 端口2模式寄存器1
sfr P3M0        =   0xB2;   //0000,0000 端口3模式寄存器0
sfr P3M1        =   0xB1;   //0000,0000 端口3模式寄存器1
sfr P4M0        =   0xB4;   //0000,0000 端口4模式寄存器0
sfr P4M1        =   0xB3;   //0000,0000 端口4模式寄存器1
sfr P5M0        =   0xCA;   //0000,0000 端口5模式寄存器0
sfr P5M1        =   0xC9;   //0000,0000 端口5模式寄存器1
sfr P6M0        =   0xCC;   //0000,0000 端口6模式寄存器0
sfr P6M1        =   0xCB;   //0000,0000 端口6模式寄存器1
sfr P7M0        =   0xE2;   //0000,0000 端口7模式寄存器0
sfr P7M1        =   0xE1;   //0000,0000 端口7模式寄存器1

//系统管理特殊功能寄存器
sfr PCON        =   0x87;   //0001,0000 电源控制寄存器
sfr AUXR        =   0x8E;   //0000,0000 辅助寄存器
sfr AUXR1       =   0xA2;   //0000,0000 辅助寄存器1
sfr P_SW1       =   0xA2;   //0000,0000 外设端口切换寄存器1
sfr CLK_DIV     =   0x97;   //0000,0000 时钟分频控制寄存器
sfr PCON2       =   0x97;
sfr BUS_SPEED   =   0xA1;   //xx10,x011 总线速度控制寄存器
sfr P1ASF       =   0x9D;   //0000,0000 端口1模拟功能配置寄存器
sfr P_SW2       =   0xBA;   //0xxx,x000 外设端口切换寄存器

//中断特殊功能寄存器
sfr IE          =   0xA8;   //0000,0000 中断控制寄存器
sbit EA   = IE^7;	//中断允许总控制位
sbit ELVD = IE^6;	//低压监测中断允许位
sbit EADC = IE^5;	//ADC 中断 允许位
sbit ES   = IE^4;	//串行中断 允许控制位
sbit ET1  = IE^3;	//定时中断1允许控制位
sbit EX1  = IE^2;	//外部中断1允许控制位
sbit ET0  = IE^1;	//定时中断0允许控制位
sbit EX0  = IE^0;	//外部中断0允许控制位

//   7     6     5    4    3    2    1    0    Reset Value
//  PPCA  PLVD  PADC  PS   PT1  PX1  PT0  PX0   0000,0000
sfr IP          =   0xB8;   //0000,0000 中断优先级寄存器
sbit PPCA = IP^7;	//PCA 中断 优先级设定位
sbit PLVD = IP^6; 	//低压中断 优先级设定位
sbit PADC = IP^5; 	//ADC 中断 优先级设定位
sbit PS   = IP^4;	//串行中断0优先级设定位
sbit PT1  = IP^3;	//定时中断1优先级设定位
sbit PX1  = IP^2;	//外部中断1优先级设定位
sbit PT0  = IP^1;	//定时中断0优先级设定位
sbit PX0  = IP^0;	//外部中断0优先级设定位

sfr IE2         =   0xAF;   //0000,0000 中断控制寄存器2
sfr IP2         =   0xB5;   //xxxx,xx00 中断优先级寄存器2
sfr INT_CLKO    =   0x8F;   //0000,0000 外部中断与时钟输出控制寄存器
sfr WAKE_CLKO   = 0x8F;
sfr	AUXR2       = 0x8F;

//定时器特殊功能寄存器
sfr TCON        =   0x88;   //0000,0000 T0/T1控制寄存器
sbit TF1        =   TCON^7;
sbit TR1        =   TCON^6;
sbit TF0        =   TCON^5;
sbit TR0        =   TCON^4;
sbit IE1        =   TCON^3;
sbit IT1        =   TCON^2;
sbit IE0        =   TCON^1;
sbit IT0        =   TCON^0;
sfr TMOD        =   0x89;   //0000,0000 T0/T1模式寄存器
sfr TL0         =   0x8A;   //0000,0000 T0低字节
sfr TL1         =   0x8B;   //0000,0000 T1低字节
sfr TH0         =   0x8C;   //0000,0000 T0高字节
sfr TH1         =   0x8D;   //0000,0000 T1高字节
sfr T4T3M       =   0xD1;   //0000,0000 T3/T4模式寄存器
sfr T3T4M       =   0xD1;   //0000,0000 T3/T4模式寄存器
sfr T4H         =   0xD2;   //0000,0000 T4高字节
sfr T4L         =   0xD3;   //0000,0000 T4低字节
sfr T3H         =   0xD4;   //0000,0000 T3高字节
sfr T3L         =   0xD5;   //0000,0000 T3低字节
sfr T2H         =   0xD6;   //0000,0000 T2高字节
sfr T2L         =   0xD7;   //0000,0000 T2低字节
sfr WKTCL       =   0xAA;   //0000,0000 掉电唤醒定时器低字节
sfr WKTCH       =   0xAB;   //0000,0000 掉电唤醒定时器高字节
sfr WDT_CONTR   =   0xC1;   //0000,0000 看门狗控制寄存器

//串行口特殊功能寄存器
sfr SCON        =   0x98;   //0000,0000 串口1控制寄存器
sbit SM0        =   SCON^7;
sbit SM1        =   SCON^6;
sbit SM2        =   SCON^5;
sbit REN        =   SCON^4;
sbit TB8        =   SCON^3;
sbit RB8        =   SCON^2;
sbit TI         =   SCON^1;
sbit RI         =   SCON^0;
sfr SBUF        =   0x99;   //xxxx,xxxx 串口1数据寄存器
sfr S2CON       =   0x9A;   //0000,0000 串口2控制寄存器
sfr S2BUF       =   0x9B;   //xxxx,xxxx 串口2数据寄存器
sfr S3CON       =   0xAC;   //0000,0000 串口3控制寄存器
sfr S3BUF       =   0xAD;   //xxxx,xxxx 串口3数据寄存器
sfr S4CON       =   0x84;   //0000,0000 串口4控制寄存器
sfr S4BUF       =   0x85;   //xxxx,xxxx 串口4数据寄存器
sfr SADDR       =   0xA9;   //0000,0000 从机地址寄存器
sfr SADEN       =   0xB9;   //0000,0000 从机地址屏蔽寄存器

//ADC 特殊功能寄存器
sfr ADC_CONTR   =   0xBC;   //0000,0000 A/D转换控制寄存器
sfr ADC_RES     =   0xBD;   //0000,0000 A/D转换结果高8位
sfr ADC_RESL    =   0xBE;   //0000,0000 A/D转换结果低2位

//SPI 特殊功能寄存器
sfr SPSTAT      =   0xCD;   //00xx,xxxx SPI状态寄存器
sfr SPCTL       =   0xCE;   //0000,0100 SPI控制寄存器
sfr SPDAT       =   0xCF;   //0000,0000 SPI数据寄存器

//IAP/ISP 特殊功能寄存器
sfr IAP_DATA    =   0xC2;   //0000,0000 EEPROM数据寄存器
sfr IAP_ADDRH   =   0xC3;   //0000,0000 EEPROM地址高字节
sfr IAP_ADDRL   =   0xC4;   //0000,0000 EEPROM地址第字节
sfr IAP_CMD     =   0xC5;   //xxxx,xx00 EEPROM命令寄存器
sfr IAP_TRIG    =   0xC6;   //0000,0000 EEPRPM命令触发寄存器
sfr IAP_CONTR   =   0xC7;   //0000,x000 EEPROM控制寄存器

//PCA/PWM 特殊功能寄存器
//7     6     5     4     3     2     1     0     Reset Value
//CF    CR    -     -     -    CCF2  CCF1  CCF0   00xx,xx00	//PCA 控制寄存器。
sfr CCON        =   0xD8;   //00xx,xx00 PCA控制寄存器
sbit CCF0  = CCON^0;	//PCA 模块0中断标志，由硬件置位，必须由软件清0。
sbit CCF1  = CCON^1;	//PCA 模块1中断标志，由硬件置位，必须由软件清0。
sbit CCF2  = CCON^2;	//PCA 模块2中断标志，由硬件置位，必须由软件清0。
sbit CR    = CCON^6;	//1: 允许PCA计数器计数，必须由软件清0。
sbit CF    = CCON^7;	//PCA计数器溢出（CH，CL由FFFFH变为0000H）标志。PCA计数器溢出后由硬件置位，必须由软件清0

sfr CMOD        =   0xD9;   //0xxx,x000 PCA 工作模式寄存器
sfr CL          =   0xE9;   //0000,0000 PCA计数器低字节
sfr CH          =   0xF9;   //0000,0000 PCA计数器高字节
sfr CCAPM0      =   0xDA;   //0000,0000 PCA模块0的PWM寄存器
sfr CCAPM1      =   0xDB;   //0000,0000 PCA模块1的PWM寄存器
sfr CCAPM2      =   0xDC;   //0000,0000 PCA模块2的PWM 寄存器
sfr CCAP0L      =   0xEA;   //0000,0000 PCA模块0的捕捉/比较寄存器低字节
sfr CCAP1L      =   0xEB;   //0000,0000 PCA模块1的捕捉/比较寄存器低字节
sfr CCAP2L      =   0xEC;   //0000,0000 PCA模块2的捕捉/比较寄存器低字节
sfr PCA_PWM0    =   0xF2;   //xxxx,xx00 PCA模块0的PWM寄存器
sfr PCA_PWM1    =   0xF3;   //xxxx,xx00 PCA模块1的PWM寄存器
sfr PCA_PWM2    =   0xF4;   //xxxx,xx00 PCA模块1的PWM寄存器
sfr CCAP0H      =   0xFA;   //0000,0000 PCA模块0的捕捉/比较寄存器高字节
sfr CCAP1H      =   0xFB;   //0000,0000 PCA模块1的捕捉/比较寄存器高字节
sfr CCAP2H      =   0xFC;   //0000,0000 PCA模块2的捕捉/比较寄存器高字节

//比较器特殊功能寄存器
sfr CMPCR1      =   0xE6;   //0000,0000 比较器控制寄存器1
sfr CMPCR2      =   0xE7;   //0000,0000 比较器控制寄存器2

//增强型PWM波形发生器特殊功能寄存器
sfr PWMCFG      =   0xf1;   //x000,0000 PWM配置寄存器
sfr PWMCR       =   0xf5;   //0000,0000 PWM控制寄存器
sfr PWMIF       =   0xf6;   //x000,0000 PWM中断标志寄存器
sfr PWMFDCR     =   0xf7;   //xx00,0000 PWM外部异常检测控制寄存器

//如下特殊功能寄存器位于扩展RAM区域
//访问这些寄存器,需先将P_SW2的BIT7设置为1,才可正常读写
#define PWMC        0xFFF0   
#define PWMCH       0xFFF0   /* PWM计数器高字节  */
#define PWMCL       0xFFF1   /* PWM计数器低字节  */
#define PWMCKS      0xFFF2   /* PWM时钟选择      */

#define PWM2T1      0xFF00
#define PWM2T1H     0xFF00   /* PWM2T1计数高字节 */
#define PWM2T1L     0xFF01   /* PWM2T1计数低字节 */
#define PWM2T2      0xFF02   
#define PWM2T2H     0xFF02   /* PWM2T2计数高字节 */
#define PWM2T2L     0xFF03   /* PWM2T2计数低字节 */
#define PWM2CR      0xFF04   /* PWM2控制         */

#define PWM3T1      0xFF10   
#define PWM3T1H     0xFF10   /* PWM3T1计数高字节 */
#define PWM3T1L     0xFF11   /* PWM3T1计数低字节 */
#define PWM3T2      0xFF12
#define PWM3T2H     0xFF12   /* PWM3T2计数高字节 */
#define PWM3T2L     0xFF13   /* PWM3T2计数低字节 */
#define PWM3CR      0xFF14   /* PWM3控制         */

#define PWM4T1      0xFF20
#define PWM4T1H     0xFF20   /* PWM4T1计数高字节 */
#define PWM4T1L     0xFF21   /* PWM4T1计数低字节 */
#define PWM4T2      0xFF22
#define PWM4T2H     0xFF22   /* PWM4T2计数高字节 */
#define PWM4T2L     0xFF23   /* PWM4T2计数低字节 */
#define PWM4CR      0xFF24   /* PWM4控制         */

#define PWM5T1      0xFF30
#define PWM5T1H     0xFF30   /* PWM5T1计数高字节 */
#define PWM5T1L     0xFF31   /* PWM5T1计数低字节 */
#define PWM5T2      0xFF32
#define PWM5T2H     0xFF32   /* PWM5T2计数高字节 */
#define PWM5T2L     0xFF33   /* PWM5T2计数低字节 */
#define PWM5CR      0xFF34   /* PWM5控制         */

#define PWM6T1      0xFF40
#define PWM6T1H     0xFF40   /* PWM6T1计数高字节 */
#define PWM6T1L     0xFF41   /* PWM6T1计数低字节 */
#define PWM6T2      0xFF42
#define PWM6T2H     0xFF42   /* PWM6T2计数高字节 */
#define PWM6T2L     0xFF43   /* PWM6T2计数低字节 */
#define PWM6CR      0xFF44   /* PWM6控制         */

#define PWM7T1      0xFF50        
#define PWM7T1H     0xFF50   /* PWM7T1计数高字节 */    
#define PWM7T1L     0xFF51   /* PWM7T1计数低字节 */
#define PWM7T2      0xFF52
#define PWM7T2H     0xFF52   /* PWM7T2计数高字节 */
#define PWM7T2L     0xFF53   /* PWM7T2计数低字节 */
#define PWM7CR      0xFF54   /* PWM7控制         */

#define	PWM2_ID		0
#define	PWM3_ID		1
#define	PWM4_ID		2
#define	PWM5_ID		3
#define	PWM6_ID		4
#define	PWM7_ID		5

#define	PwmClk_1T	0
#define	PwmClk_2T	1
#define	PwmClk_3T	2
#define	PwmClk_4T	3
#define	PwmClk_5T	4
#define	PwmClk_6T	5
#define	PwmClk_7T	6
#define	PwmClk_8T	7
#define	PwmClk_9T	8
#define	PwmClk_10T	9
#define	PwmClk_11T	10
#define	PwmClk_12T	11
#define	PwmClk_13T	12
#define	PwmClk_14T	13
#define	PwmClk_15T	14
#define	PwmClk_16T	15
#define	PwmClk_T2	16


//                    7   6   5   4     3        2       1        0      Reset Value
//PWMnCR:  PWMn控制   -   -   -   -   PWMn_PS  EPWMnI  ECnT2SI  ECnT1SI   0000,0000
#define	PWMn_PS_1		0x00	/* PWM管脚选择位 */
#define	PWMn_PS_2		0x08	/* PWM管脚选择位 */
#define	EPWMnI_Enable	0x04	/* 允许PWM中断   */
#define	ECnT2SI_Enable	0x02	/* 允许T2翻转时中断 */
#define	ECnT1SI_Enable	0x01	/* 允许T1翻转时中断 */

#define	PWM2_P37	0x00
#define	PWM2_P27	0x08
#define	PWM3_P21	0x00
#define	PWM3_P45	0x08
#define	PWM4_P22	0x00
#define	PWM4_P44	0x08
#define	PWM5_P23	0x00
#define	PWM5_P42	0x08
#define	PWM6_P16	0x00
#define	PWM6_P07	0x08
#define	PWM7_P17	0x00
#define	PWM7_P06	0x08

#define	EAXSFR()		P_SW2 |=  0x80	/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展SFR(XSFR) */
#define	EAXRAM()		P_SW2 &= ~0x80	/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展RAM(XRAM) */
#define	C2INI	0x01	/* PWM输出端口的初始电平为高电平 */
#define	C3INI	0x02
#define	C4INI	0x04
#define	C5INI	0x08
#define	C6INI	0x10
#define	C7INI	0x20
#define	CBTADC	0x40	/* PWM计数器归零时自动触发ADC转换。（注：前提条件是PWM和ADC必须被使能，即ENPWM==1，且ADCON==1） */

#define	ENPWM	0x80	/* 使能PWM波形发生器，PWM计数器开始计数 */
#define	ECBI	0x40	/* 使能PWM计数器归零中断 */
#define	ENC7O	0x20	/* 相应PWM通道的端口设置为PWM输出口，受PWM波形发生器控制 */
#define	ENC6O	0x10
#define	ENC5O	0x08
#define	ENC4O	0x04
#define	ENC3O	0x02
#define	ENC2O	0x01
#define	PWM_Enable()	PWMCR |=  0x80	/* 使能PWM波形发生器，PWM计数器开始计数 */
#define	PWM_Disable()	PWMCR &= ~0x80	/* 关闭PWM波形发生器 */

#define	CBIF	0x40	/* PWM计数器归零中断标志位 */
#define	C7IF	0x20
#define	C6IF	0x10	/* 第n通道的PWM中断标志位 */
#define	C5IF	0x08
#define	C4IF	0x04
#define	C3IF	0x02
#define	C2IF	0x01

#define	ENFD		0x20	/* 使能PWM的外部异常检测功 */
#define	FLTFLIO		0x10	/* 发生WM外部异常时，PWM的输出口立即被设置为高阻输入模式。（注：只有ENCnO==1所对应的端口才会被强制悬空） */
#define	EFDI		0x08	/* 使能PWM异常检测中断 */
#define	FDCMP		0x04	/* 当比较器的输出由低变高时，触发PWM异常 */
#define	FDIO		0x02	/* 当P2.4的电平由低变高时，触发PWM异常 */
#define	FDIF		0x01	/* 当发生PWM异常（比较器的输出由低变高或者P2.4的电平由低变高）时，硬件自动将此位置1, 并置位中断标志.需要软件清零 */
#define	PWM_FaultDetect_Enable()	PWMFDCR |=  0x20		/* 使能PWM的外部异常检测功能 */
#define	PWM_FaultDetect_Disable()	PWMFDCR &= ~0x20		/* 禁止PWM的外部异常检测功能 */

/////////////////////////////////////////////////

sfr RL_TL0  = 0x8A;
sfr RL_TL1  = 0x8B;
sfr RL_TH0  = 0x8C;
sfr RL_TH1  = 0x8D;


sfr IPH2  = 0xB6;	//STC12C5A60S2系列
sfr IPH   = 0xB7;


sfr ISP_DATA  = 0xC2;
sfr ISP_ADDRH = 0xC3;
sfr ISP_ADDRL = 0xC4;
sfr ISP_CMD   = 0xC5;
sfr ISP_TRIG  = 0xC6;
sfr ISP_CONTR = 0xC7;

sfr	TH4  = 0xD2;
sfr	TL4  = 0xD3;
sfr	TH3  = 0xD4;
sfr	TL3  = 0xD5;
sfr	TH2  = 0xD6;
sfr	TL2  = 0xD7;

sfr	RL_T4H  = 0xD2;
sfr	RL_T4L  = 0xD3;
sfr	RL_T3H  = 0xD4;
sfr	RL_T3L  = 0xD5;
sfr	RL_T2H  = 0xD6;
sfr	RL_T2L  = 0xD7;


sbit  RXD2      = P1^0;
sbit  TXD2      = P1^1;
sbit  CCP1      = P1^0;
sbit  CCP0      = P1^1;
sbit  SPI_SS    = P1^2;
sbit  SPI_MOSI  = P1^3;
sbit  SPI_MISO  = P1^4;
sbit  SPI_SCLK  = P1^5;

sbit  SPI_SS_2    = P2^4;
sbit  SPI_MOSI_2  = P2^3;
sbit  SPI_MISO_2  = P2^2;
sbit  SPI_SCLK_2  = P2^1;

sbit  SPI_SS_3    = P5^4;
sbit  SPI_MOSI_3  = P4^0;
sbit  SPI_MISO_3  = P4^1;
sbit  SPI_SCLK_3  = P4^3;


sbit RXD  = P3^0;
sbit TXD  = P3^1;
sbit INT0 = P3^2;
sbit INT1 = P3^3;
sbit T0   = P3^4;
sbit T1   = P3^5;
sbit WR   = P3^6;
sbit RD   = P3^7;
sbit CCP2  = P3^7;

sbit CLKOUT0   = P3^5;
sbit CLKOUT1   = P3^4;

//							7     6     5    4    3    2    1     0    Reset Value
//sfr IE2       = 0xAF;		-     -     -    -    -    -   ESPI  ES2   0000,0000B	//Auxiliary Interrupt   
#define		SPI_INT_ENABLE()		IE2 |=  2	//允许SPI中断
#define		SPI_INT_DISABLE()		IE2 &= ~2	//允许SPI中断
#define		UART2_INT_ENABLE()		IE2 |=  1	//允许串口2中断
#define		UART2_INT_DISABLE()		IE2 &= ~1	//允许串口2中断




//                                           7      6      5     4     3     2    1     0        Reset Value
//sfr IPH   = 0xB7; //中断优先级高位       PPCAH  PLVDH  PADCH  PSH  PT1H  PX1H  PT0H  PX0H   0000,0000
//sfr IP2   = 0xB5; //                       -      -      -     -     -     -   PSPI   PS2   xxxx,xx00
//sfr IPH2  = 0xB6; //                       -      -      -     -     -     -   PSPIH  PS2H  xxxx,xx00
#define		PPCAH	0x80
#define		PLVDH	0x40
#define		PADCH	0x20
#define		PSH		0x10
#define		PT1H	0x08
#define		PX1H	0x04
#define		PT0H	0x02
#define		PX0H	0x01

#define		PCA_InterruptFirst()	PPCA = 1
#define		LVD_InterruptFirst()	PLVD = 1
#define		ADC_InterruptFirst()	PADC = 1
#define		UART1_InterruptFirst()	PS   = 1
#define		Timer1_InterruptFirst()	PT1  = 1
#define		INT1_InterruptFirst()	PX1  = 1
#define		Timer0_InterruptFirst()	PT0  = 1
#define		INT0_InterruptFirst()	PX0  = 1

/*************************************************************************************************/


//                       7      6     5    4    3    2     1      0        Reset Value
//sfr CMPCR1 = 0xE6;   CMPEN  CMPIF  PIE  NIE  PIS  NIS  CMPOE  CMPRES      00000000B
#define	CMPEN	0x80	//1: 允许比较器, 0: 禁止,关闭比较器电源
#define	CMPIF	0x40	//比较器中断标志, 包括上升沿或下降沿中断, 软件清0
#define	PIE		0x20	//1: 比较结果由0变1, 产生上升沿中断
#define	NIE		0x10	//1: 比较结果由1变0, 产生下降沿中断
#define	PIS		0x08	//输入正极性选择, 0: 选择内部P5.5做正输入,           1: 由ADCIS[2:0]所选择的ADC输入端做正输入.
#define	NIS		0x04	//输入负极性选择, 0: 选择内部BandGap电压BGv做负输入, 1: 选择外部P5.4做输入.
#define	CMPOE	0x02	//1: 允许比较结果输出到P1.2, 0: 禁止.
#define	CMPRES	0x01	//比较结果, 1: CMP+电平高于CMP-,  0: CMP+电平低于CMP-,  只读

//                       7        6       5  4  3  2  1  0    Reset Value
//sfr CMPCR2 = 0xE7;   INVCMPO  DISFLT       LCDTY[5:0]       00001001B
#define	INVCMPO	0x80	//1: 比较器输出取反,  0: 不取反
#define	DISFLT	0x40	//1: 关闭0.1uF滤波,   0: 允许
#define	LCDTY	0x00	//0~63, 比较结果变化延时周期数

/*************************************************************************************************/
#define		S1_DoubleRate()		PCON |= 0x80
#define		S1_SHIFT()			SCON &= 0x3f
#define		S1_8bit()			SCON |= 0x40
#define		S1_9bit()			SCON |= 0xc0
#define		S1_RX_Enable()		SCON |= 0x10
#define		S1_USE_P30P31()		P_SW1 &=  ~0xc0					//UART1 使用P30 P31口	默认
#define		S1_USE_P36P37()		P_SW1 = (P_SW1 & ~0xc0) | 0x40	//UART1 使用P36 P37口
#define		S1_USE_P16P17()		P_SW1 = (P_SW1 & ~0xc0) | 0x80	//UART1 使用P16 P17口
#define		S1_TXD_RXD_SHORT()	PCON2 |= (1<<4)	//将TXD与RXD连接中继输出
#define		S1_TXD_RXD_OPEN()	PCON2 |= (1<<4)	//将TXD与RXD连接中继断开	默认
#define 	S1_BRT_UseTimer2()	AUXR |=  1;
#define 	S1_BRT_UseTimer1()	AUXR &= ~1;

//						  7      6      5      4      3      2     1     0        Reset Value
//sfr S2CON = 0x9A;		S2SM0    -    S2SM2  S2REN  S2TB8  S2RB8  S2TI  S2RI      00000000B		 //S2 Control

#define		S2_8bit()			S2CON &= ~(1<<7)		//串口2模式0，8位UART，波特率 = 定时器2的溢出率 / 4
#define		S2_9bit()			S2CON |=  (1<<7)		//串口2模式1，9位UART，波特率 = 定时器2的溢出率 / 4
#define		S2_RX_Enable()		S2CON |=  (1<<4)		//允许串2接收

#define		S2_MODE0()			S2CON &= ~(1<<7)		//串口2模式0，8位UART，波特率 = 定时器2的溢出率 / 4
#define		S2_MODE1()			S2CON |=  (1<<7)		//串口2模式1，9位UART，波特率 = 定时器2的溢出率 / 4
#define		S2_RX_EN()			S2CON |=  (1<<4)							//允许串2接收
#define		S2_RX_Disable()		S2CON &= ~(1<<4)							//禁止串2接收
#define		TI2					(S2CON & 2) != 0
#define		RI2					(S2CON & 1) != 0
#define		SET_TI2()			S2CON |=  2
#define		CLR_TI2()			S2CON &= ~2
#define		CLR_RI2()			S2CON &= ~1
#define		S2TB8_SET()			S2CON |=  8
#define		S2TB8_CLR()			S2CON &= ~8
#define		S2_Int_en()			IE2   |=  1		//串口2允许中断
#define		S2_USE_P10P11()		P_SW2 &= ~1		//UART2 使用P1口	默认
#define		S2_USE_P46P47()		P_SW2 |=  1		//UART2 使用P4口


//						  7      6      5      4      3      2     1     0        Reset Value
//sfr S3CON = 0xAC;		S3SM0  S3ST3  S3SM2  S3REN  S3TB8  S3RB8  S3TI  S3RI      00000000B		 //S3 Control

#define		S3_MODE0()			S3CON &= ~(1<<7)	/* 串口3模式0，8位UART，波特率 = 定时器的溢出率 / 4  */
#define		S3_MODE1()			S3CON |=  (1<<7)	/* 串口3模式1，9位UART，波特率 = 定时器的溢出率 / 4  */
#define		S3_8bit()			S3CON &= ~(1<<7)	/* 串口3模式0，8位UART，波特率 = 定时器的溢出率 / 4  */
#define		S3_9bit()			S3CON |=  (1<<7)	/* 串口3模式1，9位UART，波特率 = 定时器的溢出率 / 4  */
#define		S3_RX_Enable()		S3CON |=  (1<<4)	/* 允许串3接收									     */
#define		S3_RX_Disable()		S3CON &= ~(1<<4)	/* 禁止串3接收									     */
#define		TI3					(S3CON & 2) != 0	/* 判断TI3是否发送完成								 */
#define		RI3					(S3CON & 1) != 0	/* 判断RI3是否接收完成								 */
#define		SET_TI3()			S3CON |=  (1<<1)	/* 设置TI3(引起中断)								 */
#define		CLR_TI3()			S3CON &= ~(1<<1)	/* 清除TI3											 */
#define		CLR_RI3()			S3CON &= ~1			/* 清除RI3											 */
#define		S3TB8_SET()			S3CON |=  (1<<3)	/* 设置TB8											 */
#define		S3TB8_CLR()			S3CON &= ~(1<<3)	/* 清除TB8											 */
#define		S3_Int_Enable()		IE2   |=  (1<<3)	/* 串口3允许中断								     */
#define		S3_Int_Disable()	IE2   &= ~(1<<3)	/* 串口3禁止中断								     */
#define 	S3_BRT_UseTimer3()	S3CON |=  (1<<6)	/* BRT select Timer3								 */
#define 	S3_BRT_UseTimer2()	S3CON &= ~(1<<6)	/* BRT select Timer2								 */
#define		S3_USE_P00P01()		P_SW2 &= ~2			/* UART3 使用P0口	默认						     */
#define		S3_USE_P50P51()		P_SW2 |=  2			/* UART3 使用P5口								     */

//						  7      6      5      4      3      2     1     0        Reset Value
//sfr S4CON = 0x84;		S4SM0  S4ST4  S4SM2  S4REN  S4TB8  S4RB8  S4TI  S4RI      00000000B		 //S4 Control

#define		S4_MODE0()			S4CON &= ~(1<<7)	/* 串口4模式0，8位UART，波特率 = 定时器的溢出率 / 4  */
#define		S4_MODE1()			S4CON |=  (1<<7)	/* 串口4模式1，9位UART，波特率 = 定时器的溢出率 / 4  */
#define		S4_8bit()			S4CON &= ~(1<<7)	/* 串口4模式0，8位UART，波特率 = 定时器的溢出率 / 4  */
#define		S4_9bit()			S4CON |=  (1<<7)	/* 串口4模式1，9位UART，波特率 = 定时器的溢出率 / 4  */
#define		S4_RX_Enable()		S4CON |=  (1<<4)	/* 允许串4接收									     */
#define		S4_RX_Disable()		S4CON &= ~(1<<4)	/* 禁止串4接收									     */
#define		TI4					(S4CON & 2) != 0	/* 判断TI3是否发送完成							     */
#define		RI4					(S4CON & 1) != 0	/* 判断RI3是否接收完成							     */
#define		SET_TI4()			S4CON |=  2			/* 设置TI3(引起中断)							     */
#define		CLR_TI4()			S4CON &= ~2			/* 清除TI3										     */
#define		CLR_RI4()			S4CON &= ~1			/* 清除RI3										     */
#define		S4TB8_SET()			S4CON |=  8			/* 设置TB8										     */
#define		S4TB8_CLR()			S4CON &= ~8			/* 清除TB8										     */
#define		S4_Int_Enable()		IE2   |=  (1<<4)	/* 串口4允许中断								     */
#define		S4_Int_Disable()	IE2   &= ~(1<<4)	/* 串口4禁止中断								     */
#define 	S4_BRT_UseTimer4()	S4CON |=  (1<<6)	/* BRT select Timer4								 */
#define 	S4_BRT_UseTimer2()	S4CON &= ~(1<<6)	/* BRT select Timer2								 */
#define		S4_USE_P02P03()		P_SW2 &= ~4			/* UART4 使用P0口	默认						     */
#define		S4_USE_P52P53()		P_SW2 |=  4			/* UART4 使用P5口								     */

/**********************************************************/
//						   7     6       5      4     3      2      1      0    Reset Value
//sfr AUXR  = 0x8E;		T0x12 T1x12 UART_M0x6  T2R  T2_C/T T2x12 EXTRAM  S1ST2  0000,0000	//Auxiliary Register 

#define 	ExternalRAM_enable()		AUXR |=  2		/* 允许外部XRAM，禁止使用内部1024RAM     */
#define 	InternalRAM_enable()		AUXR &= ~2		/* 禁止外部XRAM，允许使用内部1024RAM     */
#define		S1_M0x6()					AUXR |=  (1<<5)	/* UART Mode0 Speed is 6x Standard       */
#define		S1_M0x1()					AUXR &= ~(1<<5)	/* default,	UART Mode0 Speed is Standard */

//====================================
#define		Timer0_16bitAutoReload()	TMOD &= ~0x03					/* 16位自动重装	*/
#define		Timer0_16bit()				TMOD  = (TMOD & ~0x03) | 0x01	/* 16位         */
#define		Timer0_8bitAutoReload()		TMOD  = (TMOD & ~0x03) | 0x02	/* 8位自动重装	*/
#define		Timer0_16bitAutoRL_NoMask()	TMOD |=  0x03		/* 16位自动重装不可屏蔽中断	*/
#define 	Timer0_Run()	 			TR0 = 1				/* 允许定时器0计数			*/
#define 	Timer0_Stop()	 			TR0 = 0				/* 禁止定时器0计数			*/
#define		Timer0_Gate_INT0_P32()		TMOD |=  (1<<3)		/* 时器0由外部INT0高电平允许定时计数 */
#define		Timer0_AsTimer()			TMOD &= ~(1<<2)		/* 时器0用做定时器	*/
#define		Timer0_AsCounter()			TMOD |=  (1<<2)		/* 时器0用做计数器	*/
#define		Timer0_AsCounterP34()		TMOD |=  (1<<2)		/* 时器0用做计数器	*/
#define 	Timer0_1T()					AUXR |=  (1<<7)		/* Timer0 clodk = fo	*/
#define 	Timer0_12T()				AUXR &= ~(1<<7)		/* Timer0 clodk = fo/12	12分频,	default	*/
#define		Timer0_CLKO_Enable()		AUXR2 |=  1			/* 允许 T0 溢出脉冲在T0(P3.5)脚输出，Fck0 = 1/2 T0 溢出率，T0可以1T或12T。	*/
#define		Timer0_CLKO_Disable()		AUXR2 &= ~1
#define		Timer0_CLKO_Enable_P34()	AUXR2 |=  1			/* 允许 T0 溢出脉冲在T0(P3.5)脚输出，Fck0 = 1/2 T0 溢出率，T0可以1T或12T。	*/
#define		Timer0_CLKO_Disable_P34()	AUXR2 &= ~1
#define 	Timer0_InterruptEnable()	ET0 = 1				/* 允许Timer1中断.*/
#define 	Timer0_InterruptDisable()	ET0 = 0				/* 禁止Timer1中断.*/

#define		T0_Load(n)					TH0 = (n) / 256,	TL0 = (n) % 256
#define		T0_Load_us_1T(n)			Timer0_AsTimer(),Timer0_1T(), Timer0_16bitAutoReload(),TH0=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)/256, TL0=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)%256
#define		T0_Load_us_12T(n)			Timer0_AsTimer(),Timer0_12T(),Timer0_16bitAutoReload(),TH0=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)/256,TL0=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)%256
#define		T0_Frequency_1T_P35(n)		ET0=0,Timer0_AsTimer(),Timer0_1T(),Timer0_16bitAutoReload(),TH0=(65536-(n/2+MAIN_Fosc/2)/(n))/256,TL0=(65536-(n/2+MAIN_Fosc/2)/(n))%256,AUXR2 |= bit0,TR0=1		/* fx=fosc/(2*M)/n,  M=1 or M=12 */
#define		T0_Frequency_12T_P35(n)		ET0=0,Timer0_AsTimer(),Timer0_12T(),Timer0_16bitAutoReload(),TH0=(65536-(n/2+MAIN_Fosc/24)/(n))/256,TL0=(65536-(n/2+MAIN_Fosc/24)/(n))%256,AUXR2 |= bit0,TR0=1	/* fx=fosc/(2*M)/n,  M=1 or M=12 */

//====================================
#define		Timer1_16bitAutoReload()	TMOD &= ~0x30					/* 16位自动重装	*/
#define		Timer1_16bit()				TMOD  = (TMOD & ~0x30) | 0x10	/* 16位			*/
#define		Timer1_8bitAutoReload()		TMOD  = (TMOD & ~0x30) | 0x20	/* 8位自动重装	*/
#define 	Timer1_Run()	 			TR1 = 1				/* 允许定时器1计数			*/
#define 	Timer1_Stop()	 			TR1 = 0				/* 禁止定时器1计数			*/
#define		Timer1_Gate_INT1_P33()		TMOD |=  (1<<7)		/* 时器1由外部INT1高电平允许定时计数	*/
#define		Timer1_AsTimer()			TMOD &= ~(1<<6)		/* 时器1用做定时器			*/
#define		Timer1_AsCounter()			TMOD |=  (1<<6)		/* 时器1用做计数器			*/
#define		Timer1_AsCounterP35()		TMOD |=  (1<<6)		/* 时器1用做计数器			*/
#define 	Timer1_1T()					AUXR |=  (1<<6)		/* Timer1 clodk = fo		*/
#define 	Timer1_12T()				AUXR &= ~(1<<6)		/* Timer1 clodk = fo/12	12分频,	default	*/
#define		Timer1_CLKO_Enable()		AUXR2 |=  2			/* 允许 T1 溢出脉冲在T1(P3.4)脚输出，Fck1 = 1/2 T1 溢出率，T1可以1T或12T。	*/
#define		Timer1_CLKO_Disable()		AUXR2 &= ~2
#define		Timer1_CLKO_Enable_P35()	AUXR2 |=  2			/* 允许 T1 溢出脉冲在T1(P3.4)脚输出，Fck1 = 1/2 T1 溢出率，T1可以1T或12T。	*/
#define		Timer1_CLKO_Disable_P35()	AUXR2 &= ~2
#define 	Timer1_InterruptEnable()	ET1 = 1				/* 允许Timer1中断.	*/
#define 	Timer1_InterruptDisable()	ET1 = 0				/* 禁止Timer1中断.	*/

#define		T1_Load(n)					TH1 = (n) / 256,	TL1 = (n) % 256
#define		T1_Load_us_1T(n)			Timer1_AsTimer(),Timer1_1T(), Timer1_16bitAutoReload(),TH1=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)/256, TL1=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)%256
#define		T1_Load_us_12T(n)			Timer1_AsTimer(),Timer1_12T(),Timer1_16bitAutoReload(),TH1=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)/256,TL1=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)%256
#define		T1_Frequency_1T_P34(n)		ET1=0,Timer1_AsTimer(),Timer1_1T(),Timer1_16bitAutoReload(),TH1=(65536-(n/2+MAIN_Fosc/2)/(n))/256,TL1=(65536-(n/2+MAIN_Fosc/2)/(n))%256,AUXR2 |= bit1,TR1=1		/* fx=fosc/(2*M)/n,  M=1 or M=12 */
#define		T1_Frequency_12T_P34(n)		ET1=0,Timer1_AsTimer(),Timer1_12T(),Timer1_16bitAutoReload(),TH1=(65536-(n/2+MAIN_Fosc/24)/(n))/256,TL1=(65536-(n/2+MAIN_Fosc/24)/(n))%256,AUXR2 |= bit1,TR1=1	/* fx=fosc/(2*M)/n,  M=1 or M=12 */

//====================================
#define 	Timer2_Run()	 			AUXR |=  (1<<4)	/* 允许定时器2计数	*/
#define 	Timer2_Stop()	 			AUXR &= ~(1<<4)	/* 禁止定时器2计数	*/
#define		Timer2_AsTimer()			AUXR &= ~(1<<3)	/* 时器2用做定时器	*/
#define		Timer2_AsCounter()			AUXR |=  (1<<3)	/* 时器2用做计数器	*/
#define		Timer2_AsCounterP31()		AUXR |=  (1<<3)	/* 时器2用做计数器	*/
#define 	Timer2_1T()					AUXR |=  (1<<2)	/* Timer0 clock = fo	*/
#define 	Timer2_12T()				AUXR &= ~(1<<2)	/* Timer0 clock = fo/12	12分频,	default	*/
#define		Timer2_CLKO_Enable()		AUXR2 |=  4		/* 允许 T2 溢出脉冲在T1(P3.0)脚输出，Fck2 = 1/2 T2 溢出率，T2可以1T或12T。	*/
#define		Timer2_CLKO_Disable()		AUXR2 &= ~4
#define		Timer2_CLKO_Enable_P30()	AUXR2 |=  4		/* 允许 T2 溢出脉冲在T1(P3.0)脚输出，Fck2 = 1/2 T2 溢出率，T2可以1T或12T。	*/
#define		Timer2_CLKO_Disable_P30()	AUXR2 &= ~4
#define 	Timer2_InterruptEnable()	IE2  |=  (1<<2)	/* 允许Timer2中断.	*/
#define 	Timer2_InterruptDisable()	IE2  &= ~(1<<2)	/* 禁止Timer2中断.	*/

#define		T2_Load(n)					TH2 = (n) / 256,	TL2 = (n) % 256
#define		T2_Load_us_1T(n)			Timer2_AsTimer(),Timer2_1T(), TH2=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)/256, TL2=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)%256
#define		T2_Load_us_12T(n)			Timer2_AsTimer(),Timer2_12T(),TH2=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)/256,TL2=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)%256
#define		T2_Frequency_1T_P30(n)		Timer2_InterruptDisable(),Timer2_AsTimer(),Timer2_1T(), TH2=(65536-(n/2+MAIN_Fosc/2)/(n))/256, TL2=(65536-(n/2+MAIN_Fosc/2)/(n))%256, Timer2_CLKO_Enable_P30(),Timer2_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */
#define		T2_Frequency_12T_P30(n)		Timer2_InterruptDisable(),Timer2_AsTimer(),Timer2_12T(),TH2=(65536-(n/2+MAIN_Fosc/24)/(n))/256,TL2=(65536-(n/2+MAIN_Fosc/24)/(n))%256,Timer2_CLKO_Enable_P30(),Timer2_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */

//====================================
#define 	Timer3_Run()	 			T4T3M |=  (1<<3)	/* 允许定时器3计数	*/
#define 	Timer3_Stop()	 			T4T3M &= ~(1<<3)	/* 禁止定时器3计数	*/
#define		Timer3_AsTimer()			T4T3M &= ~(1<<2)	/* 时器3用做定时器	*/
#define		Timer3_AsCounter()			T4T3M |=  (1<<2)	/* 时器3用做计数器, P0.5为外部脉冲	*/
#define		Timer3_AsCounterP05()		T4T3M |=  (1<<2)	/* 时器3用做计数器, P0.5为外部脉冲	*/
#define 	Timer3_1T()					T4T3M |=  (1<<1)	/* 1T模式	*/
#define 	Timer3_12T()				T4T3M &= ~(1<<1)	/* 12T模式,	default	*/
#define		Timer3_CLKO_Enable()		T4T3M |=  1			/* 允许T3溢出脉冲在T3(P0.4)脚输出，Fck = 1/2 T2 溢出率，T2可以1T或12T。	*/
#define		Timer3_CLKO_Disable()		T4T3M &= ~1			/* 禁止T3溢出脉冲在T3(P0.4)脚输出	*/
#define		Timer3_CLKO_Enable_P04()	T4T3M |=  1			/* 允许T3溢出脉冲在T3(P0.4)脚输出，Fck = 1/2 T2 溢出率，T2可以1T或12T。	*/
#define		Timer3_CLKO_Disable_P04()	T4T3M &= ~1			/* 禁止T3溢出脉冲在T3(P0.4)脚输出	*/
#define 	Timer3_InterruptEnable()	IE2  |=  (1<<5)		/* 允许Timer3中断.	*/
#define 	Timer3_InterruptDisable()	IE2  &= ~(1<<5)		/* 禁止Timer3中断.	*/

#define		T3_Load(n)					TH3 = (n) / 256,	TL3 = (n) % 256
#define		T3_Load_us_1T(n)			Timer3_AsTimer(),Timer3_1T(), TH3=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)/256, TL3=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)%256
#define		T3_Load_us_12T(n)			Timer3_AsTimer(),Timer3_12T(),TH3=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)/256,TL3=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)%256
#define		T3_Frequency_1T_P04(n)		Timer3_InterruptDisable(),Timer3_AsTimer(),Timer3_1T(), TH3=(65536-(n/2+MAIN_Fosc/2)/(n))/256, TL3=(65536-(n/2+MAIN_Fosc/2)/(n))%256, Timer3_CLKO_P04_Enable,Timer3_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */
#define		T3_Frequency_12T_P04(n)		Timer3_InterruptDisable(),Timer3_AsTimer(),Timer3_12T(),TH3=(65536-(n/2+MAIN_Fosc/24)/(n))/256,TL3=(65536-(n/2+MAIN_Fosc/24)/(n))%256,Timer3_CLKO_P04_Enable,Timer3_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */

//====================================
#define 	Timer4_Run()	 			T4T3M |=  (1<<7)	/* 允许定时器4计数	*/
#define 	Timer4_Stop()	 			T4T3M &= ~(1<<7)	/* 禁止定时器4计数	*/
#define		Timer4_AsTimer()			T4T3M &= ~(1<<6)	/* 时器4用做定时器  */
#define		Timer4_AsCounter()			T4T3M |=  (1<<6)	/* 时器4用做计数器, P0.7为外部脉冲	*/
#define		Timer4_AsCounterP07()		T4T3M |=  (1<<6)	/* 时器4用做计数器, P0.7为外部脉冲	*/
#define 	Timer4_1T()					T4T3M |=  (1<<5)	/* 1T模式	*/
#define 	Timer4_12T()				T4T3M &= ~(1<<5)	/* 12T模式,	default	*/
#define		Timer4_CLKO_Enable()		T4T3M |=  (1<<4)	/* 允许T4溢出脉冲在T4(P0.6)脚输出，Fck = 1/2 T2 溢出率，T2可以1T或12T。	*/
#define		Timer4_CLKO_Disable()		T4T3M &= ~(1<<4)	/* 禁止T4溢出脉冲在T4(P0.6)脚输出	*/
#define		Timer4_CLKO_Enable_P06()	T4T3M |=  (1<<4)	/* 允许T4溢出脉冲在T4(P0.6)脚输出，Fck = 1/2 T2 溢出率，T2可以1T或12T。	*/
#define		Timer4_CLKO_Disable_P06()	T4T3M &= ~(1<<4)	/* 禁止T4溢出脉冲在T4(P0.6)脚输出	*/
#define 	Timer4_InterruptEnable()	IE2  |=  (1<<6)		/* 允许Timer4中断.	*/
#define 	Timer4_InterruptDisable()	IE2  &= ~(1<<6)		/* 禁止Timer4中断.	*/

#define		T4_Load(n)					TH4 = (n) / 256,	TL4 = (n) % 256
#define		T4_Load_us_1T(n)			Timer4_AsTimer(),Timer4_1T(), TH4=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)/256, TL4=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)%256
#define		T4_Load_us_12T(n)			Timer4_AsTimer(),Timer4_12T(),TH4=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)/256,TL4=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)%256
#define		T4_Frequency_1T_P06(n)		Timer4_InterruptDisable(),Timer4_AsTimer(),Timer4_1T(), TH4=(65536-(n/2+MAIN_Fosc/2)/(n))/256, TL4=(65536-(n/2+MAIN_Fosc/2)/(n))%256, Timer4_CLKO_P06_Enable(),Timer4_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */
#define		T4_Frequency_12T_P06(n)		Timer4_InterruptDisable(),Timer4_AsTimer(),Timer4_12T(),TH4=(65536-(n/2+MAIN_Fosc/24)/(n))/256,TL4=(65536-(n/2+MAIN_Fosc/24)/(n))%256,Timer4_CLKO_P06_Enable(),Timer4_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */
//====================================================================================================================


//sfr WDT_CONTR = 0xC1; //Watch-Dog-Timer Control register
//                                      7     6     5      4       3      2   1   0     Reset Value
//                                  WDT_FLAG  -  EN_WDT CLR_WDT IDLE_WDT PS2 PS1 PS0    xx00,0000
#define D_WDT_FLAG			(1<<7)
#define D_EN_WDT			(1<<5)
#define D_CLR_WDT			(1<<4)	//auto clear
#define D_IDLE_WDT			(1<<3)	//WDT counter when Idle
#define D_WDT_SCALE_2		0
#define D_WDT_SCALE_4		1
#define D_WDT_SCALE_8		2		//T=393216*N/fo
#define D_WDT_SCALE_16		3
#define D_WDT_SCALE_32		4
#define D_WDT_SCALE_64		5
#define D_WDT_SCALE_128		6
#define D_WDT_SCALE_256		7

#define	WDT_reset(n)	WDT_CONTR = D_EN_WDT + D_CLR_WDT + D_IDLE_WDT + (n)		//初始化WDT，喂狗


//						  7     6      5    4     3      2    1     0     Reset Value
//sfr PCON   = 0x87;	SMOD  SMOD0  LVDF  POF   GF1    GF0   PD   IDL    0001,0000	 //Power Control 
//SMOD		//串口双倍速
//SMOD0
#define		LVDF		(1<<5)	//P4.6低压检测标志
//POF
//GF1
//GF0
//#define 	D_PD		2		//set 1, power down mode
//#define 	D_IDLE		1		//set 1, idle mode
#define		MCU_IDLE()			PCON |= 1	//MCU 进入 IDLE 模式
#define		MCU_POWER_DOWN()	PCON |= 2	//MCU 进入 睡眠 模式


//sfr ISP_CMD   = 0xC5;
#define		ISP_STANDBY()	ISP_CMD = 0		//ISP空闲命令（禁止）
#define		ISP_READ()		ISP_CMD = 1		//ISP读出命令
#define		ISP_WRITE()		ISP_CMD = 2		//ISP写入命令
#define		ISP_ERASE()		ISP_CMD = 3		//ISP擦除命令

//sfr ISP_TRIG  = 0xC6;
#define 	ISP_TRIG()	ISP_TRIG = 0x5A,	ISP_TRIG = 0xA5		//ISP触发命令

//							  7    6    5      4    3    2    1     0    Reset Value
//sfr IAP_CONTR = 0xC7;		IAPEN SWBS SWRST CFAIL  -   WT2  WT1   WT0   0000,x000	//IAP Control Register
#define ISP_EN			(1<<7)
#define ISP_SWBS		(1<<6)
#define ISP_SWRST		(1<<5)
#define ISP_CMD_FAIL	(1<<4)
#define ISP_WAIT_1MHZ	7
#define ISP_WAIT_2MHZ	6
#define ISP_WAIT_3MHZ	5
#define ISP_WAIT_6MHZ	4
#define ISP_WAIT_12MHZ	3
#define ISP_WAIT_20MHZ	2
#define ISP_WAIT_24MHZ	1
#define ISP_WAIT_30MHZ	0

#if (MAIN_Fosc >= 24000000L)
	#define		ISP_WAIT_FREQUENCY	ISP_WAIT_30MHZ
#elif (MAIN_Fosc >= 20000000L)
	#define		ISP_WAIT_FREQUENCY	ISP_WAIT_24MHZ
#elif (MAIN_Fosc >= 12000000L)
	#define		ISP_WAIT_FREQUENCY	ISP_WAIT_20MHZ
#elif (MAIN_Fosc >= 6000000L)
	#define		ISP_WAIT_FREQUENCY	ISP_WAIT_12MHZ
#elif (MAIN_Fosc >= 3000000L)
	#define		ISP_WAIT_FREQUENCY	ISP_WAIT_6MHZ
#elif (MAIN_Fosc >= 2000000L)
	#define		ISP_WAIT_FREQUENCY	ISP_WAIT_3MHZ
#elif (MAIN_Fosc >= 1000000L)
	#define		ISP_WAIT_FREQUENCY	ISP_WAIT_2MHZ
#else
	#define		ISP_WAIT_FREQUENCY	ISP_WAIT_1MHZ
#endif



/* ADC Register */
//								7       6      5       4         3      2    1    0   Reset Value
//sfr ADC_CONTR = 0xBC;		ADC_POWER SPEED1 SPEED0 ADC_FLAG ADC_START CHS2 CHS1 CHS0 0000,0000	//AD 转换控制寄存器 
//sfr ADC_RES  = 0xBD;		ADCV.9 ADCV.8 ADCV.7 ADCV.6 ADCV.5 ADCV.4 ADCV.3 ADCV.2	  0000,0000	//A/D 转换结果高8位 
//sfr ADC_RESL = 0xBE;												  ADCV.1 ADCV.0	  0000,0000	//A/D 转换结果低2位
//sfr ADC_CONTR  = 0xBC;	//直接用MOV操作，不要用与或


//sfr SPCTL  = 0xCE;	SPI控制寄存器
//   7       6       5       4       3       2       1       0    	Reset Value
//	SSIG	SPEN	DORD	MSTR	CPOL	CPHA	SPR1	SPR0		0x00

#define	SPI_SSIG_None()		SPCTL |=  (1<<7)		//1: 忽略SS脚
#define	SPI_SSIG_Enable()	SPCTL &= ~(1<<7)		//0: SS脚用于决定主从机
#define	SPI_Enable()		SPCTL |=  (1<<6)		//1: 允许SPI
#define	SPI_Disable()		SPCTL &= ~(1<<6)		//0: 禁止SPI
#define	SPI_LSB_First()		SPCTL |=  (1<<5)		//1: LSB先发
#define	SPI_MSB_First()		SPCTL &= ~(1<<5)		//0: MSB先发
#define	SPI_Master()		SPCTL |=  (1<<4)		//1: 设为主机
#define	SPI_Slave()			SPCTL &= ~(1<<4)		//0: 设为从机
#define	SPI_SCLK_NormalH()	SPCTL |=  (1<<3)		//1: 空闲时SCLK为高电平
#define	SPI_SCLK_NormalL()	SPCTL &= ~(1<<3)		//0: 空闲时SCLK为低电平
#define	SPI_PhaseH()		SPCTL |=  (1<<2)		//1: 
#define	SPI_PhaseL()		SPCTL &= ~(1<<2)		//0: 
#define	SPI_Speed(n)		SPCTL = (SPCTL & ~3) | (n)	//设置速度, 0 -- fosc/4, 1 -- fosc/16, 2 -- fosc/64, 3 -- fosc/128

//sfr SPDAT  = 0xCF; //SPI Data Register                                                     0000,0000
//sfr SPSTAT  = 0xCD;	//SPI状态寄存器
//   7       6      5   4   3   2   1   0    	Reset Value
//	SPIF	WCOL	-	-	-	-	-	-
#define	SPIF	0x80		//SPI传输完成标志。写入1清0。
#define	WCOL	0x40		//SPI写冲突标志。写入1清0。

#define		SPI_USE_P12P13P14P15()	AUXR1 &= 0x0c	//将SPI切换到P12(SS) P13(MOSI) P14(MISO) P15(SCLK)(上电默认)。
#define		SPI_USE_P24P23P22P21()	AUXR1 = (AUXR1 & ~0x0c) | 0x04	//将SPI切换到P24(SS) P23(MOSI) P22(MISO) P21(SCLK)。
#define		SPI_USE_P54P40P41P43()	AUXR1 = (AUXR1 & ~0x0c) | 0x08	//将SPI切换到P54(SS) P40(MOSI) P41(MISO) P43(SCLK)。


/*
;PCA_PWMn:    7       6     5   4   3   2     1       0
;			EBSn_1	EBSn_0	-	-	-	-	EPCnH	EPCnL
;B5-B2:		保留
;B1(EPCnH):	在PWM模式下，与CCAPnH组成9位数。
;B0(EPCnL):	在PWM模式下，与CCAPnL组成9位数。
*/
#define		PWM0_NORMAL()	PCA_PWM0 &= ~3				//PWM0正常输出(默认)
#define		PWM0_OUT_0()	PCA_PWM0 |=  3				//PWM0一直输出0
#define		PWM0_OUT_1()	PCA_PWM0 &= ~3, CCAP0H = 0;	//PWM0一直输出1

#define		PWM1_NORMAL()	PCA_PWM1 &= ~3				//PWM0正常输出(默认)
#define		PWM1_OUT_0()	PCA_PWM1 |=  3				//PWM0一直输出0
#define		PWM1_OUT_1()	PCA_PWM1 &= ~3, CCAP1H = 0;	//PWM1一直输出1

#define		PWM2_NORMAL()	PCA_PWM2 &= ~3				//PWM1正常输出(默认)
#define		PWM2_OUT_0()	PCA_PWM2 |=  3				//PWM2一直输出0
#define		PWM2_OUT_1()	PCA_PWM2 &= ~3, CCAP2H = 0;	//PWM2一直输出1

//					 7     6     5     4     3     2     1     0    Reset Value
//sfr CMOD  = 0xD9;	CIDL   -     -     -   CPS2   CPS1  CPS0  ECF   0xxx,0000	//PCA 工作模式寄存器。
#define PCA_IDLE_OFF()		CMOD |=  (1<<7)				//IDLE状态PCA停止计数。
#define PCA_IDLE_ON()		CMOD &= ~(1<<7)				//IDLE状态PCA继续计数。
#define PCA_CLK_12T()		CMOD &= ~0x0E				//PCA计数脉冲选择外部晶振/12。	fosc/12
#define PCA_CLK_2T()		CMOD = (CMOD & ~0x0E) + 2	//PCA计数脉冲选择外部晶振/2。	fosc/2
#define PCA_CLK_T0()		CMOD = (CMOD & ~0x0E) + 4	//PCA计数脉冲选择Timer0中断，Timer0可通过AUXR寄存器设置成工作在12T或1T模式。
#define PCA_CLK_ECI()		CMOD = (CMOD & ~0x0E) + 6	//PCA计数脉冲选择从ECI/P3.4脚输入的外部时钟，最大 fosc/2。
#define PCA_CLK_1T()		CMOD = (CMOD & ~0x0E) + 8	//PCA计数脉冲选择外部晶振。		Fosc/1
#define PCA_CLK_4T()		CMOD = (CMOD & ~0x0E) + 10	//PCA计数脉冲选择外部晶振/4。	Fosc/4
#define PCA_CLK_6T()		CMOD = (CMOD & ~0x0E) + 12	//PCA计数脉冲选择外部晶振/6。	Fosc/6
#define PCA_CLK_8T()		CMOD = (CMOD & ~0x0E) + 14	//PCA计数脉冲选择外部晶振/8。	Fosc/8
#define PCA_INT_ENABLE()	CMOD |=  1					//PCA计数器溢出中断允许位，1---允许CF（CCON.7）产生中断。
#define PCA_INT_DISABLE()	CMOD &= ~1					//PCA计数器溢出中断禁止。

//					    7      6       5        4       3       2       1      0    Reset Value
//sfr AUXR1 = 0xA2;	  S1_S1  S1_S0  CCP_S1   CCP_S0  SPI_S1   SPI_S0    -     DPS   0100,0000	//Auxiliary Register 1

#define		PCA_USE_P12P11P10P37()	AUXR1 &= ~0x30		//将PCA/PWM切换到P12(ECI) P11(CCP0) P10(CCP1) P37(CCP2)(上电默认)。
#define		PCA_USE_P34P35P36P37()	AUXR1 = (AUXR1 & ~0x30) | 0x10	//将PCA/PWM切换到P34(ECI) P35(CCP0) P36(CCP1) P37(CCP2)。
#define		PCA_USE_P24P25P26P27()	AUXR1 = (AUXR1 & ~0x30) | 0x20	//将PCA/PWM切换到P24(ECI) P25(CCP0) P26(CCP1) P27(CCP2)。

#define		DPS_SEL1()		AUXR1 |=  1		//1：选择DPTR1。
#define		DPS_SEL0()		AUXR1 &= ~1		//0：选择DPTR0(上电默认)。


/*									7     6      5      4     3     2     1     0     Reset Value
//sfr CCAPM0 = 0xDA;	PWM 寄存器  -   ECOM0  CAPP0  CAPN0  MAT0  TOG0  PWM0  ECCF0   x000,0000	//PCA 模块0 
//sfr CCAPM1 = 0xDB;	PWM 寄存器  -   ECOM1  CAPP1  CAPN1  MAT1  TOG1  PWM1  ECCF1   x000,0000	//PCA 模块1
//sfr CCAPM2 = 0xDC;	PWM 寄存器  -   ECOM2  CAPP2  CAPN2  MAT2  TOG2  PWM2  ECCF2   x000,0000	//PCA 模块2
;ECOMn = 1:	允许比较功能。
;CAPPn = 1:	允许上升沿触发捕捉功能。
;CAPNn = 1:	允许下降沿触发捕捉功能。
;MATn  = 1:	当匹配情况发生时，允许CCON中的CCFn置位。
;TOGn  = 1:	当匹配情况发生时，CEXn将翻转。(CEX0/PCA0/PWM0/P3.7,CEX1/PCA1/PWM1/P3.5)
;PWMn  = 1:	将CEXn设置为PWM输出。
;ECCFn = 1:	允许CCON中的CCFn触发中断。
;ECOMn CAPPn CAPNn MATn TOGn PWMn ECCFn
;  0     0     0    0    0    0     0		00H	未启用任何功能。
;  x     1     0    0    0    0     x	 	20H	16位CEXn上升沿触发捕捉功能。
;  x     0     1    0    0    0     x	 	10H	16位CEXn下降沿触发捕捉功能。
;  x     1     1    0    0    0     x	 	30H	16位CEXn/PCAn边沿（上、下沿）触发捕捉功能。
;  1     0     0    1    0    0     x	 	48H	16位软件定时器。
;  1     0     0    1    1    0     x	 	4CH	16位高速脉冲输出。
;  1     0     0    0    0    1     0		42H	8位PWM。无中断
;  1     1     0    0    0    1     1		63H	8位PWM。低变高可产生中断
;  1     0     1    0    0    1     1		53H	8位PWM。高变低可产生中断
;  1     1     1    0    0    1     1		73H	8位PWM。低变高或高变低均可产生中断
;*******************************************************************
;*******************************************************************/
#define		PCA0_none()				CCAPM0 = 0
#define		PCA0_PWM(nbit)			CCAPM0 = 0x42,PCA_PWM0 = (PCA_PWM0 & 0x0c) | ((8-nbit)<<6)
#define		PCA0_PWM_rise_int(nbit) CCAPM0 = 0x63,PCA_PWM0 = (PCA_PWM0 & 0x0c) | ((8-nbit)<<6)
#define		PCA0_PWM_fall_int(nbit) CCAPM0 = 0x53,PCA_PWM0 = (PCA_PWM0 & 0x0c) | ((8-nbit)<<6)
#define		PCA0_PWM_edge_int(nbit) CCAPM0 = 0x73,PCA_PWM0 = (PCA_PWM0 & 0x0c) | ((8-nbit)<<6)
#define		PCA0_capture_rise()		CCAPM0 = (0x20 + 1)
#define		PCA0_capture_fall()		CCAPM0 = (0x10 + 1)
#define		PCA0_capture_edge()		CCAPM0 = (0x30 + 1)
#define		PCA0_16bit_Timer()		CCAPM0 = (0x48 + 1)
#define		PCA0_High_Pulse()		CCAPM0 = (0x4C + 1)

#define		PCA1_none()				CCAPM1 = 0
#define		PCA1_PWM(nbit)			CCAPM1 = 0x42,PCA_PWM1 = (PCA_PWM1 & 0x0c) | ((8-nbit)<<6)
#define		PCA1_PWM_rise_int(nbit) CCAPM1 = 0x63,PCA_PWM1 = (PCA_PWM1 & 0x0c) | ((8-nbit)<<6)
#define		PCA1_PWM_fall_int(nbit) CCAPM1 = 0x53,PCA_PWM1 = (PCA_PWM1 & 0x0c) | ((8-nbit)<<6)
#define		PCA1_PWM_edge_int(nbit) CCAPM1 = 0x73,PCA_PWM1 = (PCA_PWM1 & 0x0c) | ((8-nbit)<<6)
#define		PCA1_capture_rise()		CCAPM1 = (0x20 + 1)
#define		PCA1_capture_fall()		CCAPM1 = (0x10 + 1)
#define		PCA1_capture_edge()		CCAPM1 = (0x30 + 1)
#define		PCA1_16bit_Timer()		CCAPM1 = (0x48 + 1)
#define		PCA1_High_Pulse()		CCAPM1 = (0x4C + 1)

#define		PCA2_none()				CCAPM2 = 0
#define		PCA2_PWM(nbit)			CCAPM2 = 0x42,PCA_PWM2 = (PCA_PWM2 & 0x0c) | ((8-nbit)<<6)
#define		PCA2_PWM_rise_int(nbit) CCAPM2 = 0x63,PCA_PWM2 = (PCA_PWM2 & 0x0c) | ((8-nbit)<<6)
#define		PCA2_PWM_fall_int(nbit) CCAPM2 = 0x53,PCA_PWM2 = (PCA_PWM2 & 0x0c) | ((8-nbit)<<6)
#define		PCA2_PWM_edge_int(nbit) CCAPM2 = 0x73,PCA_PWM2 = (PCA_PWM2 & 0x0c) | ((8-nbit)<<6)
#define		PCA2_capture_rise()		CCAPM2 = (0x20 + 1)
#define		PCA2_capture_fall()		CCAPM2 = (0x10 + 1)
#define		PCA2_capture_edge()		CCAPM2 = (0x30 + 1)
#define		PCA2_16bit_Timer()		CCAPM2 = (0x48 + 1)
#define		PCA2_High_Pulse()		CCAPM2 = (0x4C + 1)

/* Above is STC additional SFR or change */




/**********************************************************/
typedef 	unsigned char	u8;
typedef 	unsigned int	u16;
typedef 	unsigned long	u32;

/**********************************************************/
#define NOP1()  _nop_()
#define NOP2()  NOP1(),NOP1()
#define NOP3()  NOP2(),NOP1()
#define NOP4()  NOP3(),NOP1()
#define NOP5()  NOP4(),NOP1()
#define NOP6()  NOP5(),NOP1()
#define NOP7()  NOP6(),NOP1()
#define NOP8()  NOP7(),NOP1()
#define NOP9()  NOP8(),NOP1()
#define NOP10() NOP9(),NOP1()
#define NOP11() NOP10(),NOP1()
#define NOP12() NOP11(),NOP1()
#define NOP13() NOP12(),NOP1()
#define NOP14() NOP13(),NOP1()
#define NOP15() NOP14(),NOP1()
#define NOP16() NOP15(),NOP1()
#define NOP17() NOP16(),NOP1()
#define NOP18() NOP17(),NOP1()
#define NOP19() NOP18(),NOP1()
#define NOP20() NOP19(),NOP1()
#define NOP21() NOP20(),NOP1()
#define NOP22() NOP21(),NOP1()
#define NOP23() NOP22(),NOP1()
#define NOP24() NOP23(),NOP1()
#define NOP25() NOP24(),NOP1()
#define NOP26() NOP25(),NOP1()
#define NOP27() NOP26(),NOP1()
#define NOP28() NOP27(),NOP1()
#define NOP29() NOP28(),NOP1()
#define NOP30() NOP29(),NOP1()
#define NOP31() NOP30(),NOP1()
#define NOP32() NOP31(),NOP1()
#define NOP33() NOP32(),NOP1()
#define NOP34() NOP33(),NOP1()
#define NOP35() NOP34(),NOP1()
#define NOP36() NOP35(),NOP1()
#define NOP37() NOP36(),NOP1()
#define NOP38() NOP37(),NOP1()
#define NOP39() NOP38(),NOP1()
#define NOP40() NOP39(),NOP1()
#define NOP(N)  NOP##N()


/**********************************************/
#define P0n_standard(bitn)			P0M1 &= ~(bitn),	P0M0 &= ~(bitn)	/* 00  */
#define P0n_push_pull(bitn)			P0M1 &= ~(bitn),	P0M0 |=  (bitn)	/* 01  */
#define P0n_pure_input(bitn)		P0M1 |=  (bitn),	P0M0 &= ~(bitn)	/* 10  */
#define P0n_open_drain(bitn)		P0M1 |=  (bitn),	P0M0 |=  (bitn)	/* 11  */

#define P1n_standard(bitn)			P1M1 &= ~(bitn),	P1M0 &= ~(bitn)
#define P1n_push_pull(bitn)			P1M1 &= ~(bitn),	P1M0 |=  (bitn)
#define P1n_pure_input(bitn)		P1M1 |=  (bitn),	P1M0 &= ~(bitn)
#define P1n_open_drain(bitn)		P1M1 |=  (bitn),	P1M0 |=  (bitn)

#define P2n_standard(bitn)			P2M1 &= ~(bitn),	P2M0 &= ~(bitn)
#define P2n_push_pull(bitn)			P2M1 &= ~(bitn),	P2M0 |=  (bitn)
#define P2n_pure_input(bitn)		P2M1 |=  (bitn),	P2M0 &= ~(bitn)
#define P2n_open_drain(bitn)		P2M1 |=  (bitn),	P2M0 |=  (bitn)

#define P3n_standard(bitn)			P3M1 &= ~(bitn),	P3M0 &= ~(bitn)
#define P3n_push_pull(bitn)			P3M1 &= ~(bitn),	P3M0 |=  (bitn)
#define P3n_pure_input(bitn)		P3M1 |=  (bitn),	P3M0 &= ~(bitn)
#define P3n_open_drain(bitn)		P3M1 |=  (bitn),	P3M0 |=  (bitn)

#define P4n_standard(bitn)			P4M1 &= ~(bitn),	P4M0 &= ~(bitn)
#define P4n_push_pull(bitn)			P4M1 &= ~(bitn),	P4M0 |=  (bitn)
#define P4n_pure_input(bitn)		P4M1 |=  (bitn),	P4M0 &= ~(bitn)
#define P4n_open_drain(bitn)		P4M1 |=  (bitn),	P4M0 |=  (bitn)

#define P5n_standard(bitn)			P5M1 &= ~(bitn),	P5M0 &= ~(bitn)
#define P5n_push_pull(bitn)			P5M1 &= ~(bitn),	P5M0 |=  (bitn)
#define P5n_pure_input(bitn)		P5M1 |=  (bitn),	P5M0 &= ~(bitn)
#define P5n_open_drain(bitn)		P5M1 |=  (bitn),	P5M0 |=  (bitn)

#define P6n_standard(bitn)			P6M1 &= ~(bitn),	P6M0 &= ~(bitn)
#define P6n_push_pull(bitn)			P6M1 &= ~(bitn),	P6M0 |=  (bitn)
#define P6n_pure_input(bitn)		P6M1 |=  (bitn),	P6M0 &= ~(bitn)
#define P6n_open_drain(bitn)		P6M1 |=  (bitn),	P6M0 |=  (bitn)

#define P7n_standard(bitn)			P7M1 &= ~(bitn),	P7M0 &= ~(bitn)
#define P7n_push_pull(bitn)			P7M1 &= ~(bitn),	P7M0 |=  (bitn)
#define P7n_pure_input(bitn)		P7M1 |=  (bitn),	P7M0 &= ~(bitn)
#define P7n_open_drain(bitn)		P7M1 |=  (bitn),	P7M0 |=  (bitn)

/****************************************************************/


//sfr INT_CLKO = 0x8F;	//附加的 SFR WAKE_CLKO (地址：0x8F)
/*
    7   6    5    4   3     2        1       0         Reset Value
    -  EX4  EX3  EX2  -   T2CLKO   T1CLKO  T0CLKO      0000,0000B
b6 -  EX4      : 外中断INT4允许
b5 -  EX3      : 外中断INT3允许
b4 -  EX2      : 外中断INT2允许
b2 - T1CLKO    : 允许 T2 溢出脉冲在P3.0脚输出，Fck1 = 1/2 T1 溢出率
b1 - T1CLKO    : 允许 T1 溢出脉冲在P3.4脚输出，Fck1 = 1/2 T1 溢出率
b0 - T0CLKO    : 允许 T0 溢出脉冲在P3.5脚输出，Fck0 = 1/2 T0 溢出率
*/

#define		LVD_InterruptEnable()		ELVD = 1
#define		LVD_InterruptDisable()		ELVD = 0


//sfr WKTCL = 0xAA;	//STC11F\10和STC15系列 唤醒定时器低字节
//sfr WKTCH = 0xAB;	//STC11F\10和STC15系列 唤醒定时器高字节
//	B7		B6	B5	B4	B3	B2	B1	B0		B7	B6	B5	B4	B3	B2	B1	B0
//	WKTEN				S11	S10	S9	S8		S7	S6	S5	S4	S3	S2	S1	S0	n * 560us
#define		WakeTimerDisable()		WKTCH &= 0x7f	//WKTEN = 0		禁止睡眠唤醒定时器
#define		WakeTimerSet(scale)		WKTCL = (scale) % 256,WKTCH = (scale) / 256 | 0x80	//WKTEN = 1	允许睡眠唤醒定时器


//sfr CLK_DIV = 0x97; //Clock Divder 系统时钟分频  -     -      -       -     -  CLKS2 CLKS1 CLKS0 xxxx,x000
#define		SYSTEM_CLK_1T()		CLK_DIV &= ~0x07	//default
#define		SYSTEM_CLK_2T()		CLK_DIV = (CLK_DIV & ~0x07) | 1
#define		SYSTEM_CLK_4T()		CLK_DIV = (CLK_DIV & ~0x07) | 2
#define		SYSTEM_CLK_8T()		CLK_DIV = (CLK_DIV & ~0x07) | 3
#define		SYSTEM_CLK_16T()	CLK_DIV = (CLK_DIV & ~0x07) | 4
#define		SYSTEM_CLK_32T()	CLK_DIV = (CLK_DIV & ~0x07) | 5
#define		SYSTEM_CLK_64T()	CLK_DIV = (CLK_DIV & ~0x07) | 6
#define		SYSTEM_CLK_128T()	CLK_DIV =  CLK_DIV          | 7

#define		MCLKO_P54_None()	CLK_DIV &= ~0xc0					//主时钟不输出
#define		MCLKO_P54_DIV1()	CLK_DIV  = (CLK_DIV & ~0xc0) | 0x40	//主时钟不分频输出
#define		MCLKO_P54_DIV2()	CLK_DIV  = (CLK_DIV & ~0xc0) | 0x80	//主时钟2分频输出
#define		MCLKO_P54_DIV4()	CLK_DIV  =  CLK_DIV | 0xc0			//主时钟4分频输出

#define		MCLKO_P34_None()	CLK_DIV &= ~0xc0					//主时钟不输出
#define		MCLKO_P34_DIV1()	CLK_DIV  = (CLK_DIV & ~0xc0) | 0x40	//主时钟不分频输出
#define		MCLKO_P34_DIV2()	CLK_DIV  = (CLK_DIV & ~0xc0) | 0x80	//主时钟2分频输出
#define		MCLKO_P34_DIV4()	CLK_DIV  =  CLK_DIV | 0xc0			//主时钟4分频输出

//sfr BUS_SPEED = 0xA1; //Stretch register      -   -  -  -   -   -  EXRTS1  EXRTSS0 xxxx,xx10
#define		BUS_SPEED_1T()	BUS_SPEED = 0
#define		BUS_SPEED_2T()	BUS_SPEED = 1
#define		BUS_SPEED_4T()	BUS_SPEED = 2
#define		BUS_SPEED_8T()	BUS_SPEED = 3

/*   interrupt vector */
#define		INT0_VECTOR		0
#define		TIMER0_VECTOR	1
#define		INT1_VECTOR		2
#define		TIMER1_VECTOR	3
#define		UART1_VECTOR	4
#define		ADC_VECTOR		5
#define		LVD_VECTOR		6
#define		PCA_VECTOR		7
#define		UART2_VECTOR	8
#define		SPI_VECTOR		9
#define		INT2_VECTOR		10
#define		INT3_VECTOR		11
#define		TIMER2_VECTOR	12
#define		INT4_VECTOR		16
#define		UART3_VECTOR	17
#define		UART4_VECTOR	18
#define		TIMER3_VECTOR	19
#define		TIMER4_VECTOR	20
#define		CMP_VECTOR		21
#define		PWM_VECTOR		22
#define		PWMFD_VECTOR	23


#define	TRUE	1
#define	FALSE	0

//=============================================================

//========================================

#define	PolityLow			0	//低优先级中断
#define	PolityHigh			1	//高优先级中断

//========================================

#define		MCLKO_None	0
#define		MCLKO_DIV1	1
#define		MCLKO_DIV2	2
#define		MCLKO_DIV4	3

#define		ENABLE		1
#define		DISABLE		0

#define		STC15W_4K16S4	16
#define		STC15W_4K32S4	32
#define		STC15W_4K40S4	40
#define		STC15W_4K48S4	48
#define		STC15W_4K56S4	56

#define		IAP15W_4K58S4	58
#define		IAP15W_4K61S4	61
#define		IAP15W_4K63S4	63

#define		IAP15W_413AS	13

#endif

