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
	SETDATE=5     //state to set the date
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
 * 			set date: state to set the date
 */
int main(void);

/*
 * Function: getState
 * ------------------
 * Summary:
 * --------
 * 		returns an integer that represents the current state
 * 		0 ==> STANDARD
 * 		1 ==> SET TIME
 * 		2 ==> SET ALARM
 * 		3 ==> SET MUSIC
 * 		4 ==> ALARM
 * 		5 ==> SET DATE
 */
int getState(void);

/*
 * Function: getAlarmEnabled
 * -------------------------
 * Summary:
 * --------
 * 		returns 1 if the alarm is enabled
 * 		returns 0 if the alarm is disabled
 */
int getAlarmEnabled(void);

/*
 * Function: getAlarm
 * ------------------
 * Summary:
 * --------
 * 		returns 1 if the alarm is going off
 * 		returns 0 if the alarm is not going off
 */
int getAlarm(void);

/*
 * Function: setAlarm
 * ------------------
 * Parmameters:
 * ------------
 * 		int onOff:
 *			1==> alarm is going off
 *			0==> alarm is not going off
 * Summary:
 * --------
 * 		sets the variable that indicates whether or not the alarm is going off
 */
void setAlarm(int onOff);

/*
 * Function: dispSetAlarm
 * ----------------------
 * Summary:
 * --------
 * 		calls the methods to display the menu to set the alarm time (SET ALARM state)
 */
void dispSetAlarm(void);

/*
 * Function: dispSetTime
 * ---------------------
 * Summary:
 * --------
 * 		calls the methods to display the menu to set the time (SET TIME state)
 */
void dispSetTime(void);

/*
 * Function: dispSetMusic
 * ----------------------
 * Summary:
 * --------
 * 		calls the methods to display the menu to set the music (SET MUSIC state)
 */
void dispSetMusic(void);

/*
 * Function: dispSetDate
 * ---------------------
 * Summary:
 * --------
 * 		calls the methods to display the the menu to set the date (SET DATE state)
 */
void dispSetDate(void);

/*
 * Function: dispTimeStandard
 * --------------------------
 * Summary:
 * --------
 * 		calls the methods to display the time (STANDARD) state
 */
void dispTimeStandard(void);

/*
 * Function: toggleAlarm
 * ---------------------
 * Summary:
 * --------
 * 		toggle the enabling of the alarm on and off
 */
void toggleAlarm(void);

#endif //MAIN_H
