#include "uapi.h"
#include <stddef.h>
#include <stdint.h>
#include "stm32l1xx_hal.h"

#if (defined(STM32L1xx) || defined(STM32L1))
    void hal_delay(uint32_t ms) {
        HAL_Delay(ms);
    }

    void hal_write_pin(port_t reg, pin_t shift, pin_state_t value) {
        HAL_GPIO_WritePin(reg, shift, value);
        #ifdef DEBUG
        printf("hal_write_pin: 0x%X, 0x%X, 0x%X\r\n", reg, shift, value);
        #endif
    }

    uapi mcu = {
        .delay = hal_delay,
        .write_pin = hal_write_pin,
        .write = write,
        .read_pin = read_bit,
        .toggle_pin = toggle_bit,
        .set_pin = set_bit,
        .clear_pin = clear_bit
    };

#elif
    uapi mcu = {
        .delay = delay,
        .write_pin = write_bit,
        .write = write,
        .read_pin = read_bit,
        .toggle_pin = toggle_bit,
        .set_pin = set_bit,
        .clear_pin = clear_bit
    };
#endif