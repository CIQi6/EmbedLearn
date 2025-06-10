#include "timerBase.h"
#include "usart1.h"
/// TIMx,x[6,7]中断优先级配置
void TIMx_NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure; 
    // 设置中断组为0
    //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
		
		// 设置中断来源
    NVIC_InitStructure.NVIC_IRQChannel = macTIM_IRQ;
	
		// 设置主优先级为 0
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	 
	  // 设置抢占优先级为3
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

// 基本定时器配置
void TIM7_Config(void) {
	TIM_TimeBaseInitTypeDef  tim;
	TIMx_NVIC_Configuration();
	macTIM_APBxClock_FUN (macTIM_CLK, ENABLE);
	
	tim.TIM_RepetitionCounter = (uint8_t)7200 - 1;
	tim.TIM_Period = 20000 - 1;
	TIM_TimeBaseInit(macTIMx, &tim);
	
	TIM_ClearFlag(macTIMx, TIM_FLAG_Update);
	
	TIM_ITConfig(macTIMx, TIM_IT_Update, ENABLE);
	
	TIM_Cmd(macTIMx, DISABLE);
	
}

void TIM7_Start(void) {
  USART1_SendString("TIM7 Start\n");

	TIM_Cmd(TIM7, ENABLE);
}

void TIM7_Stop(void) {
  USART1_SendString("TIM7 Stop\n");
	TIM_Cmd(TIM7, DISABLE);
}
