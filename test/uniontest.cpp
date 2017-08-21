#include <cstdio>
#include <cstdlib>

#define BYTE char

struct Hedgehoggo {
    int age;
    int kalashnikovo;
};

union Block {
    Hedgehoggo hoggo;
    BYTE barray[sizeof(Hedgehoggo)];
};

int main()
{
    BYTE test[20];

    Block* toInterpret = (Block*)test;

    // 0b00000000000000010000100000000100 = 67588
    test[0] = 0b00000100; // 4
    test[1] = 0b00001000; // 8
    test[2] = 0b00000001; // 0
    test[3] = 0b00000000; // 0

    //0001000000001000
    test[4] = 0b000001000; // 8
    test[5] = 0b000010000; // 16
    test[6] = 0b0; // 0
    test[7] = 0b0; // 0

    for (int i = 0; i < sizeof(Hedgehoggo); i++) {
        printf("%d\n", toInterpret->barray[i]);
    }
    printf("Age : %d / Kalashnikovo : %d", toInterpret->hoggo.age, toInterpret->hoggo.kalashnikovo);
}