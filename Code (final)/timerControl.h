/*
 * @author: Laure Buysse
 * @file: timerControl.h
 *
 * description: .h file for the timer control, contains:
 * 						prototypes to calculate a leapyear
 * 						prototypes to calculate winter-/summertime
 * 						prototypes to calculate the amound of days inbetween dates
 * 						prototypes to get the current day of the week
 * 						prototypes to set and get dates (/months, /days)
 */

#ifndef TIMERCONTROL_H
#define TIMERCONTROL_H

/* * * * * 
 * enums *
 * * * * */
enum Month {
	Jan , Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};

enum Day {
	Mon , Tue, Wed, Thu, Fri, Sat, Sun
};

/* * * * * * * *
 * prototypes  *
 * * * * * * * */


	/*
	 * Function: get_month_int
	 * -----------------
	 * Summary:
	 * --------
     *      returns the current months as an integer
	 * 			f.ex.: current month is december => return = 11 
	 */
	int get_month_int(void);
	
	/*
	 * Function: get_dayPassed
	 * -----------------
	 * Summary:
	 * --------
     *      returns integer that tells if a day has passed (used to update the date)
	 * 			0 -> days isn't complete yet
	 * 			1 -> day complete
	 */
	int get_dayPassed(void);
	
	/*
	 * Function: set_dayPassed
	 * -----------------
	 * Parameters:
	 * -------
	 * 		int nextDay:
	 * 			integer respresenting if a day has passed or not (used to update the date)
	 * Summary:
	 * --------
     *      sets variable to indicate if days has passed or not 
	 * 			0 -> days isn't complete yet / hasn't passed
	 *			1 -> days complete
	 */
	void set_dayPassed(int nextDay);

	/*
	 * Function: leapyear
	 * -----------------
	 * Parameters:
	 * -------
	 * 		int year:
	 * 			integer representing a certain year
	 * Summary:
	 * --------
     *      calculates whether a gives year is a leapyear or not
	 * 			0 -> year is NOT a leapyear
	 * 			1 -> year is a leapyear
	 */
	int leapyear(int year);

	/*
	 * Function: update_date
	 * -----------------
	 * Summary:
	 * --------
     *      updates the day (current day + 1 )
	 */
	void update_date(void);

	/*
	 * Function: update_time
	 * -----------------
	 * Summary:
	 * --------
     *      updates the time and check for for summer-/wintertime 
	 */
	void update_time(void);

	/*
	 * Function: get_hours
	 * -----------------
	 * Summary:
	 * --------
     *      returns the current hour
	 * 			f.ex.: if time = 10:50:20 => return = 10
	 */
	int get_hours(void);

	/*
	 * Function: get_minutes
	 * -----------------
	 * Summary:
	 * --------
     *      returns the current amount of minutes
	 * 			f.ex.: if time = 10:50:20 => return = 50
	 */
	int get_minutes(void);

	/*
	 * Function: get_seconds
	 * -----------------
	 * Summary:
	 * --------
     *      returns the current amount of seconds
	 * 			f.ex.: if time= 10:50:20 => return = 20
	 */
	int get_seconds(void);

	/*
	 * Function: get_year
	 * -----------------
	 * Summary:
	 * --------
     *      returns the current year
	 * 			f.ex.: if date = 10 Dec 2019 => return = 2019
	 */
	int get_year(void);

	/*
	 * Function: get_day
	 * -----------------
	 * Summary:
	 * --------
     *      returns the current day of the month
	 * 			f.ex.: if date = 10 Dec 2019 => return = 10
	 */
	int get_day(void);

	/*
	 * Function: get_weekday
	 * -----------------
	 * Summary:
	 * --------
     *      returns the current day of the month
	 * 			f.ex.: if date = Wed 10 Dec 2019 => return = "Wed"
	 */
	char* get_weekday(void);
	
	/*
	 * Function: get_month
	 * -----------------
	 * Summary:
	 * --------
     *      returns the current month
	 * 			f.ex.: if date = Wed 10 Dec 2019 => return = "Dec"
	 */
	char* get_month(void);

	/*
	 * Function: set_date
	 * -----------------
	 * Parameters:
	 * -------
	 * 		int d:
	 * 			integer representing a day of the month
	 * 		ind m:
	 * 			integer representing a month
	 * 		int y:
	 * 			integer representing a certain year
	 * Summary:
	 * --------
     *      sets the current day, month, year
	 * 		the current day of the week is calculated and set aswell 
	 * 			f.ex.: d = 11, m = 12, y = 2019 
	 * 				=> date will be set for "Wed 11 Dec 2019"
	 */
	void set_date(int d, int m, int y);

	/*
	 * Function: set_time
	 * -----------------
	 * Parameters:
	 * -------
	 * 		int h:
	 * 			integer representing a certain hours
	 * 		ind m:
	 * 			integer representing an amount of minutes
	 * 		int s:
	 * 			integer representing an amount of seconds
	 * Summary:
	 * --------
     *      sets the current time
	 * 			f.ex.: h = 11, m = 12, s = 50 
	 * 				=> time will be set for : 11:12:50
	 */
	void set_time(int h, int m, int s);

	/*
	 * Function: getTimeBit
	 * -----------------
	 * Summary:
	 * --------
     *      returns the timebit 
	 * 			0 -> seconds has NOT passed yet
	 * 			1 -> a seconds has passed
	 */
	int getTimeBit(void);

	/*
	 * Function: setTimeBit
	 * -----------------
	 * Parameters:
	 * -------
	 * 		int t:
	 * 			integer representing the timebit
	 * 				0 -> seconds has NOT passed yet
	 * 				1 -> a seconds has passe
	 * Summary:
	 * --------
     *      sets the timebit
	 */
	void setTimeBit(int t);

	/*
	 * Function: checkSummerTime - Lander Buysse
	 * -----------------
	 * Summary:
	 * --------
     *      checks whether current time has to be changed to summertime
	 */
	void checkSummerTime(void);

	/*
	 * Function: checkWinterTime - Lander Buysse
	 * -----------------
	 * Summary:
	 * --------
     *      checks whether current time has to be changed to wintertime
	 */
	void checkWinterTime(void);

	/*
	 * Function: calc_days
	 * -----------------
	 * Parameters:
	 * -------
	 * 		int d:
	 * 			integer representing a day of the month
	 * 		int m:
	 * 			integer representing a month
	 * 		int y:
	 * 			integer representing a year
	 * Summary:
	 * --------
     *     	calculates the day left in the current month 
	 * 		+ the amount of days left in the startmonth (= 31)
	 */
	int calc_days(int d, int m, int y);

	/*
	 * Function: calc_months
	 * -----------------
	 * Parameters:
	 * -------
	 * 		int d:
	 * 			integer representing a day of the month
	 * 		int m:
	 * 			integer representing a month
	 * 		int y:
	 * 			integer representing a year
	 * Summary:
	 * --------
     *     	calculates the amount of (complete) months inbetween the given date and 
	 * 		the startdate (1st of january 0001)
	 * 		! Complete years aren't counted as month
	 * 		! Incomplete months aren't counted
	 */
	int calc_months(int d, int m, int y);

	/*
	 * Function: calc_years
	 * -----------------
	 * Parameters:
	 * -------
	 * 		int d:
	 * 			integer representing a day of the month
	 * 		int m:
	 * 			integer representing a month
	 * 		int y:
	 * 			integer representing a year
	 * Summary:
	 * --------
     *     	calculates the amount of complete years inbetween the given date and
	 * 		the startdate (1st of january 0001)
	 */
	int calc_years(int d, int m, int y);
	
#endif
