#ifndef EE_24C01_H
#define EE_24C01_H

/************************************************************************************
*  Published on: 28-05-2016                                                        *
*  Author: jnk0le@hotmail.com                                                      *
*  https://github.com/jnk0le                                                       *
*  This library is distributed under MIT license terms                             *
************************************************************************************/

void eewrite(uint8_t device, uint8_t addr, uint8_t dat);
uint8_t eeread(uint8_t device, uint8_t addr);
void eereadto(uint8_t device, uint8_t addr, uint8_t *dat);

void ee_write_page(uint8_t device, uint8_t addr, uint8_t len, uint8_t *buf);
void ee_read_page(uint8_t device, uint8_t addr, uint8_t len, uint8_t *buf);

#endif