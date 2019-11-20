/*
 * @author: Lander Buysse
 * @file: ledControl.h
 *
 * @description: .h file for the led control, contains:
 * 						method prototypes to call the methods from the driver
 *						method prototype for a delay in between notes, or to determine the duration of a note
 */

/* * * * * * * * * * *
 * files to include  *
 * * * * * * * * * * */
#include "ledDriver.h"

#ifndef LEDCONTROL_H
#define LEDCONTROL_H

/* * * * * * *
 * variables *
 * * * * * * */
#define BLUE_F BLUE_FRDM
#define RED_F RED_FRDM
#define GREEN_F GREEN_FRDM
#define BLUE_A BLUE_AP
#define RED_A RED_AP
#define GREEN_A GREEN_AP

/* * * * * * * *
 * prototypes  *
 * * * * * * * */

/*
 *
 */
void delay(long delay);
void turnOn(int nr);
void turnOff(int nr);
void initialise(int nr);

#endif //LEDCONTROL_H
