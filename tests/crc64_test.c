#include "crc64.h"
#include <assert.h>
#include <stdio.h>

uint64_t test_crc64(uint64_t crc, uint8_t data) {
    uint64_t crc1;
    uint64_t crc2;

    crc1 = crc64_update(crc, data);
    crc2 = crc64_update_bit_by_bit(crc, data);

    printf("crc64_update(0x%016lX, 0x%02X) = 0x%016lX, 0x%016lX\n", crc, data,
        crc1, crc2);

    assert(crc1 == crc2 && "Both calculations should be the same");

    return crc1;
}

int main(void) {
    int i;
    uint64_t crc = CRC64_INIT;

    printf("Testing CRC64\n");

    for (i = 0; i < 255; i++)
        crc = test_crc64(crc, i);

    return 0;
}
