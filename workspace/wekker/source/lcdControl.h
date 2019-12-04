/*
 * @author: Laure Buysse
 * @file: lcdControl.h
 * 
 * description: .h file for the lcd control
 *              contains:
 *                  constant definition for the array containing the font of the letters for the lcd
 *                  prototypes to put characters, strings, int on the lcd
 *                  prototypes to display certain menus/layouts on the lcd 
 *                  prototype to get the name of a month based on the number of a month
 *                  prototype to get the length of a string
 */

#ifndef LCDCONTROL_H
#define LCDCONTROL_H

/* * * * * * * * * * *
 * files to include  *
 * * * * * * * * * * */
#include "MK64F12.h"

/* * * * * * *
 * constants *
 * * * * * * */
extern const unsigned char font[96][6];     //constant array of characters used to define the font used for the letters 

/* * * * * * * *
 * prototypes  *
 * * * * * * * */

	/*
	 * Function: put_character
	 * -----------------
	 * Parameters:
	 * -------
	 * 		unsigned char c:
	 * 			character to be displayed on the screen
	 * Summary:
	 * --------
	 * 		puts character on the lcd 
     *      position is based on the previous position the screen was written 
     *      if this is the first write then the posistion wil start in the left top corner 
	 */
    void put_character(unsigned char c);

    /*
	 * Function: put_string
	 * -----------------
	 * Parameters:
	 * -------
	 * 		char* str:
	 * 			character array (~ string) that is to be displayed on the screen
	 * Summary:
	 * --------
	 * 		puts a character array (~ string) on the lcd
     *      position is based on the previous position the screen was written on
     *      if this is the first write then the position will start in the left top corner
	 */
    void put_string(char* str);

    /*
	 * Function: put_string_pos
	 * -----------------
	 * Parameters:
	 * -------
	 * 		char* str:
	 * 			character array (~ string) that is to be displayed on the screen
     *      uint8_t x:
     *          x-position on the screen (lefttop)
     *      uint8_t y:
     *          y-position on the screen (lefttop)
	 * Summary:
	 * --------
	 * 		puts a character array (~ string) on the lcd
     *      the start position of the first character (lefttop) has to be given through 
     *      an x- and y-coördinate 
	 */
    void put_string_pos(char* str, uint8_t x, uint8_t y);

    /*
	 * Function: put_int
	 * -----------------
	 * Parameters:
	 * -------
	 * 		int integer:
	 * 			integer that is to be displayed on the screen
     *      uint8_t x:
     *          x-position on the screen (lefttop)
     *      uint8_t y:
     *          y-position on the screen (lefttop)
	 * Summary:
	 * --------
	 * 		puts an integer(~ string) on the lcd
     *      the start position of the integer (lefftop) has to be given to through 
     *      an x- and y-coördinate
	 */
    void put_int(int integer, uint8_t x, uint8_t y);

    /*
	 * Function: getMonthName
	 * -----------------
	 * Parameters:
	 * -------
	 * 		int m:
	 * 			integer (1 through 12) that represents a month
	 * Summary:
	 * --------
	 * 		returns the shortened (3) name of the month (char*) based on the integer for that month:
     *          f.ex.: 2 -> 'Feb' (short for february)
     *                6 -> 'Jun' (short for june)
	 */
    char* getMonthName(int m);

    /*
	 * Function: get_string_length
	 * -----------------
	 * Parameters:
	 * -------
	 * 		char *s:
	 * 			character array (~ string) of which we want the length
	 * Summary:
	 * --------
	 * 		returns the lenght of a given character array (~ string)
	 */
    int get_string_lenght(char *s);

    /*
	 * Function: center_text
	 * -----------------
	 * Parameters:
	 * -------
	 * 		char* str:
     *          character array (~ string) that needs to be displayed in the center of the lcd
	 * Summary:
	 * --------
	 * 		display a given character array (~ string) in the center of the lcd *
     *      * center of the lcd:
     *              horizontal: centered
     *              vertical:   line three  <= entire line cleared first   
     */
    void center_text(char* str);

    /*
	 * Function: center_date
	 * -----------------
	 * Parameters:
	 * -------
	 * 		int d:
	 * 		    integer representing the day of the year
     *      int m:
     *          integer representing the month of the year
     *      int y:
     *          integer representing the year
	 * Summary:
	 * --------
	 * 		displays the date in the center of the lcd *
     *      a zero is added when the integer 'd' is smaller than 10
     *          f.ex.: d = 3 , m = 4 , y = 2019
     *              => 03 Apr 2019 
     * 
     *      * center of the lcd:
     *              horizontal: centered
     *              vertical:   line three <= entire line cleared first
	 */
    void center_date(int d, int m, int y);

    /*
	 * Function: clear
	 * -----------------
	 * Summary:
	 * --------
     *      clear the entire lcd
	 */
    void clear(void);

    /*
	 * Function: display_time_lefttop
	 * -----------------
	 * Parameters:
	 * -------
	 * 		int hours:
	 * 		    integer representing the hours of a certain time
     *      int minutes:
     *          integer representing the minutes of a certain time
     *      int seconds:
     *          integer representing the seconds of a certain time
	 * Summary:
	 * --------
	 * 		displays the time in the left top corner of the lcd (<= entire line cleared first)
     *      a zero is added when the integer is smaller than 10
     *          f.ex.: hours = 3, minutes = 20, seconds = 25
     *              => 03:20:25
	 */
    void display_time_lefttop(int hours, int minutes, int seconds);

    /*
	 * Function: display_time_lefttop
	 * -----------------
	 * Parameters:
	 * -------
	 * 		int hours:
	 * 		    integer representing the hours of a certain time
     *      int minutes:
     *          integer representing the minutes of a certain time
     *      int seconds:
     *          integer representing the seconds of a certain time
	 * Summary:
	 * --------
	 * 		displays the time in center of the lcd *
     *      a zero is added when the integer is smaller than 10
     *          f.ex.: hours = 3, minutes = 20, seconds = 25
     *              => 03:20:25
     * 
     *      * center of the lcd:
     *              horizontal: centered
     *              vertical:   line three <= entire line cleared first
	 */
    void display_time_center(int hours, int minutes, int seconds);

    /*
	 * Function: display_time_current
	 * -----------------
	 * Parameters:
	 * -------
	 * 		int hours:
	 * 		    integer representing the hours of a certain time
     *      int minutes:
     *          integer representing the minutes of a certain time
     *      int seconds:
     *          integer representing the seconds of a certain time
	 * Summary:
	 * --------
	 * 		'current-state-layout' * is written to the display (after the screen is first cleared)
     * 
     *      * ----------------------------
     *       |Current time                |
     *       |                            |
     *       |         hh:mm:ss           |
     *       |                            |
     *        ----------------------------     
	 */
    void display_time_current(int hours, int minutes, int seconds);

    /*
	 * Function: display_time_alarm
	 * -----------------
	 * Parameters:
	 * -------
	 * 		int hours:
	 * 		    integer representing the hours of a certain time
     *      int minutes:
     *          integer representing the minutes of a certain time
     *      int seconds:
     *          integer representing the seconds of a certain time
	 * Summary:
	 * --------
	 * 		'alarm-state-layout' * is written to the display (after the screen is first cleared)
     * 
     *      * ----------------------------
     *       |Alarm time set for:         |
     *       |                            |
     *       |         hh:mm:ss           |
     *       |                            |
     *        ----------------------------     
	 */
    void display_time_alarm(int hours, int minutes, int seconds);

    /*
	 * Function: display_time_time
	 * -----------------
	 * Parameters:
	 * -------
	 * 		int hours:
	 * 		    integer representing the hours of a certain time
     *      int minutes:
     *          integer representing the minutes of a certain time
     *      int seconds:
     *          integer representing the seconds of a certain time
	 * Summary:
	 * --------
	 * 		'time-state-layout' * is written to the display (after the screen is first cleared)
     * 
     *      * ----------------------------
     *       |New time set for:           |
     *       |                            |
     *       |         hh:mm:ss           |
     *       |                            |
     *        ----------------------------     
	 */    
    void display_time_time(int hours, int minutes,int seconds);

    /*
	 * Function: display_music
	 * -----------------
	 * Parameters:
	 * -------
	 * 		char* str:
     *          character array (~ string) that represents the music tone
	 * Summary:
	 * --------
	 * 		'music-state-layout' * is written to the display (after the screen is first cleared)
     * 
     *      * ----------------------------
     *       |Current alarm tone          |
     *       |                            |
     *       |            str             |
     *       |                            |
     *        ----------------------------     
	 */
    void display_music(char* str);

    /*
	 * Function: display_menu
	 * -----------------
	 * Parameters:
	 * -------
     *      char* str:
     *          character array (~ string) that represents the current menu item
     *          f.ex.:
     *              "set time"
     *              "set alarm"
	 * 		int hours:
	 * 		    integer representing the hours of a certain time
     *      int minutes:
     *          integer representing the minutes of a certain time
     *      int seconds:
     *          integer representing the seconds of a certain time
	 * Summary:
	 * --------
	 * 		'menu-state-layout' * is written to the display (after the screen is first cleared)
     *      for the time displayed in the left top coner of the lcd applies that:
     *          a zero is added when the integer is smaller than 10
     *              f.ex.: hours = 3, minutes = 20, seconds = 25
     *                  => 03:20:25
     *      * ----------------------------
     *       |hh:mm:ss                    |
     *       |                            |
     *       |            str             |
     *       |                            |
     *        ----------------------------     
	 */
    void display_menu(char* str, int hours, int minutes, int seconds);

    /*
	 * Function: display_alarm_onOff
	 * -----------------
	 * Parameters:
	 * -------
	 * 		int onOff:
     *          integer that represent the alarm being off (0) or on (1)
	 * Summary:
	 * --------
     *      write "On" or "Off" to the top right corner of the lcd depending on the 
     *      onOff parameter
	 */
    void display_alarm_onOff(int onOff);

    /*
	 * Function: display_date_leftbottom
	 * -----------------
	 * Parameters:
	 * -------
	 * 		char* weekday:
     *          character array (~ string) that represents the day of a week
     *      int day:
     *          integer that represents the day of a month
     *      char* month:
     *          character array (~ string) that represents a month
     *      int year:
     *          integer that represents the year
	 * Summary:
	 * --------
	 * 		displays the given date at the left bottom corner of the lcd (line cleared first)
     *          f.ex.:  weekday = "Mon", day = 1, month= "Jan", year="2019"
     *              => "Mon 1 Jan 2019 "
	 */
    void display_date_leftbottom(char* weekday, int day, char* month, int year);
    
    /*
	 * Function: display date
	 * -----------------
	 * Parameters:
	 * -------
     *      int d:
     *          integer that represents a day of a month
     *      int m:
     *          integer that represents a month
     *      int y:
     *          integer that represents the year
	 * Summary:
	 * --------
     *      'date-state-layout' * is written to the display (after the screen is first cleared)
     *          - date is centered on line three
     *          - int m is converted to a char*:
     *              f.ex.: m = 2 => mm == "Feb" (short for february)
     *      * ----------------------------
     *       |New date set for:           |
     *       |                            |
     *       |        dd mm yyyy          |
     *       |                            |
     *        ----------------------------  
	 */
    void display_date(int d, int m, int y);

#endif //LCDCONTROL_H

