#include "uapi.h"

void delay(volatile uint32_t ms) {
    while (ms > 0) {
        ms--;
    }
}

void write_bit(size_t reg, size_t shift, rst_t value) {
    (reg) = ((reg) & ~(ST_SET << (shift))) | ((value) << (shift));
}

void write(size_t reg, uint32_t value) {
    (reg) = (value);
}

rst_t read_bit(size_t reg, size_t shift) {
    return ((reg) & (ST_SET << (shift))) ? ST_SET : ST_REST_SET;
}

void toggle_bit(size_t reg, size_t shift) {
    (reg) ^= (ST_SET << (shift));
}

void set_bit(size_t reg, size_t shift) {
    (reg) |= (ST_SET << (shift));
}

void clear_bit(size_t reg, size_t shift) {
    (reg) &= ~(ST_SET << (shift));
}

uapi mcu = {
    .delay = delay,
    .write_pin = write_bit,
    .write_reg = write,
    .read_pin = read_bit,
    .toggle_pin = toggle_bit,
    .set_pin = set_bit,
    .clear_pin = clear_bit
};