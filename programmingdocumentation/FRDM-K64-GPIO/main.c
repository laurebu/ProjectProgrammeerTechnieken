/*
 * Copyright (c) 2014, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "MK64F12.h"

int main(void)
{
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK; 		/*Enable Port B Clock Gate Control*/
	SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;		/*Enable Port E Clock Gate Control*/
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;		/*Enable Port C Clock Gate Control*/
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;      /*Enable Port A Clock Gate Control*/

	PORTB_PCR21 = 0x100;        /*Blue Led, configured as Alternative 1 (GPIO)*/
	PORTB_PCR22 = 0x100;		/*Red Led, configured as Alternative 1 (GPIO)*/
	PORTE_PCR26 = 0x100;		/*Green Led, configured as Alternative 1 (GPIO)*/
	PORTC_PCR6  = 0x100;		/*Switch 2, configured as Alternative 1 (GPIO)*/
	PORTA_PCR4  = 0x100;		/*Changing the NMI to GPIO*/

	GPIOB_PDDR |= (1 << 21);		/*Setting the bit 21 of the port B as Output*/
	GPIOB_PDDR |= (1 << 22);		/*Setting the bit 22 of the port B as Output*/
	GPIOE_PDDR |= (1 << 26);		/*Setting the bit 26 of the port E as Output*/
	GPIOC_PDDR |= (0 << 6);			/*Setting the bit 6 of the port C as Input*/

	/*Turn off RGB Leds*/
	GPIOB_PDOR |= (1 << 22);	/*Turn Off Red Led*/
	GPIOB_PDOR |= (1 << 21);	/*Turn Off Blue Led*/
	GPIOE_PDOR |= (1 << 26);	/*Turn Off Green Led*/

	unsigned long Counter = 0x100000;		/*Delay Value*/

	for(;;)
	{
		if(GPIOC_PDIR == 0)			/*If the Switch 2 was press*/
		{
			GPIOB_PDOR = (1 << 21);	/*Turn On Red Led*/
			while(Counter != 0)		/*Wait Delay Value*/
			{
				Counter--;
			}
			Counter = 0x100000;		/*Recharger the Delay*/
			GPIOB_PDOR = (1 << 22) | ( 1 << 21); /*Turn Off Red Led*/
			while(Counter != 0)		/*Wait Delay Value*/
			{
				Counter--;
			}
			Counter = 0x100000;		/*Recharger the Delay*/

			GPIOE_PDOR = (0 << 26);	/*Turn On Green Led*/
			while(Counter != 0)		/*Wait Delay Value*/
			{
				Counter--;
			}
			Counter = 0x100000;		/*Recharger the Delay*/
			GPIOE_PDOR =  (1 << 26); /*Turn Off Green Led*/
			while(Counter != 0)		 /*Wait Delay Value*/
			{
				Counter--;
			}
			Counter = 0x100000;		/*Recharger the Delay*/

			GPIOB_PDOR = (1 << 22);	/*Turn On Blue Led*/
			while(Counter != 0)		/*Wait Delay Value*/
			{
				Counter--;
			}
			Counter = 0x100000;		/*Recharger the Delay*/
			GPIOB_PDOR =  (1 << 21) | (1 << 22); /*Turn Off Blue Led*/
			while(Counter != 0)		 /*Wait Delay Value*/
			{
				Counter--;
			}
			Counter = 0x100000;		/*Recharger the Delay*/
		}
	}
	return 0;
}
