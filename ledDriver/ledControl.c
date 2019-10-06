/*
 * @author: Lander Buysse
 * @file: ledDriver.c
 */

//files to include
#include "ledControl.h"
#include "MK64F12.h"

/*
 * wait for some time
 */
void delay(long delay) {
	for (long i = 0; i < delay; i++) {
	}
}

/*
 * calls driver function to turn on led
 *
 * nr --> GPIO nr (values defined in ledDriver.h)
 */
void turnOn(int nr){
	turnOnLed(nr);
}

/*
 * calls driver function to turn off led
 *
 * nr --> GPIO nr (values defined in ledDriver.h)
 */
void turnOff(int nr){
	turnOffLed(nr);
}

/*
 * calls driver function to initialise led
 *
 * nr --> GPIO nr (values defined in ledDriver.h)
 */
void initialise(int nr){
	initialiseLed(nr);
}
