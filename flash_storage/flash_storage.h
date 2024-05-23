#ifndef FLASH_STORAGE_H
#define FLASH_STORAGE_H

#include "pico/stdlib.h"
#include "pico/binary_info.h"

#define STORED_DATA_SPACE (ADDR_PERSISTENT_BASE_ADDR)
#define FLASH_TARGET_OFFSET (256 * 1024)

class Flash
{
public:
    void write_to_address(uint32_t key, uint8_t value);
    uint32_t read_from_address(uint32_t key);
    uint32_t read_from_buffer(uint32_t key);
    uint32_t get_address(void);
};

extern uint32_t ADDR_PERSISTENT[];
#define ADDR_PERSISTENT_BASE_ADDR (ADDR_PERSISTENT)

#endif