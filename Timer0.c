//Este timer es para usar el reloj/calendario del programa

#include <avr/interrupt.h>
#include <inttypes.h>
#include "reloj.h"

static volatile uint8_t SecFlag;

void Timer0_Init ( void ){
	TCNT0  = 0;	//incializando timer en 0
	TCCR0A = (2<<WGM00);	//CTC enable
	
	TIMSK0 = (1<<OCIE0A);	//Output cmp match A interrupt enable
	OCR0A  = 125 -1;		//TOP 	(1ms)(8MHz)/64
	TCCR0B = (3<<CS00);		//64 PS
	sei();	//interrupciones globales

}



ISR (TIMER0_COMPA_vect) 
{ 
	static uint16_t mSecCnt;
	mSecCnt++; /* Incrementa contador de milisegundos */
	if( mSecCnt == 1000 ){
		Clock_Update();		//actualizando reloj	
		mSecCnt = 0;		//reiniciando cuenta de ms
		Clock_Display();
	}
}
