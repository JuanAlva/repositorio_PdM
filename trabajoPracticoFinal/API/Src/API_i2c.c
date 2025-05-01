/*
 * API_i2c.c
 *
 *  Created on: Apr 20, 2025
 *      Author: juan
 */

#include "API_i2c.h"

#define REGSIZE	1
#define WAKEREG 0x6B
#define BYTESTOWRITE 1
#define DATAREG 0x43
#define BYTESTOREAD 6
#define WAKEUP 0x00

HAL_StatusTypeDef i2cInit(I2C_HandleTypeDef *hi2c) {
    uint8_t data = 0;

    data = WAKEUP;
    return HAL_I2C_Mem_Write(hi2c, GYRO_ADDR, WAKEREG, REGSIZE, &data, BYTESTOWRITE, HAL_MAX_DELAY);
}

HAL_StatusTypeDef i2cRead(I2C_HandleTypeDef *hi2c, GyroscopeData *data) {
    uint8_t raw_data[6];
    HAL_StatusTypeDef ret;

    ret = HAL_I2C_Mem_Read(hi2c, GYRO_ADDR, DATAREG, REGSIZE, raw_data, BYTESTOREAD, HAL_MAX_DELAY);
    if (ret != HAL_OK) return ret;

    data->gyro_x = (int16_t)(raw_data[0] << 8 | raw_data[1]);
    data->gyro_y = (int16_t)(raw_data[2] << 8 | raw_data[3]);
    data->gyro_z = (int16_t)(raw_data[4] << 8 | raw_data[5]);

    return HAL_OK;
}
