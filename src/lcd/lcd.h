#ifndef LCD_H
#define LCD_H

#include "../../include/uapi.h"

#define WAIT_TIME_AFTER_POWER_ON 20
#define WAIT_TIME_INIT_FIRST 5
#define WAIT_TIME_INIT_SECOND 120
#define WAIT_TIME_INIT_FINAL 20

typedef struct lcd_interface_t {
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
} lcd_interface_t;

extern lcd_interface_t lcd;

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

    LCD_INSTRUCTION = ~LCD_RS,
    LCD_DATA = LCD_RS,

    LCD_WRITE = ~LCD_RW,
    LCD_READ = LCD_RW,

    // INSTRUCTIONS
    LCD_CLEAR = LCD_INSTRUCTION | LCD_WRITE | 0x01,
    LCD_HOME = LCD_INSTRUCTION | LCD_WRITE | 0x02,
    LCD_ENTRY_MODE_SET = LCD_INSTRUCTION | LCD_WRITE | 0x04,
    LCD_DISPLAY_CONTROL = LCD_INSTRUCTION | LCD_WRITE | 0x08,
    LCD_CURSOR_SHIFT = LCD_INSTRUCTION | LCD_WRITE | 0x10,
    LCD_FUNCTION_SET = LCD_INSTRUCTION | LCD_WRITE | 0x20,
    LCD_SET_CGRAM_ADDR = LCD_INSTRUCTION | LCD_WRITE | 0x40,
    LCD_SET_DDRAM_ADDR = LCD_INSTRUCTION | LCD_WRITE | 0x80,
    LCD_READ_BUSY_FLAG = LCD_INSTRUCTION | LCD_READ | 0x80,

    LCD_CURSOR_OFF = LCD_DISPLAY_CONTROL | 0x00,
    LCD_CURSOR_ON = LCD_DISPLAY_CONTROL | 0x01,
    LCD_DISPLAY_OFF = LCD_DISPLAY_CONTROL | 0x02,
    LCD_DISPLAY_ON = LCD_DISPLAY_CONTROL | 0x03,

    LCD_CURSOR_LEFT = LCD_CURSOR_SHIFT | 0x00,
    LCD_CURSOR_RIGHT = LCD_CURSOR_SHIFT | 0x01,

    LCD_INIT = 0x30

} lcd_flags_t;

typedef struct lcd_state_t {
    u32_t d0 : 1;
    u32_t d1 : 1;
    u32_t d2 : 1;
    u32_t d3 : 1;
    u32_t d4 : 1;
    u32_t d5 : 1;
    u32_t d6 : 1;
    u32_t d7 : 1;
    u32_t rw : 1;
    u32_t rs : 1;
} lcd_state_t;

void lcd_flush();
void lcd_update();
void lcd_init();
void lcd_send_char(char c);
void lcd_write_string(const char *s);
lcd_state_t lcd_read_busy_flag();

#endif  // LCD_H
