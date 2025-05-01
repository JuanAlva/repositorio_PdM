/*
 * API_mpu6050.h
 *
 *  Created on: Apr 26, 2025
 *      Author: juan
 */

#ifndef INC_API_MPU6050_H_
#define INC_API_MPU6050_H_

#include "port.h"

#define PWR_MGMT 0x6B
#define GYRO_XOUT 0x43
#define GYRO_YOUT 0x45
#define GYRO_ZOUT 0x47
#define ACEL_XOUT 0x3B
#define ACEL_YOUT 0x3D
#define ACEL_ZOUT 0x3F
#define TEMP_OUT 0x41
#define WAKEUP 0x00

void sensorInit(SensorMPU6050 *sensor);

SensorMPU6050 sensorRead(SensorMPU6050 *sensor);

void sensorReadGyroscopeX(SensorMPU6050 *sensor, int16_t *gyro_x);
void sensorReadGyroscopeY(SensorMPU6050 *sensor, int16_t *gyro_y);
void sensorReadGyroscopeZ(SensorMPU6050 *sensor, int16_t *gyro_z);

void sensorReadAccelerationX(SensorMPU6050 *sensor, int16_t *accel_x);
void sensorReadAccelerationY(SensorMPU6050 *sensor, int16_t *accel_y);
void sensorReadAccelerationZ(SensorMPU6050 *sensor, int16_t *accel_z);

void sensorReadTemperature(SensorMPU6050 *sensor, int16_t *temp);

void sensorReadAll(SensorMPU6050 *sensor);

#endif /* INC_API_MPU6050_H_ */
