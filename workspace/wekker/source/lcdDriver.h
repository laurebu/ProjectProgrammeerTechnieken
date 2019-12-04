/*
 * @author: Laure Buysse
 * @file: lcdDriver.h
 * 
 * description: .h file for the lcd driver
 *              contains:
 *                  prototypes for communication to the lcd (through spi)
 *                  prototypes for delay functions
 *                  prototypes to initialise the lcd and/or needed pins
 *                  prototypes to clear (parts of) the lcd
 */

#ifndef LCDDRIVER_H
#define LCDDRIVER_H

/* * * * * * * * * * *
 * files to include  *
 * * * * * * * * * * */
#include "MK64F12.h"

/* * * * * * *
 * constants *
 * * * * * * */
#define A0 3        // Port C   - bit to represent command (0) or data (1)
#define nCS 0       // Port D   - Chip select
#define SCK 1       // Port D   - Clock
#define MOSI 2      // Port D   - Master Out Slave In
#define RESET 3     // Port D   

/* * * * * * * *
 * prototypes  *
 * * * * * * * */

    /*
	 * Function: delay_ms
	 * -----------------
	 * Parameters:
	 * -------
	 * 		int ms:
	 * 			integer that represents an amount of miliseconds
	 * Summary:
	 * --------
     *      functions that implements a wait for a certain amount of miliseconds
	 */
    void delay_ms(int ms);

    /*
	 * Function: delay_us
	 * -----------------
	 * Parameters:
	 * -------
	 * 		int us:
	 * 			integer that represents an amount of microseconds
	 * Summary:
	 * --------
     *      functions that implements a wait for a certain amount of microseconds
	 */
    void delay_us(int us);

    /*
	 * Function: spi_write
	 * -----------------
	 * Parameters:
	 * -------
	 * 		uint8_t command:
	 * 			8 bit integer command for the lcd
	 * Summary:
	 * --------
     *      writes an 8 bit command to output pins using the SPI (serial peripheral interface) protocol
	 */
    void spi_write(uint8_t command);

    /*
	 * Function: lcd_data
	 * -----------------
	 * Parameters:
	 * -------
	 * 		uint8_t data:
	 * 			8 bit integer data for the lcd
	 * Summary:
	 * --------
     *      writes data to the lcd using SPI protocol
	 */
    void lcd_data(uint8_t data);

    /*
	 * Function: lcd_comm
	 * -----------------
	 * Parameters:
	 * -------
	 * 		uint8_t command:
	 * 			8 bit integer command for the lcd
	 * Summary:
	 * --------
     *      writes a command to the lcd using SPI protocol
	 */
    void lcd_comm(uint8_t command);

    /*
	 * Function: pins_init
	 * -----------------
	 * Summary:
	 * --------
     *      initialises pins needed for the lcd
     *          - Port masks
     *          - Pins as GPIO
     *          - Direction output
	 */
    void pins_init(void);

    /*
	 * Function: clear_line
	 * -----------------
	 * Parameters:
	 * -------
	 * 		int line:
	 * 			integer that represents a line (= page) of the lcd
     *              0 -> page 0 (line 1)
     *              1 -> page 1 (line 2)
     *              2 -> page 2 (line 3)
     *              3 -> page 3 (line 4)
	 * Summary:
	 * --------
     *      clears a certain page (128 x 8) of the lcd
	 */
    void clear_line(int line);

    /*
	 * Function: clear_lcd
	 * -----------------
	 * Summary:
	 * --------
     *      clear the entire lcd
	 */
    void clear_lcd(void);

    /*
	 * Function: lcd_init
	 * -----------------
	 * Summary:
	 * --------
     *      initialises lcd
     *          - initialise needed pins
     *          - reset lcd
     *          - give initialisation commands
     *          - clear entire screen
     *          - set beginning position as left top corner
	 */
    void lcd_init(void);

    /*
	 * Function: set_pos
	 * -----------------
	 * Parameters:
	 * -------
	 * 		uint8_t x:
	 * 			integer that represents the x-coördinate of the current position on the screen
     *      uint8_t y:
     *          integer that represents the y-coördinate of the current position on the screen    
	 * Summary:
	 * --------
     *      sets the position to the given x- and y-coördinate 
	 */
    void set_pos(uint8_t x, uint8_t y);

    /*
	 * Function: get_xpos
	 * -----------------
	 * Summary:
	 * --------
     *      returns the current x-position
	 */
    uint8_t get_xpos(void);

    /*
	 * Function: get_ypos
	 * -----------------
	 * Summary:
	 * --------
     *      returns the current y-position
	 */
    uint8_t get_ypos(void);

#endif //LCDDRIVER_H
