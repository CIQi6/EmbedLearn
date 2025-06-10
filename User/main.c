/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/main.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */  

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "key.h"
#include "exti.h"
#include "sysTick.h"
#include "timerBase.h"
#include "led.h"
#include "usart1.h"

volatile u32 time = 0; 

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
	USART1_Init();
	LED_Init();
	Key_GPIO_Config();	
	EXTI_Pxy_Config();
	SysTick_Init();
	TIM7_Config();
	
   USART1_SendString("Program started\n");

	// key1使用查询模式
	while(1) {
		if (Key_Scan(macKEY1_GPIO_PORT, macKEY1_GPIO_PIN) == KEY_ON) {
      USART1_SendString("Key 1 pressed\n");

			LED1_ON();
			SysTick_Stop();
			TIM7_Start();
			LED1_ON();
			Delay_ms(200000);
			USART1_SendString("finish k1\n");

			LED1_OFF();
		}
	}
}




/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
