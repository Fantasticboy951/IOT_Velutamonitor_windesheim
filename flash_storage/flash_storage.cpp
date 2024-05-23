#include "flash_storage.h"

#include "hardware/flash.h"
uint8_t stored_data[FLASH_PAGE_SIZE];
const uint8_t *flash_target_contents = (const uint8_t *) (XIP_BASE + FLASH_TARGET_OFFSET);

void Flash::write_to_address(uint32_t key, uint8_t value)
{
    if (key >= FLASH_PAGE_SIZE)
        return;

    uint32_t address = get_address();
    stored_data[key] = value;
    flash_range_program(address, stored_data, FLASH_PAGE_SIZE);
}

uint32_t Flash::read_from_address(uint32_t key)
{
    return flash_target_contents[key];
}

uint32_t Flash::read_from_buffer(uint32_t key)
{
    return stored_data[key];
}

uint32_t Flash::get_address(void)
{
    return (uint32_t)(FLASH_TARGET_OFFSET);//ADDR_PERSISTENT_BASE_ADDR;
}
