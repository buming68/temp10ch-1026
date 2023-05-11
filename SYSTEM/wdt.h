
#ifndef	__WDT_H
#define	__WDT_H

#include	"config.h"

#define IDLE_Count 1 
#define IDLE_Stop  0

#define WDT_CLOCK_2T    0	
#define WDT_CLOCK_4T    1	
#define WDT_CLOCK_8T		2
#define WDT_CLOCK_16T		3
#define WDT_CLOCK_32T		4
#define WDT_CLOCK_64T		5
#define WDT_CLOCK_128T  6
#define WDT_CLOCK_256T  7


typedef struct
{
	u8 WDT_EN;                  //看门狗是否允许 						ENABLE,DISABLE
	u8 WDT_IDLE;                //看门狗在IDLE模式位是否计数            IDLE_Count, IDLE_ Stop
  u8 WDT_CLOCK;              	//看门狗计数器的预分频                  WDT_CLOCK_2T,	WDT_CLOCK_4T,	WDT_CLOCK_6T,	
                                                                      //WDT_CLOCK_8T,WDT_CLOCK_16T,	WDT_CLOCK_32T,	                                                                      //WDT_CLOCK_64T,	WDT_CLOCK_128T,WDT_CLOCK_256T
} WDT_InitTypeDef;


extern u8	Wdt_Inilize(WDT_InitTypeDef *WDTx);
extern void	Wdt_EnOrNo(u8 theFlag);
extern void Wdt_Feed(void);

extern void	WDT_config(void);
#endif
