#include "hashfilefactory.hpp"
/**
* Create the hashed file using the file on the first paramether to read the CSV format file and the file on the second paramether to write the binary file
*/
void HashFileFactory::createBinaryFilePerfectHash(FILE *toRead, FILE *toWrite) {
  IOHandler handler(toRead);
  this->hashSize = handler.getBiggestId();

  Article_t currentArticle;

  while (handler.hasNext()) {
    handler >> currentArticle;
    Block_t currentBlock;
    currentBlock.tryPutArticle(currentArticle);
    currentBlock.validate();

    fseek(toWrite, currentArticle.id * sizeof(Block_t), SEEK_SET);
    fwrite(&currentBlock, sizeof(Block_t), 1, toWrite);

    handler.parseNext();
  }
}

/**
* Attemp to read an article receiving the ID, a callback variable and a file whence fields will be read
*/

bool HashFileFactory::getArticleFromHash(int id, Article_t *article, FILE *toRead) {
  Block_t block;

  fseek(toRead, sizeof(Block_t) * id, SEEK_SET);
  fread(&block, sizeof(Block_t), 1, toRead);

  if (!block.isValid()) {
    return false;
  }

  memcpy(article, block.getArticle(0), sizeof(Article_t));

  return true;
}
