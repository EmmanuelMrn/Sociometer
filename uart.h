#ifndef _UART_H
#define _UART_H

#include <avr/interrupt.h>
#include <inttypes.h>

void USART_Init( void );
void USART_Transmit( unsigned char data );
unsigned char USART_Receive( void );
unsigned char USART_available( void );
unsigned int IR_ReceiveMSG(char *str);

#endif