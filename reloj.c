#include "comunicacion.h"
#include <inttypes.h>

uint8_t seg;
uint8_t min; 
uint8_t horas;
uint8_t mes;
uint8_t dia;
uint8_t anio;

void Clock_Init(uint8_t hora, uint8_t minutos, uint8_t segundos, uint8_t month, uint8_t day, uint8_t year)
{
	seg=segundos;
	min=minutos;
	horas=hora;
	mes=month;
	dia=day;
	anio=year;
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
				dia++;
				if(dia == 28 && mes==2){
					dia=1;
					mes++;
					if(mes==12)
						mes=1;
						anio++;
				}
				if((dia==30) && (mes==4 || mes==6 || mes==9 || mes==11)){
					dia=1;
					mes++;
					if(mes==12)
						mes=1;
						anio++;
				}
				if(dia==31){
					dia=1;
					mes++;
					if(mes==12)
						mes=1;
						anio++;
				}
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
	USB_TX(' ');
	USB_TX('-');
	USB_TX(' ');
	PrintDec2d(dia);
	USB_TX('/');
	PrintDec2d(mes);
	USB_TX('/');
	PrintDec2d(anio);
}


