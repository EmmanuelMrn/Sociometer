#ifndef _COMPARADOR_H
#define _COMPARADOR_H

#include <inttypes.h>
#include <avr/interrupt.h>
#include <avr/io.h>

void comparador_init( void );
unsigned char comparador_secFlag( void );
ISR ( ANALOG_COMP_vect );

#endif