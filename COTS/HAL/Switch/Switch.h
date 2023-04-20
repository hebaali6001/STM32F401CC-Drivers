#include "Stdtypes.h"

#ifndef SWITCH_H
#define SWITCH_H
 
 
#define NO_OF_SWITCHS		1
 
 
 
  
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
 
 
  
 
#define NO_OF_SWITCHS 		1
 
 
 
 
  typedef enum{
	 
	Switch_Ok=0,
	Switch_NotOk,
	 
 }Switch_Return;
 
 
 typedef enum {
	 
	 SW__NOTPRESSED,
	 SW__PRESSED,
	 
 }Switch_value;
 
 
 
 
 typedef enum{
	
	SW_Port_A=0,
	SW_Port_B,
	SW_Port_C,
	SW_Port_D,
	SW_Port_E,
	//SW_Port_F,
	//SW_Port_G,
	SW_Port_H,
	SW_portsRange,
	
 }Switch_Port;
 
 
 
 typedef enum{
	
	 SW_Pin_0 = 0,
	 SW_Pin_1,
	 SW_Pin_2,
	 SW_Pin_3,
	 SW_Pin_4,
	 SW_Pin_5,
	 SW_Pin_6,
	 SW_Pin_7,
	 SW_Pin_8,
	 SW_Pin_9,
	 SW_Pin_10,
	 SW_Pin_11,
	 SW_Pin_12,
	 SW_Pin_13,
	 SW_Pin_14,
	 SW_Pin_15,
	 SW_pinsRnge,
	  
 }Switch_Pin;
 
 
  typedef enum {
	
	 Pull_down=0,
	 Pull_up,
	
 }Switch_mode;
 
  typedef struct{
	
	Switch_Port port;
	Switch_Pin pin; 
	Switch_mode SwMode;
	u8 GPIOPin_mode;
	char* Switch_name;
	
 }Switch_Config;
 
 
 
 extern Switch_Config SWarr[NO_OF_SWITCHS];
 

 Switch_Return init_Switch(Switch_Config* Switcharr);
 
 Switch_Return get_SwitchValue(Switch_Config Switch, Switch_value* status);
 



 extern void runnable_SW1(void);

 #endif /*SWITCH_H*/
