#ifndef __DELAY_H_
#define __DELAY_H_

#define MAIN_Fosc		11059200L	//定义主时钟
#include	"15W4KxxS4.H"

#include <string.h>
#include <stdio.h>
#include <intrins.H>

#define  uint32   unsigned long
#define  uint16   unsigned int  
#define  uint8    unsigned char  

extern void delay_ms(uint16 x);

#endif
