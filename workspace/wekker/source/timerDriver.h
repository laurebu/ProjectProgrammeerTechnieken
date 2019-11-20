/*
 * @author: Laure Buysse
 * @file: timerDriver.h
 */

#ifndef TIMERDRIVER_H
#define TIMERDRIVER_H

void init_timer(void);
void PIT0_IRQHandler(void);
int get_seconds_total(void);
void set_seconds_total(int amount);
void set_timebit(int value);
int get_timebit(void);

#endif
