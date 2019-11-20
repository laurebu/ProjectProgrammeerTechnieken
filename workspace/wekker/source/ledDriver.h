/*
 * @author: Lander Buysse
 * @file: ledDriver.h
 *
 * @description: .h file for the led driver, contains:
 * 						constants for the LED's GPIO pins for the frdm-k64f and the application shield
 * 						method prototypes to initialise, turn on and turn off a led
 */
#ifndef LEDDRIVER_H
#define LEDDRIVER_H

/* * * * * * *
 * variables *
 * * * * * * */
	//define the value of the GPIO pin for each led
	#define BLUE_FRDM	21		//blue led on the frdm-k64f
	#define RED_FRDM    22		//red led on the frdm-k64f
	#define GREEN_FRDM  26		//green led on the frdm-k64f
	#define BLUE_AP		12		//blue led on the application shield
	#define RED_AP      2		//red led on the application shield
	#define GREEN_AP	4		//green led on the application shield

	//define the required values for the clock gate control by port (A,B,C,D,E)
	#define SCGC5A		0x200   //value to enable the clock gate control for port A
	#define SCGC5B		0x400	//value to enable the clock gate control for port B
	#define SCGC5C		0x800	//value to enable the clock gate control for port C
	#define SCGC5D		0x1000	//value to enable the clock gate control for port D
	#define SCGC5E		0x2000	//value to enable the clock gate control for port E

/* * * * * * * *
 * prototypes  *
 * * * * * * * */

	/*
	 * Function: initialiseLed
	 * -------------------
	 * Parameters:
	 * -----------
	 * 		int nr: GPIO nr of the led you want to initialise
	 * 		constants are defined for the frdm-k64f and the application shield in the section: variables
	 * Summary:
	 * --------
	 * 		initialises a led by:
	 * 			enabling port clock control gate,
	 * 		 	configure leds as alternative 1
	 * 		 	set the pin as output
	 *
	 * 		this method should be called once before trying to turn on/off the led
	 */
	void initialiseLed(int nr);

	/*
	 * Function: turnOnLed
	 * -------------------
	 * Parameters:
	 * -----------
	 * 		int nr: GPIO nr of the led you want to turn on
	 * 		constants are defined for the frdm-k64f and the application shield in the section: variables
	 * Summary:
	 * --------
	 * 		turns on a led
	 */
	void turnOnLed(int nr);

	/*
	 * Function: turnOffLed
	 * -------------------
	 * Parameters:
	 * -----------
	 * 		int nr: GPIO nr of the led you want to turn off
	 * 		constants are defined for the frdm-k64f and the application shield in the section: variables
	 * Summary:
	 * --------
	 * 		turns a led off
	 */
	void turnOffLed(int nr);

#endif //LEDDRIVER_H
