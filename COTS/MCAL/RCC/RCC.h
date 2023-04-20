

#ifndef RCC_H
#define RCC_H

			/***********************Includes*******************/



			/***********************DataTypes*******************/
typedef enum {
	
	RCC_Ok=0,
	RCC_NotOk,
	RCC_OutOfRange,
	RCC_Wrong_BusName,
	
}RCC_Return;





typedef enum{

	SecuritySys_Disable =0,
	SecuritySys_Enable,


}SecuritySys_status;


typedef enum{
	
	CLK_HSI=0,
	CLK_HSE,
	CLK_PLL,
	
}ClkSource;



typedef enum{
	
	MCO1_CLK_HSI=0,
	MCO1_CLK_LSE,
	MCO1_CLK_HSE,
	MCO1_CLK_PLL,
	
}MCO_1_ClkSource;


typedef enum{
	
	MCO2_CLK_SYSCLK=0,
	MCO2_CLK_PLLI2S,
	MCO2_CLK_HSE,
	MCO2_CLK_PLL,
	
}MCO_2_ClkSource;


typedef enum{				//devide system clock by factor from 1 to 512
	
	MCO_Pre1 = 0b000,
	MCO_Pre2 = 0b100,
	MCO_Pre3 = 0b101,
	MCO_Pre4 = 0b110,
	MCO_Pre5 = 0b111,

}MCO_Prebscaller;


typedef enum{
	
	HSE_ClkSrc_crystal=0,
	HSE_ClkSrc_RC,
	
}HSE_ClkSrc;



typedef enum{
	
	PLL_HSI=0,
	PLL_HSE,
	
}PLL_ClkSrc;


typedef enum{
	
	PLLP_2 = 0b00,
	PLLP_4 = 0b01,
	PLLP_6 = 0b10,
	PLLP_8 = 0b11,
	
}RCC_P_DivFactor;


typedef enum{
	
	PLLQ_2 =  0b0010,
	PLLQ_3 =  0b0011,
	PLLQ_4 =  0b0100,
	PLLQ_5 =  0b0101,
	PLLQ_6 =  0b0110,
	PLLQ_7 =  0b0111,
	PLLQ_8 =  0b1000,
	PLLQ_9 =  0b1001,
	PLLQ_10 = 0b1010,
	PLLQ_11 = 0b1011,
	PLLQ_12 = 0b1100,
	PLLQ_13 = 0b1101,
	PLLQ_14 = 0b1110,
	PLLQ_15 = 0b1111,
	
}RCC_Q_divFactor;


typedef enum{
	
	clk_Disable=0,
	clk_Enable,

}clk_status;



typedef enum{
	
	AHB1=0,
	AHB2,		//page115
	APB1,
	APB2,
	
}RCC_BusName; 


typedef enum{				//devide system clock by factor from 1 to 512
	
	AHB_Pre1=0b0000,
	AHB_Pre2=0b1000,
	AHB_Pre4=0b1001,
	AHB_Pre8=0b1010,
	AHB_Pre16=0b1011,
	AHB_Pre64=0b1100,
	AHB_Pre128=0b1101,
	AHB_Pre256=0b1110,
	AHB_Pre512=0b1111,

}AHB_Prescaller;




typedef enum{				//devide cloch of AHB wire by factor from 1 to 16 
	
	APB1_Pre1=0,
	APB1_Pre2=4,
	APB1_Pre4,
	APB1_Pre8,
	APB1_Pre16,
	
}APB1_Prescaller;


typedef enum{				//devide cloch of AHB wire by factor from 1 to 16
	
	APB2_Pre1=0,
	APB2_Pre2=4,
	APB2_Pre4,
	APB2_Pre8,
	APB2_Pre16,

}APB2_Prescaller;


typedef enum{

	RCC_DMA2=22,
	RCC_DMA1=21,
	RCC_CRC=12,
	RCC_GPIOH=7,
	RCC_GPIOE=4,
	RCC_GPIOD=3,
	RCC_GPIOC=2,
	RCC_GPIOB=1,
	RCC_GPIOA=0,
	
}RCC_AHB1_Peripheras;



typedef enum{
	
	RCC_PWR=28,
	RCC_I2C3=23,
	RCC_I2C2=22,
	RCC_I2C1=21,
	RCC_USART2=17,
	RCC_SPI3=15,
	RCC_SPI2=14,
	RCC_WWDG=11,
	RCC_TIM5=3,
	RCC_TIM4=2,
	RCC_TIM3=1,
	RCC_TIM2=0,
	
}RCC_APB1_Peripheras;



typedef enum{
	
	RCC_TIM11=18,
	RCC_TIM10=17,
	RCC_TIM9=16,
	RCC_SYSCFG=14,
	RCC_SPI1=12,
	RCC_SDIO=11,
	RCC_ADC1=8,
	RCC_USART6=5,
	RCC_USART1=4,
	RCC_TIM1=0,
	
}RCC_APB2_Peripheras;



typedef enum{
	
	RCC_Periph_Disable=0,
	RCC_Periph_Enable,
	///note: each bus had its periph enable register.starting from page 118....
	//and i need it's bits num in the functions impementation..
}RCC_Peripheral_Status; 





			/***********************APIs*******************/

RCC_Return RCC_Select_SecuritySys_Status(SecuritySys_status status);

RCC_Return RCC_Select_ClockSource(ClkSource ClkSrc);



RCC_Return RCC_SelectAHB_Prescaller(AHB_Prescaller Prescaller);

RCC_Return RCC_SelectAPB1_Prescaller(APB1_Prescaller Prescaller);

RCC_Return RCC_SelectAPB2_Prescaller(APB2_Prescaller Prescaller);



RCC_Return RCC_Enable_Clock_Prepheral(RCC_BusName BusName , u64 CPY_prepheralnum );

RCC_Return RCC_Disable_Clock_Prepheral(RCC_BusName BusName , u64 CPY_prepheralnum );



RCC_Return RCC_Config_MCO1(MCO_1_ClkSource , MCO_Prebscaller);

RCC_Return RCC_Config_MCO2(MCO_2_ClkSource , MCO_Prebscaller);



//you should set the ClkSource option with HSI or HSE only..
RCC_Return RCC_Config_PLL(PLL_ClkSrc PllSrc , HSE_ClkSrc ClkSrc);

RCC_Return RCC_Config_HSE(HSE_ClkSrc ClkSrc);



// freq factors is (*N /M /P) where  192<= N <=432  ,,  2<= M <=63
RCC_Return PLL84clk_FrequencyConfig ( u8 Mfactor , RCC_P_DivFactor Pfactor , u16 Nfactor );

// freq factors is (*N /M /Q) where  192<= N <=432  ,,  2<= M <=63
RCC_Return PLL48clk_FrequencyConfig ( u8 Mfactor , RCC_Q_divFactor Qfactor , u16 Nfactor );



// you should configure the HSI befora enablibg it...
RCC_Return RCC_Enable_HSI(clk_status status);

// you should configure the HSE befora enablibg it...
RCC_Return RCC_Enable_HSE(clk_status status, HSE_ClkSrc ClkSrc);

// you should configure the PLL befora enablibg it...
RCC_Return RCC_Enable_PLL(clk_status status);


ClkSource RCC_Check_RunningClock(void);





#endif /*RCC_H*/
