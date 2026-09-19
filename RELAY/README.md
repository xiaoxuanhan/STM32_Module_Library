# 继电器模块

## 1.模块介绍

继电器就类似于一个开关，用**小电流、低压**去控制**大电流、高压**电路，实现强弱电隔离；我的继电器是低电平触发的；

- VCC：接 5V
- GND：GND
- IN：接单片机 GPIO
- 触点侧一般接常开端和公共端；

## 2.alarm.c

```#include "led.h"
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
```

## 3.alarm.h

```#ifndef __LED_H__
#ifndef __ALARM_H__
#define __ALARM_H__

#define ALARM_STATUS_ON 0
#define ALARM_ATATUS_OFF 1

#include "stdint.h"
	void alarm_init(void);
	void alarm_on(void);
	void alarm_off(void);
	uint8_t alarm_status_get();

#endif

```
