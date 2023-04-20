#ifndef SCHED_CFG_H
#define SCHED_CFG_H
 
#include "Sched.h"





#include "LED.h"
#include "Switch.h"








const taskInfo_t tasks[]={
	[1]={
		.name = "LED1",
		.cbf = runnable_LED1,
		.priod_ms = 500,
		.startDelay = 2000,
	},
	[2]={
		.name = "LED3",
		.cbf = runnable_LED2,
		.priod_ms = 1000,
		.startDelay = 2000,
		},
	[3]={
		.name = "LED3",
		.cbf = runnable_LED3,
		.priod_ms = 2000,
		.startDelay = 2000,
		},
	[0]={
		.name = "SW1",
		.cbf = runnable_SW1,
		.priod_ms = 5,
		.startDelay = 5,
		}
};








#endif /* SCHED_CFG_H */
