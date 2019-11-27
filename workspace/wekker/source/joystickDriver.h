/*
 * @author: Lander Buysse
 * @file: joystickDriver.h
 *
 * description: .h file for the joystick driver, contains:
 * 						constants for the joystick direction GPIO pins the application shield
 * 						method prototypes to initialize the joystick, detect and handle interrupts from the joystick GPIO pins
 */
#ifndef JOYSTICKDRIVER_H
#define JOYSTICKDRIVER_H

/* * * * * * *
 * variables *
 * * * * * * */
	//define the values of the GPIO pins for the joystick
	#define RIGHT	10
	#define LEFT	11
	#define UP		10
	#define DOWN	11
	#define CENTER	23

	#define INTERRUPT_MASK_24 0x01000000  //bit mask for the 24th bit of a 32 bit int

	//define the required values for the clock gate control by port (B and C)
	#define SCGC5B		0x400
	#define SCGC5C		0x800

/* * * * * * * *
 * prototypes  *
 * * * * * * * */

	/*
	 * Function: joystickInit
	 * ----------------------
	 * Summary:
	 * --------
	 * 		method to initialise the joystick
	 * 			this method should be called before calling any other methods from this driver
	 */
	void joystickInit(void);

	/*
	 * Function: PORTB_IRQHandler
	 * --------------------------
	 * Summary:
	 * --------
	 * 		interrupt handler for the up,down and center GPIO pins from the joystick
	 */
	void PORTB_IRQHandler(void);

	/*
	 * Function: PORTC_IRQHandler
	 * --------------------------
	 * Summary:
	 * --------
	 * 		interrupt handler for the left and right GPIO pins from the joystick
	 */
	void PORTC_IRQHandler(void);

	/*
	 * Function: getLeft
	 * -----------------
	 * Summary:
	 * --------
	 * 		returns 1 if there was an interrupt on the GPIO pin for pushing the joystick left
	 * 		returns 0 if there was no interrupt on this pin
	 */
	int getLeft(void);

	/*
	 * Function: getRight
	 * ------------------
	 * Summary:
	 * --------
	 * 		returns 1 if there was an interrupt on the GPIO pin for pushing the joystick right
	 * 		returns 0 if there was no interrupt on this pin
	 */
	int getRight(void);

	/*
	 * Function: getUp
	 * ---------------
	 * Summary:
	 * --------
	 * 		returns 1 if there was an interrupt on the GPIO pin for pushing the joystick up
	 * 		returns 0 if there was no interrupt on this pin
	 */
	int getUp(void);

	/*
	 * Function: getDown
	 * -----------------
	 * Summary:
	 * --------
	 * 		returns 1 if there was an interrupt on the GPIO pin for pushing the joystick down
	 * 		returns 0 if there was no interrupt on this pin
	 */
	int getDown(void);

	/*
	 * Function: getCenter
	 * -------------------
	 * Summary:
	 * --------
	 * 		returns 1 if there was an interrupt on the GPIO pin for pushing the joystick in the center
	 * 		returns 0 if there was no interrupt on this pin
	 */
	int getCenter(void);

#endif //JOYSTICKDRIVER_H
