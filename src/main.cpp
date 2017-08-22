#include "block.hpp"
#include "iohandler.hpp"

#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[])
{
    IOHandler handler(fopen("./files/pattern.csv", "r"));
    FILE* blockFile = fopen("./test/pattern.block", "wb+");
  
    Article_t currentArticle;
    
    while (handler.hasNext()) {
        Block_t currentBlock;
        
        do{
            handler >> currentArticle;
        }while(currentBlock.tryPutArticle(currentArticle));

    }

}