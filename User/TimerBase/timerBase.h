#ifndef TIME_TEST_H
#define TIME_TEST_H


#include "stm32f10x.h"

/********************基本定时器TIM参数定义，只限TIM6、7************/
#define macTIM7 // 如果使用TIM7，注释掉这个宏即可
#define             macTIMx                 TIM7
#define             macTIM_APBxClock_FUN    RCC_APB1PeriphClockCmd
#define             macTIM_CLK              RCC_APB1Periph_TIM7
#define             macTIM_IRQ              TIM7_IRQn
#define             macTIM_INT_FUN          TIM7_IRQHandler

/**************************函数声明********************************/
void               TIM7_NVIC_Configuration                   (void);
void               TIM7_Config                               (void);
void							 TIM7_Start               							  (void);
void							 TIM7_Stop               							    (void);
#endif	/* TIME_TEST_H */
