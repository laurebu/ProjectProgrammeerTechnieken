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

	/*
	 * Function: note
	 * --------------
	 * Parameters:
	 * -----------
	 * 		int freq:
	 * 			frequency of the note to play
	 * 		int duration:
	 * 			duration of the note to play
	 * 				(in _asm nop cycles)
	 * Summary:
	 * --------
	 * 		plays a note through the speaker
	 */
	void note(int freq, int duration);

	/*
	 * Function: selectTune
	 * --------------------
	 * Parameters:
	 * -----------
	 * 		int distance:
	 * 				positive or negative integer to select a different tune
	 * 				example: -1 select previous tune
	 * 						 2 select the tune after the next one
	 * Summary:
	 * --------
	 * 		selects a tune
	 */
	void selectTune(int distance);

/*****************
 * tunes to play *
 *****************/
	/*
	 * Function: octave
	 * ----------------
	 * Summary:
	 * --------
	 * 		plays and octave from C4 to C5 and back to C4
	 */
	void octave(void);

	/*
	 * Function: standardAlarmSound
	 * ----------------------------
	 * Summary:
	 * --------
	 * 		plays a standard alarm sound (3 short notes)
	 */
	void standardAlarmSound(void);

	/*
	 * Function: Morgenstimmung_EG
	 * ---------------------------
	 * Summary:
	 * --------
	 * 		plays a simplified version of Edvard Griegs MorgenStimmung
	 */
	void Morgenstimmung_EG(void);

	/*
	 * Function: furElise_LvB
	 * ----------------------
	 * Summary:
	 * --------
	 * 		plays Ludwig van Beethoven's für Elise
	 */
	void furElise_LvB(void);

	/*
	 * Function: playMusic
	 * -------------------
	 * Parameters:
	 * -----------
	 * 		int nr:
	 * 			nr of the music tune to play
	 * 			0 ==> standard alarm sound
	 * 			1 ==> für Elise
	 * 			2 ==> Morgenstimmung
	 * 			3 ==> octave
	 * Summary:
	 * --------
	 * 		plays one of the defined music tunes
	 */
	void playMusic(int nr);

/* * * * * * * * * * * * * * *
 * some used note sequences  *
 * * * * * * * * * * * * * * */
	/*
	 * Function: E5_Dc5_E5_Dc5_E5_B4_D5_C5_A4
	 * -----------------------------
	 * Summary:
	 * --------
	 * 		plays a sequence of notes(E5_Dc5_E5_Dc5_E5_B4_D5_C5_A4)
	 * 			(used in für Elise)
	 */
	void E5_Dc5_E5_Dc5_E5_B4_D5_C5_A4(void);

	/*
	 * Function: A3_C4_E4_A4_B4
	 * ------------------------
	 * Summary:
	 * --------
	 * 		plays a sequence of notes(A3_C4_E4_A4_B4)
	 * 			(used in für Elise)
	 */
	void A3_C4_E4_A4_B4(void);

	/*
	 * Function: Gc3_E4_Gc4_B4_C5_A3_E4
	 * --------------------------------
	 * Summary:
	 * --------
	 * 		plays a sequence of notes(Gc3_E4_Gc4_B4_C5_A3_E4)
	 * 			(used in für Elise)
	 */
	void Gc3_E4_Gc4_B4_C5_A3_E4(void);

	/*
	 * Function: Gc3_E4_C5_B4_A4
	 * --------------------------------
	 * Summary:
	 * --------
	 * 		plays a sequence of notes(Gc3_E4_C5_B4_A4)
	 * 			(used in für Elise)
	 */
	void Gc3_E4_C5_B4_A4(void);

	/*
	 * Function: G5_E5_D5_Cn5_D5_E5
	 * --------------------------------
	 * Summary:
	 * --------
	 * 		plays a sequence of notes(G5_E5_D5_Cn5_D5_E5)
	 * 			(used in Morgenstimmung)
	 */
	void G5_E5_D5_Cn5_D5_E5(void);

#endif //SPEAKERCONTROL_H
