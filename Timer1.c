#include <avr/interrupt.h>
#include <inttypes.h>

void Timer1_Init ( void ){
	TCNT1  = 0;	//incializando timer en 0
	TCCR1A |= (1<<COM1A0) ;	//Compare Output Mode for Channel A Tooggle

	OCR1A  = 104; //TOP 	
	TCCR1B |= (1<<CS10) | (1<<WGM12);	//No PS and CTC enable
}
