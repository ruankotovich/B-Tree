#include "hashfilefactory.hpp"

HashFileFactory::HashFileFactory(FILE* toReadText, FILE* toWriteHash) : handler(toReadText) {
    blockFile = toWriteHash;
    lastId = -1;
}

void HashFileFactory::createBinaryFilePerfectHash() {
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

int HashFileFactory::hashFunction(int k) {
    return k;
}

bool HashFileFactory::getArticleFromHash(int id, Article_t *article) {
    Block_t block;
    Header_Interpretation_t *header = (Header_Interpretation_t*)(&block.content[0]);
    
    if (!header->struct_header.valid) {
        return false;
    }

    fseek(blockFile, sizeof(Block_t) * hashFunction(id), SEEK_SET);

    fread(&block, sizeof(Block_t), 1, blockFile);

    memcpy(article, block.getArticle(0), sizeof(Article_t));

    return true;
}