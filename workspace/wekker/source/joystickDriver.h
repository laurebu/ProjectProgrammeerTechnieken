/*
 * @author: Lander Buysse
 * @file: joystickDriver.h
 */
#ifndef JOYSTICKDRIVER_H
#define JOYSTICKDRIVER_H

//define the values of the GPIO pins for the joystick
#define RIGHT	10
#define LEFT	11
#define UP		10
#define DOWN	11
#define CENTER	23

//define the required values for the clock gate control by port (B and C)
#define SCGC5B		0x400
#define SCGC5C		0x800

/*
 *	prototypes
 */
void joystickInit(void);

#endif //JOYSTICKDRIVER_H
