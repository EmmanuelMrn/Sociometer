#include <avr/io.h>
#include <avr/interrupt.h>
#include <inttypes.h>


void USART_Init( void ){
	//Set baud rate
	UBRR1 = 103;
	//u2x=0, No parity
	UCSR1A &= ~(1<<U2X1); 
	//Enable receiver and transmitter
	UCSR1B = (1<<RXEN1)|(1<<TXEN1);
	//8data, 1stop bit
	UCSR1C &= ~(1<<USBS1);
	UCSR1C |=(3<<UCSZ10);
}

unsigned char USART_available( void ){
	return (UCSR1A & (1<<RXC1));
}

void USART_Transmit( unsigned char data ){
	/* Wait for empty transmit buffer */
	while ( !( UCSR1A & (1<<UDRE1)) );
	/* Put data into buffer, sends the data */
	UDR1 = data;
}

unsigned char USART_Receive( void ){
	/* Wait for data to be received */
	while ( !USART_available() );
	/* Get and return received data from buffer */
	return UDR1;
}

void USART_puts(char *str){
	while(*str){
		USART_Transmit(*str++);
	}

}


unsigned int IR_ReceiveMSG(char *str){
	char data = 0;
	if(USART_available){
		
		do{
			data = USART_Receive();
			*str++ = data;
			
		}while(*str != '\0');
		return 1;
	}
	
}
