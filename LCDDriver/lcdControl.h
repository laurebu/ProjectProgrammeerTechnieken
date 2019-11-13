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
void display_time_letfftop(int hours, int minutes, int seconds);
void display_time_center(int hours, int minutes, int seconds);
void display_time_current(int hours, int minutes, int seconds);
void display_time_alarm(int hours, int minutes, int seconds);
void center_text(char* str, int lengthstr);
void display_music(char* str, int lengthstr);
void display_menu(char* str, int length, int hours, int minutes, int seconds);

#endif //LCDCONTROL_H

