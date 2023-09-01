#ifndef CRC16_H_
#define CRC16_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define CRC16_INIT 0xFFFF

/* Byte by byte algorithm that uses a 512 bytes pre-computed table. */
uint16_t crc16_update(uint16_t crc, uint8_t data);

/* Bit by bit algorithm computation. */
uint16_t crc16_update_bit_by_bit(uint16_t crc, uint8_t data);

#ifdef __cplusplus
}
#endif

#endif /* CRC16_H_ */
