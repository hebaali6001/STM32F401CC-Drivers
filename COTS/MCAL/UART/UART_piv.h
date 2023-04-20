#ifndef UART_PIV_H
#define UART_PIV_H
#include "Stdtypes.h"




#define USART_1_BASEADDRRESS			(0x40011000)	//APB2
#define USART_6_BASEADDRRESS			(0x40011400)	//APB2
#define USART_2_BASEADDRRESS			(0x40004400)	//APB1






typedef struct{
	
	volatile u32 SR;			// ofset 0x00
	volatile u32 DR;			// ofset 0x04
	volatile u32 BRR;			// ofset 0x08
	volatile u32 CR1;			// ofset 0x0c
	volatile u32 CR2;			// ofset 0x10
	volatile u32 CR3;			// ofset 0x14
	volatile u32 GTPR;			// ofset 0x18	
	
}UART_t;





UART_t* const UART_1 = ((UART_t* const) USART_1_BASEADDRRESS);

UART_t* const UART_6 = ((UART_t* const) USART_6_BASEADDRRESS);

UART_t* const UART_2 = ((UART_t* const) USART_2_BASEADDRRESS);


#endif /* UART_PIV_H */
