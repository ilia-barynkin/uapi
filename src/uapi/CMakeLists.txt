project(uapi VERSION 0.0.1 LANGUAGES C)

include_directories(include)

#TODO make subdirectory addition more automated
add_subdirectory(uapi_common)
add_subdirectory(uapi_stm32_hal)
