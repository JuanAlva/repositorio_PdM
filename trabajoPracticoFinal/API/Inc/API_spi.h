/*
 * API_spi.h
 *
 *  Created on: Apr 20, 2025
 *      Author: juan
 */

#ifndef INC_API_SPI_H_
#define INC_API_SPI_H_

#include "stm32f4xx_hal.h"
#include "fatfs.h"

// Inicializa la SD y el sistema de archivos
uint8_t SD_Init(void);

// Guarda una línea de texto en un archivo
uint8_t SD_SaveGyroData(const char *linea);

#endif /* INC_API_SPI_H_ */
