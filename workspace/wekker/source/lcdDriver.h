/*
 * @author: Laure Buysse
 * @file: lcdDriver.h
 */
#ifndef LCDDRIVER_H
#define LCDDRIVER_H

#include "MK64F12.h"


//port C
#define A0 3
//port D
#define nCS 0
#define SCK 1
#define MOSI 2
#define RESET 3

/*
 * prototypes
 */
void delay_ms(int ms);
void delay_us(int us);
void spi_write(uint8_t command);
void lcd_data(uint8_t data);
void lcd_comm(uint8_t command);
void pins_init(void);
void clear_lcd(void);
void lcd_init(void);
void clear_line(int line);
void set_pos(uint8_t x, uint8_t y);
uint8_t get_xpos(void);
uint8_t get_ypos(void);

#endif //LCDDRIVER_H
