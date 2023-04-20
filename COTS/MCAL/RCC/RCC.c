#include "Stdtypes.h"

#include "RCC.h"
#include "RCC_private.h"

#define CSSON 	19

#define HSION 	0
#define HSIRDY 	1

#define HSEON 	16
#define HSERDY 	17
#define HSEBYP 	18

#define PLLSRC 	22
#define PLLON 	24
#define PLLRDY 	25


#define PLLQ			0x0F000000
#define PLLQ_SHIFT		24

#define PLLP			0x00030000
#define PLLP_SHIFT		16

#define PLLN			0x00007FC0
#define PLLN_SHIFT		6

#define PLLM			0x0000003F
#define PLLM_SHIFT		0

#define MCO1			0x00600000
#define MCO1_SHIFT		21
#define MCO1_PRE_SHIFT	24
#define MCO1_PRE		0x07000000

#define MCO2			0xC0000000
#define MCO2_SHIFT		30
#define MCO2_PRE_SHIFT	27
#define MCO2_PRE		0x38000000



#define ZERO			0x0000 0000


/**************************************************************************/
				/* PREPHERLS DISABLE */
#define AHB1_RESET_CHECK 	0x8 
#define AHB1_DMA2_RESET 	0x800400000
#define AHB1_DMA1_RESET 	0x800200000
#define AHB1_CRC_RESET      0x800001000
#define AHB1_GPIOH_RESET    0x800000080
#define AHB1_GPIOE_RESET    0x800000010
#define AHB1_GPIOD_RESET    0x800000008
#define AHB1_GPIOC_RESET    0x800000004
#define AHB1_GPIOB_RESET    0x800000002
#define AHB1_GPIOA_RESET    0x800000001
							

#define AHB2_RESET_CHECK	0x7 	
#define AHB2_OTGFS_RESET	0x700000080

#define APB1_RESET_CHECK	0x6  	
#define APB1_PWR_RESET      0x610000000
#define APB1_I2C3_RESET     0x600800000
#define APB1_I2C2_RESET     0x600400000
#define APB1_I2C1_RESET     0x600200000
#define APB1_USART2_RESET   0x600020000
#define APB1_SPI3_RESET     0x600008000
#define APB1_SPI2_RESET     0x600004000
#define APB1_WWDG_RESET     0x600000800
#define APB1_TIM5_RESET     0x600000008
#define APB1_TIM4_RESET     0x600000004
#define APB1_TIM3_RESET     0x600000002
#define APB1_TIM2_RESET     0x600000001


#define APB2_RESET_CHECK 	0x5 
#define APB2_TIM11_RESET	0x500040000
#define APB2_TIM10_RESET    0x500020000
#define APB2_TIM9_RESET     0x500010000
#define APB2_SYSCFG_RESET   0x500004000
#define APB2_SPI4_RESET     0x500002000
#define APB2_SPI1_RESET     0x500001000
#define APB2_SDIO_RESET     0x500000800
#define APB2_ADC1_RESET     0x500000100
#define APB2_USART6_RESET   0x500000020
#define APB2_USART1_RESET   0x500000010
#define APB2_TIM1_RESET     0x500000001
/***************************************************************************/




/**************************************************************************/
				/* PREPHERLS ENABLE */
#define AHB1_ENABLE_CHECK	0x4 
#define AHB1_DMA2_ENABLE 	0x400400000
#define AHB1_DMA1_ENABLE    0x400200000
#define AHB1_CRC_ENABLE     0x400001000
#define AHB1_GPIOH_ENABLE   0x400000080
#define AHB1_GPIOE_ENABLE   0x400000010
#define AHB1_GPIOD_ENABLE   0x400000008
#define AHB1_GPIOC_ENABLE   0x400000004
#define AHB1_GPIOB_ENABLE   0x400000002
#define AHB1_GPIOA_ENABLE	0x400000001
                            
                            
#define AHB2_ENABLE_CHECK   0x3 
#define AHB2_OTGFS_ENABLE   0x300000080
                            
#define APB1_ENABLE_CHECK   0x2 
#define APB1_PWR_ENABLE     0x210000000
#define APB1_I2C3_ENABLE    0x200800000
#define APB1_I2C2_ENABLE    0x200400000
#define APB1_I2C1_ENABLE    0x200200000
#define APB1_USART2_ENABLE  0x200020000
#define APB1_SPI3_ENABLE    0x200008000
#define APB1_SPI2_ENABLE    0x200004000
#define APB1_WWDG_ENABLE    0x200000800
#define APB1_TIM5_ENABLE    0x200000008
#define APB1_TIM4_ENABLE    0x200000004
#define APB1_TIM3_ENABLE    0x200000002
#define APB1_TIM2_ENABLE    0x200000001
                            
                            
#define APB2_ENABLE_CHECK   0xE 
#define APB2_TIM11_ENABLE	0xE00040000
#define APB2_TIM10_ENABLE   0xE00020000
#define APB2_TIM9_ENABLE    0xE00010000
#define APB2_SYSCFG_ENABLE  0xE00004000
#define APB2_SPI4_ENABLE    0xE00002000
#define APB2_SPI1_ENABLE    0xE00001000
#define APB2_SDIO_ENABLE    0xE00000800
#define APB2_ADC1_ENABLE    0xE00000100
#define APB2_USART6_ENABLE  0xE00000020
#define APB2_USART1_ENABLE  0xE00000010
#define APB2_TIM1_ENABLE    0xE00000001
/***************************************************************************/
							/*RCC_APIs*/

RCC_Return RCC_Select_SecuritySys_Status(SecuritySys_status status){
	u32 Rcccr;

	Rcccr = RCC->CR;
	Rcccr &= ~(1 << CSSON);
	Rcccr |= status << CSSON;
	RCC->CR = Rcccr;
	
	return RCC_Ok;
}


RCC_Return RCC_Select_ClockSource(ClkSource ClkSrc){
	u32 cfrg;
	
	
	cfrg = RCC->CFGR;
	cfrg &= ~(0x00000003);
	cfrg |= ClkSrc;
	RCC->CFGR =cfrg;

	return RCC_Ok;
}




RCC_Return RCC_SelectAHB_Prescaller(AHB_Prescaller Prescaller){
	
	u32 cfrg;
	
	cfrg = RCC->CFGR;
	cfrg &= ~(0x000000f0);
	cfrg |= (4<<Prescaller);
	RCC->CFGR =cfrg;
	
	return RCC_Ok;
}


RCC_Return RCC_SelectAPB1_Prescaller(APB1_Prescaller Prescaller){
	
	u32 cfrg;
	
	cfrg = RCC->CFGR;
	cfrg &= ~(0x00001c00);
	cfrg |= (10<<Prescaller);
	RCC->CFGR =cfrg;
	
	return RCC_Ok;	
}


RCC_Return RCC_SelectAPB2_Prescaller(APB2_Prescaller Prescaller){
	
	u32 cfrg;
	
	cfrg = RCC->CFGR;
	cfrg &= ~(0x0000e000);
	cfrg |= (13<<Prescaller);
	RCC->CFGR =cfrg;
	
	return RCC_Ok;
}




RCC_Return RCC_Enable_Clock_Prepheral(RCC_BusName BusName , u64 CPY_prepheralnum ){

	u32 bus_reg=0x00;
	RCC_Return status=RCC_NotOk;
	
	switch(BusName){
		case AHB1:
		{
		//	if((CPY_prepheralnum>>32)!=AHB1_ENABLE_CHECK){
			//		status=RCC_Wrong_BusName;
		//	}else{
				bus_reg = RCC->AHB1ENR;///////////
				bus_reg |= (1<<CPY_prepheralnum);
				RCC->AHB1ENR = bus_reg;
				status = RCC_Ok;
			//}
			break;
		}
		case AHB2:
		{
		//	if((CPY_prepheralnum>>32)!= AHB2_ENABLE_CHECK){
		//			status=RCC_Wrong_BusName;
		//	}else{
				bus_reg = RCC->AHB2ENR; ////////
				bus_reg |= (1<<CPY_prepheralnum);
				RCC->AHB2ENR = bus_reg;
				status = RCC_Ok;
		//	}
			
			break;
		}
		case APB1:
		{
		//	if((CPY_prepheralnum>>32)!= APB1_ENABLE_CHECK){
		//			status=RCC_Wrong_BusName;
		//	}else{
				bus_reg = RCC->APB1ENR;///////////
				bus_reg |= (1<<CPY_prepheralnum);
				RCC->APB1ENR = bus_reg;
				status = RCC_Ok;
		//	}
			
			break;
		}
		case APB2:
		{
		//	if((CPY_prepheralnum>>32)!= APB2_ENABLE_CHECK){
		//			status=RCC_Wrong_BusName;
		//	}else{
				bus_reg = RCC->APB2ENR;///////
				bus_reg |= (1<<CPY_prepheralnum);
				RCC->APB2ENR = bus_reg;
				status = RCC_Ok;
		//	}
			
			break;
		}
	}
	return status;
}


RCC_Return RCC_Disable_Clock_Prepheral(RCC_BusName BusName , u64 CPY_prepheralnum ){
	
	u32 bus_reg=0x00;
	RCC_Return status=RCC_NotOk;
	
	switch(BusName){
		case AHB1:
		{
			if((CPY_prepheralnum>>32)!=AHB1_RESET_CHECK){
					status=RCC_Wrong_BusName;
			}else{
				bus_reg = RCC->AHB1RSTR;////////
				bus_reg |= CPY_prepheralnum;
				RCC->AHB1RSTR = bus_reg;
				status = RCC_Ok;
			}
			break;
		}
		case AHB2:
		{
			if((CPY_prepheralnum>>32)!=AHB2_RESET_CHECK){
					status=RCC_Wrong_BusName;
			}else{
				bus_reg = RCC->AHB2RSTR;///////
				bus_reg |= CPY_prepheralnum;
				RCC->AHB2RSTR = bus_reg;
				status = RCC_Ok;
			}
			
			break;
		}
		case APB1:
		{
			if((CPY_prepheralnum>>32)!=APB1_RESET_CHECK){
					status=RCC_Wrong_BusName;
			}else{
				bus_reg = RCC->APB1RSTR;///////
				bus_reg |= CPY_prepheralnum;
				RCC->APB1RSTR = bus_reg;
				status = RCC_Ok;
			}
			
			break;
		}
		case APB2:
		{
			if((CPY_prepheralnum >> 32)!=APB2_RESET_CHECK){
					status=RCC_Wrong_BusName;
			}else{
				bus_reg = RCC->APB2RSTR;////////
				bus_reg |= CPY_prepheralnum;
				RCC->APB2RSTR = bus_reg;
				status = RCC_Ok;
			}
			
			break;
		}
	}
	return status;
}



RCC_Return RCC_Config_MCO1(MCO_1_ClkSource Source, MCO_Prebscaller Prescaller){

	u32 cfgr = RCC->CFGR;

	cfgr &= ~(MCO1);
	cfgr &= ~(MCO1_PRE);

	cfgr |= (Source<<MCO1_SHIFT);
	cfgr |= (Prescaller<<MCO1_PRE_SHIFT);

	RCC->CFGR = cfgr;

	return RCC_Ok;
}

RCC_Return RCC_Config_MCO2(MCO_2_ClkSource Source, MCO_Prebscaller Prescaller){

	u32 cfgr = RCC->CFGR;

	cfgr &= ~(MCO2);
	cfgr &= ~(MCO2_PRE);

	cfgr |= (Source<<MCO2_SHIFT);
	cfgr |= (Prescaller<<MCO2_PRE_SHIFT);

	RCC->CFGR = cfgr;

	return RCC_Ok;
}




RCC_Return RCC_Config_PLL(PLL_ClkSrc PllSrc , HSE_ClkSrc ClkSrc){
	
	u32 Rcccr = RCC->CR;
	u8 pllcfgr = RCC->PLLCFGR;

	pllcfgr &= ~(1 << PLLSRC);
	pllcfgr |= (PllSrc << PLLSRC);
	RCC->PLLCFGR = pllcfgr;
	if(PllSrc == PLL_HSE){
	
	Rcccr &= ~(1 << HSEBYP);
	Rcccr |= (ClkSrc << HSEBYP);
	RCC->CR = Rcccr;
	
	}
	return RCC_Ok;	
}


RCC_Return RCC_Config_HSE(HSE_ClkSrc ClkSrc){
	
	u32 Rcccr;
	Rcccr = RCC->CR;

	Rcccr &= ~(1 << HSEBYP);
	Rcccr |= (ClkSrc << HSEBYP);
	RCC->CR = Rcccr;
	
	return RCC_Ok;
}




RCC_Return PLL84clk_FrequencyConfig ( u8 Mfactor , RCC_P_DivFactor Pfactor , u16 Nfactor ){
	
	u8 pllcfgr = RCC->PLLCFGR;
	RCC_Return Status=RCC_NotOk;
	
	if((Nfactor<192)|(Nfactor>432)){
			Status = RCC_OutOfRange;
	}
	if((Mfactor<2)|(Mfactor>63)){
			Status = RCC_OutOfRange;
	}
	
	pllcfgr &= ~(PLLM);
	pllcfgr |= Mfactor << PLLM_SHIFT;
	
	pllcfgr &= ~(PLLP);
	pllcfgr |= Pfactor << PLLP_SHIFT;
	
	pllcfgr &= ~(PLLN);
	pllcfgr |= Nfactor << PLLN_SHIFT;
	
	RCC->PLLCFGR = pllcfgr;
	
	return Status;
}


RCC_Return PLL48clk_FrequencyConfig ( u8 Mfactor , RCC_Q_divFactor Qfactor , u16 Nfactor ){
	
	u8 pllcfgr = RCC->PLLCFGR;
	RCC_Return Status = RCC_NotOk;
	
	if((Nfactor<192)|(Nfactor>432)){
			Status = RCC_OutOfRange;
	}
	if((Mfactor<2)|(Mfactor>63)){
			Status = RCC_OutOfRange;
	}
	
	pllcfgr &= ~(PLLM);
	pllcfgr |= Mfactor << PLLM_SHIFT;
	
	pllcfgr &= ~(PLLQ);
	pllcfgr |= Qfactor << PLLQ_SHIFT;
	
	pllcfgr &= ~(PLLN);
	pllcfgr |= Nfactor << PLLN_SHIFT;
	
	RCC->PLLCFGR = pllcfgr;
	
	return Status;	
}




RCC_Return RCC_Enable_HSI(clk_status status){
	
	u32 Rcccr;
	u8 error_status;

	Rcccr = RCC->CR;
	Rcccr &= ~(1 << HSION);
	Rcccr |= status << HSION;
	RCC->CR = Rcccr;
	
	if ((RCC->CR & (1 << HSIRDY)) != status){
		error_status = RCC_NotOk;
	}else{
		error_status = RCC_Ok;
	}
	
	return error_status;
}


RCC_Return RCC_Enable_HSE(clk_status status, HSE_ClkSrc ClkSrc){
	
	u32 Rcccr;
	u8 error_status;

	Rcccr = RCC->CR;
	
	Rcccr &= ~(1 << HSEON);
	Rcccr |= status << HSEON;
	Rcccr &= ~(1 << HSEBYP);
	Rcccr |= ClkSrc << HSEBYP;	
	RCC->CR = Rcccr;


	if ((RCC->CR & (1 << HSERDY)) != status){
		error_status = RCC_NotOk;
	}else{
		error_status = RCC_Ok;
	}
	
	return error_status;
}


RCC_Return RCC_Enable_PLL(clk_status status){
	
	u32 Rcccr;
	u8 error_status;

	Rcccr = RCC->CR;
	Rcccr &= ~(1 << PLLON);
	Rcccr |= status << PLLON;
	RCC->CR = Rcccr;
	
	if ((RCC->CR & (1 << PLLRDY)) != status){
		error_status = RCC_NotOk;
	}else{
		error_status = RCC_Ok;
	}
	
	return error_status;	
}


ClkSource RCC_Check_RunningClock(){
	
	return( ((RCC->CFGR) & 0x0c) >>2 );
}
