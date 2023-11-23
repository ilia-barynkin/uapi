#include "uapi.h"

void delay(volatile uint32_t ms) {
    ms = (ms * SYSTEM_CORE_CLOCK) / 1000;
    while (ms > 0) {
        ms--;
    }
}

void write_bit(volatile uint32_t reg, volatile uint32_t shift, pin_state_t value) {
    (reg) = ((reg) & ~(PIN_STATE_SET << (shift))) | ((value) << (shift));

    #ifdef DEBUG
    printf("write_bit: 0x%X, 0x%X, 0x%X\r\n", reg, shift, value);
    #endif
}

void write_pin(port_t port, pin_t pin, pin_state_t value) {
    (port) = ((port) & ~(PIN_STATE_SET << (pin))) | ((value) << (pin));

    #ifdef DEBUG
    printf("write_pin: 0x%X, 0x%X, 0x%X\r\n", port, pin, value);
    #endif
}

void write(volatile uint32_t reg, volatile uint32_t value) {
    (reg) = (value);
}

pin_state_t read_bit(volatile uint32_t reg, volatile uint32_t shift) {
    return ((reg) & (PIN_STATE_SET << (shift))) ? PIN_STATE_SET : PIN_STATE_RESET;
}

void toggle_bit(volatile uint32_t reg, volatile uint32_t shift) {
    (reg) ^= (PIN_STATE_SET << (shift));
}

void set_bit(volatile uint32_t reg, volatile uint32_t shift) {
    (reg) |= (PIN_STATE_SET << (shift));
}

void clear_bit(volatile uint32_t reg, volatile uint32_t shift) {
    (reg) &= ~(PIN_STATE_SET << (shift));
}
