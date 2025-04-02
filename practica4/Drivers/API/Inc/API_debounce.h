/*
 * API_debounce.h
 *
 *  Created on: Apr 2, 2025
 *      Author: juan
 */

#ifndef API_INC_API_DEBOUNCE_H_
#define API_INC_API_DEBOUNCE_H_

#include <stdint.h>
#include <stdbool.h>
#include "API_delay.h"
#include "stm32f4xx_hal.h"

typedef enum {
	BUTTON_UP,
	BUTTON_FALLING,
	BUTTON_DOWN,
	BUTTON_RAISING
} debounceState;

void debounceFSM_init();
void debounceFSM_update();

void buttonPressed();
void buttonReleased();

bool_t readKey();

#endif /* API_INC_API_DEBOUNCE_H_ */
