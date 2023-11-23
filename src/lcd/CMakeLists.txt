add_library(uapi_lcd src/lcd.c)
target_include_directories(uapi_lcd PUBLIC src)
target_link_libraries(uapi_lcd PUBLIC uapi_stm32_hal)