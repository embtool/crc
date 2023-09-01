# CRC in C

I often need a CRC implementation in C and it is seldom readily available.

CRCs are simple checksums but there are a few pitfalls.

There are many CRC polynomials, compact forms with an implicit high bit
or low bit.

## Using CRC in C

Below there is ann example of how to use the CRC16 implementation.

There are several CRC sizes beyond 16.
For now the CRC sizes provided are: 8, 16, 32 or 64.

How to use:

- CRC16_INIT definition to initialize the CRC value.
- crc16_update() function to update the CRC value with one byte of data.

```c
/* File: main.c */
#include "crc16.h"
#include <stdint.h>
#include <stdio.h>

int main(void) {
    uint8_t data[6] = {'t', 'e', 's', 't', 0, 0};

    // Initialize the CRC
    uint16_t crc = CRC16_INIT;

    // Update the CRC for each byte
    for (int i = 0; i < 4; ++i)
        crc = crc16_update(crc, data[i]);

    printf("Message: \"%s\"\n", data);
    printf("CRC:     0x%04X\n", crc);

    // Send the data
    // data[4] = crc;
    // data[5] = crc >> 8;
    // serial_send(data, 6);
}
```

How to compile:

- Provide the CRC source and header path to the compiler.

```console
$ gcc -o main main.c ../../src/crc16.c -I../../include
```

Output of the example:

```console
$ ./main
Message: "test"
CRC:     0xDC2E
```

## References

- Wikipedia https://en.wikipedia.org/wiki/Cyclic_redundancy_check
- Best CRC Polynomials https://users.ece.cmu.edu/~koopman/crc/
