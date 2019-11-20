/*
 * @author: Lander Buysse
 * @file: speakerDriver.h
 */
#ifndef SPEAKERDRIVER_H
#define SPEAKERDRIVER_H

/* * * * * * *
 * variables *
 * * * * * * */

	//define frequencies
	#define E3 165
	#define Gc3 208 //G#3 but '#' can't be used
	#define A3 220
	#define B3 247
	#define Cn4 262
	#define D4 294
	#define E4 330
	#define F4 349
	#define Fc4 370 //F#4 but '#' can't be used
	#define G4 392
	#define Gc4 415 //G#4 but '#' can't be used
	#define A4 440
	#define B4 494
	#define Cn5 523
	#define D5 587
	#define Dc5 622 //D#5 but '#' can't be used
	#define E5 659
	#define F5 698
	#define Fc5 740
	#define G5 784
	#define A5 880
	#define B5 988
	#define Cn6 1047
	#define E6 1319
	#define annoying 2500  //somewhere in between a D#7 and a E7

/* * * * * * * *
 * prototypes  *
 * * * * * * * */

	/*
	 * Function: initPWM
	 * -----------------
	 * Summary:
	 * --------
	 * 		initialises the PWM (needed to play a note)
	 * 		this method should be called once before trying to play a note
	 */
	void initPWM(void);

	/*
	 * Function: playNote
	 * ------------------
	 * Parameters:
	 * -----------
	 * 		int note_value:
	 * 			frequency of the note to be played
	 * Summary:
	 * --------
	 * 		plays a note where the frequency=note_value
	 */
	void playNote(int);

	/*
	 * Function: stopNote
	 * ------------------
	 * Summary:
	 * --------
	 * 		stops playing a note
	 */
	void stopNote(void);

#endif //SPEAKERDRIVER_H
