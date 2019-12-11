/*
 * @author: Laure Buysse
 * @file: timerDriver.h
 * 
 * description: .h file for the timer driver
 *              contains:
 *                  prototype to initialise the timer
 *                  prototypes for IRQ handling
 *                  protoypes to initialise values
 */

#ifndef TIMERDRIVER_H
#define TIMERDRIVER_H

/* * * * * * * *
 * prototypes  *
 * * * * * * * */

	/*
	 * Function: init_timer
	 * -----------------
	 * Summary:
	 * --------
	 * 		initialises the needed registers for the timer
	 */
    void init_timer(void);

    /*
	 * Function: PIT0->IRQHandler(void)
	 * -----------------
	 * Summary:
	 * --------
	 * 		interrupt request handler for the timer
	 */
    void PIT0_IRQHandler(void);

    /*
	 * Function: get_seconds_total
	 * -----------------
	 * Summary:
	 * --------
	 * 		returns the total amount of a seconds (integer) that have passed
	 */
    int get_seconds_total(void);

    void set_seconds_total(int amount);
    void set_timebit(int value);

    /*
	 * Function: init_timer
	 * -----------------
	 * Summary:
	 * --------
	 * 		returns the integer 'timebit'
	 */
    int get_timebit(void);

#endif
