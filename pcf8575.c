//**************************************************************
// ****** FUNCTIONS FOR PCF EXPANDERS INTERFACING *******
//**************************************************************
//Compiler          : AVR-GCC
//Author            : jnk0le@hotmail.com
//                    https://github.com/jnk0le
//Date              : 18 June 2016
//License           : MIT
//**************************************************************

#include <util/twi.h>
#include "TWI_routines.h"
#include "pcf.h"

//******************************************************************
//Function  : To read IO port state.
//Arguments : SLA_R device address.
//Return    : Byte containing state of all inputs.
//Note      : All pins used as inputs have to be configured to output logic '1'
//******************************************************************
uint8_t pcf8574_read(uint8_t device)
{
	uint8_t tmp;

	twistart();
	twiwrite(device);
	tmp = twiread_ACK();
	twistop();

	return tmp;
}

//******************************************************************
//Function  : To set the IO port output state.
//Arguments : 1. SLA_W device address.
//          : 2. Byte containing state of all pins output.
//Return    :    none
//Note      : All pins used as inputs have to be configured to output logic '1'
//******************************************************************
void pcf8574_write(uint8_t device, uint8_t data)
{
	twistart();
	twiwrite(device);
	twiwrite(data);
	twistop();
}


//******************************************************************
//Function  : To read IO port state.
//Arguments : SLA_R device address.
//Return    : 16 bit unsigned integer containing state of the all inputs. (little endian)
//Note      : All pins used as inputs have to be configured to output logic '1'
//******************************************************************
uint16_t pcf8575_read(uint8_t device)
{
	uint16_t tmp;

	twistart();
	twiwrite(device);
	tmp = twiread();
	tmp |= (twiread() << 8);
	twistop();

	return tmp;
}

//******************************************************************
//Function  : To set the IO port output state.
//Arguments : 1. SLA_W device address.
//          : 2. 16 bit unsigned integer containing state of all pins output. (little endian)
//Return    :    none
//Note      : All pins used as inputs have to be configured to output logic '1'
//******************************************************************
void pcf8575_write(uint8_t device, uint16_t data)
{
	twistart();
	twiwrite(device);
	twiwrite((uint8_t)data);
	twiwrite((uint8_t)data >> 8);
	twistop();
}