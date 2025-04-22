/*
 * API_i2c.c
 *
 *  Created on: Apr 20, 2025
 *      Author: juan
 */

#include "API_i2c.h"

HAL_StatusTypeDef MPU6050_Init(I2C_HandleTypeDef *hi2c) {
    uint8_t data = 0;
    // Wake up el MPU6050 (sacarlo de sleep mode)
    data = 0x00;
    return HAL_I2C_Mem_Write(hi2c, MPU6050_ADDR, 0x6B, 1, &data, 1, HAL_MAX_DELAY);
}

HAL_StatusTypeDef MPU6050_ReadGyro(I2C_HandleTypeDef *hi2c, MPU6050_GyroData *data) {
    uint8_t raw_data[6];
    HAL_StatusTypeDef ret;

    ret = HAL_I2C_Mem_Read(hi2c, MPU6050_ADDR, 0x43, 1, raw_data, 6, HAL_MAX_DELAY);
    if (ret != HAL_OK) return ret;

    data->gyro_x = (int16_t)(raw_data[0] << 8 | raw_data[1]);
    data->gyro_y = (int16_t)(raw_data[2] << 8 | raw_data[3]);
    data->gyro_z = (int16_t)(raw_data[4] << 8 | raw_data[5]);

    return HAL_OK;
}
