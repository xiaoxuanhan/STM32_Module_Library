#ifndef __ALARM_H__
#define __ALARM_H__
#include "stdint.h"
	void alarm_init(void);
	void alarm_on(void);
	void alarm_off(void);
	uint8_t alarm_status_get();
#define ALARM_STATUS_ON 0
#define ALARM_ATATUS_OFF 1

#endif
