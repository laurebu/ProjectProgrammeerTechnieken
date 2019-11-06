/*
 * @author: Lander Buysse
 * @file: speakerControl.c
 *
 */

//files to include
#include "speakerDriver.h"
#include "speakercontrol.h"
#include "main.h"

/*
 * return the current alarm status
 * 0=off
 * 1=on
 */
int getAlarmStatus(){
	return getAlarm();
}
/*
 * calls the initialize method for the pwm from the speaker driver
 */
void initSpeaker(void){
	initPWM();
}

/*
 * pause in between notes or keep a note going for a while
 */
void pause(int loops){
	while(loops--){
		asm("nop");
	}
}

/*
 * play and note for a specified duration
 */
void note(int freq, int duration){
	playNote(freq);
	pause(duration);
}

/*
 * plays an standard alarm sound
 */
void standardAlarmSound(void){
	pause(500000);
	note(annoying,1100000);
	stopNote();
	pause(500000);
	note(annoying,1100000);
	stopNote();
	pause(500000);
	note(annoying,1100000);
	stopNote();
	pause(500000);
}

/*
 * plays a part of Edvard Grieg's morgenstimmung
 */
void Morgenstimmung_EG(void){
	int delay= 1200000;
	A5_Fc5_E5_D5_E5_Fc5();
	A5_Fc5_E5_D5_E5_Fc5();
	note(A5,delay);
	note(Fc5,delay);
	note(A5,delay);
	note(B5,delay);
	note(Fc5,delay);
	note(B5,delay);
	note(A5,delay);
	note(Fc5,delay);
	note(E5,delay);
	note(D5,delay);
	pause(delay);
	pause(delay);
	stopNote();
	pause(delay);
}



/*
 * plays Ludwig van Beethoven's Für Elise
 */
void furElise_LvB(void){
	int delay=500000;
	E5_Dc5_E5_Dc5_E5_B4_D5_C5_A4();
	A3_C4_E4_A4_B4();
	Gc3_E4_Gc4_B4_C5_A3_E4();
	E5_Dc5_E5_Dc5_E5_B4_D5_C5_A4();
	A3_C4_E4_A4_B4();
	Gc3_E4_C5_B4_A4();
	note(A3,delay);
	E5_Dc5_E5_Dc5_E5_B4_D5_C5_A4();
	A3_C4_E4_A4_B4();
	Gc3_E4_Gc4_B4_C5_A3_E4();
	E5_Dc5_E5_Dc5_E5_B4_D5_C5_A4();
	A3_C4_E4_A4_B4();
	Gc3_E4_C5_B4_A4();
	note(A3,delay);
	note(B4,delay);
	note(C5,delay);
	note(D5,delay);
	note(E5,delay*2);
	note(C4,delay);
	note(G4,delay);
	note(F5,delay);
	note(E5,delay);
	note(D5,delay*2);
	note(B3,delay);
	note(F4,delay);
	note(E5,delay);
	note(D5,delay);
	note(C5,delay*2);
	note(A3,delay);
	note(E4,delay);
	note(D5,delay);
	note(C5,delay);
	note(B4,delay*2);
	note(E4,delay*2);
	stopNote();
	note(E4,delay);
	note(E5,delay);
	note(E4,delay);
	note(E5,delay);
	note(E5,delay);
	note(E6,delay);
	note(Dc5,delay);
	E5_Dc5_E5_Dc5_E5_B4_D5_C5_A4();
	A3_C4_E4_A4_B4();
	Gc3_E4_Gc4_B4_C5_A3_E4();
	E5_Dc5_E5_Dc5_E5_B4_D5_C5_A4();
	A3_C4_E4_A4_B4();
	Gc3_E4_C5_B4_A4();
	stopNote();
}

/*
 * plays an octave forwards and backwards (C4->C5->C4)
 */
void octave(){
	int delay=850000;
	note(C4,delay);
	note(D4,delay);
	note(E4,delay);
	note(F4,delay);
	note(G4,delay);
	note(A4,delay);
	note(B4,delay);
	note(C5,delay);
	note(B4,delay);
	note(A4,delay);
	note(G4,delay);
	note(F4,delay);
	note(E4,delay);
	note(D4,delay);
	note(C4,0);
}

/*
 * plays a note sequence (A4_Fc4_E4_D4_E4_Fc4_A4)
 */
void A4_Fc4_E4_D4_E4_Fc4(void){
	int delay= 1200000;
	note(A4,delay);
	note(Fc4,delay);
	note(E4,delay);
	note(D4,delay);
	note(E4,delay);
	note(Fc4,delay);
	stopNote();
}

/*
 * plays a note sequence (Gc3_E4_Gc4_B4_C5_A3_E4)
 */
void Gc3_E4_Gc4_B4_C5_A3_E4(void){
	int delay=500000;
	note(Gc3,delay);
	note(E4,delay);
	note(Gc4,delay);
	note(B4,delay);
	note(C5,delay*2);
	note(E3,delay);
	note(A3,delay);
	note(E4,delay);
}

/*
 * plays a note sequence(Gc3_E4_C5_B4_A4)
 */
void Gc3_E4_C5_B4_A4(void){
	int delay=500000;
	note(Gc3,delay);
	note(E4,delay);
	note(C5,delay);
	note(B4,delay);
	note(A4,delay*2);
}
/*
 * plays a note sequence (A3_C4_E4_A4_B4)
 */
void A3_C4_E4_A4_B4(void){
	int delay=500000;
	note(A3,delay);
	note(C4,delay);
	note(E4,delay);
	note(A4,delay);
	note(B4,delay*2);
}

/*
 * plays a note sequence (A5_Fc5_E5_D5_E5_Fc5)
 */
void A5_Fc5_E5_D5_E5_Fc5(void){
	int delay= 1200000;
	note(A5,delay);
	note(Fc5,delay);
	note(E5,delay);
	note(D5,delay);
	note(E5,delay);
	note(Fc5,delay);
	stopNote();
}

/*
 * plays a sequence of notes(E5_Dc5_E5_Dc5_E5_B4_D5_C5_A4)
 */
void E5_Dc5_E5_Dc5_E5_B4_D5_C5_A4(void){
	int delay=500000;
	note(E5,delay);
	note(Dc5,delay);
	note(E5,delay);
	note(Dc5,delay);
	note(E5,delay);
	note(B4,delay);
	note(D5,delay);
	note(C5,delay);
	note(A4,delay*2);
}
