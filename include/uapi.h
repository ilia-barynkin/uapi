#ifndef UAPI_H
#define UAPI_H

#include "uapi_types.h"

typedef enum
{
  PIN_STATE_RESET = false,
  PIN_STATE_SET = true
} pin_state_t;

typedef vu32_t port_t;
typedef u16_t pin_t;

typedef void (*delay_fn)(vu32_t ms);
typedef void (*write_fn)(vu32_t reg, vu32_t value);
typedef void (*write_pin_fn)(port_t port, pin_t pin, pin_state_t state);
typedef pin_state_t (*read_bit_fn)(vu32_t reg, vu32_t shift);
typedef void (*toggle_bit_fn)(vu32_t reg, vu32_t shift);
typedef void (*set_bit_fn)(vu32_t reg, vu32_t shift);
typedef void (*clear_bit_fn)(vu32_t reg, vu32_t shift);

typedef struct uapi {
    delay_fn delay;
    write_pin_fn write_pin;
    write_fn write;
    read_bit_fn read_pin;
    toggle_bit_fn toggle_pin;
    set_bit_fn set_pin;
    clear_bit_fn clear_pin;
} uapi;

extern uapi mcu;

#endif //UAPI_H