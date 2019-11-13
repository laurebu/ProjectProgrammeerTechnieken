/*
 * @author: Lander Buysse
 * @file: speakerControl.h
 */

#ifndef SPEAKERCONTROL_H
#define SPEAKERCONTROL_H

/*
 * prototypes
 */
void pause(int delay);
void initSpeaker(void);
void note(int,int);
int getAlarmStatus(void);

/***********************************************
 * tunes to play and some used note sequences  *
 ***********************************************/
void octave(void);
void standardAlarmSound(void);
void A4_Fc4_E4_D4_E4_Fc4(void);
void A5_Fc5_E5_D5_E5_Fc5(void);
void E5_Dc5_E5_Dc5_E5_B4_D5_C5_A4(void);
void A3_C4_E4_A4_B4(void);
void Gc3_E4_Gc4_B4_C5_A3_E4(void);
void Gc3_E4_C5_B4_A4(void);
void Morgenstimmung_EG(void);
void furElise_LvB(void);

#endif //SPEAKERCONTROL_H