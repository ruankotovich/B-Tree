#include "article.hpp"
#include "byteparser.hpp"

#define BLOCK_SIZE 4096
#define RECORD_COUNT_SIZE INT_SIZE
#define RECORD_AREA_SIZE (BLOCK_SIZE-RECORD_COUNT_SIZE)

struct Block_t {
    BYTE block_header[RECORD_COUNT_SIZE];
    BYTE record_content[RECORD_AREA_SIZE];
};