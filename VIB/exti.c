#include "exti.h"
#include "sys.h"
#include "delay.h"
#include "led.h"

uint8_t  vibratez_flag = FALSE;

void exti_init(void)
{
	GPIO_InitTypeDef gpio_initstruct;
	//打开时钟
	__HAL_RCC_GPIOA_CLK_ENABLE();
	
	//调用GPIO的初始化函数
	gpio_initstruct.Pin = GPIO_PIN_4;
	gpio_initstruct.Pull = GPIO_PULLUP;
	gpio_initstruct.Mode = GPIO_MODE_IT_FALLING;
	HAL_GPIO_Init(GPIOA,&gpio_initstruct);
	
	HAL_NVIC_SetPriority(EXTI4_IRQn,2,0);
	HAL_NVIC_EnableIRQ(EXTI4_IRQn);
	
}
void EXTI4_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == GPIO_PIN_4)
	{
		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_4) == GPIO_PIN_RESET)
		{
			vibratez_flag = TRUE;
		}
	}
}
 
uint8_t vibrate_flag_get()
{
	uint8_t temp = vibratez_flag;
	vibratez_flag = FALSE;
	return temp;
}

void vibrate_flag_set(uint8_t value)
{
	vibratez_flag = value;
}
