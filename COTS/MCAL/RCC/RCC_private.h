#ifndef RCC_PRIVATE_H 
#define RCC_PRIVATE_H 


#define RCC_BASEADDRESS       (0x40023800)



typedef struct {
	
	volatile u32 CR;						 			//Adress Offse : 0x00
	volatile u32 PLLCFGR;                 			//Adress Offse : 0x04
	volatile u32 CFGR;                    			//Adress Offse : 0x08
	volatile u32 CIR;                     			//Adress Offse : 0x0c
	volatile u32 AHB1RSTR;                			//Adress Offse : 0x10
	volatile u32 AHB2RSTR;                			//Adress Offse : 0x14
	volatile u32 Reserved0[2];             			//Adress Offse : 0x18
	volatile u32 APB1RSTR;                			//Adress Offse : 0x20
	volatile u32 APB2RSTR;                			//Adress Offse : 0x24
	volatile u32 Reserved1[2];             			//Adress Offse : 0x28
	volatile u32 AHB1ENR;                 			//Adress Offse : 0x30
	volatile u32 AHB2ENR;                 			//Adress Offse : 0x34
	volatile u32 Reserved2[2];             			//Adress Offse : 0x38
	volatile u32 APB1ENR;                 			//Adress Offse : 0x40
	volatile u32 APB2ENR;                 			//Adress Offse : 0x44
	volatile u32 Reserved3[2];             			//Adress Offse : 0x48
	volatile u32 AHB1LPENR;               			//Adress Offse : 0x50
	volatile u32 AHB2LPENR;               			//Adress Offse : 0x54
	volatile u32 Reserved4[2];             			//Adress Offse : 0x58
	volatile u32 APB1LPENR;               			//Adress Offse : 0x60
	volatile u32 APB2LPENR;               			//Adress Offse : 0x64
	volatile u32 Reserved5[2];             			//Adress Offse : 0x68
	volatile u32 BDCR;                    			//Adress Offse : 0x70
	volatile u32 CSR;                     			//Adress Offse : 0x74
	volatile u32 Reserved6[2];             			//Adress Offse : 0x78
	volatile u32 SSCGR;                   			//Adress Offse : 0x80
	volatile u32 PLLI2SCFGR;              			//Adress Offse : 0x84
	
}RCC_t;

 volatile RCC_t* const RCC = ((RCC_t* const)RCC_BASEADDRESS);		//agrb l const de sh3`ala wala la2 bs lazem a3mloo ptr to const 3shan mynf3sh a3`yr l address da

#define CSSON				  19					//set this bit to enable the "clk security system"



#endif /* RCC_PRIVATE_H */
