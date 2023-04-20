/*
 * Switch_App.c
 *
 *  Created on: Apr 3, 2023
 *      Author: DELL
 */


#include "Switch.h"
#include "LED.h"


//run every 5 msec
// start delay 5 ms
void runnable_SW1(void){
	static u8 SwitchState;

	get_SwitchValue(SWarr[0],&SwitchState);
	set_LedStatus(leds[3],SwitchState);
}

