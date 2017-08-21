#include "article.hpp"

Article_t::Article_t() {}
Article_t::Article_t(int id, char title[FIELD_TITLE_MAX_SIZE], int year, char authors[FIELD_AUTHORS_MAX_SIZE], int citations, char date[FIELD_DATE_MAX_SIZE], char snippet[FIELD_SNIPPET_MAX_SIZE])
    : id(id)
    , year(year)
    , citations(citations)
{
    std::memcpy(this->title, title, FIELD_TITLE_MAX_SIZE);
    std::memcpy(this->authors, authors, FIELD_AUTHORS_MAX_SIZE);
    std::memcpy(this->date, date, FIELD_DATE_MAX_SIZE);
    std::memcpy(this->snippet, snippet, FIELD_SNIPPET_MAX_SIZE);
}

std::string Article_t::toString()
{
    nlohmann::json jsonObject;
    jsonObject["id"] = id;
    jsonObject["title"] = title;
    jsonObject["year"] = year;
    jsonObject["authors"] = authors;
    jsonObject["citations"] = citations;
    jsonObject["date"] = date;
    jsonObject["snippet"] = snippet;
    return jsonObject.dump();
}
