/*
 * @author: Lander Buysse
 * @file: main.h
 */

#ifndef MAIN_H
#define MAIN_H

//states
typedef enum{
	STANDARD=0,   //standard state that displays time
	SETTIME=1,	  //state to set the clock
	SETALARM=2,	  //state to set the alarm time
	SETMUSIC=3,   //state to change the music tune used
	ALARM=4,      //state in which the alarm is active
}states;

/* * * * * * * *
 * prototypes  *
 * * * * * * * */

/*
 * Function: main
 * --------------
 * Summary:
 * --------
 * 		main method that is implemented as a statemachine with 5 states:
 * 			standard: state that:
 * 					 displays the current time
 * 					 displays a menu to select the settings
 * 					 enables/disables the alarm and displays it to the user
 * 			set time; state to set the current time
 * 			set alarm; state to set the alarm time
 * 			set music: state to select the tune for the alarm
 * 			alarm: state for when the alarm is going off
 */
int main(void);
void setState(int stateValue);
int getState(void);
int getAlarm(void);
int getAlarmEnabled(void);
void setAlarm(int onOff);
void dispSetAlarm(void);
void dispSetTime(void);
void dispSetMusic(void);
void dispTimeStandard(void);
void toggleAlarm(void);

#endif //MAIN_H
