#include "btree.hpp"
#include <iostream>

using namespace std;

int main()
{
    BTree btree;

    FILE* indexFile = fopen("test/primaryindex.block", "wb");
    btree.buildIndex(indexFile);
    Article_t art;
    btree.insert(738289, indexFile);
    btree.insert(1, indexFile);
    btree.insert(2, indexFile);
    btree.insert(3, indexFile);
    btree.insert(4, indexFile);

    int key;
    while (std::cin >> key) {
        if (btree.getArticle(key, &art, fopen("test/primaryindex.block", "rb"))) {
            std::cout << art.toString() << '\n';
        }
    }

    return 0;
}
