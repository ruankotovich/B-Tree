#include "block.hpp"

void Block_t::putArticle(Article_t& article)
{
    int position = i_fromByteArray(this->block_header, 0);
    Article_Interpretation_t* articleOnBytes = (Article_Interpretation_t*)(&this->record_content[sizeof(Article_t) * position]);
    articleOnBytes->article = article;
    byte_fromInt(++position, 0, this->block_header);
}