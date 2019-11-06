/*
 * @author: Laure Buysse
 * @file: lcdDriver.h
 */
#ifndef LCDDRIVER_H
#define LCDDRIVER_H

//constants
#define BUFFER_SIZE 512
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
void spi_write(unsigned char command);
void lcd_data(unsigned char data);
void lcd_comm(unsigned char command);
void pins_init(void);
void copy_to_lcd(void);
void lcd_clear(void);
void lcd_init(void);
void line(int x0, int y0, int x1, int y1, int mode);
void pixel(int x, int y, int mode);

#endif //LCDDRIVER_H
