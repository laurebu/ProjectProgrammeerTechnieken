/*
 * @author: Lander Buysse
 * @file: inputControl.c
 */

/* * * * * * * * * * *
 * files to include  *
 * * * * * * * * * * */
#include "inputControl.h"
#include <stdio.h>
#include "joystickDriver.h"
#include "MK64F12.h"
#include "main.h"

/* * * * * * *
 * variables *
 * * * * * * */
timeParts timePart;
changeState selectState;
alarmParts alarmPart;
int hour_time=0;
int min_time=0;
int sec_time=0;
int hour_alarm=0;
int min_alarm=0;
int sec_alarm=0;

/* * * * * *
 * methods *
 * * * * * */
void initEnums(void){
	timePart=0;
	selectState=0;
	alarmPart=0;
}

int getHour(void){
	return hour_time;
}

int getMin(void){
	return min_time;
}

int getSec(void){
	return sec_time;
}


int getHourAlarm(void){
	return hour_alarm;
}

int getMinAlarm(void){
	return min_alarm;
}


int getSecAlarm(void){
	return sec_alarm;
}

int getSettingNr(void){
	return selectState;
}

char * getSetting(int setting){
	char *str="";
	switch(setting){
		case 0:
			str="Standard";
			break;
		case 1:
			str="Set Time";
			break;
		case 2:
			str="Set Alarm";
			break;
		case 3:
			str="Set Music";
			break;
		default:
			setting=0; //just in case something went wrong
			str="Standard";
			break;
	}
	return str;
}



void incrementTime(int hour_timeMinSec){
	switch(hour_timeMinSec){
		case 0: //increment hour_time
			if (hour_time<23){
				hour_time=hour_time+1;
			}else{
				hour_time=0;
			}
			break;
		case 1: //increment min_time
			if (min_time<59){
				min_time=min_time+1;
			}else{
				min_time=0;
			}
			break;
		case 2: //increment sec_time
			if (sec_time<59){
				sec_time=sec_time+1;
			}else{
				sec_time=0;
			}
			break;
		default:
			//do nothing, just in case something went wrong
			break;
	}
}

void decrementTime(int hour_timeMinSec){
	switch(hour_timeMinSec){
			case 0: //decrement hour_time
				if (hour_time>0){
					hour_time=hour_time-1;
				}else{
					hour_time=23;
				}
				break;
			case 1: //increment min_time
				if (min_time>0){
					min_time=min_time-1;
				}else{
					min_time=59;
				}
				break;
			case 2: //increment sec_time
				if (sec_time>0){
					sec_time=sec_time-1;
				}else{
					sec_time=59;
				}
				break;
			default:
				//do nothing, just in case something went wrong
				break;
		}
}

void incrementAlarm(int alarm_hms){
	switch(alarm_hms){
		case 0: //increment hour_alarm
			if (hour_alarm<23){
				hour_alarm=hour_alarm+1;
			}else{
				hour_alarm=0;
			}
			break;
		case 1: //increment min_alarm
			if (min_alarm<59){
				min_alarm=min_alarm+1;
			}else{
				min_alarm=0;
			}
			break;
		case 2: //increment sec_alarm
			if (sec_alarm<59){
				sec_alarm=sec_alarm+1;
			}else{
				sec_alarm=0;
			}
			break;
		default:
			//do nothing, just in case something went wrong
			break;
	}
}

void decrementAlarm(int alarm_hms){
	switch(alarm_hms){
			case 0: //decrement hour_alarm
				if (hour_alarm>0){
					hour_alarm=hour_alarm-1;
				}else{
					hour_alarm=23;
				}
				break;
			case 1: //increment min_alarm
				if (min_alarm>0){
					min_alarm=min_alarm-1;
				}else{
					min_alarm=59;
				}
				break;
			case 2: //increment sec_alarm
				if (sec_alarm>0){
					sec_alarm=sec_alarm-1;
				}else{
					sec_alarm=59;
				}
				break;
			default:
				//do nothing, just in case something went wrong
				break;
		}
}


int checkInterruptLeft(void){
	if(getLeft()==1){//if interrupt on left joystick pin
		if(getState()==0){ //while in STANDARD state
			//select previous setting
			if(selectState==0){
				selectState=3;
			}else{
				selectState=(selectState-1)%3;
			}
		}
		if(getState()==1){// while in SET TIME state
			//select previous from hour, min, sec (_time)
			if(timePart==0){
				timePart=2;
			}else{
				timePart=(timePart-1)%2;
			}
		}
		if(getState()==2){// while in SET ALARM state
			//select previous from hour, min, sec (_alarm)
			if(alarmPart==0){
				alarmPart=2;
			}else{
				alarmPart=(alarmPart-1)%2;
			}
		}
		return 1;
	}else{
		return 0;
	}
}

int checkInterruptRight(void){
	if(getRight()==1){ //if interrupt on right joystick pin
		if(getState()==0){
			//select next setting
			selectState=(selectState+1)%4;
		}
		if(getState()==1){ //while in SET TIME state
			//select next from hour, min, sec (_time)
			timePart=(timePart+1)%3;
		}
		if(getState()==2){ //while in setalarm state
			//select next from hour, min, sec (_alarm)
			alarmPart=(alarmPart+1)%3;
		}
		return 1;
		}else{
			return 0;
		}
}

int checkInterruptUp(void){
	if(getUp()==1){ //if interrupt on up joystick pin
		if(getState()==1){ // while in SET TIME state
			//increment the hour,min,sec of the time to set
			incrementTime(timePart);
		}
		if(getState()==2){ //while in SET ALARM state
			//increment the hour,min,sec of the alarm to set
			incrementAlarm(alarmPart);
		}
		return 1;
	}else{
		return 0;
	}
}

int checkInterruptDown(void){
	if(getDown()==1){ //if interrupt on down joystick  pin
		if(getState()==1){ //while in SET TIME state
			//decrement the hour,min,sec of the time to set
			decrementTime(timePart);
		}
		if(getState()==2){ //while in SET ALARM state
			//decrement the hour,min,sec of the alarm to set
			decrementAlarm(alarmPart);
		}
		return 1;
	}else{
		return 0;
	}
}

int checkInterruptCenter(void){
	if(getCenter()==1){ //if interrupt on center joystick pin
		if(getState()==4){ //while in alarmstate
			setAlarm(0); //alarm on
		}
		return 1;
	}else{
		return 0;
	}
}
