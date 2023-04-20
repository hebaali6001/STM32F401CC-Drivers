#include "DMA.h"



const u32* DMA_Buffer;



DMA_Config Channels[DMA_CHANNELS] = {
	[0] = {	.Module = DMA_1,
			.Stream_no = DMA_Stream_2,
			.Channel = DMA_channel_4,
			.Priority = DMA_Medium,
			.Circular_Mode = DMA_Enable,
			.Direction = Memory_to_peripheral,
			.Transfer_Complete_Intrupt = DMA_Enable,
			.Half_Transfer_Intrupt = DMA_Enable,
			.Transfer_Error_Intrupt = DMA_Enable,
			.Count = 25000,
			.Periephral_DataSize = DMA_word,
			.Periephral_Auto_Increament = DMA_Enable,
			.Periephral_Address = USART1_ADDRESS,
			.Memoey_DataSize = DMA_word,
			.Memoey_Auto_Increament = DMA_Enable,
			.Memoey_Address_0 = (u32)&DMA_Buffer,
			.Memoey_Address_1 = (u32)&DMA_Buffer,
	}
};


/*
typedef struct{

	DMA_Module		Module;
	DMA_Stream		Stream_no;
	DMA_Channel 	Channel;

	DMA_Priority	Priority;
	DMA_Status		Circular_Mode;
	DMA_Direction	Direction;
	DMA_Status		Transfer_Complete_Intrupt;
	DMA_Status		Half_Transfer_Intrupt;
	DMA_Status		Transfer_Error_Intrupt;
  //DMA_Status		Direct_Mode_Error_Intrupt;
	u16				Count;							// 0 - 65535

	DMA_Data_Size	Periephral_DataSize;
	DMA_Status		Periephral_Auto_Increament;
	u32*			Periephral_Address;

	DMA_Data_Size	Memoey_DataSize;
	DMA_Status		Memoey_Auto_Increament;
	u32*			Memoey_Address_0;					//memory_0

	u32*			Memoey_Address_1;					//memory_1

}DMA_Config;

*/
