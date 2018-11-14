#ifndef _SERIAL0_H
#define _SERIAL0_H

void USB_SerialInit( int speed );
void USB_SerialTx( char dato );
uint8_t USB_SerialRx( char *dato );
void USB_SerialUpdate( void );

#endif