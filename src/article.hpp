#pragma once
#include <cstdint>
#include <cstring>
#include <sstream>

#define FIELD_TITLE_MAX_SIZE 300 //!< Max size of the article title
#define FIELD_AUTHORS_MAX_SIZE 1024 //!< Max size of the article authors' names
#define FIELD_DATE_MAX_SIZE 20 //!< Max size of the article date
#define FIELD_SNIPPET_MAX_SIZE 1024 //!< Max size of the article snippet

struct Article_t {
  int id;
  char title[FIELD_TITLE_MAX_SIZE];
  int year;
  char authors[FIELD_AUTHORS_MAX_SIZE];
  int citations;
  char date[FIELD_DATE_MAX_SIZE];
  char snippet[FIELD_SNIPPET_MAX_SIZE];
  std::string toString();
  Article_t(int, char[FIELD_TITLE_MAX_SIZE], int, char[FIELD_AUTHORS_MAX_SIZE], int, char[FIELD_DATE_MAX_SIZE], char[FIELD_SNIPPET_MAX_SIZE]);
  Article_t();

};
