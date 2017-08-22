#include "block.hpp"
#include "iohandler.hpp"

#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[])
{
    IOHandler handler(fopen("./files/pattern.csv", "r"));
    FILE* blockFile = fopen("./test/pattern.block", "ab+");

    Article_t currentArticle;

    while (handler.hasNext()) {
        Block_t currentBlock;

        do {
            handler.parseNext();
            handler >> currentArticle;
        } while (currentBlock.tryPutArticle(currentArticle) && handler.hasNext());

        fwrite(&currentBlock, sizeof(Block_t), 1, blockFile);
    }
}