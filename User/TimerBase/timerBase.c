#include "timerBase.h"
#include "usart1.h"
/// TIMx,x[6,7]�ж����ȼ�����
void TIMx_NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure; 
    // �����ж���Ϊ0
    //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
		
		// �����ж���Դ
    NVIC_InitStructure.NVIC_IRQChannel = macTIM_IRQ;
	
		// ���������ȼ�Ϊ 0
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	 
	  // ������ռ���ȼ�Ϊ3
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

// ������ʱ������
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
