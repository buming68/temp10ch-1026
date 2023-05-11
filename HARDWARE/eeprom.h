
#ifndef	__EEPROM_H
#define	__EEPROM_H

#include	"config.h"

//	ѡ��MCU�ͺ�
//#define	MCU_Type	STC15W_4K16S4	
//#define	MCU_Type	STC15W_4K32S4	
//#define	MCU_Type	STC15W_4K40S4	
//#define	MCU_Type	STC15W_4K48S4	
//#define	MCU_Type	STC15W_4K56S4	
//#define	MCU_Type  IAP15W_4K58S4


//#define	MCU_Type	IAP15W_4K61S4		

//#define	MCU_Type	IAP15W_413AS

#define	MCU_Type  IAP15W_4K63S4
/************************** ISP/IAP *****************************
 IAPϵ�� ������Ӧ�ó����޸�Ӧ�ó���

STC15W4KxxS4	�������䣬512�ֽ�/��������0x0000��ʼ��

     �ͺ�        ��С   ������  ��ʼ��ַ  ������ַ   MOVC��ƫ�Ƶ�ַ
STC15W4K16S4   42K   		84����  0x0000  ~  0xD3FF        0x0000
STC15W4K32S4   26K    	52����  0x0000  ~  0xB3FF        0x0000
STC15W4K40S4   18K    	36����  0x0000  ~  0x93FF        0x0000
STC15W4K48S4   10K   		20����  0x0000  ~  0xD3FF        0x0000
STC15W4K56S4   2K    		4����  0x0000  	~  0xB3FF         0x0000

IAP15W4K58S4   K    		116����  0x0000  ~  0xE7FF        0xE000
IAP15W4K61S4   K    		122����  0x0000  ~  0xF3FF        0xE000
IRC15W4K63S4   K    		127����  0x0000  ~  0xFDFF        0xE000

IAP15W413AS              26����  0x0000  ~  0x33FF				0x2C00  ռ�ó������2K  ������ÿռ�11K
*/


#if   (MCU_Type == STC15W_4K16S4)
      #define   MOVC_ShiftAddress    0x0000
#elif (MCU_Type == STC15W_4K32S4)
      #define   MOVC_ShiftAddress    0x0000
#elif (MCU_Type == STC15W_4K40S4)
      #define   MOVC_ShiftAddress    0x0000
#elif (MCU_Type == STC15W_4K48S4)
      #define   MOVC_ShiftAddress    0x0000
#elif (MCU_Type == STC15W_4K56S4)
      #define   MOVC_ShiftAddress    0x0000
#elif (MCU_Type == IAP15W_4K58S4)
/*����ʵ����Ҫ���� ��Ҫע�ⲻҪ�������Լ�����Ч������ ����������ȡ2K*/
      #define   MOVC_ShiftAddress    0xE000 
#elif (MCU_Type == IAP15W_4K61S4)
      #define   MOVC_ShiftAddress    0xE000
#elif (MCU_Type == IAP15W_4K63S4)
      #define   MOVC_ShiftAddress    0xE000			
#elif (MCU_Type == IAP15W_413AS)
      #define   MOVC_ShiftAddress    0x2C00				
#endif

/**************************ͨ�����ʺ�վַ˵�� *****************************
BaudAddr[2],EEPROMTemp[2]
��һλ�������ʱ�־λ  2--1200�� 3--2400�� 4--4800�� 5--9600����ʼȱʡֵ��
											6--19200��7-=38400��8--				9--56000
											0x0A--57600,        0x0B--115200
				 Ŀǰ��֧��9600��19200							
�ڶ�λ���ӻ�485��ַ   01---250  ��ʼȱʡֵ:01
											00---�㲥��ַ�����д�վ�����Խ���
����λ���Ƿ��Զ��ش�  0---���ش�   1��2��3  �ش����ʱ�����루ʹ��DIP���أ����Ǵ��룩�������Ǽ��ʱ��											
											1---1��    2---3��   3----5��				
****************************************************************************/

extern u8 BaudAddr[3];						//ͨѶ����1��485�ӿ�����ʹ�õ�  ���ʱ�־����ַ
extern u8 EEPROMTemp[3];					//ͨѶ����1��485�ӿ�ȱʡ  ���ʱ�־����ַ,����ʹ�ó�ʼ��ֵ
extern u16 Addr_Baud ;    				//ͨѶ���ʴ���
extern u16 Addr_485 ;    					//485��ַ
extern u16 Addr_autoT ;						//�Ƿ��Զ��ش���1���ش�


void	DisableEEPROM(void);
void 	EEPROM_read_n(u16 EE_address,u8 *DataAddress,u16 number);
void 	EEPROM_write_n(u16 EE_address,u8 *DataAddress,u16 number);
void	EEPROM_SectorErase(u16 EE_address);

void EEPROM_Init(void);
extern uint8 EEPROM_write_1(u16 EE_address,u8 *DataAddress);

#endif