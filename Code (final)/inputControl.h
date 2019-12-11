/*
 * @author: Lander Buysse
 * @file: inputControl.h
 *
 * description: .h file for the input control
 * 				contains:
 * 					enum definitions for the states, and parts of the time/alarm
 * 					prototypes for getters and setters to be used in the main method
 * 					prototypes to check interrupts and define the action
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

	typedef enum{      //enum used to select which datePart will be changed (day, month, year)
		day_I=0,
		month_I=1,
		year_I=2
	}dateParts;

	typedef enum{
		STANDARD_I=0, 	//standard state that displays time
		TIME_I=1,	 	//state to set the clock
		ALARM_I=2,	  	//state to set the alarm time
		MUSIC_I=3,    	//state to change the music tune used
		Date_I=4        //state to set the date
	}changeState;



/* * * * * * * *
 * prototypes  *
 * * * * * * * */

	/*
	 * Function: getDayToSet
	 * ---------------------
	 * Summary:
	 * --------
	 * 		returns the value of the new day to set as new date
	 * 			(returns an integer in between 1 and 31)
	 */
	int getDayToSet(void);

	/*
	 * Function: getMonthToSet
	 * -----------------------
	 * Summary:
	 * --------
	 * 		returns the value of the new month to set as a new date
	 * 			(returns an integer in between 1 and 12)
	 */
	int getMonthToSet(void);

	/*
	 * Function: getYearToSet
	 * ----------------------
	 * Summary:
	 * --------
	 * 		returns the value of the new year to set as a new date
	 */
	int getYearToSet(void);

	/*
	 * Function: getHour
	 * ---------------
	 * Summary:
	 * --------
	 * 		returns the value of hour to set as the new time
	 * 			(returns an integer in between 0 and 23)
	 */
	int getHour(void);

	/*
	 * Function: getMin
	 * ----------------
	 * Summary:
	 * --------
	 * 		returns the value of min to set as the new time
	 * 			(returns an integer in between 0 and 59)
	 */
	int getMin(void);

	/*
	 * Function: getSec
	 * ----------------
	 * Summary:
	 * --------
	 * 		returns the value of sec to set as the new time
	 * 			(returns an integer in between 0 and 59)
	 */
	int getSec(void);

	/*
	 * Function: getHourAlarm
	 * ----------------------
	 * Summary:
	 * --------
	 * 		returns the value of hour_time to set as the new alarm time
	 * 			(returns an integer in between 0 and 23)
	 */
	int getHourAlarm(void);

	/*
	 * Function: getSecAlarm
	 * ---------------------
	 * Summary:
	 * --------
	 * 		return the value of sec_alarm to set as the new alarm time
	 * 			(returns an integer in between 0 and 59)
	 */
	int getSecAlarm(void);

	/*
	 * Function: getMinAlarm
	 * ---------------------
	 * Summary:
	 * --------
	 * 		returns the value of min_alarm to set as the new alarm time
	 * 			(returns and integer in between 0 and 59)
	 */
	int getMinAlarm(void);

	/*
	 * Function: getSettingNr
	 * ----------------------
	 * Summary:
	 * --------
	 * 		returns the nr of the selected setting
	 * 			(returns an integer in between 0 and nr of settings-1
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
	 * Function: leapyearSet
	 * ---------------------
	 * Parameters:
	 * -----------
	 * 		int year:
	 * 			the year to check on whether or not it is a leapyear
	 * 	Summary:
	 * 	--------
	 * 		returns 1 if the year is a leapyear
	 * 		returns 0 if it isn't
	 */
	int leapyearSet(int year);

	/*
	 * Function: SyncDateToSet
	 * -----------------------
	 * Parameters:
	 * -----------
	 * 		int d:
	 * 			integer that contains the value of the next day to set as date
	 * 		int m:
	 * 			integer that contains the value of the next month to set as date
	 * 		int y:
	 * 			integer that contains the value of the next year to set as date
	 * Summary:
	 * --------
	 * 		synchronises the date to set with the given parameters
	 * 			(changes dayToSet, monthToSet and yearToSet)
	 */
	void syncDateToSet(int d, int m, int y);

	/*
	 * Function: adjustDays
	 * --------------------
	 * Summary:
	 * --------
	 * 		adjust the days to not go over the maximum days in a month (taking leapyears in consideration)
	 * 		this method should be called whenever the new mont to set as day or the new year to set as date is changed
	 */
	void adjustDays(void);

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

	/*
	 * Function: checkInterruptLeft
	 * ----------------------------
	 * Summary:
	 * --------
	 * 		checks if there was an interrupt on the GPIO pin for pushing the joystick left
	 * 		returns 1 if there was an interrupt on this pin
	 * 			if there was an interrupt, the current state is checked
	 * 				state==STANDARD ==>select previous setting
	 * 				state==SETTIME 	==>select previous timePart
	 * 				state==SETALARM ==>select previous alarmPart
	 * 				state==>SETDATE ==>select previous datePart
	 * 		returns 0 if there was no interrupt on this pin
	 */
	int checkInterruptLeft(void);

	/*
	 * Function: checkInterruptRight
	 * -----------------------------
	 * Summary:
	 * --------
	 * 		checks if there was an interrupt on the GPIO pin for pushing the  joystick right
	 * 		returns 1 if there was an interrupt on this pin
	 * 			if there was an interrupt, the current state is checked
	 *				state==STANDARD ==>select next setting
	 * 				state==SETTIME 	==>select next timePart
	 * 				state==SETALARM ==>select next alarmPart
	 * 				state==SETDATE  ==>select next datePart
	 * 		returns 0 if there was no interrupt on this pin
	 */
	int checkInterruptRight(void);

	/*
	 * Function: checkInterruptUp
	 * --------------------------
	 * Summary:
	 * --------
	 * 		checks if there was an interrupt on the GPIO pin for pushing the joystick up
	 * 		returns 1 if there was an interrupt on this pin
	 *			if there was an interrupt, the current state is checked
	 *				state==SETTIME  ==> increment the time to set
	 *				state==SETALARM ==> increment the alarm to set
	 *				state==SETDATE  ==> increment the date to set
	 * 		returns 0 if there was no interrupt on this pin
	 */
	int checkInterruptUp(void);

	/*
	 * Function: checkInterruptDown
	 * --------------------------
	 * Summary:
	 * --------
	 * 		checks if there was an interrupt on the GPIO pin for pushing the joystick down
	 * 		returns 1 if there was an interrupt on this pin
	 *			if there was an interrupt, the current state is checked
	 *				state==SETTIME  ==> decrement the time to set
	 *				state==SETALARM ==> decrement the alarm to set
	 *				state==SETDATE  ==> decrement the date to set
	 * 		returns 0 if there was no interrupt on this pin
	 */
	int checkInterruptDown(void);

	/*
	 * Function: checkInterruptCenter
	 * --------------------------
	 * Summary:
	 * --------
	 * 		checks if there was an interrupt on the GPIO pin for pushing the joystick in the center
	 * 		returns 1 if there was an interrupt on this pin
	 *			if there was an interrupt, the current state is checked
	 *				state==ALARM ==> turns off the alarm
	 * 		returns 0 if there was no interrupt on this pin
	 */
	int checkInterruptCenter(void);

	/*
	 * Function: incrementTime
	 * -----------------------
	 * Parameters:
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
	 * Parameters:
	 * -----------
	 * 		int hourMinSec:
	 * 			integer to indicate what part of the time to set that needs to be decremented
	 * 			if 0 ==>increment hours
	 * 			if 1 ==>increment minutes
	 * 			if 2 ==>increment seconds
	 * Summary:
	 * --------
	 * 		decrements the hours, minutes or seconds of the time to set
	 */
	void decrementTime(int hourMinSec);

	/*
	 * Function: incrementAlarm
	 * ------------------------
	 * Parameters:
	 * -----------
	 * 		int alarm_hms:
	 * 			integer to indicate what part of the alarm time to set needs to be incremented
	 * 			if 0 ==>increment hours
	 * 			if 1 ==>increment minutes
	 * 			if 2 ==>increment seconds
	 * Summary:
	 * --------
	 * 		increments the hours, minutes or seconds of the alarm time to set
	 */
	void incrementAlarm(int alarm_hms);

	/*
	 * Function: decrementAlarm
	 * ------------------------
	 * Parameters:
	 * -----------
	 * 		int alarm_hms:
	 * 			integer to indicate what part of the alarm time to set needs to be decremented
	 * 			if 0 ==>increment hours
	 * 			if 1 ==>increment minutes
	 * 			if 2 ==>increment seconds
	 * Summary:
	 * --------
	 * 		decrements the hours, minutes or seconds of the alarm time to set
	 */
	void decrementAlarm(int alarm_hms);

	/*
	 * Function: incrementDate
	 * -----------------------
	 * Parameters:
	 * -----------
	 * 		int dmy:
	 * 			integer to indicate which part of the date to set that needs to be incremented
	 * 			if 0 ==> days
	 * 			if 1 ==> months
	 * 			if 2 ==> years
	 * 	Summary:
	 * 	--------
	 * 		increments the days, months or years of the date to set
	 */
	void incrementDate(int dmy);

	/*
	 * Function: decrementDate
	 * -----------------------
	 * Parameters:
	 * -----------
	 * 		int dmy:
	 * 			integer to indicate which part of the date to set that needs to be decremented
	 * 			if 0 ==> days
	 * 			if 1 ==> months
	 * 			if 2 ==> years
	 * Summary:
	 * --------
	 * 		decrements the days, months, years of the day to set
	 */
	void decrementDate(int dmy);

#endif //INPUTCONTROL_H
