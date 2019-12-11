/*
 * @author: Laure Buysse
 * @file: timerControl.c
 *
 * description: .c file for the timer control, contains:
 * 						method to calculate a leapyear
 * 						method to calculate winter-/summertime
 * 						methods to calculate the amound of days inbetween dates
 * 						methods to get the current day of the week
 * 						methods to set and get dates (/months, /days)
 */

/* * * * * * * * * * *
 * files to include  *
 * * * * * * * * * * */
#include "timerControl.h"
#include "timerDriver.h"
#include "lcdControl.h"
#include "lcdDriver.h"
#include <stdio.h>

/* * * * * * *
 * variables *
 * * * * * * */
int seconds = 0;
int minutes = 0;
int hours = 0;

int days = 0;
int year = 2019;

const int startDays = 0;
const int startMonth = 0;
const int startYear = 1;
const enum Day startWeekday = Sat;

int dayPassed=0;
int firstHourChange=1;

enum Day day = Tue;
enum Month month = Jan;

/* * * * * *
 * methods *
 * * * * * */
int get_month_int(void){
	return month+1;
}

/*
 * A year is a leapyear when:
 * 	- the year is divisible by four (2016, 2020 etc.)
 * 	- AND the year is not divisble by a hunderd (2100, 2200 etc.)
 * 	- EXCEPTION the year is divisble by fourhunderd (2000, 2400 etc.)
 */
int leapyear(int year){
	if(year%4 == 0){
		if(year%100 == 0){
			if(year%400 == 0){
				// leap year (/4 and /400)
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			// leap year (/4 and not /100)
			return 1;
		}
	}
	else {
		return 0;
	}
}

/* Called when a day is passed */
void update_date(){
	day = (day+1)%7;

	switch(month){
		// 31 days in a month
		case Jan :
		case Mar :
		case May :
		case Jul :
		case Aug :
		case Oct :
		case Dec :
			if(month == Dec){
				// End of the year
				year += 1;
			}
			if(days == 30){
				// End of the month
				days = 0;
				month = (month + 1)%12;
			}
			else {
				days += 1;
			}
			break;

		// 29 or 28 days in a month (depending on if the year is a leap year or not)
		case Feb :
			if(leapyear(year)==1){
				// Leap year
				if(days == 28){
					// End of the month
					days = 0;
					month = (month + 1)%12;
				}
				else {
					days += 1;
				}
			}
			else {
				// Not a leap year
				if(days == 27){
					//end of the month
					days = 0;
					month = (month + 1)%12;
				}
				else {
					days += 1;
				}
			}
			break;

		// 30 days in a month
		case Apr :
		case Jun :
		case Sep :
		case Nov :
			if(days == 29){
				// End of the month
				days = 0;
				month = (month + 1)%12;
			}
			else {
				days += 1;
			}
			break;
		default:
			break;
	}
}

void update_time(){
	// Time is at maximum 23:59:59 -> next day (update date) + time back at zero
	if(get_seconds_total() == 86400){
		hours = 0;
		minutes = 0;
		seconds = 0;
		set_seconds_total(0);
		update_date();
		set_dayPassed(1);
	}
	else {
		hours = get_seconds_total()/3600;
		minutes = (get_seconds_total() - 3600*hours)/60;
		seconds = (get_seconds_total() - (3600*hours) - (60*minutes));
	}
	checkSummerTime();
	checkWinterTime();
}

void checkSummerTime(void){
	//check for summertime (2am --> 3am)
	if(month==2){ // month = march (starting to count from 0)
		if(day==6){ //day = sunday (starting to count from 0)
			if((days+8)>31){ //==> last sunday of march
				if(get_seconds_total()==2*60*60) {//hour = 2 am
					set_seconds_total(3*60*60);
				}
			}
		}
	}
}

void checkWinterTime(void){
	//check for wintertime (3am --> 2am)
	if(month==9){ //month = october (starting to count from 0)
		if(day==6){ //day = sunday (starting to count from 0)
			if(days+8>31){ //==>last sunday of october
				if(get_seconds_total()==(3*60*60)){//current hour = 3 am
					if(firstHourChange==1){  //first time the hour reaches 3 am
						set_seconds_total(2*60*60);  //new hour: ==>2am
						firstHourChange=0;
					}
					if(get_seconds_total()==((3*60*60)+1) && firstHourChange==0){  //past 3 am for the second time
						firstHourChange=1; //Reset this variable again for the next year
					}
				}
			}
		}
	}
}

void set_dayPassed(int nextDay){
	dayPassed=nextDay;
}
int get_dayPassed(void){
	return dayPassed;
}

int get_hours() {
	update_time();
	return hours;
}

int get_minutes() {
	update_time();
	return minutes;
}

int get_seconds() {
	update_time();
	return seconds;
}

int get_year(){
	return year;
}

int get_day(){
	return days+1;
}

char* get_weekday(){
	char* str;
	switch(day){
		case 0:
			str = "Mon";
			break;
		case 1:
			str = "Tue";
			break;
		case 2:
			str = "Wed";
			break;
		case 3:
			str = "Thu";
			break;
		case 4:
			str = "Fri";
			break;
		case 5:
			str = "Sat";
			break;
		case 6:
			str = "Sun";
			break;
	}
	return str;
}

char* get_month(){
	char* str;
	switch(month+1){
		case 1:
			str = "Jan";
			break;
		case 2:
			str = "Feb";
			break;
		case 3:
			str = "Mar";
			break;
		case 4:
			str = "Apr";
			break;
		case 5:
			str = "May";
			break;
		case 6:
			str = "Jun";
			break;
		case 7:
			str = "Jul";
			break;
		case 8:
			str = "Aug";
			break;
		case 9:
			str = "Sep";
			break;
		case 10:
			str = "Oct";
			break;
		case 11:
			str = "Nov";
			break;
		case 12:
			str = "Dec";
			break;
		default:
			str = "Jan";
			break;
	}
	return str;
}

void set_time(int h, int m, int s) {
	hours = h;
	minutes = m;
	seconds = s;
	int total = h*3600 + m*60 + s;
	set_seconds_total(total);
}

int getTimeBit(void){
	return get_timebit();
}

void setTimeBit(int t){
	set_timebit(t);
}


void set_date(int d, int m, int y){
	// Calculate days in between current day and new date
	// No change between dates
	if((year == y) && (month == m) && (days == d)){
		day = day;
	}
	// Change
	else {
		// Calculate how many days are between the current date and the date to set
		int daysInbetweenDays = calc_days(d, m, y);
		int daysInbetweenMonths = calc_months(d, m, y);
		int daysInbetweenYears = calc_years(d,m,y);
		int daysInbetween = daysInbetweenDays + daysInbetweenMonths + daysInbetweenYears;

		// Adjust the day of the week
		day = (startWeekday + daysInbetween )%7;
	}

	// Set the day of the month, the month and the year
	days = d - 1;
	month = m - 1;
	year = y;
}

int calc_days(int d, int m, int y){
		int daysInbetween = 0;

	// Calculate how many days there are left
	if(m == (startMonth + 1)){
		// Current month and month to set are the same
		daysInbetween += (d - startDays + 1);
	}
	else {
		// Current month and month to set are different
		switch(startMonth + 1){	// Current month till end date
			// 31 days in the month
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				daysInbetween += ((31 - startDays) + 1);
				break;
			// 30 days in month
			case 4:
			case 6:
			case 9:
			case 11:
				daysInbetween += ((30 - startDays) + 1);
				break;
			// 28 or 29 days in a month
			case 2:
				if(leapyear(startYear)){
					daysInbetween += ((29 - startDays) + 1);
				}
				else {
					daysInbetween += ((28 - startDays) + 1);
				}
				break;
		}
		// Month to set from beginning to date now
		daysInbetween += (d);
	}
	return daysInbetween;
}

// Calculate how many full months (in days) are in the last not-complete year and add
// Notice: if (actual_month == month) => there isn't a full month in between the dates
int calc_months(int d, int m, int y){
	int daysInbetween = 0;
	int actual_month = startMonth + 1;
	// The month to set is bigger than the current month (f.ex. april(now) -> August(to set))
	if( actual_month < m) {
		for(int i = (actual_month + 1); i<=(m-1) ; i++){
			switch(i){
				// 31 days in the month
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					daysInbetween += 31;
					break;
				// 30 days in a month
				case 4:
				case 6:
				case 9:
				case 11:
					daysInbetween += 30;
					break;
				// 28-29 days in month
				case 2:
					if(leapyear(y)){
						// Leapyear -> february counts 29 days
						daysInbetween += 29;
					}
					else {
						daysInbetween += 28;
					}
					break;
			}
		}
	}
	else if (actual_month > m ){
		// The month to set is smaller than the current month (f.ex. april(now) -> january(to set))
		// Step 1: Go from current month (+1) till December and add
		for(int i = (actual_month + 1); i < 13 ; i++){
			switch(i){
				// 31 days in the month
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					daysInbetween += 31;
					break;
				// 30 days in a month
				case 4:
				case 6:
				case 9:
				case 11:
					daysInbetween += 30;
					break;
				// 28-29 days in month
				case 2:
					if(leapyear(y - 1)){
						// Leap year -> February counts 29 days
						daysInbetween += 29;
					}
					else {
						daysInbetween += 28;
					}
					break;
			}
		}
		// Step 2: Go January to the month to set (-1) and add days
		for(int i = 1 ; i <= (m-1) ; i++){
			switch(i){
				// 31 days in the month
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					daysInbetween += 31;
					break;
				// 30 days in a month
				case 4:
				case 6:
				case 9:
				case 11:
					daysInbetween += 30;
					break;
				// 28-29 days in month
				case 2:
					if(leapyear(y)){
						// Leap year -> February counts 29 days
						daysInbetween += 29;
					}
					else {
						daysInbetween += 28;
					}
					break;
			}
		}
	}
	return daysInbetween;
}

//Calculate how many full years (in days) are in between the current date and the date to set
int calc_years(int d, int m, int y){
	int daysInbetween = 0;
	for(int i = (startYear + 1) ; i <= y; i ++){
		// Make sure the last year is a full year and not just a couple of months
		if(i == y){
			if(((startMonth + 1) < m) || (((startMonth + 1) == m) && (startDays <= d))){
				// Check in which year february falls
				if(startMonth <  2){
					// February falls in previous years
					if (leapyear(i-1) == 1){
					// Leap year -> year counts 366 days
						daysInbetween += 366;
					}
					else {
						daysInbetween += 365;
					}
				}
				else {
					// February in current year
					if (leapyear(i) == 1){
					// Leap year -> year counts 366 days
						daysInbetween += 366;
					}
					else {
						daysInbetween += 365;
					}
				}
			}
		}
		// Multiple years still to pass
		else if (i < y)
		{
			// Check in which year february falls
			if(startMonth <  2){
				// February falls in this year
				if (leapyear(i-1) == 1){
					// Leap year -> year counts 366 days
					daysInbetween += 366;
				}
				else {
					daysInbetween += 365;
				}
			}
			else {
				// February in current year
				if (leapyear(i) == 1){
				// Leap year -> year counts 366 days
					daysInbetween += 366;
				}
				else {
					daysInbetween += 365;
				}
			}
		}
	}
	return daysInbetween;
}
