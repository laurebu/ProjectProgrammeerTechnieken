/*
 * @author: Laure Buysse
 * @file: timerControl.c
 *
 * description: .c file for the timer driver, contains:
 * 						prototype to initialise a PIT timer 
 * 						prototype to handle IRQ of the timer
 * 						prototype to count the amount of times the timer has gone off
 * 						prototype to reset the amount of time the timer has gone off
 */

#ifndef TIMERDRIVER_H
#define TIMERDRIVER_H

	/*
	 * Function: init_timer
	 * -----------------
	 * Summary:
	 * --------
     *      initialises the PIT timer to count a second 
	 */
    void init_timer(void);

    /*
	 * Function: PIT0_IRQHandler
	 * -----------------
	 * Summary:
	 * --------
     *      interrupt request handler for the timer
	 */
    void PIT0_IRQHandler(void);

    /*
	 * Function: get_seconds_total
	 * -----------------
	 * Summary:
	 * --------
     *      returns the amount of times the timer has gone off (= the amount of seconds)
	 */
    int get_seconds_total(void);


    /*
	 * Function: set_seconds_total
	 * -----------------
     * Parameters:
	 * -------
	 * 		int amount:
     *          integer representing an mount of seconds
	 * Summary:
	 * --------
     *      set the amount of times the timer has gone off (= the amount of seconds)
	 */
    void set_seconds_total(int amount);

    /*
	 * Function: set_timebit
	 * -----------------
     * Parameters:
	 * -------
	 * 		int value:
     *          integer representing whether the timer has gone off or not
     *              0 -> timer has not gone off yet
     *              1 -> timer has gone off
	 * Summary:
	 * --------
     *      set the timebit (which represents if the timer has gone off)
	 */
    void set_timebit(int value);

    /*
	 * Function: set_timebit
	 * -----------------
	 * Summary:
	 * --------
     *      returns the timebit (which represents if the timer has gone off)
     *              0 -> timer has not gone off yet
     *              1 -> timer has gone off
	 */
    int get_timebit(void);

#endif
