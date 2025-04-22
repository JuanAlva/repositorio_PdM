/*
 * API_uart.c
 *
 *  Created on: Apr 19, 2025
 *      Author: juan
 */

#include "API_uart.h"
#include <string.h>
#include <stdlib.h>
#include "stm32f4xx_hal.h"

UART_HandleTypeDef huart2;

#define INITMSG "\n\rUART inicializada: 9600 8N1\n\r"
#define UART_MAX_STRING_SIZE 1024
#define PROMPT "\n\rIngrese 'c' para reiniciar el terminal"

bool_t uartInit(void)
{
	huart2.Instance = USART2;
	huart2.Init.BaudRate = 9600;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart2) != HAL_OK){
		return false;
	}
	// Limpieza de terminal
	HAL_UART_Transmit(&huart2, (uint8_t*)"\033[0;0H", strlen("\033[0;0H"), HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t*)"\033[2J", strlen("\033[2J"), HAL_MAX_DELAY);
	// Parametros de configuracion
	HAL_UART_Transmit(&huart2, (uint8_t*)INITMSG, strlen(INITMSG), HAL_MAX_DELAY);
	return true;
}

void uartSendString(uint8_t *pstring)
{
	if (pstring == NULL) return;

	uint16_t len = strlen((char *)pstring);

	if (len > UART_MAX_STRING_SIZE) return;

	HAL_UART_Transmit(&huart2, pstring, len, HAL_MAX_DELAY);
}

void uartSendStringSize(uint8_t *pstring, uint16_t size)
{
	if (pstring == NULL) return;

	if (size <= 0 || size > strlen((char *)pstring)) return;

	HAL_UART_Transmit(&huart2, pstring, size, HAL_MAX_DELAY);
}

void uartReceiveStringSize(uint8_t *pstring, uint16_t size)
{
	if (pstring == NULL) return;

	if (size <= 0 || size > strlen((char *)pstring)) return;

	HAL_UART_Receive(&huart2, pstring, size, HAL_MAX_DELAY);
}

char readUserInput(void)
{
	char readBuf[1];

	HAL_UART_Transmit(&huart2, (uint8_t*)PROMPT, strlen(PROMPT), HAL_MAX_DELAY);
	HAL_UART_Receive(&huart2, (uint8_t*)readBuf, 1, HAL_MAX_DELAY);

	return readBuf;
}
