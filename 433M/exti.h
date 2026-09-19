#ifndef __EXTI_H__
#define __EXTI_H__
void exti_init(void);
#define TRUE 1
#define FALSE 0
#include "stdint.h"
uint8_t buttonA_flag_get(void);
void buttonA_flag_set(uint8_t value);
uint8_t buttonB_flag_get(void);
void buttonB_flag_set(uint8_t value);
#endif
