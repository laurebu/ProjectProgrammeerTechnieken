/*
 * @author: Laure Buysse
 * @file: lcdDriver.c
 */

//files to include
#include "lcdDriver.h"
#include <stdio.h>
#include "MK64F12.h"
#include <stdlib.h>

uint8_t buffer[BUFFER_SIZE];

/*
 * delay function in ms
 */
void delay_ms(int ms) {
	for (long i = 0; i < (1700 * ms); i++) {}
}

/*
 * delay function in us
 */
void delay_us(int us) {
	for (long i = 0; i < (int)(1.7 * us); i++) {}
}

/*
 * TODO: add documentation
 */
void spi_write(unsigned char command){
	GPIOD->PDOR &= ~(1 << nCS); 			// chip select low

	for(int n=8; n>0; n--){
		GPIOD->PDOR &= ~(1 << SCK);		// clock low
		if(command & (1<<(n-1))){		// if current bit is '1'
			GPIOD->PDOR |= (1 << MOSI);	// set data pin high
		} else {
			GPIOD->PDOR &= ~(1 << MOSI);	// set data pin low
		}
		delay_us(1);					// wait a bit
		GPIOD->PDOR |= (1 << SCK); 		// clock high
		delay_us(1);
	}

	GPIOD->PDOR |= (1 << nCS); 			// chip select high
	delay_us(5);
}

/*
 * TODO: add documentation
 */
void lcd_data(unsigned char data) //Data Output Serial Interface
{
	GPIOC->PDOR |= (1 << A0);			// use data mode
	spi_write(data);
}

/*
 * TODO: add documentation
 */
void lcd_comm(unsigned char command) //Command Output Serial Interface
{
	GPIOC->PDOR &= ~(1 << A0);			// use command mode
	spi_write(command);
}

/*
 * TODO: add documentation
 */
void pins_init()
{
	//enable all necessary ports for the LCD
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;

	PORTD->PCR[nCS] |= PORT_PCR_MUX(1);		// Chip select enable
	PORTD->PCR[SCK] |= PORT_PCR_MUX(1);		// Clock enabled
	PORTD->PCR[MOSI] |= PORT_PCR_MUX(1);	// Output (mosi) enabled
	PORTD->PCR[RESET] |= PORT_PCR_MUX(1);	// Reset enabled
	PORTC->PCR[A0] |= PORT_PCR_MUX(1);		// A0 enabled (data/command pin)

	  /* Port Direction Register */
	GPIOD->PDDR |= (1 << nCS);				// Set all needed pins as output
	GPIOD->PDDR |= (1 << SCK);
	GPIOD->PDDR |= (1 << MOSI);
	GPIOD->PDDR |= (1 << RESET);
	GPIOC->PDDR |= (1 << A0);

}

/*
 * TODO: add documentation
 */
void copy_to_lcd(){
	/* Set starting page */
	char page = 0xB0;

	/* Page 0*/
	lcd_comm(0x00);
	lcd_comm(0x10);
	lcd_comm(page);

	for(int i=0; i<128; i++){
		lcd_data(buffer[i]);
	}

	/* Page 1*/
	page++;
	lcd_comm(0x00);
	lcd_comm(0x10);
	lcd_comm(page);

	for(int i=128; i<256; i++){
		lcd_data(buffer[i]);
	}

	/* Page 2 */
	page++;
	lcd_comm(0x00);
	lcd_comm(0x10);
	lcd_comm(page);

	for(int i=256; i<384; i++){
		lcd_data(buffer[i]);
	}

	/* Page 2 */
	page++;
	lcd_comm(0x00);
	lcd_comm(0x10);
	lcd_comm(page);

	for(int i=384; i<512; i++){
		lcd_data(buffer[i]);
	}

}

/*
 * TODO: add documentation
 */
void lcd_clear(){
	/* Create an empty buffer*/
	for(int i=0; i<512; i++){
		buffer[i] = 0x00;
	}

	/* Write buffer to lcd */
	copy_to_lcd();
}

/*
 * TODO: add documentation
 */
void lcd_init(){
	/* Init pins */
	pins_init();

	/* Reset lcd */
	GPIOD->PDOR &= ~(1 << RESET);		//send reset pulse
	delay_ms(50);					//wait
	GPIOD->PDOR |= (1 << RESET); 		//stop reset

	/* Set start value chip select and clock */
	GPIOD->PDOR |= (1 << RESET);		//set chip select to inactive
	GPIOD->PDOR |= (1 << SCK);		//set clock to inactive

	/* Init commands for lcd */
	lcd_comm(0xAE);
	lcd_comm(0xA2);
	lcd_comm(0xA0);
	lcd_comm(0xC8);
	lcd_comm(0x22);
	lcd_comm(0x2F);
	lcd_comm(0x40);
	lcd_comm(0xAF);
	lcd_comm(0x81);
	lcd_comm(0x17);
	lcd_comm(0xA6);

	/* Clear screen*/
	lcd_clear();
}

/*
 * TODO: add documentation
 * Set (mode 1) or erase (mode 0) one pixel (position: (x, y))
 */
void pixel(int x, int y, int mode){
	/* Make sure the pixel is on the screen*/
	if(x > 127 || y > 31 || x < 0 || y < 0) return;

	/* Check if the pixel needs to be erased or set */
	if(mode == 1){
		/* 8 bits per value in buffer, 128 columns, so offset of 128*n bits when y%8 = n */
		buffer[x+(y/8)*128] |= (1 << y%8);
	}
	else {
		/* 8 bits per value in buffer, 128 columns, so offset of 128*n bits when y%8 = n */
		buffer[x+(y/8)*128] &= ~(1 << y%8);
	}
}






