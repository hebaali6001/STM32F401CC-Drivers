#include "Stdtypes.h"
#ifndef SCHED_H
#define SCHED_H

#include "LED.h"

#define TICK	5
#define MAX		4





typedef void(*runnable_cbf_t)(void);




typedef enum{

	Sched_Ok=0,
	Sched_NotOk,
	Sched_WrongConfig,

}Sched_Return;



typedef struct{

	char* 			name;
	runnable_cbf_t 	cbf;
	u32				priod_ms;
	u32 			startDelay;

}taskInfo_t;



typedef struct{

	const taskInfo_t* runnable;
	u32 remain;

}task_t;














Sched_Return sched_Init(void);

void sched_Start(void);

//void sched_AddRunnable(runnable_t* runnable); 				//shoud return runnableHandler/and take runnable_T struct;

//Sched_Return sched_PauseRunnable(runnableHandler ,time ms);










#endif /*SCHED_H*/
