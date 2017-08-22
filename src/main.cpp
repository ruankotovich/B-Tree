#include "block.hpp"
#include "iohandler.hpp"

#include <cstdlib>
#include <iostream>


int main(int argc, char* argv[])
{
    IOHandler handler(fopen("./files/pattern.csv", "r"));
    FILE* blockFile = fopen("./test/pattern.block", "wb+");
    int lastId = 0;
    Article_t currentArticle;

    while (handler.hasNext()) {
        Block_t currentBlock;

        while (currentBlock.hasSpace() && handler.hasNext()) {
            handler >> currentArticle;
            handler.parseNext();

            currentBlock.tryPutArticle(currentArticle);

            int qntInvalidToWrite = currentArticle.id - lastId - 1;
            lastId = currentArticle.id;

            if (qntInvalidToWrite > 0) {
                for (; qntInvalidToWrite; qntInvalidToWrite--) {
                    fwrite(&Block_Handler_T::invalidBlock, sizeof(Block_t), 1, blockFile);
                }
            }
        }

        fwrite(&currentBlock, sizeof(Block_t), 1, blockFile);
    }
}