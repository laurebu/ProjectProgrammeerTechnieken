/*
 * @author: Laure Buysse
 * @file: lcdDriver.h
 * 
 * description: .h file for the lcd driver
 *              contains:
 *                  prototypes for initialising the lcd (and the pins)
 * 					prototypes to introduce delay
 * 					prototypes for writing data or commands using spi
 * 					prototypes to clear the entire lcd
 * 					prototypes to keep track of the current position on the lcd screen
 *                  definitions for certain pins
 */

#ifndef LCDDRIVER_H
#define LCDDRIVER_H

/* * * * * * *
 * includes  *
 * * * * * * */
#include "MK64F12.h"

/* * * * * * * *
 * definitions *
 * * * * * * * */
#define A0 3        // Port C
#define nCS 0       // Port D
#define SCK 1       // Port D
#define MOSI 2      // Port D
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
	 * 			integer representing a certain amount of milliseconds
	 * Summary:
	 * --------
     *      introduces a certain amount of delay (in milliseconds) 
	 */
    void delay_ms(int ms);

    /*
	 * Function: delay_us
	 * -----------------
	 * Parameters:
	 * -------
	 * 		int us:
	 * 			integer representing a certain amount of microseconds
	 * Summary:
	 * --------
     *      introduces a certain amount of delay (in microseconds)
	 */
    void delay_us(int us);

    /*
	 * Function: spi_write
	 * -----------------
	 * Parameters:
	 * -------
	 * 		uint8_t command:
	 * 			unsigned integer (eight bits) representing data to be send over spi
	 * Summary:
	 * --------
     *      sends eight bits of data using spi
	 */
    void spi_write(uint8_t command);

    /*
	 * Function: lcd_data
	 * -----------------
	 * Parameters:
	 * -------
	 * 		uint8_t data:
	 * 			unsigned integer (eight bits) representing data to be send to the lcd using spi
	 * Summary:
	 * --------
     *      sends eight bits of data to the lcd using spi
	 */
    void lcd_data(uint8_t data);

    /*
	 * Function: lcd_comm
	 * -----------------
	 * Parameters:
	 * -------
	 * 		uint8_t data:
	 * 			unsigned integer (eight bits) representing a command that is to be send to the lcd using psi
	 * Summary:
	 * --------
     *      send an eight bit command to the lcd
	 */
    void lcd_comm(uint8_t command);

    /*
	 * Function: pins_init
	 * -----------------
	 * Summary:
	 * --------
     *      initialises pins needed for the lcd
	 */
    void pins_init(void);

    /*
	 * Function: clear_lcd
	 * -----------------
	 * Summary:
	 * --------
     *      clears the entire lcd
	 */
    void clear_lcd(void);

    /*
	 * Function: lcd_init
	 * -----------------
	 * Summary:
	 * --------
     *      initialises the lcd
	 */
    void lcd_init(void);

    /*
	 * Function: clear_line
	 * -----------------
	 * Parameters:
	 * -------
	 * 		int line:
	 * 			integer representing a line (/page) of the lcd
     *              1 -> line 1 -> page 0
     *              2 -> line 2 -> page 1
     *              3 -> line 3 -> page 2
     *              4 -> line 4 -> page 3
	 * Summary:
	 * --------
     *      clears a certain page of the lcd
	 */
    void clear_line(int line);

    /*
	 * Function: set_pos
	 * -----------------
	 * Parameters:
	 * -------
	 * 		uint8_t x:
	 * 			integer representing the current x-position on the screen
     *      uint8_t y:
     *          integer representing the current y-position on the screen
	 * Summary:
	 * --------
     *      set the current position
     * 
     *      * position (0,0) represent the top left corner of the lcd
	 */
    void set_pos(uint8_t x, uint8_t y);

    /*
	 * Function: get_xpos
	 * -----------------
	 * Summary:
	 * --------
     *      returns the current x-position of the screen
	 */
    uint8_t get_xpos(void);

    /*
	 * Function: get_ypos
	 * -----------------
	 * Summary:
	 * --------
     *      returns the current y-position of the screen
	 */
    uint8_t get_ypos(void);

#endif //LCDDRIVER_H
