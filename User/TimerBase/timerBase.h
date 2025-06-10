#ifndef TIME_TEST_H
#define TIME_TEST_H


#include "stm32f10x.h"

/********************������ʱ��TIM�������壬ֻ��TIM6��7************/
#define macTIM7 // ���ʹ��TIM7��ע�͵�����꼴��
#define             macTIMx                 TIM7
#define             macTIM_APBxClock_FUN    RCC_APB1PeriphClockCmd
#define             macTIM_CLK              RCC_APB1Periph_TIM7
#define             macTIM_IRQ              TIM7_IRQn
#define             macTIM_INT_FUN          TIM7_IRQHandler

/**************************��������********************************/
void               TIM7_NVIC_Configuration                   (void);
void               TIM7_Config                               (void);
void							 TIM7_Start               							  (void);
void							 TIM7_Stop               							    (void);
#endif	/* TIME_TEST_H */
