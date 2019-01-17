#include <avr/interrupt.h>
#include <avr/io.h>
#include <inttypes.h>

void ADC_init( void ){ // 10bits, ON, clk -> PS=128, ADC1, VREF=vcc
	ADMUX  = (1<<MUX0 ) | ( 1<<REFS0 ); //vref=vcc , mux=adc1
	ADCSRA = (1<<ADEN ) | ( 7<<ADPS0 ); //enabled, CLK=125Khz
}

uint8_t ADC_read( void ){
	uint16_t result;
	ADCSRA|=(1<<ADSC); //start conversion
	while( ADCSRA & (1<<ADSC) ); // WAITING
	result=ADCL;
	result|=(ADCH<<8);
	return result;
}