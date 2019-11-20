/*
 * @author: Lander Buysse
 * @file: speakerControl.h
 */

#ifndef SPEAKERCONTROL_H
#define SPEAKERCONTROL_H

/* * * * * * *
 * variables *
 * * * * * * */
typedef enum{    	//enum uses to define which songs can be used as an alarm tune
	STANDARDALARM=0,
	FURELISE=1,
	MORGENSTIMMUNG=2,
	OCTAVE=3,
}tunes;

/* * * * * * * *
 * prototypes  *
 * * * * * * * */
	/*
	 * Function: pause
	 * ---------------
	 * Parameters:
	 * -----------
	 * 		int delay:
	 * 			nr of assembler nop operation that will be executed
	 * Summary:
	 * --------
	 * 		pauses the playing of a note for a nr of assembler nop operations
	 */
	void pause(int delay);

	/*
	 * Function: getTune
	 * -----------------
	 * Parameters:
	 * -------
	 * 		int tune:
	 * 			nr of the tune of which the name will be returned
	 * Summary:
	 * --------
	 * 		returns the pointer to the first char of an array of chars that contains the string of a tuneName
	 */
	char* getTune(int tune);

	/*
	 * Function: getTuneNr
	 * -------------------
	 * Summary:
	 * --------
	 * 		returns the number of the currently selected tune
	 * 		(returns an integer in between 0 and nr of tunes-1)
	 */
	int getTuneNr(void);
	void note(int,int);
	void selectTune(int distance);
/***********************************************
 * tunes to play and some used note sequences  *
 ***********************************************/
	void octave(void);
	void standardAlarmSound(void);
	void A4_Fc4_E4_D4_E4_Fc4(void);
	void E5_Dc5_E5_Dc5_E5_B4_D5_C5_A4(void);
	void A3_C4_E4_A4_B4(void);
	void Gc3_E4_Gc4_B4_C5_A3_E4(void);
	void Gc3_E4_C5_B4_A4(void);
	void G5_E5_D5_Cn5_D5_E5(void);
	void Morgenstimmung_EG(void);
	void furElise_LvB(void);
	void playMusic(int);
#endif //SPEAKERCONTROL_H
