/*
 * @author: Laure Buysse
 * @file: lcdControl.h
 */

#ifndef LCDCONTROL_H
#define LCDCONTROL_H

#include "MK64F12.h"

extern const unsigned char font[96][6];

void put_character(unsigned char c);
void put_string(char* str);
void put_string_pos(char* str, uint8_t x, uint8_t y);
void put_int(int integer, uint8_t x, uint8_t y);
void display_time_lefttop(int hours, int minutes, int seconds);
void display_time_center(int hours, int minutes, int seconds);
void display_time_current(int hours, int minutes, int seconds);
void display_time_alarm(int hours, int minutes, int seconds);
void display_time_time(int hours, int minutes,int seconds);
int get_string_lenght(char *s);
void center_text(char* str);
void display_music(char* str);
void display_menu(char* str, int hours, int minutes, int seconds);
void display_alarm_onOff(int onOff);
void clear(void);
void display_date_leftbottom(char* weekday, int day, char* month, int year);
void center_date(int d, int m, int y);
char* getMonthName(int m);
void display_date(int d, int m, int y);

#endif //LCDCONTROL_H

