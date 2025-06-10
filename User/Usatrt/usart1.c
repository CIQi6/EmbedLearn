#include "stm32f10x.h"
#include "usart1.h"


/// ≈‰÷√USART1Ω” ’÷–∂œ
void NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure; 
	/* Configure the NVIC Preemption Priority Bits */  
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	
	/* Enable the USARTy Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = macUSART_IRQ;	 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void USART1_Init(void) {
	  USART_InitTypeDef USART_InitStructure;
	  GPIO_InitTypeDef GPIO_InitStructure;

		NVIC_Configuration();
    // ?? USART1 ? GPIOA ??
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);

    // ?? USART1 Tx ?? (PA9) ? Rx ?? (PA10)
    GPIO_InitStructure.GPIO_Pin = macUSART_TX_PIN;  // Tx ??
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  // ????
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(macUSART_TX_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = macUSART_RX_PIN;  // Rx ??
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  // ????
    GPIO_Init(macUSART_RX_PORT, &GPIO_InitStructure);

    // ?? USART1 ?????? 9600
    USART_InitStructure.USART_BaudRate = 9600; 
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
    USART_Init(USART1, &USART_InitStructure);

    // ?? USART1
    USART_Cmd(USART1, ENABLE);
}

void USART1_SendChar(char ch) {
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);  // ?????????
    USART_SendData(USART1, (uint8_t)ch);  // ????
}

void USART1_SendString(const char *str) {
    while (*str) {
        USART1_SendChar(*str++);
    }
}
