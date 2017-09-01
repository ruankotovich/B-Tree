#pragma once
#include "article.hpp"
#include <cstdio>
#include <cstdlib>

#define IOHANDLER_READY 0x0 //!< READY state of the buffer reading
#define IOHANDLER_SLEEPING 0x1 //!< SLEEPING state of the buffer reading
#define IOHANDLER_END 0x2 //!< END state of the buffer reading

#define IOHANDLER_READ_BUFFER_SIZE 4096 //!< IOHandler reading buffer size (block size)

/**
* A class to read and handle the CSV file, buffering and handleing the fields
*/
class IOHandler {
    FILE* file;
    char state;
    int idBuffer;
    char titleBuffer[FIELD_TITLE_MAX_SIZE];
    int yearBuffer;
    char authorsBuffer[FIELD_AUTHORS_MAX_SIZE];
    int citationsBuffer;
    char dateBuffer[FIELD_DATE_MAX_SIZE];
    char snippetBuffer[FIELD_SNIPPET_MAX_SIZE];
    char readBuffer[IOHANDLER_READ_BUFFER_SIZE];

public:
    IOHandler(FILE*);
    bool hasNext();
    void parseNext();
    void operator>>(Article_t&);
    int getBiggestId();
};
