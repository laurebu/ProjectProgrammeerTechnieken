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
   SIM_SCGC6 |= SIM_SCGC6_FTM0_MASK;	/*Enable the FTM0 Clock*/
   SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;	/*Enable the PORTD Clock*/
   PORTD_PCR5 = PORT_PCR_MUX(4);		/*MUX = ALT 4*/

   NVIC_EnableIRQ(FTM0_IRQn);		/*Enable the FTM Interrupt*/
   FTM0_SC |= 0x004F;				/*Setting TOIE = 1,CLKS =  01, PS = 111*/
   FTM0_MOD = 32000;				/*Setting the Modulo register = 32000*/
   FTM0_C5SC |= 0x0028;				/*Setting MSB = 1, ELSnB = 1*/
   FTM0_C5V = 500;					/*Value of the Channel*/

    int i;
    for (;;) {
        i++;						/*Just a Count*/
    }
    return 0;
}

void FTM0_IRQHandler (void)
{
  //Clear interrupt flag
	unsigned long ChannelValue = FTM0_C5V;			/*Take the value of the Channel to compare it*/
  (void)FTM0_SC;
  FTM0_SC |= 0x0080;								/*FTM counter has overflow*/
  if(ChannelValue < 32000)							/*Channel Value > Modulo Value*/
  {
	  FTM0_C5V += 500;								/*Add 500 to Channel*/
  }
  else
  {
	  FTM0_C5V = 0;									/*Set Channel in 0*/
  }
}

