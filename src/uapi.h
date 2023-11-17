#ifndef UAPI_H
#define UAPI_H

// An attempt to implement platform-independent GPIO functions for 32-shift MCUs.

#include <stddef.h>
#include <stdint.h>

#ifndef SYSTEM_CORE_CLOCK
#define SYSTEM_CORE_CLOCK 40000
#endif

typedef enum
{
  ST_REST_SET = 0,
  ST_SET
} rst_t;

inline void delay(volatile uint32_t ms) {
    while (ms > 0) {
        ms--;
    }
}

inline void write_bit(size_t reg, size_t shift, rst_t value) {
    (reg) = ((reg) & ~(ST_SET << (shift))) | ((value) << (shift));
}

inline void write(size_t reg, uint32_t value) {
    (reg) = (value);
}

inline rst_t read_bit(size_t reg, size_t shift) {
    return ((reg) & (ST_SET << (shift))) ? ST_SET : ST_REST_SET;
}

inline void toggle_bit(size_t reg, size_t shift) {
    (reg) ^= (ST_SET << (shift));
}

inline void set_bit(size_t reg, size_t shift) {
    (reg) |= (ST_SET << (shift));
}

inline void clear_bit(size_t reg, size_t shift) {
    (reg) &= ~(ST_SET << (shift));
}

typedef void (*delay_fn)(uint32_t ms);
typedef void (*write_bit_fn)(size_t reg, size_t shift, uint8_t value);
typedef void (*write_fn)(size_t reg, uint8_t value);
typedef uint8_t (*read_bit_fn)(size_t reg, size_t shift);
typedef void (*toggle_bit_fn)(size_t reg, size_t shift);
typedef void (*set_bit_fn)(size_t reg, size_t shift);
typedef void (*clear_bit_fn)(size_t reg, size_t shift);

typedef struct uapi {
    delay_fn delay;
    write_bit_fn write_pin;
    write_fn write_reg;
    read_bit_fn read_pin;
    toggle_bit_fn toggle_pin;
    set_bit_fn set_pin;
    clear_bit_fn clear_pin;
} uapi;

extern uapi uapi_mcu;

#endif //UAPI_H