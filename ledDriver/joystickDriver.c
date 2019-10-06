/*
 * @author: Lander Buysse
 * @file: joystickDriver.c
 */

//files to include
#include <stdio.h>
#include "joystickDriver.h"
#include "MK64F12.h"

void joystickInit(){
	/*SIM->SCGC5 |= SCGC5B; //Enable port C Clock Gate Control for center, up and down

	PORTB->PCR[CENTER] = 0x90100; //ISF (24): set high for detection  interrupt
    							  //IRQC (16-19): interrupt on rising-edge: 0b1001
								  //MUX(8-10): configure as GPIO (Alternative 1): 0b001
	GPIOB->PDDR |= (0 << CENTER); //setting bit <nr> of the port B as output

	GPIOB->ISFR |= (1 << CENTER); //clear interrupt status flag
	NVIC_EnableIRQ(PORTB_IRQn);   //enable the interrupt*/
}

