/*
 * ADC.h
 *
 *  Created on: Sep 28, 2024
 *      Author: amr mohamed
 */

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
#include "ADC.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAX_VALUE							1023
#define ADC_MIN_VALUE							0
#define ADC_INTERNAL_VALUE						2.56
/*******************************************************************************
 *                             Function Prototypes                             *
 *******************************************************************************/

extern volatile uint16 g_adcData;

/*Function initialization*/
void ADC_init(void);

/*Function that reads from a specific channel and return its digital value*/
uint16 ADC_readChannel(uint8 ch_num);

#endif /* ADC_H_ */
