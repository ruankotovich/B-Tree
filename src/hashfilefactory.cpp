#include "hashfilefactory.hpp"

/**
* Create the hashed file using the file on the first paramether to read the CSV format file and the file on the second paramether to write the binary file
* as a bonus, create the primary index as well xD
*/

void HashFileFactory::createBinaryFilePerfectHash(FILE *toRead, FILE *toWrite) {
  IOHandler handler(toRead);

  FILE* indexFileWrite = fopen("test/primaryindex.block", "wb+");
  BTree btree;
  btree.buildIndex(indexFileWrite);

  this->hashSize = handler.getBiggestId();

  Article_t currentArticle;

  while (handler.hasNext()) {
    handler >> currentArticle;
    Block_t currentBlock;
    currentBlock.tryPutArticle(currentArticle);
    currentBlock.validate();

    btree.insert(currentArticle.id, indexFileWrite);

    fseek(toWrite, currentArticle.id * sizeof(Block_t), SEEK_SET);
    fwrite(&currentBlock, sizeof(Block_t), 1, toWrite);

    handler.parseNext();
  }
}

/**
* Attemp to read an article receiving the ID, a callback variable and a file whence fields will be read
*/
