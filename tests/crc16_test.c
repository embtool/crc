#include "crc16.h"
#include <assert.h>
#include <stdio.h>

uint16_t test_crc16(uint16_t crc, uint8_t data) {
    uint16_t crc1;
    uint16_t crc2;

    crc1 = crc16_update(crc, data);
    crc2 = crc16_update_bit_by_bit(crc, data);

    printf("crc16_update(0x%04X, 0x%02X) = 0x%04X, 0x%04X\n", crc, data, crc1,
        crc2);

    assert(crc1 == crc2 && "Both calculations should be the same");

    return crc1;
}

int main(void) {
    int i;
    uint16_t crc = CRC16_INIT;

    printf("Testing CRC16\n");

    for (i = 0; i < 255; i++)
        crc = test_crc16(crc, i);

    return 0;
}
