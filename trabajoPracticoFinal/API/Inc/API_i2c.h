/*
 * API_i2c.h
 *
 *  Created on: Apr 20, 2025
 *      Author: juan
 */

#ifndef INC_API_I2C_H_
#define INC_API_I2C_H_

#include "stm32f4xx_hal.h"
#include <stdint.h>

#define GYRO_ADDR 0x68 << 1 // Dirección I2C del MPU6050

typedef struct {
    int16_t gyro_x;
    int16_t gyro_y;
    int16_t gyro_z;
} GyroscopeData;

HAL_StatusTypeDef i2cInit(I2C_HandleTypeDef *hi2c);

HAL_StatusTypeDef i2cRead(I2C_HandleTypeDef *hi2c, GyroscopeData *data);

#endif /* INC_API_I2C_H_ */
