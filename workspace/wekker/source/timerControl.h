/*
 * @author: Laure Buysse
 * @file: timerControl.h
 */

#ifndef TIMERCONTROL_H
#define TIMERCONTROL_H

void update_time(void);
int get_hours(void);
int get_minutes(void);
int get_seconds(void);
void set_time(int h, int m, int s);
int getTimeBit(void);
void setTimeBit(int t);

#endif
