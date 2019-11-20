/*
 * @author: Lander Buysse, Laure Buysse
 * @file: main.c
 */

/* * * * * * * * * * *
 * files to include  *
 * * * * * * * * * * */
#include "main.h"
#include <stdio.h>
#include "MK64F12.h"
#include "ledControl.h"
#include "speakerControl.h"
#include "inputControl.h"
#include "hardwareInit.h"
#include "lcdControl.h"
#include "timerControl.h"

/* * * * * * *
 * variables *
 * * * * * * */
states state;
int alarmOnOff=0;
int firstDisplay=0;
int alarmEnabled=0;
/* * * * * *
 * methods *
 * * * * * */
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
	checkInterruptCenter();
	return alarmOnOff;
}

void setAlarm(int onOff){
	alarmOnOff=onOff;
}

int getAlarmEnabled(){
	return alarmEnabled;
}
/*
 * sets the state
 */
void setState(int stateValue){
	state=stateValue;
}

void dispSetAlarm(){
	if(firstDisplay==1){
		display_time_alarm(getHourAlarm(),getMinAlarm(),getSecAlarm());
		firstDisplay=0;
	}else{
		display_time_center(getHourAlarm(),getMinAlarm(),getSecAlarm());
	}
}

void dispSetTime(){
	if(firstDisplay==1){
		display_time_time(getHour(),getMin(),getSec());
		firstDisplay=0;
	}else{
		display_time_center(getHour(),getMin(),getSec());
	}
}

void dispTimeStandard(){
	if(firstDisplay==1){
		display_time_current(get_hours(),get_minutes(),get_seconds());
		firstDisplay=0;
	}else{
		display_time_center(get_hours(),get_minutes(),get_seconds());
	}
	display_alarm_onOff(alarmEnabled);
}

void dispSetMusic(){
	if(firstDisplay==1){
		display_music(getTune(getTuneNr()),10);
		firstDisplay=0;
	}else{
		center_text(getTune(getTuneNr()),10);
	}
}
void dispSettingStandard(){
	if(firstDisplay==1){
		display_time_lefttop(get_hours(),get_minutes(),get_seconds());
		display_menu(getSetting(getSettingNr()), 10,get_hours(), get_minutes(), get_seconds());
		firstDisplay=0;
	}else{
		center_text(getSetting(getSettingNr()),10);
	}
}

void backToStandard(){
	firstDisplay=1;
	if(getSettingNr()==0){
		dispTimeStandard();
	}else{
		dispSettingStandard();
	}
	state=STANDARD;
}

void toggleAlarm(){
	if(alarmEnabled==0){
		alarmEnabled=1;
	}else{
		alarmEnabled=0;
	}
}
/* * * * *
 * main  *
 * * * * */
int main(void) {
	init(); //initialise the drivers
	turnOff(RED_A);
	turnOff(BLUE_F);
	initEnums(); //initialises some values of the enums defined in inputcontrol
	firstDisplay=1; //initialise the int that indicates if it is the first time something has to be displayed
	alarmEnabled=0; //at startup the alarm is disabled by default,
					//user can enable the alarm by pushing the joystick center when the current time is displayed
	//we start in the standard state
	state=STANDARD;
	while(1){
		switch(state){
			case STANDARD:
				//INTERRUPT FROM TIMER (every second)
				if(getTimeBit()==1){
					if((alarmEnabled==1) && (getHourAlarm()==get_hours()) && (getMinAlarm()==get_minutes()) && (getSecAlarm()==get_seconds())){
						//go into alarm state when the alarm is enabled and the current time matches the alarm time
						state=ALARM;
					}
					if(getSettingNr()==0){
						dispTimeStandard();
					}else{
						display_time_lefttop(get_hours(),get_minutes(),get_seconds());
					}
					setTimeBit(0);
				}

				//JOYSTICK LEFT
				//the selected setting is changed automatically on checking the interrupt
				if(checkInterruptLeft()==1){
					if(getSettingNr()==0){
						firstDisplay=1;
						dispTimeStandard();
					}else{
						dispSettingStandard();
					}
				}

				//JOYSTICK RIGHT
				if(checkInterruptRight()==1){
					if(getSettingNr()==0){
						firstDisplay=1;
						dispTimeStandard();
					}else{
						dispSettingStandard();
					}
				}

				//JOYSTICK CENTER
				if(checkInterruptCenter()==1){
					state=getSettingNr();
					firstDisplay=1;
					if(getSettingNr()==0){
						toggleAlarm();
					}
					if(getSettingNr()==1){
						dispSetTime();
					}
					if(getSettingNr()==2){
						dispSetAlarm();
					}
					if(getSettingNr()==3){
						dispSetMusic();
					}
				}


				//JOYSTICK UP AND DOWN have no functions in this state
				//but we still check them to reset their values in case someone tried to use them
				checkInterruptUp();
				checkInterruptDown();

				break;
			case SETTIME:
				//JOYSTICK LEFT
				//changing in between hour, min sec is done automatically when checking the interrupt
				if(checkInterruptLeft()==1){
					dispSetTime(); //display the time to set
				}

				//JOYSTICK RIGHT
				//changing in between hour, min sec is done automatically when checking the interrupt
				if(checkInterruptRight()==1){
					dispSetTime(); //display the time to set
				}

				//JOYSTICK CENTER
				if(checkInterruptCenter()==1){
					set_time(getHour(),getMin(),getSec());
					backToStandard();
				}

				//JOYSTICK UP
				//incrementing the hour,min,sec is done automatically when checking the interrupt
				if(checkInterruptUp()==1){
					dispSetTime(); //display the time to set
				}

				//JOYSTICK DOWN
				//decrementing the hour,min,sec is done automatically when checking the interrupt
				if(checkInterruptDown()==1){
					dispSetTime(); //display the time to set
				}
				break;
			case SETALARM:
				//JOYSTICK LEFT
				//changing in between hour, min sec alarm is done automatically when checking the interrupt
				if(checkInterruptLeft()==1){
					dispSetAlarm(); //display the alarmtime to set
				}

				//JOYSTICK RIGHT
				//changing in between hour, min sec alarm is done automatically when checking the interrupt
				if(checkInterruptRight()==1){
					dispSetAlarm(); //display the alarmtime to set
				}
				//JOYSTICK CENTER
				if(checkInterruptCenter()==1){
					backToStandard();
				}

				//JOYSTICK UP
				//incrementing the hour,min,sec is done automatically when checking the interrupt
				if(checkInterruptUp()==1){
					dispSetAlarm(); //display the alarmtime to set
				}

				//JOYSTICK DOWN
				//decrementing the hour,min,sec is done automatically when checking the interrupt
				if(checkInterruptDown()==1){
					dispSetAlarm(); //display the alarmtime to set
				}
				break;
			case SETMUSIC:
				//JOYSTICK LEFT
				if(checkInterruptLeft()==1){
					selectTune(-1);
					dispSetMusic();
				}

				//JOYSTICK RIGHT
				if(checkInterruptRight()==1){
					selectTune(+1);
					dispSetMusic();
				}

				//JOYSTICK CENTER
				if(checkInterruptCenter()==1){
					backToStandard();
				}

				//JOYSTICK UP AND JOYSTICK DOWN have no functions in this state
				//but we still check them to reset their values in case someone tried to use them
				checkInterruptUp();
				checkInterruptDown();
				break;

			case ALARM:
				//state in which the alarm goes off
				setAlarm(1); //Alarm on
				//turn on led
				turnOn(BLUE_F);
				clear(); //clear the lcd
				center_text("A L A R M",10);
				while(alarmOnOff){ //until someone pressed the center button to stop the alarm, keep playing
					playMusic(getTuneNr());
				}
				//ALARM is now off
				setAlarm(0);
				turnOff(BLUE_F); //turn the led off again
				backToStandard();
				//JOYSTICK UP,DOWN,LEFT,RIGHT have no functions in this state
				//but we still check them to reset their values in case someone tried to use them
				checkInterruptLeft();
				checkInterruptRight();
				checkInterruptUp();
				checkInterruptDown();
				break;
			default:
				state=STANDARD; //just in case something went wrong
				break;
		}
	}
	return 0;
}
