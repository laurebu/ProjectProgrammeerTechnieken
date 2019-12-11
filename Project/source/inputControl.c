/*
 * @author: Lander Buysse
 * @file: inputControl.c
 *
 * description: .c file for the input control
 * 					contains:
 * 						getters and setter to be used in the main method
 * 						methods to check interrupts and define the action
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
	timeParts timePart=0;
	changeState selectState=0;
	alarmParts alarmPart=0;
	dateParts datePart=0;
	int hour_time=0;
	int min_time=0;
	int sec_time=0;
	int hour_alarm=0;
	int min_alarm=0;
	int sec_alarm=0;
	int dayToSet=1;
	int monthToSet=1;
	int yearToSet=2019;

/* * * * * *
 * methods *
 * * * * * */

	int getDayToSet(void){
		return dayToSet;
	}
	int getMonthToSet(void){
		return monthToSet;
	}
	int getYearToSet(void){
		return yearToSet;
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

	void syncDateToSet(int d, int m, int y){
		dayToSet=d;
		monthToSet=m;
		yearToSet=y;
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
			case 5:
				str="Set Date";
				break;
			default:
				setting=0; //just in case something went wrong
				str="Standard";
				break;
		}
		return str;
	}

	void incrementDate(int dmy){
		switch(dmy){
			case 0: //day
				switch(monthToSet){
					// 31 days in a month
					case 1: //january
					case 3: //march
					case 5: //may
					case 7: //july
					case 8: //august
					case 10: //october
					case 12: //December
						dayToSet=(dayToSet+1)%31;
                        if(dayToSet==0){
                            dayToSet=31;
                        }
						break;

					// 29 or 28 days in a month (depending on if the year is a leap year or not)
					case 2: //february
						if(leapyearSet(yearToSet)==1){
							// Leap year
							if(dayToSet == 29){
								// End of the month
								dayToSet = 1;
							}
							else {
								dayToSet = dayToSet + 1;
							}
						}
						else {
							// Not a leap year
							if(dayToSet == 28){
								//end of the month
								dayToSet = 1;
							}
							else {
								dayToSet = dayToSet + 1;
							}
						}
						break;
					// 30 days in a month
					case 4://april
					case 6://june
					case 9://september
					case 11://november
						dayToSet=(dayToSet+1)%30;
					default:
						break;
					}
				break;
			case 1: //month
				monthToSet=(monthToSet+1)%12;
                if (monthToSet==0){
                	monthToSet=12;
                }
                adjustDays();
				break;
			case 2: //year
				yearToSet=yearToSet+1;
				if(leapyearSet(yearToSet)==0 && monthToSet==2 && dayToSet>28){
					//if the date was previously 29 february of a leapyear and the new year is not, correct the days
					dayToSet=28;
				}
				adjustDays();
				break;
			default:
				break;
		}
	}

	void decrementDate(int dmy){
		switch(dmy){
			case 0: //day
				switch(monthToSet){
					// 31 days in a month
					case 1: //january
					case 3: //march
					case 5: //may
					case 7: //july
					case 8: //august
					case 10: //october
					case 12: //December
						if(dayToSet==1){
							dayToSet=31;
						}else{
							dayToSet=dayToSet-1;
						}
						break;

					// 29 or 28 days in a month (depending on if the year is a leap year or not)
					case 2: //february
						if(leapyearSet(yearToSet)==1){
							// Leap year
							if(dayToSet == 1){
								// End of the month
								dayToSet = 29;
							}
							else {
								dayToSet = dayToSet- 1;
							}
						}
						else {
							// Not a leap year
							if(dayToSet == 1){
								//end of the month
								dayToSet = 28;
							}
							else {
								dayToSet = dayToSet-1;
							}
						}
						break;
					// 30 days in a month
					case 4://april
					case 6://june
					case 9://september
					case 11://november
						if (dayToSet==1){
							dayToSet=30;
						}else{
							dayToSet=dayToSet-1;
						}
					default:
						break;
					}
				break;
			case 1: //month
				if(monthToSet==1){
					monthToSet=12;
				}else{
					monthToSet=monthToSet-1;
				}
				adjustDays();
				break;
			case 2: //year
				if(yearToSet!=0){
					yearToSet=yearToSet-1;
				}
				adjustDays();
				break;
			default:
				break;
		}
	}

	void adjustDays(void){
		//if month to set has less than 31 days and the days is currently higher from a different month
		//==> correct the days
		if(dayToSet>30 && (monthToSet==4 || monthToSet==6 || monthToSet==9 || monthToSet==11)){
			dayToSet=30;
		}
		//special case: february,
		if(monthToSet==2){
			if(leapyearSet(yearToSet)){//in case of a leapyear
				if(dayToSet>29){
					dayToSet=29;
				}
			}else{
				if(dayToSet>28){
					dayToSet=28;
				}
			}
		}
	}

	int leapyearSet(int year){
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
			switch(getState()){
				case 0: //while in standard state
					//select previous setting
					if(selectState==0){
						selectState=5;
					}else{
						if(selectState==5){
							selectState=3;
						}else{
							selectState=(selectState-1)%5;
						}
					}
					break;
				case 1: //while in SET TIME state
					//select previous from hour, min, sec (_time)
					if(timePart==0){
						timePart=2;
					}else{
						timePart=(timePart-1)%2;
					}
					break;
				case 2: //while in SET ALARM state
					//select previous from hour, min, sec (_alarm)
					if(alarmPart==0){
						alarmPart=2;
					}else{
						alarmPart=(alarmPart-1)%2;
					}
					break;
				case 5: //while in SET DATE state
					//select previous from day,month, year
					if(datePart==0){
						datePart=2;
					}else{
						datePart=(datePart-1)%2;
					}
					break;
				default:
					//Do nothing in the set music or alarm state
					break;
			}
			return 1;
		}else{
			return 0;
		}
	}

	int checkInterruptRight(void){
		if(getRight()==1){ //if interrupt on right joystick pin
			switch(getState()){
				case 0: //while in STANDARD state
					//select next setting
					if (selectState==3){
						selectState=5;
					}else{
						selectState=(selectState+1)%6;
					}
					break;
				case 1: //while in SET TIME state
					//select next from hour, min, sec (_time)
					timePart=(timePart+1)%3;
					break;
				case 2: //while in SET ALARM state
					//select next from hour, min, sec (_alarm)
					alarmPart=(alarmPart+1)%3;
					break;
				case 5:
					//select next from day, month, year
					datePart=(datePart+1)%3;
					break;
				default:
					//Do nothing in the set music or alarm state
					break;
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
			if(getState()==5){ //while in SET DATE state
				//increment the day, month year of the day to set
				incrementDate(datePart);
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
			if(getState()==5){ //while in SET DATE state
				//decrement the day,month, year of the date to set
				decrementDate(datePart);
			}
			return 1;
		}else{
			return 0;
		}
	}

	int checkInterruptCenter(void){
		if(getCenter()==1){ //if interrupt on center joystick pin
			if(getState()==4){ //while in alarmstate
				setAlarm(0); //alarm off
			}
			return 1;
		}else{
			return 0;
		}
	}
