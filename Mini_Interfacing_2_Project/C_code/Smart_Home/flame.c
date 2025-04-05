/*
 * flame.c
 *
 *  Created on: Oct 3, 2024
 *      Author: amr mohamed
 */

#include "flame.h"
#include "std_types.h"
#include "gpio.h"
#include "common_macros.h"

/*Flame sensor initialization*/
void FlameSensor_init(void)
{
	GPIO_setupPinDirection(FLAMESENSOR_PORT_ID, FLAMESENSOR_PIN_ID, PIN_INPUT);
}

/*reading the sensor's pin whether it's high or low*/
uint8 FlameSensor_getValue(void)
{
	if( GPIO_readPin(FLAMESENSOR_PORT_ID, FLAMESENSOR_PIN_ID))
	{
		return LOGIC_HIGH;
	}
	else
	{
		return LOGIC_LOW;
	}
}
