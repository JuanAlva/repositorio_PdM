/*
 * API_debounce.c
 *
 *  Created on: Apr 1, 2025
 *      Author: juan
 */


#include "API_debounce.h"

#define DEBOUNCE_TIME 40

static debounceState_t debounceState;
static delay_t debounceDelay;
static bool_t buttonPressedFlag = false;

void debounceFSM_init() {
    debounceState = BUTTON_UP;
    delayInit(&debounceDelay, DEBOUNCE_TIME);
}

static bool readButton() {
    return HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET;
}

void debounceFSM_update() {
    switch (debounceState) {
        case BUTTON_UP:
            if (readButton()) {
                debounceState = BUTTON_FALLING;
                delayInit(&debounceDelay, DEBOUNCE_TIME);
            }
            break;

        case BUTTON_FALLING:
            if (delayRead(&debounceDelay)) {
                if (readButton()) {
                    debounceState = BUTTON_DOWN;
                    buttonPressed();
                    buttonPressedFlag = true;
                } else {
                    debounceState = BUTTON_UP;
                }
            }
            break;

        case BUTTON_DOWN:
            if (!readButton()) {
                debounceState = BUTTON_RAISING;
                delayInit(&debounceDelay, DEBOUNCE_TIME);
            }
            break;

        case BUTTON_RAISING:
            if (delayRead(&debounceDelay)) {
                if (!readButton()) {
                    debounceState = BUTTON_UP;
                    buttonReleased();
                } else {
                    debounceState = BUTTON_DOWN;
                }
            }
            break;
    }
}

void buttonPressed() {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
}

void buttonReleased() {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
}

bool_t readKey() {
    if (buttonPressedFlag) {
        buttonPressedFlag = false;
        return true;
    }
    return false;
}
