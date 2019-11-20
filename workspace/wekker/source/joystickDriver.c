/*
 * @author: Lander Buysse
 * @file: joystickDriver.c
 */

/* * * * * * * * * * *
 * files to include  *
 * * * * * * * * * * */
#include <stdio.h>
#include "joystickDriver.h"
#include "MK64F12.h"
/* * * * * * *
 * variables *
 * * * * * * */
int joystickLeft=0;
int joystickRight=0;
int joystickUp=0;
int joystickDown=0;
int joystickCenter=0;

/* * * * * *
 * methods *
 * * * * * */

void joystickInit(void){

	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK; //Enable port B Clock Gate Control

	PORTB->PCR[UP] = 0x90100; 		//ISF (24): set high for detection  interrupt
	    							//IRQC (16-19): interrupt on rising-edge: 0b1001
									//MUX(8-10): configure as GPIO (Alternative 1): 0b001

	PORTB->PCR[CENTER] = 0x90100;   //ISF (24): set high for detection  interrupt
    							  	//IRQC (16-19): interrupt on rising-edge: 0b1001
								  	//MUX(8-10): configure as GPIO (Alternative 1): 0b001

	PORTB->PCR[DOWN] = 0x90100; 	//ISF (24): set high for detection  interrupt
	    							//IRQC (16-19): interrupt on rising-edge: 0b1001
									//MUX(8-10): configure as GPIO (Alternative 1): 0b001

	PORTC->PCR[LEFT] = 0x90100; 	//ISF (24): set high for detection  interrupt
	    							//IRQC (16-19): interrupt on rising-edge: 0b1001
									//MUX(8-10): configure as GPIO (Alternative 1): 0b001

	PORTC->PCR[RIGHT] = 0x90100; 	//ISF (24): set high for detection  interrupt
	    							//MUX(8-10): configure as GPIO (Alternative 1): 0b001

	GPIOB->PDDR |=  (0 << CENTER); 	//setting bit of the center pin of the port B as input
	GPIOB->PDDR |= (0 << UP);		//setting bit of the up pin of the port B as input
	GPIOB->PDDR |= (0 << DOWN);		//setting bit of the down pin of the port B as input
	GPIOC->PDDR |= (0 << LEFT);		//setting bit of the left pin of the port C as input
	GPIOC->PDDR |= (0 << RIGHT);	//setting bit of the right pin of the port C as input

	//next line doesn't work on the joystick for some reason :(
	//PORTB->ISFR = PORT_ISFR_ISF(0x1000000);	//clear interrupt status flag for center
	//so we do this instead to clear the interrupts on the pins, this does work :)
	PORTB->PCR[CENTER] &= ~(0 << 24); 	//clear the interrupt for the center pin
	PORTB->PCR[UP] &= ~(0 << 24); 		//clear the interrupt for the up pin
	PORTB->PCR[DOWN] &= ~(0 << 24); 	//clear the interrupt for the down pin
	PORTC->PCR[RIGHT] &= ~(0 << 24); 	//clear the interrupt for the right pin
	PORTC->PCR[LEFT] &= ~(0 << 24); 	//clear the interrupt for the left pin

	NVIC_EnableIRQ(PORTB_IRQn);   	//enable the interrupt
	NVIC_EnableIRQ(PORTC_IRQn);     //enable the interrupt
}

int getLeft(void){
	int result=joystickLeft; //temp variable
	joystickLeft=0; //reset the read variable back to zero
	return result; //return the temp variable
}

int getRight(void){
	int result=joystickRight; //temp variable
	joystickRight=0; //Reset the read variable back to zero
	return result;
}

int getUp(void){
	int result=joystickUp; //temp variable
	joystickUp=0; //Reset the read variable back to zero
	return result; //return the temp variable
}

int getDown(void){
	int result=joystickDown; //temp variable
	joystickDown=0; //Reset the read variable back to zero
	return result; //return the temp variable
}

int getCenter(void){
	int result=joystickCenter; //Temp variable
	joystickCenter=0; //Reset the read variable back to zero
	return result;
}

/*
 * interrupt handler for portc
 * 		handles the actions for joystick left and joystick right
 */
void PORTC_IRQHandler(void){
	if((PORTC->PCR[LEFT] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24){ //check if interrupt was called on LEFT pin
		joystickLeft=1;
		PORTC->PCR[LEFT] &= ~(0 << 24);  // clear the interrupt for the LEFT pin
	}
	if((PORTC->PCR[RIGHT] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24){ //check if interrupt was called on RIGHT pin
		joystickRight=1;
		PORTC->PCR[RIGHT] &= ~(0 << 24);  // clear the interrupt for the RIGHT pin
	}
}


/*
 * interrupt handler for portb
 * 		handles the actions for joystick up, joystick down and joystick center
 */
void PORTB_IRQHandler(void){
	if((PORTB->PCR[CENTER] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24){ //check if interrupt was called on CENTER pin
		joystickCenter=1;
		PORTB->PCR[CENTER] &= ~(0 << 24);  //Clear the interrupt for the CENTER pin
	}
	if((PORTB->PCR[UP] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24){ //check if interrupt was called on UP pin
		joystickUp=1;
		PORTB->PCR[UP] &= ~(0 << 24); //clear the interrupt for the UP pin
	}
	if((PORTB->PCR[DOWN] & INTERRUPT_MASK_24)==INTERRUPT_MASK_24){ //check if interrupt was called on DOWN pin
		joystickDown=1;
		PORTB->PCR[DOWN] &= ~(0 << 24); //clear the interrupt for the DOWN pin
	}
}


