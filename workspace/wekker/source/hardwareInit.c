/*
 * @author: Lander Buysse
 * @file: hardwareInit.c
 */

//files to include
#include "speakerDriver.h"
#include "buttonDriver.h"
#include "ledDriver.h"
#include "joystickDriver.h"
#include "lcdDriver.h"
#include <stdio.h>

/*
 * initialises the drivers
 */
void init(void){
	initPWM(); //initialises the PWM for the speaker
	//initialise the required leds TODO
	joystickInit(); //initialises the joystick
	SW2Init(); //initialises switch2
	lcd_init();//initialises the lcd screen
}