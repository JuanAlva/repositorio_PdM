/*
 * API_bluetooth.h
 *
 *  Created on: Apr 20, 2025
 *      Author: juan
 */

#ifndef INC_API_BLUETOOTH_H_
#define INC_API_BLUETOOTH_H_

#include "stm32f4xx_hal.h"

void bluetoothInit(void);
void bluetoothSendMessage(char *message);
int bluetoothReceiveMessage(char *buffer, int buffer_size);

#endif /* INC_API_BLUETOOTH_H_ */

