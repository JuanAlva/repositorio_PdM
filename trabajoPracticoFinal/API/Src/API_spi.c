/*
 * API_spi.c
 *
 *  Created on: Apr 20, 2025
 *      Author: juan
 */

#include "API_spi.h"
#include "string.h"

FATFS fs;
FIL file;
FRESULT fres;

uint8_t SD_Init(void) {
    if (f_mount(&fs, "", 1) != FR_OK) {
        return 0; // Error
    }
    return 1; // OK
}

uint8_t SD_SaveGyroData(const char *linea) {
    fres = f_open(&file, "gyro.txt", FA_OPEN_APPEND | FA_WRITE);
    if (fres != FR_OK) {
        return 0; // Error
    }

    UINT bytesWritten;
    fres = f_write(&file, linea, strlen(linea), &bytesWritten);
    f_close(&file);

    return (fres == FR_OK && bytesWritten == strlen(linea));
}

