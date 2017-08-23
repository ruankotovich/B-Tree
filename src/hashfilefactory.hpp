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

public:
    HashFileFactory(FILE* toReadText, FILE* toWriteHash);
    void createBinaryFileHash(); // poderia retornar boolean indicando que houve algum erro na leitura ou escrita.
};