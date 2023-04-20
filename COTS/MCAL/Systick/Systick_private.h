#include "Stdtypes.h"
#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H






#define SYSTICK_BASEADDRESS						(0xE000E010)


typedef struct{
	
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;

}Systick_t;


#define SYSTICK				((Systick_t* const)SYSTICK_BASEADDRESS)






#endif /* SYSTICK_PRIVATE_H */
