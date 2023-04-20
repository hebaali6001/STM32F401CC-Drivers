#include "Sched.h"
#include "Systick.h"












static task_t list[MAX];
extern const taskInfo_t tasks[MAX];

u8 schedFlag=0;


static void tickCbf(void){
	if(schedFlag==0){
		schedFlag=1;
	}else{
		//CPU_Load=100%;
	}
}



Sched_Return sched_Init(){
	
	Sched_Return status = Sched_NotOk;
	u8 idx;
	
	Systick_Set_CallBackFunction(tickCbf);
	Systick_Set_Period_ms(TICK);
	
	for(idx=0;idx<MAX;idx++){
		list[idx].runnable = &tasks[idx];
		list[idx].remain = tasks[idx].startDelay;
	}

	status = Sched_Ok;
	return status;
}




/*
Sched_Return sched_PauseRunnable(runnableHandler ,time ms){
	Sched_Return status = Sched_NotOk;



	status = Sched_Ok;
	return status;
}
 */
 



 static void sched(void){
	
	u8 idx;
	
	for(idx=0 ; idx<MAX ; idx++){
		if(list[idx].runnable){
			if(list[idx].remain == 0){
				list[idx].runnable->cbf();
				list[idx].remain = list[idx].runnable->priod_ms;
			}
			list[idx].remain -= TICK; 	// asebha kda .. wala a5leha else?? hgrb
		}
	}	
}



void sched_Start(){

	Systick_Start();
	while(1){
		if(schedFlag){	//tick
			sched();
			schedFlag=0;
		}
	}
}
