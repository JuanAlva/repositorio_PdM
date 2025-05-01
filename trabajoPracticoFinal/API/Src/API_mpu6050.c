/*
 * API_mpu6050.c
 *
 *  Created on: Apr 26, 2025
 *      Author: juan
 */


#include "API_mpu6050.h"

void sensorInit(SensorMPU6050 *sensor) {
    sensorWriteOneRegister(sensor, PWR_MGMT, WAKEUP);
}

void sensorReadGyroscopeX(SensorMPU6050 *sensor, int16_t *gyro_x) {
    sensorReadTwoRegister(sensor, GYRO_XOUT, gyro_x);
}

void sensorReadGyroscopeY(SensorMPU6050 *sensor, int16_t *gyro_y) {
    sensorReadTwoRegister(sensor, GYRO_YOUT, gyro_y);
}

void sensorReadGyroscopeZ(SensorMPU6050 *sensor, int16_t *gyro_z){
    sensorReadTwoRegister(sensor, GYRO_ZOUT, gyro_z);
}

void sensorReadAccelerationX(SensorMPU6050 *sensor, int16_t *accel_x){
    sensorReadTwoRegister(sensor, ACEL_XOUT, accel_x);
}

void sensorReadAccelerationY(SensorMPU6050 *sensor, int16_t *accel_y){
    sensorReadTwoRegister(sensor, ACEL_YOUT, accel_y);
}

void sensorReadAccelerationZ(SensorMPU6050 *sensor, int16_t *accel_z){
    sensorReadTwoRegister(sensor, ACEL_ZOUT, accel_z);
}

void sensorReadTemperature(SensorMPU6050 *sensor, int16_t *temp){
    sensorReadTwoRegister(sensor, TEMP_OUT, temp);
}

void sensorReadAll(SensorMPU6050 *sensor){
    sensorRead14Regs(sensor);
}
