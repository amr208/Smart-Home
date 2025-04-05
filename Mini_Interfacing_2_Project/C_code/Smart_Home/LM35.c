/*
 * LM35.c
 *
 *  Created on: Oct 2, 2024
 *      Author: amr mohamed
 */

#include "std_types.h"
#include "ADC.h"
#include "LM35.h"
#include <util/delay.h>

uint8 LM35_GetTempValue(void)
{
	uint8 Temp = 0;

	/*reading the ADC value*/
	uint16 adcVal = ADC_readChannel(LM35_CHANNEL_NUM);

	/*General equation for having the actual temperature*/
	Temp = (uint8)(((uint32)adcVal*LM35_MAX_TEMP_VALUE*ADC_INTERNAL_VALUE)/(ADC_MAX_VALUE*LM35_MAX_VOLTAGE));

	return Temp;
}
