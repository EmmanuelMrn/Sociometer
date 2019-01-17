#include <avr/io.h>
#include <avr/interrupt.h>
#include <inttypes.h>

static volatile unsigned char flagSegundoComparador = 0 ;

void comparador_init( void ){
	ADCSRA &= ~(1<<ADEN);
	ADCSRB |= (1<<ACME);
	ACSR |= (1<<ACIE) | (3<<ACIS0);
	ADMUX |= (1<<MUX0);
}

unsigned char comparador_secFlag( void ){
	if(flagSegundoComparador){
		flagSegundoComparador=0;
		return 1;
	}
	else {
		return 0;
	}
	
}


ISR ( ANALOG_COMP_vect ){
	flagSegundoComparador = 1;
}