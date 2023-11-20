#ifndef UAPI_H
#define UAPI_H

// An attempt to implement platform-independent GPIO functions for 32-shift MCUs.

#include <stddef.h>
#include <stdint.h>

#ifndef SYSTEM_CORE_CLOCK
// TODO: add calibration
#define SYSTEM_CORE_CLOCK 8000 * 16
#endif

typedef enum
{
  ST_CLR = 0,
  ST_SET
} rst_t;

void delay(volatile uint32_t ms);
void write_bit(volatile uint32_t reg, volatile uint32_t shift, rst_t value);
void write(volatile uint32_t reg, uint32_t value);
rst_t read_bit(volatile uint32_t reg, volatile uint32_t shift);
void toggle_bit(volatile uint32_t reg, volatile uint32_t shift);
void set_bit(volatile uint32_t reg, volatile uint32_t shift);
void clear_bit(volatile uint32_t reg, volatile uint32_t shift);

typedef void (*delay_fn)(uint32_t ms);
typedef void (*write_bit_fn)(volatile uint32_t reg, volatile uint32_t shift, rst_t value);
typedef void (*write_fn)(volatile uint32_t reg, volatile uint32_t value);
typedef rst_t (*read_bit_fn)(volatile uint32_t reg, volatile uint32_t shift);
typedef void (*toggle_bit_fn)(volatile uint32_t reg, volatile uint32_t shift);
typedef void (*set_bit_fn)(volatile uint32_t reg, volatile uint32_t shift);
typedef void (*clear_bit_fn)(volatile uint32_t reg, volatile uint32_t shift);

typedef struct uapi {
    delay_fn delay;
    write_bit_fn write_pin;
    write_fn write;
    read_bit_fn read_pin;
    toggle_bit_fn toggle_pin;
    set_bit_fn set_pin;
    clear_bit_fn clear_pin;
} uapi;

extern uapi mcu;

#endif //UAPI_H