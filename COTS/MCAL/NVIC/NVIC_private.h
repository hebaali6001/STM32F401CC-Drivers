#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H
#include "Stdtypes.h"



#define NVIC_BASEADDRESS			0xE000E100




typedef struct{
	
	volatile u32 	ISER[8];
	volatile u32 	reserved[24];
	volatile u32 	ICER[8];
	volatile u32	reserved1[24];
	volatile u32 	ISPR[8];
	volatile u32	reserved2[24];
	volatile u32 	ICPR[8];
	volatile u32	reserved3[24];
	volatile u32 	IABR[8];
	volatile u32	reserved4[56];
	volatile u8		IPR[240];

}NVIC_t;


#define NVIC			((volatile NVIC_t* const)NVIC_BASEADDRESS)


#define STIR 						((u32*) (0xE000EF00))

#define AIRCR						((u32*) (0xE000ED0C))




#endif /* NVIC_PRIVATE_H */
