#ifndef __IEE_RAM
#define __IEE_RAM



#include "PE_Types.h"



#define IEE_RAM_AREA_START                 ((IEE_RAM_TAddress)0x13F400UL)  
#define IEE_RAM_AREA_END                   ((IEE_RAM_TAddress)0x13FFFFUL)
#define IEE_RAM_AREA_SIZE                  ((IEE_RAM_TAddress)0xBFFU)      
#define EEPROM_START_PTR                   ((IEE_RAM_TAddress)0x13F800UL)  


#ifndef __BWUserType_IEE_RAM_TAddress
#define __BWUserType_IEE_RAM_TAddress
typedef far char * far IEE_RAM_TAddress; 
#endif


typedef struct    
{
    unsigned char fstat_var;        
    unsigned char ferfstat_var;     
}ErrType;




ErrType LaunchFlashCommand(char params, unsigned char ccob0high, unsigned char ccob0low, unsigned int ccob1,unsigned int ccob2,unsigned int ccob3,unsigned int ccob4,unsigned int ccob5, unsigned int ccob6, unsigned int ccob7);


void  ENABLE_EE_RAM_WRITING(void);

void  DISABLE_EE_RAM_WRITING(void);



void IEE_RAM_Init(byte init);













byte IEE_RAM_Set_X_WORDS(IEE_RAM_TAddress Addr,VUINT8 *Data,VUINT16 size);


byte IEE_RAM_SetData(IEE_RAM_TAddress Addr,VUINT8 *Data,VUINT16 size);


byte IEE_RAM_SetWord( IEE_RAM_TAddress Addr, word Data );

byte IEE_RAM_SetLong(IEE_RAM_TAddress Addr,dword Data);


byte IEE_RAM_SetByte(IEE_RAM_TAddress Addr,byte Data);

byte IEE_RAM_SetByte_User(IEE_RAM_TAddress Addr,byte Data);
















byte IEE_RAM_GetLong(IEE_RAM_TAddress Addr,dword *Data);

byte IEE_RAM_GetWord(IEE_RAM_TAddress Addr,word *Data);

byte IEE_RAM_Get_X_WORDS(IEE_RAM_TAddress Addr,VUINT8 *Data,VUINT16 size);


byte IEE_RAM_GetData(IEE_RAM_TAddress Addr,VUINT8 *Data,VUINT16 size);

byte IEE_RAM_GetByte(IEE_RAM_TAddress Addr,byte *Data);


byte IEE_RAM_GetByte_User(IEE_RAM_TAddress Addr,byte *Data);


#endif 



