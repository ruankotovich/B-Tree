#include "block.hpp"

bool Block_t::tryPutArticle(Article_t& article)
{
    int position = i_fromByteArray(this->block_header, 0);
    int realPosition = position * sizeof(Article_t);

    if (realPosition < BLOCK_SIZE - sizeof(Article_t)) {
        Article_Interpretation_t* articleOnBytes = (Article_Interpretation_t*)(&this->record_content[realPosition]);
        articleOnBytes->article = article;
        byte_fromInt(++position, 0, this->block_header);
        return true;
    }

    return false;
}

Article_t* Block_t::getArticle(int position)
{
    Article_Interpretation_t* articleOnBytes = (Article_Interpretation_t*)(&this->record_content[sizeof(Article_t) * position]);
    return (&articleOnBytes->article);
}