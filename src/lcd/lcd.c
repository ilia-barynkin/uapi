#include "main.h"
#include "uapi.h"
#include "lcd.h"
#include "assert.h"

lcd_interface lcd = {
    .rs_port = RS_GPIO_Port,
    .rs_pin = RS_Pin,
    .rw_port = RW_GPIO_Port,
    .rw_pin = RW_Pin,
    .e_port = E_GPIO_Port,
    .e_pin = E_Pin,
    .d0_port = DB0_GPIO_Port,
    .d0_pin = DB0_Pin,
    .d1_port = DB1_GPIO_Port,
    .d1_pin = DB1_Pin,
    .d2_port = DB2_GPIO_Port,
    .d2_pin = DB2_Pin,
    .d3_port = DB3_GPIO_Port,
    .d3_pin = DB3_Pin,
    .d4_port = DB4_GPIO_Port,
    .d4_pin = DB4_Pin,
    .d5_port = DB5_GPIO_Port,
    .d5_pin = DB5_Pin,
    .d6_port = DB6_GPIO_Port,
    .d6_pin = DB6_Pin,
    .d7_port = DB7_GPIO_Port,
    .d7_pin = DB7_Pin,
    .pulse_delay = 5
};

uint16_t lcd_state = 0;

void lcd_flush() {
    mcu.write_pin(lcd.e_port, lcd.e_pin, 1);
    mcu.delay(lcd.pulse_delay);
    mcu.write_pin(lcd.e_port, lcd.e_pin, 0);
    mcu.delay(lcd.pulse_delay);
    lcd_state = 0;
}

void lcd_update() {
    mcu.write_pin(lcd.rs_port, lcd.rs_pin, (lcd_state & LCD_RS) >> 9);
    mcu.write_pin(lcd.rw_port, lcd.rw_pin, (lcd_state & LCD_RW) >> 8);
    mcu.write_pin(lcd.d7_port, lcd.d7_pin, (lcd_state & LCD_D7) >> 7);
    mcu.write_pin(lcd.d6_port, lcd.d6_pin, (lcd_state & LCD_D6) >> 6);
    mcu.write_pin(lcd.d5_port, lcd.d5_pin, (lcd_state & LCD_D5) >> 5);
    mcu.write_pin(lcd.d4_port, lcd.d4_pin, (lcd_state & LCD_D4) >> 4);
    mcu.write_pin(lcd.d3_port, lcd.d3_pin, (lcd_state & LCD_D3) >> 3);
    mcu.write_pin(lcd.d2_port, lcd.d2_pin, (lcd_state & LCD_D2) >> 2);
    mcu.write_pin(lcd.d1_port, lcd.d1_pin, (lcd_state & LCD_D1) >> 1);
    mcu.write_pin(lcd.d0_port, lcd.d0_pin, (lcd_state & LCD_D0) >> 0);

    lcd_flush();
}

// TODO: re-implement this as a more idiomatic C

void lcd_init() {
    #ifdef DEBUG
    assert(lcd.d5_port != 42);
    #endif

    char init_bytes[]={0x30,0x30,0x30,0x38,0x10,0x2,0xc,0x1};

	for(size_t i=0; i < sizeof(init_bytes); ++i)
	{
        //lcd_state &= ~LCD_RS;
        lcd_state = init_bytes[i];
		//lcd_send_command(init_bytes[i]);
        lcd_update();
        mcu.delay(200);
	}

	mcu.delay(20);
}

void lcd_send_char(char c) {
    lcd_state = c;
    lcd_state |= LCD_RS;
    lcd_update();
}

void lcd_write_string(const char *s) {
    while(*s) {
        lcd_send_char(*s++);
    }
}

// void lcd_send_command(uint16_t command) {
//     lcd_update(command | LCD_RS);
// }
