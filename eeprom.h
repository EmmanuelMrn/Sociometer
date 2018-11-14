#ifndef _EEPROM_H
#define _EEPROM_H

unsigned char EEPROM_read(unsigned int uiAddress);
void EEPROM_write(unsigned int uiAddress, unsigned char ucData);
void EEPROM_writeString( unsigned int uiAddress, unsigned char *ucData );

#endif