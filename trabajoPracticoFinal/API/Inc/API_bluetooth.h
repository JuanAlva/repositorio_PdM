/*
 * API_bluetooth.h
 *
 *  Created on: Apr 20, 2025
 *      Author: juan
 */

#ifndef INC_API_BLUETOOTH_H_
#define INC_API_BLUETOOTH_H_

#include "stm32f4xx_hal.h"

// Inicializa la comunicación con el módulo Bluetooth
void Bluetooth_Init(void);

// Envia un mensaje de texto al dispositivo Bluetooth
void Bluetooth_SendMessage(char *message);

// Recibe un mensaje de texto desde el dispositivo Bluetooth
int Bluetooth_ReceiveMessage(char *buffer, int buffer_size);

// Configura parámetros específicos del módulo (como velocidad de transmisión)
//void Bluetooth_SetConfig(uint32_t baud_rate);

#endif /* INC_API_BLUETOOTH_H_ */
