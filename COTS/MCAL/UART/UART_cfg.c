#include "UART.h"






UART_MODULE_Config modules[NO_OF_UART_MODULES] = {
	{
		.TX={UARTPort_A , UART_Pin_9 , UART_High_Speed , UART_AF_7 , ALTERNATE_FUNCTION_PP , "UART1_tx"},
		.RX={UARTPort_A , UART_Pin_10 , UART_High_Speed , UART_AF_7 , ALTERNATE_FUNCTION_PP_PULLUP , "UART1_rx"}
	},
	{
		.TX={UARTPort_A , UART_Pin_11 , UART_High_Speed , UART_AF_8 , ALTERNATE_FUNCTION_PP , "UART6_tx"},
		.RX={UARTPort_A , UART_Pin_12 , UART_High_Speed , UART_AF_8 , ALTERNATE_FUNCTION_PP_PULLUP , "UART6_rx"}
	}
};
