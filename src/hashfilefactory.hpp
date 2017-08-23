#pragma once
#include "block.hpp"
#include "iohandler.hpp"
#include <cstdlib>
#include <iostream>

class HashFileFactory {
private:
    IOHandler handler;
    FILE* blockFile;
    int lastId = 0;
    Article_t currentArticle;
    int hashFunction(int k);

public:
    HashFileFactory(FILE* toReadText, FILE* toWriteHash);
    void createBinaryFilePerfectHash(); // poderia retornar boolean indicando que houve algum erro na leitura ou escrita. NA1 PODERIA
    bool getArticleFromHash(int id, Article_t *article);
    
};