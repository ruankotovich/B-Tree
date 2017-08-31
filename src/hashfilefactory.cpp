#include "hashfilefactory.hpp"
#include <cstdio>

HashFileFactory::HashFileFactory() {
    lastId = -1;
}

void HashFileFactory::createBinaryFilePerfectHash(FILE *toRead, FILE *toWrite) {
    IOHandler handler(toRead);
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
                    fwrite(&Block_Handler_T::invalidBlock, sizeof(Block_t), 1, toWrite);
                }
            }
        }

        fwrite(&currentBlock, sizeof(Block_t), 1, toWrite);
    }
}

int HashFileFactory::hashFunction(int k) {
    return k;
}

bool HashFileFactory::getArticleFromHash(int id, Article_t *article, FILE *toRead) {
    Block_t block;

    fseek(toRead, sizeof(Block_t) * hashFunction(id), SEEK_SET);
    fread(&block, sizeof(Block_t), 1, toRead);

    Header_Interpretation_t *header = (Header_Interpretation_t*)(&block.content[0]);

    if (!header->struct_header.valid) {
        return false;
    }

    memcpy(article, block.getArticle(0), sizeof(Article_t));

    return true;
}
