/*
 * @author: Lander Buysse
 * @file: ledControl.h
 *
 * description: .h file for the led control, contains:
 * 						method prototypes to call the methods from the driver
 */

/* * * * * * * * * * *
 * files to include  *
 * * * * * * * * * * */
	#include "ledDriver.h"

#ifndef LEDCONTROL_H
#define LEDCONTROL_H

/* * * * * * *
 * variables *
 * * * * * * */
	//define names for the GPIO pins of the LED's, take over the values described in the speaker driver
	#define BLUE_F BLUE_FRDM
	#define RED_F RED_FRDM
	#define GREEN_F GREEN_FRDM
	#define BLUE_A BLUE_AP
	#define RED_A RED_AP
	#define GREEN_A GREEN_AP

/* * * * * * * *
 * prototypes  *
 * * * * * * * */

	/*
	 * Function: turnOn
	 * ----------------
	 * Parameters:
	 * -----------
	 * 		int nr:
	 * 			GPIO nr of the led to turn on
	 * Summary:
	 * --------
	 * 		calls driver function to turn on led
	 */
	void turnOn(int nr);

	/*
	 * Function: turnOff
	 * -----------------
	 * Parameters:
	 * -----------
	 * 		int nr:
	 * 			GPIO nr of the led to turn off
	 * Summary:
	 * --------
	 * 		calls driver function to turn off led
	 */
	void turnOff(int nr);

	/*
	 * Function: initialise
	 * --------------------
	 * Parameters:
	 * -----------
	 * 		int nr:
	 * 			GPIO nr of the led to initialise
	 * Summary:
	 * --------
	 * 		calls driver function to initialise led
	 */
	void initialise(int nr);

#endif //LEDCONTROL_H
