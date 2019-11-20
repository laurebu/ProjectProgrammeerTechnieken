/*
 * @author: Lander Buysse
 * @file: inputControl.h
 */
#ifndef INPUTCONTROL_H
#define INPUTCONTROL_H

/* * * * * * *
 * variables *
 * * * * * * */

typedef enum{   	//enum used to select which timepart will be changed (hour,min or sec)
	HOUR_I=0,
	MIN_I=1,
	SEC_I=2
}timeParts;

typedef enum{		//enum used to select which alarmpart will be changed (hour,min or sec)
	HOUR_A_I=0,
	MIN_A_I=1,
	SEC_A_I=2
}alarmParts;

typedef enum{
	STANDARD_I=0, 	//standard state that displays time
	TIME_I=1,	 	//state to set the clock
	ALARM_I=2,	  	//state to set the alarm time
	MUSIC_I=3,    	//state to change the music tune used
}changeState;



/* * * * * * * *
 * prototypes  *
 * * * * * * * */

/*
 * Function: initEnums
 * -------------------
 * Summary:
 * --------
 * 		initialises some used variables/enums to standard values
 * 		this method should be called first in main before using other methods
 */
void initEnums(void);

/*
 * Function: getHour
 * ---------------
 * Summary:
 * --------
 * 		returns the value of hour to set as the new time
 * 		(returns an integer in between 0 and 23)
 */
int getHour(void);


/*
 * Function: getMin
 * ----------------
 * Summary:
 * --------
 * 		returns the value of min to set as the new time
 * 		(returns an integer in between 0 and 59)
 */
int getMin(void);

/*
 * Function: getSec
 * ----------------
 * Summary:
 * --------
 * 		returns the value of sec to set as the new time
 * 		(returns an integer in between 0 and 59)
 */
int getSec(void);

/*
 * Function: getHourAlarm
 * ----------------------
 * Summary:
 * --------
 * 		returns the value of hour_time to set as the new alarm time
 * 		(returns an integer in between 0 and 23)
 */
int getHourAlarm(void);

/*
 * Function: getSecAlarm
 * ---------------------
 * Summary:
 * --------
 * 		return the value of sec_alarm to set as the new alarm time
 * 		(returns an integer in between 0 and 59)
 */
int getSecAlarm(void);

/*
 * Function: getMinAlarm
 * ---------------------
 * Summary:
 * --------
 * 		returns the value of min_alarm to set as the new alarm time
 * 		(returns and integer in between 0 and 59)
 */
int getMinAlarm(void);



/*
 * Function: getSettingNr
 * ----------------------
 * Summary:
 * --------
 * 		returns the nr of the selected setting
 * 		(returns an integer in between 0 and nr of settings-1
 */
int getSettingNr(void);



/*
 * Function: getSetting
 * -----------------
 * Parameters:
 * -------
 * 		int setting:
 * 			nr of the setting of which the name will be returned
 * Summary:
 * --------
 * 		returns the pointer to the first char of an array of chars that contains the string of a setting
 */
char* getSetting(int setting);

/*
 * Function: setDisplay
 * --------------------
 * Parameters:
 * -----------
 * 		int displayOrNot:
 * 			integer that indicates whether or not something has to be displayed
 * 			if 0==> nothing needs to be displayed
 * 			if 1==> display setted time in settime and setalarm state, display music tunes in the setmusic state
 * 			if 2==> display setting in standard state,
 * 			if 3==> display time in standard state
 * Summary:
 * --------
 * 		sets the variable disp which indicates whether or not something has to be displayed
 */
void setDisplay(int displayOrNot);

int checkInterruptLeft(void);
int checkInterruptRight(void);
int checkInterruptUp(void);
int checkInterruptDown(void);
int checkInterruptCenter(void);

/*
 * Function: incrementTime
 * -----------------------
 * parameters:
 * -----------
 * 		int hourMinSec:
 * 			integer to indicate what part of the time to set that needs to be incremented
 * 			if 0 ==>increment hours
 * 			if 1 ==>increment minutes
 * 			if 2 ==>increment seconds
 * Summary:
 * --------
 * 		increments the hours, minutes or seconds of the time to set
 */
void incrementTime(int hourMinSec);

/*
 * Function: decrementTime
 * -----------------------
 * parameters:
 * -----------
 * 		int hourMinSec:
 * 			integer to indicate what part of the time to set that needs to be incremented
 * 			if 0 ==>increment hours
 * 			if 1 ==>increment minutes
 * 			if 2 ==>increment seconds
 * Summary:
 * --------
 * 		decrements the hours, minutes or seconds of the time to set
 */
void decrementTime(int hourMinSec);
void incrementAlarm(int);
void decrementAlarm(int);


#endif //INPUTCONTROL_H
