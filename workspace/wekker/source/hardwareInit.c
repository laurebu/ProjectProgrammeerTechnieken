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
	initialiseLed(BLUE_FRDM);
	initialiseLed(RED_AP);
	joystickInit(); //initialises the joystick
	lcd_init();//initialises the lcd screen
}
