/*
 * @author: Laure Buysse
 * @file: lcdDriver.c
 * 
 * description: .c file for the lcd driver
 *              contains:
 *                  functions for communication to the lcd (through spi)
 *                  delay functions
 *                  functions to initialise the lcd and/or needed pins
 *                  functions to clear (parts of) the lcd
 */

/* * * * * * * * * * *
 * files to include  *
 * * * * * * * * * * */
#include "lcdDriver.h"
#include <stdio.h>
#include "MK64F12.h"
#include <stdlib.h>

/* * * * * * *
 * variables *
 * * * * * * */
uint8_t yposition = 0;
uint8_t xposition = 0;


/* * * * * *
 * methods *
 * * * * * */
// delay in ms
void delay_ms(int ms) {
	for (long i = 0; i < (1700 * ms); i++) {}
}

// dealy in us
void delay_us(int us) {
	for (long i = 0; i < (int)(1.7 * us); i++) {}
}

void spi_write(uint8_t command){
	GPIOD->PDOR &= ~(1 << nCS); 			// chip select low

	for(int n=8; n>0; n--){
		GPIOD->PDOR &= ~(1 << SCK);			// clock low
		if(command & (1<<(n-1))){			// if current bit is '1'
			GPIOD->PDOR |= (1 << MOSI);		// set data pin high
		} else {
			GPIOD->PDOR &= ~(1 << MOSI);	// set data pin low
		}
		delay_us(1);						// wait a bit
		GPIOD->PDOR |= (1 << SCK); 			// clock high
		delay_us(1);
	}

	GPIOD->PDOR |= (1 << nCS); 				// chip select high
	delay_us(5);
}

void lcd_data(uint8_t data) //Data Output Serial Interface
{
	GPIOC->PDOR |= (1 << A0);			// use data mode
	spi_write(data);
}

void lcd_comm(uint8_t command) //Command Output Serial Interface
{
	GPIOC->PDOR &= ~(1 << A0);			// use command mode
	spi_write(command);
}

void clear_line(int line){
	lcd_comm(0x00);		// send command column nibble high
	lcd_comm(0x10);		// send command column nibble low	
	char page;
	switch(line){
		case 0:
			page=0xB0;	// page 0
			break;
		case 1:
			page=0xB1;	// page 1
			break;
		case 2:
			page=0xB2;	// page 2
			break;
		case 3:
			page=0xB3;	// page 3
			break;
		default:
			page=0xB0;	// page 0
			break;
	}
	lcd_comm(page);		// send command page	

	for(int i=0; i<128; i++){
		lcd_data(0x00);	// send data (zeros) for the entire page (0x00 for 128 columns)
	}
}

void clear_lcd(){
	clear_line(0);
	clear_line(1);
	clear_line(2);
	clear_line(3);
}

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

void lcd_init(){
	// Init pins 
	pins_init();

	// Reset lcd 
	GPIOD->PDOR &= ~(1 << RESET);		//send reset pulse
	delay_ms(50);						//wait
	GPIOD->PDOR |= (1 << RESET); 		//stop reset

	// Set start value chip select and clock 
	GPIOD->PDOR |= (1 << RESET);		//set chip select to inactive
	GPIOD->PDOR |= (1 << SCK);			//set clock to inactive

	// Init commands for lcd 
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

	// Clear screen
	clear_lcd();

	// Set beginning position
	set_pos(0,0);
}

void set_pos(uint8_t x, uint8_t y){
	//check to see position is within screen limits (128 x 32)
	if (x < 127 || y < 32 || x > 0 || y > 0) {
		//set column high, column low and page address
	    lcd_comm(x & 0x0F);      			// set column low nibble
	    lcd_comm(0x10 | (x >> 4));      	// set column high  nibble
	    lcd_comm(0xB0 | (y >> 3));      	// set page address
	    xposition = x;						// set current position (x)
	    yposition = y;						// set current position (y)
	}
}

uint8_t get_xpos(void){
	return xposition;
}

uint8_t get_ypos(void){
	return yposition;
}








