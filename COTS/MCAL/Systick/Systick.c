 
#include "Systick.h"
#include "Systick_private.h"



#define ENABLE_MUSK				(0x01)
#define RESET_VAR_REGISTER		(0x00)
#define MAX_TIMER_LOAD			(0x00ffffffff)
#define CLKSOURCE_SHIFT			2
#define REQUIST_EN_ESHIFT		1


static cbf_t notifyapp;




SYSTIC_Return Systick_Start(void){
	
	SYSTIC_Return status = SYSTICK_NotOk;
	
	u32 en = SYSTICK->CTRL;
	en |= (ENABLE_MUSK);
	SYSTICK->CTRL = en;
	
	return status;
}

SYSTIC_Return Systick_Stop(void){
	
	SYSTIC_Return status = SYSTICK_NotOk;
	
	u32 en = SYSTICK->CTRL;
	en &= ~(ENABLE_MUSK);
	SYSTICK->CTRL = en;
	
	//and clear the current value in the val_Register
	SYSTICK->VAL = RESET_VAR_REGISTER;
	
	return status;
}

SYSTIC_Return Systick_Init(void){


	SYSTIC_Return status = SYSTICK_NotOk;
	u32 ctrl =0;

	Systick_Stop();

	ctrl = SYSTICK->CTRL;
	ctrl |= (ENABLE_MUSK<<REQUIST_EN_ESHIFT);
	ctrl |= (ENABLE_MUSK<<CLKSOURCE_SHIFT);
	SYSTICK->CTRL = ctrl;

	status = SYSTICK_Ok;
	return status;
}

SYSTIC_Return Systick_Set_Period_ms(u32 time){
	
	SYSTIC_Return status = SYSTICK_NotOk;
	Systick_Stop();
	
	u32 loc_ticks = (SYSTEM_CLOCK /1000 *time)-1;
	
	if(loc_ticks > MAX_TIMER_LOAD){
		status = SYSTICK_WrongConfig;
	}else{
		SYSTICK->LOAD = loc_ticks;
		
		//and clear the current value in the val_Register
		SYSTICK->VAL = RESET_VAR_REGISTER;
		
		status = SYSTICK_Ok;
	}
	return status;
}

SYSTIC_Return Systick_Set_Period_us(u32 time){

	SYSTIC_Return status = SYSTICK_NotOk;
	Systick_Stop();
	
	u32 loc_ticks = (SYSTEM_CLOCK /1000000 *time)-1;
	
	if(loc_ticks > MAX_TIMER_LOAD){
		status = SYSTICK_WrongConfig;
	}else{
		SYSTICK->LOAD = loc_ticks;
		
		//and clear the current value in the val_Register	
		SYSTICK->VAL = RESET_VAR_REGISTER;
		
		status = SYSTICK_Ok;
	}
	return status;
}

SYSTIC_Return Systick_Set_CallBackFunction(cbf_t func){
	
	SYSTIC_Return status = SYSTICK_NotOk;
	if(func){
		notifyapp =func;
		status = SYSTICK_Ok;
	}
	return status;
}



void SysTick_Handler (){
	if(notifyapp){
		notifyapp();
	}
}
