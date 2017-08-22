#include "iohandler.hpp"

#define R_NOTHING 0
#define R_SOR 1
#define R_EOC 2
#define R_SON 3

static inline char after_pairClass(char previous, char current)
{
    switch (previous) {
    case '\"': {

        if (current == ';' || current == '\n' || current == EOF) {
            return R_EOC;
        }

    } break;

    case ';': {

        if (current == '\"') {
            return R_SOR;
        }

    } break;

    case '\r': {
        if (current == '\n' || current == EOF) {
            return R_EOC;
        }
    }
    }
    return R_NOTHING;
}

static inline char pairClass(char previous, char current)
{

    switch (previous) {
    case '\"': {

        return R_EOC;
    } break;

    case ';': {
        if (current == ';') {
            return R_EOC;
        }
        if (current == 'N') {
            return R_SON;
        }

    } break;
    }
    return R_NOTHING;
}

static inline void readColumn(FILE* file, char* buffer, char previous)
{
    char current = fgetc(file);
    int pointer = 0;
    char type;
    type = pairClass(previous, current);
    if (type != R_SON) {
        current = fgetc(file);
        do {
            previous = current;
            current = fgetc(file);
            if (type < R_SOR) {
                buffer[pointer++] = previous;
            }
        } while ((type = after_pairClass(previous, current)) < R_EOC);
    } else {
        fscanf(file, "ULL\n");
        fscanf(file, "ULL\r\n");
        fscanf(file, "ULL;");
        pointer = 1;
    }
    buffer[pointer - 1] = '\0';
}

void IOHandler::parseNext()
{
    if (fscanf(this->file, "\"%d\";", &this->idBuffer) == 1) {
        // READ TITLE
        readColumn(this->file, this->readBuffer, ';');

        std::memcpy(this->titleBuffer, this->readBuffer, FIELD_TITLE_MAX_SIZE);

        // READ YEAR
        fscanf(this->file, "\"%d\";", &this->yearBuffer);

        // READ AUTHOR
        readColumn(this->file, this->readBuffer, ';');
        std::memcpy(this->authorsBuffer, this->readBuffer, FIELD_AUTHORS_MAX_SIZE);

        // READ CITATION
        fscanf(this->file, "\"%d\";", &this->citationsBuffer);

        // READ DATE
        readColumn(this->file, this->readBuffer, ';');
        std::memcpy(this->dateBuffer, this->readBuffer, FIELD_DATE_MAX_SIZE);

        // READ SNIPPET
        readColumn(this->file, readBuffer, ';');
        std::memcpy(this->snippetBuffer, this->readBuffer, FIELD_SNIPPET_MAX_SIZE);

        this->state = IOHANDLER_READY;
    } else {
        this->state = IOHANDLER_END;
    }
}

void IOHandler::operator>>(Article_t& article)
{
    article.id = idBuffer;
    article.year = yearBuffer;
    article.citations = citationsBuffer;
    std::memcpy(article.title, this->titleBuffer, FIELD_TITLE_MAX_SIZE);
    std::memcpy(article.authors, this->authorsBuffer, FIELD_AUTHORS_MAX_SIZE);
    std::memcpy(article.date, this->dateBuffer, FIELD_DATE_MAX_SIZE);
    std::memcpy(article.snippet, this->snippetBuffer, FIELD_SNIPPET_MAX_SIZE);
}

bool IOHandler::hasNext()
{
    return this->state == IOHANDLER_READY;
}

IOHandler::IOHandler(FILE* file)
{
    this->file = file;
    this->state = IOHANDLER_SLEEPING;
    this->parseNext();
}