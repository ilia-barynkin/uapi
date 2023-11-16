#ifndef UTIL_H
#define UTIL_H

// An attempt to implement platform-independent GPIO functions for 32-bit MCUs.

#include <stddef.h>
#include <stdint.h>

#ifndef SYSTEM_CORE_CLOCK
#define SYSTEM_CORE_CLOCK 40000
#endif

inline void delay(uint32_t ms) {
    for (volatile uint32_t i = 0; i < ms * SYSTEM_CORE_CLOCK / 1000; i++);
}

inline void write_bit(size_t port, size_t bit, uint8_t value) {
    (port) |= ((port) & ~(1 << (bit))) | ((value) << (bit));
}

inline void write(size_t port, uint8_t value) {
    (port) = value;
}

inline uint8_t read_bit(size_t port, size_t bit) {
    return (port) & (1 << (bit));
}

inline void toggle_bit(size_t port, size_t bit) {
    (port) ^= (1 << (bit));
}

inline void set_bit(size_t port, size_t bit) {
    (port) |= (1 << (bit));
}

inline void clear_bit(size_t port,size_t bit) {
    (port) &= ~(1 << (bit));
}

typedef void (*delay_fn)(uint32_t ms);
typedef void (*write_bit_fn)(size_t port, size_t bit, uint8_t value);
typedef void (*write_fn)(size_t port, uint8_t value);
typedef uint8_t (*read_bit_fn)(size_t port, size_t bit);
typedef void (*toggle_bit_fn)(size_t port, size_t bit);
typedef void (*set_bit_fn)(size_t port, size_t bit);
typedef void (*clear_bit_fn)(size_t port, size_t bit);

static struct mcu_api {
    delay_fn delay;
    write_bit_fn write_pin;
    write_fn write_port;
    read_bit_fn read_pin;
    toggle_bit_fn toggle_pin;
    set_bit_fn set_pin;
    clear_bit_fn clear_pin;
} mcu_api = {
    .delay = delay,
    .write_pin = write_bit,
    .write_port = write,
    .read_pin = read_bit,
    .toggle_pin = toggle_bit,
    .set_pin = set_bit,
    .clear_pin = clear_bit
};

#endif //UTIL_H