#include "uapi.h"

uapi uapi_mcu = {
    .delay = delay,
    .write_pin = write_bit,
    .write_reg = write,
    .read_pin = read_bit,
    .toggle_pin = toggle_bit,
    .set_pin = set_bit,
    .clear_pin = clear_bit
};