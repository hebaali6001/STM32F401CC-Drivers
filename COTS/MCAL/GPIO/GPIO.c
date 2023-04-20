 
#include "Stdtypes.h"
#include "GPIO.h"
#include "GPIO_private.h"

 
 
#define MODER_MASK 							((loc_MBuffer>>5)& 0x03)
#define OTYPER_MASK 						((loc_MBuffer>>4)& 0x01)
#define PUPDR_MASK 							(loc_MBuffer & 0x03)
#define NULL ((void*)0)
 
 
 
 GPIO_Return GPIO_initPin(GPIO_PinConfig pinCfg){
	
	GPIO_t* loc_GPIOPtr = NULL;
	u8 loc_MBuffer = 0x00;
	GPIO_Return status = GPIO_NotOk;
	
	
	if(pinCfg.port >= portsRange){
			status = GPio_WrongPort;
	}
	if(pinCfg.pin >= pinsRnge){
			status = GPio_WrongPin;
	}
	if(!(((pinCfg.Pin_mode)>>7)&0x01)){
			status = GPio_WrongConfig;
	}
	
	switch (pinCfg.port){

				case Port_A:
				{
					loc_GPIOPtr = GPIO_A;
					break;
				}
				case Port_B:
				{
					loc_GPIOPtr = GPIO_B;
					break;
				}
				case Port_C:
				{
					loc_GPIOPtr = GPIO_C;
					break;
				}
				case Port_D:
				{
					loc_GPIOPtr = GPIO_D;
					break;
				}
				case Port_E:
				{
					loc_GPIOPtr = GPIO_E;
					break;
				}
				case Port_H:
				{
					loc_GPIOPtr = GP_h;
					break;
				}
			}
	
	loc_MBuffer = pinCfg.Pin_mode;
	loc_GPIOPtr->MODER |= MODER_MASK<<((pinCfg.pin)*2);
				
	loc_MBuffer = pinCfg.Pin_mode;
	loc_GPIOPtr->OTYPER |= OTYPER_MASK<<(pinCfg.pin);
	
	loc_MBuffer = pinCfg.Pin_mode;
	loc_GPIOPtr->OSPEEDR |= (pinCfg.speed)<<((pinCfg.pin)*2);
	
	loc_MBuffer = pinCfg.Pin_mode;
	loc_GPIOPtr->PUPDR |= PUPDR_MASK<<((pinCfg.pin)*2);
	
	status = GPIO_Ok;
	
	return status;
 }
 
 GPIO_Return GPIO_setPortValue(GPIO_Port port, GPIO_PinValue value){
	
	GPIO_t* loc_GPIOPtr = NULL;
	GPIO_Return status = GPIO_NotOk;
	
	if(port >= portsRange){
		status = GPio_WrongPort;
	}


	switch (port){

				case Port_A:
				{
					loc_GPIOPtr = GPIO_A;
					break;
				}
				case Port_B:
				{
					loc_GPIOPtr = GPIO_B;
					break;
				}
				case Port_C:
				{
					loc_GPIOPtr = GPIO_C;
					break;
				}
				case Port_D:
				{
					loc_GPIOPtr = GPIO_D;
					break;
				}
				case Port_E:
				{
					loc_GPIOPtr = GPIO_E;
					break;
				}
				case Port_H:
				{
					loc_GPIOPtr = GP_h;
					break;
				}
			}
		
		if(value==Pin_High){
			loc_GPIOPtr->BSRR |= 0x0000FFFF;
		}else{
			loc_GPIOPtr->BSRR |= 0xFFFF0000;
		}
		
	status = GPIO_Ok;
	
	return status;	
	 
 }
 
 GPIO_Return GPIO_writePinValue(GPIO_Port port ,GPIO_Pin pin ,GPIO_PinValue value){
	
	GPIO_t* loc_GPIOPtr = NULL;
	GPIO_Return status = GPIO_NotOk;
	
	if(port >= portsRange){
		status = GPio_WrongPort;
	}
	if(pin >= pinsRnge){
		status = GPio_WrongPin;
	}

	switch (port){

				case Port_A:
				{
					loc_GPIOPtr = GPIO_A;
					break;
				}
				case Port_B:
				{
					loc_GPIOPtr = GPIO_B;
					break;
				}
				case Port_C:
				{
					loc_GPIOPtr = GPIO_C;
					break;
				}
				case Port_D:
				{
					loc_GPIOPtr = GPIO_D;
					break;
				}
				case Port_E:
				{
					loc_GPIOPtr = GPIO_E;
					break;
				}
				case Port_H:
				{
					loc_GPIOPtr = GP_h;
					break;
				}
			}
		
		
		if(value==Pin_High){
			loc_GPIOPtr->BSRR |= (1<<pin);
		}else{
			loc_GPIOPtr->BSRR |= (1<<(pin+16));
		}
		
	status = GPIO_Ok;
	
	return status; 
	 
 }
 
 GPIO_Return GPIO_getPinValue(GPIO_Port port ,GPIO_Pin pin ,GPIO_PinValue* value){
	
	GPIO_t* loc_GPIOPtr = NULL;
	GPIO_Return status = GPIO_NotOk;
	
	if(port >= portsRange){
		status = GPio_WrongPort;
	}
	if(pin >= pinsRnge){
		status = GPio_WrongPin;
	}

	switch (port){
			
			case Port_A:
			{
				loc_GPIOPtr = GPIO_A;
				break;
			}
			case Port_B:
			{
				loc_GPIOPtr = GPIO_B;
				break;
			}
			case Port_C:
			{
				loc_GPIOPtr = GPIO_C;
				break;
			}
			case Port_D:
			{
				loc_GPIOPtr = GPIO_D;
				break;
			}
			case Port_E:
			{
				loc_GPIOPtr = GPIO_E;
				break;
			}
			case Port_H:
			{
				loc_GPIOPtr = GP_h;
				break;
			}	
		} 
		
		if(((loc_GPIOPtr->IDR)>>pin) &0x01){
			*value = Pin_High;
		}else{
			*value = Pin_Low;
		}
	
	status = GPIO_Ok;
	
	return status; 
 }
 
 GPIO_Return GPIO_select_AF(GPIO_Port port ,GPIO_Pin pin ,GPIO_AF AF){


	GPIO_t* loc_GPIOPtr = NULL;
	GPIO_Return status = GPIO_NotOk;
	
	if(port >= portsRange){
		status = GPio_WrongPort;
	}
	if(pin >= pinsRnge){
		status = GPio_WrongPin;
	}
	
	switch (port){
			
			case Port_A:
			{
				loc_GPIOPtr = GPIO_A;
				break;
			}
			case Port_B:
			{
				loc_GPIOPtr = GPIO_B;
				break;
			}
			case Port_C:
			{
				loc_GPIOPtr = GPIO_C;
				break;
			}
			case Port_D:
			{
				loc_GPIOPtr = GPIO_D;
				break;
			}
			case Port_E:
			{
				loc_GPIOPtr = GPIO_E;
				break;
			}
			case Port_H:
			{
				loc_GPIOPtr = GP_h;
				break;
			}	
		}
	//check if the pin is configured as alternate function pin 
	if((((loc_GPIOPtr->MODER)>>(pin*2))&0x03)!= 2){
		status = GPio_WrongConfig;
	}
	
	if(pin<8){
		loc_GPIOPtr->AFRL &=~(0x7<<(pin-8*4));
		loc_GPIOPtr->AFRL |= (AF<<(pin-8*4));
	}else{
		loc_GPIOPtr->AFRH &= ~(0x7<<((pin-8)*4));
		loc_GPIOPtr->AFRH |= (AF<<((pin-8)*4));
	}
	 
	 
	status = GPIO_Ok;
	
	return status;
 }
 
 GPIO_LockedStatus GPIO_lockPortConfig(GPIO_Port port, u16 LockedPinsPattern){
	 
	GPIO_t* loc_GPIOPtr = NULL;
	GPIO_LockedStatus status = GPIO_PortUnLocked;
	
	if(port >= portsRange){
		status = GPio_WrongPort;
	}


	switch (port){
			
			case Port_A:
			{
				loc_GPIOPtr = GPIO_A;
				break;
			}
			case Port_B:
			{
				loc_GPIOPtr = GPIO_B;
				break;
			}
			case Port_C:
			{
				loc_GPIOPtr = GPIO_C;
				break;
			}
			case Port_D:
			{
				loc_GPIOPtr = GPIO_D;
				break;
			}
			case Port_E:
			{
				loc_GPIOPtr = GPIO_E;
				break;
			}
			case Port_H:
			{
				loc_GPIOPtr = GP_h;
				break;
			}	
		}
	
	loc_GPIOPtr->LCKR |= LockedPinsPattern;
	
	loc_GPIOPtr->LCKR |= (1<<16);
	loc_GPIOPtr->LCKR &= ~(1<<16);
	loc_GPIOPtr->LCKR |= (1<<16);
	u32 dummy = loc_GPIOPtr->LCKR;
	
	if((loc_GPIOPtr->LCKR>>16) & 0x01){
		status = GPIO_PortLocked;
	}else{
		status = GPIO_PortUnLocked;
	}
	
	return status;
 }
 
 
 
