#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "article.hpp"
#include "secondarybtree.hpp"

using namespace std;

int main(int argc, char** argv)
{
    SecondaryBTreeDataMap searchKey;

    if (argc > 1) {
        std::memcpy(searchKey.key, argv[1], SECONDARY_KEY_LENGTH);
    } else {
        std::string buffer;
        std::getline(std::cin, buffer);
        std::memcpy(searchKey.key, buffer.c_str(), SECONDARY_KEY_LENGTH);
        std::cout << "\"" << buffer << "\"\n";
    }

    SecondaryBTree btree;

    Article_t a;
    FILE* indexFile = fopen("files/secondaryindex.block", "rb");

    btree.readRoot(indexFile);

    if (indexFile != NULL) {
        auto result = btree.getArticle(searchKey, &a, indexFile);

        if (result.first) {
            cout << a.toString();
            cout << "\n\nNumber of block read in PrimaryBTree Index to find the record: " << result.second + 1;
            fseek(indexFile, 0, SEEK_END);
            cout << "\n\nTotal number of blocks in primary index file: " << ((ftell(indexFile) / sizeof(AbstractBlock_t))) << "\n";
        } else {
            cout << "Record not found.\n";
        }
    } else {
        cout << "There isn't a primary index file.\n";
    }

    return 0;
}
