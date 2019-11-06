/*
 * @author: Lander Buysse
 * @file: ledDriver.c
 */

//files to include
#include "ledDriver.h"
#include "MK64F12.h"

/*
 * turn on led
 *
 * nr --> GPIO nr (values defined in ledDriver.h)
 */
void turnOnLed(int nr){
	switch(nr){
		case BLUE_FRDM:
		case RED_FRDM:
			GPIOB->PDOR = (0 << nr); //turn on led
			break;
		case GREEN_FRDM:
			GPIOE->PDOR = (0 << nr); //turn on led
			break;
		case BLUE_AP:
		case GREEN_AP:
			GPIOC->PDOR = (0 << nr); //turn on led
			break;
		case RED_AP:
			GPIOA->PDOR = (0 << nr); //turn on led
			break;
		default:
			break;
	}
}

/*
 * turn off led
 *
 * nr --> GPIO nr (values defined in ledDriver.h)
 */
void turnOffLed(int nr){
	switch(nr){
			case BLUE_FRDM:
			case RED_FRDM:
				GPIOB->PDOR = (1 << nr); //turn off led
				break;
			case GREEN_FRDM:
				GPIOE->PDOR = (1 << nr); //turn off led
				break;
			case BLUE_AP:
			case GREEN_AP:
				GPIOC->PDOR = (1 << nr); //turn off led
				break;
			case RED_AP:
				GPIOA->PDOR = (1 << nr); //turn off led
				break;
			default:
				break;
		}
}

/*
 * initialise led by:
 * 		 enabling port clock control gate,
 * 		 configure leds as alternative 1
 * 		 set the pin as output
 *
 * 		 nr --> GPIO nr (values defined in ledDriver.h)
 */
void initialiseLed(int nr){
	switch(nr){
		case BLUE_FRDM:
		case RED_FRDM:
			SIM->SCGC5 |= SCGC5B; //enable Port B Clock Gate Control
			PORTB->PCR[nr] = 0x100; //blue or red led, configured as Alternative 1 (GPIO)
			GPIOB->PDDR |= (1 << nr); //setting bit <nr> of the port B as output
			break;
		case GREEN_FRDM:
			SIM->SCGC5 |= SCGC5E; //enable Port E Clock Gate Control
			PORTE->PCR[nr] = 0x100; //green led, configured as Alternative 1 (GPIO)
			GPIOE->PDDR |= (1 << nr); //setting bit <nr> of the port E as output
			break;
		case BLUE_AP:
		case GREEN_AP:
			SIM->SCGC5 |= SCGC5C; //enable Port C Clock Gate Control
			PORTC->PCR[nr] = 0x100; //blue or green led, configured as Alternative 1 (GPIO)
			GPIOC->PDDR |= (1 << nr); //setting bit <nr> of the port C as output
			break;
		case RED_AP:
			SIM->SCGC5 |= SCGC5A; //enable Port C Clock Gate Control
			PORTA->PCR[nr] = 0x100; //blue or green led, configured as Alternative 1 (GPIO)
			GPIOA->PDDR |= (1 << nr); //setting bit <nr> of the port C as output
			break;
		default:
			break;
	}
}

