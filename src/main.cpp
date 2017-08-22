#include "block.hpp"
#include "iohandler.hpp"

#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[])
{
    IOHandler handler(fopen("./files/pattern.csv", "r"));
    Block_t block;
    FILE* blockFile = fopen("./test/penises.block", "wb+");

    while (handler.hasNext()) {
        Article_t article;
        handler >> article;
        block.tryPutArticle(article);
        fwrite(&block, sizeof(Block_t), 1, blockFile);
        fclose(blockFile);
        blockFile = fopen("./test/penises.block", "rb");
        Block_t anotherBlock;
        fread(&anotherBlock, sizeof(Block_t), 1, blockFile);
        // std::cout << article.toString() << "\n\n"
        //           << std::endl;
        std::cout << anotherBlock.getArticle(0)->toString() << "\n\n"
                  << std::endl;
        handler.parseNext();
    }
}