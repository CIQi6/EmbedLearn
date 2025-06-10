/**
	* @brief 配置 GPIO 
	* @Parm 
	@ @Retval
*/
#include "key.h"

/**
  * @brief  配置按键用到的I/O口
  * @param  无
  * @retval 无
  */
void Key_GPIO_Config(void) {
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// 配置key1
	/* 开启按钮端口（PA）的时钟 */
	RCC_APB2PeriphClockCmd(macKEY1_GPIO_CLK, ENABLE);

	GPIO_InitStructure.GPIO_Pin = macKEY1_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // 上拉输入
	
	GPIO_Init(macKEY1_GPIO_PORT, &GPIO_InitStructure);
	
	// 配置key2 PC13 	外部中断输入
	RCC_APB2PeriphClockCmd(maxKEY2_GPIO_CLK, ENABLE);

	GPIO_InitStructure.GPIO_Pin = macKEY2_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(macKEY2_GPIO_PORT, &GPIO_InitStructure);
	
}

 /*
 * 函数名：Key_Scan
 * 描述  ：检测是否有按键按下
 * 输入  ：GPIOx：x 可以是 A，B，C，D或者 E
 *		     GPIO_Pin：待读取的端口位 	
 * 输出  ：KEY_OFF(没按下按键)、KEY_ON（按下按键）
 */
uint8_t Key_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
	if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON) {
		while(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON) ;
		return KEY_ON;
	}else {
		return KEY_OFF;
	}
}
