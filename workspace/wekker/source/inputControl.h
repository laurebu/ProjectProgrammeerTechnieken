/*
 * @author: Lander Buysse
 * @file: inputControl.h
 */
#ifndef INPUTCONTROL_H
#define INPUTCONTROL_H

#define INTERRUPT_MASK_24 0x01000000

typedef enum{
	HOUR_I=0,
	MIN_I=1,
	SEC_I=2
}timeParts;

typedef enum{
	HOUR_A_I=0,
	MIN_A_I=1,
	SEC_A_I=2
}alarmParts;

typedef enum{
	STANDARD_I=0, //standard state that displays time
	TIME_I=1,	  //state to set the clock
	ALARM_I=2,	  //state to set the alarm time
	MUSIC_I=3,    //state to change the music tune used
}changeState;

typedef enum{
	STANDARDALARM=0,
	FURELISE=1,
	MORGENSTIMMUNG=2,
	OCTAVE=3,
}tunes;

/*
 * prototypes
 */
int getHour(void);
int getMin(void);
int getSec(void);
int getHourAlarm(void);
int getSecAlarm(void);
int getMinAlarm(void);
char* getTunes(int);
char* getSetting(int);
void setAlarm(int onOff);
void incrementTime(int hourMinSec);
void decrementTime(int hourMinSec);
void incrementAlarm(int);
void decrementAlarm(int);
void initEnums(void);


#endif //INPUTCONTROL_H
