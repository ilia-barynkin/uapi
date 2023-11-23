#ifndef LCD_H
#define LCD_H

#include "../../include/uapi.h"

typedef struct lcd_interface {
    port_t rs_port;
    pin_t rs_pin;
    port_t rw_port;
    pin_t rw_pin;
    port_t e_port;
    pin_t e_pin;
    port_t d0_port;
    pin_t d0_pin;
    port_t d1_port;
    pin_t d1_pin;
    port_t d2_port;
    pin_t d2_pin;
    port_t d3_port;
    pin_t d3_pin;
    port_t d4_port;
    pin_t d4_pin;
    port_t d5_port;
    pin_t d5_pin;
    port_t d6_port;
    pin_t d6_pin;
    port_t d7_port;
    pin_t d7_pin;

    u32_t pulse_delay;
} lcd_interface;

extern lcd_interface lcd;

typedef enum {
    LCD_RS = 1 << 9,
    LCD_RW = 1 << 8,
    LCD_D7 = 1 << 7,
    LCD_D6 = 1 << 6,
    LCD_D5 = 1 << 5,
    LCD_D4 = 1 << 4,
    LCD_D3 = 1 << 3,
    LCD_D2 = 1 << 2,
    LCD_D1 = 1 << 1,
    LCD_D0 = 1 << 0,
    LCD_ALL_DATA_LINES = LCD_D7 | LCD_D6 | LCD_D5 | LCD_D4 | LCD_D3 | LCD_D2 | LCD_D1 | LCD_D0,

    LCD_INSTRUCTION = ~LCD_RS | LCD_ALL_DATA_LINES,
    LCD_DATA = LCD_RS | LCD_ALL_DATA_LINES,

    LCD_WRITE = ~LCD_RW & (LCD_INSTRUCTION | LCD_DATA),
    LCD_READ = LCD_RW | (LCD_INSTRUCTION | LCD_DATA),

    LCD_READ_DATA = LCD_READ & LCD_DATA,
    LCD_WRITE_DATA = LCD_WRITE & LCD_DATA,

    // INSTRUCTIONS
    LCD_CLEAR = ~(LCD_INSTRUCTION ^ LCD_D0),
    LCD_RETURN_HOME = ~(LCD_INSTRUCTION ^ LCD_D1),
    LCD_ENTRY_MODE_SET = ~(LCD_INSTRUCTION ^ LCD_D2),
    LCD_DISPLAY_ON_OFF = ~(LCD_INSTRUCTION ^ LCD_D3 | LCD_D2 | LCD_D1),
    LCD_DISPLAY_ON = ~(LCD_INSTRUCTION ^ LCD_D3 | LCD_D2),
    LCD_CURSOR_ON_OFF = ~(LCD_INSTRUCTION ^ LCD_D4),
    LCD_SHIFT_CURSOR = ~(LCD_INSTRUCTION ^ LCD_D5),
    LCD_SHIFT_DISPLAY = ~(LCD_INSTRUCTION ^ LCD_D6),
    LCD_FUNCTION_SET = ~(LCD_INSTRUCTION ^ LCD_D7),
    
    // ad-hoc
    LCD_INIT = 0x30 | LCD_INSTRUCTION
} lcd_flags;

void lcd_flush();
void lcd_update();
void lcd_init();
void lcd_send_char(char c);
void lcd_write_string(const char *s);
//void lcd_send_command(uint16_t command);

#endif  // LCD_H
