#ifndef DMA_H
#define DMA_H
#include "Stdtypes.h"






/** DMA1 **/ // the APB1 Bus

#define SPI3_I2S3_ADDRESS                    	(0x40003C00)
#define SPI2_I2S2_ADDRESS                     	(0x40003800)
#define I2C1_ADDRESS                            (0x40005400)
#define I2C3_ADDRESS                            (0x40005C00)
#define I2C2_ADDRESS                            (0x40005800)
#define TIM4_ADDRESS                   			(0x40000800)
#define TIM2_ADDRESS                            (0x40000000)
#define TIM3_ADDRESS                            (0x40000400)
#define TIM5_ADDRESS                            (0x40000C00)
#define USART2_ADDRESS                          (0x40004400)



/** DMA2 **/ // the APB2 Bus

#define ADC1_ADDRESS                            (0x40012000)
#define TIM1_ADDRESS                            (0x40010000)
#define SPI1_ADDRESS                            (0x40013000)
#define SPI4_ADDRESS		                    (0x40013400)
#define USART1_ADDRESS                          (0x40011000)
#define USART6_ADDRESS                          (0x40011400)
#define SDIO_ADDRESS                            (0x40012C00)

/*************************************************************************************/




#define DMA_CHANNELS 					1

typedef void (*DMA_Cbf_t)(void);




typedef enum{
	
	DMA_Ok,
	DMA_NotOK,
	DMA_WrongConfig,
	
}DMA_Return;



typedef enum{
	DMA_1=0,
	DMA_2,
	
}DMA_Module;



typedef enum{
	DMA_Stream_0 = 0,
	DMA_Stream_1,
	DMA_Stream_2,
	DMA_Stream_3,
	DMA_Stream_4,
	DMA_Stream_5,
	DMA_Stream_6,
	DMA_Stream_7,

}DMA_Stream;


typedef enum{
	DMA_channel_0 = 0b000, 
	DMA_channel_1 = 0b001,
	DMA_channel_2 = 0b010,
	DMA_channel_3 = 0b011,
	DMA_channel_4 = 0b100,
	DMA_channel_5 = 0b101,
	DMA_channel_6 = 0b110,
	DMA_channel_7 = 0b111,
	
}DMA_Channel;



typedef enum{
	DMA_Low = 0b00,
	DMA_Medium = 0b01,
	DMA_High = 0b10,
	DMA_Very_high = 0b11,
	
}DMA_Priority;


//for Dist and Src
typedef enum{
	DMA_byte = 0b00,				//8-bit
	DMA_half_word = 0b01,           //16-bit
	DMA_word = 0b10,                //32-bit

}DMA_Data_Size;             



typedef enum{
	DMA_Disable = 0,
	DMA_Enable,
	
}DMA_Status;



typedef enum{
	Peripheral_to_memory = 0b00,
	Memory_to_peripheral = 0b01,
	Memory_to_memory = 0b10,
	
}DMA_Direction;




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
	u32 			Periephral_Address;
	
	DMA_Data_Size	Memoey_DataSize;
	DMA_Status		Memoey_Auto_Increament;
	u32 			Memoey_Address_0;					//memory_0
	
	u32				Memoey_Address_1;					//memory_1
	
}DMA_Config;



extern DMA_Config Channels[DMA_CHANNELS];





DMA_Return DMA_ConfigChannel(DMA_Config* config);

DMA_Return DMA_EnableChannel(DMA_Config Channel , DMA_Status status);

DMA_Return DMA_set_CalBackFunction(DMA_Config Channel , DMA_Cbf_t func);



















#endif /* DMA_H */ 
