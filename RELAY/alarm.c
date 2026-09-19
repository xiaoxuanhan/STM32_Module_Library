#include "alarm.h"
#include "sys.h"

//初始化GPIO函数
void alarm_init(void)
{
	GPIO_InitTypeDef gpio_initstruct;
	//打开时钟
	__HAL_RCC_GPIOB_CLK_ENABLE();
	
	//调用GPIO的初始化函数
	gpio_initstruct.Pin = GPIO_PIN_7;
	gpio_initstruct.Pull = GPIO_PULLUP;
	gpio_initstruct.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_initstruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB,&gpio_initstruct);
	
	//关闭LED
	alarm_off();
}

//继电器闭合的函数
void alarm_on(void)
{
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,GPIO_PIN_RESET);
}

//继电器打开的函数
void alarm_off(void)
{
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,GPIO_PIN_SET);
}

uint8_t alarm_status_get()
{
	return (uint8_t )HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_7);
}

