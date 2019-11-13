/*
 * @author: Lander Buysse, Laure Buysse
 * @file: main.c
 */

//files to include
#include "main.h"
#include <stdio.h>
#include "MK64F12.h"
#include "ledControl.h"
#include "speakerControl.h"
#include "inputControl.h"
#include "hardwareInit.h"
#include "lcdControl.h"

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
	turnOff(RED_A);
	turnOff(BLUE_F);
	initEnums(); //initialises some values of the enums defined in inputcontrol
	setAlarm(0); //make sure the alarm isn't going off
	setDisplay(1);

	//we start in the standard state
	state=ALARM;

	while(1){ //keep looping through the different states maybe make a start/stop??
			  //using the other switch (sw3), shouldn't be a problem==>need to change button driver
		switch(state){
			case STANDARD:
				//TODO first check if we don't need to go to the alarmstate
				if(getDisplay()==2){
					//TODO display the setting
					printf("%s \n",getSetting(getSettingNr()));
					setDisplay(0);
				}
				if(getDisplay()==1){
					//TODO display the time here (every second)
				}
				//displayTime(hour,min,sec) every time time is changed in this state?
				//test to make sure we don't need to go to the alarm state here

				break;
			case SETTIME:
				//state to set the time, time changing is done automatically using interrupts
				if(getDisplay()==1){
					//TODO change the printf to a writeToLCD LAURE I NEED A METHOD HERE
					printf("Time: %d: %d: %d: \n",getHour(),getMin(),getSec());
					setDisplay(0); //indicate that the changed time has been displayed
				}
				break;
			case SETALARM:
				//state to set the alarm, alarm changing is done automatically using interrupts
				if(getDisplay()==1){
					//TODO method to display time here
					printf("Alarm time: %d: %d: %d: \n",getHourAlarm(),getMinAlarm(),getSecAlarm());
					setDisplay(0); //indicate that the changed alarm time has been displayed
				}
				break;
			case SETMUSIC:
				//state to set the music tune
				if(getDisplay()==1){
					//TODO method to display a string here
					printf("%s \n",getTune(getTuneNr()));
					setDisplay(0);
				}
				break;
			case ALARM:
				//state in which the alarm goes off
				setAlarm(1); //sets the alarm variable alarmOnOff in inputcontrol
				//turn on led
				turnOn(BLUE_F);
				while(getAlarm()==1){
					playMusic(getTuneNr());
				}
				turnOff(BLUE_F);
				state=STANDARD;
				break;
			default:
				state=STANDARD; //just in case something went wrong
				break;
		}
	}
	return 0;
}
