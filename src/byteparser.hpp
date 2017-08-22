#pragma once

#include <cstdlib>
#define BYTE unsigned char
#define BYTE_BITS 8

const size_t SHORT_SIZE = sizeof(short);
const size_t INT_SIZE = sizeof(int);
const size_t LONG_SIZE = sizeof(long);
const size_t BYTE_SIZE = sizeof(BYTE);

unsigned short int us_fromByteArray(BYTE*, unsigned int);
short int s_fromByteArray(BYTE*, unsigned int);

unsigned int ui_fromByteArray(BYTE*, unsigned int);
int i_fromByteArray(BYTE*, unsigned int);

unsigned long int ul_fromByteArray(BYTE*, unsigned int);
long int l_fromByteArray(BYTE*, unsigned int);

void byte_fromShort(short, unsigned int, BYTE*);
void byte_fromUnsignedShort(unsigned short, unsigned int, BYTE*);
void byte_fromInt(int, unsigned int, BYTE*);
void byte_fromUnsignedInt(unsigned int, unsigned int, BYTE*);
void byte_fromLong(long, unsigned int, BYTE*);
void byte_fromUnsignedLong(unsigned long, unsigned int, BYTE*);