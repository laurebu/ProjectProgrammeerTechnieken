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
}states;

/*
 * prototypes
 */
int main(void);
void setState(int stateValue);
int getState(void);
int getAlarm(void);
void setAlarm(int);

#endif //MAIN_H
