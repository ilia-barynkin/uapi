add_library(stm32_lcd STATIC stm32lcd.c)
target_include_directories(stm32_lcd PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
