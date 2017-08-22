#include "block.hpp"

bool Block_t::tryPutArticle(Article_t& article)
{
    Header_Interpretation_t* headerOnBytes = (Header_Interpretation_t*)(&this->content[0]);

    unsigned char position = headerOnBytes->struct_header.count;
    unsigned int realPosition = RECORD_HEADER_SIZE + (position * sizeof(Article_t));

    if (realPosition < BLOCK_SIZE - sizeof(Article_t)) {
        Article_Interpretation_t* articleOnBytes = (Article_Interpretation_t*)(&this->content[realPosition]);

        std::memcpy(&articleOnBytes->struct_article, &article, sizeof(Article_Interpretation_t));

        ++headerOnBytes->struct_header.count;
        headerOnBytes->struct_header.valid = 0b1;

        return true;
    }

    return false;
}

Article_t* Block_t::getArticle(unsigned int position)
{
    Article_Interpretation_t* articleOnBytes = (Article_Interpretation_t*)(&this->content[(sizeof(Article_t) * position) + RECORD_HEADER_SIZE]);
    return (&articleOnBytes->struct_article);
}

Block_t::Block_t()
{
    Header_Interpretation_t* headerOnBytes = (Header_Interpretation_t*)(&this->content[0]);
    headerOnBytes->struct_header.count = 0b0;
    headerOnBytes->struct_header.valid = 0b0;
}