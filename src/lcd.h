#ifndef LCD_H
#define LCD_H

#include "lcd_config.h"

typedef struct lcd_interface {
    size_t rs_port;
    size_t rs_pin;
    size_t rw_port;
    size_t rw_pin;
    size_t e_port;
    size_t e_pin;
    size_t d0_port;
    size_t d0_pin;
    size_t d1_port;
    size_t d1_pin;
    size_t d2_port;
    size_t d2_pin;
    size_t d3_port;
    size_t d3_pin;
    size_t d4_port;
    size_t d4_pin;
    size_t d5_port;
    size_t d5_pin;
    size_t d6_port;
    size_t d6_pin;
    size_t d7_port;
    size_t d7_pin;
    uint32_t pulse_delay;
} lcd_interface;

extern lcd_interface lcd;

typedef enum {
    RS = 0b00000010 << 7,
    RW = 0b00000001 << 7,
    LCD_COMMAND = RS | RW,
    LCD_DATA = RS
} lcd_flags;

typedef enum {
    D7 = 0b10000000,
    D6 = 0b01000000,
    D5 = 0b00100000,
    D4 = 0b00010000,
    D3 = 0b00001000,
    D2 = 0b00000100,
    D1 = 0b00000010,
    D0 = 0b00000001
} lcd_data_lines;

void lcd_pulse();
void lcd_update(uint16_t data);
void lcd_init();
void lcd_send_char(char c);
void lcd_send_string(const char *s);
void lcd_send_command(uint8_t command);

#endif  // LCD_H