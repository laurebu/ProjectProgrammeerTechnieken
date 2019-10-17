#include "MK64F12.h"
#include "LCD_SPI.h"

void SPI_config();
void SPI_write(uint8_t command);

void SPI_config(){
	/*
	   * Initialise the needed pins:
	   *	- enable port clock control gate
	   *	- configure the pins as Alternative 1 (GPIO)
	   *	- set the pins as output
	   */
	  SIM->SCGC5 |= SCGC5C;					// port C clock gate control
	  SIM->SCGC5 |= SCGC5D;					// port D clock gate control
	  SIM->SCGC6 |= SIM_SCGC6_SPI0_MASK;	// SPI0 clock gate control

	  PORTD->PCR[0] |= PORT_PCR_MUX(2);
	  PORTD->PCR[1] |= PORT_PCR_MUX(2);
	  PORTD->PCR[2] |= PORT_PCR_MUX(2);
	  PORTD->PCR[3] |= PORT_PCR_MUX(2);
	  PORTC->PCR[3] |= PORT_PCR_MUX(1);
	  GPIOC->PDDR |= (1 << 3);

	  /*
	   * RSER: DMA/Interrupt Request Select and Enable Register
	   * 	No configuration necessary; default okay
	   */
	  SPI0->RSER |= 0;
	  SPI0->TCR |= 0;
	  SPI0->SR = (0xDA0A0000);

	  /*
	   * MCR: module configuration register
	   *	- (31) Master/Slave Mode Select: Master mode 			- 1
	   *	- (30) Continuous SCK Enable: Enabled 					- 0
	   *	- (28-29) SPI Configuration: SPI						- 00
	   *	- (27) Freeze: do not									- 0
	   *	- (26) Modified Timing Format Enable: disabled			- 0
	   *	- (25) Peripheral Chip Select Strobe Enable				- 0
	   *	- (24) Receive FIFO Overflow Overwrite Enable: ignored	- 0
	   *	- (22-23) Reserved										- 00
	   *	- (16-21) Peripheral Chip Select: inactive low			- 000001
	   *	- (15) Doze enable: no effect							- 0
	   *	- (14) Module Disable: enable module clocks				- 0
	   *	- (13) Disable Transmit FIFO: disable					- 1
	   *	- (12) Disable Receive FIFO: disable					- 1
	   *	- (11) Clear TX Fifo: clear counter						- 1
	   *	- (10) Flushes the RX Fifo: clear						- 1
	   *	- (8-9) Sample Pont : 0 protocol clock					- 00
	   *	- (3-7) Reserved										- 00000
	   *	- (2) Reserved											- 0
	   *	- (1) Reserved											- 0
	   *	- (0) Halt: stop transfers								- 1
	   */
	  SPI0->MCR = 0;
	  SPI0->MCR = (0x80013C01);

	  /*
	   * CTAR0: clock and transfer attributes register in master mode
	   *	- (31) Double Baude Rate								- 0
	   *	- (27-30) Frame Size									- 0111
	   *	- (26) Clock polarity: inactive value of SCK is low		- 0
	   *	- (25) Clock phase: on leading edge captured			- 0
	   *	- (24) LSB first: Data is transferred MSB first			- 0
	   *	- (22-23) PCS to SCK Delay Prescaler (value 1)			- 00
	   *	- (20-21) after SCK Delay Prescaler (value 1)			- 00
	   *	- (18-19) Delay after transfer control (value 1)		- 11
	   *	- (16-17) Baud rate scaler 								- 00
	   *	- (12-15) PSC to SCK delay scaler 						- 0001
	   *	- (8-11) after sck delay scaler 						- 0000
	   *	- (4-7) Delay after transfer scaler (value 2)			- 0101
	   *	- (0-3) Baud Rate Scaler (value 2)						- 0001
	   */
	  SPI0->CTAR[0] = 0;
	  SPI0->CTAR[0] = 0x38010130;
}

void SPI_write(uint8_t command)
{
	SPI0->MCR &= ~(1 << Halt);
	SPI0->MCR &= ~(1 << Freeze);

	SPI0->SR &= ~(1 << EOQF);

	SPI0->PUSHR = (1 << EOQ | 1 << PCS | command);

	while(!(SPI0->SR & SPI_SR_TCF_MASK));

	SPI0->SR |= (1 << TCF);
	SPI0->SR |= (1 << EOQF);
	SPI0->MCR |= (1 << Halt);
}
