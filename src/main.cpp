#include "block.hpp"
#include "iohandler.hpp"

#include <iostream>
int main(int argc, char* argv[])
{
    IOHandler handler(fopen("./files/pattern.csv", "r"));
    Block_t block;

    while (handler.hasNext()) {
        Article_t article;
        handler >> article;
        block.putArticle(article);
        // std::cout << article.toString() << "\n\n"
        //           << std::endl;
        std::cout << block.getArticle(0)->toString() << "\n\n"
                  << std::endl;
        handler.parseNext();
    }
}