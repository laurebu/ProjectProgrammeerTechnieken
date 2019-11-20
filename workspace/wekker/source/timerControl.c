/*
 * @author: Laure Buysse
 * @file: timerControl.c
 */

#include "timerControl.h"
#include "timerDriver.h"
#include "lcdControl.h"
#include "lcdDriver.h"

int seconds;
int minutes;
int hours;

void update_time(){
	if(get_seconds_total() == 86400){
		hours = 0;
		minutes = 0;
		seconds = 0;
		set_seconds_total(0);
	}
	else {
		hours = get_seconds_total()/3600;
		minutes = (get_seconds_total() - 3600*hours)/60;
		seconds = (get_seconds_total() - (3600*hours) - (60*minutes));
	}
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
