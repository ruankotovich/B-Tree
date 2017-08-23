//#include "block.hpp"
//#include "iohandler.hpp"

#include "hashfilefactory.cpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[])
{
    FILE* blockFile = fopen("./test/pattern.block", "wb+");
    HashFileFactory HashFileFactory(fopen("./files/pattern.csv", "r"), blockFile);
    
    HashFileFactory.createBinaryFileHash();
}