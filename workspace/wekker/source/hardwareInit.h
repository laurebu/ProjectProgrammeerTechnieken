/*
 * @author: Lander Buysse
 * @file: hardwareInit.h
 *
 *description: .h file for the initialization of hardware components, contains:
 * 						method prototype to call the initialize methods from the drivers (led,lcd,joystick,speaker,timer)
 */
#ifndef HARDWAREINIT_H
#define HARDWAREINIT_H

/* * * * * * * *
 * prototypes  *
 * * * * * * * */

	/*
	 * Function : init
	 * ---------------
	 *  Summary:
	 * --------
	 * 		this function initialises the drivers by calling the necessary initialise methods from the drivers
	 */
	void init(void);

#endif //HARDWAREINIT_H


