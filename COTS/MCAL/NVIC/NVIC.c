
#include "NVIC.h"
#include "NVIC_private.h"


#define PRIDROUP_MUSK 			0b111
#define LEVELMUSK				0b0000
 
 
NVIC_Return Enable_Interrupt(u8 cpy_peripheral_num){

	NVIC_Return status = NVIC_NotOk;

	if((cpy_peripheral_num<0) || (cpy_peripheral_num>239)){
		status = NVIC_Invalid_prepheral;
	}else{

	u8 loc_Register_Num=0;
	u8 loc_Bit_Num=0;
	
	u8 loc_periph = cpy_peripheral_num;
	loc_Register_Num = loc_periph/32;
	loc_periph = cpy_peripheral_num;
	loc_Bit_Num = loc_periph%32;
	
	NVIC->ISER[loc_Register_Num] |= (1<<loc_Bit_Num);
	
	status = NVIC_Ok;
	}
	return status;
}



NVIC_Return Disable_Interrupt(u8 cpy_peripheral_num){
	
	NVIC_Return status = NVIC_NotOk;

	if((cpy_peripheral_num<0) || (cpy_peripheral_num>239)){
		status = NVIC_Invalid_prepheral;
	}else{
	
	u8 loc_Register_Num=0;
	u8 loc_Bit_Num=0;
	
	u8 loc_periph = cpy_peripheral_num;
	loc_Register_Num = loc_periph/32;
	loc_periph = cpy_peripheral_num;
	loc_Bit_Num = loc_periph%32;
	
	NVIC->ICER[loc_Register_Num] |= (1<<loc_Bit_Num);
	
	status = NVIC_Ok;
	}
	return status;
}


NVIC_Return Get_Interrupt_Status(u8 cpy_peripheral_num ,u8* Status){
	
	NVIC_Return status = NVIC_NotOk;

	if((cpy_peripheral_num<0) || (cpy_peripheral_num>239)){
		status = NVIC_Invalid_prepheral;
	}else{

	u8 loc_Register_Num=0;
	u8 loc_Bit_Num=0;
	
	u8 loc_periph = cpy_peripheral_num;
	loc_Register_Num = loc_periph/32;
	loc_periph = cpy_peripheral_num;
	loc_Bit_Num = loc_periph%32;
	
	*Status=(((NVIC->ISER[loc_Register_Num])>>loc_Bit_Num)&0x01);


	status = NVIC_Ok;
	}
	return status;	
}



NVIC_Return Set_Pending(u8 cpy_peripheral_num){
	
	NVIC_Return status = NVIC_NotOk;

	if((cpy_peripheral_num<0) || (cpy_peripheral_num>239)){
		status = NVIC_Invalid_prepheral;
	}else{

	u8 loc_Register_Num=0;
	u8 loc_Bit_Num=0;
	
	u8 loc_periph = cpy_peripheral_num;
	loc_Register_Num = loc_periph/32;
	loc_periph = cpy_peripheral_num;
	loc_Bit_Num = loc_periph%32;
	
	NVIC->ISPR[loc_Register_Num] |= (1<<loc_Bit_Num);////////////

	status = NVIC_Ok;
	}
	return status;
}



NVIC_Return Clear_Pending(u8 cpy_peripheral_num){
	
	NVIC_Return status = NVIC_NotOk;

	if((cpy_peripheral_num<0) || (cpy_peripheral_num>239)){
		status = NVIC_Invalid_prepheral;
	}else{

	u8 loc_Register_Num=0;
	u8 loc_Bit_Num=0;
	
	u8 loc_periph = cpy_peripheral_num;
	loc_Register_Num = loc_periph/32;
	loc_periph = cpy_peripheral_num;
	loc_Bit_Num = loc_periph%32;
	
	NVIC->ICPR[loc_Register_Num] |= (1<<loc_Bit_Num);////////////

	status = NVIC_Ok;
	}
	return status;
}


NVIC_Return Get_Intrpt_Pend_Status(u8 cpy_peripheral_num ,u8* Status){
	
	NVIC_Return status = NVIC_NotOk;

	if((cpy_peripheral_num<0) || (cpy_peripheral_num>239)){
		status = NVIC_Invalid_prepheral;
	}else{

	u8 loc_Register_Num=0;
	u8 loc_Bit_Num=0;
	
	u8 loc_periph = cpy_peripheral_num;
	loc_Register_Num = loc_periph/32;
	loc_periph = cpy_peripheral_num;
	loc_Bit_Num = loc_periph%32;
	
	*Status=(((NVIC->ISPR[loc_Register_Num])>>loc_Bit_Num)&0x01);

	status = NVIC_Ok;
	}
	return status;	
}



NVIC_Return Get_Intrpt_Active_Status(u8 cpy_peripheral_num ,u8* Status){
	
	NVIC_Return status = NVIC_NotOk;

	if((cpy_peripheral_num<0) || (cpy_peripheral_num>239)){
		status = NVIC_Invalid_prepheral;
	}else{

	u8 loc_Register_Num=0;
	u8 loc_Bit_Num=0;
	
	u8 loc_periph = cpy_peripheral_num;
	loc_Register_Num = loc_periph/32;
	loc_periph = cpy_peripheral_num;
	loc_Bit_Num = loc_periph%32;
	
	*Status=(((NVIC->IABR[loc_Register_Num])>>loc_Bit_Num)&0x01);

	status = NVIC_Ok;
	}
	return status;
}



NVIC_Return Configure_PriorityMood(NVIC_Priority_Mood PriorityMood){
	
	NVIC_Return status = NVIC_NotOk;
//	u32 aircr = *AIRCR;
	*AIRCR = (0xFA050000);
	*AIRCR = (0X05FA0000);

	*AIRCR &= ~(PRIDROUP_MUSK<<8);
	*AIRCR |= (PriorityMood<<8);
	status = NVIC_Ok;

	return status;
}


NVIC_Return Get_PriorityMood(NVIC_Priority_Mood* PriorityMood){
	
	NVIC_Return status = NVIC_NotOk;
	
	*PriorityMood = (((*AIRCR)>>8)&PRIDROUP_MUSK);
	
	status = NVIC_Ok;

	return status;
}



NVIC_Return Set_PriorityLevel(u8 cpy_peripheral_num , u8 priority_level , u8 subgroup_level){
	
	NVIC_Return status = NVIC_NotOk;
	
	NVIC_Priority_Mood loc_check=0;
	
	if((cpy_peripheral_num<0) || (cpy_peripheral_num>239)){
		status = NVIC_Invalid_prepheral;
	}else{
	 
	Get_PriorityMood(&loc_check);
	NVIC->IPR[cpy_peripheral_num] = 0;
	switch(loc_check){
		case PriorityLevels_16_Subgroup_0:
		{
			if((priority_level<0) || (priority_level>15)){
				status = NVIC_Invalid_priorityLevel;
			}else{

				NVIC->IPR[cpy_peripheral_num] |= (priority_level<<4);
				status = NVIC_Ok;
			}
			break;
		}
		case PriorityLevels_8_Subgroup_2:
		{
			if(((priority_level<0) || (priority_level>7))&&((subgroup_level<0) || (subgroup_level>1))){
				status = NVIC_Invalid_priorityLevel;
			}else{
				NVIC->IPR[cpy_peripheral_num] |= (subgroup_level<<4);
				NVIC->IPR[cpy_peripheral_num] &= 0b00011111;
				NVIC->IPR[cpy_peripheral_num] |= (priority_level<<5);
				status = NVIC_Ok;
			}
			break;
		}
		case PriorityLevels_4_Subgroup_4:
		{
			if(((priority_level<0) || (priority_level>3))&&((subgroup_level<0) || (subgroup_level>3))){
				status = NVIC_Invalid_priorityLevel;
			}else{
				NVIC->IPR[cpy_peripheral_num] |= (subgroup_level<<4);
				NVIC->IPR[cpy_peripheral_num] &= 0b00111111;
				NVIC->IPR[cpy_peripheral_num] |= (priority_level<<6);
				status = NVIC_Ok;
			}
			break;
		}
		case PriorityLevels_2_Subgroup_8:
		{
			if(((priority_level<0) || (priority_level>1))&&((subgroup_level<0) || (subgroup_level>7))){
				status = NVIC_Invalid_priorityLevel;
			}else{
				NVIC->IPR[cpy_peripheral_num] |= (subgroup_level<<4);
				NVIC->IPR[cpy_peripheral_num] &= 0b01111111;
				NVIC->IPR[cpy_peripheral_num] |= (priority_level<<7);
				status = NVIC_Ok;
			}
			break;
		}
		case PriorityLevels_0_Subgroup_16:
		{
		if((subgroup_level<0) || (subgroup_level>15)){
			status = NVIC_Invalid_priorityLevel;
		}else{
			NVIC->IPR[cpy_peripheral_num] |= (subgroup_level<<4);
			status = NVIC_Ok;
		}	
			break;
		}
	}
	}
	return status;
}


