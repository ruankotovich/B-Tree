#pragma once
#include "article.hpp"
#include "typessize.hpp"
#define BLOCK_SIZE 4096
#define RECORD_HEADER_SIZE (BYTE_SIZE << 1)
#define RECORD_AREA_SIZE (BLOCK_SIZE - RECORD_HEADER_SIZE)

struct Block_t {
    BYTE content[BLOCK_SIZE];
    bool tryPutArticle(Article_t&);
    bool hasSpace();
    Article_t* getArticle(unsigned int);
    Block_t();
};

union Header_Interpretation_t {

    struct Header {
        unsigned char valid;
        unsigned char count;
    } struct_header;

    BYTE bytes_header[RECORD_HEADER_SIZE];
};

union Article_Interpretation_t {
    Article_t struct_article;
    BYTE bytes_article[sizeof(Article_t)];
};

namespace Block_Handler_T {
    const Block_t invalidBlock;
};