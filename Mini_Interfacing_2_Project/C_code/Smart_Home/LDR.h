/*
 * LDR.h
 *
 *  Created on: Oct 3, 2024
 *      Author: amr mohamed
 */

#ifndef LDR_H_
#define LDR_H_

#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define LDR_CHANNEL_NUM				0
#define LDR_MAX_LIGHT_INTENSITY		100
#define LDR_MAX_VOLTAGE				2.56
/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

uint8 LDR_getLightIntensity(void);

#endif /* LDR_H_ */
