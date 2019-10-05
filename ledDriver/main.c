//includes
#include <stdio.h>
#include "ledDriver.h"
#include "MK64F12.h"

/*
 * temporary main to test some stuff in
 * be aware, still need to make middleware, don't use these functions directly unless for testing
 */
int main(void) {
	//remark: red one stays on from the start
	//may have to do something about this in the middleware, not sure how yet

	//testing code
	printf("hello");
	while (1) {

		initialiseLed(BLUE_AP);
		turnOnLed(BLUE_AP);
		delay(10000000);
		turnOffLed(BLUE_AP);
		delay(10000000);

	}
	return 0;
}
