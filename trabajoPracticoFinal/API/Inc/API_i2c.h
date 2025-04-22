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

#define MPU6050_ADDR 0x68 << 1 // Dirección I2C del MPU6050 (shifted)

typedef struct {
    int16_t gyro_x;
    int16_t gyro_y;
    int16_t gyro_z;
} MPU6050_GyroData;

// Inicializa el MPU6050
HAL_StatusTypeDef MPU6050_Init(I2C_HandleTypeDef *hi2c);

// Lee los datos del giroscopio
HAL_StatusTypeDef MPU6050_ReadGyro(I2C_HandleTypeDef *hi2c, MPU6050_GyroData *data);

#endif /* INC_API_I2C_H_ */
