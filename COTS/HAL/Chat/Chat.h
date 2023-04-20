#ifndef CHAT_H
#define CHAT_H


#include  "UART.h"
#include "Stdtypes.h"



/************************************** GPIO_PIN_MODE *********************************************/

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

#define Input_Output_Analog							0b11100000

/**************************************************************************************************/



#define 	UART_MODULES_NUM		1	
#define 	SPI_MODULES_NUM			1
#define 	I2C_MODULES_NUM			1



/**************************** ALTERNATE_FUNCTION **************************************************/

#define	Chat_AF_I2C_2_3				9
#define	Chat_AF_I2C_1_2_3 			4
#define	Chat_AF_SPI_1_2_4			5
#define	Chat_AF_SPI_3				6
#define	Chat_AF_USART_1_2			7
#define	Chat_AF_USART_6				8

/**************************************************************************************************/








typedef enum{
	Chat_Ok=0,
	Chat_NotOk,
	Chat_WrongGonfig,
	
}Chat_Return;



typedef enum{
	chat_UART1,
	chat_UART2,
	chat_UART6,

	chat_I2C1,
	chat_I2C2,
	chat_I2C3,

	chat_SPI1,
	chat_SPI2,
	chat_SPI3,
	chat_SPI4,
	
}Chat_module;




typedef enum{
	Chat_disable=0,
	Chat_enable,
	
}Chat_Status;

 typedef enum{
	
	Chat_Port_A=0,
	Chat_Port_B,
	Chat_Port_C,
	Chat_Port_D,
	Chat_Port_E,
	//Chat_Port_F,
	//Chat_Port_G,
	Chat_Port_H,
	Chat_portsRange,
	
 }Chat_Port;
 
 
 
 typedef enum{
	
	Chat_Pin_0 = 0,
	Chat_Pin_1,
	Chat_Pin_2,
	Chat_Pin_3,
	Chat_Pin_4,
	Chat_Pin_5,
	Chat_Pin_6,
	Chat_Pin_7,
	Chat_Pin_8,
	Chat_Pin_9,
	Chat_Pin_10,
	Chat_Pin_11,
	Chat_Pin_12,
	Chat_Pin_13,
	Chat_Pin_14,
	Chat_Pin_15,
	Chat_pinsRnge,
	  
 }Chat_Pin;



typedef enum {
	 
	Chat_Low_Speed = 0b00,
	Chat_Medium_Speed,
	Chat_High_Speed,
	Chat_Very_High_Speed,
	
 }Chat_speed;
 


 typedef enum {
	
	Chat_Active_High=0,	
	Chat_Active_Low,
	
 }Chat_mode;
 
/******************************************************** UART_CONFIGURATION *************************************************************/ 
 
typedef enum{
	Chat_StopBit_1 	= 0b00,
	Chat_StopBit_0_5 = 0b01,
	Chat_StopBit_2 	= 0b10,
	Chat_StopBit_1_5 = 0b11,

}ChatUART_StopBit;



typedef enum{
	Chat_2400 =2400,
	Chat_9600=9600,
	Chat_19200=19200,
	Chat_57600=57600,
	Chat_115200=115200,
	Chat_460800=460800,
	Chat_896000=896000,
}ChatUART_BaudRate;



typedef enum{
	Chat_Date_8_Bit=0,
	Chat_Date_9_Bit,
	
}ChatUART_dataLength;


typedef enum{
	Chat_overSample_16=0,
	Chat_overSample_8,
	
}ChatUART_overSample;




typedef struct{
	
	Chat_module module;
	
	Chat_Port 	TXport;
	Chat_Pin 	TXpin;
	Chat_speed 	TXspeed;
	u8 			af;
	u8		 	GPIO_TXmode;
	
	Chat_Pin 	RXpin;
	Chat_Port 	RXport;
	Chat_speed 	RXspeed;
	u8		 	af;
	u8 			GPIO_RXmode;
	
	ChatUART_StopBit 	StopBit;
	ChatUART_BaudRate 	BaudRate;
	Chat_Status			ParityBit;
	ChatUART_dataLength	dataLength;
	ChatUART_overSample	overSample;
	
}UART_ChatConfig;



typedef struct{
	

}SPI_ChatConfig;


typedef struct{
	

}I2C_ChatConfig;






extern UART_ChatConfig UARTmodules[UART_MODULES_NUM];
extern SPI_ChatConfig SPImodules[SPI_MODULES_NUM];
extern I2C_ChatConfig I2Cmodules[I2C_MODULES_NUM];




/*****************************************************************************************************************************************/




/******************************************************** SPI_CONFIGURATION *************************************************************/ 


/*****************************************************************************************************************************************/







/******************************************************** I2C_CONFIGURATION *************************************************************/ 


/*****************************************************************************************************************************************/




Chat_Return chat_Init_UART(UART_ChatConfig* modules);

//void chatI_Init_SPI(SPI_ChatConfig* modules);  	/* NOT IMPLEMENTED YET */

//void chat_Init_I2C(I2C_ChatConfig* modules);		/* NOT IMPLEMENTED YET */

Chat_Return chat_send_Async(u8* buffer , u8 size , Chat_module module);

Chat_Return chat_Recieve_Async(u8* buffer , u8 size , Chat_module module);



#endif /*CHAT_H*/