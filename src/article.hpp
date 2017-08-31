#pragma once
#include <cstdint>
#include <cstring>
#include <sstream>

#define FIELD_TITLE_MAX_SIZE 300
#define FIELD_AUTHORS_MAX_SIZE 1024
#define FIELD_DATE_MAX_SIZE 20
#define FIELD_SNIPPET_MAX_SIZE 1024

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
