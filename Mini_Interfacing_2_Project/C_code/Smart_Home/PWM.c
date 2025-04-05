/*
 * PWM.c
 *
 *  Created on: Oct 3, 2024
 *      Author: amr mohamed
 */
#include "PWM.h"
#include "std_types.h"
#include "common_macros.h"
#include "gpio.h"
#include <avr/io.h>



void PWM_Timer0_Start(uint8 duty_cycle)
{
	/*putting the value of duty cycle*/
	OCR0 = duty_cycle;
}

