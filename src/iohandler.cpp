#include "iohandler.hpp"

#define R_NOTHING 0 //!< The two characters are nothing in special
#define R_SOR 1 //!< The two characters means START OF RECORD
#define R_EOC 2 //!< The two characters means END OF RECORD
#define R_SON 3 //!< The two characters means START OF NULL

/**
* Second degree verifyer, classify a pair of characters.
*
* Classes :
* R_NOTHING as 0 \
* R_SOR as 1 \
* R_EOC as 2 \
* R_SON as 3 \
*/
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

/**
* First degree verifyer, classify a pair of characters.
*
* Classes :
* R_NOTHING as 0 \
* R_SOR as 1 \
* R_EOC as 2 \
* R_SON as 3 \
*/
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

/**
* Read a column receiving the file, the buffer and the previous char
*/
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

/**
* Read a column receiving the file and the previous char, ignoring the buffer
*/
static inline void readNIgnoreColumn(FILE* file, char previous)
{
  char current = fgetc(file);
  char type;
  type = pairClass(previous, current);
  if (type != R_SON) {
    current = fgetc(file);
    do {
      previous = current;
      current = fgetc(file);
    } while ((type = after_pairClass(previous, current)) < R_EOC);
  } else {
    fscanf(file, "ULL\n");
    fscanf(file, "ULL\r\n");
    fscanf(file, "ULL;");
  }
}

/**
* Parse the next record contained in the buffer
*/
int IOHandler::getBiggestId(){

  int idBuffer;
  int bigger = 0;
  unsigned long backupPosition = ftell(this->file);
  fseek(this->file, 0, SEEK_SET);
  while (fscanf(this->file, "\"%d\";", &idBuffer) == 1) {
    // READ TITLE
    readNIgnoreColumn(this->file, ';');
    // READ YEAR
    fscanf(this->file, "\"%*d\";");

    // READ AUTHOR
    readNIgnoreColumn(this->file,  ';');

    // READ CITATION
    fscanf(this->file, "\"%*d\";");

    // READ DATE
    readNIgnoreColumn(this->file, ';');

    // READ SNIPPET
    readNIgnoreColumn(this->file, ';');

    if(idBuffer > bigger){
      bigger = idBuffer;
    }
  }

  fseek(this->file, backupPosition, SEEK_SET);

  return bigger;
}

/**
* Prepare the next parsing element
*/
void IOHandler::parseNext()
{
  if (fscanf(this->file, "\"%d\";", &this->idBuffer) == 1) {
    // READ TITLE
    readColumn(this->file, this->readBuffer, ';');

    std::memcpy(this->titleBuffer, this->readBuffer, FIELD_TITLE_MAX_SIZE);
    this->titleBuffer[FIELD_TITLE_MAX_SIZE - 1] = '\0';
    // READ YEAR
    fscanf(this->file, "\"%d\";", &this->yearBuffer);

    // READ AUTHOR
    readColumn(this->file, this->readBuffer, ';');
    std::memcpy(this->authorsBuffer, this->readBuffer, FIELD_AUTHORS_MAX_SIZE);
    this->authorsBuffer[FIELD_AUTHORS_MAX_SIZE - 1] = '\0';
    // READ CITATION
    fscanf(this->file, "\"%d\";", &this->citationsBuffer);

    // READ DATE
    readColumn(this->file, this->readBuffer, ';');
    std::memcpy(this->dateBuffer, this->readBuffer, FIELD_DATE_MAX_SIZE);
    this->dateBuffer[FIELD_DATE_MAX_SIZE - 1] = '\0';
    // READ SNIPPET
    readColumn(this->file, readBuffer, ';');
    std::memcpy(this->snippetBuffer, this->readBuffer, FIELD_SNIPPET_MAX_SIZE);
    this->snippetBuffer[FIELD_SNIPPET_MAX_SIZE - 1] = '\0';
    this->state = IOHANDLER_READY;
  } else {
    this->state = IOHANDLER_END;
  }
}

/**
* Copy the content of the buffer into an article
*/
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

/**
* Verify if there is next record in the buffer
*/
bool IOHandler::hasNext()
{
  return this->state == IOHANDLER_READY;
}

/**
* Default IOHandler constructor, receiving a file to read
*/
IOHandler::IOHandler(FILE* file)
{
  this->file = file;
  this->state = IOHANDLER_SLEEPING;
  this->parseNext();
}
