#ifndef CRC32_H_
#define CRC32_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define CRC32_INIT 0xFFFFFFFF

/* Byte by byte algorithm that uses a 1024 bytes pre-computed table. */
uint32_t crc32_update(uint32_t crc, uint8_t data);

/* Bit by bit algorithm computation. */
uint32_t crc32_update_bit_by_bit(uint32_t crc, uint8_t data);

#ifdef __cplusplus
}
#endif

#endif /* CRC32_H_ */
