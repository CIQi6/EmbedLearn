#ifndef __KEY_H
#define	__KEY_H

#include "stm32f10x.h"

#define KEYI_PA0

#ifdef KEYI_PA0
#define               macKEY1_GPIO_CLK                      RCC_APB2Periph_GPIOA
#define               macKEY1_GPIO_PORT    	                GPIOA			   
#define               macKEY1_GPIO_PIN		                  GPIO_Pin_0

#define								maxKEY2_GPIO_CLK											RCC_APB2Periph_GPIOC
#define               macKEY2_GPIO_PORT    	                GPIOC			   
#define               macKEY2_GPIO_PIN		                  GPIO_Pin_13

#endif

#define KEY_ON  1
#define KEY_OFF 0

void Key_GPIO_Config(void);
uint8_t Key_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
#endif /* __KEY_H */
