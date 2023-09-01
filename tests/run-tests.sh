#!/bin/sh
set -xe

CC="zig cc"
CFLAGS="-std=c90 -pedantic -I../../include"

mkdir -p build
cd build

# CRC16

$CC $CFLAGS -O0 ../crc16_test.c ../../src/crc16.c -o crc16_test_O0
./crc16_test_O0 >crc16_output.txt

$CC $CFLAGS -O3 ../crc16_test.c ../../src/crc16.c -o crc16_test_O3
./crc16_test_O3 | diff crc16_output.txt -

$CC $CFLAGS -Os ../crc16_test.c ../../src/crc16.c -o crc16_test_Os
./crc16_test_Os | diff crc16_output.txt -

cd ..
