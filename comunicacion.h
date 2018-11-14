#ifndef _COMUNICACION0_H
#define _COMUNICACION0_H

#include <inttypes.h>
#include "Serial.h"

unsigned int atoi(char *str);
void itoa(char *str, uint16_t number, uint8_t base);
void PrintDec2d(uint8_t dato);
void USB_TX(char cad);
void USB_putsTX(char *str);
uint8_t USB_Rx( void );
void updateUSB( void );

#endif