#ifndef __EXTI_H__
#define __EXTI_H__
#include "stdint.h"

void exti_init(void);
#define TRUE 1
#define FALSE 0
uint8_t vibrate_flag_get();
void vibrate_flag_set(uint8_t value);

#endif
