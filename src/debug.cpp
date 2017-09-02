#include "btree.hpp"
#include <iostream>

union BlockDerreference {
    Block_t block;
    Node node;
};

int main()
{
    Block_t block;
    BlockDerreference* derreference;
    derreference = (BlockDerreference*)&block;
    FILE* indexFile = fopen("test/primaryindex.block", "rb");
    int i = 0;
    int k;

    while ((k = fread(&block, sizeof(Block_t), 1, indexFile)) == 1) {
        std::cout << " --- At seek " << i << '\n';
        std::cout << "Key Count : " << derreference->node.count << "\n";
        std::cout << "Keys : {";
        for (int j = 0; j < derreference->node.count; ++j) {
            std::cout << derreference->node.keys[j] << ',';
        }
        std::cout << "}\n";
        std::cout << "Pointer Count : " << derreference->node.countPointers << "\n";
        std::cout << "Pointers : {";
        for (int j = 0; j < derreference->node.countPointers; ++j) {
            std::cout << derreference->node.blockPointers[j] << ',';
        }
        std::cout << "}\n";
        std::cout << "isLeaf() : " << derreference->node.isLeaf() << "\n";
        std::cout << "hasRoom() : " << derreference->node.hasRoom() << "\n";
        i++;
        std::cout << "\n\n";
        fseek(indexFile, sizeof(Block_t) * i, SEEK_SET);
    }

    return 0;
}