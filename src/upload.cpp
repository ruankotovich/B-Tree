#include "hashfilefactory.hpp"
#include "btree.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[])
{
  HashFileFactory hashFileFactory;

  hashFileFactory.createBinaryFilePerfectHash(fopen(argv[1], "r"), fopen("./data.block", "wb+"));
}
