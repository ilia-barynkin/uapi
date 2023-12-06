#include "../../include/uapi.h"
#include "lcd.h"
#include "assert.h"

#include "main.h"

lcd_interface_t lcd = {
    .rs_port = LCD_RS_GPIO_Port,
    .rs_pin = LCD_RS_Pin,
    .rw_port = LCD_RW_GPIO_Port,
    .rw_pin = LCD_RW_Pin,
    .e_port = LCD_E_GPIO_Port,
    .e_pin = LCD_E_Pin,
    .d0_port = LCD_D0_GPIO_Port,
    .d0_pin = LCD_D0_Pin,
    .d1_port = LCD_D1_GPIO_Port,
    .d1_pin = LCD_D1_Pin,
    .d2_port = LCD_D2_GPIO_Port,
    .d2_pin = LCD_D2_Pin,
    .d3_port = LCD_D3_GPIO_Port,
    .d3_pin = LCD_D3_Pin,
    .d4_port = LCD_D4_GPIO_Port,
    .d4_pin = LCD_D4_Pin,
    .d5_port = LCD_D5_GPIO_Port,
    .d5_pin = LCD_D5_Pin,
    .d6_port = LCD_D6_GPIO_Port,
    .d6_pin = LCD_D6_Pin,
    .d7_port = LCD_D7_GPIO_Port,
    .d7_pin = LCD_D7_Pin,
    .pulse_delay = 5
};

void lcd_flush() {
    mcu.write_pin(lcd.e_port, lcd.e_pin, 1);
    mcu.delay(lcd.pulse_delay);
    mcu.write_pin(lcd.e_port, lcd.e_pin, 0);
    mcu.delay(lcd.pulse_delay);
}

void lcd_update(u32_t flags) {
    lcd_state_t* state = (lcd_state_t*)&flags;

    #ifdef DEBUG
    assert((flags & LCD_RS) >> 9 == state->rs);
    assert((flags & LCD_RW) >> 8 == state->rw);
    assert((flags & LCD_D7) >> 7 == state->d7);
    assert((flags & LCD_D6) >> 6 == state->d6);
    assert((flags & LCD_D5) >> 5 == state->d5);
    assert((flags & LCD_D4) >> 4 == state->d4);
    assert((flags & LCD_D3) >> 3 == state->d3);
    assert((flags & LCD_D2) >> 2 == state->d2);
    assert((flags & LCD_D1) >> 1 == state->d1);
    assert((flags & LCD_D0) >> 0 == state->d0);
    #endif

    mcu.write_pin(lcd.rs_port, lcd.rs_pin, (flags & LCD_RS) >> 9);
    mcu.write_pin(lcd.rw_port, lcd.rw_pin, (flags & LCD_RW) >> 8);
    mcu.write_pin(lcd.d7_port, lcd.d7_pin, (flags & LCD_D7) >> 7);
    mcu.write_pin(lcd.d6_port, lcd.d6_pin, (flags & LCD_D6) >> 6);
    mcu.write_pin(lcd.d5_port, lcd.d5_pin, (flags & LCD_D5) >> 5);
    mcu.write_pin(lcd.d4_port, lcd.d4_pin, (flags & LCD_D4) >> 4);
    mcu.write_pin(lcd.d3_port, lcd.d3_pin, (flags & LCD_D3) >> 3);
    mcu.write_pin(lcd.d2_port, lcd.d2_pin, (flags & LCD_D2) >> 2);
    mcu.write_pin(lcd.d1_port, lcd.d1_pin, (flags & LCD_D1) >> 1);
    mcu.write_pin(lcd.d0_port, lcd.d0_pin, (flags & LCD_D0) >> 0);

    lcd_flush();
}

lcd_state_t lcd_read() {
    lcd_state_t state;
    state.d7 = mcu.read_pin(lcd.d7_port, lcd.d7_pin);
    state.d6 = mcu.read_pin(lcd.d6_port, lcd.d6_pin);
    state.d5 = mcu.read_pin(lcd.d5_port, lcd.d5_pin);
    state.d4 = mcu.read_pin(lcd.d4_port, lcd.d4_pin);
    state.d3 = mcu.read_pin(lcd.d3_port, lcd.d3_pin);
    state.d2 = mcu.read_pin(lcd.d2_port, lcd.d2_pin);
    state.d1 = mcu.read_pin(lcd.d1_port, lcd.d1_pin);
    state.d0 = mcu.read_pin(lcd.d0_port, lcd.d0_pin);
    state.rs = mcu.read_pin(lcd.rs_port, lcd.rs_pin);
    state.rw = mcu.read_pin(lcd.rw_port, lcd.rw_pin);
    return state;
}

void lcd_init() {
    mcu.delay(WAIT_TIME_AFTER_POWER_ON);
    lcd_update(LCD_INIT);
    mcu.delay(WAIT_TIME_INIT_FIRST);
    lcd_update(LCD_INIT);
    mcu.delay(WAIT_TIME_INIT_SECOND);
    lcd_update(LCD_INIT);
    mcu.delay(WAIT_TIME_INIT_FINAL);
}

void lcd_send_char(char c) {
    lcd_update(LCD_RS | c);
}

void lcd_write_string(const char *s) {
    while(*s) {
        lcd_send_char(*s++);
    }
}

lcd_state_t lcd_read_busy_flag() {
    lcd_update(LCD_READ_BUSY_FLAG);
    return lcd_read();
}
