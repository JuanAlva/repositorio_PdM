/*
 * API_uart.c
 *
 *  Created on: Apr 19, 2025
 *      Author: juan
 */

#include "API_uart.h"
#include "API_i2c.h"

void UART_SendGyroData(UART_HandleTypeDef *huart, MPU6050_GyroData *data) {
    char buffer[100];
    int len = snprintf(buffer, sizeof(buffer),
                       "Giroscopio:\r\nX: %d\r\nY: %d\r\nZ: %d\r\n\r\n",
                       data->gyro_x, data->gyro_y, data->gyro_z);
    HAL_UART_Transmit(huart, (uint8_t*)buffer, len, HAL_MAX_DELAY);
}
