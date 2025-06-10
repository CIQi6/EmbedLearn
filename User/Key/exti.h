#ifndef __EXTI_H
#define	__EXTI_H


#include "stm32f10x.h"


/*外部中断EXIT相关宏定义*/
#define             macEXTI_GPIO_CLK                        (RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO)     
#define             macEXTI_GPIO_PORT                       GPIOC   
#define             macEXTI_GPIO_PIN                        GPIO_Pin_13
#define             macEXTI_SOURCE_PORT                     GPIO_PortSourceGPIOC
#define             macEXTI_SOURCE_PIN                      GPIO_PinSource13
#define             macEXTI_LINE                            EXTI_Line13
#define             macEXTI_IRQ                             EXTI15_10_IRQn
#define             macEXTI_INT_FUNCTION                    EXTI15_10_IRQHandler


void EXTI_Pxy_Config(void);


#endif /* __EXTI_H */
