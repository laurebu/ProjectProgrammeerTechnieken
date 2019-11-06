/*
 * LCDDriver.c
 *
 *  Created on: 1 nov. 2019
 *      Author: Anzhelina
 */

#include <stdio.h>
#include "MK64F12.h"

void pins_init();
void lcd_init();

uint8_t buffer[512];

void delay_ms(int ms) {
	for (long i = 0; i < (1700 * ms); i++) {}
}

void delay_us(int us) {
	for (long i = 0; i < (int)(1.7 * us); i++) {}
}

void spi_write(unsigned char command){
	GPIOD->PDOR &= ~(1 << 0); 			// chip select low

	for(int n=8; n>0; n--){
		GPIOD->PDOR &= ~(1 << 1);		// clock low
		if(command & (1<<(n-1))){		// if current bit is '1'
			GPIOD->PDOR |= (1 << 2);	// set data pin high
		} else {
			GPIOD->PDOR &= ~(1 << 2);	// set data pin low
		}
		delay_us(1);					// wait a bit
		GPIOD->PDOR |= (1 << 1); 		// clock high
		delay_us(1);
	}

	GPIOD->PDOR |= (1 << 0); 			// chip select high
	delay_us(5);
}

void lcd_data(unsigned char data) //Data Output Serial Interface
{
	GPIOC->PDOR |= (1 << 3);			// use data mode
	spi_write(data);
}

void lcd_comm(unsigned char command) //Command Output Serial Interface
{
	GPIOC->PDOR &= ~(1 << 3);			// use command mode
	spi_write(command);
}


void pins_init()
{
	//enable all necessary ports for the LCD
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;

	PORTD->PCR[0] |= PORT_PCR_MUX(1);		// Chip select enable
	PORTD->PCR[1] |= PORT_PCR_MUX(1);		// Clock enabled
	PORTD->PCR[2] |= PORT_PCR_MUX(1);		// Output (mosi) enabled
	PORTD->PCR[3] |= PORT_PCR_MUX(1);		// Reset enabled
	PORTC->PCR[3] |= PORT_PCR_MUX(1);		// A0 enabled (data/command pin)

	  /* Port Direction Register */
	GPIOD->PDDR |= (1 << 0);				// Set all needed pins as output
	GPIOD->PDDR |= (1 << 1);
	GPIOD->PDDR |= (1 << 2);
	GPIOD->PDDR |= (1 << 3);
	GPIOC->PDDR |= (1 << 3);

}

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

void lcd_clear(){
	/* Create an empty buffer*/
	for(int i=0; i<512; i++){
		buffer[i] = 0x00;
	}

	/* Write buffer to lcd */
	copy_to_lcd();
}

void lcd_init(){
	/* Init pins */
	pins_init();

	/* Reset lcd */
	GPIOD->PDOR &= ~(1 << 3);		//send reset pulse
	delay_ms(50);					//wait
	GPIOD->PDOR |= (1 << 3); 		//stop reset

	/* Set start value chip select and clock */
	GPIOD->PDOR |= (1 << 3);		//set chip select to inactive
	GPIOD->PDOR |= (1 << 1);		//set clock to inactive

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

/* Set (mode 1) or erase (mode 0) one pixel (position: (x, y)) */
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

/* Set (mode 1) or erase (mode 0) a line */
void line(int x0, int y0, int x1, int y1, int mode){
	/* Make sure the pixel is on the screen*/
	if(x0 > 127 || y0 > 31 || x0 < 0 || y0 < 0 || x1 > 127 || y1 > 31 || x1 < 0 || y1 < 0) return;

	/* Check if the line needs to be erased or set */
	if(mode == 1){
		/* Set line */
		if(y0 == y1){
			/* Horizontal line (y0 == y1) */
			int length = abs(x1-x0);

			for(int i=0; i<length;i++){
				if(x0 < x1){
					pixel(x0+i,y0,1);
				}
				else {
					pixel(x1+1,y0,1);
				}
			}
		}
		else {
			/* Vertical line (x0 == x1) */
			int length = abs(y1-y0);

			for(int i=0; i<length; i++){
				if(y0 < y1){
					pixel(x0,y0+i,1);
				}
				else {
					pixel(x0,y1+1,1);
				}
			}
		}
	}
	/* Erase line */
	else {
		if(y0 == y1){
			/* Horizontal line (y0 == y1) */
			int length = abs(x1-x0);

			for(int i=0; i<length;i++){
				if(x0 < x1){
					pixel(x0+i,y0,0);
				}
				else {
					pixel(x1+1,y0,0);
				}
			}
		}
		else {
			/* Vertical line (x0 == x1) */
			int length = abs(y1-y0);

			for(int i=0; i<length; i++){
				if(y0 < y1){
					pixel(x0,y0+i,0);
				}
				else {
					pixel(x0,y1+1,0);
				}
			}
		}
	}
}

void writeChar(int x, int y, char chara){
	if (chara == 'A'){
		line(x,y,x,y+5,1);
		line(x,y,x+3,y,1);
		line(x,y+3,x+3,y+3,1);
		line(x,y+2,x+3,y+2,1);
	}
}

void main(){
	lcd_init();

	pixel(127,31,1);

	writeChar(0,0,'A');

	copy_to_lcd();
}
