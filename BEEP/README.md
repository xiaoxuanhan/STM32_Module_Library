# 蜂鸣器模块

## 1.模块介绍

蜂鸣器分为有源蜂鸣器和无源蜂鸣器，两者区别在于有没有震荡源，如果是有源蜂鸣器直接给低电平就可以让蜂鸣器响起来，但是如果是无源蜂鸣器的话就要用方波来驱动蜂鸣器模块；（到底给低电平还是高电平在于蜂鸣器模块上面写的是低电平驱动还是高电平驱动）；

vcc---3.3v/5v

gnd---gnd

in---gpio

## 2.beep.c

```#include "led.h"
#include "beep.h"
#include "sys.h"

//初始化GPIO函数
void beep_init(void)
{
	GPIO_InitTypeDef gpio_initstruct;
	//打开时钟
	__HAL_RCC_GPIOB_CLK_ENABLE();
	
	//调用GPIO的初始化函数
	gpio_initstruct.Pin = GPIO_PIN_8;
	gpio_initstruct.Pull = GPIO_PULLUP;
	gpio_initstruct.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_initstruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB,&gpio_initstruct);
	
	//关闭蜂鸣器
	beep_off();
}

//打开蜂鸣器的函数
void beep_on(void)
{
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_RESET);
}

//关闭蜂鸣器的函数
void beep_off(void)
{
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);
}



```

## 3.beep.h

```#ifndef __LED_H__
#ifndef __BEEP_H__
#define __BEEP_H__
	void beep_init(void);
	void beep_on(void);
	void beep_off(void);
#endif
```