#include "hashfilefactory.hpp"
#include "btree.hpp"
#include <cstdlib>
#include <iostream>



int main(int argc, char* argv[])
{
    //BTree bTree(4096);
    int v[] = {2, 2, 3, 5, 6, 7, 0, 0};
    int count = 5;
    int i;
    int key = 1;
    
    for (i = count; i >= 1; i--) {
        if (key > v[i - 1]) {
            v[i] = key;
            break;
        }
        else {
            v[i] = v[i - 1];
        }
    }
    if (i == 0) {
        v[0] = key;
    }

}