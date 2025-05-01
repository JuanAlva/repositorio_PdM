/*
 * port.h
 *
 *  Created on: Apr 26, 2025
 *      Author: juan
 */

#ifndef INC_PORT_H_
#define INC_PORT_H_

#include <stdint.h>
#include "stm32f4xx_hal.h"

#include "API_lcd.h"

extern void Error_Handler(void);

typedef struct {
	I2C_HandleTypeDef *hi2c;
	uint8_t address;
	uint8_t data[14];
} SensorMPU6050;

void lcdWriteByte(uint8_t value);
void sensorWriteOneRegister(SensorMPU6050 *sensor, uint8_t reg, uint8_t data);
void sensorReadTwoRegister(SensorMPU6050 *sensor, uint8_t reg, int16_t *value);
void sensorRead14Regs(SensorMPU6050 *sensor);

#endif /* INC_PORT_H_ */
