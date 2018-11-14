#ifndef _TIMER0_H
#define _TIMER0_H

#include <avr/interrupt.h>
#include <inttypes.h>
#include "reloj.h"

void Timer0_Init ( void );
ISR (TIMER0_COMPA_vect);

#endif