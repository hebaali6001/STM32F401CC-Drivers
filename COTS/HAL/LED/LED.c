#include "LED.h"
#include "GPIO.h"

 





 LED_Return init_Led(LED_Config* LEDS){
	
	LED_Return status = LED_NotOk;
	GPIO_PinConfig cfg;
	u8 i;
	
	for(i=0 ; i<NO_OF_LEDS ; i++){
		
		cfg.port = LEDS[i].port;
		cfg.pin = LEDS[i].pin;
		cfg.speed = LEDS[i].speed;
		cfg.Pin_mode = LEDS[i].GPIOPin_mode;
		GPIO_initPin(cfg);
	}
	
	status = LED_Ok;
	return status;
	
 }
 
 LED_Return set_LedStatus(LED_Config led , LED_status state){
 	
	LED_Return status = LED_NotOk;
	GPIO_writePinValue(led.port , led.pin ,(led.LedMode^state));
	
 	status = LED_Ok;
	return status;
 }
 
 
 
 
 
