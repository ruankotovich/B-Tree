#include "iohandler.hpp"
#include <iostream>
int main(int argc, char* argv[])
{
    IOHandler handler(fopen("./misc/testinho.csv", "r"));
    while (handler.hasNext()) {
        Article_t article;
        handler >> article;
        std::cout << article.toString() << "\n\n" << std::endl;
        handler.parseNext();
    }
}
