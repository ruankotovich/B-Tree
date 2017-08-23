#include "hashfilefactory.cpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[])
{
    FILE* blockFile = fopen("./test/pattern.block", "wb+");
    HashFileFactory hashFileFactory(fopen("./files/pattern.csv", "r"), blockFile);
    
    //hashFileFactory.createBinaryFilePerfectHash();

    Article_t article;
    if(hashFileFactory.getArticleFromHash(3, &article)) {
        std::cout << article.toString();
    }
    else {
        std::cout << "OLOSKO";
    }
}