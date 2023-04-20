 
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H



 
 
#define GPIO_A_BASEADDRESS				(0x40020000)

#define GPIO_B_BASEADDRESS				(0x40020400)

#define GPIO_C_BASEADDRESS				(0x40020800)

#define GPIO_D_BASEADDRESS				(0x40020C00)

#define GPIO_E_BASEADDRESS				(0x40021000)

#define GPIO_H_BASEADDRESS				(0x40021C00)





typedef struct {
	 
	volatile u32 MODER;						 			//Adress Offse : 0x00
	volatile u32 OTYPER;						 		//Adress Offse : 0x04
	volatile u32 OSPEEDR;						 		//Adress Offse : 0x08
	volatile u32 PUPDR;						 			//Adress Offse : 0x0c
	volatile u32 IDR;						 			//Adress Offse : 0x10
	volatile u32 ODR;						 			//Adress Offse : 0x14
	volatile u32 BSRR;						 			//Adress Offse : 0x18
	volatile u32 LCKR;						 			//Adress Offse : 0x1c
	volatile u32 AFRL;						 			//Adress Offse : 0x20
	volatile u32 AFRH;						 			//Adress Offse : 0x24
	 
}GPIO_t;




 GPIO_t* const GPIO_A = ((GPIO_t* const)GPIO_A_BASEADDRESS);
								
 GPIO_t* const GPIO_B = ((GPIO_t* const)GPIO_B_BASEADDRESS);
								
 GPIO_t* const GPIO_C = ((GPIO_t* const)GPIO_C_BASEADDRESS);
								
 GPIO_t* const GPIO_D = ((GPIO_t* const)GPIO_D_BASEADDRESS);
								
 GPIO_t* const GPIO_E = ((GPIO_t* const)GPIO_E_BASEADDRESS);
								
 GPIO_t* const GP_h = ((GPIO_t* const)GPIO_H_BASEADDRESS);






#endif  /*GPIO_PRIVATE_H*/
