#include "block.hpp"

/**
* Verify if there is space in the block
*/
bool Block_t::hasSpace()
{
  unsigned char position = ((Header_Interpretation_t*)(&this->content[0]))->struct_header.count;
  unsigned int realPosition = RECORD_HEADER_SIZE + (position * sizeof(Article_t));

  return (realPosition < (BLOCK_SIZE-RECORD_TAIL_SIZE) - sizeof(Article_t));
}

/**
* Try to put the article into the block, return true if it has been successfull
*/
bool Block_t::tryPutArticle(Article_t& article)
{
  Header_Interpretation_t* headerOnBytes = (Header_Interpretation_t*)(&this->content[0]);
  Tail_Interpretation_t* tailOnBytes = (Tail_Interpretation_t*)(&this->content[TAIL_LOCATION]);

  unsigned char position = headerOnBytes->struct_header.count;
  unsigned int realPosition = DATA_LOCATION + (position * sizeof(Article_t));

  if (realPosition < BLOCK_SIZE - sizeof(Article_t)) {
    Article_Interpretation_t* articleOnBytes = (Article_Interpretation_t*)(&this->content[realPosition]);

    std::memcpy(&articleOnBytes->struct_article, &article, sizeof(Article_Interpretation_t));

    ++headerOnBytes->struct_header.count;
    tailOnBytes->struct_tail.verificationMask = headerOnBytes->struct_header.verificationMask = VERIFICATION_MASK;

    return true;
  }

  return false;
}

/**
* Get an article in the relative position in the block
*/
Article_t* Block_t::getArticle(unsigned int position)
{
  Article_Interpretation_t* articleOnBytes = (Article_Interpretation_t*)(&this->content[(sizeof(Article_t) * position) + RECORD_HEADER_SIZE]);
  return (&articleOnBytes->struct_article);
}


/**
* Validate the block before the insertion so the block can be identifyed
*/
void Block_t::validate(){
  Header_Interpretation_t* headerOnBytes = (Header_Interpretation_t*)(&this->content[0]);
  Tail_Interpretation_t* tailOnBytes = (Tail_Interpretation_t*)(&this->content[TAIL_LOCATION]);
  tailOnBytes->struct_tail.verificationMask = headerOnBytes->struct_header.verificationMask = VERIFICATION_MASK;
  headerOnBytes->struct_header.count = 0b0;
}

/**
* Verify if the block is valid
*/
bool Block_t::isValid(){
  Header_Interpretation_t* headerOnBytes = (Header_Interpretation_t*)(&this->content[0]);
  Tail_Interpretation_t* tailOnBytes = (Tail_Interpretation_t*)(&this->content[TAIL_LOCATION]);
  return tailOnBytes->struct_tail.verificationMask == headerOnBytes->struct_header.verificationMask && headerOnBytes->struct_header.verificationMask == VERIFICATION_MASK;
}


/**
* Default block constructor
*/
Block_t::Block_t()
{
}
