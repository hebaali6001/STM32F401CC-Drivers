 
#include "LED.h"
 
 


 /*
 LED_Config leds[NO_OF_LEDS]={

	 {Port_A , Pin_0 , Low_Speed , Active_High , GP_OUTPUT_PP , "LED1"},
	 {Port_A , Pin_13 , Low_Speed , Active_High , GP_OUTPUT_PP , "LED2"}
 };

 */


 
LED_Config leds[NO_OF_LEDS] = {
	{LEDPort_A , LED_Pin_9 , LED_Low_Speed , LED_Active_High , GP_OUTPUT_PP , "LED1"},
	{LEDPort_A , LED_Pin_10 , LED_Low_Speed , LED_Active_High , GP_OUTPUT_PP , "LED2"},
	{LEDPort_A , LED_Pin_11 , LED_Low_Speed , LED_Active_High , GP_OUTPUT_PP , "LED3"},
	{LEDPort_A , LED_Pin_12 , LED_Low_Speed , LED_Active_High , GP_OUTPUT_PP , "LED4"}
	};


