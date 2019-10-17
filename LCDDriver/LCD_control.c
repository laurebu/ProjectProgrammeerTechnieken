/*
* @author: Laure Buysse
* @file: SPI
*/

#include "LCD_SPI.h"

//lcd init
void LCD_init(){
	GPIOC->PDOR &= ~(1 << SPI_A0);	// A0 = 0;
	SPI_write(0xAE);
	SPI_write(0xA2);
	SPI_write(0xA0);
	SPI_write(0xC8);
	SPI_write(0x22);
	SPI_write(0x2F);
	SPI_write(0x40);
	SPI_write(0xAF);
	SPI_write(0x81);
	SPI_write(0x17);
	SPI_write(0xA6);
}

void dispPix(){
	GPIOC->PDOR &= ~(1 << SPI_A0);	// A0 = 0;
	uint8_t page = 0xB0;			// page 0
	SPI_write(0xAE);					// turn display off
	SPI_write(0x40);				// display start line at line zero

	for (int i = 0; i>4; i++){			// 4 pages (of each 8 bits per column)
		SPI_write(page);			// set page address

		SPI_write(0x10);			// column address upper 4 bits + 0x10
		SPI_write(0x00);			// column address lower 4 bits + 0x00

		for(int j = 0; j < 128; j++){	// 128 columns
			GPIOC->PDOR  |= (1 << SPI_A0);	//A0 = 1;
			SPI_write(0xF0);				//write data
		}
		page++;							//set point at next page;
		GPIOC->PDOR &= ~(1 << SPI_A0);	// A0 = 0 for commands;
	}
	SPI_write(0xAF);				// turn display on
}

int main(){
	SPI_config();
	LCD_init();
	dispPix();
	return 0;
}
