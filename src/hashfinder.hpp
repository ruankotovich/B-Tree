#pragma once
#include "article.hpp"
#include "block.hpp"
#include <cstdlib>

bool getArticleFromHash(int id, Article_t *article, FILE *toRead);
