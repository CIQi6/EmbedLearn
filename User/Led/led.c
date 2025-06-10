#include "led.h"

void LED_Init(void) {
	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(LED1_GPIO_CLK, ENABLE);
	
	gpio.GPIO_Pin = LED1_GPIO_PIN;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LED1_GPIO_PORT, &gpio);
	
	GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
	 
}

void LED1_ON(void) {
	GPIO_ResetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
}

void LED1_OFF(void) {
	GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
}
