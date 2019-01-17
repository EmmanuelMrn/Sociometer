#ifndef _ADC_H
#define _ADC_H

#include <inttypes.h>
#include <avr/interrupt.h>
#include <avr/io.h>

void ADC_init( void );
uint8_t ADC_read( void );

#endif