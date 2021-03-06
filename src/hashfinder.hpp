#pragma once
#include "article.hpp"
#include "block.hpp"
#include <cstdlib>

/**
* Retrieves and return the article from the hash file
*/
bool getArticleFromHash(int id, Article_t *article, FILE *toRead);