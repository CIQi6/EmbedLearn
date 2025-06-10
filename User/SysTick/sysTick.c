#include "sysTick.h"
#include "usart1.h"
static __IO u32 TimingDelay;

/**
  * @brief  ��ʼ�� SysTick
  * @param  ��
  * @retval ��
  */
void SysTick_Init(void) {
	if (SysTick_Config(SystemCoreClock / 100000)) {
		while (1);
	}
	// �ر�sysTick
	SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk;
}

/**
	* @brief ����SysTick
	* @param ��
	* @retval ��
*/
void SysTick_Start(void) {
  USART1_SendString("SysTick Start\n");
	SysTick->CTRL |= ~ SysTick_CTRL_ENABLE_Msk;
}


/**
	* @brief ֹͣSysTick
	* @param ��
	* @retval ��
*/
void SysTick_Stop(void) {
  USART1_SendString("SysTick Stop\n");
	SysTick->CTRL |= ~ SysTick_CTRL_ENABLE_Msk;
}


/**
  * @brief   us��ʱ����,10usΪһ����λ
  * @param  
  *		@arg nTime: Delay_us( 1 ) ��ʵ�ֵ���ʱΪ 1 * 10us = 10us
  * @retval  ��
  */
void Delay_us(__IO u32 nTime) {
	TimingDelay = nTime;
  USART1_SendString("waiting \n");

	// ʹ�ܵδ�ʱ��
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
	
	while(TimingDelay != 0);
}

/**
  * @brief  ��ȡ���ĳ���
  * @param  ��
  * @retval ��
  * @attention  �� SysTick �жϺ��� SysTick_Handler()����
  */
void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00)
	{ 
		TimingDelay--;
	}
}
