#include "hashfilefactory.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[])
{
    HashFileFactory hashFileFactory;

    FILE* blockFile = fopen("./data.block", "rb+");
    if (blockFile != NULL) {
        fseek(blockFile, sizeof(Block_t), SEEK_END);
        int numberOfArticles = ftell(blockFile) / sizeof(Block_t) - 1;
        rewind(blockFile);

        // while (true) {
        int id = atoi(argv[1]);
        // std::cout << "Insira o id: ";
        // std::cin >> id;
        // std::cout << "\n";

        Article_t article;

        if (hashFileFactory.getArticleFromHash(id, &article, blockFile)) {
            std::cout << article.toString();
            std::cout << "\n\n> Number of records: " << numberOfArticles << "\n"
                      << "> Number of blocks read: 1\n";
        } else {
            std::cout << "Record not found";
        }

        // std::cout << "\n\n-----------------------------------------------------------\n\n";
        // }
    }
}