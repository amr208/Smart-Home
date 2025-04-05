/*
 * ADC.c
 *
 *  Created on: Sep 28, 2024
 *      Author: amr mohamed
 */

#include <avr/io.h>
#include "common_macros.h"
#include "ADC.h"
#include "std_types.h"
#include <avr/delay.h>

/*ADC initialization*/
void ADC_init(void)
{
	/*to work with Internal 2.56V Voltage Reference we set the next two bits*/
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);

	/*Enabling ADC*/
	SET_BIT(ADCSRA,ADEN);

	/*Setting the next three bits to 1, to choose 128 prescalar*/
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
}


uint16 ADC_readChannel(uint8 ch_num)
{
	/*making sure the register reads the ch_num only*/
	ADMUX &= 0xE0;
	ADMUX |= (ch_num & 0x07);

	/* write this bit to one to start each conversion*/
	SET_BIT(ADCSRA,ADSC);

	while(BIT_IS_CLEAR(ADCSRA,ADIF))
		{
			/*waiting until an ADC conversion completes and the Data Registers are updated*/
		}

		/*Clearing the ADC Interrupt Flag manually*/
		SET_BIT(ADCSRA,ADIF);

		/*the ADC register holds the value that the ADC reads*/
		return ADC;
}

