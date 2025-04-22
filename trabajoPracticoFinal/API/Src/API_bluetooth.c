/*
 * API_bluetooth.c
 *
 *  Created on: Apr 20, 2025
 *      Author: juan
 */


#include "API_bluetooth.h"
#include "stm32f4xx_hal.h"
#include <string.h>

// Configuración del puerto serie (UART)
extern UART_HandleTypeDef huart1;

void Bluetooth_Init(void) {
    // Inicialización del puerto UART para comunicación Bluetooth
    HAL_UART_Init(&huart1);
}

void Bluetooth_SendMessage(char *message) {
    // Enviar el mensaje por UART
    HAL_UART_Transmit(&huart1, (uint8_t*)message, strlen(message), HAL_MAX_DELAY);
}

int Bluetooth_ReceiveMessage(char *buffer, int buffer_size) {
    // Recibir mensaje por UART
    return HAL_UART_Receive(&huart1, (uint8_t*)buffer, buffer_size, HAL_MAX_DELAY);
}

/*void Bluetooth_SetConfig(uint32_t baud_rate) {
    // Configurar el baud rate del puerto UART para el módulo Bluetooth
    BLUETOOTH_UART.Init.BaudRate = baud_rate;
    HAL_UART_Init(&BLUETOOTH_UART);
}*/
