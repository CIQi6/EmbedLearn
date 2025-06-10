#ifndef __SYSTICK_H
#define __SYSTICK_H

#include "stm32f10x.h"

void SysTick_Init(void);
void SysTick_Start(void);
void SysTick_Stop(void);
void Delay_us(__IO u32 nTime);
#define Delay_ms(x) Delay_us(x)	 //��λms
void TimingDelay_Decrement(void);
#endif /* __SYSTICK_H */
