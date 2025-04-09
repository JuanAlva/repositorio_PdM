/*
 * API_debounce.c
 *
 *  Created on: Apr 2, 2025
 *      Author: juan
 */

#include "API_debounce.h"
#include "API_delay.h"

#define DEBOUNCE_DELAY 40

#define BUTTON_PIN GPIO_PIN_13
#define BUTTON_PORT GPIOC
#define LED_PIN GPIO_PIN_5
#define LED_PORT GPIOA

typedef enum {
	BUTTON_UP,
	BUTTON_FALLING,
	BUTTON_DOWN,
	BUTTON_RAISING,
} debounceState_t;

static debounceState_t currentState;
static bool_t keyPressed;
bool_t edge;
delay_t debounceDelay;

void debounceFSM_init() {
	currentState = BUTTON_UP;
	keyPressed = false;
}

void debounceFSM_update() {
	switch (currentState) {
		case BUTTON_UP:
			if (HAL_GPIO_ReadPin(BUTTON_PORT, BUTTON_PIN) == GPIO_PIN_RESET) {
				delayInit(&debounceDelay, DEBOUNCE_DELAY);
				currentState = BUTTON_FALLING;
			}
			break;

		case BUTTON_FALLING:
			if (delayRead(&debounceDelay) == true) {
				if (HAL_GPIO_ReadPin(BUTTON_PORT, BUTTON_PIN) == GPIO_PIN_RESET) {
					// buttonPressed();
					keyPressed = true;
					edge = true;
					currentState = BUTTON_DOWN;

				}
				else {
					currentState = BUTTON_UP;
				}

			}
			break;


		case BUTTON_DOWN:
			if (HAL_GPIO_ReadPin(BUTTON_PORT, BUTTON_PIN) == GPIO_PIN_SET) {
				delayInit(&debounceDelay, DEBOUNCE_DELAY);
				currentState = BUTTON_RAISING;
			}
			break;

		case BUTTON_RAISING:
			if (delayRead(&debounceDelay) == true) {
				if (HAL_GPIO_ReadPin(BUTTON_PORT, BUTTON_PIN) == GPIO_PIN_SET) {
					// buttonReleased();
					edge = false;
					currentState = BUTTON_UP;
				}
				else {
					currentState = BUTTON_DOWN;
				}
			}
			break;

		default:
			debounceFSM_init();
			break;
	}
}

void buttonPressed() {
	HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_SET);
}

void buttonReleased() {
	HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_RESET);
}

bool_t readKey() {
	if (keyPressed == true) {
		keyPressed = false;
		return true;
	}
	return false;
}
