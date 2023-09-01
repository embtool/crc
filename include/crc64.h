#ifndef CRC64_H_
#define CRC64_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define CRC64_INIT 0xFFFFFFFFFFFFFFFF

/* Byte by byte algorithm that uses a 2048 bytes pre-computed table. */
uint64_t crc64_update(uint64_t crc, uint8_t data);

/* Bit by bit algorithm computation. */
uint64_t crc64_update_bit_by_bit(uint64_t crc, uint8_t data);

#ifdef __cplusplus
}
#endif

#endif /* CRC64_H_ */
