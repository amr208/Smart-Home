/*
 * LM35.h
 *
 *  Created on: Oct 2, 2024
 *      Author: amr mohamed
 */

#ifndef LM35_H_
#define LM35_H_

#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define LM35_CHANNEL_NUM			1
#define LM35_MAX_TEMP_VALUE			150
#define LM35_MAX_VOLTAGE			1.5

/*******************************************************************************
 *                             Function Prototypes                             *
 *******************************************************************************/

/*Function to return the actual value of temperature*/
uint8 LM35_GetTempValue(void);


#endif /* LM35_H_ */
