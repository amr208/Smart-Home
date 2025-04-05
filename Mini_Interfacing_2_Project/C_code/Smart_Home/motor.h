/*
 * motor.h
 *
 *  Created on: Oct 3, 2024
 *      Author: amr mohamed
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "std_types.h"
/*******************************************************************************
 *                             Data Types Declarations                         *
 *******************************************************************************/
extern uint8 fanState;
/*******************************************************************************
 *                             Data Types Declarations                         *
 *******************************************************************************/
typedef enum
{
    CW,
    A_CW,
    Stop
} DcMotor_State;

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define MOTOR_IN1_PORT_ID			PORTB_ID
#define MOTOR_IN2_PORT_ID			PORTB_ID
#define MOTOR_ENABLE_PORT_ID		PORTB_ID
#define MOTOR_IN1_PIN_ID			PIN0_ID
#define MOTOR_IN2_PIN_ID			PIN1_ID
#define MOTOR_ENABLE_PIN_ID			PIN3_ID

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

void DcMotor_Init(void);

void DcMotor_Rotate(DcMotor_State state, uint8 speed);
#endif /* MOTOR_H_ */
