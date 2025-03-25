/*
 * API_delay.h
 *
 *  Created on: Mar 22, 2025
 *      Author: juan
 */

#ifndef API_INC_API_DELAY_H_
#define API_INC_API_DELAY_H_

#include "stm32f4xx_hal.h"
#include "stdint.h"
#include "stdbool.h"

typedef	uint32_t tick_t;
typedef bool bool_t;

typedef struct{
	tick_t startTime;
	tick_t duration;
	bool_t running;
}delay_t;

void delayInit(delay_t *delay, tick_t duration);
bool_t delayRead(delay_t *delay);
void deelayWrite(delay_t *delay, tick_t duration);

#endif /* API_INC_API_DELAY_H_ */
