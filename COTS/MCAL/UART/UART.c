#include "UART.h"
#include "UART_piv.h"
#include "GPIO.h"


#define	NULL				((void*)0)
#define ENABLEMUSK			1
#define	UARTEN				13
#define	TRANSMITEN			3
#define	RECIEVEEN			2
#define	STOPBITMUSK			(0b11)
#define	STOPBIT				12
#define	RECIEVE_INTRPT		5
#define	TRANS_INTRPT		6
#define	WORDLENGTH			12
#define	PARITYBIT			10
#define OVERSAMPLE			15




static UARTcbf_t UART_notifyTX_1;
static UARTcbf_t UART_notifyRX_1;
static UARTcbf_t UART_notifyTX_2;
static UARTcbf_t UART_notifyRX_2;
static UARTcbf_t UART_notifyTX_6;
static UARTcbf_t UART_notifyRX_6;


/*****************************************************/
static u8* TXBUFFER_1;
static u8 TXSize_1;
static u8 TXIDx_1;
static UART_Return TXStatus_1 = UART_Idel;

static u8* RXBUFFER_1;
static u8 RXSize_1;
static u8 RXIDx_1;
static UART_Return RXStatus_1 = UART_Idel;

/*****************************************************/
static u8* TXBUFFER_2;
static u8 TXSize_2;
static u8 TXIDx_2;
static UART_Return TXStatus_2 = UART_Idel;

static u8* RXBUFFER_2;
static u8 RXSize_2;
static u8 RXIDx_2;
static UART_Return RXStatus_2 = UART_Idel;

/*****************************************************/
static u8* TXBUFFER_6;
static u8 TXSize_6;
static u8 TXIDx_6;
static UART_Return TXStatus_6 = UART_Idel;

static u8* RXBUFFER_6;
static u8 RXSize_6;
static u8 RXIDx_6;
static UART_Return RXStatus_6 = UART_Idel;

/*****************************************************/




UART_Return UART_Init(UART_MODULE_Config* MDs){
	
	UART_Return status = UART_NotOk;
	GPIO_PinConfig cfg;
	u8 i;
	
	for(i=0 ; i<NO_OF_UART_MODULES ; i++){
		
		cfg.port = MDs[i].TX.port;
		cfg.pin = MDs[i].TX.pin;
		cfg.speed = MDs[i].TX.speed;
		cfg.Pin_mode = MDs[i].TX.GPIOPin_mode;
		GPIO_initPin(cfg);
		GPIO_select_AF(MDs[i].TX.port ,MDs[i].TX.pin ,MDs[i].TX.af);

		cfg.port = MDs[i].RX.port;
		cfg.pin = MDs[i].RX.pin;
		cfg.speed = MDs[i].RX.speed;
		cfg.Pin_mode = MDs[i].RX.GPIOPin_mode;
		GPIO_initPin(cfg);
		GPIO_select_AF(MDs[i].RX.port ,MDs[i].RX.pin ,MDs[i].RX.af);
	}
	
	status = UART_Ok;
	return status;
	
 }


UART_Return UART_ModuleEnable(UART_module module, UART_Status status){
	
	UART_Return state = UART_NotOk;
	UART_t* loc_UARTptr = NULL;
	u32 loc_cr=0x00;
	
	if(module>UART6){
		state = UART_WrongGonfig;
	}else{
		
	switch (module){
		case UART1:
		{
			loc_UARTptr = UART_1;
			break;
		}
		case UART2:
		{
			loc_UARTptr = UART_2;
			break;
		}
		case UART6:
		{
			loc_UARTptr = UART_6;
			break;
		}
	}
	
	loc_cr = loc_UARTptr->CR1;
	loc_cr &= ~(ENABLEMUSK<<UARTEN);
	loc_cr |= (status<<UARTEN);
	loc_UARTptr->CR1 = loc_cr;
	
	state = UART_Ok;
	}
	return state;
}




UART_Return UART_enableTransmiter(UART_module module, UART_Status status){
	UART_Return state = UART_NotOk;
	UART_t* loc_UARTptr = NULL;
	u32 loc_cr=0x00;
	
	if(module>UART6){
		state = UART_WrongGonfig;
	}else{
	switch (module){
		case UART1:
		{
			loc_UARTptr = UART_1;
			break;
		}
		case UART2:
		{
			loc_UARTptr = UART_2;
			break;
		}
		case UART6:
		{
			loc_UARTptr = UART_6;
			break;
		}
	}
	
	loc_cr = loc_UARTptr->CR1;
	loc_cr &= ~(ENABLEMUSK<<TRANSMITEN);
	loc_cr |= (status<<TRANSMITEN);
	loc_UARTptr->CR1 = loc_cr;
	
	state = UART_Ok;
	}
	return state;
}										

UART_Return UART_enableReciever(UART_module module, UART_Status status){
	UART_Return state = UART_NotOk;
	UART_t* loc_UARTptr = NULL;
	u32 loc_cr=0x00;
	
	if(module>UART6){
		state = UART_WrongGonfig;
	}else{
	switch (module){
		case UART1:
		{
			loc_UARTptr = UART_1;
			break;
		}
		case UART2:
		{
			loc_UARTptr = UART_2;
			break;
		}
		case UART6:
		{
			loc_UARTptr = UART_6;
			break;
		}
	}
	
	loc_cr = loc_UARTptr->CR1;
	loc_cr &= ~(ENABLEMUSK<<RECIEVEEN);
	loc_cr |= (status<<RECIEVEEN);
	loc_UARTptr->CR1 = loc_cr;
	
	state = UART_Ok;
	}
	return state;
}										




UART_Return UART_enableTransmite_Interrupt(UART_module module, UART_Status status){
	UART_Return state = UART_NotOk;
	UART_t* loc_UARTptr = NULL;
	u32 loc_cr=0x00;
	
	if(module>UART6){
		state = UART_WrongGonfig;
	}else{
	switch (module){
		case UART1:
		{
			loc_UARTptr = UART_1;
			break;
		}
		case UART2:
		{
			loc_UARTptr = UART_2;
			break;
		}
		case UART6:
		{
			loc_UARTptr = UART_6;
			break;
		}
	}
	
	loc_UARTptr->SR = 0;
	loc_cr = loc_UARTptr->CR1;
	loc_cr &= ~(ENABLEMUSK<<TRANS_INTRPT);
	loc_cr |= (status<<TRANS_INTRPT);
	loc_UARTptr->CR1 = loc_cr;
	
	state = UART_Ok;
	}
	
	return state;
}								

UART_Return UART_enableReciever_Interrupt(UART_module module, UART_Status status){
	UART_Return state = UART_NotOk;
	UART_t* loc_UARTptr = NULL;
	u32 loc_cr=0x00;
	
	if(module>UART6){
		state = UART_WrongGonfig;
	}else{
	switch (module){
		case UART1:
		{
			loc_UARTptr = UART_1;
			break;
		}
		case UART2:
		{
			loc_UARTptr = UART_2;
			break;
		}
		case UART6:
		{
			loc_UARTptr = UART_6;
			break;
		}
	}
	
	loc_UARTptr->SR = 0;
	loc_cr = loc_UARTptr->CR1;
	loc_cr &= ~(ENABLEMUSK<<RECIEVE_INTRPT);
	loc_cr |= (status<<RECIEVE_INTRPT);
	loc_UARTptr->CR1 = loc_cr;
	
	state = UART_Ok;
	}
	return state;
}								




UART_Return UART_setDataLength(UART_module module , UART_dataLength dataLength){
	UART_Return state = UART_NotOk;
	UART_t* loc_UARTptr = NULL;
	u32 loc_cr=0x00;
	
	if(module>UART6){
		state = UART_WrongGonfig;
	}else{
	switch (module){
		case UART1:
		{
			loc_UARTptr = UART_1;
			break;
		}
		case UART2:
		{
			loc_UARTptr = UART_2;
			break;
		}
		case UART6:
		{
			loc_UARTptr = UART_6;
			break;
		}
	}
	
	loc_cr = loc_UARTptr->CR1;
	loc_cr &= ~(ENABLEMUSK<<WORDLENGTH);
	loc_cr |= (dataLength<<WORDLENGTH);
	loc_UARTptr->CR1 = loc_cr;

	state = UART_Ok;
	}
	return state;
}							

UART_Return UART_enableParityBit(UART_module module , UART_Status status){
	UART_Return state = UART_NotOk;
	UART_t* loc_UARTptr = NULL;
	u32 loc_cr=0x00;
	
	if(module>UART6){
		state = UART_WrongGonfig;
	}else{
	switch (module){
		case UART1:
		{
			loc_UARTptr = UART_1;
			break;
		}
		case UART2:
		{
			loc_UARTptr = UART_2;
			break;
		}
		case UART6:
		{
			loc_UARTptr = UART_6;
			break;
		}
	}
	
	loc_cr = loc_UARTptr->CR1;
	loc_cr &= ~(ENABLEMUSK<<PARITYBIT);
	loc_cr |= (status<<PARITYBIT);
	loc_UARTptr->CR1 = loc_cr;
	
	state = UART_Ok;
	}
	return state;
}										

UART_Return UART_setStopBit(UART_module module , UART_StopBit StopBit){
	UART_Return state = UART_NotOk;
	UART_t* loc_UARTptr = NULL;
	u32 loc_cr=0x00;
	
	if(module>UART6){
		state = UART_WrongGonfig;
	}else{
	switch (module){
		case UART1:
		{
			loc_UARTptr = UART_1;
			break;
		}
		case UART2:
		{
			loc_UARTptr = UART_2;
			break;
		}
		case UART6:
		{
			loc_UARTptr = UART_6;
			break;
		}
	}
	
	loc_cr = loc_UARTptr->CR2;
	loc_cr &= ~(STOPBITMUSK<<STOPBIT);
	loc_cr |= (StopBit<<STOPBIT);
	loc_UARTptr->CR2 = loc_cr;
	
	state = UART_Ok;
	}
	return state;
}										


UART_Return UART_setBaudRate( UART_module module , UART_BaudRate BaudRate ,UART_overSample sample){
	UART_Return state = UART_NotOk;

		u32 loc_cr=0x00 , loc_brr=0x0000;
		UART_t* loc_UARTptr = NULL;
		f64 loc_baudRateVal=0.0 , loc_f=0.0 , loc_assist=0.0;
		u16 loc_mantisa=0 , loc_fraction=0,loc_int=0;
		loc_baudRateVal = UART_SYSTEM_CLOCK / (8.0 * (2-sample) * BaudRate);

		loc_mantisa = (u16)loc_baudRateVal;
		loc_f = loc_baudRateVal - loc_mantisa;

		if (sample == 0){
			loc_f *= 16;
		}else if(sample == 1){
			loc_f *= 8;
		}

		loc_int = (u16)loc_f;
		loc_assist = loc_f - loc_int;
		if(loc_assist >= 0.5){
			loc_fraction = (u16)(loc_f + 1);
		}else{
			loc_fraction = (u16)(loc_f);
		}

		if(loc_fraction > 0xf){
			loc_mantisa += 1;
			loc_fraction -= 0xf;
		}



		if(module>UART6){
			state = UART_WrongGonfig;
		}else{
		switch (module){
			case UART1:
			{
				loc_UARTptr = UART_1;
				break;
			}
			case UART2:
			{
				loc_UARTptr = UART_2;
				break;
			}
			case UART6:
			{
				loc_UARTptr = UART_6;
				break;
			}
		}

		loc_cr = loc_UARTptr->CR1;
		loc_cr &= ~(ENABLEMUSK<<OVERSAMPLE);
		loc_cr |= (sample<<OVERSAMPLE);
		loc_UARTptr->CR1 = loc_cr;



		loc_brr = loc_fraction;
		loc_brr |= (loc_mantisa<<4);

		loc_UARTptr->BRR = loc_brr;

		state = UART_Ok;
		}
		return state;
}


//u8* TXBUFFER;
//u8 TXSize;
//u8 TXIDx;
//UART_Return TXStatus;

UART_Return UART_sendBuffer_Async_ZeroCpy(UART_module module, u8* Buffer, u8 size){
	UART_Return state = UART_Busy;

		if(module>UART6){
			state = UART_WrongGonfig;
		}else{
		switch (module){
			case UART1:
			{
				if(TXStatus_1 == UART_Idel){

					TXBUFFER_1 = Buffer;
					TXSize_1 = size;
					TXIDx_1 = 0;
					TXStatus_1 = UART_Busy;
					UART_1->DR = TXBUFFER_1[TXIDx_1];
					TXIDx_1++;
					UART_1->SR &= ~(1<<TRANS_INTRPT);
					UART_enableTransmite_Interrupt(UART1, UART_enable);
					state = UART_Ok;
				}
				break;
			}
			case UART2:
			{
				if(TXStatus_2 == UART_Idel){
						TXBUFFER_2 = Buffer;
						TXSize_2 = size;
						TXIDx_2 = 0;
						TXStatus_2 = UART_Busy;
						UART_2->DR = TXBUFFER_2[TXIDx_2];
						TXIDx_2++;
						UART_2->SR &= ~(1<<TRANS_INTRPT);
						UART_enableTransmite_Interrupt(UART2, UART_enable);
						state = UART_Ok;
				}
				break;
			}
			case UART6:
			{
				if(TXStatus_6 == UART_Idel){
						TXBUFFER_6 = Buffer;
						TXSize_6 = size;
						TXIDx_6 = 0;
						TXStatus_6 = UART_Busy;
						UART_6->DR = TXBUFFER_6[TXIDx_6];
						TXIDx_6++;
						UART_6->SR &= ~(1<<TRANS_INTRPT);
						UART_enableTransmite_Interrupt(UART6, UART_enable);
						state = UART_Ok;
				}
				break;
			}
		}
		}
	return state;
}

UART_Return UART_recieveBuffer_Async(UART_module module, u8* Buffer, u8 size){
	UART_Return state = UART_Busy;

		if(module>UART6){
			state = UART_WrongGonfig;
		}else{
		switch (module){
			case UART1:
			{
				if(RXStatus_1 == UART_Idel){

					RXStatus_1 = UART_Busy;
					RXBUFFER_1 = Buffer;
					RXSize_1 = size;
					RXIDx_1 = 0;
					UART_1->SR &= ~(1<<RECIEVE_INTRPT);
					UART_enableReciever_Interrupt(UART1, UART_enable);
					state = UART_Ok;
				}
				break;
			}
			case UART2:
			{
				if(RXStatus_2 == UART_Idel){

					RXStatus_2 = UART_Busy;
					RXBUFFER_2 = Buffer;
					RXSize_2 = size;
					RXIDx_2 = 0;
					UART_2->SR &= ~(1<<RECIEVE_INTRPT);
					UART_enableReciever_Interrupt(UART2, UART_enable);
					state = UART_Ok;
				}
				break;
			}
			case UART6:
			{
				if(RXStatus_6 == UART_Idel){

					RXStatus_6 = UART_Busy;
					RXBUFFER_6 = Buffer;
					RXSize_6 = size;
					RXIDx_6 = 0;
					UART_6->SR &= ~(1<<RECIEVE_INTRPT);
					UART_enableReciever_Interrupt(UART6, UART_enable);
					state = UART_Ok;
				}
				break;
			}
		}

		}
	return state;
}


UART_Return UART_sendBuffer_Sync(UART_module module, u8* Buffer, u8 size){
	UART_Return state = UART_NotOk;
	UART_t* loc_UARTptr = NULL;
	u8 i=0;
	
	if(module>UART6){
		state = UART_WrongGonfig;
	}else{
	switch (module){
		case UART1:
		{
			loc_UARTptr = UART_1;
			break;
		}
		case UART2:
		{
			loc_UARTptr = UART_2;
			break;
		}
		case UART6:
		{
			loc_UARTptr = UART_6;
			break;
		}
	}
	
	for(i=0 ; i<size ; i++){
		loc_UARTptr->DR = Buffer[i];
		while(!((loc_UARTptr->SR)>>TRANS_INTRPT));
	}
	
	state = UART_Ok;
	}
	return state;
}


UART_Return UART_recieveBuffer_Sync(UART_module module, u8* Buffer, u8 size){
	UART_Return state = UART_NotOk;
	UART_t* loc_UARTptr = NULL;
	u8 i=0;

	if(module>UART6){
		state = UART_WrongGonfig;
	}else{
	switch (module){
		case UART1:
		{
			loc_UARTptr = UART_1;
			break;
		}
		case UART2:
		{
			loc_UARTptr = UART_2;
			break;
		}
		case UART6:
		{
			loc_UARTptr = UART_6;
			break;
		}
	}

	for(i=0 ; i<size ; i++){
		while(!((loc_UARTptr->SR)>>RECIEVE_INTRPT));
		Buffer[i] = loc_UARTptr->DR;
	}

	state = UART_Ok;
	}
	return state;
}


UART_Return UART_setCallBackFunc(UART_module module , UARTcbf_t funcTX , UARTcbf_t funcRX){
	UART_Return state = UART_NotOk;
	if(funcTX){
		if(module == UART1){
			UART_notifyTX_1 = funcTX;
			state = UART_Ok;
		}else if(module == UART2){
			UART_notifyTX_2 = funcTX;
			state = UART_Ok;
		}else if(module == UART6){
			UART_notifyTX_6 = funcTX;
			state = UART_Ok;
		}
	}
	if(funcRX){
			if(module == UART1){
				UART_notifyRX_1 = funcRX;
				state = UART_Ok;
			}else if(module == UART2){
				UART_notifyRX_2 = funcRX;
				state = UART_Ok;
			}else if(module == UART6){
				UART_notifyRX_6 = funcRX;
				state = UART_Ok;
			}
		}
	return state;
}

 
void USART1_IRQHandler(){

	if((UART_1->SR)>>TRANS_INTRPT){
		if(TXIDx_1 < TXSize_1){
				UART_1->DR = TXBUFFER_1[TXIDx_1];
				TXIDx_1++;
		}else if(TXIDx_1 == TXSize_1){
				TXStatus_1 = UART_Idel;
				UART_1->SR &= ~(1<<TRANS_INTRPT);
				UART_enableTransmite_Interrupt(UART1, UART_disable);
	//			if(UART_notifyTX_1){
	//				UART_notifyTX_1();
	//			}
			}
	}
	if(((UART_1->SR)>>RECIEVE_INTRPT) && (RXStatus_1 == UART_Busy)){
			RXBUFFER_1[RXIDx_1] = UART_1->DR;
			RXIDx_1 ++;
			if(RXIDx_1 == RXSize_1){
				RXStatus_1 = UART_Idel;
				UART_1->SR &= ~(1<<RECIEVE_INTRPT);
				UART_enableReciever_Interrupt(UART1, UART_disable);
	//		 	if(UART_notifyRX_1){
	//				  UART_notifyRX_1();
	//			}
			}
	}
}

void USART2_IRQHandler(){

	if((UART_2->SR)>>TRANS_INTRPT){
		if(TXIDx_2 < TXSize_2){
				UART_2->DR = TXBUFFER_2[TXIDx_2];
				TXIDx_2++;
		}else if(TXIDx_2 == TXSize_2){
				TXStatus_2 = UART_Idel;
				UART_2->SR &= ~(1<<TRANS_INTRPT);
				UART_enableTransmite_Interrupt(UART2, UART_disable);
	//			if(UART_notifyTX_2){
	//				UART_notifyTX_2();
	//			}
		}
	}
	if(((UART_2->SR)>>RECIEVE_INTRPT) && (RXStatus_2 == UART_Busy)){

		RXBUFFER_2[RXIDx_2] = UART_2->DR;
		RXIDx_2 ++;
		if(RXIDx_2 == RXSize_2){
			RXStatus_2 = UART_Idel;
			UART_2->SR &= ~(1<<RECIEVE_INTRPT);
			UART_enableReciever_Interrupt(UART2, UART_disable);
	//		if(UART_notifyRX_2){
	//		UART_notifyRX_2();
	//		}
		}
	}
}

void USART6_IRQHandler(){

	if((UART_6->SR)>>TRANS_INTRPT){
		if(TXIDx_6 > TXSize_6){
			UART_6->DR = TXBUFFER_6[TXIDx_6];
			TXIDx_6++;
		}else if(TXIDx_6 == TXSize_6){
			TXStatus_6 = UART_Idel;
			UART_6->SR &= ~(1<<TRANS_INTRPT);
			UART_enableTransmite_Interrupt(UART6, UART_disable);
	//		if(UART_notifyTX_6){
	//			UART_notifyTX_6();
	//		}
		}
	}
	if(((UART_6->SR)>>RECIEVE_INTRPT) && (RXStatus_6 == UART_Busy)){
			RXBUFFER_6[RXIDx_6] = UART_6->DR;
			RXIDx_6 ++;
			if(RXIDx_6 == RXSize_6){
				RXStatus_6 = UART_Idel;
				UART_6->SR &= ~(1<<RECIEVE_INTRPT);
				UART_enableReciever_Interrupt(UART2, UART_disable);
	//			if(UART_notifyRX_6){
	//				UART_notifyRX_6();
	//			}
			}
	}
}
