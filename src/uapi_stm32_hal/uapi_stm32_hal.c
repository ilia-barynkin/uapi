#include "../../include/uapi.h"
#include "stm32f1xx_hal.h"

uapi mcu = {
    .delay = HAL_Delay,
    .write_pin = HAL_GPIO_WritePin
    //.write = uapi_write,
    //.read_pin = uapi_read_pin,
    //.toggle_pin = uapi_toggle_pin,
    //.set_pin = uapi_set_pin,
    //.clear_pin = uapi_clear_pin
};
