/*
 * @author: Laure Buysse
 * @file: timerControl.c
 *
 * description: .c file for the timer driver, contains:
 * 						method to initialise a PIT timer 
 * 						method to handle IRQ of the timer
 * 						method to count the amount of times the timer has gone off
 * 						method to reset the amount of time the timer has gone off
 */

/* * * * * * * * * * *
 * files to include  *
 * * * * * * * * * * */
#include "timerDriver.h"
#include <stdio.h>
#include "MK64F12.h"
#include <stdlib.h>

/* * * * * * *
 * variables *
 * * * * * * */
int secondsTotal;
int timebit;

/* * * * * *
 * methods *
 * * * * * */
void init_timer(){
	/* Enable all necessary ports for the timer */
	SIM->SCGC6 |= SIM_SCGC6_PIT_MASK;

	/* Configure timer */
		/* Module Control Register */
		PIT->MCR = 0x00;

		/* Timer Load Value Register */
		PIT->CHANNEL[0].LDVAL = 0x1413AA0;

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







