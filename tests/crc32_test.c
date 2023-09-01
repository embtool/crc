#include "crc32.h"
#include <assert.h>
#include <stdio.h>

uint32_t test_crc32(uint32_t crc, uint8_t data) {
    uint32_t crc1;
    uint32_t crc2;

    crc1 = crc32_update(crc, data);
    crc2 = crc32_update_bit_by_bit(crc, data);

    printf("crc32_update(0x%08X, 0x%02X) = 0x%08X, 0x%08X\n", crc, data, crc1,
        crc2);

    assert(crc1 == crc2 && "Both calculations should be the same");

    return crc1;
}

int main(void) {
    int i;
    uint32_t crc = CRC32_INIT;

    printf("Testing CRC32\n");

    for (i = 0; i < 255; i++)
        crc = test_crc32(crc, i);

    return 0;
}
