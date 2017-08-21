#pragma once
#include "article.hpp"
#include <cstdio>
#include <cstdlib>

#define IOHANDLER_READY 0x0
#define IOHANDLER_SLEEPING 0x1
#define IOHANDLER_END 0x2

#define IOHANDLER_READ_BUFFER_SIZE 4096

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
    // friend std::ostream& operator<<(std::ostream& os, const IOHandler& dt);
    void operator>>(Article_t&);
};