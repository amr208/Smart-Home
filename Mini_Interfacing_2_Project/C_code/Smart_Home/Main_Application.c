/*
 * Main_Application.c
 *
 *  Created on: Oct 3, 2024
 *      Author: amr mohamed
 */

#include <avr/io.h>
#include <util/delay.h>
#include "common_macros.h"
#include "std_types.h"
#include "ADC.h"
#include "buzzer.h"
#include "flame.h"
#include "gpio.h"
#include "LCD.h"
#include "LDR.h"
#include "LED.h"
#include "LM35.h"
#include "motor.h"
#include "PWM.h"

/*Important global variable that indicated whether the fan is turned on or off*/
uint8 fanState;

void Timer0_Init(void);

void Display_Intensity(void);

void Display_FanState(void);

void Lighting_System(void);

void Flame_Alert(void);

void Fan_Speed_Interfacing(void);

void Temp_Display(void);

int main(void)
{
	/*LED Initialization*/
	LEDS_init();

	/*FlameSensor Initialization*/
	FlameSensor_init();

	/*ADC Initialization*/
	ADC_init();

	/*LCD Initialization*/
	LCD_init();

	/*Timer Initialization*/
	Timer0_Init();

	/*Motor Initialization*/
	DcMotor_Init();

	/*Buzzer initialization*/
	Buzzer_init();

	/*Main Code Cycle*/
	while(1)
	{
		/*
		 * The home system has two main scenarios:
		 *  when the Light sensor (LDR) is sensing less light, The LEDs begin to turn on
		 *  the Fan is turned on and it's speed being controlled by the rooms temperature
		 *  the light intensity, fan state, and temperature degree are always displayed on the LCD
		 * */

		/*The LDR, LEDs interfacing with the mechanism mentioned above*/
		Lighting_System();


		/*
		 * The LM35 temperature sensor outputs an analog voltage proportional to the temperature,
		 * which is read by the ADC and converted into a digital value. Based on the temperature,
		 * the PWM signal's duty cycle is adjusted using Timer0 in Fast PWM mode. The PWM signal
		 * controls the speed of the DC motor (fan), increasing speed as the temperature rises.
		 * This provides automatic fan speed control based on temperature changes.
		 */
		Fan_Speed_Interfacing();


		/*
		 * Check the value of the flame sensor. If the flame is detected (LOGIC_HIGH),
		 * activate the buzzer and display a flame alert message on the LCD.
		 * Clear any previous messages on the first line of the LCD.
		 */
		if(FlameSensor_getValue() == LOGIC_HIGH)
		{
		    Buzzer_on();  /*Turn on the buzzer to signal flame detection.*/
		    LCD_MoveCursor(1,0);  /*Move the cursor to the first row to clear the previous message.*/
		    LCD_SendString("                ");  /* Clear the previous message on the LCD.*/
		    Flame_Alert();  /* Display a specific flame alert message or visual cue.*/
		}
		else
		{
		    Buzzer_off();  /* Turn off the buzzer when no flame is detected.*/
		    Temp_Display();  /* Show the current temperature on the LCD.*/
		    LCD_MoveCursor(0,0);  /* Clear any previous messages on the second row of the LCD.*/
		    LCD_SendString("  ");  /* Clear the previous content to avoid overlapping display.*/
		    Display_FanState();  /* Display the current state of the fan (on, off, or speed).*/
		    Display_Intensity();  /* Display the light intensity from the LDR sensor.*/
		}

	}
}

void Timer0_Init(void)
{
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);
	/*for fast PWM mode activation*/
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);

	/*for non_inverting mode*/
	SET_BIT(TCCR0,COM01);

	/*for 1024 prescalar*/
	SET_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,CS00);
}

void Lighting_System(void)
{
    /* Get the current light intensity value from the LDR sensor*/
    uint8 g_Intensity = LDR_getLightIntensity();

    /* If light intensity is very low (<= 15), turn on all LEDs (Red, Green, Blue)*/
    if(g_Intensity <= 15)
    {
        LED_on(LED_RED);
        LED_on(LED_GREEN);
        LED_on(LED_BLUE);
    }
    /* If light intensity is between 16 and 50, turn on Red and Green LEDs, turn off Blue*/
    else if(g_Intensity > 15 && g_Intensity <= 50)
    {
        LED_on(LED_RED);
        LED_on(LED_GREEN);
        LED_off(LED_BLUE);
    }
    /* If light intensity is between 51 and 70, turn on only the Red LED*/
    else if(g_Intensity > 50 && g_Intensity <= 70)
    {
        LED_on(LED_RED);
        LED_off(LED_GREEN);
        LED_off(LED_BLUE);
    }
    /*If light intensity is high (> 70), turn off all LEDs*/
    else if(g_Intensity > 70)
    {
        LED_off(LED_RED);
        LED_off(LED_GREEN);
        LED_off(LED_BLUE);
    }
}


void Display_Intensity(void)
{
    /* Move the cursor to the second row, 9th position on the LCD to start displaying the LDR value*/
    LCD_MoveCursor(1, 8);

    /* Display "LDR=" on the LCD to indicate that the next value is the light intensity*/
    LCD_SendString("LDR=");

    /* Get the current light intensity value from the LDR sensor*/
    uint16 g_Intensity = LDR_getLightIntensity();

    /* Move the cursor to the 13th position on the second row to print the intensity value*/
    LCD_MoveCursor(1, 12);

    /* If the intensity value is less than 100, print the value followed by "%" and add a space to clear any leftover characters*/
    if(g_Intensity < 100)
    {
        LCD_intgerToString(g_Intensity); 	// Display the light intensity value
        LCD_SendCharacter('%');  			// Display the "%" symbol for percentage
        LCD_SendCharacter(' ');  			// Add a space to clear any previous larger numbers
    }
    /* If the intensity value is 100 or more, simply print the value followed by "%" */
    else
    {
        LCD_intgerToString(g_Intensity);    /* Display the light intensity value*/
        LCD_SendCharacter('%');  			/* Display the "%" symbol for percentage*/
    }
}


void Flame_Alert(void)
{
		LCD_MoveCursor(0,0);
		LCD_SendString("Critical alert!");
}

void Display_FanState(void)
{
    /* Move the cursor to the first row, 3rd position on the LCD to start displaying the fan state*/
    LCD_MoveCursor(0, 2);

    /* Display "Fan is " to indicate the status of the fan*/
    LCD_SendString("Fan is ");

    /* Check the state of the fan (whether it's ON or OFF)*/
    if(fanState == LOGIC_HIGH)  	/* If fanState is HIGH, the fan is ON*/
    {
        LCD_SendString("ON     ");  /* Display "ON" and add extra spaces to clear previous characters*/
    }
    else
    {
        LCD_SendString("OFF   ");  /* Display "OFF" and add extra spaces to clear previous characters*/
    }
}



void Fan_Speed_Interfacing(void)
{
    /* Get the current temperature value from the LM35 temperature sensor*/
    uint8 temp = 0;
    temp = LM35_GetTempValue();

    /* If the temperature is 25°C or below, stop the fan*/
    if(temp <= 25)
    {
        DcMotor_Rotate(Stop, 0);
    }
    /* If the temperature is between 26°C and 30°C, set the fan to low speed*/
    else if (temp > 25 && temp <= 30)
    {
        DcMotor_Rotate(CW, 64);  /* Rotate the fan clockwise at a low speed (25% duty cycle)*/
    }
    /* If the temperature is between 31°C and 35°C, set the fan to medium speed*/
    else if (temp > 30 && temp <= 35)
    {
        DcMotor_Rotate(CW, 128);  /* Rotate the fan at medium speed (50% duty cycle)*/
    }
    /*If the temperature is between 36°C and 40°C, set the fan to high speed*/
    else if (temp > 35 && temp <= 40)
    {
        DcMotor_Rotate(CW, 192);  /* Rotate the fan at high speed (75% duty cycle)*/
    }
    /* If the temperature exceeds 40°C, set the fan to maximum speed*/
    else if (temp > 40)
    {
        DcMotor_Rotate(CW, 255);  /* Rotate the fan at maximum speed (100% duty cycle)*/
    }
}

void Temp_Display(void)
{
	uint8 temp = 0;
	temp = LM35_GetTempValue();
	LCD_MoveCursor(1,0);
	LCD_SendString("Temp=");
	LCD_intgerToString(temp);
}

