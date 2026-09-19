# 震动传感器模块

## 1.模块介绍

震动传感器在检测到震动的时候会引起电平降低，平常DO口都输出高电平，那么就会引起中断；

vcc---3.3v

GND---GND

DO---GPIO(这个GPIO配置成可以引起中断的端口，那么震动传感器就可以引起中断)

## 2.exti.c

```#include "led.h"
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
	gpio_initstruct.Mode = GPIO_MODE_IT_FALLING;//下降沿触发中断
	HAL_GPIO_Init(GPIOA,&gpio_initstruct);
	
	HAL_NVIC_SetPriority(EXTI4_IRQn,2,0);// 设置EXTI4外部中断：抢占优先级2，子优先级0
	HAL_NVIC_EnableIRQ(EXTI4_IRQn);// 开启EXTI4中断，允许该中断触发
	
}
//中断服务函数
void EXTI4_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
}
//中断回调函数
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == GPIO_PIN_4)
	{
		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_4) == GPIO_PIN_RESET)//如果检测到低电平
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
```

## 3.exti.h

```#ifndef __LED_H__
#ifndef __EXTI_H__
#define __EXTI_H__

#include "stdint.h"
#define TRUE 1
#define FALSE 0

void exti_init(void);
uint8_t vibrate_flag_get();
void vibrate_flag_set(uint8_t value);

#endif
```
