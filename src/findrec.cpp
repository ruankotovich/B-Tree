#include "hashfinder.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[])
{
  FILE* blockFile = fopen("files/data.block", "rb+");
  if (blockFile != NULL) {

    fseek(blockFile, sizeof(Block_t), SEEK_END);
    int numberOfArticles = ftell(blockFile) / sizeof(Block_t) - 1;
    rewind(blockFile);
    
    
    int id;

    if(argc > 1){
      id = atoi(argv[1]);
    }else{
      std::cin >> id;
    }

    Article_t article;

    if (getArticleFromHash(id, &article, blockFile)) { // recover an article from the hash
      std::cout << article.toString();
      std::cout << "\n\n> Number of records: " << numberOfArticles << "\n" << "> Number of blocks read: 1 \n"; // since it's a perfect hash
    } else {
      std::cout << "Record not found\n";
    }

  }
}
