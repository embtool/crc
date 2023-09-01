#ifndef CRC8_H_
#define CRC8_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define CRC8_INIT 0xFF

/* Byte by byte algorithm that uses a 256 bytes pre-computed table. */
uint8_t crc8_update(uint8_t crc, uint8_t data);

/* Bit by bit algorithm computation. */
uint8_t crc8_update_bit_by_bit(uint8_t crc, uint8_t data);

#ifdef __cplusplus
}
#endif

#endif /* CRC8_H_ */
