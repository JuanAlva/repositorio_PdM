/*
 * API_lcd.h
 *
 *  Created on: Apr 27, 2025
 *      Author: juan
 */

#ifndef INC_API_LCD_H_
#define INC_API_LCD_H_

#include "port.h"
#include <stdbool.h>

typedef bool bool_t;

typedef enum
{
  LCD_OK       = 0x00U,
  LCD_ERROR    = 0x01U,

} LCD_Status_t;


#define DATOS 1
#define CONTROL 0

#define LCD_DIR 0x27

#define COMANDO_INI1 0x30
#define COMANDO_INI2 0x20

//Bits de ENABLE y BACK LIGHT

#define EN (1<<2)
#define BL (1<<3)

// Comandos de control

#define CLR_LCD 1
#define RETURN_HOME (1<<1)
#define ENTRY_MODE (1<<2)
#define DISPLAY_CONTROL (1<<3)
#define CURSOR_DISPLAY_SHIFT (1<<4)
#define FUNTION_SET (1<<5)
#define SET_CGRAM (1<<6)
#define SET_DDRAM (1<<7)

// Subcomandos

#define DISPLAY_ON (1<<2)
#define CURSOR_ON (1<<1)
#define CURSOR_BLINK 1
#define AUTOINCREMENT (1<<1)
#define _4BIT_MODE 0x28

//DEMORAS NECESARIAS

#define DELAY20ms 20
#define DELAY10ms 10
#define DELAY2ms  2
#define DELAY1ms  1
#define DelayTime 1

//MANEJO DE NIBBLES
#define HIGH_NIBBLE 0xf0
#define LOW_NIBBLE 4

//LINEAS DEL LCD

#define LINEA1 0x80
#define LINEA2 0xc0

bool_t initLcd(void);

void datoLcd (uint8_t dato);
void datoAsciiLcd (uint8_t dato);
void datoBCD (uint8_t dato);
void sacaTextoLcd (uint8_t *texto);
void clrLcd(void);
void posCaracHLcd(uint8_t posH);
void posCaracLLcd(uint8_t posL);
void cursorOffLcd(void);
void cursorOnLcd(void);

#endif /* INC_API_LCD_H_ */
