/*
 * @author: Lander Buysse
 * @file: speakerControl.c
 *
 */

/* * * * * * * * * * *
 * files to include  *
 * * * * * * * * * * */
#include "speakerDriver.h"
#include "speakercontrol.h"
#include "main.h"
#include <stdio.h>

/* * * * * * *
 * variables *
 * * * * * * */
tunes tune;

/* * * * * *
 * methods *
 * * * * * */

int getTuneNr(void){
	return tune;
}

char * getTune(int tune){
	char *str="";
	switch(tune){
	case STANDARDALARM:
		str="standard Alarm";
		break;
	case FURELISE:
		str="Fur Elise";
		break;
	case MORGENSTIMMUNG:
		str="MorgenStimmung";
		break;
	case OCTAVE:
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
 * pause in between notes or keep a note going for a while
 */
void pause(int loops){
	while(loops--){
		asm("nop");
	}
}

void note(int freq, int duration){
	if(getAlarm()==1){
		playNote(freq);
		pause(duration);
	}
}

void selectTune(int distance){
	if (distance<0){
		if(tune==0){
			tune=3;
		}else{
			tune=(tune+(distance))%3;
		}
	}else{
		tune=(tune+distance)%4;
	}
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
	G5_E5_D5_Cn5_D5_E5();
	G5_E5_D5_Cn5_D5_E5();
	note(G5,delay);
	note(E5,delay);
	note(G5,delay);
	note(A5,delay);
	note(E5,delay);
	note(A5,delay);
	note(G5,delay);
	note(E5,delay);
	note(D5,delay);
	note(Cn5,delay);
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
	note(Cn5,delay);
	note(D5,delay);
	note(E5,delay*2);
	note(Cn4,delay);
	note(G4,delay);
	note(F5,delay);
	note(E5,delay);
	note(D5,delay*2);
	note(B3,delay);
	note(F4,delay);
	note(E5,delay);
	note(D5,delay);
	note(Cn5,delay*2);
	note(A3,delay);
	note(E4,delay);
	note(D5,delay);
	note(Cn5,delay);
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
	note(Cn4,delay);
	note(D4,delay);
	note(E4,delay);
	note(F4,delay);
	note(G4,delay);
	note(A4,delay);
	note(B4,delay);
	note(Cn5,delay);
	note(B4,delay);
	note(A4,delay);
	note(G4,delay);
	note(F4,delay);
	note(E4,delay);
	note(D4,delay);
	note(Cn4,0);
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
	note(Cn5,delay*2);
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
	note(Cn5,delay);
	note(B4,delay);
	note(A4,delay*2);
}
/*
 * plays a note sequence (A3_C4_E4_A4_B4)
 */
void A3_C4_E4_A4_B4(void){
	int delay=500000;
	note(A3,delay);
	note(Cn4,delay);
	note(E4,delay);
	note(A4,delay);
	note(B4,delay*2);
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
	note(Cn5,delay);
	note(A4,delay*2);
}

/*
 * plays the selected music tune
 */
void playMusic(int nr){
	switch(getTuneNr()){
		case 0:
			standardAlarmSound();
			break;
		case 1:
			furElise_LvB();
			break;
		case 2:
			Morgenstimmung_EG();
			break;
		case 3:
			octave();
			break;
		default:
			break;
	}
}

void G5_E5_D5_Cn5_D5_E5(){
	int delay= 1200000;
	note(G5,delay);
	note(E5,delay);
	note(D5,delay);
	note(Cn5,delay);
	note(D5,delay);
	note(E5,delay);
	stopNote();
};
