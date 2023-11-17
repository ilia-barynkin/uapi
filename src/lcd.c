#include "uapi.h"
#include "lcd.h"

lcd_interface lcd = {
    .rs_port = RS_GPIO_Port,
    .rs_pin = RS_Pin,
    .rw_port = RW_GPIO_Port,
    .rw_pin = RW_Pin,
    .e_port = E_GPIO_Port,
    .e_pin = E_Pin,
    .d0_port = D0_GPIO_Port,
    .d0_pin = D0_Pin,
    .d1_port = D1_GPIO_Port,
    .d1_pin = D1_Pin,
    .d2_port = D2_GPIO_Port,
    .d2_pin = D2_Pin,
    .d3_port = D3_GPIO_Port,
    .d3_pin = D3_Pin,
    .d4_port = D4_GPIO_Port,
    .d4_pin = D4_Pin,
    .d5_port = D5_GPIO_Port,
    .d5_pin = D5_Pin,
    .d6_port = D6_GPIO_Port,
    .d6_pin = D6_Pin,
    .d7_port = D7_GPIO_Port,
    .d7_pin = D7_Pin,
    .pulse_delay = 1
};

void lcd_pulse() {
    mcu.set_pin(lcd.e_port, lcd.e_pin);
    mcu.delay(lcd.pulse_delay);
    mcu.clear_pin(lcd.e_port, lcd.e_pin);
}

void lcd_update(uint16_t data) {
    mcu.write_pin(lcd.rs_port, lcd.rs_pin, data & RS);
    mcu.write_pin(lcd.rw_port, lcd.rw_pin, data & RW);
    mcu.write_pin(lcd.d7_port, lcd.d7_pin, data & D7);
    mcu.write_pin(lcd.d6_port, lcd.d6_pin, data & D6);
    mcu.write_pin(lcd.d5_port, lcd.d5_pin, data & D5);
    mcu.write_pin(lcd.d4_port, lcd.d4_pin, data & D4);
    mcu.write_pin(lcd.d3_port, lcd.d3_pin, data & D3);
    mcu.write_pin(lcd.d2_port, lcd.d2_pin, data & D2);
    mcu.write_pin(lcd.d1_port, lcd.d1_pin, data & D1);
    mcu.write_pin(lcd.d0_port, lcd.d0_pin, data & D0);

    lcd_pulse();
}

// TODO: re-implement this as a more idiomatic C

void lcd_init() {
    char init_bytes[]={0x30,0x30,0x30,0x38,0x10,0x2,0xc,0x1};

	for(size_t i=0; i < sizeof(init_bytes); ++i)
	{
		mcu.delay(200);
		lcd_update(init_bytes[i]);
	}

	mcu.delay(20);
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
