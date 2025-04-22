/*
 * API_uart.h
 *
 *  Created on: Apr 19, 2025
 *      Author: juan
 */

#ifndef API_INC_API_UART_H_
#define API_INC_API_UART_H_

#include "stm32f4xx_hal.h"
#include "API_i2c.h"
#include <stdint.h>
#include <stdio.h>

void UART_SendGyroData(UART_HandleTypeDef *huart, MPU6050_GyroData *data);

#endif /* API_INC_API_UART_H_ */
