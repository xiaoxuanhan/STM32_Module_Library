#include "exti.h"
#include "sys.h"
#include "delay.h"
#include "led.h"

uint8_t buttonA_flag = FALSE;
uint8_t buttonB_flag = FALSE;

void exti_init(void)
{
	GPIO_InitTypeDef gpio_initstruct;
	//打开时钟
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	
	//调用GPIO的初始化函数
	gpio_initstruct.Pin = GPIO_PIN_12;
	gpio_initstruct.Pull = GPIO_PULLDOWN;
	gpio_initstruct.Mode = GPIO_MODE_IT_RISING;
	HAL_GPIO_Init(GPIOA,&gpio_initstruct);
	HAL_NVIC_SetPriority(EXTI15_10_IRQn,2,0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
	
	gpio_initstruct.Pin = GPIO_PIN_5;
	gpio_initstruct.Pull = GPIO_PULLDOWN;
	gpio_initstruct.Mode = GPIO_MODE_IT_RISING;
	HAL_GPIO_Init(GPIOB,&gpio_initstruct);
	HAL_NVIC_SetPriority(EXTI9_5_IRQn,2,0);
	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
	
	
}
void EXTI15_10_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_12);
}

void EXTI9_5_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_5);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == GPIO_PIN_12)
	{
		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_12) == GPIO_PIN_SET)
		{
			buttonB_flag = TRUE;
		}
	}
	else if(GPIO_Pin == GPIO_PIN_5)
	{
		if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5) == GPIO_PIN_SET)
		{
			buttonA_flag = TRUE;
		}
	}
}

uint8_t buttonA_flag_get(void)
{
	uint8_t temp = buttonA_flag;
	buttonA_flag = FALSE;
	return temp;
}

void buttonA_flag_set(uint8_t value)
{
	buttonA_flag = value;
}

uint8_t buttonB_flag_get(void)
{
	uint8_t temp = buttonB_flag;
	buttonB_flag = FALSE;
	return temp;
}

void buttonB_flag_set(uint8_t value)
{
	buttonB_flag = value;
}