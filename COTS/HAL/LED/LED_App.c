/*
 * LED_App.c
 *
 *  Created on: Apr 3, 2023
 *      Author: DELL
 */

#include "LED.h"






//run every 500 msec
// start delay 2000 ms
void runnable_LED1(void){

	static u8 led1_state = 0;

	led1_state ^= 1;
	set_LedStatus(leds[0],led1_state);
}



//run every 1000 msec
// start delay 2000 ms
void runnable_LED2(void){

	static u8 led2_state = 0;

	led2_state ^= 1;
	set_LedStatus(leds[1],led2_state);
}



//run every 2000 msec
// start delay 2000 ms
void runnable_LED3(void){

	static u8 led3_state = 0;

	led3_state ^= 1;
	set_LedStatus(leds[2],led3_state);
}
