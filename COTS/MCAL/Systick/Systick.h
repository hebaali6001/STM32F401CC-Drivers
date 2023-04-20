#ifndef SYSTICK_H
#define SYSTICK_H

#include "Stdtypes.h"



#define SYSTEM_CLOCK			(25000000)


typedef void (*cbf_t)(void);
			




typedef enum{
	
	SYSTICK_Ok=0,
	SYSTICK_NotOk, 
	SYSTICK_WrongConfig,
	
}SYSTIC_Return;




SYSTIC_Return Systick_Start(void);

SYSTIC_Return Systick_Stop(void);

SYSTIC_Return Systick_Init(void);

SYSTIC_Return Systick_Set_Period_ms(u32 time);

SYSTIC_Return Systick_Set_Period_us(u32 time);

SYSTIC_Return Systick_Set_CallBackFunction(cbf_t func);













#endif /* SYSTICK_H */
