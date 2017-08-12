#include <cstdio>
#include <cstdlib>

int main()
{
    FILE* test = fopen("test.txt", "r");

    printf("%d", fscanf(test, "%*[^;];"));
}