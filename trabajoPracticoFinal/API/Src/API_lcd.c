/*
 * API_lcd.c
 *
 *  Created on: Apr 27, 2025
 *      Author: juan
 */


#include "API_lcd.h"

static void delayLcd(uint32_t demora);
static void controlLcd(uint8_t valor);
static void envia8bitsLcd (uint8_t valor,_Bool tipo);
static void envia4bitsLcd (uint8_t valor,_Bool tipo);

static const uint8_t LCD_INIT_CMD[] = {
    _4BIT_MODE,                             // Función: modo 4 bits, 2 líneas
    DISPLAY_CONTROL,                        // Desactiva display momentáneamente (DISPLAY_ON aún no activo)
    RETURN_HOME,                            // Vuelve cursor a la posición inicial
    ENTRY_MODE + AUTOINCREMENT,            // Configura para escribir de izquierda a derecha
    DISPLAY_CONTROL + DISPLAY_ON,          // Enciende display (sin cursor ni blink)
    CLR_LCD                                // Limpia pantalla
};

static void envia4bitsLcd(uint8_t valor, _Bool tipo) {
	lcdWriteByte(valor | tipo | EN | BL);
	delayLcd(DelayTime);
	lcdWriteByte(valor | tipo | BL);
	delayLcd(DelayTime);
}

static void delayLcd(uint32_t delay) {
	HAL_Delay(delay);
}

static void envia8bitsLcd (uint8_t valor,_Bool tipo){
	envia4bitsLcd(valor&HIGH_NIBBLE,tipo);
	envia4bitsLcd(valor<<LOW_NIBBLE,tipo);
}

static void controlLcd(uint8_t valor){
	envia8bitsLcd(valor,CONTROL);
}

bool_t initLcd(void){
	//if(I2C_HW_init()==LCD_ERROR)return LCD_ERROR;
	delayLcd(DELAY20ms);
	envia4bitsLcd(COMANDO_INI1,CONTROL);
	delayLcd(DELAY10ms);
	envia4bitsLcd(COMANDO_INI1,CONTROL);
	delayLcd(DELAY1ms);
	envia4bitsLcd(COMANDO_INI1,CONTROL);
	envia4bitsLcd(COMANDO_INI2,CONTROL);
	for(uint8_t i=0;i<sizeof(LCD_INIT_CMD);i++)controlLcd(LCD_INIT_CMD[i]);
	delayLcd(DELAY2ms);
	return LCD_OK;
}

void datoLcd (uint8_t dato){
	envia8bitsLcd(dato,DATOS);
}

void datoAsciiLcd (uint8_t dato){
	envia8bitsLcd(dato+ '0',DATOS);
}

void datoBCD (uint8_t dato){
	  datoAsciiLcd((((dato)&0xf0)>>4));
	  datoAsciiLcd(((dato)&0x0f));
}

void sacaTextoLcd (uint8_t *texto){
	while(*texto)datoLcd(*texto++);
}


void clrLcd(void){
   dontrolLcd(CLR_LCD);				//	Display Clear.
   delayLcd(DELAY2ms);

}

void posCaracHLcd(uint8_t posH){
	controlLcd(posH | LINEA1);
}

void posCaracLLcd(uint8_t posL){
	controlLcd(posL | LINEA2);
}


void cursorOffLcd(void){
	controlLcd(DISPLAY_CONTROL+DISPLAY_ON);
}

void cursorOnLcd(void){
	controlLcd(DISPLAY_CONTROL+CURSOR_ON+DISPLAY_ON+CURSOR_BLINK);
}
