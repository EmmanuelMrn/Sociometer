#ifndef _RELOJ0_H
#define _RELOJ0_H

void Clock_Init(uint8_t hora, uint8_t minutos, uint8_t segundos, uint8_t month, uint8_t day, uint8_t year);
void Clock_Display(void);
void Clock_Update( void );


#endif