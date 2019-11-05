/*
 * @author: Lander Buysse, Laure Buysse
 * @file: main.c
 */

//files to include
#include "main.h"
#include "stdio.h"
#include "MK64F12.h"
#include "ledControl.h"
#include "speakerControl.h"
#include "inputControl.h"
#include "hardwareInit.h"

//variables
states state;
int alarmOnOff=0;

/*
 * returns the state
 */
int getState(void){
	return state;
}

/*
 * returns whether the alarm is on or off
 * 0=off
 * 1=on
 */
int getAlarm(){
	return alarmOnOff;
}

/*
 * sets whether the alarm is on or off
 * 0=off
 * 1=on
 */
void setAlarm(int onOff){
	alarmOnOff=onOff;
}
/*
 * sets the state
 */
void setState(int stateValue){
	state=stateValue;
}

/*
 * main
 */
int main(void) {
	init();
	initEnums(); //initialises some values of the enums defined in inputcontrol
	state=SETMUSIC; //TODO test the state using this dont forget to put it back to standard
	setAlarm(0);

	/*
	//TODO: test all the states, and the ways to change setting and states
	state=STANDARD;
	//call these two in hardwareInitialisation, i'll make this later
	//also turn the annoying red led of in there!!!!
	initSwitch2();
	initJoystick();
	setAlarm(0);

	//we start in the standard state
	state=STANDARD;

	while(1){ //keep looping through the different states maybe make a start/stop??
			  //using the other switch (sw3), shouldn't be a problem==>need to change button driver
		switch(state){
			case STANDARD:

				//displayTime(hour,min,sec) every time time is changed in this state?
				//test to make sure we don't need to go to the alarm state here

				//this part is just to test, will remove this later
				initialise(BLUE_FRDM);
				turnOn(BLUE_FRDM);
				delay(500000);
				turnOff(BLUE_FRDM);
				break;
			case SETTIME:

				//in this state the clock will be set
				//this is done automatically using the input control
				//use methods, getHour(), getMin(), getSec() to get the time
				//then display the time,
					//perhaps from inputcontrol call a method in main that calls method to do this
					//this can be done while at the end of the methods IncrementTime and decrementTime

				//test if changing the time works, also best remove this later
				while(state==1){
					delay(500000);
					printf("Time: %d: %d: %d:",getHour(),getMin(),getSec());
				}

				//this part is just to test, will remove this later
				initialise(RED_FRDM);
				turnOn(RED_FRDM);
				delay(500000);
				turnOff(RED_FRDM);


				break;
			case SETALARM:

				//test is changing the time works, also best remove this later
				while(state==1){
					delay(500000);
					printf("AlarmTime: %d: %d: %d:",getHour(),getMin(),getSec());
				}

				//this part is just to test, will remove this later
				initialise(GREEN_FRDM);
				turnOn(GREEN_FRDM);
				delay(500000);
				turnOff(GREEN_FRDM);
				break;
			case SETMUSIC:
				//state to set the music tune
				//well once we find a way to fix the damn speaker

				//this part is just to test, will remove this later
				initialise(GREEN_AP);
				turnOn(GREEN_AP);
				delay(500000);
				turnOff(GREEN_AP);
				break;
			case ALARM:
				//state in which the alarm goes off
				setAlarm(1); //sets the alarm variable alarmOnOff in inputcontrol
				//alarmOnOff will be turned off automatically from inputcontrol when the button is pushed
				//while alarm var is set (alarmOnOff==1)
					//play music
					//blinking a led
					//blinking the hour??
				//else
					//stop everything above
					//go back to standard: state=STANDARD or state=0

				//this part is just to test, will remove this later
				initialise(BLUE_FRDM);
				turnOn(BLUE_FRDM);
				delay(500000);
				turnOff(BLUE_FRDM);
				break;
			default:
				state=STANDARD; //just in case something went wrong
				break;
		}
	}*/
	return 0;
}
