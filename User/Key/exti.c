#include "exti.h"

 /**
  * @brief  ����Ƕ�������жϿ�����NVIC
  * @param  ��
  * @retval ��
  */
static void NVIC_Configuration(void){
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	/* �����ж�Դ */
	NVIC_InitStructure.NVIC_IRQChannel = macEXTI_IRQ;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

 /**
  * @brief  ���� PC13 Ϊ���жϿڣ��������ж����ȼ�
  * @param  ��
  * @retval ��
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
