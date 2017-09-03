#include "hashfinder.hpp"

bool getArticleFromHash(int id, Article_t *article, FILE *toRead) {
  Block_t block;

  fseek(toRead, sizeof(Block_t) * id, SEEK_SET);
  fread(&block, sizeof(Block_t), 1, toRead);

  if (!block.isValid()) {
    return false;
  }

  memcpy(article, block.getArticle(0), sizeof(Article_t));

  return true;
}
