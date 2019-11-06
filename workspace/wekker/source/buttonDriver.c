/*
* @author: Laure Buysse
* @file: buttonDriver.c
*/

//files to include
#include "inputControl.h"
#include <stdio.h>
#include "MK64F12.h"
#include "buttonDriver.h"

/**
*
* void SW2Init(void)
*
* Summary of the SW2Init function:
*
*   The SW2Init will initialise switch 2 on the k64F MBED board. This means
*   it also configures the IRQC for the switch.
*   Note that the switch is situated at Port C, bit 6
*
*/
void SW2Init(void){
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK; //Enable port C Clock Gate Control for switch

    PORTC->PCR[6] = 0x90100;            //ISF (24): set high for detection  interrupt
                                        //IRQC (16-19): interrupt on rising-edge: 0b1001
                                        //MUX(8-10): configure as GPIO (Alternative 1): 0b001

    GPIOC->PDDR |= (0 << 6);            //Configure switch as Input

    PORTC->ISFR = PORT_ISFR_ISF(0x40); //Clear interrupt status flag
    NVIC_EnableIRQ(PORTC_IRQn);        //Enable the interrupt
}
