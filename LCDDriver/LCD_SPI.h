/*
 * @author: Laure Buysse
 * @file: LCD_SPI.h
 */

//files to include
#include <stdio.h>
#include "MK64F12.h"

//define the GPIO pins for the SPI_LCD
#define SPI_CS		0	//on shield: D10	- on FDRM-k64F: PTD0
#define SPI_A0		3	//on shield: D7	    - on FDRM-k64F: PTC3
#define SPI_SCK		1	//on shield: D13	- on FDRM-k64F: PTD1
#define SPI_reset	3	//on shield: D12	- on FDRM-k64F: PTD3
#define SPI_MOSI	2	//on shield: D11	- on FDRM-k64F: PTD2

//define the required values for the clock gate control by port (A,B,C,D,E)
#define SCGC5A		0x200
#define SCGC5B		0x400
#define SCGC5C		0x800
#define SCGC5D		0x1000
#define SCGC5E		0x2000

//pins
#define Halt	0
#define Freeze	27
#define EOQF	28
#define EOQ		27
#define PCS		16
#define TCF		31

//commands for lcd
#define OFF		0xAE
#define ON		0xAF

//commands for display
#define displayOff	0xAE
#define displayOn	0xAF

//functions
void SPI_config();
void SPI_write(uint8_t command);

