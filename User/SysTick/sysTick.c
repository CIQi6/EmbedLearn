#include "sysTick.h"
#include "usart1.h"
static __IO u32 TimingDelay;

/**
  * @brief  初始化 SysTick
  * @param  无
  * @retval 无
  */
void SysTick_Init(void) {
	if (SysTick_Config(SystemCoreClock / 100000)) {
		while (1);
	}
	// 关闭sysTick
	SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk;
}

/**
	* @brief 启动SysTick
	* @param 无
	* @retval 无
*/
void SysTick_Start(void) {
  USART1_SendString("SysTick Start\n");
	SysTick->CTRL |= ~ SysTick_CTRL_ENABLE_Msk;
}


/**
	* @brief 停止SysTick
	* @param 无
	* @retval 无
*/
void SysTick_Stop(void) {
  USART1_SendString("SysTick Stop\n");
	SysTick->CTRL |= ~ SysTick_CTRL_ENABLE_Msk;
}


/**
  * @brief   us延时程序,10us为一个单位
  * @param  
  *		@arg nTime: Delay_us( 1 ) 则实现的延时为 1 * 10us = 10us
  * @retval  无
  */
void Delay_us(__IO u32 nTime) {
	TimingDelay = nTime;
  USART1_SendString("waiting \n");

	// 使能滴答定时器
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
	
	while(TimingDelay != 0);
}

/**
  * @brief  获取节拍程序
  * @param  无
  * @retval 无
  * @attention  在 SysTick 中断函数 SysTick_Handler()调用
  */
void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00)
	{ 
		TimingDelay--;
	}
}
