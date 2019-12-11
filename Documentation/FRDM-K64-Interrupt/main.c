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

void DelayFunction (void);

int main(void)
{
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK; 		/*Enable Port B Clock Gate Control*/
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;		/*Enable Port C Clock Gate Control*/
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;      /*Enable Port A Clock Gate Control*/

	PORTB_PCR21 = 0x100;        /*Blue Led, configured as Alternative 1 (GPIO)*/
	PORTB_PCR22 = 0x100;		/*Red Led, configured as Alternative 1 (GPIO)*/
	PORTC_PCR6  = 0x90100; 		/*PORTC_PCR6: ISF=0,IRQC=9,MUX=1 */
	PORTA_PCR4  = 0x100;		/*Changing the NMI to GPIO*/

	GPIOB_PDDR |= (1 << 21);		/*Setting the bit 21 of the port B as Output*/
	GPIOB_PDDR |= (1 << 22);		/*Setting the bit 22 of the port B as Output*/
	GPIOC_PDDR |= (0 << 6);			/*Setting the bit 6 of the port C as Input*/

	/*Turn off Red and Blue Leds*/
	GPIOB_PDOR |= (1 << 22);	/*Turn Off Red Led*/
	GPIOB_PDOR |= (1 << 21);	/*Turn Off Blue Led*/

	PORTC_ISFR = PORT_ISFR_ISF(0x40); 	  /* Clear interrupt status flag */
	NVIC_EnableIRQ(PORTC_IRQn);			/*Enable the PORTC interrupt*/

    for (;;)
    {
		GPIOB_PTOR |= (1 << 22); 		/*Red LED blinking*/
		DelayFunction();
    }
    return 0;
}


void PORTC_IRQHandler(void)
{
	DelayFunction();
	GPIOB_PSOR |= (1 << 22);				/*Turn Off Red Led*/
	GPIOB_PCOR |= (1 << 21);				/*Turn On Blue Led*/
	DelayFunction();
	GPIOB_PSOR |= (1 << 21);				/*Turn Off Blue Led*/
	DelayFunction();

	PORTC_ISFR = PORT_ISFR_ISF(0x40);		/* Clear interrupt status flag */
}

void DelayFunction(void)
{
	int cnt;
	for(cnt=0; cnt<1000000; cnt++)
	{

	}
}
