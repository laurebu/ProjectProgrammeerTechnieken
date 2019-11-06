/*
 * @author: Lander Buysse
 * @file: speakerDriver.c
 */

//files to include
#include <stdio.h>
#include "MK64F12.h"
#include "speakerDriver.h"
#include "speakerControl.h"

/*
 * plays a note where the frequency=note_value
 */
void playNote(int note_value){
		if(getAlarmStatus()==1){
			int val = 164000/note_value;
			FTM0->SC = 0x004F; 				//setting time overflow enable interrupt=1, CLKS = 01, PS = 111
			FTM0->MOD = val;
			FTM0->CONTROLS[1].CnSC = 0x0028;	//set the FTM to work as a center aligned PWM, MSB=1, ELSn
			FTM0->CONTROLS[1].CnV = val/2; //set the  value of the channel to have the required frequency (164kHz/value= f)
			GPIOC->PDDR = (1 << 2); //setting bit <nr> of the port B as output
		}else{
			stopNote();
		}
}

/*
 * stops playing a note
 */
void stopNote(void){
	FTM0->SC =0x0027;
}

/*
 * initialises the PWM
 */
void initPWM(void){
	SIM->SCGC6 = SIM_SCGC6_FTM0_MASK;   //enable the FTM0 clock
	SIM->SCGC5 = SIM_SCGC5_PORTC_MASK;  //enable the portc clock
	PORTC->PCR[2] = PORT_PCR_MUX(4);     //configure as alternative
}


