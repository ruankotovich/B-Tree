#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "article.hpp"
#include "primarybtree.hpp"

using namespace std;

int main(int argc, char** argv)
{
    int id;
    
    if(argc>1){ id = atoi(argv[1]);}else{std::cin >> id;}
    PrimaryBTree btree;
    
    Article_t a;
    FILE* indexFile = fopen("files/primaryindex.block", "rb");

    btree.readRoot(indexFile);

    if (indexFile != NULL) {
        auto result = btree.getArticle(id, &a, indexFile);

        if (result.first) {
            cout << a.toString();
            cout << "\n\nNumber of block read in PrimaryBTree Index to find the record: " << result.second + 1;
            fseek(indexFile, 0, SEEK_END);
            cout << "\n\nTotal number of blocks in primary index file: " << ((ftell(indexFile) / sizeof(AbstractBlock_t))) << "\n";
        } else {
            cout << "Record not found.\n";
        }
    }
    else {
        cout << "There isn't a primary index file.\n";
    }

    return 0;
}
