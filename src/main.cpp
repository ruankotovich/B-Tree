#include "hashfilefactory.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[])
{
    HashFileFactory hashFileFactory;
    
    hashFileFactory.createBinaryFilePerfectHash(fopen("./files/pattern.csv", "r"),
                                                fopen("./test/pattern.block", "wb+"));

    FILE* blockFile = fopen("./test/pattern.block", "rb+");
    if (blockFile != NULL) {
        fseek(blockFile, sizeof(Block_t), SEEK_END);
        int numberOfArticles = ftell(blockFile) / sizeof(Block_t)- 1;
        rewind(blockFile);

        while (true) {
            int id;
            std::cout << "Insira o id: ";
            std::cin >> id;
            std::cout << "\n";

            Article_t article;

            if (hashFileFactory.getArticleFromHash(id, &article, blockFile)) {
                std::cout << article.toString();
                std::cout << "\n\n> Number of records: " << numberOfArticles << "\n"
                          << "> Number of blocks read: 1\n";
            } else {
                std::cout << "OLOSKO";
            }

            std::cout << "\n\n";
        }
    }
}