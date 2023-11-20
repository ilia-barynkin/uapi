#include "uapi.h"

void delay(volatile uint32_t ms) {
    ms = (ms * SYSTEM_CORE_CLOCK) / 1000;
    while (ms > 0) {
        ms--;
    }
}

void write_bit(volatile uint32_t reg, volatile uint32_t shift, rst_t value) {
    (reg) = ((reg) & ~(ST_SET << (shift))) | ((value) << (shift));
}

void write(volatile uint32_t reg, uint32_t value) {
    (reg) = (value);
}

rst_t read_bit(volatile uint32_t reg, volatile uint32_t shift) {
    return ((reg) & (ST_SET << (shift))) ? ST_SET : ST_CLR;
}

void toggle_bit(volatile uint32_t reg, volatile uint32_t shift) {
    (reg) ^= (ST_SET << (shift));
}

void set_bit(volatile uint32_t reg, volatile uint32_t shift) {
    (reg) |= (ST_SET << (shift));
}

void clear_bit(volatile uint32_t reg, volatile uint32_t shift) {
    (reg) &= ~(ST_SET << (shift));
}

uapi mcu = {
    .delay = delay,
    .write_pin = write_bit,
    .write = write,
    .read_pin = read_bit,
    .toggle_pin = toggle_bit,
    .set_pin = set_bit,
    .clear_pin = clear_bit
};