/**
	* @brief ���� GPIO 
	* @Parm 
	@ @Retval
*/
#include "key.h"

/**
  * @brief  ���ð����õ���I/O��
  * @param  ��
  * @retval ��
  */
void Key_GPIO_Config(void) {
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// ����key1
	/* ������ť�˿ڣ�PA����ʱ�� */
	RCC_APB2PeriphClockCmd(macKEY1_GPIO_CLK, ENABLE);

	GPIO_InitStructure.GPIO_Pin = macKEY1_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // ��������
	
	GPIO_Init(macKEY1_GPIO_PORT, &GPIO_InitStructure);
	
	// ����key2 PC13 	�ⲿ�ж�����
	RCC_APB2PeriphClockCmd(maxKEY2_GPIO_CLK, ENABLE);

	GPIO_InitStructure.GPIO_Pin = macKEY2_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(macKEY2_GPIO_PORT, &GPIO_InitStructure);
	
}

 /*
 * ��������Key_Scan
 * ����  ������Ƿ��а�������
 * ����  ��GPIOx��x ������ A��B��C��D���� E
 *		     GPIO_Pin������ȡ�Ķ˿�λ 	
 * ���  ��KEY_OFF(û���°���)��KEY_ON�����°�����
 */
uint8_t Key_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
	if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON) {
		while(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON) ;
		return KEY_ON;
	}else {
		return KEY_OFF;
	}
}
