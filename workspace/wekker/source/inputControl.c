/*
 * @author: Lander Buysse
 * @file: inputControl.c
 */

//files to include
#include "inputControl.h"
#include <stdio.h>
#include "joystickDriver.h"
#include "buttonDriver.h"
#include "MK64F12.h"
#include "main.h"

//variables
tunes tune;
timeParts timePart;
changeState selectState;
alarmParts alarmPart;
int hour_time=0;
int min_time=0;
int sec_time=0;
int hour_alarm=0;
int min_alarm=0;
int sec_alarm=0;

/*
 * initialises used enums to their standard values
 */
void initEnums(void){
	timePart=HOUR_I;
	selectState=STANDARD_I;
	tune=STANDARDALARM;
	alarmPart=HOUR_A_I;
}

/*
 * returns the hour from the state set time
 */
int getHour(void){
	return hour_time;
}

/*
 * returns min from the state set time
 */
int getMin(void){
	return min_time;
}

/*
 * returns sec from the state set time
 */
int getSec(void){
	return sec_time;
}

/*
 * returns the hour from the state set alarm
 */
int getHourAlarm(void){
	return hour_alarm;
}

/*
 * returns the min from te state set alarm
 */
int getMinAlarm(void){
	return min_alarm;
}

/*
 * returns the sec from the state set alarm
 */
int getSecAlarm(void){
	return sec_alarm;
}

/*
 * returns the string to be displayed when choosing to change a setting
 */
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

/*
 * returns the string to be displayed when choosing to change a setting
 */
char * getTune(int tune){
	char *str="";
	switch(tune){
	case 0:
		str="standard Alarm";
		break;
	case 1:
		str="Für Elise (L. v. Beethoven)";
		break;
	case 2:
		str="MorgenStimmung (E. Grieg)";
		break;
	case 3:
		str="Octave";
		break;
	default:
		tune=0; //just in case something went wrong
		str="standard Alarm";
		break;
	}
	return str;
}

/*
 * increment the hour, min or sec when setting the time
 */
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


/*
 * decrement the hour,min or sec when setting the time
 */
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

/*
 * increment the hour, min or sec when setting the alarm
 */
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

/*
 * decrement the hour,min or sec when setting the alarm
 */
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
/*
 * interrupt handler for portc
 * 		handles the actions for joystick left and joystick right
 */
void PORTC_IRQHandler(void){
	switch(getState()){
			case 0: //STANDARD
				//joystick left
				if((PORTC->PCR[LEFT] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24){ //check if interrupt was called on left pin
					if (selectState==0){ //go to the previous option
						selectState=3;
					}
					else{
				        selectState = (selectState-1) % 4;
				    }
					PORTC->PCR[LEFT] &= ~(0 << 24); //clear the interrupt for the left pin
					//TODO: show the selected option
						//=>getSetting(selectState)
				}
				//joystick right
				if((PORTC->PCR[RIGHT] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24){ //check if interrupt was called on right pin
					selectState=(selectState+1)%4; //go to the next option
					PORTC->PCR[RIGHT] &= ~(0 << 24); //clear the interrupt for the right pin
					//TODO: show the selected option
						//=>getSetting(selectState)
				}
				break;
			case 1: //SETTIME
				//joystick left
				if((PORTC->PCR[LEFT] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24){//check if interrupt was called on left pin
					if (timePart==0){ //go to the previous option
						timePart=2;
					}
					else{
						timePart = (timePart-1) % 3;
					}
					PORTC->PCR[LEFT] &= ~(0 << 24); //clear the interrupt for the left pin
				}
				//joystick right
				if((PORTC->PCR[RIGHT] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24){ //check if interrupt was called on right pin
					timePart=(timePart+1)%3; //go to the next option
					PORTC->PCR[RIGHT] &= ~(0 << 24); //clear the interrupt for the right pin
				}
				break;
			case 2: //SETALARM
				//joystick left
				if((PORTC->PCR[LEFT] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24){//check if interrupt was called on left pin
					if (alarmPart==0){ //go to the previous option
						alarmPart=2;
					}else{
						alarmPart = (alarmPart-1) % 3;
					}
					PORTC->PCR[LEFT] &= ~(0 << 24); //clear the interrupt for the left pin
				}
				//joystick right
				if((PORTC->PCR[RIGHT] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24){ //check if interrupt was called on right pin
					alarmPart=(alarmPart+1)%3; //go to the next option
					PORTC->PCR[RIGHT] &= ~(0 << 24); //clear the interrupt for the right pin
				}
				break;
			case 3: //SETMUSIC
				//TODO:implement this,
				//joystick left
				if((PORTC->PCR[LEFT] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24){ //check if interrupt was called on left pin
					if (tune==0){ //go to the previous option
						tune=3;
					}else{
						tune = (tune-1) % 3;
					}
					PORTC->PCR[LEFT] &= ~(0 << 24); //clear the interrupt for the left pin
				}
				//joystick right
				if((PORTC->PCR[RIGHT] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24){ //check if interrupt was called on right pin
					tune=(tune+1)%4; //Set next tune
					PORTC->PCR[RIGHT] &= ~(0 << 24); //clear the interrupt for the right pin
				}
				break;
			case 4: //ALARM
				//joystick left or right ==> do nothing and clear the interrupts
				if(((PORTC->PCR[LEFT] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24) || ((PORTC->PCR[RIGHT] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24)){
					PORTC->PCR[LEFT] &= ~(0 << 24); //clear the interrupt for the left pin
					PORTC->PCR[RIGHT] &= ~(0 << 24); //clear the interrupt for the right pin
				}
				break;
			default:
				//do nothing, clr interrupts and go back to standard, just in case something happened
				PORTC->PCR[LEFT] &= ~(0 << 24); //clear the interrupt for the left pin
				PORTC->PCR[RIGHT] &= ~(0 << 24); //clear the interrupt for the right pin
				setState(0);
				break;
		}

}

/*
 * interrupt handler for portb
 * 		handles the actions for joystick up, joystick down and joystick center
 */
void PORTB_IRQHandler(void){
	switch(getState()){
		case 0: //STANDARD
			if((PORTB->PCR[CENTER] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24){ //check if interrupt was called on CENTER pin
				setState((int)selectState); //go to the selected state
				PORTB->PCR[CENTER] &= ~(0 << 24);  //Clear the interrupt for the CENTER pin
			}
			//nothing needs to happen here for the up and down pins so just clear the interrupts
			if(((PORTB->PCR[UP] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24) || ((PORTB->PCR[DOWN] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24)){
				PORTB->PCR[UP] &= ~(0 << 24);  // clear the interrupt for the up pin
				PORTB->PCR[DOWN] &= ~(0 << 24); //clear the interrupt for the down pin
			}
			break;
		case 1: //SETTIME
			//joystick center
			if((PORTB->PCR[CENTER] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24){ //check if interrupt was called on CENTER pin
				setState(0); //0==STANDARD state
				timePart=0; //Set back to hour_time
				PORTB->PCR[CENTER] &= ~(0 << 24);  //Clear the interrupt for the CENTER pin
			}
			//joystick down
			if((PORTB->PCR[DOWN] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24){ //check if interrupt was called on DOWN pin
				decrementTime(timePart); //decrement hour, min or sec
				PORTB->PCR[DOWN] &= ~(0 << 24); //clear the interrupt for the DOWN pin
			}
			//joystick up
			if((PORTB->PCR[UP] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24){ //check if interrupt was called on up pin
				incrementTime(timePart); //increment hour, min or sec
				PORTB->PCR[UP] &= ~(0 << 24);  //clear the interrupt for the UP pin
			}
			break;
		case 2: //SETALARM
			//joystick center
			if((PORTB->PCR[CENTER] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24){ //check if interrupt was called on CENTER pin
				setState(0); //0==STANDARD state
				timePart=0; //Set back to hour_time
				PORTB->PCR[CENTER] &= ~(0 << 24);  //Clear the interrupt for the center pin
			}
			//joystick down
			if((PORTB->PCR[DOWN] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24){ //check if interrupt was called on CENTER pin
				decrementAlarm(alarmPart); //decrement hour, min or sec of the alarm
				PORTB->PCR[DOWN] &= ~(0 << 24);//clear the interrupt for the DOWN pin
			}
			//joystick up
			if((PORTB->PCR[UP] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24){ //check if interrupt was called on up pin
				incrementAlarm(alarmPart); //increment hour, min or sec of the alarm
				PORTB->PCR[UP] &= ~(0 << 24);  //clear the interrupt for the UP pin
			}
			break;
		case 3: //SETMUSIC
			//joystick center
			if((PORTB->PCR[CENTER] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24){ //check if interrupt was called on CENTER pin
				setState(0); //0==STANDARD state
				PORTB->PCR[CENTER] &= ~(0 << 24);  //Clear the interrupt for the center pin
			}
			//joystick up
			if((PORTB->PCR[UP] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24){ //check if interrupt was called on UP pin
				PORTB->PCR[UP] &= ~(0 << 24);  //Clear the interrupt for the up pin
			}
			//joystick down
			if((PORTB->PCR[DOWN] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24){ //check if interrupt was called on DOWN pin
				PORTB->PCR[DOWN] &= ~(0 << 24);  //Clear the interrupt for the down pin
			}
			break;
		case 4: //ALARM
			//TODO: implement this
			//joystick center
			if((PORTB->PCR[CENTER] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24){ //check if interrupt was called on CENTER pin
				setAlarm(0);
				setState(0); //0==STANDARD state
				PORTB->PCR[CENTER] &= ~(0 << 24);  //Clear the interrupt for the center pin
			}
			break;
		default:
			setState(0); //go to standard state, just in case something went wrong
			//TODO:clr the interrupts
			break;
	}
}