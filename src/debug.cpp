#include "secondarybtree.hpp"
#include <iostream>

union BlockDerreference {
    Block_t block;
    SecondaryBTreeNode node;
};

void printAll(Block_t& block, FILE* indexFile, BlockDerreference* derreference)
{
    int i = 0;

    rewind(indexFile);
    while (fread(&block, sizeof(Block_t), 1, indexFile)) {
        std::cout << " --- At seek " << i << '\n';
        std::cout << "Key Count : " << derreference->node.count << "\n";
        std::cout << "Keys : {";
        for (int j = 0; j < derreference->node.count; ++j) {
            std::cout << derreference->node.keys[j].key << ',';
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
}
int main()
{
    Block_t block;
    BlockDerreference* derreference;
    derreference = (BlockDerreference*)&block;
    FILE* indexFile = fopen("test/secondaryindex.block", "rb");

    int toRead;
    std::cout << "\n >> ";
    while (std::cin >> toRead) {

        if (toRead <= 0) {
            printAll(block, indexFile, derreference);
            std::cout << "\n --- \n >> ";
        } else {

            fseek(indexFile, sizeof(Block_t) * toRead, SEEK_SET);
            fread(&block, sizeof(Block_t), 1, indexFile);
            std::cout << "\n\n --- \n";
            std::cout << " --- At seek " << toRead << '\n';
            std::cout << "Key Count : " << derreference->node.count << "\n";
            std::cout << "Keys : {";
            for (int j = 0; j < derreference->node.count; ++j) {
                std::cout << derreference->node.keys[j].key << ',';
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
            std::cout << "\n --- \n >> ";
        }
    }

    return 0;
}