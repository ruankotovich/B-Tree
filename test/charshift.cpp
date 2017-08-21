#include <cstdio>

#define BYTE unsigned char
#define BYTE_BITS 8

const size_t SHORT_SIZE = sizeof(short);
const size_t INT_SIZE = sizeof(int);
const size_t LONG_SIZE = sizeof(long);
const size_t BYTE_SIZE = sizeof(BYTE);

unsigned short int us_fromByteArray(BYTE* bytearray, int offset)
{
    unsigned short number = 0;

    for (int i = 0, j = offset; i < SHORT_SIZE; ++i, ++j) {
        number |= bytearray[j] << (i * BYTE_BITS * BYTE_SIZE);
    }

    return number;
}

void byte_fromUnsignedShort(unsigned short number, int offset, BYTE* bytearray)
{
    for (int i = 0, j = offset; i < SHORT_SIZE; i++, ++j) {
        bytearray[j] = number & (0b11111111) << (i * BYTE_BITS * BYTE_SIZE);
    }
}

int main()
{
    BYTE bytearr[10];
    byte_fromUnsignedShort(105, 0, bytearr);
    unsigned short a = us_fromByteArray(bytearr, 0);
    printf("%d", a);

    // byte_fromShort(10, 0, bytearr);
    // unsigned char a[] = { 0b11111111, 0b0 };
    // short numba = 0;

    // for (int i = 0; i < sizeof(short); ++i) {
    //     numba |= a[i] << BYTE_BITS*i*sizeof(char);
    // }
}