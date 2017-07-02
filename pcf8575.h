#ifndef PCF_H
#define PCF_H

/************************************************************************************
*  Published on: 18-06-2016                                                        *
*  Author: jnk0le@hotmail.com                                                      *
*  https://github.com/jnk0le                                                       *
*  This library is distributed under MIT license terms                             *
************************************************************************************/

uint8_t pcf8574_read(uint8_t device);
void pcf8574_write(uint8_t device, uint8_t data);

uint16_t pcf8575_read(uint8_t device);
void pcf8575_write(uint8_t device, uint16_t data);

#endif