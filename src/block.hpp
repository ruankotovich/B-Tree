#pragma once
#include "article.hpp"
#include "typessize.hpp"

#define BLOCK_SIZE 4096 //!< Preset block size
#define RECORD_HEADER_SIZE (LONG_SIZE + BYTE_SIZE) //!< Preset record header size
#define RECORD_TAIL_SIZE (LONG_SIZE) //!< Preset record header size
#define RECORD_AREA_SIZE (BLOCK_SIZE - RECORD_HEADER_SIZE - RECORD_TAIL_SIZE) //!< Preset record area size, containing the data
#define DATA_LOCATION RECORD_HEADER_SIZE //< Preset data location
#define TAIL_LOCATION RECORD_AREA_SIZE + RECORD_TAIL_SIZE //!< Preset tail location
#define VERIFICATION_MASK 1554243220411767901 //!< The mask used for validation

/**
* A struct to embbed and abstract an block, its head, data and tail
*/
struct Block_t {
    BYTE content[BLOCK_SIZE];
    bool tryPutArticle(Article_t&);
    bool hasSpace();
    bool isValid();
    void validate();
    Article_t* getArticle(unsigned int);
    Block_t();
};

/**
* A struct meaning an abstract block
*/
struct AbstractBlock_t {
    char data[BLOCK_SIZE];
};

/**
* An union to abstract the reinterpretation of the header onto the block
*/
union Header_Interpretation_t {

    /**
  * Abstract header representation
  */
    struct Header {
        unsigned long verificationMask;
        unsigned char count;
    } struct_header;

    BYTE bytes_header[RECORD_HEADER_SIZE];
};

/**
* An union to abstract the reinterpretation of the tail onto the block
*/
union Tail_Interpretation_t {
    /**
  * Abstract tail representation
  */
    struct Tail {
        unsigned long verificationMask;
    } struct_tail;
    BYTE bytes_header[RECORD_TAIL_SIZE];
};

/**
* An union to abstract the reinterpretation of the article onto the block
*/
union Article_Interpretation_t {
    Article_t struct_article;
    BYTE bytes_article[sizeof(Article_t)];
};
