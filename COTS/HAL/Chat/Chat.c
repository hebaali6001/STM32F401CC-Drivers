#include "Chat.h"




Chat_Return chat_Init_UART(){
	Chat_Return Status = Chat_NotOk;
	u8 i=0;
	
	
	/************************ UART_INITILIZATION ****************************/
	
	
	UART_MODULE_Config config[UART_MODULES_NUM];
	for(i=0 ; i<UART_MODULES_NUM ; i++){
		config[i].TX.Port =  UARTmodules[i].TXport;
		config[i].TX.pin =  UARTmodules[i].TXpin;
		config[i].TX.speed =  UARTmodules[i].TXspeed;
		config[i].TX.GPIOPin_mode =  UARTmodules[i].GPIO_TXmode;
		if((UARTmodules.module == chat_UART1) || (UARTmodules.module == chat_UART2)){
			config[i].TX.af = 7;
		}else if(UARTmodules.module == chat_UART6){
			config[i].TX.af = 8;
		}
		
		
		config[i].RX.Port =  UARTmodules[i].RXport;
		config[i].RX.pin =  UARTmodules[i].RXpin;
		config[i].RX.speed =  UARTmodules[i].RXspeed;
		config[i].RX.GPIOPin_mode =  UARTmodules[i].GPIO_RXmode;
		if((UARTmodules.module == chat_UART1) || (UARTmodules.module == chat_UART2)){
			config[i].RX.af = 7;
		}else if(UARTmodules.module == chat_UART6){
			config[i].RX.af = 8;
		}
	} 
	
	init_UART(config);
	
	for(i=0 ; i<UART_MODULES_NUM ; i++){
		
		UART_setDataLength(UARTmodules[i].module , dataLength);					//Data Length
		UART_enableParityBit(UARTmodules[i].module , ParityBit);				//Parity Bit
		UART_setStopBit(UARTmodules[i].module , StopBit);						//Stop Bit
		UART_setBaudRate(UARTmodules[i].module , BaudRate ,overSample);			//BaudRate
		
	}
	
	
	/************************ SPI_INITILIZATION ****************************/	
	
	
	SPI_MODULE_Config config[SPI_MODULES_NUM];
	for(i=0 ; i<SPI_MODULES_NUM ; i++){
	
		//Not Impllemented Yet
	
	
	}
	
	
	/************************ I2C_INITILIZATION ****************************/
	
	
	I2C_MODULE_Config config[I2C_MODULES_NUM];
	for(i=0 ; i<I2C_MODULES_NUM ; i++){
	
		//Not Impllemented Yet
	
	
	}
	
	
	/***********************************************************************/
	
	Status = Chat_Ok;
	return Status;
}






//void chatI_Init_SPI(SPI_ChatConfig* modules);  	/* NOT IMPLEMENTED YET */

//void chat_Init_I2C(I2C_ChatConfig* modules);		/* NOT IMPLEMENTED YET */





Chat_Return chat_send_Async(u8* buffer , u8 size , Chat_module module){
	Chat_Return Status = Chat_NotOk;
	switch(module){
		case chat_UART1:
		{
			UART_enableTransmiter(UART1,UART_enable);
			UART_sendBuffer_Async_ZeroCpy(UART1, buffer, size);
			break;
		}
		case chat_UART2:
		{
			UART_enableTransmiter(UART2,UART_enable);
			UART_sendBuffer_Async_ZeroCpy(UART2, buffer, size);
			break;
		}
		case chat_UART6:
		{
			UART_enableTransmiter(UART6,UART_enable);
			UART_sendBuffer_Async_ZeroCpy(UART6, buffer, size);
			break;
		}
		case chat_I2C1:
		{
			/*nothing*/
			break;
		}
		case chat_I2C2:
		{
			/*nothing*/
			break;
		}
		case chat_I2C3:
		{
			/*nothing*/
			break;
		}
		case chat_SPI1:
		{
			/*nothing*/
			break;
		}
		case chat_SPI2:
		{
			/*nothing*/
			break;
		}
		case chat_SPI3:
		{
			/*nothing*/
			break;
		}
		case chat_SPI4:
		{
			/*nothing*/
			break;
		}
	}
	
	
	return Status;
}

Chat_Return chat_Recieve_Async(u8* buffer , u8 size , Chat_module module){
	Chat_Return Status = Chat_NotOk;
	
	switch(module){
		case chat_UART1:
		{
			UART_enableReciever(UART1,UART_enable);
			UART_recieveBuffer_Async(UART1, buffer, size);
			break;
		}
		case chat_UART2:
		{
			UART_enableReciever(UART2,UART_enable);
			UART_recieveBuffer_Async(UART2, buffer, size);
			break;
		}
		case chat_UART6:
		{
			UART_enableReciever(UART6,UART_enable);
			UART_recieveBuffer_Async(UART6, buffer, size);
			break;
		}
		case chat_I2C1:
		{
			/*nothing*/
			break;
		}
		case chat_I2C2:
		{
			/*nothing*/
			break;
		}
		case chat_I2C3:
		{
			/*nothing*/
			break;
		}
		case chat_SPI1:
		{
			/*nothing*/
			break;
		}
		case chat_SPI2:
		{
			/*nothing*/
			break;
		}
		case chat_SPI3:
		{
			/*nothing*/
			break;
		}
		case chat_SPI4:
		{
			/*nothing*/
			break;
		}
	}
	
	return Status;
}