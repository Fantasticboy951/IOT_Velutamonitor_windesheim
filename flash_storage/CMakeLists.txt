cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)

add_library(flash_storage flash_storage.cpp flash_storage.h)

target_link_libraries(flash_storage pico_stdlib hardware_flash)