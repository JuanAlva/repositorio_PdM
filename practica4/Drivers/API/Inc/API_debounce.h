/*
 * API_debounce.h
 *
 *  Created on: Apr 2, 2025
 *      Author: juan
 */

#ifndef API_INC_API_DEBOUNCE_H_
#define API_INC_API_DEBOUNCE_H_

#include <stm32f4xx_hal.h>
#include <stdint.h>
#include <stdbool.h>

typedef bool bool_t;

void debounceFSM_init(void);
void debounceFSM_update(void);
void buttonPressed(void);
void buttonReleased(void);

bool_t readKey(void);

#endif /* API_INC_API_DEBOUNCE_H_ */
