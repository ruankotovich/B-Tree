#include "hashfilefactory.hpp"
#include "primarybtree.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[])
{
  HashFileFactory hashFileFactory;
  hashFileFactory.createBinaryFilePerfectHash(fopen(argv[1], "r"), fopen("files/data.block", "wb+"));
}
