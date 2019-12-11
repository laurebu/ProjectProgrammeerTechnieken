/*
 * @author: Lander Buysse
 * @file: ledDriver.c
 *
 * description: .c file for the led control, contains:
 * 						methods to call the methods from the driver
 */

/* * * * * * * * * * *
 * files to include  *
 * * * * * * * * * * */
	#include "ledControl.h"
	#include "ledDriver.h"
	#include "MK64F12.h"
	#include <stdio.h>


/* * * * * *
 * methods *
 * * * * * */

	void turnOn(int nr){
		turnOnLed(nr);
	}

	void turnOff(int nr){
		turnOffLed(nr);
	}

	void initialise(int nr){
		initialiseLed(nr);
	}

