/*
	Proyecto Sociometro
	Moran Carrillo José Emmanuel
*/

#include<avr/io.h>
#include<avr/interrupt.h>
#include "Serial.h"
#include "delay.h"
#include "Timer0.h"
#include "Timer1.h"
#include "comunicacion.h"
#include "reloj.h"
#include "uart.h"
#include "eeprom.h"
#include "adc.h"
#include "comparador.h"

char dato;
char dataE;
char cad[20];

int main(void)
{
	USB_SerialInit(9600);
	sei();
	
	dato = USB_Rx(); // Inicia programa
	
	USB_putsTX("Reloj");
	USB_TX(10);
	USB_TX(13);
			
	Clock_Init(23,59,55,1,17,19); //hours, minutes, seconds, month, day, year
	Timer0_Init(); //Habilita reloj del sistema
	
	/* Comparador Test */
		comparador_init();
		DDRB |=(1<<PD7);
	
	/*  Tx y Rx Test
		DDRB |=(1<<PB5); //Out OC1A 
			
		Timer1_Init(); //38KHz
		
		USART_Init();
	*/
	
	
	/* Configura terminales de Led example
		DDRD |=(1<< PD5);
		PORTD &= ~(1<<PD5);

		DDRB |=(1<< PB0);
		PORTB &= ~(1<<PB0);

		DDRC |=(1<< PC7);
	*/
	
    
	 while(1){
		/* Testing led example
			PORTC |= (1<<PC7);
			USB_TX('-');	
			delay();
			
			PORTC &= ~(1<<PC7);
			USB_TX('x');
			delay();
			
			PORTC |= (1<<PC7);
			dato = USB_Rx();
			USB_TX(dato);
			delay();
		*/
		
		/*Test Transmision 
			delay();
			
			USART_puts("Hola");
			USB_TX(10);
			USB_TX(13);
		*/
		
		/* Testing EEPROM 
			EEPROM_write(0x03F4, 0x55);
			EEPROM_write(0x0400, 0xaa);
			
			delay();
			
			dataE = EEPROM_read(0x03F4);
			USB_TX(dataE);
			dataE = EEPROM_read(0x0400);
			USB_TX(dataE);
		*/
		
		
		/* Test Recepcion
			if(USART_available()){
				IR_ReceiveMSG(cad);
			}
		*/
		
		/* Comparador Test
			if(comparador_secFlag()){
				USB_TX("sound");
				USB_TX(10);
				USB_TX(13);
			}
		*/
	 }
	 
	 return 0; 
}


