/*
 * port.c
 *
 *  Created on: Apr 26, 2025
 *      Author: juan
 */

#include "port.h"

extern I2C_HandleTypeDef hi2c1;

void lcdWriteByte(uint8_t value){
	if(HAL_I2C_Master_Transmit (&hi2c1,LCD_DIR<<1,&value, sizeof(value),HAL_MAX_DELAY)!=HAL_OK)Error_Handler();
	// Escribe un byte al LCD por I2C usa por dirección (LCD_DIR<<1)
	// la dirección requiere un corrimiento hacia la izquierda
}

void sensorWriteOneRegister(SensorMPU6050 *sensor, uint8_t reg, uint8_t data) {
	HAL_I2C_Mem_Write(sensor->hi2c, sensor->address, reg, 1, &data, 1, HAL_MAX_DELAY);
	// Utiliza la función HAL para escribir un byte en el registro (reg)
}

void sensorReadTwoRegister(SensorMPU6050 *sensor, uint8_t reg, int16_t *value) {
	uint8_t buffer[2];

	HAL_I2C_Mem_Read(sensor->hi2c, sensor->address, reg, 1, buffer, 2, HAL_MAX_DELAY);
	// Se leen 2 bytes consecutivos desde el registro (reg)

	*value = (int16_t)(buffer[0] << 8 | buffer[1]);
	// Se combinan los dos bytes en un entero de 16 bits (big-endian)
}

void sensorRead14Regs(SensorMPU6050 *sensor){
	HAL_I2C_Mem_Read(sensor->hi2c, sensor->address, 0x3B, 1, sensor->data, 14, HAL_MAX_DELAY);
	// Lee 14 registros consecutivos a partir de 0x3B (acelerómetro + temperatura + giroscopio)
}

