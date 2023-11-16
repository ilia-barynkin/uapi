#include "util.h"
#include "lcd_config.h"
#include "lcd.h"

void lcd_pulse() {
    mcu_api.set_pin(lcd_interface.e_port, lcd_interface.e_pin);
    mcu_api.delay(lcd_interface.pulse_delay);
    mcu_api.clear_pin(lcd_interface.e_port, lcd_interface.e_pin);
}

void lcd_update(uint16_t data) {
    mcu_api.write_pin(lcd_interface.rs_port, lcd_interface.rs_pin, data & RS);
    mcu_api.write_pin(lcd_interface.rw_port, lcd_interface.rw_pin, data & RW);
    mcu_api.write_pin(lcd_interface.d7_port, lcd_interface.d7_pin, data & D7);
    mcu_api.write_pin(lcd_interface.d6_port, lcd_interface.d6_pin, data & D6);
    mcu_api.write_pin(lcd_interface.d5_port, lcd_interface.d5_pin, data & D5);
    mcu_api.write_pin(lcd_interface.d4_port, lcd_interface.d4_pin, data & D4);
    mcu_api.write_pin(lcd_interface.d3_port, lcd_interface.d3_pin, data & D3);
    mcu_api.write_pin(lcd_interface.d2_port, lcd_interface.d2_pin, data & D2);
    mcu_api.write_pin(lcd_interface.d1_port, lcd_interface.d1_pin, data & D1);
    mcu_api.write_pin(lcd_interface.d0_port, lcd_interface.d0_pin, data & D0);

    lcd_pulse();
}

// TODO: re-implement this as a more idiomatic C

void lcd_init() {
    char init_bytes[]={0x30,0x30,0x30,0x38,0x10,0x2,0xc,0x1};

	for(size_t i=0; i < sizeof(init_bytes); ++i)
	{
		mcu_api.delay(200);
		lcd_update(init_bytes[i]);
	}

	mcu_api.delay(20);
}

void lcd_send_char(char c) {
    lcd_update(c | LCD_DATA);
}

void lcd_send_string(const char *s) {
    while(*s) {
        lcd_send_char(*s++);
    }
}

void lcd_send_command(uint8_t command) {
    lcd_update(command | LCD_COMMAND);
}