/*
 * API_uart.c
 *
 *  Created on: Apr 3, 2025
 *      Author: juan
 */

#include "API_uart.h"
#include "stm32f4xx_hal.h"
#include <string.h>

#define UART_MAX_SIZE 256

static UART_HandleTypeDef huart2;

bool uartInit(void) {
    huart2.Instance = USART2;
    huart2.Init.BaudRate = 9600;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;

    if (HAL_UART_Init(&huart2) != HAL_OK) {
        return false;
    }

    char msg[] = "UART inicializada a 9600 8N1\r\n";
    HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

    return true;
}

void uartSendString(uint8_t *pstring)
{
	assert_param( pstring );
	uint16_t len = strlen((const char *)pstring);
	if (len == 0 || len > UART_MAX_SIZE)
	    return;

	if (HAL_UART_Transmit(&huart2, (uint8_t *)pstring, len, HAL_MAX_DELAY) != HAL_OK)
	    return;
}

void uartSendStringSize(uint8_t *pstring, uint16_t size)
{
	assert_param( pstring );
	if( size > 0 && size < UART_MAX_SIZE )
		if( HAL_UART_Transmit(&huart2, pstring, size, HAL_MAX_DELAY) != HAL_OK )
			return;

}

void uartReceiveStringSize(uint8_t *pstring, uint16_t size)
{
	assert_param( pstring );

	if( size > 0 && size < UART_MAX_SIZE )
		if( HAL_UART_Receive(&huart2, pstring, size, HAL_MAX_DELAY) != HAL_OK )
			return;
}
