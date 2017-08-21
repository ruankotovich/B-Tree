#pragma once

#include <cstdlib>
#define BYTE unsigned char
#define BYTE_BITS 8

const size_t SHORT_SIZE = sizeof(short);
const size_t INT_SIZE = sizeof(int);
const size_t LONG_SIZE = sizeof(long);
const size_t BYTE_SIZE = sizeof(BYTE);

unsigned short int us_fromByteArray(BYTE*, int);
short int s_fromByteArray(BYTE*, int);

unsigned int ui_fromByteArray(BYTE*, int);
int i_fromByteArray(BYTE*, int);

unsigned long int ul_fromByteArray(BYTE*, int);
long int l_fromByteArray(BYTE*, int);

void byte_fromShort(short, int, BYTE*);
void byte_fromUnsignedShort(unsigned short, int, BYTE*);
void byte_fromInt(int, int, BYTE*);
void byte_fromUnsignedInt(unsigned int, int, BYTE*);
void byte_fromLong(long, int, BYTE*);
void byte_fromUnsignedLong(unsigned long, int, BYTE*);