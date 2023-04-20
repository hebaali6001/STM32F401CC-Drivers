#ifndef UART_H
#define UART_H
#include "Stdtypes.h"






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





#define UART_SYSTEM_CLOCK							25000000			//HSE

#define  NO_OF_UART_MODULES							2



typedef void(*UARTcbf_t)(void);



typedef enum{
	UART_Ok=0,
	UART_NotOk,
	UART_WrongGonfig,
	UART_Busy,
	UART_Idel,
	
}UART_Return;



typedef enum{
	UART_disable=0,
	UART_enable,
	
}UART_Status;


typedef enum{
	UART1,
	UART2,
	UART6,
	
}UART_module;



 typedef enum{
	
	UARTPort_A=0,
	UARTPort_B,
	UARTPort_C,
	UARTPort_D,
	UARTPort_E,
	//UARTPort_F,
	//UARTPort_G,
	UARTPort_H,
	UARTportsRange,
	
 }UART_Port;
 
 
 
 typedef enum{
	
	UART_Pin_0 = 0,
	UART_Pin_1,
	UART_Pin_2,
	UART_Pin_3,
	UART_Pin_4,
	UART_Pin_5,
	UART_Pin_6,
	UART_Pin_7,
	UART_Pin_8,
	UART_Pin_9,
	UART_Pin_10,
	UART_Pin_11,
	UART_Pin_12,
	UART_Pin_13,
	UART_Pin_14,
	UART_Pin_15,
	UART_pinsRnge,
	  
 }UART_Pin;


typedef enum{
	 
	UART_AF_0 =0x00, 	//system = 0x00,
	UART_AF_1, 			//TIM_1_2,
	UART_AF_2, 			//TIM_3_4_5, 
	UART_AF_3, 			//TIM_9_10_11,
	UART_AF_4, 			//I2C_1_2_3,
	UART_AF_5, 			//SPI_1_2_4,
	UART_AF_6, 			//SPI_3,
	UART_AF_7, 			//USART_1_2,
	UART_AF_8, 			//USART_6,
	UART_AF_9, 			//I2C_2_3,
	UART_AF_10, 		// OTG_FS,
	UART_AF_11, 		//RESERVED, 
	UART_AF_12, 		//SDIO,
	UART_AF_13, 		//RESERVED1,
	UART_AF_14, 		//RESERVED2,
	UART_AF_15, 		//EVENTOUT,
	
 }UART_AF;

typedef enum {
	 
	  UART_Low_Speed = 0b00,
	  UART_Medium_Speed,
	  UART_High_Speed,
	  UART_Very_High_Speed,
	
 }UART_speed;
 

 
 
typedef enum{
	StopBit_1 	= 0b00,
	StopBit_0_5 = 0b01,
	StopBit_2 	= 0b10,
	StopBit_1_5 = 0b11,

}UART_StopBit;



typedef enum{
	UART_2400 =2400,
	UART_9600=9600,
	UART_19200=19200,
	UART_57600=57600,
	UART_115200=115200,
	UART_460800=460800,
	UART_896000=896000,
}UART_BaudRate;



typedef enum{
	Date_8_Bit=0,
	Date_9_Bit,
	
}UART_dataLength;


typedef enum{
	overSample_16=0,
	overSample_8,
	
}UART_overSample;



typedef struct{
	
	UART_Port 	port;
	UART_Pin 	pin; 
	UART_speed 	speed;
	UART_AF 	af;							//UART_1, UART_2 or UART_6
	u8 			GPIOPin_mode;
	char * 		pin_name;
	
 }UART_Config;
 
	

typedef struct{
	
	UART_Config TX;
	UART_Config RX;
	
 }UART_MODULE_Config;
 
 
 
extern UART_MODULE_Config modules[NO_OF_UART_MODULES];
 
 
 
 
UART_Return UART_Init(UART_MODULE_Config* MDs);
 

UART_Return UART_ModuleEnable(UART_module module, UART_Status status);




UART_Return UART_enableTransmiter(UART_module module, UART_Status status);						//Enable Transmitter

UART_Return UART_enableReciever(UART_module module, UART_Status status);						//Enable Reciever




UART_Return UART_enableTransmite_Interrupt(UART_module module, UART_Status status);				//Enable Transmite Interrupt

UART_Return UART_enableReciever_Interrupt(UART_module module, UART_Status status);				//Enable Recieve	Interrupt




UART_Return UART_setDataLength(UART_module module , UART_dataLength dataLength);				//Data Length

UART_Return UART_enableParityBit(UART_module module , UART_Status status);						//Parity Bit

UART_Return UART_setStopBit(UART_module module , UART_StopBit StopBit);							//Stop Bit

UART_Return UART_setBaudRate(UART_module module , UART_BaudRate BaudRate ,UART_overSample sample);						//BaudRate




UART_Return UART_sendBuffer_Async_ZeroCpy(UART_module module, u8* Buffer, u8 size);

UART_Return UART_recieveBuffer_Async(UART_module module, u8* Buffer, u8 size);


UART_Return UART_sendBuffer_Sync(UART_module module, u8* Buffer, u8 size);

UART_Return UART_recieveBuffer_Sync(UART_module module, u8* Buffer, u8 size);

UART_Return UART_setCallBackFunc(UART_module module , UARTcbf_t funcTX , UARTcbf_t funcRX);









#endif /* UART_H */
