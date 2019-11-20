/*
 * @author: Lander Buysse
 * @file: joystickDriver.h
 */
#ifndef JOYSTICKDRIVER_H
#define JOYSTICKDRIVER_H

/* * * * * * *
 * variables *
 * * * * * * */
//define the values of the GPIO pins for the joystick
#define RIGHT	10
#define LEFT	11
#define UP		10
#define DOWN	11
#define CENTER	23

#define INTERRUPT_MASK_24 0x01000000  //bit mask for the 24th bit of a 32 bit int

//define the required values for the clock gate control by port (B and C)
#define SCGC5B		0x400
#define SCGC5C		0x800

/* * * * * * * *
 * prototypes  *
 * * * * * * * */
void joystickInit(void);
void PORTB_IRQHandler(void);
void PORTC_IRQHandler(void);
int getLeft(void);
int getRight(void);
int getUp(void);
int getDown(void);
int getCenter(void);

#endif //JOYSTICKDRIVER_H
