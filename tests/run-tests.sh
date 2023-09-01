#!/bin/sh
set -xe

CC="zig cc"
CFLAGS="-std=c90 -pedantic -I../../include"

mkdir -p build
cd build

# CRC8

$CC $CFLAGS -O0 ../crc8_test.c ../../src/crc8.c -o crc8_test_O0
./crc8_test_O0 >crc8_output.txt

$CC $CFLAGS -O3 ../crc8_test.c ../../src/crc8.c -o crc8_test_O3
./crc8_test_O3 | diff crc8_output.txt -

$CC $CFLAGS -Os ../crc8_test.c ../../src/crc8.c -o crc8_test_Os
./crc8_test_Os | diff crc8_output.txt -

# CRC16

$CC $CFLAGS -O0 ../crc16_test.c ../../src/crc16.c -o crc16_test_O0
./crc16_test_O0 >crc16_output.txt

$CC $CFLAGS -O3 ../crc16_test.c ../../src/crc16.c -o crc16_test_O3
./crc16_test_O3 | diff crc16_output.txt -

$CC $CFLAGS -Os ../crc16_test.c ../../src/crc16.c -o crc16_test_Os
./crc16_test_Os | diff crc16_output.txt -

# CRC32

$CC $CFLAGS -O0 ../crc32_test.c ../../src/crc32.c -o crc32_test_O0
./crc32_test_O0 >crc32_output.txt

$CC $CFLAGS -O3 ../crc32_test.c ../../src/crc32.c -o crc32_test_O3
./crc32_test_O3 | diff crc32_output.txt -

$CC $CFLAGS -Os ../crc32_test.c ../../src/crc32.c -o crc32_test_Os
./crc32_test_Os | diff crc32_output.txt -

cd ..
