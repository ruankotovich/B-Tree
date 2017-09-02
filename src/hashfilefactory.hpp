#pragma once
#include "block.hpp"
#include "iohandler.hpp"
#include <cstdlib>
#include <cstdio>
#include <iostream>

/**
* A class to recover raw information in the hashed file
*/
class HashFileFactory {
private:
  int hashSize;
public:
  void createBinaryFilePerfectHash(FILE *toRead, FILE *toWrite); // poderia retornar boolean indicando que houve algum erro na leitura ou escrita. NA1 PODERIA
  bool getArticleFromHash(int id, Article_t *article, FILE *toRead);

};
