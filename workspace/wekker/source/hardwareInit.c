/*
 * @author: Lander Buysse
 * @file: hardwareInit.c
 *
 * description: .c file for the initialization of hardware components, contains:
 * 						method to call the initialize methods from the drivers (led,lcd,joystick,speaker,timer)
 */

/* * * * * * * * * * *
 * files to include  *
 * * * * * * * * * * */
	#include "speakerDriver.h"
	#include "ledDriver.h"
	#include "joystickDriver.h"
	#include "lcdDriver.h"
	#include <stdio.h>
	#include "timerDriver.h"

/* * * * * *
 * methods *
 * * * * * */
	void init(void){
		initPWM(); //initialises the PWM for the speaker

		//initialise the required leds
		initialiseLed(BLUE_FRDM);

		initialiseLed(RED_AP);

		joystickInit(); //initialises the joystick

		lcd_init();//initialises the lcd screen

		init_timer();//initialises the time
	}
