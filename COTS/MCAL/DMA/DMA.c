#include "DMA.h"
#include "DMA_prv.h"





#define NULL							((void*)0)

#define STREAM_SHIFT					24
#define	EN_SHIFT						0
#define CHANNEL_SHIFT 					25
#define MUSK							0b111
#define PRIORITY_SH						16
#define CIRCULARM_SHIFT					8
#define DIRECTION_SH					6
#define TRANS_COM_INTRPT				4
#define HALF_COM_INTRPT					3
#define TRANS_ERR_INTRPT				2
#define	PERIPH_DATASIZE					11
#define MEMOEY_DATASIZE					13
#define	PERIPH_AUTOINCRMNT				9
#define MEMOEY_AUTOINCRMNT				10




static DMA_Cbf_t DMA1_Notify0;
static DMA_Cbf_t DMA1_Notify1;
static DMA_Cbf_t DMA1_Notify2;
static DMA_Cbf_t DMA1_Notify3;
static DMA_Cbf_t DMA1_Notify4;
static DMA_Cbf_t DMA1_Notify5;
static DMA_Cbf_t DMA1_Notify6;

static DMA_Cbf_t DMA2_Notify0;
static DMA_Cbf_t DMA2_Notify1;
static DMA_Cbf_t DMA2_Notify2;
static DMA_Cbf_t DMA2_Notify3;
static DMA_Cbf_t DMA2_Notify4;










DMA_Return DMA_ConfigChannel(DMA_Config* config){
	DMA_Return state = DMA_NotOK;
	DMA_t* loc_DmaPtr = NULL;
	u8 idx = 0;
	
	
	for(idx=0 ; idx<DMA_CHANNELS ; idx++){
		
		if((config[idx].Module) == DMA_1){
			loc_DmaPtr = P_DMA1;
		}else if((config[idx].Module) == DMA_2){
			loc_DmaPtr = P_DMA2;
		}else{
			state = DMA_WrongConfig;
		}


		/* channel set */
		*((&(loc_DmaPtr->SxCR))+((STREAM_SHIFT*(config[idx].Stream_no))/4)) &= ~(0b111<<CHANNEL_SHIFT);
		*((&(loc_DmaPtr->SxCR))+((STREAM_SHIFT*(config[idx].Stream_no))/4)) |= (config[idx].Channel<<CHANNEL_SHIFT);

		/* Priority set */
		*((&(loc_DmaPtr->SxCR))+((STREAM_SHIFT*(config[idx].Stream_no))/4)) &= ~(0b11<<PRIORITY_SH);
		*((&(loc_DmaPtr->SxCR))+((STREAM_SHIFT*(config[idx].Stream_no))/4)) |= (config[idx].Priority<<PRIORITY_SH);


		/* CircularMood enable status set*/
		*((&(loc_DmaPtr->SxCR))+((STREAM_SHIFT*(config[idx].Stream_no))/4)) &= ~(1<<CIRCULARM_SHIFT);
		*((&(loc_DmaPtr->SxCR))+((STREAM_SHIFT*(config[idx].Stream_no))/4)) |= (config[idx].Circular_Mode<<CIRCULARM_SHIFT);


		/* Data Direction set*/
		*((&(loc_DmaPtr->SxCR))+((STREAM_SHIFT*(config[idx].Stream_no))/4)) &= ~(0b11<<DIRECTION_SH);
		*((&(loc_DmaPtr->SxCR))+((STREAM_SHIFT*(config[idx].Stream_no))/4)) |= (config[idx].Direction<<DIRECTION_SH);



		/* Transefer Complete Interrupt set*/
		*((&(loc_DmaPtr->SxCR))+((STREAM_SHIFT*(config[idx].Stream_no))/4)) &= ~(1<<TRANS_COM_INTRPT);
		*((&(loc_DmaPtr->SxCR))+((STREAM_SHIFT*(config[idx].Stream_no))/4)) |= (config[idx].Transfer_Complete_Intrupt<<TRANS_COM_INTRPT);



		/* Half Transefer Complete Interrupt set*/
		*((&(loc_DmaPtr->SxCR))+((STREAM_SHIFT*(config[idx].Stream_no))/4)) &= ~(1<<HALF_COM_INTRPT);
		*((&(loc_DmaPtr->SxCR))+((STREAM_SHIFT*(config[idx].Stream_no))/4)) |= (config[idx].Half_Transfer_Intrupt<<HALF_COM_INTRPT);


		/* Transefer Error Interrupt set*/
		*((&(loc_DmaPtr->SxCR))+((STREAM_SHIFT*(config[idx].Stream_no))/4)) &= ~(1<<TRANS_ERR_INTRPT);
		*((&(loc_DmaPtr->SxCR))+((STREAM_SHIFT*(config[idx].Stream_no))/4)) |= (config[idx].Transfer_Error_Intrupt<<TRANS_ERR_INTRPT);



		/* Number of data set*/
		*((&(loc_DmaPtr->SxNDTR))+((STREAM_SHIFT*(config[idx].Stream_no))/4)) = config[idx].Count;



		/* Periphera Data size set*/
		*((&(loc_DmaPtr->SxCR))+((STREAM_SHIFT*(config[idx].Stream_no))/4)) &= ~(0b11<<PERIPH_DATASIZE);
		*((&(loc_DmaPtr->SxCR))+((STREAM_SHIFT*(config[idx].Stream_no))/4)) |= (config[idx].Periephral_DataSize<<PERIPH_DATASIZE);



		/* Memory Data size set*/
		*((&(loc_DmaPtr->SxCR))+((STREAM_SHIFT*(config[idx].Stream_no))/4)) &= ~(0b11<<MEMOEY_DATASIZE);
		*((&(loc_DmaPtr->SxCR))+((STREAM_SHIFT*(config[idx].Stream_no))/4)) |= (config[idx].Memoey_DataSize<<MEMOEY_DATASIZE);



		/* Periphera Auto Increament set*/
		*((&(loc_DmaPtr->SxCR))+((STREAM_SHIFT*(config[idx].Stream_no))/4)) &= ~(1<<PERIPH_AUTOINCRMNT);
		*((&(loc_DmaPtr->SxCR))+((STREAM_SHIFT*(config[idx].Stream_no))/4)) |= (config[idx].Periephral_Auto_Increament<<PERIPH_AUTOINCRMNT);



		/* Periphera Auto Increament set*/
		*((&(loc_DmaPtr->SxCR))+((STREAM_SHIFT*(config[idx].Stream_no))/4)) &= ~(1<<MEMOEY_AUTOINCRMNT);
		*((&(loc_DmaPtr->SxCR))+((STREAM_SHIFT*(config[idx].Stream_no))/4)) |= (config[idx].Memoey_Auto_Increament<<MEMOEY_AUTOINCRMNT);



		/* Periphera Address set*/
		*((&(loc_DmaPtr->SxPAR))+((STREAM_SHIFT*(config[idx].Stream_no))/4)) = (config[idx].Periephral_Address);



		/* Memoery_0 Address set*/
		*((&(loc_DmaPtr->SxM0AR))+((STREAM_SHIFT*(config[idx].Stream_no))/4)) = (config[idx].Memoey_Address_0);



		/* Memoery_1 Address set*/
		if(config[idx].Circular_Mode){
		*((&(loc_DmaPtr->SxM1AR))+((STREAM_SHIFT*(config[idx].Stream_no))/4)) = (config[idx].Memoey_Address_1);

		}
	}

	state = DMA_Ok;
	return state;
}








DMA_Return DMA_EnableChannel(DMA_Config Channel, DMA_Status Status){
	DMA_Return state = DMA_NotOK;
	
	if(Channel.Module == DMA_1){
		
		*((&(P_DMA1->SxCR))+((STREAM_SHIFT*Channel.Stream_no))/4) &= ~(1<<EN_SHIFT);
		*((&(P_DMA1->SxCR))+((STREAM_SHIFT*Channel.Stream_no))/4) |= (Status<<EN_SHIFT);
		state = DMA_Ok;

	}else if(Channel.Module == DMA_2){
		
		*((&(P_DMA2->SxCR))+((STREAM_SHIFT*Channel.Stream_no))/4) &= ~(1<<EN_SHIFT);
		*((&(P_DMA2->SxCR))+((STREAM_SHIFT*Channel.Stream_no))/4) |= (Status<<EN_SHIFT);
		state = DMA_Ok;
		
	}else{
		state = DMA_WrongConfig;
	}
		
	return state;
}


DMA_Return DMA_set_CalBackFunction(DMA_Config Channel , DMA_Cbf_t func){
	DMA_Return state = DMA_NotOK;

	if(func){
		if(Channel.Module == DMA_1){
			if(Channel.Stream_no==0){
				DMA1_Notify0 = func;
			}else if(Channel.Stream_no==1){
				DMA1_Notify1 = func;
			}else if(Channel.Stream_no==2){
				DMA1_Notify2 = func;
			}else if(Channel.Stream_no==3){
				DMA1_Notify3 = func;
			}else if(Channel.Stream_no==4){
				DMA1_Notify4 = func;
			}else if(Channel.Stream_no==5){
				DMA1_Notify5 = func;
			}else if(Channel.Stream_no==6){
				DMA1_Notify6 = func;
			}
		}else if(Channel.Module == DMA_2){
			if(Channel.Stream_no==0){
				DMA2_Notify0 = func;
			}else if(Channel.Stream_no==1){
				DMA2_Notify1 = func;
			}else if(Channel.Stream_no==2){
				DMA2_Notify2 = func;
			}else if(Channel.Stream_no==3){
				DMA2_Notify3 = func;
			}else if(Channel.Stream_no==4){
				DMA2_Notify4 = func;
			}
		}else{
			state = DMA_WrongConfig;
		}
	}
		return state;
}






DMA1_Stream0_IRQHandler(){
	if(DMA1_Notify0){
		DMA1_Notify0();
	}
}
DMA1_Stream1_IRQHandler(){
	if(DMA1_Notify1){
		DMA1_Notify1();
	}
}
DMA1_Stream2_IRQHandler(){
	if(DMA1_Notify2){
		DMA1_Notify2();
	}
}
DMA1_Stream3_IRQHandler(){
	if(DMA1_Notify3){
		DMA1_Notify3();
	}
}
DMA1_Stream4_IRQHandler(){
	if(DMA1_Notify4){
		DMA1_Notify4();
	}
}
DMA1_Stream5_IRQHandler(){
	if(DMA1_Notify5){
		DMA1_Notify5();
	}
}
DMA1_Stream6_IRQHandler(){
	if(DMA1_Notify6){
		DMA1_Notify6();
	}
}

DMA2_Stream0_IRQHandler(){
	if(DMA2_Notify0){
		DMA2_Notify0();
	}
}
DMA2_Stream1_IRQHandler(){
	if(DMA2_Notify1){
		DMA2_Notify1();
	}
}
DMA2_Stream2_IRQHandler(){
	if(DMA2_Notify2){
		DMA2_Notify2();
	}
}
DMA2_Stream3_IRQHandler(){
	if(DMA2_Notify3){
		DMA2_Notify3();
	}
}

DMA2_Stream4_IRQHandler(){
	if(DMA2_Notify4){
		DMA2_Notify4();
	}
}

