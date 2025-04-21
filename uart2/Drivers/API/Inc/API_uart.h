/*
 * API_uart.h
 *
 *  Created on: Apr 18, 2025
 *      Author: juan
 */

#ifndef API_INC_API_UART_H_
#define API_INC_API_UART_H_

#include <stdbool.h>
#include <string.h>
#include <stdint.h>

typedef bool bool_t;

bool_t uartInit();
void uartSendString(uint8_t *pstring);
void uartSendStringSize(uint8_t *pstring, uint16_t size);
void uartReceiveStringSize(uint8_t *pstring, uint16_t size);



#endif /* API_INC_API_UART_H_ */
