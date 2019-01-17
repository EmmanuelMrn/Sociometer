#include <avr/interrupt.h>
#include <inttypes.h>

//timer 8kHz for check the adc
void Timermic_Init ( void ){
	TCNT1  = 0;	//incializando timer en 0
	TCCR1A |= (1<<COM1A0) ;	//Compare Output Mode for Channel A Tooggle

	OCR1A  = 20; //TOP 	
	TCCR1B |= (3<<CS10) | (1<<WGM12);	//No PS and CTC enable
}
