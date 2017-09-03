#pragma once
#include "article.hpp"
#include "block.hpp"
#include <cstdlib>

bool getArticleFromHash(int id, Article_t *article, FILE *toRead);
bool getArticleFromHash(char id, Article_t *article, FILE *toRead);
