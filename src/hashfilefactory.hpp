#pragma once
#include "block.hpp"
#include "iohandler.hpp"
#include <cstdlib>
#include <iostream>

class HashFileFactory {
private:
    IOHandler *handler;
    
    int lastId = 0;
    Article_t currentArticle;

public:
    HashFileFactory();
    void createBinaryFilePerfectHash(FILE *toRead, FILE *toWrite); // poderia retornar boolean indicando que houve algum erro na leitura ou escrita. NA1 PODERIA
    bool getArticleFromHash(int id, Article_t *article, FILE *toRead);
    
};