/*
 * @author: Laure Buysse
 * @file: timerControl.h
 */

#ifndef TIMERCONTROL_H
#define TIMERCONTROL_H

enum Month {
	Jan , Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};

enum Day {
	Mon , Tue, Wed, Thu, Fri, Sat, Sun
};

int get_month_int(void);
int get_dayPassed(void);
void set_dayPassed(int nextDay);
int leapyear(int year);
void update_date(void);
void update_time(void);
int get_hours(void);
int get_minutes(void);
int get_seconds(void);
int get_year(void);
int get_day(void);
char* get_weekday(void);
char* get_month(void);
void set_date(int d, int m, int y);
void set_time(int h, int m, int s);
int getTimeBit(void);
void setTimeBit(int t);
void checkSummerTime(void);
void checkWinterTime(void);
int calc_days(int d, int m, int y);
int calc_months(int d, int m, int y);
int calc_years(int d, int m, int y);
#endif
