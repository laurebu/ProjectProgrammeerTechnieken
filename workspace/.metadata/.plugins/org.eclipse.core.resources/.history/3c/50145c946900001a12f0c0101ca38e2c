/*
 * @author: Lander Buysse
 * @file: ledDriver.h
 */
#ifndef LEDDRIVER_H
#define LEDDRIVER_H

//files to include
#include "stdio.h"

//define the value of the GPIO pin for each led
#define BLUE_FRDM	21		//blue led on the frdm-k64f
#define RED_FRDM    22		//red led on the frdm-k64f
#define GREEN_FRDM  26		//green led on the frdm-k64f
#define BLUE_AP		12		//blue led on the application shield
#define RED_AP      2		//red led on the application shield
#define GREEN_AP	4		//green led on the application shield

//define the required values for the clock gate control by port (A,B,C,D,E)
#define SCGC5A		0x200
#define SCGC5B		0x400
#define SCGC5C		0x800
#define SCGC5D		0x1000
#define SCGC5E		0x2000

/*
 *  prototypes
 */
void turnOnLed(int nr);
void turnOffLed(int nr);
void initialiseLed(int nr);

#endif //LEDDRIVER_H
