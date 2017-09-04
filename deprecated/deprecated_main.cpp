#include "primarybtree.hpp"
#include <iostream>

using namespace std;

int main()
{
    PrimaryBTree btree;
    FILE* indexFileWrite = fopen("files/primaryindex.block", "wb");
    FILE* indexFileRead = fopen("files/primaryindex.block", "rb");
    btree.buildIndex(indexFileWrite);

    Article_t art;
    btree.insert(8, indexFileWrite, indexFileRead);
    btree.insert(738289, indexFileWrite, indexFileRead);
    btree.insert(1, indexFileWrite, indexFileRead);
    btree.insert(7, indexFileWrite, indexFileRead);
    btree.insert(25, indexFileWrite, indexFileRead);
    btree.insert(16, indexFileWrite, indexFileRead);
    btree.insert(6, indexFileWrite, indexFileRead);
    btree.insert(26, indexFileWrite, indexFileRead);
    btree.insert(12, indexFileWrite, indexFileRead);
    btree.insert(9, indexFileWrite, indexFileRead);
    btree.insert(10, indexFileWrite, indexFileRead);
    btree.insert(5, indexFileWrite, indexFileRead);
    btree.insert(13, indexFileWrite, indexFileRead);
    btree.insert(23, indexFileWrite, indexFileRead);
    btree.insert(14, indexFileWrite, indexFileRead);
    btree.insert(30, indexFileWrite, indexFileRead);
    btree.insert(17, indexFileWrite, indexFileRead);
    btree.insert(22, indexFileWrite, indexFileRead);
    btree.insert(11, indexFileWrite, indexFileRead);
    btree.insert(18, indexFileWrite, indexFileRead);
    btree.insert(3, indexFileWrite, indexFileRead);
    btree.insert(27, indexFileWrite, indexFileRead);
    btree.insert(19, indexFileWrite, indexFileRead);
    btree.insert(4, indexFileWrite, indexFileRead);
    btree.insert(20, indexFileWrite, indexFileRead);
    btree.insert(2, indexFileWrite, indexFileRead);
    btree.insert(24, indexFileWrite, indexFileRead);
    btree.insert(21, indexFileWrite, indexFileRead);
    btree.insert(15, indexFileWrite, indexFileRead);
    btree.insert(28, indexFileWrite, indexFileRead);
    btree.insert(29, indexFileWrite, indexFileRead);
    btree.insert(1549146, indexFileWrite, indexFileRead);

    fclose(indexFileWrite);

    int key;
    while (std::cin >> key) {
        if (btree.getArticle(key, &art, indexFileRead)) {
            std::cout << art.toString() << '\n';
        }
    }

    return 0;
}
