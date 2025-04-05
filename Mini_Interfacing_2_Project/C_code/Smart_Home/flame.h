/*
 * flame.h
 *
 *  Created on: Oct 3, 2024
 *      Author: amr mohamed
 */

#ifndef FLAME_H_
#define FLAME_H_

#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define FLAMESENSOR_PORT_ID		PORTD_ID
#define FLAMESENSOR_PIN_ID		PIN2_ID
/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*Initialization*/
void FlameSensor_init(void);

/*getting the sensor value*/
uint8 FlameSensor_getValue(void);

#endif /* FLAME_H_ */
