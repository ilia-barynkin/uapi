#include "uapi.h"

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