#include "Stdtypes.h"

#ifndef GPIO_H
#define GPIO_H
 
 
 
#define GP_OUTPUT_PP								0b10100000
#define GP_OUTPUT_PP_PULLUP				            0b10100001
#define GPO_OUTPUT_PP_PULLDOWN				        0b10100010
													  
#define GP_OUTPUT_OD			                    0b10110000
#define GP_OUTPUT_OD_PULLUP				            0b10110001
#define GP_OUTPUT_OD_PULLDOWN			            0b10110010
													  
#define ALTERNATE_FUNCTION_PP			            0b11000000
#define ALTERNATE_FUNCTION_PP_PULLUP				0b11000001
#define ALTERNATE_FUNCTION_PP_PULLDOWN				0b11000010
													  
#define ALTERNATE_FUNCTION_OD				        0b11010000
#define ALTERNATE_FUNCTION_OD_PULLUP				0b11010001
#define ALTERNATE_FUNCTION_OD_PULLDOWN			    0b11010010
													  
#define GP_INPUT_FLOATING			                0b10000000
#define GP_INPUT_PullUp			                    0b10000001
#define GP_INPUT_PULLDOWN			                0b10000010
													  
#define Input_Output_Analog                         0b11100000
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 typedef enum{
		
	GPIO_Ok=0,
	GPIO_NotOk, 
	GPio_WrongConfig,
	GPio_WrongPort,
	GPio_WrongPin,
	
 }GPIO_Return;
 
 
 typedef enum{

	GPIO_PortUnLocked,
	GPIO_PortLocked,
	
 }GPIO_LockedStatus;
 
 typedef enum{

	Port_A=0,
	Port_B,
	Port_C,
	Port_D,
	Port_E,
	//Port_F,
	//Port_G,
	Port_H,
	portsRange,

 }GPIO_Port;
 
 typedef enum{
	
	Pin_0 = 0,
	Pin_1,
	Pin_2,
	Pin_3,
	Pin_4,
	Pin_5,
	Pin_6,
	Pin_7,
	Pin_8,
	Pin_9,
	Pin_10,
	Pin_11,
	Pin_12,
	Pin_13,
	Pin_14,
	Pin_15,
	pinsRnge,
	  
 }GPIO_Pin;


typedef enum{
	 
	Pin_Low = 0, 
	Pin_High, 
	 
 }GPIO_PinValue;  
 
 
 
 typedef enum{
	 
	AF_0 =0x00, 	//system = 0x00,
	AF_1, 			//TIM_1_2,
	AF_2, 			//TIM_3_4_5, 
	AF_3, 			//TIM_9_10_11,
	AF_4, 			//I2C_1_2_3,
	AF_5, 			//SPI_1_2_4,
	AF_6, 			//SPI_3,
	AF_7, 			//USART_1_2,
	AF_8, 			//USART_6,
	AF_9, 			//I2C_2_3,
	AF_10, 			// OTG_FS,
	AF_11, 			//RESERVED, 
	AF_12, 			//SDIO,
	AF_13, 			//RESERVED1,
	AF_14, 			//RESERVED2,
	AF_15, 			//EVENTOUT,
	
 }GPIO_AF; 
 
 
 
 typedef enum{
	 
	Low_Speed = 0b00,
	Medium_Speed,
	High_Speed,
	Very_High_Speed,
	 
 }GPIO_speed;
 
 
 
 typedef struct{
	
	GPIO_Port port;
	GPIO_Pin pin;
	GPIO_speed speed;
	u8 Pin_mode;
	 
 }GPIO_PinConfig;
 
 
 
 
 
 GPIO_Return GPIO_initPin(GPIO_PinConfig pinCfg);
 
 GPIO_Return GPIO_writePortValue(GPIO_Port port , u32 Value);
 
 GPIO_Return GPIO_writePinValue(GPIO_Port port ,GPIO_Pin pin ,GPIO_PinValue value);
 
 GPIO_Return GPIO_getPinValue(GPIO_Port port ,GPIO_Pin pin ,GPIO_PinValue* value);
 
 GPIO_Return GPIO_select_AF(GPIO_Port port ,GPIO_Pin pin ,GPIO_AF AF);
 
 GPIO_LockedStatus GPIO_lockPortConfig(GPIO_Port port, u16 LockedPinsPattern);
 
 
 
 
 
 
 #endif /*GPIO_H*/
