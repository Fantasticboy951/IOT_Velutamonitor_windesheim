# CMakeLists.txt in src directory

# Add the executable for the main.c file
add_executable(blink
    main.c
)

# Link de standaard bibliotheken voor de Pico
target_link_libraries(blink pico_stdlib LoRa_pico_lib)

# Schrijf extra output formats (UF2, ELF, BIN)
pico_add_extra_outputs(blink)