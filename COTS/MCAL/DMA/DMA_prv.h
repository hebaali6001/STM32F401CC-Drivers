#ifndef DMA_PRV_H
#define DMA_PRV_H
#include "Stdtypes.h"



#define DMA_1_BASEADDRESS			(0x40026000)
#define DMA_2_BASEADDRESS			(0x40026400)





typedef struct{
	
	volatile u32 LISR;				//offset 0x0000
	volatile u32 HISR;				//offset 0x0004
	volatile u32 LIFCR;				//offset 0x0008
	volatile u32 HIFCR;				//offset 0x000C
	volatile u32 SxCR;				//offset 0x0010      //  0x10 + (0x18 * x)
	volatile u32 SxNDTR;			//offset 0x0014      //  0x14 + (0x18 * x)
	volatile u32 SxPAR;				//offset 0x0018      //  0x18 + (0x18 * x)
	volatile u32 SxM0AR;			//offset 0x001C      //  0x1C + (0x18 * x)
	volatile u32 SxM1AR;			//offset 0x0020      //  0x20 + (0x18 * x)
	volatile u32 SxFCR;				//offset 0x0024      //  0x24 + (0x18 * x)
	
}DMA_t;



DMA_t* const P_DMA1 = ((DMA_t* const) DMA_1_BASEADDRESS);
DMA_t* const P_DMA2 = ((DMA_t* const) DMA_2_BASEADDRESS);


#endif /* DMA_PRV_H */
