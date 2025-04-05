/*
 * buzzer.h
 *
 *  Created on: Oct 3, 2024
 *      Author: amr mohamed
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define BUZZER_PORT_ID		PORTD_ID
#define BUZZER_PIN_ID		PIN3_ID
/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*function for initialization*/
void Buzzer_init(void);

/*function for turning the buzzer on*/
void Buzzer_on(void);

/*function for turning the buzzer off*/
void Buzzer_off(void);

#endif /* BUZZER_H_ */
