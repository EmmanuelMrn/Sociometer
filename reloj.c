#include "comunicacion.h"
#include <inttypes.h>

uint8_t seg;
uint8_t min; 
uint8_t horas;

void Clock_Init(uint8_t hora, uint8_t minutos, uint8_t segundos)
{
	seg=segundos;
	min=minutos;
	horas=hora;
}

void Clock_Update( void ){
	seg++;
	
	if(seg == 60){
		seg=0;
		min++;
		if(min == 60){
			min=0;
			horas++;
			if(horas == 24)
				horas=0;
		}
	}
	
}

void PrintDec2d( uint8_t dato){
	USB_TX( dato/10 +'0'); // decenas 
	USB_TX( dato%10 +'0'); // unidades 
}


void Clock_Display( void ){
	USB_TX(13);
	PrintDec2d(horas);
	USB_TX(':');
	PrintDec2d(min);
	USB_TX(':');
	PrintDec2d(seg);
}


