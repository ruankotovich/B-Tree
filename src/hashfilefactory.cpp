#include "hashfilefactory.hpp"

/**
* Create the hashed file using the file on the first paramether to read the CSV format file and the file on the second paramether to write the binary file
* as a bonus, create the primary index as well xD
*/

void HashFileFactory::createBinaryFilePerfectHash(FILE *toRead, FILE *toWrite) {
  IOHandler handler(toRead);

  FILE* primaryIndexFileWrite = fopen("test/primaryindex.block", "wb+");
  FILE* secondaryIndexFileWrite = fopen("test/secondaryindex.block", "wb+");


  PrimaryBTree pBtree;
  SecondaryBTree sBtree;

  pBtree.buildIndex(primaryIndexFileWrite);
  sBtree.buildIndex(secondaryIndexFileWrite);

  this->hashSize = handler.getBiggestId();

  Article_t currentArticle;
  SecondaryBTreeDataMap key;

  while (handler.hasNext()) {
    handler >> currentArticle;
    Block_t currentBlock;
    currentBlock.tryPutArticle(currentArticle);
    currentBlock.validate();

    std::memcpy(key.key, currentArticle.title, SECONDARY_KEY_LENGTH);
    key.dataPointer = currentArticle.id;

    pBtree.insert(currentArticle.id, primaryIndexFileWrite);
    sBtree.insert(key, secondaryIndexFileWrite);

    fseek(toWrite, currentArticle.id * sizeof(Block_t), SEEK_SET);
    fwrite(&currentBlock, sizeof(Block_t), 1, toWrite);

    handler.parseNext();
  }
}

/**
* Attemp to read an article receiving the ID, a callback variable and a file whence fields will be read
*/
