/*
 * API_delay.c
 *
 *  Created on: Mar 22, 2025
 *      Author: juan
 */

#include "API_delay.h"

void delayInit(delay_t *delay, tick_t duration) {
	delay->duration = duration;
	delay->running = false;
}

bool_t delayRead(delay_t *delay){
	if(delay->running == false){
		delay->startTime = HAL_GetTick();
		delay->running = true;
		return false;
	}

	if((HAL_GetTick() - delay->startTime) >= delay->duration){
		delay->running = false;
		return true;
	}

	return false;
}

void delayWrite(delay_t *delay, tick_t duration) {
	delay->duration = duration;
	delay->running = false;
}

bool_t delayIsRunning(delay_t *delay){
	return delay->running;
}
