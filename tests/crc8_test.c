#include "crc8.h"
#include <assert.h>
#include <stdio.h>

uint8_t test_crc8(uint8_t crc, uint8_t data) {
    uint8_t crc1;
    uint8_t crc2;

    crc1 = crc8_update(crc, data);
    crc2 = crc8_update_bit_by_bit(crc, data);

    printf("crc8_update(0x%02X, 0x%02X) = 0x%02X, 0x%02X\n", crc, data, crc1,
        crc2);

    assert(crc1 == crc2 && "Both calculations should be the same");

    return crc1;
}

int main(void) {
    int i;
    uint8_t crc = CRC8_INIT;

    printf("Testing CRC8\n");

    for (i = 0; i < 255; i++)
        crc = test_crc8(crc, i);

    return 0;
}
