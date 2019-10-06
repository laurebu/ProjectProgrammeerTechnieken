//files to include
#include <stdio.h>
#include "ledControl.h"
#include "MK64F12.h"
#include "joystickDriver.h"

/*
 * temporary main to test some stuff in
 */
int main(void) {
	//remark: red one stays on from the start
	//may have to do something about this in the middleware, not sure how yet

	//testing code
	printf("hello");
	initialise(GREEN_FRDM);
	initialise(BLUE_FRDM);
	initialise(RED_FRDM);
	while (1) {

		turnOn(GREEN_FRDM);
		delay(1000000);
		turnOff(GREEN_FRDM);
		delay(1000000);

		turnOn(RED_FRDM);
		delay(1000000);
		turnOff(RED_FRDM);
		delay(1000000);

		turnOn(BLUE_FRDM);
		delay(1000000);
		turnOff(BLUE_FRDM);
		delay(1000000);

	}
	return 0;
}
