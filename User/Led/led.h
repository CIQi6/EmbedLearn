#ifndef __LED_H
#define	__LED_H

#include "stm32f10x.h"
#define LED1_GPIO_PORT    	GPIOB			              /* GPIO端口 */
#define LED1_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO端口时钟 */
#define LED1_GPIO_PIN		    GPIO_Pin_0			          /* 连接到SCL时钟线的GPIO */

void LED_Init(void);
void LED1_ON(void);
void LED1_OFF(void);
#endif /* __LED_H */
