/*
 * LDR.c
 *
 *  Created on: Oct 3, 2024
 *      Author: amr mohamed
 */
#include "std_types.h"
#include "ADC.h"
#include "LDR.h"
#include <util/delay.h>

uint8 LDR_getLightIntensity(void)
{
	uint8 Light = 0;

	/*reading the ADC value*/
	uint16 adcVal = 0;
	adcVal = ADC_readChannel(LDR_CHANNEL_NUM);


	/*General equation for having the actual temperature*/
	Light = (uint8)(((uint32)adcVal * LDR_MAX_LIGHT_INTENSITY * ADC_INTERNAL_VALUE) / (ADC_MAX_VALUE * LDR_MAX_VOLTAGE));
	return Light;
}


