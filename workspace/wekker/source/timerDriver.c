/*
 * @author: Laure Buysse
 * @file: timerDriver.c
 */

//files to include
#include "timerDriver.h"

#include <stdio.h>
#include "MK64F12.h"
#include <stdlib.h>

int secondsTotal;
int timebit;

void init_timer(){
	/* Enable all necessary ports for the timer */
	SIM->SCGC6 |= SIM_SCGC6_PIT_MASK;

	/* Configure timer */
		/* Module Control Register */
		PIT->MCR = 0x00;

		/* Timer Load Value Register */
		PIT->CHANNEL[0].LDVAL = 0x1312D00;

		/* Timer Control Register */
		PIT->CHANNEL[0].TCTRL |= (1 << 1);	// Timer interrupts enabled
		PIT->CHANNEL[0].TCTRL |= (1 << 0);	// Timer enabled
		/* Enable the interrupt */
		NVIC_EnableIRQ(PIT0_IRQn);

	// Initialise variables
	secondsTotal = 0;
	timebit = 0;
}

void PIT0_IRQHandler(void){
	timebit = 1;
	secondsTotal += 1;
	PIT->CHANNEL[0].TFLG |= (1 << 0);

}

int get_seconds_total(){
	return secondsTotal;
}

void set_seconds_total(int amount){
	secondsTotal = amount;
}

void set_timebit(int value){
	timebit = value;
}

int get_timebit(){
	return timebit;
}







