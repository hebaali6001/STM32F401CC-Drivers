#include "Stdtypes.h"
#ifndef LED_H
#define LED_H


 
 
 
 
 
 
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
 
 
 
#define  NO_OF_LEDS			4
 
 
 typedef enum{
	 
	LED_Ok=0,
	LED_NotOk,
	 
 }LED_Return;
 
 
 
 typedef enum {

	LED_OFF=0,	///////////////////////
	LED_ON,

	 
 }LED_status;
 
  
 
 
 typedef enum{
	
	LEDPort_A=0,
	LEDPort_B,
	LEDPort_C,
	LEDPort_D,
	LEDPort_E,
	//LEDPort_F,
	//LEDPort_G,
	LEDPort_H,
	LEDportsRange,
	
 }LED_Port;
 
 
 
 typedef enum{
	
	LED_Pin_0 = 0,
	LED_Pin_1,
	LED_Pin_2,
	LED_Pin_3,
	LED_Pin_4,
	LED_Pin_5,
	LED_Pin_6,
	LED_Pin_7,
	LED_Pin_8,
	LED_Pin_9,
	LED_Pin_10,
	LED_Pin_11,
	LED_Pin_12,
	LED_Pin_13,
	LED_Pin_14,
	LED_Pin_15,
	LED_pinsRnge,
	  
 }LED_Pin;
 
 
 
  typedef enum {
	 
	  LED_Low_Speed = 0b00,
	  LED_Medium_Speed,
	  LED_High_Speed,
	  LED_Very_High_Speed,
	
 }LED_speed;
 


 typedef enum {
	
	LED_Active_High=0,
	LED_Active_Low,
	
 }LED_mode;
 
 
 typedef struct{
	
	LED_Port port;
	LED_Pin pin; 
	LED_speed speed;
	LED_mode LedMode;
	u8 GPIOPin_mode;
	char* LED_name;
	
 }LED_Config;
 
 


 extern LED_Config leds[NO_OF_LEDS];



 

 LED_Return init_Led(LED_Config* LEDS);
 
 LED_Return set_LedStatus(LED_Config led , LED_status state);
 
 
 



 extern void runnable_LED1(void);
 extern void runnable_LED2(void);
 extern void runnable_LED3(void);






 #endif /*LED_H*/
