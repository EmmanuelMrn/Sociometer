#include <avr/io.h>
#include<avr/interrupt.h>
#include <inttypes.h>
#include "Serial.h"
  
void updateUSB( void ){
	USB_SerialUpdate();
}

void USB_TX(char cad){
	USB_SerialTx(cad);	
	USB_SerialUpdate();
}

uint8_t USB_Rx( void ){
	char tecla;
	uint8_t x;
	
	do{
	
		x = USB_SerialRx( &tecla );
		USB_SerialUpdate();	
		
	}while(x == 0);
	
	return tecla;
}

void USB_putsTX(char *str){
	while(*str){
		USB_SerialTx(*str++);
	}
	
	USB_SerialUpdate();
}

void USB_getsRX(char *str){
	char dato = 'a';
	while(dato != 13){
		dato = USB_Rx();
		if(dato != 13){
			*str = dato;
			*str++;
		}
	}
	*str = 0;
}

void itoa(char *str, uint16_t number, uint8_t base){
	unsigned int cociente, residuo,count = 0, i=0, j;
	char c;
	cociente = number;
	do{
		residuo = cociente%base;
		cociente = cociente/base;
		if(residuo > 9)	//si es mayor a 9, agregar el respectivo para imprimir letra.
		{
			c = residuo + 55;
		}else{
			c = residuo + '0'; //agregar el respectivo para crear el caracter de numero
		}

		*str++ = c;
		count++;
	}while( cociente != 0 );	
	*str= '\0';
	str -=count;
	j = count -1;
	while(i < j)
	{
		if( *(str+i) != *(str+j))
		{
			c = *(str+i);
			*(str+i) = *(str+j);
			*(str+j) = c;	
		}
		i++;
		j--;
	}
}
	
unsigned int atoi(char *str){
	unsigned int num = 0, exp = 1, val, count = 0;
	while(*str)
	{
		str++;
		count++;
	}
	str--;	
	while(count != 0 )
	{
		val = *str--;	
		val = val - '0';	
		if(val >=0 && val <=9)
		{
			num = num + (val * exp);	
			exp = exp*10;
			count--;
		}
	}
	return num;
}