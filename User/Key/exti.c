#include "exti.h"

 /**
  * @brief  配置嵌套向量中断控制器NVIC
  * @param  无
  * @retval 无
  */
static void NVIC_Configuration(void){
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	/* 配置中断源 */
	NVIC_InitStructure.NVIC_IRQChannel = macEXTI_IRQ;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

 /**
  * @brief  配置 PC13 为线中断口，并设置中断优先级
  * @param  无
  * @retval 无
  */
void EXTI_Pxy_Config(void){
	
	EXTI_InitTypeDef EXTI_InitStructure; 
	RCC_APB2PeriphClockCmd(macEXTI_GPIO_CLK, ENABLE);
	NVIC_Configuration();
  GPIO_EXTILineConfig(macEXTI_SOURCE_PORT, macEXTI_SOURCE_PIN); 
	EXTI_InitStructure.EXTI_Line = macEXTI_LINE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
}
