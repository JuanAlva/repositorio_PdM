/*
 * API_bluetooth.c
 *
 *  Created on: Apr 20, 2025
 *      Author: juan
 */

#include "API_bluetooth.h"
#include "stm32f4xx_hal.h"
#include <string.h>

extern UART_HandleTypeDef huart1;

void bluetoothInit(void) {
	HAL_UART_Transmit(&huart1, (uint8_t*)"\033[0;0H", strlen("\033[0;0H"), HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart1, (uint8_t*)"\033[2J", strlen("\033[2J"), HAL_MAX_DELAY);
    HAL_UART_Init(&huart1);
}

void bluetoothSendMessage(char *message) {
    HAL_UART_Transmit(&huart1, (uint8_t*)message, strlen(message), HAL_MAX_DELAY);
}

int bluetoothReceiveMessage(char *buffer, int buffer_size) {
    return HAL_UART_Receive(&huart1, (uint8_t*)buffer, buffer_size, HAL_MAX_DELAY);
}


